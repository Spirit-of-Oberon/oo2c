MODULE Object;

(**This module provides the definitions for a basic object type used in most of
   the ADT library.

   Note: This module is a construction site.  New type definitions and features
   are added on demand.  If it is not used, it has no place here.  *)

IMPORT
  S := SYSTEM, RT0;
  
TYPE
  Hash* = LONGINT;
  (**The integer type used to store hash values.  *)
  
  Object* = POINTER TO ObjectDesc;
  ObjectArray* = ARRAY OF Object;
  ObjectArrayPtr* = POINTER TO ObjectArray;
  ObjectDesc* = RECORD [ABSTRACT]
  (**This class is the common base type of (almost) all classes defined in this
     module and the ADT library.  It provides the methods @oproc{Object.Equals}
     and @oproc{Object.HashCode}.

     It is an abstract class without any state of its own.  As such, it has no
     initialization procedure or a cleanup method.  *)
  END;

TYPE
  String* = POINTER TO StringDesc;
  StringArray* = ARRAY OF String;
  StringArrayPtr* = POINTER TO StringArray;
  StringDesc = RECORD [ABSTRACT]
  (**A string is a sequence of Unicode characters.  Each character holds a
     Unicode code point in the range @samp{[U+0000, U+10FFFF}.  Values from the
     surrogate code ranges @samp{[U+DC00, U+DFFF} are not allowed.

     Strings are immutable.  That is, over the whole lifetime of a string, its
     address, type, length, and content stays the same.

     A @otype{String} can hold any Oberon-2 string, but the reverse is not
     true, even if the character range is restricted: @samp{U+0000} can appear
     in a @otype{String}, but not in an Oberon-2 string.  *)
    (ObjectDesc)
    length-: LONGINT;
    (**Number of code points in the sequence.  Because surrogate pairs
       are not allowed, this equals the number of characters.  *)
  END;

TYPE
  CharsLatin1* = POINTER TO ARRAY[READ_ONLY] OF CHAR;
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  This
     restriction may be enforced by the OOC2 compiler at a later stage.  *)
  CharsUCS4* = POINTER TO ARRAY[READ_ONLY] OF UCS4CHAR;
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  This
     restriction may be enforced by the OOC2 compiler at a later stage.  *)
  
