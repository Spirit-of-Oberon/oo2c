MODULE OOC:Auxiliary:GetSymbolTable;

IMPORT
  URI, OOC:Error, Sym := OOC:SymbolTable, OOC:SymbolTable:CreateNamespace,
  OOC:Repository, OOC:Config;
  
PROCEDURE GetSymbolTable* (module: Repository.Module;
                           VAR res: Error.Msg): Sym.Module;
  VAR
    symTab: Sym.Module;
    errList: Error.List;
    uriStr: Repository.URIBuffer;
    uri: URI.URI;
  BEGIN
    symTab := module. GetSymbolTable (res);
    IF (symTab. ns = NIL) THEN
      uri := module. GetURI (Repository.modSymbolFile);
      uri. GetString (uriStr);
      errList := Error.NewList (uriStr);
      CreateNamespace.CreateNamespace (symTab, errList);
      ASSERT (errList. msgCount = 0)
    END;
    RETURN symTab
  END GetSymbolTable;

END OOC:Auxiliary:GetSymbolTable.
