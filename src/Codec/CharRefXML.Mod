MODULE Codec:CharRefXML;

IMPORT
  IntStr, Object, ADT:StringBuffer, Codec;
  
TYPE
  Encoder = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.EncoderDesc)
  END;

VAR
  encoder-: Encoder;
  
PROCEDURE (enc: Encoder) EncodeLatin1*(s[NO_COPY]: ARRAY OF CHAR;
                                       start, end: LONGINT;
                                       b: StringBuffer.StringBuffer)
RAISES Codec.EncodingError;
  VAR
    str: ARRAY 12 OF CHAR;
  BEGIN
    WHILE (start # end) DO
      b.AppendLatin1("&#");
      IntStr.IntToStr(ORD(s[start]), str);
      b.AppendLatin1(str);
      b.AppendLatin1Char(";");
      INC(start);
    END;
  END EncodeLatin1;

PROCEDURE (enc: Encoder) EncodeUTF16*(s[NO_COPY]: ARRAY OF LONGCHAR;
                                      start, end: LONGINT;
                                      b: StringBuffer.StringBuffer)
RAISES Codec.EncodingError;
  VAR
    str: ARRAY 12 OF CHAR;
    i: LONGINT;
    w1, w2: LONGCHAR;
  BEGIN
    WHILE (start # end) DO
      w1 := s[start];
      INC(start);
      IF (w1 < Object.surrogateLow) OR (w1 >= Object.surrogateEnd) THEN
        (* non-surrogate character *)
        i := ORD(w1);
      ELSIF (start = end) THEN
        RAISE(NEW(Codec.EncodingError, start-1, end));
      ELSE
        w2 := s[start];
        IF (w1 < Object.surrogateHigh) &
           (Object.surrogateHigh <= w2) & (w2 < Object.surrogateEnd) THEN
          INC(start);
          i := (ORD(w1) MOD 1024)*1024 + (ORD(w2) MOD 1024) +
              ORD(Object.surrogateLimit);
        ELSE  (* invalid surrogate pair *)
          RAISE(NEW(Codec.EncodingError, start-1, end));
        END;
      END;
      
      b.AppendLatin1("&#");
      IntStr.IntToStr(i, str);
      b.AppendLatin1(str);
      b.AppendLatin1Char(";");
    END;
  END EncodeUTF16;

BEGIN
  encoder := NEW(Encoder, Codec.exceptionEncoder);
END Codec:CharRefXML.
