MODULE Language:IntegerType [OOC_EXTENSIONS];

IMPORT 
  IntStr, ADT:String, ADT:StringBuffer, L := Language;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : LONGINT;
  END;

  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
    min-, max- : LONGINT;
  END;


PROCEDURE New* (t : Type; val : LONGINT) : Value;
(** Return a @otype{Value} for integer @oparam{val} with type @oparam{t}. This
 * function returns @code{NIL} if the value is outside the allowed range for
 * the type. *)
VAR v : Value;
BEGIN
  IF (val < t.min) OR (val > t.max) THEN 
    RETURN NIL
  END;
  NEW(v);
  L.InitValue (v, t);
  v.value := val;
  RETURN v;
END New;

PROCEDURE (v : Value) ToString* () : String.String;
VAR str: ARRAY 32 OF CHAR;
BEGIN
  IntStr.IntToStr (v. value, str);
  RETURN String.New (str)
END ToString;



PROCEDURE NewType* (min, max : LONGINT) : Type;
(** Return an integer type with given maximum and minimum allowed values *)
VAR t : Type;
BEGIN
  NEW(t);
  L.InitType (t);
  t.min := min; t.max := max;
  RETURN t;
END NewType;

PROCEDURE (t : Type) Value* (val : LONGINT) : Value;
BEGIN
  RETURN New(t, val);
END Value;

PROCEDURE (t : Type) ValueOf* (s : ARRAY OF CHAR) : Value;
VAR
  res : IntStr.ConvResults;
  val : LONGINT;
BEGIN
  IntStr.StrToInt(s, val, res);
  IF res # IntStr.strAllRight THEN
    RETURN NIL;
  ELSE
    RETURN t.Value(val);
  END;
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
VAR
  b : StringBuffer.StringBuffer;
BEGIN
  b := StringBuffer.New("IntegerType(");
  b.AppendLongInt(t.min);
  b.AppendChar(",");
  b.AppendLongInt(t.max);
  b.AppendChar(")");
  RETURN b.ToString();
END ToString;

END Language:IntegerType.

