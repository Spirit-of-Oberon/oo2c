MODULE H2O:Type;

IMPORT
  Obj := Object, ADT:StringBuffer, ADT:ArrayList, Log, Err, O := Object,
  H2O:Value, H2O:Option;

CONST 
  (* module name-spaces *)
  vars* = 0;
  types* = 1;
  typedefs* = 2;

  (* Object classes *)
  scNone* = 0;
  scStatic* = 1;
  scTypedef* = 2;
  scExtern* = 3;

  (* Type qualifiers *)
  tqVolatile* = 0;
  tqConst* = 1;
  tqCdecl* = 2;
  tqStdcall* = 3;
  tqClass* = 4;

  (* types *)

  tInteger * = 1;
  tUnsigned * = 2;
  tReal * = 3;
  tPointer * = 4;
  tArray * = 5;
  tVoid * = 6;
  tEnum * = 7;
  tFunction * = 8;
  tStruct * = 9;
  tUnion * = 10;
  tQualifier * = 11;
  tName * = 12;
  
  (* Tree traversal types *)

  pre* = 0;
  post* = 1;

TYPE
  Type* = POINTER TO TypeDesc;
  Object* = POINTER TO ObjectDesc;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc* = RECORD (O.ObjectDesc)
    imports- : ArrayList.ArrayList(Module);
    name- : STRING;
    next- : Module;
    definitions- : LONGINT;
(* All objects declared in the global scope (ie. variables and procedures) *)
    vars* : Object;

(* All types declared with type tags (ie. struct, union, enum) *)
    types* : Object;

(* All types declared via typedef *)
    typedefs* : Object;

    options- : Option.Options;

    stripPrefix- : Option.StringList;
    outputName- : Option.String;
    interfaceType- : Option.String;
    prolog- : Option.String; doneProlog* : BOOLEAN;
    epilog- : Option.String; doneEpilog* : BOOLEAN;
    linkFramework- : Option.StringList;
    linkLib- : Option.StringList;
    linkFile- : Option.StringList;
    userImport- : Option.StringList;
    defaultVar- : Option.Boolean;
    translate- : Option.Boolean;
    merge- : Option.Boolean;
    visited* : BOOLEAN;
  END;

  TypeDesc* = RECORD (Obj.ObjectDesc)
    class* : SHORTINT;		(* see tXXX above *)
    size* : LONGINT;
    base* : Type;
    link* : Object;
    name* : STRING;
    qualifiers* : SET;
    variant* : SET;
    module* : Module;
    visited* : BOOLEAN;
  END;

  ObjectDesc* = RECORD 
    name* : STRING;
    addr* : LONGINT;
    type* : Type;
    qualifiers* : SET;
    module* : Module;
    variant* : SET;
    next* : Object;
  END;

  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
    type* : SET;
  END;

VAR
  intType-, unsignedIntType-,
  shortType-, unsignedShortType-,
  longType-, unsignedLongType-,
  longLongType-, unsignedLongLongType-,
  floatType-, doubleType-, longDoubleType-,
  charType-, unsignedCharType-, voidType- : Type;
  wCharType-, unsignedWCharType- : Type;

  modules- : Module;
  reserved- : ArrayList.ArrayList(STRING);

  options* : Option.Options;
  allowRedefinedProc : Option.Boolean;
  allowRedefined : Option.Boolean;

CONST
  pointerSize* = 4;

PROCEDURE (v : Visitor) AcceptPre* (VAR t : Type; mod : Module);
BEGIN
END AcceptPre;

PROCEDURE (v : Visitor) AcceptPost* (VAR t : Type; mod : Module);
BEGIN
END AcceptPost;

PROCEDURE (t : Type) IsConstructor* () : BOOLEAN;
BEGIN
  CASE t.class OF
  tFunction,
  tEnum, 
  tStruct, tUnion,
  tArray,
  tPointer:
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END IsConstructor;

