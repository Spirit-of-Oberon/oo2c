MODULE Language:String16 [OOC_EXTENSIONS];

IMPORT 
  S := SYSTEM, ADT:Object, ADT:String, LongStrings,
  L := Language, LString := Language:String;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc)
  END;

TYPE
  Value* = POINTER TO ValueDesc;
  CharArray = POINTER TO ARRAY OF LONGCHAR;
  ValueDesc* = RECORD
    (LString.ValueDesc)
    array-: CharArray;
  END;

VAR
  type-: Type;
  typeName: String.String;
  emptyArray: CharArray;
  empty: Value;

PROCEDURE Init (v: Value; value: CharArray);
  BEGIN
    L.InitValue (v, type);
    v. array := value;
  END Init;

PROCEDURE New (value: CharArray): Value;
  VAR
    v: Value;
  BEGIN
    IF (LEN (value^) = 1) THEN
      RETURN empty
    ELSE
      NEW(v);
      Init (v, value);
      RETURN v
    END
  END New;

PROCEDURE NewRegion* (source[NO_COPY]: ARRAY OF LONGCHAR; pos, endPos: LONGINT): Value;
  VAR
    array: CharArray;
    i: LONGINT;
  BEGIN
    NEW (array, endPos-pos+1);
    i := 0;
    WHILE (pos # endPos) DO
      array[i] := source[pos]; INC (pos); INC (i);
    END;
    array[i] := 0X;
    RETURN New (array)
  END NewRegion;

PROCEDURE NewRegion8* (source[NO_COPY]: ARRAY OF CHAR; pos, endPos: LONGINT): Value;
  VAR
    array: CharArray;
    i: LONGINT;
  BEGIN
    NEW (array, endPos-pos+1);
    i := 0;
    WHILE (pos # endPos) DO
      array[i] := source[pos]; INC (pos); INC (i);
    END;
    array[i] := 0X;
    RETURN New (array)
  END NewRegion8;

PROCEDURE NewString* (source[NO_COPY]: ARRAY OF LONGCHAR): Value;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (source[i] # 0X) DO
      INC (i)
    END;
    RETURN NewRegion (source, 0, i)
  END NewString;

PROCEDURE NewChar* (source: LONGCHAR): Value;
  VAR
    str: ARRAY 1 OF LONGCHAR;
  BEGIN
    str[0] := source;
    RETURN NewRegion (str, 0, 1)
  END NewChar;

PROCEDURE (v: Value) Length*(): LONGINT;
  BEGIN
    RETURN LEN (v. array^)-1;
  END Length;

PROCEDURE (v: Value) CharAt*(i: LONGINT): LONGCHAR;
  BEGIN
    ASSERT ((0 <= i) & (i < LEN (v. array^)-1));
    RETURN v. array[i];
  END CharAt;

PROCEDURE (v : Value) Compare* (str : Object.Object) : LONGINT;
BEGIN
  RETURN LongStrings.Compare(v.array^, str(Value).array^);
END Compare;

PROCEDURE (v : Value) Concat* (str : Value) : Value;
VAR
  res : CharArray;
BEGIN
  NEW(res, v.Length() + str.Length() + 1);
  LongStrings.Concat(v.array^, str.array^, res^);
  RETURN New(res);
END Concat;

PROCEDURE (v: Value) Equals* (y: Object.Object): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    WITH y: Value DO
      IF (LEN (v. array^) = LEN (y. array^)) THEN
        i := 0;
        WHILE (i # LEN (v. array^)) & (v. array[i] = y. array[i]) DO
          INC (i);
        END;
        RETURN (i = LEN (v. array^));
      ELSE
        RETURN FALSE;
      END;
    ELSE
      RETURN FALSE;
    END;
  END Equals;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
  VAR
    len, x, p: LONGINT;
  BEGIN
    (* this is intended as a reimplementation of the Python hash code on
       strings; any errors are mine, of course *)
    len := LEN (v. array^)-1;
    x := ASH (ORD (v. array[0]), 7);
    p := 0;
    WHILE (p # len) DO
      <* PUSH; OverflowCheck := FALSE *>
      x := S.VAL (LONGINT, S.VAL (SET, 1000003*x) /
                           S.VAL (SET, ORD (v. array[p])));
      <* POP *>
      INC (p)
    END;
    x := S.VAL (LONGINT, S.VAL (SET, x) / S.VAL (SET, len));
    RETURN x
  END HashCode;
  
PROCEDURE (v: Value) ToString* (): String.String;
  BEGIN
    RETURN String.New ("[instance of Language:String16]");
  END ToString;

PROCEDURE (v: Value) Store* (w: Object.Writer);
  VAR
    i: LONGINT;
  BEGIN
    v. Store^ (w);
    w. WriteNum (LEN (v. array^)-1);
    FOR i := 0 TO LEN (v.array^)-2 DO
      w. WriteNum (ORD (v. array[i]));
    END;
  END Store;

PROCEDURE (v: Value) Load* (r: Object.Reader);
  VAR
    array: CharArray;
    len, i, j: LONGINT;
  BEGIN
    v. Load^ (r);
    r. ReadNum (len);
    NEW (array, len+1);
    FOR i := 0 TO len-1 DO
      r. ReadNum (j);
      array[i] := LONGCHR (j);
    END;
    array[len] := 0X;
    v. array := array;
  END Load;



PROCEDURE (t: Type) Value* (value: String.String): Value;
  BEGIN
    RETURN NewRegion8(value. array^, 0, value. length);
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
      RETURN NewRegion8 (str, 1, i-1)
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
  typeName := String.New ("String16");

  NEW (emptyArray, 1);
  emptyArray[0] := 0X;
  NEW (empty);
  Init (empty, emptyArray);
END Language:String16.
