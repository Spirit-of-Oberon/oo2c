MODULE Net:NNTP;

IMPORT
  SYS:=SYSTEM, Ascii, CharClass, IntStr, Object, Exception,
  ADT:StringBuffer, IO, IO:Address, IO:SocketChannel;

(* NNTP client supports synchronous and asynchronous operation, incremental
   processing of large requests or responses, and multiplexing with other
   socket connections. *)
  
CONST
  textCapacity = 8*1024-32;
  bufferCapacity = 8*1024;  (* most be larger than longest line *)
  maxLineLength = textCapacity-2;
  defaultPort* = 119;
  
TYPE
  Msg = POINTER TO MsgDesc;
  MsgDesc = RECORD
    nextMsg: Msg;
  END;
  
TYPE
  Response* = POINTER TO ResponseDesc;
  ResponseDesc = RECORD
    (**Represents an NNTP response.  *)
    (MsgDesc)
    statusLine-: Object.String8;
    (**The first line of the response, as received from the NNTP server.
       The end of line characters have been stripped.  *)
    status-: LONGINT;
    (**The integer status code.  *)
    long: BOOLEAN;
  END;

TYPE
  Request = POINTER TO RequestDesc;
  RequestDesc = RECORD [ABSTRACT]
    (**Represents an NNTP request.  *)
    (MsgDesc)
    command: Object.String8;
    long: BOOLEAN;
    response-: Response;
    (* Refers to the associated response object, once it has been received.
       Until then, this field is @code{NIL}.  *)
  END;

TYPE
  Text* = POINTER TO TextDesc;
  TextDesc = RECORD
    (**A chunk of text data of a long response or a long request.  *)
    (MsgDesc)
    length*: LONGINT;
    (**Number of valid characters in @ofield{data}.  A number in the range
       @samp{0 <= @ofield{length} <= LEN(@ofield{data})}.  *)
    last*: BOOLEAN; 
    (**If @code{TRUE}, then this chunk is the last part of the response or
       request.  For a request, this means that the message is complete and
       must terminted with a single @samp{.} (dot) on a line by itself.  For a
       response, it means that no further text data follows.  *)
    data*: ARRAY textCapacity OF CHAR;
    (**Text data.  A number of lines, using @oconst{eol} as their end of
       line marker.  The class @otype{Client} is responsible for encoding this
       data for NNTP's over the wire protocol (that is, using CRLF at end of
       line, doubling a @samp{.} at the beginning of the line, and closing
       a long message with a @samp{.} on a line by itself).  *)
  END;
  
