MODULE Codec:Ascii [OOC_EXTENSIONS];

IMPORT
  Object, ADT:StringBuffer, Codec;


TYPE
  Ascii* = POINTER TO AsciiDesc;
  AsciiDesc = RECORD
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
  codec-: Ascii;

(* Codec: Ascii
   ------------------------------------------------------------------------ *)

PROCEDURE (c: Ascii) INIT*(preferredName: ARRAY OF CHAR);
  BEGIN
    c.INIT^(Codec.unicode, preferredName);
  END INIT;

PROCEDURE (c: Ascii) NewDecoder*(): Decoder;
  BEGIN
    RETURN NEW(Decoder);
  END NewDecoder;

PROCEDURE (c: Ascii) NewEncoder*(): Encoder;
  BEGIN
    RETURN NEW(Encoder, Codec.exceptionEncoder);
  END NewEncoder;

PROCEDURE (c: Ascii) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                    start, end: LONGINT): STRING;
  BEGIN
    RETURN Object.NewLatin1Region(data, start, end);
  END DecodeRegion;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                  start, end: LONGINT;
                                  b: StringBuffer.StringBuffer);
  BEGIN
    b. AppendLatin1Region (data, start, end);
  END Decode;
  
PROCEDURE (enc: Encoder) EncodeLatin1*(s[NO_COPY]: ARRAY OF CHAR;
                                       start, end: LONGINT;
                                       b: StringBuffer.StringBuffer)
RAISES Codec.EncodingError;
  VAR
    i: LONGINT;
  BEGIN
    WHILE (start # end) DO
      i := start;
      WHILE (i # end) & (s[i] < 80X) DO
        INC(i);
      END;
      b.AppendLatin1Region(s, start, i);

      start := i;
      IF (start # end) THEN
        REPEAT
          INC(i);
        UNTIL (i = end) OR (s[i] < 80X);
        Codec.EscapeLatin1(enc, s, start, i, b);
        start := i;
      END;
    END;
  END EncodeLatin1;

PROCEDURE (enc: Encoder) EncodeUTF16*(s[NO_COPY]: ARRAY OF LONGCHAR;
                                      start, end: LONGINT;
                                      b: StringBuffer.StringBuffer)
RAISES Codec.EncodingError;
  VAR
    d: Codec.BufferLatin1;
    i: LONGINT;
  BEGIN
    WHILE (start # end) DO
      i := 0;
      WHILE (start # end) & (s[start] < 80X) DO
        d[i] := SHORT(s[start]);
        INC(start);INC (i);
        
        IF (i = LEN(d)) THEN
          b.AppendLatin1Region(d, 0, i);
          i := 0;
        END;
      END;
      b.AppendLatin1Region(d, 0, i);
      
      IF (start # end) THEN
        i := start;
        REPEAT
          INC(i);
        UNTIL (i = end) OR (s[i] < 80X);
        Codec.EscapeUTF16(enc, s, start, i, b);
        start := i;
      END;
    END;
  END EncodeUTF16;

PROCEDURE Register*;
  BEGIN
    Codec.Register (codec, "ANSI_X3.4-1968");
    Codec.Register (codec, "iso-ir-6");
    Codec.Register (codec, "ANSI_X3.4-1986");
    Codec.Register (codec, "ISO_646.irv:1991");
    Codec.Register (codec, "ASCII");
    Codec.Register (codec, "ISO646-US");
    Codec.Register (codec, "US-ASCII");  (* preferred MIME name *)
    Codec.Register (codec, "us");
    Codec.Register (codec, "IBM367");
    Codec.Register (codec, "cp367");
    Codec.Register (codec, "csASCII");
  END Register;

BEGIN
  codec := NEW(Ascii, "US-ASCII");
END Codec:Ascii.
