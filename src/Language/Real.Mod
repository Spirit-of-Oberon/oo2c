MODULE Language:Real [OOC_EXTENSIONS];

IMPORT
  Reals, ADT:Object, ADT:String, L := Language;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : Reals.Real;
  END;

  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
  END;

VAR
  type- : Type;
  typeName : String.String;

PROCEDURE New* (val : Reals.Real) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @ovar{type}. *)
VAR 
  v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := val;
  RETURN v;
END New;

(*
PROCEDURE NewLInt* (l : LONGINT) : Value;
BEGIN
  RETURN New(Integers.Long(l));
END NewLInt;
*)

(*
PROCEDURE NewInt* (i : INTEGER) : Value;
BEGIN
  RETURN NewLInt(i);
END NewInt;
*)

PROCEDURE (v: Value) Store* (w: Object.Writer);
  VAR
    i: LONGINT;
  BEGIN
    v. Store^ (w);
    w. WriteNum (LEN (v. value^));
    FOR i := 0 TO LEN (v. value^)-1 DO
      w. WriteReal (v. value[i]);
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
      r. ReadReal (v. value[i]);
    END;
  END Load;

PROCEDURE (v: Value) Equals* (y: Object.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Value) & (Reals.Cmp(y(Value).value^, v.value^) = 0);
  END Equals;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
  VAR
    h, i: LONGINT;
  BEGIN
    HALT(0);
  END HashCode;
  
PROCEDURE (v : Value) ToString* () : String.String;
VAR str: ARRAY 128 OF CHAR;	(* FIXME! *)
BEGIN
  Reals.ToString(v.value, str, 0);
  RETURN String.New (str)
END ToString;

(*
PROCEDURE (v: Value) ToLInt*(): LONGINT;
  BEGIN
    RETURN Integers.Short (v. value);
  END ToLInt;
*)

(*
PROCEDURE (t : Type) ValueLInt* (val : LONGINT) : Value;
BEGIN
  RETURN New(Integers.Long(val));
END ValueLInt;
*)

PROCEDURE (t : Type) Value* (val : Reals.Real) : Value;
BEGIN
  RETURN New(val);
END Value;

PROCEDURE (t : Type) ValueOf* (s : ARRAY OF CHAR) : Value;
VAR
  val : Reals.Real;
BEGIN
  val := Reals.ToReal(s);
  RETURN New(val);
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName
END ToString;

BEGIN
  NEW(type);
  L.InitType(type);
  typeName := String.New("Real");
END Language:Real.

