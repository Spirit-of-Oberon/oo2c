MODULE OOC:Repository:GetImports;

IMPORT
  Msg, URI, Rep := OOC:Repository, OOC:Config:Repositories, OOC:Config:Pragmas,
  
  OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:Builder:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree, Sym := OOC:SymbolTable;
  


CONST
  noSuchModule = 1;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  getImportsContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | noSuchModule:
      t := "Cannot locate module `${name}'"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE GetImports* (m: Rep.Module;
                       pragmas: Pragmas.Section;
                       repositories: Repositories.Section;
                       VAR errList: Error.List);
  VAR
    res: Msg.Msg;
    inputBuffer: InputBuffer.Buffer;
    scannerBuilder: BasicList.Builder;
    astBuilder: ExtTree.Builder;
    ast: AST.Node;
    uri: URI.URI;
    uriStr: Rep.URIBuffer;
    item: Sym.Item;
    import: Rep.Module;
  
  PROCEDURE StoreImports (m: Rep.Module; imports: AST.NodeList);
    VAR
      i: LONGINT;
      import: Rep.Module;
      
    PROCEDURE Err (code: Error.Code; sym: BasicList.Symbol);
      VAR
        lastError: Error.Msg;
      BEGIN
        lastError := Error.New (getImportsContext, code);
        lastError. SetIntAttrib ("pos", sym. pos);
        lastError. SetIntAttrib ("line", sym. line);
        lastError. SetIntAttrib ("column", sym. column);
        errList. Append (lastError)
      END Err;

    BEGIN
      i := 0;
      WHILE (i < imports. len) DO
        import := repositories. GetModule (imports. n[i](ExtTree.ImportDecl). moduleName^);
        IF (import = NIL) THEN
          Err (noSuchModule,
               imports. n[i](ExtTree.ImportDecl). module. 
                 nameList. n[0](ExtTree.Terminal). sym)
        ELSE
          m. AddImport (import)
        END;
        INC (i, 2)
      END
    END StoreImports;

  BEGIN
    IF m. importListScanned THEN         (* imports are already known *)
      RETURN
          
    ELSIF (m. symbolTable # NIL) THEN    (* take imports from symbol file *)
      (* FIXME... check if there is a situation where we must ignore
         the contents of the symbol file *)
      item := m. symbolTable. nestedItems;
      WHILE (item # NIL) DO
        WITH item: Sym.Import DO
          import := repositories. GetModule (item. moduleName. str^);
          ASSERT (import # NIL);
          m. AddImport (import);
        ELSE                             (* ignore *)
        END;
        item := item. nextNested
      END;
    ELSE                                 (* take imports from source file *)
      
      inputBuffer := m. GetInputBuffer (res);
      IF (inputBuffer = NIL) THEN
        ast := NIL;
        uri := m. GetURI (Rep.modModuleSource);
        uri. GetString (uriStr);
        errList := Error.NewList (uriStr);
        errList. Append (res)
      ELSE
        errList := inputBuffer. errList;
        scannerBuilder := BasicList.New (inputBuffer, TRUE);
        Scanner.ScanInput (scannerBuilder, pragmas, Scanner.enableAll);
        inputBuffer. Close;
        
        ast := NIL;
        IF (errList. msgCount = 0) THEN
          astBuilder := ExtTree.New();
          ast := Parser.Module (scannerBuilder. head, 
                                astBuilder, errList,
                                Parser.enableAll+{Parser.onlyParseImport})
        END;
        IF (errList. msgCount = 0) &
           (ast(ExtTree.Module). importList # NIL) THEN
          StoreImports (m, ast(ExtTree.Module).
                        importList(ExtTree.ImportList). imports);
          m. AddImport (NIL)  (* mark module with "import scanned" *)
        END
      END
    END;
  END GetImports;

BEGIN
  NEW (getImportsContext);
  Error.InitContext (getImportsContext, "OOC:Aux:GetImports")
END OOC:Repository:GetImports.
