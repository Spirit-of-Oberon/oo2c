MODULE OOC:C:ConvertDecl;

IMPORT
  ADT:String, ADT:Dictionary, 
  OOC:Repository, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:C:Naming, OOC:C:DeclWriter;


CONST
  modeWriteExported = 0;
  modeWritePrivate = 1;
  modeWriteFctDef = 2;
  modeFormalParameter = 3;


PROCEDURE ^ ConvertDecl (w: DeclWriter.Writer;
                         item: Sym.Declaration;
                         mode: SHORTINT): DeclWriter.Declaration;

PROCEDURE ConvertType (w: DeclWriter.Writer;
                       resolvedType, type: Sym.Type): DeclWriter.Type;
  VAR
x:String.String;
    ptr: Sym.Item;
    fct: DeclWriter.Function;
    struct: DeclWriter.Struct;

  PROCEDURE ConvertParam (fct: DeclWriter.Function; param: Sym.VarDecl);
    VAR
      decl: DeclWriter.Declaration;

    PROCEDURE AddArrayLength (type: Sym.Type; dim: LONGINT);
      VAR
        length: DeclWriter.Declaration;
      BEGIN
        IF (type IS Sym.Array) & type(Sym.Array). isOpenArray THEN
          length := w. NewDeclaration (Naming.NameOfLengthParam (param, dim),
                                       DeclWriter.tqNone,
                                       DeclWriter.scAuto,
                                       w. basicType[DeclWriter.lengthType]);
          fct. AddParameter (length);

          AddArrayLength (type(Sym.Array). elementType, dim+1)
        END;
      END AddArrayLength;

    BEGIN
      decl := ConvertDecl (w, param, modeFormalParameter);
      fct. AddParameter (decl);
      AddArrayLength (param. type, 0);
    END ConvertParam;

  BEGIN
    IF (type = NIL) THEN
      RETURN w. basicType[DeclWriter.void]
    ELSE
      WITH type: Sym.PredefType DO
        CASE type. id OF
        | Predef.boolean:
          RETURN w. basicType[DeclWriter.char8]
        | Predef.char:
          RETURN w. basicType[DeclWriter.char8]
        | Predef.longchar:
          RETURN w. basicType[DeclWriter.char16]
        | Predef.shortint:
          RETURN w. basicType[DeclWriter.int8]
        | Predef.integer:
          RETURN w. basicType[DeclWriter.int16]
        | Predef.longint:
          RETURN w. basicType[DeclWriter.int32]
        | Predef.real:
          RETURN w. basicType[DeclWriter.real32]
        | Predef.longreal:
          RETURN w. basicType[DeclWriter.real64]
        | Predef.set:
          RETURN w. basicType[DeclWriter.uint32]

        | Predef.address:
          RETURN w. basicType[DeclWriter.int32]
        | Predef.byte:
          RETURN w. basicType[DeclWriter.char8]
        | Predef.ptr:
          RETURN w. basicType[DeclWriter.ptr]
        END

        (* nothing *)
      | type: Sym.TypeName DO
        WITH resolvedType: Sym.PredefType DO
          RETURN ConvertType (w, resolvedType, resolvedType);
        ELSE
          x := Naming.NameOfType (resolvedType);
          ASSERT (x.array[0]#"#");
          RETURN w. NewTypeRef (DeclWriter.refTypedef,
                                Naming.NameOfType (resolvedType));
        END;
        
      | type: Sym.Pointer DO
        ASSERT (FALSE);
        (*ConvertType (type. srcCodeBaseType);*)
        
      | type: Sym.FormalPars DO
        fct := w. NewFunction (ConvertType (w, type. resultType, type. srcCodeResultType));
        IF (type. receiver # NIL) THEN
          ConvertParam (fct, type. receiver)
        END;
        ptr := type. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Sym.Declaration DO
            ConvertParam (fct, ptr(Sym.VarDecl))
          ELSE                     (* ignore non-declarations *)
          END;
          ptr := ptr. nextNested
        END;
        RETURN fct;
        
      | type: Sym.Array DO
        IF type. isOpenArray THEN
          RETURN w. NewArray (ConvertType (w, type. elementType, type. srcCodeElementType), -1)
        ELSE
          RETURN w. NewArray (ConvertType (w, type. elementType, type. srcCodeElementType), type. length)
        END;
          
      | type: Sym.Record DO
        ASSERT (type. baseType = NIL);
        
        struct := w. NewStruct (type. isUnion);
        ptr := type. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Sym.FieldDecl DO
            struct. AddMember (ConvertDecl (w, ptr, modeFormalParameter));
          ELSE                     (* ignore non-declarations *)
          END;
          ptr := ptr. nextNested
        END;
        RETURN struct
      END
    END
  END ConvertType;

PROCEDURE ConvertDecl (w: DeclWriter.Writer;
                       item: Sym.Declaration;
                       mode: SHORTINT): DeclWriter.Declaration;
  VAR
    sc: DeclWriter.StorageClass;
    name: String.String;
    ctype: DeclWriter.Type;
  BEGIN
    WITH item: Sym.ProcDecl DO
      CASE mode OF
      | modeWriteExported:
        sc := DeclWriter.scExtern
      | modeWritePrivate:
        sc := DeclWriter.scStatic
      | modeWriteFctDef:
        IF (item. exportMark = Sym.nameNotExported) THEN
          sc := DeclWriter.scStatic
        ELSE
          sc := DeclWriter.scAuto
        END
      END;
      RETURN w. NewDeclaration
        (Naming.NameOfDeclaration (item), DeclWriter.tqNone, sc,
         ConvertType (w, item. formalPars, item. formalPars));

    | item: Sym.ConstDecl DO
      IF (item. value # NIL) THEN
        RETURN w. NewDefine (Naming.NameOfDeclaration (item),
                             item. value);
      END;
      
    | item: Sym.VarDecl DO
      IF item. isParameter THEN
        sc := DeclWriter.scAuto
      ELSE
        IF (mode = modeWriteExported) THEN
          sc := DeclWriter.scExtern
        ELSIF (item. exportMark = Sym.nameNotExported) &
              (item. parent IS Sym.Module) THEN
          sc := DeclWriter.scStatic
        ELSE
          sc := DeclWriter.scAuto
        END
      END;

      name := Naming.NameOfDeclaration (item);
      ctype := ConvertType (w, item. type, item. srcCodeType);
      IF (mode = modeFormalParameter) & item. isParameter THEN
        IF ~item. isVarParam & item. isPassPerReference THEN
          (* for non-scalar values that are passed to a value parameter, the
             name of the address passed from the caller is extended; this way,
             it can be distinguished from the name of the local copy of the
             value parameter *)
          name := name. Concat (String.New (Naming.suffixPassPerRef))
        END;

        IF item. isPassPerReference & ~(item. type IS Sym.Array) THEN
          (* for pass-by-reference arguments, turn the argument type into
             a pointer; C arrays are already pointers, so we skip this for
             array type *)
          ctype := w. NewPointer (DeclWriter.tqNone, ctype);
        END;
      END;
      
      RETURN w. NewDeclaration (name, DeclWriter.tqNone, sc, ctype)

    | item: Sym.FieldDecl DO
      RETURN w. NewDeclaration
          (Naming.NameOfDeclaration (item),
           DeclWriter.tqNone,
           DeclWriter.scMember,
           ConvertType (w, item. type, item. srcCodeType));
      
    | item: Sym.TypeDecl DO
      RETURN w. NewDeclaration (Naming.NameOfDeclaration (item),
                                DeclWriter.tqNone,
                                DeclWriter.scTypedef,
                                ConvertType (w, item. type, item. srcCodeType))
    END
  END ConvertDecl;

PROCEDURE ConvertSymTab* (w: DeclWriter.Writer; m: Repository.Module;
                          symTab: Sym.Module; exports: Dictionary.Dictionary;
                          writeExported: BOOLEAN);
(**Translates all declarations of the module to C.  The C declarations are
   emitted to the writer object @oparam{w}.  The parameter @oparam{m}
   identifies the repository entry of the current module.

   The procedure supports two different modes of operations: writing the public
   interface of a module, and writing the complement to the public interface.
   The set of emitted declarations is selected by @oparam{writeExported}.  With
   @samp{@oparam{writeExported}=@code{TRUE}}, all items in @oparam{exports} are
   written.  Otherwise, all items @emph{not} in @oparam{exports} are emitted.  *)
  VAR
    mode: SHORTINT;
      
  PROCEDURE ConvertTopLevel (root: Sym.Item; m: Repository.Module;
                             mode: SHORTINT);
    VAR
      ptr: Sym.Item;
      decl: DeclWriter.Declaration;
    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Sym.Declaration DO
          IF (exports. HasKey (ptr) = (mode = modeWriteExported)) THEN
            WITH ptr: Sym.Import DO
              decl := w. NewIncludeModule
                  (m. GetImport (ptr. moduleName. str^));
            ELSE
              decl := ConvertDecl (w, ptr, mode)
            END;
            w. AddDeclaration (decl)
          END
        ELSE                               (* ignore non-declarations *)
        END;
        ptr := ptr. nextNested
      END
    END ConvertTopLevel;
  
  BEGIN
    IF writeExported THEN
      mode := modeWriteExported
    ELSE
      mode := modeWritePrivate
    END;
    ConvertTopLevel (symTab, m, mode);

    IF writeExported THEN
      w. AddDeclaration
          (w. NewDeclaration
           (Naming.NameOfModuleInit (m),
            DeclWriter.tqNone,
            DeclWriter.scExtern, 
            w. NewFunction (w. basicType[DeclWriter.void])))
    END;
  END ConvertSymTab;

PROCEDURE GetProc* (w: DeclWriter.Writer;
                    procDecl: Sym.ProcDecl): DeclWriter.Declaration;
(**Creates the header of a C function definition matching the procedure
   declaration @oparam{procDecl}.  The declaration instance is created using
   the factory methods of @oparam{w}.  *)
  BEGIN
    RETURN ConvertDecl (w, procDecl, modeWriteFctDef)
  END GetProc;

PROCEDURE GetDecl* (w: DeclWriter.Writer;
                    decl: Sym.Declaration): DeclWriter.Declaration;
(**Creates a C declaration for the object @oparam{decl}.  *)
  BEGIN
    RETURN ConvertDecl (w, decl, modeWriteFctDef)
  END GetDecl;

PROCEDURE GetTypeRef* (w: DeclWriter.Writer;
                       type: Sym.Type): DeclWriter.Type;
(**Creates a C type expression for the object @oparam{type}.  *)
  BEGIN
    IF (type. namingDecl # NIL) & ~(type IS Sym.PredefType) THEN
      RETURN w. NewTypeRef (DeclWriter.refTypedef,
                            Naming.NameOfType (type));
    ELSE
      RETURN ConvertType (w, type, type);
    END;
  END GetTypeRef;

PROCEDURE GetPointerDecl* (w: DeclWriter.Writer;
                           paramDecl: Sym.VarDecl): DeclWriter.Declaration;
(**Produces a declaration that defines a pointer either to the element type of
   @oparam{paramDecl} (if it is an array), or a pointer to the type of
   @oparam{paramDecl} (otherwise).  *)
  VAR
    elemType: Sym.Type;
  BEGIN
    IF (paramDecl. type IS Sym.Array) THEN
      elemType := paramDecl. type(Sym.Array). GetNonOpenElementType();
    ELSE
      elemType := paramDecl. type;
    END;
    
    RETURN w. NewDeclaration
        (Naming.NameOfDeclaration (paramDecl),
         DeclWriter.tqNone,
         DeclWriter.scAuto,
         w. NewPointer (DeclWriter.tqNone, GetTypeRef (w, elemType)));
  END GetPointerDecl;

END OOC:C:ConvertDecl.
