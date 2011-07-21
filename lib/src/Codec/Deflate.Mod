(* 	$Id: Deflate.Mod,v 1.1 2003/09/22 19:32:17 mva Exp $	 *)
MODULE Codec:Deflate[OOC_EXTENSIONS];
(*  Codec for the "deflate" encryption algorithm of the zlib library.
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
  SYSTEM, C, Codec, Log, Object, ADT:StringBuffer, Codec:zlib;

TYPE
  Deflate* = POINTER TO DeflateDesc;
  DeflateDesc = RECORD
    (Codec.CodecDesc)
  END;

TYPE
  Encoder* = POINTER TO EncoderDesc;
  EncoderDesc = RECORD
    (Codec.EncoderDesc)
    strm: zlib.z_stream_s;
  END;
     
TYPE
  Decoder* = POINTER TO DecoderDesc;
  DecoderDesc = RECORD
    (Codec.DecoderDesc)
    strm: zlib.z_stream_s;
  END;

CONST
  sizeBuffer = 4*1024;
  
VAR
  deflate-: Deflate;

PROCEDURE CheckErr (err: C.int; fct: ARRAY OF CHAR);
  BEGIN
    IF (err # zlib.Z_OK) THEN
      Log.String("function signalled error: ", fct);
      Log.LongInt("error code", err);
      HALT(1);
    END;
  END CheckErr;

PROCEDURE (c: Deflate) NewDecoder*(): Decoder;
  VAR
    dec: Decoder;
  BEGIN
    NEW (dec);
    Codec.InitDecoder (dec);
    dec.strm.zalloc := NIL;
    dec.strm.zfree := NIL;
    dec.strm.opaque := NIL;
    RETURN dec;
  END NewDecoder;

PROCEDURE (dec: Decoder) Start*;
  BEGIN
    CheckErr(zlib.inflateInit_(dec.strm, 
                               zlib.ZLIB_VERSION, SIZE(zlib.z_stream_s)),
             "inflateInit_");
  END Start;

PROCEDURE (dec: Decoder) Decode* (data[NO_COPY]: ARRAY OF CHAR;
                                  start, end: LONGINT;
                                  b: StringBuffer.StringBuffer);
  VAR
    d: ARRAY sizeBuffer OF CHAR;
    err: C.int;
  BEGIN
    dec.strm.next_in := SYSTEM.ADR(data[start]);
    dec.strm.avail_in := end-start;
    
    LOOP
      dec.strm.next_out := SYSTEM.ADR(d);
      dec.strm.avail_out := sizeBuffer;
      err := zlib.inflate(dec.strm, zlib.Z_NO_FLUSH);
      IF (err = zlib.Z_STREAM_END) OR (dec.strm.avail_in = 0) THEN
        b.AppendLatin1Region (d, 0, sizeBuffer-dec.strm.avail_out);
        EXIT;
      ELSE
        CheckErr(err, "inflate/NO_FLUSH");
        b.AppendLatin1Region (d, 0, sizeBuffer-dec.strm.avail_out);
      END;
    END;
  END Decode;

PROCEDURE (dec: Decoder) End*;
  BEGIN
    CheckErr(zlib.inflateEnd(dec.strm), "inflateEnd");
  END End;

PROCEDURE (dec: Decoder) Reset*;
  BEGIN
    CheckErr(zlib.inflateReset(dec.strm), "inflateReset");
  END Reset;


PROCEDURE (c: Deflate) NewEncoder*(): Encoder;
  VAR
    enc: Encoder;
  BEGIN
    NEW (enc);
    Codec.InitEncoder (enc);
    enc.strm.zalloc := NIL;
    enc.strm.zfree := NIL;
    enc.strm.opaque := NIL;
    RETURN enc;
  END NewEncoder;

PROCEDURE (enc: Encoder) Start*;
  BEGIN
    CheckErr(zlib.deflateInit_(enc.strm, zlib.Z_DEFAULT_COMPRESSION,
                               zlib.ZLIB_VERSION, SIZE(zlib.z_stream_s)),
             "deflateInit_");
  END Start;

PROCEDURE (enc: Encoder) Encode*(s: Object.String;
                                     start, end: LONGINT;
                                     b: StringBuffer.StringBuffer);
  VAR
    d: ARRAY sizeBuffer OF CHAR;
    c: Object.CharsLatin1;
  BEGIN
    c := s(Object.String8).CharsLatin1();
    enc.strm.next_in := SYSTEM.ADR(c[start]);
    enc.strm.avail_in := end-start;
    
    WHILE (enc.strm.avail_in # 0) DO
      enc.strm.next_out := SYSTEM.ADR(d);
      enc.strm.avail_out := sizeBuffer;
      CheckErr(zlib.deflate(enc.strm, zlib.Z_NO_FLUSH), "deflate/NO_FLUSH");
      b.AppendLatin1Region (d, 0, sizeBuffer-enc.strm.avail_out);
    END;
  END Encode;

PROCEDURE (enc: Encoder) Closure*(b: StringBuffer.StringBuffer);
  VAR
    d: ARRAY sizeBuffer OF CHAR;
    err: C.int;
  BEGIN
    LOOP
      enc.strm.next_out := SYSTEM.ADR(d);
      enc.strm.avail_out := sizeBuffer;
      err := zlib.deflate(enc.strm, zlib.Z_FINISH);
      IF (err = zlib.Z_STREAM_END) THEN
        b.AppendLatin1Region (d, 0, sizeBuffer-enc.strm.avail_out);
        EXIT;
      ELSE
        CheckErr(err, "deflate/FINISH");
        b.AppendLatin1Region (d, 0, sizeBuffer-enc.strm.avail_out);
      END;
    END;
  END Closure;

PROCEDURE (enc: Encoder) End*;
  BEGIN
    CheckErr(zlib.deflateEnd(enc.strm), "deflateEnd");
  END End;

PROCEDURE (enc: Encoder) Reset*;
  BEGIN
    CheckErr(zlib.deflateReset(enc.strm), "deflateReset");
  END Reset;

PROCEDURE Register*;
  BEGIN
    Codec.Register (deflate, "deflate");
  END Register;

BEGIN
  NEW (deflate);
  Codec.InitCodec (deflate, Codec.compression, "deflate");
END Codec:Deflate.
