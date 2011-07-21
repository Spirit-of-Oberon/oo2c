(* 	$Id: SymbolTable.Mod,v 1.127 2005/10/07 08:35:42 mva Exp $	 *)
MODULE OOC:SymbolTable [OOC_EXTENSIONS];
(*  Defines structure and entries of the symbol table.
    Copyright (C) 2000-2005  Michael van Acken

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
  Object, Object:Boxed, Exception, Strings, ADT:Dictionary:AddressKey,
  ADT:Dictionary, ADT:Storable, ADT:ArrayList, ADT:Object:Storage, IO,
  URI, ParserURI := URI:Parser, URI:Scheme:File,
  OOC:Scanner:InputBuffer, SB := OOC:Scanner:SymList, OOC:Doc, OOC:AST;

TYPE
  NameString* = InputBuffer.CharArray;
  (**This type is used to store names as character arrays.  The string is
     always terminated by a @code{0X} character.  In the future, the base
     character of the string may change to something different than
     @code{CHAR}.  *)
  ModulePos* = InputBuffer.CharPos;
  (**Values of this type store a source position as an integer type.  The
     very first character of the source file has position 0.  *)
  ModuleLine* = SB.Line;
  (**Line number in the source file, starting at 0.
     See @omodule{*OOC:Scanner:Builder} for more information.  *)
  ModuleColumn* = SB.Column;
  (**Column number in the source file, starting at 0.
     See @omodule{*OOC:Scanner:Builder} for more information.  *)
  Exports* = AddressKey.Dictionary;
  ExtensionDict* = Dictionary.Dictionary(Object.Object, ArrayList.ArrayList);

TYPE
  Position* = POINTER TO PositionDesc;
  PositionDesc = RECORD
    (**A position is a tuple of character position, line number, and column
       number.  The former is used internally to determine the visibility of
       declared names at various positions of the source code.  All three
       values can be used for error messages.  *)
    (Storable.ObjectDesc)
    pos-: ModulePos;
    line-: ModuleLine;
    column-: ModuleColumn;
  END;
  
VAR
  importPosition: Position;
  (* used as position attribute of imported types *)
  
TYPE
  Name* = POINTER TO NameDesc;
  NameDesc = RECORD
    (**A name is a string associated with a source code position.  These two
       informations together are necessary to pinpoint a declaration in the
       source code, and to determine which declaration is referred to by a
       using occurence of a name.  *)
    (PositionDesc)
    str-: NameString;
  END;

TYPE
  Flag* = POINTER TO FlagDesc;
  FlagDesc = RECORD
    (**Modifier flags are registered by the parser for declarations and types.
       For example, a parameter flag @samp{[NO_COPY]} is mapped to an instance
       of this type with a @ofield{id} of @oconst{flagNoCopy}.  Flags are
       processed after the symbol table has be calculated.  In this pass, their
       data is incorporated into the various instances of @otype{Item}.  *)
    nextFlag-: Flag;
    id-: INTEGER;
    (**Symbolic id for the flag.  *)
    pos-: Position;
    (**Error messages for the flag should refer to this module position.  *)
  END;

CONST
  flagUnknownName* = -1;
  flagNoCopy* = 0;
  flagAbstract* = 1;
  flagNoLengthInfo* = 2;
  flagNoDescriptor* = 3;
  flagNotExtensible* = 4;
  flagCString* = 5;
  flagNilCompat* = 6;
  flagUnion* = 7;
  flagReadOnly* = 8;
  flagNoReturn* = 9;
  flagDeprecated* = 10;
  flagOOCExtensions* = 11;
  flagExtensible* = 12;
  (**This flag is disabled, because it causes a deref of NIL in
     @omodule{*OOC:SymbolTable:InterfaceDescr} due to an unset
     @ofield{Record.className}.  *)
  flagAlign1* = 13;
  flagAlign2* = 14;
  flagAlign4* = 15;
  flagAlign8* = 16;
  flagVtable* = 17;
  flagUncheckedException* = 18;
  flagAtomic* = 19;

CONST
  libTypeStandard* = 0;
  (**Library is a "normal" shared or static link library linked in with the
     @samp{-l} option.  *)
  libTypeFramework* = 1;
  (**Library is a Mac OS X framework library and uses @samp{-framework} for
     linking.  *)
  
CONST
  nameNotExported* = 0;
  (**The declarared name is not exported.  In other words, the name is not
     visible outside the current module.  *)
  nameExported* = 1;
  (**The declarared name is exported without any restrictions.  *)
  nameExportedRO* = 2;
  (**The declarared name is exported, but client modules have only read
     access to the value.  They cannot change it directly (in theory).  *)

TYPE
  ExportMark* = SHORTINT;
  (**Data type to store the export flag of a declaration.  Can take one of
     the values @oconst{nameNotExported}, @oconst{nameExported}, or 
     @oconst{nameExportedRO}.  *)

TYPE
  Item* = POINTER TO ItemDesc;
  (**Any defined entity of an Oberon-2 module is mapped onto an instance of
     @otype{Item}.  The includes named entities like the module itself, its
     procedures, constants, and so on, @emph{and} unnamed entities like new
     types defined by type constructors like @code{POINTER}, @code{RECORD},
     or @code{ARRAY}.  All entities are part of a hierarchy of items.  The
     root of the hierarchy is the module entity, the inner nodes are
     procedures, record types, and formal parameter lists, and the leaves
     are all other entities.  Besides this hierarchy, other relationsships
     between items exist, e.g. to represent the formal parameter list of a
     procedure, or the fields and type-bound procedures of a record type.  *)
  ItemDesc* = RECORD [ABSTRACT]
    (Storable.ObjectDesc)
    nextNested-: Item;
    (**Link to next direct descendant of the parent item.  The head of the
       is stored in the field @ofield{nestedItems} of the @ofield{parent}.  *)
    parent-: Item;
    (**Link to parent item.  This is @code{NIL} for the module object, and
       non-@code{NIL} for all other items.  In the latter case, the item is
       part of the @ofield{nestedItems} list of the parent item.  *)
    nestedItems-: Item;
    (**This is the head of the list of items, that are direct descendants of
       the current item.  The descendants are linked using the field
       @ofield{nextNested}.  For an item that is not an inner node of an
       item hierarchy, this field is always @code{NIL}.  *)
    tailNestedItems: Item;
    (* Last entry in list of @ofield{nestedItems}, or @code{NIL}.  *)
    flagList-: Flag;
    (**List of modifier flags for this declaration or type.  This list is
       never written to the symbol file.  *)
  END;

CONST
  visiblePosImportedDecl* = -3;
  (**This value is assigned to @ofield{Declaration.visibleFrom} for
     declarations taken from a symbol file, with the exception of formal
     procedure parameters.  *)
  posImportedName* = -2;
  (**This position is assigned to all imported @ofield{Position.pos} fields.
     It ensures that all declarations, with the exception of formal parameters,
     are considered to be visible before this position.  This trickery is
     necessary to avoid conflicts for imported formal parameters, if the
     parameter and its type name are identical.  *)
  visiblePosImportedFormalParam* = -1;
  (**This value is assigned to @ofield{Declaration.visibleFrom} for formal
     procedure parameters taken from a symbol file.  *)

TYPE
  Declaration* = POINTER TO DeclarationDesc;
  DeclarationDesc* = RECORD [ABSTRACT]
    (**A declaration defines an Oberon-2 object, and associates a name with
       this object.  *)
    (ItemDesc)
    name-: Name;
    (**The declared name.  This field also includes information about the
       position of the declared name.  *)
    visibleFrom-: ModulePos;
    (**Within the module of the declaration, the declared name is visible for
       all character positions greater or equal to @ofield{visibleFrom}.

       For an imported declaration, the value of @ofield{visibleFrom} is
       @oconst{visiblePosImportedDecl}, except for the names of formal
       parameters, for which it is @oconst{visiblePosImportedFormalParam}.  In
       any case, this field is negative if, and only if, the declaration was
       taken from a symbol file.  *)
    exportMark-: ExportMark;
    (**Export status of the declaration.  *)
    docString-: Doc.Document;
    (**Some piece of documentation attached to this declaration.  Typically,
       this is a doc comment placed after the name of the declaration.  *)
    deprecated*: BOOLEAN;
    (**If @code{TRUE}, then the declaration has been marked as deprecated.
       For each use of the object a warning is generated.  *)
    cachedId: NameString;
    (* used by @oproc{Declaration.GetId} to cache the result of an id
       computation; initialized to NIL, not stored in a symbol file *)
    usageCount-: LONGINT;
    (**Number of lookups of this name during compilation of the module.
       A value of zero means that the name is not referenced in the local
       module.  This field is not stored in the symbol file.  *)
  END;
  DeclarationArray* = POINTER TO ARRAY OF Declaration;


TYPE
  Namespace* = POINTER TO NamespaceDesc;
  NamespaceDesc* = RECORD [ABSTRACT]
    (**A namespace is a mechanism that maps names to objects.  It has methods
       to retrieve an object based on its name.  How this mapping is
       implemented, and how visibility of identifiers is handled, is not
       defined in this module.  See @oproc{*OOC:SymbolTable:Namespace}
       for concrete implementations for module, procedure, and record 
       namespaces.
       
       Namespaces are created by calling
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
  END;

TYPE
  TypePars* = POINTER TO TypeParsDesc;
  TypeVar* = POINTER TO TypeVarDesc;
  TypeVarArray* = POINTER TO ARRAY OF TypeVar;
  TypeParsDesc = RECORD
    (**This is a formal parameter list of a parameterized type.

       If the instance is associated with a type declaration, all parameters
       are nested in this item, as well as all items that make up the base
       type.  If it is associated with an unnamed type, then it is empty and
       @ofield{params} is a list of all type variables used in the type's
       definition.  *)
    (ItemDesc)
    params*: TypeVarArray;
    (**The list of formal type parameters.  @samp{LEN(params^)} is the number
       of parameters.  If there are no parameters at all, this is a reference
       to an array of length zero.  This field is set during
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}, and remains
       @code{NIL} until then.  *)
    ns-: Namespace;
    (**A reference to the record's namespace.  Note that the namespace
       does not exist before
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}
       has been run.  *)
  END;

CONST
  dynamicSize* = -1;
  (**The size of a variable of this type depends on the concrete instance that
     it holds, and therefore cannot be computed statically.  Examples for this
     or open array heap objects, or string constants.  *)
  unknownSize* = -2;
  (**The size of the type has not been computed yet.  *)
  
