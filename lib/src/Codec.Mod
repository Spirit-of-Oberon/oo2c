(* 	$Id: Codec.Mod,v 1.1 2003/09/22 19:32:17 mva Exp $	 *)
MODULE Codec [OOC_EXTENSIONS];
(*  Registry for encoders/decoders of binary and character data.
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
  Strings, Object, ADT:Dictionary, ADT:StringBuffer, IO;

(**This module provides a registry for Unicode, transport, and encryption
   codecs.  A codec can be registered under several names.  Case is ignored
   when looking up a codec by its name.  *)

TYPE
  CodecClass* = SHORTINT;
  
TYPE
  Codec* = POINTER TO CodecDesc;
  CodecDesc* = RECORD [ABSTRACT]
    (**A codec provides functions to convert a sequence of 8-bit characters
       into the Unicode representation used by the @otype{Object.String} class,
       and vice versa.  There are two kinds of functions, for convient
       translation of self contained entities, and for streaming encoding or
       decoding of chunked data.

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
    (Object.ObjectDesc)
    
    class-: CodecClass;
    (**The type of the code.  One of @oconst{*Codec.unicode},
       @oconst{*Codec.transport}, @oconst{*Codec.encryption}, or
       @oconst{*Codec.compression}.  *)
    
    preferredName-: STRING;
    (**The preferred name for this codec.  This is an ASCII string.  A codec
       may be known under any number of names.  If the codec has a preferred
       MIME name, then this value should be used here.  *)
  END;
  Decoder* = POINTER TO DecoderDesc;
  DecoderDesc* = RECORD [ABSTRACT]
  END;
  Encoder* = POINTER TO EncoderDesc;
  EncoderDesc* = RECORD [ABSTRACT]
    escape: Encoder;
  END;

CONST
  unicode* = 0;
  (**A Unicode codec translates a sequence of 32-bit Unicode code points into
     an 8-bit character sequence, and vice versa.  *)
  transport* = 1;
  (**A transport codec transforms an 8-bit character string into another 8-bit
     representation, typically escaping some character codes on the way.  *)
  encryption* = 2;
  (**Encrypts an 8-bit character string into another 8-bit string.  Because
     encryption needs parameters like the encryption key and an initialization
     vector as input, the shorthand notations like
     @oproc{Codec.DecodeRegion} and @oproc{Codec.EncodeRegion}
     do not work.  *)
  compression* = 3;
  (**A compression codec tries to translate an 8-bit character sequence into
     a short 8-bit representation.  *)
  
TYPE
  CryptoDecoder* = POINTER TO CryptoDecoderDesc;
  CryptoDecoderDesc* = RECORD [ABSTRACT]
    (DecoderDesc)
  END;

TYPE
  CryptoEncoder* = POINTER TO CryptoEncoderDesc;
  CryptoEncoderDesc* = RECORD [ABSTRACT]
    (EncoderDesc)
  END;

TYPE
  BufferLatin1* = ARRAY 4096 OF CHAR;
  BufferUCS4* = ARRAY 1024 OF UCS4CHAR;

TYPE
  EncodingError* = POINTER TO EncodingErrorDesc;
  EncodingErrorDesc = RECORD
    (IO.ErrorDesc)
    start, end: LONGINT;
  END;

TYPE
  ExceptionEncoder = POINTER TO ExceptionEncoderDesc;
  ExceptionEncoderDesc = RECORD
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

VAR
  reg: Dictionary.Dictionary;
  exceptionEncoder-: ExceptionEncoder;


PROCEDURE (e: EncodingError) INIT*(start, end: LONGINT);
  BEGIN
    e.INIT^("Cannot convert text to target encoding");
    e.start := start;
    e.end := end;
  END INIT;


PROCEDURE (dec: Decoder) INIT*();
  BEGIN
  END INIT;

PROCEDURE (dec: Decoder) Start*;
(**Allocates and initializes all resources required for the decoder instance.
   This method must be called once before @oproc{dec.Decode}.  The default
   implementation is a no-op.

   The amount of memory allocated in this step differs significantly across the
   different kinds of decoders.  For example, the space requirements of a
   Unicode codec are virtually none, while a compression decoder may require
   several hundreds of KBytes.  *)
  END Start;

PROCEDURE (dec: Decoder) [ABSTRACT] Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                             start, end: LONGINT;
                                             b: StringBuffer.StringBuffer);
(**Decode the 8-bit character sequence in @samp{data[start, end-1]} starting
   with the decoder state @oparam{dec}.  The result is appended to the string
   buffer @oparam{b}.  On completion, @oparam{dec} is updated to reflect the
   decoder's state after the last byte of the sequence has been processed.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{data})}.
   @oproc{dec.Start} has been called.
   @end precond  *)
  END Decode;

PROCEDURE (dec: Decoder) Reset*;
(**Resets the decoder's state to that created by the initial @oproc{dec.Start}.
   All allocated resources are kept.  Using this method, it is possible to
   use one and the same decoder for several different data streams.  *)
  END Reset;

PROCEDURE (dec: Decoder) End*;
(**The complement operation to @oproc{dec.Start}, freeing all resources
   allocated earlier.  After this method has been called, no other methods of
   this decoder must be called, except for @oproc{dec.Start}.  The default
   implementation is a no-op.  *)
  END End;


PROCEDURE (enc: Encoder) INIT*(escape: Encoder);
  BEGIN
    enc.escape := escape;
  END INIT;

PROCEDURE (enc: Encoder) SetEscapeEncoder*(escape: Encoder);
(**For character sequences that cannot be handled by this encoder, the encoder
   @oparam{escape} is called.  It either raises an @otype{EncodingError}
   exception, or translates the characters into a format that can be handled by
   @oparam{enc}.  An example for this is an encoder that creates XML character
   references from code points that cannot be mapped by @oparam{enc}.  *)
  BEGIN
    enc.escape := escape;
  END SetEscapeEncoder;

PROCEDURE (enc: Encoder) Start*;
(**Allocates and initializes all resources required for the encoder instance.
   This method must be called once before @oproc{enc.Encode}.  The default
   implementation is a no-op.

   The amount of memory allocated in this step differs significantly across the
   different kinds of decoders.  For example, the space requirements of a
   Unicode codec are virtually none, while a compression decoder may require
   several MBytes of memory.  *)
  END Start;

PROCEDURE (enc: Encoder) [ABSTRACT] EncodeLatin1*(s[NO_COPY]: ARRAY OF CHAR;
                                                  start, end: LONGINT;
                                                  b: StringBuffer.StringBuffer)
RAISES EncodingError;
(**Encode the Latin1 character sequence in @samp{s[start, end-1]} starting with
   the encoder state @oparam{enc}.  The result is a string holding only code
   points in the range @samp{[U+0000, U+00FF]}, which is appended to the string
   buffer @oparam{b}.  On completion, @oparam{enc} is updated to reflect the
   encoder's state after the last byte of the sequence has been processed.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= @oparam{s}.length}.
   @oproc{enc.Start} has been called.  All code points in @samp{data[start,
   end-1]} are valid.  That is, neither is out of range nor from the surrogate
   areas.
   @end precond  *)
  END EncodeLatin1;

PROCEDURE (enc: Encoder) [ABSTRACT] EncodeUTF16*(s[NO_COPY]: ARRAY OF LONGCHAR;
                                                 start, end: LONGINT;
                                                 b: StringBuffer.StringBuffer)
RAISES EncodingError;
(**Encode the UTF-16 character sequence in @samp{s[start, end-1]} starting with
   the encoder state @oparam{enc}.  The result is a string holding only code
   points in the range @samp{[U+0000, U+00FF]}, which is appended to the string
   buffer @oparam{b}.  On completion, @oparam{enc} is updated to reflect the
   encoder's state after the last byte of the sequence has been processed.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= @oparam{s}.length}.
   @oproc{enc.Start} has been called.  All code points in @samp{data[start,
   end-1]} are valid.  That is, neither is out of range nor from the surrogate
   areas.
   @end precond  *)
  END EncodeUTF16;

PROCEDURE (enc: Encoder) Encode*(s: STRING;
                                 start, end: LONGINT;
                                 b: StringBuffer.StringBuffer)
RAISES EncodingError;
(**Encode the UTF-16 character sequence in @samp{s[start, end-1]} starting with
   the encoder state @oparam{enc}.  The result is a string holding only code
   points in the range @samp{[U+0000, U+00FF]}, which is appended to the string
   buffer @oparam{b}.  On completion, @oparam{enc} is updated to reflect the
   encoder's state after the last byte of the sequence has been processed.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= @oparam{s}.length}.
   @oproc{enc.Start} has been called.  All code points in @samp{data[start,
   end-1]} are valid.  That is, neither is out of range nor from the surrogate
   areas.
   @end precond  *)
  VAR
    chars8: Object.CharsLatin1;
    chars16: Object.CharsUTF16;
  BEGIN
    WITH s: Object.String8 DO
      chars8 := s.CharsLatin1();
      enc.EncodeLatin1(chars8^, start, end, b);
    | s: Object.String16 DO
      chars16 := s.CharsUTF16();
      enc.EncodeUTF16(chars16^, start, end, b);
    END;
  END Encode;

PROCEDURE EscapeLatin1*(enc: Encoder; s[NO_COPY]: ARRAY OF CHAR;
                        start, end: LONGINT;
                        b: StringBuffer.StringBuffer)
RAISES EncodingError;
  VAR
    esc: StringBuffer.StringBuffer;
    chars8: StringBuffer.CharsLatin1;
    chars16: StringBuffer.CharsUTF16;
  BEGIN
    esc := NEW(StringBuffer.StringBuffer, end-start);
    enc.escape.EncodeLatin1(s, start, end, esc);
    
    chars8 := esc.CharsLatin1();
    IF (chars8 # NIL) THEN
      enc.EncodeLatin1(chars8^, 0, esc.length, b);
    ELSE
      chars16 := esc.CharsUTF16();
      enc.EncodeUTF16(chars16^, 0, esc.length, b);
    END;
  END EscapeLatin1;

PROCEDURE EscapeUTF16*(enc: Encoder; s[NO_COPY]: ARRAY OF LONGCHAR;
                       start, end: LONGINT;
                       b: StringBuffer.StringBuffer)
RAISES EncodingError;
  VAR
    esc: StringBuffer.StringBuffer;
    chars8: StringBuffer.CharsLatin1;
    chars16: StringBuffer.CharsUTF16;
  BEGIN
    esc := NEW(StringBuffer.StringBuffer, end-start);
    enc.escape.EncodeUTF16(s, start, end, esc);
    
    chars8 := esc.CharsLatin1();
    IF (chars8 # NIL) THEN
      enc.EncodeLatin1(chars8^, 0, esc.length, b);
    ELSE
      chars16 := esc.CharsUTF16();
      enc.EncodeUTF16(chars16^, 0, esc.length, b);
    END;
  END EscapeUTF16;

PROCEDURE (enc: Encoder) Closure*(b: StringBuffer.StringBuffer);
(**If the encoder still holds any partial data from previous calls to
   @oproc{enc.Encode}, then flush this data to the buffer @oparam{b}.  This
   method must be called at the end of the data stream for codecs that operate
   on blocks of data, and for which the last and possibly incomplete block must
   be handled specially.  *)
  END Closure;

PROCEDURE (enc: Encoder) Reset*;
(**Resets the encoder's state to that created by the initial @oproc{enc.Start}.
   All allocated resources are kept.  Using this method, it is possible to use
   one and the same encoder for several different data streams.  *)
  END Reset;

PROCEDURE (enc: Encoder) End*;
(**The complement operation to @oproc{enc.Start}, freeing all resources
   allocated earlier.  After this method has been called, no other methods of
   this encoder must be called, except for @oproc{enc.Start}.  The default
   implementation is a no-op.  *)
  END End;


PROCEDURE (codec: Codec) INIT*(class: CodecClass;
                               preferredName: ARRAY OF CHAR);
  BEGIN
    codec. class := class;
    codec. preferredName := Object.NewLatin1(preferredName);
  END INIT;

PROCEDURE (codec: Codec) [ABSTRACT] NewDecoder*(): Decoder;
(**Creates a decoder object for the codec @oparam{codec}.  Note: Some decoders,
   like those implementing an decryption algorithm, require additional settings
   before they can be used.  *)
  END NewDecoder;

PROCEDURE (codec: Codec) [ABSTRACT] NewEncoder*(): Encoder;
(**Creates an encoder object for the codec @oparam{codec}.  By default, any
   character sequences the encoder cannot handle cause it to raise an exception
   @otype{EncodingError}.

   Note: Some encoders, like those implementing encryption algorithm, require
   additional settings before they can be used.  *)
  END NewEncoder;

PROCEDURE (codec: Codec) DecodeRegion*(data[NO_COPY]: ARRAY OF CHAR;
                                       start, end: LONGINT): STRING;
(**Decode the 8-bit character sequence in @samp{data[start, end-1]}.  For
   succesful completion, the byte sequence @samp{data[start, end-1]} must be
   well formed with respect to the decoder, and the resulting Unicode code
   points must all be valid.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{data})}.
   @end precond  *)
  VAR
    dec: Decoder;
    b: StringBuffer.StringBuffer;
  BEGIN
    dec := codec. NewDecoder();
    b := NEW(StringBuffer.StringBuffer, end-start+1);
    dec. Start;
    dec. Decode (data, start, end, b);
    dec. End;
    RETURN b. ToString();
  END DecodeRegion;

PROCEDURE (codec: Codec) Decode*(data[NO_COPY]: ARRAY OF CHAR): STRING;
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

PROCEDURE (codec: Codec) EncodeRegion*(s: STRING;
                                       start, end: LONGINT): Object.String8
RAISES EncodingError;
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
    b: StringBuffer.StringBuffer;
    s8: STRING;
  BEGIN
    enc := codec. NewEncoder();
    b := NEW(StringBuffer.StringBuffer, end-start+1);
    enc. Start;
    enc. Encode (s, start, end, b);
    enc. End;
    s8 := b. ToString();
    RETURN s8(Object.String8);
  END EncodeRegion;

PROCEDURE (codec: Codec) Encode*(s: STRING): Object.String8
RAISES EncodingError;
(**Equivalent to @samp{codec.Encode(s,0,s.length)}.  *)
  BEGIN
    RETURN codec.EncodeRegion(s, 0, s.length);
  END Encode;

(* ------------------------------------------------------------------------ *)

PROCEDURE (enc: ExceptionEncoder) EncodeLatin1*(s[NO_COPY]: ARRAY OF CHAR;
                                                start, end: LONGINT;
                                                b: StringBuffer.StringBuffer)
RAISES EncodingError;
  BEGIN
    RAISE(NEW(EncodingError, start, end));
  END EncodeLatin1;

PROCEDURE (enc: ExceptionEncoder) EncodeUTF16*(s[NO_COPY]: ARRAY OF LONGCHAR;
                                               start, end: LONGINT;
                                               b: StringBuffer.StringBuffer)
RAISES EncodingError;
  BEGIN
    RAISE(NEW(EncodingError, start, end));
  END EncodeUTF16;


(* ------------------------------------------------------------------------ *)

PROCEDURE (dec: CryptoDecoder) INIT*();
  BEGIN
    dec.INIT^();
  END INIT;

PROCEDURE (enc: CryptoEncoder) INIT*(codec: Codec);
  BEGIN
    enc.INIT^(exceptionEncoder);
  END INIT;

PROCEDURE (dec: CryptoDecoder) [ABSTRACT] SetKey* (key: Object.String8);
  END SetKey;

PROCEDURE (enc: CryptoEncoder) [ABSTRACT] SetKey* (key: Object.String8);
  END SetKey;


PROCEDURE Cap(str: STRING): STRING;
  VAR
    chars: Object.CharsLatin1;
    s: ARRAY 128 OF CHAR;
  BEGIN
    chars := str(Object.String8).CharsLatin1();
    COPY(chars^, s);
    Strings.Capitalize(s);
    RETURN Object.NewLatin1(s);
  END Cap;

PROCEDURE Get* (name: STRING): Codec;
  VAR
    obj: Object.Object;
    norm: STRING;
  BEGIN
    norm := Cap(name);
    IF reg.HasKey(norm) THEN
      obj := reg. Get (norm);
      RETURN obj(Codec);
    ELSE
      RETURN NIL;
    END;
  END Get;

PROCEDURE Register* (codec: Codec; name: STRING);
(**@precond
   @oparam{name} is an ASCII string.
   @end precond  *)
  BEGIN
    reg.Set(Cap(name), codec);
  END Register;

BEGIN
  reg := Dictionary.New();
END Codec.
