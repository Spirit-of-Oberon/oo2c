(* 	$Id: String.Mod,v 1.2 2003/05/19 22:55:38 mva Exp $	 *)
MODULE URI:String;
(*  Auxiliary string functions for URI parser.
    Copyright (C) 2000,2003  Michael van Acken

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
  Object, ADT:StringBuffer, URI:CharClass;


TYPE
  Offset* = INTEGER;


PROCEDURE Unescape* (x: STRING): STRING;
(**Replaces escaped characters with their ISO Latin-1 counterparts.  The
   escape sequence @samp{%00} is translated to a space (ASCII code 32).
   
   @precond
   The string @oparam{x} is well-formed.  That is, every occurence of
   the character @samp{%} is followed by two valid hexadecimal digits.
   @end precond  *)
  VAR
    i, j: Offset;
    str: Object.CharsLatin1;
    res: POINTER TO ARRAY OF CHAR;
    
  PROCEDURE Hex (ch: CHAR): INTEGER;
    BEGIN
      CASE ch OF
      | "0".."9":
        RETURN ORD(ch)-ORD("0")
      | "a".."f":
        RETURN ORD(ch)-(ORD("a")-10)
      | "A".."F":
        RETURN ORD(ch)-(ORD("A")-10)
      END
    END Hex;
  
  BEGIN
    str := x(Object.String8).CharsLatin1();
    
    i := 0;
    WHILE (str[i] # 0X) & (str[i] # "%") DO
      INC (i)
    END;
    IF (str[i] = 0X) THEN
      RETURN x;
    ELSE
      NEW (res, LEN (str^));
      i := 0; j := 0;
      WHILE (str[i] # 0X) DO
        IF (str[i] = "%") THEN
          res[j] := CHR (Hex(str[i+1])*16 + Hex(str[i+2]));
          IF (res[j] = 0X) THEN
            res[j] := " "
          END;
          INC (i, 3)
        ELSE
          res[j] := str[i];
          INC (i)
        END;
        INC (j)
      END;
      RETURN Object.NewLatin1Region(res^, 0, j);
    END
  END Unescape;

PROCEDURE AppendEscaped* (source: STRING; unreserved: ARRAY OF CHAR;
                          dest: StringBuffer.StringBuffer);
(**Appends the string @oparam{source} to @oparam{dest}, possibly escaping some
   characters on the way.  All characters from @oproc{CharClass.IsUnreserved}
   and all characters in @oparam{unreserved} are copied as is.  Any other
   characters are translated into a three character sequence @samp{%HH}, where
   @samp{H} is a hex digit from @samp{[0-9A-F]}.  If @oparam{dest} cannot 
   hold the whole result, then the result string is truncated.  *)
  VAR
    i: INTEGER;
    src: Object.CharsLatin1;
  
  PROCEDURE ToHex (i: INTEGER): CHAR;
    BEGIN
      IF (i < 10) THEN
        RETURN CHR (i+ORD ("0"))
      ELSE
        RETURN CHR (i+(ORD ("A")-10))
      END
    END ToHex;
  
  BEGIN
    src := source(Object.String8).CharsLatin1();
    i := 0;
    WHILE (src[i] # 0X) DO
      IF ~CharClass.IsUnreserved (src[i]) &
         ~CharClass.IsMember (src[i], unreserved) THEN
        dest.AppendLatin1Char("%");
        dest.AppendLatin1Char(ToHex(ORD(src[i]) DIV 16));
        dest.AppendLatin1Char(ToHex(ORD(src[i]) MOD 16));
      ELSE
        dest.AppendLatin1Char(src[i]);
      END;
      INC (i)
    END;
  END AppendEscaped;

END URI:String.
