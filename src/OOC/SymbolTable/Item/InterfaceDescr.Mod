(* 	$Id$	 *)
MODULE OOC:SymbolTable:Item:InterfaceDescr;
(*  Writes a description of a module's interface as XML.
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
  Channel, Msg, Strings,
  ADT:Object, ADT:Dictionary, ADT:ArrayList,
  URI, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Repository,  OOC:Config:Repositories,
  OOC:SymbolTable:Item, OOC:SymbolTable:Item:GetClass, 
  OOC:SymbolTable:Namespace, DocXML := OOC:Doc:Output:XML;


CONST
  dtdPackageName = "OOC";
  dtdResourcePath = "xml/interface-description.dtd";

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
                  module: Item.Module; repositories: Repositories.Section;
                  extensionDict: Dictionary.Dictionary);
(**Writes the exported parts of the symbol table with root @oparam{module} as
   XML to the output channel @oparam{ch}.  Includes descriptions for
   declarations, cross-references, information about class and base classes,
   inherited fields and methods, and so on.  The output document is used as the
   common base for all module documentation output targets.  In particular, the
   HTML text is a transformation of the emitted data.

   Note: The implementation is incomplete.  Declaration and type flags are not
   written out.  *)
  VAR
    w: Writer.Writer;
    ptr: Item.Item;
    moduleDict, declDict: Dictionary.Dictionary;
    
  PROCEDURE WriteReference (tagName: ARRAY OF Writer.Char;
                            decl: Item.Declaration);
    VAR
      baseModule: Item.Module;
      className: Item.Name;
      href: ARRAY 2*1024 OF CHAR;
      id: Item.NameString;
      repModule: Repository.Module;
    BEGIN
      w. StartTag (tagName, FALSE);
      baseModule := decl. Module();
      w. AttrStringLatin1 ("module", baseModule. name. str^);
      w. AttrStringLatin1 ("name", decl. name. str^);
      className := GetClass.GetClass (decl);
      w. AttrStringLatin1 ("class", className. str^);
      IF (module = baseModule) THEN
        COPY ("", href)
      ELSE
        COPY (baseModule. name. str^, href)
      END;
      Strings.Append ("#", href);
      id := decl. GetId();
      Strings.Append (id^, href);
      w. AttrStringLatin1 ("href", href);
      w. EndTag;
      
      IF (module # baseModule) THEN
        repModule := repositories. GetModule (baseModule. name. str^);
        IF (repModule # NIL) THEN
          moduleDict. Set (repModule, NIL)
        END
      END
    END WriteReference;
  
  PROCEDURE DeclDocString (decl: Item.Declaration);
    VAR
      class: Item.Record;
      baseDef: Item.ProcDecl;
      rewriteMap: Dictionary.Dictionary;
      i: LONGINT;
      
    PROCEDURE GetBaseDefinition (superClass: Item.Record;
                                 name: Item.Name): Item.ProcDecl;
      VAR
        class: Item.Record;
        baseDef: Item.Declaration;
      BEGIN
        IF (superClass. baseType # NIL) THEN
          class := superClass. baseType(Item.Record);
          baseDef := class. ns. Identify (module, name, FALSE);
          IF (baseDef = NIL) OR (baseDef. docString = NIL) THEN
            RETURN GetBaseDefinition (class, name)
          ELSE
            RETURN baseDef(Item.ProcDecl)
          END
        ELSE
          RETURN NIL
        END
      END GetBaseDefinition;
    
    BEGIN
      IF (decl. docString # NIL) THEN
        DocXML.WriteOberonDoc (w, decl. docString, module,
                               NIL, repositories, moduleDict)
      
      ELSIF (decl IS Item.ProcDecl) & decl(Item.ProcDecl). isTypeBound THEN
        (* this is a type-bound procedure without a description; see if it is a
           redefinition of a procedure that does have a description and use
           this one  *)
        class := decl(Item.ProcDecl). Class();
        baseDef := GetBaseDefinition (class, decl. name);
        IF (baseDef # NIL) THEN
          WriteReference ("doc-inherited-from", baseDef);
          
          rewriteMap := Dictionary.New();
          rewriteMap. Set (baseDef. formalPars. receiver,
                           decl(Item.ProcDecl). formalPars. receiver);
          FOR i := 0 TO LEN (baseDef. formalPars. params^)-1 DO
            rewriteMap. Set (baseDef. formalPars. params[i],
                             decl(Item.ProcDecl). formalPars. params[i])
          END;
          
          DocXML.WriteOberonDoc (w, baseDef. docString, module, rewriteMap,
                                 repositories, moduleDict)
        END
      END
    END DeclDocString;

  PROCEDURE DeclAttr (decl: Item.Declaration);
    VAR
      id: Item.NameString;
    BEGIN
      w. AttrStringLatin1 ("name", decl. name. str^);
      IF ~declDict. HasKey (decl) THEN
        (* only write id if this is the first time we encounter this particular
           declaration; this degenerate case happens with constructions like
           "VAR x*, y*: RECORD a*: CHAR", where the field "a" appears in the
           XML output both within the declaration of "x" and of "y" *)
        id := decl. GetId();
        w. AttrStringLatin1 ("id", id^);
        declDict. Set (decl, NIL);
      END
    END DeclAttr;
  
  PROCEDURE WriteItem (item: Item.Item);
    VAR
      i: Item.Item;
      element: ARRAY 32 OF CHAR;
      moduleRepository: Repository.Module;
    
    PROCEDURE StartDecl (tag: ARRAY OF CHAR; decl: Item.Declaration);
      BEGIN
        w. StartTagLatin1 (tag, FALSE);
        DeclAttr (decl);
        CASE decl. exportMark OF
        | Item.nameNotExported:
          w. AttrString ("export", "no")
        | Item.nameExported:
          w. AttrString ("export", "yes")
        | Item.nameExportedRO:
          w. AttrString ("export", "read-only")
        END
      END StartDecl;
    
    PROCEDURE ^ WriteType (tag: ARRAY OF Writer.Char; type, resolvedType: Item.Type);
    
    PROCEDURE WriteTypeComponent (type, resolvedType: Item.Type);
      VAR
        i: Item.Item;
        j: LONGINT;
        module: Item.Module;
        href: ARRAY 2*1024 OF CHAR;
        import: Item.Import;
        repModule: Repository.Module;
      BEGIN
        WITH type: Item.TypeName DO
          w. StartTag ("type-name", FALSE);
          IF (type. module # NIL) THEN
            w. AttrStringLatin1 ("module", type. module. str^)
          ELSIF (resolvedType # NIL) & (resolvedType IS Item.PredefType) THEN
            (* note: this produces a wrong reference if the original type name
               is an alias of a predefined type; it is not clear how this 
               could be fixed without checking if the type's name is defined
               in the current module ... *)
            module := resolvedType. Module();
            w. AttrStringLatin1 ("module", module. name. str^)
          END;
          w. AttrStringLatin1 ("name", type. ident. str^);
          
          IF (type. module # NIL) OR
             (resolvedType = NIL) OR ~(resolvedType IS Item.PredefType) THEN
            IF (type. module # NIL) THEN
              import := type. GetImport();
              COPY (import. externalSymTab. name. str^, href);
              repModule := repositories. GetModule (import. externalSymTab. name. str^);
              IF (repModule # NIL) THEN
                moduleDict. Set (repModule, NIL)
              END
            ELSE
              COPY ("", href);
            END;
            Strings.Append ("#", href);
            Strings.Append (type. ident. str^, href);
            w. AttrStringLatin1 ("href", href)
          END;
          w. EndTag
          
        | type: Item.Pointer DO
          w. StartTag ("pointer", FALSE);
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

    PROCEDURE WriteType (tag: ARRAY OF Writer.Char; type, resolvedType: Item.Type);
      BEGIN
        w. StartTag (tag, FALSE);
        WriteTypeComponent (type, resolvedType);
        w. EndTag
      END WriteType;
    
    PROCEDURE WriteBaseDefinitions (superClass: Item.Record; name: Item.Name);
      VAR
        class: Item.Record;
        baseDef: Item.Declaration;
      BEGIN
        IF (superClass. baseType # NIL) THEN
          class := superClass. baseType(Item.Record);
          baseDef := class. ns. Identify (module, name, FALSE);
          IF (baseDef # NIL) THEN
            WriteReference ("redefined-method", baseDef)
          END;
          WriteBaseDefinitions (class, name)
        END
      END WriteBaseDefinitions;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.Module DO
          StartDecl ("module-interface", item);
          moduleRepository := repositories. GetModule (item. name. str^);
          
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
            DeclDocString (item);
            WriteTypeComponent (item. formalPars, item. formalPars);
            IF item. isTypeBound THEN
              WriteBaseDefinitions (item. Class(), item. name)
            END;
            w. EndTag
          END
        ELSE
        END
      END      
    END WriteItem;

  PROCEDURE WriteDeclList (list: Item.Item; className: Item.Name);
    VAR
      itemClass: Item.Name;
    BEGIN
      WHILE (list # NIL) DO
        itemClass := GetClass.GetClass (list);
        IF (itemClass = className) THEN
          WriteItem (list)
        END;
        list := list. nextNested
      END
    END WriteDeclList;
  
  PROCEDURE WriteModuleRef (modList: Dictionary.Dictionary);
    VAR
      i: LONGINT;
      thisModule, remoteMod: Repository.Module;
      str: ARRAY 2*1024 OF CHAR;
      res: Msg.Msg;
      remoteURI, relativeURI: URI.URI;
      baseURI: URI.HierarchicalURI;
      keys: ArrayList.ArrayList;
    BEGIN
      thisModule := repositories. GetModule (module. name. str^);
      baseURI := thisModule. GetURI (Repository.modInterfaceHTML, res);
      ASSERT (res = NIL);
      
      keys := modList. Keys();
      FOR i := 0 TO keys. size-1 DO
        remoteMod := keys. array[i](Repository.Module);

        w. StartTag ("module-ref", FALSE);
        w. AttrStringLatin1 ("name", remoteMod. name^);

        w. StartTag ("ref-target", FALSE);
        w. AttrStringLatin1 ("type", "html");
        remoteURI := remoteMod. GetURI (Repository.modInterfaceHTML, res);
        ASSERT (res = NIL);
        relativeURI := remoteURI. MakeRelative (baseURI);
        relativeURI. GetString (str);
        w. AttrStringLatin1 ("relative-uri", str);
        w. EndTag;

        w. EndTag
      END
    END WriteModuleRef;
  
  PROCEDURE WriteBaseClasses (topRecord: Item.Record);
    VAR
      omitMethod: ArrayList.ArrayList;
      
    PROCEDURE WriteRecord (record: Item.Record);
      VAR
        href: ARRAY 2*1024 OF CHAR;
        ns: Namespace.Namespace;
        i: LONGINT;
        module: Item.Module;
        item: Item.Item;
      
      PROCEDURE NewMethod (method: Item.ProcDecl): BOOLEAN;
        VAR
          i: LONGINT;
        BEGIN
          FOR i := 0 TO omitMethod. size-1 DO
            IF (omitMethod. array[i](Item.Declaration). name. str^ =
                method. name. str^) THEN
              RETURN FALSE
            END
          END;
          RETURN TRUE
        END NewMethod;
      
      BEGIN
        w. StartTag ("base-class", FALSE);
        module := record. Module();
        w. AttrStringLatin1 ("module", module. name. str^);
        w. AttrStringLatin1 ("class", record. className. str^);
        IF (topRecord. Module() = module) THEN
          COPY ("", href)
        ELSE
          COPY (module. name. str^, href)
        END;
        Strings.Append ("#", href);
        Strings.Append (record. className. str^, href);
        w. AttrStringLatin1 ("href", href);
        
        ns := record. ns(Namespace.Namespace);
        FOR i := 0 TO ns. localCount-1 DO
          item := ns. localDecl[i];
          IF (item(Item.Declaration). exportMark # Item.nameNotExported) &
             ((item IS Item.FieldDecl) OR NewMethod (item(Item.ProcDecl))) THEN
            WITH item: Item.FieldDecl DO
              WriteReference ("inherited-field", item)
            | item: Item.ProcDecl DO
              WriteReference ("inherited-method", item);
              omitMethod. Append (item)
            END
          END
        END;
        
        IF (record. baseType # NIL) THEN
          WriteRecord (record. baseType(Item.Record))
        END;
        
        w. EndTag
      END WriteRecord;
    
    BEGIN
      omitMethod := ArrayList.New (16);
      IF (topRecord. baseType # NIL) THEN
        WriteRecord (topRecord. baseType(Item.Record))
      END
    END WriteBaseClasses;
  
  PROCEDURE WriteKnownExtensions (type: Object.Object);
    VAR
      i: LONGINT;
      obj: Object.Object;
      list: ArrayList.ArrayList;
      item: Item.Item;
    BEGIN
      IF extensionDict. HasKey (type) THEN
        obj := extensionDict. Get (type);
        list := obj(ArrayList.ArrayList);
        FOR i := 0 TO list. size-1 DO
          item := list. array[i](Item.Record). parent. nestedItems;
          WHILE ~((item IS Item.TypeDecl) &
                  (item(Item.TypeDecl). type = list. array[i])) DO
            item := item. nextNested
          END;
          WriteReference ("known-extension", item(Item.TypeDecl));
          WriteKnownExtensions (list. array[i])
        END
      END
    END WriteKnownExtensions;

  BEGIN
    moduleDict := Dictionary.New();
    declDict := Dictionary.New();
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. SetBaseURI (baseURI);
    w. WriteTextDecl ("1.0", "no");
    w. NewLine;
    w. Write8 ("<!DOCTYPE interface-description SYSTEM '");
    w. WriteURI (GetSystemId (repositories), FALSE);
    w. Write8 ("'>");
(*    Item.Prune (module, Exports.GetExports (module)); (* ... *)*)
    (* note: prune doesn't work if not-exported declarations are targets
       of a reference command; for this reason, such bad references must
       be flagged as errors *)
    
    w. StartTag ("interface-description", FALSE);
    DeclAttr (module);
    DeclDocString (module);
    WriteDeclList (module. nestedItems, NIL);
    ptr := module. nestedItems;
    WHILE (ptr # NIL) DO
      IF (ptr IS Item.TypeDecl) &
         (ptr(Item.TypeDecl). srcCodeType IS Item.Record) &
         (ptr(Item.TypeDecl). srcCodeType(Item.Record). className # NIL) THEN
        (* note: we need to use `srcCodeType' here, or we will produce multiple
           class elements if there are any alias declarations on the record
           type *)
        w. StartTag ("class", FALSE);
        w. AttrStringLatin1 ("name", ptr(Item.TypeDecl). srcCodeType(Item.Record). className. str^);
        WriteDeclList (module. nestedItems, 
                     ptr(Item.TypeDecl). srcCodeType(Item.Record). className);
        WriteBaseClasses (ptr(Item.TypeDecl). srcCodeType(Item.Record));
        WriteKnownExtensions (ptr(Item.TypeDecl). srcCodeType(Item.Record));
        w. EndTag
      END;
      ptr := ptr. nextNested
    END;
    WriteModuleRef (moduleDict);
    w. EndTag;
    
    w. EndOfText
  END Write;

BEGIN
  dtdSystemId := NIL
END OOC:SymbolTable:Item:InterfaceDescr.
