MODULE Config:Value:Boolean;

IMPORT
  Strings, Msg, ConfigValue := Config:Value;


TYPE
  Type* = BOOLEAN;
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (ConfigValue.ValueDesc)
    boolean-: Type;
  END;


CONST
  invalidValue = 1;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (ConfigValue.ErrorContextDesc)
  END;

VAR
  booleanContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidValue:
      t := "Not a boolean value"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE New* (boolean: Type): Value;
  VAR
    s: Value;
  BEGIN
    NEW (s);
    s. boolean := boolean;
    RETURN s
  END New;

PROCEDURE (v: Value) StringToValue* (str: ConfigValue.String; VAR errMsg: Msg.Msg);
  VAR
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
    
    IF (str = "TRUE") THEN
      v. boolean := TRUE;
      errMsg := NIL
    ELSIF (str = "FALSE") THEN
      v. boolean := FALSE;
      errMsg := NIL
    ELSE
      errMsg := Msg.New (booleanContext, invalidValue)
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

BEGIN
  NEW (booleanContext);
  Msg.InitContext (booleanContext, "Config:Value:Boolean");
END Config:Value:Boolean.
