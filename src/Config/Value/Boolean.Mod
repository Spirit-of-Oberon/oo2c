MODULE Config:Value:Boolean;

IMPORT
  Exception, Strings, ConfigValue := Config:Value;


TYPE
  Type* = BOOLEAN;
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    boolean-: Type;
  END;


PROCEDURE New* (boolean: Type): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. boolean := boolean;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: ConfigValue.String)
RAISES Exception.ParseError;
  VAR
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
    
    IF (str = "TRUE") THEN
      v. boolean := TRUE;
    ELSIF (str = "FALSE") THEN
      v. boolean := FALSE;
    ELSE
      RAISE(NEW(Exception.ParseError, ConfigValue.wrongFormat, start));
    END
  END StringToValue;

PROCEDURE (v: Value) ValueToString* (VAR str: ConfigValue.String);
  BEGIN
    IF v. boolean THEN
      COPY ("TRUE", str)
    ELSE
      COPY ("FALSE", str)
    END
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
    COPY ("Config:Value:Boolean", str)
  END DefiningModule;

END Config:Value:Boolean.
