(* 	$Id$	 *)
MODULE OOC:SymbolTable:Exports;
(*  Marks declarations that are part of the module's symbol file.
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
  ADT:Dictionary, OOC:SymbolTable:Item, OOC:Doc;


PROCEDURE GetExports* (module: Item.Module): Dictionary.Dictionary;
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
          dict. Set (doc. usedImportsList. array[i](Item.Import), NIL)
        END
      END
    END MarkReferencedImports;
  
  PROCEDURE MarkList (root: Item.Item);
    VAR
      ptr: Item.Item;
      
    PROCEDURE MarkDecl (item: Item.Declaration);
      PROCEDURE MarkType (type: Item.Type);
        VAR
          decl: Item.Declaration;
        BEGIN
          IF ~dict. HasKey (type) THEN
            dict. Set (type, NIL);
            
            WITH type: Item.PredefType DO
              (* nothing *)
            | type: Item.TypeName DO
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
            | type: Item.Pointer DO
              MarkType (type. srcCodeBaseType)
            | type: Item.FormalPars DO
              IF (type. srcCodeResultType # NIL) THEN
                MarkType (type. srcCodeResultType)
              END;
              IF (type. receiver # NIL) THEN
                MarkDecl (type. receiver)
              END;
              MarkList (type)
            | type: Item.Array DO
              MarkType (type. srcCodeElementType)
            | type: Item.Record DO
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
          
          WITH item: Item.Import DO
            (* nothing *)
          | item: Item.ProcDecl DO
            MarkType (item. formalPars)
          | item: Item.ConstDecl DO
            (* nothing *)
          | item: Item.VarDecl DO
            MarkType (item. srcCodeType)
          | item: Item.FieldDecl DO
            MarkType (item. srcCodeType)
          | item: Item.TypeDecl DO
            MarkType (item. srcCodeType)
          END
        END
      END MarkDecl;

    BEGIN
      ptr := root. nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Item.Declaration DO
          IF (ptr. exportMark # Item.nameNotExported) OR 
             (ptr IS Item.VarDecl) & ptr(Item.VarDecl). isParameter THEN
            MarkDecl (ptr)
          END
        ELSE                               (* ignore non-declarations *)
        END;
        ptr := ptr. nextNested
      END
    END MarkList;
  
  BEGIN
    dict := Dictionary.New();
    MarkReferencedImports (module. docString);
    MarkList (module);
    RETURN dict
  END GetExports;

END OOC:SymbolTable:Exports.
