MODULE Config:Value:String;

IMPORT
  Object, ConfigValue := Config:Value;


TYPE
  Type* = Object.String8;
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

PROCEDURE (v: Value) StringToValue* (str: ConfigValue.String);
  BEGIN
    v. string := Object.NewLatin1(str);
  END StringToValue;

PROCEDURE (v: Value) ValueToString* (VAR str: ConfigValue.String);
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    chars := v.string.CharsLatin1();
    COPY (chars^, str)
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
    COPY ("Config:Value:String", str)
  END DefiningModule;

END Config:Value:String.
