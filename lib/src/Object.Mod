(* 	$Id: Object.Mod,v 1.29 2004/07/01 19:09:02 mva Exp $	 *)
MODULE Object;
(*  Low-level object and string implementation.
    Copyright (C) 2002,2003  Michael van Acken

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

(**This module provides the definitions for a basic object type used in most of
   the ADT library, and the implementation of the predefined type
   @code{STRING}.

   Note: This module is a construction site.  New type definitions and features
   are added on demand.  If it is not used, it has no place here.  *)

IMPORT
  S := SYSTEM, RT0, HashCode;
  (* Because this module is implicitly imported by almost all other modules,
     normal modules cannot be added to this import list.  Before a module can
     be imported here, it must be added to the `exclude' list of the
     `autoImport' entries of all modules importing `Object'.  *)
     
TYPE
  Hash* = LONGINT;
  (**The integer type used to store hash values.  *)
  
  Object* = POINTER TO ObjectDesc;
  ObjectArray*(E: Object) = ARRAY OF E;
  ObjectArrayPtr*(E: Object) = POINTER TO ObjectArray(E);
  ObjectDesc* = RECORD [ABSTRACT] (RT0.ObjectDesc)
  (**This class is the common base type of (almost) all classes defined in this
     module and the ADT library.  It provides the methods @oproc{Object.Equals}
     and @oproc{Object.HashCode}.

     It is an abstract class without any state of its own.  As such, it has no
     initialization procedure or cleanup method.

     String constants are assignment compatbile with variables of type
     @otype{Object}.  Such an assignment automatically converts the constant
     into an instance of @otype{String}.  That is, in an assignment, for a
     procedure argument passed to a value parameter, and as a function result,
     a string constant can be used instead of a @otype{String}.  The string
     object is created once, as part of the module's initialization code,
     @emph{not} each time its surrounding code is evaluated.  *)
  END;

CONST
  surrogateLow* = 0D800X;
  (**Smallest code of the surrogate area, and the beginning of the low
     surrogate area.  *)
  surrogateHigh* = 0DC00X;
  (**Beginning of the high surrogate area.  *)
  surrogateEnd* = 0E000X;
  (**First code @emph{after} the surrogate area.  *)
  surrogateLimit* = 10000X;
  (**Starting with this code point, a Unicode character is mapped onto two
     16-bit values in UTF-16.  *)
     
TYPE
  String* = POINTER TO StringDesc;
  (**A string is a sequence of Unicode characters.  Each character holds a
     Unicode code point in the range @samp{[U+0000, U+10FFFF}.  Values from the
     surrogate code ranges @samp{[U+DC00, U+DFFF} are not allowed.

     Strings are immutable.  That is, over the whole lifetime of a string, its
     address, type, length, and content stays the same.

     A @otype{String} can hold any Oberon-2 string, but the reverse is not
     true, even if the character range is restricted: @samp{U+0000} can appear
     in a @otype{String}, but not in an Oberon-2 string.

     @emph{Note}: The predefined type name @code{STRING} is an alias for
     @otype{String}.  *)
  StringArray* = ARRAY OF String;
  StringArrayPtr* = POINTER TO StringArray;
  StringDesc = RECORD [ABSTRACT]
    (ObjectDesc)
    length-: LONGINT;
    (**Number of words points in the sequence.  For an instance of
       @otype{String8}, this is the number of characters in the string.  For
       @otype{String16}, it is the number of 16-bit words in the sequence.
       This number may differ from the number of characters in the presence of
       surrogate pairs.  *)
  END;

TYPE
  CharsLatin1* = POINTER TO ARRAY[READ_ONLY] OF CHAR;
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  *)
  CharsUTF16* = POINTER TO ARRAY[READ_ONLY] OF LONGCHAR;
  (**Note: The elements of this type should be considered read-only in
     importing modules, similar to read-only exported record fields.  *)
  
TYPE
  String8* = POINTER TO String8Desc;
  (**Concrete class for 8-bit strings.  *)
  String8Desc = RECORD
    (StringDesc)
    data: CharsLatin1;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+00FF}.  The array is of length @samp{@ofield{length}+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;
  
TYPE
  String16* = POINTER TO String16Desc;
  (**Concrete class for 32-bit strings.  *)
  String16Desc = RECORD
    (StringDesc) 
    data: CharsUTF16;
    (**Holds a sequence of Unicode code points in the range @samp{U+0000} to
       @samp{U+10FFFF}, excluding the surrogate area @samp{[U+DC00, U+DFFFF]}.
       Characters with a code point of @samp{U+10000} or higher are encoded as
       surrogate pairs.  The array is of length @samp{@ofield{length}+1}, with
       @samp{data[length]} having the value @samp{0X}.  *)
  END;

VAR
  emptyString-: String;
  (**Initialized with an instance of @otype{String8} holding the empty
     string.  *)
     
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
   @omodule{*ADT:Dictionary}.

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
    RETURN HashCode.Ptr(x);
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

PROCEDURE NewString16(source: S.ADDRESS; length: LONGINT): String16;
  VAR
    s: String16;
    d: CharsUTF16;
  BEGIN
    NEW(s);
    NEW(d, length+1);
    s. length := length;
    s. data := d;
    S.MOVE(source, S.ADR(d^), length*SIZE(LONGCHAR));
    d[length] := 0X;
    RETURN s;
  END NewString16;


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
    RETURN NewString8(S.ADR(str)+start, end-start);
  END NewLatin1Region;

PROCEDURE NewLatin1Char*(ch: CHAR): String8;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Latin-1 code point.
   @end precond  *)
  BEGIN
    RETURN NewString8(S.ADR(ch), 1);
  END NewLatin1Char;

PROCEDURE NewUTF16*(str[NO_COPY]: ARRAY OF LONGCHAR): String;
(**Create a string value from @oparam{str} without any translation.

   @precond
   The characters in @oparam{str} are Unicode 3.1 code points outside the
   surrogate areas.
   @end precond  *)
  VAR
    i, j: LONGINT;
    s: String16;
    d: CharsUTF16;
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
  END NewUTF16;

PROCEDURE NewUTF16Region*(str[NO_COPY]: ARRAY OF LONGCHAR; start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end-1]} without any
   translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   The characters in @oparam{str} are Unicode 3.1 code points outside the
   surrogate areas.
   @end precond  *)
  VAR
    i, j: LONGINT;
    s: String16;
    d: CharsUTF16;
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
  END NewUTF16Region;

