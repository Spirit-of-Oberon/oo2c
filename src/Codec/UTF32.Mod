MODULE Codec:UTF32 [OOC_EXTENSIONS];

(**Note: This codec is incomplete.  It ignores byte order issues.  *)

IMPORT
  SYSTEM, Codec, String := Language:String0;

  
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
  surrogateStart = 0DC00H;
  surrogateEnd = 0E00H;
  unicodeEnd = 110000H;

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
                                   start, end: LONGINT): String.String;
  VAR
    i: LONGINT;
    d: POINTER TO ARRAY OF String.Char;
  BEGIN
    ASSERT ((end-start) MOD SIZE(String.Char) = 0, String.invalidData);
    NEW (d, (end-start) DIV SIZE(String.Char));
    SYSTEM.MOVE(SYSTEM.ADR(data[start]), SYSTEM.ADR(d^), end-start);
    FOR i := 0 TO LEN(d^)-1 DO
      ASSERT ((d[i] < unicodeEnd) &
              ((d[i] < surrogateStart) OR (d[i] >= surrogateEnd)),
              String.invalidChar);
    END;
    RETURN String.NewUTF32Region(d^, 0, LEN(d^));
  END DecodeRegion;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                           start, end: LONGINT;
                                           b: String.Buffer);
  VAR
    d: String.BufferUTF32;
    offset, len, dend, chars, i: LONGINT;
  BEGIN
    offset := dec. incompleteSize;
    IF (end-start+offset >= SIZE(String.Char)) THEN
      SYSTEM.MOVE(SYSTEM.ADR(dec. incomplete), SYSTEM.ADR(d), offset);

      REPEAT
        len := (end-start-offset);
        SYSTEM.MOVE(SYSTEM.ADR(data[start]), SYSTEM.ADR(d[offset]), len);
        dend := len+offset;
        chars := dend DIV SIZE(String.Char);
        FOR i := 0 TO chars-1 DO
          ASSERT ((d[i] < unicodeEnd) &
                  ((d[i] < surrogateStart) OR (d[i] >= surrogateEnd)),
                  String.invalidChar);
        END;
        b. AppendUTF32Region (d, 0, chars);
        
        INC (start, len);
        offset := 0;
      UNTIL (end-start < SIZE(String.Char));
                                       
      dec. incompleteSize := dend MOD SIZE(String.Char);
      IF (dec. incompleteSize # 0) THEN  (* avoid index at end of array d *)
        SYSTEM.MOVE(SYSTEM.ADR(d[dend DIV SIZE(String.Char)]),
                    SYSTEM.ADR(dec.incomplete), dec. incompleteSize);
      END;
    END;
  END Decode;
  
PROCEDURE (dec: Decoder) Reset*;
  BEGIN
    dec.incompleteSize := 0;
  END Reset;


PROCEDURE (c: UTF32) EncodeRegion*(s: String.String;
                                   start, end: LONGINT): String.String8;
  VAR
    i, len: LONGINT;
    d8: String.CharsLatin1;
    d, d32: String.CharsUTF32;
    e: POINTER TO ARRAY OF CHAR;
  BEGIN
    WITH s: String.String32 DO
      NEW (e, (end-start)*SIZE(String.Char));
      d32 := s.CharsUTF32();
      SYSTEM.MOVE(SYSTEM.ADR(d32^), SYSTEM.ADR(e^), LEN(e^));
      
    | s: String.String8 DO
      d8 := s.CharsLatin1();
      len := end-start;
      NEW (d, len);
      i := 0;
      WHILE (start # end) DO
        d[i] := ORD (d8[start]);
        INC (start); INC (i);
      END;
      
      NEW (e, len*SIZE(String.Char));
      SYSTEM.MOVE(SYSTEM.ADR(d^), SYSTEM.ADR(e^), LEN(e^));
    END;
    RETURN String.NewLatin1Region(e^, 0, LEN(e^));
  END EncodeRegion;

PROCEDURE (enc: Encoder) Encode*(s: String.String;
                                          start, end: LONGINT;
                                          b: String.Buffer);
  VAR
    d8: String.BufferLatin1;
    d32: String.BufferUTF32;
    s8: String.CharsLatin1;
    s32: String.CharsUTF32;
    len, i: LONGINT;
  BEGIN
    WITH s: String.String8 DO
      s8 := s.CharsLatin1();
      WHILE (start # end) DO
        len := LEN(d32);
        IF (len > end-start) THEN len := end-start; END;
        FOR i := 0 TO len-1 DO
          d32[i] := ORD (s8[start+i]);
        END;
        SYSTEM.MOVE(SYSTEM.ADR(d32), SYSTEM.ADR(d8), len*SIZE(String.Char));
        b. AppendLatin1Region (d8, 0, len*SIZE(String.Char));
        INC (start, len);
      END;
      
    | s: String.String32 DO
      s32 := s.CharsUTF32();
      WHILE (start # end) DO
        len := SIZE(String.BufferLatin1) DIV SIZE(String.Char);
        IF (len > end-start) THEN len := end-start; END;
        SYSTEM.MOVE(SYSTEM.ADR(s32[start]), SYSTEM.ADR(d8), len*SIZE(String.Char));
        b. AppendLatin1Region (d8, 0, len*SIZE(String.Char));
        INC (start, len);
      END;
    END;
  END Encode;

PROCEDURE (enc: Encoder) Closure*(b: String.Buffer);
  END Closure;

PROCEDURE Register*;
  BEGIN
    Codec.Register (utf32, "UTF-32");
  END Register;

BEGIN
  NEW (utf32);
  InitUTF32 (utf32, "UTF-32");
END Codec:UTF32.
