(* 	$Id$	 *)
MODULE OOC:Make:Entity:ModuleFile;
(*  Implements `Make' entities for various files associated with modules.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Msg, Out, Strings, Files, Time, ADT:String, ADT:StringBuffer, 
  URI, URI:Scheme:File,
  Make, Make:Entity:Resource, Make:Edge:TimeDep,
  OOC:Config, OOC:Config:Assembler, OOC:Error,
  OOC:Repository, OOC:Repository:GetImports, OOC:Repository:GetModuleClass,
  Sym := OOC:SymbolTable;



TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc = RECORD
    (Resource.EntityDesc)
    module-: Repository.Module;
    fileId-: Repository.FileId;
    maxTimeStampKnown: BOOLEAN;
    maxTimeStamp: Time.TimeStamp;
  END;


PROCEDURE InitEntity (entity: Entity; context: Make.Context;
                      module: Repository.Module; fileId: Repository.FileId);
  BEGIN
    Resource.Init (entity, context);
    entity. module := module;
    entity. fileId := fileId;
    entity. maxTimeStampKnown := FALSE;
    Time.InitTimeStamp (entity. maxTimeStamp, 0, 0);
  END InitEntity;

PROCEDURE NewEntity (context: Make.Context; module: Repository.Module;
                     fileId: Repository.FileId): Entity;
  VAR
    entity: Entity;
  BEGIN
    NEW (entity);
    InitEntity (entity, context, module, fileId);
    RETURN entity
  END NewEntity;


PROCEDURE (entity: Entity) GetId (VAR id: ARRAY OF CHAR);
  VAR
    type: ARRAY 64 OF CHAR;
  BEGIN
    COPY (entity. module. name^, id);
    Strings.Append (", ", id);
    CASE entity. fileId OF
    | Repository.modSymbolFile:
      type := "symbol file"
    | Repository.modModuleSource:
      type := "source"
    | Repository.modSymbolTableXML:
      type := "symbol table XML"
    | Repository.modInterfaceDescr:
      type := "interface description"
    | Repository.modInterfaceXML:
      type := "interface XML"
    | Repository.modInterfaceHTML:
      type := "interface HTML"
    END;
    Strings.Append (type, id)
  END GetId;


PROCEDURE GetEntity* (context: Make.Context; module: Repository.Module;
                      fileId: Repository.FileId): Entity;
  VAR
    node: Make.Node;
    entity: Entity;
  BEGIN
    (* if this node already exists in the graph, reuse this node *)
    node := context. nodeList;
    WHILE (node # NIL) DO
      IF (node IS Entity) &
         (node(Entity). module = module) &
         (node(Entity). fileId = fileId) THEN
        RETURN node(Entity)
      END;
      node := node. nextNode
    END;
    
    (* create new node *)
    entity := NewEntity (context, module, fileId);
    RETURN entity
  END GetEntity;


PROCEDURE (entity: Entity) GetURI* (): URI.URI;
  BEGIN
    RETURN entity. module. GetURI (entity. fileId);
  END GetURI;

PROCEDURE Exists (entity: Entity; fileId: Repository.FileId): BOOLEAN;
  VAR
    uri: URI.URI;
    path: Repository.URIBuffer;
  BEGIN
    IF (fileId = Repository.modCodeFileC) &
       (entity. module. symbolTable # NIL) &  (* have no symbol file yet *)
       (entity. module. symbolTable. class # Sym.mcStandard) THEN
      (* assume that for INTERFACE & FOREIGN modules the code file always
         exists; if it does not, we are not able to build it anyway, because
         it is always provided by the user *)
      RETURN TRUE;
    ELSE
      uri := entity. module. GetURI (fileId);
      uri(File.URI). GetPath (path);
      RETURN Files.Exists (path)
    END;
  END Exists;

PROCEDURE (entity: Entity) Exists* (): BOOLEAN;
  BEGIN
    RETURN Exists (entity, entity. fileId)
  END Exists;

PROCEDURE (entity: Entity) GetTimeStamp* (VAR ts: Time.TimeStamp);
  VAR
    aEdge: Make.Edge;
    ts2: Time.TimeStamp;
  BEGIN
    entity. module. GetTimeStamp (entity. fileId, ts);
    
    IF (entity. fileId = Repository.modHeaderFileC) OR
       (entity. fileId = Repository.modDeclFileC) OR
       (entity. fileId = Repository.modCodeFileC) THEN
      (* the time stamp of the entity is the maximum over the time stamp of
         the entity itself and the time stamps of all files included by it *)
      IF ~entity. maxTimeStampKnown THEN
        aEdge := entity. ancestorList;
        WHILE (aEdge # NIL) DO
          IF (aEdge. ancestor IS Entity) &
             ((aEdge. ancestor(Entity). fileId = Repository.modHeaderFileC) OR
              (aEdge. ancestor(Entity). fileId = Repository.modHeaderFileC)) THEN
            aEdge. ancestor(Entity). GetTimeStamp (ts2);
            IF (ts2. Cmp (ts) > 0) THEN
              ts := ts2
            END
          END;
          aEdge := aEdge. nextAncestor
        END;
        
        entity. maxTimeStamp := ts;
        entity. maxTimeStampKnown := TRUE
      END;
      ts := entity. maxTimeStamp
    END
  END GetTimeStamp;

PROCEDURE (entity: Entity) Id* (): String.String;
  VAR
    str: StringBuffer.StringBuffer;
    uri: URI.URI;
    s: ARRAY 1024 OF CHAR;
  BEGIN
    str := StringBuffer.New ("[OOC:Make:Entity:ModuleFile(");
    CASE entity. fileId OF
    | Repository.modSymbolFile:
      str. AppendString ("modSymbolFile")
    | Repository.modModuleSource:
      str. AppendString ("modModuleSource")
    | Repository.modSymbolTableXML:
      str. AppendString ("modSymbolTableXML")
    | Repository.modInterfaceDescr:
      str. AppendString ("modInterfaceDescr")
    | Repository.modInterfaceXML:
      str. AppendString ("modInterfaceXML")
    | Repository.modInterfaceHTML:
      str. AppendString ("modInterfaceHTML")
    | Repository.modObjectFile:
      str. AppendString ("modObjectFile")
    | Repository.modHeaderFileC:
      str. AppendString ("modHeaderFileC")
    | Repository.modDeclFileC:
      str. AppendString ("modDeclFileC")
    | Repository.modCodeFileC:
      str. AppendString ("modCodeFileC")
    | Repository.modAssemblerFile:
      str. AppendString ("modAssemblerFile")
    | Repository.modMainFileC:
      str. AppendString ("modMainFileC")
    | Repository.modMainFileAssembler:
      str. AppendString ("modMainFileAssembler")
    | Repository.modMainObjectFile:
      str. AppendString ("modMainObjectFile")
    | Repository.modExecutable:
      str. AppendString ("modExecutable")
    END;
    str. AppendString (")] ");
    uri := entity. GetURI();
    uri. GetString (s);
    str. AppendString (s);
    RETURN str.ToString()
  END Id;


PROCEDURE AddTimeDep (context: Make.Context; descendant, ancestor: Entity);
  VAR
    dep: TimeDep.Edge;
  BEGIN
    dep := TimeDep.New (descendant, ancestor);
    context. AddDependence (dep)
  END AddTimeDep;

PROCEDURE AncestorClosure* (descendant: Entity; entity: Entity;
                            fileId: Repository.FileId);
  VAR
    importedEntity: Entity;
    dummyErrList: Error.List;
    import: Repository.Import;
  BEGIN
    IF ~descendant. IsDescendantOf (entity) THEN
      descendant. AddAncestor (entity);
      
      GetImports.GetImports (entity. module, dummyErrList);
      (* ignore any errors when scanning the imports; for dependency scanning,
         malformed modules are of no importance *)
      import := entity. module. importList;
      WHILE (import # NIL) DO
        importedEntity := GetEntity(entity. context, import. imported, fileId);
        AncestorClosure (descendant, importedEntity, fileId);
        import := import. nextImport
      END
    END
  END AncestorClosure;

PROCEDURE DiscoverCompile* (command: Make.Command; module: Repository.Module);
  VAR
    ancestorEntity: Entity;
    dummyErrList: Error.List;
    import: Repository.Import;
  BEGIN
    ASSERT (command. state = Make.commandUndiscovered);
    
    GetImports.GetImports (module, dummyErrList);
    (* ignore any errors when scanning the imports; for dependency scanning,
       malformed modules are of no importance *)
    import := module. importList;
    WHILE (import # NIL) DO
      ancestorEntity := GetEntity (command. context, import. imported, Repository.modSymbolFile);
      command. AddAncestor (ancestorEntity);
      import := import. nextImport
    END
  END DiscoverCompile;

PROCEDURE (entity: Entity) Discover*(): Make.EntityState;
  VAR
    srcEntity: Entity;
    usageData: Make.Entity;
    nextState: Make.EntityState;
    dummy: Sym.Module;
    res: Msg.Msg;
  
  PROCEDURE AddImportDeps (entity: Entity; fileId: Repository.FileId;
                           timeDep: BOOLEAN);
    VAR
      ancestorEntity: Entity;
      dummyErrList: Error.List;
      import: Repository.Import;
    BEGIN
      GetImports.GetImports (entity. module, dummyErrList);
      (* ignore any errors when scanning the imports; for dependency scanning,
         malformed modules are of no importance *)
      import := entity. module. importList;
      WHILE (import # NIL) DO
        ancestorEntity := GetEntity (entity. context, import. imported, fileId);
        IF timeDep THEN
          AddTimeDep (entity. context, entity, ancestorEntity)
        ELSE
          entity. AddAncestor (ancestorEntity)
        END;
        import := import. nextImport
      END
    END AddImportDeps;

  PROCEDURE AncestorState (entity: Entity; ancestorType: Repository.FileId): Make.EntityState;
    VAR
      aEdge: Make.Edge;
      ancestor: Make.Node;
      build: BOOLEAN;
    BEGIN
      build := ~entity. Exists();
      aEdge := entity. ancestorList;
      WHILE (aEdge # NIL) DO
        ancestor := aEdge. ancestor;
        WITH ancestor: Entity DO
          IF (ancestorType < 0) OR (ancestor. fileId = ancestorType) THEN
            IF (ancestor. state = Make.entityInvalid) THEN
              RETURN Make.entityInvalid
            ELSIF aEdge. IsInvalid() THEN
              build := TRUE
            END
          END
        ELSE
          (* ignore all other ancestors (like UsageData) *)
        END;
        aEdge := aEdge. nextAncestor
      END;
      IF build THEN
        RETURN Make.entityBuild
      ELSE
        RETURN Make.entityValid
      END
    END AncestorState;
  
  PROCEDURE MissingFile (entity: Entity);
    VAR
      uri: URI.URI;
      s: ARRAY 1024 OF CHAR;
    BEGIN
      (* ... FIXME error messages should use the errList mechanism *)
      Out.String ("Error: File does not exist ");
      uri := entity. GetURI();
      uri. GetString (s);
      Out.String (s);
      Out.Ln;
    END MissingFile;
  
  BEGIN
    CASE entity. fileId OF
    | Repository.modModuleSource:
      (* the module itself depends on nothing; dependencies on its imported
         symbol files have the module's symbol file as target, not the 
         module source code itself *)
      IF entity. Exists() THEN
        RETURN Make.entityValid
      ELSE
        MissingFile (entity);
        RETURN Make.entityInvalid
      END
      
    | Repository.modSymbolFile:
      (* the symbol file also marks the time of the last compilation of the
         module; this implies, that it is invalid if the module source is
         more recent, or if any of the imported symbol files have changed *)
      IF (entity. state = Make.entityUndiscovered) THEN
        IF entity. Exists() & ~Exists (entity, Repository.modModuleSource) THEN
          (* we have a symbol file, but no source file; because we cannot
             build a new one, shortcut the validation logic and assume the
             the symbol file is up to date with respect to the source *)
          AddImportDeps (entity, Repository.modSymbolFile, TRUE);
          RETURN Make.entityUndiscovered+2
        ELSE
          (* add dependence on the source code file *)
          AddTimeDep (entity. context, entity,
                      GetEntity (entity. context, entity. module,
                                 Repository.modModuleSource));
          RETURN entity. state+1
        END
      ELSIF (entity. state = Make.entityUndiscovered+1) THEN
        IF ~entity. HasInvalidAncestor() &
           entity. HasInvalidAncestorEdge() THEN
          (* the source code ancestor file does exist, but the current entity
             is either missing or outdated: rebuild *)
          RETURN Make.entityBuild
        ELSIF ~entity. Exists() THEN
          (* we don't want to rebuild the symbol file after checking with the
             source file, but the symbol file does not exist; no chance to fix
             this, this entity is invalid *)
          MissingFile (entity);
          RETURN Make.entityInvalid
        ELSE
          (* the symbol file exists, and it is more recent than the
             corresponding source file (if one exists); add dependencies for
             all symbol files the current entity is relying on *)
          AddImportDeps (entity, Repository.modSymbolFile, TRUE);
          RETURN entity. state+1
        END
      ELSE  (* (entity. state = Make.entityUndiscovered+1) *)
        (* traverse list of ancestor symbol files; if one of the ancestors
           is invalid, the current node cannot be rebuild is is therefore
           invalid, too; if the node if invalid with respect to an ancestor
           symbol file, it has to be rebuild *)
        nextState := AncestorState (entity, Repository.modSymbolFile);
        IF (nextState = Make.entityValid) &
           (entity. module. symbolTable = NIL) THEN
          (* the analysis says that the symbol file is valid: read in its
             data, because it may hold information like the name of an
             external .c file, which are required to compile the current
             module *)
          dummy := entity. module. GetSymbolTable(res);
        END;
        RETURN nextState;
      END
      
    | Repository.modInterfaceDescr:
      (* the interface XML code depends on the symbol file of the module, which
         includes descriptions of declarations, and on the symbol files of all
         modules imported by it; actually, it may even contain 
         information from modules that are imported indirectly, e.g., when
         inheriting a method description from a remote base class  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module, Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        AddImportDeps (entity, Repository.modSymbolFile, TRUE);
        (* fixme: add_import should be transitive in this case! ... *)
        
        usageData := entity. context. GetNamedEntity ("UsageData");
        IF (usageData # NIL) THEN
          entity. AddAncestor (usageData)
        END;
        
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, Repository.modSymbolFile)
      END
      
    | Repository.modInterfaceXML:
      (* the interface XML code depends on the symbol file and the XML
         interface descriptions of all imported modules; the latter is
         necessary because the current HTML generation process relies on
         the XML files of directly and indirectly imported modules *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module, Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        (* fixme: dep on all imported XML missing... *)
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, Repository.modSymbolFile)
      END
      
    | Repository.modSymbolTableXML:
      (* the symbol table XML stuff depends on the
         module's symbol file; this ensure that the module has been compiled
         successfully, and that its imports are all up to date *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module, Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, Repository.modSymbolFile)
      END
      
    | Repository.modInterfaceHTML:
      (* HTML is generated from the XML interface description *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module, Repository.modInterfaceDescr);
        AddTimeDep (entity. context, entity, srcEntity);
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, Repository.modInterfaceDescr)
      END
      
    | Repository.modHeaderFileC:
      (* The contents of the C header file are a subset of the contents of the
         module's symbol file.   For this reason, the best check if the header
         file is up to date is to compare the fingerprint of the symbol file
         from which the header file was derived with the current fingerprint
         of the symbol file.  If they differ, then the header file is invalid
         and a new one must be generated.  For this to work, the header file
         must contain a copy of the symbol file fingerprint, say in base64
         encoded form in the very first line of the file.
         
         ... FIXME: The above is the most efficient solution.  For the moment,
         the header file is required to be more recent than the symbol file.
         
         The header is also dependent on all files that are included by it,
         because these files must exist before it can be used.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module,
                                Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        AddImportDeps (entity, Repository.modHeaderFileC, FALSE);
        (* ... note: AddImportDeps may create too many deps *)
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, Repository.modHeaderFileC)
      END
      
    | Repository.modDeclFileC:
      (* For the declaration file to be up to date, it must be more recent than
         the symbol file, which in turn must be more recent than the source
         code file.  The file is also dependent on all files that are included
         by it, because these files must exist before it can be used.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module,
                                Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        
        entity. AddAncestor (GetEntity (entity. context, entity. module,
                                        Repository.modHeaderFileC));
        AddImportDeps (entity, Repository.modHeaderFileC, FALSE);
        (* ... note: AddImportDeps may create too many deps *)
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, -1)
      END
      
    | Repository.modCodeFileC:
      (* The C code of a module must be more recent than the symbol file, which
         in turn must be more recent than the source code.  It also depends on
         the existence of the declaration file.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module,
                                Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        srcEntity := GetEntity (entity. context, entity. module,
                                Repository.modDeclFileC);
        entity. AddAncestor (srcEntity);
        RETURN entity. state+1
      ELSE
        nextState := AncestorState (entity, -1);
        IF (nextState = Make.entityBuild) &
           (entity. module. symbolTable. class # Sym.mcStandard) THEN
          (* we cannot build the .c file of an INTERFACE or FOREIGN module *)
          nextState := Make.entityValid;
        END;
        RETURN nextState;
      END
      
    | Repository.modAssemblerFile:
      (* The assembler code of a module must be more recent than the symbol
         file, which in turn must be more recent than the source code.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module,
                                Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        RETURN entity. state+1
      ELSE
        nextState := AncestorState (entity, -1);
        IF (nextState = Make.entityBuild) &
           (entity. module. symbolTable. class # Sym.mcStandard) THEN
          (* we cannot build the code of an INTERFACE or FOREIGN module *)
          nextState := Make.entityValid;
        END;
        RETURN nextState;
      END
      
    | Repository.modMainFileC:
      (* This file depends on the existence of all included header files.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        entity. AddAncestor (GetEntity (entity. context, entity. module,
                                        Repository.modSymbolFile));
        RETURN entity. state+1
      ELSE
        IF entity. HasInvalidAncestor() THEN
          RETURN Make.entityInvalid
        ELSE
          RETURN Make.entityBuild
        END
      END
      
    | Repository.modMainFileAssembler:
      (* This file depends on the existence of all object files.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        entity. AddAncestor (GetEntity (entity. context, entity. module,
                                        Repository.modObjectFile));
        RETURN entity. state+1
      ELSE
        IF entity. HasInvalidAncestor() THEN
          RETURN Make.entityInvalid
        ELSE
          RETURN Make.entityBuild
        END
      END
      
    | Repository.modObjectFile:
      (* For the C back-end, the object file is derived from the C code file.
         If the code file is more recent than the object file, then the C
         compiler must create a new one.  Note: This time stamp based approach
         fails if the C compiler leaves incomplete files behind if
         interruped.  *)
      IF (entity. state = Make.entityUndiscovered) THEN
        IF entity. Exists() & ~Exists (entity, Repository.modModuleSource) THEN
          (* we have an object file, but no source file; because we cannot
             build a new one, shortcut the validation logic and assume the
             the object file is up to date *)
          RETURN Make.entityValid
        ELSE
          srcEntity := GetEntity (entity. context, entity. module,
                                  Repository.modSymbolFile);
          AddTimeDep (entity. context, entity, srcEntity);
          RETURN entity. state+1
        END
      ELSIF (entity. state = Make.entityUndiscovered+1) THEN
        IF Assembler.useAssembler &
           ((entity. module. symbolTable # NIL) &
            (entity. module. symbolTable. class = Sym.mcStandard) OR
            (GetModuleClass.GetModuleClass (entity. module) = Sym.mcStandard)) THEN
          srcEntity := GetEntity (entity. context, entity. module,
                                  Repository.modAssemblerFile);
        ELSE
          srcEntity := GetEntity (entity. context, entity. module,
                                  Repository.modCodeFileC);
        END;
        AddTimeDep (entity. context, entity, srcEntity);
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, -1)
      END
    
    | Repository.modMainObjectFile:
      IF (entity. state = Make.entityUndiscovered) THEN
        IF Assembler.useAssembler THEN
          srcEntity := GetEntity (entity. context, entity. module,
                                  Repository.modMainFileAssembler);
        ELSE
          srcEntity := GetEntity (entity. context, entity. module,
                                  Repository.modMainFileC);
        END;
        AddTimeDep (entity. context, entity, srcEntity);
        RETURN entity. state+1
      ELSE
        RETURN AncestorState (entity, -1)
      END
    
    | Repository.modExecutable:
      IF (entity. state = Make.entityUndiscovered) THEN
        srcEntity := GetEntity (entity. context, entity. module,
                                Repository.modSymbolFile);
        AddTimeDep (entity. context, entity, srcEntity);
        RETURN entity. state+1
      ELSIF (entity. state = Make.entityUndiscovered+1) THEN
        IF entity. HasInvalidAncestor() THEN
          RETURN Make.entityInvalid
        ELSE
          srcEntity := GetEntity (entity. context, entity. module,
                                  Repository.modMainObjectFile);
          AddTimeDep (entity. context, entity, srcEntity);
          
          (* add run-time module RT0 to dependencies; note: this may 
             not the right place to do this if other back-ends are 
             supported ... *)
          srcEntity := GetEntity (entity. context, 
            Config.repositories. GetModule (Config.runtimeModule),
            Repository.modObjectFile);
          entity. AddAncestor (srcEntity);
          
          AncestorClosure (entity, GetEntity (entity. context, entity. module,
                          Repository.modObjectFile), Repository.modObjectFile);
          RETURN entity. state+1
        END
      ELSE
        RETURN AncestorState (entity, -1)  (* exclude symbol file... *)
      END
    END
  END Discover;


PROCEDURE CreateClosure* (closureGroup: Make.Entity; entity: Entity);
(**Adds @oparam{entity} and the entities of all modules that are directly or
   indirectly imported by @oparam{entity} to the group @oparam{closureGroup}.
   The newly created entities inherit the file id from @oparam{entity}.  For
   example, if @oparam{entity} has an id @oconst{Repository.modModuleSource},
   then, after completion, the list of descendants of @oparam{closureGroup}
   contains @oparam{entity} and entities with the file id
   @oconst{Repository.modModuleSource} for all modules imported into
   @oparam{entity}.  *)
  VAR
    importedEntity: Entity;
    dummyErrList: Error.List;
    import: Repository.Import;
  BEGIN
    IF ~closureGroup. IsDescendantOf (entity) THEN
      (* add `entity' to the group *)
      closureGroup. AddAncestor (entity);
      
      GetImports.GetImports (entity. module, dummyErrList);
      (* ignore any errors when scanning the imports; for dependency scanning,
         malformed modules are of no importance *)
      import := entity. module. importList;
      WHILE (import # NIL) DO
        importedEntity := GetEntity (entity. context, import. imported, entity. fileId);
        CreateClosure (closureGroup, importedEntity);
        import := import. nextImport
      END
    END
  END CreateClosure;

END OOC:Make:Entity:ModuleFile.