TYPE
  String8* = POINTER TO String8Desc;
  String8Desc = RECORD
    (StringDesc)
    data: CharsLatin1;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+00FF}.  The array is of length @samp{@ofield{length}+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;
  
TYPE
  String32* = POINTER TO String32Desc;
  String32Desc = RECORD
    (StringDesc) 
    data: CharsUCS4;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+10FFFF}, excluding the surrogate area @samp{[U+DC00, U+DFFFF]}.
       The array is of length @samp{@ofield{length}+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;

VAR
  emptyString-: String;

PROCEDURE ^ NewLatin1Region*(str[NO_COPY]: ARRAY OF CHAR;
                             start, end: LONGINT): String8;

PROCEDURE (x: Object) ToString*(): String;
(**Returns a string representation of the object.  Typically, the string is
   some form of ``natural'' representation of the value.  For complex objects,
   it should describe the type and essential attributes of the object.  The
   exact format of the returned value is intentionally left vague.  *)
  CONST
    nameCutoff = 128;
  VAR
    str: ARRAY 1+nameCutoff+1+nameCutoff+4+16+1+1 OF CHAR;
    i: LONGINT;
    struct: RT0.Struct;
    
  PROCEDURE Append(name: RT0.Name);
    VAR
      j: LONGINT;
    BEGIN
      j := 0;
      WHILE (j # nameCutoff) & (name[j] # 0X) DO
        str[i] := name[j]; INC(i); INC(j);
      END;
    END Append;

  PROCEDURE AppendHex(x: LONGINT);
    VAR
      j, ch: LONGINT;
    BEGIN
      FOR j := 7 TO 0 BY -1 DO
        ch := (x MOD 16)+ORD("0");
        IF (ch > ORD("9")) THEN
          INC(ch, ORD("a")-(ORD("9")+1));
        END;
        str[i+j] := CHR(ch);
        x := x DIV 16;
      END;
      INC(i, 8);
    END AppendHex;
  
  BEGIN
    str := "<"; i := 1;
    struct := RT0.TypeOf(x);
    Append(struct.module.name);
    str[i] := "."; INC (i);
    Append(struct.name);
    str[i] := " "; INC(i);
    str[i] := "a"; INC(i);
    str[i] := "t"; INC(i);
    str[i] := " "; INC(i);
<* IF TARGET_ADDRESS = 64 THEN *>
    AppendHex(SHORT(S.LSH(S.VAL(S.ADDRESS, x), -32)));
    AppendHex(SHORT(S.LSH(S.LSH(S.VAL(S.ADDRESS, x), 32), -32)));
<* ELSE *>
    AppendHex(S.VAL(S.ADDRESS, x));
<* END *>
    str[i] := ">"; INC(i);
    RETURN NewLatin1Region(str, 0, i);
  END ToString;

PROCEDURE (x: Object) Equals*(y: Object): BOOLEAN;
(**Indicates whether some other object is "equal to" this one.

   The @oproc{Object.Equals} method implements an equivalence relation:

   @itemize @bullet
   @item
   It is reflexive: for any reference value @samp{x}, @samp{x.Equals(x)} should
   return @code{TRUE}.

   @item
   It is symmetric: for any reference values @samp{x} and @samp{y},
   @samp{x.Equals(y)} should return @code{TRUE} if and only if
   @samp{y.Equals(x)} returns @code{TRUE}.

   @item
   It is transitive: for any reference values @samp{x}, @samp{y}, and @samp{z},
   if @samp{x.Equals(y)} returns @code{TRUE} and @samp{y.Equals(z)} returns
   @code{TRUE}, then @samp{x.Equals(z)} should return @code{TRUE}.

   @item
   It is consistent: for any reference values @samp{x} and @samp{y}, multiple
   invocations of @samp{x.Equals(y)} consistently return @code{TRUE} or
   consistently return @code{FALSE}, provided no information used in equals
   comparisons on the object is modified.

   @item
   For any non-@code{NIL} reference value @samp{x}, @samp{x.Equals(NIL)} should
   return @code{FALSE}.
   @end itemize

   The @samp{Equals} method for class @otype{Object} implements the most
   discriminating possible equivalence relation on objects; that is, for any
   reference values @samp{x} and @samp{y}, this method returns @code{TRUE} if
   and only if @samp{x} and @samp{y} refer to the same object (@samp{x=y} has
   the value @code{TRUE}).  *)
  BEGIN
    RETURN (x = y)
  END Equals;

PROCEDURE (x: Object) HashCode*(): Hash;
(**Returns a hash code value for the object.  This method is supported for the
   benefit of dictionaries such as those provided by
   @omodule{*ADT:Dictionary}..

   The general contract of @oproc{Object.HashCode} is:

   @itemize
   @item
   Whenever it is invoked on the same object more than once during an execution
   of an application, the @oproc{Object.HashCode} method must consistently
   return the same integer, provided no information used in equals comparisons
   on the object is modified.  This integer need not remain consistent from one
   execution of an application to another execution of the same application.

   @item
   If two objects are equal according to the @oproc{Object.Equals} method, then
   calling the @oproc{Object.HashCode} method on each of the two objects must
   produce the same integer result.

   @item
   It is @emph{not} required that if two objects are unequal according to the
   @oproc{Object.Equals} method, then calling the @oproc{Object.HashCode}
   method on each of the two objects must produce distinct integer results.
   However, the programmer should be aware that producing distinct integer
   results for unequal objects may improve the performance of dictionaries.
   @end itemize

   As much as is reasonably practical, the @oproc{Object.HashCode} method
   defined by class @otype{Object} does return distinct integers for distinct
   objects.  (This is typically implemented by converting the internal address
   of the object into an integer, but this implementation technique is not
   required.)  *)
  BEGIN
<*IF TARGET_ADDRESS=64 THEN*>
    RETURN S.VAL(Hash,
                 S.VAL(SET, SHORT(S.LSH(S.LSH(S.VAL(S.ADDRESS,x), 32), -32))) /
                 S.VAL(SET, SHORT(S.LSH(S.VAL(S.ADDRESS,x), -32))))
<*ELSE*>
    RETURN S.VAL(Hash, x)
<*END*>
  END HashCode;



PROCEDURE NewString8(source: S.ADDRESS; length: LONGINT): String8;
  VAR
    s: String8;
    d: CharsLatin1;
  BEGIN
    NEW(s);
    NEW(d, length+1);
    s. length := length;
    s. data := d;
    S.MOVE(source, S.ADR(d^), length*SIZE(CHAR));
    d[length] := 0X;
    RETURN s;
  END NewString8;

PROCEDURE NewString32(source: S.ADDRESS; length: LONGINT): String32;
  VAR
    s: String32;
    d: CharsUCS4;
  BEGIN
    NEW(s);
    NEW(d, length+1);
    s. length := length;
    s. data := d;
    S.MOVE(source, S.ADR(d^), length*SIZE(UCS4CHAR));
    d[length] := 0X;
    RETURN s;
  END NewString32;


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
    RETURN NewString8(S.ADR(str), i);
  END NewLatin1;

PROCEDURE NewLatin1Region*(str[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT): String8;
(**Create a string value from @samp{str[start, end-1]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   The characters in @oparam{str} are Latin-1 code points.
   @end precond  *)
  BEGIN
    RETURN NewString8(S.ADR(str[start]), end-start);
  END NewLatin1Region;

PROCEDURE NewLatin1Char*(ch: CHAR): String8;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Latin-1 code point.
   @end precond  *)
  BEGIN
    RETURN NewString8(S.ADR(ch), 1);
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
    d: CharsUCS4;
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
      d[j] := str[j];
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
    d: CharsUCS4;
  BEGIN
    i := end-start;
    NEW(s);
    NEW(d, i+1);
    s. length := i;
    s. data := d;
    FOR j := start TO end-1 DO
      d[j-start] := str[j];
    END;
    d[i] := 0X;
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
    d: CharsUCS4;
  BEGIN
    NEW(s);
    NEW(d, 2);
    s. length := 1;
    s. data := d;
    d[0] := ch;
    d[1] := 0X;
    RETURN s;
  END NewUCS2Char;

PROCEDURE NewUCS4Region*(str[NO_COPY]: ARRAY OF UCS4CHAR;
                          start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   All characters are Unicode 3.1 code points outside the surrogate areas.
   @end precond  *)
  BEGIN
    RETURN NewString32 (S.ADR(str[start]), end-start);
  END NewUCS4Region;

PROCEDURE NewUCS4Char*(ch: UCS4CHAR): String;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Unicode 3.1 code point.
   @end precond  *)
  BEGIN
    RETURN NewString32(S.ADR(ch), 1);
  END NewUCS4Char;

PROCEDURE NewUCS4*(str[NO_COPY]: ARRAY OF UCS4CHAR): String;
(**Create a string value from @oparam{str} without any translation.

   @precond
   The characters in @oparam{str} are Unicode 3.1 code points outside the
   surrogate areas.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE(str[i] # 0X) DO
      INC(i);
    END;
    RETURN NewString32 (S.ADR(str), i);
  END NewUCS4;

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
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c8.data^),
                    s1.length*SIZE(CHAR));
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c8.data[s1.length]),
                    s2.length*SIZE(CHAR)+SIZE(CHAR));
        RETURN c8;
        
      | s2: String32 DO                  (* String8+String32 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        FOR i := 0 TO s1.length-1 DO
          c32.data[i] := s1.data[i];
        END;
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c32.data[s1.length]),
                    s2.length*SIZE(UCS4CHAR)+SIZE(UCS4CHAR));
        RETURN c32;
      END;
      
    | s1: String32 DO
      WITH s2: String8 DO
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c32.data^),
                    s1.length*SIZE(UCS4CHAR));
        FOR i := 0 TO s2.length DO
          c32.data[s1.length+i] := s2.data[i];
        END;
        RETURN c32;
        
      | s2: String32 DO                  (* String32+String32 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c32.data^),
                    s1.length*SIZE(UCS4CHAR));
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c32.data[s1.length]),
                    s2.length*SIZE(UCS4CHAR)+SIZE(UCS4CHAR));
        RETURN c32;
      END;
    END;
  END Concat2;

