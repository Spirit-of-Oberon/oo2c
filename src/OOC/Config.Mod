MODULE OOC:Config;

IMPORT
  Msg, Config:Value, Config:Source:CmdLine, Config:Section:Options,
  Config:Section:Arguments, Config:Simple,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:Config:Repositories, OOC:Config:Repositories:FileSystem(*KEEP THIS!*);


VAR
  options: Options.Section;
  cmdLine: CmdLine.CmdLine;
  arguments-: Arguments.Section;
  pragmas-: Pragmas.Section;
  repositories-: Repositories.Section;

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

PROCEDURE AddOption* (name: ARRAY OF CHAR; init: Value.Value): Options.Option;
(**Add the program option @oparam{name} to the configuration parser.
   Its initial value is @oparam{init}.  The new option instance is
   returned.  *)
  BEGIN
    RETURN options. Set (name, init);
  END AddOption;

PROCEDURE AddCmdLine* (options, template: ARRAY OF CHAR);
(**Add the command line options listed in @oparam{options} to the configuration
   parser.  The option names are mapped onto program options using the
   rule in @oparam{template}.  *)
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := cmdLine. AddOptionTemplate (options, template);
  END AddCmdLine;

PROCEDURE Read* (errList: Msg.MsgList);
  BEGIN
    config. Read (errList);
  END Read;

BEGIN
  InitConfig (defaultConfigFile);
END OOC:Config.
