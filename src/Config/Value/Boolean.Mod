MODULE Config:Value:Boolean;

IMPORT
  Exception, ConfigValue := Config:Value;


TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    boolean-: BOOLEAN;
  END;


PROCEDURE New* (boolean: BOOLEAN): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. boolean := boolean;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: STRING)
RAISES Exception.ParseError;
  VAR
    i, start: LONGINT;
    strip: STRING;
  BEGIN
    (* strip leading whitespace from `str' *)
    i := 0;
    WHILE (i # str.length) & (str.CharAt(i) <= " ") DO
      INC (i)
    END;
    start := i;
    
    (* strip trailing whitespace from `str' *)
    i := str.length;
    WHILE (i > 0) & (str.CharAt(i-1) <= " ") DO
      DEC (i)
    END;
    
    strip := str.Substring(start, i);
    IF strip.Equals("TRUE") THEN
      v.boolean := TRUE;
    ELSIF strip.Equals("FALSE") THEN
      v.boolean := FALSE;
    ELSE
      RAISE(NEW(Exception.ParseError, ConfigValue.wrongFormat, start));
    END
  END StringToValue;

PROCEDURE (v: Value) ValueToString*(): STRING;
  BEGIN
    IF v.boolean THEN
      RETURN "TRUE";
    ELSE
      RETURN "FALSE";
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

END Config:Value:Boolean.
