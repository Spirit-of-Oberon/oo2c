MODULE OOC:SymbolTable:ImportModules;

IMPORT
  Msg, OOC:Error, OOC:SymbolTable:Item,
  OOC:Repository, OOC:Config:Repositories;


CONST
  noSuchModule = 1;
  readErrorSymbolFile = 2;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  importModulesContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | noSuchModule:
      t := "Cannot locate module `${name}'"
    | readErrorSymbolFile:
      t := "Failed to read symbol file: ${reason}"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE ImportModules* (systemModule: Item.Module;
                          repositories: Repositories.Section;
                          symTab: Item.Module;
                          errList: Error.List);
  VAR
    ptr: Item.Item;
    lastError: Error.Msg;
    
  PROCEDURE Err (code: Error.Code; name: Item.Name);
    BEGIN
      lastError := Error.New (importModulesContext, code);
      lastError. SetIntAttrib ("pos", name. pos);
      lastError. SetIntAttrib ("line", name. line);
      lastError. SetIntAttrib ("column", name. column);
      lastError. SetStringAttrib ("name", Msg.GetStringPtr (name. str^));
      errList. Append (lastError)
    END Err;
  
  PROCEDURE ReadSymbolFile (import: Item.Import);
    VAR
      m: Repository.Module;
      res: Msg.Msg;
    BEGIN
      IF (import. moduleName. str^ = "SYSTEM") THEN
        import. SetExternalSymTab (systemModule)
      ELSE
        m := repositories. GetModule (import. moduleName. str^);
        IF (m = NIL) THEN
          Err (noSuchModule, import. moduleName)
        ELSE
          symTab := m. GetSymbolTable (res);
          IF (res # NIL) THEN
            Err (readErrorSymbolFile, import. moduleName);
            lastError. SetMsgAttrib ("reason", res)
          ELSE
            import. SetExternalSymTab (symTab)
          END
        END
      END
    END ReadSymbolFile;
  
  BEGIN
    lastError := NIL;
    ptr := symTab. nestedItems;
    WHILE (ptr # NIL) DO
      WITH ptr: Item.Import DO
        ReadSymbolFile (ptr)
      ELSE
      END;
      ptr := ptr. nextNested
    END
  END ImportModules;


BEGIN
  NEW (importModulesContext);
  Error.InitContext (importModulesContext, "OOC:SymbolTable:ImportModules")
END OOC:SymbolTable:ImportModules.
