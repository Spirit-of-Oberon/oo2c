MODULE Config:Value:Integer;

IMPORT
  Exception, Strings, IntStr, ConfigValue := Config:Value;


TYPE
  Type* = LONGINT;
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    integer-: Type;
  END;


PROCEDURE New* (int: Type): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. integer := int;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: ConfigValue.String)
RAISES Exception.ParseError;
  VAR
    int: Type;
    res: IntStr.ConvResults;
    i, len, start: INTEGER;
  BEGIN
    (* strip leading whitespace from `str' *)
    i := 0;
    WHILE (str[i] # 0X) & (str[i] <= " ") DO
      INC (i)
    END;
    start := i;
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
    | IntStr.strWrongFormat:
      RAISE(NEW(Exception.ParseError, ConfigValue.wrongFormat, start));
    | IntStr.strOutOfRange:
      RAISE(NEW(Exception.ParseError, ConfigValue.outOfRange, start));
    | IntStr.strEmpty:
      RAISE(NEW(Exception.ParseError, ConfigValue.empty, start));
    END;
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

END Config:Value:Integer.
