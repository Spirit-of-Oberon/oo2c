(* 	$Id: UU.Mod,v 1.2 2004/12/20 10:11:27 mva Exp $	 *)
MODULE Codec:UU [OOC_EXTENSIONS];
(*  Codec for uuencode transport encoding.
    Copyright (C) 2002, 2004  Michael van Acken

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
  SYSTEM, Ascii, Codec, ADT:StringBuffer;

CONST
  lineLength = 45;  (* number of bytes per line when encoding *)
  lengthBufferPlain = lineLength+3;
  lengthBufferCode = (lineLength DIV 3)*4+3;
      
TYPE
  UU* = POINTER TO UUDesc;
  UUDesc = RECORD
    (Codec.CodecDesc)
  END;

TYPE
  Encoder* = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.EncoderDesc)
    incompleteSize: LONGINT;     (* valid characters in `incompleteData' *)
    incompleteData: ARRAY lengthBufferPlain OF CHAR;
  END;
     
TYPE
  Decoder* = POINTER TO DecoderDesc;
  DecoderDesc = RECORD
  (**Decoder for data using the @samp{uu} format.  Only full complete lines of
     data are processed at a time.  End of line characters are ignored while
     decoding.  This means that empty lines in the source data are ignored, and
     lines of uuencoded data that are joined together without any newline
     characters in between are decoded like separate lines.  *)
    (Codec.DecoderDesc)
    incompleteLength: LONGINT;   (* expected length of incomplete line *)
    incompleteSize: LONGINT;     (* valid characters in `incompleteData' *)
    incompleteData: ARRAY 64+1 OF CHAR;
  END;

TYPE
  Header* = RECORD
    fileMode-: LONGINT;
    (**The Unix file mode indicated in the @samp{begin} line.  Only the 4 least
       significant digits are reported.  Only use this value after masking out
       any dangerous bits, like @samp{setuid} and @samp{execute}!  *)
    fileName-: ARRAY 256 OF CHAR;
    (**File name from the @samp{begin} line.  If the name starts and ends with
       a double quote @samp{"}, then the quote is removed.  If the name is
       to long to be stored in this field, then it is truncated.  *)
  END;
  
VAR
  uu-: UU;

PROCEDURE (dec: Decoder) INIT*();
  BEGIN
    dec.INIT^();
    dec.incompleteSize := 0;
  END INIT;

PROCEDURE (enc: Encoder) INIT*();
  BEGIN
    enc.INIT^(Codec.exceptionEncoder);
    enc.incompleteSize := 0;
  END INIT;

PROCEDURE (c: UU) NewDecoder*(): Decoder;
  BEGIN
    RETURN NEW(Decoder);
  END NewDecoder;

PROCEDURE (c: UU) NewEncoder*(): Encoder;
  BEGIN
    RETURN NEW(Encoder);
  END NewEncoder;

PROCEDURE LookingAt (data[NO_COPY]: ARRAY OF CHAR; start: LONGINT;
                     s: ARRAY OF CHAR): BOOLEAN;
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0; j := start;
    WHILE (s[i] # 0X) & (data[j] = s[i]) DO
      INC (i); INC (j);
    END;
    RETURN (s[i] = 0X);
  END LookingAt;

PROCEDURE IsEOL* (ch: CHAR): BOOLEAN;
  BEGIN
    RETURN (ch = Ascii.lf) OR (ch = Ascii.cr);
  END IsEOL;

PROCEDURE Extract* (source[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT;
                    VAR destination: ARRAY OF CHAR);
  VAR
    i: INTEGER;
  BEGIN
    IF (end-start >= LEN (destination)) THEN
      end := start+LEN (destination)-1;
    END;
    
    i := 0;
    WHILE (start # end) DO
      destination[i] := source[start];
      INC (i);
      INC (start);
    END;
    destination[i] := 0X
  END Extract;
  
PROCEDURE DecodeByte (ch: CHAR): LONGINT;
  BEGIN
    IF (ch <= 20X) OR (ch > 60X) THEN
      RETURN -1;
    ELSE
      RETURN (ORD (ch)-20H) MOD 40H;
    END;
  END DecodeByte;

PROCEDURE LineBegin* (data[NO_COPY]: ARRAY OF CHAR;
                      start, end: LONGINT; VAR header: Header): LONGINT;
(**If the text starting a @samp{data[start]} holds a valid @samp{begin} of a
   uuencoded file, then return the index of the first eol character of the
   @samp{begin} line.  In this case, @samp{data[start, result-1]} is the
   complete line, without the eol character that ends it.

   If there is no match, then result @samp{-1}.  If the indicated region of
   @oparam{data} holds no end of line character, then no match is possible.  *)
  CONST
    minimumLineLength = 5+1+1+1+1+1;
    (* this is: "begin" + space + octal digit + space + file char + eol char *)
  VAR
    fileName, mode, endFileName: LONGINT;
    
  PROCEDURE IsOctal (ch: CHAR): BOOLEAN;
    BEGIN
      RETURN ("0" <= ch) & (ch < "8");
    END IsOctal;
  
  PROCEDURE SkipWS ();
    BEGIN
      WHILE (start # end) & (data[start] <= " ") & ~IsEOL (data[start]) DO
        INC (start);
      END;
    END SkipWS;
  
  BEGIN
    IF (end-start >= minimumLineLength) &
       LookingAt (data, start, "begin ") THEN
      INC (start, 6);
      SkipWS;
      IF (start # end) & IsOctal(data[start]) THEN
        mode := 0;
        REPEAT
          mode := (mode*8 + (ORD (data[start])-ORD("0"))) MOD ASH(2,12);
          INC (start);
        UNTIL (start = end) OR ~IsOctal(data[start]);
        
        SkipWS;

        fileName := start;
        WHILE (start # end) & ~IsEOL(data[start]) DO
          INC (start);
        END;

        IF (start # fileName) & (start # end) THEN
          endFileName := start;
          IF (data[fileName] = '"') & (endFileName >= fileName+2) &
             (data[endFileName-1] = '"') THEN
            INC (fileName);
            DEC (endFileName);
          END;
          header. fileMode := mode;
          Extract (data, fileName, endFileName, header.fileName);
          RETURN start;
        END;
      END;
    END;
    RETURN -1;
  END LineBegin;

PROCEDURE LineData* (data[NO_COPY]: ARRAY OF CHAR;
                     start, end: LONGINT): LONGINT;
(**If the text starting a @samp{data[start]} holds a complete text line with
   uuencoded data, then return the index of the first eol character of the
   line.  In this case, @samp{data[start, result-1]} is the
   complete line, without the eol character that ends it.

   If there is no match, then result @samp{-1}.  If the indicated region of
   @oparam{data} holds no end of line character, then no match is possible.  *)
  VAR
    len: LONGINT;
  BEGIN
    IF (end-start >= 2) THEN
      len := DecodeByte (data[start]);
      IF (len >= 0) THEN
        len := ((len+2) DIV 3)*4;
        INC (start);
        WHILE (start # end) & (len # 0) DO
          IF (DecodeByte (data[start]) < 0) THEN
            RETURN -1;
          END;
          INC (start); DEC (len);
        END;
        IF (start # end) & IsEOL(data[start]) THEN
          RETURN start;
        END;
      END;
    END;
    RETURN -1;
  END LineData;

PROCEDURE LineEnd* (data[NO_COPY]: ARRAY OF CHAR;
                    start, end: LONGINT): LONGINT;
(**If the text starting a @samp{data[start]} holds a valid @samp{end} of a
   uuencode file, then return the index of the first eol character of the
   @samp{begin} line.  In this case, @samp{data[start, result-1]} is the
   complete line, without the eol character that ends it.

   If there is no match, then result @samp{-1}.  If the indicated region of
   @oparam{data} holds no end of line character, then no match is possible.  *)
  BEGIN
    IF (end-start >= 4) &
       LookingAt(data, start, "end") &
       IsEOL (data[start+3]) THEN
      RETURN start+3;
    ELSE
      RETURN -1;
    END;
  END LineEnd;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                  start, end: LONGINT;
                                  b: StringBuffer.StringBuffer);
  CONST
    overhead = 65*4;
    sizeBuffer = 4*1024;
  VAR
    d: ARRAY sizeBuffer+overhead OF CHAR;
    dpos, i, len, triplets, lineEnd, shift, byte, t, shortData: LONGINT;
  BEGIN
    IF (dec.incompleteSize # 0) THEN    (* pending incomplete line *)
      IF (dec.incompleteSize+(end-start) >= dec.incompleteLength) THEN
        (* we have enough data for the whole line: assemble and decode it *)
        len := dec.incompleteLength-dec.incompleteSize;
        SYSTEM.MOVE (SYSTEM.ADR(data[start]),
                     SYSTEM.ADR(dec.incompleteData[dec.incompleteSize]),
                     len);
        dec.incompleteSize := 0;        (* break recursion *)
        dec.Decode (dec.incompleteData, 0, dec.incompleteLength, b);
        INC (start, len);
      ELSE
        (* still not enough data: add more data to buffer and exit *)
        SYSTEM.MOVE (SYSTEM.ADR(data[start]),
                     SYSTEM.ADR(dec.incompleteData[dec.incompleteSize]),
                     end-start);
        INC (dec.incompleteSize, end-start);
        RETURN;
      END;
    END;
    
    dpos := 0;
    LOOP
      (* skip any newline characters; empty lines are skipped, and two joined
         uuencode lines are accepted  *)
      WHILE (start # end) & IsEOL (data[start]) DO INC (start) END;
      
      IF (start = end) THEN              (* processed all data *)
        EXIT
      ELSE
        len := DecodeByte (data[start]);
        ASSERT (len >= 0, Codec.invalidData);
        triplets := (len+2) DIV 3;
        shortData := len-triplets*3;
        lineEnd := start+1+triplets*4;
        IF (lineEnd > end) THEN  (* incomplete line *)
          SYSTEM.MOVE (SYSTEM.ADR(data[start]),
                       SYSTEM.ADR(dec.incompleteData),
                       end-start);
          dec.incompleteLength := 1+triplets*4;
          dec.incompleteSize := end-start;
          EXIT
        ELSE
          INC (start);
          FOR i := 0 TO triplets-1 DO
            t := 0; shift := 18;
            WHILE (shift >= 0) DO
              byte := DecodeByte(data[start]);
              ASSERT (byte >= 0, Codec.invalidData);
              INC (t, ASH(byte, shift));
              INC (start);
              DEC (shift, 6);
            END;

            d[dpos] := CHR (t DIV (256*256));
            d[dpos+1] := CHR (t DIV 256 MOD 256);
            d[dpos+2] := CHR (t MOD 256);
            INC (dpos, 3);
          END;
          INC (dpos, shortData);
          
          IF (dpos >= sizeBuffer) THEN
            b.AppendLatin1Region (d, 0, dpos);
            dpos := 0;
          END;
        END;
      END;
    END;
    b.AppendLatin1Region (d, 0, dpos);
  END Decode;

PROCEDURE (dec: Decoder) Reset*;
  BEGIN
    dec. incompleteSize := 0;
  END Reset;

PROCEDURE EncodeByte (b: LONGINT): CHAR;
  BEGIN
    IF (b = 0) THEN
      RETURN CHR(20H+40H);
    ELSE
      RETURN CHR(b+20H);
    END;
  END EncodeByte;

PROCEDURE EncodeLine (data[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT;
                      VAR out: ARRAY OF CHAR; VAR opos: LONGINT);
(* precond: start+(end-start+3) <= LEN(d),
   opos+(end-start+2) DIV 3*4 +2 <= LEN(out) *)
  VAR
    t: LONGINT;
  BEGIN
    out[opos] := EncodeByte (end-start);
    INC (opos);
    WHILE (start < end) DO
      t := LONG (ORD (data[start]))*256*256 +
          LONG (ORD (data[start+1]))*256 +
          LONG (ORD (data[start+2]));
      out[opos] := EncodeByte (ASH (t, -18));
      out[opos+1] := EncodeByte (ASH (t, -12) MOD 64);
      out[opos+2] := EncodeByte (ASH (t, -6) MOD 64);
      out[opos+3] := EncodeByte (t MOD 64);
      INC (start, 3);
      INC (opos, 4);
    END;
    out[opos] := Ascii.lf;
    INC (opos);
  END EncodeLine;

PROCEDURE (enc: Encoder) EncodeLatin1*(s[NO_COPY]: ARRAY OF CHAR;
                                       start, end: LONGINT;
                                       b: StringBuffer.StringBuffer);
  CONST
    sizeBuffer = 4*1024;
  VAR
    d: ARRAY sizeBuffer+lengthBufferCode OF CHAR;
    dpos, len: LONGINT;
  BEGIN
    dpos := 0;
    IF (enc.incompleteSize # 0) THEN    (* pending incomplete line *)
      IF (enc.incompleteSize+(end-start) >= lineLength) THEN
        (* we have enough data for the whole line: assemble and encode it *)
        len := lineLength-enc.incompleteSize;
        SYSTEM.MOVE (SYSTEM.ADR(s)+start,
                     SYSTEM.ADR(enc.incompleteData[enc.incompleteSize]),
                     len);
        enc.incompleteSize := 0;
        EncodeLine (enc.incompleteData, 0, lineLength, d, dpos);
        INC (start, len);
      ELSE
        (* still not enough data: add more data to buffer and exit *)
        SYSTEM.MOVE (SYSTEM.ADR(s)+start,
                     SYSTEM.ADR(enc.incompleteData[enc.incompleteSize]),
                     end-start);
        INC (enc.incompleteSize, end-start);
        RETURN;
      END;
    END;
    
    WHILE (start+lineLength <= end) DO
      EncodeLine (s, start, start+lineLength, d, dpos);
      
      IF (dpos >= sizeBuffer) THEN
        b.AppendLatin1Region (d, 0, dpos);
        dpos := 0;
      END;
      
      INC (start, lineLength);
    END;
    b.AppendLatin1Region (d, 0, dpos);

    (* store unprocessed data for later *)
    IF (end > start) THEN
      SYSTEM.MOVE (SYSTEM.ADR(s)+start,
                   SYSTEM.ADR(enc.incompleteData),
                   end-start);
    END;
    enc.incompleteSize := end-start;
  END EncodeLatin1;

PROCEDURE (enc: Encoder) EncodeUTF16*(s[NO_COPY]: ARRAY OF LONGCHAR;
                                      start, end: LONGINT;
                                      b: StringBuffer.StringBuffer);
  BEGIN
    ASSERT(FALSE);
  END EncodeUTF16;
  
PROCEDURE (enc: Encoder) Closure*(b: StringBuffer.StringBuffer);
  VAR
    d: ARRAY lengthBufferCode OF CHAR;
    i: LONGINT;
  BEGIN
    IF (enc.incompleteSize # 0) THEN
      FOR i := 0 TO 2 DO
        enc.incompleteData[enc.incompleteSize+i] := 0X;
      END;
      i := 0;
      EncodeLine (enc.incompleteData, 0, enc.incompleteSize, d, i);
      b.AppendLatin1Region (d, 0, i);
    END;
  END Closure;

PROCEDURE (enc: Encoder) Reset*;
  BEGIN
    enc. incompleteSize := 0;
  END Reset;

PROCEDURE Register*;
  BEGIN
    Codec.Register (uu, "uu");
  END Register;

BEGIN
  uu := NEW(UU, Codec.transport, "uu");
END Codec:UU.
