MODULE OOC:Auxiliary:ParseModule;

IMPORT
  Msg, URI,
  OOC:Config, OOC:Config:Pragmas, OOC:Repository,
  
  OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:Builder:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Builder,
  OOC:AST:ExtTree:CreateSymTab, OOC:SymbolTable:CreateNamespace,
  OOC:Auxiliary:WriteSymbolFile;
  


PROCEDURE ParseModule* (m: Repository.Module;
                        checkModuleName, createNamespace, writeSymbolFile: BOOLEAN;
                        VAR ast: AST.Node;
                        VAR symTab: Sym.Module;
                        VAR pragmaHistory: Pragmas.History;
                        VAR errList: Error.List);
(**If this function is called multiple times for the same module while
   evaluating a build command, only on of these calls should pass @code{TRUE}
   to @oparam{writeSymbolFile}.  Otherwise the build logic implemented in
   @omodule{*OOC:Make} would get confused, because it assumes that the time
   of the symbol file designates the time of the last compilation.  *)
  VAR
    res: Msg.Msg;
    inputBuffer: InputBuffer.Buffer;
    scannerBuilder: BasicList.Builder;
    astBuilder: ExtTree.Builder;
    stb: Builder.Builder;
    uri: URI.URI;
    uriStr: Repository.URIBuffer;
  BEGIN
    inputBuffer := m. GetInputBuffer (res);
    IF (inputBuffer = NIL) THEN
      ast := NIL;
      symTab := NIL;
      pragmaHistory := NIL;
      uri := m. GetURI (Repository.modModuleSource);
      uri. GetString (uriStr);
      errList := Error.NewList (uriStr);
      errList. Append (res)
    ELSE
      errList := inputBuffer. errList;
      scannerBuilder := BasicList.New (inputBuffer, TRUE);
      Scanner.ScanInput (scannerBuilder, Config.pragmas, Scanner.enableAll);
      inputBuffer. Close;
      pragmaHistory := scannerBuilder. pragmaHistory;
      
      ast := NIL;
      IF (errList. msgCount = 0) THEN
        astBuilder := ExtTree.New();
        IF checkModuleName THEN
          astBuilder. SetModuleName (m. name^)
        END;
        ast := Parser.Module (scannerBuilder. head, 
                              astBuilder, errList,
                              Parser.enableAll)
      END;

      symTab := NIL;
      IF (errList. msgCount = 0) THEN
        stb := Builder.New();
        symTab := CreateSymTab.CreateSymTab
          (ast, stb, m. GetURI (Repository.modModuleSource),
           m. origin. baseURI);
        IF createNamespace THEN
          IF (errList. msgCount = 0) THEN
            CreateNamespace.CreateNamespace (symTab, errList)
          END;
          IF (errList. msgCount = 0) & writeSymbolFile THEN
            (* no error in the declaration part of the module: write the
               symbol table to file, skipping any external references and
               strictly local information on the way *)
            WriteSymbolFile.WriteSymbolFile (m, symTab, errList);
          END
        END
      END
    END
  END ParseModule;

END OOC:Auxiliary:ParseModule.