PROCEDURE NewUTF16Char*(ch: LONGCHAR): String;
(**Create a string value of length 1 from @samp{ch} without any translation.

   @precond
   @oparam{ch} is a Unicode 3.1 code point outside the
   surrogate areas.
   @end precond  *)
  VAR
    s: String16;
    d: CharsUTF16;
  BEGIN
    NEW(s);
    NEW(d, 2);
    s. length := 1;
    s. data := d;
    d[0] := ch;
    d[1] := 0X;
    RETURN s;
  END NewUTF16Char;

PROCEDURE NewUCS4Char*(ch: UCS4CHAR): String;
(**Create a string value from @oparam{ch}.  The length of the string instance
   is 2 if @samp{@oparam{ch} >= @oconst{surrogateLimit}}, and 1 otherwise.

   @precond
   @oparam{ch} is a Unicode code point.
   @end precond  *)
  VAR
    s: String16;
    d: CharsUTF16;
    v: LONGINT;
  BEGIN
    IF (ch < surrogateLimit) THEN
      RETURN NewUTF16Char(SHORT(ch));
    ELSE
      NEW(s);
      NEW(d, 3);
      s. length := 2;
      s. data := d;

      v := ORD(ch)-ORD(surrogateLimit);
      d[0] := LONGCHR(ORD(surrogateLow) + v DIV 1024);
      d[1] := LONGCHR(ORD(surrogateHigh) + v MOD 1024);
      d[2] := 0X;
      RETURN s;
    END;
  END NewUCS4Char;

PROCEDURE NewUCS4Region*(str[NO_COPY]: ARRAY OF UCS4CHAR;
                         start, end: LONGINT): String;
