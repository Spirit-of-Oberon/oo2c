(*	$Id$	*)
MODULE IO:TextRider [OOC_EXTENSIONS];

(*
    TextRider -  Text-based input/output of Oberon variables.       
    Copyright (C) 1998, 1999, 2002, 2003  Michael van Acken
    Copyright (C) 1997  Michael Griebling
 
    This module is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.
 
    This module is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*)

IMPORT
  CharClass, Exception, Strings, LRealStr, RealStr, IntStr, Object, IO;

(**This is a port of the writer part of @omodule{*TextRider} to @omodule{IO}.
   Reader and scanner were dropped.  Don't use the riders with non-blocking
   channels.  *)
  
CONST
  maxLengthEol* = 2;
  (**Maximum length of an end of line character sequence.  This value is
     system dependent, and always larger or equal to 2.  *)

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    channel-: IO.ByteChannel;
    (**The channel on which this writer is operating.  *)

    error-: IO.Error;
    (**If any of the write methods encounters an error, then the corresponding
       exception is stored here.  This field is sticky.  That is, is stays
       @code{NIL} until the first error, and it keeps the first error's
       exception.  *)
    
    eol: ARRAY maxLengthEol OF CHAR;
      (* character sequence of end of line marker *)
    eolLen: INTEGER;            (* number of characters in `eol' *)
  END;


PROCEDURE InitWriter* (w: Writer; ch: IO.ByteChannel);
  VAR
    i: INTEGER;
  BEGIN
    w. channel := ch;
    w. error := NIL;
    w. eolLen := Strings.Length (CharClass.systemEol);
    FOR i := 0 TO w. eolLen-1 DO
      w. eol[i] := CharClass.systemEol[i]
    END
  END InitWriter;

PROCEDURE ConnectWriter*(ch: IO.ByteChannel): Writer;
(**@precond
   @oparam{ch} is in blocking mode.
   @end precond *)
  VAR
    w: Writer;
  BEGIN
    NEW(w);
    InitWriter (w, ch);
    RETURN w;
  END ConnectWriter;


(* Writer methods 
   ------------------------------------------------------------------------ *)

(* The following write methods write the value as a string to the 
   underlying Channel.
 *)
 
PROCEDURE (w: Writer) SetEol* (marker: ARRAY OF CHAR; markerLen: INTEGER);
(**Sets new end of line marker.  If the passed string marker does not fit into
   the writer's field @samp{w.eol}, then nothing is done.  The empty marker is
   permitted.  The default value for newly created writer is
   @ovar{CharClass.systemEol}.

   @precond
   (0 <= markerLen < LEN (marker)) & (markerLen <= maxLengthEol)
   @end precond  *)
  VAR
    i: INTEGER;
  BEGIN
    IF (markerLen < 0) OR (markerLen > maxLengthEol) THEN
      (* nothing *)
    ELSE
      FOR i := 0 TO markerLen-1 DO
        w. eol[i] := marker[i]
      END;
      w. eolLen := markerLen
    END
  END SetEol;

PROCEDURE SetError(w: Writer);
  VAR
    e: Exception.Exception;
  BEGIN
    IF (w.error = NIL) THEN
      e := Exception.Current();
      w.error := e(IO.Error);
    END;
  END SetError;

(* The terminating 0X is not written *)
PROCEDURE (w: Writer) WriteString*(s[NO_COPY]: ARRAY OF CHAR);
  VAR
    d, len: LONGINT;
  BEGIN
    len := Strings.Length(s);
    TRY
      d := w.channel.Write(s, 0, len);
    CATCH IO.Error:
      SetError(w);
    END;
  END WriteString;

PROCEDURE (w: Writer) WriteStringRegion*(s[NO_COPY]: ARRAY OF CHAR;
                                         start, end: LONGINT);
  VAR
    d: LONGINT;
  BEGIN
    TRY
      d := w.channel.Write(s, start, end-start);
    CATCH IO.Error:
      SetError(w);
    END;
  END WriteStringRegion;

PROCEDURE (w: Writer) WriteObject*(obj: Object.Object);
  VAR
    chars: Object.CharsLatin1;
    s: Object.String;
    i: LONGINT;
  BEGIN
    IF (obj = NIL) THEN
      w.WriteString("<NIL>");
    ELSE
      s := obj.ToString();
      TRY
        WITH s: Object.String8 DO
          chars := s.CharsLatin1();
          i := w.channel.Write(chars^, 0, s.length);
        | s: Object.String16 DO
          w.WriteString("[IO:TextRider.WriteObject: String16 not implemented]");
        END;
      CATCH IO.Error:
        SetError(w);
      END;
    END;
  END WriteObject;

PROCEDURE (w: Writer) WriteBool*(bool: BOOLEAN);
  BEGIN
    IF bool THEN w. WriteString ("TRUE")
    ELSE w. WriteString ("FALSE")
    END
  END WriteBool;
  
PROCEDURE (w: Writer) WriteChar*(ch: CHAR);
  VAR
    d: LONGINT;
  BEGIN
    TRY
      d := w.channel.Write(ch, 0, 1);
    CATCH IO.Error:
      SetError(w);
    END;
  END WriteChar;
  
PROCEDURE WritePad (w: Writer; n: LONGINT);
  BEGIN
    (* output padding *)
    WHILE n>0 DO w.WriteChar(" "); DEC(n) END  
  END WritePad;
  
(* Convert 'sint' to a string of at least 'n' chars and write it to the
   underlying channel. If 'n' is too small it will be extended. If 'n'
   is greater then nessesary spaces will be added after the number, i.e.
   it is left justified. *)
PROCEDURE (w: Writer) WriteLInt*(lint: LONGINT; n: LONGINT);
  VAR
    val: ARRAY 16 OF CHAR;
  BEGIN
    (* convert to a string *)
    IntStr.IntToStr(lint, val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));
    
    (* output the string *)
    w.WriteString(val)
  END WriteLInt;
  
PROCEDURE (w: Writer) WriteSInt* (sint: SHORTINT; n: LONGINT);
  BEGIN
    w.WriteLInt(sint, n)
  END WriteSInt;

PROCEDURE (w: Writer) WriteInt* (int: INTEGER; n: LONGINT);
  BEGIN
    w.WriteLInt(int, n)
  END WriteInt;
 
(* Write `lint' as a heximal number using `d' digits. 
   If `d' <= 0 then `lint' is written using 8 digits. *)
PROCEDURE (w: Writer) WriteHex* (lint: LONGINT; d: LONGINT);
  PROCEDURE WriteHexDigits(w: Writer; VAR n: LONGINT; digits: LONGINT);
    CONST
      BASE=16;
    VAR
      dig: LONGINT;
    BEGIN
      (* output padding digits *)
      WHILE digits>8 DO 
        IF n<0 THEN w.WriteChar("F") ELSE w.WriteChar("0") END;
        DEC(digits)
      END;

      (* output the actual number *)
      WHILE digits>0 DO
        DEC(digits);
        dig := ASH(n, -4*digits) MOD BASE;
        IF dig<=9 THEN w.WriteChar(CHR(ORD("0") + dig)) 
        ELSE w.WriteChar(CHR(ORD("A") - 10 + dig)) 
        END
      END
    END WriteHexDigits;

  BEGIN
    IF d<=0 THEN d:=8 END;
    WriteHexDigits(w, lint, d)
  END WriteHex;

PROCEDURE (w: Writer) WriteLReal*(lreal: LONGREAL; n, k: LONGINT);
(**Writes the value @oparam{lreal} in the format produced by
   @oproc{LRealStr.RealToFloat}.  *)
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    (* convert to a string *)
    LRealStr.RealToFloat(lreal, SHORT(k), val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));

    (* output the string *)
    w.WriteString(val);
  END WriteLReal;

