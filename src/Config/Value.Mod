MODULE Config:Value [OOC_EXTENSIONS];

IMPORT
  Strings, Msg;


TYPE
  Char* = CHAR;
  String* = ARRAY OF Char;
  StringPtr* = POINTER TO String;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT]
  END;

TYPE
  PrototypeName* = POINTER TO ARRAY OF CHAR;
  Prototype* = POINTER TO PrototypeDesc;
  PrototypeDesc = RECORD
    next: Prototype;
    name-: PrototypeName;
    prototype-: Value;
  END;

TYPE
  PrototypeList* = POINTER TO PrototypeListDesc;
  PrototypeListDesc = RECORD
    head: Prototype;
  END;

TYPE
  ErrorContext* = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
    (Msg.ContextDesc)
  END;


PROCEDURE (ec: ErrorContext) WriteTemplate* (msg: Msg.Msg; VAR text, templ: Msg.LString);
  BEGIN
    COPY (text, templ)
  END WriteTemplate;
  
PROCEDURE (v: Value) [ABSTRACT] StringToValue* (str: String; VAR errMsg: Msg.Msg);
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


PROCEDURE NewPrototypeList* (): PrototypeList;
  VAR
    tl: PrototypeList;
  BEGIN
    NEW (tl);
    tl. head := NIL;
    RETURN tl
  END NewPrototypeList;


PROCEDURE (tl: PrototypeList) RegisterPrototype* (name: ARRAY OF CHAR; prototype: Value);
  VAR
    ptr, prev, newPrototype: Prototype;
  BEGIN
    prev := NIL; ptr := tl. head;
    WHILE (ptr # NIL) & (ptr. name^ # name) DO
      prev := ptr; ptr := ptr. next
    END;
    ASSERT (ptr = NIL);
    
    NEW (newPrototype);
    newPrototype. next := NIL;
    NEW (newPrototype. name, Strings.Length (name)+1);
    COPY (name, newPrototype. name^);
    newPrototype. prototype := prototype;
    
    IF (prev = NIL) THEN
      tl. head := newPrototype
    ELSE
      prev. next := newPrototype
    END
  END RegisterPrototype;

PROCEDURE (tl: PrototypeList) GetClone* (prototypeName: ARRAY OF CHAR): Value;
  VAR
    ptr: Prototype;
  BEGIN
    ptr := tl. head;
    WHILE (ptr # NIL) & (ptr. name^ # prototypeName) DO
      ptr := ptr. next
    END;
    IF (ptr = NIL) THEN
      RETURN NIL
    ELSE
      RETURN ptr. prototype. Clone()
    END
  END GetClone;

END Config:Value.
