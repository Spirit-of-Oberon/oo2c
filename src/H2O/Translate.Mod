MODULE H2O:Translate;

IMPORT 
  IO:TextRider, IO, IO:FileChannel, E := Exception, Out, Err, Log,
  ADT:Dictionary, ADT:StringBuffer,
  H2O:Option,
  H2O:Type, H2O:Scanner, H2O:Emitter, H2O:Value, H2O:Process, H2O:Parser,
  H2O:Variant;

TYPE
  EnumProc = PROCEDURE(obj : Type.Object; e : Emitter.Emitter);

TYPE
  RewriteProcedures = POINTER TO RewriteProceduresDesc;
  RewriteProceduresDesc = RECORD (Type.VisitorDesc)
  END;

  RewriteAliases = POINTER TO RewriteAliasesDesc;
  RewriteAliasesDesc = RECORD (Type.VisitorDesc)
  END;

  ApplyDefaultVariants = POINTER TO ApplyDefaultVariantsDesc;
  ApplyDefaultVariantsDesc = RECORD (Type.VisitorDesc)
  END;

VAR
  seq : LONGINT;
  e : Emitter.Emitter;
  rewriteProcedures : RewriteProcedures;
  rewriteAliases : RewriteAliases;
  applyDefaultVariants : ApplyDefaultVariants;

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
  mapPointer : Option.String;
  moduleSuffix : Option.String;
  outputDirectory : Option.String;

(*
Elimination of type constructors:

1: POINTER TO T             {pointer}
2: POINTER TO ARRAY OF T    {pointer,array}
3: ARRAY OF T               {array}
4: VAR T                    {var}
5: VAR ARRAY OF T           {var,array}

POINTER TO T (non-parameter)
  record    1, 2
  array     2
  other     2

POINTER TO T (parameter)
  record    1, 2, 3, 4, 5
  array     2, 5
  other     2, 3, 4, 5

ARRAY OF T (parameter)
            3, 5
*)

PROCEDURE DeclareType(VAR t : Type.Type; mod : Type.Module);
VAR 
  alias, base : Type.Type;
  buf : StringBuffer.StringBuffer;
  name : STRING;
BEGIN
  IF t.IsConstructor() THEN
    CASE t.class OF
    | Type.tPointer:
      IF Variant.array IN t.variant THEN 
        Log.Set("Variant", t.variant);
        Log.Object("PointerToArray", t);
        t.class := Type.tArray;
        t.size := -1
      END;
    | Type.tArray:
      IF Variant.pointer IN t.variant THEN 
        Log.Object("ArrayToPointer", t);
        t.class := Type.tPointer 
      END;
    ELSE
    END;
    Log.Object("DeclareType", t);
    Log.Object("InModule", mod.name);
    alias := Type.FindAliasTypeModule(mod, t);
    Log.Object("FoundAlias", alias);
    IF alias # NIL THEN
    Log.Object("InModule", alias.module.name);
      t := alias;
    ELSE
      base := t.base;
      buf := StringBuffer.New("Auto");
      CASE t.class OF
      | Type.tPointer:  buf.Append("Ptr");
      | Type.tArray:    buf.Append("Array");
      | Type.tFunction: buf.Append("Procedure");
      | Type.tEnum:     buf.Append("Enum");
      END;
      IF Type.IsNamedType(base) THEN
        buf.Append(base.name)
      ELSE
        buf.AppendInt(seq); INC(seq);
      END;
      name := buf.ToString();

      t := Type.NewType(Type.tName, t, t.size, {}); 
      t.name := name;
      t.module := mod;
      Parser.Install(Type.typedefs, mod, "Type", name, t, FALSE);
    END;
  END;
END DeclareType;

