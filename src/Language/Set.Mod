MODULE Language:Set;

IMPORT 
  ADT:Storable, ADT:String, ADT:StringBuffer,
  L := Language, SYSTEM, LanguageNew;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : SET;
  END;

PROCEDURE New* (value : SET) : Value;
VAR v : Value;
BEGIN
  NEW(v);
  L.InitValue(v);
  v.value := value;
  RETURN v;
END New;

PROCEDURE (v : Value) Equals* (y : LanguageNew.Object) : BOOLEAN;
BEGIN
  WITH y : Value DO
    RETURN y.value = v.value
  ELSE
    RETURN FALSE;
  END;
END Equals;

PROCEDURE (v: Value) Compare* (y: Storable.Object): LONGINT;
  BEGIN
    ASSERT (FALSE); RETURN -1;
  END Compare;
  
PROCEDURE (v : Value) HashCode* () : LONGINT;
VAR
BEGIN
  RETURN SYSTEM.VAL(LONGINT, v.value);
END HashCode;

PROCEDURE (v : Value) ToString* () : String.String;
VAR b : StringBuffer.StringBuffer;
BEGIN
  b := StringBuffer.New("");
  b.AppendSet(v.value);
  RETURN b.ToString();
END ToString;

PROCEDURE (v : Value) ToLInt* () : LONGINT;
BEGIN
  RETURN SYSTEM.VAL(LONGINT, v.value);
END ToLInt;

PROCEDURE (v : Value) Store* (w : Storable.Writer);
BEGIN
  w.WriteSet(v.value);
END Store;

PROCEDURE (v : Value) Load* (r : Storable.Reader);
BEGIN
  r.ReadSet(v.value);
END Load;

END Language:Set.
