MODULE OOC:C:ConvertDecl;

IMPORT
  ADT:Dictionary, 
  OOC:Repository, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:C:Naming, OOC:C:DeclWriter;


CONST
  modeWriteExported = 0;
  modeWritePrivate = 1;
  modeWriteFctDef = 2;


PROCEDURE ConvertDecl (w: DeclWriter.Writer;
                       item: Sym.Declaration;
                       mode: SHORTINT): DeclWriter.Declaration;
  VAR
    sc: DeclWriter.StorageClass;

  PROCEDURE ConvertType (resolvedType, type: Sym.Type): DeclWriter.Type;
    VAR
      ptr: Sym.Item;
      fct: DeclWriter.Function;
(*          decl: Sym.Declaration;*)
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
          fct := w. NewFunction (ConvertType (type. resultType, type. srcCodeResultType));
          IF (type. receiver # NIL) THEN
            fct. AddParameter (ConvertDecl (w, type. receiver, mode))
          END;
          ptr := type. nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Sym.Declaration DO
              fct. AddParameter (ConvertDecl (w, ptr, mode))
            ELSE                     (* ignore non-declarations *)
            END;
            ptr := ptr. nextNested
          END;
          RETURN fct

        | type: Sym.Array DO
          ASSERT (type. isOpenArray);
          RETURN w. NewArray (ConvertType (type. elementType, type. srcCodeElementType), -1)
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
         ConvertType (item. formalPars, item. formalPars));

    | item: Sym.ConstDecl DO
      ASSERT (FALSE);

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

      RETURN w. NewDeclaration
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

END OOC:C:ConvertDecl.
