MODULE OOC:C:ConvertDecl;

IMPORT
  ADT:Dictionary, 
  OOC:Repository, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:C:Naming, OOC:C:DeclWriter;


CONST
  modeWriteExported = 0;
  modeWritePrivate = 1;
  modeWriteFctDef = 2;


TYPE
  Converter* = POINTER TO ConverterDesc;
  ConverterDesc = RECORD
    m: Repository.Module;
    symTab: Sym.Module;
    exports: Dictionary.Dictionary;
    mode: SHORTINT;
    w: DeclWriter.Writer;
  END;

PROCEDURE InitConverter (c: Converter;
                         m: Repository.Module;
                         symTab: Sym.Module;
                         exports: Dictionary.Dictionary);
  BEGIN
    c. m := m;
    c. w := NIL;
    c. symTab := symTab;
    c. exports := exports;
    c. mode := modeWritePrivate;
  END InitConverter;

PROCEDURE NewConverter* (m: Repository.Module;
                         symTab: Sym.Module;
                         exports: Dictionary.Dictionary): Converter;
(**Creates a converter to transform the declarations in the symbol table
   @oparam{symTab} of the module @oparam{m} into a series of C declarations. *)
  VAR
    c: Converter;
  BEGIN
    NEW (c);
    InitConverter (c, m, symTab, exports);
    RETURN c
  END NewConverter;


PROCEDURE ConvertDecl (c: Converter; item: Sym.Declaration): DeclWriter.Declaration;
  VAR
    sc: DeclWriter.StorageClass;

  PROCEDURE ConvertType (resolvedType, type: Sym.Type): DeclWriter.Type;
    VAR
      ptr: Sym.Item;
      fct: DeclWriter.Function;
(*          decl: Sym.Declaration;*)
    BEGIN
      IF (type = NIL) THEN
        RETURN c. w. basicType[DeclWriter.void]
      ELSE
        WITH type: Sym.PredefType DO
          CASE type. id OF
          | Predef.boolean:
            RETURN c. w. basicType[DeclWriter.char8]
          | Predef.char:
            RETURN c. w. basicType[DeclWriter.char8]
          | Predef.longchar:
            RETURN c. w. basicType[DeclWriter.char16]
          | Predef.shortint:
            RETURN c. w. basicType[DeclWriter.int8]
          | Predef.integer:
            RETURN c. w. basicType[DeclWriter.int16]
          | Predef.longint:
            RETURN c. w. basicType[DeclWriter.int32]
          | Predef.real:
            RETURN c. w. basicType[DeclWriter.real32]
          | Predef.longreal:
            RETURN c. w. basicType[DeclWriter.real64]
          | Predef.set:
            RETURN c. w. basicType[DeclWriter.uint32]

          | Predef.address:
            RETURN c. w. basicType[DeclWriter.int32]
          | Predef.byte:
            RETURN c. w. basicType[DeclWriter.char8]
          | Predef.ptr:
            RETURN c. w. basicType[DeclWriter.ptr]
          END

          (* nothing *)
        | type: Sym.TypeName DO
          IF (type. module = NIL) THEN
            RETURN ConvertType (resolvedType, resolvedType)
          ELSE
            ASSERT (FALSE);
          END;
