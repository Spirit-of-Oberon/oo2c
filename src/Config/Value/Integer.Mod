MODULE Config:Value:Integer;

IMPORT
  Strings, IntStr, Msg, ConfigValue := Config:Value;


TYPE
  Type* = LONGINT;
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    integer-: Type;
  END;


CONST
  strOutOfRange = IntStr.strOutOfRange;
  strWrongFormat = IntStr.strWrongFormat;
  strEmpty = IntStr.strEmpty;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (ConfigValue.ErrorContextDesc)
  END;

VAR
  integerContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | strOutOfRange:
      t := "Integer value out of range"
    | strWrongFormat:
      t := "Invalid format for integer value"
    | strEmpty:
      t := "Value is empty"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE New* (int: Type): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. integer := int;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: ConfigValue.String; VAR errMsg: Msg.Msg);
  VAR
    int: Type;
    res: IntStr.ConvResults;
    i, len: INTEGER;
  BEGIN
    (* strip leading whitespace from `str' *)
    i := 0;
    WHILE (str[i] # 0X) & (str[i] <= " ") DO
      INC (i)
    END;
    Strings.Delete (str, 0, i);
    
    (* strip trailing whitespace from `str' *)
    len := Strings.Length (str);
    i := len;
    WHILE (i > 0) & (str[i-1] <= " ") DO
      DEC (i)
    END;
    Strings.Delete (str, i, len-i);
    
    IntStr.StrToInt (str, int, res);
    CASE res OF
    | IntStr.strAllRight:
      v. integer := int;
      errMsg := NIL
    ELSE
      errMsg := Msg.New (integerContext, res)
    END
  END StringToValue;

PROCEDURE (v: Value) ValueToString* (VAR str: ConfigValue.String);
  BEGIN
    IntStr.IntToStr (v. integer, str)
  END ValueToString;

PROCEDURE (v: Value) Clone* (): Value;
  VAR
    clone: Value;
  BEGIN
    NEW (clone);
    clone^ := v^;
    RETURN clone
  END Clone;

PROCEDURE (v: Value) DefiningModule* (VAR str: ConfigValue.String);
  BEGIN
    COPY ("Config:Value:Integer", str)
  END DefiningModule;

BEGIN
  NEW (integerContext);
  Msg.InitContext (integerContext, "Config:Value:Integer");
END Config:Value:Integer.
