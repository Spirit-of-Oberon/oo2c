(* 	$Id: Unparsed.Mod,v 1.2 2003/05/19 22:55:38 mva Exp $	 *)
MODULE URI:Query:Unparsed;
(*  Implements class for unparsed query components.
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
  Query* = POINTER TO QueryDesc;
  QueryDesc = RECORD
  (**Unparsed query component of an URI.  *)
    (URI.QueryDesc)
    unparsed-: STRING;
    (**Holds the query substring of a URI @emph{without} any modifications.
       In particular, escaped characters are @emph{not} replaced with their
       character value.  This field is never @code{NIL}.  *)
  END;


PROCEDURE Init* (query: Query; unparsed: STRING);
  BEGIN
    URI.InitQuery (query);
    ASSERT (unparsed # NIL);
    query. unparsed := unparsed
  END Init;

PROCEDURE New* (unparsed: STRING): Query;
  VAR
    query: Query;
  BEGIN
    NEW (query);
    Init (query, unparsed);
    RETURN query
  END New;

PROCEDURE (query: Query) Clone* (): Query;
  VAR
    copy: Query;
  BEGIN
    NEW (copy);
    query. Copy (copy);
    RETURN copy
  END Clone;

PROCEDURE (query: Query) Copy* (dest: URI.Query);
  BEGIN
    (*query. Copy^ (dest); procedure is abstract in super class *)
    WITH dest: Query DO
      dest.unparsed := query.unparsed;
    END
  END Copy;

PROCEDURE (query: Query) ParseQuery* (str: Object.CharsLatin1;
                                      offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    i: URI.Offset;
  BEGIN
    i := 0;
    WHILE CharClass.SkipURIC (str^, i) DO END;
    IF (str[i] # 0X) THEN
      RAISE(NEW(Exception.ParseError,
                "Illegal character in query component", i+offset));
    ELSE
      query.unparsed := Object.NewLatin1Region(str^, 0, i);
    END
  END ParseQuery;

PROCEDURE (query: Query) WriteXML* (w: TextRider.Writer);
  BEGIN
    w. WriteString (CC.eol+"<query-unparsed>");
    w. WriteObject (query. unparsed);
    w. WriteString ("</query-unparsed>");
  END WriteXML;

PROCEDURE (query: Query) Append* (sb: StringBuffer.StringBuffer);
  BEGIN
    sb.Append("?");
    sb.Append(query.unparsed);
  END Append;

END URI:Query:Unparsed.
