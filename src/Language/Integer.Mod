MODULE Language:Integer [OOC_EXTENSIONS];

IMPORT
  Integers, ADT:Object, ADT:String, L := Language;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : Integers.Integer;
  END;

  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
  END;

VAR
  type- : Type;
  typeName : String.String;

  minus1, zero- : Value;

PROCEDURE New* (val : Integers.Integer) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @ovar{type}. *)
VAR 
  v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := val;
  RETURN v;
END New;

PROCEDURE NewLInt* (l : LONGINT) : Value;
BEGIN
  RETURN New(Integers.Long(l));
END NewLInt;

PROCEDURE NewInt* (i : INTEGER) : Value;
BEGIN
  RETURN NewLInt(i);
END NewInt;

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

PROCEDURE (v: Value) ToLInt*(): LONGINT;
  BEGIN
    RETURN Integers.Short (v. value);
  END ToLInt;

PROCEDURE (v : Value) Sum* (right : Value) : Value;
BEGIN
  RETURN New(Integers.Sum(v.value, right.value));
END Sum;

PROCEDURE (v : Value) Difference* (right : Value) : Value;
BEGIN
  RETURN New(Integers.Difference(v.value, right.value));
END Difference;

PROCEDURE (v : Value) Product* (right : Value) : Value;
BEGIN
  RETURN New(Integers.Product(v.value, right.value));
END Product;

PROCEDURE (v : Value) Quotient* (right : Value) : Value;
BEGIN
  RETURN New(Integers.Quotient(v.value, right.value));
END Quotient;

PROCEDURE (v : Value) Remainder* (right : Value) : Value;
BEGIN
  RETURN New(Integers.Remainder(v.value, right.value));
END Remainder;

PROCEDURE (v : Value) Compare* (right : Value) : LONGINT;
BEGIN
  RETURN Integers.Compare(v.value, right.value);
END Compare;

PROCEDURE (v : Value) Sign* () : LONGINT;
BEGIN
  RETURN Integers.Sign(v.value);
END Sign;

PROCEDURE (v : Value) Negate* () : Value;
BEGIN
  RETURN v.Product(minus1);
END Negate;

PROCEDURE (t : Type) ValueLInt* (val : LONGINT) : Value;
BEGIN
  RETURN New(Integers.Long(val));
END ValueLInt;

PROCEDURE (t : Type) Value* (val : Integers.Integer) : Value;
BEGIN
  RETURN New(val);
END Value;

PROCEDURE (t : Type) ValueOf* (s : ARRAY OF CHAR) : Value;
VAR
  val : Integers.Integer;
BEGIN
  Integers.ConvertFromString(s, val);
  RETURN New(val);
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName
END ToString;

BEGIN
  zero := New(Integers.Long(0));
  minus1 := New(Integers.Long(-1));
  NEW(type);
  L.InitType(type);
  typeName := String.New("Integer");
END Language:Integer.

