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
  Strings, ADT:Object, ADT:String, ADT:Dictionary, Language:String0;

(**This module provides a registry for Unicode, transport, and encryption
   codecs.  A codec can be registered under several names.  Case is ignored
   when looking up a codec by its name.  *)

TYPE
  Codec* = String0.Codec;
  CodecDesc* = String0.CodecDesc;
  Class* = String0.CodecClass;
  Encoder* = String0.Encoder;
  EncoderDesc* = String0.EncoderDesc;
  Decoder* = String0.Decoder;
  DecoderDesc* = String0.DecoderDesc;
  
CONST
  unicode* = String0.codecUnicode;
  (**A Unicode codec translates a sequence of 32-bit Unicode code points into
     an 8-bit character sequence, and vice versa.  *)
  transport* = String0.codecTransport;
  (**A transport codec transforms an 8-bit character string into another 8-bit
     representation, typically escaping some character codes on the way.  *)
  encryption* = String0.codecEncryption;
  (**Encrypts an 8-bit character string into another 8-bit string.  Because
     encryption needs parameters like the encryption key and an initialization
     vector as input, the shorthand notations like
     @oproc{String0.Codec.DecodeRegion} and @oproc{String0.Codec.EncodeRegion}
     do not work.  *)
  compression* = String0.codecCompression;
  (**A compression codec tries to translate an 8-bit character sequence into
     a short 8-bit representation.  *)
  
TYPE
  Wrapper = POINTER TO WrapperDesc;
  WrapperDesc = RECORD
    (Object.ObjectDesc)
    codec: String0.Codec;
  END;

TYPE
  CryptoDecoder* = POINTER TO CryptoDecoderDesc;
  CryptoDecoderDesc* = RECORD [ABSTRACT]
    (String0.DecoderDesc)
  END;

TYPE
  CryptoEncoder* = POINTER TO CryptoEncoderDesc;
  CryptoEncoderDesc* = RECORD [ABSTRACT]
    (String0.EncoderDesc)
  END;

VAR
  reg: Dictionary.Dictionary;

PROCEDURE InitCryptoDecoder* (dec: CryptoDecoder);
  BEGIN
    String0.InitDecoder (dec);
  END InitCryptoDecoder;

PROCEDURE InitCryptoEncoder* (enc: CryptoEncoder);
  BEGIN
    String0.InitEncoder (enc);
  END InitCryptoEncoder;

PROCEDURE (dec: CryptoDecoder) [ABSTRACT] SetKey* (key: String0.String8);
  END SetKey;

PROCEDURE (enc: CryptoEncoder) [ABSTRACT] SetKey* (key: String0.String8);
  END SetKey;


PROCEDURE NewWrapper (codec: String0.Codec): Wrapper;
  VAR
    w: Wrapper;
  BEGIN
    NEW (w);
    Object.Init (w);
    w. codec := codec;
    RETURN w;
  END NewWrapper;

PROCEDURE Get* (name: ARRAY OF CHAR): String0.Codec;
  VAR
    obj: Object.Object;
  BEGIN
    Strings.Capitalize (name);
    obj := reg. Get (String.New (name));
    IF (obj = NIL) THEN
      RETURN NIL;
    ELSE
      RETURN obj(Wrapper). codec;
    END;
  END Get;

PROCEDURE Register* (codec: String0.Codec; name: ARRAY OF CHAR);
(**@precond
   @oparam{name} is an ASCII string.
   @end precond  *)
  BEGIN
    Strings.Capitalize (name);
    reg. Set (String.New (name), NewWrapper (codec));
  END Register;

PROCEDURE Init* ();
  BEGIN
    reg := Dictionary.New();
    
    Register (String0.latin1, "ISO_8859-1:1987");
    Register (String0.latin1, "iso-ir-100");
    Register (String0.latin1, "ISO_8859-1");
    Register (String0.latin1, "ISO-8859-1");  (* preferred MIME name *)
    Register (String0.latin1, "latin1");
    Register (String0.latin1, "l1");
    Register (String0.latin1, "IBM819");
    Register (String0.latin1, "CP819");
    Register (String0.latin1, "csISOLatin1y");

    Register (String0.utf32, "UTF-32");
  END Init;

BEGIN
  Init
END Codec.
