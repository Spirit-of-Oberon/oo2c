(* 	$Id: Opaque.Mod,v 1.3 2003/05/20 20:10:33 mva Exp $	 *)
MODULE URI:Scheme:Opaque;
(*  Implementation of the generic opaque URI.
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
  TextRider, CC := CharClass, Object, Exception, ADT:StringBuffer,
  URI, URI:CharClass, URI:String;


TYPE
  Generic* = POINTER TO GenericDesc;
  GenericDesc* = RECORD
  (**This class implements the generic opaque URI.  *)
    (URI.OpaqueURIDesc)
    opaque-: STRING;
  END;


PROCEDURE Init* (uri: Generic; schemeId, opaque: STRING);
  BEGIN
    URI.InitOpaqueURI (uri, schemeId);
    ASSERT (opaque # NIL);
    uri. opaque := opaque
  END Init;

PROCEDURE New* (schemeId, opaque: STRING): Generic;
  VAR
    uri: Generic;
  BEGIN
    NEW (uri);
    Init (uri, schemeId, opaque);
    RETURN uri
  END New;

PROCEDURE (uri: Generic) Clone* (): Generic;
  VAR
    copy: Generic;
  BEGIN
    NEW (copy);
    uri. Copy (copy);
    RETURN copy
  END Clone;

PROCEDURE (uri: Generic) Copy* (dest: URI.URI);
  BEGIN
    uri. Copy^ (dest);
    WITH dest: Generic DO
      dest. opaque := uri. opaque;
    END
  END Copy;

PROCEDURE IsValidOpaqueStr (str[NO_COPY]: ARRAY OF CHAR): URI.Offset;
  VAR
    i: URI.Offset;
  BEGIN
    IF (str[0] = "/") THEN
      RETURN 0
    ELSE
      i := 0;
      WHILE CharClass.SkipURIC (str, i) DO END;
      IF (str[i] = 0X) THEN
        RETURN -1
      ELSE
        RETURN i
      END
    END
  END IsValidOpaqueStr;

PROCEDURE (uri: Generic) ParseOpaquePart* (str: Object.CharsLatin1; offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    pos: URI.Offset;
  BEGIN
    pos := IsValidOpaqueStr (str^);
    IF (pos < 0) THEN
      uri. opaque := String.Unescape(Object.NewLatin1(str^));
    ELSE
      RAISE(NEW(Exception.ParseError,
                "Illegal character for opaque component of an URI",
                pos+offset));
    END
  END ParseOpaquePart;

PROCEDURE (uri: Generic) WriteXML* (w: TextRider.Writer);
  BEGIN
    w. WriteString (CC.eol+"<opaque-uri>");
    IF (uri. schemeId # NIL) THEN
      w. WriteString (CC.eol+"<scheme>");
      w. WriteObject (uri. schemeId);
      w. WriteString ("</scheme>")
    END;
    w. WriteString (CC.eol+"<opaque-part>");
    w. WriteObject (uri. opaque);
    w. WriteString ("</opaque-part>");
    w. WriteString (CC.eol+"</opaque-uri>")
  END WriteXML;

PROCEDURE (uri: Generic) ToString*(): Object.String8;
  VAR
    sb: StringBuffer.StringBuffer;
    str: STRING;
  BEGIN
    sb := StringBuffer.New("");
    uri. AppendScheme (sb);
    String.AppendEscaped (uri. opaque, CharClass.reserved, sb);
    str := sb.ToString();
    RETURN str(Object.String8);
  END ToString;

END URI:Scheme:Opaque.