TYPE
  Type* = POINTER TO TypeDesc;
  TypeDecl* = POINTER TO TypeDeclDesc;
  TypeDesc* = RECORD [ABSTRACT]
    (**Common base type of all type definitions.  As far as the symbol table is
       concerned, a type is either a type reference (that is, an instance of
       @otype{TypeName}), or a type constructor defining a new record, array,
       pointer, or procedure type.

       @emph{Note}: Prior to the introduction of parametric types, two type
       instances were considered to be of the same type if, and only if, their
       pointers were equal.  With parametric types, this decision is not that
       simple any more: two types involving type arguments may be represented
       by different objects, but still are of the same type. The predicate
       @oproc{*OOC:SymbolTable:TypeRules.SameType} must be used to get the
       correct result.  *)
    (ItemDesc)
    position-: Position;
    (**Position of the type name or type constructor.  This field is mostly
       used to attach a position to any type related error messages.  *)
    namingDecl-: TypeDecl;
    (**For a type that is associated with a name, this field refers to the type
       declaration that defines this type.  It is @code{NIL} for anonymous
       types, that is, for type constructors that do not appear on the right
       side of a type declaration.  If multiple aliases are defined for a type,
       this field refers to the name of the original declaration.  *)
    typePars-: TypePars;
    (**For a parametric type, or a type-bound procedure of a parametric type,
       this field holds a reference to the formal parameter list.  Otherwise,
       it is @code{NIL}.

       The @otype{FormalPars} of type-bound procedures duplicate the
       @ofield{typePars} of the receiver's type.  *)
    size-: LONGINT;                      (* FIXME... make this `Integer'? *)
    (**Size in bytes of the memory that needs to be allocated to hold a value
       of this type.  For most types, this is a non-negative value.  It is zero
       for empty record types, and for array types with length of zero.  For
       types whose size is computed at run-time (like open array parameters and
       open array heap objects) or whose size is a function of the actual value
       (as for string constants), this field is @oconst{dynamicSize}.  The
       field is initialized to @oconst{unknownSize}, and changed to its final
       value after

       @itemize @bullet
       @item
       its symbol file has been read in completely, or

       @item
       while completing the information on declarations of the currently parsed
       module.
       @end itemize  *)
    align-: INTEGER;
    (**Minimum alignment of this type.  A variable holding a value of this type
       must be allocated at a memory address that is a multiple of this number.
       The field is initialized to @samp{1}, the minimum possible alignment.  *)
    hasDescriptor*: BOOLEAN;
    (**If @code{TRUE}, then this type has an associated type descriptor that is
       available during run-time.  Default is @code{TRUE} for type from
       non-@code{INTERFACE} modules.  *)
  END;


(* Module
   ------------------------------------------------------------------------ *)

TYPE
  ModuleClass* = SHORTINT;

CONST
  mcStandard* = 0;
  (**Indicates a standard module.  *)
  mcInternal* = 1;
  (**Indicates an internal module, for example the pseudo module that defines
     predefined entities, or @code{SYSTEM}.  *)
  mcForeign* = 2;
  (**Indicates a @code{FOREIGN} module.  Such a module has all the outward
     appearance of a standard module, although the actual implementation is
     done in a different programming language.  *)
  mcInterface* = 3;
  (**Indicates an @code{INTERFACE} module.  An @code{INTERFACE} does not
     provide any executable code of its own.  Instead, it describes how to link
     to a another piece of code, typically a shared library, and how to access
     its functions and variables.  *)

TYPE
  CallConv* = SHORTINT;

CONST
  callConvInvalid* = -1;
  (**Error return code, indicating that a given calling convention identifier
     is not known to the compiler.  *)
  callConvDefault* = 0;
  (**This value is used if no explicit calling convention is stated.  On the
     module level it only applies to standard modules, because @code{INTERFACE}
     and @code{FOREIGN} modules require an explicit calling convention.  On the
     procedure level, this value signals that the procedure should take its
     calling convention from the module's default calling convention.  *)
  callConvInternal* = 1;
  (**This id is used for procedure and functions that are predefined or are
     derived from a pseudo module like @code{SYSTEM}.  Because calls to such
     procedures are not mapped to regular procedure calls, normal calling
     conventions do not apply.  In particular, internal procedures cannot be
     assigned to procedure variables.  *)
  callConvC* = 2;
  (**`C' calling convention.  Here the caller removes arguments, permitting
     the usage of the ellipsis parameter in C functions.  *)
  callConvPascal* = 3;
  (**`Pascal' calling convention.  The callee removes arguments.  This is 
     the default calling convention under Win32.  *)  
  callConvFastcall* = 4;
  (**The Microsoft `Fastcall' calling convention for x86. Arguments to
	functions are passed in registers "whenever possible". The first two
	LONGINT or smaller arguments are passed in the ECX and EDX registers; all
	other arguments are passed right to left on the stack. The callee removes
	arguments from the stack. *)

TYPE
  LinkDirective* = POINTER TO LinkDirectiveDesc;
  LinkDirectiveDesc = RECORD
    (Storable.ObjectDesc)
    next-: LinkDirective;
  END;

TYPE
  LinkFile* = POINTER TO LinkFileDesc;
  LinkFileDesc = RECORD
    (LinkDirectiveDesc)
    file: URI.HierarchicalURI;
    prefixOption, suffixOption: STRING;
  END;

TYPE
  LinkLib* = POINTER TO LinkLibDesc;
  LinkLibDesc = RECORD
    (LinkDirectiveDesc)
    libraryName-: STRING;
    dependencies-: Object.StringArrayPtr;
    prefixOption-, suffixOption-: STRING;
    type-: LONGINT;
  END;

CONST
  declModuleBody* = "_MODULE_BODY";
  
TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleRef* = POINTER TO ModuleRefDesc;
  ModuleRefDesc = RECORD
    name*: NameString;
    fingerprint*: LONGINT;
  END;
  ModuleRefArray* = POINTER TO ARRAY OF ModuleRef;
  ProcDecl* = POINTER TO ProcDeclDesc;
  ModuleDesc = RECORD
    (**This class represents the top-level module object.  It is the root
       of the symbol table, that is defined by a module's source file.  *)
    (DeclarationDesc)
    ns-: Namespace;
    (**A reference to the global module namespace.  Note that the namespace
       does not exist before
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace} has been run.  *)

    class-: ModuleClass;
    (**Identifies the class of the module.  It is one of @oconst{mcStandard},
       @oconst{mcInternal}, @oconst{mcForeign}, or @oconst{mcInterface}.  *)
    libraryName-: STRING;
    (**If the module is compiled to be part of a (static or shared) library,
       then this field holds the name of the target library.  For a module that
       is compiled to a standalone object file, @ofield{libraryName} is
       @code{NIL}.  *)
    callConv-: CallConv;
    (**The default calling convention to be used for all procedures in the
       module.  If this is @oconst{callConvDefault}, then the final choice
       is up to the compiler back-end.  *)
    linkDirectives-: LinkDirective;
    (**List of @samp{FILE}, @samp{OBJ}, and @samp{LIB} link directives from
       the module header.  *)
    fingerprint*: LONGINT;
    (**The fingerprint value of the module's symbol file.  This field is
       only valid if the @otype{Module} object has been read from file.  *)

    prunedImports*: ModuleRefArray;
    (**List of import entries removed by the @oproc{Prune} function.  This
       field is not part of the fingerprinted area of the symbol file.  *)
    moduleAST-: AST.Node;
    (**Refers to the abstract syntax tree of the module, for example an
       instance of @otype{*OOC:AST.Module}.  *)
    bodyDecl-: ProcDecl;
    (**This pseudo declaration is used to turn the statement sequence in the
       module body into a fully fledged procedure declaration.  It's name
       is @oconst{declModuleBody}.  *)
  END;

TYPE
  Import* = POINTER TO ImportDesc;
  (**An item of this class represents an import declaration.  It has a
     name, either the module's name, or the alias assigned to it.  *)
  ImportDesc = RECORD
    (DeclarationDesc)
    moduleName-: Name;
    (**The name of the imported module.  If the module has a multi-part
       identifier for its name, the string contains @samp{:} characters,
       but no whitespace.  *)
    
    externalSymTab-: Module;
    (**A reference to the imported symbol table of the external module.  This
       field is initialized to @code{NIL}, and is filled when
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace} is called.  *)

    fingerprint-: LONGINT;
    (**The fingerprint of the imported module's symbol file.
       If @ofield{externalSymTab} is set, then this is changed to the symbol
       table's fingerprint field.  If the import is read from file, then
       its the value store in the symbol file.  *)
  END;


(* Types
   ------------------------------------------------------------------------ *)

TYPE
  PredefId* = INTEGER;
  (**Numeric code assigned to predefined types and procedures.  Within their
     separate classes, ids uniquely identify a named entity.  *)
  PredefType* = POINTER TO PredefTypeDesc;
  PredefTypeDesc* = RECORD
    (**Predefined types (like @code{INTEGER}, @code{SET}, the string types,
       and so on) of the language are represented by instances of this
       class.  The @omodule{*OOC:SymbolTable:Predef} defines the predefined
       entities.  *)
    (TypeDesc)
    id-: PredefId;
  END;

TYPE
  TypeName* = POINTER TO TypeNameDesc;
  TypeNameDesc = RECORD
    (**A reference to a named type.  In the first pass over the code, any
       type reference is translated into an instance of this class.  In a
       later pass,
       during @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace},
       the type names are replaced with references to the type
       associated with the name.  *)
    (TypeDesc)
    module-: Name;
    (**Module part of the type name.  This field is @code{NIL} if the 
       type is part of the local module, or is a predefined type.  *)
    ident-: Name;
    (**The actual type name.  *)
  END;

TYPE
  Pointer* = POINTER TO PointerDesc;
  PointerDesc = RECORD
    (**This class represents pointer type constructors @samp{POINTER TO Foo}.*)
    (TypeDesc)
    baseType*: Type;                     (*... make this read-only? *)
    (**The pointer base type.  If this is initially a type name, it is 
       replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeBaseType-: Type;
    (**The pointer base type, as it is defined in the source code.  If this
       is an instance of @otype{TypeName}, it is @emph{not} touched 
       by @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}, and it will
       forever stay a type name.  *)
    doCArrayAssignment*: BOOLEAN;
    (**Setting this flag for an array pointer type enables C-style array
       assignment semantics for variables derived from this type.  Assigning an
       array or string constant to such a pointer variable is legal, and
       assigns the @emph{address} (but not the @emph{contents}) of the array or
       string to the variable.  *)
    isStatic*: BOOLEAN;
    (**If set, then no run-time information is available for the referenced
       objects beyond its static type.  Default is @code{FALSE} for non-
       @code{INTERFACE} modules.  *)
  END;

