MODULE Language:Real [OOC_EXTENSIONS];

IMPORT
  ADT:Object, ADT:String, L := Language, LRealStr;

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

PROCEDURE NewLReal* (val : LONGREAL) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @ovar{type}. *)
VAR 
  v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := val;
  RETURN v;
END NewLReal;

PROCEDURE NewReal* (val : REAL) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @ovar{type}. *)
VAR 
  v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := val;
  RETURN v;
END NewReal;

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
  BEGIN
    RETURN ENTIER(v.value);
  END HashCode;

PROCEDURE (v : Value) ToString* () : String.String;
VAR 
  str: ARRAY 128 OF CHAR;	(* FIXME! *)
BEGIN
  LRealStr.RealToFloat(v.value, 0, str);
  RETURN String.New (str)
END ToString;

PROCEDURE (v : Value) ToLReal*() : LONGREAL;
BEGIN
  RETURN v.value;
END ToLReal;

PROCEDURE (v : Value) ToReal*() : REAL;
BEGIN
  RETURN SHORT(v.value);
END ToReal;

PROCEDURE (v : Value) Sum* (right : Value) : Value;
BEGIN
  RETURN NewLReal(v.value + right.value);
END Sum;

PROCEDURE (v : Value) Difference* (right : Value) : Value;
BEGIN
  RETURN NewLReal(v.value - right.value);
END Difference;

PROCEDURE (v : Value) Product* (right : Value) : Value;
BEGIN
  RETURN NewLReal(v.value * right.value);
END Product;

PROCEDURE (v : Value) Quotient* (right : Value) : Value;
BEGIN
  RETURN NewLReal(v.value / right.value);
END Quotient;

PROCEDURE (v : Value) Compare* (right : Value) : LONGINT;
BEGIN
  IF v.value = right.value THEN
    RETURN 0;
  ELSIF v.value < right.value THEN
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
  RETURN NewLReal(-v.value);
END Negate;

PROCEDURE (t : Type) Value* (val : LONGREAL) : Value;
BEGIN
  RETURN NewLReal(val);
END Value;

PROCEDURE (t : Type) ValueOf* (s : ARRAY OF CHAR) : Value;
VAR 
  real : LONGREAL;
  res : LRealStr.ConvResults;
BEGIN
  LRealStr.StrToReal(s, real, res);
  IF res = LRealStr.strAllRight THEN
    RETURN NewLReal(real);
  ELSE
    RETURN NIL;
  END;
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName
END ToString;

BEGIN
  zero := NewLReal(0.0);
  NEW(type);
  L.InitType(type);
  typeName := String.New("Real");
END Language:Real.