PROCEDURE EliminateConstructors(VAR t : Type.Type; o : Type.Object; mod : Type.Module);
BEGIN
  IF Type.IsTypeConstructor(t) THEN
    IF (o # NIL) THEN
      IF (t.class = Type.tPointer) 
       & (Variant.var IN o.variant) 
       & ~Type.IsPointerBaseType(t.base) THEN
        DeclareType(t.base, mod)
      ELSE
        DeclareType(t, mod)
      END;
    ELSE
      DeclareType(t, mod)
    END;
  END;
END EliminateConstructors;

PROCEDURE (v : RewriteProcedures) AcceptPost* (VAR t : Type.Type; mod : Type.Module);
VAR o : Type.Object;
BEGIN
  IF t.class = Type.tFunction THEN
    EliminateConstructors(t.base, NIL, mod);
    o := t.link;
    WHILE o # NIL DO
      EliminateConstructors(o.type, o, mod);
      o := o.next;
    END;
  END;
END AcceptPost;

PROCEDURE (v : RewriteProcedures) INIT*;
BEGIN
  v.type := { Type.post};
END INIT;

PROCEDURE ApplyDefaultVariant(VAR t : Type.Type; param : BOOLEAN; mod : Type.Module);
BEGIN
  IF t.variant = {} THEN
  END;
END ApplyDefaultVariant;

PROCEDURE (v : ApplyDefaultVariants) AcceptPost* (VAR t : Type.Type; mod : Type.Module); 
VAR o : Type.Object;
BEGIN
  IF t.class = Type.tFunction THEN
    ApplyDefaultVariant(t.base, FALSE, mod);
    o := t.link;
    WHILE o # NIL DO
      ApplyDefaultVariant(o.type, TRUE, mod);
      o := o.next;
    END;
  END;
END AcceptPost;

PROCEDURE (v : ApplyDefaultVariants) INIT*;
BEGIN
  v.type := { Type.post};
END INIT;

PROCEDURE EliminateAliases(VAR t : Type.Type; mod : Type.Module);
VAR
  alias : Type.Type;
BEGIN
  alias := Type.FindAliasTypeModule(mod, t);
  IF alias # NIL THEN
    t := alias;
  ELSE
  END;
END EliminateAliases;

PROCEDURE (v : RewriteAliases) AcceptPost* (VAR t : Type.Type; mod : Type.Module);
BEGIN
  EliminateAliases(t, mod);
END AcceptPost;

PROCEDURE (v : RewriteAliases) INIT*;
BEGIN
  v.type := { Type.post};
END INIT;

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

PROCEDURE ^WriteType(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);

PROCEDURE WriteParams(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
VAR 
  obj : Type.Object;
  buf : StringBuffer.StringBuffer;
  pos : LONGINT;
  name : STRING;
  base : Type.Type;
  var : BOOLEAN;
BEGIN
  Log.Object("WriteParams", t);
  e.WriteChar("(");
  obj := t.link;
  pos := 0;
  WHILE obj # NIL DO
    name := obj.name;
    (* var := (base.class = Type.tPointer) & ~Type.IsPointerBaseType(base.base.Base()); *)
    var := Variant.var IN obj.variant;
    IF var THEN
      e.WriteString("VAR ");
    END;
    IF name = NIL THEN
      buf := StringBuffer.New("p");
      buf.AppendInt(pos);
      name := buf.ToString();
    END;
    e.WriteObject(name);
    e.WriteString(" : ");
    IF var THEN
      WriteType(e, obj.type.base, mod, level);
    ELSE
      WriteType(e, obj.type, mod, level);
    END;
    obj := obj.next;
    IF obj # NIL THEN e.WriteString("; ") END;
    INC(pos);
  END;
  e.WriteString(")");
  IF t.base # Type.voidType THEN
    e.WriteString(" : ");
    WriteType(e, t.base, mod, level);
  END;
END WriteParams;

PROCEDURE WriteProcedureType(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
BEGIN
  e.WriteString("PROCEDURE");
  WriteParams(e, t, mod, level);
END WriteProcedureType;

PROCEDURE WritePointerType(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
VAR
  base : Type.Type;
BEGIN
  base := t.base.Base();
  CASE base.class OF
  | Type.tFunction:
    WriteProcedureType(e, base, mod, level);
  | Type.tVoid:
    e.WriteObject(mapPointer.value);
  | Type.tStruct, Type.tUnion, Type.tArray:
    e.WriteString("POINTER TO ");
    WriteType(e, t.base, mod, level);
  ELSE
    e.WriteString("POINTER TO ARRAY OF ");
    WriteType(e, t.base, mod, level);
  END;
END WritePointerType;

PROCEDURE WriteArrayType(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
BEGIN
  e.WriteString("ARRAY ");
  IF t.size >= 0 THEN
    e.WriteInt(t.size); e.WriteChar(" ");
  END;
  e.WriteString("OF ");
  WriteType(e, t.base, mod, level);
END WriteArrayType;

PROCEDURE WriteRecordType(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
VAR obj : Type.Object;
BEGIN
  e.WriteString("RECORD"); 
  IF t.class = Type.tUnion THEN
    e.WriteString(" [UNION]");
  END;
  IF t.link # NIL THEN
    e.WriteLn;
    obj := t.link;
    WHILE obj # NIL DO
      e.Indent(level+1);
      e.WriteObject(obj.name); e.WriteString("* : ");
      WriteType(e, obj.type, mod, level+1);
      e.WriteString(";"); e.WriteLn;
      obj := obj.next;
    END;
    e.Indent(level); 
  ELSE
    e.WriteChar(" ");
  END;
  e.WriteString("END");
END WriteRecordType;

PROCEDURE WriteType(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
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
  | Type.tStruct, Type.tUnion:
    IF t.name # NIL THEN
      e.WriteObject(t.name);
    ELSE
      WriteRecordType(e, t, mod, level);
    END;
  | Type.tName:
    IF t.module # mod THEN
      e.WriteObject(t.module.outputName.value);
      e.WriteChar(".");
    END;
    e.WriteObject(t.module.MapName(t.name));
  | Type.tPointer:
    WritePointerType(e, t, mod, level);
  | Type.tQualifier:
    WriteType(e, t.base, mod, level);
  | Type.tArray:
    WriteArrayType(e, t, mod, level);
  | Type.tVoid:
    e.WriteString("C_VOID");
  ELSE
    e.WriteString("UNIMPLEMENTED TYPE: ");
    e.WriteObject(t);
  END;
END WriteType;

PROCEDURE DeclName(e : Emitter.Emitter; name : STRING; mod : Type.Module);
BEGIN
  e.WriteObject(mod.MapName(name));
  e.WriteObject("* = ");
END DeclName;

PROCEDURE TranslateType(obj : Type.Object; e : Emitter.Emitter);
VAR 
  type : Type.Type;
  base : Type.Type;
  canConvert : BOOLEAN;
BEGIN
  type := obj.type;;
  base := type.Base();
  canConvert := ~((base.class = Type.tVoid) OR (base.class = Type.tFunction));

  e.DeclType(Emitter.dtType);
  IF ~canConvert THEN
    e.WriteString("(* ");
  END;
  e.Indent(1);
  DeclName(e, obj.name, obj.module);
  (* always dereference "Name" types *)
  IF type.class = Type.tName THEN
    WriteType(e, type.base, obj.module, 1);
  ELSE
    WriteType(e, obj.type, obj.module, 1);
  END;
  e.WriteChar(";");
  IF ~canConvert THEN
    e.WriteString("*)");
  END;
  e.WriteLn;
END TranslateType;

PROCEDURE DeclNameFlags(e : Emitter.Emitter; name : STRING; mod : Type.Module; flagsBeforeName : BOOLEAN);
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
    WriteType(e, t, obj.module, 1);
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
     WriteParams(e, obj.type, obj.module, 1);
     e.WriteChar(";");
     e.WriteLn;
  END;
END TranslateProc;

PROCEDURE Enum(obj : Type.Object; e : Emitter.Emitter; p : EnumProc);
BEGIN
  WHILE obj # NIL DO
    p(obj, e);
    obj := obj.next;
  END;
END Enum;

PROCEDURE ApplyRules(obj : Type.Object);
BEGIN
  IF obj # NIL THEN
    Variant.ApplyRules(obj);
  END;
END ApplyRules;

PROCEDURE TranslateModule(m : Type.Module);
VAR 
  e : Emitter.Emitter;
  i : LONGINT;
  module : Type.Module;
  file : IO.ByteChannel;
  writer : TextRider.Writer;
  name : STRING;
  depCount : INTEGER;

  PROCEDURE ListDependencies(VAR count : INTEGER; type : STRING; list : Option.StringList);
  BEGIN
    FOR i := 0 TO list.value.size - 1 DO
      IF count > 0 THEN
        e.WriteString("; ");
      END;
      e.WriteObject(type);
      e.WriteString(' "');
      e.WriteObject(list.value.Get(i));
      e.WriteString('"');
      INC(count);
    END;
  END ListDependencies;

BEGIN
  name := outputDirectory.value + "/" + 
    m.outputName.value + "." + moduleSuffix.value;
TRY
  file := FileChannel.OpenUnbuffered(name, {FileChannel.write, FileChannel.create});
  writer := TextRider.ConnectWriter(file);
  e := NEW(Emitter.Emitter, writer);
  e.WriteString("MODULE ");
  e.WriteObject(m.outputName.value);
  e.WriteString(' [ INTERFACE "');
  e.WriteObject(m.interfaceType.value);
  e.WriteString('"');
  IF (m.linkFramework.value.size > 0) OR (m.linkLib.value.size > 0) THEN
    e.WriteString("; LINK ");
    depCount := 0;
    ListDependencies(depCount, "FRAMEWORK", m.linkFramework);
    ListDependencies(depCount, "LIB", m.linkLib);
    e.WriteString(" END");
  END;
  e.WriteString(" ];");
  e.WriteLn;
  e.WriteLn;
  e.WriteString("IMPORT SYSTEM");
  IF m.imports.Size() > 0 THEN
    FOR i := 0 TO m.imports.Size() - 1 DO 
      IF TRUE (* i > 0 *) THEN e.WriteString(", ") END;
      module := m.imports.Get(i);
      e.WriteObject(module.outputName.value);
    END;
  END;
  e.WriteChar(";");
  e.WriteLn;
  Parser.ParseMacros(e, m);

  Enum(m.types, e, TranslateType);
  Enum(m.typedefs, e, TranslateType);
  Enum(m.vars, e, TranslateVar);
  Enum(m.vars, e, TranslateProc);
  
  e.WriteString("END ");
  e.WriteObject(m.outputName.value);
  e.WriteString(".");
  e.WriteLn;
  file.Close();
CATCH E.Exception(e):
  Log.Object("TranslateModule", e.GetMessage());
END;
END TranslateModule;

PROCEDURE Translate* ();
VAR m : Type.Module;
BEGIN
  m := Type.modules;
  WHILE m # NIL DO
    Parser.ShowDepend(m.name, m.imports);
    m := m.next;
  END;

  m := Type.modules;
  seq := 0;
  WHILE m # NIL DO
    ApplyRules(m.types);
    ApplyRules(m.typedefs);
    ApplyRules(m.vars);
    (* Type.TraverseTypes(m, applyDefaultRules); *)
    Type.TraverseTypes(m, rewriteProcedures);
    (* Type.TraverseTypes(m, rewriteAliases); *)
    m := m.next;
  END; 

  m := Type.modules;
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
  mapPointer := options.String("MapPointer", "SYSTEM.PTR");
  outputDirectory := options.String("OutputDirectory", ".");

  moduleSuffix := options.String("ModuleSuffix", "Mod");
END InitOptions;

BEGIN
  InitOptions;
  rewriteProcedures := NEW(RewriteProcedures);
  rewriteAliases := NEW(RewriteAliases);
END H2O:Translate.