PROCEDURE (t : Type) Size* () : LONGINT;
VAR size, sum, max : LONGINT;

  PROCEDURE AggregateSize(obj : Object; VAR sum, max : LONGINT);
  VAR size : LONGINT;
  BEGIN
    sum := 0; max := 0;
    WHILE obj # NIL DO
      size := obj.type.Size();
      IF size > max THEN max := size END;
      sum := sum + size;
      obj := obj.next;
    END;
  END AggregateSize;

BEGIN
  CASE t.class OF
  | tInteger, tUnsigned, tReal:
    RETURN t.size;
  | tPointer:
    RETURN pointerSize;
  | tEnum:
    RETURN intType.Size();
  | tArray:
    size := t.size; IF size < 0 THEN size := 0 END;
    RETURN size * t.base.Size();
  | tQualifier, tName:
    RETURN t.base.Size();
  | tVoid, tFunction:
    RETURN 0;
  | tStruct, tUnion:
    AggregateSize(t.link, sum, max);
    IF t.class = tStruct THEN RETURN sum ELSE RETURN max END;
  END;
END Size;

PROCEDURE (t : Type) Depend* (list : ArrayList.ArrayList(Module); src : Module);

  PROCEDURE Accumulate(module : Module);
  BEGIN
    IF (module # NIL) & ~list.Contains(module) THEN
      list.Append(module);
    END;
  END Accumulate;

  PROCEDURE Visit(t : Type);
  VAR o : Object;
  BEGIN
    IF t.visited THEN RETURN END;
    t.visited := TRUE;

    Accumulate(t.module);
    IF (t.module # src) & (t.module # NIL) THEN
    ELSE
      CASE t.class OF
      | tFunction, tArray, tPointer, tName:
        Visit(t.base);
      ELSE
      END;

      CASE t.class OF
      | tStruct, tUnion, tFunction:
        o := t.link;
        WHILE o # NIL DO
          Visit(o.type); 
          o := o.next
        END
      ELSE
      END
    END;
    t.visited := FALSE;
  END Visit;

BEGIN
  list.Clear;
  Visit(t);
END Depend;

PROCEDURE (t : Type) ToString* () : STRING;
VAR
  b : StringBuffer.StringBuffer;
  o : Object;
BEGIN
  b := StringBuffer.New("");
  CASE t.class OF
  | tArray:
    b.Append(t.base); b.AppendLatin1Char("[");
    IF t.size >= 0 THEN b.AppendInt(t.size) END;
    b.AppendLatin1Char("]");
  | tPointer:
    b.Append(t.base); b.AppendLatin1Char("*");
  | tFunction:
    b.Append(t.base);
    b.AppendLatin1Char("(");
    o := t.link;
    WHILE o # NIL DO
      b.Append(o.type);
      o := o.next;
      IF o # NIL THEN b.AppendLatin1Char(",") END;
    END;
    b.AppendLatin1Char(")");
  | tStruct:
    b.Append("struct ");
    IF t.name # NIL THEN b.Append(t.name) END;
  | tUnion:
    b.Append("union ");
    IF t.name # NIL THEN b.Append(t.name) END;
  | tEnum:
    b.Append("enum ");
    IF t.name # NIL THEN b.Append(t.name) END;
  | tQualifier:
    IF tqVolatile IN t.qualifiers THEN
      b.Append("volatile ");
    END;
    IF tqConst IN t.qualifiers THEN
      b.Append("const ");
    END;
    b.Append(t.base);
  | tName:
    b.Append(t.name);
  ELSE
    IF t.name # NIL THEN b.Append(t.name) ELSE b.Append("?TYPE?") END;
  END;
  RETURN b.ToString();
END ToString;

PROCEDURE (t : Type) Base* () : Type;
BEGIN
  WHILE t.class = tName DO
    t := t.base;
  END;
  RETURN t;
END Base;

PROCEDURE (t : Type) Unqualify* () : Type;
BEGIN
  WHILE t.class = tQualifier DO
    t := t.base;
  END;
  RETURN t;
END Unqualify;

PROCEDURE FindObjectLocal* (s : Object; name : STRING; VAR result : Object) : BOOLEAN;
BEGIN
  WHILE s # NIL DO
    IF name.Equals(s.name) THEN
      result := s;
      RETURN TRUE;
    END;
    s := s.next;
  END;
  RETURN FALSE;
END FindObjectLocal;

PROCEDURE FindObjectIndex* (s : Object; index : LONGINT; VAR result : Object) : BOOLEAN;
BEGIN
  ASSERT(index >= 0);
  WHILE s # NIL DO
    IF index = 0 THEN
      result := s;
      RETURN TRUE;
    END;
    DEC(index);
    s := s.next;
  END;
  RETURN FALSE;
END FindObjectIndex;

PROCEDURE FindObjectModule* (mod : Module; search : SET; name : STRING; VAR result : Object) : BOOLEAN;
BEGIN
  RETURN
    ((vars IN search) & FindObjectLocal(mod.vars, name, result)) OR
    ((types IN search) & FindObjectLocal(mod.types, name, result)) OR
    ((typedefs IN search) & FindObjectLocal(mod.typedefs, name, result));
END FindObjectModule;

PROCEDURE FindObject* (search : SET; name : STRING; VAR result : Object) : BOOLEAN;
VAR mod : Module;
BEGIN
  mod := modules;
  WHILE mod # NIL DO
    IF FindObjectModule(mod, search, name, result) THEN RETURN TRUE END;
    mod := mod.next;
  END;
  RETURN FALSE;
END FindObject;

(* Constants may be defined as part of Enum definitions. These may be used
from other modules as part of expressions. *)

PROCEDURE FindConstant* (name : STRING; VAR result : Value.Object; VAR mod : Module) : BOOLEAN;
VAR obj : Object; t : Type; const : Object;
BEGIN
  mod := modules;
  WHILE mod # NIL DO
    obj := mod.types;
    WHILE obj # NIL DO
      t := obj.type;
      IF t.class = tEnum THEN
        IF FindObjectLocal(t.link, name, const) THEN
          result := Value.NewLongInt(const.addr);
          RETURN TRUE;
        END;
      END;
      obj := obj.next;
    END;
    mod := mod.next;
  END;
  RETURN FALSE;
END FindConstant;

PROCEDURE AppendObject* (VAR s : Object; elem : Object);
VAR e : Object;
BEGIN
  elem.next := NIL;
  IF s = NIL THEN
    s := elem;
  ELSE
    e := s;
    WHILE e.next # NIL DO e := e.next END;
    e.next := elem;
  END;
END AppendObject;

PROCEDURE NewObject* (name : STRING; addr : LONGINT; type : Type; module : Module) : Object;
VAR o : Object;
BEGIN
  NEW(o);
  o.name := name;
  o.addr := addr;
  o.type := type;
  o.qualifiers := {};
  o.variant := {};
  o.module := module;
  o.next := NIL;
  RETURN o;
END NewObject;

PROCEDURE BindLocal* (VAR s : Object; name : STRING; addr : LONGINT; type : Type; mod : Module; tail : BOOLEAN);
VAR obj : Object;
BEGIN
  obj := NewObject(name, addr, type, mod);
  IF tail THEN
    AppendObject(s, obj);
  ELSE
    obj.next := s;
    s := obj;
  END;
END BindLocal;

PROCEDURE Bind* (scope : INTEGER; name : STRING; addr : LONGINT; type : Type; mod : Module; tail : BOOLEAN);
BEGIN
  CASE scope OF
  | types: BindLocal(mod.types, name, addr, type, mod, tail);
  | vars: BindLocal(mod.vars, name, addr, type, mod, tail);
  | typedefs: BindLocal(mod.typedefs, name, addr, type, mod, tail);
  END;
END Bind;

PROCEDURE NewType* (class : SHORTINT; base : Type; size : LONGINT; qual : SET) : Type;
VAR t : Type;
BEGIN
  NEW(t);
  t.class := class;
  t.base := base;
  t.size := size;
  t.link := NIL;
  t.name := NIL;
  t.qualifiers := qual;
  t.module := NIL;
  t.variant := {};
  t.visited := FALSE;

  RETURN t;
END NewType;

PROCEDURE BaseType* (class : SHORTINT; size : LONGINT; name : ARRAY OF CHAR) : Type;
VAR t : Type;
BEGIN
  t := NewType(class, NIL, size, {});
  t.name := Obj.NewLatin1(name);
  RETURN t;
END BaseType;

(* Some declarations are OK without defining a name. This is because they have
   a type tag which generates a declaration as a side-effect. *)

PROCEDURE TypeNeedsName* (t : Type) : BOOLEAN;
VAR class : INTEGER;
BEGIN
  class := t.class;
  RETURN ~
  ((class = tStruct) OR (class = tUnion) OR (class = tEnum));
END TypeNeedsName;

(* Determine if two types are the same. If <structural> is true, the test uses structural equivalence rather than name equivalence. *)

PROCEDURE SameTypes* (t1, t2 : Type; structural : BOOLEAN) : BOOLEAN;
CONST
  ignoreQualifiers = TRUE;

  PROCEDURE SameTypesList (o1, o2 : Object) : BOOLEAN;
  BEGIN
    WHILE ((o1 # NIL) & (o2 # NIL)) DO
      IF ~SameTypes(o1.type, o2.type, structural) THEN RETURN FALSE END;
      o1 := o1.next;
      o2 := o2.next;
    END;

    RETURN (o1 = NIL) & (o2 = NIL);
  END SameTypesList;

BEGIN
  ASSERT((t1 # NIL) & (t2 # NIL));

  IF structural THEN
    t1 := t1.Base(); t2 := t2.Base();
  END;

  IF ignoreQualifiers THEN
    WHILE t1.class = tQualifier DO t1 := t1.base END;
    WHILE t2.class = tQualifier DO t2 := t2.base END;
  END;

  IF (t1.class # t2.class) THEN RETURN FALSE END;
  CASE t1.class OF
  | tInteger, tUnsigned, tReal:
    RETURN t1.size = t2.size;
  | tPointer:
    RETURN SameTypes(t1.base, t2.base, structural)
  | tArray:
    RETURN SameTypes(t1.base, t2.base, structural) & (t1.size = t2.size)
  | tVoid, tEnum, tStruct, tUnion:
    RETURN t1 = t2;
  | tFunction:
    RETURN SameTypes(t1.base, t2.base, structural) & SameTypesList(t1.link, t2.link);
  | tQualifier:
    RETURN (t1.qualifiers = t2.qualifiers) & SameTypes(t1.base, t2.base, structural);
  | tName:
    RETURN t1 = t2;
  END;
END SameTypes;

(* In some situations a type may be redefined. In particular, this is allowed
if a structure or union is defined as an opaque type, and is later redefined.
*)

PROCEDURE AllowedRedefinition* (new, old : Type) : BOOLEAN;
BEGIN
  RETURN 
    (new.class = old.class) & (
       ((new.class IN {tStruct, tUnion}) & (old.link = NIL))
    OR ((new.class = tFunction) & allowRedefinedProc.value & SameTypes(new, old, FALSE)))
    OR allowRedefined.value;
END AllowedRedefinition;

(* Determine if a name is a valid output symbol *)

PROCEDURE IsLetter* (c : UCS4CHAR) : BOOLEAN;
BEGIN
  RETURN ((c >= 'A') & (c <= 'Z')) OR
    ((c >= 'a') & (c <= 'z'));
END IsLetter;

PROCEDURE IsDigit* (c : UCS4CHAR) : BOOLEAN;
BEGIN
  RETURN (c >= '0') & (c <= '9');
END IsDigit;

PROCEDURE ValidOutputSymbol(name : STRING) : BOOLEAN;
VAR c : UCS4CHAR;
BEGIN
  IF (name.length > 0) THEN
    c := name.CharAt(0);
    IF IsLetter(c) OR (c = '_') THEN
      RETURN ~reserved.Contains(name);
    END;
  END;
  RETURN FALSE
END ValidOutputSymbol;

PROCEDURE IsValidParameterType(t : Type) : BOOLEAN;
BEGIN
  RETURN ~ (t.class IN { tStruct, tUnion, tFunction });
END IsValidParameterType;

PROCEDURE IsValidResultType(t : Type) : BOOLEAN;
BEGIN
  RETURN ~ (t.class IN { tStruct, tUnion, tFunction, tArray });
END IsValidResultType;

PROCEDURE IsValidProcedureType* (t : Type) : BOOLEAN;
VAR o : Object;
BEGIN
  ASSERT(t.class = tFunction);
  IF IsValidResultType(t.base.Base()) THEN
    o := t.link;
    WHILE o # NIL DO
      IF ~IsValidParameterType(o.type.Base()) THEN
        RETURN FALSE
      END;
      o := o.next;
    END;
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END IsValidProcedureType;

(* Determine if a type is OK as a pointer base type *)

PROCEDURE IsPointerBaseType* (t : Type) : BOOLEAN;
BEGIN
  RETURN t.class IN { tArray, tStruct, tUnion };
END IsPointerBaseType;

(* Determine if a type is a type constructor *)

PROCEDURE IsTypeConstructor* (t : Type) : BOOLEAN;
BEGIN
  RETURN t.class IN { tFunction, tEnum, tStruct, tUnion, tArray, tPointer };
END IsTypeConstructor;
  
(* Find a declared type that is a equivalent to a given type constructor *)

PROCEDURE FindAliasTypeLocal* (obj : Object; t : Type; structural : BOOLEAN) : Type;
BEGIN
  IF t.class = tName THEN RETURN NIL END;
  WHILE obj # NIL DO
    IF (obj.type.base # t) & SameTypes(t, obj.type.base, structural) THEN
      (* Log.Object("Type", t);
      Log.Object("Alias", obj.type); *)
      RETURN obj.type
    END;
    obj := obj.next;
  END;
  RETURN NIL
END FindAliasTypeLocal;

PROCEDURE FindAliasTypeModule* (mod : Module; t : Type; structural : BOOLEAN) : Type;
VAR i : LONGINT; result : Type; imported : Module;
BEGIN
  result := FindAliasTypeLocal(mod.typedefs, t, structural);
  IF result # NIL THEN RETURN result END;
    
  FOR i := 0 TO mod.imports.Size()-1 DO
    imported := mod.imports.Get(i);
    result := FindAliasTypeLocal(imported.typedefs, t, structural);
    IF result # NIL THEN RETURN result END;
  END;
  RETURN NIL
END FindAliasTypeModule;

(* Determine if a type has a name *)

PROCEDURE IsTaggedType* (t : Type) : BOOLEAN;
BEGIN
  RETURN ((t.class IN {tEnum, tStruct, tUnion}) & (t.name # NIL));
END IsTaggedType;

PROCEDURE IsNamedType* (t : Type) : BOOLEAN;
BEGIN
  RETURN IsTaggedType(t) OR (t.class = tName);
END IsNamedType;

PROCEDURE ^VisitObjects(o : Object; mod : Module; v : Visitor);

PROCEDURE VisitType*(VAR t : Type; mod : Module; v : Visitor);
BEGIN
  IF pre IN v.type THEN
    v.AcceptPre(t, mod);
  END;
  IF t.class IN { tFunction, tStruct, tUnion } THEN
    VisitObjects(t.link, mod, v)
  END;
  IF t.class = tPointer THEN
    IF ~IsNamedType(t.base (* .Base() *)) THEN
      VisitType(t.base, mod, v);
    END;
  ELSIF t.class IN { tFunction, tArray, tQualifier } THEN
    VisitType(t.base, mod, v);
  END;
  IF post IN v.type THEN
    v.AcceptPost(t, mod);
  END;
END VisitType;

PROCEDURE VisitObjects(o : Object; mod : Module; v : Visitor);
BEGIN
  WHILE o # NIL DO
    (* Log.Object("OBJECT", o.name); Log.Object("OBJECTmodule", mod); *)
    VisitType(o.type, mod, v);
    o := o.next
  END;
END VisitObjects;

PROCEDURE VisitObjectsBase(o : Object; mod : Module; v : Visitor);
BEGIN
  WHILE o # NIL DO
    (* Log.Object("BASEOBJECT", o.type.name); Log.Object("BASEOBJECTmodule", mod); *)
    VisitType(o.type.base, mod, v);
    o := o.next
  END;
END VisitObjectsBase;

PROCEDURE TraverseTypes* (mod : Module; v : Visitor);
BEGIN
  (* Log.Object("MODULE", mod.name); *)
  VisitObjectsBase(mod.typedefs, mod, v);
  VisitObjects(mod.types, mod, v);
  VisitObjects(mod.vars, mod, v);
END TraverseTypes;

PROCEDURE (m : Module) AddImports* (list : ArrayList.ArrayList(Module));
VAR 
  i : LONGINT;
  mod : Module;
BEGIN
  FOR i := 0 TO list.size -1 DO
    mod := list.Get(i);
    IF (m # mod) & ~m.imports.Contains(mod) THEN
      m.imports.Append(mod);
      Err.String("MODULE "); Err.Object(m.name);
      Err.String(" IMPORTS "); Err.Object(mod.name);
      Err.Ln;
    END;
  END;
END AddImports;

PROCEDURE ModuleName* (fileName : STRING) : STRING;
(* Extract module name from file name. This is the portion of the file name
between the last directory separator, and the first extension. Eg:
  "test.h"  -> "test"
  "src.c/foo.h.h" -> "foo"
  "one" -> "one"
*)
VAR
  pos, slash, dot : INTEGER;
  ch : CHAR;
BEGIN
  pos := 0; slash := 0; dot := -1;
  LOOP
    ch := SHORT(SHORT(fileName.CharAt(pos)));
    CASE ch OF
    | 0X:   EXIT;
    | '/':  slash := pos+1; dot := -1;
    | '.':  IF dot < 0 THEN dot := pos END;
    ELSE
    END;
    INC(pos);
  END;
  IF dot < 0 THEN 
    dot := pos			(* no dot between slash and end of string *)
  END;
  RETURN fileName.Substring(slash, dot);
END ModuleName;

PROCEDURE FindModule* (name : STRING) : Module;
VAR m : Module;
BEGIN
  m := modules;
  WHILE m # NIL DO
    IF name.Equals(m.name) THEN
      RETURN m;
    END;
    m := m.next;
  END;
  RETURN NIL;
END FindModule;

PROCEDURE ShowModules;
VAR m : Module;
BEGIN
  m := modules;
  WHILE m # NIL DO
    Log.Object("MODULE", m.name);
    m.options.Write(Log.writer);
    m := m.next;
  END;
END ShowModules;

PROCEDURE NewModule* (name : STRING) : Module;
VAR m : Module;
BEGIN
  NEW(m);
  m.imports := NEW(ArrayList.ArrayList(Module), 10);
  m.name := name;
  m.next := modules;
  m.options := NEW(Option.Options);
  m.definitions := 0;

  m.stripPrefix := m.options.StringList("StripPrefix");
  m.outputName := m.options.String("OutputName", m.name);
  m.interfaceType := m.options.String("InterfaceType", "C");
  m.prolog := m.options.String("Prolog", "");
  m.doneProlog := FALSE;
  m.epilog := m.options.String("Epilog", "");
  m.doneEpilog := FALSE;
  m.linkFramework := m.options.StringList("LinkFramework");
  m.linkLib := m.options.StringList("LinkLib");
  m.linkFile := m.options.StringList("LinkFile");
  m.userImport := m.options.StringList("Import");
  m.defaultVar := m.options.Boolean("DefaultVar", FALSE);
  m.translate := m.options.Boolean("Translate", TRUE);
  m.merge := m.options.Boolean("Merge", FALSE);
  m.visited := FALSE;
  m.vars := NIL;
  m.types := NIL;
  m.typedefs := NIL;

  modules := m;
  RETURN m;
END NewModule;

PROCEDURE (m : Module) AddDefinition*;
BEGIN
  INC(m.definitions);
END AddDefinition;

PROCEDURE (m : Module) MapName* (name : STRING) : STRING;
VAR base : STRING;
BEGIN
  IF m.stripPrefix.IsPrefix(name, base) THEN
    IF ValidOutputSymbol(base) THEN
      name := base;
    END
  END;
  RETURN name;
END MapName;

PROCEDURE Key(name : STRING);
BEGIN
  reserved.Append(name);
END Key;

PROCEDURE DefineKeywords;
BEGIN
  (* Oberon-2 reserved words *)
  Key("ARRAY"); Key("BEGIN"); Key("BY"); Key("CASE"); Key("CONST");
  Key("DIV"); Key("DO"); Key("ELSE"); Key("ELSIF"); Key("END");
  Key("EXIT"); Key("FOR"); Key("IF"); Key("IMPORT"); Key("IN");
  Key("IS"); Key("LOOP"); Key("MOD"); Key("MODULE"); Key("NIL");
  Key("OF"); Key("OR"); Key("POINTER"); Key("PROCEDURE"); Key("RECORD");
  Key("REPEAT"); Key("RETURN"); Key("THEN"); Key("TO"); Key("TYPE");
  Key("UNTIL"); Key("VAR"); Key("WHILE"); Key("WITH"); 

  (* Oberon-2 predeclared identifiers *)
  Key("ASSERT"); Key("ABS"); Key("ASH"); Key("BOOLEAN"); Key("CAP");
  Key("CHAR"); Key("CHR"); Key("COPY"); Key("DEC"); Key("ENTIER");
  Key("EXCL"); Key("FALSE"); Key("HALT"); Key("INC"); Key("INCL");
  Key("INTEGER"); Key("LEN"); Key("LONG"); Key("LONGINT"); Key("LONGREAL");
  Key("MAX"); Key("MIN"); Key("NEW"); Key("ODD"); Key("ORD"); Key("REAL");
  Key("SET"); Key("SHORT"); Key("SHORTINT"); Key("SIZE"); Key("TRUE"); 

  (* OOC reserved words *)
  Key("TRY"); Key("CATCH"); Key("RAISES");

  (* OOC predeclared identifiers *)
  Key("LONGCHAR"); Key("UCS4CHAR"); Key("HUGEINT"); Key("EXCEPTION");
  Key("STRING");
END DefineKeywords;

BEGIN
  reserved := NEW(ArrayList.ArrayList(STRING),20);
  DefineKeywords;

  charType := BaseType(tInteger, 1, "char");  
  unsignedCharType := BaseType(tUnsigned, 1, "unsigned char");
  wCharType := BaseType(tInteger, 2, "wchar_t");  
  unsignedWCharType := BaseType(tUnsigned, 2, "unsigned wchar_t");
  shortType := BaseType(tInteger, 2, "short");
  unsignedShortType := BaseType(tUnsigned, 2, "unsigned short");
  longType := BaseType(tInteger, 4, "long");
  unsignedLongType := BaseType(tUnsigned, 4, "unsigned long");
  longLongType := BaseType(tInteger, 8, "long long");
  unsignedLongLongType := BaseType(tUnsigned, 8, "unsigned long long");
  intType := longType; unsignedIntType := unsignedLongType;
  floatType := BaseType(tReal, 4, "float");
  doubleType := BaseType(tReal, 8, "double");
  longDoubleType := BaseType(tReal, 8, "long double");
  voidType := BaseType(tVoid, 0, "void");

  options := NEW(Option.Options);
  allowRedefinedProc := options.Boolean("AllowRedefinedProc", FALSE);
  allowRedefined := options.Boolean("AllowRedefined", FALSE);
END H2O:Type.

