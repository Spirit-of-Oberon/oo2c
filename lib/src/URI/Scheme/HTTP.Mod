(* 	$Id$	 *)
MODULE URI:Scheme:HTTP;
(*  Implementation of the "file" URI scheme.
    Copyright (C) 2000  Michael van Acken

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
  Ascii, Channel, IntStr, Msg, Strings, TextRider, IO:Socket,
  URI0 := URI, URI:Error, URI:String,
  URI:Scheme:Hierarchical, URI:Authority:ServerBased,
  Query := URI:Query:Unparsed;


TYPE
  URI* = POINTER TO URIDesc;
  URIDesc = RECORD
  (**This class implements the @samp{http:} URI scheme.  It uses
     @otype{ServerBased.Authority} for its authority component, and 
     @otype{Query.Query} for a query part.  *)
    (Hierarchical.GenericDesc)
  END;


CONST
  noServerSpecified = 1;
  unresolvedHostName = 2;
  malformedStatus = 3;
  responseError = 4;
  
VAR
  httpContext: Error.Context;


PROCEDURE Init* (http: URI; schemeId: URI0.StringPtr;
                 authority: URI0.Authority; query: URI0.Query);
  BEGIN
    Hierarchical.Init (http, schemeId, authority, query)
  END Init;

PROCEDURE New* (schemeId: URI0.StringPtr;
                authority: URI0.Authority; query: URI0.Query): URI;
  VAR
    http: URI;
  BEGIN
    NEW (http);
    Init (http, schemeId, authority, query);
    RETURN http
  END New;

PROCEDURE (http: URI) NewAuthority* (): URI0.Authority;
  BEGIN
    RETURN ServerBased.New (NIL, String.Copy (""), -1, 80)
  END NewAuthority;

PROCEDURE (http: URI) NewQuery* (): URI0.Query;
  BEGIN
    RETURN Query.New (String.Copy (""))
  END NewQuery;

PROCEDURE (http: URI) Clone* (): URI;
  VAR
    copy: URI;
  BEGIN
    NEW (copy);
    http. Copy (copy);
    RETURN copy
  END Clone;


PROCEDURE (uri: URI) GetChannel* (mode: URI0.ChannelMode;
                                  VAR res: Error.Msg): Channel.Channel;
(**@precond
   @oparam{uri} is an absoulte URI of the schema @samp{http}.
   @end precond  *)
  CONST
    crlf = Ascii.cr+Ascii.lf;
  VAR
    sock: Socket.Socket;
    addr: Socket.sockaddr_in;
    auth: ServerBased.Authority;
    req: ARRAY 4*1024 OF CHAR;
    number: ARRAY 32 OF CHAR;
    ch: Channel.Channel;
    writer: Channel.Writer;
    textReader: TextRider.Reader;
    i, j: LONGINT;
  
  PROCEDURE Err (code: Error.Code);
    BEGIN
      res := Msg.New (httpContext, code)
    END Err;
  
  PROCEDURE LookingAt (str: ARRAY OF CHAR): BOOLEAN;
    VAR
      j: LONGINT;
    BEGIN
      IF (i >= 0) THEN
        j := 0;
        WHILE (str[j] # 0X) & (req[i] # 0X) & (str[j] = req[i]) DO
          INC (j); INC (i)
        END;
        DEC (i, j);
        RETURN (str[j] = 0X)
      ELSE
        RETURN FALSE
      END
    END LookingAt;
  
  PROCEDURE IsDigit (): BOOLEAN;
    BEGIN
      RETURN (i >= 0) & ("0" <= req[i]) & (req[i] <= "9")
    END IsDigit;
  
  BEGIN
    ch := NIL;
    sock := Socket.New (Socket.AF_INET, Socket.SOCK_STREAM, 0, res);
    
    IF (res = Socket.done) THEN
      IF (uri. authority = NIL) THEN
        Err (noServerSpecified)
      ELSE
        auth := uri. authority(ServerBased.Authority);
        Socket.InitSockAddrINET (addr, auth. host^, auth. port);
        IF (addr. sin_family # Socket.AF_INET) THEN
          Err (unresolvedHostName);
          res. SetStringAttrib ("host", Msg.GetStringPtr (auth. host^))
        END
      END
    END;
    
    IF (res = Socket.done) THEN
      sock. Connect (addr, SIZE (Socket.sockaddr_in))
    END;
    IF (res = Socket.done) THEN
      ch := sock. GetChannel();
      sock. Close();                     (* close fd of socket object *)
      
      (* create GET request *)
      req := "GET ";
      uri. AppendPath (req);
      IF (req[4] = 0X) THEN              (* path is completely empty *)
        Strings.Append ("/", req)
      END;
      Strings.Append (" HTTP/1.0"+crlf, req);
      auth := uri. authority(ServerBased.Authority);
      Strings.Append ("Host: ", req);
      Strings.Append (auth. host^, req);
      IF (auth. port # auth. defaultPort) THEN
        Strings.Append (":", req);
        IntStr.IntToStr (auth. port, number);
        Strings.Append (number, req)
      END;
      Strings.Append (crlf, req);
      Strings.Append (crlf, req);
      writer := ch. NewWriter();
      writer. WriteBytes (req, 0, Strings.Length (req));
      
      (* read status line and extract code and reason phrase; note:
         HTTP/0.9 responses are not accepted *)
      textReader := TextRider.ConnectReader (ch);
      textReader. SetEol (crlf, 2);
      textReader. ReadLine (req);
      IF (textReader. res = TextRider.done) THEN
        i := 0;
        IF LookingAt ("HTTP/") THEN
          i := 5;
          IF IsDigit() THEN
            REPEAT INC (i) UNTIL ~IsDigit()
          ELSE
            i := -1
          END;
          IF LookingAt (".") THEN INC (i) END;
          IF IsDigit() THEN
            REPEAT INC (i) UNTIL ~IsDigit()
          ELSE
            i := -1
          END;
          IF LookingAt (" ") THEN INC (i) END;
          FOR j := 1 TO 3 DO
            IF IsDigit() THEN
              INC (i)
            ELSE
              i := -1
            END
          END;
          IF LookingAt (" ") THEN INC (i) END;
          
          IF (i = -1) THEN
            Err (malformedStatus)
          ELSIF (req[i-4] # "2") THEN  (* non-success response *)
            Err (responseError);
            Strings.Extract (req, SHORT (i-4),
                             Strings.Length (req)-SHORT (i-4), req);
            res. SetStringAttrib ("status", Msg.GetStringPtr (req))
          END
        END
      END;
      
      (* skip header lines *)
      WHILE (textReader. res = TextRider.done) & (req # "") DO
        textReader. ReadLine (req)
      END;
      
      IF (textReader. res # TextRider. done) THEN
        res := textReader. res
      ELSE
        RETURN ch
      END
    END;
    RETURN NIL
  END GetChannel;
  
PROCEDURE NewPrototype*(): URI;
  BEGIN
    RETURN New (String.Copy ("http"), NIL, NIL)
  END NewPrototype;

BEGIN
  URI0.RegisterScheme (NewPrototype());
  
  httpContext := Error.NewContext ("URI:Scheme:HTTP");
  httpContext. SetString (noServerSpecified,
    "No server name specified");
  httpContext. SetString (unresolvedHostName,
    "Could not resolve host name `${host}'");
  httpContext. SetString (malformedStatus,
    "Malformed status line in response");
  httpContext. SetString (responseError,
    "HTTP request failed: ${status}");
END URI:Scheme:HTTP.