(**Create a string value from @samp{str[start, end]} without any translation.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= LEN(@oparam{str})}.
   All characters are Unicode 3.1 code points outside the surrogate areas.
   @end precond  *)
  VAR
    s: String16;
    i, c, v: LONGINT;
    d: CharsUTF16;
  BEGIN
    c := 0;
    i := start;
    WHILE (i # end) DO
      IF (str[i] >= surrogateLimit) THEN
        INC(c, 2);
      ELSE
        INC(c);
      END;
      INC(i);
    END;

    NEW(d, c+1);
    i := 0;
    WHILE (start # end) DO
      IF (str[start] >= surrogateLimit) THEN
        v := ORD(str[start])-ORD(surrogateLimit);
        d[i] := LONGCHR(ORD(surrogateLow) + v DIV 1024);
        d[i+1] := LONGCHR(ORD(surrogateHigh) + v MOD 1024);
        INC(i, 2);
      ELSE
        d[i] := SHORT(str[start]);
        INC(i);
      END;
      INC(start);
    END;

    NEW(s);
    s.length := c;
    s.data := d;
    RETURN s;
  END NewUCS4Region;

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
    RETURN NewUCS4Region(str, 0, i);
  END NewUCS4;

PROCEDURE Concat2* (s1, s2: String): String;
(**Concatenates two strings.

   @precond
   Neither @oparam{s1} nor @oparam{s2} is @code{NIL}.
   @end precond *)
  VAR
    c8: String8;
    c32: String16;
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
                    S.ADR(c8.data^)+s1.length,
                    s2.length*SIZE(CHAR)+SIZE(CHAR));
        RETURN c8;
        
      | s2: String16 DO                  (* String8+String16 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        FOR i := 0 TO s1.length-1 DO
          c32.data[i] := s1.data[i];
        END;
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c32.data^)+s1.length*SIZE(LONGCHAR),
                    s2.length*SIZE(LONGCHAR)+SIZE(LONGCHAR));
        RETURN c32;
      END;
      
    | s1: String16 DO
      WITH s2: String8 DO
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c32.data^),
                    s1.length*SIZE(LONGCHAR));
        FOR i := 0 TO s2.length DO
          c32.data[s1.length+i] := s2.data[i];
        END;
        RETURN c32;
        
      | s2: String16 DO                  (* String16+String16 *)
        NEW(c32);
        c32.length := s1.length+s2.length;
        NEW(c32.data, s1.length+s2.length+1);
        S.MOVE(S.ADR(s1.data^),
                    S.ADR(c32.data^),
                    s1.length*SIZE(LONGCHAR));
        S.MOVE(S.ADR(s2.data^),
                    S.ADR(c32.data^)+s1.length*SIZE(LONGCHAR),
                    s2.length*SIZE(LONGCHAR)+SIZE(LONGCHAR));
        RETURN c32;
      END;
    END;
  END Concat2;

PROCEDURE (s: String) Concat*(t: String): String;
(**Concatenates strings @oparam{s} and @oparam{t}.

   @precond
   @oparam{t} is not @code{NIL}.
   @end precond *)
  BEGIN
    RETURN Concat2(s, t);
  END Concat;

