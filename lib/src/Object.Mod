MODULE Object;

(**This module provides the definitions for a basic object type used in most of
   the ADT library.

   Note: This module is a construction site.  New type definitions and features
   are added on demand.  If it is not used, it has no place here.  *)

IMPORT
  Out0,
  S := SYSTEM;
  
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
    (ObjectDesc)
    length-: LONGINT;
    (**Number of code points in the sequence.  Because surrogate pairs
       are not allowed, this equals the number of characters.  *)
  END;

TYPE
  CharsLatin1* = POINTER TO ARRAY OF CHAR;
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  This
     restriction may be enforced by the OOC2 compiler at a later stage.  *)
  CharsUTF32* = POINTER TO ARRAY OF Char;
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

VAR
  emptyString-: String;
  
PROCEDURE (x: Object) ToStringN*(): String;
(**Returns a string representation of the object.  Typically, the string is
   some form of ``natural'' representation of the value.  For complex objects,
   it should describe the type and essential attributes of the object.  The
   exact format of the returned value is intentionally left vague.  *)
  BEGIN
    RETURN NIL;  (* ... FIXME *)
  END ToStringN;

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
                 S.VAL(SET, S.LSH(S.LSH(S.VAL(S.ADDRESS, x), 32), -32)) /
                 S.VAL(SET, S.LSH(S.VAL(S.ADDRESS, x), -32)))
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
    d: CharsUTF32;
  BEGIN
    NEW(s);
    NEW(d, length+1);
    s. length := length;
    s. data := d;
    S.MOVE(source, S.ADR(d^), length*SIZE(Char));
    d[length] := 0;
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
    RETURN NewString32 (S.ADR(str[start]), end-start);
  END NewUTF32Region;

PROCEDURE NewUTF32Char*(ch: Char): String;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Unicode 3.1 code point.
   @end precond  *)
  BEGIN
    RETURN NewString32(S.ADR(ch), 1);
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
    RETURN NewString32 (S.ADR(str), i);
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
          c32.data[i] := ORD(s1.data[i]);
        END;
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c32.data[s1.length]),
                    s2.length*SIZE(Char)+SIZE(Char));
        RETURN c32;
      END;
      
    | s1: String32 DO
      WITH s2: String8 DO
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c32.data^),
                    s1.length*SIZE(Char));
        FOR i := 0 TO s2.length DO
          c32.data[s1.length+i] := ORD(s2.data[i]);
        END;
        RETURN c32;
        
      | s2: String32 DO                  (* String32+String32 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c32.data^),
                    s1.length*SIZE(Char));
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c32.data[s1.length]),
                    s2.length*SIZE(Char)+SIZE(Char));
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

PROCEDURE (s: String32) CharsUTF32*(): CharsUTF32;
  BEGIN
    RETURN s.data;
  END CharsUTF32;

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
        WHILE (i # s.length) & (ORD(s.data[i]) = y.data[i]) DO
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
        WHILE (i # s.length) & (s.data[i] = ORD(y.data[i])) DO
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
      Out0.String("  0");Out0.Ln;
    min := s.length;
    WITH y: String8 DO
      Out0.String("  a");Out0.Ln;
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (s.data[i] = y.data[i]) DO
      Out0.String("  b");Out0.Ln;
        INC(i);
      END;
      IF (i = min) THEN
      Out0.String("  c");Out0.Ln;
        RETURN (s.length - y.length);
      ELSE
      Out0.String("  d");Out0.Ln;
        RETURN (ORD(s.data[i]) - ORD(y.data[i]));
      END;
    | y: String32 DO
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (ORD(s.data[i]) = y.data[i]) DO
        INC(i);
      END;
      IF (i = min) THEN
        RETURN (s.length - y.length);
      ELSE
        RETURN (ORD(s.data[i]) - y.data[i]);
      END;
    END;
  END Compare;

PROCEDURE (s: String32) Compare*(y: Object): LONGINT;
  VAR
    min, i: LONGINT;
  BEGIN
      Out0.String("  1");Out0.Ln;
    min := s.length;
    WITH y: String8 DO
      IF (y.length < min) THEN min := y.length; END;
      i := 0;
      WHILE (i # min) & (s.data[i] = ORD(y.data[i])) DO
        INC(i);
      END;
      IF (i = min) THEN
        RETURN (s.length - y.length);
      ELSE
        RETURN (s.data[i] - ORD(y.data[i]));
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
        RETURN (s.data[i] - y.data[i]);
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
    x := ASH(s.data[0], 7);
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
    RETURN NewString8(S.ADR(s. data[start]), end-start);
  END Substring;

PROCEDURE (s: String32) Substring* (start, end: LONGINT): String;
  BEGIN
    RETURN NewString32(S.ADR(s. data[start]), end-start);
  END Substring;


PROCEDURE (s: String) [ABSTRACT] IndexOf*(char: Char; pos: LONGINT): LONGINT;
  END IndexOf;

PROCEDURE (s: String8) IndexOf* (char: Char; pos: LONGINT): LONGINT;
  VAR
    endpos: LONGINT;
  BEGIN
    IF (char <= ORD(MAX(CHAR))) THEN
      endpos := s.length;
      WHILE (pos # endpos) DO
        IF (s.data[pos] = CHR(char)) THEN
          RETURN pos;
        END;
        INC (pos)
      END;
    END;
    RETURN -1
  END IndexOf;

PROCEDURE (s: String32) IndexOf* (char: Char; pos: LONGINT): LONGINT;
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
