(* 	$Id$	 *)
MODULE OOC:SymbolTable:Exports;
(*  Marks declarations that are part of the module's symbol file.
    Copyright (C) 2000, 2001, 2002  Michael van Acken

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
  Log, ADT:Dictionary, Sym := OOC:SymbolTable, OOC:Doc;


PROCEDURE GetExports* (module: Sym.Module): Dictionary.Dictionary;
(**Creates a dictionary with all items that appear in the
   module's symbol file.
   
   FIXME: Can we remove record fields that are not exported?
   No, if we need them to compute field offsets! ... *)
  VAR
    dict: Dictionary.Dictionary;
  
  PROCEDURE MarkReferencedImports (doc: Doc.Document);
    VAR
      i: LONGINT;
    BEGIN
      IF (doc # NIL) & (doc. usedImportsList # NIL) THEN
        (* mark all import statements that appear in the documentation
           string *)
        FOR i := 0 TO doc. usedImportsList. size-1 DO
          dict. Set (doc. usedImportsList. array[i](Sym.Import), NIL)
        END
      END
    END MarkReferencedImports;
  
  PROCEDURE MarkList (root: Sym.Item);
    VAR
      ptr: Sym.Item;
      
    PROCEDURE MarkDecl (item: Sym.Declaration);
      PROCEDURE MarkType (type: Sym.Type);
        VAR
          decl: Sym.Declaration;
        BEGIN
          IF ~dict. HasKey (type) THEN
            dict. Set (type, NIL);
            IF (type. namingDecl # NIL) THEN
              MarkDecl (type. namingDecl)
            END;
            
            WITH type: Sym.PredefType DO
              (* nothing *)
            | type: Sym.TypeName DO
              IF (type. module = NIL) THEN
                decl := module. ns. IdentifyLocal (root, type. ident, TRUE)
                (* this may be NIL if we are looking at the name of a
                   predefined type; in this case, we are done *)
              ELSE
                decl := module. ns. IdentifyLocal (root, type. module, TRUE);
                ASSERT (decl # NIL)
              END;
              IF (decl # NIL) THEN
                MarkDecl (decl)
              END
            | type: Sym.Pointer DO
              MarkType (type. srcCodeBaseType)
            | type: Sym.FormalPars DO
              IF (type. srcCodeResultType # NIL) THEN
                MarkType (type. srcCodeResultType)
              END;
              IF (type. receiver # NIL) THEN
                MarkDecl (type. receiver)
              END;
              MarkList (type)
            | type: Sym.Array DO
              MarkType (type. srcCodeElementType)
            | type: Sym.Record DO
              IF (type. srcCodeBaseType # NIL) THEN
                MarkType (type. srcCodeBaseType)
              END;
              MarkList (type)
            END
          END
        END MarkType;

      BEGIN
        IF ~dict. HasKey (item) THEN
          dict. Set (item, NIL);
          
          MarkReferencedImports (item. docString);
          
          WITH item: Sym.Import DO
            (* nothing *)
          | item: Sym.ProcDecl DO
            MarkType (item. formalPars)
          | item: Sym.PredefProc DO
            (* nothing *)
          | item: Sym.ConstDecl DO
            (* nothing *)
          | item: Sym.VarDecl DO
            MarkType (item. srcCodeType)
          | item: Sym.FieldDecl DO
            MarkType (item. srcCodeType)
          | item: Sym.TypeDecl DO
            MarkType (item. srcCodeType)
          ELSE
            Log.Type ("-- [OOC:SymbolTable:Exports]: Unknown type of `item'",
                      item);
            ASSERT (FALSE);
          END
        END
      END MarkDecl;

    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Sym.Declaration DO
          IF (ptr. exportMark # Sym.nameNotExported) OR 
             (ptr IS Sym.VarDecl) & ptr(Sym.VarDecl). isParameter OR
             (ptr IS Sym.Import) THEN
            MarkDecl (ptr)
          END
        ELSE                               (* ignore non-declarations *)
        END;
        ptr := ptr. nextNested
      END
    END MarkList;
  
  BEGIN
    dict := Dictionary.New();
    (*MarkReferencedImports (module. docString);
         --> obsolete, all imports must appear in the symbol file *)
    MarkList (module);
    RETURN dict
  END GetExports;

END OOC:SymbolTable:Exports.
