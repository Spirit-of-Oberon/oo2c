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

PROCEDURE New* (val : Integers.Integer) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @oparam{t}. *)
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
  NEW(type);
  L.InitType(type);
  typeName := String.New("INTEGER");
END Language:Integer.