(*              IF (type. module = NIL) THEN
            decl := module. ns. IdentifyLocal (root, type. ident, TRUE)
            (* this may be NIL if we are looking at the name of a
               predefined type; in this case, we are done *)
          ELSE
            decl := module. ns. IdentifyLocal (root, type. module, TRUE);
            ASSERT (decl # NIL)
          END;
          IF (decl # NIL) THEN
            ConvertDecl (decl)
          END*)

        | type: Sym.Pointer DO
          ASSERT (FALSE)
(*              ConvertType (type. srcCodeBaseType)*)
        | type: Sym.FormalPars DO
          fct := c. w. NewFunction (ConvertType (type. resultType, type. srcCodeResultType));
          IF (type. receiver # NIL) THEN
            fct. AddParameter (ConvertDecl (c, type. receiver))
          END;
          ptr := type. nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Sym.Declaration DO
              fct. AddParameter (ConvertDecl (c, ptr))
            ELSE                     (* ignore non-declarations *)
            END;
            ptr := ptr. nextNested
          END;
          RETURN fct

        | type: Sym.Array DO
          ASSERT (type. isOpenArray);
          RETURN c. w. NewArray (ConvertType (type. elementType, type. srcCodeElementType), -1)
(*              ConvertType (type. srcCodeElementType)*)
        | type: Sym.Record DO
          ASSERT (FALSE)
(*              IF (type. srcCodeBaseType # NIL) THEN
            ConvertType (type. srcCodeBaseType)
          END;
          ConvertList (type)*)
        END
      END
    END ConvertType;

  BEGIN  (* pre: (exports. HasKey (ptr) = writeExported) *)
    WITH item: Sym.Import DO
      RETURN c. w. NewIncludeModule (c. m. GetImport (item. moduleName. str^));
      
    | item: Sym.ProcDecl DO
      CASE c. mode OF
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
      RETURN c. w. NewDeclaration
        (Naming.NameOfDeclaration (item), DeclWriter.tqNone, sc,
         ConvertType (item. formalPars, item. formalPars));

    | item: Sym.ConstDecl DO
      ASSERT (FALSE);

    | item: Sym.VarDecl DO
      IF item. isParameter THEN
        sc := DeclWriter.scAuto
      ELSE
        IF (c. mode = modeWriteExported) THEN
          sc := DeclWriter.scExtern
        ELSIF (item. exportMark = Sym.nameNotExported) &
              (item. parent IS Sym.Module) THEN
          sc := DeclWriter.scStatic
        ELSE
          sc := DeclWriter.scAuto
        END
      END;

      RETURN c. w. NewDeclaration
        (Naming.NameOfDeclaration (item), DeclWriter.tqNone, sc,
         ConvertType (item. type, item. srcCodeType))

    | item: Sym.FieldDecl DO
      ASSERT (FALSE);
(*          ConvertType (item. srcCodeType)*)

    | item: Sym.TypeDecl DO
      ASSERT (FALSE);
(*          ConvertType (item. srcCodeType)*)
    END
  END ConvertDecl;

PROCEDURE ConvertList (c: Converter; root: Sym.Item);
  VAR
    ptr: Sym.Item;
  BEGIN
    ptr := root. nestedItems;
    WHILE (ptr # NIL) DO
      WITH ptr: Sym.Declaration DO
        IF (c. exports. HasKey (ptr) = (c. mode = modeWriteExported)) THEN
          c. w. AddDeclaration (ConvertDecl (c, ptr))
        END
      ELSE                               (* ignore non-declarations *)
      END;
      ptr := ptr. nextNested
    END
  END ConvertList;

PROCEDURE (c: Converter) ConvertSymTab* (w: DeclWriter.Writer; writeExported: BOOLEAN);
(**Translates all declarations of the module to C.  The C declarations are
   emitted into the block object @oparam{b}.

   The procedure supports two different modes of operations: writing the public
   interface of a module, and writing the complement to the public interface.
   The set of emitted declarations is selected by
   @oparam{NewConverter.exports}.  With
   @samp{@oparam{writeExported}=@code{TRUE}}, all items in
   @oparam{NewConverter.exports} are written.  Otherwise, all items @emph{not}
   in @oparam{NewConverter.exports} are emitted.  *)
  BEGIN
    c. w := w;
    IF writeExported THEN
      c. mode := modeWriteExported
    ELSE
      c. mode := modeWritePrivate
    END;
    ConvertList (c, c. symTab);

    IF writeExported THEN
      c. w. AddDeclaration
          (c. w. NewDeclaration
           (Naming.NameOfModuleInit (c. m),
            DeclWriter.tqNone,
            DeclWriter.scExtern, 
            c. w. NewFunction (c. w. basicType[DeclWriter.void])))
    END;
  END ConvertSymTab;

PROCEDURE (c: Converter) ConvertProc* (w: DeclWriter.Writer; procDecl: Sym.ProcDecl): DeclWriter.Declaration;
(**Creates the header of a C function definition matching the procedure
   declaration @oparam{procDecl}.  The declaration instance is created using
   the factory methods of @oparam{b}.  *)
  BEGIN
    c. w := w;
    c. mode := modeWriteFctDef;
    RETURN ConvertDecl (c, procDecl)
  END ConvertProc;

PROCEDURE (c: Converter) ConvertDecl* (w: DeclWriter.Writer; decl: Sym.Declaration): DeclWriter.Declaration;
(**Creates a C declaration for the object @oparam{decl}.  *)
  BEGIN
    c. w := w;
    c. mode := modeWriteFctDef;
    RETURN ConvertDecl (c, decl)
  END ConvertDecl;

END OOC:C:ConvertDecl.
