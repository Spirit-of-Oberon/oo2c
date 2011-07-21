(* 	$Id: InterfaceDescr.Mod,v 1.22 2003/07/06 21:49:42 mva Exp $	 *)
MODULE OOC:SymbolTable:InterfaceDescr;
(*  Writes a description of a module's interface as XML.
    Copyright (C) 2000, 2001, 2002, 2003  Michael van Acken

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
  Strings, Object, ADT:Dictionary, ADT:ArrayList, IO,
  URI, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Repository,  OOC:Config:Repositories,
  Sym := OOC:SymbolTable, OOC:SymbolTable:GetClass, 
  OOC:SymbolTable:Namespace, DocXML := OOC:Doc:Output:XML;


CONST
  dtdPackageName = "OOC";
  dtdResourcePath = "xml/interface-description.dtd";

VAR
  dtdSystemId: URI.URI;
  absoluteDtdSystemId*: BOOLEAN;
  (**If @code{TRUE} (which is the default), then write the system ID of the
     XML interface description document as an absolute path.  Otherwise,
     write a relative one.  *)
  
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

PROCEDURE Write* (cw: IO.ByteChannel; baseURI: URI.HierarchicalURI;
                  module: Sym.Module; repositories: Repositories.Section;
                  extensionDict: Sym.ExtensionDict)
RAISES IO.Error;
(**Writes the exported parts of the symbol table with root @oparam{module} as
   XML to the output writer @oparam{cw}.  Includes descriptions for
   declarations, cross-references, information about class and base classes,
   inherited fields and methods, and so on.  The output document is used as the
   common base for all module documentation output targets.  In particular, the
   HTML text is a transformation of the emitted data.

   Note: The implementation is incomplete.  Declaration and type flags are not
   written out.  *)
  VAR
    w: Writer.Writer;
    ptr: Sym.Item;
    moduleDict, declDict: Dictionary.Dictionary;
    
  PROCEDURE WriteReference (tagName: ARRAY OF Writer.Char;
                            decl: Sym.Declaration);
    VAR
      baseModule: Sym.Module;
      className: Sym.Name;
      href: ARRAY 2*1024 OF CHAR;
      id: Sym.NameString;
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
  
  PROCEDURE DeclDocString (decl: Sym.Declaration);
    VAR
      class: Sym.Record;
      baseDef: Sym.ProcDecl;
      rewriteMap: Dictionary.Dictionary;
      i: LONGINT;
      
    PROCEDURE GetBaseDefinition (superClass: Sym.Record;
                                 name: Sym.Name): Sym.ProcDecl;
      VAR
        class: Sym.Record;
        baseDef: Sym.Declaration;
      BEGIN
        IF (superClass. baseType # NIL) THEN
          class := superClass. baseType(Sym.Record);
          baseDef := class. ns. Identify (module, name, FALSE);
          IF (baseDef = NIL) OR (baseDef. docString = NIL) THEN
            RETURN GetBaseDefinition (class, name)
          ELSE
            RETURN baseDef(Sym.ProcDecl)
          END
        ELSE
          RETURN NIL
        END
      END GetBaseDefinition;
    
    BEGIN
      IF (decl. docString # NIL) THEN
        DocXML.WriteOberonDoc (w, decl. docString, module,
                               NIL, repositories, moduleDict)
      
      ELSIF (decl IS Sym.ProcDecl) & decl(Sym.ProcDecl).IsTypeBound() THEN
        (* this is a type-bound procedure without a description; see if it is a
           redefinition of a procedure that does have a description and use
           this one  *)
        class := decl(Sym.ProcDecl). Class();
        baseDef := GetBaseDefinition (class, decl. name);
        IF (baseDef # NIL) THEN
          WriteReference ("doc-inherited-from", baseDef);
          
          rewriteMap := Dictionary.New();
          rewriteMap. Set (baseDef. formalPars. receiver,
                           decl(Sym.ProcDecl). formalPars. receiver);
          FOR i := 0 TO LEN (baseDef. formalPars. params^)-1 DO
            rewriteMap. Set (baseDef. formalPars. params[i],
                             decl(Sym.ProcDecl). formalPars. params[i])
          END;
          
          DocXML.WriteOberonDoc (w, baseDef. docString, module, rewriteMap,
                                 repositories, moduleDict)
        END
      END
    END DeclDocString;

  PROCEDURE DeclAttr (decl: Sym.Declaration);
    VAR
      id: Sym.NameString;
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
  
  PROCEDURE WriteItem (item: Sym.Item);
    VAR
      i: Sym.Item;
      element: ARRAY 32 OF CHAR;
      moduleRepository: Repository.Module;
      str: STRING;
    
    PROCEDURE StartDecl (tag: ARRAY OF CHAR; decl: Sym.Declaration);
      BEGIN
        w. StartTagLatin1 (tag, FALSE);
        DeclAttr (decl);
        CASE decl. exportMark OF
        | Sym.nameNotExported:
          w. AttrString ("export", "no")
        | Sym.nameExported:
          w. AttrString ("export", "yes")
        | Sym.nameExportedRO:
          w. AttrString ("export", "read-only")
        END
      END StartDecl;
    
    PROCEDURE ^ WriteType (tag: ARRAY OF Writer.Char; type, resolvedType: Sym.Type);
    
    PROCEDURE WriteTypeComponent (type, resolvedType: Sym.Type);
      VAR
        i: Sym.Item;
        j: LONGINT;
        module: Sym.Module;
        href: ARRAY 2*1024 OF CHAR;
        import: Sym.Import;
        repModule: Repository.Module;
        id: Sym.NameString;
        typeModule: Sym.Name;
      BEGIN
        WITH type: Sym.TypeName DO
          w. StartTag ("type-name", FALSE);
          IF type.IsPredefReference() THEN
            typeModule := NIL;
          ELSE
            typeModule := type.module;
          END;
          IF (typeModule # NIL) THEN
            w. AttrStringLatin1 ("module", typeModule. str^)
          ELSIF (resolvedType # NIL) & (resolvedType IS Sym.PredefType) THEN
            (* note: this produces a wrong reference if the original type name
               is an alias of a predefined type; it is not clear how this 
               could be fixed without checking if the type's name is defined
               in the current module ... *)
            module := resolvedType. Module();
            w. AttrStringLatin1 ("module", module. name. str^)
          END;
          w. AttrStringLatin1 ("name", type. ident. str^);
          
          IF (typeModule # NIL) OR
             (resolvedType = NIL) OR ~(resolvedType IS Sym.PredefType) THEN
            IF (resolvedType IS Sym.TypeVar) THEN
              id := resolvedType.namingDecl.GetId();
              COPY ("#", href);
              Strings.Append(id^, href);
            ELSE
              IF (typeModule # NIL) THEN
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
            END;
            w. AttrStringLatin1 ("href", href)
          END;
          w. EndTag
          
        | type: Sym.Pointer DO
          w. StartTag ("pointer", FALSE);
          WriteType ("pointer-base", type. srcCodeBaseType, type. baseType);
          w. EndTag

        | type: Sym.Array DO
          w. StartTag ("array", FALSE);
          IF ~type. isOpenArray THEN
            w. StartTag ("length", FALSE);
            w. EndTag
          END;
          WriteType ("element-type", type. srcCodeElementType, type. elementType);
          w. EndTag

        | type: Sym.Record DO
          w. StartTag ("record", FALSE);
          i := type. nestedItems;
          WHILE (i # NIL) DO
            IF (i IS Sym.FieldDecl) THEN
              WriteItem (i)
            END;
            i := i. nextNested
          END;
          w. EndTag

        | type: Sym.FormalPars DO
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
          IF (LEN(type.raises^) # 0) THEN
            w.StartTag("exceptions", FALSE);
            FOR j := 0 TO LEN(type.raises^)-1 DO
              WriteTypeComponent(type.raises[j].srcCodeType,
                                 type.raises[j].type);
            END;
            w.EndTag;
          END;
          w. EndTag;

        | type: Sym.QualType DO
          w.StartTag("qualified-type", FALSE);
          WriteType("type", type.srcCodeBaseType, type.baseType);
          w.StartTag("type-arguments", FALSE);
          FOR j := 0 TO LEN(type.arguments^)-1 DO
            WriteTypeComponent(type.arguments[j].srcCodeType,
                               type.arguments[j].type);
          END;
          w.EndTag();
          w.EndTag();
        END
      END WriteTypeComponent;

    PROCEDURE WriteType (tag: ARRAY OF Writer.Char; type, resolvedType: Sym.Type);
      BEGIN
        w. StartTag (tag, FALSE);
        WriteTypeComponent (type, resolvedType);
        w. EndTag
      END WriteType;
    
    PROCEDURE WriteBaseDefinitions (superClass: Sym.Record; name: Sym.Name);
      VAR
        class: Sym.Record;
        baseDef: Sym.Declaration;
      BEGIN
        IF (superClass. baseType # NIL) THEN
          class := superClass. baseType(Sym.Record);
          baseDef := class. ns. Identify (module, name, FALSE);
          IF (baseDef # NIL) THEN
            WriteReference ("redefined-method", baseDef)
          END;
          WriteBaseDefinitions (class, name)
        END
      END WriteBaseDefinitions;

    PROCEDURE WriteAliasList(receiver: Sym.VarDecl);
      VAR
        id: Sym.NameString;
        i: Sym.Item;
      BEGIN
        w.StartTag("type-alias-list", FALSE);
        i := receiver.parent(Sym.FormalPars).nestedItems;
        WHILE (i # NIL) DO
          WITH i: Sym.TypeDecl DO
            w.StartTag("type-alias", FALSE);
            w.AttrStringLatin1("name", i.name.str^);
            id := i.GetId();
            w. AttrStringLatin1 ("id", id^);
            w.EndTag();
          ELSE
            (* ignore *)
          END;
          i := i. nextNested
        END;
        w.EndTag();
      END WriteAliasList;
    
    PROCEDURE WriteTypePars(typePars: Sym.TypePars);
      VAR
        i: Sym.Item;
      BEGIN
        w.StartTag("type-parameters", FALSE);
        i := typePars.nestedItems;
        WHILE (i # NIL) DO
          WITH i: Sym.TypeDecl DO
            WriteItem(i);
          ELSE
            (* ignore *)
          END;
          i := i. nextNested
        END;
        w.EndTag();
      END WriteTypePars;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.Module DO
          StartDecl ("module-interface", item);
          str := item. ClassToString();
          (*IF (str. array^ # "standard") THEN*)
            w. AttrObject ("class", str);
          (*END;*)
          
          IF (item.libraryName # NIL) THEN
            w. AttrObject("library-name", item.libraryName);
          END;
          
          str := item. CallConvToString();
          (*IF (str. array^ # "default") THEN*)
            w. AttrObject ("call-conv", str);
          (*END;*)
          moduleRepository := repositories. GetModule (item. name. str^);
          
          i := item. nestedItems;
          WHILE (i # NIL) DO
            IF (i IS Sym.Declaration) THEN
              WriteItem (i)
            END;
            i := i. nextNested
          END;
          w. EndTag
        
        | item: Sym.Import DO
          StartDecl ("import-decl", item);
          w. AttrStringLatin1 ("module", item. moduleName. str^);
          moduleRepository := repositories. GetModule (item. moduleName. str^);
          DeclDocString (item);
          w. EndTag
        
        | item: Sym.ConstDecl DO
          StartDecl ("const-decl", item);
          w. AttrString ("value", "unknown");
          DeclDocString (item);
          w. EndTag
        
        | item: Sym.TypeDecl DO
          StartDecl ("type-decl", item);
          DeclDocString (item);
          IF (item.type IS Sym.TypeVar) THEN  (* is type parameter *)
            WriteType ("type", item.type(Sym.TypeVar).srcCodeBound,
                       item.type(Sym.TypeVar).bound);
          ELSE
            WriteType ("type", item. srcCodeType, item. type);
          END;
          IF item.HasTypeParameters() THEN
            WriteTypePars(item.type.typePars);
          END;
          w. EndTag
          
        | item: Sym.VarDecl DO
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
          IF item.hasAliasList THEN
            WriteAliasList(item);
          END;
          w. EndTag
          
        | item: Sym.FieldDecl DO
          IF (item. exportMark # Sym.nameNotExported) THEN
            (* record fields may be part of the symbol file of a module even
               if they are not exported explicitly, but we don't want such
               fields to appear in a human readable interface description *)
            StartDecl ("field-decl", item);
            DeclDocString (item);
            WriteType ("type", item. srcCodeType, item. type);
            w. EndTag;
          END;
        
        | item: Sym.ProcDecl DO
          IF ~item. isForwardDecl THEN
            StartDecl ("procedure", item);
            DeclDocString (item);
            WriteTypeComponent (item. formalPars, item. formalPars);
            IF item.IsTypeBound() THEN
              WriteBaseDefinitions (item. Class(), item. name)
            END;
            w. EndTag
          END
        ELSE
        END
      END      
    END WriteItem;

  PROCEDURE WriteDeclList (list: Sym.Item; className: Sym.Name);
    VAR
      itemClass: Sym.Name;
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
      remoteURI, relativeURI: URI.URI;
      baseURI: URI.HierarchicalURI;
      keys: Object.ObjectArrayPtr;
    BEGIN
      thisModule := repositories. GetModule (module. name. str^);
      baseURI := thisModule. GetURI (Repository.modInterfaceHTML, FALSE);
      
      keys := modList. Keys();
      FOR i := 0 TO LEN (keys^)-1 DO
        remoteMod := keys[i](Repository.Module);

        w. StartTag ("module-ref", FALSE);
        w. AttrStringLatin1 ("name", remoteMod. name^);

        w. StartTag ("ref-target", FALSE);
        w. AttrStringLatin1 ("type", "html");
        remoteURI := remoteMod. GetURI (Repository.modInterfaceHTML, FALSE);
        relativeURI := remoteURI. MakeRelative (baseURI);
        w. AttrObject ("relative-uri", relativeURI.ToString());
        w. EndTag;

        w. EndTag
      END
    END WriteModuleRef;
  
  PROCEDURE WriteBaseClasses (topRecord: Sym.Record);
    VAR
      omitMethod: ArrayList.ArrayList;
      
    PROCEDURE WriteRecord (record: Sym.Record);
      VAR
        href: ARRAY 2*1024 OF CHAR;
        ns: Namespace.Namespace;
        i: LONGINT;
        module: Sym.Module;
        item: Sym.Item;
      
      PROCEDURE NewMethod (method: Sym.ProcDecl): BOOLEAN;
        VAR
          i: LONGINT;
        BEGIN
          FOR i := 0 TO omitMethod. size-1 DO
            IF (omitMethod. array[i](Sym.Declaration). name. str^ =
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
          IF (item(Sym.Declaration). exportMark # Sym.nameNotExported) &
             ((item IS Sym.FieldDecl) OR NewMethod (item(Sym.ProcDecl))) THEN
            WITH item: Sym.FieldDecl DO
              WriteReference ("inherited-field", item)
            | item: Sym.ProcDecl DO
              WriteReference ("inherited-method", item);
              omitMethod. Append (item)
            END
          END
        END;
        
        IF (record. baseType # NIL) THEN
          WriteRecord (record. baseType(Sym.Record))
        END;
        
        w. EndTag
      END WriteRecord;
    
    BEGIN
      omitMethod := ArrayList.New (16);
      IF (topRecord. baseType # NIL) THEN
        WriteRecord (topRecord. baseType(Sym.Record))
      END
    END WriteBaseClasses;
  
  PROCEDURE WriteKnownExtensions (type: Object.Object);
    VAR
      i: LONGINT;
      list: ArrayList.ArrayList;
      item: Sym.Item;
    BEGIN
      IF (extensionDict # NIL) & extensionDict. HasKey (type) THEN
        list := extensionDict. Get (type);
        FOR i := 0 TO list. size-1 DO
          item := list. array[i](Sym.Record). parent. nestedItems;
          WHILE ~((item IS Sym.TypeDecl) &
                  (item(Sym.TypeDecl). type = list. array[i])) DO
            item := item. nextNested
          END;
          WriteReference ("known-extension", item(Sym.TypeDecl));
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
    w. WriteURI (GetSystemId (repositories), absoluteDtdSystemId);
    w. Write8 ("'>");
(*    Sym.Prune (module, Exports.GetExports (module)); (* ... *)*)
    (* note: prune doesn't work if not-exported declarations are targets
       of a reference command; for this reason, such bad references must
       be flagged as errors *)
    
    w. StartTag ("interface-description", FALSE);
    DeclAttr (module);
    DeclDocString (module);
    WriteDeclList (module. nestedItems, NIL);
    ptr := module. nestedItems;
    WHILE (ptr # NIL) DO
      IF (ptr IS Sym.TypeDecl) &
         (ptr(Sym.TypeDecl). srcCodeType IS Sym.Record) &
         (ptr(Sym.TypeDecl). srcCodeType(Sym.Record). className # NIL) THEN
        (* note: we need to use `srcCodeType' here, or we will produce multiple
           class elements if there are any alias declarations on the record
           type *)
        w. StartTag ("class", FALSE);
        w. AttrStringLatin1 ("name", ptr(Sym.TypeDecl). srcCodeType(Sym.Record). className. str^);
        WriteDeclList (module. nestedItems, 
                     ptr(Sym.TypeDecl). srcCodeType(Sym.Record). className);
        WriteBaseClasses (ptr(Sym.TypeDecl). srcCodeType(Sym.Record));
        WriteKnownExtensions (ptr(Sym.TypeDecl). srcCodeType(Sym.Record));
        w. EndTag
      END;
      ptr := ptr. nextNested
    END;
    WriteModuleRef (moduleDict);
    w. EndTag;
    
    w. EndOfText
  END Write;

BEGIN
  dtdSystemId := NIL;
  absoluteDtdSystemId := TRUE;
END OOC:SymbolTable:InterfaceDescr.
