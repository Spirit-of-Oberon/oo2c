MODULE Config [OOC_EXTENSIONS];

IMPORT
  Exception, Object, IntStr, ADT:Dictionary;


TYPE
  Config* = POINTER TO ConfigDesc;
  ConfigDesc* = RECORD [ABSTRACT]
  END;

TYPE
  Variable* = POINTER TO VariableDesc;
  VariableDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
  END;

TYPE
  BooleanVar* = POINTER TO BooleanVarDesc;
  BooleanVarDesc = RECORD
    (VariableDesc)
    boolean-: BOOLEAN;
  END;

TYPE
  IntegerVar* = POINTER TO IntegerVarDesc;
  IntegerVarDesc = RECORD
    (VariableDesc)
    integer-: LONGINT;
  END;

TYPE
  StringVar* = POINTER TO StringVarDesc;
  StringVarDesc = RECORD
    (VariableDesc)
    string-: STRING;
  END;

TYPE
  PrototypeMap* = Dictionary.Dictionary(STRING, Variable);

CONST
  outOfRange* = "Value out of range";
  wrongFormat* = "Invalid format";
  empty* = "Value is empty";


PROCEDURE InitConfig* (config: Config);
  BEGIN
  END InitConfig;

PROCEDURE (v: Variable) [ABSTRACT] StringToValue*(str: STRING)
RAISES Exception.ParseError;
  END StringToValue;

PROCEDURE (v: Variable) [ABSTRACT] ToString*(): STRING;
  END ToString;

PROCEDURE (v: Variable) [ABSTRACT] Clone*(): Variable;
  END Clone;



PROCEDURE NewBooleanVar* (boolean: BOOLEAN): BooleanVar;
  VAR
    s: BooleanVar;
  BEGIN
    NEW (s);
    s. boolean := boolean;
    RETURN s
  END NewBooleanVar;

PROCEDURE (v: BooleanVar) StringToValue* (str: STRING)
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
      RAISE(NEW(Exception.ParseError, wrongFormat, start));
    END
  END StringToValue;

PROCEDURE (v: BooleanVar) ToString*(): STRING;
  BEGIN
    IF v.boolean THEN
      RETURN "TRUE";
    ELSE
      RETURN "FALSE";
    END
  END ToString;

PROCEDURE (v: BooleanVar) Clone* (): BooleanVar;
  VAR
    clone: BooleanVar;
  BEGIN
    NEW (clone);
    clone^ := v^;
    RETURN clone
  END Clone;



PROCEDURE NewIntegerVar* (int: LONGINT): IntegerVar;
  VAR
    s: IntegerVar;
  BEGIN
    NEW (s);
    s. integer := int;
    RETURN s
  END NewIntegerVar;

PROCEDURE (v: IntegerVar) StringToValue* (str: STRING)
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
      RAISE(NEW(Exception.ParseError, wrongFormat, start));
    | IntStr.strOutOfRange:
      RAISE(NEW(Exception.ParseError, outOfRange, start));
    | IntStr.strEmpty:
      RAISE(NEW(Exception.ParseError, empty, start));
    END;
  END StringToValue;

PROCEDURE (v: IntegerVar) ToString*(): STRING;
  VAR
    str: ARRAY 16 OF CHAR;
  BEGIN
    IntStr.IntToStr(v.integer, str);
    RETURN Object.NewLatin1(str);
  END ToString;

PROCEDURE (v: IntegerVar) Clone* (): IntegerVar;
  VAR
    clone: IntegerVar;
  BEGIN
    NEW (clone);
    clone^ := v^;
    RETURN clone
  END Clone;


PROCEDURE NewStringVar* (str: Object.String8): StringVar;
  VAR
    s: StringVar;
  BEGIN
    NEW (s);
    s.string := str;
    RETURN s
  END NewStringVar;

PROCEDURE (v: StringVar) StringToValue* (str: STRING);
  BEGIN
    v.string := str;
  END StringToValue;

PROCEDURE (v: StringVar) ToString*(): STRING;
  BEGIN
    RETURN v.string;
  END ToString;

PROCEDURE (v: StringVar) Clone* (): StringVar;
  VAR
    clone: StringVar;
  BEGIN
    NEW (clone);
    clone^ := v^;
    RETURN clone
  END Clone;


PROCEDURE SetPrototype*(map: PrototypeMap; name: STRING; prototype: Variable);
  BEGIN
    map.Set(name, prototype);
  END SetPrototype;

PROCEDURE GetClone*(map: PrototypeMap; prototypeName: STRING): Variable;
  VAR
    ptr: Variable;
  BEGIN
    ptr := map.Get(prototypeName);
    IF (ptr = NIL) THEN
      RETURN NIL
    ELSE
      RETURN ptr.Clone();
    END
  END GetClone;

END Config.
