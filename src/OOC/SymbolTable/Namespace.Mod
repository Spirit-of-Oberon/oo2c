(* 	$Id: Namespace.Mod,v 1.24 2004/03/19 19:17:13 mva Exp $	 *)
MODULE OOC:SymbolTable:Namespace;
(*  Implements namespaces and semantic checks on them.
    Copyright (C) 2000-2004  Michael van Acken

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
  OOC:Error, Sym := OOC:SymbolTable, TR := OOC:SymbolTable:TypeRules,
  OOC:SymbolTable:Predef, OOC:SymbolTable:Uses;


TYPE
  Namespace* = POINTER TO NamespaceDesc;
  NamespaceDesc = RECORD
    (**A namespace maps names to declarations.  There are two different 
       search methods: @oproc{Namespace.IdentifyLocal} and 
       @oproc{Namespace.Identify}.  *)
    (Sym.NamespaceDesc)
    localDecl-: Sym.DeclarationArray;
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
    nestedIn-: Namespace;
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
    extends-: Namespace;
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
  staticMethodNotExported = 8;
  staticMethodAbstract = 9;
  notProcedure = 10;
  
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
    | staticMethodNotExported:
      t := "This static type-bound procedure must be exported"
    | staticMethodAbstract:
      t := "This static type-bound procedure cannot be abstract"
    | notProcedure:
      t := "This must be a non-function procedure"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE InitNamespace (ns: Namespace; da: Sym.DeclarationArray; 
                         len: LONGINT);
  BEGIN
    Sym.InitNamespace (ns);
    ns. localDecl := da;
    ns. localCount := len
  END InitNamespace;

PROCEDURE (ns: Namespace) IdentifyLocal2*(sourceContext: Sym.Item;
                                          name: Sym.Name;
                                          ignorePosition: BOOLEAN;
                                          VAR baseNotExported: BOOLEAN): Sym.Declaration;
  VAR
    s, e, m: LONGINT;
    decl: Sym.Declaration;
  BEGIN
(*    Log.String("### looking for", name.str^);
    FOR s := 0 TO ns.localCount-1 DO
      Log.String ("  local", ns.localDecl[s].name.str^);
    END;*)
    
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
      ELSIF (decl. exportMark = Sym.nameNotExported) THEN
        (* query and declaration are in different modules: check if the name
           is exported *)
        decl := NIL;
        baseNotExported := TRUE;
      END;
      RETURN decl
    ELSE
      RETURN NIL
    END
  END IdentifyLocal2;

PROCEDURE (ns: Namespace) Identify2*(sourceContext: Sym.Item;
                                     name: Sym.Name;
                                     ignorePosition: BOOLEAN;
                                     VAR baseNotExported: BOOLEAN): Sym.Declaration;
  BEGIN
    RETURN ns. IdentifyLocal2(sourceContext, name, ignorePosition, baseNotExported)
  END Identify2;

PROCEDURE ErrDecl (code: Error.Code; decl: Sym.Declaration; errList: Error.List);
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
    da: Sym.DeclarationArray;
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
          IF (da[j]. name. pos < da[min]. name. pos) THEN
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
                               da: Sym.DeclarationArray; len: LONGINT);
  BEGIN
    InitNamespace (ns, da, len);
    ns. nestedIn := NIL
  END InitNested;

PROCEDURE NewNested* (da: Sym.DeclarationArray; len: LONGINT): Nested;
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

PROCEDURE (ns: Nested) IdentifyLocal2*(sourceContext: Sym.Item;
                                       name: Sym.Name;
                                       ignorePosition: BOOLEAN;
                                       VAR baseNotExported: BOOLEAN): Sym.Declaration;
  BEGIN
    RETURN ns. IdentifyLocal2^(sourceContext, name, ignorePosition, baseNotExported)
  END IdentifyLocal2;

