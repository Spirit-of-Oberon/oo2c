(* 	$Id$	 *)
MODULE OOC:SymbolTable:Item:InterfaceXML;
(*  Writes the exported interface of a module into an XML document.
    Copyright (C) 2000, 2001  Michael van Acken

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
  Channel, TextRider, URI, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Repository, OOC:Config:Repositories,
  OOC:SymbolTable:Item,
  OOC:SymbolTable:Item:GetClass, OOC:SymbolTable:Exports,
  DocXML := OOC:Doc:Output:XML;


CONST
  dtdPackageName = "OOC";
  dtdResourcePath = "xml/module-interface.dtd";

VAR
  dtdSystemId: URI.URI;

PROCEDURE GetSystemId (repositories: Repositories.Section): URI.URI;
  BEGIN
    IF (dtdSystemId = NIL) THEN
      dtdSystemId := repositories. GetResource (dtdPackageName, dtdResourcePath);
      ASSERT (dtdSystemId # NIL);
      RETURN dtdSystemId
    ELSE
      RETURN dtdSystemId
    END
  END GetSystemId;

PROCEDURE Write* (cw: Channel.Writer; baseURI: URI.HierarchicalURI;
                  module: Item.Module;
                  repositories: Repositories.Section);
(**Writes the exported parts of the symbol table with root @oparam{module}
   to the output channel @oparam{ch}.  The result is an XML document that
   describes the public interface of the module.
   
   Note: The implementation is incomplete.  Declaration and type flags
   are not written out.  *)
  VAR
    w: Writer.Writer;
    
  PROCEDURE WriteItem (item: Item.Item);
    VAR
      i: Item.Item;
      element: ARRAY 32 OF CHAR;
      moduleRepository: Repository.Module;
    
    PROCEDURE StartDecl (tag: ARRAY OF CHAR; decl: Item.Declaration);
      BEGIN
        w. StartTagLatin1 (tag, FALSE);
        w. AttrStringLatin1 ("name", decl. name. str^);
        CASE decl. exportMark OF
        | Item.nameNotExported:
          w. AttrString ("export", "no")
        | Item.nameExported:
          w. AttrString ("export", "yes")
        | Item.nameExportedRO:
          w. AttrString ("export", "read-only")
        END
      END StartDecl;
    
    PROCEDURE DeclDocString (decl: Item.Declaration);
      BEGIN
        IF (decl. docString # NIL) THEN
          DocXML.WriteOberonDoc (w, decl. docString, module, NIL, NIL, NIL)
        END
      END DeclDocString;
    
    PROCEDURE ^ WriteType (tag: ARRAY OF CHAR; type, resolvedType: Item.Type);
    
    PROCEDURE ClassAttr (item: Item.Item);
      VAR
        class: Item.Name;
      BEGIN
        class := GetClass.GetClass (item);
        IF (class # NIL) THEN
          w. AttrStringLatin1 ("class", class. str^)
        END
      END ClassAttr;
    
    PROCEDURE WriteTypeComponent (type, resolvedType: Item.Type);
      VAR
        i: Item.Item;
        j: LONGINT;
        module: Item.Module;
      
      PROCEDURE WriteBaseClass (baseType: Item.Record);
        VAR
          module: Item.Module;
          moduleRepository: Repository.Module;
        BEGIN
          w. StartTag ("base-class", FALSE);
          (* note: this dumps core if the base type has not been classified
             as a class; currently, this can only happen if it is a record
             without any pointers, base type, or type-bound procedure *)
          w. AttrStringLatin1 ("class", baseType. className. str^);
          
          module := baseType. Module();
          w. AttrStringLatin1 ("module", module. name. str^);
          
          moduleRepository := repositories. GetModule (module. name. str^);
          IF (moduleRepository # NIL) THEN  (* make this required? ... *)
            w. AttrURI ("repository-base", moduleRepository. origin. baseURI, FALSE)
          END;
          
          IF (baseType. baseType # NIL) THEN
            WriteBaseClass (baseType. baseType(Item.Record))
          END;
          w. EndTag
        END WriteBaseClass;
      
      BEGIN
        WITH type: Item.TypeName DO
          w. StartTag ("type-name", FALSE);
          IF (type. module # NIL) THEN
            w. AttrStringLatin1 ("module", type. module. str^)
          ELSIF (resolvedType # NIL) & (resolvedType IS Item.PredefType) THEN
            module := resolvedType. Module();
            w. AttrStringLatin1 ("module", module. name. str^)
          END;
          w. AttrStringLatin1 ("name", type. ident. str^);
          w. EndTag

        | type: Item.Pointer DO
          w. StartTag ("pointer", FALSE);
          ClassAttr (type);
          WriteType ("pointer-base", type. srcCodeBaseType, type. baseType);
          w. EndTag

        | type: Item.Array DO
          w. StartTag ("array", FALSE);
          IF ~type. isOpenArray THEN
            w. StartTag ("length", FALSE);
            w. EndTag
          END;
          WriteType ("element-type", type. srcCodeElementType, type. elementType);
          w. EndTag

        | type: Item.Record DO
          w. StartTag ("record", FALSE);
          ClassAttr (type);
          IF (type. srcCodeBaseType # NIL) THEN
            WriteType ("base-type", type. srcCodeBaseType, type. baseType);
            WriteBaseClass (type. baseType(Item.Record))
          END;
          i := type. nestedItems;
          WHILE (i # NIL) DO
            IF (i IS Item.FieldDecl) THEN
              WriteItem (i)
            END;
            i := i. nextNested
          END;
          w. EndTag

        | type: Item.FormalPars DO
          w. StartTag ("formal-parameters", FALSE);
          IF (type. receiver # NIL) THEN
            WriteItem (type. receiver);
          END;
          FOR j := 0 TO LEN (type. params^)-1 DO
            WriteItem (type. params[j])
          END;
          IF (type. srcCodeResultType # NIL) THEN
            WriteType ("result-type", type. srcCodeResultType, type. resultType)
          END;
          w. EndTag
        END
      END WriteTypeComponent;

    PROCEDURE WriteType (tag: ARRAY OF CHAR; type, resolvedType: Item.Type);
      BEGIN
        w. StartTagLatin1 (tag, FALSE);
        WriteTypeComponent (type, resolvedType);
        w. EndTag
      END WriteType;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.Module DO
          StartDecl ("module-interface", item);
          moduleRepository := repositories. GetModule (item. name. str^);
          IF (moduleRepository # NIL) THEN  (* make this required? ... *)
            w. AttrURI ("repository-base", moduleRepository. origin. baseURI, FALSE)
          END;
          DeclDocString (item);
          
          i := item. nestedItems;
          WHILE (i # NIL) DO
            IF (i IS Item.Declaration) THEN
              WriteItem (i)
            END;
            i := i. nextNested
          END;
          w. EndTag
        
        | item: Item.Import DO
          StartDecl ("import-decl", item);
          w. AttrStringLatin1 ("module", item. moduleName. str^);
          moduleRepository := repositories. GetModule (item. moduleName. str^);
          IF (moduleRepository # NIL) THEN  (* make this required? ... *)
            w. AttrURI ("repository-base", moduleRepository. origin. baseURI, FALSE)
          END;
          DeclDocString (item);
          w. EndTag
        
        | item: Item.ConstDecl DO
          StartDecl ("const-decl", item);
          w. AttrString ("value", "unknown");
          DeclDocString (item);
          w. EndTag
        
        | item: Item.TypeDecl DO
          StartDecl ("type-decl", item);
          DeclDocString (item);
          WriteType ("type", item. srcCodeType, item. type);
          w. EndTag
          
        | item: Item.VarDecl DO
          IF item. isReceiver THEN
            element := "receiver-decl"
          ELSIF item. isParameter THEN
            element := "parameter-decl"
          ELSE
            element := "var-decl"
          END;
          StartDecl (element, item);
          IF item. isParameter THEN
            w. AttrBool ("variable-parameter", item. isVarParam)
          END;
          DeclDocString (item);
          WriteType ("type", item. srcCodeType, item. type);
          w. EndTag
          
        | item: Item.FieldDecl DO
          StartDecl ("field-decl", item);
          DeclDocString (item);
          WriteType ("type", item. srcCodeType, item. type);
          w. EndTag
        
        | item: Item.ProcDecl DO
          IF ~item. isForwardDecl THEN
            StartDecl ("procedure", item);
            ClassAttr (item);
            DeclDocString (item);
            WriteTypeComponent (item. formalPars, item. formalPars);
            w. EndTag
          END
        ELSE
        END
      END      
    END WriteItem;

  BEGIN
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");
    w. SetBaseURI (baseURI);
    w. NewLine;
    w. Write8 ("<!DOCTYPE module-interface SYSTEM '");
    w. WriteURI (GetSystemId (repositories), FALSE);
    w. Write8 ("'>");
    Item.Prune (module, Exports.GetExports (module)); (* ... *)
    WriteItem (module);
    w. EndOfText
  END Write;

BEGIN
  dtdSystemId := NIL
END OOC:SymbolTable:Item:InterfaceXML.
