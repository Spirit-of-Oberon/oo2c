MODULE OOC:Auxiliary:ParseModule;

IMPORT
  Channel, Files, Msg, URI, OOC:Auxiliary:Config, OOC:Repository,
  
  OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:Builder:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree,
  OOC:SymbolTable:Item, OOC:SymbolTable:Builder,
  OOC:AST:ExtTree:CreateSymTab, OOC:SymbolTable:CreateNamespace,
  OOC:SymbolTable:Exports, OOC:Doc:ResolveRef;
  


PROCEDURE ParseModule* (m: Repository.Module; config: Config.Config;
                        createNamespace, writeSymbolFile: BOOLEAN;
                        VAR ast: AST.Node;
                        VAR symTab: Item.Module;
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
    ch: Channel.Channel;
  BEGIN
    inputBuffer := m. GetInputBuffer (res);
    IF (inputBuffer = NIL) THEN
      ast := NIL;
      symTab := NIL;
      uri := m. GetURI (Repository.modModuleSource);
      uri. GetString (uriStr);
      errList := Error.NewList (uriStr);
      errList. Append (res)
    ELSE
      errList := inputBuffer. errList;
      scannerBuilder := BasicList.New (inputBuffer, TRUE);
      Scanner.ScanInput (scannerBuilder, config. pragmas, Scanner.enableAll);
      inputBuffer. Close;
      
      ast := NIL;
      IF (errList. msgCount = 0) THEN
        astBuilder := ExtTree.New();
        ast := Parser.Module (scannerBuilder. head, 
                              astBuilder, errList,
                              Parser.enableAll)
      END;

      symTab := NIL;
      IF (errList. msgCount = 0) THEN
        stb := Builder.New();
        symTab := CreateSymTab.CreateSymTab
          (ast, stb, m. GetURI (Repository.modModuleSource));
        IF createNamespace THEN
          IF (errList. msgCount = 0) THEN
            CreateNamespace.CreateNamespace (symTab,
                                             config. predefModule,
                                             config. systemModule,
                                             config. typeRules,
                                             config. repositories, errList)
          END;
          IF (errList. msgCount = 0) & writeSymbolFile THEN
            (* no error in the declaration part of the module: write the
               symbol table to file, skipping any external references and
               strictly local information on the way *)
            ch := m. GetOutputChannel (Repository.modSymbolFile, TRUE, res);
            IF (res = NIL) THEN
              Item.Prune (symTab, Exports.GetExports (symTab)); (* ... *)
              stb. WriteSymbolTable (ch, symTab, res);
              ch(Files.File). Register;
              ch. Close;
              IF (res = Channel.done) THEN
                res := ch. res
              END
            END;
            IF (res # NIL) THEN
              errList. Append (res)
            END
          END
        END
      END
    END
  END ParseModule;

END OOC:Auxiliary:ParseModule.
