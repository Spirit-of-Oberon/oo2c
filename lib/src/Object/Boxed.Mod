(*	$Id: Boxed.Mod,v 1.17 2004/06/04 08:54:27 mva Exp $	*)
MODULE Object:Boxed;
(*  Implements object representations for predefined types.
    Copyright (C) 2002-2004  Michael van Acken

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

(**This module provides ``boxed'' representations for the predefined types
   of Oberon-2.  For every predefined type, there is a corresponding
   class definition.  (Ok, that is the theory.  Not all types are implemented.
   If you need one, add it.  And do not forget to send me the patch!)

   All boxed values are derived from the class @otype{Object}.  Instances are
   immutable.  That is, they take on a value when created and never change
   it during their lifetime.  *)

IMPORT
  SYSTEM, IntStr, RealStr, LRealStr, Strings,
  HashCode, Obj := Object, IO, ADT:Storable, ADT:StringBuffer;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD [ABSTRACT]
    (Storable.ObjectDesc)
    (**This is the base type for all boxed versions of Oberon-2 values.  *)
  END;
  ParseFct* = PROCEDURE(str: ARRAY OF CHAR): Object;

TYPE
  Boolean* = POINTER TO BooleanDesc;
  BooleanDesc* = RECORD
    (ObjectDesc)
    value-: BOOLEAN;
  END;

VAR
  true-, false-: Boolean;
  trueString, falseString: STRING;
  
TYPE
  LongInt* = POINTER TO LongIntDesc;
  LongIntDesc* = RECORD
    (ObjectDesc)
    value-: LONGINT;
  END;
  
VAR
  zeroLongInt-: LongInt;

TYPE
  LongReal* = POINTER TO LongRealDesc;
  LongRealDesc* = RECORD
    (ObjectDesc)
    value-: LONGREAL;
  END;
  
VAR
  zeroLongReal-: LongReal;

TYPE
  Set* = POINTER TO SetDesc;
  SetDesc* = RECORD
    (ObjectDesc)
    value-: SET;
  END;

TYPE
  String* = POINTER TO StringDesc;
  StringDesc* = RECORD
    (ObjectDesc)
    value-: STRING;
  END;

VAR
  emptyString: String;


(* Object
   ------------------------------------------------------------------------ *)

PROCEDURE (v: Object) [ABSTRACT] ToString*(): STRING;
  END ToString;

PROCEDURE (v: Object) [ABSTRACT] Cmp*(y: Obj.Object): LONGINT;
  END Cmp;

(* Boolean
   ------------------------------------------------------------------------ *)

PROCEDURE NewBoolean*(value: BOOLEAN): Boolean;
  VAR
    v: Boolean;
  BEGIN
    NEW(v);
    v.value := value;
    RETURN v;
  END NewBoolean;

PROCEDURE ParseBoolean*(str[NO_COPY]: ARRAY OF CHAR): Boolean;
  BEGIN
    IF (str = "TRUE") THEN
      RETURN true;
    ELSIF (str = "FALSE") THEN
      RETURN false;
    ELSE
      RETURN NIL;
    END;
  END ParseBoolean;

PROCEDURE BooleanToString*(value: BOOLEAN): STRING;
(**Equivalent to calling @oproc{NewBoolean} with @oparam{value}, and then
   @oproc{Object.ToString} on the result.  *)
  VAR
    v: Boolean;
  BEGIN
    v := NewBoolean(value);
    RETURN v.ToString();
  END BooleanToString;

PROCEDURE (v: Boolean) Equals*(y: Obj.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Boolean) & (v.value = y(Boolean).value)
  END Equals;
  
PROCEDURE (v: Boolean) Cmp*(y: Obj.Object): LONGINT;
  BEGIN
<*PUSH; Assertions:=TRUE*>
    ASSERT (FALSE);
<*POP*>
  END Cmp;
  
PROCEDURE (v: Boolean) HashCode*(): Obj.Hash;
  BEGIN
    RETURN HashCode.Boolean(v.value);
  END HashCode;
  
PROCEDURE (v: Boolean) ToString*(): STRING;
  BEGIN
    IF v.value THEN
      RETURN trueString;
    ELSE
      RETURN falseString;
    END;
  END ToString;

PROCEDURE (v: Boolean) Store*(w: Storable.Writer) RAISES IO.Error;
  BEGIN
    IF v.value THEN
      w.WriteSInt(1);
    ELSE
      w.WriteSInt(0);
    END;
  END Store;

PROCEDURE (v: Boolean) Load*(r: Storable.Reader) RAISES IO.Error;
  VAR
    si: SHORTINT;
  BEGIN
    r.ReadSInt(si);
    v.value := (si # 0);
  END Load;

(* LongInt
   ------------------------------------------------------------------------ *)

PROCEDURE NewLongInt*(val: LONGINT): LongInt;
(** Return a @otype{LongInt} for @oparam{val}. *)
  VAR 
    v: LongInt;
  BEGIN
    NEW(v);
    v.value := val;
    RETURN v;
  END NewLongInt;

PROCEDURE ParseLongInt*(s: ARRAY OF CHAR): LongInt;
  VAR 
    int: LONGINT;
    res: IntStr.ConvResults;
  BEGIN
    IntStr.StrToInt(s, int, res);
    IF res = IntStr.strAllRight THEN
      RETURN NewLongInt(int);
    ELSE
      RETURN NIL;
    END;
  END ParseLongInt;

PROCEDURE IntToString*(value: LONGINT): STRING;
(**Equivalent to calling @oproc{NewLongInt} with @oparam{value}, and then
   @oproc{Object.ToString} on the result.  *)
  VAR
    v: LongInt;
  BEGIN
    v := NewLongInt(value);
    RETURN v.ToString();
  END IntToString;

PROCEDURE (v: LongInt) Store*(w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w. WriteLInt(v.value);
  END Store;

PROCEDURE (v: LongInt) Load*(r: Storable.Reader) RAISES IO.Error;
  BEGIN
    r. ReadLInt(v.value);
  END Load;

PROCEDURE (v: LongInt) Equals*(y: Obj.Object): BOOLEAN;
  BEGIN
    RETURN (y IS LongInt) & (v.value = y(LongInt).value);
  END Equals;
  
PROCEDURE (v: LongInt) HashCode*(): Obj.Hash;
  BEGIN
    RETURN v.value;
  END HashCode;

PROCEDURE (v: LongInt) ToString*(): STRING;
  VAR 
    str: ARRAY 10 OF CHAR;
  BEGIN
    IntStr.IntToStr(v.value, str);
    RETURN Obj.NewLatin1(str);
  END ToString;

PROCEDURE (v: LongInt) Add*(right: LongInt): LongInt;
  BEGIN
    RETURN NewLongInt(v.value + right.value);
  END Add;

PROCEDURE (v: LongInt) Sub*(right: LongInt): LongInt;
  BEGIN
    RETURN NewLongInt(v.value - right.value);
  END Sub;

PROCEDURE (v: LongInt) Mul*(right: LongInt): LongInt;
  BEGIN
    RETURN NewLongInt(v.value * right.value);
  END Mul;

PROCEDURE (v: LongInt) Div*(right: LongInt): LongInt;
  BEGIN
    RETURN NewLongInt(v.value DIV right.value);
  END Div;

PROCEDURE (v: LongInt) Mod*(right: LongInt): LongInt;
  BEGIN
    RETURN NewLongInt(v.value MOD right.value);
  END Mod;

PROCEDURE (v: LongInt) Cmp*(right: Obj.Object): LONGINT;
  BEGIN
    IF v.value = right(LongInt).value THEN
      RETURN 0;
    ELSIF v.value < right(LongInt).value THEN
      RETURN -1;
    ELSE
      RETURN 1;
    END;
  END Cmp;

PROCEDURE (v: LongInt) Sign*(): LONGINT;
  BEGIN
    RETURN v.Cmp(zeroLongInt);
  END Sign;

PROCEDURE (v: LongInt) Neg*(): LongInt;
  BEGIN
    RETURN NewLongInt(-v.value);
  END Neg;

(* LongReal
   ------------------------------------------------------------------------ *)

PROCEDURE NewLongReal*(val: LONGREAL): LongReal;
(** Return a @otype{LongReal} for @oparam{val}. *)
  VAR 
    v: LongReal;
  BEGIN
    NEW(v);
    v.value := val;
    RETURN v;
  END NewLongReal;

PROCEDURE ParseLongReal*(s: ARRAY OF CHAR): LongReal;
  VAR 
    real: LONGREAL;
    res: LRealStr.ConvResults;
  BEGIN
    LRealStr.StrToReal(s, real, res);
    IF res = LRealStr.strAllRight THEN
      RETURN NewLongReal(real);
    ELSE
      RETURN NIL;
    END;
  END ParseLongReal;

PROCEDURE LongRealToString*(value: LONGREAL): STRING;
(**Equivalent to calling @oproc{NewLongReal} with @oparam{value}, and then
   @oproc{Object.ToString} on the result.  *)
  VAR
    v: LongReal;
  BEGIN
    v := NewLongReal(value);
    RETURN v.ToString();
  END LongRealToString;

PROCEDURE ParseLongRealLiteral*(s: ARRAY OF CHAR): LongReal;
(**Like @oproc{ParseLongReal}, but the character of the exponent decides
   whether the value should be treated as a @code{REAL} or @code{LONGREAL}
   literal.  *)
  VAR 
    real: REAL;
    longreal: LONGREAL;
    res: LRealStr.ConvResults;
    v: LongReal;
    i: LONGINT;
  BEGIN
    (* check if the number has a "D" exponent, which would make it LONGREAL;
       this influences the rounding for the resulting real value *)
    i := 0;
    WHILE (s[i] # 0X) & (s[i] # "D") DO
      INC (i);
    END;
    
    v := NIL;
    IF (s[i] = "D") THEN
      s[i] := "E";
      LRealStr.StrToReal(s, longreal, res);
      IF res = LRealStr.strAllRight THEN
        v := NewLongReal(longreal);
      END;
    ELSE
      RealStr.StrToReal(s, real, res);
      IF res = LRealStr.strAllRight THEN
        v := NewLongReal(real);
      END;
    END;
    RETURN v;
  END ParseLongRealLiteral;

PROCEDURE (v: LongReal) Store*(w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w. WriteLReal(v.value);
  END Store;

PROCEDURE (v: LongReal) Load*(r: Storable.Reader) RAISES IO.Error;
  BEGIN
    r. ReadLReal(v.value);
  END Load;

PROCEDURE (v: LongReal) Equals*(y: Obj.Object): BOOLEAN;
  BEGIN
    RETURN (y IS LongReal) & (v.value = y(LongReal).value);
  END Equals;
  
PROCEDURE (v: LongReal) HashCode*(): Obj.Hash;
  BEGIN
    RETURN HashCode.LongReal(v.value);
  END HashCode;

PROCEDURE (v: LongReal) ToString*(): STRING;
  VAR 
    str: ARRAY 128 OF CHAR;
  BEGIN
    LRealStr.RealToFloat(v.value, 17, str);
    RETURN Obj.NewLatin1(str);
  END ToString;

PROCEDURE (v: LongReal) ToLongReal*(): LONGREAL;
  BEGIN
    RETURN v.value;
  END ToLongReal;

PROCEDURE (v: LongReal) Add*(right: LongReal): LongReal;
  BEGIN
    RETURN NewLongReal(v.value + right.value);
  END Add;

PROCEDURE (v: LongReal) Sub*(right: LongReal): LongReal;
  BEGIN
    RETURN NewLongReal(v.value - right.value);
  END Sub;

PROCEDURE (v: LongReal) Mul*(right: LongReal): LongReal;
  BEGIN
    RETURN NewLongReal(v.value * right.value);
  END Mul;

PROCEDURE (v: LongReal) Div*(right: LongReal): LongReal;
  BEGIN
    RETURN NewLongReal(v.value / right.value);
  END Div;

PROCEDURE (v: LongReal) Cmp*(right: Obj.Object): LONGINT;
  BEGIN
    IF v.value = right(LongReal).value THEN
      RETURN 0;
    ELSIF v.value < right(LongReal).value THEN
      RETURN -1;
    ELSE
      RETURN 1;
    END;
  END Cmp;

PROCEDURE (v: LongReal) Sign*(): LONGINT;
  BEGIN
    (* If I remember correctly, IEEE 754's has both a positive and a negative
       zero.  This means that the sign() function never return 0.  CHECKME...*)
    RETURN v.Cmp(zeroLongReal);
  END Sign;

PROCEDURE (v: LongReal) Neg*(): LongReal;
  BEGIN
    RETURN NewLongReal(-v.value);
  END Neg;

(* Set
   ------------------------------------------------------------------------ *)

PROCEDURE NewSet*(value: SET): Set;
  VAR v: Set;
  BEGIN
    NEW(v);
    v.value := value;
    RETURN v;
  END NewSet;

PROCEDURE SetToString*(value: SET): STRING;
(**Equivalent to calling @oproc{NewSet} with @oparam{value}, and then
   @oproc{Object.ToString} on the result.  *)
  VAR
    v: Set;
  BEGIN
    v := NewSet(value);
    RETURN v.ToString();
  END SetToString;

PROCEDURE (v: Set) Equals*(y: Obj.Object): BOOLEAN;
BEGIN
  WITH y: Set DO
    RETURN y.value = v.value
  ELSE
    RETURN FALSE;
  END;
END Equals;

PROCEDURE (v: Set) Cmp*(y: Obj.Object): LONGINT;
  BEGIN
<*PUSH; Assertions:=TRUE*>
    ASSERT (FALSE);
<*POP*>
  END Cmp;
  
PROCEDURE (v: Set) HashCode*(): Obj.Hash;
  BEGIN
    RETURN HashCode.Set(v.value);
  END HashCode;

PROCEDURE (v: Set) ToString*(): STRING;
  VAR
    str: ARRAY 32*4+3 OF CHAR;
    val: SET;
    begin, i: SHORTINT;
    comma: BOOLEAN;
    num: ARRAY 8 OF CHAR;
  BEGIN
    val := v.value;
    
    COPY("{", str);
    comma := FALSE;
    i := MIN(SET);
    WHILE i <= MAX(SET) DO
      IF i IN val THEN
        begin := i;
        WHILE (i < MAX(SET)) & ((i+1) IN val) DO INC(i) END;
        IF comma THEN 
          Strings.Append(",", str)
        END;
        comma := TRUE;
        IntStr.IntToStr(begin, num);
        Strings.Append(num, str);
        IF begin < i THEN
          IF i = begin + 1 THEN
            Strings.Append(",", str);
          ELSE
            Strings.Append("..", str);
          END;
          IntStr.IntToStr(i, num);
          Strings.Append(num, str);
        END;
      END;
      INC(i)
    END; 
    Strings.Append("}", str);
    
    RETURN Obj.NewLatin1(str);
  END ToString;

PROCEDURE (v: Set) ToLongInt*(): LONGINT;
  BEGIN
    RETURN SYSTEM.VAL(LONGINT, v.value);
  END ToLongInt;

PROCEDURE (v: Set) Store*(w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w.WriteSet(v.value);
  END Store;

PROCEDURE (v: Set) Load*(r: Storable.Reader) RAISES IO.Error;
  BEGIN
    r.ReadSet(v.value);
  END Load;

(* String
   ------------------------------------------------------------------------ *)

PROCEDURE NewString*(value: STRING): String;
  VAR
    v: String;
  BEGIN
    IF (value. length = 0) THEN
      RETURN emptyString;
    ELSE
      NEW(v);
      v.value := value;
      RETURN v;
    END
  END NewString;

PROCEDURE (v: String) Cmp*(str: Obj.Object): LONGINT;
  BEGIN
    RETURN v.value.Compare(str(String).value);
  END Cmp;

PROCEDURE (v: String) Equals*(y: Obj.Object): BOOLEAN;
  BEGIN
    RETURN (y IS String) & v. value. Equals(y(String). value)
  END Equals;
  
PROCEDURE (v: String) HashCode*(): Obj.Hash;
  BEGIN
    RETURN v.value.HashCode();
  END HashCode;
  
PROCEDURE (v: String) ToString*(): STRING;
  VAR
    i: LONGINT;
    delim: ARRAY 2 OF CHAR;
    sb: StringBuffer.StringBuffer;
  BEGIN
    i := v. value. IndexOf ('"', 0);
    IF (i < 0) THEN
      delim := '"'
    ELSE
      delim := "'"
    END;
    sb := StringBuffer.New(Obj.NewLatin1(delim));
    sb.Append(v.value);
    sb.AppendLatin1(delim);
    RETURN sb. ToString()
  END ToString;

PROCEDURE (v: String) Store*(w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w.WriteStr(v.value);
  END Store;

PROCEDURE (v: String) Load*(r: Storable.Reader) RAISES IO.Error;
  BEGIN
    r.ReadStr(v.value);
  END Load;

PROCEDURE ParseString*(str[NO_COPY]: ARRAY OF CHAR): String;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (str[i] # 0X) DO
      INC (i)
    END;
    IF (i >= 2) & (str[0] = str[i-1]) & ((str[0] = '"') OR (str[0] = "'")) THEN
      RETURN NewString(Obj.NewLatin1Region(str, 1, i-1));
    ELSE  (* string is not delimited properly *)
      RETURN NIL;
    END
  END ParseString;

BEGIN
  true := NewBoolean(TRUE); trueString := Obj.NewLatin1("TRUE");
  false := NewBoolean(FALSE); falseString := Obj.NewLatin1("FALSE");
  
  zeroLongReal := NewLongReal(0.0);

  NEW(emptyString);
  emptyString.value := Obj.NewLatin1("");
END Object:Boxed.
