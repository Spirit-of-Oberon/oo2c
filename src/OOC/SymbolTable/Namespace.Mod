(* 	$Id$	 *)
MODULE OOC:SymbolTable:Namespace;
(*  Implements namespaces and semantic checks on them.
    Copyright (C) 2000  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)


IMPORT
  OOC:Error, OOC:SymbolTable:Item, OOC:SymbolTable:TypeRules;


TYPE
  Namespace* = POINTER TO NamespaceDesc;
  NamespaceDesc = RECORD
    (**A namespace maps names to declarations.  There are two different 
       search methods: @oproc{Namespace.IdentifyLocal} and 
       @oproc{Namespace.Identify}.  *)
    (Item.NamespaceDesc)
    localDecl-: Item.DeclarationArray;
    (* A list of local declarations of the namespace.  The array elements
       @samp{localDecl[0..@ofield{localCount}-1]} hold valid references.  *)
    localCount-: LONGINT;
    (* The number of declaration local to the namespace *)
  END;

TYPE
  Nested* = POINTER TO NestedDesc;
  NestedDesc = RECORD
    (**This class implements module and procedure namespaces.  A module 
       namespace is nested into the namespace of the predefined entities,
       and a procedure's namespace is nested in the one of the enclosing
       procedure, or the one of the module.  *)
    (NamespaceDesc)
    nestedIn: Namespace;
    (* Refers to the namespace, in which this namespace is nested.  If there
       is no such namespace, e.g. because the namespace belongs to the
       pseudo module of the predefined entities, this field is @code{NIL}.  *)
  END;

TYPE
  Extended* = POINTER TO ExtendedDesc;
  ExtendedDesc = RECORD
    (**This class implements record namespaces.  A record namespace extends
       the namespace of its base type.  *)
    (NamespaceDesc)
    extends: Namespace;
    (* Refers to the namespace, of which this namespace is an extension.  If
       the record has no base type, this field is @code{NIL}.  *)
  END;



CONST
  multipleDeclForName = 1;
  multipleMemberForName = 2;
  definedForBaseType = 3;
  fieldExistsInBaseType = 4;
  invalidTBProcExport = 5;
  invalidRedefintion = 6;
  redefinitionBeforeBase = 7;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  namespaceContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | multipleDeclForName:
      t := "Multiple declaration of same name"
    | multipleMemberForName:
      t := "A record member of this name already exists"
    | definedForBaseType:
      t := "This name is already defined in the record's base type"
    | fieldExistsInBaseType:
      t := "A field of this name is already defined for the base type"
    | invalidTBProcExport:
      t := "Must be exported like inherited declaration"
    | invalidRedefintion:
      t := "Formal parameters don't match inherited declaration"
    | redefinitionBeforeBase:
      t := "This procedure redefines a procedure that is declared later"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE InitNamespace (ns: Namespace; da: Item.DeclarationArray; 
                         len: LONGINT);
  BEGIN
    Item.InitNamespace (ns);
    ns. localDecl := da;
    ns. localCount := len
  END InitNamespace;

PROCEDURE (ns: Namespace) IdentifyLocal* (sourceContext: Item.Item;
                   name: Item.Name; ignorePosition: BOOLEAN): Item.Declaration;
  VAR
    s, e, m: LONGINT;
    decl: Item.Declaration;
  BEGIN
    s := 0; e := ns. localCount;
    WHILE (s < e) DO
      m := (s+e) DIV 2;
      IF (ns. localDecl[m]. name. str^ < name. str^) THEN
        s := m+1
      ELSE
        e := m
      END
    END;
    ASSERT (s = e);
    IF (s < ns. localCount) & (ns. localDecl[s]. name. str^ = name. str^) THEN
      decl := ns. localDecl[s];
      IF (decl. Module() = sourceContext. Module()) THEN
        (* query and declaration are in same module: check range of 
           visibility of the declration *)
        IF (decl. visibleFrom > name. pos) & ~ignorePosition THEN
          decl := NIL
        END
      ELSIF (decl. exportMark = Item.nameNotExported) THEN
        (* query and declaration are in different modules: check if the name
           is exported *)
        decl := NIL
      END;
      RETURN decl
    ELSE
      RETURN NIL
    END
  END IdentifyLocal;

PROCEDURE (ns: Namespace) Identify* (sourceContext: Item.Item;
                   name: Item.Name; ignorePosition: BOOLEAN): Item.Declaration;
  BEGIN
    RETURN ns. IdentifyLocal (sourceContext, name, ignorePosition)
  END Identify;