PROCEDURE (s: String) Concat*(t: String): String;
  BEGIN
    RETURN Concat2(s, t);
  END Concat;

PROCEDURE (s: String8) CharsLatin1*(): CharsLatin1;
  BEGIN
    RETURN s.data;
  END CharsLatin1;

PROCEDURE (s: String32) CharsUCS4*(): CharsUCS4;
  BEGIN
    RETURN s.data;
  END CharsUCS4;

PROCEDURE (s: String) ToString*(): String;
  BEGIN
    RETURN s;
  END ToString;

PROCEDURE (s: String) [ABSTRACT] Equals*(y: Object): BOOLEAN;
  END Equals;

PROCEDURE (s: String8) Equals*(y: Object): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    IF (y = NIL) OR ~(y IS String) OR (s.length # y(String).length) THEN
      RETURN FALSE;
    ELSE
      WITH y: String8 DO
        i := 0;
        WHILE (i # s.length) & (s.data[i] = y.data[i]) DO
          INC(i);
        END;
        RETURN (i = s.length);
      | y: String32 DO
        i := 0;
        WHILE (i # s.length) & (s.data[i] = y.data[i]) DO
          INC(i);
        END;
        RETURN (i = s.length);
      END;
    END;
  END Equals;

PROCEDURE (s: String32) Equals*(y: Object): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    IF (y = NIL) OR ~(y IS String) OR (s.length # y(String).length) THEN
      RETURN FALSE;
    ELSE
      WITH y: String8 DO
        i := 0;
        WHILE (i # s.length) & (s.data[i] = y.data[i]) DO
          INC(i);
        END;
        RETURN (i = s.length);
      | y: String32 DO
        i := 0;
        WHILE (i # s.length) & (s.data[i] = y.data[i]) DO
          INC(i);
        END;
        RETURN (i = s.length);
      END;
    END;
  END Equals;

PROCEDURE (s: String) [ABSTRACT] Compare*(y: Object): LONGINT;
  END Compare;

PROCEDURE (s: String8) Compare*(y: Object): LONGINT;
  VAR
    min, i: LONGINT;
  BEGIN
    min := s.length;
    WITH y: String8 DO
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (s.data[i] = y.data[i]) DO
        INC(i);
      END;
      IF (i = min) THEN
        RETURN (s.length - y.length);
      ELSE
        RETURN (ORD(s.data[i]) - ORD(y.data[i]));
      END;
    | y: String32 DO
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (s.data[i] = y.data[i]) DO
        INC(i);
      END;
      IF (i = min) THEN
        RETURN (s.length - y.length);
      ELSE
        RETURN (ORD(s.data[i]) - ORD(y.data[i]));
      END;
    END;
  END Compare;

PROCEDURE (s: String32) Compare*(y: Object): LONGINT;
  VAR
    min, i: LONGINT;
  BEGIN
    min := s.length;
    WITH y: String8 DO
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (s.data[i] = y.data[i]) DO
        INC(i);
      END;
      IF (i = min) THEN
        RETURN (s.length - y.length);
      ELSE
        RETURN (ORD(s.data[i]) - ORD(y.data[i]));
      END;
    | y: String32 DO
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (s.data[i] = y.data[i]) DO
        INC(i);
      END;
      IF (i = min) THEN
        RETURN (s.length - y.length);
      ELSE
        RETURN (ORD(s.data[i]) - ORD(y.data[i]));
      END;
    END;
  END Compare;

PROCEDURE (s: String) [ABSTRACT] HashCode*(): Hash;
  END HashCode;

PROCEDURE (s: String8) HashCode*(): Hash;
  VAR
    len, p: LONGINT;
    x: Hash;
  BEGIN
    (* this is intended as a reimplementation of the Python hash code on
       strings; any errors are mine, of course *)
    len := s.length;
    x := ASH(LONG(ORD(s.data[0])), 7);
    p := 0;
    WHILE (p # len) DO
      <* PUSH; OverflowCheck := FALSE *>
      x := S.VAL(Hash, S.VAL(SET, 1000003*x) /
                 S.VAL(SET, LONG(ORD(s.data[p]))));
      <* POP *>
      INC(p);
    END;
    x := S.VAL(Hash, S.VAL(SET,x) / S.VAL(SET,len));
    RETURN x
  END HashCode;

PROCEDURE (s: String32) HashCode*(): Hash;
  VAR
    len, p: LONGINT;
    x: Hash;
  BEGIN
    (* this is intended as a reimplementation of the Python hash code on
       strings; any errors are mine, of course *)
    len := s.length;
    x := ASH(ORD(s.data[0]), 7);
    p := 0;
    WHILE (p # len) DO
      <* PUSH; OverflowCheck := FALSE *>
      x := S.VAL(Hash, S.VAL(SET, 1000003*x) /
                 S.VAL(SET, s.data[p]));
      <* POP *>
      INC(p);
    END;
    x := S.VAL(Hash, S.VAL(SET,x) / S.VAL(SET,len));
    RETURN x
  END HashCode;

PROCEDURE (s: String) [ABSTRACT] CharAt* (index: LONGINT): UCS4CHAR;
  END CharAt;

PROCEDURE (s: String8) CharAt* (index: LONGINT): UCS4CHAR;
  BEGIN
    RETURN s. data[index];
  END CharAt;

PROCEDURE (s: String32) CharAt* (index: LONGINT): UCS4CHAR;
  BEGIN
    RETURN s. data[index];
  END CharAt;

PROCEDURE (s: String) [ABSTRACT] Substring* (start, end: LONGINT): String;
  END Substring;

PROCEDURE (s: String8) Substring* (start, end: LONGINT): String;
  BEGIN
    RETURN NewString8(S.ADR(s. data[start]), end-start);
  END Substring;

PROCEDURE (s: String32) Substring* (start, end: LONGINT): String;
  BEGIN
    RETURN NewString32(S.ADR(s. data[start]), end-start);
  END Substring;


PROCEDURE (s: String) [ABSTRACT] IndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
  END IndexOf;

PROCEDURE (s: String8) IndexOf* (char: UCS4CHAR; pos: LONGINT): LONGINT;
  VAR
    endpos: LONGINT;
  BEGIN
    IF (char <= MAX(CHAR)) THEN
      endpos := s.length;
      WHILE (pos # endpos) DO
        IF (s.data[pos] = char) THEN
          RETURN pos;
        END;
        INC (pos)
      END;
    END;
    RETURN -1
  END IndexOf;

PROCEDURE (s: String32) IndexOf* (char: UCS4CHAR; pos: LONGINT): LONGINT;
  VAR
    endpos: LONGINT;
  BEGIN
    endpos := s.length;
    WHILE (pos # endpos) DO
      IF (s.data[pos] = char) THEN
        RETURN pos;
      END;
      INC (pos)
    END;
    RETURN -1
  END IndexOf;

BEGIN
  emptyString := NewLatin1("");
END Object.
