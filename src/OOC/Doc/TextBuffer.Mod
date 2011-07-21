(* 	$Id: TextBuffer.Mod,v 1.1.1.1 2000/08/20 13:54:45 mva Exp $	 *)
MODULE OOC:Doc:TextBuffer[OOC_EXTENSIONS];
(*  Text buffers are used to accumulate text.
    Copyright (C) 1999, 2000  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  CharClass, Strings, OOC:Doc;
  
  
CONST
  minTextWidth = 32;
  
TYPE
  Buffer* = POINTER TO BufferDesc;
  BufferDesc = RECORD
    str-: Doc.String;
    len-: LONGINT;
  END;


PROCEDURE New*(): Buffer;
  VAR
    b: Buffer;
  BEGIN
    NEW (b);
    NEW (b. str, 2*1024-16);
    b. str[0] := 0X;
    b. len := 0;
    RETURN b
  END New;

PROCEDURE (b: Buffer) Clear*;
  BEGIN
    b. str[0] := 0X;
    b. len := 0
  END Clear;

PROCEDURE Extend (b: Buffer; to: LONGINT);
  VAR
    i: LONGINT;
    s: Doc.String;
  BEGIN
    i := LEN (b. str^);
    WHILE (i <= to) DO
      INC (i, 2*1024)
    END;
    NEW (s, i);
    COPY (b. str^, s^);
    b. str := s
  END Extend;

PROCEDURE (b: Buffer) Append* (str[NO_COPY]: ARRAY OF CHAR);
  VAR
    len: LONGINT;
  BEGIN
    len := Strings.Length (str);
    IF (b. len+len >= LEN (b. str^)) THEN
      Extend (b, b. len+len)
    END;
    Strings.Append (str, b. str^);
    INC (b. len, len)
  END Append;

PROCEDURE (b: Buffer) AppendEOL*;
  BEGIN
    IF (b. len+1 >= LEN (b. str^)) THEN
      Extend (b, b. len+1)
    END;
    b. str[b. len] := CharClass.eol;
    b. str[b. len+1] := 0X;
    INC (b. len)
  END AppendEOL;

PROCEDURE (b: Buffer) AppendSpaces* (len: LONGINT);
  VAR
    i: LONGINT;
  BEGIN
    IF (b. len+len >= LEN (b. str^)) THEN
      Extend (b, b. len+len)
    END;
    FOR i := b. len TO b. len+len-1 DO
      b. str[i] := " "
    END;
    b. str[b. len+len] := 0X;
    INC (b. len, len)
  END AppendSpaces;

PROCEDURE (b: Buffer) AppendSubstring* (str[NO_COPY]: ARRAY OF CHAR;
                                        start, end: LONGINT);
  VAR
    i, len: LONGINT;
  BEGIN
    len := end-start;
    IF (b. len+len >= LEN (b. str^)) THEN
      Extend (b, b. len+len)
    END;
    FOR i := start TO end-1 DO
      b. str[i-start+b. len] := str[i]
    END;
    b. str[b. len+len] := 0X;
    INC (b. len, len)
  END AppendSubstring;

PROCEDURE (b: Buffer) AppendNoLB* (str[NO_COPY]: ARRAY OF CHAR);
  VAR
    i, j, count: LONGINT;
  BEGIN
    i := 0; count := 0;
    WHILE (str[i] # 0X) DO
      IF (str[i] = CharClass.eol) THEN
        INC (count)
      END;
      INC (i)
    END;
    Extend (b, b. len+i+count);
    
    i := 0; j := b. len;
    WHILE (str[i] # 0X) DO
      IF (str[i] = CharClass.eol) THEN
        b. str[j] := " ";
        IF (i > 0) & (str[i-1] = ".") THEN
          b. str[j+1] := " ";
          INC (j)
        END
      ELSE
        b. str[j] := str[i];
      END;
      INC (i); INC (j)
    END;
    b. str[j] := 0X;
    b. len := j
  END AppendNoLB;

PROCEDURE (b: Buffer) Capitalize* (start, end: LONGINT);
  BEGIN
    WHILE (start # end) DO
      b. str[start] := CAP (b. str[start]);
      INC (start)
    END
  END Capitalize;


PROCEDURE FormatBlock* (dest, source: Buffer;
                        indent, scrWidth, offsetFirst: LONGINT);
(* Copy text from `source' to the target buffer `dest', formatting it on 
   the fly.  The text in `source' is formatted with an indentation of `indent',
   for a screen width of `scrWidth'.  If `offsetFirst' is negative, then format
   the first line of text without any indentation, with an assumed screen width
   reduced by ABS(offsetFirst).  If `offsetFirst' is non-negative, indent the
   first line by additional `offsetFirst' spaces.  *)
  VAR
    s: Doc.String;
    i, start, end: LONGINT;
    firstLine: BOOLEAN;
  
  PROCEDURE LastWord (s: Doc.String; sLen, start, width: LONGINT): LONGINT;
    BEGIN
      IF (start+width < sLen) THEN
        i := start+width;
        (* if s[start+width] is a character, move to 
           the beginning of the word *)
        WHILE (i # start) & (s[i] > " ") DO
          DEC (i)
        END;
        (* move backward to the end of the whitespace at or before s[i] *)
        WHILE (i # start) & (s[i-1] <= " ") DO
          DEC (i)
        END;

        IF (i = start) THEN  (* oops, we got a very long line here *)
          i := start+width;
          WHILE (s[i] > " ") DO
            INC (i)
          END;
          RETURN i
        ELSE  
          (* `i' refers to first whitespace char after last word in 
             s[start .. start+width-1] *)
          RETURN i
        END
      ELSE
        RETURN sLen
      END
    END LastWord;
  
  BEGIN
    IF (scrWidth-indent < minTextWidth) THEN
      scrWidth := indent+minTextWidth
    END;
    s := source. str;
    
    IF (source. len = 0) THEN             (* empty block *)
      dest. AppendEOL;
      RETURN
    END;
    
    firstLine := TRUE;
    i := 0;
    WHILE (s[i] # 0X) DO
      (* skip leading whitespace *)
      WHILE (0X < s[i]) & (s[i] <= " ") DO
        INC (i)
      END;
      
      IF (s[i] # 0X) THEN
        (* find end of last word that would fit into [indent, scrWidth] *)
        start := i;
        IF firstLine THEN
          IF (offsetFirst < 0) THEN
            end := LastWord (s, source. len, start, scrWidth+offsetFirst)
          ELSE
            end := LastWord (s, source. len, start, scrWidth-indent-offsetFirst)
          END;
          IF (offsetFirst >= 0) THEN
            dest. AppendSpaces (offsetFirst+indent)
          END;
          firstLine := FALSE
        ELSE
          end := LastWord (s, source. len, start, scrWidth-indent);
          dest. AppendSpaces (indent)
        END;
        
        dest. AppendSubstring (s^, start, end);
        dest. AppendEOL;
        
        i := end
      END
    END
  END FormatBlock;

PROCEDURE FormatBlockHTML* (dest, source: Buffer;
                            indent, scrWidth, offsetFirst: LONGINT);
(* Copy text from `source' to the target buffer `dest', formatting it on 
   the fly.  The text in `source' is formatted with an indentation of `indent',
   for a screen width of `scrWidth'.  If `offsetFirst' is negative, then format
   the first line of text without any indentation, with an assumed screen width
   reduced by ABS(offsetFirst).  If `offsetFirst' is non-negative, indent the
   first line by additional `offsetFirst' spaces.
   
   HTML tags are treated as if they had a length of zero, and character
   references like "&amp;" are assumed to have a length of one.  *)
  VAR
    s: Doc.String;
    i, start, end: LONGINT;
    firstLine: BOOLEAN;
  
  PROCEDURE LastWord (s: Doc.String; sLen, start, width: LONGINT): LONGINT;
    VAR
      j, lastWord, len: LONGINT;
    BEGIN
      j := start; lastWord := -1; len := 0;
      WHILE (s[j] # 0X) DO
        IF (s[j] = "&") THEN
          WHILE (s[j] # 0X) & (s[j] # ";") DO
            INC (j)
          END;
          INC (len)
        ELSIF (s[j] = "<") THEN
          WHILE (s[j] # 0X) & (s[j] # ">") DO
            INC (j)
          END
        ELSIF (s[j] <= " ") THEN
          IF (j # start) & (s[j-1] > " ") THEN
            IF (len > width) THEN
              IF (lastWord < 0) THEN
                RETURN j
              ELSE
                RETURN lastWord
              END
            ELSE
              lastWord := j;
              INC (j); INC (len)
            END
          ELSE
            INC (j); INC (len)
          END
        ELSE
          INC (j); INC (len)
        END
      END;
      IF (len > width) THEN
        IF (lastWord < 0) THEN
          RETURN j
        ELSE
          RETURN lastWord
        END
      ELSE
        RETURN j
      END
    END LastWord;
  
  BEGIN
    IF (scrWidth-indent < minTextWidth) THEN
      scrWidth := indent+minTextWidth
    END;
    s := source. str;
    
    IF (source. len = 0) THEN             (* empty block *)
      dest. AppendEOL;
      RETURN
    END;
    
    firstLine := TRUE;
    i := 0;
    WHILE (s[i] # 0X) DO
      (* skip leading whitespace *)
      WHILE (0X < s[i]) & (s[i] <= " ") DO
        INC (i)
      END;
      
      IF (s[i] # 0X) THEN
        (* find end of last word that would fit into [indent, scrWidth] *)
        start := i;
        IF firstLine THEN
          IF (offsetFirst < 0) THEN
            end := LastWord (s, source. len, start, scrWidth+offsetFirst)
          ELSE
            end := LastWord (s, source. len, start, scrWidth-indent-offsetFirst)
          END;
          IF (offsetFirst >= 0) THEN
            dest. AppendSpaces (offsetFirst+indent)
          END;
          firstLine := FALSE
        ELSE
          end := LastWord (s, source. len, start, scrWidth-indent);
          dest. AppendSpaces (indent)
        END;
        
        dest. AppendSubstring (s^, start, end);
        dest. AppendEOL;
        
        i := end
      END
    END
  END FormatBlockHTML;

PROCEDURE IndentBlock* (dest, source: Buffer; indent: LONGINT);
  VAR
    s: Doc.String;
    i, start: LONGINT;
  BEGIN
    s := source. str;
    i := 0;
    WHILE (s[i] # 0X) DO
      start := i;
      WHILE (s[i] # 0X) & (s[i] # CharClass.eol) DO
        INC (i)
      END;
      IF (s[i] = CharClass.eol) THEN
        INC (i)
      END;
      dest. AppendSpaces (indent);
      dest. AppendSubstring (s^, start, i)
    END
  END IndentBlock;
  
END OOC:Doc:TextBuffer.
