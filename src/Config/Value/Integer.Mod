MODULE Config:Value:Integer;

IMPORT
  Object, Exception, IntStr, ConfigValue := Config:Value;


TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    integer-: LONGINT;
  END;


PROCEDURE New* (int: LONGINT): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. integer := int;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: STRING)
RAISES Exception.ParseError;
  VAR
    strip: STRING;
    str8: Object.String8;
    chars: Object.CharsLatin1;
    int: LONGINT;
    res: IntStr.ConvResults;
    i, start: LONGINT;
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
    str8 := strip.ToString8("?");
    chars := str8.CharsLatin1();
    
    IntStr.StrToInt (chars^, int, res);
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

PROCEDURE (v: Value) ValueToString*(): STRING;
  VAR
    str: ARRAY 16 OF CHAR;
  BEGIN
    IntStr.IntToStr(v.integer, str);
    RETURN Object.NewLatin1(str);
  END ValueToString;

PROCEDURE (v: Value) Clone* (): Value;
  VAR
    clone: Value;
  BEGIN
    NEW (clone);
    clone^ := v^;
    RETURN clone
  END Clone;

END Config:Value:Integer.
