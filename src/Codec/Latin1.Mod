MODULE Codec:Latin1 [OOC_EXTENSIONS];

IMPORT
  Codec, String := Language:String0;


TYPE
  Latin1* = POINTER TO Latin1Desc;
  Latin1Desc = RECORD
    (Codec.CodecDesc) 
  END;
  Decoder = POINTER TO DecoderDesc;
  DecoderDesc = RECORD
    (Codec.DecoderDesc)
  END;
  Encoder = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.EncoderDesc)
  END;

VAR
  latin1-: Latin1;

(* Codec: Latin1
   ------------------------------------------------------------------------ *)

PROCEDURE InitLatin1 (c: Latin1; preferredName: ARRAY OF CHAR);
  BEGIN
    Codec.InitCodec (c, Codec.unicode, preferredName);
  END InitLatin1;

PROCEDURE (c: Latin1) NewDecoder*(): Decoder;
  VAR
    dec: Decoder;
  BEGIN
    NEW (dec);
    Codec.InitDecoder (dec);
    RETURN dec;
  END NewDecoder;

PROCEDURE (c: Latin1) NewEncoder*(): Encoder;
  VAR
    enc: Encoder;
  BEGIN
    NEW (enc);
    Codec.InitEncoder (enc);
    RETURN enc;
  END NewEncoder;

PROCEDURE (c: Latin1) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                    start, end: LONGINT): String.String;
  BEGIN
    RETURN String.NewLatin1Region(data, start, end);
  END DecodeRegion;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                            start, end: LONGINT;
                                            b: String.Buffer);
  BEGIN
    b. AppendLatin1Region (data, start, end);
  END Decode;
  
PROCEDURE (c: Latin1) EncodeRegion*(s: String.String;
                                    start, end: LONGINT): String.String8;
  VAR
    i, len: LONGINT;
    d: POINTER TO ARRAY OF CHAR;
    d8: String.CharsLatin1;
    d32: String.CharsUTF32;
  BEGIN
    WITH s: String.String8 DO
      d8 := s.CharsLatin1();
      RETURN String.NewLatin1Region(d8^, start, end);
      
    | s: String.String32 DO
      d32 := s.CharsUTF32();
      len := end-start;
      NEW (d, len+1);
      i := 0;
      WHILE (start # end) DO
        ASSERT (d32[start] < 256, String.invalidChar);
        d[i] := CHR (d32[start]);
        INC (start); INC (i);
      END;
      d[len] := 0X;
      RETURN String.NewLatin1Region(d^, 0, len);
    END;
  END EncodeRegion;

PROCEDURE (enc: Encoder) Encode*(s: String.String;
                                           start, end: LONGINT;
                                           b: String.Buffer);
  VAR
    d: String.BufferLatin1;
    d8: String.CharsLatin1;
    d32: String.CharsUTF32;
    i: LONGINT;
  BEGIN
    WITH s: String.String8 DO
      d8 := s.CharsLatin1();
      b. AppendLatin1Region (d8^, 0, s. length);
      
    | s: String.String32 DO
      d32 := s.CharsUTF32();
      i := 0;
      WHILE (start # end) DO
        ASSERT (d32[start] < 256, String.invalidChar);
        d[i] := CHR (d32[start]);
        INC (start); INC (i);

        IF (i = LEN (d)) THEN
          b. AppendLatin1Region (d, 0, i);
          i := 0;
        END;
      END;
      b. AppendLatin1Region (d, 0, i);
    END;
  END Encode;

PROCEDURE (enc: Encoder) Closure*(b: String.Buffer);
  END Closure;

PROCEDURE Register*;
  BEGIN
    Codec.Register (latin1, "ISO_8859-1:1987");
    Codec.Register (latin1, "iso-ir-100");
    Codec.Register (latin1, "ISO_8859-1");
    Codec.Register (latin1, "ISO-8859-1");  (* preferred MIME name *)
    Codec.Register (latin1, "latin1");
    Codec.Register (latin1, "l1");
    Codec.Register (latin1, "IBM819");
    Codec.Register (latin1, "CP819");
    Codec.Register (latin1, "csISOLatin1y");
  END Register;

BEGIN
  NEW (latin1);
  InitLatin1 (latin1, "ISO-8859-1");
END Codec:Latin1.
