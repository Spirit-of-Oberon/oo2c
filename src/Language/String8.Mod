MODULE Language:String8 [OOC_EXTENSIONS];

IMPORT 
  ADT:String, ADT:StringBuffer, L := Language;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc)
  END;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value-: String.String;
  END;

VAR
  type-: Type;
  typeName: String.String;
  empty: Value;

PROCEDURE New* (value: String.String): Value;
  VAR
    v: Value;
  BEGIN
    IF (value. length = 0) THEN
      RETURN empty
    ELSE
      NEW(v);
      L.InitValue (v, type);
      v.value := value;
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
  empty := New (String.New (""));
END Language:String8.
