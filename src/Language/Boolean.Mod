MODULE Language:Boolean;

IMPORT 
  ADT:String, L := Language;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
  END;

  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : BOOLEAN;
  END;

VAR
  type-: Type;
  typeName: String.String;
  true, false: Value;


PROCEDURE New* (value : BOOLEAN) : Value;
VAR v : Value;
BEGIN
  NEW(v);
  L.InitValue (v, type);
  v.value := value;
  RETURN v;
END New;

PROCEDURE (v : Value) ToString* () : String.String;
BEGIN
  IF v.value THEN
    RETURN String.New("TRUE");
  ELSE
    RETURN String.New("FALSE");
  END;
END ToString;



PROCEDURE (t : Type) Value* (value : BOOLEAN) : Value;
BEGIN
  RETURN New(value);
END Value;

PROCEDURE (t : Type) ValueOf* (str : ARRAY OF CHAR) : Value;
BEGIN
  IF str = "TRUE" THEN
    RETURN true
  ELSIF str = "FALSE" THEN
    RETURN false
  ELSE
    RETURN NIL
  END;
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName
END ToString;

BEGIN
  NEW(type);
  L.InitType (type);
  typeName := String.New ("BOOLEAN");
  true := New (TRUE);
  false := New (FALSE);
END Language:Boolean.
