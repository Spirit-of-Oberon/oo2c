MODULE H2O:Translate;

IMPORT 
  TextRider, Out,
  ADT:Dictionary,
  H2O:Option, H2O:Module,
  H2O:Type, H2O:Scanner, H2O:Emitter, H2O:Value, H2O:Process, H2O:Parser;

TYPE
  EnumProc = PROCEDURE(obj : Type.Object; e : Emitter.Emitter);

VAR
  e : Emitter.Emitter;

  options- : Option.Options;

  mapCharType : Option.String;  
  mapUnsignedCharType : Option.String;  
  mapShortType : Option.String;  
  mapUnsignedShortType : Option.String;  
  mapLongType : Option.String;  
  mapUnsignedLongType : Option.String;  
  mapLongLongType : Option.String;
  mapUnsignedLongLongType : Option.String;
  mapFloatType : Option.String;
  mapDoubleType : Option.String;
  mapLongDoubleType : Option.String;
  moduleSuffix : Option.String;

PROCEDURE MapNumber(e : Emitter.Emitter;
  size : LONGINT; m1, m2, m4, m8 : Option.String);
BEGIN
  CASE size OF
  | 1: e.WriteObject(m1.value);
  | 2: e.WriteObject(m2.value);
  | 4: e.WriteObject(m4.value);
  | 8: e.WriteObject(m8.value);
  END;
END MapNumber;

PROCEDURE WriteType(e : Emitter.Emitter; t : Type.Type);
BEGIN
  CASE t.class OF
  | Type.tInteger:
    MapNumber(e, t.size, 
      mapCharType, mapShortType, mapLongType, mapLongLongType);
  | Type.tUnsigned:
    MapNumber(e, t.size, 
      mapUnsignedCharType, mapUnsignedShortType, 
      mapUnsignedLongType, mapUnsignedLongLongType);
  | Type.tReal:
    MapNumber(e, t.size, NIL, NIL, mapFloatType, mapDoubleType);
  | Type.tName:
    WriteType(e, t.base);
  ELSE
    e.WriteString("UNIMPLEMENTED TYPE: ");
    e.WriteObject(t);
  END;
END WriteType;

PROCEDURE DeclName(e : Emitter.Emitter; name : STRING; mod : Module.Module);
BEGIN
  e.Indent(1);
  e.WriteObject(mod.MapName(name));
  e.WriteObject("* = ");
END DeclName;

PROCEDURE TranslateType(obj : Type.Object; e : Emitter.Emitter);
BEGIN
  e.DeclType(Emitter.dtType);
  DeclName(e, obj.name, obj.module);
  WriteType(e, obj.type);
  e.WriteLn;
END TranslateType;

PROCEDURE DeclNameFlags(e : Emitter.Emitter; name : STRING; mod : Module.Module; flagsBeforeName : BOOLEAN);
VAR mapName : STRING;
BEGIN
  mapName := mod.MapName(name);
  IF ~flagsBeforeName THEN 
    e.WriteObject(mapName); e.WriteString("* ") 
  END;
  IF ~mapName.Equals(name) THEN
    e.WriteString('["');
    e.WriteObject(name);
    e.WriteString('"] ');
  END;
  IF flagsBeforeName THEN 
    e.WriteObject(mapName); e.WriteString("* ") 
  END;
END DeclNameFlags;

PROCEDURE TranslateVar(obj : Type.Object; e : Emitter.Emitter);
VAR 
  t : Type.Type;
BEGIN
  t := obj.type;
  IF t.class # Type.tFunction THEN
    e.DeclType(Emitter.dtVar);
    e.Indent(1);
    DeclNameFlags(e, obj.name, obj.module, FALSE);
    e.WriteString(": ");
    WriteType(e, t);
    e.WriteChar(";");
    e.WriteLn;
  END;
END TranslateVar;

PROCEDURE TranslateProc(obj : Type.Object; e : Emitter.Emitter);
VAR
  t : Type.Type;
BEGIN
  t := obj.type;
  IF t.class = Type.tFunction THEN
     e.Indent(1);
     e.WriteString("PROCEDURE ");
     DeclNameFlags(e, obj.name, obj.module, TRUE);
     e.WriteChar(";");
     e.WriteLn;
  END;
END TranslateProc;

PROCEDURE Enum(obj : Type.Object; e : Emitter.Emitter; m : Module.Module; p : EnumProc);
BEGIN
  WHILE obj # NIL DO
    IF obj.module = m THEN
      p(obj, e);
    END;
    obj := obj.next;
  END;
END Enum;

PROCEDURE TranslateModule(m : Module.Module);
VAR 
  e : Emitter.Emitter;
  i : LONGINT;
  module : Module.Module;
BEGIN
  e := NEW(Emitter.Emitter, Out.writer);
  e.WriteString("MODULE ");
  e.WriteObject(m.outputName.value);
  e.WriteString(";");
  e.WriteLn;
  e.WriteLn;
  IF m.imports.Size() > 0 THEN
    e.WriteString("IMPORT ");
    FOR i := 0 TO m.imports.Size() - 1 DO 
      IF i > 0 THEN e.WriteString(", ") END;
      module := m.imports.Get(i);
      e.WriteObject(module.name);
    END;
  END;
  Parser.ParseMacros(e, m);
  Enum(Type.types, e, m, TranslateType);
  Enum(Type.typedefs, e, m, TranslateType);
  Enum(Type.vars, e, m, TranslateVar);
  Enum(Type.vars, e, m, TranslateProc);
  
  e.WriteString("END ");
  e.WriteObject(m.outputName.value);
  e.WriteString(".");
  e.WriteLn;
END TranslateModule;

PROCEDURE Translate* ();
VAR m : Module.Module;
BEGIN

  m := Module.modules;
  WHILE m # NIL DO
    IF m.definitions > 0 THEN
      TranslateModule(m);
    END;
    m := m.next;
  END;
END Translate;

PROCEDURE InitOptions;
BEGIN
  options := NEW(Option.Options);
  mapCharType := options.String("MapChar", "CHAR");
  mapUnsignedCharType := options.String("MapUnsignedChar", "CHAR");
  mapShortType := options.String("MapShort", "INTEGER");
  mapUnsignedShortType := options.String("MapUnsignedShort", "INTEGER");
  mapLongType := options.String("MapLong", "LONGINT");
  mapUnsignedLongType := options.String("MapUnsignedLong", "LONGINT");
  mapLongLongType := options.String("MapLongLong", "HUGEINT");
  mapUnsignedLongLongType := options.String("MapUnsignedLongLong", "HUGEINT");
  mapFloatType := options.String("MapFloat", "REAL");
  mapDoubleType := options.String("MapDouble", "LONGREAL");
  mapLongDoubleType := options.String("MapLongDouble", "LONGDOUBLE");

  moduleSuffix := options.String("ModuleSuffix", "Mod");
END InitOptions;

BEGIN
  InitOptions;
END H2O:Translate.
