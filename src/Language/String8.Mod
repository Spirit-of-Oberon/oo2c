MODULE Language:String8 [OOC_EXTENSIONS];

IMPORT 
  ADT:Object, ADT:String, ADT:StringBuffer,
  L := Language, LString := Language:String;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc)
  END;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD
    (LString.ValueDesc)
    value-: String.String;
  END;

VAR
  type-: Type;
  typeName: String.String;
  empty: Value;

PROCEDURE Init (v: Value; value: String.String);
  BEGIN
    L.InitValue (v, type);
    v.value := value;
  END Init;

PROCEDURE New* (value: String.String): Value;
  VAR
    v: Value;
  BEGIN
    IF (value. length = 0) THEN
      RETURN empty
    ELSE
      NEW(v);
      Init (v, value);
      RETURN v
    END
  END New;

PROCEDURE NewRegion* (source[NO_COPY]: ARRAY OF CHAR; pos, endPos: LONGINT): Value;
  BEGIN
    RETURN New (String.NewRegion (source, pos, endPos))
  END NewRegion;

PROCEDURE NewString* (source[NO_COPY]: ARRAY OF CHAR): Value;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (source[i] # 0X) DO
      INC (i)
    END;
    RETURN NewRegion (source, 0, i)
  END NewString;

PROCEDURE NewChar* (source: CHAR): Value;
  VAR
    str: ARRAY 1 OF CHAR;
  BEGIN
    str[0] := source;
    RETURN NewRegion (str, 0, 1)
  END NewChar;

PROCEDURE (v: Value) Length*(): LONGINT;
  BEGIN
    RETURN v. value. length;
  END Length;

PROCEDURE (v: Value) CharAt*(i: LONGINT): CHAR;
  BEGIN
    ASSERT ((0 <= i) & (i < v. value. length));
    RETURN v. value. array[i];
  END CharAt;

PROCEDURE (v : Value) Compare* (str : Object.Object) : LONGINT;
BEGIN
  RETURN v.value.Compare(str(Value).value);
END Compare;

PROCEDURE (v : Value) Concat* (str : Value) : Value;
BEGIN
  RETURN New(v.value.Concat(str.value));
END Concat;

PROCEDURE (v: Value) Equals* (y: Object.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Value) & v. value. Equals(y(Value). value)
  END Equals;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
  BEGIN
    RETURN v. value. HashCode();
  END HashCode;
  
PROCEDURE (v: Value) ToString* (): String.String;
  VAR
    i: LONGINT;
    delim: ARRAY 2 OF CHAR;
    sb: StringBuffer.StringBuffer;
  BEGIN
    i := v. value. IndexOf ('"', 0);
    IF (i < 0) THEN
      delim := '"'
    ELSE
      delim := "'"
    END;
    sb := StringBuffer.New (delim);
    sb. Append (v. value);
    sb. AppendString (delim);
    RETURN sb. ToString()
  END ToString;

PROCEDURE (v: Value) Store* (w: Object.Writer);
  BEGIN
    v. Store^ (w);
    w. WriteObject (v. value);
  END Store;

PROCEDURE (v: Value) Load* (r: Object.Reader);
  VAR
    obj: Object.Object;
  BEGIN
    v. Load^ (r);
    r. ReadObject (obj);
    v. value := obj(String.String);
  END Load;



PROCEDURE (t: Type) Value* (value: String.String): Value;
  BEGIN
    RETURN New(value);
  END Value;

PROCEDURE (t: Type) ValueOf* (str[NO_COPY]: ARRAY OF CHAR): Value;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (str[i] # 0X) DO
      INC (i)
    END;
    IF (i >= 2) & (str[0] = str[i-1]) & ((str[0] = '"') OR (str[0] = "'")) THEN
      RETURN NewRegion (str, 1, i-1)
    ELSE  (* string is not delimited properly *)
      RETURN NIL
    END
  END ValueOf;

PROCEDURE (t: Type) ToString* (): String.String;
  BEGIN
    RETURN typeName
  END ToString;

BEGIN
  NEW(type);
  L.InitType (type);
  typeName := String.New ("String8");

  NEW (empty);
  Init (empty, String.New (""));
END Language:String8.
