MODULE TestInterfaceGen;

IMPORT
  StdChannels, Out, Err, 
  Config:Source:CmdLine, Config:Section:Arguments, OOC:Auxiliary:Config, 
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  OOC:Make, OOC:Make:SyncDispatcher, OOC:Make:Node:ModuleOutput,
  OOC:Make:BuildCmd:InterfaceDescr, OOC:Make:BuildCmd:InterfaceHTML,
  OOC:Make:BuildCmd:CompileModule, OOC:Error, Rep := OOC:Repository,
  OOC:Make:Node:Group, OOC:Make:Node:UsageData;
  


VAR
  config: Config.Config;
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  dg: Make.DepGraph;
  node: ModuleOutput.Node;
  m: Rep.Module;
  mode: SHORTINT;
  closureGroup: Group.Node;
  
  buildHTML: Options.Option;
  closure: Options.Option;

PROCEDURE RegisterCmdLineOptions (config: Config.Config);
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := config. cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    ot := config. cmdLine. AddOptionTemplate ("--html",
                 "<options><set name='build-html'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--closure",
                 "<options><set name='closure'>TRUE</set></options>");
  END RegisterCmdLineOptions;

PROCEDURE NewConfig (defaultConfigFile: ARRAY OF CHAR): Config.Config;
  VAR
    config: Config.Config;
  BEGIN
    NEW (config);
    Config.InitConfig (config, defaultConfigFile);

    buildHTML := config. options. Set ("build-html", BooleanValue.New (FALSE));
    closure := config. options. Set ("closure", BooleanValue.New (FALSE));
    
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
    Out.String ("Usage: TestInterfaceGen [--html][--closure] {-r <base-dir>} <file>"); Out.Ln;
    HALT (1)
  ELSE
    dg := Make.NewDepGraph (config, SyncDispatcher.New());
    dg. SetBuildCmd (Rep.modSymbolFile, CompileModule.New());
    dg. SetBuildCmd (Rep.modInterfaceDescr, InterfaceDescr.New());
    dg. SetBuildCmd (Rep.modInterfaceHTML, InterfaceHTML.New());
    
    IF buildHTML. value(BooleanValue.Value). boolean THEN
      mode := Rep.modInterfaceHTML
    ELSE
      mode := Rep.modInterfaceDescr
    END;
    IF closure. value(BooleanValue.Value). boolean THEN
      closureGroup := Group.NewNode (TRUE);
      dg. AddNode (closureGroup)
    ELSE
      closureGroup := NIL
    END;

    (* instances of `Rep.modInterfaceDescr' automatically add the node with
       the name "UsageData" to their ancestor list *)
    dg. AddNamedNode (UsageData.NewNode(), "UsageData");
    
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
          node := ModuleOutput.GetNode (dg, m, mode);
          IF (closureGroup # NIL) THEN
            ModuleOutput.CreateClosure (closureGroup, node)
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
END TestInterfaceGen.
