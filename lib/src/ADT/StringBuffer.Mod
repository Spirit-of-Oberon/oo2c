(*	$Id$	*)
MODULE ADT:StringBuffer [OOC_EXTENSIONS];
(*  String data type of dynamic length.
    Copyright (C) 1998-2002  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  S := SYSTEM, IntStr, RealStr, Object;

TYPE
  CharsLatin1* = POINTER TO ARRAY[READ_ONLY] OF CHAR;
  CharsUCS4* = POINTER TO ARRAY[READ_ONLY] OF UCS4CHAR;
  StringBuffer* = POINTER TO StringBufferDesc;
  StringBufferDesc* = RECORD
  (**Assembles string values.  This class is mutable in the sense that it can
     be modified in place.  All variables sharing a reference to an instance of
     @otype{StringBuffer} see all changes applied to it.  *)
    (Object.ObjectDesc)
    capacity: LONGINT;
    length-: LONGINT;
    (**The length of the current string.  *)
    data8: CharsLatin1;
    (* As long as 8-bit characters are added to a buffer, its internal storage
       is based on CHAR.  The first @otype{Char} value switches it to 32-bit
       storage.  *)
    data32: CharsUCS4;
  END;


PROCEDURE Init(b: StringBuffer; initialCapacity: LONGINT);
  BEGIN
    IF (initialCapacity < 8) THEN
      (* make sure that we have a sane capacity; 0 and 1 break
         EnsureCapacity *)
      initialCapacity := 8;
    END;
    b.capacity := initialCapacity;
    b.length := 0;
    NEW(b.data8, initialCapacity);
    b.data32 := NIL;
  END Init;

PROCEDURE NewCapacity*(initialCapacity: LONGINT): StringBuffer;
  VAR
    b: StringBuffer;
  BEGIN
    NEW(b);
    Init(b, initialCapacity);
    RETURN b;
  END NewCapacity;

PROCEDURE (b: StringBuffer) ToString*(): STRING;
  BEGIN
    IF(b.data8 # NIL) THEN
      RETURN Object.NewLatin1Region(b.data8^, 0, b.length);
    ELSE
      RETURN Object.NewUCS4Region(b.data32^, 0, b.length);
    END;
  END ToString;

PROCEDURE (b: StringBuffer) CharAt*(index: LONGINT): UCS4CHAR;
  BEGIN
    IF (b.data8 # NIL) THEN
      RETURN b.data8[index];
    ELSE
      RETURN b.data32[index];
    END;
  END CharAt;

PROCEDURE (b: StringBuffer) Clear*;
  BEGIN
    b.length := 0;
  END Clear;

PROCEDURE (b: StringBuffer) EnsureCapacity (cap: LONGINT);
  VAR
    newCap: LONGINT;
    new8: CharsLatin1;
    new32: CharsUCS4;
  BEGIN
    IF (b.capacity < cap) THEN
      newCap := b.capacity;
      WHILE (newCap < cap) DO
        newCap := newCap*2;
      END;
      b.capacity := newCap;
      
      IF (b.data8 # NIL) THEN
        NEW(new8, newCap);
        S.MOVE(S.ADR(b.data8^), S.ADR(new8^), b.length*SIZE(CHAR));
        b.data8 := new8;
      ELSE
        NEW(new32, newCap);
        S.MOVE(S.ADR(b.data32^), S.ADR(new32^), b.length*SIZE(UCS4CHAR));
        b.data32 := new32;
      END;
    END;
  END EnsureCapacity;

PROCEDURE (b: StringBuffer) CharsLatin1*(): CharsLatin1;
(**Return a reference to the character data of the string buffer.  It holds
   valid character data in the index range @samp{0} to @samp{b.length-1}.  The
   element at index @samp{b.length} is @samp{0X}.  Please note that the string
   buffer may also contain @samp{0X} itself.

   If wide characters have been added to @oparam{b}, then no
   @otype{CharsLatin1} representation is available and result is @code{NIL}.

   @emph{Important}: The reference only remains valid until the first operation
   that modifies the buffer.  After such an operation, it may or may not
   reflect the current buffer contents.  *)
  BEGIN
    IF (b.data8 # NIL) THEN
      b.EnsureCapacity(b.length+1);
      b.data8[b.length] := 0X;
    END;
    RETURN b.data8;
  END CharsLatin1;

PROCEDURE (b: StringBuffer) ConvertTo32;
  VAR
    i: LONGINT;
  BEGIN
    NEW(b.data32, LEN(b.data8^));
    FOR i := 0 TO b.length-1 DO;
      b.data32[i] := b.data8[i];
    END;
    b.data8 := NIL;
  END ConvertTo32;

PROCEDURE (b: StringBuffer) AppendLatin1Region*(data[NO_COPY]: ARRAY OF CHAR;
                                                start, end: LONGINT);
  VAR
    len, i: LONGINT;
  BEGIN
    ASSERT(start >= 0);
    ASSERT(start <= end);
    ASSERT(end <= LEN(data));
    
    len := end-start;
    b.EnsureCapacity(b.length+len);
    IF (b.data8 # NIL) THEN
<*PUSH; IndexCheck:=FALSE*>
      S.MOVE(S.ADR(data[start]), S.ADR(b.data8[b.length]), len*SIZE(CHAR));
<*POP*>
    ELSE
      i := b.length;
      WHILE (start # end) DO
        b.data32[i] := data[start];
        INC(start); INC(i);
      END;
    END;
    INC(b.length, len);
  END AppendLatin1Region;

PROCEDURE Length(data[NO_COPY]: ARRAY OF CHAR): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (data[i] # 0X) DO
      INC(i);
    END;
    RETURN i;
  END Length;

PROCEDURE (b: StringBuffer) AppendLatin1*(data[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    b.AppendLatin1Region(data, 0, Length(data));
  END AppendLatin1;

PROCEDURE (b: StringBuffer) AppendLatin1Char*(ch: CHAR);
  BEGIN
    b.EnsureCapacity(b.length+1);
    IF (b.data8 # NIL) THEN
      b.data8[b.length] := ch;
    ELSE
      b.data32[b.length] := ch;
    END;
    INC(b.length);
  END AppendLatin1Char;

PROCEDURE (b: StringBuffer) AppendUCS4Region*(data[NO_COPY]: ARRAY OF UCS4CHAR;
                                              start, end: LONGINT);
  VAR
    len: LONGINT;
  BEGIN
    ASSERT(start >= 0);
    ASSERT(start <= end);
    ASSERT(end <= LEN(data));
    
    len := end-start;
    b.EnsureCapacity(b.length+len);
    IF (b.data32 = NIL) THEN
      b.ConvertTo32;
    END;
<*PUSH; IndexCheck:=FALSE*>
    S.MOVE(S.ADR(data[start]), S.ADR(b.data32[b.length]), len*SIZE(UCS4CHAR));
<*POP*>
    INC(b.length, len);
  END AppendUCS4Region;

PROCEDURE (b: StringBuffer) Append*(obj: Object.Object);
  VAR
    s: STRING;
    c8: Object.CharsLatin1;
    c32: Object.CharsUCS4;
  BEGIN
    IF (obj = NIL) THEN
      b.Append("NIL");
    ELSE
      WITH obj: STRING DO
        s := obj;
      ELSE
        s := obj.ToString();
      END;
      
      WITH s: Object.String8 DO
        c8 := s.CharsLatin1();
        b.AppendLatin1Region(c8^, 0, s.length);
      | s: Object.String32 DO
        c32 := s.CharsUCS4();
        b.AppendUCS4Region(c32^, 0, s.length);
      END;
    END;
  END Append;

PROCEDURE New*(str: STRING): StringBuffer;
  VAR
    b: StringBuffer;
  BEGIN
    b := NewCapacity(str.length);
    b.Append(str);
    RETURN b;
  END New;

PROCEDURE NewLatin1*(str[NO_COPY]: ARRAY OF CHAR): StringBuffer;
  VAR
    b: StringBuffer;
  BEGIN
    b := NewCapacity(Length(str));
    b.AppendLatin1(str);
    RETURN b;
  END NewLatin1;

PROCEDURE (b: StringBuffer) AppendInt* (val: LONGINT);
(**Append the string representation of @code{LONGINT} @oparam{val} to the
   current string *)
  VAR a: ARRAY 32 OF CHAR;
  BEGIN
    IntStr.IntToStr(val, a);
    b.AppendLatin1(a);
  END AppendInt;

PROCEDURE (b: StringBuffer) AppendReal* (val: REAL);
(**Append the string representation of @code{REAL} @oparam{val} to the
   current string *)
  VAR a: ARRAY 32 OF CHAR;
  BEGIN
    RealStr.RealToStr(val, a);
    b.AppendLatin1(a);
  END AppendReal;

PROCEDURE (b: StringBuffer) AppendSet* (val: SET);
(**Append the string representation of a @code{SET} @oparam{val} to the
   currrent string. *)
  VAR
    begin, i: SHORTINT; comma: BOOLEAN;
  BEGIN
    b.AppendLatin1Char("{");
    comma := FALSE;
    i := MIN(SET);
    WHILE i <= MAX(SET) DO
      IF i IN val THEN
        begin := i;
        WHILE (i < MAX(SET)) & ((i+1) IN val) DO INC(i) END;
        IF comma THEN 
          b.AppendLatin1Char(",")
        END;
        comma := TRUE;
        b.AppendInt(begin);
        IF begin < i THEN
          IF i = begin + 1 THEN
            b.AppendLatin1Char(",");
          ELSE
            b.AppendLatin1("..");
          END;
          b.AppendInt(i);
        END;
      END;
      INC(i)
    END; 
    b.AppendLatin1Char("}");
  END AppendSet;

PROCEDURE (b: StringBuffer) AppendBool* (val: BOOLEAN);
(**Append the string representation of a @code{BOOLEAN} @oparam{val} to the
   current string. *)
  BEGIN
    IF val THEN
      b.AppendLatin1("TRUE")
    ELSE
      b.AppendLatin1("FALSE")
    END
  END AppendBool;

PROCEDURE (b: StringBuffer) Insert*(obj: Object.Object; at: LONGINT);
  VAR
    s: STRING;
    c8: Object.CharsLatin1;
    c32: Object.CharsUCS4;
    i: LONGINT;
  BEGIN
    IF (obj = NIL) THEN
      b.Insert("NIL", at);
    ELSE
      WITH obj: STRING DO
        s := obj;
      ELSE
        s := obj.ToString();
      END;

      b.EnsureCapacity(b.length+s.length);
      WITH s: Object.String8 DO
        c8 := s.CharsLatin1();
        IF (b.data8 # NIL) THEN
          FOR i := b.length-1 TO at BY -1 DO
            b.data8[i+s.length] := b.data8[i];
          END;
          FOR i := 0 TO s.length-1 DO
            b.data8[at+i] := c8[i];
          END;
        ELSE
          FOR i := b.length-1 TO at BY -1 DO
            b.data32[i+s.length] := b.data32[i];
          END;
          FOR i := 0 TO s.length-1 DO
            b.data32[at+i] := c8[i];
          END;
        END;
        
      | s: Object.String32 DO
        c32 := s.CharsUCS4();
        IF (b.data32 = NIL) THEN
          b.ConvertTo32;
        END;
        FOR i := b.length-1 TO at BY -1 DO
          b.data32[i+s.length] := b.data32[i];
        END;
        FOR i := 0 TO s.length-1 DO
          b.data32[at+i] := c32[i];
        END;
      END;
      INC(b.length, s.length);
    END;
  END Insert;

PROCEDURE (b: StringBuffer) Delete*(start, end: LONGINT);
  VAR
    i, d: LONGINT;
  BEGIN
    ASSERT (start >= 0);
    ASSERT (start <= end);
    ASSERT (end <= b.length);
    
    IF (end = b.length) THEN
      b.length := start;
    ELSIF (b.data8 # NIL) THEN
      d := end-start;
      FOR i := start TO b.length-d-1 DO
        b.data8[i] := b.data8[i+d]
      END;
      DEC (b.length, d);
    ELSIF (b.data32 # NIL) THEN
      d := end-start;
      FOR i := start TO b.length-d-1 DO
        b.data32[i] := b.data32[i+d]
      END;
      DEC (b.length, d);
    END;
  END Delete;
 
END ADT:StringBuffer.
