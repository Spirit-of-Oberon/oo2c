MODULE H2O:Module;

IMPORT
  ADT:String, ADT:Object, ADT:ArrayList, Err;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc* = RECORD (Object.ObjectDesc)
    imports- : ArrayList.ArrayList;
    name- : String.String;
    next- : Module;
  END;

VAR
  modules- : Module;

PROCEDURE (m : Module) AddImports* (list : ArrayList.ArrayList);
VAR 
  i : LONGINT;
  mod : Module;
BEGIN
  FOR i := 0 TO list.size -1 DO
    mod := list.array[i](Module);
    IF (m # mod) & ~m.imports.Contains(mod) THEN
      m.imports.Append(mod);
      Err.String("MODULE "); Err.String(m.name.array^);
      Err.String(" IMPORTS "); Err.String(mod.name.array^);
      Err.Ln;
    END;
  END;
END AddImports;

PROCEDURE ModuleName* (fileName : ARRAY OF CHAR) : String.String;
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
    ch := fileName[pos];
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
  RETURN String.NewRegion(fileName, slash, dot);
END ModuleName;

PROCEDURE FindModule* (name : String.String) : Module;
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

PROCEDURE NewModule* (name : String.String) : Module;
VAR m : Module;
BEGIN
  NEW(m);
  m.imports := ArrayList.New(5);
  m.name := name;
  m.next := modules;
  modules := m;
  RETURN m;
END NewModule;

BEGIN
  modules := NIL;
END H2O:Module.
