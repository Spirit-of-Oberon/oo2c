MODULE H2O:Translate;

IMPORT 
  IO:TextRider, IO, IO:FileChannel, E := Exception, Out, Err, Log,
  ADT:Dictionary, ADT:StringBuffer,
  H2O:Option,
  H2O:Type, H2O:Scanner, H2O:Emitter, H2O:Value, H2O:Process, H2O:Parser,
  H2O:Variant;

CONST
  debugProgress = FALSE;

TYPE
  EnumProc = PROCEDURE(obj : Type.Object; e : Emitter.Emitter);

TYPE
  RewriteProcedures = POINTER TO RewriteProceduresDesc;
  RewriteProceduresDesc = RECORD (Type.VisitorDesc)
  END;

VAR
  seq : LONGINT;
  e : Emitter.Emitter;
  rewriteProcedures : RewriteProcedures;

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
  mapEnum : Option.String;
  mapVoid : Option.String;
  moduleSuffix : Option.String;
  outputDirectory : Option.String;
  renameVariables : Option.Boolean;
  renameProcedures : Option.Boolean;
  tagSuffix : Option.String;
  autoPrefix : Option.String;

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

PROCEDURE GetName(t : Type.Type) : STRING;
VAR
  name : STRING;
BEGIN
  ASSERT(Type.IsNamedType(t));
  IF Type.IsTaggedType(t) THEN
    name := t.name + tagSuffix.value
  ELSE
    name := t.name;
  END;
  RETURN t.module.MapName(name);
END GetName;

PROCEDURE QualName(t : Type.Type; mod : Type.Module) : STRING;
VAR b : StringBuffer.StringBuffer;
BEGIN
  b := StringBuffer.New("");
  IF t.module # mod THEN
    b.Append(t.module.outputName.value);
    b.AppendLatin1(".");
  END;
  b.Append(GetName(t));
  RETURN b.ToString();
