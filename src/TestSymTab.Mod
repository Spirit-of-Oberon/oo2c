MODULE TestSymTab;

IMPORT
  StdChannels, Out, Err, Msg, Channel, URI,
  Config:Source:CmdLine, Config:Section:Arguments, OOC:Auxiliary:Config, 
  Config:Section:Options, IntegerValue := Config:Value:Integer,
  BooleanValue := Config:Value:Boolean,
  OOC:Error, OOC:AST, OOC:SymbolTable:Item, Rep := OOC:Repository,
  OOC:Make, OOC:Make:SyncDispatcher, OOC:Make:Node:ModuleOutput,
  OOC:Make:BuildCmd:InterfaceXML, XML := OOC:SymbolTable:Item:XML,
  OOC:Make:BuildCmd:CompileModule, OOC:Auxiliary:ParseModule;
  
CONST
  modeNameOnlyXML = 0;
  modeResolveNamesXML = 1;
  modeInterfaceXML = 2;
  
VAR
  config: Config.Config;
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  dg: Make.DepGraph;
  dummy: Make.Node;
  m: Rep.Module;

  mode: Options.Option;
  oo2cStyleErrors: Options.Option;

TYPE
  BuildCmd* = POINTER TO BuildCmdDesc;
  BuildCmdDesc = RECORD
    (Make.BuildCmdDesc)
  END;

PROCEDURE NewBuildCmd*(): BuildCmd;
  VAR
    cmd: BuildCmd;
  BEGIN
    NEW (cmd);
    RETURN cmd
  END NewBuildCmd;

PROCEDURE (cmd: BuildCmd) Build* (n: Make.Node): Make.BuildResult;
(**Writes the description of the module's public interface as an XML document.
   *)
  VAR
    ast: AST.Node;
    symTab: Item.Module;
    errList: Error.List;
    res: Msg.Msg;
    outputChannel: Channel.Channel;
    outputURI: URI.HierarchicalURI;
    m: Rep.Module;
    resolve: BOOLEAN;
  BEGIN
    m := n(ModuleOutput.Node). module;
    resolve := mode. value(IntegerValue.Value). integer = modeResolveNamesXML;

    ParseModule.ParseModule (m, n. dg. config, resolve, FALSE,
        ast, symTab, errList);
    IF (errList. msgCount = 0) THEN
      outputURI := m. GetURI (Rep.modSymbolTableXML, res);
      outputChannel := m. GetOutputChannel (Rep.modSymbolTableXML, FALSE, res);
      IF (outputChannel = NIL) THEN
        errList. Append (res)
      ELSE
        XML.Write (outputChannel, symTab);
        outputChannel. Close;
        IF (outputChannel. res # Channel.done) THEN
          errList. Append (outputChannel. res)
        END
      END
    END;
    RETURN Make.NewBuildResult (errList. msgCount = 0, FALSE, errList)
  END Build;



PROCEDURE RegisterCmdLineOptions (config: Config.Config);
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := config. cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    ot := config. cmdLine. AddOptionTemplate ("--names-only-xml",
           "<options><set name='mode'>0</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--resolve-names-xml",
           "<options><set name='mode'>1</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--interface-xml",
           "<options><set name='mode'>2</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--terse-errors",
           "<options><set name='oo2cStyleErrors'>TRUE</set></options>");
  END RegisterCmdLineOptions;

PROCEDURE NewConfig (defaultConfigFile: ARRAY OF CHAR): Config.Config;
  VAR
    config: Config.Config;
  BEGIN
    NEW (config);
    Config.InitConfig (config, defaultConfigFile);

    mode := config. options. Set ("mode", IntegerValue.New (modeResolveNamesXML));
    oo2cStyleErrors := config. options. Set ("oo2cStyleErrors", BooleanValue.New (FALSE));
    
    RegisterCmdLineOptions (config);
    RETURN config
  END NewConfig;

BEGIN
  cfgErrList := Error.NewList ("");
  config := NewConfig ("");
  config. Read (cfgErrList);
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  ELSIF (config. arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestSymTab [--names-only-xml|--resolve-names-xml|--interface-xml] [--terse-errors] -r <repository> <file>"); Out.Ln;
    HALT (1)
  ELSE
    Error.oo2cStyleErrors := oo2cStyleErrors. value(BooleanValue.Value). boolean;
    
    dg := Make.NewDepGraph (config, SyncDispatcher.New());
    dg. SetBuildCmd (Rep.modSymbolFile, CompileModule.New());
    dg. SetBuildCmd (Rep.modSymbolTableXML, NewBuildCmd());
    dg. SetBuildCmd (Rep.modInterfaceXML, InterfaceXML.New());
    
    FOR i := 0 TO config. arguments. ArgNumber()-1 DO
      arg := config. arguments. Get (i);
      IF Rep.ValidModuleName (arg^) THEN
        m := config. repositories. GetModule (arg^);
        IF (m = NIL) THEN
          Err.String ("Error: Cannot locate module ");
          Err.String (arg^);
          Err.Ln;
          HALT (1)
        ELSE
          CASE mode. value(IntegerValue.Value). integer OF
          | modeNameOnlyXML, modeResolveNamesXML:
            dummy := ModuleOutput.GetNode (dg, m, Rep.modSymbolTableXML)
          | modeInterfaceXML:
            dummy := ModuleOutput.GetNode (dg, m, Rep.modInterfaceXML)
          END
        END
      ELSE
        Err.String ("Error: Invalid module name ");
        Err.String (arg^);
        Err.Ln;
        HALT (1)
      END
    END;
    IF ~dg. Evaluate() THEN
      HALT (1)
    END
  END
END TestSymTab.
