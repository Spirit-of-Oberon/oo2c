MODULE OOC:Auxiliary:Config;

IMPORT
  Config:Simple, OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:Config:Repositories, OOC:Config:Repositories:FileSystem(*KEEP THIS!*),
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef, OOC:SymbolTable:TypeRules,
  OOC:SymbolTable:Builder, OOC:SymbolTable:CreateNamespace, OOC:Error;


TYPE
  Config* = POINTER TO ConfigDesc;
  ConfigDesc* = RECORD
    (Simple.ConfigDesc)
    pragmas-: Pragmas.Section;
    repositories-: Repositories.Section;
    
    typeRules-: TypeRules.Rules;
    predefModule-: Sym.Module;
    systemModule-: Sym.Module;
  END;

CONST
  runtimeModule* = "RT0";
  (**Name of the pseudo module that pulls in the run-time system.  *)


PROCEDURE InitConfig* (config: Config; defaultConfigFile: ARRAY OF CHAR);
  VAR
    stb: Builder.Builder;
  BEGIN
    Simple.Init (config, defaultConfigFile);
    config. pragmas := Pragmas.New();
    config. sectionList. Add (config. pragmas);
    StdPragmas.CreateVariables (config. pragmas);
    config. repositories := Repositories.New();
    config. sectionList. Add (config. repositories);
    
    (* create module containing the predefined constants, types, 
       procedures, and function *)
    NEW (config. typeRules);
    TypeRules.Init (config. typeRules);
    
    stb := Builder.New();
    config. predefModule := Predef.CreatePredef (stb);
    CreateNamespace.CreateNamespace (config. predefModule, NIL, NIL,
                                     config. typeRules, config. repositories,
                                     Error.NewList(""));
    config. systemModule := Predef.CreateSYSTEM (stb);
    CreateNamespace.CreateNamespace (config. systemModule, NIL, NIL,
                                     config. typeRules, config. repositories,
                                     Error.NewList(""))
  END InitConfig;

END OOC:Auxiliary:Config.