TYPE
  Client* = POINTER TO ClientDesc;
  ClientDesc* = RECORD
    serverAddr: Address.SocketInet;
    
    async-: BOOLEAN;
    (**If @code{FALSE}, connects and requests are processed synchronously.  A
       method implementing a request returns only if the status line of the
       response has been received.  Note: The interface for requests that
       include a text part is more complicated than this.

       In asynchronous mode, requests are queued for processing and the
       initiating method returns immediately.  *)

    welcome-: Object.String8;
    (**The text received from the server after connecting.  *)
    
    postingAllowed-: BOOLEAN;
    (**Set to @code{TRUE} if the server's welcome message indicates that
       it allows posting.  *)
    
    channel: SocketChannel.Channel;
    
    rLen: LONGINT;    (* number of valid bytes in `r'; 0<=rLen<=LEN(r) *)
    rLine: LONGINT;   (* start of current line; 0<=rLine<=rLen *)
    rPos: LONGINT;    (* current scanning position; rLine<=rPos<=rLen *)
    rText: Text;      (* if #NIL: rLine is in text part of a response *)
    sPos: LONGINT;    (* position of first unset char in `waiting' *)
    sLen: LONGINT;    (* number of valid bytes in `r'; 0<=sLen<=LEN(s) *)
    s, r: ARRAY bufferCapacity OF CHAR;
    waiting, sent: Msg;
  END;

TYPE
  ProtocolError* = POINTER TO ProtocolErrorDesc;
  ProtocolErrorDesc = RECORD
  (**Raised if malformed data is received from the remote server.  This is
     @emph{not} used for responses that indicate failure to process a request.
     Examples for a protocol error is a response message that does not begin
     with a three digit status code.  After such an error, the connection to
     the server should be closed immediately.  *)
    (Exception.ExceptionDesc)
  END;

TYPE
  ErrorResponse* = POINTER TO ErrorResponseDesc;
  ErrorResponseDesc = RECORD
  (**Raised if the response from the server indicates an error.  All status
     code @samp{3xx}, @samp{4xx}, and @samp{5xx} trigger this exception.  This
     means that associated request has been processed, with a negative
     outcome.  The complete response can be accessed through
     @ofield{request}'s response entry.  *)
    (Exception.ExceptionDesc)
    request-: Request;
  END;

(* Request Classes
   ------------------------------------------------------------------------ *)
  
TYPE
  Connect = POINTER TO ConnectDesc;
  ConnectDesc = RECORD
    (RequestDesc) 
  END;
  
TYPE
  Group* = POINTER TO GroupDesc;
  GroupDesc = RECORD
    (RequestDesc)
    msgCount-, first-, last-: LONGINT;
    name-: Object.String8;
  END;
  
TYPE
  XHdr* = POINTER TO XHdrDesc;
  XHdrDesc = RECORD
    (RequestDesc)
    msgCount-, first-, last-: LONGINT;
    name-: Object.String8;
  END;
  
TYPE
  Article* = POINTER TO ArticleDesc;
  ArticleDesc = RECORD
    (RequestDesc)
  END;
  
TYPE
  Quit* = POINTER TO QuitDesc;
  QuitDesc = RECORD
    (RequestDesc)
  END;
  

CONST
  eol* = Ascii.lf;
  respXHDR = 221;
  respARTICLE =220;

PROCEDURE (cl: Client) LogRequest*(cmd: Object.String8);
  END LogRequest;

PROCEDURE (cl: Client) LogResponse*(statusLine: Object.String8);
  END LogResponse;

PROCEDURE RaiseProtocolError(msg: STRING) RAISES ProtocolError;
  VAR
    e: ProtocolError;
  BEGIN
    NEW(e);
    Exception.Init(e, msg);
    RAISE(e);
  END RaiseProtocolError;

PROCEDURE InitMsg(msg: Msg);
  BEGIN
    msg.nextMsg := NIL;
  END InitMsg;

PROCEDURE NewText*(): Text;
  VAR
    t: Text;
  BEGIN
    NEW(t);
    InitMsg(t);
    t.length := 0;
    t.last := FALSE;
    RETURN t;
  END NewText;

PROCEDURE InitRequest(req: Request; cmd: Object.String8; long: BOOLEAN);
  BEGIN
    InitMsg(req);
    req.command := cmd;
    req.long := long;
    req.response := NIL;
  END InitRequest;

PROCEDURE (req: Request) ParseStatus(resp: Response) RAISES ProtocolError;
  BEGIN
  END ParseStatus;

PROCEDURE InitResponse(resp: Response; VAR b: ARRAY OF CHAR;
                       start, end: LONGINT; status: LONGINT; long: BOOLEAN);
  BEGIN
    InitMsg(resp);
    resp.statusLine := Object.NewLatin1Region(b, start, end);
    resp.status := status;
    resp.long := long;
  END InitResponse;

PROCEDURE NewResponse(VAR b: ARRAY OF CHAR; start, end: LONGINT;
                      status: LONGINT; long: BOOLEAN): Response;
  VAR
    resp: Response;
  BEGIN
    NEW(resp);
    InitResponse(resp, b, start, end, status, long);
    RETURN resp;
  END NewResponse;

PROCEDURE InitClient*(cl: Client; serverAddr: Address.SocketInet;
                      async: BOOLEAN);
  BEGIN
    cl.serverAddr := serverAddr;
    cl.async := async;
    cl.welcome := NIL;
    cl.postingAllowed := FALSE;
    cl.channel := NIL;
  END InitClient;

PROCEDURE NewClient*(serverAddr: Address.SocketInet;
                     async: BOOLEAN): Client;
  VAR
    cl: Client;
  BEGIN
    NEW(cl);
    InitClient(cl, serverAddr, async);
    RETURN cl;
  END NewClient;

PROCEDURE Append(VAR list: Msg; msg: Msg);
  VAR
    ptr: Msg;
  BEGIN
    msg.nextMsg := NIL;
    IF (list = NIL) THEN
      list := msg;
    ELSE
      ptr := list;
      WHILE (ptr.nextMsg # NIL) DO
        ptr := ptr.nextMsg;
      END;
      ptr.nextMsg := msg;
    END;
  END Append;

PROCEDURE SendMsg(cl: Client) RAISES IO.Error;
  VAR
    pos, start, copy, dest, left, i: LONGINT;
    msg, ptr: Msg;
    chars: Object.CharsLatin1;
  BEGIN
    pos := cl.sPos; dest := cl.sLen;
    WHILE (cl.waiting # NIL) DO
      LOOP
        msg := cl.waiting;
        WITH msg: Request DO
          chars := msg.command.CharsLatin1();
          copy := msg.command.length-pos;
          left := LEN(cl.s)-dest;
          IF (copy+2 > left) THEN
            (* command line doesn't fit into buffer: copy as much as possible
               and leave loop *)
            IF (left < copy) THEN
              copy := left;
            END;
            SYS.MOVE(SYS.ADR(chars^)+pos, SYS.ADR(cl.s)+dest, copy);
            INC(pos, copy);
            INC(dest, copy);
            EXIT;
          ELSE  (* rest of command plus CRLF fits into buffer *)
            SYS.MOVE(SYS.ADR(chars^)+pos, SYS.ADR(cl.s)+dest, copy);
            INC(dest, copy);
            cl.s[dest] := Ascii.cr;
            cl.s[dest+1] := Ascii.lf;
            INC(dest, 2);

            cl.LogRequest(msg.command);
            ptr := cl.waiting;
            cl.waiting := cl.waiting.nextMsg;
            Append(cl.sent, ptr);
            pos := 0;
            IF (cl.waiting = NIL) THEN
              EXIT;
            END;
          END;
        ELSE
          ASSERT(FALSE);
        END;
      END;

      start := 0;
      WHILE (start # dest) DO
        i := cl.channel.Write(cl.s, start, dest-start);
        ASSERT(i >= 0);
        INC(start, i);
      END;
      dest := 0;
    END;
    cl.sPos := pos; cl.sLen := dest;
  END SendMsg;

PROCEDURE (cl: Client) SendRequest*(req: Request) RAISES IO.Error;
  BEGIN
    Append(cl.waiting, req);
    SendMsg(cl);
  END SendRequest;

PROCEDURE (cl: Client) SendText*(text: Text);
  BEGIN
  END SendText;

PROCEDURE GetResponse(cl: Client; start, end: LONGINT): Response
RAISES ProtocolError;
  VAR
    status: LONGINT;
    long: BOOLEAN;
    resp: Response;
  BEGIN
    IF (end-start >= 3) &
       CharClass.IsNumeric(cl.r[start]) &
       CharClass.IsNumeric(cl.r[start+1]) &
       CharClass.IsNumeric(cl.r[start+2]) &
       ((end-start = 3) OR (cl.r[start+3] <= " ")) THEN
      status := (ORD(cl.r[start])-ORD("0"))*100+
          (ORD(cl.r[start+1])-ORD("0"))*10+
          (ORD(cl.r[start+2])-ORD("0"));
      long := (status=respXHDR) OR (status=respARTICLE);
      IF long THEN
        cl.rText := NewText();
      END;
      resp := NewResponse(cl.r, start, end, status, long);
      RETURN resp;
    ELSE
      RaiseProtocolError("No status code: "+
                         Object.NewLatin1Region(cl.r, start, end));
      RETURN NIL;
    END;
  END GetResponse;

PROCEDURE GetMsg(cl: Client): Msg RAISES IO.Error, ProtocolError;
(**Retrieves the next response or chunk of text from the socket.  Undos NNTP
   encoding (CRLF -> LF, ".." --> "." at beginning of line).  Beyond a basic
   check that the status line of a response begins with a 3 digit code, no
   parsing is done.  *)
  VAR
    line, pos, len, end, i, copy: LONGINT;
    msg: Msg;
  BEGIN
    line := cl.rLine; pos := cl.rPos; len := cl.rLen;
    
    LOOP
      (* pre: line is the starting position of the current line *)
      WHILE (pos # len) & (cl.r[pos] # Ascii.lf) DO
        INC(pos);
      END;

      IF (pos # len) THEN  (* we reached the end of a complete line *)
        (* make `end' point at the beginning of the eol sequence *)
        end := pos;
        IF (end > line) & (cl.r[end-1] = Ascii.cr) THEN
          DEC(end);
        END;

        (* here holds: r[line,end[ holds a complete line of data, minus eol *)
        IF (cl.rText # NIL) THEN
          IF (end = line+1) & (cl.r[line] = ".") THEN (* end of text *)
            cl.rText.last := TRUE;
            msg := cl.rText;
            cl.rText := NIL;
            INC(pos); line := pos;
            EXIT;
          ELSE                           (* line of text *)
            IF (cl.r[line] = ".") & (cl.r[line+1] = ".") THEN
              INC(line);    (* undo double "." at beginning of line *)
            END;
            IF (cl.rText.length+(end-line)+1 > LEN(cl.rText.data))  THEN
              (* line does not fit into current text block *)
              IF (end-line > maxLineLength) THEN
                RaiseProtocolError("Line too long");
              ELSE
                cl.rText.last := FALSE;
                msg := cl.rText;
                cl.rText := NewText();
                EXIT;
              END;
            ELSE
              copy := end-line;
              SYS.MOVE(SYS.ADR(cl.r)+line,
                       SYS.ADR(cl.rText.data)+cl.rText.length,
                       end-line);
              INC(cl.rText.length, copy);
              cl.rText.data[cl.rText.length] := eol;
              INC(cl.rText.length);
              INC(pos); line := pos;
            END;
          END;
        ELSE                             (* status line of response *)
          msg := GetResponse(cl, line, end);
          cl.LogResponse(msg(Response).statusLine);
          INC(pos); line := pos;
          EXIT;
        END;

      ELSE
        (* no data or incomplete line: move remaning data to beginning
           of buffer and read more from the socket *)
        FOR i := line TO len-1 DO
          cl.r[i-line] := cl.r[i];
        END;
        DEC(pos, line);
        DEC(len, line);
        line := 0;
        i := cl.channel.Read(cl.r, len, LEN(cl.r)-len);
        ASSERT(i > 0);
        INC(len, i);
      END;
    END;

    cl.rLine := line; cl.rPos := pos; cl.rLen := len;
    RETURN msg;
  END GetMsg;

PROCEDURE (cl: Client) RetrieveResponse*(): Response
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    msg: Msg;
    resp: Response;
    req: Request;
    e: ErrorResponse;
  BEGIN
    msg := GetMsg(cl);
    resp := msg(Response);
    
    IF (cl.sent = NIL) THEN
      RaiseProtocolError("Response without prior request: "+resp.statusLine);
    ELSE
      req := cl.sent(Request);
      req.response := resp;
      cl.sent := cl.sent.nextMsg;
      IF (resp.status >= 300) THEN       (* negative response *)
        NEW(e);
        Exception.Init(e, resp.statusLine);
        e.request := req;
        RAISE(e);
      ELSIF (req IS Connect) THEN        (* special case: welcome message *)
        cl.welcome := resp.statusLine;
        cl.postingAllowed := (resp.status = 200);
      ELSE                               (* request specific parsing *)
        req.ParseStatus(resp);
      END;
    END;
    RETURN resp;
  END RetrieveResponse;

PROCEDURE (cl: Client) RetrieveText*(): Text
RAISES IO.Error, ProtocolError;
  (**Retrieves the next text chunk of the current response.  The chunk contains
     an integral number of lines.  That is, it is either empty, or the first
     character of the chunk is the first of a line and character
     @samp{text.data[text.length-1]} is @oconst{eol}.

     @precond
     The current response is of type ``long'', and no text chunk has been
     retrieved with a @ofield{Text.last} of @code{TRUE}.
     @end precond  *)
  VAR
    msg: Msg;
  BEGIN
    msg := GetMsg(cl);
    RETURN msg(Text);
  END RetrieveText;

PROCEDURE (cl: Client) Connect*()
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    resp: Response;
    connect: Connect;
  BEGIN
    cl.channel := SocketChannel.Connect(cl.serverAddr);
    cl.sPos := 0; cl.sLen := 0;
    cl.rLine := 0; cl.rPos := 0; cl.rLen := 0; cl.rText := NIL;
    cl.waiting := NIL; cl.sent := NIL;

    NEW(connect);
    InitRequest(connect, NIL, FALSE);
    cl.sent := connect;
    IF ~cl.async THEN
      resp := cl.RetrieveResponse();
    END;
  END Connect;

PROCEDURE (cl: Client) Close*() RAISES IO.Error;
  BEGIN
    cl.channel.Close();
    cl.channel := NIL;
  END Close;


PROCEDURE ShortRequest(cl: Client; req: Request)
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    resp: Response;
  BEGIN
    ASSERT(~req.long);
    cl.SendRequest(req);
    resp := cl.RetrieveResponse();
  END ShortRequest;

PROCEDURE SkipWhitespace(params: Object.CharsLatin1; VAR pos: LONGINT);
  BEGIN
    WHILE (params[pos] # 0X) & (params[pos] <= " ") DO
      INC(pos);
    END;
  END SkipWhitespace;

PROCEDURE SkipStatus(params: Object.CharsLatin1): LONGINT;
  VAR
    pos: LONGINT;
  BEGIN
    pos := 3;
    SkipWhitespace(params, pos);
    RETURN pos;
  END SkipStatus;

PROCEDURE GetInt(params: Object.CharsLatin1; VAR pos: LONGINT): LONGINT
RAISES ProtocolError;
  VAR
    str: ARRAY 16 OF CHAR;
    start, i: LONGINT;
    res: IntStr.ConvResults;
  BEGIN
    (* skip any redundant leading zeros *)
    WHILE (params[pos] = "0") & (params[pos+1] = "0") DO
      INC(pos);
    END;
    
    start := pos; i := 0;
    WHILE (params[pos] > " ") DO
      IF (i < LEN(str)-1) THEN
        str[i] := params[pos]; INC(i);
      END;
      INC(pos);
    END;
    str[i] := 0X;
    
    IntStr.StrToInt(str, i, res);
    IF (res # IntStr.strAllRight) THEN
      RaiseProtocolError("Invalid number");
    ELSE
      SkipWhitespace(params, pos);
      RETURN i;
    END;
  END GetInt;

PROCEDURE GetString(params: Object.CharsLatin1; VAR pos: LONGINT): Object.String8;
  VAR
    start, e: LONGINT;
  BEGIN
    start := pos;
    WHILE (params[pos] > " ") DO
      INC(pos);
    END;
    e := pos;
    SkipWhitespace(params, pos);
    RETURN Object.NewLatin1Region(params^, start, e);
  END GetString;

(* Commands
   ------------------------------------------------------------------------ *)

PROCEDURE (req: Group) ParseStatus(resp: Response) RAISES ProtocolError;
  VAR
    params: Object.CharsLatin1;
    pos: LONGINT;
  BEGIN
    params := resp.statusLine.CharsLatin1();
    pos := SkipStatus(params);
    req.msgCount := GetInt(params, pos);
    req.first := GetInt(params, pos);
    req.last := GetInt(params, pos);
    req.name := GetString(params, pos);
  END ParseStatus;

PROCEDURE (cl: Client) Group*(name: STRING): Group
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    req: Group;
    cmd: STRING;
  BEGIN
    NEW(req);
    cmd := "group "+name;
    InitRequest(req, cmd(Object.String8), FALSE);
    req.msgCount := -1;
    req.first := -1;
    req.last := -1;
    req.name := NIL;
    ShortRequest(cl, req);
    RETURN req;
  END Group;


PROCEDURE (req: XHdr) ParseLine*(text: Text; VAR pos: LONGINT;
                                 VAR msgId, startHeader, endHeader: LONGINT)
RAISES ProtocolError;
  VAR
    str: ARRAY 16 OF CHAR;
    start, i: LONGINT;
    res: IntStr.ConvResults;
  BEGIN
    start := pos; i := 0;
    WHILE (pos # text.length) & CharClass.IsNumeric(text.data[pos]) DO
      IF (i < LEN(str)) THEN
        str[i] := text.data[pos];
      END;
      INC(pos); INC(i);
    END;
    IF (i = LEN(str)) THEN
      RaiseProtocolError("Message id too long");
    ELSE
      str[i] := 0X;
      IntStr.StrToInt(str, msgId, res);
      IF (res = IntStr.strAllRight) THEN
        IF (pos # text.length) & (text.data[pos] <= " ") THEN
          INC(pos);
        END;
        startHeader := pos;

        WHILE (pos # text.length) & (text.data[pos] # eol) DO
          INC(pos);
        END;
        endHeader := pos;

        IF (pos # text.length) THEN
          INC(pos);
        END;
      ELSE
        RaiseProtocolError("Invalid message id");
      END;
    END;
  END ParseLine;

PROCEDURE (cl: Client) XHdr*(header: STRING; lower, upper: LONGINT): XHdr
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    req: XHdr;
    cmd: STRING;
    b: StringBuffer.StringBuffer;
  BEGIN
    b := StringBuffer.New("xhdr ");
    b.Append(header);
    b.AppendLatin1Char(" ");
    b.AppendInt(lower);
    b.AppendLatin1Char("-");
    b.AppendInt(upper);
    cmd := b.ToString();
    
    NEW(req);
    InitRequest(req, cmd(Object.String8), FALSE);
    ShortRequest(cl, req);
    RETURN req;
  END XHdr;


PROCEDURE (cl: Client) Article*(msgId: LONGINT): Article
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    req: Article;
    cmd: STRING;
    b: StringBuffer.StringBuffer;
  BEGIN
    b := StringBuffer.New("article ");
    b.AppendInt(msgId);
    cmd := b.ToString();
    
    NEW(req);
    InitRequest(req, cmd(Object.String8), FALSE);
    ShortRequest(cl, req);
    RETURN req;
  END Article;


PROCEDURE (cl: Client) Quit*(): Quit
RAISES IO.Error, ProtocolError, ErrorResponse;
  VAR
    req: Quit;
    cmd: STRING;
  BEGIN
    NEW(req);
    cmd := "quit";
    InitRequest(req, cmd(Object.String8), FALSE);
    ShortRequest(cl, req);
    RETURN req;
  END Quit;

END Net:NNTP.
