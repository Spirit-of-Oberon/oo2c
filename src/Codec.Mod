(* 	$Id$	 *)
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
  Strings, Object, ADT:Dictionary, ADT:StringBuffer;

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



PROCEDURE InitDecoder* (dec: Decoder);
  BEGIN
  END InitDecoder;

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


PROCEDURE InitEncoder* (enc: Encoder);
  BEGIN
  END InitEncoder;

PROCEDURE (enc: Encoder) Start*;
(**Allocates and initializes all resources required for the encoder instance.
   This method must be called once before @oproc{enc.Encode}.  The default
   implementation is a no-op.

   The amount of memory allocated in this step differs significantly across the
   different kinds of decoders.  For example, the space requirements of a
   Unicode codec are virtually none, while a compression decoder may require
   several MBytes of memory.  *)
  END Start;

PROCEDURE (enc: Encoder) [ABSTRACT] Encode*(s: STRING;
                                            start, end: LONGINT;
                                            b: StringBuffer.StringBuffer);
(**Encode the 8-bit character sequence in @samp{s[start, end-1]} starting with
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
  END Encode;

PROCEDURE (enc: Encoder) [ABSTRACT] Closure*(b: StringBuffer.StringBuffer);
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


PROCEDURE InitCodec* (codec: Codec; class: CodecClass;
                      preferredName: ARRAY OF CHAR);
  BEGIN
    codec. class := class;
    codec. preferredName := Object.NewLatin1(preferredName);
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
                                       start, end: LONGINT): STRING;
(**Decode the 8-bit character sequence in @samp{data[start, end-1]}.  For
   succesul completion, the byte sequence @samp{data[start, end-1]} must be
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
    b := StringBuffer.NewCapacity(end-start);
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
                                       start, end: LONGINT): Object.String8;
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
    b := StringBuffer.NewCapacity(end-start);
    enc. Start;
    enc. Encode (s, start, end, b);
    enc. End;
    s8 := b. ToString();
    RETURN s8(Object.String8);
  END EncodeRegion;

PROCEDURE (codec: Codec) Encode*(s: STRING): Object.String8;
(**Equivalent to @samp{codec.Encode(s,0,s.length)}.  *)
  BEGIN
    RETURN codec.EncodeRegion(s, 0, s.length);
  END Encode;

PROCEDURE InitCryptoDecoder* (dec: CryptoDecoder);
  BEGIN
    InitDecoder (dec);
  END InitCryptoDecoder;

PROCEDURE InitCryptoEncoder* (enc: CryptoEncoder);
  BEGIN
    InitEncoder (enc);
  END InitCryptoEncoder;

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
