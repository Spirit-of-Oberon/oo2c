MODULE Language:Boolean;

IMPORT 
  ADT:Storable, ADT:String, L := Language, LanguageNew;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : BOOLEAN;
  END;

VAR
  true-, false-: Value;

PROCEDURE New* (value : BOOLEAN) : Value;
VAR v : Value;
BEGIN
  NEW(v);
  L.InitValue (v);
  v.value := value;
  RETURN v;
END New;

PROCEDURE (v: Value) Equals* (y: LanguageNew.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Value) & (v. value = y(Value). value)
  END Equals;
  
PROCEDURE (v: Value) Compare* (y: Storable.Object): LONGINT;
  BEGIN
    ASSERT (FALSE); RETURN -1;
  END Compare;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
  BEGIN
    IF v. value THEN
      RETURN 1
    ELSE
      RETURN 2
    END;
  END HashCode;
  
PROCEDURE (v : Value) ToString* () : String.String;
BEGIN
  IF v.value THEN
    RETURN String.New("TRUE");
  ELSE
    RETURN String.New("FALSE");
  END;
END ToString;

BEGIN
  true := New (TRUE);
  false := New (FALSE);
END Language:Boolean.
