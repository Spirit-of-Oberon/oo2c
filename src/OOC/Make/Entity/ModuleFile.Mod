MODULE OOC:Make:Entity:ModuleFile;

IMPORT
  Strings, Files, Msg, Time, ADT:String, URI, URI:Scheme:File,
  Make, Make:Entity:Resource, Make:Edge:TimeDep,
  ConfigOOC := OOC:Auxiliary:Config, OOC:Error,
  OOC:Repository, OOC:Repository:GetImports;



TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc = RECORD
    (Resource.EntityDesc)
    module-: Repository.Module;
    fileId-: Repository.FileId;
  END;


PROCEDURE InitEntity (entity: Entity; 
                    module: Repository.Module; fileId: Repository.FileId);
  BEGIN
    Resource.Init (entity);
    entity. module := module;
    entity. fileId := fileId
  END InitEntity;

PROCEDURE NewEntity (module: Repository.Module; fileId: Repository.FileId): Entity;
  VAR
    entity: Entity;
  BEGIN
    NEW (entity);
    InitEntity (entity, module, fileId);
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
    entity := NewEntity (module, fileId);
    context. AddNode (entity);
    RETURN entity
  END GetEntity;


PROCEDURE (entity: Entity) GetURI* (): URI.URI;
  VAR
    res: Msg.Msg;
  BEGIN
    RETURN entity. module. GetURI (entity. fileId, res);
  END GetURI;

PROCEDURE (entity: Entity) Exists* (): BOOLEAN;
  VAR
    uri: URI.URI;
    path: Repository.URIBuffer;
    res: Msg.Msg;
  BEGIN
    uri := entity. module. GetURI (entity. fileId, res);
    IF (res = NIL) THEN
      uri(File.URI). GetPath (path);
      RETURN Files.Exists (path)
    ELSE
      RETURN FALSE
    END
  END Exists;

PROCEDURE (entity: Entity) GetTimeStamp* (VAR ts: Time.TimeStamp);
  BEGIN
    entity. module. GetTimeStamp (entity. fileId, ts)
  END GetTimeStamp;

PROCEDURE (entity: Entity) Id* (): String.String;
  VAR
    str: String.String;
    uri: URI.URI;
    s: ARRAY 1024 OF CHAR;
  BEGIN
    str := String.New ("[OOC:Make:Entity:ModuleFile(");
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
    END;
    str. AppendString (")] ");
    uri := entity. GetURI();
    uri. GetString (s);
    str. AppendString (s);
    RETURN str
  END Id;


PROCEDURE AddTimeDep (context: Make.Context; descendent, ancestor: Entity);
  VAR
    dep: TimeDep.Edge;
  BEGIN
    dep := TimeDep.New (descendent, ancestor);
    context. AddDependence (dep)
  END AddTimeDep;

PROCEDURE DiscoverCompile* (command: Make.Command; module: Repository.Module);
  VAR
    ancestorEntity: Entity;
    dummyErrList: Error.List;
    import: Repository.Import;
    config: ConfigOOC.Config;
  BEGIN
    ASSERT (command. state = Make.commandUndiscovered);
    
    config := command. context. config(ConfigOOC.Config);
    GetImports.GetImports (module, config. pragmas,
                           config. repositories, dummyErrList);
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
  
  PROCEDURE AddImportDeps (entity: Entity; fileId: Repository.FileId);
    VAR
      ancestorEntity: Entity;
      dummyErrList: Error.List;
      import: Repository.Import;
      config: ConfigOOC.Config;
    BEGIN
      config := entity. context. config(ConfigOOC.Config);
      GetImports.GetImports (entity. module, config. pragmas,
                             config. repositories, dummyErrList);
      (* ignore any errors when scanning the imports; for dependency scanning,
         malformed modules are of no importance *)
      import := entity. module. importList;
      WHILE (import # NIL) DO
        ancestorEntity := GetEntity (entity. context, import. imported, fileId);
        AddTimeDep (entity. context, entity, ancestorEntity);
        import := import. nextImport
      END
    END AddImportDeps;

  PROCEDURE AncestorState (entity: Entity; ancestorType: Repository.FileId): Make.EntityState;
    VAR
      aEdge: Make.Edge;
      ancestor: Make.Node;
      build: BOOLEAN;
    BEGIN
      build := FALSE;
      aEdge := entity. ancestorList;
      WHILE (aEdge # NIL) DO
        ancestor := aEdge. ancestor;
        WITH ancestor: Entity DO
          IF (ancestor. fileId = ancestorType) THEN
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
  
  BEGIN
    CASE entity. fileId OF
    | Repository.modModuleSource:
      (* the module itself depends on nothing; dependencies on its imported
         symbol files have the module's symbol file as target, not the 
         module source code itself *)
      IF entity. Exists() THEN
        RETURN Make.entityValid
      ELSE
        RETURN Make.entityInvalid
      END
      
    | Repository.modSymbolFile:
      (* the symbol file also marks the time of the last compilation of the
         module; this implies, that it is invalid if the module source is
         more recent, or if any of the imported symbol files have changed *)
      IF (entity. state = Make.entityUndiscovered) THEN
        (* add dependence on the source code file *)
        AddTimeDep (entity. context, entity,
                    GetEntity (entity. context, entity. module,
                               Repository.modModuleSource));
        RETURN entity. state+1
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
          RETURN Make.entityInvalid
        ELSE
          (* the symbol file exists, and it is more recent than the
             corresponding source file (if one exists); add dependencies for
             all symbol files the current entity is relying on *)
          AddImportDeps (entity, Repository.modSymbolFile);
          RETURN entity. state+1
        END
      ELSE  (* (entity. state = Make.entityUndiscovered+1) *)
        (* traverse list of ancestor symbol files; if one of the ancestors
           is invalid, the current node cannot be rebuild is is therefore
           invalid, too; if the node if invalid with respect to an ancestor
           symbol file, it has to be rebuild *)
        RETURN AncestorState (entity, Repository.modSymbolFile)
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
        AddImportDeps (entity, Repository.modSymbolFile);
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
    END
  END Discover;


PROCEDURE CreateClosure* (closureGroup: Make.Entity; entity: Entity);
(**Adds @oparam{entity} and the entities of all modules that are directly or
   indirectly imported by @oparam{entity} to the group @oparam{closureGroup}.
   The newly created entities inherit the file id from @oparam{entity}.  For
   example, if @oparam{entity} has an id @oconst{Repository.modModuleSource},
   then, after completion, the list of descendents of @oparam{closureGroup}
   contains @oparam{entity} and entities with the file id
   @oconst{Repository.modModuleSource} for all modules imported into
   @oparam{entity}.  *)
  VAR
    importedEntity: Entity;
    dummyErrList: Error.List;
    import: Repository.Import;
    config: ConfigOOC.Config;
  BEGIN
    IF ~closureGroup. IsDescendentOf (entity) THEN
      (* add `entity' to the group *)
      closureGroup. AddAncestor (entity);
      
      config := entity. context. config(ConfigOOC.Config);
      GetImports.GetImports (entity. module,
                             config. pragmas,
                             config. repositories,
                             dummyErrList);
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