PROCEDURE ErrDecl (code: Error.Code; decl: Item.Declaration; errList: Error.List);
  VAR
    lastError: Error.Msg;
  BEGIN
    lastError := Error.New (namespaceContext, code);
    lastError. SetIntAttrib ("pos", decl. name. pos);
    lastError. SetIntAttrib ("line", decl. name. line);
    lastError. SetIntAttrib ("column", decl. name. column);
    errList. Append (lastError)
  END ErrDecl;

PROCEDURE (ns: Namespace) CheckLocalUniqueness* (errList: Error.List);
(**Checks that all names registered locally to the namespace @oparam{ns} are
   unique within the namespace.  Any duplicates will be marked as faulty, and
   all but the very first, in terms of file position, of the multiple 
   declarations are removed.
   
   Note: Forward declarations of procedures are not part of any namespace.  *)
  VAR
    min, i, j, h: LONGINT;
    da: Item.DeclarationArray;
  BEGIN
    da := ns. localDecl;
    i := 0;
    WHILE (i < ns. localCount-1) DO
      IF (da[i]. name. str^ = da[i+1]. name. str^) THEN
        (* identify all declarations with the name of `i', and from
           these declarations the one with the smallest module 
           position *)
        min := i;
        j := i+1;
        WHILE (j < ns. localCount) & 
              (da[i]. name. str^ = da[j]. name. str^) DO
          IF (da[j]. name. pos < da[i]. name. pos) THEN
            min := j
          END;
          INC (j)
        END;

        (* emit error messages for all but declaration `min' *)
        FOR h := i TO j-1 DO
          IF (h # min) THEN
            ErrDecl (multipleDeclForName, da[h], errList)
          END
        END;
        
        (* remove all faulty declarations but `min' *)
        da[i] := da[min];
        h := j-i-1;
        FOR j := i+(h+1) TO ns. localCount-1 DO
          da[j-h] := da[j]
        END;
        DEC (ns. localCount, h)
      END;
      INC (i)
    END
  END CheckLocalUniqueness;



PROCEDURE InitNested (ns: Nested; 
                               da: Item.DeclarationArray; len: LONGINT);
  BEGIN
    InitNamespace (ns, da, len);
    ns. nestedIn := NIL
  END InitNested;

PROCEDURE NewNested* (da: Item.DeclarationArray; len: LONGINT): Namespace;
  VAR
    ns: Nested;
  BEGIN
    NEW (ns);
    InitNested (ns, da, len);
    RETURN ns
  END NewNested;

PROCEDURE (ns: Nested) SetEnclosingNamespace* (ns0: Namespace);
(**Sets the enclosing namespace of @oparam{ns} to @oparam{ns0}.  *)
  BEGIN
    ns. nestedIn := ns0
  END SetEnclosingNamespace;

PROCEDURE (ns: Nested) IdentifyLocal* (sourceContext: Item.Item;
                   name: Item.Name; ignorePosition: BOOLEAN): Item.Declaration;
  BEGIN
    RETURN ns. IdentifyLocal^ (sourceContext, name, ignorePosition)
  END IdentifyLocal;

PROCEDURE (ns: Nested) Identify* (sourceContext: Item.Item;
                   name: Item.Name; ignorePosition: BOOLEAN): Item.Declaration;
  VAR
    decl: Item.Declaration;
  BEGIN
    decl := ns. IdentifyLocal (sourceContext, name, ignorePosition);
    IF (decl = NIL) & (ns. nestedIn # NIL) THEN
      decl := ns. nestedIn. Identify (sourceContext, name, ignorePosition)
    END;
    RETURN decl
  END Identify;


PROCEDURE InitExtended (ns: Extended; 
                        da: Item.DeclarationArray; len: LONGINT);
  BEGIN
    InitNamespace (ns, da, len);
    ns. extends := NIL
  END InitExtended;

PROCEDURE NewExtended* (da: Item.DeclarationArray; len: LONGINT): Namespace;
  VAR
    ns: Extended;
  BEGIN
    NEW (ns);
    InitExtended (ns, da, len);
    RETURN ns
  END NewExtended;

PROCEDURE (ns: Extended) SetBaseNamespace* (ns0: Namespace);
(**Sets the base namespace of @oparam{ns} to @oparam{ns0}.  *)
  BEGIN
    ns. extends := ns0
  END SetBaseNamespace;

PROCEDURE (ns: Extended) IdentifyLocal* (sourceContext: Item.Item;
                   name: Item.Name; ignorePosition: BOOLEAN): Item.Declaration;
  BEGIN
    RETURN ns. IdentifyLocal^ (sourceContext, name, ignorePosition)
  END IdentifyLocal;

PROCEDURE (ns: Extended) Identify* (sourceContext: Item.Item;
                   name: Item.Name; ignorePosition: BOOLEAN): Item.Declaration;
  VAR
    decl: Item.Declaration;
  BEGIN
    decl := ns. IdentifyLocal (sourceContext, name, ignorePosition);
    IF (decl = NIL) & (ns. extends # NIL) THEN
      decl := ns. extends. Identify (sourceContext, name, ignorePosition)
    END;
    RETURN decl
  END Identify;

PROCEDURE (ns: Extended) InsertTBProc* (procDecl: Item.ProcDecl;
                                        errList: Error.List);
(**Adds the type-bound procedure @oparam{procDecl} to the namespace 
   @oparam{ns}.  If a record field or type-bound procedure of this name
   alreay exists, an error messages is posted to @oparam{errList}, and
   the namespace is not modified.
   
   Note: A potential name clash is only checked on the level of the namespace.
   Inherited names are not taken into account.  *)
  VAR
    s, e, m, i: LONGINT;
    n: Item.DeclarationArray;
  BEGIN
    IF (ns. IdentifyLocal (procDecl, procDecl. name, FALSE) # NIL) THEN
      ErrDecl (multipleMemberForName, procDecl, errList)
    ELSE
      s := 0; e := ns. localCount;
      WHILE (s < e) DO
        m := (s+e) DIV 2;
        IF (ns. localDecl[m]. name. str^ < procDecl. name. str^) THEN
          s := m+1
        ELSE
          e := m
        END
      END;
      
      ASSERT (s = e);
      IF (s < ns. localCount) THEN
        ASSERT (ns. localDecl[s]. name. str^ > procDecl. name. str^)
      END;
      
      NEW (n, ns. localCount+1);
      FOR i := 0 TO s-1 DO
        n[i] := ns. localDecl[i]
      END;
      n[s] := procDecl;
      FOR i := s TO ns. localCount-1 DO
        n[i+1] := ns. localDecl[i]
      END;
      
      ns. localDecl := n;
      INC (ns. localCount)
    END
  END InsertTBProc;

PROCEDURE (ns: Extended) CheckRestrictions* (record: Item.Record;
                                             tr: TypeRules.Rules;
                                             errList: Error.List);
(**Checks the restrictions placed by the language on the names of record
   fields and type-bound procedures.  For redefinitions of type-bound 
   procedures, this procedure also checks whether the export marks correspond,
   and whether the formal parameter list of the redefinition matches that
   of the base definition.
   
   When this procedure is done, all type-bound procedures of the record
   namespace have a valid value in
   @ofield{Item.ProcDecl.tbProcIndex}, and the record's
   @ofield{Item.Record.tbProcCount} correctly reflects the
   number of type-bound procedures attached to it.  *)
  VAR
    i: LONGINT;
    decl, base: Item.Declaration;
  BEGIN
    FOR i := 0 TO ns. localCount-1 DO
      decl := ns. localDecl[i];
      WITH decl: Item.FieldDecl DO
        IF (ns. extends # NIL) & 
           (ns. extends. Identify (decl, decl. name, TRUE) # NIL) THEN
          ErrDecl (definedForBaseType, decl, errList)
        END
      | decl: Item.ProcDecl DO
        IF (ns. extends = NIL) THEN
          base := NIL
        ELSE
          base := ns. extends. Identify (decl, decl. name, TRUE);
        END;
        IF (base # NIL) THEN
          WITH base: Item.FieldDecl DO
            ErrDecl (fieldExistsInBaseType, decl, errList)
          | base: Item.ProcDecl DO
            IF (decl. exportMark # base. exportMark) THEN
              ErrDecl (invalidTBProcExport, decl, errList)
            END;
            IF tr. IsValidRedefinition (base. formalPars, 
                                        decl. formalPars) THEN
              base. CopyTBProcIndex (decl);
              IF (decl. name. pos < base. visibleFrom) THEN
                ErrDecl (redefinitionBeforeBase, decl, errList)
              END
            ELSE
              ErrDecl (invalidRedefintion, decl, errList)
            END
          END
        ELSE
          record. AssignTBProcIndex (decl)
        END
      END
    END
  END CheckRestrictions;

BEGIN
  NEW (namespaceContext);
  Error.InitContext (namespaceContext, "OOC:SymbolTable:Namespace")
END OOC:SymbolTable:Namespace.
