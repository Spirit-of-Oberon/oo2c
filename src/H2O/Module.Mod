MODULE H2O:Module;

IMPORT
  Object, ADT:ArrayList, Err, H2O:Option, Log;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc* = RECORD (Object.ObjectDesc)
    imports- : ArrayList.ArrayList(Module);
    name- : STRING;
    next- : Module;
    definitions- : LONGINT;

    options- : Option.Options;

    outputName- : Option.String;
    stripPrefix- : Option.StringList;
  END;

VAR
  modules- : Module;

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
    RETURN base;
  ELSE
    RETURN name;
  END;
END MapName;

BEGIN
  modules := NIL;
END H2O:Module.
