MODULE Codec:UTF32 [OOC_EXTENSIONS];

(**Note: This codec is incomplete.  It ignores byte order issues.  *)

IMPORT
  SYSTEM, Object, ADT:StringBuffer, Codec;

  
TYPE
  UTF32* = POINTER TO UTF32Desc;
  UTF32Desc = RECORD
    (Codec.CodecDesc) 
  END;
  Decoder = POINTER TO DecoderDesc;
  DecoderDesc = RECORD
    (Codec.DecoderDesc)
    incomplete: ARRAY 4 OF CHAR;
    incompleteSize: LONGINT;
  END;
  Encoder = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.EncoderDesc)
  END;

CONST
  surrogateStart = 0DC00X;
  surrogateEnd = 0E00X;
  unicodeEnd = 110000X;

VAR
  utf32-: UTF32;

(* Codec: UTF-32 (undefined byte order)
   ------------------------------------------------------------------------ *)

PROCEDURE InitUTF32 (c: UTF32; preferredName: ARRAY OF CHAR);
  BEGIN
    Codec.InitCodec (c, Codec.unicode, preferredName);
  END InitUTF32;

PROCEDURE (c: UTF32) NewDecoder*(): Decoder;
  VAR
    dec: Decoder;
  BEGIN
    NEW (dec);
    Codec.InitDecoder (dec);
    dec. incompleteSize := 0;
    RETURN dec;
  END NewDecoder;

PROCEDURE (c: UTF32) NewEncoder*(): Encoder;
  VAR
    enc: Encoder;
  BEGIN
    NEW (enc);
    Codec.InitEncoder (enc);
    RETURN enc;
  END NewEncoder;

PROCEDURE (c: UTF32) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                   start, end: LONGINT): Object.String;
  VAR
    i: LONGINT;
    d: POINTER TO ARRAY OF UCS4CHAR;
  BEGIN
    ASSERT ((end-start) MOD SIZE(UCS4CHAR) = 0, Codec.invalidData);
    NEW (d, (end-start) DIV SIZE(UCS4CHAR));
    SYSTEM.MOVE(SYSTEM.ADR(data[start]), SYSTEM.ADR(d^), end-start);
    FOR i := 0 TO LEN(d^)-1 DO
      ASSERT ((d[i] < unicodeEnd) &
              ((d[i] < surrogateStart) OR (d[i] >= surrogateEnd)),
              Codec.invalidChar);
    END;
    RETURN Object.NewUCS4Region(d^, 0, LEN(d^));
  END DecodeRegion;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                           start, end: LONGINT;
                                           b: StringBuffer.StringBuffer);
  VAR
    d: Codec.BufferUCS4;
    offset, len, dend, chars, i: LONGINT;
  BEGIN
    offset := dec. incompleteSize;
    IF (end-start+offset >= SIZE(UCS4CHAR)) THEN
      SYSTEM.MOVE(SYSTEM.ADR(dec. incomplete), SYSTEM.ADR(d), offset);

      REPEAT
        len := (end-start-offset);
        SYSTEM.MOVE(SYSTEM.ADR(data[start]), SYSTEM.ADR(d[offset]), len);
        dend := len+offset;
        chars := dend DIV SIZE(UCS4CHAR);
        FOR i := 0 TO chars-1 DO
          ASSERT ((d[i] < unicodeEnd) &
                  ((d[i] < surrogateStart) OR (d[i] >= surrogateEnd)),
                  Codec.invalidChar);
        END;
        b. AppendUCS4Region (d, 0, chars);
        
        INC (start, len);
        offset := 0;
      UNTIL (end-start < SIZE(UCS4CHAR));
                                       
      dec. incompleteSize := dend MOD SIZE(UCS4CHAR);
      IF (dec. incompleteSize # 0) THEN  (* avoid index at end of array d *)
        SYSTEM.MOVE(SYSTEM.ADR(d[dend DIV SIZE(UCS4CHAR)]),
                    SYSTEM.ADR(dec.incomplete), dec. incompleteSize);
      END;
    END;
  END Decode;
  
PROCEDURE (dec: Decoder) Reset*;
  BEGIN
    dec.incompleteSize := 0;
  END Reset;


PROCEDURE (c: UTF32) EncodeRegion*(s: Object.String;
                                   start, end: LONGINT): Object.String8;
  VAR
    i, len: LONGINT;
    d8: Object.CharsLatin1;
    d32: Object.CharsUCS4;
    d: POINTER TO ARRAY OF UCS4CHAR;
    e: POINTER TO ARRAY OF CHAR;
  BEGIN
    WITH s: Object.String32 DO
      NEW (e, (end-start)*SIZE(UCS4CHAR));
      d32 := s.CharsUCS4();
      SYSTEM.MOVE(SYSTEM.ADR(d32^), SYSTEM.ADR(e^), LEN(e^));
      
    | s: Object.String8 DO
      d8 := s.CharsLatin1();
      len := end-start;
      NEW (d, len);
      i := 0;
      WHILE (start # end) DO
        d[i] := d8[start];
        INC (start); INC (i);
      END;
      
      NEW (e, len*SIZE(UCS4CHAR));
      SYSTEM.MOVE(SYSTEM.ADR(d^), SYSTEM.ADR(e^), LEN(e^));
    END;
    RETURN Object.NewLatin1Region(e^, 0, LEN(e^));
  END EncodeRegion;

PROCEDURE (enc: Encoder) Encode*(s: Object.String;
                                          start, end: LONGINT;
                                          b: StringBuffer.StringBuffer);
  VAR
    d8: Codec.BufferLatin1;
    d32: Codec.BufferUCS4;
    s8: Object.CharsLatin1;
    s32: Object.CharsUCS4;
    len, i: LONGINT;
  BEGIN
    WITH s: Object.String8 DO
      s8 := s.CharsLatin1();
      WHILE (start # end) DO
        len := LEN(d32);
        IF (len > end-start) THEN len := end-start; END;
        FOR i := 0 TO len-1 DO
          d32[i] := s8[start+i];
        END;
        SYSTEM.MOVE(SYSTEM.ADR(d32), SYSTEM.ADR(d8), len*SIZE(UCS4CHAR));
        b. AppendLatin1Region (d8, 0, len*SIZE(UCS4CHAR));
        INC (start, len);
      END;
      
    | s: Object.String32 DO
      s32 := s.CharsUCS4();
      WHILE (start # end) DO
        len := SIZE(Codec.BufferUCS4) DIV SIZE(UCS4CHAR);
        IF (len > end-start) THEN len := end-start; END;
        SYSTEM.MOVE(SYSTEM.ADR(s32[start]), SYSTEM.ADR(d8), len*SIZE(UCS4CHAR));
        b. AppendLatin1Region (d8, 0, len*SIZE(UCS4CHAR));
        INC (start, len);
      END;
    END;
  END Encode;

PROCEDURE (enc: Encoder) Closure*(b: StringBuffer.StringBuffer);
  END Closure;

PROCEDURE Register*;
  BEGIN
    Codec.Register (utf32, "UTF-32");
  END Register;

BEGIN
  NEW (utf32);
  InitUTF32 (utf32, "UTF-32");
END Codec:UTF32.
