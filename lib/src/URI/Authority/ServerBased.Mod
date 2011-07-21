(* 	$Id: ServerBased.Mod,v 1.3 2003/05/22 20:17:54 mva Exp $	 *)
MODULE URI:Authority:ServerBased;
(*  Implements class for registry-based authority components.
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
  IntStr, TextRider, CC := CharClass, Object, Exception, ADT:StringBuffer,
  URI, URI:CharClass, URI:String;

CONST
  defaultPort = -1;

TYPE
  Port* = LONGINT;
  Authority* = POINTER TO AuthorityDesc;
  AuthorityDesc* = RECORD
  (**Server-based authority component of an URI.  *)
    (URI.AuthorityDesc)
    userinfo-: STRING;
    (**Userinfo from authority component.  @code{NIL} if no userinfo is
       given.  *)
    host-: STRING;
    (**Host part.  This is never @code{NIL}.  *)
    port-: Port;
    (**Port number.  If the port is part of the authority component, this
       field holds this number.  Otherwise, it is set to
       @ofield{defaultPort}.  *)
    defaultPort-: Port;
    (**Default port.  If the URI's authority component does not include a
       port number, this value is used instead.  *)
  END;


PROCEDURE Init* (auth: Authority; userinfo, host: STRING; port, defaultPort: Port);
  BEGIN
    ASSERT (host # NIL);
    auth. userinfo := userinfo;
    auth. host := host;
    auth. port := port;
    auth. defaultPort := defaultPort
  END Init;

PROCEDURE New* (userinfo, host: STRING; port, defaultPort: Port): Authority;
(**Creates a new server-based authority component.  The arguments
   @oparam{userinfo}, @oparam{host}, @oparam{port}, and @oparam{defaultPort}
   are used to initialize the corresponding fields of a new instance of
   @otype{Authority}.

   @precond
   @oparam{host} must not be @code{NIL}.
   @end precond  *)
  VAR
    auth: Authority;
  BEGIN
    NEW (auth);
    Init (auth, userinfo, host, port, defaultPort);
    RETURN auth
  END New;

PROCEDURE (auth: Authority) Clone* (): Authority;
  VAR
    copy: Authority;
  BEGIN
    NEW (copy);
    auth. Copy (copy);
    RETURN copy
  END Clone;

PROCEDURE (auth: Authority) Copy* (dest: URI.Authority);
  BEGIN
    (*auth. Copy^ (dest); procedure is abstract in super class *)
    WITH dest: Authority DO
      IF (auth. userinfo # NIL) THEN
        dest. userinfo := auth.userinfo;
      ELSE
        dest. userinfo := NIL
      END;
      IF (dest. host # NIL) THEN
        dest. host := auth.host;
      ELSE
        dest. host := NIL
      END;
      dest. port := auth. port;
      dest. defaultPort := auth. defaultPort
    END
  END Copy;

PROCEDURE ParseHost (str: Object.CharsLatin1; offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    i, j, lastLabelStart: URI.Offset;
    
  PROCEDURE IsIPv4Address (str: Object.CharsLatin1): BOOLEAN;
    VAR
      i: URI.Offset;
    BEGIN
      i := 0;
      WHILE (str[i] # 0X) DO
        IF ~CharClass.IsDigit (str[i]) & (str[i] # ".") THEN
          RETURN FALSE
        END;
        INC (i)
      END;
      RETURN TRUE
    END IsIPv4Address;
  
  PROCEDURE SkipDigits (): BOOLEAN;
    VAR
      start, val: INTEGER;
    BEGIN
      IF CharClass.IsDigit (str[i]) &
         ((str[i] # "0") OR ~CharClass.IsDigit (str[i+1])) THEN
        start := i;
        val := 0;
        REPEAT
          IF (val < 1000) THEN
            val := val*10 + ORD(str[i])-ORD("0")
          END;
          INC (i)
        UNTIL ~CharClass.IsDigit (str[i]);
        IF (val > 255) THEN
          i := start                     (* fix error position, return FALSE *)
        ELSE
          RETURN TRUE
        END
      END;
      RETURN FALSE
    END SkipDigits;
  
  PROCEDURE SkipLabel(): BOOLEAN;
    BEGIN
      IF CharClass.IsAlpha (str[i]) THEN
        REPEAT
          INC (i)
        UNTIL ~CharClass.IsAlphaNum (str[i]) & (str[i] # "-");
        IF ~CharClass.IsAlphaNum (str[i-1]) THEN
          DEC (i)                        (* fix error pos and return FALSE *)
        ELSE
          RETURN TRUE
        END
      END;
      RETURN FALSE
    END SkipLabel;

  PROCEDURE ErrorIPv4() RAISES Exception.ParseError;
    BEGIN
      RAISE(NEW(Exception.ParseError,
                "Malformed IPv4 address in authority component", i+offset));
    END ErrorIPv4;
  
  BEGIN
    i := 0;
    IF IsIPv4Address (str) THEN
      FOR j := 1 TO 4 DO
        IF ~SkipDigits() THEN
          ErrorIPv4();
        END;
        IF (j < 4) THEN
          IF (str[i] = ".") THEN
            INC (i)
          ELSE
            ErrorIPv4();
          END
        END
      END
    ELSE
      LOOP
        lastLabelStart := i;
        IF ~SkipLabel() THEN
          ErrorIPv4();
        END;
        IF (str[i] = ".") THEN
          INC (i);
          IF (str[i] = 0X) OR (str[i] = ":") THEN
            EXIT
          END
        ELSE
          EXIT
        END
      END;
      IF ~CharClass.IsAlpha (str[lastLabelStart]) THEN
        RAISE(NEW(Exception.ParseError,
                  "Malformed host name in authority component", i+offset));
      END
    END;
  END ParseHost;

PROCEDURE (auth: Authority) ParseAuthority* (str: Object.CharsLatin1;
                                             offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    i, start: INTEGER;
    userinfo: STRING;
    host: Object.String8;
    port: LONGINT;
  BEGIN
    CASE str[0] OF
    | "/", "?", "#", 0X: RETURN;       (* "server" expands to empty *)
    ELSE                               (* continue *)
    END;
    
    i := 0;
    WHILE (str[i] # 0X) & (str[i] # "@") DO
      INC (i)
    END;
    
    userinfo := NIL;
    IF (str[i] # 0X) THEN
      (* the authority component includes a user info part *)
      i := 0;
      WHILE CharClass.SkipUnreserved (str^, i) OR
            CharClass.SkipEscaped (str^, i) OR
            CharClass.SkipMember (str^, i, ";:&=+$,") DO
      END;
      IF (str[i] = "@") THEN
        userinfo := String.Unescape (Object.NewLatin1Region(str^, 0, i));
        INC (i)
      ELSE
        RAISE(NEW(Exception.ParseError,
                  "Illegal character in user info part of authority component",
                  i+offset));
      END
    ELSE                                 (* no user info *)
      i := 0
    END;
    
    start := i;
    WHILE (str[i] # 0X) & (str[i] # ":") DO
      INC (i)
    END;
    IF (i = start) THEN
      RAISE(NEW(Exception.ParseError,
                "Host name in authority component is empty", i+offset));
    ELSE
      host := Object.NewLatin1Region(str^, start, i);
      ParseHost (host.CharsLatin1(), offset+start);
    END;
    
    port := defaultPort;
    IF (str[i] = ":") THEN
      INC (i);
      start := i+1;
      IF (str[i] # 0X) THEN
        port := 0;
        WHILE CharClass.IsDigit (str[i]) DO
          IF (port < 1000000) THEN
            port := port*10+ORD(str[i])-ORD("0")
          END;
          INC (i)
        END;
        IF (port > 65535) THEN
          RAISE(NEW(Exception.ParseError,
                    "Port number out of range in authority component",
                    start+offset));
        END
      END
    END;
    
    IF (str[i] # 0X) THEN
      RAISE(NEW(Exception.ParseError,
                "Junk after authority component", i+offset));
    END;
    
    auth. userinfo := userinfo;
    auth. host := host;
    IF (port = defaultPort) THEN
      auth. port := auth. defaultPort
    ELSE
      auth. port := port
    END;
  END ParseAuthority;

PROCEDURE (auth: Authority) WriteXML* (w: TextRider.Writer);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    w. WriteString (CC.eol+"<authority-server-based>");
    IF (auth. userinfo # NIL) THEN
      w. WriteString (CC.eol+"<userinfo>");
      w. WriteObject (auth. userinfo);
      w. WriteString ("</userinfo>");
    END;
    w. WriteString (CC.eol+"<host>");
    w. WriteObject (auth. host);
    w. WriteString ("</host>");
    IF (auth. port >= 0) THEN
      w. WriteString (CC.eol+"<port>");
      IntStr.IntToStr (auth. port, str);
      w. WriteString (str);
      w. WriteString ("</port>");
    END;
    w. WriteString (CC.eol+"</authority-server-based>");
  END WriteXML;

PROCEDURE (auth: Authority) Append* (sb: StringBuffer.StringBuffer);
  VAR
    s: ARRAY 32 OF CHAR;
  BEGIN
    sb.Append("//");
    IF (auth.userinfo # NIL) THEN
      String.AppendEscaped(auth.userinfo, CharClass.unreservedUserinfo, sb);
      sb.Append("@");
    END;
    sb.Append(auth.host);
    IF (auth.port >= 0) & (auth.port # auth.defaultPort) THEN
      sb.Append(":");
      IntStr.IntToStr(auth.port, s);
      sb.AppendLatin1(s);
    END
  END Append;

END URI:Authority:ServerBased.
