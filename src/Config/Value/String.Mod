MODULE Config:Value:String;

IMPORT
  Msg, ConfigValue := Config:Value;


TYPE
  Type* = ConfigValue.StringPtr;
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    string-: Type;
  END;

PROCEDURE New* (str: ConfigValue.String): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. string := ConfigValue.GetStringPtr (str);
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: ConfigValue.String; VAR errMsg: Msg.Msg);
  BEGIN
    v. string := ConfigValue.GetStringPtr (str);
    errMsg := NIL
  END StringToValue;

PROCEDURE (v: Value) ValueToString* (VAR str: ConfigValue.String);
  BEGIN
    COPY (v. string^, str)
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