PROCEDURE (w: Writer) WriteReal*(real: REAL; n, k: LONGINT);
(**As @oproc{Writer.WriteLReal}.  *)
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    (* convert to a string *)
    RealStr.RealToFloat(real, SHORT(k), val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));

    (* output the string *)
    w.WriteString(val)
  END WriteReal;

PROCEDURE (w: Writer) WriteLRealFix*(VAR lreal: LONGREAL; n, k: LONGINT);
(**Writes the value @oparam{lreal} in the format produced by
   @oproc{LRealStr.RealToFixed}.  *)
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    (* convert to a string *)
    LRealStr.RealToFixed(lreal, SHORT(k), val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));
    
    (* output the string *)
    w.WriteString(val)
  END WriteLRealFix;

PROCEDURE (w: Writer) WriteRealFix*(real: REAL; n, k: LONGINT);
(**As @oproc{Writer.WriteLRealFix}.  *)
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    (* convert to a string *)
    RealStr.RealToFixed(real, SHORT(k), val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));
    
    (* output the string *)
    w.WriteString(val)
  END WriteRealFix;

PROCEDURE (w: Writer) WriteLRealEng*(VAR lreal: LONGREAL; n, k: LONGINT);
(**Writes the value @oparam{lreal} in the format produced by
   @oproc{LRealStr.RealToEng}.  *)
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    (* convert to a string *)
    LRealStr.RealToEng(lreal, SHORT(k), val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));
    
    (* output the string *)
    w.WriteString(val)
  END WriteLRealEng;

PROCEDURE (w: Writer) WriteRealEng*(real: REAL; n, k: LONGINT);
(**As @oproc{Writer.WriteLRealEng}.  *)
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    (* convert to a string *)
    RealStr.RealToEng(real, SHORT(k), val);
    
    (* output any required padding *)
    WritePad(w, n-Strings.Length(val));
    
    (* output the string *)
    w.WriteString(val)
  END WriteRealEng;
  
PROCEDURE (w: Writer) WriteSet*(s: SET);
(**Write @oparam{s} in Oberon-2 set notation.  *)
  VAR
    bit, lo: SHORTINT; addComma: BOOLEAN;
  BEGIN
    w.WriteChar("{"); bit:=0; addComma:=FALSE;
    WHILE bit<=MAX(SET) DO      
      IF bit IN s THEN
        lo:=bit;
        WHILE (bit<MAX(SET)) & (bit+1 IN s) DO INC(bit) END; (* check for runs *)
        
        (* output the set element(s) *)
        IF addComma THEN w.WriteString(", ") ELSE addComma:=TRUE END;
        w.WriteInt(lo, 0);
        IF lo<bit THEN
          w.WriteString(".."); w.WriteInt(bit, 0)
        END
      END;
      INC(bit)
    END;
    w.WriteChar("}");
  END WriteSet;
 
PROCEDURE (w: Writer) WriteLn*();
(**Write a newline.  *)
  VAR
    i: INTEGER;
  BEGIN
    FOR i := 0 TO w. eolLen-1 DO
      w. WriteChar (w.eol[i])
    END
  END WriteLn;

END IO:TextRider.
