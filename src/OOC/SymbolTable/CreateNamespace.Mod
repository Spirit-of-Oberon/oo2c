(* 	$Id: CreateNamespace.Mod,v 1.74 2004/01/20 06:59:57 sgreenhill Exp $	 *)
MODULE OOC:SymbolTable:CreateNamespace [OOC_EXTENSIONS];
(*  Creates namespaces for module, and resolves type names in declarations.
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
  Msg, IO, ADT:ArrayList, ADT:Dictionary, OOC:Error, Sym := OOC:SymbolTable,
  OOC:SymbolTable:Namespace, OOC:SymbolTable:Uses,
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
  notException = 26;
  invalidTypeBound = 27;
  notParametricType = 28;
  tooFewTypeArgs = 29;
  tooManyTypeArgs = 30;
  notExtensionOfBound = 31;
  tooFewTypeAliases = 32;
  cannotDefineTypeAliases = 33;
  inconsistentVtable = 34;
  tbProcForImportedRecord = 35;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  createNamespaceContext: ErrorContext;
  predefModule: Sym.Module;
  exception-: Sym.VarDecl;
  (**Predefined pseudo variable @samp{EXCEPTION}, holding the current exception
     within a @code{CATCH} block.  *)
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
      t := "Cannot create instance of abstract type"
    | abstractProcForConcreteRecord:
      t := "Receiver type is not abstract"
    | abstractProcNotExported:
      t := "Abstract procedure must be exported"
    | procedureStillAbstract:
      t := "Inherited procedure `${name}' is still abstract"
    | atMostOneLinkFile:
      t := "Module must provide at most one LINK FILE directive"
    | notException:
      t := "Type is not an extension of `Exception.Exception'"
    | invalidTypeBound:
      t := "Invalid type bound"
    | notParametricType:
      t := "This is not a parametric type"
    | tooFewTypeArgs:
      t := "Too few type arguments"
    | tooManyTypeArgs:
      t := "Too many type arguments"
    | notExtensionOfBound:
      t := "This is not an extension of the type bound"
    | tooFewTypeAliases:
      t := "The base record type has ${count} type parameter(s)"
    | cannotDefineTypeAliases:
      t := "The base record type has no type parameters"
    | inconsistentVtable:
      t := "VTABLE flag is inconsistent with base type"
    | tbProcForImportedRecord:
      t := "Receiver's base record is imported";
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE ResolveQualident* (ns: Sym.Namespace; contextOfUse: Sym.Item;
                             uses: Uses.Uses;
                             module, ident: Sym.Name): Sym.Declaration;
  VAR
    m, decl: Sym.Declaration;
  BEGIN
    m := ns.Identify(contextOfUse, module, FALSE);
    IF (m = NIL) OR ~(m IS Sym.Import) THEN
      RETURN NIL;
    ELSE
      Uses.Mark(m, uses, module);
      ns := m(Sym.Import).externalSymTab.ns;
    END;
    decl := ns.Identify(contextOfUse, ident, FALSE);
    Uses.Mark(decl, uses, ident);
    RETURN decl;
  END ResolveQualident;

PROCEDURE CreateNamespace* (root: Sym.Module;
                            uses: Uses.Uses;
                            errList: Error.List)
RAISES IO.Error;
(**Populates the namespaces of the symbol table @oparam{root} and performs
   semantic checks on the declarations.  It is assumed, that the namespace
   of module @oparam{root} is nested into the namespace of the pseudo module
   holding the predefined objects.
   
   The type rules used to check the declarations are taken from object
   @omodule{TR}.  Any errors are reported to the error list @oparam{errList}.
   After successful completion of this procedure, the symbol table
   @oparam{root} can be used to resolve any using occurences of names within
   the module's source code.

   If @oparam{uses} is not @code{NIL}, then declarations are registered with
   this object, and it is notified for references to module and type names.  *)
  VAR
    lastError: Error.Msg;
    visited, privateRecords: Dictionary.Dictionary;
    unpatchedQualTypes: ArrayList.ArrayList;
    i: LONGINT;
    
  PROCEDURE SetErrPos(err: Error.Msg; pos: Sym.Position);
    VAR
      i: LONGINT;
    BEGIN
      i := pos.pos;
      IF (i < 0) THEN
        i := 0;
      END;
      err. SetIntAttrib ("pos", i);
      err. SetIntAttrib ("line", pos. line);
      err. SetIntAttrib ("column", pos. column);
    END SetErrPos;
  
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
      SetErrPos(lastError, pos);
      errList. Append (lastError)
    END Err;
  
  PROCEDURE ErrType (code: Error.Code; type: Sym.Type);
    BEGIN
      lastError := Error.New (createNamespaceContext, code);
      SetErrPos(lastError, type.position);
      errList. Append (lastError)
    END ErrType;
  
  PROCEDURE ErrDecl (code: Error.Code; decl: Sym.Declaration; errList: Error.List);
    BEGIN
      lastError := Error.New (createNamespaceContext, code);
      SetErrPos(lastError, decl.name);
      errList. Append (lastError)
    END ErrDecl;

  PROCEDURE ImportAllModules (root: Sym.Module)
  RAISES IO.Error;
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
              CreateNamespace (ptr. externalSymTab, NIL, errList);
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
     @emph{not} included in the namespace mapping.

     This procedure also adds all record types to @ovar{privateRecords}.  *)
    CONST
      namespaceNested = 0;
      namespaceExtended = 1;
    VAR
      ptr: Sym.Item;

    PROCEDURE Assemble (item: Sym.Item; nsType: SHORTINT): Sym.Namespace;
      VAR
        ptr: Sym.Item;
        c: LONGINT;
        da: Sym.DeclarationArray;

      PROCEDURE IsDeclaration (x: Sym.Item): BOOLEAN;
        BEGIN
          WITH x: Sym.ProcDecl DO
            RETURN ~(x.IsTypeBound() OR x. isForwardDecl)
          | x: Sym.TypeDecl DO
            IF (x.type = NIL) THEN
              (* this is an alias type introduced by a receiver; such a
                 declaration is only added to the namespace of the formal
                 parameters, _not_ to that of the procedure *)
              RETURN (item IS Sym.FormalPars);
            ELSE
              RETURN TRUE;
            END;
          | x: Sym.VarDecl DO
            (* formal parameters are added to the namespace of the procedure,
               but _not_ to the namespace of the FormalPars object *)
            RETURN ~x.isParameter OR ~(item IS Sym.FormalPars);
          ELSE
            RETURN (x IS Sym.Declaration)
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
        IF (item IS Sym.ProcDecl) THEN
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
        IF (item IS Sym.ProcDecl) THEN    (* add formal parameters *)
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

        CASE nsType OF
        | namespaceNested  : RETURN Namespace.NewNested(da, c);
        | namespaceExtended: RETURN Namespace.NewExtended(da, c);
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
          item. SetNamespace (Assemble (item, namespaceNested))
        | item: Sym.ProcDecl DO
          item. SetNamespace (Assemble (item, namespaceNested))
        | item: Sym.Record DO
          item. SetNamespace (Assemble (item, namespaceExtended));
          privateRecords.Set(item, NIL);
        | item: Sym.TypePars DO
          item. SetNamespace (Assemble (item, namespaceNested));
        | item: Sym.FormalPars DO
          item. SetNamespace (Assemble (item, namespaceNested));
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

    PROCEDURE SetEnclosingParent(ns: Namespace.Nested; parent: Sym.Item);
      BEGIN
        IF (parent IS Sym.Module) THEN
          ns.SetEnclosingNamespace
              (parent(Sym.Module).ns(Namespace.Namespace));
        ELSIF (parent IS Sym.ProcDecl) THEN
          ns.SetEnclosingNamespace
              (parent(Sym.ProcDecl).ns(Namespace.Namespace));
        END
      END SetEnclosingParent;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.Module DO
          IF (predefModule # NIL) THEN
            item. ns(Namespace.Nested). 
              SetEnclosingNamespace (predefModule. ns(Namespace.Namespace))
          END
        | item: Sym.ProcDecl DO
          item.ns(Namespace.Nested).SetEnclosingNamespace
              (item.formalPars.ns(Namespace.Namespace));
        | item: Sym.TypePars DO
          SetEnclosingParent(item.ns(Namespace.Nested), item. parent);
        | item: Sym.FormalPars DO
          IF (item.parent IS Sym.ProcDecl) &
             (item.parent(Sym.ProcDecl).formalPars = item) THEN
            SetEnclosingParent(item.ns(Namespace.Nested), item.parent.parent);
          ELSE  (* procedure type definition *)
            SetEnclosingParent(item.ns(Namespace.Nested), item.parent);
          END;
        ELSE  (* no other item is associated with a namespace *)
        END;      

        (* descend into nested objects *)
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ConnectNamespaces (ptr, predefModule, errList);
          ptr := ptr. nextNested
        END
      END
    END ConnectNamespaces;
  
  PROCEDURE ResolveTypeNames (item: Sym.Item; contextOfUse: Sym.Item;
                              unpatchedQualTypes: ArrayList.ArrayList;
                              errList: Error.List);
  (* Replaces all type names in @oparam{item} with a reference to the 
     indicated type.  Names are resolved in the context of the procedure
     (or module) @oparam{contextOfUse}.  Restrictions placed on the base
     type of a record are checked.

     Any qualified type instance @otype{Sym.QualType} added for a reference to
     a parametric type without a argument list @samp{<@dots{}>} is put into
     @oparam{unpatchedQualTypes} for later fixup.  *)
    VAR
      ptr: Sym.Item;
      i, typeDeclCount: LONGINT;
      typePars: Sym.TypePars;
      
    PROCEDURE GetTypeByName (typeName: Sym.Type; contextOfUse: Sym.Item; 
                             extendedSearch: BOOLEAN;
                             addQualTypeDefaults: BOOLEAN;
                             errList: Error.List): Sym.Type;
    (**Resolves type name @oparam{typeName}, within the context of procedure
       (or module) @oparam{contextOfUse}.  With @oparam{extendedSearch} set to
       @code{TRUE} and the standard search failing, perform an extended search
       in the local namespace that ignores the range visibility of
       declarations.  This is used to resolve names used as pointer base types.

       With @oparam{addQualTypeDefaults}, a reference to a parametric type is
       converted into an instance of @otype{Sym.QualType}, using the parameter
       bounds as arguments.  *)
      VAR
        item, itemRedir: Sym.Declaration;
        ns: Sym.Namespace;
        type: Sym.Type;
        qt: Sym.QualType;
      BEGIN
        WITH typeName: Sym.TypeName DO
          ns := contextOfUse. Namespace();
          IF (typeName. module # NIL) THEN
            IF typeName.IsPredefReference() THEN
              ns := predefModule.ns;
            ELSE
              (* resolve module name to get to external namespace *)
              item := ns. Identify (contextOfUse, typeName. module, FALSE);
              Uses.Mark(item, uses, typeName.module);
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
          END;
          item := ns. Identify (contextOfUse, typeName. ident, FALSE);
          IF (item = NIL) & extendedSearch THEN
            item := ns. IdentifyLocal (contextOfUse, typeName. ident, TRUE);
            IF (item = NIL) & (contextOfUse IS Sym.TypePars) THEN
              (* with parametric types, the local namespace may contain just
                 the formal parameter names; compensate by going one level
                 higher *)
              item := ns(Namespace.Nested).nestedIn.IdentifyLocal
                  (contextOfUse, typeName. ident, TRUE);
            END;
          END;

          IF (item = NIL) THEN
            Err (undeclaredIdent, typeName);
            RETURN typeName
          ELSE
            IF (typeName.module = NIL) &
               (item IS Sym.TypeDecl) & (item.parent = predefModule) THEN
              (* mark type name as predefined type *)
              typeName.MarkAsPredefReference();
            END;
            
            (* if the type name refers to a name redirection, then resolve the
               redirection and continue with the resulting symbol table entry  *)
            Uses.Mark(item, uses, typeName.ident);
            itemRedir := item;
            WITH itemRedir: Sym.Redirect DO
              item := ResolveQualident(contextOfUse.Namespace(), contextOfUse,
                                      uses, itemRedir.module, itemRedir.ident);
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
              (* the right hand side of a type declaration might be another
                 type name *)
              type := GetTypeByName(item(Sym.TypeDecl).type, contextOfUse,
                                    extendedSearch, addQualTypeDefaults,
                                    errList);
              
              IF addQualTypeDefaults & (type.typePars # NIL) &
                 ~(type IS Sym.TypeVar) THEN
                NEW(qt);
                Sym.InitQualType(qt, NIL, type.position, type, NIL);
                unpatchedQualTypes.Append(qt);
                RETURN qt;
              ELSE
                RETURN type;
              END;
            END
          END;
          
        | typeName: Sym.QualType DO
          typeName.baseType := GetTypeByName(typeName.baseType, contextOfUse,
                                             extendedSearch, FALSE, errList);
          RETURN typeName;
          
        ELSE
          RETURN typeName
        END
      END GetTypeByName;

    PROCEDURE CollectFormalPars (item: Sym.FormalPars);
    (* Sets the field @ofield{Sym.FormalPars.params}.  Doing this here means
       we can omit this field from the symbol file, eliminating a few bytes
       of redundancy.  *)
      VAR
        ptr: Sym.Item;
        c: LONGINT;
      BEGIN
        c := 0;
        ptr := item.nestedItems;
        WHILE (ptr # NIL) DO
          IF (ptr IS Sym.VarDecl) & 
             ptr(Sym.VarDecl).isParameter &
             ~ptr(Sym.VarDecl).isReceiver THEN
            INC(c);
          END;
          ptr := ptr.nextNested
        END;
        
        NEW(item.params, c);
        c := 0;
        ptr := item.nestedItems;
        WHILE (ptr # NIL) DO
          IF (ptr IS Sym.VarDecl) &
             ptr(Sym.VarDecl).isParameter &
             ~ptr(Sym.VarDecl).isReceiver THEN
            item.params[c] := ptr(Sym.VarDecl);
            INC(c);
          END;
          ptr := ptr.nextNested
        END;
      END CollectFormalPars;

    PROCEDURE ResolveReceiver(procDecl: Sym.ProcDecl;
                              receiver: Sym.VarDecl);
      VAR
        class: Sym.Record;
        ptr: Sym.Item;
        count: LONGINT;

      PROCEDURE FixupAliasDecl(formalPars: Sym.FormalPars);
        VAR
          ptr: Sym.Item;
        BEGIN
          ptr := formalPars.nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Sym.TypeDecl DO
              IF (ptr.type = NIL) THEN
                ptr.type := receiver.type;
                ptr.srcCodeType := receiver.srcCodeType;
              END;
            ELSE
              (* ignore *)
            END;
            ptr := ptr.nextNested;
          END;
        END FixupAliasDecl;
      
      BEGIN
        receiver.SetType(GetTypeByName(receiver.type, contextOfUse, FALSE,
                                       FALSE, errList));
        class := procDecl.Class();
        IF (class = NIL) THEN
          (* some previous error prevents the class lookup: bail out *)
          FixupAliasDecl(procDecl.formalPars);
          RETURN;
        END;
        procDecl.formalPars.SetTypePars(class.typePars);
        (*item.formalPars.SetTypePars(receiver.type.typePars);*)

        IF (class.typePars = NIL) THEN
          IF receiver.hasAliasList THEN
            ErrType(cannotDefineTypeAliases, receiver.srcCodeType);

            (* finish the type alias declarations by assigning them the type
               of the receiver; this gets rid of a NIL pointer that may trip
               up later stages *)
            FixupAliasDecl(procDecl.formalPars);
          END;
        ELSE
          count := 0;
          ptr := procDecl.formalPars.nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Sym.TypeDecl DO
              IF (ptr.type = NIL) THEN
                (* unfinished alias declaration: fixup type reference; if this
                   is read from the symbol file, the `ptr.type' is alread set  *)
                ptr.type := class.typePars.params[count];
                ptr.srcCodeType := ptr.type;
              END;
              INC(count);
            ELSE
              (* ignore *)
            END;
            ptr := ptr.nextNested;
          END;
          
          IF ~receiver.hasAliasList OR
             (count # LEN(class.typePars.params^)) THEN
            ErrType(tooFewTypeAliases, receiver.srcCodeType);
            lastError.SetIntAttrib("count", LEN(class.typePars.params^));
          END;
        END;
      END ResolveReceiver;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.TypeDecl DO
          IF (item.type.typePars # NIL) & (item.type.typePars.ns # NIL) THEN
            typePars := item.type.typePars;
            item.type := GetTypeByName(item.type, item.type.typePars,
                                       FALSE, TRUE, errList);
            item.type.SetTypePars(typePars);  (* transfer parameter list *)
          ELSE
            item.type := GetTypeByName(item.type, contextOfUse,
                                       FALSE, TRUE, errList);
          END;
          
        | item: Sym.VarDecl DO
          IF ~item.isReceiver THEN
            item.SetType(GetTypeByName(item.type, contextOfUse,
                                       FALSE, TRUE, errList));
          END;
          
        | item: Sym.FieldDecl DO
          item. type := GetTypeByName (item. type, contextOfUse,
                                       FALSE, TRUE, errList);
          
        | item: Sym.Pointer DO
          item. baseType := GetTypeByName (item. baseType, contextOfUse,
                                           TRUE, TRUE, errList);
              
        | item: Sym.FormalPars DO
          IF (item. resultType # NIL) THEN
            item. resultType := GetTypeByName (item. resultType, contextOfUse,
                                               FALSE, TRUE, errList)
          END;
          IF (item.raises # NIL) THEN
            FOR i := 0 TO LEN(item.raises^)-1 DO
              item.raises[i].type := GetTypeByName
                  (item.raises[i].type, contextOfUse, FALSE, FALSE, errList);
            END;
          END;
          
        | item: Sym.Array DO
          item. elementType := GetTypeByName (item. elementType, contextOfUse,
                                              FALSE, TRUE, errList);
          
        | item: Sym.Record DO
          IF (item. baseType # NIL) THEN
            item.baseType := GetTypeByName (item.baseType, contextOfUse,
                                            FALSE, TRUE, errList);
          END
        
        | item: Sym.QualType DO
          (* don't look up baseType; the interpretation of this name depends
             on the context of use, i.e., pointer base or not *)
          FOR i := 0 TO LEN(item.arguments^)-1 DO
            item.arguments[i].type :=
                GetTypeByName(item.arguments[i].srcCodeType, contextOfUse,
                              TRUE, TRUE, errList);
          END;

        | item: Sym.TypeVar DO
          item.bound := GetTypeByName(item.bound, contextOfUse,
                                      TRUE, TRUE, errList);
          
          
        (* scope objects: fix context of use for using 
           occurences of identifiers *)
        | item: Sym.Module DO
          contextOfUse := item
        | item: Sym.ProcDecl DO
          IF (item.formalPars # NIL) & (item.formalPars.receiver # NIL) THEN
            ResolveReceiver(item, item.formalPars.receiver);
          END;
          contextOfUse := item
        | item: Sym.TypePars DO
          ASSERT(item.ns # NIL);
          contextOfUse := item;
        ELSE  (* ignore any other kind items *)
        END;
        
        (* decend into nested objects *)
        typeDeclCount := 0;
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          ResolveTypeNames (ptr, contextOfUse, unpatchedQualTypes, errList);
          IF (ptr IS Sym.TypeDecl) THEN
            INC(typeDeclCount);
          END;
          ptr := ptr. nextNested
        END;

        (* with the children completed, we can do some post processing *)
        WITH item: Sym.TypePars DO
          (* create and initialize TypePars.params *)
          NEW(item.params, typeDeclCount);
          typeDeclCount := 0;
          ptr := item.nestedItems;
          WHILE (ptr # NIL) DO
            IF (ptr IS Sym.TypeDecl) THEN
              item.params[typeDeclCount] := ptr(Sym.TypeDecl).type(Sym.TypeVar);
              INC(typeDeclCount);
            END;
            ptr := ptr.nextNested;
          END;
          
        | item: Sym.FormalPars DO
          CollectFormalPars(item);
        ELSE
          (* ignore *)
        END;
      END;
    END ResolveTypeNames;
  
  PROCEDURE CheckTypeRestrictions (item: Sym.Item; errList: Error.List);
  (* Checks the type restrictions placed by the language on declarations
     and definitions.  *)
    VAR
      ptr: Sym.Item;
      type: Sym.Type;
      record: Sym.Record;
      i: LONGINT;
      ns: Sym.Namespace;
      typePars: Sym.TypePars;
    
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

    PROCEDURE CheckTypePars(typePars: Sym.TypePars);
      VAR
        ptr: Sym.Item;
      BEGIN
        ptr := typePars.nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Sym.TypeDecl DO
            IF ~TR.IsValidTypeBound(ptr.type(Sym.TypeVar).bound) THEN
              ErrType(invalidTypeBound, ptr.srcCodeType);
            END;
          ELSE
            (* ignore *)
          END;
          ptr := ptr.nextNested;
        END;
      END CheckTypePars;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.VarDecl DO
          type := item. type;
          IF item. isParameter THEN
            IF ~(type IS Sym.TypeName) & ~TR.IsValidParameterType (type) THEN
              ErrType (invalidParameterType, item. srcCodeType)
            END;
            IF ~item.isVarParam THEN
              CheckInstance(item.type, item.srcCodeType);
            END;
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
          IF item.IsTypeBound() THEN
            record := item.Class();
            IF (record # NIL) & (record.Module() # item.Module()) THEN
              ErrDecl(tbProcForImportedRecord, item, errList);
            ELSIF item.isAbstract THEN
              IF (record # NIL) & ~record.isAbstract THEN
                ErrDecl(abstractProcForConcreteRecord, item, errList);
              END;
              IF (item.exportMark = Sym.nameNotExported) THEN
                ErrDecl(abstractProcNotExported, item, errList);
              END;
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
          END;
          IF (item.raises # NIL) THEN
            FOR i := 0 TO LEN(item.raises^)-1 DO
              IF errList.NoErrors() & ~TR.IsException(item.raises[i].type) THEN
                ErrType(notException, item.raises[i].srcCodeType);
              END;
            END;
          END;
          
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
              ns := type.Namespace();
              item.ns(Namespace.Extended).SetBaseNamespace
                  (ns(Namespace.Namespace));
            ELSE
              type := item.srcCodeBaseType;
              IF (type IS Sym.QualType) THEN
                type := type(Sym.QualType).srcCodeBaseType;
              END;
              Err (illegalRecordBase, type(Sym.TypeName))
            END
          END

        | item: Sym.QualType DO
          typePars := item.baseType.typePars;
          IF (typePars = NIL) THEN
            ErrType(notParametricType, item.srcCodeBaseType);
          ELSIF (LEN(typePars.params^) < LEN(item.arguments^)) THEN
            ErrType(tooManyTypeArgs,
                    item.arguments[LEN(typePars.params^)].srcCodeType);
          ELSIF (LEN(typePars.params^) > LEN(item.arguments^)) THEN
            ErrType(tooFewTypeArgs, item.srcCodeBaseType);
          ELSE
            FOR i := 0 TO LEN(typePars.params^)-1 DO
              type := item.arguments[i].type;
              IF (type IS Sym.TypeVar) THEN
                type := type(Sym.TypeVar).bound;
              END;
              IF ~TR.IsExtensionOf(type, typePars.params[i].bound) THEN
                ErrType(notExtensionOfBound, item.arguments[i].srcCodeType);
              END;
            END;
          END;
        ELSE  (* ignore any other kind of items *)
        END;

        IF (item IS Sym.Type) & (item(Sym.Type).typePars # NIL) THEN
          CheckTypePars(item(Sym.Type).typePars);
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
      ptr: Sym.Item;
      record: Sym.Record;
    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Sym.ProcDecl DO
          IF ptr.IsTypeBound() & ~ptr. isForwardDecl THEN
            record := ptr.Class();
            IF (record # NIL) & (record.Module() = ptr.Module()) THEN
              record. ns(Namespace.Extended). InsertTBProc (ptr, errList);
              IF (ptr.name.pos >= 0) &  (* don't overwrite imported flag *)
                 ((ptr.exportMark = Sym.nameNotExported) OR
                  privateRecords.HasKey(record)) THEN
                (* if procedure is not exported or if the record type is not
                   visible outside this module, then client modules cannot
                   redefine this procedure; the procedure CheckRestrictions
                   in module Namespace will detect redefinitions within the
                   local module *)
                ptr.notRedefined := TRUE;
              END;
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
          
          IF forward.IsTypeBound() THEN
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
        baseRecord : Sym.Record;
        type: Sym.Type;

      PROCEDURE AllocateTBProcIndices(record: Sym.Record);
      (* When this procedure is done, all type-bound procedures of the record
         namespace have a valid value in @ofield{Sym.ProcDecl.tbProcIndex}, and
         the record's @ofield{Sym.Record.tbProcCount} correctly reflects the
         number of type-bound procedures attached to it.  *)
        VAR
          decl, base: Sym.Item;
          ns: Namespace.Extended;
        BEGIN
          decl := root.nestedItems;
          WHILE (decl # NIL) DO
            WITH decl: Sym.ProcDecl DO
              IF decl.IsTypeBound() & ~decl.isForwardDecl &
                 (decl.Class() = record) THEN
                ns := record.ns(Namespace.Extended);
                IF (ns.extends = NIL) THEN
                  base := NIL;
                ELSE
                  base := ns.extends.Identify(decl, decl.name, TRUE);
                END;
                IF (base # NIL) & (base IS Sym.ProcDecl) THEN
                  base(Sym.ProcDecl).CopyTBProcIndex(decl);
                ELSE
                  record.AssignTBProcIndex(decl);
                END;
              END;
            ELSE
              (* ignore *)
            END;
            decl := decl.nextNested;
          END;
        END AllocateTBProcIndices;
      
      BEGIN
        IF (record. tbProcCount = -1) THEN
          IF (record. baseType = NIL) OR ~TR.IsRecord(record.baseType) THEN
            record. tbProcCount := 0
          ELSE
            type := record.baseType.Deparam();
            baseRecord := type(Sym.Record);
            CheckRecord (baseRecord);
            record. tbProcCount := baseRecord. tbProcCount;
            IF record. isVtable & ~baseRecord. isVtable THEN
              ErrType(inconsistentVtable, record);
            END;
            record. isVtable := baseRecord. isVtable;
          END;
          record.ns(Namespace.Extended).CheckRestrictions (record, uses,
                                                           errList);

          AllocateTBProcIndices(record);
          
          IF errList.NoErrors() & ~record.isAbstract THEN
            (* Check that no abstract procedure remain.  Only do this if the
               call to CheckRestrictions did not report any errors, or we might
               report a missing procedure although only the formal parameters
               were invalid.  *)
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
  (* As a side-effect, this procedure removes a record from
     @ovar{privateRecords} if one of its names or one of the names of its
     exensions is exported.  *)
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

      PROCEDURE SetAlign(VAR alignAttribute : INTEGER; newValue : INTEGER);
        BEGIN
          IF (alignAttribute = 0) THEN
            alignAttribute := newValue;
          ELSE
            InvalidFlag(flag, modifierFlagWithoutEffect);
          END;
        END SetAlign;

      BEGIN
        IF ~visited.HasKey(item) THEN
          visited.Set(item, NIL);
          
          flag := item.flagList;
          WHILE (flag # NIL) DO
            WITH item: Sym.Module DO
              CASE flag.id OF
              | Sym.flagOOCExtensions:
                (* has no effect *)
              | Sym.flagDeprecated:
                SetFlag(item.deprecated, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.ProcDecl DO
              CASE flag.id OF
              | Sym.flagAbstract:
                SetFlag(item.isAbstract, TRUE);
              | Sym.flagDeprecated:
                SetFlag(item.deprecated, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;

            | item: Sym.ConstDecl DO
              CASE flag.id OF
              | Sym.flagDeprecated:
                SetFlag(item.deprecated, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.VarDecl DO
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
              | Sym.flagDeprecated:
                SetFlag(item.deprecated, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.FieldDecl DO
              CASE flag.id OF
              | Sym.flagDeprecated:
                SetFlag(item.deprecated, TRUE);
              ELSE
                InvalidFlag(flag, invalidModifierFlag);
              END;
              
            | item: Sym.TypeDecl DO
              CASE flag.id OF
              | Sym.flagDeprecated:
                SetFlag(item.deprecated, TRUE);
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
              | Sym.flagExtensible:
                SetFlag(item.isExtensible, TRUE);
              | Sym.flagUncheckedException:
                SetFlag(item.isUncheckedException, TRUE);
              | Sym.flagVtable:
                SetFlag(item.isVtable, TRUE);
              | Sym.flagAtomic:
                SetFlag(item.isAtomic, TRUE);
              | Sym.flagUnion:
                SetFlag(item.isUnion, TRUE);
              | Sym.flagAlign1:
                SetAlign(item.fieldAlign, 1);
              | Sym.flagAlign2:
                SetAlign(item.fieldAlign, 2);
              | Sym.flagAlign4:
                SetAlign(item.fieldAlign, 4);
              | Sym.flagAlign8:
                SetAlign(item.fieldAlign, 8);
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
              | Sym.flagReadOnly:
                SetFlag(item.readOnlyExport, TRUE);
              | Sym.flagAtomic:
                SetFlag(item.isAtomic, TRUE);
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

            | item: Sym.FormalPars DO
              CASE flag.id OF
              | Sym.flagNoReturn:
                SetFlag(item.noReturn, TRUE);
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

    PROCEDURE ResolveCallingConvention(fpars : Sym.FormalPars);
      (**Resolve the calling convention for formal parameter declaration. If
        "default", then the declaration inherits the calling convention
        declared for the enclosing module. *)

        VAR 
          parentItem : Sym.Item;
        BEGIN
          IF fpars.callConv = Sym.callConvDefault THEN
            parentItem := fpars.parent;
            WHILE parentItem.parent # NIL DO 
              parentItem := parentItem.parent;
            END;
            fpars.callConv := parentItem(Sym.Module).callConv;
          END;
        END ResolveCallingConvention;

    BEGIN
      IF (item # NIL) THEN
        ResolveFlags(item);
        
        WITH item: Sym.Pointer DO
          IF (item.baseType IS Sym.Record) &
             ~item.baseType(Sym.Record).hasDescriptor THEN
            item.isStatic := TRUE;
          END;

        | item: Sym.Record DO
          IF (item.baseType # NIL) & TR.IsRecord(item.baseType) THEN
            type := item.baseType.Deparam();
            IF type(Sym.Record).isUncheckedException THEN
              item.isUncheckedException := TRUE;
            END;
          END;
          
        | item: Sym.VarDecl DO
          IF item.isParameter THEN
            type := item.type.Deparam();
            ResolveFlagsDirect(item, type);
            IF (type IS Sym.Record) & ~type(Sym.Record).hasDescriptor OR
               (type IS Sym.Array) & ~type(Sym.Array).hasLengthInfo THEN
              item.supplementArgs := FALSE;
            END;
          END;

        | item: Sym.TypeDecl DO
          IF (item.exportMark # Sym.nameNotExported) &
             (item.type IS Sym.Record) THEN
            type := item.type;
            WHILE (type # NIL) & privateRecords.HasKey(type) DO
              privateRecords.Delete(type);
              type := type(Sym.Record).baseType;
            END;
          END;
        | item: Sym.FormalPars DO
          ResolveCallingConvention(item);
        ELSE  (* ignore *)
        END;
        
        (* descend into nested objects *)
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

  PROCEDURE PropagateTypeVars(item: Sym.Item);
  (* For every type that uses a type variable in its definition, create an
     entry `Type.typePars' listing all used type variables.  *)
    VAR
      ptr: Sym.Item;

    PROCEDURE Propagate(type, srcCodeType: Sym.Type);
      VAR
        tv: Sym.TypeVarArray;
        i: LONGINT;
        ptr: Sym.Item;
        
      PROCEDURE MergePars(type: Sym.Type; typeVars: Sym.TypeVarArray);
        (* pre: `typeVars' holds only unique variables *)
        VAR
          tp: Sym.TypePars;
          oldVars, tv: Sym.TypeVarArray;
          i, j, new: LONGINT;
        BEGIN
          IF (type.typePars = NIL) THEN  (* use without change *)
            NEW(tp);
            Sym.InitTypePars(tp, type.parent);
            tp.params := typeVars;
            type.SetTypePars(tp);
          ELSE                           (* merge with existing list *)
            oldVars := type.typePars.params;
            new := 0;
            i := 0;
            WHILE (i # LEN(typeVars^)) DO
              j := 0;
              WHILE (j # LEN(oldVars^)) & (oldVars[j] # typeVars[i]) DO
                INC(j);
              END;
              IF (j = LEN(oldVars^)) THEN  (* no match in old variables *)
                typeVars[new] := typeVars[i];
                INC(new);
              END;
              INC(i);
            END;

            IF (new # 0) THEN
              NEW(tv, LEN(oldVars^)+new);
              FOR i := 0 TO LEN(oldVars^)-1 DO
                tv[i] := oldVars[i];
              END;
              FOR i := 0 TO new-1 DO
                tv[LEN(oldVars^)+i] := typeVars[i];
              END;
              type.typePars.params := tv;
            END;
          END;
        END MergePars;

      PROCEDURE Merge(type, baseType: Sym.Type);
        BEGIN
          IF (baseType.typePars # NIL) THEN
            MergePars(type, baseType.typePars.params);
          END;
        END Merge;

      PROCEDURE MergeVarDecl(type: Sym.Type; varDecl: Sym.VarDecl);
        BEGIN
          Propagate(varDecl.type, varDecl.srcCodeType);
          Merge(type, varDecl.type);
        END MergeVarDecl;
      
      BEGIN
        IF (type # NIL) & ((type = srcCodeType) OR (type IS Sym.TypeVar)) THEN
          (* don't follow type names, because visibility of type variables
             does not span multiple type declarations *)
          WITH type: Sym.TypeVar DO
            IF (type.typePars = NIL) THEN
              NEW(tv, 1);
              tv[0] := type;
              MergePars(type, tv);
            END;
            
          | type: Sym.PredefType DO
            (* ignore *)

          | type: Sym.Pointer DO
            Propagate(type.baseType, type.srcCodeBaseType);
            Merge(type, type.baseType);

          | type: Sym.FormalPars DO
            (* do not propagate unbound variables from the receiver type: they
               are of no interest in the "outside" view, and always qualified
               in the "inside" view *)
            FOR i := 0 TO LEN(type.params^)-1 DO
              MergeVarDecl(type, type.params[i]);
            END;
            
          | type: Sym.Array DO
            Propagate(type.elementType, type.srcCodeElementType);
            Merge(type, type.elementType);

          | type: Sym.Record DO
            IF (type.baseType # NIL) THEN
              Propagate(type.baseType, type.srcCodeBaseType);
              Merge(type, type.baseType);
            END;
            ptr := type.nestedItems;
            WHILE (ptr # NIL) DO
              WITH ptr: Sym.FieldDecl DO
                Propagate(ptr.type, ptr.srcCodeType);
                Merge(type, ptr.type);
              ELSE
                (* ignore *)
              END;
              ptr := ptr.nextNested;
            END;

          | type: Sym.QualType DO
            (* no variables are propagated out of the unqualified base type *)
            FOR i := 0 TO LEN(type.arguments^)-1 DO
              Propagate(type.arguments[i].type, type.arguments[i].srcCodeType);
              Merge(type, type.arguments[i].type);
            END;

          | type: Sym.TypeName DO
            (* ignore *)
          END;
        END;
      END Propagate;
    
    BEGIN
      WITH item: Sym.TypeDecl DO
        Propagate(item.type, item.srcCodeType);
      | item: Sym.ProcDecl DO
        IF item.IsTypeBound() THEN
          Propagate(item.formalPars, item.formalPars);
        END;
      ELSE
        (* ignore *)
      END;

      (* descend into nested objects *)
      ptr := item.nestedItems;
      WHILE (ptr # NIL) DO
        PropagateTypeVars(ptr);
        ptr := ptr.nextNested;
      END;
    END PropagateTypeVars;

  PROCEDURE PatchQualType(qualType: Sym.QualType);
    VAR
      params: Sym.TypeVarArray;
      i: LONGINT;
    BEGIN
      params := qualType.baseType.typePars.params;
      
      NEW(qualType.arguments, LEN(params^));
      FOR i := 0 TO LEN(params^)-1 DO
        Sym.InitTypeRef(qualType.arguments[i], params[i].bound);
      END;
    END PatchQualType;
  
  BEGIN
    ASSERT (errList # NIL);

    CASE root.class OF
    | Sym.mcInterface, Sym.mcForeign:
      IF (LinkFileSections(root.linkDirectives) > 1) THEN
        ErrDecl(atMostOneLinkFile, root, errList);
      END;
    ELSE
    END;

    IF (uses # NIL) THEN
      uses.StartModule(root, errList);
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
    
    (* first pass: create namespace objects for module, procedures, records,
       and parametric type (excluding any type-bound procedures and procedure 
       forward declarations) *)
    privateRecords := Dictionary.New();
    PopulateNamespace (root);
    
    (* second pass: check local uniqueness constraint for module, procedure,
       record, and parametric type namespaces; note: for records, this checks
       only a small part of the restrictions placed on their namespaces  *)
    CheckLocalUniqueness (root, errList);
    
    (* third pass: connect namespace links; the namespaces of procedures and
       parametric types are nested into the enclosing procedure/module  *)
    ConnectNamespaces (root, predefModule, errList);
    
    
    (* here holds: module, procedure, and parametric type namespaces can be
       searched for declarations, ignoring procedure forward declarations  *)
    
    
    (* fourth pass: resolve type names in declarations, and fix up namespaces
       for record types *)
    unpatchedQualTypes := ArrayList.New(4);
    ResolveTypeNames (root, NIL, unpatchedQualTypes, errList);
    FOR i := 0 TO unpatchedQualTypes.size-1 DO
      PatchQualType(unpatchedQualTypes.array[i](Sym.QualType));
    END;
    
    (* CAUTION: Some type names may not have been resolved successfully
       past this point.  Check for instances of Sym.TypeName before assuming
       that the types are valid.  *)
      
    (* fourth and a half pass: resolve modifier flags that may be attached to
       declarations and types; this must be done before dealing with any
       restrictions imposed on data type; this call also eliminates all
       non-private records from privateRecords *)
    visited := Dictionary.New();
    ResolveModifierFlags (root, errList);
    
    (* fifth pass: check type restrictions of declarations *)
    CheckTypeRestrictions (root, errList);

    (* sixth pass: traverse list of type-bound procedures and insert them
       into the corresponding record namespace; also set notRedefined flag
       for type-bound procedures that cannot be redefined outside the module *)
    InsertTypeBoundProcs (root, errList);

    (* seventh pass: fixup formal parameter types, so that the type has
       a list of direct references to the formal parameters *)
    (*CollectFormalPars (root);  obsolete, is now done directly in the 
      Builder's Finalize method *)

    (* eighth pass: resolve forward declarations of procedures *)
    IF errList.NoErrors() THEN
      (* if there are type names that could not be resolved, then this
         function cannot operate properly; only run it if we are clean *)
      ResolveForwardDecl (root, errList);
    END;


    (* here holds: any namespace (module, procedure, or record) can be
       searched and is guaranteed to deliver the correct results *)
    
    (* nineth pass: propagate type variables upward in the tree of
       constructors, so that every type that has a type variable somewhere has
       a non-NIL field `type.typePars'  *)
    PropagateTypeVars(root);
    
    (* tenth pass: check namespace restrictions imposed on extended
       records and assign indexes to type-bound procedures; fix notRedefined
       for type-bound procedures that are redefined in the local module *)
    IF errList.NoErrors() THEN
      (* if there are type names that could not be resolved, then this
         function cannot operate properly; only run it if we are clean *)
      CheckExtendedRecords (root, errList);
    END;
    (*XML.Write(StdChannels.stdout, root);*)
    
    ResolveRef.Resolve (root, errList);
    
    IF (uses # NIL) & errList.NoErrors() THEN
      uses.RegisterSymTab(root);
    END;
  END CreateNamespace;

PROCEDURE Init* ();
  VAR
    stb: Builder.Builder;
    predef, system: Sym.Module;
  BEGIN
    predefModule := NIL;
    systemModule := NIL;
    
    stb := Builder.New();
    predef := Predef.CreatePredef (stb, exception);
    system := Predef.CreateSYSTEM (stb);
    TRY
      CreateNamespace (predef, NIL, Error.NewList (""));
      CreateNamespace (system, NIL, Error.NewList(""));
    CATCH IO.Error:
      (* cannot happen *)
    END;
    
    predefModule := predef;
    systemModule := system;
  END Init;
    
BEGIN
  NEW (createNamespaceContext);
  Error.InitContext (createNamespaceContext, "OOC:SymbolTable:CreateNamespace");
  Init;
END OOC:SymbolTable:CreateNamespace.
