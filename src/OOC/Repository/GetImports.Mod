MODULE OOC:Repository:GetImports;

IMPORT
  Msg, URI, Rep := OOC:Repository, OOC:Config:Repositories, OOC:Config:Pragmas,
  
  OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:Builder:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree;
  


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
    IF m. importListScanned THEN
      RETURN
    END;
    
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
      IF (errList. msgCount = 0) & (ast(ExtTree.Module). importList # NIL) THEN
        StoreImports (m, ast(ExtTree.Module). importList(ExtTree.ImportList). imports);
        m. AddImport (NIL)  (* mark module with "import scanned" *)
      END
    END
  END GetImports;

BEGIN
  NEW (getImportsContext);
  Error.InitContext (getImportsContext, "OOC:Aux:GetImports")
END OOC:Repository:GetImports.