PROCEDURE (s: String8) CharsLatin1*(): CharsLatin1;
(**Return a reference to the string's content.  The characters from the
   index range @samp{[0, @ofield{s.length}[} hold valid data.  The character
   at position @ofield{s.length} is @code{0X}.  *)
  BEGIN
    RETURN s.data;
  END CharsLatin1;

PROCEDURE (s: String16) CharsUTF16*(): CharsUTF16;
(**Return a reference to the string's content.  The characters from the
   index range @samp{[0, @ofield{s.length}[} hold valid data.  The character
   at position @ofield{s.length} is @code{0X}.  *)
  BEGIN
    RETURN s.data;
  END CharsUTF16;

PROCEDURE (s: String) ToString*(): String;
(**Identity operation returning @oparam{s}.  *)
  BEGIN
    RETURN s;
  END ToString;

PROCEDURE (s: String) [ABSTRACT] ToString8*(replace: CHAR): String8;
(**Identity operation returning @oparam{s} if all characters are in the range
   of @otype{String8}.  Otherwise, characters outside this range are
   substituted with @oparam{replace}.  *)
  END ToString8;

PROCEDURE (s: String8) ToString8*(replace: CHAR): String8;
  BEGIN
    RETURN s;
  END ToString8;

PROCEDURE (s: String16) ToString8*(replace: CHAR): String8;
  VAR
    data8: CharsLatin1;
    i: LONGINT;
    s8: String8;
  BEGIN
    NEW(data8, s.length+1);
    FOR i := 0 TO s.length DO
      IF (s.data[i] > 0FFX) THEN
        (* FIXME... take surrogate pairs into account *)
        data8[i] := replace;
      ELSE
        data8[i] := SHORT(s.data[i]);
      END;
    END;

    NEW(s8);
    s8.length := s.length;
    s8.data := data8;
    RETURN s8;
  END ToString8;

PROCEDURE (s: String) [ABSTRACT] ToString16*(): String16;
(**Identity operation returning @oparam{s} as an instance of @otype{String16}.  *)
  END ToString16;

PROCEDURE (s: String8) ToString16*(): String16;
  VAR
    data16: CharsUTF16;
    i: LONGINT;
    s16: String16;
  BEGIN
    NEW(data16, s.length+1);
    FOR i := 0 TO s.length DO
      data16[i] := s.data[i];
    END;
    
    NEW(s16);
    s16.length := s.length;
    s16.data := data16;
    RETURN s16;
  END ToString16;

PROCEDURE (s: String16) ToString16*(): String16;
  BEGIN
    RETURN s;
  END ToString16;

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
      | y: String16 DO
        i := 0;
        WHILE (i # s.length) & (s.data[i] = y.data[i]) DO
          INC(i);
        END;
        RETURN (i = s.length);
      END;
    END;
  END Equals;

PROCEDURE (s: String16) Equals*(y: Object): BOOLEAN;
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
      | y: String16 DO
        i := 0;
        WHILE (i # s.length) & (s.data[i] = y.data[i]) DO
          INC(i);
        END;
        RETURN (i = s.length);
      END;
    END;
  END Equals;

PROCEDURE (s: String) [ABSTRACT] EqualsIgnoreCase*(y: Object): BOOLEAN;
  END EqualsIgnoreCase;

PROCEDURE (s: String8) EqualsIgnoreCase*(y: Object): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    IF (y = NIL) OR ~(y IS String) OR (s.length # y(String).length) THEN
      RETURN FALSE;
    ELSE
      (* note: using CAP() restricts the usefulness to ASCII -- for now *)
      WITH y: String8 DO
        i := 0;
        WHILE (i # s.length) & (CAP(s.data[i]) = CAP(y.data[i])) DO
          INC(i);
        END;
        RETURN (i = s.length);
      | y: String16 DO
        i := 0;
        WHILE (i # s.length) & (CAP(s.data[i]) = CAP(y.data[i])) DO
          INC(i);
        END;
        RETURN (i = s.length);
      END;
    END;
  END EqualsIgnoreCase;

PROCEDURE (s: String16) EqualsIgnoreCase*(y: Object): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    IF (y = NIL) OR ~(y IS String) OR (s.length # y(String).length) THEN
      RETURN FALSE;
    ELSE
      (* note: using CAP() restricts the usefulness to ASCII -- for now *)
      WITH y: String8 DO
        i := 0;
        WHILE (i # s.length) & (CAP(s.data[i]) = CAP(y.data[i])) DO
          INC(i);
        END;
        RETURN (i = s.length);
      | y: String16 DO
        i := 0;
        WHILE (i # s.length) & (CAP(s.data[i]) = CAP(y.data[i])) DO
          INC(i);
        END;
        RETURN (i = s.length);
      END;
    END;
  END EqualsIgnoreCase;

PROCEDURE (s: String) [ABSTRACT] Compare*(y: Object): LONGINT;
(**Compares the two strings @oparam{s} and @oparam{y}.  The sign of the result 
   signals if @oparam{s} is less than, equal to, or greater than @oparam{y}:
   
   @table @asis
   @item @oparam{s} < @oparam{y}
   @result{} < 0
   @item @oparam{s} = @oparam{y}
   @result{} = 0
   @item @oparam{s} > @oparam{y}
   @result{} > 0
   @end table

   @precond
   @oparam{y} is not @code{NIL}.
   @end precond *)
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
    | y: String16 DO
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

PROCEDURE (s: String16) Compare*(y: Object): LONGINT;
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
    | y: String16 DO
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
  BEGIN
    RETURN HashCode.CharRegion(s.data^, 0, s.length);
  END HashCode;

PROCEDURE (s: String16) HashCode*(): Hash;
  BEGIN
    RETURN HashCode.LongCharRegion(s.data^, 0, s.length);
  END HashCode;

PROCEDURE (s: String) [ABSTRACT] CharAt*(index: LONGINT): UCS4CHAR;
(**Return the character at position @oparam{index}.

   @precond
   @samp{0 <= @oparam{index} < @ofield{s.length}}
   @end precond *)
  END CharAt;

PROCEDURE (s: String8) CharAt*(index: LONGINT): UCS4CHAR;
  BEGIN
    RETURN s.data[index];
  END CharAt;

PROCEDURE (s: String16) CharAt*(index: LONGINT): UCS4CHAR;
  VAR
    w1, w2: LONGCHAR;
  BEGIN
    w1 := s.data[index];
    IF (w1 < surrogateLow) OR (w1 >= surrogateEnd) THEN
      (* non-surrgate character *)
      RETURN w1;
    ELSE
      (* because `data' is 0X terminated and `w1' is not 0X, there is no need
         to check index+1 versus the string's length *)
      w2 := s.data[index+1];
      IF (w1 < surrogateHigh) &
         (surrogateHigh <= w2) & (w2 < surrogateEnd) THEN
        RETURN UCS4CHR((ORD(w1) MOD 1024)*1024 +
                       (ORD(w2) MOD 1024) +
                       ORD(surrogateLimit));
      ELSE  (* invalid surrogate pair *)
        RETURN w1;
      END;
    END;
  END CharAt;

PROCEDURE (s: String) [ABSTRACT] NextChar*(VAR index: LONGINT): UCS4CHAR;
(**Return the character at position @oparam{index} and increment @oparam{index}
   to point to the next character in the string.  If @oparam{index} equals
   the length of the string, then result is @samp{0X}.

   @precond
   @samp{0 <= @oparam{index} <= @ofield{s.length}}
   @end precond *)
  END NextChar;

PROCEDURE (s: String8) NextChar*(VAR index: LONGINT): UCS4CHAR;
  VAR
    c: CHAR;
  BEGIN
    c := s.data[index];
    INC(index);
    RETURN c;
  END NextChar;

PROCEDURE (s: String16) NextChar*(VAR index: LONGINT): UCS4CHAR;
  VAR
    w1, w2: LONGCHAR;
  BEGIN
    w1 := s.data[index];
    INC(index);
    IF (w1 < surrogateLow) OR (w1 >= surrogateEnd) THEN
      (* non-surrogate character *)
      RETURN w1;
    ELSE
      (* because `data' is 0X terminated and `w1' is not 0X, there is no need
         to check index versus the string's length *)
      w2 := s.data[index];
      IF (w1 < surrogateHigh) &
         (surrogateHigh <= w2) & (w2 < surrogateEnd) THEN
        INC(index);
        RETURN UCS4CHR((ORD(w1) MOD 1024)*1024 +
                       (ORD(w2) MOD 1024)+
                       ORD(surrogateLimit));
      ELSE  (* invalid surrogate pair *)
        RETURN w1;
      END;
    END;
  END NextChar;

PROCEDURE (s: String) [ABSTRACT] Substring* (start, end: LONGINT): String;
(**Return the substring of @oparam{s} starting at @oparam{start} (inclusive)
   and ending at @oparam{end} (exclusive).  The length of the result is
   @samp{end-start}.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{end} <= @ofield{s.length}}
   @end precond *)
  END Substring;

PROCEDURE (s: String8) Substring* (start, end: LONGINT): String8;
  BEGIN
    RETURN NewString8(S.ADR(s.data^)+start, end-start);
  END Substring;

PROCEDURE (s: String16) Substring* (start, end: LONGINT): String16;
  BEGIN
    RETURN NewString16(S.ADR(s.data^)+start*SIZE(LONGCHAR), end-start);
  END Substring;


PROCEDURE (s: String) [ABSTRACT] Trim*(): String;
(**Return the substring beginning with the first character of @oparam{s} and
   ending with the last character of @oparam{s} with a code greater than space
   (@samp{20X}).  If @oparam{s} contains no such characters, then result is the
   empty string.  *)
  END Trim;

PROCEDURE (s: String8) Trim*(): String8;
  VAR
    a, b: LONGINT;
  BEGIN
    a := 0;
    WHILE (a # s.length) & (s.data[a] <= " ") DO
      INC(a);
    END;
    b := s.length;
    WHILE (b # a) & (s.data[b-1] <= " ") DO
      DEC(b);
    END;
    RETURN NewString8(S.ADR(s.data^)+a, b-a);
  END Trim;

PROCEDURE (s: String16) Trim*(): String16;
  VAR
    a, b: LONGINT;
  BEGIN
    a := 0;
    WHILE (a # s.length) & (s.data[a] <= " ") DO
      INC(a);
    END;
    b := s.length;
    WHILE (b # a) & (s.data[b-1] <= " ") DO
      DEC(b);
    END;
    RETURN NewString16(S.ADR(s.data^)+a*SIZE(LONGCHAR), b-a);
  END Trim;


PROCEDURE (s: String) [ABSTRACT] IndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
(**Return the index of the first character matching @oparam{char}.  Search
   starts at @oparam{pos} and progresses to the end of the string @oparam{s}.
   If no matching character is found, result is @samp{-1}.
   
   @precond
   @samp{0 <= @oparam{pos} <= @ofield{s.length}}
   @end precond *)
  END IndexOf;

PROCEDURE (s: String8) IndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
  VAR
    endpos: LONGINT;
  BEGIN
    endpos := s.length;
    WHILE (pos # endpos) DO
      IF (s.data[pos] = char) THEN
        RETURN pos;
      END;
      INC (pos);
    END;
    RETURN -1
  END IndexOf;

PROCEDURE (s: String16) IndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
  VAR
    endpos, v: LONGINT;
    w1, w2: LONGCHAR;
  BEGIN
    IF (char < surrogateLimit) THEN
      endpos := s.length;
      WHILE (pos # endpos) DO
        IF (s.data[pos] = char) THEN
          RETURN pos;
        END;
        INC(pos);
      END;
      RETURN -1;
    ELSE
      v := ORD(char)-ORD(surrogateLimit);
      w1 := LONGCHR(ORD(surrogateLow) + v DIV 1024);
      w2 := LONGCHR(ORD(surrogateHigh) + v MOD 1024);
      
      endpos := s.length;
      WHILE (pos # endpos) DO
        IF (s.data[pos] = w1) & (s.data[pos+1] = w2) THEN
          (* because `data' is 0X terminated, there is no need to check
             pos+1 versus the string's length *)
          RETURN pos;
        END;
        INC(pos);
      END;
      RETURN -1;
    END;
  END IndexOf;


PROCEDURE (s: String) [ABSTRACT] LastIndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
(**Return the index of the last character matching @oparam{char}.  Search
   starts with the character before @oparam{pos} and progresses to the
   beginning of the string @oparam{s}.  If no matching character is found,
   result is @samp{-1}.

   @precond
   @samp{0 <= @oparam{pos} <= @ofield{s.length}}
   @end precond  *)
  END LastIndexOf;

PROCEDURE (s: String8) LastIndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
  BEGIN
    WHILE (pos > 0) DO
      DEC(pos);
      IF (s.data[pos] = char) THEN
        RETURN pos;
      END;
    END;
    RETURN -1;
  END LastIndexOf;

PROCEDURE (s: String16) LastIndexOf*(char: UCS4CHAR; pos: LONGINT): LONGINT;
  VAR
    v: LONGINT;
    w1, w2: LONGCHAR;
  BEGIN
    IF (char < surrogateLimit) THEN
      WHILE (pos > 0) DO
        DEC(pos);
        IF (s.data[pos] = char) THEN
          RETURN pos;
        END;
      END;
      RETURN -1;
    ELSE
      v := ORD(char)-ORD(surrogateLimit);
      w1 := LONGCHR(ORD(surrogateLow) + v DIV 1024);
      w2 := LONGCHR(ORD(surrogateHigh) + v MOD 1024);
      
      WHILE (pos > 0) DO
        DEC(pos);
        IF (s.data[pos] = w1) & (s.data[pos+1] = w2) THEN
          (* because `data' is 0X terminated and `data[pos]' is not 0X, there
             is no need to check pos+1 versus the string's length *)
          RETURN pos;
        END;
      END;
      RETURN -1;
    END;
  END LastIndexOf;


PROCEDURE (s: String) EndsWith*(suffix: String): BOOLEAN;
(**Return @code{TRUE} is the last characters in @oparam{s} equal
   @oparam{suffix}.  Result is @code{FALSE} if @samp{@ofield{s.length} <
   @ofield{suffix.length}}.

   @precond
   @samp{@oparam{suffix} # @code{NIL}}
   @end precond  *)
  VAR
    e: String;
  BEGIN
    IF (s.length >= suffix.length) THEN
      e := s.Substring(s.length-suffix.length, s.length);
      RETURN e.Equals(suffix);
    ELSE
      RETURN FALSE;
    END;
  END EndsWith;

PROCEDURE (s: String) StartsWith*(prefix: String): BOOLEAN;
(**Return @code{TRUE} is the first characters in @oparam{s} equal
   @oparam{prefix}.  Result is @code{FALSE} if @samp{@ofield{s.length} <
   @ofield{prefix.length}}.

   @precond
   @samp{@oparam{prefix} # @code{NIL}}
   @end precond  *)
  VAR
    e: String;
  BEGIN
    IF (s.length >= prefix.length) THEN
      e := s.Substring(0, prefix.length);
      RETURN e.Equals(prefix);
    ELSE
      RETURN FALSE;
    END;
  END StartsWith;

BEGIN
  emptyString := NewLatin1("");
END Object.
