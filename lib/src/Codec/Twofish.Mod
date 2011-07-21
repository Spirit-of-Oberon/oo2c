(* 	$Id: Twofish.Mod,v 1.1 2003/09/22 19:32:17 mva Exp $	 *)
MODULE Codec:Twofish[OOC_EXTENSIONS];
(*  Codec for the Twofish encryption algorithm.
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
  SYSTEM, Codec, Object, ADT:StringBuffer, Codec:TwofishC;

(**NOTE: As it is, this module implements ECB with zero padding if the
   data length is not a multiple of 16.  ECB is very simple, and rather
   unsuited for large pieces of data.  Padding means that decrypted data
   may grow by some zero bytes.  *)
  
CONST
  maxKeySize = 32;
  blockSize = 16;
      
TYPE
  Twofish* = POINTER TO TwofishDesc;
  TwofishDesc = RECORD
    (Codec.CodecDesc)
  END;

TYPE
  Encoder* = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.CryptoEncoderDesc)
    incompleteSize: LONGINT;     (* valid characters in `incompleteData' *)
    incompleteData: ARRAY blockSize OF CHAR;
    xkey: TwofishC.Twofish_key;
  END;
     
TYPE
  Decoder* = POINTER TO DecoderDesc;
  DecoderDesc = RECORD
    (Codec.CryptoDecoderDesc)
    incompleteSize: LONGINT;     (* valid characters in `incompleteData' *)
    incompleteData: ARRAY blockSize OF CHAR;
    xkey: TwofishC.Twofish_key;
  END;

VAR
  twofish-: Twofish;

PROCEDURE (c: Twofish) NewDecoder*(): Decoder;
  VAR
    dec: Decoder;
  BEGIN
    NEW (dec);
    Codec.InitCryptoDecoder (dec);
    dec. incompleteSize := 0;
    RETURN dec;
  END NewDecoder;

PROCEDURE (c: Twofish) NewEncoder*(): Encoder;
  VAR
    enc: Encoder;
  BEGIN
    NEW (enc);
    Codec.InitCryptoEncoder (enc);
    enc. incompleteSize := 0;
    RETURN enc;
  END NewEncoder;

PROCEDURE (dec: Decoder) SetKey* (key: Object.String8);
  VAR
    len: LONGINT;
    c: Object.CharsLatin1;
  BEGIN
    len := key. length;
    IF (len > maxKeySize) THEN
      len := maxKeySize;
    END;
    c := key. CharsLatin1();
    TwofishC.Twofish_prepare_key(c^, len, dec.xkey);
  END SetKey;

PROCEDURE (enc: Encoder) SetKey* (key: Object.String8);
  VAR
    len: LONGINT;
    c: Object.CharsLatin1;
  BEGIN
    len := key. length;
    IF (len > maxKeySize) THEN
      len := maxKeySize;
    END;
    c := key. CharsLatin1();
    TwofishC.Twofish_prepare_key(c^, len, enc.xkey);
  END SetKey;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                      start, end: LONGINT;
                                      b: StringBuffer.StringBuffer);
  CONST
    sizeBuffer = 4*1024;
  VAR
    d: ARRAY sizeBuffer+blockSize OF CHAR;
    dpos, len: LONGINT;
  BEGIN
    dpos := 0;
    IF (dec.incompleteSize # 0) THEN    (* pending incomplete block *)
      IF (dec.incompleteSize+(end-start) >= blockSize) THEN
        (* we have enough data for the whole line: assemble and decode it *)
        len := blockSize-dec.incompleteSize;
        SYSTEM.MOVE (SYSTEM.ADR(data[start]),
                     SYSTEM.ADR(dec.incompleteData[dec.incompleteSize]),
                     len);
        TwofishC.Twofish_decrypt(dec.xkey,
                                 SYSTEM.ADR(dec.incompleteData),
                                 SYSTEM.ADR(d));
        INC (start, len);
        INC (dpos, blockSize);
        dec.incompleteSize := 0;
      ELSE
        (* still not enough data: add more data to buffer and exit *)
        SYSTEM.MOVE (SYSTEM.ADR(data[start]),
                     SYSTEM.ADR(dec.incompleteData[dec.incompleteSize]),
                     end-start);
        INC (dec.incompleteSize, end-start);
        RETURN;
      END;
    END;

    (* here holds: dec.incompleteSize = 0 *)
    WHILE (start <= end-blockSize) DO
      TwofishC.Twofish_decrypt(dec.xkey,
                               SYSTEM.ADR(data[start]),
                               SYSTEM.ADR(d[dpos]));
      INC (start, blockSize);
      INC (dpos, blockSize);
      
      IF (dpos >= sizeBuffer) THEN
        b.AppendLatin1Region (d, 0, dpos);
        dpos := 0;
      END;
    END;
    b.AppendLatin1Region (d, 0, dpos);

    IF (end > start) THEN
      (* store unprocessed data for later *)
      SYSTEM.MOVE (SYSTEM.ADR(data[start]),
                   SYSTEM.ADR(dec.incompleteData),
                   end-start);
    END;
    dec.incompleteSize := end-start;
  END Decode;

PROCEDURE (dec: Decoder) Reset*;
  BEGIN
    dec. incompleteSize := 0;
  END Reset;

PROCEDURE (enc: Encoder) Encode*(s: Object.String;
                                     start, end: LONGINT;
                                     b: StringBuffer.StringBuffer);
  CONST
    sizeBuffer = 4*1024;
  VAR
    d: ARRAY sizeBuffer+blockSize OF CHAR;
    c: Object.CharsLatin1;
    dpos, len: LONGINT;
  BEGIN
    c := s(Object.String8).CharsLatin1();

    dpos := 0;
    IF (enc.incompleteSize # 0) THEN    (* pending incomplete block *)
      IF (enc.incompleteSize+(end-start) >= blockSize) THEN
        (* we have enough data for the whole line: assemble and encode it *)
        len := blockSize-enc.incompleteSize;
        SYSTEM.MOVE (SYSTEM.ADR(c[start]),
                     SYSTEM.ADR(enc.incompleteData[enc.incompleteSize]),
                     len);
        TwofishC.Twofish_encrypt(enc.xkey,
                                 SYSTEM.ADR(enc.incompleteData),
                                 SYSTEM.ADR(d));
        INC (start, len);
        INC (dpos, blockSize);
        enc.incompleteSize := 0;
      ELSE
        (* still not enough data: add more data to buffer and exit *)
        SYSTEM.MOVE (SYSTEM.ADR(c[start]),
                     SYSTEM.ADR(enc.incompleteData[enc.incompleteSize]),
                     end-start);
        INC (enc.incompleteSize, end-start);
        RETURN;
      END;
    END;
    
    WHILE (start <= end-blockSize) DO
      TwofishC.Twofish_encrypt(enc.xkey,
                               SYSTEM.ADR(c[start]),
                               SYSTEM.ADR(d[dpos]));
      INC (start, blockSize);
      INC (dpos, blockSize);
      
      IF (dpos >= sizeBuffer) THEN
        b.AppendLatin1Region (d, 0, dpos);
        dpos := 0;
      END;
    END;
    b.AppendLatin1Region (d, 0, dpos);

    (* store unprocessed data for later *)
    IF (end > start) THEN
      SYSTEM.MOVE (SYSTEM.ADR(c[start]),
                   SYSTEM.ADR(enc.incompleteData),
                   end-start);
    END;
    enc.incompleteSize := end-start;
  END Encode;

PROCEDURE (enc: Encoder) Closure*(b: StringBuffer.StringBuffer);
  VAR
    d: ARRAY blockSize OF CHAR;
    i: LONGINT;
  BEGIN
    IF (enc.incompleteSize # 0) THEN     (* pad with zeros *)
      FOR i := enc.incompleteSize TO blockSize-1 DO
        enc.incompleteData[i] := 0X;
      END;
      TwofishC.Twofish_encrypt(enc.xkey,
                               SYSTEM.ADR(enc.incompleteData),
                               SYSTEM.ADR(d));
      b.AppendLatin1Region (d, 0, blockSize);
    END;
  END Closure;

PROCEDURE (enc: Encoder) Reset*;
  BEGIN
    enc. incompleteSize := 0;
  END Reset;

PROCEDURE Register*;
  BEGIN
    Codec.Register (twofish, "Twofish");
  END Register;

BEGIN
  TwofishC.Twofish_initialise;           (* endless loop on error *)
  NEW (twofish);
  Codec.InitCodec (twofish, Codec.encryption, "Twofish");
END Codec:Twofish.
