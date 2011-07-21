(* 	$Id: Unparsed.Mod,v 1.2 2003/05/19 22:55:38 mva Exp $	 *)
MODULE URI:Authority:Unparsed;
(*  Implements class for unparsed authority components.
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
  TextRider, CC := CharClass, Object, Exception, ADT:StringBuffer,
  URI, URI:CharClass;


TYPE
  Authority* = POINTER TO AuthorityDesc;
  AuthorityDesc = RECORD
  (**Unparsed authority component of an URI.  *)
    (URI.AuthorityDesc)
    unparsed-: STRING
    (**Holds the authority substring of a URI @emph{without} any
       modifications.  In particular, escaped characters are @emph{not}
       replaced with their character value.  *)
  END;


PROCEDURE Init* (auth: Authority; unparsed: STRING);
  BEGIN
    URI.InitAuthority (auth);
    ASSERT (unparsed # NIL);
    auth. unparsed := unparsed
  END Init;

PROCEDURE New* (unparsed: STRING): Authority;
  VAR
    auth: Authority;
  BEGIN
    NEW (auth);
    Init (auth, unparsed);
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
      dest. unparsed := auth. unparsed;
    END
  END Copy;

PROCEDURE (auth: Authority) ParseAuthority* (str: Object.CharsLatin1;
                                             offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    i: URI.Offset;
  BEGIN
    i := 0;
    WHILE CharClass.SkipAuthChar (str^, i) DO END;
    IF (str[i] # 0X) THEN
      RAISE(NEW(Exception.ParseError,
                "Illegal character in authority component", i+offset));
    ELSE
      auth.unparsed := Object.NewLatin1Region(str^, 0, i);
    END
  END ParseAuthority;

PROCEDURE (auth: Authority) WriteXML* (w: TextRider.Writer);
  BEGIN
    w. WriteString (CC.eol+"<authority-unparsed>");
    w. WriteObject (auth. unparsed);
    w. WriteString ("</authority-unparsed>")
  END WriteXML;

PROCEDURE (auth: Authority) Append* (sb: StringBuffer.StringBuffer);
  BEGIN
    sb.Append("//");
    sb.Append(auth. unparsed);
  END Append;

END URI:Authority:Unparsed.
