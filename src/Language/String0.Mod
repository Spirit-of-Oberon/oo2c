(* 	$Id$	 *)
MODULE Language:String0 [OOC_EXTENSIONS];
(*  Character strings based on Unicode 3.1.
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

(* NOTE: This module is intended to become Language:String eventually.
   It will replace the current Language:String, Language:String8, and
   Language:String16 modules.
   
   Importing it as String:=Language:String0 might save a lot of changes
   later.  *)

IMPORT
  SYSTEM;


(**This modules provides a string abstraction based on the code point
   definitions of Unicode 3.1.  It defines the classes @otype{String},
   @otype{Buffer}, and @otype{Codec}, representing string values, a way to put
   strings together, and a mechanism to translate between string
   representations.

   In order of importance, the use cases addressed by these classes are

   @itemize @bullet
   @item
   Creating Unicode 3.1 string values and passing them around in an easy and
   efficient way.
   @item
   Interacting with Oberon-2's notion of strings.  In particular, it must be
   easy to pass a string to an @code{ARRAY OF CHAR}, and vice versa.
   @item
   Translating between different encodings of string values, for example from
   UTF-8 to Latin-1.
   @item
   Support for stateful codecs, including operations like encryption and
   decryption.
   @item
   Encoding or decoding a chunked stream of bytes, while giving the programmer
   some control over the resources being used for this purpose.
   @item
   Efficient access to a string's value as a sequence of characters.  This is
   for applications like scanners and pattern matchers, which need a short path
   to character data for performance reasons.
   @end itemize  *)
  
TYPE
  Char* = LONGINT;
  (**Type of a single character within a string.  A value of this type holds a
     Unicode code point in the range @samp{[U+0000, U+10FFFF}.  Values from
     the surrogate code ranges @samp{[U+DC00, U+DFFF} are not allowed.
     
     [Note: If we introduce a 32-bit character type, then it may make sense to
     change the base type.]  *)
  String* = POINTER TO StringDesc;
  StringDesc = RECORD [ABSTRACT]
  (**A string holds a sequence of @otype{Char}.  A @otype{String} can hold any
     Oberon-2 string, but the reverse is not true, even if the character range
     is restricted: @samp{U+0000} can appear in a @otype{String}, but not in an
     Oberon-2 string.

     Strings are immutable.  That is, over the whole lifetime of a string, its
     address, type, length, and content stays the same.  *)
    length-: LONGINT;
    (**Number of code points in the sequence.  Because surrogate pairs
       are not allowed, this equals the number of characters.  *)
  END;

TYPE
  Buffer* = POINTER TO BufferDesc;
  CharsLatin1* = POINTER TO ARRAY OF CHAR;
  CharsUTF32* = POINTER TO ARRAY OF Char;
  BufferDesc = RECORD
  (**A buffer is the preferred way to assemble several strings into one
     large string value.  *)
    capacity: LONGINT;
    length-: LONGINT;
    data8: CharsLatin1;
    (* As long as 8-bit characters are added to a buffer, its internal storage
       is based on CHAR.  The first @otype{Char} value switches it to 32-bit
       storage.  *)
    data32: CharsUTF32;
  END;
  
TYPE
  CodecClass* = SHORTINT;
  
CONST
  codecUnicode* = 0;
  (**See @oconst{*Codec.unicode}.  *)
  codecTransport* = 1;
  (**See @oconst{*Codec.transport}.  *)
  codecEncryption* = 2;
  (**See @oconst{*Codec.encryption}.  *)
  codecCompression* = 3;
  (**See @oconst{*Codec.compression}.  *)
  
TYPE
  Codec* = POINTER TO CodecDesc;
  CodecDesc* = RECORD [ABSTRACT]
    (**A codec provides functions to convert a sequence of 8-bit characters
       into the Unicode representation used by the @otype{String} class, and
       vice versa.  There are two kinds of functions, for convient translation
       of self contained entities, and for streaming encoding or decoding of
       chunked data.

       For the convenience functions, decoding and encoding starts at the
       beginning of the passed entity in the default state, and it is an error
       if codec does not reach a ``clean'' state at the end of the entity.
       Errors should be signaled by something like an exception.  Right now,
       this is approximated (badly) by a failed @code{ASSERT}.

       For chunked encoding or decoding, separate functions are provided that
       take a state ``token'', and update it as part of their work.  The token
       typically

       @itemize @bullet
       @item
       contains information on some internal state (for example, holding the
       mode of operation if the encoding employs switches),

       @item
       holds partially decoded data (for example, if the previously decoded
       chunk ended in an incomplete byte sequence),

       @item
       specifies how to react to error conditions (like replace, discard, or
       abort),

       @item
       keeps track of any errors (for example, by counting the number of
       discarded characters).
       @end itemize  *)
    class-: CodecClass;
    (**The type of the code.  One of @oconst{*Codec.unicode},
       @oconst{*Codec.transport}, @oconst{*Codec.encryption}, or
       @oconst{*Codec.compression}.  *)
    
    preferredName-: String;
    (**The preferred name for this codec.  This is an ASCII string.  A codec
       may be known under any number of names.  If the codec has a preferred
       MIME name, then this value should be used here.  *)
  END;
  Decoder* = POINTER TO DecoderDesc;
  DecoderDesc* = RECORD [ABSTRACT]
  END;
  Encoder* = POINTER TO EncoderDesc;
  EncoderDesc* = RECORD [ABSTRACT]
  END;
  
TYPE
  String8* = POINTER TO String8Desc;
  BufferLatin1 = ARRAY 8*1024 OF CHAR;
  String8Desc = RECORD
    (StringDesc)
    data: CharsLatin1;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+00FF}.  The array is of length @ofield{length+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;
  
TYPE
  String32 = POINTER TO String32Desc;
  BufferUTF32 = ARRAY SIZE(BufferLatin1) DIV SIZE(Char) OF Char;
  String32Desc = RECORD
    (StringDesc) 
    data: CharsUTF32;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+10FFFF}, excluding the surrogate area @samp{[U+DC00, U+DFFFF]}.
       The array is of length @ofield{length+1}, with @samp{data[length]}
       having the value @samp{0X}.  *)
  END;

TYPE
  Latin1 = POINTER TO Latin1Desc;
  Latin1Desc = RECORD
    (CodecDesc) 
  END;
  DecoderLatin1 = POINTER TO DecoderLatin1Desc;
  DecoderLatin1Desc = RECORD
    (DecoderDesc)
  END;
  EncoderLatin1 = POINTER TO EncoderLatin1Desc;
  EncoderLatin1Desc = RECORD
    (EncoderDesc)
  END;

TYPE
  UTF32 = POINTER TO UTF32Desc;
  UTF32Desc = RECORD
    (CodecDesc) 
  END;
  DecoderUTF32 = POINTER TO DecoderUTF32Desc;
  DecoderUTF32Desc = RECORD
    (DecoderDesc)
    incomplete: ARRAY 4 OF CHAR;
    incompleteSize: LONGINT;
  END;
  EncoderUTF32 = POINTER TO EncoderUTF32Desc;
  EncoderUTF32Desc = RECORD
    (EncoderDesc)
  END;
  
CONST
  invalidChar* = 100;
  (**The character cannot be mapped into the character range of the target
     encoding.  *)
  invalidData* = 101;
  (**The input data of an operation is malformed.  For example, a decode
     instruction operating on 32-bit values is called with a number of bytes
     that is not a multiple of 4.  *)

  surrogateStart = 0DC00H;
  surrogateEnd = 0E00H;
  unicodeEnd = 110000H;
  
VAR
  latin1-: Latin1;
  utf32-: UTF32;



PROCEDURE NewString8(source: SYSTEM.ADDRESS; length: LONGINT): String8;
  VAR
    s: String8;
    d: CharsLatin1;
  BEGIN
    NEW(s);
    NEW(d, length+1);
    s. length := length;
    s. data := d;
    SYSTEM.MOVE(source, SYSTEM.ADR(d^), length*SIZE(CHAR));
    d[length] := 0X;
    RETURN s;
  END NewString8;

PROCEDURE NewString32(source: SYSTEM.ADDRESS; length: LONGINT): String32;
  VAR
    s: String32;
    d: CharsUTF32;
  BEGIN
    NEW(s);
    NEW(d, length+1);
    s. length := length;
    s. data := d;
    SYSTEM.MOVE(source, SYSTEM.ADR(d^), length*SIZE(Char));
    d[length] := 0;
    RETURN s;
  END NewString32;


PROCEDURE InitBuffer (b: Buffer; initialCapacity: LONGINT);
  BEGIN
    b. capacity := initialCapacity;
    b. length := 0;
    NEW(b. data8, initialCapacity);
    b. data32 := NIL;
  END InitBuffer;

PROCEDURE NewBuffer* (initialCapacity: LONGINT): Buffer;
  VAR
    b: Buffer;
  BEGIN
    NEW (b);
    InitBuffer (b, initialCapacity);
    RETURN b;
  END NewBuffer;

PROCEDURE (b: Buffer) ToString*(): String;
  BEGIN
    IF (b. data8 # NIL) THEN
      RETURN NewString8(SYSTEM.ADR (b. data8^), b. length);
    ELSE
      RETURN NewString32(SYSTEM.ADR (b. data32^), b. length);
    END;
  END ToString;

PROCEDURE (b: Buffer) Clear*;
  BEGIN
    b. length := 0;
  END Clear;

PROCEDURE (b: Buffer) CharsLatin1*(): CharsLatin1;
  BEGIN
    ASSERT (b. data8 # NIL);
    RETURN b. data8;
  END CharsLatin1;

PROCEDURE (b: Buffer) EnsureCapacity (cap: LONGINT);
  VAR
    newCap: LONGINT;
    new8: CharsLatin1;
    new32: CharsUTF32;
  BEGIN
    IF (b. capacity < cap) THEN
      newCap := b. capacity;
      WHILE (newCap < cap) DO
        newCap := newCap*2;
      END;
      b. capacity := newCap;
      
      IF (b. data8 # NIL) THEN
        NEW(new8, newCap);
        SYSTEM.MOVE(SYSTEM.ADR(b. data8^), SYSTEM.ADR (new8^), b. length*SIZE(CHAR));
        b. data8 := new8;
      ELSE
        NEW(new32, newCap);
        SYSTEM.MOVE(SYSTEM.ADR(b. data32^), SYSTEM.ADR (new32^), b. length*SIZE(Char));
        b. data32 := new32;
      END;
    END;
  END EnsureCapacity;

PROCEDURE (b: Buffer) ConvertTo32;
  VAR
    i: LONGINT;
  BEGIN
    NEW(b. data32, LEN(b. data8^));
    FOR i := 0 TO b. length-1 DO;
      b. data32[i] := ORD(b. data8[i]);
    END;
    b. data8 := NIL;
  END ConvertTo32;

PROCEDURE (b: Buffer) AppendLatin1Region* (data[NO_COPY]: ARRAY OF CHAR;
                                           start, end: LONGINT);
  VAR
    len, i: LONGINT;
  BEGIN
    len := end-start;
    b. EnsureCapacity(b. length+len);
    IF (b. data8 # NIL) THEN
      SYSTEM.MOVE(SYSTEM.ADR(data[start]),
                  SYSTEM.ADR(b. data8[b. length]),
                  len*SIZE(CHAR));
    ELSE
      i := b. length;
      WHILE (start # end) DO
        b. data32[i] := ORD(data[start]);
        INC (start); INC (i);
      END;
    END;
    INC (b. length, len);
  END AppendLatin1Region;

PROCEDURE (b: Buffer) AppendUTF32Region* (data[NO_COPY]: ARRAY OF Char;
                                          start, end: LONGINT);
  VAR
    len: LONGINT;
  BEGIN
    len := end-start;
    b. EnsureCapacity(b. length+len);
    IF (b. data32 = NIL) THEN
      b. ConvertTo32;
    END;
    SYSTEM.MOVE(SYSTEM.ADR(data[start]),
                SYSTEM.ADR(b. data32[b. length]),
                len*SIZE(Char));
    INC (b. length, len);
  END AppendUTF32Region;

PROCEDURE (b: Buffer) AppendString* (s: String);
  BEGIN
    WITH s: String8 DO
      b. AppendLatin1Region (s. data^, 0, s. length);
      
    | s: String32 DO
      b. EnsureCapacity (b. length+s. length);
      IF (b. data32 = NIL) THEN
        b. ConvertTo32;
      END;
      SYSTEM.MOVE(SYSTEM.ADR(s. data^),
                  SYSTEM.ADR(b. data32[b. length]),
                  s. length*SIZE(Char));
    END;
  END AppendString;



PROCEDURE NewLatin1*(str[NO_COPY]: ARRAY OF CHAR): String;
(**Create a string value from @oparam{str} without any translation.

   @precond
   The characters in @oparam{str} are Latin-1 code points.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE(str[i] # 0X) DO
      INC(i);
    END;
    RETURN NewString8(SYSTEM.ADR(str), i);
  END NewLatin1;

PROCEDURE NewLatin1Region*(str[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end-1]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{data})}.
   The characters in @oparam{str} are Latin-1 code points.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    RETURN NewString8(SYSTEM.ADR(str[start]), end-start);
  END NewLatin1Region;

PROCEDURE NewUCS2*(str[NO_COPY]: ARRAY OF LONGCHAR): String;
(**Create a string value from @oparam{str} without any translation.

   @precond
   The characters in @oparam{str} are Unicode 3.1 code points outside the
   surrogate areas.
   @end precond  *)
  VAR
    i, j: LONGINT;
    s: String32;
    d: CharsUTF32;
  BEGIN
    i := 0;
    WHILE(str[i] # 0X) DO
      INC(i);
    END;
    
    NEW(s);
    NEW(d, i+1);
    s. length := i;
    s. data := d;
    FOR j := 0 TO i DO
      d[j] := ORD(str[j]);
    END;
    RETURN s;
  END NewUCS2;

PROCEDURE NewUTF32Region*(str[NO_COPY]: ARRAY OF Char;
                         start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{data})}.
   All characters are Unicode 3.1 code points outside the surrogate areas.
   @end precond  *)
  BEGIN
    RETURN NewString32 (SYSTEM.ADR(str[start]), end-start);
  END NewUTF32Region;

PROCEDURE NewUTF32*(str[NO_COPY]: ARRAY OF Char): String;
(**Create a string value from @oparam{str} without any translation.

   @precond
   The characters in @oparam{str} are Unicode 3.1 code points outside the
   surrogate areas.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE(str[i] # 0) DO
      INC(i);
    END;
    RETURN NewString32 (SYSTEM.ADR(str), i);
  END NewUTF32;

PROCEDURE (s: String8) CharsLatin1*(): CharsLatin1;
  BEGIN
    RETURN s. data;
  END CharsLatin1;

PROCEDURE (s: String) [ABSTRACT] CharAt* (index: LONGINT): Char;
  END CharAt;

PROCEDURE (s: String8) CharAt* (index: LONGINT): Char;
  BEGIN
    RETURN ORD(s. data[index]);
  END CharAt;

PROCEDURE (s: String32) CharAt* (index: LONGINT): Char;
  BEGIN
    RETURN s. data[index];
  END CharAt;

PROCEDURE (s: String) [ABSTRACT] Substring* (start, end: LONGINT): String;
  END Substring;

PROCEDURE (s: String8) Substring* (start, end: LONGINT): String;
  BEGIN
    RETURN NewString8(SYSTEM.ADR(s. data[start]), end-start);
  END Substring;

PROCEDURE (s: String32) Substring* (start, end: LONGINT): String;
  BEGIN
    RETURN NewString32(SYSTEM.ADR(s. data[start]), end-start);
  END Substring;


PROCEDURE InitDecoder* (dec: Decoder);
  BEGIN
  END InitDecoder;

PROCEDURE InitEncoder* (enc: Encoder);
  BEGIN
  END InitEncoder;

PROCEDURE (dec: Decoder) [ABSTRACT] DecodeIncr* (data[NO_COPY]: ARRAY OF CHAR;
                                                 start, end: LONGINT;
                                                 b: Buffer);
(**Decode the 8-bit character sequence in @samp{data[start, end-1]} starting
   with the decoder state @oparam{dec}.  The result is appended to the string
   buffer @oparam{b}.  On completion, @oparam{state} is updated to reflect the
   decoder's state after the last byte of the sequence has been processed.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{data})}.
   @end precond  *)
  END DecodeIncr;

PROCEDURE (enc: Encoder) [ABSTRACT] EncodeIncr*(s: String;
                                                start, end: LONGINT;
                                                b: Buffer);
(**Encode the 8-bit character sequence in @samp{s[start, end-1]} starting with
   the encoder state @oparam{enc}.  The result is a string holding only code
   points in the range @samp{[U+0000, U+00FF]}, which is appended to the string
   buffer @oparam{b}.  On completion, @oparam{enc} is updated to reflect the
   encoder's state after the last byte of the sequence has been processed.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= @oparam{s}.length}.  All code
   points in @samp{data[start, end-1]} are valid.  That is, neither is out of
   range nor from the surrogate areas.
   @end precond  *)
  END EncodeIncr;

PROCEDURE (enc: Encoder) [ABSTRACT] Closure*(b: Buffer);
(**If the encoder still holds any partial data from previous calls to
   @oproc{enc.EncodeIncr}, then flush this data to the buffer @oparam{b}.  This
   method must be called at the end of the data stream for codecs that operate
   on blocks of data, and for which the last and possibly incomplete block must
   be handled specially.  *)
  END Closure;

PROCEDURE InitCodec* (codec: Codec; class: CodecClass;
                      preferredName: ARRAY OF CHAR);
  BEGIN
    codec. class := class;
    codec. preferredName := NewLatin1(preferredName);
  END InitCodec;

PROCEDURE (codec: Codec) [ABSTRACT] NewDecoder*(): Decoder;
(**Creates a decoder object for the codec @oparam{codec}.  Note: Some decoders,
   like those implementing an decryption algorithm, require additional settings
   before they can be used.  *)
  END NewDecoder;

PROCEDURE (codec: Codec) [ABSTRACT] NewEncoder*(): Encoder;
(**Creates an encoder object for the codec @oparam{codec}.  Note: Some
   encoders, like those implementing encryption algorithm, require additional
   settings before they can be used.  *)
  END NewEncoder;

PROCEDURE (codec: Codec) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                       start, end: LONGINT): String;
(**Decode the 8-bit character sequence in @samp{data[start, end-1]}.  For
   succesul completion, the byte sequence @samp{data[start, end-1]} must be
   well formed with respect to the decoder, and the resulting Unicode code
   points must all be valid.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{data})}.
   @end precond  *)
  VAR
    dec: Decoder;
    b: Buffer;
  BEGIN
    dec := codec. NewDecoder();
    b := NewBuffer(end-start);
    dec. DecodeIncr (data, start, end, b);
    RETURN b. ToString();
  END DecodeRegion;

PROCEDURE (codec: Codec) Decode*(data[NO_COPY]: ARRAY OF CHAR): String;
(**Equivalent to @samp{codec.Decode(data,0,String.Length(data))}.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE(data[i] # 0X) DO
      INC(i);
    END;
    RETURN codec. DecodeRegion (data, 0, i);
  END Decode;

PROCEDURE (codec: Codec) EncodeRegion*(s: String;
                                       start, end: LONGINT): String8;
(**Encode Unicode sequence in @samp{s[start, end-1]} into the 8-bit
   character sequence.  The result is stored in a string holding only code
   points in the range @samp{[U+0000, U+00FF]}.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= @oparam{s}.length}.  All code
   points in @samp{data[start, end-1]} are valid.  That is, neither is out of
   range nor from the surrogate areas.
   @end precond  *)
  VAR
    enc: Encoder;
    b: Buffer;
    s8: String;
  BEGIN
    enc := codec. NewEncoder();
    b := NewBuffer (end-start);
    enc. EncodeIncr (s, start, end, b);
    s8 := b. ToString();
    RETURN s8(String8);
  END EncodeRegion;

PROCEDURE (codec: Codec) Encode*(s: String): String8;
(**Equivalent to @samp{codec.Encode(s,0,s.length)}.  *)
  BEGIN
    RETURN codec.EncodeRegion(s, 0, s.length);
  END Encode;




(* Codec: Latin1
   ------------------------------------------------------------------------ *)

PROCEDURE InitLatin1 (c: Latin1; preferredName: ARRAY OF CHAR);
  BEGIN
    InitCodec (c, codecUnicode, preferredName);
  END InitLatin1;

PROCEDURE (c: Latin1) NewDecoder*(): DecoderLatin1;
  VAR
    dec: DecoderLatin1;
  BEGIN
    NEW (dec);
    InitDecoder (dec);
    RETURN dec;
  END NewDecoder;

PROCEDURE (c: Latin1) NewEncoder*(): EncoderLatin1;
  VAR
    enc: EncoderLatin1;
  BEGIN
    NEW (enc);
    InitEncoder (enc);
    RETURN enc;
  END NewEncoder;

PROCEDURE (c: Latin1) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                    start, end: LONGINT): String;
  BEGIN
    RETURN NewString8(SYSTEM.ADR(data[start]), end-start);
  END DecodeRegion;

PROCEDURE (dec: DecoderLatin1) DecodeIncr* (data[NO_COPY]: ARRAY OF CHAR;
                                            start, end: LONGINT;
                                            b: Buffer);
  BEGIN
    b. AppendLatin1Region (data, start, end);
  END DecodeIncr;
  
PROCEDURE (c: Latin1) EncodeRegion*(s: String;
                                    start, end: LONGINT): String8;
  VAR
    i, len: LONGINT;
    out: String8;
    d: CharsLatin1;
  BEGIN
    WITH s: String8 DO
      RETURN NewString8(SYSTEM.ADR(s. data[start]), end-start);
      
    | s: String32 DO
      len := end-start;
      NEW (d, len+1);
      i := 0;
      WHILE (start # end) DO
        ASSERT (s. data[start] < 256, invalidChar);
        d[i] := CHR (s. data[start]);
        INC (start); INC (i);
      END;
      d[len] := 0X;
      
      NEW (out);
      out. length := len;
      out. data := d;
      RETURN out;
    END;
  END EncodeRegion;

PROCEDURE (enc: EncoderLatin1) EncodeIncr*(s: String;
                                           start, end: LONGINT;
                                           b: Buffer);
  VAR
    d: BufferLatin1;
    i: LONGINT;
  BEGIN
    WITH s: String8 DO
      b. AppendLatin1Region (s. data^, 0, s. length);
      
    | s: String32 DO
      i := 0;
      WHILE (start # end) DO
        ASSERT (s. data[start] < 256, invalidChar);
        d[i] := CHR (s. data[start]);
        INC (start); INC (i);

        IF (i = LEN (d)) THEN
          b. AppendLatin1Region (d, 0, i);
          i := 0;
        END;
      END;
      b. AppendLatin1Region (d, 0, i);
    END;
  END EncodeIncr;

PROCEDURE (enc: EncoderLatin1) Closure*(b: Buffer);
  END Closure;

(* Codec: UTF-32 (undefined byte order)
   ------------------------------------------------------------------------ *)

PROCEDURE InitUTF32 (c: UTF32; preferredName: ARRAY OF CHAR);
  BEGIN
    InitCodec (c, codecUnicode, preferredName);
  END InitUTF32;

PROCEDURE (c: UTF32) NewDecoder*(): DecoderUTF32;
  VAR
    dec: DecoderUTF32;
  BEGIN
    NEW (dec);
    InitDecoder (dec);
    dec. incompleteSize := 0;
    RETURN dec;
  END NewDecoder;

PROCEDURE (c: UTF32) NewEncoder*(): EncoderUTF32;
  VAR
    enc: EncoderUTF32;
  BEGIN
    NEW (enc);
    InitEncoder (enc);
    RETURN enc;
  END NewEncoder;

PROCEDURE (c: UTF32) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                   start, end: LONGINT): String;
  VAR
    s: String32;
    i: LONGINT;
  BEGIN
    ASSERT ((end-start) MOD SIZE(Char) = 0, invalidData);
    s := NewString32(SYSTEM.ADR(data[start]), (end-start) DIV 4);
    FOR i := 0 TO s. length-1 DO
      ASSERT ((s. data[i] < unicodeEnd) &
              ((s. data[i] < surrogateStart) OR (s. data[i] >= surrogateEnd)),
              invalidChar);
    END;
    RETURN s;
  END DecodeRegion;

PROCEDURE (dec: DecoderUTF32) DecodeIncr* (data[NO_COPY]: ARRAY OF CHAR;
                                           start, end: LONGINT;
                                           b: Buffer);
  VAR
    d: BufferUTF32;
    offset, len, dend, chars, i: LONGINT;
  BEGIN
    offset := dec. incompleteSize;
    IF (end-start+offset >= SIZE(Char)) THEN
      SYSTEM.MOVE(SYSTEM.ADR(dec. incomplete), SYSTEM.ADR(d), offset);

      REPEAT
        len := (end-start-offset);
        SYSTEM.MOVE(SYSTEM.ADR(data[start]), SYSTEM.ADR(d[offset]), len);
        dend := len+offset;
        chars := dend DIV SIZE(Char);
        FOR i := 0 TO chars-1 DO
          ASSERT ((d[i] < unicodeEnd) &
                  ((d[i] < surrogateStart) OR (d[i] >= surrogateEnd)),
                  invalidChar);
        END;
        b. AppendUTF32Region (d, 0, chars);
        
        INC (start, len);
        offset := 0;
      UNTIL (end-start < SIZE(Char));
                                       
      dec. incompleteSize := dend MOD SIZE(Char);
      IF (dec. incompleteSize # 0) THEN  (* avoid index at end of array d *)
        SYSTEM.MOVE(SYSTEM.ADR(d[dend DIV SIZE(Char)]),
                    SYSTEM.ADR(dec.incomplete), dec. incompleteSize);
      END;
    END;
  END DecodeIncr;
  
PROCEDURE (c: UTF32) EncodeRegion*(s: String;
                                   start, end: LONGINT): String8;
  VAR
    i, len: LONGINT;
    d: CharsUTF32;
  BEGIN
    WITH s: String32 DO
      RETURN NewString8(SYSTEM.ADR(s. data[start]), (end-start)*SIZE(Char));
      
    | s: String8 DO
      len := end-start;
      NEW (d, len);
      i := 0;
      WHILE (start # end) DO
        d[i] := ORD (s. data[start]);
        INC (start); INC (i);
      END;
      RETURN NewString8(SYSTEM.ADR(d^), len*SIZE(Char));
    END;
  END EncodeRegion;

PROCEDURE (enc: EncoderUTF32) EncodeIncr*(s: String;
                                          start, end: LONGINT;
                                          b: Buffer);
  VAR
    d8: BufferLatin1;
    d32: BufferUTF32;
    len, i: LONGINT;
  BEGIN
    WITH s: String8 DO
      WHILE (start # end) DO
        len := LEN(d32);
        IF (len > end-start) THEN len := end-start; END;
        FOR i := 0 TO len-1 DO
          d32[i] := ORD (s. data[start+i]);
        END;
        SYSTEM.MOVE(SYSTEM.ADR(d32), SYSTEM.ADR(d8), len*SIZE(Char));
        b. AppendLatin1Region (d8, 0, len*SIZE(Char));
        INC (start, len);
      END;
      
    | s: String32 DO
      WHILE (start # end) DO
        len := SIZE(BufferLatin1) DIV SIZE(Char);
        IF (len > end-start) THEN len := end-start; END;
        SYSTEM.MOVE(SYSTEM.ADR(s. data[start]), SYSTEM.ADR(d8), len*SIZE(Char));
        b. AppendLatin1Region (d8, 0, len*SIZE(Char));
        INC (start, len);
      END;
    END;
  END EncodeIncr;

PROCEDURE (enc: EncoderUTF32) Closure*(b: Buffer);
  END Closure;

BEGIN
  NEW (latin1);
  InitLatin1 (latin1, "ISO-8859-1");
  NEW (utf32);
  InitUTF32 (utf32, "UTF-32");
END Language:String0.
