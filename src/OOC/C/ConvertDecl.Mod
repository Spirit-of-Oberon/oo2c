MODULE OOC:C:ConvertDecl;

IMPORT
Log,OOC:SymbolTable:Item:XML,StdChannels,
  ADT:Dictionary, 
  OOC:Repository, OOC:SymbolTable:Item, OOC:SymbolTable:Predef,
  OOC:C:Naming, OOC:C:WriteDecl;


CONST
  modeWriteExported = 0;
  modeWritePrivate = 1;
  modeWriteFctDef = 2;


TYPE
  Converter* = POINTER TO ConverterDesc;
  ConverterDesc = RECORD
    m: Repository.Module;
    symTab: Item.Module;
    exports: Dictionary.Dictionary;
    mode: SHORTINT;
    b: WriteDecl.Block;
  END;

PROCEDURE InitConverter (c: Converter;
                         m: Repository.Module;
                         symTab: Item.Module;
                         exports: Dictionary.Dictionary);
  BEGIN
    c. m := m;
    c. b := NIL;
    c. symTab := symTab;
    c. exports := exports;
    c. mode := modeWritePrivate;
  END InitConverter;

PROCEDURE NewConverter* (m: Repository.Module;
                         symTab: Item.Module;
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


PROCEDURE ConvertDecl (c: Converter; item: Item.Declaration): WriteDecl.Declaration;
  VAR
    sc: WriteDecl.StorageClass;

  PROCEDURE ConvertType (resolvedType, type: Item.Type): WriteDecl.Type;
    VAR
      ptr: Item.Item;
      fct: WriteDecl.Function;
(*          decl: Item.Declaration;*)
    BEGIN
      IF (type = NIL) THEN
        RETURN WriteDecl.basicType[WriteDecl.void]
      ELSE
        WITH type: Item.PredefType DO
          CASE type. id OF
          | Predef.boolean:
            RETURN WriteDecl.basicType[WriteDecl.char8]
          | Predef.char:
            RETURN WriteDecl.basicType[WriteDecl.char8]
          | Predef.longchar:
            RETURN WriteDecl.basicType[WriteDecl.char16]
          | Predef.shortint:
            RETURN WriteDecl.basicType[WriteDecl.int8]
          | Predef.integer:
            RETURN WriteDecl.basicType[WriteDecl.int16]
          | Predef.longint:
            RETURN WriteDecl.basicType[WriteDecl.int32]
          | Predef.real:
            RETURN WriteDecl.basicType[WriteDecl.real32]
          | Predef.longreal:
            RETURN WriteDecl.basicType[WriteDecl.real64]
          | Predef.set:
            RETURN WriteDecl.basicType[WriteDecl.uint32]

          | Predef.address:
            RETURN WriteDecl.basicType[WriteDecl.int32]
          | Predef.byte:
            RETURN WriteDecl.basicType[WriteDecl.char8]
          | Predef.ptr:
            RETURN WriteDecl.basicType[WriteDecl.ptr]
          END

          (* nothing *)
        | type: Item.TypeName DO
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

        | type: Item.Pointer DO
          ASSERT (FALSE)
(*              ConvertType (type. srcCodeBaseType)*)
        | type: Item.FormalPars DO
          fct := c. b. NewFunction (ConvertType (type. resultType, type. srcCodeResultType));
          IF (type. receiver # NIL) THEN
            fct. AddParameter (ConvertDecl (c, type. receiver))
          END;
          ptr := type. nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Item.Declaration DO
              fct. AddParameter (ConvertDecl (c, ptr))
            ELSE                     (* ignore non-declarations *)
            END;
            ptr := ptr. nextNested
          END;
          RETURN fct

        | type: Item.Array DO
          ASSERT (type. isOpenArray);
          RETURN c. b. NewArray (ConvertType (type. elementType, type. srcCodeElementType), -1)
(*              ConvertType (type. srcCodeElementType)*)
        | type: Item.Record DO
          ASSERT (FALSE)
(*              IF (type. srcCodeBaseType # NIL) THEN
            ConvertType (type. srcCodeBaseType)
          END;
          ConvertList (type)*)
        END
      END
    END ConvertType;

  BEGIN  (* pre: (exports. HasKey (ptr) = writeExported) *)
    WITH item: Item.Import DO
      c. b. IncludeModule (c. m. GetImport (item. moduleName. str^))

    | item: Item.ProcDecl DO
      CASE c. mode OF
      | modeWriteExported:
        sc := WriteDecl.scExtern
      | modeWritePrivate:
        sc := WriteDecl.scStatic
      | modeWriteFctDef:
        IF (item. exportMark = Item.nameNotExported) THEN
          sc := WriteDecl.scStatic
        ELSE
          sc := WriteDecl.scAuto
        END
      END;
      RETURN c. b. NewDeclaration
        (Naming.NameOfDeclaration (item), WriteDecl.tqNone, sc,
         ConvertType (item. formalPars, item. formalPars));

    | item: Item.ConstDecl DO
      ASSERT (FALSE);

    | item: Item.VarDecl DO
      IF item. isParameter THEN
        sc := WriteDecl.scAuto
      ELSE
        IF (c. mode = modeWriteExported) THEN
          sc := WriteDecl.scExtern
        ELSIF (item. exportMark = Item.nameNotExported) &
              (item. parent IS Item.Module) THEN
          sc := WriteDecl.scStatic
        ELSE
          sc := WriteDecl.scAuto
        END
      END;

      RETURN c. b. NewDeclaration
        (Naming.NameOfDeclaration (item), WriteDecl.tqNone, sc,
         ConvertType (item. type, item. srcCodeType))

    | item: Item.FieldDecl DO
      ASSERT (FALSE);
(*          ConvertType (item. srcCodeType)*)

    | item: Item.TypeDecl DO
      ASSERT (FALSE);
(*          ConvertType (item. srcCodeType)*)
    END
  END ConvertDecl;

PROCEDURE ConvertList (c: Converter; root: Item.Item);
  VAR
    ptr: Item.Item;
  BEGIN
    ptr := root. nestedItems;
    WHILE (ptr # NIL) DO
      WITH ptr: Item.Declaration DO
        IF (c. exports. HasKey (ptr) = (c. mode = modeWriteExported)) THEN
          c. b. AddDecl (ConvertDecl (c, ptr))
        END
      ELSE                               (* ignore non-declarations *)
      END;
      ptr := ptr. nextNested
    END
  END ConvertList;

PROCEDURE (c: Converter) ConvertSymTab* (b: WriteDecl.Block; writeExported: BOOLEAN);
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
    c. b := b;
    IF writeExported THEN
      c. mode := modeWriteExported
    ELSE
      c. mode := modeWritePrivate
    END;
    ConvertList (c, c. symTab);

    IF writeExported THEN
      c. b. AddDecl (c. b. NewDeclaration (Naming.NameOfModuleInit (c. m),
        WriteDecl.tqNone, WriteDecl.scExtern, 
        c. b. NewFunction (WriteDecl.basicType[WriteDecl.void])))
    END;
  END ConvertSymTab;

PROCEDURE (c: Converter) ConvertProc* (b: WriteDecl.Block; procDecl: Item.ProcDecl): WriteDecl.Declaration;
(**Creates the header of a C function definition matching the procedure
   declaration @oparam{procDecl}.  The declaration instance is created using
   the factory methods of @oparam{b}.  *)
  BEGIN
    c. b := b;
    c. mode := modeWriteFctDef;
    RETURN ConvertDecl (c, procDecl)
  END ConvertProc;

PROCEDURE (c: Converter) ConvertDecl* (b: WriteDecl.Block; decl: Item.Declaration): WriteDecl.Declaration;
(**Creates a C declaration for the object @oparam{decl}.  *)
  BEGIN
    c. b := b;
    c. mode := modeWriteFctDef;
    RETURN ConvertDecl (c, decl)
  END ConvertDecl;

END OOC:C:ConvertDecl.
