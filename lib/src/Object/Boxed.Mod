MODULE Object:Boxed;

(**This module provides ``boxed'' representations for the predefined types
   of Oberon-2.  For every predefined type, there is a corresponding
   class definition.  (Ok, that is the theory.  Not all types are implemented.
   If you need one, add it.  And do not forget to send me the patch!)

   All boxed values are derived from the class @otype{Object}.  Instances are
   immutable.  That is, they take on a value when created and never change
   it during their lifetime.  *)

IMPORT
  SYSTEM, IntStr, RealStr, LRealStr, Strings,
  Obj := Object, ADT:Storable, ADT:StringBuffer;

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
  trueString, falseString: Obj.String;
  
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
    value-: Obj.String;
  END;

VAR
  emptyString: String;


(* Object
   ------------------------------------------------------------------------ *)

PROCEDURE (v: Object) [ABSTRACT] ToString*(): Obj.String;
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

PROCEDURE (v: Boolean) Equals*(y: Obj.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Boolean) & (v.value = y(Boolean).value)
  END Equals;
  
PROCEDURE (v: Boolean) Cmp*(y: Obj.Object): LONGINT;
  BEGIN
    ASSERT (FALSE);
    RETURN -1;
  END Cmp;
  
PROCEDURE (v: Boolean) HashCode*(): Obj.Hash;
  BEGIN
    IF v.value THEN
      RETURN 1
    ELSE
      RETURN 2
    END;
  END HashCode;
  
PROCEDURE (v: Boolean) ToString*(): Obj.String;
  BEGIN
    IF v.value THEN
      RETURN trueString;
    ELSE
      RETURN falseString;
    END;
  END ToString;

PROCEDURE (v: Boolean) Store*(w: Storable.Writer);
  BEGIN
    IF v.value THEN
      w.WriteSInt(1);
    ELSE
      w.WriteSInt(0);
    END;
  END Store;

PROCEDURE (v: Boolean) Load*(r: Storable.Reader);
  VAR
    si: SHORTINT;
  BEGIN
    r.ReadSInt(si);
    v.value := (si # 0);
  END Load;

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

PROCEDURE (v: LongReal) Store*(w: Storable.Writer);
  BEGIN
    w. WriteLReal(v.value);
  END Store;

PROCEDURE (v: LongReal) Load*(r: Storable.Reader);
  BEGIN
    r. ReadLReal(v.value);
  END Load;

PROCEDURE (v: LongReal) Equals*(y: Obj.Object): BOOLEAN;
  BEGIN
    RETURN (y IS LongReal) & (v.value = y(LongReal).value);
  END Equals;
  
PROCEDURE (v: LongReal) HashCode*(): Obj.Hash;
(* Compute hash code by XORing bits in the LONGREAL's binary representation. *)
  CONST 
    size = SIZE(LONGREAL) DIV SIZE(SET);
  VAR
    a: ARRAY size OF SET;
    i: LONGINT; hash: SET;
  BEGIN
    SYSTEM.MOVE(SYSTEM.ADR(v.value), SYSTEM.ADR(a), size * SIZE(LONGINT));
    hash := {};
    FOR i := 0 TO size-1 DO
      hash := hash / a[i];
    END;
    RETURN SYSTEM.VAL(Obj.Hash, hash);
  END HashCode;

PROCEDURE (v: LongReal) ToString*(): Obj.String;
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
    ASSERT (FALSE);
    RETURN -1;
  END Cmp;
  
PROCEDURE (v: Set) HashCode*(): Obj.Hash;
  BEGIN
    RETURN SYSTEM.VAL(Obj.Hash, v.value);
  END HashCode;

PROCEDURE SetToString(val: SET; VAR str: ARRAY OF CHAR);
  VAR
    begin, i: SHORTINT;
    comma: BOOLEAN;
    num: ARRAY 8 OF CHAR;
  BEGIN
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
  END SetToString;

PROCEDURE (v: Set) ToString*(): Obj.String;
  VAR
    str: ARRAY 32*4+3 OF CHAR;
  BEGIN
    SetToString(v.value, str);
    RETURN Obj.NewLatin1(str);
  END ToString;

PROCEDURE (v: Set) Store*(w: Storable.Writer);
  BEGIN
    w.WriteSet(v.value);
  END Store;

PROCEDURE (v: Set) Load*(r: Storable.Reader);
  BEGIN
    r.ReadSet(v.value);
  END Load;

(* String
   ------------------------------------------------------------------------ *)

PROCEDURE NewString*(value: Obj.String): String;
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
    RETURN v. value. HashCode();
  END HashCode;
  
PROCEDURE (v: String) ToString*(): Obj.String;
  VAR
    i: LONGINT;
    delim: ARRAY 2 OF CHAR;
    sb: StringBuffer.StringBuffer;
    chars: Obj.CharsLatin1;
  BEGIN
    i := v. value. IndexOf ('"', 0);
    IF (i < 0) THEN
      delim := '"'
    ELSE
      delim := "'"
    END;
    sb := StringBuffer.New (delim);
    chars := v.value(Obj.String8).CharsLatin1();  (* FIXME... *)
    sb. AppendString (chars^);
    sb. AppendString (delim);
    RETURN sb. ToString()
  END ToString;

PROCEDURE (v: String) Store*(w: Storable.Writer);
  BEGIN
    w.WriteStr(v.value);
  END Store;

PROCEDURE (v: String) Load*(r: Storable.Reader);
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
