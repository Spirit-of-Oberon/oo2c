(* 	$Id$	 *)
MODULE URI:Query:WWWForm;
(*  Implements class for WWW form query components of GET/POST requests.
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

(** NOTE: This module is a draft.  It is not included into the
`libxml' shared library because it depends on `libadt'.  Until libxml
is changed to use libadt, or this module is rewritten, it will stay
excluded.  Other issues: No syntax checkking is performed on the query
part, nor are invalid escape sequences detected.  I don't know if this
query class should be applied to all HTTP URIs.  *)

IMPORT
  ADT:Object, ADT:String, ADT:Dictionary, ADT:ArrayList,
  Strings, TextRider, CC := CharClass, 
  URI, URI:Error, StringURI := URI:String, URI:CharClass;

TYPE
  Query* = POINTER TO QueryDesc;
  QueryDesc = RECORD
    (URI.QueryDesc)
    names-: ArrayList.ArrayList;         (* of String.String *)
    values-: ArrayList.ArrayList;        (* of String.String *)
    dict-: Dictionary.Dictionary;        (* maps names to values *)
  END;

CONST
  unreservedQChar = ":@+$,";

CONST
  illegalQueryChar = 1;

VAR
  queryContext: Error.Context;


PROCEDURE Init* (query: Query);
  BEGIN
    URI.InitQuery (query);
    query. names := ArrayList.New (4);
    query. values := ArrayList.New (4);
    query. dict := Dictionary.New();
  END Init;

PROCEDURE New* (): Query;
  VAR
    query: Query;
  BEGIN
    NEW (query);
    Init (query);
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
      dest. names := query. names. Copy();
      dest. values := query. values. Copy();
      dest. dict := query. dict. Copy();
    END
  END Copy;

PROCEDURE (query: Query) Add* (name, value: String.String);
  VAR
    al: ArrayList.ArrayList;
    obj: Object.Object;
  BEGIN
    query. names. Append (name);
    query. values. Append (value);
    IF query. dict. HasKey (name) THEN
      obj := query. dict. Get (name);
      obj(ArrayList.ArrayList). Append (value)
    ELSE
      al := ArrayList.New (4);
      al. Append (value);
      query. dict. Set (name, al)
    END
  END Add;

PROCEDURE (query: Query) ParseString* (VAR b: ARRAY OF CHAR; pos, endpos: LONGINT);
  VAR
    str: ARRAY 1024 OF CHAR;
    n, v: String.String;
    i: INTEGER;
    
  PROCEDURE Hex (ch: CHAR): INTEGER;
    BEGIN
      CASE CAP (ch) OF
      | "A".."F": RETURN ORD (CAP (ch))-(ORD ("A")-10);
      | "0".."9": RETURN ORD (CAP (ch))-ORD ("0");
      ELSE                               (* error *)
        RETURN 0
      END
    END Hex;
  
  BEGIN
    WHILE (pos # endpos) DO
      i := 0;
      WHILE (pos # endpos) & (b[pos] # "=") DO
        IF (i < LEN(str)) THEN
          IF (b[pos] = "%") & (pos+2 < endpos) THEN
            str[i] := CHR (Hex(b[pos+1])*16+Hex(b[pos+2]));
            INC (pos, 2)
          ELSIF (b[pos] = "+") THEN
            str[i] := " "
          ELSE
            str[i] := b[pos]
          END;
          INC (i)
        END;
        INC (pos)
      END;
      n := String.NewRegion (str, 0, i);
      
      IF (pos # endpos) THEN
        INC (pos);                       (* skip "=" *)
        i := 0;
        WHILE (pos # endpos) & (b[pos] # "&") DO
          IF (i < LEN(str)) THEN
            IF (b[pos] = "%") & (pos+2 < endpos) THEN
              str[i] := CHR (Hex(b[pos+1])*16+Hex(b[pos+2]));
              INC (pos, 2)
            ELSIF (b[pos] = "+") THEN
              str[i] := " "
            ELSE
              str[i] := b[pos]
            END;
            INC (i)
          END;
          INC (pos)
        END;
        v := String.NewRegion (str, 0, i);
        
        IF (pos # endpos) THEN  (* skip "&" *)
          INC (pos)
        END
      ELSE
        v := String.New ("")
      END;
      query. Add (n, v)
(*Log.String("pn", n. array^);
Log.String("pv", v. array^);*)

    END
  END ParseString;

PROCEDURE (query: Query) ParseQuery* (str: URI.StringPtr; offset: URI.Offset): Error.Msg;
  VAR
    i: URI.Offset;
  BEGIN
    i := 0;
    WHILE CharClass.SkipURIC (str^, i) DO END;
    IF (str[i] # 0X) THEN
      RETURN Error.New (queryContext, illegalQueryChar, i+offset)
    ELSE
      query. ParseString (str^, 0, Strings.Length (str^));
      RETURN NIL
    END
  END ParseQuery;

PROCEDURE (query: Query) WriteXML* (w: TextRider.Writer);
  VAR
    i: LONGINT;
  BEGIN
    w. WriteString (CC.eol+"<query-www-form>");
    FOR i := 0 TO query. names. size-1 DO
      w. WriteString (CC.eol+"  <entry name='");
      w. WriteString (query. names. array[i](String.String). array^);
      w. WriteString ("'>");
      w. WriteString (query. values. array[i](String.String). array^);
      w. WriteString ("</entry>");
    END;
    w. WriteString ("</query-www-form>");
  END WriteXML;

PROCEDURE (query: Query) Append* (VAR str: ARRAY OF CHAR);
  VAR
    i: LONGINT;
  BEGIN
    Strings.Append ("?", str);
    FOR i := 0 TO query. names. size-1 DO
      IF (i # 0) THEN
        Strings.Append ("&", str)
      END;
      StringURI.AppendEscaped (query. names. array[i](String.String). array^,
                               unreservedQChar, str);
      Strings.Append ("=", str);
      StringURI.AppendEscaped (query. values. array[i](String.String). array^,
                               unreservedQChar, str);
    END
  END Append;

BEGIN
  queryContext := Error.NewContext ("URI:Query:WWWForm");
  queryContext. SetString (illegalQueryChar,
    "Illegal character in query component");
END URI:Query:WWWForm.
