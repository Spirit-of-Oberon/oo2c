MODULE OOC:C:ConvertDecl;

IMPORT
Log,OOC:SymbolTable:Item:XML,StdChannels,
  ADT:Dictionary, 
  OOC:Repository, OOC:SymbolTable:Item,
  OOC:SymbolTable:Predef, OOC:SymbolTable:System,
  OOC:C:Naming, OOC:C:WriteDecl;
  
PROCEDURE Convert* (m: Repository.Module; symTab: Item.Module;
                    b: WriteDecl.Block;
                    exports: Dictionary.Dictionary; writeExported: BOOLEAN);
(**Converts the declarations in the symbol table @oparam{symTab} of the module
   @oparam{m} into a series of C declarations.  The declarations are emitted
   into the file object @oparam{f}.

   The procedure supports two different modes of operations: writing the public
   interface of a module, and writing the complement to the public interface.
   The set of emitted declarations is selected by @oparam{exports}.  With
   @samp{@oparam{writeExported}=@code{TRUE}}, all items in @oparam{exports} are
   written.  Otherwise, all items @emph{not} in @oparam{exports} are emitted.  *)
  PROCEDURE ConvertList (root: Item.Item);
    VAR
      ptr: Item.Item;
      
    PROCEDURE ConvertDecl (item: Item.Declaration): WriteDecl.Declaration;
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

              | System.address:
                RETURN WriteDecl.basicType[WriteDecl.int32]
              | System.byte:
                RETURN WriteDecl.basicType[WriteDecl.char8]
              | System.ptr:
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
              fct := b. NewFunction (ConvertType (type. resultType, type. srcCodeResultType));
              IF (type. receiver # NIL) THEN
                fct. AddParameter (ConvertDecl (type. receiver))
              END;
              ptr := type. nestedItems;
              WHILE (ptr # NIL) DO
                WITH ptr: Item.Declaration DO
                  fct. AddParameter (ConvertDecl (ptr))
                ELSE                     (* ignore non-declarations *)
                END;
                ptr := ptr. nextNested
              END;
              RETURN fct
              
            | type: Item.Array DO
              ASSERT (type. isOpenArray);
              RETURN b. NewArray (ConvertType (type. elementType, type. srcCodeElementType), -1)
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
          b. IncludeModule (m. GetImport (item. moduleName. str^))
          
        | item: Item.ProcDecl DO
          IF writeExported THEN
            sc := WriteDecl.scExtern
          ELSE
            sc := WriteDecl.scStatic
          END;
          RETURN b. NewDeclaration
            (Naming.NameOfDeclaration (item), WriteDecl.tqNone, sc,
             ConvertType (item. formalPars, item. formalPars));
          
        | item: Item.ConstDecl DO
          ASSERT (FALSE);
          
        | item: Item.VarDecl DO
          IF item. isParameter THEN
            sc := WriteDecl.scAuto
          ELSE
            IF writeExported THEN
              sc := WriteDecl.scExtern
            ELSIF (item. exportMark = Item.nameNotExported) THEN
              sc := WriteDecl.scStatic
            ELSE
              sc := WriteDecl.scAuto
            END
          END;
          
          RETURN b. NewDeclaration
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

    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Item.Declaration DO
          IF (exports. HasKey (ptr) = writeExported) THEN
            b. AddDecl (ConvertDecl (ptr))
          END
        ELSE                               (* ignore non-declarations *)
        END;
        ptr := ptr. nextNested
      END
    END ConvertList;
  
  BEGIN
    ConvertList (symTab);

    IF writeExported THEN
      b. AddDecl (b. NewDeclaration (Naming.NameOfModuleInit (m),
        WriteDecl.tqNone, WriteDecl.scExtern, 
        b. NewFunction (WriteDecl.basicType[WriteDecl.void])))
    END;
  END Convert;

END OOC:C:ConvertDecl.
