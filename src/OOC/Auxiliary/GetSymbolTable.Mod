MODULE OOC:Auxiliary:GetSymbolTable;

IMPORT
  URI, OOC:Error, OOC:SymbolTable:Item, OOC:SymbolTable:CreateNamespace,
  OOC:Repository, OOC:Auxiliary:Config;
  
PROCEDURE GetSymbolTable* (module: Repository.Module; config: Config.Config;
                           VAR res: Error.Msg): Item.Module;
  VAR
    symTab: Item.Module;
    errList: Error.List;
    uriStr: Repository.URIBuffer;
    uri: URI.URI;
  BEGIN
    symTab := module. GetSymbolTable (res);
    IF (symTab. ns = NIL) THEN
      uri := module. GetURI (Repository.modSymbolFile, res);
      uri. GetString (uriStr);
      errList := Error.NewList (uriStr);
      CreateNamespace.CreateNamespace (symTab,
                                       config. predefModule,
                                       config. systemModule,
                                       config. typeRules, 
                                       config. repositories, errList);
      ASSERT (errList. msgCount = 0)
    END;
    RETURN symTab
  END GetSymbolTable;

END OOC:Auxiliary:GetSymbolTable.
