MODULE Language:Real [OOC_EXTENSIONS];

IMPORT
  ADT:Object, ADT:String, L := Language, RealStr, LRealStr, SYSTEM;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value : LONGREAL;
  END;

  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
  END;

VAR
  type- : Type;
  typeName : String.String;

  zero- : Value;

PROCEDURE New* (val : LONGREAL) : Value;
(** Return a @otype{Value} for real @oparam{val}. *)
VAR 
  v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := val;
  RETURN v;
END New;

PROCEDURE (v: Value) Store* (w: Object.Writer);
  BEGIN
    v. Store^ (w);
    w. WriteLReal(v.value);
  END Store;

PROCEDURE (v: Value) Load* (r: Object.Reader);
  BEGIN
    v. Load^ (r);
    r. ReadLReal(v.value);
  END Load;

PROCEDURE (v: Value) Equals* (y: Object.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Value) & (v.value = y(Value).value);
  END Equals;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
(* Compute hash code by XORing bits in the LONGREAL's binary representation. *)
CONST 
  size = SIZE(LONGREAL) DIV SIZE(SET);
VAR
  a : ARRAY size OF SET;
  i : LONGINT; hash : SET;
BEGIN
  SYSTEM.MOVE(SYSTEM.ADR(v.value), SYSTEM.ADR(a), size * SIZE(LONGINT));
  hash := {};
  FOR i := 0 TO size-1 DO
    hash := hash / a[i];
  END;
  RETURN SYSTEM.VAL(LONGINT, hash);
END HashCode;

PROCEDURE (v : Value) ToString* () : String.String;
VAR 
  str: ARRAY 128 OF CHAR;	(* FIXME! *)
BEGIN
  LRealStr.RealToFloat(v.value, 17, str);
  RETURN String.New (str)
END ToString;

PROCEDURE (v : Value) ToReal*() : LONGREAL;
BEGIN
  RETURN v.value;
END ToReal;

PROCEDURE (v : Value) Sum* (right : Value) : Value;
BEGIN
  RETURN New(v.value + right.value);
END Sum;

PROCEDURE (v : Value) Difference* (right : Value) : Value;
BEGIN
  RETURN New(v.value - right.value);
END Difference;

PROCEDURE (v : Value) Product* (right : Value) : Value;
BEGIN
  RETURN New(v.value * right.value);
END Product;

PROCEDURE (v : Value) Quotient* (right : Value) : Value;
BEGIN
  RETURN New(v.value / right.value);
END Quotient;

PROCEDURE (v : Value) Compare* (right : Object.Object) : LONGINT;
BEGIN
  IF v.value = right(Value).value THEN
    RETURN 0;
  ELSIF v.value < right(Value).value THEN
    RETURN -1;
  ELSE
    RETURN 1;
  END;
END Compare;

PROCEDURE (v : Value) Sign* () : LONGINT;
BEGIN
  RETURN v.Compare(zero);
END Sign;

PROCEDURE (v : Value) Negate* () : Value;
BEGIN
  RETURN New(-v.value);
END Negate;

PROCEDURE (t : Type) Value* (val : LONGREAL) : Value;
BEGIN
  RETURN New(val);
END Value;

PROCEDURE (t : Type) ValueOf* (s : ARRAY OF CHAR) : Value;
VAR 
  real : LONGREAL;
  res : LRealStr.ConvResults;
BEGIN
  LRealStr.StrToReal(s, real, res);
  IF res = LRealStr.strAllRight THEN
    RETURN New(real);
  ELSE
    RETURN NIL;
  END;
END ValueOf;

PROCEDURE (t : Type) ValueOfLiteral* (s : ARRAY OF CHAR) : Value;
(**Like @oproc{Type.ValueOf}, but the character of the exponent decides
   whether the value should be treated as a @code{REAL} or @code{LONGREAL}
   literal.  *)
VAR 
  real : REAL;
  longreal : LONGREAL;
  res : LRealStr.ConvResults;
  v: Value;
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
      v := New(longreal);
    END;
  ELSE
    RealStr.StrToReal(s, real, res);
    IF res = LRealStr.strAllRight THEN
      v := New(real);
    END;
  END;
  RETURN v;
END ValueOfLiteral;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName
END ToString;

BEGIN
  NEW(type);
  L.InitType(type);
  typeName := String.New("Real");

  zero := New(0.0);
END Language:Real.

