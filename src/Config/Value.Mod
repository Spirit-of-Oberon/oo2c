MODULE Config:Value [OOC_EXTENSIONS];

IMPORT
  Exception, Object, ADT:Dictionary;


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


PROCEDURE (v: Value) [ABSTRACT] StringToValue*(str: STRING)
RAISES Exception.ParseError;
  END StringToValue;

PROCEDURE (v: Value) [ABSTRACT] ValueToString*(): STRING;
  END ValueToString;

PROCEDURE (v: Value) [ABSTRACT] Clone*(): Value;
  END Clone;


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
