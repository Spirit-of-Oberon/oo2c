MODULE Language:Char8 [OOC_EXTENSIONS];

IMPORT
  Ascii, ADT:Object, ADT:String, L := Language;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD (L.TypeDesc)
  END;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD (L.ValueDesc)
    value-: LONGINT;
  END;

CONST
  min = 0;
  max = 255;
  
VAR
  type-: Type;
  typeName: String.String;
  zero: Value;

  
PROCEDURE Init (v: Value; value: CHAR);
  BEGIN
    L.InitValue (v, type);
    v.value := ORD (value);
  END Init;

PROCEDURE New* (value: CHAR): Value;
  VAR
    v: Value;
  BEGIN
    IF (value = 0X) THEN
      RETURN zero
    ELSE
      NEW(v);
      Init (v, value);
      RETURN v
    END;
  END New;

PROCEDURE (v: Value) Equals* (y: Object.Object): BOOLEAN;
  BEGIN
    RETURN (y IS Value) & (v. value = y(Value). value)
  END Equals;
  
PROCEDURE (v: Value) HashCode* (): LONGINT;
  BEGIN
    RETURN v. value;
  END HashCode;
  
PROCEDURE (v: Value) ToString* (): String.String;
  VAR
    str: ARRAY 4 OF CHAR;

  PROCEDURE ToHex (i: LONGINT): CHAR;
    BEGIN
      IF (i < 10) THEN
        RETURN CHR (ORD("0")+i)
      ELSE
        RETURN CHR (ORD("A")-10+i)
      END;
    END ToHex;
  
  BEGIN
    IF (v. value < ORD (" ")) OR (v. value >= ORD (Ascii.del)) THEN
      str := "xxX";
      str[0] := ToHex (v. value DIV 16);
      str[1] := ToHex (v. value MOD 16);
    ELSIF (v. value = ORD ('"')) THEN
      str := "'"+'"'+'"';
    ELSE
      str := '" "';
      str[1] := CHR (v. value);
    END;
    RETURN String.New (str)
  END ToString;

PROCEDURE (v: Value) Store* (w: Object.Writer);
  BEGIN
    v. Store^ (w);
    w. WriteNum (v. value);
  END Store;

PROCEDURE (v: Value) Load* (r: Object.Reader);
  BEGIN
    v. Load^ (r);
    r. ReadNum (v. value);
  END Load;



PROCEDURE (t: Type) Value* (value: CHAR): Value;
  BEGIN
    RETURN New(value);
  END Value;

PROCEDURE (t: Type) ValueOf* (str[NO_COPY]: ARRAY OF CHAR): Value;
  VAR
    i, hexCount, ord: LONGINT;
    
  PROCEDURE HexDigit (ch: CHAR): LONGINT;
    BEGIN
      CASE CAP (ch) OF
      | "0".."9": RETURN ORD(ch)-ORD("0")
      | "A".."F": RETURN ORD(ch)+(10-ORD("A"))
      ELSE
        RETURN -1
      END;
    END HexDigit;
    
  PROCEDURE HexToInt (str: ARRAY OF CHAR; end: CHAR; VAR result: LONGINT): BOOLEAN;
    BEGIN
      result := 0; i := 0;
      WHILE (str[i] # end) DO
        IF ((MAX (LONGINT)-HexDigit (str[i])) DIV 16 < result) THEN
          RETURN FALSE
        END;
        result := result*16+HexDigit (str[i]);
        INC (i)
      END;
      RETURN TRUE
    END HexToInt;
  
  BEGIN
    i := 0; hexCount := 0;
    WHILE (str[i] # 0X) DO
      IF (HexDigit (str[i]) >= 0) THEN
        INC (hexCount)
      END;
      INC (i)
    END;
    IF (i = 3) & (str[0] = str[i-1]) & ((str[0] = '"') OR (str[0] = "'")) THEN
      (* single character, written as '...' or "..." *)
      RETURN New (str[1])
    ELSIF (i >= 2) & (str[i-1] = "X") & (hexCount+1 = i) THEN
      (* character written has hexadecimal constant nnX *)
      IF HexToInt (str, "X", ord) & (min <= ord) & (ord <= max) THEN
        RETURN New (CHR (ord))
      ELSE  (* overflow *)
        RETURN NIL
      END
    ELSE  (* string is not delimited properly, nor is in hex notation *)
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
  typeName := String.New ("Char8");

  NEW (zero);
  Init (zero, 0X);
END Language:Char8.
