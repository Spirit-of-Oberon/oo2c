(* 	$Id$	 *)
MODULE OOC:SymbolTable:CreateNamespace [OOC_EXTENSIONS];
(*  Creates namespaces for module, and resolves type names in declarations.
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
  OOC:Error, OOC:SymbolTable:Item, OOC:SymbolTable:Namespace,
  OOC:SymbolTable:TypeRules, OOC:SymbolTable:ImportModules,
  OOC:Config:Repositories, OOC:Doc:ResolveRef;


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
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  createNamespaceContext: ErrorContext;


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
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE CreateNamespace* (root: Item.Module;
                            predefModule, systemModule: Item.Module;
                            tr: TypeRules.Rules;
                            repositories: Repositories.Section;
                            errList: Error.List);
(**Populates the namespaces of the symbol table @oparam{root} and performs
   semantic checks on the declarations.  It is assumed, that the namespace
   of module @oparam{root} is nested into the namespace of module
   @oparam{predefModule}.  Typically, @oparam{predefModule} defines the 
   predefined entities of the language, and is defined by module
   @omodule{*OOC:SymbolTable:Predef}.
   
   The type rules used to check the declarations are taken from object
   @oparam{tr}.  Any errors are reported to the error list @oparam{errList}.
   After successful completion of this procedure, the symbol table
   @oparam{root} can be used to resolve any using occurences of names within
   the module's source code.  *)
  VAR
    lastError: Error.Msg;
    
  PROCEDURE Err (code: Error.Code; tname: Item.TypeName);
    VAR
      pos: Item.Position;
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
  
  PROCEDURE ErrType (code: Error.Code; type: Item.Type);
    BEGIN
      lastError := Error.New (createNamespaceContext, code);
      lastError. SetIntAttrib ("pos", type. position. pos);
      lastError. SetIntAttrib ("line", type. position. line);
      lastError. SetIntAttrib ("column", type. position. column);
      errList. Append (lastError)
    END ErrType;
  
  PROCEDURE ErrDecl (code: Error.Code; decl: Item.Declaration; errList: Error.List);
    BEGIN
      lastError := Error.New (createNamespaceContext, code);
      lastError. SetIntAttrib ("pos", decl. name. pos);
      lastError. SetIntAttrib ("line", decl. name. line);
      lastError. SetIntAttrib ("column", decl. name. column);
      errList. Append (lastError)
    END ErrDecl;

  PROCEDURE ImportAllModules (root: Item.Module);
    VAR
      ptr: Item.Item;
    BEGIN
      ImportModules.ImportModules (systemModule, repositories, root, errList);
      IF (errList. msgCount = 0) THEN
        ptr := root. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Item.Import DO
            IF (ptr. externalSymTab. ns = NIL) THEN
              (* for each of the imported modules: create namespace information
                 and resolve any reference commands in embedded documentation
                 strings *)
              CreateNamespace (ptr. externalSymTab, predefModule, systemModule,
                               tr, repositories, errList);
(*              ResolveRef.Resolve (ptr. externalSymTab, repositories, errList)
... moved to end of CreateNamespace *)
            END
          ELSE
          END;
          ptr := ptr. nextNested
        END
      END
    END ImportAllModules;
  
  PROCEDURE PopulateNamespace (item: Item.Item);
  (* For all definitions that include a namespace (i.e., for module, procedure,
     and record type), create a namespace that initially includes all the
     declarations local to this particular definition.  When this procedure
     is done, every definition with local declarations contains a mapping of
     identifiers to declarations.
     
     Note: Type-bound procedures and forward declarations of procedures are
     @emph{not} included in the namespace mapping.  *)
    VAR
      ptr: Item.Item;

    PROCEDURE Assemble (item: Item.Item; nested: BOOLEAN): Item.Namespace;
      VAR
        ptr: Item.Item;
        c: LONGINT;
        da: Item.DeclarationArray;

      PROCEDURE IsDeclaration (item: Item.Item): BOOLEAN;
        BEGIN
          WITH item: Item.ProcDecl DO
            RETURN ~(item. isTypeBound OR item. isForwardDecl)
          ELSE
            RETURN (item IS Item.Declaration)
          END
        END IsDeclaration;
      
      PROCEDURE Quicksort (da: Item.DeclarationArray; l, r: LONGINT);
        VAR
          i, j: LONGINT;
          t: Item.Declaration;
          v: Item.NameString;
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
        IF (item IS Item.ProcDecl) (*&
           (item(Item.ProcDecl). visibleFrom >= 0) ... *) THEN
          (* add formal parameters, but only if the module is not an imported
             symbol file; otherwise, due to the missing visibility information,
             identification of parameter types may wrongly take a parameter
             name as defining occurence *)
          ptr := item(Item.ProcDecl). formalPars. nestedItems;
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
            da[c] := ptr(Item.Declaration);
            INC (c)
          END;
          ptr := ptr. nextNested
        END;
        IF (item IS Item.ProcDecl) (*&     (* add formal parameters *)
           (item(Item.ProcDecl). visibleFrom >= 0)...*) THEN
          ptr := item(Item.ProcDecl). formalPars. nestedItems;
          WHILE (ptr # NIL) DO
            IF IsDeclaration (ptr) THEN
              da[c] := ptr(Item.Declaration);
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

        WITH item: Item.Module DO
          item. SetNamespace (Assemble (item, TRUE))
        | item: Item.ProcDecl DO
          item. SetNamespace (Assemble (item, TRUE))
        | item: Item.Record DO
          item. SetNamespace (Assemble (item, FALSE))
        ELSE  (* no other item is associated with a namespace *)
        END
      END
    END PopulateNamespace;
  
  PROCEDURE CheckLocalUniqueness (item: Item.Item; errList: Error.List);
  (* Using the namespace information created by @oproc{PopulateNamespace},
     check that any declaration's name is unique in its local namespace.
     That is, if a namespace contains two local declarations of the same name,
     the second declaration is reported as faulty.  *)
    VAR
      ptr: Item.Item;
      ns0: Item.Namespace;
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
  
  PROCEDURE ConnectNamespaces (item: Item.Item; predefModule: Item.Module;
                               errList: Error.List);
  (* For the module and procedure namespaces, set the nesting information 
     of their respective namespaces.  Any module, except the virtual module
     defining the predefined entities, is nested in the predefined 
     namespace.  A procedure's namespace is nested in the one of the 
     enclosing procedure, or in the module's namespace if it is declared
     on the module level.
     
     Note: Record namespaces are @emph{not} completed by this procedure.  *)
    VAR
      ptr: Item.Item;
    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.Module DO
          IF (predefModule # NIL) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (predefModule. ns(Namespace.Namespace))
          END
        | item: Item.ProcDecl DO
          IF (item. parent IS Item.Module) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (item. parent(Item.Module). 
                                       ns(Namespace.Namespace))
          ELSIF (item. parent IS Item.ProcDecl) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (item. parent(Item.ProcDecl). 
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
  
  PROCEDURE ResolveTypeNames (item: Item.Item; contextOfUse: Item.Item;
                              tr: TypeRules.Rules; errList: Error.List);
  (* Replaces all type names in @oparam{item} with a reference to the 
     indicated type.  Names are resolved in the context of the procedure
     (or module) @oparam{contextOfUse}.  Restrictions placed on the base
     type of a record are checked.  *)
    VAR
      ptr: Item.Item;
      baseType: Item.Type;
      
    PROCEDURE GetTypeByName (typeName: Item.Type; contextOfUse: Item.Item; 
                      extendedSearch: BOOLEAN; errList: Error.List): Item.Type;
    (**Resolves type name @oparam{typeName}, within the context of procedure
       (or module) @oparam{contextOfUse}.  With @oparam{extendedSearch} set to
       @code{TRUE} and the standard search failing, perform an extended search
       in the local namespace that ignores the range visibility of
       declarations.  This is used to resolve names used as pointer base
       types.  *)
      VAR
        item: Item.Item;
        ns: Item.Namespace;
      BEGIN
        WITH typeName: Item.TypeName DO
          ns := contextOfUse. Namespace();
          IF (typeName. module # NIL) THEN
            (* resolve module name to get to external namespace *)
            item := ns. Identify (contextOfUse, typeName. module, FALSE);
            IF (item = NIL) THEN
              Err (undeclaredModule, typeName);
              RETURN typeName
            ELSIF ~(item IS Item.Import) THEN
              Err (notModule, typeName);
              RETURN typeName
            ELSE
              ns := item(Item.Import). externalSymTab. ns;
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
          ELSIF ~(item IS Item.TypeDecl) THEN
            Err (notTypeName, typeName);
            RETURN typeName
          ELSE
            RETURN item(Item.TypeDecl). type
          END
        ELSE
          RETURN typeName
        END
      END GetTypeByName;

    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.TypeDecl DO
          item. type := GetTypeByName (item. type, contextOfUse, FALSE, errList)
          
        | item: Item.VarDecl DO
          item. type := GetTypeByName (item. type, contextOfUse, FALSE, errList);
        | item: Item.FieldDecl DO
          item. type := GetTypeByName (item. type, contextOfUse, FALSE, errList)
          
        | item: Item.Pointer DO
          item. baseType := GetTypeByName (item. baseType,
                                           contextOfUse, TRUE, errList)
        | item: Item.FormalPars DO
          IF (item. resultType # NIL) THEN
            item. resultType := GetTypeByName (item. resultType,
                                               contextOfUse, FALSE, errList)
          END
          
        | item: Item.Array DO
          item. elementType := GetTypeByName (item. elementType,
                                              contextOfUse, FALSE, errList)
        | item: Item.Record DO
          IF (item. baseType # NIL) THEN
            baseType := GetTypeByName (item. baseType, contextOfUse, FALSE, errList);
            IF ~(baseType IS Item.TypeName) THEN
              IF tr. IsValidRecordBaseType (baseType) THEN
                item. ns(Namespace.Extended). 
                  SetBaseNamespace (baseType(Item.Record). 
                                      ns(Namespace.Namespace));
                item. baseType := baseType
              ELSE
                Err (illegalRecordBase, item. baseType(Item.TypeName))
              END
            END
          END
        
        (* scope objects: fix context of use for using 
           occurences of identifiers *)
        | item: Item.Module DO
          contextOfUse := item
        | item: Item.ProcDecl DO
          contextOfUse := item
        ELSE  (* ignore any other kind items *)
        END;
        
        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ResolveTypeNames (ptr, contextOfUse, tr, errList);
          ptr := ptr. nextNested
        END
      END
    END ResolveTypeNames;
  
  PROCEDURE CheckTypeRestrictions (item: Item.Item; tr: TypeRules.Rules;
                                   errList: Error.List);
  (* Checks the type restrictions placed by the language on declarations
     and definitions.  *)
    VAR
      ptr: Item.Item;
      type: Item.Type;
    
    PROCEDURE CheckOpenArray (type, srcCodeType: Item.Type);
      BEGIN
        IF ~(type IS Item.TypeName) & tr. IsOpenArrayType (type) THEN
          ErrType (invalidOpenArray, srcCodeType)
        END
      END CheckOpenArray;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.VarDecl DO
          type := item. type;
          IF item. isParameter THEN
            IF ~(type IS Item.TypeName) & ~tr. IsValidParameterType (type) THEN
              ErrType (invalidParameterType, item. srcCodeType)
            END
          ELSE
            CheckOpenArray (item. type, item. srcCodeType)
          END;
          IF item. isReceiver & ~(type IS Item.TypeName) THEN
            IF ~tr. IsValidReceiverType (type) THEN
              ErrType (invalidReceiverType, item. srcCodeType)
            ELSIF (type IS Item.Record) & ~item. isVarParam THEN
              ErrType (invalidReceiverModeRecord, item. srcCodeType)
            ELSIF (type IS Item.Pointer) & item. isVarParam THEN
              ErrType (invalidReceiverModePointer, item. srcCodeType)
            END
          END
          
        | item: Item.FieldDecl DO
          CheckOpenArray (item. type, item. srcCodeType)
          
        | item: Item.Pointer DO
          type := item. baseType;
          IF ~(type IS Item.TypeName) & ~tr. IsValidPointerBaseType (type) THEN
            ErrType (invalidPointerBaseType, item. srcCodeBaseType)
          END
          
        | item: Item.FormalPars DO
          type := item. resultType;
          IF (type # NIL) & ~(type IS Item.TypeName) &
             ~tr. IsValidResultType (type) THEN
            ErrType (invalidResultType, item. srcCodeResultType)
          END
          
        | item: Item.Array DO
          type := item. elementType;
          IF ~(type IS Item.TypeName) &
             ~tr. IsValidArrayElementType (type, item. isOpenArray) THEN
            ErrType (invalidArrayElementType, item. srcCodeElementType)
          END
        
        ELSE  (* ignore any other kind of items *)
        END;
        
        (* descend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CheckTypeRestrictions (ptr, tr, errList);
          ptr := ptr. nextNested
        END
      END
    END CheckTypeRestrictions;
  
  PROCEDURE InsertTypeBoundProcs (module: Item.Module; errList: Error.List);
  (* Adds type-bound procedures to the namespace of their record base type.  *)
    VAR
      ptr, record: Item.Item;
    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Item.ProcDecl DO
          IF ptr. isTypeBound & ~ptr. isForwardDecl THEN
            record := ptr. formalPars. receiver. type;
            IF (record IS Item.Pointer) THEN
              record := record(Item.Pointer). baseType
            END;
            WITH record: Item.Record DO
              record. ns(Namespace.Extended). InsertTBProc (ptr, errList)
            ELSE  (* receiver is malformed in some way *)
            END
          END
        ELSE
        END;
        ptr := ptr. nextNested
      END
    END InsertTypeBoundProcs;

  PROCEDURE ResolveForwardDecl (item: Item.Item; tr: TypeRules.Rules;
                                errList: Error.List);
  (* Checks the validity of procedure forward declarations, and adjusts the
     range of visibility of the forward declared procedures.  *)
    VAR
      ptr: Item.Item;
      forward: Item.ProcDecl;
      def: Item.Declaration;
      class: Item.Record;
      ns: Item.Namespace;
    BEGIN
      IF (item # NIL) THEN
        IF (item IS Item.ProcDecl) & item(Item.ProcDecl). isForwardDecl THEN
          forward := item(Item.ProcDecl);
          
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
          ELSIF ~(def IS Item.ProcDecl) THEN
            ErrDecl (forwardNameClash, forward, errList)
          ELSIF (def. visibleFrom < def. name. pos) THEN
            IF (def. visibleFrom >= 0) THEN (* this isn't imported *)
              ErrDecl (multipleForwardDecl, forward, errList)
            END
          ELSIF (def. visibleFrom < forward. visibleFrom) THEN
            ErrDecl (forwardAfterDefinition, forward, errList)
          ELSIF ~tr. IsValidForwardDecl (forward. formalPars,
                                         def(Item.ProcDecl). formalPars) THEN
            ErrDecl (forwardMismatchFPars, forward, errList)
          ELSE
            def(Item.ProcDecl). RegisterForwardDecl (forward)
          END
        END;
        
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ResolveForwardDecl (ptr, tr, errList);
          ptr := ptr. nextNested
        END
      END
    END ResolveForwardDecl;
  
  PROCEDURE CheckExtendedRecords (item: Item.Item; tr: TypeRules.Rules;
                                  errList: Error.List);
  (* Performs semantic checks on the field and type-bound procedure of 
     records.  Also, this procedure sets the fields
     @ofield{OOC:SymbolTable:Item.ProcDecl.tbProcIndex}, and
     @ofield{OOC:SymbolTable:Item.Record.tbProcCount}.  *)
    VAR
      ptr: Item.Item;
    
    PROCEDURE CheckRecord (record: Item.Record);
      BEGIN
        IF (record. tbProcCount = -1) THEN
          IF (record. baseType = NIL) OR 
             ~(record. baseType IS Item.Record) THEN
            record. tbProcCount := 0
          ELSE
            CheckRecord (record. baseType(Item.Record));
            record. tbProcCount := record. baseType(Item.Record). tbProcCount
          END;
          record. ns(Namespace.Extended). 
            CheckRestrictions (record, tr, errList)
        END
      END CheckRecord;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.Record DO
          CheckRecord (item)
        ELSE
        END;
        
        (* decend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CheckExtendedRecords (ptr, tr, errList);
          ptr := ptr. nextNested
        END
      END
    END CheckExtendedRecords;
  
  BEGIN
    ASSERT (errList # NIL);

    (* The declarations of a module are resolved in a multi-pass process.
       Instead of reading the parse tree, creating the symbol tale, and
       checking the rules associated with declarations in a single convoluted
       process, the whole task is broken into handy sub-tasks.  Each of the
       sub-tasks is ideally performing a single job, depending on the results
       of the previous sub-tasks, and providing the foundation for further
       processing.  *)
    ImportAllModules (root);
    IF (errList. msgCount # 0) THEN
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
    ResolveTypeNames (root, NIL, tr, errList);

    (* CAUTION: Some type names may not have been resolved successfully
       past this point.  Check for instances of Item.TypeName before assuming
       that the types are valid.  *)
      
    (* fifth pass: check type restrictions of declarations *)
    CheckTypeRestrictions (root, tr, errList);

    (* sixth pass: traverse list of type-bound procedures and insert them
       into the corresponding record namespace *)
    InsertTypeBoundProcs (root, errList);

    (* seventh pass: fixup formal parameter types, so that the type has
       a list of direct references to the formal parameters *)
    (*CollectFormalPars (root);  obsolete, is now done directly in the 
      Builder's Finalize method *)

    (* eighth pass: resolve forward declarations of procedures *)
    ResolveForwardDecl (root, tr, errList);


    (* here holds: any namespace (module, procedure, or record) can be
       searched and is guaranteed to deliver the correct results *)


    (* nineth pass: check namespace restrictions imposed on extended
       records and assign indexes to type-bound procedures *)
    CheckExtendedRecords (root, tr, errList);
    
    
    ResolveRef.Resolve (root, repositories, errList)
  END CreateNamespace;

BEGIN
  NEW (createNamespaceContext);
  Error.InitContext (createNamespaceContext, "OOC:SymbolTable:CreateNamespace")
END OOC:SymbolTable:CreateNamespace.
