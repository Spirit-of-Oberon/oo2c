MODULE OOC:Config;

IMPORT
  RT0, Msg, IO, Config:Value, Config:Value:String, Config:Source:CmdLine,
  Config:Section:Options, Config:Section:Arguments, Config:Simple,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas, OOC:Config:Autoconf,
  OOC:Config:Repositories,
  <*PUSH; Warnings:=FALSE*>OOC:Config:Repositories:FileSystem<*POP*>;


VAR
  options-: Options.Section;
  cmdLine: CmdLine.CmdLine;
  arguments-: Arguments.Section;
  pragmas-: Pragmas.Section;
  repositories-: Repositories.Section;

CONST
  runtimeModule* = "RT0";
  (**Name of the pseudo module that pulls in the run-time system.  *)
  configEnvVar = "OO2CRC";
  
VAR
  config: Simple.Config;
  xsltproc-: Options.Option;

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

PROCEDURE InitConfig (defaultConfigFile: ARRAY OF CHAR);
  VAR
    configFile: Options.Option;
  BEGIN
    config := Simple.New (defaultConfigFile);
    cmdLine := config. cmdLine;
    arguments := config. arguments;
    options := config. options;

    configFile := options. Set ("config-file",
                                String.New (defaultConfigFile));
    config. ConfigFileCmdLineOption (cmdLine. AddOptionTemplate (
       "--config", "<option><set name='config-file'>$1</set></option>"));
    config. ConfigFileEnvVar(config. envVars. AddVariableTemplate (
       configEnvVar, "<option><set name='config-file'>$1</set></option>"));
    
    pragmas := Pragmas.New();
    config. sectionList. Add (pragmas);
    StdPragmas.CreateVariables (pragmas);
    repositories := Repositories.New();
    config. sectionList. Add (repositories);

    xsltproc := AddOption("xsltproc", String.New ("xsltproc"));
    AddCmdLine ("--xsltproc",
                "<options><set name='xsltproc'>$1</set></options>");
  END InitConfig;

PROCEDURE Read* (errList: Msg.MsgList) RAISES IO.Error;
  BEGIN
    config. Read (errList);
  END Read;

PROCEDURE HaveXsltProc*(): BOOLEAN;
  BEGIN
    RETURN (xsltproc.value(String.Value).string^ # "no");
  END HaveXsltProc;

BEGIN
  InitConfig (Autoconf.configFile);
  RT0.poisonHeap := 055H;
END OOC:Config.