END QualName;

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
        t.class := Type.tArray;
        t.size := -1
      END;
    | Type.tArray:
      IF Variant.pointer IN t.variant THEN 
        t.class := Type.tPointer 
      END;
    ELSE
    END;
    alias := Type.FindAliasTypeModule(mod, t, FALSE);
    IF alias # NIL THEN
      t := alias;
    ELSE
      base := t.base;
      buf := StringBuffer.New("");
      buf.Append(autoPrefix.value);
      CASE t.class OF
      | Type.tArray:    
          buf.Append("Array");
          IF t.size # -1 THEN buf.AppendInt(t.size) END;
      | Type.tPointer:  buf.Append("Ptr");
      | Type.tFunction: buf.Append("Procedure");
      | Type.tEnum:     buf.Append("Enum");
      END;
      IF (base # NIL) & Type.IsNamedType(base) THEN
        buf.Append(GetName(base))
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
      IF (t.class = Type.tPointer) THEN
        IF ~(Variant.defined IN o.variant)
          & ~Type.IsPointerBaseType(t.base.Base())
          & mod.defaultVar.value THEN
          o.variant := o.variant + {Variant.defined, Variant.var};
        END;
        IF (Variant.var IN o.variant)
          & ~Type.IsPointerBaseType(t.base) THEN
          DeclareType(t.base, mod)
        ELSE
          DeclareType(t, mod)
        END
      ELSE
        DeclareType(t, mod)
      END
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

PROCEDURE EliminateAliases(VAR t : Type.Type; mod : Type.Module);
VAR
  alias : Type.Type;
BEGIN
  alias := Type.FindAliasTypeModule(mod, t, FALSE);
  IF alias # NIL THEN
    t := alias;
  ELSE
  END;
END EliminateAliases;

(*
PROCEDURE (v : RewriteAliases) AcceptPost* (VAR t : Type.Type; mod : Type.Module);
BEGIN
  EliminateAliases(t, mod);
END AcceptPost;

PROCEDURE (v : RewriteAliases) INIT*;
BEGIN
  v.type := { Type.post};
END INIT;
*)

PROCEDURE ^RewriteAliases(VAR t : Type.Type; mod : Type.Module);

PROCEDURE RewriteAliasesObjects(o : Type.Object; mod : Type.Module; par : BOOLEAN);
BEGIN
  WHILE o # NIL DO
    IF par & (Variant.var IN o.variant) THEN
      RewriteAliases(o.type.base, mod);
    ELSE
      RewriteAliases(o.type, mod);
    END;
    o := o.next;
  END;
END RewriteAliasesObjects;

PROCEDURE RewriteAliases(VAR t : Type.Type; mod : Type.Module);
BEGIN
  IF t.module # mod THEN RETURN END;

  IF t.class IN { Type.tFunction, Type.tStruct, Type.tUnion } THEN
    RewriteAliasesObjects(t.link, mod, t.class = Type.tFunction)
  END;
  IF t.class = Type.tPointer THEN
    IF ~Type.IsNamedType(t.base (* .Base() *)) THEN
      RewriteAliases(t.base, mod);
    END;
  ELSIF t.class IN { Type.tFunction, Type.tArray, Type.tQualifier } THEN
    RewriteAliases(t.base, mod);
  END;
  EliminateAliases(t, mod);
END RewriteAliases;

PROCEDURE RewriteAliasesList(o : Type.Object; mod : Type.Module);
BEGIN
  WHILE o # NIL DO
    IF o.type.class = Type.tName THEN
      RewriteAliases(o.type.base, mod);
    END;
    o := o.next;
  END;
END RewriteAliasesList;

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
    IF var THEN
      e.WriteString(" [NIL_COMPAT]");
    END;
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
  IF t.base.Base() # Type.voidType THEN
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
    e.WriteString("POINTER ");
    IF Variant.cstring IN t.variant THEN
      e.WriteString("[CSTRING] ");
    END;
    e.WriteString("TO ARRAY OF ");
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
    IF (t.name # NIL) THEN
      e.WriteObject(QualName(t, mod));
    ELSE
      WriteRecordType(e, t, mod, level);
    END;
  | Type.tName:
    e.WriteObject(QualName(t, mod));
  | Type.tPointer:
    WritePointerType(e, t, mod, level);
  | Type.tQualifier:
    WriteType(e, t.base, mod, level);
  | Type.tArray:
    WriteArrayType(e, t, mod, level);
  | Type.tEnum:
    e.WriteObject(mapEnum.value);
    e.WriteString(" (* enumerated type *)");
  | Type.tVoid:
    e.WriteObject(mapVoid.value);
  ELSE
    e.WriteString("UNIMPLEMENTED TYPE: ");
    e.WriteObject(t);
  END;
END WriteType;

PROCEDURE WriteTypeDeclaration(e : Emitter.Emitter; t : Type.Type; mod : Type.Module; level : INTEGER);
BEGIN
  IF t.class IN {Type.tStruct, Type.tUnion} THEN
    WriteRecordType(e, t, mod, level);
  ELSE
    WriteType(e, t, mod, level);
  END;
END WriteTypeDeclaration;

PROCEDURE DeclName(e : Emitter.Emitter; name : STRING; mod : Type.Module);
BEGIN
  e.WriteObject(mod.MapName(name));
  e.WriteObject("* = ");
END DeclName;

PROCEDURE EmitTypeDeclaration* (name : STRING; type : Type.Type; mod : Type.Module; e : Emitter.Emitter);
VAR
  base : Type.Type;
  canConvert : BOOLEAN;
BEGIN
  IF Type.IsNamedType(type) THEN
    IF Variant.emitted IN type.variant THEN
      RETURN
    END;
  END;
  base := type.Base();
  canConvert := ~((base.class = Type.tVoid) OR (base.class = Type.tFunction));

  e.DeclType(Emitter.dtType);
  IF ~canConvert THEN
    e.WriteString("(* ");
  END;
  e.Indent(1);
  DeclName(e, name, mod);
  (* always dereference "Name" types *)
  IF type.class = Type.tName THEN
    WriteTypeDeclaration(e, type.base, mod, 1);
  ELSE
    WriteTypeDeclaration(e, type, mod, 1);
  END;
  e.WriteChar(";");
  IF ~canConvert THEN
    e.WriteString("*)");
  END;
  e.WriteLn;
  INCL(type.variant, Variant.emitted)
END EmitTypeDeclaration;

PROCEDURE DeclNameFlags(e : Emitter.Emitter; name : STRING; mod : Type.Module; flagsBeforeName : BOOLEAN; doMapNames : BOOLEAN);
VAR mapName : STRING;
BEGIN
  IF doMapNames THEN
    mapName := mod.MapName(name);
  ELSE
    mapName := name;
  END;
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
    DeclNameFlags(e, obj.name, obj.module, FALSE, renameVariables.value);
    e.WriteString(": ");
    WriteType(e, t, obj.module, 1);
    e.WriteChar(";");
    e.WriteLn;
  END;
END TranslateVar;

PROCEDURE TranslateProc(obj : Type.Object; e : Emitter.Emitter);
VAR
  t : Type.Type;
  validProcType : BOOLEAN;
BEGIN
  t := obj.type;
  IF t.class = Type.tFunction THEN
    validProcType := Type.IsValidProcedureType(t);
    e.Indent(1);
    IF ~validProcType THEN e.WriteString("(* ") END;
    e.WriteString("PROCEDURE ");
    DeclNameFlags(e, obj.name, obj.module, TRUE, renameProcedures.value);
    WriteParams(e, obj.type, obj.module, 1);
    e.WriteChar(";");
    IF ~validProcType THEN e.WriteString(" *)") END;
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
  o : Type.Object;

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

  PROCEDURE ^EmitReferencedObjects(o : Type.Object);

  PROCEDURE EmitReferencedTypes(t : Type.Type);
  VAR base : Type.Type;
  BEGIN
    IF t.class IN { Type.tFunction, Type.tStruct, Type.tUnion} THEN
      EmitReferencedObjects(t.link);
    END;
    IF t.class = Type.tPointer THEN
      base := t.base.Base();
      IF base.class IN {Type.tStruct, Type.tUnion} THEN
      ELSE
        EmitReferencedTypes(t.base);
      END;
    ELSIF t.class IN {Type.tName, Type.tFunction, Type.tArray, Type.tQualifier} THEN
      EmitReferencedTypes(t.base);
    END;
    IF Type.IsNamedType(t) THEN
      IF (t.module = m) THEN
        EmitTypeDeclaration(GetName(t), t, t.module, e);
      END;
    END;
  END EmitReferencedTypes;

  PROCEDURE EmitReferencedObjects(o : Type.Object);
  BEGIN
    WHILE o # NIL DO
      EmitReferencedTypes(o.type);
      o := o.next;
    END;
  END EmitReferencedObjects;

  PROCEDURE EmitTypes(o : Type.Object);
  BEGIN
    WHILE o # NIL DO
      IF o.type.class = Type.tName THEN
        EmitReferencedTypes(o.type.base);
      ELSE
        EmitReferencedTypes(o.type);
      END;
      EmitTypeDeclaration(o.name, o.type, o.module, e);
      o := o.next;
    END;
  END EmitTypes;

  PROCEDURE EmitEnums(o : Type.Object);
  VAR t : Type.Type; elem : Type.Object;
  BEGIN
    WHILE o # NIL DO
      t := o.type;
      IF (t.class = Type.tEnum) & (t.link # NIL) THEN
        e.DeclType(Emitter.dtConst);
        e.Indent(1);
        e.WriteString("(* Constants occurring in enumeration '");
        e.WriteObject(o.name);
        e.WriteString("' *)");
        e.WriteLn;
        elem := t.link;
        WHILE elem # NIL DO
          e.Indent(1);
          DeclName(e, elem.name, o.module);
          e.WriteInt(elem.addr);
          e.WriteString(";");
          e.WriteLn;
          elem := elem.next;
        END;
      END;
      o := o.next;
    END;
  END EmitEnums;

BEGIN
  name := outputDirectory.value + "/" + 
    m.outputName.value + "." + moduleSuffix.value;
TRY
  file := FileChannel.OpenUnbuffered(name, {FileChannel.write, FileChannel.create, FileChannel.truncate});
  writer := TextRider.ConnectWriter(file);
  e := NEW(Emitter.Emitter, writer);
  e.WriteString("MODULE ");
  e.WriteObject(m.outputName.value);
  e.WriteString(' [ INTERFACE "');
  e.WriteObject(m.interfaceType.value);
  e.WriteString('"');
  IF (m.linkFramework.value.size > 0) OR (m.linkLib.value.size > 0) OR (m.linkFile.value.size > 0) THEN
    e.WriteString("; LINK ");
    depCount := 0;
    ListDependencies(depCount, "FRAMEWORK", m.linkFramework);
    ListDependencies(depCount, "LIB", m.linkLib);
    ListDependencies(depCount, "FILE", m.linkFile);
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
  IF debugProgress THEN Log.Msg("ParseMacros") END;
  Parser.ParseMacros(e, m);
  IF debugProgress THEN Log.Msg("EmitEnums"); END;
  EmitEnums(m.types);

  IF debugProgress THEN Log.Msg("EmitTypes"); END;
  EmitTypes(m.types);
  IF debugProgress THEN Log.Msg("EmitTypeDefs"); END;
  EmitTypes(m.typedefs);
  IF debugProgress THEN Log.Msg("TranslateVar"); END;
  Enum(m.vars, e, TranslateVar);
  IF debugProgress THEN Log.Msg("TranslateProc"); END;
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

PROCEDURE ProcessModule(m : Type.Module);

  PROCEDURE TranslateImportedModules;
  VAR i : LONGINT; mod : Type.Module;
  BEGIN
    FOR i := 0 TO m.imports.Size() -1 DO
      mod := m.imports.Get(i);
      IF ~mod.visited THEN
        ProcessModule(mod);
      END;
    END;
  END TranslateImportedModules;

BEGIN
  TranslateImportedModules;
  m.visited := TRUE;
  Log.Object("Processing", m.name);

  seq := 0;
  ApplyRules(m.types);
  ApplyRules(m.typedefs);
  ApplyRules(m.vars);
  Type.TraverseTypes(m, rewriteProcedures);
  RewriteAliasesList(m.types, m);
  RewriteAliasesList(m.typedefs, m);
  RewriteAliasesList(m.vars, m);
  (* Type.TraverseTypes(m, rewriteAliases); *)
  IF m.definitions > 0 THEN
    TranslateModule(m);
  END;
END ProcessModule;

PROCEDURE Translate* ();
VAR m : Type.Module;
BEGIN
  m := Type.modules;
  WHILE m # NIL DO
    IF ~m.visited THEN ProcessModule(m) END;
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
  mapEnum := options.String("MapEnum", "LONGINT");
  mapVoid := options.String("MapVoid", "C_VOID");
  outputDirectory := options.String("OutputDirectory", ".");
  renameVariables := options.Boolean("RenameVariables", FALSE);
  renameProcedures := options.Boolean("RenameProcedures", TRUE);
  tagSuffix := options.String("TagSuffix", "_tag");
  autoPrefix := options.String("AutoPrefix", "Auto");

  moduleSuffix := options.String("ModuleSuffix", "Mod");
END InitOptions;

BEGIN
  InitOptions;
  rewriteProcedures := NEW(RewriteProcedures);
  (* rewriteAliases := NEW(RewriteAliases); *)
END H2O:Translate.
