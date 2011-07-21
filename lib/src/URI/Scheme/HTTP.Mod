(* 	$Id: HTTP.Mod,v 1.5 2003/06/03 21:05:31 mva Exp $	 *)
MODULE URI:Scheme:HTTP;
(*  Implementation of the "file" URI scheme.
    Copyright (C) 2000, 2003  Michael van Acken

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
  Ascii, IntStr, Object, ADT:StringBuffer, IO, IO:Address, IO:SocketChannel,
  IO:Buffer, URI0 := URI, URI:Scheme:Hierarchical, URI:Authority:ServerBased,
  Query := URI:Query:Unparsed;

TYPE
  URI* = POINTER TO URIDesc;
  URIDesc = RECORD
  (**This class implements the @samp{http:} URI scheme.  It uses
     @otype{ServerBased.Authority} for its authority component, and 
     @otype{Query.Query} for a query part.  *)
    (Hierarchical.GenericDesc)
  END;


PROCEDURE Init* (http: URI; schemeId: STRING;
                 authority: URI0.Authority; query: URI0.Query);
  BEGIN
    Hierarchical.Init (http, schemeId, authority, query)
  END Init;

PROCEDURE New* (schemeId: STRING;
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
    RETURN ServerBased.New (NIL, "", -1, 80)
  END NewAuthority;

PROCEDURE (http: URI) NewQuery* (): URI0.Query;
  BEGIN
    RETURN Query.New ("")
  END NewQuery;

PROCEDURE (http: URI) Clone* (): URI;
  VAR
    copy: URI;
  BEGIN
    NEW (copy);
    http. Copy (copy);
    RETURN copy
  END Clone;


PROCEDURE (uri: URI) GetChannel* (mode: URI0.ChannelMode): Buffer.Channel
RAISES IO.Error;
(**@precond
   @oparam{uri} is an absoulte URI of the schema @samp{http}.
   @end precond  *)
  CONST
    crlf = Ascii.cr+Ascii.lf;
  VAR
    sock: SocketChannel.Channel;
    auth: ServerBased.Authority;
    addr: Address.Socket;
    connected: BOOLEAN;
    req: StringBuffer.StringBuffer;
    chars: StringBuffer.CharsLatin1;
    done: LONGINT;
    ch: Buffer.Channel;
    str8: Object.String8;
    resp: Object.CharsLatin1;
    number: ARRAY 32 OF CHAR;
    i, j: LONGINT;
  
  PROCEDURE LookingAt (str: ARRAY OF CHAR): BOOLEAN;
    VAR
      j: LONGINT;
    BEGIN
      IF (i >= 0) THEN
        j := 0;
        WHILE (str[j] # 0X) & (resp[i] # 0X) & (str[j] = resp[i]) DO
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
      RETURN (i >= 0) & ("0" <= resp[i]) & (resp[i] <= "9")
    END IsDigit;
  
  BEGIN
    sock := SocketChannel.Open();
    
    IF (uri. authority = NIL) THEN
      RAISE(NEW(IO.Error, "No server name specified"));
    ELSE
      auth := uri. authority(ServerBased.Authority);
      addr := Address.GetSocketInet
          (Address.GetByName(auth.host.ToString8("?")), auth.port);
    END;
    
    connected := sock.Connect(addr);
    ASSERT(connected);
    
    (* create GET request *)
    req := StringBuffer.New("GET ");
    uri.AppendPath(req);
    IF (req.length = 4) THEN              (* path is completely empty *)
      req.Append("/");
    END;
    req.Append(" HTTP/1.0"+crlf);
    auth := uri.authority(ServerBased.Authority);
    req.Append("Host: ");
    req.Append(auth.host);
    IF (auth.port # auth.defaultPort) THEN
      req.Append(":");
      IntStr.IntToStr(auth.port, number);
      req.AppendLatin1(number);
    END;
    req.Append (crlf+crlf);              (* empty line ends request *)
    chars := req.CharsLatin1();
    done := sock.Write(chars^, 0, req.length);
    ASSERT(done = req.length);
    
    (* read status line and extract code and reason phrase; note:
       HTTP/0.9 responses are not accepted *)
    ch := Buffer.Open(sock);
    str8 := ch.ReadLineLF();
    IF (str8 # NIL) THEN
      resp := str8.CharsLatin1();
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
          RAISE(NEW(IO.FormatError, "Malformed status line in response"));
        ELSIF (resp[i-4] # "2") THEN  (* non-success response *)
          RAISE(NEW(IO.ErrorResponse,
                    "HTTP request failed: "+str8.Substring(i-4, str8.length)));
        END;
      END;
    END;
    
    (* skip header lines; empty line contains only 2 characters: CR+LF *)
    WHILE (str8 # NIL) & (str8.length > 2) DO
      str8 := ch.ReadLineLF();
    END;
    
    RETURN ch;
  END GetChannel;
  
PROCEDURE NewPrototype*(): URI;
  BEGIN
    RETURN New ("http", NIL, NIL)
  END NewPrototype;

END URI:Scheme:HTTP.
