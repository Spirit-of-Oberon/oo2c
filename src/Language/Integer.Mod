MODULE Language:Integer [OOC_EXTENSIONS];

IMPORT
  Integers, ADT:Object, ADT:String, L := Language;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value : Integers.Integer;
  END;

  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
  END;

VAR
  type- : Type;
  typeName : String.String;

  minus1, zero-, one : Value;

PROCEDURE NewInt (val : Integers.Integer) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @ovar{type}. *)
VAR 
  v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := val;
  RETURN v;
END NewInt;

PROCEDURE NewDistinct* (l : LONGINT) : Value;
(**Return a new integer object for value @oparam{l}.  The returned object's
   address is guaranteed to be different from all other instance of
   @otype{Value}.  *)
BEGIN
  RETURN NewInt(Integers.Long(l));
END NewDistinct;

PROCEDURE New* (l : LONGINT) : Value;
BEGIN
  CASE l OF
  |  0: RETURN zero;
  |  1: RETURN one;
  | -1: RETURN minus1;
  ELSE
    RETURN NewInt(Integers.Long(l));
  END;
END New;

PROCEDURE NewString* (str: ARRAY OF CHAR): Value;
  VAR
    i: Integers.Integer;
  BEGIN
    Integers.ConvertFromString (str, i);
    RETURN NewInt(i);
  END NewString;

PROCEDURE (v: Value) Store* (w: Object.Writer);
  VAR
    i: LONGINT;
  BEGIN
    v. Store^ (w);
    w. WriteNum (LEN (v. value^));
    FOR i := 0 TO LEN (v. value^)-1 DO
      w. WriteInt (v. value[i]);
    END;
  END Store;

PROCEDURE (v: Value) Load* (r: Object.Reader);
  VAR
    len, i: LONGINT;
  BEGIN
    v. Load^ (r);
    r. ReadNum (len);
    NEW (v. value, len);
    FOR i := 0 TO len-1 DO
      r. ReadInt (v. value[i]);
    END;
  END Load;

PROCEDURE (v: Value) Equals* (y: Object.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Value) & (Integers.Compare(y(Value).value, v.value) = 0);
  END Equals;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
  VAR
    h, i: LONGINT;
  BEGIN
(*    RETURN Integers.Digits10Of(v.value);*)
    (* FIXME... Digits10Of seems to be broken; as a workaround,
       I'm simply adding the digits to get the hash *)
    h := 0;
    FOR i := 0 TO LEN (v.value^)-1 DO
      INC (h, v. value[i]);
    END;
    RETURN h
  END HashCode;
  
PROCEDURE (v : Value) ToString* () : String.String;
VAR str: ARRAY 128 OF CHAR;	(* FIXME! *)
BEGIN
  Integers.ConvertToString(v.value, str);
  RETURN String.New (str)
END ToString;

PROCEDURE (v: Value) ToInt*(): LONGINT;
  BEGIN
    RETURN Integers.Short (v. value);
  END ToInt;

PROCEDURE (v : Value) Sum* (right : Value) : Value;
BEGIN
  RETURN NewInt(Integers.Sum(v.value, right.value));
END Sum;

PROCEDURE (v : Value) Difference* (right : Value) : Value;
BEGIN
  RETURN NewInt(Integers.Difference(v.value, right.value));
END Difference;

PROCEDURE (v : Value) Product* (right : Value) : Value;
BEGIN
  RETURN NewInt(Integers.Product(v.value, right.value));
END Product;

PROCEDURE (v : Value) Quotient* (right : Value) : Value;
BEGIN
  RETURN NewInt(Integers.Quotient(v.value, right.value));
END Quotient;

PROCEDURE (v : Value) Remainder* (right : Value) : Value;
BEGIN
  RETURN NewInt(Integers.Remainder(v.value, right.value));
END Remainder;

PROCEDURE (v : Value) Ash* (exp : Value) : Value;
BEGIN
  RETURN New(ASH (Integers.Short(v.value), Integers.Short(exp.value)));
END Ash;

PROCEDURE (v : Value) Compare* (right : Object.Object) : LONGINT;
BEGIN
  RETURN Integers.Compare(v.value, right(Value).value);
END Compare;

PROCEDURE (v : Value) Sign* () : LONGINT;
BEGIN
  RETURN Integers.Sign(v.value);
END Sign;

PROCEDURE (v : Value) Negate* () : Value;
BEGIN
  RETURN v.Product(minus1);
END Negate;

PROCEDURE (t : Type) Value* (val : LONGINT) : Value;
BEGIN
  RETURN New(val);
END Value;

PROCEDURE (t : Type) ValueOf* (s : ARRAY OF CHAR) : Value;
VAR
  val : Integers.Integer;
BEGIN
  Integers.ConvertFromString(s, val);
  RETURN NewInt(val);
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName
END ToString;

BEGIN
  NEW(type);
  L.InitType(type);
  typeName := String.New("Integer");

  zero := NewDistinct(0);
  one := NewDistinct(1);
  minus1 := NewDistinct(-1);
END Language:Integer.

