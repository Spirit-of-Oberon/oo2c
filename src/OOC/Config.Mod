MODULE OOC:Config;

IMPORT
  Msg, Config:Source:CmdLine, Config:Section:Options,
  Config:Section:Arguments, Config:Simple,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:Config:Repositories, OOC:Config:Repositories:FileSystem(*KEEP THIS!*),
  Sym := OOC:SymbolTable;


VAR
  cmdLine-: CmdLine.CmdLine;
  arguments-: Arguments.Section;
  options-: Options.Section;
  pragmas-: Pragmas.Section;
  repositories-: Repositories.Section;
  predefModule-: Sym.Module;
  systemModule-: Sym.Module;

CONST
  runtimeModule* = "RT0";
  (**Name of the pseudo module that pulls in the run-time system.  *)
  defaultConfigFile = "";
  
VAR
  config: Simple.Config;

PROCEDURE InitConfig (defaultConfigFile: ARRAY OF CHAR);
  BEGIN
    config := Simple.New (defaultConfigFile);
    cmdLine := config. cmdLine;
    arguments := config. arguments;
    options := config. options;
    
    pragmas := Pragmas.New();
    config. sectionList. Add (pragmas);
    StdPragmas.CreateVariables (pragmas);
    repositories := Repositories.New();
    config. sectionList. Add (repositories);
  END InitConfig;

PROCEDURE Read* (errList: Msg.MsgList);
  BEGIN
    config. Read (errList);
  END Read;

PROCEDURE SetPredefModules* (predef, system: Sym.Module);
(**Sets @ovar{predefModule} and @ovar{systemModule}.  This procedure exists
   so that these variable can be exported read-only.  The modules are
   constructed in the module initialization of
   @omodule{*OOC:SymbolTable:Predef}, and completed during the initialization
   of @omodule{*OOC:SymbolTable:CreateNamespace}.  *)
  BEGIN
    predefModule := predef;
    systemModule := system;
  END SetPredefModules;

BEGIN
  InitConfig (defaultConfigFile);
END OOC:Config.
