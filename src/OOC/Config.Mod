MODULE OOC:Config;

IMPORT
  Msg, Config:Source:CmdLine, Config:Section:Options,
  Config:Section:Arguments, Config:Simple,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:Config:Repositories, OOC:Config:Repositories:FileSystem(*KEEP THIS!*),
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:SymbolTable:Builder, OOC:SymbolTable:CreateNamespace, OOC:Error;


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

VAR
  config: Simple.Config;

PROCEDURE InitConfig* (defaultConfigFile: ARRAY OF CHAR);
  VAR
    stb: Builder.Builder;
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
    
    stb := Builder.New();
    predefModule := Predef.CreatePredef (stb);
    CreateNamespace.CreateNamespace (predefModule, NIL, NIL,
                                     repositories, Error.NewList(""));
    systemModule := Predef.CreateSYSTEM (stb);
    CreateNamespace.CreateNamespace (systemModule, NIL, NIL,
                                     repositories, Error.NewList(""))
  END InitConfig;

PROCEDURE Read* (errList: Msg.MsgList);
  BEGIN
    config. Read (errList);
  END Read;

END OOC:Config.
