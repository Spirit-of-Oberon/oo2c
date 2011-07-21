(* 	$Id: WWWForm.Mod,v 1.8 2003/06/24 21:56:25 mva Exp $	 *)
MODULE URI:Query:WWWForm;
(*  Implements class for WWW form query components of GET/POST requests.
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

(** NOTE: This module is a draft.  No syntax checkking is performed on
the query part, nor are invalid escape sequences detected.  I don't
know if this query class should be applied to all HTTP URIs.  *)

IMPORT
  Object, Exception, ADT:Dictionary, ADT:ArrayList, ADT:StringBuffer,
  Strings, TextRider, CC := CharClass, 
  URI, StringURI := URI:String, URI:CharClass;

TYPE
  Query* = POINTER TO QueryDesc;
  QueryDesc = RECORD
    (URI.QueryDesc)
    names-: ArrayList.ArrayList(STRING);
    values-: ArrayList.ArrayList(STRING);
    dict-: Dictionary.Dictionary(STRING, ArrayList.ArrayList(STRING));
    (**Maps a name to a list of its values.  *)
  END;

CONST
  unreservedQChar = ":@+$,";


PROCEDURE Init* (query: Query);
  BEGIN
    URI.InitQuery (query);
    query.names := NEW(ArrayList.ArrayList(STRING), 4);
    query.values := NEW(ArrayList.ArrayList(STRING), 4);
    query.dict := NEW(Dictionary.Dictionary
                      (STRING, ArrayList.ArrayList(STRING)));
  END Init;

PROCEDURE New* (): Query;
  VAR
    query: Query;
  BEGIN
    NEW(query);
    Init(query);
    RETURN query
  END New;

PROCEDURE (query: Query) Clone* (): Query;
  VAR
    copy: Query;
  BEGIN
    NEW(copy);
    query.Copy(copy);
    RETURN copy
  END Clone;

PROCEDURE (query: Query) Copy* (dest: URI.Query);
  BEGIN
    (*query. Copy^ (dest); procedure is abstract in super class *)
    WITH dest: Query DO
      dest.names := query.names.Copy();
      dest.values := query.values.Copy();
      dest.dict := query.dict.Copy();
    END
  END Copy;

PROCEDURE (query: Query) Add* (name, value: STRING);
  VAR
    al: ArrayList.ArrayList(STRING);
  BEGIN
    query.names.Append(name);
    query.values.Append(value);
    IF query.dict.HasKey (name) THEN
      al := query.dict.Get(name);
    ELSE
      al := NEW(ArrayList.ArrayList(STRING), 4);
      query.dict.Set(name,al);
    END;
    al.Append(value);
  END Add;

PROCEDURE (query: Query) ParseString* (b[NO_COPY]: ARRAY OF CHAR;
                                       pos, endpos: LONGINT);
  VAR
    str: ARRAY 1024 OF CHAR;
    n, v: STRING;
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
      n := Object.NewLatin1Region (str, 0, i);
      
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
        v := Object.NewLatin1Region (str, 0, i);
        
        IF (pos # endpos) THEN  (* skip "&" *)
          INC (pos)
        END
      ELSE
        v := Object.NewLatin1 ("")
      END;
      query. Add (n, v)
(*Log.String("pn", n. array^);
Log.String("pv", v. array^);*)

    END
  END ParseString;

PROCEDURE (query: Query) ParseQuery* (str: Object.CharsLatin1;
                                      offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    i: URI.Offset;
  BEGIN
    i := 0;
    WHILE CharClass.SkipURIC(str^, i) DO END;
    IF (str[i] # 0X) THEN
      RAISE(NEW(Exception.ParseError,
                "Illegal character in query component", i+offset));
    ELSE
      query.ParseString(str^, 0, Strings.Length(str^));
    END
  END ParseQuery;

PROCEDURE (query: Query) WriteXML* (w: TextRider.Writer);
  VAR
    i: LONGINT;
  BEGIN
    w. WriteString(CC.eol+"<query-www-form>");
    FOR i := 0 TO query. names. size-1 DO
      w. WriteString(CC.eol+"  <entry name='");
      w. WriteObject(query. names. array[i]);
      w. WriteString("'>");
      w. WriteObject(query. values. array[i]);
      w. WriteString("</entry>");
    END;
    w. WriteString("</query-www-form>");
  END WriteXML;

PROCEDURE (query: Query) Append* (sb: StringBuffer.StringBuffer);
  VAR
    i: LONGINT;
  BEGIN
    sb.Append("?");
    FOR i := 0 TO query.names.size-1 DO
      IF (i # 0) THEN
        sb.Append("&");
      END;
      StringURI.AppendEscaped(query.names.array[i], unreservedQChar, sb);
      sb.Append("=");
      StringURI.AppendEscaped(query.values.array[i], unreservedQChar, sb);
    END;
  END Append;

END URI:Query:WWWForm.
