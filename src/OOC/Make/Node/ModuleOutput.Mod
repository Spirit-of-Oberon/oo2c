MODULE OOC:Make:Node:ModuleOutput;

IMPORT
  Strings, Files, Msg, Time, URI, URI:Scheme:File, OOC:Error, OOC:Repository,
  OOC:Repository:GetImports, OOC:Make, OOC:Make:Edge:TimeStampDep,
  OOC:Make:Edge:StaticDep;



TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD
    (Make.NodeDesc)
    module-: Repository.Module;
    fileId-: Repository.FileId;
  END;


PROCEDURE InitNode (n: Node; static: BOOLEAN; 
                    module: Repository.Module; fileId: Repository.FileId);
  BEGIN
    Make.InitNode (n, static);
    n. module := module;
    n. fileId := fileId
  END InitNode;

PROCEDURE NewNode (static: BOOLEAN; 
                   module: Repository.Module; fileId: Repository.FileId): Node;
  VAR
    n: Node;
  BEGIN
    NEW (n);
    InitNode (n, static, module, fileId);
    RETURN n
  END NewNode;


PROCEDURE (n: Node) GetId* (VAR id: ARRAY OF CHAR);
  VAR
    type: ARRAY 64 OF CHAR;
  BEGIN
    COPY (n. module. name^, id);
    Strings.Append (", ", id);
    CASE n. fileId OF
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

PROCEDURE GetNode* (dg: Make.DepGraph; module: Repository.Module;
                    fileId: Repository.FileId): Node;
  VAR
    node: Make.Node;
    n: Node;
  BEGIN
    (* if this node already exists in the graph, reuse this node *)
    node := dg. nodeList;
    WHILE (node # NIL) DO
      IF (node IS Node) &
         (node(Node). module = module) &
         (node(Node). fileId = fileId) THEN
        RETURN node(Node)
      END;
      node := node. nextNode
    END;
    
    (* create new node *)
    n := NewNode (fileId = Repository.modModuleSource, module, fileId);
    dg. AddNode (n);
    RETURN n
  END GetNode;


PROCEDURE (n: Node) GetBuildCommand*(): Make.BuildCmd;
  BEGIN
    ASSERT (n. dg. buildCmds[n. fileId] # NIL);
    RETURN n. dg. buildCmds[n. fileId]
  END GetBuildCommand;

PROCEDURE (n: Node) Exists* (): BOOLEAN;
  VAR
    uri: URI.URI;
    path: Repository.URIBuffer;
    res: Msg.Msg;
  BEGIN
    uri := n. module. GetURI (n. fileId, res);
    IF (res = NIL) THEN
      uri(File.URI). GetPath (path);
      RETURN Files.Exists (path)
    ELSE
      RETURN FALSE
    END
  END Exists;

PROCEDURE (n: Node) GetTimeStamp* (VAR ts: Time.TimeStamp);
  BEGIN
    n. module. GetTimeStamp (n. fileId, ts)
  END GetTimeStamp;

PROCEDURE (n: Node) AddDependencies*;
  VAR
    srcNode, usageData: Make.Node;
  
  PROCEDURE AddImportDeps (n: Node; fileId: Repository.FileId);
    VAR
      ancestorNode: Make.Node;
      dummyErrList: Error.List;
      import: Repository.Import;
    BEGIN
      GetImports.GetImports (n. module,
                             n. dg. config. pragmas,
                             n. dg. config. repositories,
                             dummyErrList);
      (* ignore any errors when scanning the imports; for dependency scanning,
         malformed modules are of no importance *)
      import := n. module. importList;
      WHILE (import # NIL) DO
        ancestorNode := GetNode (n. dg, import. imported, fileId);
        n. dg. AddDependency (TimeStampDep.New (n, ancestorNode));
        import := import. nextImport
      END
    END AddImportDeps;
  
  BEGIN
    CASE n. fileId OF
    | Repository.modModuleSource:
      (* the module itself depends on nothing; dependencies on its imported
         symbol files have the module's symbol file as target, not the 
         module source code itself *)
         
    | Repository.modSymbolFile:
      (* the symbol file also marks the time of the last compilation of the
         module; this implies, that it is invalid if the module source is
         more recent, or if any of the imported symbol files have changed *)
      srcNode := GetNode (n. dg, n. module, Repository.modModuleSource);
      n. dg. AddDependency (TimeStampDep.New (n, srcNode));
      AddImportDeps (n, Repository.modSymbolFile)
      
    | Repository.modInterfaceDescr:
      (* the interface XML code depends on the symbol file of the module, which
         includes descriptions of declarations, and on the symbol files of all
         modules imported by it; actually, it may even contain information
         information from modules that are imported indirectly, e.g., when
         inheriting a method description from a remote base class  *)
      srcNode := GetNode (n. dg, n. module, Repository.modSymbolFile);
      n. dg. AddDependency (TimeStampDep.New (n, srcNode));
      AddImportDeps (n, Repository.modSymbolFile);
      (* fixme: add_import should be transitive in this case! ... *)
      
      usageData := n. dg. GetNamedNode ("UsageData");
      IF (usageData # NIL) THEN
        n. dg. AddDependency (TimeStampDep.New (n, usageData))
      END;
      
    | Repository.modInterfaceXML:
      (* the interface XML code depends on the symbol file and the XML
         interface descriptions of all imported modules; the latter is
         necessary because the current HTML generation process relies on
         the XML files of directly and indirectly imported modules *)
      srcNode := GetNode (n. dg, n. module, Repository.modSymbolFile);
      n. dg. AddDependency (TimeStampDep.New (n, srcNode))
      
    | Repository.modSymbolTableXML:
      (* the symbol table XML stuff depends on the
         module's symbol file; this ensure that the module has been compiled
         successfully, and that its imports are all up to date *)
      srcNode := GetNode (n. dg, n. module, Repository.modSymbolFile);
      n. dg. AddDependency (TimeStampDep.New (n, srcNode))
      
    | Repository.modInterfaceHTML:
      (* HTML is generated from the XML interface description *)
      srcNode := GetNode (n. dg, n. module, Repository.modInterfaceDescr);
      n. dg. AddDependency (TimeStampDep.New (n, srcNode))
    END
  END AddDependencies;


PROCEDURE CreateClosure* (closureGroup: Make.Node; node: Node);
(**Adds @oparam{node} and the nodes of all modules that are directly or
   indirectly imported by @oparam{node} to the group @oparam{closureGroup}.
   The newly created nodes inherited the file id from @oparam{node}.  For
   example, if @oparam{node} has an id @oconst{Repository.modModuleSource},
   then, after completion, the list of descendents of @oparam{closureGroup}
   contains @oparam{node} and nodes with the file id
   @oconst{Repository.modModuleSource} for all modules imported into
   @oparam{node}.  *)
  VAR
    importedNode: Node;
    dummyErrList: Error.List;
    import: Repository.Import;
  BEGIN
    IF ~node. IsAncestor (closureGroup) THEN
      (* add `node' to the group *)
      closureGroup. dg. AddDependency (StaticDep.New (closureGroup, node, FALSE));
      
      GetImports.GetImports (node. module,
                             node. dg. config. pragmas,
                             node. dg. config. repositories,
                             dummyErrList);
      (* ignore any errors when scanning the imports; for dependency scanning,
         malformed modules are of no importance *)
      import := node. module. importList;
      WHILE (import # NIL) DO
        importedNode := GetNode (node. dg, import. imported, node. fileId);
        CreateClosure (closureGroup, importedNode);
        import := import. nextImport
      END
    END
  END CreateClosure;

END OOC:Make:Node:ModuleOutput.
