MODULE Language:Set;

IMPORT 
  ADT:Object, ADT:String, ADT:StringBuffer,
  L := Language, SYSTEM;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value- : SET;
  END;

  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc) 
  END;

VAR
  type- : Type;
  typeName : String.String;

PROCEDURE New* (value : SET) : Value;
VAR v : Value;
BEGIN
  NEW(v);
  L.InitValue(v, type);
  v.value := value;
  RETURN v;
END New;

PROCEDURE (v : Value) Equals* (y : Object.Object) : BOOLEAN;
BEGIN
  WITH y : Value DO
    RETURN y.value = v.value
  ELSE
    RETURN FALSE;
  END;
END Equals;

PROCEDURE (v: Value) Compare* (y: Object.Object): LONGINT;
  BEGIN
    ASSERT (FALSE); RETURN -1;
  END Compare;
  
PROCEDURE (v : Value) HashCode* () : LONGINT;
VAR
BEGIN
  RETURN SYSTEM.VAL(LONGINT, v.value);
END HashCode;

PROCEDURE (t : Type) ValueOf* (str : ARRAY OF CHAR) : Value;
VAR 
  s : SET;
  pos : INTEGER;
  c : CHAR;

  PROCEDURE GetChar;
  BEGIN
    c := str[pos]; INC(pos);
  END GetChar;

  PROCEDURE IsDigit () : BOOLEAN;
  BEGIN
    RETURN (c >= '0') & (c <= '9');
  END IsDigit;

  PROCEDURE ReadInteger;
  VAR result : INTEGER;
  BEGIN
    result := 0;
    WHILE IsDigit() DO
      result := result * 10 + ORD(c) - ORD('0');
      GetChar();
    END;
    s := s + {result};
  END ReadInteger;
     
BEGIN
  s := {};
  pos := 0; GetChar();
  IF c = '{' THEN
    GetChar();
    IF IsDigit() THEN
      ReadInteger();
      WHILE c = "," DO
        GetChar();
        ReadInteger();
      END
    END;
    IF c = '}' THEN
      GetChar();
      IF c = 0X THEN
        RETURN New(s);
      END;
    END;
  END;
  RETURN NIL
END ValueOf;

PROCEDURE (t : Type) ToString* () : String.String;
BEGIN
  RETURN typeName;
END ToString;

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

PROCEDURE (v : Value) Store* (w : Object.Writer);
BEGIN
  w.WriteSet(v.value);
END Store;

PROCEDURE (v : Value) Load* (r : Object.Reader);
BEGIN
  r.ReadSet(v.value);
END Load;

BEGIN
  NEW(type);
  L.InitType(type);
  typeName := String.New("Set");
END Language:Set.
