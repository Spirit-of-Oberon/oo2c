(* 	$Id$	 *)
MODULE OOC:SymbolTable:CreateNamespace [OOC_EXTENSIONS];
(*  Creates namespaces for module, and resolves type names in declarations.
    Copyright (C) 2000-2002  Michael van Acken

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
  Msg, ADT:Dictionary, OOC:Error, Sym := OOC:SymbolTable,
  OOC:SymbolTable:Namespace,
  TR := OOC:SymbolTable:TypeRules, OOC:SymbolTable:Builder,
  OOC:SymbolTable:Predef, OOC:SymbolTable:ImportModules, OOC:Doc:ResolveRef;


CONST
  undeclaredIdent = 1;
  notTypeName = 2;
  illegalRecordBase = 3;
  invalidParameterType = 4;
  invalidReceiverType = 5;
  invalidResultType = 6;
  invalidPointerBaseType = 7;
  invalidArrayElementType = 8;
  invalidOpenArray = 9;
  invalidReceiverModeRecord = 10;
  invalidReceiverModePointer = 11;
  unresolvedForwardDecl = 12;
  forwardNameClash = 13;
  multipleForwardDecl = 14;
  forwardAfterDefinition = 15;
  forwardMismatchFPars = 16;
  undeclaredModule = 17;
  notModule = 18;
  invalidModifierFlag = 19;
  modifierFlagWithoutEffect = 20;
  cannotCreateInstance = 21;
  abstractProcForConcreteRecord = 22;
  abstractProcNotExported = 23;
  procedureStillAbstract = 24;
  atMostOneLinkFile = 25;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  createNamespaceContext: ErrorContext;
  predefModule: Sym.Module;
  systemModule-: Sym.Module;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | undeclaredIdent:
      t := "Undeclared identifier"
    | notTypeName:
      t := "Data type expected"
    | illegalRecordBase:
      t := "This type cannot be used as a record base type"
    | invalidParameterType:
      t := "Can't use type constructor here"
    | invalidReceiverType:
      t := "Illegal receiver type"
    | invalidResultType:
      t := "Illegal type for function result"
    | invalidPointerBaseType:
      t := "Illegal pointer base type"
    | invalidArrayElementType:
      t := "Illegal type for array element"
    | invalidOpenArray:
      t := "Cannot use open array type here"
    | invalidReceiverModeRecord:
      t := "Receiver of record type must be a variable parameter"
    | invalidReceiverModePointer:
      t := "Receiver of pointer type must be a value parameter"
    | unresolvedForwardDecl:
      t := "Unresolved procedure forward declaration"
    | forwardNameClash:
      t := "Name of forward declaration already assigned to another object"
    | multipleForwardDecl:
      t := "Multiple forward declarations for same name"
    | forwardAfterDefinition:
      t := "Forward declaration is placed after the definition"
    | forwardMismatchFPars:
      t := "Formal parameters don't match procedure definition"
    | undeclaredModule:
      t := "Undeclared module name"
    | notModule:
      t := "This is not a module name"
    | invalidModifierFlag:
      t := "Invalid modifier flag"
    | modifierFlagWithoutEffect:
      t := "This modifier flag has no effect here"
    | cannotCreateInstance:
      t := "Cannot create an instance an abstract type"
    | abstractProcForConcreteRecord:
      t := "Receiver type is not abstract"
    | abstractProcNotExported:
      t := "Abstract procedure must be exported"
    | procedureStillAbstract:
      t := "Inherited procedure `${name}' is still abstract"
    | atMostOneLinkFile:
      t := "Module must provide at most one LINK FILE directive"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE ResolveQualident* (ns: Sym.Namespace; contextOfUse: Sym.Item;
                             module, ident: Sym.Name): Sym.Declaration;
  VAR
    m, decl: Sym.Declaration;
  BEGIN
    m := ns.Identify(contextOfUse, module, FALSE);
    IF (m = NIL) OR ~(m IS Sym.Import) THEN
      RETURN NIL;
    ELSE
      m.IncrUsageCount();
      ns := m(Sym.Import).externalSymTab.ns;
    END;
    decl := ns.Identify(contextOfUse, ident, FALSE);
    IF (decl # NIL) THEN
      decl.IncrUsageCount();
    END;
    RETURN decl;
  END ResolveQualident;

PROCEDURE CreateNamespace* (root: Sym.Module;
                            errList: Error.List);
(**Populates the namespaces of the symbol table @oparam{root} and performs
   semantic checks on the declarations.  It is assumed, that the namespace
   of module @oparam{root} is nested into the namespace of the pseudo module
   holding the predefined objects.
   
   The type rules used to check the declarations are taken from object
   @omodule{TR}.  Any errors are reported to the error list @oparam{errList}.
   After successful completion of this procedure, the symbol table
   @oparam{root} can be used to resolve any using occurences of names within
   the module's source code.  *)
  VAR
    lastError: Error.Msg;
    visited: Dictionary.Dictionary;
    
  PROCEDURE Err (code: Error.Code; tname: Sym.TypeName);
    VAR
      pos: Sym.Position;
    BEGIN
      IF (code = undeclaredIdent) THEN
        (* if we have an undeclared identifier, don't refer to the module name,
           but rather to the identifier; that is, signal that the identifier
           cannot be found, but that the module name is valid *)
        pos := tname. ident
      ELSE
        pos := tname. position
      END;
      lastError := Error.New (createNamespaceContext, code);
      lastError. SetIntAttrib ("pos", pos. pos);
      lastError. SetIntAttrib ("line", pos. line);
      lastError. SetIntAttrib ("column", pos. column);
      errList. Append (lastError)
    END Err;
  
  PROCEDURE ErrType (code: Error.Code; type: Sym.Type);
    BEGIN
      lastError := Error.New (createNamespaceContext, code);
      lastError. SetIntAttrib ("pos", type. position. pos);
      lastError. SetIntAttrib ("line", type. position. line);
      lastError. SetIntAttrib ("column", type. position. column);
      errList. Append (lastError)
    END ErrType;
  
  PROCEDURE ErrDecl (code: Error.Code; decl: Sym.Declaration; errList: Error.List);
    BEGIN
      lastError := Error.New (createNamespaceContext, code);
      lastError. SetIntAttrib ("pos", decl. name. pos);
      lastError. SetIntAttrib ("line", decl. name. line);
      lastError. SetIntAttrib ("column", decl. name. column);
      errList. Append (lastError)
    END ErrDecl;

  PROCEDURE ImportAllModules (root: Sym.Module);
    VAR
      ptr: Sym.Item;
    BEGIN
      ImportModules.ImportModules (systemModule, root, errList);
      IF errList.NoErrors() THEN
        ptr := root. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Sym.Import DO
            IF (ptr. externalSymTab. ns = NIL) THEN
              (* for each of the imported modules: create namespace information
                 and resolve any reference commands in embedded documentation
                 strings *)
              CreateNamespace (ptr. externalSymTab, errList);
(*              ResolveRef.Resolve (ptr. externalSymTab, repositories, errList)
... moved to end of CreateNamespace *)
            END
          ELSE
          END;
          ptr := ptr. nextNested
        END
      END
    END ImportAllModules;
  
  PROCEDURE PopulateNamespace (item: Sym.Item);
  (* For all definitions that include a namespace (i.e., for module, procedure,
     and record type), create a namespace that initially includes all the
     declarations local to this particular definition.  When this procedure
     is done, every definition with local declarations contains a mapping of
     identifiers to declarations.
     
     Note: Type-bound procedures and forward declarations of procedures are
     @emph{not} included in the namespace mapping.  *)
    VAR
      ptr: Sym.Item;

    PROCEDURE Assemble (item: Sym.Item; nested: BOOLEAN): Sym.Namespace;
      VAR
        ptr: Sym.Item;
        c: LONGINT;
        da: Sym.DeclarationArray;

      PROCEDURE IsDeclaration (item: Sym.Item): BOOLEAN;
        BEGIN
          WITH item: Sym.ProcDecl DO
            RETURN ~(item. isTypeBound OR item. isForwardDecl)
          ELSE
            RETURN (item IS Sym.Declaration)
          END
        END IsDeclaration;
      
      PROCEDURE Quicksort (da: Sym.DeclarationArray; l, r: LONGINT);
        VAR
          i, j: LONGINT;
          t: Sym.Declaration;
          v: Sym.NameString;
        BEGIN
          IF (l < r) THEN
            i := l-1; j := r;
            v := da[r]. name. str;
            LOOP
              REPEAT INC (i) UNTIL (i > r) OR (da[i]. name. str^ >= v^);
              REPEAT DEC (j) UNTIL (j < l) OR (da[j]. name. str^ <= v^);
              IF (i >= j) THEN EXIT END;
              t := da[i]; da[i] := da[j]; da[j] := t
            END;
            t := da[i]; da[i] := da[r]; da[r] := t;
            Quicksort (da, l, i-1);
            Quicksort (da, i+1, r)
          END
        END Quicksort;
      
      BEGIN
        (* count declarations local to `item' *)
        c := 0;
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          IF IsDeclaration (ptr) THEN
            INC (c)
          END;
          ptr := ptr. nextNested
        END;
        IF (item IS Sym.ProcDecl) (*&
           (item(Sym.ProcDecl). visibleFrom >= 0) ... *) THEN
          (* add formal parameters, but only if the module is not an imported
             symbol file; otherwise, due to the missing visibility information,
             identification of parameter types may wrongly take a parameter
             name as defining occurence *)
          ptr := item(Sym.ProcDecl). formalPars. nestedItems;
          WHILE (ptr # NIL) DO
            IF IsDeclaration (ptr) THEN
              INC (c)
            END;
            ptr := ptr. nextNested
          END
        END;
        
        (* create array with local declarations *)
        NEW (da, c);
        c := 0;
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          IF IsDeclaration (ptr) THEN
            da[c] := ptr(Sym.Declaration);
            INC (c)
          END;
          ptr := ptr. nextNested
        END;
        IF (item IS Sym.ProcDecl) (*&     (* add formal parameters *)
           (item(Sym.ProcDecl). visibleFrom >= 0)...*) THEN
          ptr := item(Sym.ProcDecl). formalPars. nestedItems;
          WHILE (ptr # NIL) DO
            IF IsDeclaration (ptr) THEN
              da[c] := ptr(Sym.Declaration);
              INC (c)
            END;
            ptr := ptr. nextNested
          END
        END;

        (* sort array *)
        Quicksort (da, 0, c-1);
        
        IF nested THEN
          RETURN Namespace.NewNested (da, c)
        ELSE
          RETURN Namespace.NewExtended (da, c)
        END
      END Assemble;

    BEGIN
      IF (item # NIL) THEN
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          PopulateNamespace (ptr);
          ptr := ptr. nextNested
        END;

        WITH item: Sym.Module DO
          item. SetNamespace (Assemble (item, TRUE))
        | item: Sym.ProcDecl DO
          item. SetNamespace (Assemble (item, TRUE))
        | item: Sym.Record DO
          item. SetNamespace (Assemble (item, FALSE))
        ELSE  (* no other item is associated with a namespace *)
        END
      END
    END PopulateNamespace;
  
  PROCEDURE CheckLocalUniqueness (item: Sym.Item; errList: Error.List);
  (* Using the namespace information created by @oproc{PopulateNamespace},
     check that any declaration's name is unique in its local namespace.
     That is, if a namespace contains two local declarations of the same name,
     the second declaration is reported as faulty.  *)
    VAR
      ptr: Sym.Item;
      ns0: Sym.Namespace;
    BEGIN
      IF (item # NIL) THEN
        ns0 := item. Namespace();
        IF (ns0 # NIL) THEN
          ns0(Namespace.Namespace). CheckLocalUniqueness (errList)
        END;
        
        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CheckLocalUniqueness (ptr, errList);
          ptr := ptr. nextNested
        END
      END
    END CheckLocalUniqueness;
  
  PROCEDURE ConnectNamespaces (item: Sym.Item; predefModule: Sym.Module;
                               errList: Error.List);
  (* For the module and procedure namespaces, set the nesting information 
     of their respective namespaces.  Any module, except the virtual module
     defining the predefined entities, is nested in the predefined 
     namespace.  A procedure's namespace is nested in the one of the 
     enclosing procedure, or in the module's namespace if it is declared
     on the module level.
     
     Note: Record namespaces are @emph{not} completed by this procedure.  *)
    VAR
      ptr: Sym.Item;
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.Module DO
          IF (predefModule # NIL) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (predefModule. ns(Namespace.Namespace))
          END
        | item: Sym.ProcDecl DO
          IF (item. parent IS Sym.Module) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (item. parent(Sym.Module). 
                                       ns(Namespace.Namespace))
          ELSIF (item. parent IS Sym.ProcDecl) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (item. parent(Sym.ProcDecl). 
                                       ns(Namespace.Namespace))
          END
        ELSE  (* no other item is associated with a namespace *)
        END;      

        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ConnectNamespaces (ptr, predefModule, errList);
          ptr := ptr. nextNested
        END
      END
    END ConnectNamespaces;
  
  PROCEDURE ResolveTypeNames (item: Sym.Item; contextOfUse: Sym.Item;
                              errList: Error.List);
  (* Replaces all type names in @oparam{item} with a reference to the 
     indicated type.  Names are resolved in the context of the procedure
     (or module) @oparam{contextOfUse}.  Restrictions placed on the base
     type of a record are checked.  *)
    VAR
      ptr: Sym.Item;
      
    PROCEDURE GetTypeByName (typeName: Sym.Type; contextOfUse: Sym.Item; 
                      extendedSearch: BOOLEAN; errList: Error.List): Sym.Type;
    (**Resolves type name @oparam{typeName}, within the context of procedure
       (or module) @oparam{contextOfUse}.  With @oparam{extendedSearch} set to
       @code{TRUE} and the standard search failing, perform an extended search
       in the local namespace that ignores the range visibility of
       declarations.  This is used to resolve names used as pointer base
       types.  *)
      VAR
        item, itemRedir: Sym.Declaration;
        ns: Sym.Namespace;
      BEGIN
        WITH typeName: Sym.TypeName DO
          ns := contextOfUse. Namespace();
          IF (typeName. module # NIL) THEN
            (* resolve module name to get to external namespace *)
            item := ns. Identify (contextOfUse, typeName. module, FALSE);
            IF (item # NIL) THEN
              item.IncrUsageCount();
            END;
            IF (item = NIL) THEN
              Err (undeclaredModule, typeName);
              RETURN typeName
            ELSIF ~(item IS Sym.Import) THEN
              Err (notModule, typeName);
              RETURN typeName
            ELSE
              ns := item(Sym.Import). externalSymTab. ns;
              ASSERT (ns # NIL)
            END
          END;
          item := ns. Identify (contextOfUse, typeName. ident, FALSE);
          IF (item = NIL) & extendedSearch THEN
            item := ns. IdentifyLocal (contextOfUse, typeName. ident, TRUE);
          END;

          IF (item = NIL) THEN
            Err (undeclaredIdent, typeName);
            RETURN typeName
          ELSE
            (* if the type name refers to a name redirection, then resolve the
               redirection and continue with the resulting symbol table entry  *)
            item.IncrUsageCount();
            itemRedir := item;
            WITH itemRedir: Sym.Redirect DO
              item := ResolveQualident(contextOfUse.Namespace(), contextOfUse,
                                       itemRedir.module, itemRedir.ident);
              IF (item = NIL) THEN
                Err (undeclaredIdent, typeName);
                RETURN typeName;
              END;
            ELSE
            END;
            
            IF ~(item IS Sym.TypeDecl) THEN
              Err (notTypeName, typeName);
              RETURN typeName
            ELSE
              RETURN item(Sym.TypeDecl). type
            END
          END
        ELSE
          RETURN typeName
        END
      END GetTypeByName;

    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.TypeDecl DO
          item. type := GetTypeByName (item. type, contextOfUse, FALSE, errList)
          
        | item: Sym.VarDecl DO
          item. SetType (GetTypeByName (item. type, contextOfUse, FALSE, errList));
          
        | item: Sym.FieldDecl DO
          item. type := GetTypeByName (item. type, contextOfUse, FALSE, errList)
          
        | item: Sym.Pointer DO
          item. baseType := GetTypeByName (item. baseType,
                                           contextOfUse, TRUE, errList)
        | item: Sym.FormalPars DO
          IF (item. resultType # NIL) THEN
            item. resultType := GetTypeByName (item. resultType,
                                               contextOfUse, FALSE, errList)
          END
          
        | item: Sym.Array DO
          item. elementType := GetTypeByName (item. elementType,
                                              contextOfUse, FALSE, errList)
        | item: Sym.Record DO
          IF (item. baseType # NIL) THEN
            item.baseType := GetTypeByName (item.baseType, contextOfUse,
                                            FALSE, errList);
          END
        
        (* scope objects: fix context of use for using 
           occurences of identifiers *)
        | item: Sym.Module DO
          contextOfUse := item
        | item: Sym.ProcDecl DO
          contextOfUse := item
        ELSE  (* ignore any other kind items *)
        END;
        
        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ResolveTypeNames (ptr, contextOfUse, errList);
          ptr := ptr. nextNested
        END
      END
    END ResolveTypeNames;
  
  PROCEDURE CheckTypeRestrictions (item: Sym.Item; errList: Error.List);
  (* Checks the type restrictions placed by the language on declarations
     and definitions.  *)
    VAR
      ptr: Sym.Item;
      type: Sym.Type;
      record: Sym.Record;
    
    PROCEDURE CheckOpenArray (type, srcCodeType: Sym.Type);
      BEGIN
        IF ~(type IS Sym.TypeName) & TR.IsOpenArrayType (type) THEN
          ErrType (invalidOpenArray, srcCodeType)
        END
      END CheckOpenArray;

    PROCEDURE CheckInstance (type, srcCodeType: Sym.Type);
      BEGIN
        IF ~TR.VariableInstance(type) THEN
          ErrType(cannotCreateInstance, srcCodeType);
        END;
      END CheckInstance;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.VarDecl DO
          type := item. type;
          IF item. isParameter THEN
            IF ~(type IS Sym.TypeName) & ~TR.IsValidParameterType (type) THEN
              ErrType (invalidParameterType, item. srcCodeType)
            END
          ELSE
            CheckOpenArray (item. type, item. srcCodeType);
            CheckInstance(item.type, item.srcCodeType);
          END;
          IF item. isReceiver & ~(type IS Sym.TypeName) THEN
            IF ~TR.IsValidReceiverType (type) THEN
              ErrType (invalidReceiverType, item. srcCodeType)
            ELSIF (type IS Sym.Record) & ~item. isVarParam THEN
              ErrType (invalidReceiverModeRecord, item. srcCodeType)
            ELSIF (type IS Sym.Pointer) & item. isVarParam THEN
              ErrType (invalidReceiverModePointer, item. srcCodeType)
            END
          END;
          
        | item: Sym.FieldDecl DO
          CheckOpenArray (item. type, item. srcCodeType);
          CheckInstance(item.type, item.srcCodeType);

        | item: Sym.ProcDecl DO
          IF item.isTypeBound & item.isAbstract THEN
            record := item.Class();
            IF (record # NIL) & ~record.isAbstract THEN
              ErrDecl(abstractProcForConcreteRecord, item, errList);
            END;
            IF (item.exportMark = Sym.nameNotExported) THEN
              ErrDecl(abstractProcNotExported, item, errList);
            END;
          END;
          
        | item: Sym.Pointer DO
          type := item. baseType;
          IF ~(type IS Sym.TypeName) & ~TR.IsValidPointerBaseType (type) THEN
            ErrType (invalidPointerBaseType, item. srcCodeBaseType)
          END
          
        | item: Sym.FormalPars DO
          type := item. resultType;
          IF (type # NIL) & ~(type IS Sym.TypeName) &
             ~TR.IsValidResultType (type) THEN
            ErrType (invalidResultType, item. srcCodeResultType)
          END
          
        | item: Sym.Array DO
          type := item. elementType;
          IF ~(type IS Sym.TypeName) &
             ~TR.IsValidArrayElementType (type, item. isOpenArray) THEN
            ErrType (invalidArrayElementType, item. srcCodeElementType)
          END;
          CheckInstance(item.elementType, item.srcCodeElementType);

        | item: Sym.Record DO
          IF (item.baseType # NIL) THEN
            type := item.baseType;
            IF TR.IsValidRecordBaseType(type) THEN
              item.ns(Namespace.Extended). 
                  SetBaseNamespace(type(Sym.Record).ns(Namespace.Namespace));
            ELSE
              Err (illegalRecordBase, item.srcCodeBaseType(Sym.TypeName))
            END
          END
          
        ELSE  (* ignore any other kind of items *)
        END;
        
        (* descend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CheckTypeRestrictions (ptr, errList);
          ptr := ptr. nextNested
        END
      END
    END CheckTypeRestrictions;
  
  PROCEDURE InsertTypeBoundProcs (module: Sym.Module; errList: Error.List);
  (* Adds type-bound procedures to the namespace of their record base type.  *)
    VAR
      ptr, record: Sym.Item;
    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Sym.ProcDecl DO
          IF ptr. isTypeBound & ~ptr. isForwardDecl THEN
            record := ptr. formalPars. receiver. type;
            IF (record IS Sym.Pointer) THEN
              record := record(Sym.Pointer). baseType
            END;
            WITH record: Sym.Record DO
              record. ns(Namespace.Extended). InsertTBProc (ptr, errList)
            ELSE  (* receiver is malformed in some way *)
            END
          END
        ELSE
        END;
        ptr := ptr. nextNested
      END
    END InsertTypeBoundProcs;

  PROCEDURE ResolveForwardDecl (item: Sym.Item; errList: Error.List);
  (* Checks the validity of procedure forward declarations, and adjusts the
     range of visibility of the forward declared procedures.  *)
    VAR
      ptr: Sym.Item;
      forward: Sym.ProcDecl;
      def: Sym.Declaration;
      class: Sym.Record;
      ns: Sym.Namespace;
    BEGIN
      IF (item # NIL) THEN
        IF (item IS Sym.ProcDecl) & item(Sym.ProcDecl). isForwardDecl THEN
          forward := item(Sym.ProcDecl);
          
          IF forward. isTypeBound THEN
            class := forward. Class();
            ns := class. Namespace();
            def := ns. IdentifyLocal (forward. parent, forward. name, TRUE)
          ELSE
            ns := forward. parent. Namespace();
            def := ns. IdentifyLocal (forward. parent, forward. name, TRUE)
          END;
          
          IF (def = NIL) THEN
            ErrDecl (unresolvedForwardDecl, forward, errList)
          ELSIF ~(def IS Sym.ProcDecl) THEN
            ErrDecl (forwardNameClash, forward, errList)
          ELSIF (def. visibleFrom < def. name. pos) THEN
            IF (def. visibleFrom >= 0) THEN (* this isn't imported *)
              ErrDecl (multipleForwardDecl, forward, errList)
            END
          ELSIF (def. visibleFrom < forward. visibleFrom) THEN
            ErrDecl (forwardAfterDefinition, forward, errList)
          ELSIF ~TR.IsValidForwardDecl (forward. formalPars,
                                         def(Sym.ProcDecl). formalPars) THEN
            ErrDecl (forwardMismatchFPars, forward, errList)
          ELSE
            def(Sym.ProcDecl). RegisterForwardDecl (forward)
          END
        END;
        
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ResolveForwardDecl (ptr, errList);
          ptr := ptr. nextNested
        END
      END
    END ResolveForwardDecl;
  
  PROCEDURE CheckExtendedRecords (item: Sym.Item; errList: Error.List);
  (* Performs semantic checks on the field and type-bound procedure of 
     records.  Also, this procedure sets the fields
     @ofield{Sym.ProcDecl.tbProcIndex}, and
     @ofield{Sym.Record.tbProcCount}.  *)
    VAR
      ptr: Sym.Item;
    
    PROCEDURE CheckRecord (record: Sym.Record);
      VAR
        i: LONGINT;
        proc: Sym.ProcDecl;
      BEGIN
        IF (record. tbProcCount = -1) THEN
          IF (record. baseType = NIL) OR 
             ~(record. baseType IS Sym.Record) THEN
            record. tbProcCount := 0
          ELSE
            CheckRecord (record. baseType(Sym.Record));
            record. tbProcCount := record. baseType(Sym.Record). tbProcCount
          END;
          record.ns(Namespace.Extended).CheckRestrictions (record, errList);

          IF ~record.isAbstract THEN
            (* check that no abstract procedure remain *)
            FOR i := 0 TO record.tbProcCount-1 DO
              proc := record.ns(Namespace.Extended).GetTBProcByIndex (i);
              IF proc.isAbstract THEN
                ErrType(procedureStillAbstract, record);
                lastError.SetStringAttrib("name",
                                          Msg.GetStringPtr(proc.name.str^));
              END;
            END;
          END;
        END
      END CheckRecord;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.Record DO
          CheckRecord (item)
        ELSE
        END;
        
        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CheckExtendedRecords (ptr, errList);
          ptr := ptr. nextNested
        END
      END
    END CheckExtendedRecords;
  
  PROCEDURE ResolveModifierFlags (item: Sym.Item; errList: Error.List);
    VAR
      ptr: Sym.Item;
      type: Sym.Type;
      
    PROCEDURE ResolveFlags (item: Sym.Item);
      VAR
        flag: Sym.Flag;

      PROCEDURE InvalidFlag (flag: Sym.Flag; code: INTEGER);
        BEGIN
          lastError := Error.New (createNamespaceContext, code);
          lastError. SetIntAttrib ("pos", flag.pos.pos);
          lastError. SetIntAttrib ("line", flag.pos.line);
          lastError. SetIntAttrib ("column", flag.pos.column);
          errList. Append (lastError)
        END InvalidFlag;

      PROCEDURE SetFlag (VAR flagAttribute: BOOLEAN; newValue: BOOLEAN);
        BEGIN
          IF (flagAttribute # newValue) THEN
            flagAttribute := newValue;
          ELSE
            InvalidFlag(flag, modifierFlagWithoutEffect);
          END;
        END SetFlag;
      
      BEGIN
        IF ~visited.HasKey(item) THEN
          visited.Set(item, NIL);
          
          flag := item.flagList;
          WHILE (flag # NIL) DO
            WITH item: Sym.VarDecl DO
              CASE flag.id OF
              | Sym.flagNoCopy:
                IF ~item.isParameter OR
                   item.isVarParam OR
                   ~((item.type IS Sym.Array) OR
                     (item.type IS Sym.Record)) THEN
                  (* NO_COPY is only applicable to value parameters of type
                     record or array *)
                  InvalidFlag(flag, invalidModifierFlag);
                ELSE
                  SetFlag(item.hasLocalCopy, FALSE);
                  item.isReadOnly := TRUE;
                END;
              | Sym.flagNilCompat:
                IF ~item.isPassPerReference THEN
                  InvalidFlag(flag, invalidModifierFlag);
                ELSE
                  SetFlag(item.permitArgumentNIL, TRUE);
                END;
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.Record DO
              CASE flag.id OF
              | Sym.flagAbstract:
                SetFlag(item.isAbstract, TRUE);
              | Sym.flagNoDescriptor:
                SetFlag(item.hasDescriptor, FALSE);
              | Sym.flagNotExtensible:
                SetFlag(item.isExtensible, FALSE);
              | Sym.flagUnion:
                SetFlag(item.isUnion, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.Array DO
              CASE flag.id OF
              | Sym.flagNoDescriptor:
                SetFlag(item.hasDescriptor, FALSE);
              | Sym.flagNoLengthInfo:
                IF ~item.isOpenArray OR
                   TR.IsOpenArrayType(item.elementType) THEN
                  InvalidFlag(flag, invalidModifierFlag);
                ELSE
                  SetFlag(item.hasLengthInfo, FALSE);
                END;
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.Pointer DO
              CASE flag.id OF
              | Sym.flagCString:
                SetFlag(item.doCArrayAssignment, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.ProcDecl DO
              CASE flag.id OF
              | Sym.flagAbstract:
                SetFlag(item.isAbstract, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            ELSE
              InvalidFlag(flag, invalidModifierFlag);
            END;
            flag := flag.nextFlag;
          END;
        END;
      END ResolveFlags;

    PROCEDURE ResolveFlagsDirect(referrer, item: Sym.Item);
      BEGIN
        IF (referrer.Module() = item.Module()) THEN
          ResolveFlags(item);
        END;
      END ResolveFlagsDirect;
    
    BEGIN
      IF (item # NIL) THEN
        ResolveFlags(item);
        
        WITH item: Sym.Pointer DO
          IF (item.baseType IS Sym.Record) &
             ~item.baseType(Sym.Record).hasDescriptor THEN
            item.isStatic := TRUE;
          END;

        | item: Sym.VarDecl DO
          IF item.isParameter THEN
            type := item.type;
            ResolveFlagsDirect(item, type);
            IF (type IS Sym.Record) & ~type(Sym.Record).hasDescriptor OR
               (type IS Sym.Array) & ~type(Sym.Array).hasLengthInfo THEN
              item.supplementArgs := FALSE;
            END;
          END;
        ELSE  (* ignore *)
        END;
        
        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ResolveModifierFlags (ptr, errList);
          ptr := ptr. nextNested
        END
      END
    END ResolveModifierFlags;

  PROCEDURE LinkFileSections(ld: Sym.LinkDirective): LONGINT;
    BEGIN
      IF (ld = NIL) THEN
        RETURN 0;
      ELSE
        WITH ld: Sym.LinkFile DO
          RETURN LinkFileSections(ld.next)+1;
        ELSE
          RETURN LinkFileSections(ld.next);
        END;
      END;
    END LinkFileSections;
  
  BEGIN
    ASSERT (errList # NIL);

    CASE root.class OF
    | Sym.mcInterface, Sym.mcForeign:
      IF (LinkFileSections(root.linkDirectives) > 1) THEN
        ErrDecl(atMostOneLinkFile, root, errList);
      END;
    ELSE
    END;
    
    (* The declarations of a module are resolved in a multi-pass process.
       Instead of reading the parse tree, creating the symbol tale, and
       checking the rules associated with declarations in a single convoluted
       process, the whole task is broken into handy sub-tasks.  Each of the
       sub-tasks is ideally performing a single job, depending on the results
       of the previous sub-tasks, and providing the foundation for further
       processing.  *)
    ImportAllModules (root);
    IF ~errList.NoErrors() THEN
      (* bail out if there are any errors during import; this saves a lot
         of checks later on, because otherwise we would have to assume that
         any reference to an imported object is broken *)
      RETURN
    END;
    
    (* first pass: create namespace objects for module, procedures, and
       records (excluding any type-bound procedures and procedure 
       forward declarations) *)
    PopulateNamespace (root);
    
    (* second pass: check local uniqueness constraint for module, procedure, 
       and record namespaces; note: for records, this checks only a small
       part of the restrictions placed on their namespaces *)
    CheckLocalUniqueness (root, errList);
    
    (* third pass: connect namespace links; the namespaces of procedures are
       nested into the enclosing procedure/module *)
    ConnectNamespaces (root, predefModule, errList);
    
    
    (* here holds: module and procedure namespaces can be searched for
                   declarations, ignoring procedure forward declarations *)
    
    
    (* fourth pass: resolve type names in declarations, and fix up namespaces
       for record types *)
    ResolveTypeNames (root, NIL, errList);

    (* CAUTION: Some type names may not have been resolved successfully
       past this point.  Check for instances of Sym.TypeName before assuming
       that the types are valid.  *)
      
    (* fourth and a half pass: resolve modifier flags that may be attached to
       declarations and types; this must be done before dealing with any
       restrictions imposed on data type *)
    visited := Dictionary.New();
    ResolveModifierFlags (root, errList);
    
    (* fifth pass: check type restrictions of declarations *)
    CheckTypeRestrictions (root, errList);

    (* sixth pass: traverse list of type-bound procedures and insert them
       into the corresponding record namespace *)
    InsertTypeBoundProcs (root, errList);

    (* seventh pass: fixup formal parameter types, so that the type has
       a list of direct references to the formal parameters *)
    (*CollectFormalPars (root);  obsolete, is now done directly in the 
      Builder's Finalize method *)

    (* eighth pass: resolve forward declarations of procedures *)
    ResolveForwardDecl (root, errList);


    (* here holds: any namespace (module, procedure, or record) can be
       searched and is guaranteed to deliver the correct results *)
    
    (* nineth pass: check namespace restrictions imposed on extended
       records and assign indexes to type-bound procedures *)
    CheckExtendedRecords (root, errList);
    
    ResolveRef.Resolve (root, errList)
  END CreateNamespace;

(*PROCEDURE CreateNamespaceRec*(root: Sym.Module;
                              errList: Error.List);
  VAR
    ptr: Sym.Item;
  BEGIN
    IF (root.ns = NIL) THEN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) & (errList.msgCount = 0) DO
        WITH ptr: Sym.Import DO
          CreateNamespaceRec(ptr.externalSymTab, errList);
        ELSE
        END;
        ptr := ptr. nextNested
      END;
      IF (errList.msgCount = 0) THEN
        CreateNamespace(root, errList);
      END;
    END;
  END CreateNamespaceRec;*)
    
PROCEDURE Init* ();
  VAR
    stb: Builder.Builder;
    predef, system: Sym.Module;
  BEGIN
    predefModule := NIL;
    systemModule := NIL;
    
    stb := Builder.New();
    predef := Predef.CreatePredef (stb);
    system := Predef.CreateSYSTEM (stb);
    CreateNamespace (predef, Error.NewList (""));
    CreateNamespace (system, Error.NewList(""));
    
    predefModule := predef;
    systemModule := system;
  END Init;
    
BEGIN
  NEW (createNamespaceContext);
  Error.InitContext (createNamespaceContext, "OOC:SymbolTable:CreateNamespace");
  Init;
END OOC:SymbolTable:CreateNamespace.
