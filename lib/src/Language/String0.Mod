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
   definitions of Unicode 3.1.  It defines the classes @otype{String} and
   @otype{Buffer}, representing string values and a way to put
   strings together.  A mechanism to translate between string
   representations is provided in a companion module, @omodule{*Codec}.

   In order of importance, the use cases addressed by these classes are

   @itemize @bullet
   @item
   Creating Unicode 3.1 string values and passing them around in an easy and
   efficient way.
   @item
   Interacting with Oberon-2's notion of strings.  In particular, it must be
   easy to pass a string to an @code{ARRAY OF CHAR}, and vice versa.
   @item
   Efficient access to a string's value as a sequence of characters.  This is
   for applications like scanners and pattern matchers, which need a short path
   to character data for performance reasons.
   @end itemize

   The @omodule{*Codec} module deals with translation issues:
   @itemize @bullet
   @item
   Translating between different encodings of string values, for example from
   UTF-8 to Latin-1.
   @item
   Support for stateful codecs, including operations like encryption and
   decryption.
   @item
   Encoding or decoding a chunked stream of bytes, while giving the programmer
   some control over the resources being used for this purpose.
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
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  This
     restriction may be enforced by the OOC2 compiler at a later stage.  *)
  CharsUTF32* = POINTER TO ARRAY OF Char;
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  This
     restriction may be enforced by the OOC2 compiler at a later stage.  *)
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
  String8* = POINTER TO String8Desc;
  BufferLatin1* = ARRAY 8*1024 OF CHAR;
  String8Desc = RECORD
    (StringDesc)
    data: CharsLatin1;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+00FF}.  The array is of length @samp{@ofield{length}+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;
  
TYPE
  String32* = POINTER TO String32Desc;
  BufferUTF32* = ARRAY SIZE(BufferLatin1) DIV SIZE(Char) OF Char;
  String32Desc = RECORD
    (StringDesc) 
    data: CharsUTF32;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+10FFFF}, excluding the surrogate area @samp{[U+DC00, U+DFFFF]}.
       The array is of length @samp{@ofield{length}+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;

CONST
  invalidChar* = 100;
  (**The character cannot be mapped into the character range of the target
     encoding.  *)
  invalidData* = 101;
  (**The input data of an operation is malformed.  For example, a decode
     instruction operating on 32-bit values is called with a number of bytes
     that is not a multiple of 4.  *)

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

PROCEDURE (b: Buffer) AppendLatin1Char* (ch: CHAR);
  BEGIN
    b. EnsureCapacity(b. length+1);
    IF (b. data8 # NIL) THEN
      b.data8[b.length] := ch;
    ELSE
      b.data32[b.length] := ORD(ch);
    END;
    INC (b. length);
  END AppendLatin1Char;

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



PROCEDURE NewLatin1*(str[NO_COPY]: ARRAY OF CHAR): String8;
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

PROCEDURE NewLatin1Region*(str[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT): String8;
(**Create a string value from @samp{str[start, end-1]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   The characters in @oparam{str} are Latin-1 code points.
   @end precond  *)
  BEGIN
    RETURN NewString8(SYSTEM.ADR(str[start]), end-start);
  END NewLatin1Region;

PROCEDURE NewLatin1Char*(ch: CHAR): String8;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Latin-1 code point.
   @end precond  *)
  BEGIN
    RETURN NewString8(SYSTEM.ADR(ch), 1);
  END NewLatin1Char;

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

PROCEDURE NewUCS2Region*(str[NO_COPY]: ARRAY OF LONGCHAR; start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end-1]} without any
   translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   The characters in @oparam{str} are Unicode 3.1 code points outside the
   surrogate areas.
   @end precond  *)
  VAR
    i, j: LONGINT;
    s: String32;
    d: CharsUTF32;
  BEGIN
    i := end-start;
    NEW(s);
    NEW(d, i+1);
    s. length := i;
    s. data := d;
    FOR j := start TO end-1 DO
      d[j-start] := ORD(str[j]);
    END;
    d[i] := 0;
    RETURN s;
  END NewUCS2Region;

PROCEDURE NewUCS2Char*(ch: LONGCHAR): String;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Unicode 3.1 code point outside the
   surrogate areas.
   @end precond  *)
  VAR
    s: String32;
    d: CharsUTF32;
  BEGIN
    NEW(s);
    NEW(d, 2);
    s. length := 1;
    s. data := d;
    d[0] := ORD(ch);
    d[1] := 0;
    RETURN s;
  END NewUCS2Char;

PROCEDURE NewUTF32Region*(str[NO_COPY]: ARRAY OF Char;
                          start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   All characters are Unicode 3.1 code points outside the surrogate areas.
   @end precond  *)
  BEGIN
    RETURN NewString32 (SYSTEM.ADR(str[start]), end-start);
  END NewUTF32Region;

PROCEDURE NewUTF32Char*(ch: Char): String;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Unicode 3.1 code point.
   @end precond  *)
  BEGIN
    RETURN NewString32(SYSTEM.ADR(ch), 1);
  END NewUTF32Char;

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

PROCEDURE Concat2* (s1, s2: String): String;
  VAR
    c8: String8;
    c32: String32;
    i: LONGINT;
  BEGIN
    WITH s1: String8 DO
      WITH s2: String8 DO                (* String8+String8 *)
        NEW(c8);
        c8.length := s1.length+s2.length;
        NEW(c8.data, s1.length+s2.length+1);
        SYSTEM.MOVE(SYSTEM.ADR(s1.data^),
                    SYSTEM.ADR(c8.data^),
                    s1.length*SIZE(CHAR));
        SYSTEM.MOVE(SYSTEM.ADR(s2.data^),
                    SYSTEM.ADR(c8.data[s1.length]),
                    s2.length*SIZE(CHAR)+SIZE(CHAR));
        RETURN c8;
        
      | s2: String32 DO                  (* String8+String32 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        FOR i := 0 TO s1.length-1 DO
          c32.data[i] := ORD(s1.data[i]);
        END;
        SYSTEM.MOVE(SYSTEM.ADR(s2.data^),
                    SYSTEM.ADR(c32.data[s1.length]),
                    s2.length*SIZE(Char)+SIZE(Char));
        RETURN c32;
      END;
      
    | s1: String32 DO
      WITH s2: String8 DO
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        SYSTEM.MOVE(SYSTEM.ADR(s1.data^),
                    SYSTEM.ADR(c32.data^),
                    s1.length*SIZE(Char));
        FOR i := 0 TO s2.length DO
          c32.data[s1.length+i] := ORD(s2.data[i]);
        END;
        RETURN c32;
        
      | s2: String32 DO                  (* String32+String32 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        SYSTEM.MOVE(SYSTEM.ADR(s1.data^),
                    SYSTEM.ADR(c32.data^),
                    s1.length*SIZE(Char));
        SYSTEM.MOVE(SYSTEM.ADR(s2.data^),
                    SYSTEM.ADR(c32.data[s1.length]),
                    s2.length*SIZE(Char)+SIZE(Char));
        RETURN c32;
      END;
    END;
  END Concat2;

PROCEDURE (s: String8) CharsLatin1*(): CharsLatin1;
  BEGIN
    RETURN s. data;
  END CharsLatin1;

PROCEDURE (s: String32) CharsUTF32*(): CharsUTF32;
  BEGIN
    RETURN s. data;
  END CharsUTF32;

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

END Language:String0.
