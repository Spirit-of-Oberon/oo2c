MODULE Config:Value:String;

IMPORT
  Object, ConfigValue := Config:Value;


TYPE
  Type* = STRING;
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    string-: Type;
  END;

PROCEDURE New* (str: Object.String8): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s.string := str;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: STRING);
  BEGIN
    v.string := str;
  END StringToValue;

PROCEDURE (v: Value) ValueToString*(): STRING;
  BEGIN
    RETURN v.string;
  END ValueToString;

PROCEDURE (v: Value) Clone* (): Value;
  VAR
    clone: Value;
  BEGIN
    NEW (clone);
    clone^ := v^;
    RETURN clone
  END Clone;

END Config:Value:String.
