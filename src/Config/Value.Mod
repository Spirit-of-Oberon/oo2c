MODULE Config:Value [OOC_EXTENSIONS];

IMPORT
  Exception, Object, Strings, ADT:Dictionary;


TYPE
  Char* = CHAR;
  String* = ARRAY OF Char;
  StringPtr* = POINTER TO String;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
  END;

TYPE
  PrototypeMap* = Dictionary.Dictionary(STRING, Value);

CONST
  outOfRange* = "Value out of range";
  wrongFormat* = "Invalid format";
  empty* = "Value is empty";


PROCEDURE (v: Value) [ABSTRACT] StringToValue* (str: String)
RAISES Exception.ParseError;
  END StringToValue;

PROCEDURE (v: Value) [ABSTRACT] ValueToString* (VAR str: String);
  END ValueToString;

PROCEDURE (v: Value) [ABSTRACT] Clone* (): Value;
  END Clone;

PROCEDURE (v: Value) [ABSTRACT] DefiningModule* (VAR str: String);
  END DefiningModule;

PROCEDURE GetStringPtr* (VAR str: String): StringPtr;
  VAR
    s: StringPtr;
  BEGIN
    NEW (s, Strings.Length (str)+1);
    COPY (str, s^);
    RETURN s
  END GetStringPtr;


PROCEDURE SetPrototype*(map: PrototypeMap; name: STRING; prototype: Value);
  BEGIN
    map.Set(name, prototype);
  END SetPrototype;

PROCEDURE GetClone*(map: PrototypeMap; prototypeName: STRING): Value;
  VAR
    ptr: Value;
  BEGIN
    ptr := map.Get(prototypeName);
    IF (ptr = NIL) THEN
      RETURN NIL
    ELSE
      RETURN ptr.Clone();
    END
  END GetClone;

END Config:Value.