PROCEDURE (ns: Nested) Identify2*(sourceContext: Sym.Item;
                                  name: Sym.Name;
                                  ignorePosition: BOOLEAN;
                                  VAR baseNotExported: BOOLEAN): Sym.Declaration;
  VAR
    decl: Sym.Declaration;
  BEGIN
    decl := ns. IdentifyLocal2(sourceContext, name, ignorePosition, baseNotExported);
    IF (decl = NIL) & (ns. nestedIn # NIL) THEN
      decl := ns. nestedIn. Identify2(sourceContext, name, ignorePosition,
                                      baseNotExported)
    END;
    RETURN decl
  END Identify2;


PROCEDURE InitExtended (ns: Extended; 
                        da: Sym.DeclarationArray; len: LONGINT);
  BEGIN
    InitNamespace (ns, da, len);
    ns. extends := NIL
  END InitExtended;

PROCEDURE NewExtended* (da: Sym.DeclarationArray; len: LONGINT): Namespace;
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

PROCEDURE (ns: Extended) IdentifyLocal2*(sourceContext: Sym.Item;
                                         name: Sym.Name;
                                         ignorePosition: BOOLEAN;
                                         VAR baseNotExported: BOOLEAN): Sym.Declaration;
  BEGIN
    RETURN ns. IdentifyLocal2^(sourceContext, name, ignorePosition, baseNotExported)
  END IdentifyLocal2;

PROCEDURE (ns: Extended) Identify2*(sourceContext: Sym.Item;
                                    name: Sym.Name;
                                    ignorePosition: BOOLEAN;
                                    VAR baseNotExported: BOOLEAN): Sym.Declaration;
  VAR
    decl: Sym.Declaration;
  BEGIN
    decl := ns. IdentifyLocal2(sourceContext, name, ignorePosition, baseNotExported);
    IF (decl = NIL) & (ns. extends # NIL) THEN
      decl := ns. extends. Identify2(sourceContext, name, ignorePosition, baseNotExported)
    END;
    RETURN decl
  END Identify2;

PROCEDURE (ns: Extended) InsertTBProc* (procDecl: Sym.ProcDecl;
                                        errList: Error.List);
(**Adds the type-bound procedure @oparam{procDecl} to the namespace 
   @oparam{ns}.  If a record field or type-bound procedure of this name
   alreay exists, an error messages is posted to @oparam{errList}, and
   the namespace is not modified.
   
   Note: A potential name clash is only checked on the level of the namespace.
   Inherited names are not taken into account.  *)
  VAR
    s, e, m, i: LONGINT;
    n: Sym.DeclarationArray;
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

PROCEDURE (ns: Extended) GetTBProcByIndex* (index: LONGINT): Sym.ProcDecl;
(**Return the type-bound procedure that has the given @oparam{index} in
   this namespace.  If the local namespace has no such procedure, the
   base namespaces are searched.  *)
  VAR
    i: LONGINT;
    decl: Sym.Declaration;
  BEGIN
    FOR i := 0 TO ns. localCount-1 DO
      decl := ns. localDecl[i];
      WITH decl: Sym.ProcDecl DO
        IF (decl. tbProcIndex = index) THEN
          RETURN decl
        END;
      ELSE  (* ignore *)
      END;
    END;

    IF (ns. extends = NIL) THEN
      RETURN NIL;
    ELSE
      RETURN ns. extends(Extended). GetTBProcByIndex (index);
    END;
  END GetTBProcByIndex;

PROCEDURE (ns: Extended) GetSuperProcByIndex* (index: LONGINT): Sym.ProcDecl;
(**Like @oproc{Extended.GetTBProcByIndex}, but return the procedure for
   @oparam{index} from the base type of @oparam{ns}.  *)
  BEGIN
    IF (ns. extends = NIL) THEN
      RETURN NIL;
    ELSE
      RETURN ns. extends(Extended). GetTBProcByIndex (index);
    END;
  END GetSuperProcByIndex;

PROCEDURE (ns: Extended) CheckRestrictions* (record: Sym.Record;
                                             uses: Uses.Uses;
                                             errList: Error.List);
(**Checks the restrictions placed by the language on the names of record
   fields and type-bound procedures.  For redefinitions of type-bound 
   procedures, this procedure also checks whether the export marks correspond,
   and whether the formal parameter list of the redefinition matches that
   of the base definition.  *)
  VAR
    i, j: LONGINT;
    decl, base: Sym.Declaration;
    baseNotExported: BOOLEAN;
    rec, ptr, baseFormalPars: Sym.Type;
    args: Sym.TypeRefArray;
    qualType: Sym.QualType;
  BEGIN
    FOR i := 0 TO ns. localCount-1 DO
      decl := ns. localDecl[i];
      WITH decl: Sym.FieldDecl DO
        IF (ns. extends # NIL) THEN
          baseNotExported := FALSE;
          base := ns.extends.Identify2(decl, decl.name, TRUE, baseNotExported);
          IF (base = NIL) THEN
            decl.shadowsPrivateBase := baseNotExported;
          ELSE
            ErrDecl (definedForBaseType, decl, errList)
          END;
        END;
        
      | decl: Sym.ProcDecl DO
        baseNotExported := FALSE;
        IF (ns. extends = NIL) THEN
          base := NIL
        ELSE
          base := ns. extends. Identify (decl, decl. name, TRUE);
        END;
        IF (base # NIL) THEN
          WITH base: Sym.FieldDecl DO
            ErrDecl (fieldExistsInBaseType, decl, errList)
          | base: Sym.ProcDecl DO
            IF (decl. exportMark # base. exportMark) THEN
              ErrDecl (invalidTBProcExport, decl, errList)
            END;

            rec := decl.Class();
            IF (rec.typePars # NIL) THEN
              (* calculate type closure for the record type of the original
                 procedure definition *)
              NEW(args, LEN(rec.typePars.params^));
              FOR j := 0 TO LEN(args^)-1 DO
                Sym.InitTypeRef(args[j], rec.typePars.params[j]);
              END;
              
              NEW(qualType);
              Sym.InitQualType(qualType, NIL, rec.position, rec, args);
              rec := Sym.Expand(qualType);

              WHILE (rec.Deparam() # base.Class()) DO
                ptr := rec.Deparam();
                rec := rec.Closure(ptr(Sym.Record).baseType);
              END;
              baseFormalPars := rec.Closure(base.formalPars);
            ELSE
              baseFormalPars := base.formalPars;
            END;
            
            IF (decl.procClass = Sym.staticMethod) OR
               TR.IsValidRedefinition(baseFormalPars, decl.formalPars) THEN
              IF base.notRedefined THEN
                base.notRedefined := FALSE;
              END;
              IF (decl. name. pos < base. visibleFrom) THEN
                ErrDecl (redefinitionBeforeBase, decl, errList)
              END;

              decl.deprecated := decl.deprecated OR base.deprecated;
              
              Uses.Mark(base, uses, decl.name);
            ELSE
              ErrDecl (invalidRedefintion, decl, errList)
            END;
          END;
        END;

        IF (decl.procClass = Sym.staticMethod) THEN
          IF (decl.exportMark = Sym.nameNotExported) THEN
            ErrDecl (staticMethodNotExported, decl, errList);
          END;
          IF (decl.name.str^ = Predef.initMethod) &
             (decl.formalPars.resultType # NIL) THEN
            ErrDecl(notProcedure, decl, errList);
          END;
          IF decl.isAbstract THEN
            ErrDecl (staticMethodAbstract, decl, errList);
          END;
        END;
      END
    END
  END CheckRestrictions;

BEGIN
  NEW (namespaceContext);
  Error.InitContext (namespaceContext, "OOC:SymbolTable:Namespace")
END OOC:SymbolTable:Namespace.
