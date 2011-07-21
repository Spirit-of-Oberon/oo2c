(* 	$Id: YEnc.Mod,v 1.1 2003/09/22 19:32:17 mva Exp $	 *)
MODULE Codec:YEnc [OOC_EXTENSIONS];
(*  Codec for yEnc transport encoding.
    Copyright (C) 2002  Michael van Acken

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
  Ascii, CharClass, Codec, IntStr, Object, ADT:StringBuffer, Codec:UU;

CONST
  lineLength = 128;
  maxLineLength = 998; (* maximum number of bytes per line when encoding *)
  escapeChar = "=";
  
TYPE
  YEnc* = POINTER TO YEncDesc;
  YEncDesc = RECORD
    (Codec.CodecDesc)
  END;

TYPE
  Encoder* = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.EncoderDesc)
    incompleteAvail: LONGINT; (* characters left in current line *)
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
    endsWithEscape: BOOLEAN;
  END;

TYPE
  Header* = RECORD
    part-: LONGINT;                      (* -1 if no part number is given *)
    line-: LONGINT;
    size-: LONGINT;
    fileName-: ARRAY 256 OF CHAR;
    (**File name from the @samp{ybegin} line.  If the name starts and ends with
       a double quote @samp{"}, then the quote is removed.  If the name is
       to long to be stored in this field, then it is truncated.  *)

    partBegin-, partEnd-: LONGINT;

    endSize-: LONGINT;
    endPart-: LONGINT;
    hasPCrc32-: BOOLEAN;
    endPCrc32-: LONGINT;
    hasCrc32-: BOOLEAN;
    endCrc32-: LONGINT;
    
    shortLines-: LONGINT;
  END;
  
VAR
  yenc-: YEnc;

PROCEDURE (c: YEnc) NewDecoder*(): Decoder;
  VAR
    dec: Decoder;
  BEGIN
    NEW (dec);
    Codec.InitDecoder (dec);
    dec.endsWithEscape := FALSE;
    RETURN dec;
  END NewDecoder;

PROCEDURE (c: YEnc) NewEncoder*(): Encoder;
  VAR
    enc: Encoder;
  BEGIN
    NEW (enc);
    Codec.InitEncoder (enc);
    enc.incompleteAvail := lineLength;
    RETURN enc;
  END NewEncoder;

PROCEDURE LookingAt (data[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT;
                     s: ARRAY OF CHAR): BOOLEAN;
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0; j := start;
    WHILE (s[i] # 0X) & (start # end) & (data[j] = s[i]) DO
      INC (i); INC (j);
    END;
    RETURN (s[i] = 0X);
  END LookingAt;

PROCEDURE GetNumber(data[NO_COPY]: ARRAY OF CHAR; VAR start: LONGINT;
                    end: LONGINT): LONGINT;
(**An error returns -1.  *)
  VAR
    i, pos: LONGINT;
    str: ARRAY 32 OF CHAR;
    res: IntStr.ConvResults;
  BEGIN
    IF (start # end) & CharClass.IsNumeric(data[start]) THEN
      i := 0;
      pos := start;
      REPEAT
        IF (i < LEN(str)) THEN
          str[i] := data[start];
        END;
        INC (i);
        INC (start);
      UNTIL (start = end) OR ~CharClass.IsNumeric(data[start]);
      IF (i < LEN(str)) THEN
        str[i] := 0X;
        IntStr.StrToInt(str, i, res);
        IF (res = IntStr.strAllRight) THEN
          RETURN i;
        END;
      END;
    END;
    RETURN -1;
  END GetNumber;
  
PROCEDURE IsEOL* (ch: CHAR): BOOLEAN;
  BEGIN
    RETURN (ch = Ascii.lf) OR (ch = Ascii.cr);
  END IsEOL;

PROCEDURE SkipWS (data[NO_COPY]: ARRAY OF CHAR;
                  VAR start: LONGINT; end: LONGINT);
  BEGIN
    WHILE (start # end) & (data[start] <= " ") & ~IsEOL (data[start]) DO
      INC (start);
    END;
  END SkipWS;

PROCEDURE LineBegin* (data[NO_COPY]: ARRAY OF CHAR;
                      start, end: LONGINT; VAR header: Header): LONGINT;
(**If the text starting a @samp{data[start]} holds a valid @samp{begin} of a
   yencoded file, then return the index of the first eol character of the
   @samp{begin} line.  In this case, @samp{data[start, result-1]} is the
   complete line, without the eol character that ends it.

   If there is no match, then result @samp{-1}.  If the indicated region of
   @oparam{data} holds no end of line character, then no match is possible.  *)
  VAR
    posFileName, endFileName: LONGINT;
  BEGIN
    IF LookingAt (data, start, end, "=ybegin ") THEN
      INC (start, 8);
      header.part := -1;
      header.partBegin := -1;
      header.partEnd := -1;
      header.shortLines := 0;

      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "part=") THEN
        INC (start, 5);
        header.part := GetNumber(data, start, end);
        IF (header.part < 1) THEN
          RETURN -1;                     (* malformed part number *)
        END;
      END;
      
      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "line=") THEN
        INC (start, 5);
        header.line := GetNumber(data, start, end);
        IF (header.line < 63) OR (header.line > maxLineLength) THEN
          RETURN -1;       (* malformed line length or out of range *)
        END;
      ELSE
        RETURN -1;                       (* missing line length *)
      END;

      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "size=")  THEN
        INC (start, 5);
        header.size := GetNumber(data, start, end);
        IF (header.size < 1)  THEN       (* max: 2^62-1 *)
          RETURN -1;              (* malformed size or out of range *)
        END;
      ELSE
        RETURN -1;                       (* missing file size *)
      END;

      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "name=") THEN
        INC (start, 5);

        SkipWS(data, start, end);                          (* skip whitespace before name *)
        posFileName := start;
        WHILE (start # end) & ~UU.IsEOL(data[start]) DO
          INC (start);
        END;
        IF (start # end) THEN
          endFileName := start;
          WHILE (endFileName > posFileName) & (data[endFileName-1] <= " ") DO
            DEC (endFileName);           (* skip whitespace after name *)
          END;
          IF (data[posFileName] = '"') & (endFileName >= posFileName+2) &
             (data[endFileName-1] = '"') THEN (* strip quotes *)
            INC (posFileName);
            DEC (endFileName);
          END;
          UU.Extract(data, posFileName, endFileName, header.fileName);
          RETURN start;
        END;
      ELSE
        RETURN -1;                       (* missing file name *)
      END;
    END;
    RETURN -1;
  END LineBegin;

PROCEDURE LinePart* (data[NO_COPY]: ARRAY OF CHAR;
                     start, end: LONGINT; VAR header: Header): LONGINT;
  BEGIN
    IF LookingAt (data, start, end, "=ypart ") THEN
      INC (start, 7);
      
      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "begin=") THEN
        INC (start, 6);
        header.partBegin := GetNumber(data, start, end);
        IF (header.partBegin < 1) OR (header.partBegin > header.size) THEN
          RETURN -1;       (* malformed part begin or out of range *)
        END;
      ELSE
        RETURN -1;                       (* missing begin *)
      END;

      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "end=")  THEN
        INC (start, 4);
        header.partEnd := GetNumber(data, start, end);
        IF (header.partEnd < header.partBegin) OR
           (header.partEnd > header.size) THEN
          RETURN -1;              (* malformed end or out of range *)
        END;
      ELSE
        RETURN -1;                       (* missing end *)
      END;

      SkipWS(data, start, end);
      IF (start # end) & UU.IsEOL(data[start]) THEN
        RETURN start;
      END;
    END;
    RETURN -1;
  END LinePart;

PROCEDURE LineData* (data[NO_COPY]: ARRAY OF CHAR;
                     start, end: LONGINT;
                     VAR header: Header): LONGINT;
(**If the text starting a @samp{data[start]} holds a complete text line with
   yencoded data, then return the index of the first eol character of the line.
   In this case, @samp{data[start, result-1]} is the complete line, without the
   eol character that ends it.

   If there is no match, then result @samp{-1}.  If the indicated region of
   @oparam{data} holds no end of line character, then no match is possible.

   If the data line is shorted than the announced line length in the
   @samp{=ybegin} header, then @ofield{header.shortLines} is incremented by
   one.  *)
  VAR
    startOfLine: LONGINT;
  BEGIN
    IF (end >= start+2) &
       (data[start] = escapeChar) & (data[start+1] = "y") THEN
      RETURN -1;                         (* =ybegin, =yend, =ypart, etc. *)
    ELSE
      startOfLine := start;
      WHILE (start # end) &
            (data[start] # Ascii.nul) &
            (data[start] # Ascii.lf) &
            (data[start] # Ascii.cr) DO
        INC (start);
      END;
      IF (start = startOfLine) OR          (* empty line *)
         (start = end) OR                  (* no eol char after line *)
         (data[start] = Ascii.nul) OR      (* invalid character in line *)
         (data[start-1] = "=") OR          (* unpaired escape at end *)
         (start-startOfLine > header.line+1) THEN (* line too long *)
        RETURN -1; (* empty line, no eol char, or invalid character in line *)
      ELSIF (start-startOfLine = header.line) OR
            (start-startOfLine = header.line+1) & (data[start-2] = "=") THEN
        RETURN start;                   (* line length matches header *)
      ELSE
        INC (header.shortLines);
        RETURN start;
      END;
    END;
  END LineData;

PROCEDURE LineEnd* (data[NO_COPY]: ARRAY OF CHAR;
                    start, end: LONGINT; VAR header: Header): LONGINT;
(**If the text starting a @samp{data[start]} holds a valid @samp{end} of a
   uuencode file, then return the index of the first eol character of the
   @samp{begin} line.  In this case, @samp{data[start, result-1]} is the
   complete line, without the eol character that ends it.

   If there is no match, then result @samp{-1}.  If the indicated region of
   @oparam{data} holds no end of line character, then no match is possible.  *)

  PROCEDURE GetCRC (VAR ok: BOOLEAN): LONGINT;
    VAR
      pos: LONGINT;

    PROCEDURE IsHex (ch: CHAR): BOOLEAN;
      BEGIN
        RETURN ("0" <= ch) & (ch <= "9") OR
            ("A" <= CAP(ch)) & (CAP(ch) <= "F");
      END IsHex;
    
    BEGIN
      pos := start;
      WHILE (start # end) & IsHex(data[start]) DO
        INC (start);
      END;
      (* assume that numbers shorter than 8 are left padded with 0s *)
      ok := (start-pos > 0) & (start-pos <= 8);
      RETURN 1;
    END GetCRC;
  
  BEGIN
    IF LookingAt(data, start, end, "=yend ") THEN
      INC(start, 6);
      SkipWS(data, start, end);
      IF LookingAt(data, start, end, "size=") THEN
        INC(start, 5);
        
        header.hasCrc32 := FALSE;
        header.endSize := GetNumber(data, start, end);
        IF (header.endSize < 1) THEN
          RETURN -1;                     (* malformed size *)
        ELSE
          SkipWS(data, start, end);

          IF LookingAt(data, start, end, "part=") THEN
            INC(start, 5);
            header.hasPCrc32 := FALSE;
            header.endPart := GetNumber(data, start, end);
            IF (header.endPart < 1) THEN
              RETURN -1;                 (* malformed part number *)
            ELSE
              SkipWS(data, start, end);
              IF LookingAt(data, start, end, "pcrc32=") THEN
                INC(start, 7);
                header.endPCrc32 := GetCRC(header.hasPCrc32);
                IF ~header.hasPCrc32 THEN
                  RETURN -1;             (* malformed CRC32 number *)
                END;
              END;
            END;
            SkipWS(data, start, end);
          ELSE
            header.endPart := -1;
          END;

          IF LookingAt(data, start, end, "crc32=") THEN
            INC(start, 6);
            header.endCrc32 := GetCRC(header.hasCrc32);
            IF ~header.hasCrc32 THEN
              RETURN -1;             (* malformed CRC32 number *)
            END;
            SkipWS(data, start, end);
          END;
          
          IF (start # end) & UU.IsEOL(data[start]) THEN
            RETURN start;
          END;
        END;
      END;
    END;
    RETURN -1;
  END LineEnd;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                  start, end: LONGINT;
                                  b: StringBuffer.StringBuffer);
  CONST
    sizeBuffer = 4*1024;
  VAR
    d: ARRAY sizeBuffer+maxLineLength+3 OF CHAR;
    dpos: LONGINT;
    ch: CHAR;
  BEGIN
    dpos := 0;
    IF dec.endsWithEscape THEN
      IF (start = end) THEN
        RETURN;                      (* nothing to do *)
      ELSE
        d[0] := CHR((ORD(data[start])-(64+42)) MOD 256);
        INC (start);
        dpos := 1;
        dec.endsWithEscape := FALSE;
      END;
    END;
    
    LOOP
      IF (start = end) THEN
        EXIT;   (* end of data *)
      ELSIF (data[start] = escapeChar) THEN
        IF (start+1 = end) THEN
          (* incomplete line: lonely escape character *)
          dec.endsWithEscape := TRUE;
          EXIT;
        END;
        ASSERT (~UU.IsEOL(data[start]), Codec.invalidData);
        d[dpos] := CHR((ORD(data[start+1])-(64+42)) MOD 256);
        INC (dpos);
        INC (start, 2);
      ELSE
        ch := data[start];
        IF (ch # Ascii.lf) & (ch # Ascii.cr) & (ch # 0X) THEN
          d[dpos] := CHR((ORD(ch)-42) MOD 256);
          INC (dpos);
        END;
        INC (start);
      END;
      
      IF (dpos >= sizeBuffer) THEN
        b.AppendLatin1Region (d, 0, dpos);
        dpos := 0;
      END
    END;
    b.AppendLatin1Region (d, 0, dpos);
  END Decode;

PROCEDURE (dec: Decoder) Reset*;
  BEGIN
    dec. endsWithEscape := FALSE;
  END Reset;

PROCEDURE (enc: Encoder) Encode*(s: Object.String;
                                 start, end: LONGINT;
                                 b: StringBuffer.StringBuffer);
  CONST
    sizeBuffer = 4*1024;
  VAR
    d: ARRAY sizeBuffer+lineLength+2 OF CHAR;
    c: Object.CharsLatin1;
    dpos, avail: LONGINT;
    ch: CHAR;
  BEGIN
    c := s(Object.String8).CharsLatin1();

    dpos := 0;
    avail := enc.incompleteAvail;
    WHILE (start # end) DO
      WHILE (start # end) & (avail > 0) DO
        ch := CHR((ORD(c[start])+42) MOD 256);
        IF (ch = Ascii.nul) OR (ch = Ascii.cr) OR
           (ch = Ascii.lf) OR (ch = escapeChar) OR 
           ((ch = " ") OR (ch = 0X)) & ((avail = lineLength) OR (avail = 1)) THEN
          d[dpos] := escapeChar;
          d[dpos+1] := CHR((ORD(ch)+64) MOD 256);
          INC (dpos, 2);
          DEC (avail, 2);
        ELSE
          d[dpos] := ch;
          ASSERT (ch # "=");
          INC (dpos);
          DEC (avail);
        END;
        INC (start);
      END;
      
      IF (avail <= 0) THEN
        d[dpos] := Ascii.lf;
        INC (dpos);
        avail := lineLength;
        
        IF (dpos >= sizeBuffer) THEN
          b.AppendLatin1Region (d, 0, dpos);
          dpos := 0;
        END;
      END;
    END;
    b.AppendLatin1Region (d, 0, dpos);
    enc.incompleteAvail := avail;
  END Encode;

PROCEDURE (enc: Encoder) Closure*(b: StringBuffer.StringBuffer);
  BEGIN
    IF (enc.incompleteAvail # lineLength) THEN
      b.AppendLatin1Char(Ascii.lf);
      enc.incompleteAvail := lineLength;
    END;
  END Closure;

PROCEDURE (enc: Encoder) Reset*;
  BEGIN
    enc.incompleteAvail := lineLength;
  END Reset;

PROCEDURE Register*;
  BEGIN
    Codec.Register (yenc, "yEnc");
  END Register;

BEGIN
  NEW (yenc);
  Codec.InitCodec (yenc, Codec.transport, "yEnc");
END Codec:YEnc.