TYPE
  ExceptionName* = POINTER TO ExceptionNameDesc;
  ExceptionNameArray* = POINTER TO ARRAY OF ExceptionName;
  ExceptionNameDesc = RECORD
    (**Entry in a formal parameter's @samp{RAISES} part.  *)
    (ItemDesc)
    type*: Type;
    (**The type of the exception.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeType-: Type;
    (**Similar to @ofield{type}, but it is not changed to a reference to
       the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
  END;

TYPE
  VarDecl* = POINTER TO VarDeclDesc;
  VarDeclArray* = POINTER TO ARRAY OF VarDecl;
  FormalPars* = POINTER TO FormalParsDesc;
  FormalParsDesc = RECORD
    (**This class models formal parameter lists of procedure declarations and
       procedure type definitions.  It includes the receiver of the procedure,
       the formal parameters, and the result type.  All of these components
       are optional and may be missing for some formal parameter definitions.
       *)
    (TypeDesc)
    receiver-: VarDecl;
    (**The receiver of a type-bound procedure.  This field is @code{NIL} for
       normal procedures.  *)
    resultType*: Type;                   (*... make this read-only? *)
    (**The result type of the formal parameter definition.  For a proper
       procedure, this field is @code{NIL}.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeResultType-: Type;
    (**Similar to @ofield{resultType}, but if this is initially a type name,
       it is not changed to a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    params*: VarDeclArray;
    (**The list of formal parameters.  @samp{LEN(params^)} is the number of
       parameters.  If there are no parameters at all, this is a reference to
       an array of length zero.  *)
    anyRestParameters-: BOOLEAN;
    (**If the last formal parameter is the special rest parameter @samp{...},
       then this field is set to @code{TRUE}.  Otherwise it is @code{FALSE}. *)
    noReturn*: BOOLEAN;
    (**If set, then it is guaranteed that this procedure never returns.
       Default is @code{FALSE}.  *)
    callConv*: CallConv;
    (**The calling convention to be used for this procedure. This value
       overrides any values specified by @ofield{Module.callConv}. *)
    raises*: ExceptionNameArray;
    (**List of exceptions that may be raised by this procedure.
       @samp{LEN(raises^)} is the number of registered types.  If there are
       none, @ofield{raises} is a reference to an array of length zero.  *)
    ns-: Namespace;
    (**For a formal parameter list of a type-bound procedure associated with
       a parametric record type, this namespace holds the local aliases for
       the variables of the base record's type parameter list.  For all other
       formal parameter lists, this namespace is currently empty.

       The namespace is nested in the namespace of the enclosing object (that
       is, in that of the module or procedure), and a procedure's namespace
       is nested in that of the formal parameters.  *)
  END;

TYPE
  Array* = POINTER TO ArrayDesc;
  ArrayDesc = RECORD
    (**This class represents constructors of array types.  *)
    (TypeDesc)
    isOpenArray-: BOOLEAN;
    (**TRUE, iff the array type is defined as @samp{ARRAY OF Foo}.  *)
    hasLengthInfo*: BOOLEAN;
    (**If @code{TRUE}, then the length of this array can be obtained
       during run-time.  Default is @code{TRUE} for non-
       @code{INTERFACE} modules.  *)
    readOnlyExport*: BOOLEAN;
    (**If @code{TRUE}, then importing modules have no write access to
       this array, or to its elements.  Default is @code{FALSE}.  *)
    elementType*: Type;                  (*... make this read-only? *)
    (**The type of the array elements.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeElementType-: Type;
    (**Similar to @ofield{elementType}, but if this is initially a type name,
       it is not changed to a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    length-: LONGINT;
    (**The length of of the array, unless @ofield{isOpenArray} is @code{TRUE}.
       Please note that this failed is set fairly late in the translation
       process, just before the statements of procedure and bodies are
       translated to IR.  Until then, this field holds a negative value.
       (It's probably a good idea to change this field to `Integer' at
       some later time.)  *)
    lengthExpr-: AST.Node;
    (**The part of the abstract syntax tree that defines the length of the
       array.  For an open array type, this field is @code{NIL}.  *)
    isAtomic*: BOOLEAN;
    (**If @code{TRUE}, then this type contains no pointers that need to be 
       considered by the GC. *)
  END;

TYPE
  Record* = POINTER TO RecordDesc;
  RecordDesc = RECORD
    (**Record type constructors are mapped to instances of this class.  *)
    (TypeDesc)
    baseType*: Type;                     (*... make this read-only? *)
    (**The base type of the record.  For records without a base type, this
       field is @code{NIL}.  Otherwise, the type name, is replaced with a
       reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeBaseType-: Type;
    (**Similar to @ofield{baseType}, but it is not changed to a reference to
       the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    tbProcCount*: LONGINT;
    (**The number of type-bound procedures defined for this record type.
       Initially, the field holds the value @code{-1}.  As part of
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}, this is
       changed to reflect the number of type-bound procedures that are part of
       the record's method table.  *)
    ns-: Namespace;
    (**A reference to the record's namespace.  Note that the namespace
       does not exist before
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}
       has been run.  *)

    isUnion*: BOOLEAN;
    (**If @code{TRUE}, then the record is treated like a C-style @code{union}
       type.  *)
    isAbstract*: BOOLEAN;
    (**If @code{TRUE}, then the record defines an abstract class.  Default
       is @code{FALSE}.  *)
    isExtensible*: BOOLEAN;
    (**If @code{TRUE}, then this type can serve as a base type for other
       records.  Default is @code{TRUE} for non-
       @code{INTERFACE} modules.  *)
    isUncheckedException*: BOOLEAN;
    (**If @code{TRUE}, then this record represents an unchecked exception.  The
       default is checked, that is, @code{FALSE}.  This applies to
       @otype{*Exception.Exception}.  *)
    isVtable*: BOOLEAN;
    (**If @code{TRUE}, then this type has a C++ virtual method table. *)
    isAtomic*: BOOLEAN;
    (**If @code{TRUE}, then this type contains no pointers that need to be 
       considered by the GC. *)
    fieldAlign* : INTEGER;
    (**Alignment constraint on fields of this record. Normally, a field is
       placed at an address that is a multiple of its size.  For example, a
       4-byte field is aligned at an address that is a multiple of 4. This is
       necessary on some architectures to avoid bus faults, but also improves
       performance by reducing the number of memory fetches required to
       retrieve field values. However, it is sometimes necessary to define
       fields with particular layouts in order to use existing application
       binary interfaces. This field defines the maximum value of alignment
       that will be used for any record field. For example, if
       @ofield{fieldAlign} has the value 2, a field with size greater than 2
       will be aligned at a multiple of 2, rather than a multiple of its size.
       *)

    className*: Name;                    (* ... make this read-only? *)
    (**If the record has been classified as being part of a @emph{class}
       definition, then this field is not @code{NIL}.  In this case, it
       points to the name of the class, typically the name of the pointer
       type that has this record as its base type.  This field is filled
       in by @oproc{*OOC:SymbolTable:SymList.Finalize}.
       
       A record is classified as a @samp{class} if it is the base type of a
       pointer type declaration, or if it is an extension of another record,
       or if it has type-bound procedures.  *)
  END;

TYPE
  TypeVarDesc = RECORD
    (**Represents a type variable from the list of formal type parameters of a
       type with @ofield{Type.typePars}.  On the language level, they are
       introduced by declarations like @samp{TYPE T(a: A, b: B) = @dots{}}.

       Two situations must be distinguished for type variables.  First,
       creating an instance of a parametric type defines concrete values for
       the type variables.  The program then works with the concrete type that
       was assigned to the variable.  Second, within a type-bound procedure,
       type variables may appear in the formal parameter list and as types of
       local variables.  Here, the concreate type is only known when the
       type-bound procedure is called, but not during compilation time.
       Therefore, the compiler must treat the type variable similar to (but not
       like) the variable's type bound.  *)
    (TypeDesc)
    bound*: Type;
    (**Lower bound of the set of valid type arguments.  *)
    srcCodeBound-: Type;
    (**Similar to @ofield{bound}, but it is not changed by
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    parameterIndex-: LONGINT;
    (**For a type variable that appears in the receiver type of a type-bound
       procedure, this is the parameters index in the type parameter list.
       For all other type variables, this field is @code{-1}.  *)
  END;
  
TYPE
  QualType* = POINTER TO QualTypeDesc;
  TypeRef = RECORD
    type*: Type;                         (*... make this read-only? *)
    (**The type argument.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeType-: Type;
    (**Similar to @ofield{type}, but it is not changed by
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
  END;
  TypeRefArray* = POINTER TO ARRAY OF TypeRef;
  QualTypeDesc = RECORD
    (**An instance of a parametric type qualified by a set of type arguments.
       On the language level, this corresponds to a type of the form
       @samp{T(A,B)}, where @samp{T} is the name of a parametric type.
       Implicit instances of @otype{QualType} are created by the compiler
       wherever a type variable appears in a pointer, record, or array type.

       As a consequence, almost every instance of @otype{Type} can appear as
       the base type of a @otype{QualType} and there is no one-to-one relation
       between the kind of type and the type of its symbol table
       representation.  For example, checking the type like @samp{@var{type} IS
       Pointer} is often insufficient to determine if @var{type} is a pointer
       variable---use @oproc{Type.Deparam} or
       @oproc{*OOC:SymbolTable:TypeRules.IsPointer} instead.  *)
    (TypeDesc)
    baseType*: Type;                     (*... make this read-only? *)
    (**Base type of the qualified type expression.  This is a reference to
       a parametric type.  *)
    srcCodeBaseType-: Type;
    arguments*: TypeRefArray;
    (**The arguments of the parametric type.  *)
  END;

TYPE
  TypeClosure* = POINTER TO TypeClosureDesc;
  TypeClosureDesc = RECORD
    (**Type closures are created while parsing designators in
       @omodule{*OOC:IR}.  Instances of this class do @emph{not} appear in the
       symbol table or symbol file.  For the most part, they correspond to
       qualified types, although their base type may be an unnamed parametric
       type.  *)
    (TypeDesc)
    baseType-: Type;
    params: TypeVarArray;
    arguments-: TypeRefArray;
  END;

VAR
  emptyClosure: TypeClosure;
  predefName: Name;


(* Objects
   ------------------------------------------------------------------------ *)

CONST
  standardProc* = 0;
  (**Normal procedure without a receiver.  *)
  virtualMethod* = 1;
  (**Type-bound procedure using the usual dynamic binding.  *)
  staticMethod* = 2;
  (**Type-bound procedure using static binding.  *)
  
TYPE
  ProcDeclDesc = RECORD
    (**Procedure declarations and forward declarations of procedures are
       mapped to objects of this class.  *)
    (DeclarationDesc)
    procClass-: SHORTINT;
    (**One of @oconst{standardProc}, @oconst{virtualMethod}, or
       @oconst{staticMethod}.  *)
    isForwardDecl-: BOOLEAN;
    (**@code{TRUE}, iff the procedure declaration is a forward declaration
       of another procedure.  *)
    isAbstract*: BOOLEAN;
    (**If @code{TRUE}, then the type-bound procedure is an abstract method.  *)
    notRedefined*: BOOLEAN;
    (**If @code{TRUE}, then this type-bound procedure is not redefined in the
       local module and cannot be redefined in any client module.  *)
    nonlocalWrites*: BOOLEAN;
    (**If this field is @code{FALSE}, then a call to this function does not
       change any values in nonlocal variables or on the heap.  That is, 
       values taken from memory before a call to the function remain valid
       after the call.  Unless proven otherwise, this field remains
       @code{TRUE}.  *)
    tbProcIndex-: LONGINT;
    (**For type-bound procedures, this is the index of the procedure in the
       method table of its base record.  The first type-bound procedure has the
       index @code{0}.  A redefinition of a type-bound procedure inherits
       the index of its base definition.  A new type-bound procedure is
       assigned the next unused index.  For normal procedures, this field
       holds a negative value.  *)
    ns-: Namespace;
    (**A reference to the procedure's namespace.  Note that the namespace
       does not exist before
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}
       has been run.  *)
    formalPars*: FormalPars;             (*... make this read-only? *)
    (**The formal parameters of the procedure.  This is also the type of
       the procedure.  *)
    linkName*: STRING;
    (**If the name of the procedure differs between the source code and the
       low-level binary representation, then this field holds the name of
       the procedure on the link level.  Otherwise, it is @code{NIL}.  *)
    procAST-: AST.Node;
    (**Refers to the abstract syntax tree of the procedure, for example an
       instance of @otype{*OOC:AST.ProcDecl}.  For the pseudo procedure
       representing the module body, this field is @code{NIL}.  In this case,
       the field @ofield{parent} is also @code{NIL}.  *)
    hasTryStatm*: BOOLEAN;
    (**If a @samp{TRY} statement is part of the intermediate representation
       of the procedure, then this field is changed to @code{TRUE}.  This
       allows the C back-end to insert some ``volatile'' qualifiers to the
       procedures parameter list, for the sake of the @samp{setjmp} magic.  *)
  END;

CONST
  unlimitedArgs* = MAX (INTEGER);
  
TYPE
  PredefProc* = POINTER TO PredefProcDesc;
  PredefProcDesc = RECORD
    (**Predefined functions and procedures are mapped to this type.  *)
    (DeclarationDesc)
    id-: PredefId;
    minArgs-, maxArgs-: INTEGER;
    (**Minimum and maximum number of arguments for this predefined
       procedure.  If there is no fixed upper bound, then @ofield{maxArgs}
       is @oconst{unlimitedArgs}.  For some predefined procures, like
       @samp{NEW}, the number of arguments depends on the context of its
       use.  *)
  END;

TYPE
  ConstDecl* = POINTER TO ConstDeclDesc;
  ConstDeclDesc = RECORD
    (DeclarationDesc)
    (**This class represents constant declarations.  *)
    value-: Boxed.Object;
    (**The value of the constant.  For the special value @samp{NIL}, this
       field is @code{NIL}.  *)
    type-: PredefType;
    constExpr-: AST.Node;
    (**The part of the abstract syntax tree that defines the value of the
       constant.  *)
  END;

TYPE
  VarDeclDesc = RECORD
    (**Variable declarations, formal parameters, and receivers of type-bound
       procedures are stored as instances of this class.  *)
    (DeclarationDesc)
    type-: Type;
    (**The type of the variable.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeType-: Type;
    (**Similar to @ofield{type}, but it is not changed to a reference to
       the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    isParameter-: BOOLEAN;
    (**@code{TRUE}, iff the variable is a formal parameter, or the receiver,
       of a procedure.  *)
    isReceiver-: BOOLEAN;
    (**@code{TRUE}, iff the variable is the receiver of a type-bound 
       procedure.  *)
    hasAliasList*: BOOLEAN;
    (**For a receiver, this field is set if it has a (possibly empty) list
       of type aliases for the base record's type variables.  *)
    isVarParam-: BOOLEAN;
    (**@code{TRUE}, iff the variable is a formal variable parameter, that 
       is, a parameter with the @code{VAR} flag set.  *)
    isPassPerReference-: BOOLEAN;
    (**For a parameter declaration, this field indicates if arguments are
       passed to the callee as references.  If it is @code{TRUE}, then the
       procedure call passes the address of the argument to the called
       procedure, instead of the arguments value.  @ofield{isVarParam} implies
       @ofield{isPassPerReference}.  Note: This field may hold the wrong
       value until @ofield{type} has been set to its final value.  *)
    hasLocalCopy*: BOOLEAN;
    (**For record and array parameters that are passed by value, this field
       indicates if a local copy of the argument has to be created.  *)
    isReadOnly*: BOOLEAN;
    (**This field determines if a parameter should be considered read-only
       within a procedure.  It is @code{TRUE} if @samp{NO_COPY} is set for
       the parameter.  *)
    permitArgumentNIL*: BOOLEAN;
    (**If set for a parameter, then the value @code{NIL} may be passed to this
       parameter.  This is only possible if arguments for this parameter are
       passed by reference, not by value.  *)
    supplementArgs*: BOOLEAN;
    (**For a parameter, this is @code{FALSE} if a call to the procedure
       should omit any type tag or length information for this formal
       parameter.  Default is @code{TRUE}.  *)
  END;

TYPE
  FieldDecl* = POINTER TO FieldDeclDesc;
  FieldDeclDesc = RECORD
    (**This class represents record fields.  *)
    (DeclarationDesc)
    type*: Type;                         (*... make this read-only? *)
    (**The type of the record field.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeType-: Type;
    (**Similar to @ofield{type}, but it is not changed to a reference to
       the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    offset-: LONGINT;                      (* FIXME... make this `Integer'? *)
    (**Offset in bytes of this field with respect to the record variable's
       base address.  This field is initially @samp{-1}, and changed to its
       final value when calculating size and alignment of the record type.  *)
    shadowsPrivateBase*: BOOLEAN;
    (**If @code{TRUE}, then a record field or type-bound procedure of the
       same name from another module is shadowed by this declaration.  This
       information is used to disambiguate member names in C structs.  *)
  END;

TYPE
  TypeDeclDesc = RECORD
    (**All type declarations are mapped to instances of this class.  *)
    (DeclarationDesc)
    type*: Type;                         (*... make this read-only? *)
    (**The type of the declaration.  If this is initially a type name,
       it is replaced with a reference to the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    srcCodeType*: Type;
    (**Similar to @ofield{type}, but it is not changed to a reference to
       the true type after
       @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.  *)
    isTypeParameter-: BOOLEAN;
    (**If @code{TRUE}, then this declaration is a formal type parameter of a
       @otype{TypePars} object.  In this case, @ofield{type} is an instance of
       @otype{TypeVar}, whose @ofield{TypeVar.bound} is the type from the
       declaration.  *)
  END;

TYPE
  Redirect* = POINTER TO RedirectDesc;
  RedirectDesc = RECORD
    (DeclarationDesc)
    module-: Name;
    ident-: Name;
  END;
  
VAR
  predefIdToType*: POINTER TO ARRAY OF PredefType;
  (**This array maps ids to instances of @otype{PredefType}.  It is set
     by @oproc{*OOC:SymbolTable:Predef.CreatePredef} and
     @oproc{*OOC:SymbolTable:Predef.CreateSYSTEM}.  *)

  emptyBaseURI: URI.HierarchicalURI;
  (* this URI is used to read relative URI strings from symbol files; it
     is subsequently discarded *)
  

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    (Storage.WriterDesc)
    docWriter: Storage.Writer;
  END;
  
TYPE
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD
    (Storage.ReaderDesc)
    docReader: Storage.Reader;
  END;

PROCEDURE (w: Writer) INIT*(ch, chDoc: IO.ByteChannel);
  BEGIN
    ASSERT(chDoc # NIL);
    w.INIT^(ch);
    w.docWriter := Storage.ConnectWriter(chDoc);
  END INIT;

PROCEDURE (r: Reader) INIT*(ch, chDoc: IO.ByteChannel);
  BEGIN
    r.INIT^(ch);
    IF (chDoc = NIL) THEN
      r.docReader := NIL;
    ELSE
      r.docReader := Storage.ConnectReader(chDoc);
    END;
  END INIT;


PROCEDURE InitNamespace* (ns: Namespace);
  BEGIN
  END InitNamespace;

PROCEDURE (ns: Namespace) [ABSTRACT] IdentifyLocal2*(sourceContext: Item;
                                                     name: Name;
                                                     ignorePosition: BOOLEAN;
                                                     VAR baseNotExported: BOOLEAN): Declaration;
(**Tries to find a declaration matching the name @oparam{name} in the local
   namespace @oparam{ns}.  The search will @emph{not} continue into any
   enclosing or inherited namespace.
   
   The parameter @oparam{sourceContext} describes the context in which the
   name is used.  It is the module or procedure item in which the using
   occurence of @oparam{name} takes place.
   
   If the parameter @oparam{ignorePosition} is @code{TRUE}, the relative
   position of @oparam{name} and any matching declaration is ignored when
   determining whether the visibility of the declaration at the place of
   the using occurence of @oparam{name}.  This is used to implement the
   relaxed ording rules for names that are used as pointer base types.

   If on entry to this procedure the parameter @oparam{baseNotExported} is
   @code{FALSE}, then a value of @code{TRUE} on completion signals that a
   matching declaration exists, but that it is not exported by its defining
   module.  While this information does not make a difference from the point
   of view of a program's sementics, it can be of importance during code
   generation.  *)
  END IdentifyLocal2;

PROCEDURE (ns: Namespace) IdentifyLocal* (sourceContext: Item;
                                          name: Name;
                                          ignorePosition: BOOLEAN): Declaration;
(**The normal search method within a given namespace.  The parameters are
   like @oproc{Namespace.IdentifyLocal2}, with the @samp{baseNotExported}
   information omitted.  *)
  VAR
    baseNotExported: BOOLEAN;
  BEGIN
    baseNotExported := FALSE;
    RETURN ns.IdentifyLocal2(sourceContext, name, ignorePosition, baseNotExported);
  END IdentifyLocal;

PROCEDURE (ns: Namespace) [ABSTRACT] Identify2* (sourceContext: Item;
                                                name: Name;
                                                ignorePosition: BOOLEAN;
                                                VAR baseNotExported: BOOLEAN): Declaration;
(**Similar to @oproc{Namespace.IdentifyLocal2}, but continue the search in
   any enclosing or inherited namespace, if the name @oparam{name} cannot
   be resolved in the local namespace.  *)
  END Identify2;

PROCEDURE (ns: Namespace) Identify* (sourceContext: Item;
                                     name: Name;
                                     ignorePosition: BOOLEAN): Declaration;
(**The normal search method within a set of interrelated namespaces.  The
   parameters are like @oproc{Namespace.Identify2}, with the
   @samp{baseNotExported} information omitted.  *)
  VAR
    baseNotExported: BOOLEAN;
  BEGIN
    baseNotExported := FALSE;
    RETURN ns.Identify2(sourceContext, name, ignorePosition, baseNotExported);
  END Identify;

PROCEDURE (ns: Namespace) GetSuperProcByIndex* (index: LONGINT): ProcDecl;
(**Forward declaration of
   @oproc{*OOC:SymbolTable:Namespace.Extended.GetSuperProcByIndex}.  *)
  BEGIN
    ASSERT(FALSE);
  END GetSuperProcByIndex;


PROCEDURE WriteType(w: Storable.Writer; type, srcCodeType: Type)
RAISES IO.Error;
  BEGIN
    w.WriteObject(srcCodeType);
  END WriteType;

PROCEDURE ReadType(r: Storable.Reader; VAR type, srcCodeType: Type)
RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    r.ReadObject(obj);
    IF (obj = NIL) THEN
      srcCodeType := NIL;
      type := NIL;
    ELSE
      srcCodeType := obj(Type);
      type := srcCodeType;
    END;
  END ReadType;

PROCEDURE InitPosition* (position: Position; pos: ModulePos;
                         line: ModuleLine; column: ModuleColumn);
  BEGIN
    position. pos := pos;
    position. line := line;
    position. column := column
  END InitPosition;

PROCEDURE (position: Position) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    (* note: extension Name does not call this Store *)
    w. WriteNum (position. pos);
    w. WriteNum (position. line);
    w. WriteNum (position. column);
  END Store;

PROCEDURE (position: Position) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    (* note: extension Name does not call this Load *)
    r. ReadNum (position. pos);
    r. ReadNum (position. line);
    r. ReadNum (position. column);
  END Load;


PROCEDURE InitName* (name: Name; str: NameString; pos: ModulePos;
                     line: ModuleLine; column: ModuleColumn);
  BEGIN
    InitPosition (name, pos, line, column);
    name. str := str
  END InitName;

PROCEDURE (name: Name) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    len: LONGINT;
  BEGIN
    (*name. Store^ (w);   don't store position part of name *)
    len := Strings.Length (name. str^);
    w. WriteNum (len);
    w. WriteBytes (name. str^, 0, len)
  END Store;

PROCEDURE (name: Name) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    str: NameString;
    len: LONGINT;
  BEGIN
    (* instead of a Load^, initialize the position part by hand: *)
    InitPosition (name, posImportedName, -1, -1);
    r. ReadNum (len);
    NEW (str, len+1);
    str[len] := 0X;
    r. ReadBytes (str^, 0, len);
    name. str := str
  END Load;



PROCEDURE InitItem* (item: Item; parent: Item);
  BEGIN
    item. nextNested := NIL;
    item. nestedItems := NIL;
    item. tailNestedItems := NIL;
    item. parent := parent;
    item. flagList := NIL;
    IF (parent # NIL) THEN
      ASSERT ( (parent IS Module) OR
               (parent IS ProcDecl) OR
               (parent IS Record) OR
               (parent IS FormalPars) OR
               (parent IS TypePars) );
      IF parent.nestedItems = NIL THEN
        parent.nestedItems := item;
      ELSE
        parent.tailNestedItems.nextNested := item;
      END;
      parent.tailNestedItems := item;
    END
  END InitItem;

PROCEDURE WriteItemList(w: Storable.Writer; item: Item) RAISES IO.Error;
  BEGIN
    WHILE item # NIL DO
      w. WriteObject(item);
      item := item.nextNested;
    END;
    w.WriteObject(NIL);
  END WriteItemList;
  
PROCEDURE ReadItemList(r: Storable.Reader;
                       VAR list, last: Item)
RAISES IO.Error;
  VAR
    obj : Object.Object;
  BEGIN
    list := NIL; last := NIL;
    r. ReadObject(obj);
    WHILE obj # NIL DO
      WITH obj : Item DO
        IF last # NIL THEN
          last.nextNested := obj
        ELSE
          list := obj
        END;
        last := obj
      END;
      r.ReadObject(obj)
    END;
  END ReadItemList;

PROCEDURE (item: Item) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    WriteItemList(w, item.nestedItems);
    w. WriteObject (item. parent);
    (* item.flagList is not stored *)
  END Store;

PROCEDURE (item: Item) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    item. nextNested := NIL;
    ReadItemList(r, item. nestedItems, item. tailNestedItems);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      item. parent := NIL
    ELSE
      item. parent := obj(Item)
    END;
    item. flagList := NIL;
  END Load;

PROCEDURE ^ (type: Type) Deparam*(): Type;

PROCEDURE (item: Item) Module*(): Module;
(**Returns the item, that is the root of the hierarchy that includes
   @oparam{item}.  The returned item is never @code{NIL}, because even
   predefined items are nested in pseudo modules.

   @emph{Note}: Currently, this function fails for the automatically generated
   pseudo procedure @oconst{declModuleBody} representing the module body.  *)
  BEGIN
    IF (item.parent = NIL) & (item IS Type) THEN
      item := item(Type).Deparam();  (* fix up "orphaned" type closure *)
    END;
    WHILE (item.parent # NIL) DO
      item := item.parent;
      IF (item.parent = NIL) & (item IS Type) THEN
        item := item(Type).Deparam();  (* fix up  "orphaned" type closure *)
      END;
    END;
    RETURN item(Module)
  END Module;

PROCEDURE (item: Item) InStandardModule*(): BOOLEAN;
(**Return @code{TRUE} if @oparam{item} is part of a normal module.  Result is
   false for internal, @samp{INTERFACE}, or @samp{FOREIGN} modules.  *)
  VAR
    module: Module;
  BEGIN
    IF (item.parent = NIL) THEN  (* for module body "procedure" *)
      RETURN TRUE;
    ELSE
      module := item.Module();
      RETURN (module.class = mcStandard);
    END;
  END InStandardModule;
  
PROCEDURE (item: Item) Procedure*(): ProcDecl;
(**Returns the procedure item in which @oparam{item} is nested.  The result is
   @code{NIL}, if @oparam{item} is not part of a procedure.  *)
  BEGIN
    REPEAT
      item := item. parent
    UNTIL (item = NIL) OR (item IS ProcDecl);
    IF (item = NIL) THEN
      RETURN NIL
    ELSE
      RETURN item(ProcDecl)
    END;
  END Procedure;

PROCEDURE (item: Item) AddFlag* (name: Name);
(**Add modifier flag @oparam{name} to @oparam{item}.  Errors for invalid
   names are reported while creating the namespace, @emph{not} by this
   procedure.  *)
  VAR
    fl: Flag;
    id: INTEGER;
    
  PROCEDURE Append (VAR list: Flag);
    BEGIN
      IF (list = NIL) THEN
        fl.nextFlag := NIL;
        list := fl;
      ELSE
        Append(list.nextFlag);
      END;
    END Append;
  
  BEGIN
    IF (name.str^ = "NO_COPY") THEN
      id := flagNoCopy;
    ELSIF (name.str^ = "ABSTRACT") THEN
      id := flagAbstract;
    ELSIF (name.str^ = "NO_LENGTH_INFO") THEN
      id := flagNoLengthInfo;
    ELSIF (name.str^ = "NO_DESCRIPTOR") THEN
      id := flagNoDescriptor;
    ELSIF (name.str^ = "NOT_EXTENSIBLE") THEN
      id := flagNotExtensible;
    (*ELSIF (name.str^ = "EXTENSIBLE") THEN
      id := flagExtensible;*)
    ELSIF (name.str^ = "UNCHECKED_EXCEPTION") THEN
      id := flagUncheckedException;
    ELSIF (name.str^ = "CSTRING") THEN
      id := flagCString;
    ELSIF (name.str^ = "NIL_COMPAT") THEN
      id := flagNilCompat;
    ELSIF (name.str^ = "UNION") THEN
      id := flagUnion;
    ELSIF (name.str^ = "READ_ONLY") THEN
      id := flagReadOnly;
    ELSIF (name.str^ = "NO_RETURN") THEN
      id := flagNoReturn;
    ELSIF (name.str^ = "DEPRECATED") THEN
      id := flagDeprecated;
    ELSIF (name.str^ = "OOC_EXTENSIONS") THEN
      id := flagOOCExtensions;
    ELSIF (name.str^ = "ALIGN1") THEN
      id := flagAlign1;
    ELSIF (name.str^ = "ALIGN2") THEN
      id := flagAlign2;
    ELSIF (name.str^ = "ALIGN4") THEN
      id := flagAlign4;
    ELSIF (name.str^ = "ALIGN8") THEN
      id := flagAlign8;
    ELSIF (name.str^ = "VTABLE") THEN
      id := flagVtable;
    ELSIF (name.str^ = "NO_TRACED_POINTERS") THEN
      id := flagAtomic;
    ELSE
      id := flagUnknownName;
    END;

    NEW(fl);
    fl.id := id;
    fl.pos := name;
    Append(item.flagList);
  END AddFlag;

PROCEDURE InitDeclaration* (decl: Declaration; parent: Item; name: Name;
                            visibleFrom: ModulePos; exportMark: ExportMark;
                            docString: Doc.Document);
  BEGIN
    InitItem (decl, parent);
    decl. name := name;
    decl. visibleFrom := visibleFrom;
    decl. exportMark := exportMark;
    decl. docString := docString;
    decl. deprecated := FALSE;
    decl. cachedId := NIL;
    decl. usageCount := 0;
  END InitDeclaration;

PROCEDURE (decl: Declaration) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    decl. Store^ (w);
    w. WriteObject (decl. name);
    (*w. WriteNum (decl. visibleFrom);*)
    w. WriteNum (decl. exportMark);
    IF (decl. exportMark # nameNotExported) THEN
      w(Writer).docWriter.WriteObject(decl.docString);
    ELSE  
      w(Writer).docWriter.WriteObject(NIL);
    END;
    w. WriteBool (decl.deprecated);
  END Store;

PROCEDURE (decl: Declaration) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    i: LONGINT;
    obj: Object.Object;
  BEGIN
    decl. Load^ (r);
    r. ReadObject (obj);
    decl. name := obj(Name);
    (*r. ReadNum (decl. visibleFrom);
      for an importing module, the point at which the declaration starts
      to be visible is of no importance *)
    decl. visibleFrom := visiblePosImportedDecl;
    (* all imported declarations get by default this position, except
       for formal parameter declarations; the latter are fixed in 
       @oproc{VarDecl.Load} *)
    r. ReadNum (i); decl. exportMark := SHORT (SHORT (i));

    (* doc strings are stored in a separate file, and only read on demand *)
    IF (r(Reader).docReader # NIL) THEN
      r(Reader).docReader.ReadObject(obj);
      IF (obj = NIL) THEN  
        decl.docString := NIL;
      ELSE  
        decl.docString := obj(Doc.Document);
      END;
    ELSE
      decl.docString := NIL;
    END;
    
    r. ReadBool (decl.deprecated);
    decl. cachedId := NIL;
    decl. usageCount := 0;
  END Load;

PROCEDURE (decl: Declaration) Name*(): STRING;
(**As long as the symbol table code does not use @code{STRING}, this function
   can be used to get the declaration's name as a string.  *)
  BEGIN
    RETURN Object.NewLatin1(decl.name.str^);
  END Name;

PROCEDURE (decl: Declaration) IncrUsageCounter*;
  BEGIN
    INC(decl.usageCount);
  END IncrUsageCounter;


PROCEDURE ExportTypePosition (type: Type): BOOLEAN;
(* The current C back-end uses the position of a unnamed type constructor to
   create a unqiue name for its type descriptor.  This means, that the position
   must be exported for variables like @samp{VAR x*: POINTER TO ARRAY OF CHAR},
   or an importing module cannot call @code{NEW} on @samp[x}.  *)
  BEGIN
    RETURN (type IS Pointer) & (type. namingDecl = NIL);
  END ExportTypePosition;

PROCEDURE InitType* (type: Type; parent: Item; position: Position);
  BEGIN
    InitItem (type, parent);
    type. position := position;
    type. namingDecl := NIL;
    type. typePars := NIL;
    type. size := unknownSize;
    type. align := 1;
    type. hasDescriptor := TRUE;
  END InitType;

PROCEDURE (type: Type) PreciousTypePars*(): BOOLEAN;
(**If @code{TRUE}, then the @ofield{type.typePars} are taken from the source
   code, and not derived automatically by the compiler.  Such parameters must
   be written to the symbol file, all others can be replaced with @code{NIL}.
   *)
  BEGIN
    RETURN (type.typePars # NIL) & (type.typePars.nestedItems # NIL);
  END PreciousTypePars;

PROCEDURE (type: Type) IsCheckedException*(): BOOLEAN;
  VAR
    ptr: Type;
  BEGIN
    IF (type IS Pointer) THEN
      ptr := type.Deparam();
      ptr := ptr(Pointer).baseType.Deparam();
      RETURN ~(ptr IS Record) OR ~ptr(Record).isUncheckedException;
    ELSE
      RETURN TRUE;
    END;
  END IsCheckedException;

PROCEDURE (type: Type) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    type. Store^ (w);
    w. WriteObject (type. namingDecl);
    IF type.PreciousTypePars() THEN
      w.WriteObject(type.typePars);
    ELSE
      w.WriteObject(NIL);
    END;
    IF ExportTypePosition (type) THEN
      w. WriteObject (type. position);
    END;
    w. WriteNum (type. size);
    w. WriteNum (type. align);
    w. WriteBool (type. hasDescriptor);
  END Store;

PROCEDURE (type: Type) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
    i: LONGINT;
  BEGIN
    type. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      type. namingDecl := NIL
    ELSE
      type. namingDecl := obj(TypeDecl)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      type. typePars := NIL
    ELSE
      type. typePars := obj(TypePars)
    END;
    IF ExportTypePosition (type) THEN
      r. ReadObject (obj);
      type. position := obj(Position);
    ELSE
      type. position := importPosition;
    END;
    r. ReadNum (type. size);
    r. ReadNum (i);
    type. align := SHORT (i);
    r. ReadBool (type. hasDescriptor);
  END Load;

PROCEDURE (type: Type) SetNamingDecl* (namingDecl: TypeDecl);
(**Sets the field @ofield{Type.namingDecl} of @oparam{type} to @oparam{namingDecl}.  *)
  BEGIN
    type. namingDecl := namingDecl
  END SetNamingDecl;

PROCEDURE (type: Type) SetTypePars* (typePars: TypePars);
(**Sets the field @ofield{type.typePars} to @oparam{typePars}.  *)
  BEGIN
    type. typePars := typePars;
  END SetTypePars;

PROCEDURE (type: Type) SetSize* (size: LONGINT; align: INTEGER);
  BEGIN
    type. size := size;
    type. align := align;
  END SetSize;

PROCEDURE (type: Type) ArrayDimensions*(): LONGINT;
(**Returns the number of dimensions of the type @oparam{type}.  Result
   is zero if @oparam{type} is no array.  *)
  VAR
    dim: LONGINT;
  BEGIN
    dim := 0;
    WHILE (type IS Array) DO
      INC (dim);
      type := type(Array). elementType
    END;
    RETURN dim
  END ArrayDimensions;

PROCEDURE (type: Type) Deparam*(): Type;
(**Returns the underlying type of a parametric type.  In particular, it
   returns @samp{QualType.baseType} for a qualified instance of a parametric
   type, and @oparam{type} for everything else.  *)
  BEGIN
    RETURN type;
  END Deparam;

PROCEDURE (type: Type) Bound*(): Type;
(**Returns the lower bound of the type.  In particular, it
   returns @samp{TypeVar.bound} for a type variable, and @oparam{type} for
   everything else.  *)
  BEGIN
    RETURN type;
  END Bound;

PROCEDURE ^ Expand*(type: Type): Type;

PROCEDURE (type: Type) Closure*(subType: Type): Type;
(**If @oparam{type} is a closure and @oparam{subType} a parametric type, then
   apply the bindings of @oparam{type} to the parameters of @oparam{subType}
   and return the resulting type.  Otherwise, return @oparam{subType}
   unchanged.  *)
  BEGIN
    RETURN Expand(subType);
  END Closure;


PROCEDURE InitLinkDirective (l: LinkDirective);
  BEGIN
    l. next := NIL;
  END InitLinkDirective;

PROCEDURE (l: LinkDirective) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w. WriteObject (l. next)
  END Store;

PROCEDURE (l: LinkDirective) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      l. next := NIL
    ELSE
      l. next := obj(LinkDirective)
    END
  END Load;

PROCEDURE (l: LinkFile) Store* (w: Storable.Writer) RAISES IO.Error;
  PROCEDURE WriteURI (w: Storable.Writer; uri: URI.HierarchicalURI)
  RAISES IO.Error;
    VAR
      str8: Object.String8;
      chars: Object.CharsLatin1;
    BEGIN
      str8 := uri.ToString();
      chars := str8.CharsLatin1();
      w.WriteString(chars^);
    END WriteURI;
  
  BEGIN
    l. Store^ (w);
    WriteURI (w, l. file);
    w. WriteStr (l. prefixOption);
    w. WriteStr (l. suffixOption);
  END Store;

PROCEDURE ReadString8(r: Storable.Reader): STRING
RAISES IO.Error;
  VAR
    str: STRING;
  BEGIN
    r.ReadStr(str);
    IF (str = NIL) THEN
      RETURN NIL;
    ELSE
      RETURN str;
    END;
  END ReadString8;

PROCEDURE (l: LinkFile) Load* (r: Storable.Reader) RAISES IO.Error;
  PROCEDURE ReadURI (r: Storable.Reader; VAR uri: URI.HierarchicalURI)
  RAISES IO.Error;
    VAR
      b: ARRAY 1024 OF CHAR;
      u: URI.URI;
    BEGIN
      r. ReadString (b);
      (* use emptyBaseURI so that the URI parser doesn't report an error for
         the relative URI: *)
      TRY
        u := ParserURI.NewURILatin1(b, emptyBaseURI);
      CATCH Exception.ParseError:
        ASSERT (FALSE);
      END;
      (* eliminate emptyBaseURI, so that we get the original relative URI: *)
      u := u(URI.HierarchicalURI). MakeRelative (emptyBaseURI);
      uri := u(URI.HierarchicalURI);
    END ReadURI;
  
  BEGIN
    l. Load^ (r);
    ReadURI (r, l. file);
    l.prefixOption := ReadString8(r);
    l.suffixOption := ReadString8(r);
  END Load;


PROCEDURE (l: LinkLib) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    l. Store^ (w);
    w. WriteStr (l. libraryName);
    w. WriteStr (l. prefixOption);
    w. WriteStr (l. suffixOption);
    w. WriteNum (l. type);
    w. WriteNum (LEN (l. dependencies^));
    FOR i := 0 TO LEN (l. dependencies^)-1 DO
      w. WriteStr (l. dependencies[i]);
    END;
  END Store;

PROCEDURE (l: LinkLib) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    len, i: LONGINT;
  BEGIN
    l.Load^(r);
    l.libraryName := ReadString8(r);
    l.prefixOption := ReadString8(r);
    l.suffixOption := ReadString8(r);
    r. ReadNum (l.type);
    r. ReadNum (len);
    NEW (l. dependencies, len);
    FOR i := 0 TO len-1 DO
      l. dependencies[i] := ReadString8(r);
    END;
  END Load;


PROCEDURE InitModule* (mod: Module; name: Name; docString: Doc.Document;
                       class: ModuleClass; callConv: CallConv;
                       moduleAST: AST.Node; bodyDecl: ProcDecl);
  BEGIN
    InitDeclaration (mod, NIL, name, 0, nameExported, docString);
    mod. ns := NIL;
    mod. class := class;
    mod. libraryName := NIL;
    mod. callConv := callConv;
    mod. linkDirectives := NIL;
    mod. fingerprint := 0;
    mod. prunedImports := NIL;
    mod. moduleAST := moduleAST;
    mod. bodyDecl := bodyDecl;
  END InitModule;

PROCEDURE (mod: Module) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    mod. Store^ (w);
    (* ignore field `ns' *)
    w. WriteSInt (mod. class);
    w. WriteStr (mod.libraryName);
    w. WriteSInt (mod. callConv);
    w. WriteObject (mod. linkDirectives)
  END Store;

PROCEDURE (mod: Module) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    mod. Load^ (r);
    mod. ns := NIL;
    r. ReadSInt (mod. class);
    mod.libraryName := ReadString8(r);
    r. ReadSInt (mod. callConv);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      mod. linkDirectives := NIL
    ELSE
      mod. linkDirectives := obj(LinkDirective)
    END;
    mod. prunedImports := NIL;
    mod. moduleAST := NIL;
  END Load;

PROCEDURE (mod: Module) SetNamespace* (ns: Namespace);
(**Sets the field @ofield{Module.ns} of @oparam{mod} to @oparam{ns}.  *)
  BEGIN
    mod. ns := ns;
  END SetNamespace;

PROCEDURE (mod: Module) SetLibraryName* (name: STRING);
  BEGIN
    mod.libraryName := name;
  END SetLibraryName;

PROCEDURE (mod: Module) ClassToString*(): STRING;
  BEGIN
    CASE mod. class OF
    | mcStandard : RETURN "standard"
    | mcInternal : RETURN "internal"
    | mcForeign  : RETURN "foreign"
    | mcInterface: RETURN "interface"
    END
  END ClassToString;

PROCEDURE (mod: Module) CallConvToString*(): STRING;
  BEGIN
    CASE mod. callConv OF
    | callConvInvalid : RETURN "--invalid--"
    | callConvDefault : RETURN "default"
    | callConvInternal: RETURN "internal"
    | callConvC       : RETURN "C"
    | callConvPascal  : RETURN "Pascal"
    | callConvFastcall  : RETURN "Fastcall"
    END
  END CallConvToString;

PROCEDURE NewLinkFile (file: URI.HierarchicalURI;
                       prefixOption, suffixOption: STRING): LinkFile;
  VAR
    l: LinkFile;
  BEGIN
    NEW (l);
    InitLinkDirective (l);
    l. file := file;
    l. prefixOption := prefixOption;
    l. suffixOption := suffixOption;
    RETURN l
  END NewLinkFile;

PROCEDURE NewLinkLib (libraryName: STRING;
                      dependencies: Object.StringArrayPtr;
                      prefixOption, suffixOption: STRING;
                      type: LONGINT): LinkLib;
  VAR
    l: LinkLib;
  BEGIN
    NEW (l);
    InitLinkDirective (l);
    l. libraryName := libraryName;
    l. dependencies := dependencies;
    l. prefixOption := prefixOption;
    l. suffixOption := suffixOption;
    l. type := type;
    RETURN l
  END NewLinkLib;

PROCEDURE AddLinkDirective (VAR list: LinkDirective; l: LinkDirective);
  BEGIN
    IF (list = NIL) THEN
      l. next := NIL;
      list := l
    ELSE
      AddLinkDirective (list. next, l)
    END
  END AddLinkDirective;

PROCEDURE (mod: Module) AddLinkFile* (file: URI.HierarchicalURI;
                                    prefixOption, suffixOption: STRING);
  BEGIN
    ASSERT (file # NIL);
    AddLinkDirective (mod. linkDirectives,
                      NewLinkFile (file, prefixOption, suffixOption))
  END AddLinkFile;

PROCEDURE (mod: Module) AddLinkLib* (libraryName: STRING;
                                     dependencies: Object.StringArrayPtr;
                                     prefixOption, suffixOption: STRING;
                                     type: LONGINT);
  BEGIN
    ASSERT (libraryName # NIL);
    AddLinkDirective (mod. linkDirectives,
                      NewLinkLib (libraryName, dependencies,
                                  prefixOption, suffixOption, type))
  END AddLinkLib;

PROCEDURE (mod: Module) NoObjectFile*(): BOOLEAN;
(**Returns @code{TRUE} if @oparam{mod} is an @samp{INTERFACE} or @samp{FOREIGN}
   module without @samp{LINK FILE} entries.  As far as the C back-end is
   concerned, such modules are translated into header files, but have no
   corresponding code or object file.  This also implies that there is no
   module descriptor, nor are there any type descriptors for definitions of the
   module.  *)
  VAR
    l: LinkDirective;
  BEGIN
    IF (mod.class = mcInterface) OR (mod.class = mcForeign) THEN
      l := mod.linkDirectives;
      WHILE (l # NIL) & ~(l IS LinkFile) DO
        l := l.next
      END;
      RETURN (l = NIL);
    ELSE
      RETURN (mod.class = mcInternal);
    END;
  END NoObjectFile;

PROCEDURE (mod: Module) GetExternalSource* (rootURI: URI.HierarchicalURI): URI.HierarchicalURI;
(**For a module of class @oconst{mcForeign} or @oconst{mcInterface}, return the
   file path for the first @samp{FILE} directive.  The URI of the file is
   expanded relative to the root of the repository, @oparam{rootURI}.  If there
   is no @samp{FILE}, result is @code{NIL}.  *)
  VAR
    l: LinkDirective;
  BEGIN
    ASSERT ((mod. class = mcForeign) OR (mod. class = mcInterface));
    l := mod. linkDirectives;
    WHILE (l # NIL) & ~(l IS LinkFile) DO
      l := l. next
    END;
    IF (l = NIL) THEN
      RETURN NIL;
    ELSE
      ASSERT (l(LinkFile). file # NIL);
      l(LinkFile). file. ResolveRelative (rootURI);
      RETURN l(LinkFile). file;
    END;
  END GetExternalSource;

PROCEDURE StringToCallConv*(str: STRING): CallConv;
  BEGIN
    IF str.Equals("C") THEN
      RETURN callConvC
    ELSIF str.Equals("Pascal") THEN
      RETURN callConvPascal
    ELSIF str.Equals("Fastcall") THEN
      RETURN callConvFastcall
	ELSE
      RETURN callConvInvalid
    END
  END StringToCallConv;



PROCEDURE InitImport* (import: Import; parent: Item; name: Name;
                       visibleFrom: ModulePos; docString: Doc.Document; 
                       moduleName: Name);
  BEGIN
    InitDeclaration (import, parent, name, visibleFrom, nameNotExported, docString);
    import. moduleName := moduleName;
    import. externalSymTab := NIL;
  END InitImport;

PROCEDURE (import: Import) SetExternalSymTab* (symTab: Module);
  BEGIN
    import. externalSymTab := symTab;
    import. fingerprint := symTab.fingerprint;
  END SetExternalSymTab;

PROCEDURE (import: Import) IsInternalImport*(): BOOLEAN;
(**Return @code{TRUE} if the imported module is pseudo module like
   @samp{SYSTEM}, which does not exist outside of the compiler itself.  *)
  BEGIN
    RETURN (import. moduleName. str^ = "SYSTEM");
  END IsInternalImport;


PROCEDURE (import: Import) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    import. Store^ (w);
    w. WriteObject (import. moduleName);
    w. WriteLInt (import. fingerprint);
  END Store;

PROCEDURE (import: Import) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    import. Load^ (r);
    r. ReadObject (obj);
    import. moduleName := obj(Name);
    r. ReadLInt (import. fingerprint);
  END Load;


PROCEDURE InitConstDecl* (constDecl: ConstDecl; parent: Item; name: Name;
                          visibleFrom: ModulePos; exportMark: ExportMark;
                          docString: Doc.Document;
                          value: Boxed.Object; type: PredefType;
                          constExpr: AST.Node);
  BEGIN
    InitDeclaration (constDecl, parent, name, visibleFrom, exportMark,
                     docString);
    constDecl. value := value;
    constDecl. type := type;
    constDecl. constExpr := constExpr;
  END InitConstDecl;

PROCEDURE (constDecl: ConstDecl) SetValueType* (value : Boxed.Object; type : PredefType);
  BEGIN
    constDecl.value := value;
    constDecl.type := type;
  END SetValueType;

PROCEDURE (constDecl: ConstDecl) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    constDecl. Store^ (w);
    w. WriteObject (constDecl. value);
    IF (constDecl. type = NIL) THEN
      (* the symbol table is incomplete: constants have not been evaluated
         and therefore their type information and their values are missing *)
      w. WriteNum (-1)
    ELSE
      w. WriteNum (constDecl. type. id)
    END
  END Store;

PROCEDURE (constDecl: ConstDecl) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
    id: LONGINT;
  BEGIN
    constDecl. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      constDecl. value := NIL
    ELSE
      constDecl. value := obj(Boxed.Object)
    END;
    r. ReadNum (id);
    IF (id = -1) THEN                    (* see comment in `Store' above *)
      constDecl. type := NIL;
    ELSE
      constDecl. type := predefIdToType[id];
      ASSERT (constDecl. type # NIL)
    END;
    constDecl. constExpr := NIL;
  END Load;


PROCEDURE InitExceptionName* (exceptionName: ExceptionName; parent: Item;
                              type: Type);
  BEGIN
    InitItem(exceptionName, parent);
    exceptionName. srcCodeType := type;
    exceptionName. type := type;
  END InitExceptionName;

PROCEDURE (exceptionName: ExceptionName) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    exceptionName. Store^ (w);
    (*w. WriteObject (exceptionName. type);*)
    WriteType(w, exceptionName.type, exceptionName.srcCodeType);
  END Store;

PROCEDURE (exceptionName: ExceptionName) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    exceptionName. Load^ (r);
    ReadType(r, exceptionName.type, exceptionName.srcCodeType);
  END Load;


PROCEDURE (varDecl: VarDecl) SetType* (type: Type);
  PROCEDURE PassPerReference (type: Type): BOOLEAN;
    BEGIN
      type := type.Deparam();
      RETURN (type IS Array) OR (type IS Record)
    END PassPerReference;
  
  BEGIN
    varDecl. type := type;
    varDecl. isPassPerReference :=
        varDecl. isParameter &
        (varDecl. isVarParam OR PassPerReference (type));
    varDecl. hasLocalCopy :=
        varDecl. isParameter &
        ~varDecl. isVarParam &
        PassPerReference (type);
    varDecl. isReadOnly :=
        varDecl. isPassPerReference &
        ~varDecl. isVarParam &
        ~varDecl. hasLocalCopy;
  END SetType;

PROCEDURE InitVarDecl* (varDecl: VarDecl; parent: Item; name: Name;
                        visibleFrom: ModulePos; exportMark: ExportMark;
                        docString: Doc.Document;
                        isParameter, isReceiver, isVarParam: BOOLEAN;
                        type: Type);
  BEGIN
    InitDeclaration (varDecl, parent, name, visibleFrom, exportMark, docString);
    varDecl. srcCodeType := type;
    varDecl. isParameter := isParameter;
    varDecl. isReceiver := isReceiver;
    varDecl. hasAliasList := FALSE;
    varDecl. isVarParam := isVarParam;
    varDecl. permitArgumentNIL := FALSE;
    varDecl. supplementArgs := TRUE;
    IF isReceiver THEN
      parent(FormalPars). receiver := varDecl
    END;
    varDecl. SetType (type);
  END InitVarDecl;

PROCEDURE (varDecl: VarDecl) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    varDecl. Store^ (w);
    WriteType(w, varDecl.type, varDecl.srcCodeType);
    w. WriteBool (varDecl. isParameter);
    w. WriteBool (varDecl. isReceiver);
    w. WriteBool (varDecl. hasAliasList);
    w. WriteBool (varDecl. isVarParam);
    w. WriteBool (varDecl. isPassPerReference);
    w. WriteBool (varDecl. hasLocalCopy);
    w. WriteBool (varDecl. isReadOnly);
    w. WriteBool (varDecl. permitArgumentNIL);
    w. WriteBool (varDecl. supplementArgs);
  END Store;

PROCEDURE (varDecl: VarDecl) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    varDecl. Load^ (r);
    ReadType(r, varDecl.type, varDecl.srcCodeType);
    r. ReadBool (varDecl. isParameter);
    r. ReadBool (varDecl. isReceiver);
    r. ReadBool (varDecl. hasAliasList);
    r. ReadBool (varDecl. isVarParam);
    r. ReadBool (varDecl. isPassPerReference);
    r. ReadBool (varDecl. hasLocalCopy);
    r. ReadBool (varDecl. isReadOnly);
    r. ReadBool (varDecl. permitArgumentNIL);
    r. ReadBool (varDecl. supplementArgs);
    
    IF varDecl. isParameter THEN
      (* fix position of formal parameter names; see @oconst{posImportedName}*)
      varDecl. visibleFrom := visiblePosImportedFormalParam
    END
  END Load;


PROCEDURE InitTypeDecl* (typeDecl: TypeDecl; parent: Item; name: Name;
                         visibleFrom: ModulePos; exportMark: ExportMark;
                         docString: Doc.Document; type: Type;
                         isTypeParameter: BOOLEAN);
  BEGIN
    InitDeclaration (typeDecl, parent, name, visibleFrom, exportMark, docString);
    typeDecl. type := type;
    typeDecl. srcCodeType := type;
    typeDecl. isTypeParameter := isTypeParameter;
  END InitTypeDecl;

PROCEDURE (typeDecl: TypeDecl) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    typeDecl. Store^ (w);
    WriteType(w, typeDecl.type, typeDecl.srcCodeType);
    w. WriteBool (typeDecl. isTypeParameter);
  END Store;

PROCEDURE (typeDecl: TypeDecl) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    typeDecl. Load^ (r);
    ReadType(r, typeDecl.type, typeDecl.srcCodeType);
    r. ReadBool (typeDecl. isTypeParameter);
  END Load;

PROCEDURE (typeDecl: TypeDecl) HasTypeParameters*(): BOOLEAN;
  VAR
    typePars: TypePars;
  BEGIN
    typePars := typeDecl.type.typePars;
    RETURN (typePars # NIL) & (typeDecl.type.parent = typePars);
  END HasTypeParameters;

PROCEDURE (typeDecl: TypeDecl) IsTypeParameter*(): BOOLEAN;
  BEGIN
    RETURN (typeDecl.parent IS TypePars);
  END IsTypeParameter;

PROCEDURE (typeDecl: TypeDecl) ParametricType*(): TypeDecl;
(**Map a type variable declaration to the parametric type declaration it is
   part of.  *)
  VAR
    ptr: Item;
  BEGIN
    ASSERT(typeDecl.IsTypeParameter());
    ptr := typeDecl.parent.parent.nestedItems;
    WHILE ~(ptr IS TypeDecl) OR
          (ptr(TypeDecl).type.parent # typeDecl.parent) DO
      ptr := ptr.nextNested;
    END;
    RETURN ptr(TypeDecl);
  END ParametricType;


PROCEDURE InitRedirect* (redir: Redirect; parent: Item; name: Name;
                         module, ident: Name);
  BEGIN
    InitDeclaration (redir, parent, name, 0, nameExported, NIL);
    redir. module := module;
    redir. ident := ident;
  END InitRedirect;

PROCEDURE (redir: Redirect) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    redir. Store^ (w);
    w. WriteObject (redir. module);
    w. WriteObject (redir. ident);
  END Store;

PROCEDURE (redir: Redirect) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    redir. Load^ (r);
    r. ReadObject (obj);
    redir. module := obj(Name);
    r. ReadObject (obj);
    redir. ident := obj(Name);
  END Load;


PROCEDURE InitFieldDecl* (fieldDecl: FieldDecl; parent: Item; name: Name;
                        visibleFrom: ModulePos; exportMark: ExportMark;
                        docString: Doc.Document; type: Type);
  BEGIN
    InitDeclaration (fieldDecl, parent, name, visibleFrom, exportMark, docString);
    fieldDecl. type := type;
    fieldDecl. srcCodeType := type;
    fieldDecl. offset := -1;
    fieldDecl. shadowsPrivateBase := FALSE;
  END InitFieldDecl;

PROCEDURE (fieldDecl: FieldDecl) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    fieldDecl. Store^ (w);
    WriteType(w, fieldDecl.type, fieldDecl.srcCodeType);
    w. WriteNum (fieldDecl. offset);
    w. WriteBool (fieldDecl. shadowsPrivateBase);
  END Store;

PROCEDURE (fieldDecl: FieldDecl) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    fieldDecl. Load^ (r);
    ReadType(r, fieldDecl.type, fieldDecl.srcCodeType);
    r. ReadNum (fieldDecl. offset);
    r. ReadBool (fieldDecl. shadowsPrivateBase);
  END Load;

PROCEDURE (fieldDecl: FieldDecl) SetOffset* (offset: LONGINT);
  BEGIN
    fieldDecl. offset := offset;
  END SetOffset;


PROCEDURE InitPredefProc* (proc: PredefProc; parent: Item; name: Name;
                           id: PredefId; minArgs, maxArgs: INTEGER);
  BEGIN
    InitDeclaration (proc, parent, name, 0, nameExported, NIL);
    proc. id := id;
    proc. minArgs := minArgs;
    proc. maxArgs := maxArgs;
  END InitPredefProc;

PROCEDURE (proc: PredefProc) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    ASSERT (FALSE)
  END Store;

PROCEDURE (proc: PredefProc) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    ASSERT (FALSE)
  END Load;


PROCEDURE InitProcDecl* (procDecl: ProcDecl; parent: Item; name: Name;
                         visibleFrom: ModulePos; exportMark: ExportMark;
                         docString: Doc.Document;
                         procClass: SHORTINT; isForwardDecl: BOOLEAN;
                         procAST: AST.Node);
  BEGIN
    InitDeclaration (procDecl, parent, name, visibleFrom, exportMark, docString);
    procDecl. procClass := procClass;
    procDecl. isForwardDecl := isForwardDecl;
    procDecl. isAbstract := FALSE;
    procDecl. notRedefined := FALSE;
    procDecl. nonlocalWrites := TRUE;
    procDecl. tbProcIndex := -1;
    procDecl. ns := NIL;
    procDecl. formalPars := NIL;
    procDecl. linkName := NIL;
    procDecl. procAST := procAST;
    procDecl. hasTryStatm := FALSE;
  END InitProcDecl;

PROCEDURE (procDecl: ProcDecl) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    procDecl. Store^ (w);
    w. WriteSInt (procDecl. procClass);
    w. WriteBool (procDecl. isForwardDecl);
    w. WriteBool (procDecl. isAbstract);
    w. WriteBool (procDecl. notRedefined);
    w. WriteBool (procDecl. nonlocalWrites);
    w. WriteNum (procDecl. tbProcIndex);
    w. WriteObject (procDecl. formalPars);
    w. WriteStr (procDecl. linkName);
    (* ignore field `ns' & `procAST' *)
  END Store;

PROCEDURE (procDecl: ProcDecl) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    procDecl. Load^ (r);
    r. ReadSInt (procDecl. procClass);
    r. ReadBool (procDecl. isForwardDecl);
    r. ReadBool (procDecl. isAbstract);
    r. ReadBool (procDecl. notRedefined);
    r. ReadBool (procDecl. nonlocalWrites);
    r. ReadNum (procDecl. tbProcIndex);
    procDecl. ns := NIL;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      procDecl. formalPars := NIL
    ELSE
      procDecl. formalPars := obj(FormalPars)
    END;
    procDecl.linkName := ReadString8(r);
    procDecl. procAST := NIL;
    procDecl. hasTryStatm := FALSE;
  END Load;

PROCEDURE (procDecl: ProcDecl) SetNamespace* (ns: Namespace);
(**Sets the field @ofield{ProcDecl.ns} of @oparam{procDecl} to @oparam{ns}.  *)
  BEGIN
    procDecl. ns := ns;
  END SetNamespace;

PROCEDURE (procDecl: ProcDecl) SetLinkName* (name: STRING);
  BEGIN
    procDecl. linkName := name;
  END SetLinkName;

PROCEDURE (procDecl: ProcDecl) CopyTBProcIndex* (redefinition: ProcDecl);
(**Sets the field @ofield{ProcDecl.tbProcIndex} of @oparam{redefinition} to
   that of @oparam{procDecl}.  @oparam{redefinition} must be a redefinition
   of the type-bound procedure @oparam{procDecl}.  *)
  BEGIN
    redefinition. tbProcIndex := procDecl. tbProcIndex
  END CopyTBProcIndex;

PROCEDURE (procDecl: ProcDecl) IsTypeBound*(): BOOLEAN;
  BEGIN
    RETURN (procDecl.procClass # standardProc);
  END IsTypeBound;

PROCEDURE (procDecl: ProcDecl) Class* (): Record;
(**For a type-bound procedure @oparam{procDecl}, this function returns the
   record type for which the procedure is defined.  For a normal procedure,
   this function returns @code{NIL}.  *)
  VAR
    class: Item;
  BEGIN
    IF procDecl.IsTypeBound() THEN
      class := procDecl.formalPars.receiver.type.Deparam();
      IF (class IS Pointer) THEN
        class := class(Pointer).baseType.Deparam();
      END;
      IF (class IS Record) THEN
        RETURN class(Record)
      ELSE
        RETURN NIL
      END;
    ELSE
      RETURN NIL
    END
  END Class;

PROCEDURE (procDecl: ProcDecl) RegisterForwardDecl* (forward: ProcDecl);
(**Adjusts the range of visibility of the procedure @oparam{procDecl} to
   start at the beginning of the visibility of @oparam{forward}.  *)
  BEGIN
    procDecl. visibleFrom := forward. visibleFrom
  END RegisterForwardDecl;

PROCEDURE (procDecl: ProcDecl) IsModuleBody*(): BOOLEAN;
(**Return @code{TRUE} iff this procedure declaration represents the module
   body.  *)
  BEGIN
    RETURN (procDecl.parent = NIL);
  END IsModuleBody;


PROCEDURE InitPredefType* (ptype: PredefType; parent: Item; id: PredefId);
  BEGIN
    InitType (ptype, parent, NIL);
    ptype. id := id;
  END InitPredefType;

PROCEDURE (tname: PredefType) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    ASSERT (FALSE)
  END Store;

PROCEDURE (tname: PredefType) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    ASSERT (FALSE)
  END Load;


PROCEDURE InitTypeName* (tname: TypeName; parent: Item; position: Position;
                         module, ident: Name);
  BEGIN
    InitType (tname, parent, position);
    tname. module := module;
    tname. ident := ident
  END InitTypeName;

PROCEDURE (tname: TypeName) IsPredefReference*(): BOOLEAN;
  BEGIN
    RETURN (tname.module # NIL) & (tname.module.str[0] = 0X);
  END IsPredefReference;

PROCEDURE (tname: TypeName) MarkAsPredefReference*();
  BEGIN
    tname.module := predefName;
  END MarkAsPredefReference;

PROCEDURE (tname: TypeName) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    tname. Store^ (w);
    w. WriteObject (tname. module);
    w. WriteObject (tname. ident)
  END Store;

PROCEDURE (tname: TypeName) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    tname. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      tname. module := NIL
    ELSE
      tname. module := obj(Name)
    END;
    r. ReadObject (obj);
    tname. ident := obj(Name)
  END Load;

PROCEDURE (tname: TypeName) GetImport* (): Import;
  VAR
    module: Module;
    decl: Declaration;
  BEGIN
    module := tname. Module();
    decl := module. ns. IdentifyLocal (module, tname. module, FALSE);
    RETURN decl(Import)
  END GetImport;


PROCEDURE InitRecord* (record: Record; parent: Item; position: Position;
                       baseType: Type);
  BEGIN
    InitType (record, parent, position);
    record. baseType := baseType;
    record. srcCodeBaseType := baseType;
    record. tbProcCount := -1;           (* initialize to "unknown number" *)
    record. ns := NIL;
    record. isUnion := FALSE;
    record. isAbstract := FALSE;
    record. isExtensible := TRUE;
    record. isUncheckedException := FALSE;
    record. isVtable := FALSE;
    record. isAtomic := FALSE;
    record. fieldAlign := 0;
    record. className := NIL
  END InitRecord;

PROCEDURE (record: Record) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    record. Store^ (w);
    WriteType(w, record.baseType, record.srcCodeBaseType);
    w. WriteNum (record. tbProcCount);
    w. WriteBool (record. isUnion);
    w. WriteBool (record. isAbstract);
    w. WriteBool (record. isExtensible);
    w. WriteBool (record. isUncheckedException);
    w. WriteBool (record. isVtable);
    w. WriteBool (record. isAtomic);
    w. WriteInt (record. fieldAlign);
    w. WriteObject (record. className);
    (* ignore field `ns' *)
  END Store;

PROCEDURE (record: Record) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    record. Load^ (r);
    ReadType(r, record.baseType, record.srcCodeBaseType);
    r. ReadNum (record. tbProcCount);
    record. ns := NIL;
    r. ReadBool (record. isUnion);
    r. ReadBool (record. isAbstract);
    r. ReadBool (record. isExtensible);
    r. ReadBool (record. isUncheckedException);
    r. ReadBool (record. isVtable);
    r. ReadBool (record. isAtomic);
    r. ReadInt (record. fieldAlign);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      record. className := NIL
    ELSE
      record. className := obj(Name)
    END;
  END Load;

PROCEDURE (record: Record) SetNamespace* (ns: Namespace);
(**Sets the field @ofield{Record.ns} of @oparam{record} to @oparam{ns}.  *)
  BEGIN
    record. ns := ns;
  END SetNamespace;

PROCEDURE (record: Record) AssignTBProcIndex* (procDecl: ProcDecl);
(**Assigns the next free type-bound procedure index to procedure 
   @oparam{procDecl}.  Also adjust the number of type-bound procedures of
   the record type @oparam{record}.  *)
  BEGIN
    procDecl. tbProcIndex := record. tbProcCount;
    INC (record. tbProcCount)
  END AssignTBProcIndex;

PROCEDURE (record: Record) ExtensionLevel*(): LONGINT;
(**A record without a base type has a level of @samp{0}.  Every extension level
   increments this level by one.  *)
  VAR
    level: LONGINT;
  BEGIN
    level := 0;
    WHILE (record.baseType # NIL) DO
      record := record.baseType(Record);
      INC(level);
    END;
    RETURN level;
  END ExtensionLevel;


PROCEDURE InitTypeVar* (typeVar: TypeVar; parent: Item;
                        position: Position; bound: Type);
  BEGIN
    InitType(typeVar, parent, position);
    typeVar.bound := bound;
    typeVar.srcCodeBound := bound;
    typeVar.parameterIndex := -1;
  END InitTypeVar;

PROCEDURE (typeVar: TypeVar) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    typeVar.Store^(w);
    WriteType(w, typeVar.bound, typeVar.srcCodeBound);
  END Store;

PROCEDURE (typeVar: TypeVar) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    typeVar.Load^(r);
    ReadType(r, typeVar.bound, typeVar.srcCodeBound);
    typeVar.parameterIndex := -1;
  END Load;

PROCEDURE (typeVar: TypeVar) Bound*(): Type;
  BEGIN
    RETURN typeVar.bound;
  END Bound;

PROCEDURE (typeVar: TypeVar) SetParameterIndex*(parameterIndex: LONGINT);
  BEGIN
    typeVar.parameterIndex := parameterIndex;
  END SetParameterIndex;


PROCEDURE InitTypePars* (typePars: TypePars; parent: Item);
  BEGIN
    InitItem(typePars, parent);
    typePars.params := NIL;
    typePars.ns := NIL;
  END InitTypePars;

PROCEDURE (typePars: TypePars) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    typePars.Store^(w);
    (* ignore field `params' and `ns' *)
  END Store;

PROCEDURE (typePars: TypePars) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    typePars.Load^(r);
    typePars.params := NIL;
    typePars.ns := NIL;
  END Load;

PROCEDURE (typePars: TypePars) SetNamespace* (ns: Namespace);
(**Sets the field @ofield{Record.ns} of @oparam{typePars} to @oparam{ns}.  *)
  BEGIN
    typePars.ns := ns;
  END SetNamespace;


PROCEDURE InitTypeRef*(VAR typeRef: TypeRef; type: Type);
  BEGIN
    typeRef.type := type;
    typeRef.srcCodeType := type;
  END InitTypeRef;

PROCEDURE StoreTypeRef(w: Storable.Writer;
                       VAR typeRef: TypeRef) RAISES IO.Error;
  BEGIN
    w. WriteObject (typeRef.srcCodeType);
  END StoreTypeRef;

PROCEDURE LoadTypeRef(r: Storable.Reader;
                      VAR typeRef: TypeRef) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    r. ReadObject (obj);
    typeRef.srcCodeType := obj(Type);
    typeRef.type := obj(Type);
  END LoadTypeRef;


PROCEDURE InitQualType* (qualType: QualType; parent: Item;
                         position: Position; baseType: Type;
                         arguments: TypeRefArray);
  BEGIN
    InitType(qualType, parent, position);
    qualType.baseType := baseType;
    qualType.srcCodeBaseType := baseType;
    qualType.arguments := arguments;
  END InitQualType;

PROCEDURE NewQualType*(parent: Item; position: Position; baseType: Type;
                       arguments: TypeRefArray): QualType;
  VAR
    qualType: QualType;
  BEGIN
    NEW(qualType);
    InitQualType(qualType, parent, position, baseType, arguments);
    RETURN qualType;
  END NewQualType;

PROCEDURE (qualType: QualType) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    qualType.Store^(w);
    WriteType(w, qualType.baseType, qualType.srcCodeBaseType);
    w.WriteNum(LEN(qualType.arguments^));
    FOR i := 0 TO LEN(qualType.arguments^)-1 DO
      StoreTypeRef(w, qualType.arguments[i]);
    END;
  END Store;

PROCEDURE (qualType: QualType) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    i, len: LONGINT;
  BEGIN
    qualType.Load^(r);
    ReadType(r, qualType.baseType, qualType.srcCodeBaseType);
    r.ReadNum(len);
    NEW(qualType.arguments, len);
    FOR i := 0 TO len-1 DO
      LoadTypeRef(r, qualType.arguments[i]);
    END;
  END Load;

PROCEDURE (qualType: QualType) Deparam*(): Type;
  BEGIN
    RETURN qualType.baseType;
  END Deparam;


PROCEDURE InitPointer* (pointer: Pointer; parent: Item; position: Position;
                        baseType: Type);
  BEGIN
    InitType (pointer, parent, position);
    pointer. baseType := baseType;
    pointer. srcCodeBaseType := baseType;
    pointer. doCArrayAssignment := FALSE;
    pointer. isStatic := FALSE;
  END InitPointer;

PROCEDURE (pointer: Pointer) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    pointer. Store^ (w);
    WriteType(w, pointer.baseType, pointer.srcCodeBaseType);
    w. WriteBool (pointer. doCArrayAssignment);
    w. WriteBool (pointer. isStatic);
  END Store;

PROCEDURE (pointer: Pointer) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    pointer. Load^ (r);
    ReadType(r, pointer.baseType, pointer.srcCodeBaseType);
    r. ReadBool (pointer. doCArrayAssignment);
    r. ReadBool (pointer. isStatic);
  END Load;

PROCEDURE InitArray* (array: Array; parent: Item; position: Position; 
                      isOpenArray: BOOLEAN; elementType: Type;
                      lengthExpr: AST.Node);
  BEGIN
    InitType (array, parent, position);
    array. isOpenArray := isOpenArray;
    array. hasLengthInfo := TRUE;
    array. readOnlyExport := FALSE;
    array. elementType := elementType;
    array. srcCodeElementType := elementType;
    array. length := -1;
    array. lengthExpr := lengthExpr;
    array. isAtomic := FALSE;
  END InitArray;

PROCEDURE (array: Array) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    array. Store^ (w);
    w. WriteBool (array. isOpenArray);
    w. WriteBool (array. hasLengthInfo);
    w. WriteBool (array. readOnlyExport);
    WriteType(w, array.elementType, array.srcCodeElementType);
    w. WriteNum (array. length);    
    w. WriteBool (array. isAtomic);
  END Store;

PROCEDURE (array: Array) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    array. Load^ (r);
    r. ReadBool (array. isOpenArray);
    r. ReadBool (array. hasLengthInfo);
    r. ReadBool (array. readOnlyExport);
    ReadType(r, array.elementType, array.srcCodeElementType);
    r. ReadNum (array. length);
    array. lengthExpr := NIL;
    r. ReadBool (array. isAtomic);
  END Load;

PROCEDURE (array: Array) SetLength* (length: LONGINT);
  BEGIN
    array. length := length;
  END SetLength;

PROCEDURE (array: Array) GetOpenDimensions* (): LONGINT;
(**Returns the number of open dimensions for the type @oparam{array}.  Result
   is zero if the length of the array is known.  *)
  VAR
    type: Type;
    dim: LONGINT;
  BEGIN
    dim := 0;
    type := array;
    WHILE (type IS Array) & type(Array).isOpenArray DO
      INC (dim);
      type := type(Array).elementType.Deparam();
    END;
    RETURN dim
  END GetOpenDimensions;

PROCEDURE (array: Array) GetNonOpenElementType* (): Type;
(**Returns the first element type of @oparam{array} that is not an open array.  *)
  VAR
    type: Type;
  BEGIN
    type := array;
    WHILE (type IS Array) & type(Array).isOpenArray DO
      type := type(Array).elementType.Deparam();
    END;
    RETURN type
  END GetNonOpenElementType;

PROCEDURE (array: Array) GetInnermostElementType* (): Type;
(**Returns the first element type of @oparam{array} that is not an array.  *)
  VAR
    type: Type;
  BEGIN
    type := array;
    WHILE (type IS Array) DO
      type := type(Array).elementType.Deparam();
    END;
    RETURN type
  END GetInnermostElementType;

PROCEDURE (array: Array) GetNthElementType* (dim: LONGINT): Type;
(**Returns the element type of @oparam{array} for dimension @oparam{dim}.
   With @samp{dim=0}, the array type itself is returned.  *)
  VAR
    type: Type;
  BEGIN
    type := array;
    WHILE (dim > 0) DO
      type := type(Array).elementType.Deparam();
      DEC (dim);
    END;
    RETURN type;
  END GetNthElementType;


PROCEDURE InitFormalPars* (formalPars: FormalPars; parent: Item;
                           position: Position);
  BEGIN
    InitType (formalPars, parent, position);
    formalPars. receiver := NIL;
    formalPars. resultType := NIL;
    formalPars. srcCodeResultType := NIL;
    formalPars. params := NIL;
    formalPars. anyRestParameters := FALSE;
    formalPars. noReturn := FALSE;
    formalPars. callConv := callConvDefault;
    formalPars. raises := NIL;
    formalPars. ns := NIL;
  END InitFormalPars;

PROCEDURE (formalPars: FormalPars) EnableRestParameters*;
(**Sets the field @ofield{FormalPars.anyRestParameters} of @oparam{formalPars}
   to @code{TRUE}.  *)
  BEGIN
    formalPars. anyRestParameters := TRUE
  END EnableRestParameters;

PROCEDURE (formalPars: FormalPars) SetResultType*(resultType: Type);
  BEGIN
    formalPars.resultType := resultType;
    formalPars.srcCodeResultType := resultType;
  END SetResultType;

PROCEDURE (formalPars: FormalPars) SetNamespace* (ns: Namespace);
(**Sets the field @ofield{FormalPars.ns} of @oparam{formalPars} to
   @oparam{ns}.  *)
  BEGIN
    formalPars. ns := ns;
  END SetNamespace;

PROCEDURE (formalPars: FormalPars) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    formalPars. Store^ (w);
    w. WriteObject (formalPars. receiver);
    WriteType(w, formalPars.resultType, formalPars.srcCodeResultType);
    w. WriteBool (formalPars. anyRestParameters);
    w. WriteBool (formalPars. noReturn);
    w. WriteSInt (formalPars. callConv);
    IF (formalPars. raises = NIL) THEN
      w. WriteNum (-1)
    ELSE
      w. WriteNum (LEN (formalPars. raises^));
      FOR i := 0 TO LEN (formalPars. raises^)-1 DO
        w. WriteObject (formalPars. raises[i])
      END
    END;
    (* ignore field `ns' *)
  END Store;

PROCEDURE (formalPars: FormalPars) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
    len, i: LONGINT;
  BEGIN
    formalPars. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      formalPars. receiver := NIL
    ELSE
      formalPars. receiver := obj(VarDecl)
    END;
    ReadType(r, formalPars.resultType, formalPars.srcCodeResultType);
    formalPars. params := NIL;
    r. ReadBool (formalPars. anyRestParameters);
    r. ReadBool (formalPars. noReturn);
    r. ReadSInt (formalPars. callConv);
    
    r. ReadNum (len);
    IF (len < 0) THEN
      formalPars. raises := NIL
    ELSE
      NEW (formalPars. raises, len);
      FOR i := 0 TO len-1 DO
        r. ReadObject (obj);
        formalPars. raises[i] := obj(ExceptionName)
      END
    END;
    formalPars. ns := NIL;
  END Load;


PROCEDURE InitTypeClosure(tc: TypeClosure; position: Position;
                          baseType: Type;
                          params: TypeVarArray;
                          arguments: TypeRefArray);
  BEGIN
    ASSERT(LEN(params^) = LEN(arguments^));
    InitType(tc, NIL, position);
    tc.baseType := baseType;
    tc.params := params;
    tc.arguments := arguments;
    IF (baseType # NIL) THEN
      tc.size := baseType.size;
      tc.align := baseType.align;
    ELSE
      tc.size := -1;
      tc.align := -1;
    END;
  END InitTypeClosure;

PROCEDURE NewTypeClosure*(position: Position; baseType: Type;
                          params: TypeVarArray;
                          arguments: TypeRefArray): TypeClosure;
  VAR
    tc: TypeClosure;
  BEGIN
    NEW(tc);
    InitTypeClosure(tc, position, baseType, params, arguments);
    RETURN tc;
  END NewTypeClosure;

PROCEDURE (typeClosure: TypeClosure) Deparam*(): Type;
  BEGIN
    RETURN typeClosure.baseType;
  END Deparam;

PROCEDURE (typeClosure: TypeClosure) Lookup*(tv, default: TypeVar): Type;
(**If @oparam{tv} is bound in @oparam{typeClosure}, then return the value it is
   bound to.  Otherwise, return @oparam{default}.  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT(LEN(typeClosure.params^) = LEN(typeClosure.arguments^));
    i := 0;
    WHILE (i # LEN(typeClosure.params^)) & (typeClosure.params[i] # tv)  DO
      INC(i);
    END;
    IF (i = LEN(typeClosure.params^)) THEN
      (* variable is unbound in the given context, for example because it is
         a variable of the class definition appearing in a variable declaration
         of a method of the class *)
      RETURN default;
    ELSE
      RETURN typeClosure.arguments[i].type;
    END;
  END Lookup;

PROCEDURE (closure: TypeClosure) Closure*(type: Type): Type;
  VAR
    i: LONGINT;
    args: TypeRefArray;
    nextType: Type;
  BEGIN
    IF (type = NIL) THEN
      (* pathological closure used for void function, record base types, etc *)
      RETURN NIL;
    END;
    
    LOOP
      WITH type: QualType DO
        ASSERT(LEN(type.arguments^) = LEN(type.baseType.typePars.params^));
        NEW(args, LEN(type.baseType.typePars.params^));
        FOR i := 0 TO LEN(args^)-1 DO
          InitTypeRef(args[i], closure.Closure(type.arguments[i].type));
        END;
        closure := NewTypeClosure(type.position, NIL,
                                  type.baseType.typePars.params, args);
        nextType := type.baseType;
        
      | type: TypeVar DO
        nextType := closure.Lookup(type, NIL);
        IF (nextType = NIL) THEN
          RETURN type;
        ELSE
          closure := emptyClosure;
        END;
        
      ELSE
        IF (type.typePars = NIL) THEN
          (* no type variables in this type, and it is not a qualified type *)
          RETURN type;
        ELSE
          EXIT;
        END;
      END;
      type := nextType;
    END;
    RETURN NewTypeClosure(closure.position, type,
                          closure.params, closure.arguments);
  END Closure;

PROCEDURE (closure: TypeClosure) ArgumentsInduced*(type: Type): BOOLEAN;
(**Return @code{TRUE} if the type arguments of @oparam{closure} are fully
   induced by the type arguments of @oparam{type}.  That is, given a variable
   of type @oparam{type}, all type arguments of @oparam{closure} are defined
   if @oparam{closure} is an extension of @oparam{type}.  *)
  VAR
    i, j: LONGINT;
  BEGIN
    IF (type = NIL) THEN
      RETURN (LEN(closure.arguments^) = 0);
    ELSE
      WITH type: QualType DO
        FOR i := 0 TO LEN(closure.params^)-1 DO
          j := 0;
          WHILE (j # LEN(type.arguments^)) &
                (type.arguments[j].type # closure.params[i]) DO
            INC(j);
          END;
          IF (j = LEN(type.arguments^)) THEN
            RETURN FALSE;
          END;
        END;
        RETURN TRUE;
      ELSE
        RETURN (LEN(closure.arguments^) = 0);
      END;
    END;
  END ArgumentsInduced;

(*PROCEDURE (typeClosure: TypeClosure) Log*();
  VAR
    i: LONGINT;
  BEGIN
    Log.Ln;
    Log.Msg("TypeClosure");
    FOR i := 0 TO LEN(typeClosure.params^)-1 DO
      Log.LongInt("pos", i);
      Log.Ptr("  param.adr", typeClosure.params[i]);
      Log.LongInt("  param.pos", typeClosure.params[i].position.pos);
      Log.Msg("  --->");
      Log.Type("  arg.type", typeClosure.arguments[i].type);
      Log.Ptr("  arg.adr", typeClosure.arguments[i].type);
      IF (typeClosure.arguments[i].type IS TypeVar) THEN
        Log.LongInt("  arg.pos", typeClosure.arguments[i].type.position.pos);
      END;
      IF (typeClosure.arguments[i].type.namingDecl # NIL) THEN
        Log.String("  arg.name", typeClosure.arguments[i].type.namingDecl.name.str^);
      END;
    END;
  END Log;*)

PROCEDURE Expand*(type: Type): Type;
(**@precond
   The type @oparam{type} contains unbound type variables that need to be bound
   to a particular value in the current context.
   @end precond

   @postcond
   The result is not an instance of @otype{QualType}.  If the result is a
   @samp{TypeClosure}, then this statement holds for the expression's base
   type.
   @end postcond  *)
  BEGIN
    RETURN emptyClosure.Closure(type);
  END Expand;



PROCEDURE (item: Item) Namespace* (): Namespace;
(**Returns the namespace instance associated with @oparam{item}.
   If @oparam{item} has no namespace, that is, if it is no module, procedure,
   or record, the result is @code{NIL}.  *)
  BEGIN
    RETURN NIL
  END Namespace;

PROCEDURE (item: Module) Namespace* (): Namespace;
  BEGIN
    RETURN item. ns
  END Namespace;

PROCEDURE (item: ProcDecl) Namespace* (): Namespace;
  BEGIN
    RETURN item. ns
  END Namespace;

PROCEDURE (item: FormalPars) Namespace* (): Namespace;
  BEGIN
    RETURN item. ns
  END Namespace;

PROCEDURE (item: Record) Namespace* (): Namespace;
  BEGIN
    RETURN item. ns
  END Namespace;

PROCEDURE (item: TypePars) Namespace* (): Namespace;
  BEGIN
    RETURN item. ns
  END Namespace;

PROCEDURE (item: QualType) Namespace* (): Namespace;
  BEGIN
    RETURN item.baseType.Namespace();
  END Namespace;


PROCEDURE Prune* (root: Module; keep: Exports);
(**Eliminates all items from the symbol table @oparam{root}, that do not
   appear as a key in @oparam{keep}.  Pruned imports are added to
   @ofield{root.prunedImports}.  *)
  VAR
    prunedImports: ArrayList.ArrayList;
    mr: ModuleRef;
    import: Import;
    i: LONGINT;
    
  PROCEDURE PruneList (VAR list, last: Item);
    VAR
      this : Item;
    BEGIN
      this := list; last := NIL; list := NIL;
      WHILE this # NIL DO
        IF keep. HasKey (this) THEN
          PruneList (this. nestedItems, this. tailNestedItems);
          (* append "this" to end of "list" *)
          IF last = NIL THEN
            list := this;
          ELSE
            last.nextNested := this;
          END;
          last := this;
        ELSE
          IF (this IS Import) & ~this(Import).IsInternalImport() THEN
            prunedImports.Append(this);
          END;
        END;
        this := this.nextNested;
      END;
      (* terminate the list *)
      IF last # NIL THEN last.nextNested := NIL END;
    END PruneList;
  
  BEGIN
    prunedImports := ArrayList.New(8);
    PruneList (root. nestedItems, root. tailNestedItems);
    NEW(root.prunedImports, prunedImports.size);
    FOR i := 0 TO prunedImports.size-1 DO
      import := prunedImports.array[i](Import);
      NEW(mr);
      mr.name := import.moduleName.str;
      mr.fingerprint := import.fingerprint;
      root.prunedImports[i] := mr;
    END;
  END Prune;

PROCEDURE (decl: Declaration) GetId*(): NameString;
(**For the given declaration, return its id string.  The id is unique within
   the module.  It is created by concatenating the declaration's identifier to
   the id string of the declaration context.  For example, given a parameter
   @samp{foo} in a top-level procedure @samp{Bar}, the id string would be
   @samp{Bar.foo}.  *)
  VAR
    id: NameString;
    declWithType: Declaration;
    parent, ptr: Item;
    
  PROCEDURE GetContainer (type: Type): Declaration;
    VAR
      ptr: Item;
      found: BOOLEAN;
    
    PROCEDURE Contains (ptr, type: Item): BOOLEAN;
      BEGIN
        IF (ptr = type) THEN
          RETURN TRUE
        ELSE
          WITH ptr: Pointer DO
            RETURN Contains (ptr. srcCodeBaseType, type)
          | ptr: Array DO
            RETURN Contains (ptr. srcCodeElementType, type)
          ELSE
            RETURN FALSE
          END
        END
      END Contains;
    
    BEGIN
      ASSERT ((type IS Record) OR (type IS FormalPars));
      IF (type IS FormalPars) & (type. parent IS ProcDecl) THEN
        RETURN type. parent(ProcDecl)
      ELSE
        ptr := type. parent;
        IF (ptr IS TypePars) THEN
          ptr := ptr.parent;
        END;
      END;
      ASSERT ((ptr IS Module) OR
              (ptr IS ProcDecl) OR
              (ptr IS Record) OR
              (ptr IS FormalPars));
      found := FALSE;
      ptr := ptr. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: VarDecl DO
          found := Contains (ptr. srcCodeType, type)
        | ptr: TypeDecl DO
          found := Contains (ptr. srcCodeType, type)
        | ptr: ProcDecl DO
          found := Contains (ptr. formalPars, type)
        | ptr: FieldDecl DO
          found := Contains (ptr. srcCodeType, type)
        ELSE
          found := FALSE
        END;
        IF found THEN
          RETURN ptr(Declaration)
        END;
        ptr := ptr. nextNested
      END;
      ASSERT (FALSE)
    END GetContainer;
  
  PROCEDURE Concat (a, b: NameString): NameString;
    VAR
      n: NameString;
    BEGIN
      IF (a^ = "") THEN
        RETURN b
      ELSE
        NEW (n, Strings.Length (a^)+Strings.Length (b^)+2);
        COPY (a^, n^);
        Strings.Append (".", n^);
        Strings.Append (b^, n^);
        RETURN n
      END
    END Concat;
  
  BEGIN
    IF (decl. cachedId # NIL) THEN
      RETURN decl. cachedId
    ELSE
      IF (decl IS Module) THEN           (* module id is the empty string *)
        NEW (id, 1);
        id[0] := 0X
      ELSIF (decl IS ProcDecl) & decl(ProcDecl).IsTypeBound() THEN
        (* for a type-bound procedure, the id the that of the record 
           type concatenated with the procedure name *)
        declWithType := GetContainer (decl(ProcDecl). Class());
        id := Concat (declWithType. GetId(), decl. name. str)
      ELSIF (decl IS FieldDecl) THEN
        (* find the nearest declaration that contains this field,
           and use its id as prefix *)
        declWithType := GetContainer (decl(FieldDecl). parent(Record));
        id := Concat (declWithType. GetId(), decl. name. str)
      ELSIF (decl IS VarDecl) & decl(VarDecl). isParameter THEN
        (* find the nearest declaration that contains this parameter,
           and use its id as prefix *)
        declWithType := GetContainer (decl(VarDecl). parent(FormalPars));
        id := Concat (declWithType. GetId(), decl. name. str)
      ELSIF (decl IS TypeDecl) & decl(TypeDecl).IsTypeParameter() THEN
        (* find the type declaration that has `decl.parent' as formal type
           parameter list, and use its id as prefix *)
        ptr := decl(TypeDecl).ParametricType();
        id := Concat(ptr(TypeDecl).GetId(), decl.name.str);
      ELSE
        parent := decl.parent;
        WHILE ~(parent IS Declaration) DO
          parent := parent.parent;
        END;
        id := Concat (parent(Declaration).GetId(), decl.name.str);
      END;
      decl. cachedId := id;
      RETURN id
    END
  END GetId;

PROCEDURE (decl: Declaration) GetEmbeddedNamespace* (followTypeNames: BOOLEAN): Namespace;
(**Returns the first logical namespace occuring in the definition of
   declaration @oparam{decl}.  This method is used to resolve reference
   commands embedded in documentation text.  *)
   
  PROCEDURE NamespaceOfType (type, srcType: Type): Namespace;
    BEGIN
      IF ~followTypeNames & (srcType IS TypeName) THEN
        RETURN NIL
      ELSE
        (* this will get into an endless loop for recursive array types; but
           who needs those freaks anyway?  *)
        WITH type: PredefType DO
          RETURN NIL
        | type: TypeName DO
          RETURN NIL;   (* should never happen in a correct program *)
        | type: Pointer DO
          RETURN NamespaceOfType (type. baseType, type. srcCodeBaseType)
        | type: FormalPars DO
          RETURN NIL                    (* procedure types have no namespace *)
        | type: Array DO
          RETURN NamespaceOfType (type. elementType, type. srcCodeElementType)
        | type: Record DO
          RETURN type. ns
        | type: TypeVar DO
          RETURN NamespaceOfType (type. bound, srcType)
        | type: QualType DO
          RETURN NamespaceOfType (type. baseType, type. srcCodeBaseType)
        END
      END
    END NamespaceOfType;
  
  BEGIN
    WITH decl: Module DO
      RETURN decl. ns
    | decl: Import DO
      RETURN decl. externalSymTab. ns
    | decl: ProcDecl DO
      RETURN decl. ns
    | decl: ConstDecl DO
      RETURN NIL
    | decl: PredefProc DO
      RETURN NIL
    | decl: VarDecl DO
      RETURN NamespaceOfType (decl. type, decl. srcCodeType)
    | decl: FieldDecl DO
      RETURN NamespaceOfType (decl. type, decl. srcCodeType)
    | decl: TypeDecl DO
      RETURN NamespaceOfType (decl. type, decl. srcCodeType)
    | decl: Redirect DO
      RETURN NIL
    END
  END GetEmbeddedNamespace;

PROCEDURE Init();
  VAR
    params: TypeVarArray;
    arguments: TypeRefArray;
    nameString: NameString;
  BEGIN
    URI.RegisterScheme(File.NewPrototype());
    
    predefIdToType := NIL;
    emptyBaseURI := File.ToURI("/");
    NEW (importPosition);
    InitPosition (importPosition, posImportedName, -1, -1);
    
    NEW(params, 0);
    NEW(arguments, 0);
    NEW(emptyClosure);
    InitTypeClosure(emptyClosure, NIL, NIL, params, arguments);

    NEW(nameString, 1);
    COPY("", nameString^);
    NEW(predefName);
    InitName(predefName, nameString, 0, 0, 0);
  END Init;

BEGIN
  Init;
END OOC:SymbolTable.
