MODULE OOC:Auxiliary:ParseModule;

IMPORT
  IO, URI,
  OOC:Config, OOC:Config:Pragmas, OOC:Repository,
  
  OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Builder, OOC:SymbolTable:Uses,
  OOC:AST:ExtTree:CreateSymTab, OOC:SymbolTable:CreateNamespace,
  OOC:Auxiliary:WriteSymbolFile;
  


PROCEDURE ParseModule* (m: Repository.Module;
                        checkModuleName, createNamespace,
                        writeSymbolFile, abortAfterImport: BOOLEAN;
                        libraryName: STRING;
                        uses: Uses.Uses;
                        VAR ast: AST.Node;
                        VAR symTab: Sym.Module;
                        VAR pragmaHistory: Pragmas.History;
                        VAR errList: Error.List)
RAISES IO.Error;
(**If this function is called multiple times for the same module while
   evaluating a build command, only on of these calls should pass @code{TRUE}
   to @oparam{writeSymbolFile}.  Otherwise the build logic implemented in
   @omodule{*OOC:Make} would get confused, because it assumes that the time
   of the symbol file designates the time of the last compilation.

   With @oparam{abortAfterImport}, abort after the import list has been
   processed.  This results in a partial symbol table in @oparam{symTab},
   that contains little more than the import statement and the module
   header.

   @postcond
   The output parameter @oparam{errList} lists all errors the occurred
   during parsing and namespace creation.
   @end postcond
   *)
  VAR
    inputBuffer: InputBuffer.Buffer;
    scannerBuilder: BasicList.Builder;
    astBuilder: ExtTree.Builder;
    stb: Builder.Builder;
    uri: URI.URI;
    uriStr: Repository.URIBuffer;
    scannerFlags, parserFlags: SET;
  BEGIN
    inputBuffer := m. GetInputBuffer();
    IF (inputBuffer = NIL) THEN
      ast := NIL;
      symTab := NIL;
      pragmaHistory := NIL;
      uri := m. GetURI (Repository.modModuleSource, TRUE);
      uri. GetString (uriStr);
      errList := Error.NewList (uriStr);
    ELSE
      errList := inputBuffer. errList;
      scannerBuilder := BasicList.New (inputBuffer, TRUE);
      scannerFlags := Scanner.enableAll;
      IF abortAfterImport THEN
        INCL(scannerFlags, Scanner.abortAtDeclarations);
      END;
      Scanner.ScanInput (scannerBuilder, Config.pragmas, scannerFlags);
      inputBuffer. Close;
      pragmaHistory := scannerBuilder. pragmaHistory;
      
      ast := NIL;
      IF errList.NoErrors() THEN
        astBuilder := ExtTree.New();
        IF checkModuleName THEN
          astBuilder. SetModuleName (m. name^)
        END;
        parserFlags := Parser.enableAll;
        IF abortAfterImport THEN
          INCL(parserFlags, Parser.onlyParseImport);
          EXCL(parserFlags, Parser.enableDocComment);
        END;
        ast := Parser.Module (scannerBuilder. head, 
                              astBuilder, errList, parserFlags);
      END;

      symTab := NIL;
      IF errList.NoErrors() THEN
        stb := Builder.New();
        symTab := CreateSymTab.CreateSymTab
          (ast, stb, libraryName, m. GetURI (Repository.modModuleSource, FALSE),
           m. origin. baseURI);
        IF createNamespace THEN
          IF errList.NoErrors() THEN
            CreateNamespace.CreateNamespace (symTab, uses, errList)
          END;
          IF errList.NoErrors() & writeSymbolFile THEN
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
