MODULE Net:HTTP:Server [OOC_EXTENSIONS];
(*  A simple HTTP server implementation.
    Copyright (C) 2001  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Ascii, Channel, IntStr, Msg, Strings, SysClock,
  ADT:Object, ADT:String, ADT:StringBuffer, ADT:ArrayList, 
  URI, URIParser := URI:Parser, HttpURI := URI:Scheme:HTTP, 
  StringURI := URI:String, URI:Query:Unparsed, URI:Query:WWWForm,
  IO:Port, IO:Port:Streaming, IO:Memory, Net:HTTP;


CONST
  crlf = Ascii.cr+Ascii.lf;

CONST
  receiveRequestLine = 0;
  receiveHeaderLine = 1;
  receiveBody = 2;
  receiveComplete = 3;

TYPE
  HeaderList = RECORD
    names: ArrayList.ArrayList;
    values: ArrayList.ArrayList;
  END;

TYPE
  Request* = POINTER TO RequestDesc;
  StringArrayPtr* = POINTER TO ARRAY OF String.String;
  RequestDesc = RECORD
    state: SHORTINT;
    buffer: StringBuffer.StringBuffer;
    uri-: HttpURI.URI;
    methodString, version: String.String;
    method-: HTTP.MethodCode;
    headers: HeaderList;
    contentLength: LONGINT;
    file: Memory.Channel;
    writer: Memory.Writer;
    params: WWWForm.Query;
  END;

TYPE
  Response* = POINTER TO ResponseDesc;
  ResponseDesc = RECORD
    status: HTTP.ResponseCode;
    headers: HeaderList;
    headerText: StringBuffer.StringBuffer;
    text: Memory.Channel;
    sent: LONGINT;
  END;

TYPE
  Servlet* = POINTER TO ServletDesc;
  ServletDesc* = RECORD [ABSTRACT]
  END;

TYPE
  Server* = POINTER TO ServerDesc;
  ServerDesc* = RECORD
    (Streaming.TransferDesc)
    req: Request;
    resp: Response;
    servlet: Servlet;
  END;

TYPE
  ServerFactory* = POINTER TO ServerFactoryDesc;
  ServerFactoryDesc = RECORD
    (Port.TransferFactoryDesc)
    servlet: Servlet;
  END;

VAR
  httpURI: HttpURI.URI;


PROCEDURE InitHeaderList (VAR hl: HeaderList);
  BEGIN
    hl. names := ArrayList.New(8);
    hl. values := ArrayList.New(8);
  END InitHeaderList;

PROCEDURE IsEqual (VAR a, b: ARRAY OF CHAR): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (a[i] # 0X) & (CAP (a[i]) = CAP (b[i])) DO
      INC (i)
    END;
    RETURN (a[i] = 0X) & (b[i] = 0X)
  END IsEqual;


PROCEDURE HasHeader (VAR hl: HeaderList; name: String.String): BOOLEAN;
  VAR
    n: ArrayList.ArrayList;
    i: LONGINT;
  BEGIN
    n := hl. names;
    FOR i := 0 TO hl. names. size-1 DO
      IF IsEqual (n. array[i](String.String). array^, name. array^) THEN
        RETURN TRUE
      END
    END;
    RETURN FALSE
  END HasHeader;

PROCEDURE GetHeader (VAR hl: HeaderList; name: String.String): String.String;
  VAR
    n: ArrayList.ArrayList;
    i: LONGINT;
  BEGIN
    n := hl. names;
    FOR i := 0 TO hl. names. size-1 DO
      IF IsEqual (n. array[i](String.String). array^, name. array^) THEN
        RETURN hl. values. array[i](String.String)
      END
    END;
    RETURN NIL
  END GetHeader;

PROCEDURE SetHeader (VAR hl: HeaderList; name, value: String.String);
  VAR
    n: ArrayList.ArrayList;
    i: LONGINT;
  BEGIN
    n := hl. names;
    FOR i := 0 TO hl. names. size-1 DO
      IF IsEqual (n. array[i](String.String). array^, name. array^) THEN
        hl. values. Set (i, value)
      END
    END;
    hl. names. Append (name);
    hl. values. Append (value)
  END SetHeader;


PROCEDURE InitServer* (s: Server; servlet: Servlet);
  BEGIN
    Streaming.InitTransfer (s);
    s. servlet := servlet;
    NEW (s. req);
    s. req. state := receiveRequestLine;
    s. req. buffer := StringBuffer.New("");
    s. req. methodString := NIL;
    s. req. method := HTTP.methodUnknown;
    s. req. uri := NIL;
    s. req. version := NIL;
    InitHeaderList (s. req. headers);
    s. req. contentLength := -1;
    s. req. file := NIL;
    s. req. writer := NIL;
    s. req. params := WWWForm.New();
    NEW (s. resp);
    s. resp. status := HTTP.scOk;
    InitHeaderList (s. resp. headers);
    s. resp. headerText := StringBuffer.New("");
    s. resp. text := NIL;
    s. resp. sent := 0;
  END InitServer;

PROCEDURE NewServer* (servlet: Servlet): Server;
  VAR
    s: Server;
  BEGIN
    NEW (s);
    InitServer (s, servlet);
    RETURN s
  END NewServer;

PROCEDURE (s: Server) SetPort* (p: Port.Port);
  CONST
    outputBuffer = 8*1024;
    inputBuffer = 8*1024;
  VAR
    b: Port.Buffer;
  BEGIN
    s. SetPort^ (p);
    IF (p # NIL) THEN
      p(Streaming.Port). SetOutputBuffer (outputBuffer, 0);
      NEW (b, inputBuffer+1);
      p(Streaming.Port). SetInputBuffer (inputBuffer, b, 0)
    END
  END SetPort;

PROCEDURE (s: Server) PortStatusChange* (newStatus: SHORTINT; reason: Msg.Msg);
(**Disbands port on close.  *)
  BEGIN
    s. PortStatusChange^ (newStatus, reason);
    IF (newStatus = Port.portClose) THEN
      s. port. Disband
    END
  END PortStatusChange;

PROCEDURE WriteData (resp: Response; port: Streaming.Port; capacity: LONGINT);
  VAR
    len: LONGINT;
  BEGIN
    IF (resp. headerText # NIL) THEN
      len := resp. headerText. length - resp. sent;
      IF (capacity >= len) THEN
        port. OutputData (resp. headerText. array^,
                          resp. sent, resp. headerText. length);
        DEC (capacity, len);
        resp. headerText := NIL;
        resp. sent := 0
      ELSE
        port. OutputData (resp. headerText. array^, resp. sent, resp. sent+capacity);
        INC (resp. sent, capacity);
        RETURN
      END
    END;
    
    IF (resp. text # NIL) THEN
      len := resp. text. file. length - resp. sent;
      IF (capacity >= len) THEN
        port. OutputData (resp. text. file. data^,
                          resp. sent, resp. text. file. length);
        DEC (capacity, len);
        resp. text := NIL;
        resp. sent := 0
      ELSE
        port. OutputData (resp. text. file. data^, resp. sent, resp. sent+capacity);
        INC (resp. sent, capacity);
        RETURN
      END
    END
  END WriteData;

PROCEDURE (s: Server) OutputNotification* (capacity: LONGINT);
  VAR
    res: Msg.Msg;
  BEGIN
    IF (s. resp. headerText = NIL) & (s. resp. text = NIL) THEN
      s. port. Close (Port.done, res);
      ASSERT (res = Port.done)
    ELSE
      WriteData (s. resp, s. port, capacity)
    END
  END OutputNotification;



PROCEDURE (req: Request) GetHeader* (name: String.String): String.String;
  BEGIN
    RETURN GetHeader (req. headers, name)
  END GetHeader;

PROCEDURE (req: Request) GetIntHeader* (name: String.String): LONGINT;
  VAR
    i: LONGINT;
    str: String.String;
    res: IntStr.ConvResults;
  BEGIN
    str := GetHeader (req. headers, name);
    i := -1;
    IF (str # NIL) THEN
      IntStr.StrToInt (str. array^, i, res);
      IF (res # IntStr.strAllRight) OR (i < 0) THEN
        i := -1
      END
    END;
    RETURN i
  END GetIntHeader;

PROCEDURE (req: Request) GetParameter* (name: String.String): String.String;
  VAR
    obj: Object.Object;
  BEGIN
    IF req. params. dict. HasKey (name) THEN
      obj := req. params. dict. Get (name);
      RETURN obj(ArrayList.ArrayList). array[0](String.String)
    ELSE
      RETURN NIL
    END
  END GetParameter;

PROCEDURE (req: Request) GetParameterValues* (name: String.String): StringArrayPtr;
  VAR
    obj: Object.Object;
    s: StringArrayPtr;
    i: LONGINT;
  BEGIN
    IF req. params. dict. HasKey (name) THEN
      obj := req. params. dict. Get (name);
      NEW (s, obj(ArrayList.ArrayList). size);
      FOR i := 0 TO obj(ArrayList.ArrayList). size-1 DO
        s[i] := obj(ArrayList.ArrayList). array[i](String.String)
      END;
      RETURN s
    ELSE
      RETURN NIL
    END
  END GetParameterValues;


PROCEDURE (resp: Response) SetHeader* (name, value: String.String);
  BEGIN
    SetHeader (resp. headers, name, value)
  END SetHeader;

PROCEDURE (resp: Response) SetStatus* (status: HTTP.ResponseCode);
  BEGIN
    resp. status := status
  END SetStatus;

PROCEDURE (resp: Response) HasHeader* (name: String.String): BOOLEAN;
  BEGIN
    RETURN HasHeader (resp. headers, name)
  END HasHeader;

PROCEDURE (resp: Response) GetWriter* (): Channel.Writer;
  VAR
    res: Msg.Msg;
  BEGIN
    IF (resp. text = NIL) THEN
      resp. text := Memory.Tmp("", {Memory.read, Memory.write}, res);
      ASSERT (res = Memory.done)
    END;
    RETURN resp. text. NewWriter()
  END GetWriter;

PROCEDURE SendResponse (resp: Response; port: Streaming.Port);
  VAR
    time: SysClock.DateTime;
    short, explain, str: ARRAY 64 OF CHAR;
    b: StringBuffer.StringBuffer;
    names: ArrayList.ArrayList;
    i: LONGINT;
  BEGIN
    b := resp. headerText;
    IF (resp. status = HTTP.scOk) THEN
      b. AppendString ("HTTP/1.0 200 Ok"+crlf)
    ELSE
      b. AppendString ("HTTP/1.0 ");
      b. AppendLongInt (resp. status);
      b. AppendChar (" ");
      HTTP.GetMessage (resp. status, short, explain);
      b. AppendString (short);
      b. AppendString (crlf)
    END;
    
    (* ok, omitting the date header is _very_ wrong... FIXME
       SysClock.GetClock (time);
       Calendar.TimeToStr (time, "Date: %a, %d %b %Y %H:%M:%S"+crlf, str);
       (* note: the above time must be GMT, _not_ local time, and the time
          string should end with " GMT *)
       b. AppendString (str);
    *)
    
    names := resp. headers. names;
    FOR i := 0 TO names. size-1 DO
      b. Append (names. array[i](String.String));
      b. AppendString (": ");
      b. Append (resp. headers. values. array[i](String.String));
      b. AppendString (crlf);
    END;
    b. AppendString (crlf);
    
    WriteData (resp, port, port. OutputCapacityLeft())
  END SendResponse;

PROCEDURE (resp: Response) SendError* (code: HTTP.ResponseCode;
                                       msg, insert: ARRAY OF CHAR);
  VAR
    str, explain: ARRAY 512 OF CHAR;
    i: INTEGER;
    b: StringBuffer.StringBuffer;
    w: Channel.Writer;
  BEGIN
    resp. SetStatus (code);
    
    HTTP.GetMessage (code, str, explain);
    IF (msg # "") THEN
      COPY (msg, str);
      i := 0;
      WHILE (str[i] # 0X) & ((str[i] # "%") OR (str[i+1] # "s")) DO
        INC (i)
      END;
      IF (str[i] # 0X) THEN
        Strings.Delete (str, i, 2);
        Strings.Insert (insert, i, str)
      END;
    END;
    
    resp. SetStatus (code);
    
    b := StringBuffer.New ("<html><head><title>Error response</title></head>"+
                           "<body>"+crlf+"<h1>Error response</h1>"+crlf+
                           "<p>Error Code ");
    b. AppendLongInt (code);
    b. AppendString ("</p>"+crlf+"<p>Message: ");
    b. AppendString (str);
    b. AppendString ("</p>"+crlf+"<p>Error code explanation: ");
    b. AppendString (explain);
    b. AppendString ("</p>"+crlf+"</body></html>"+crlf);
    w := resp. GetWriter();
    w. WriteBytes (b. array^, 0, b. length)
  END SendError;


PROCEDURE InitServlet* (servlet: Servlet);
  BEGIN
  END InitServlet;

PROCEDURE (servlet: Servlet) DoGET* (req: Request; resp: Response);
  BEGIN
    resp. SendError (HTTP.scNotImplemented,
                     "Unsupported method (%s)", req. methodString. array^)
  END DoGET;

PROCEDURE (servlet: Servlet) DoPOST* (req: Request; resp: Response);
  BEGIN
    resp. SendError (HTTP.scNotImplemented,
                     "Unsupported method (%s)", req. methodString. array^)
  END DoPOST;


PROCEDURE (s: Server) IncomingData* (b: Port.Buffer; 
                               start, end: LONGINT; VAR msg: Msg.Msg): LONGINT;
  VAR
    pos, i, j: LONGINT;
    name, uriString: String.String;
    req: Request;
    res: Msg.Msg;
    baseURI: URI.URI;
    str: ARRAY 512 OF CHAR;
  
  PROCEDURE Str(): String.String;
    VAR
      start: LONGINT;
    BEGIN  (* any char in 32..126 *)
      start := pos;
      WHILE (" " < b[pos]) & (b[pos] < Ascii.del) DO
        INC (pos)
      END;
      RETURN String.NewRegion (b^, start, pos)
    END Str;
  
  PROCEDURE SkipSP;
    BEGIN
      WHILE (b[pos] = " ") DO
        INC (pos)
      END
    END SkipSP;
  
  PROCEDURE EndOfHeaders;
    VAR
      res: Msg.Msg;
      q: StringURI.StringPtr;
    BEGIN
      s. req. state := receiveBody;
      
      IF (s. req. uri. query # NIL) THEN
        q := s. req. uri. query(Unparsed.Query). unparsed;
        s. req. params. ParseString (q^, 0, Strings.Length (q^))
      END;
      
      IF (s. req. uri = NIL) THEN
        s. resp. SendError (HTTP.scNotFound,
                            "Not found (%s)", uriString. array^)
      ELSIF (s. req. method = HTTP.methodGET) THEN
        s. servlet. DoGET (s. req, s. resp);
        SendResponse (s. resp, s. port)
      ELSIF (s. req. method = HTTP.methodPOST) THEN
        s. req. contentLength := s. req. GetIntHeader (String.New ("Content-length"));
        IF (s. req. contentLength < 0) THEN
          s. resp. SendError (HTTP.scLengthRequired, "", "")
        ELSE
          s. req. file := Memory.Tmp("", {Memory.read, Memory.write}, res);
          ASSERT (res = Memory.done);
          s. req. writer := s. req. file. NewWriter();
        END
      ELSE
        s. resp. SendError (HTTP.scNotImplemented,
                            "Unsupported method (%s)", s. req. methodString. array^)
      END;
    END EndOfHeaders;
  
  PROCEDURE EndOfBody;
    BEGIN
      s. req. state := receiveComplete;
      
      IF (s. req. method = HTTP.methodPOST) THEN
        s. req. params. ParseString (s. req. file. file. data^,
                                     0, s. req. file. Length());
        s. servlet. DoPOST (s. req, s. resp);
        SendResponse (s. resp, s. port)
      ELSE
        s. resp. SendError (HTTP.scNotImplemented,
                            "Unsupported method (%s)", s. req. methodString. array^)
      END;
    END EndOfBody;
  
  BEGIN
    req := s. req;
    pos := 0;
    WHILE (pos # end) DO
      CASE req. state OF
      | receiveRequestLine:
        i := pos;
        WHILE (i # end) & (b[i] # Ascii.lf) DO
          INC (i)
        END;
        IF (i = end) THEN                (* incomplete line *)
          FOR i := pos TO end-1 DO
            b[i-pos] := b[i]
          END;
          RETURN end-pos
        ELSE                             (* parse complete request line *)
          req. methodString := Str();
          req. method := HTTP.GetMethodCode (req. methodString. array^);
          SkipSP;
          uriString := Str();
          baseURI := URIParser.NewURI (uriString. array^, httpURI, res);
          IF (baseURI # NIL) &
             (baseURI IS HttpURI.URI) &
             baseURI(HttpURI.URI). absolutePath THEN
            req. uri := baseURI(HttpURI.URI);
            req. uri. GetString (str);
          END;
          SkipSP;
          IF (b[pos] < " ") THEN         (* looks like HTTP/0.9 request *)
            req. version := String.New ("HTTP/0.9")
          ELSE
            req. version := Str()
          END;
          pos := i+1;
          req. state := receiveHeaderLine
        END
      
      | receiveHeaderLine:
        LOOP                             (* loop over message headers *)
          i := pos-1;
          REPEAT
            INC (i);
            WHILE (i # end) & (b[i] # Ascii.lf) DO
              INC (i)
            END
          UNTIL (i = end) OR 
                ((i < pos+2) OR (b[i+1] # " ") & (b[i+1] # Ascii.ht));
          IF (i = end) THEN                (* incomplete line *)
            FOR i := pos TO end-1 DO
              b[i-pos] := b[i]
            END;
            RETURN end-pos

          ELSIF (i = pos) THEN             (* request line followed by LF?! *)
            INC (pos);
            EndOfHeaders;
            EXIT

          ELSIF (i = pos+1) & (b[pos] = Ascii.cr) THEN  (* end of headers *)
            INC (pos, 2);
            EndOfHeaders;
            EXIT

          ELSE
            (* extract field name *)
            j := pos;
            WHILE (pos # i) & (b[pos] # ":") DO
              INC (pos)
            END;
            name := String.NewRegion (b^, j, pos);

            (* skip ":" character and following LWS *)
            IF (pos # i) THEN INC (pos) END;
            WHILE (pos # i) & (b[pos] <= " ") DO
              INC (pos)
            END;

            req. buffer. Delete (0, MAX (LONGINT));
            WHILE (pos # i) DO
              j := pos;
              REPEAT
                INC (pos)
              UNTIL (pos = i) OR (b[pos] <= " ");
              req. buffer. AppendRegion (b^, j, pos);
              req. buffer. AppendChar (" ");
              WHILE (pos # i) & (b[pos] <= " ") DO
                INC (pos)
              END
            END;
            IF (req. buffer. length # 0) &
               (req. buffer. array[req. buffer. length-1] = " ") THEN
              req. buffer. Delete (req. buffer. length-1, 1)
            END;
            INC (pos);
            SetHeader (req. headers, name, req. buffer. ToString())
          END
        END
      
      | receiveBody:
        i := end-pos+s. req. file. file. length;
        IF (i >= s. req. contentLength) THEN
          i := s. req. contentLength-s. req. file. file. length;
          s. req. writer. WriteBytes (b^, pos, i);
          INC (pos, i);
          EndOfBody
        ELSE
          s. req. writer. WriteBytes (b^, pos, end-pos);
          pos := end
        END
      
      | receiveComplete:
        (* this should not happen, I'm not sure what to do if it happens; for
           example, Mozilla 0.9.1 adds an additional CR+LF after POSTing a
           form; should these additional bytes be considered part of the
           next request? *)
        RETURN 0
      END
    END;
    RETURN 0
  END IncomingData;


PROCEDURE InitServerFactory (tf: ServerFactory; servlet: Servlet);
  BEGIN
    Port.InitTransferFactory (tf);
    tf. servlet := servlet
  END InitServerFactory;

PROCEDURE NewServerFactory* (servlet: Servlet): Port.TransferFactory;
  VAR
    tf: ServerFactory;
  BEGIN
    NEW (tf);
    InitServerFactory (tf, servlet);
    RETURN tf
  END NewServerFactory;

PROCEDURE (tf: ServerFactory) NewTransfer*(): Server;
  VAR
    s: Server;
  BEGIN
    s := NewServer (tf. servlet);
    RETURN s
  END NewTransfer;

BEGIN
  httpURI := HttpURI.NewPrototype()
END Net:HTTP:Server.
