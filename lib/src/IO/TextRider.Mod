(*	$Id: TextRider.Mod,v 1.10 2006/10/05 08:39:27 mva Exp $	*)
MODULE IO:TextRider [OOC_EXTENSIONS];

(*
    TextRider -  Text-based input/output of Oberon variables.
    Copyright (C) 1998, 1999, 2002, 2003, 2006  Michael van Acken
    Copyright (C) 1997  Michael Griebling
    Copyright (C) 2003  Tim Teulings

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
  Ascii, CharClass, Exception, Strings, LRealStr, RealStr, IntStr, Object, IO;


(**This is a port of the writer part of @omodule{*TextRider} to @omodule{IO}.
   Reader and scanner were dropped.  Don't use the riders with non-blocking
   channels.  *)

CONST
  maxLengthEol* = 2;
  (**Maximum length of an end of line character sequence.  This value is
     system dependent, and always larger or equal to 2.  *)

  eolLF*   = 0; (** The EOL token is a single @oconst{Ascii.lf}. *)
  eolCR*   = 1; (** The EOL token is a single @oconst{Ascii.cr}. *)
  eolCRLF* = 2; (** The EOL token is a single @oconst{Ascii.cr}+@oconst{Ascii.lf}. *)

TYPE
  OverflowError*     = POINTER TO OverflowErrorDesc;
  OverflowErrorDesc* = RECORD
    (**Raised if the parsed datatype has correct syntax but it interpetation is
       not valid, because of numerical overflow or similar reason.  *)
    (IO.ErrorDesc)
  END;

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

  Buffer = POINTER TO ARRAY OF CHAR;

  Reader*     = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD
    channel-: IO.ByteChannel;
    (**The channel on which this reader is operating.  *)
    
    buffer: Buffer;
    (**Buffer that holds the current line. Buffer must always be at least
       @ofield{lineLength}+1 big.  *)
    tmp: Buffer;
    (**A second temporary buffer use by some conversion routines. Will always
       have the same size as @ofield{buffer}.  *)
    pos: LONGINT;
    (**Current scan position in the buffer. Must always be
       0<=@ofield{pos}<=@ofield{lineLength}.  @ofield{pos}=@ofield{lineLength}
       signals that the content of the line (excluding apossible EOL token) has
       been read.  *)
    lineLength: LONGINT;  (** Length of the current line *)
    consumeEOL: BOOLEAN;
    (**The current line is terminated by a EOL token  *)
    eol: SHORTINT;                 (** The EOL token that is in use *)
  END;

PROCEDURE NewProtocolError*(msg: STRING):IO.ProtocolError;
  BEGIN
    RETURN NEW(IO.ProtocolError, msg);
  END NewProtocolError;

PROCEDURE RaiseProtocolError*(msg: STRING) RAISES IO.ProtocolError;
  BEGIN
    RAISE(NewProtocolError(msg));
  END RaiseProtocolError;

PROCEDURE NewOverflowError*(msg: STRING):OverflowError;
  BEGIN
    RETURN NEW(OverflowError, msg);
  END NewOverflowError;

PROCEDURE RaiseOverflowError*(msg: STRING) RAISES OverflowError;
  BEGIN
    RAISE(NewOverflowError(msg));
  END RaiseOverflowError;

PROCEDURE (w: Writer) INIT*(ch: IO.ByteChannel);
  VAR
    i: INTEGER;
  BEGIN
    w. channel := ch;
    w. error := NIL;
    w. eolLen := Strings.Length (CharClass.systemEol);
    FOR i := 0 TO w. eolLen-1 DO
      w. eol[i] := CharClass.systemEol[i]
    END
  END INIT;

PROCEDURE ConnectWriter*(ch: IO.ByteChannel): Writer;
(**@precond
   @oparam{ch} is in blocking mode.
   @end precond *)
  BEGIN
    RETURN NEW(Writer, ch);
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
    chars16: Object.CharsUTF16;
    s8: Object.String8;
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
          chars16 := s.CharsUTF16();
          FOR i := 0 TO s.length-1 DO
            IF (chars16[i] >= 100X) THEN
              w.WriteString("[IO:TextRider.WriteObject: String16 not implemented]");
              RETURN;
            END;
          END;
          s8 := s.ToString8("?");
          chars := s8.CharsLatin1();
          i := w.channel.Write(chars^, 0, s8.length);
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


(* Reader methods
   ------------------------------------------------------------------------ *)

PROCEDURE (r: Reader) INIT*(ch: IO.ByteChannel);
(**Initializes an already allocated @otype{Reader} with the
   @otype{IO.ByteChannel} @oparam{ch}.

   @precond
   @oparam{ch} is in blocking mode.
   @end precond  *)
  BEGIN
    r.channel := ch;
    r.buffer:=NIL;
    r.eol:=eolLF;
    r.consumeEOL:=FALSE;
    NEW(r.buffer,80); (* for speedup *)
    NEW(r.tmp,80); (* for speedup *)
    r.lineLength:=0;
    r.pos:=0;
  END INIT;

PROCEDURE ConnectReader*(ch: IO.ByteChannel): Reader;
(**Create a new instance of @otype{Reader} that is initialized with
   @otype{IO.ByteChannel} @oparam{ch}.

   @precond
   @oparam{ch} is in blocking mode.
   @end precond  *)
  BEGIN
    RETURN NEW(Reader,ch);
  END ConnectReader;

PROCEDURE (r: Reader) SetEOL*(type: SHORTINT);
(**Define which character token is interpreted as line end.  Currently
   available are @oconst{eolLF}, which is in general used by @code{UNIX},
   @oconst{eolCR}, which is used by @code{Mac OS}, and @oconst{eolCRLF}, which
   is used by @code{DOS}, @code{Windows} and various text based network
   protocols.  *)
  BEGIN
    r.eol:=type;
  END SetEOL;

PROCEDURE (r: Reader) AquireBufferWithSize(size: LONGINT);
(**Reallocates @ofield{Reader.buffer} and @ofield{Reader.tmp} to be at least of
   size @oparam{size}.  *)
  VAR
    tmp: Buffer;
  BEGIN
    IF (r.buffer=NIL) OR (LEN(r.buffer^)<size) THEN
      NEW(r.tmp,size+size DIV 2);

      NEW(tmp,size+size DIV 2);
      COPY(r.buffer^,tmp^); (* TODO: Use MOVE! *)
      r.buffer:=tmp;
    END;
  END AquireBufferWithSize;

PROCEDURE (r: Reader) ReadLineBuffer() RAISES IO.Error;
(**Read a new line into the buffer.

   @precond
   The must be characters left to read.  If the end of the file has been
   reached a @otype{IO.FormatError} exception is raised.
   @end precond

   @postcond
   @ofield{Reader.pos} has value 0 and points to the first character of the new
   line.
   @end postcond  *)
  VAR
    ch: CHAR;
  BEGIN
    r.pos:=0;
    r.consumeEOL:=FALSE;
    r.lineLength:=0;

    CASE r.eol OF
    | eolLF:
      LOOP
        IF (r.channel.Read(ch,0,1)#1) THEN
          IF r.lineLength=0 THEN
            RaiseProtocolError("Short file");
          ELSE
            r.buffer[r.lineLength]:=0X;
            RETURN;
          END;
        END;

        r.AquireBufferWithSize(r.lineLength+1);
        r.buffer[r.lineLength]:=ch;

        IF ch=Ascii.lf THEN
          r.buffer[r.lineLength]:=0X;
          r.consumeEOL:=TRUE;
          RETURN;
        END;

        INC(r.lineLength);

      END;
    | eolCR:
      LOOP
        IF (r.channel.Read(ch,0,1)#1) THEN
          IF r.lineLength=0 THEN
            RaiseProtocolError("Short file");
          ELSE
            r.buffer[r.lineLength]:=0X;
            RETURN;
          END;
        END;

        r.AquireBufferWithSize(r.lineLength+1);
        r.buffer[r.lineLength]:=ch;

        IF ch=Ascii.cr THEN
          r.buffer[r.lineLength]:=0X;
          r.consumeEOL:=TRUE;
          RETURN;
        END;

        INC(r.lineLength);
      END;
    | eolCRLF:
      LOOP
        IF (r.channel.Read(ch,0,1)#1) THEN
          IF r.lineLength=0 THEN
            RaiseProtocolError("Short file");
          ELSE
            r.buffer[r.lineLength]:=0X;
            RETURN;
          END;
        END;

        r.AquireBufferWithSize(r.lineLength+1);
        r.buffer[r.lineLength]:=ch;

        IF (ch=Ascii.lf) & (r.lineLength>0) & (r.buffer[r.lineLength-1]=Ascii.cr) THEN
          DEC(r.lineLength); (* push back the Ascii.cr *)
          r.buffer[r.lineLength]:=0X;
          r.consumeEOL:=TRUE;
          RETURN;
        END;

        INC(r.lineLength);
      END;
    END;
  END ReadLineBuffer;

PROCEDURE (r: Reader) ConsumeWhiteSpace() RAISES IO.Error;
(**Read data until a non-whitespace character is found.

   @precond
   A non-whitespace character is available.  Else an
   @otype{IO.FormatError} exception is raised.
   @end precond

   @postcond
   @ofield{Reader.pos} points to the first non-whitespace character found.
   @end postcond  *)
  BEGIN
    LOOP
      WHILE r.pos=r.lineLength DO (* Skip line end and all following empty lines *)
        r.ReadLineBuffer;
      END;

      IF ((r.buffer[r.pos]>" ") OR (r.buffer[r.pos]=Ascii.ht)) THEN
        RETURN;
      END;
      INC(r.pos);
    END;
  END ConsumeWhiteSpace;

PROCEDURE (r: Reader) ReadChar*(VAR ch: CHAR) RAISES IO.Error;
(**Read a character. ``End of line'' tokens are normalized to
   @oconst{Ascii.lf}.

   @emph{Note}: If no character is available a @otype{IO.FormatError} exception
   is be raised.  *)
  BEGIN
    IF (r.pos=r.lineLength) & ~r.consumeEOL THEN
      r.ReadLineBuffer;
    END;

    IF (r.pos=r.lineLength) THEN
      (*Either we have read a new line and the new line is finished, then it
        must have EOL, or ReadLineBuffer would have been failed, or we did not
        read a new line, then a EOL must be avaiable, too (because of above
        check).  *)
      ch:=Ascii.lf;
      r.consumeEOL:=FALSE;
    ELSE
      ch:=r.buffer[r.pos];
      INC(r.pos);
    END;
  END ReadChar;

PROCEDURE (r: Reader) ReadString*(VAR s: ARRAY OF CHAR) RAISES IO.Error;
(**Reads in a sequence of characters enclosed in single (@code{'}) or double
   (@code{"}) quote marks.  The opening quote must be the same as the closing
   quote and must not occur within the string.  Characters are read until
   the terminating quote mark is encountered, an invalid character is read
   (end-of-line is always considered invalid), there are no more characters
   available in the channel, or the string @oparam{s} is full.  @oparam{s} is
   always terminated with @code{0X}.

   Strings without a terminating quote generate a @otype{IO.FormatError}
   exception.  If @oparam{s} is not large enough to hold the entire input, a
   @otype{OverflowError} exception is generated.

   If the strings contains illegal characters (@samp{char<" "}) a
   @otype{IO.FormatError} exception is generated.

   Upon encountering an error, the value of @oparam{s} is undefined.

   @precond
   @samp{input = [whitespace] '"' @{char@} '"' | [whitespace] "'" @{char@} "'"}.
   
   @oparam{s} must at least have a size of 1.
   @end precond  *)
  VAR
    quote: CHAR;
    pos: LONGINT;
  BEGIN
    r.ConsumeWhiteSpace;

    quote:=r.buffer[r.pos];

    IF (quote#'"') & (quote#"'") THEN
      IO.RaiseFormatError("No string found");
    END;

    INC(r.pos);
    pos:=0;
    LOOP
      IF r.pos=r.lineLength THEN
        IO.RaiseFormatError("No quote mark until line end");
      ELSIF r.buffer[r.pos]=quote THEN
        INC(r.pos);
        s[pos]:=0X;
        RETURN;
      ELSIF pos>=LEN(s)-1 THEN (* Need space for trailing 0X *)
        RaiseOverflowError("buffer too small");
      ELSIF r.buffer[r.pos]<" " THEN
        s[pos]:=0X; (* not needed, but we are gentlemens *)
        IO.RaiseFormatError("Illegal character in string");
      ELSE
        s[pos]:=r.buffer[r.pos];
      END;

      INC(pos);
      INC(r.pos);
    END;
  END ReadString;

PROCEDURE (r: Reader) ReadLInt*(VAR lint: LONGINT) RAISES IO.Error;
(**Returns the long integer constant @oparam{lint} at the current position
   according to the format @samp{IntConst = [whitespace] ["+"|"-"] digit}.

   If no integer is available a @otype{IO.FormatError} exception is raised.  If
   the parsed value is too big an @otype{OverflowError} is raised.  *)
  VAR
    x: LONGINT;
    res: IntStr.ConvResults;
  BEGIN
    r.ConsumeWhiteSpace;

    x:=0;
    IF (r.buffer[r.pos]="+") OR (r.buffer[r.pos]="-") THEN
      r.tmp[x]:=r.buffer[r.pos];
      INC(x);
      INC(r.pos);
    END;

    (* IntStr.StrToInt may do this for us, but IMHO it better to have
       it explicitely in here, too. *)
    IF (r.buffer[r.pos]>="0") & (r.buffer[r.pos]<="9") THEN
      r.tmp[x]:=r.buffer[r.pos];
      INC(x);
      INC(r.pos);
    ELSE
      IO.RaiseFormatError("No valid number found");
    END;

    WHILE (r.buffer[r.pos]>="0") & (r.buffer[r.pos]<="9") DO
      r.tmp[x]:=r.buffer[r.pos];
      INC(x);
      INC(r.pos);
    END;

    r.tmp[x]:=0X;

    IntStr.StrToInt(r.tmp^,lint,res);

    IF res#IntStr.strAllRight THEN
      IF res=IntStr.strOutOfRange THEN
        RaiseOverflowError("Value out of range");
      ELSE
        IO.RaiseFormatError("No valid number found");
      END;
    END;
  END ReadLInt;

PROCEDURE (r: Reader) ReadInt*(VAR int: INTEGER) RAISES IO.Error;
(**See @oproc{Reader.ReadLInt}.  *)
  VAR
    tmp: LONGINT;
  BEGIN
    r.ReadLInt(tmp);

    IF (tmp>=MIN(INTEGER)) & (tmp<=MAX(INTEGER)) THEN
      int:=SHORT(tmp);
    ELSE
      IO.RaiseFormatError("read value out of range");
    END;
  END ReadInt;

PROCEDURE (r: Reader) ReadSInt*(VAR sint: SHORTINT) RAISES IO.Error;
(**See @oproc{Reader.ReadLInt}.  *)
  VAR
    tmp: LONGINT;
  BEGIN
    r.ReadLInt(tmp);

    IF (tmp>=MIN(SHORTINT)) & (tmp<=MAX(SHORTINT)) THEN
      sint:=SHORT(SHORT(tmp));
    ELSE
      IO.RaiseFormatError("read value out of range");
    END;
  END ReadSInt;

PROCEDURE (r: Reader) ReadIdentifier*(VAR s: ARRAY OF CHAR) RAISES IO.Error;
(**Reads an Oberon-2 identifier.

   If @oparam{s} is not large enough to hold the entire input, an
   @otype{OverflowError} exception is generated.  If no identifier is available
   a @otype{IO.FormatError} exception is raised.

   @precond
   @samp{input = [whitespace] letter @{letter | digit@}}.

   @oparam{s} must a least have a size of 2.
   @end precond  *)
  VAR
    x: LONGINT;
  BEGIN
    ASSERT(LEN(s)>=2);

    r.ConsumeWhiteSpace;

    IF ~CharClass.IsLetter(r.buffer[r.pos]) THEN
      IO.RaiseFormatError("No identifier value found");
    END;

    s[0]:=r.buffer[r.pos];
    x:=1;
    INC(r.pos);

    WHILE (CharClass.IsLetter(r.buffer[r.pos]) OR CharClass.IsNumeric(r.buffer[r.pos])) DO
      IF x>=LEN(s)-1 THEN (* Need space for trailing 0X *)
        RaiseOverflowError("buffer too small");
      END;
      s[x]:=r.buffer[r.pos];
      INC(x);
      INC(r.pos);
    END;

    s[x]:=0X;
  END ReadIdentifier;

PROCEDURE (r: Reader) ReadBool*(VAR bool: BOOLEAN) RAISES IO.Error;
(**Sets @samp{bool=TRUE} if input equals @samp{TRUE}, and @samp{bool=FALSE} if
   input equals @samp{FALSE}.  If no bool value is available a
   @otype{IO.FormatError} exception is raised.

   @precond
   @samp{input=[whitespace] ["TRUE"|"FALSE"]}
   @end precond  *)
  VAR
    ident: ARRAY 8 OF CHAR;
  BEGIN
    r. ReadIdentifier(ident);

    IF (ident="TRUE") THEN
      bool:=TRUE;
    ELSIF (ident="FALSE") THEN
      bool:=FALSE;
    ELSE
      IO.RaiseFormatError("No bool value found");
    END
  END ReadBool;

PROCEDURE HexDigit (ch: CHAR):BOOLEAN;

  BEGIN
    RETURN ((ch>="0") & (ch<="9")) OR ((ch>="A") & (ch<="F"))
  END HexDigit;

PROCEDURE HexToInt (str: ARRAY OF CHAR; VAR lint: LONGINT): BOOLEAN;
(**Returns the long integer constant `lint' in the string `str' according to
   the format: IntConst = digit @{hexdigit@}

   Note: 80000000H-FFFFFFFFH are valid inputs which map to the negative
   integers.  *)
  VAR
    spos, epos: INTEGER;

  PROCEDURE GetDigit(c: CHAR): INTEGER;

    VAR
      d: INTEGER;
    BEGIN
      d:=ORD(c);
      IF (ORD ("0") <= d) & (d <= ORD ("9")) THEN
        DEC (d, ORD ("0"))
      ELSE  (* (ORD ("A") <= d) & (d <= ORD ("F")) *)
        (*the explicit test can be omitted, since this procedure is only called
          for numbers with H or X suffix, and the initial REPEAT loop in
          `Number' only accepts valid hexadecimal digits from the ranges
          "0".."9" and "A".."F"  *)
        DEC (d, ORD ("A")-10)
      END;
      RETURN d
    END GetDigit;

  BEGIN
    lint := 0; spos := 0; epos := 0;
    WHILE (str[epos] # 0X) DO
      INC (epos);
    END;
    DEC (epos);

    (* skip leading zeros *)
    WHILE (str[spos] = "0") DO
      INC (spos)
    END;
    IF (epos-spos > 7) THEN  (* value has more than 8 significant digits *)
      RETURN FALSE;                      (* number out of range *)
    ELSIF (spos <= epos) THEN         (* if any non-zero digits follow *)
      lint := GetDigit (str[spos]);
      INC (spos);
      IF (epos-spos = 6) & (lint >= 8) THEN
        (* value is beyond MAX(LONGINT)=07FFFFFFFH: correct this by sub-
           tracting 16 from the value of the most significant digit, creating
           the negative number that matches the bit pattern *)
        DEC (lint, 10H)
      END;
      WHILE (spos <= epos) DO
        lint := lint*10H + GetDigit (str[spos]);
        INC (spos)
      END;
      (* ELSE: number is non-empty sequence of "0", keep lint=0 *)
    END;
    RETURN (epos >= 0);
  END HexToInt;

PROCEDURE (r: Reader) ReadHex*(VAR int: LONGINT) RAISES IO.Error;
(**Reads a Oberon-2 hex value.

   If no hex number is available a @otype{IO.FormatError} exception is raised.

   @precond
   @samp{input = [whitespace] digit @{hexdigit@}}.
   @end precond  *)
  VAR
    x: LONGINT;
  BEGIN
    r.ConsumeWhiteSpace;

    IF ~CharClass.IsNumeric(r.buffer[r.pos]) THEN
      IO.RaiseFormatError("Hex number does not start with digit");
    END;

    x:=0;
    r.tmp[x]:=r.buffer[r.pos];
    INC(x);
    INC(r.pos);

    WHILE HexDigit(r.buffer[r.pos]) DO
      r.tmp[x]:=r.buffer[r.pos];
      INC(x);
      INC(r.pos);
    END;

    IF (r.pos=r.lineLength) OR (r.buffer[r.pos]#"H") THEN
      IO.RaiseFormatError("Hex number does not end with character 'H'");
    END;

    (* Skip trailing "H" for conversion routine *)
    INC(r.pos);

    r.tmp[x]:=0X;

    IF ~HexToInt(r.tmp^,int) THEN
      IO.RaiseFormatError("No valid hex number found");
    END;
  END ReadHex;

PROCEDURE (r: Reader) ReadLn*() RAISES IO.Error;
(**This method reads and discards all characters up to and including the next
   end-of-line character.  *)
  BEGIN
    IF (r.pos=r.lineLength) & ~r.consumeEOL THEN
      r.ReadLineBuffer;
    END;
    r.consumeEOL:=FALSE;
    r.pos:=r.lineLength;
  END ReadLn;

PROCEDURE (r: Reader) ReadLine*(VAR s: ARRAY OF CHAR) RAISES IO.Error;
(**Reads a sequence of characters into @oparam{s}; reading continues until an
   end-of-line character is encountered, the array @oparam{s} is full, or
   @oparam{r} reaches the end of the channel.  The end-of-line character is
   discarded and @oparam{s} is always terminated with 0X. If @oparam{r} is
   already positioned at an end-of-line character, @oparam{s} returns as an
   empty string.

   @oparam{s} returns with the sequence of characters that have been read so
   far (terminated by @code{0X}).  @oparam{s} must be big enough to hold the
   line, or a @otype{IO.FormatError} exception is raised.

   Reading past the end of file causes a @otype{IO.FormatError} exception. The
   content of @oparam{s} is undefined in this case.

   @emph{Caution}: If reading multiple lines of input and an integer, real,
   etc. has just been read, the channel may be positioned at a eol character
   and this method will return an empty string.  *)
  VAR
    pos: LONGINT;
  BEGIN
    ASSERT(LEN(s)>0);

    IF r.pos=r.lineLength THEN (* positioned at the end of line *)
      IF (r.lineLength>0) & r.consumeEOL THEN
        (* we already have read content and still must consume the EOL marker *)
        s[0]:=0X;
        r.consumeEOL:=FALSE;
        RETURN;
      ELSE
        (* Must read the next line *)
        r.ReadLineBuffer;
      END;
    END;

    pos:=0;
    LOOP
      IF pos=LEN(s)-1 THEN
        s[pos]:=0X;
        IO.RaiseFormatError("buffer too small");
      ELSIF r.pos=r.lineLength THEN
        s[pos]:=0X;
        r.consumeEOL:=FALSE; (* We read the line including an option EOL marker *)
        RETURN;
      ELSE
        s[pos]:=r.buffer[r.pos];
      END;

      INC(pos);
      INC(r.pos);
    END;
  END ReadLine;

END IO:TextRider.
