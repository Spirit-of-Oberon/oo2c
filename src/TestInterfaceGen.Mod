MODULE TestInterfaceGen;

IMPORT
  StdChannels, Out, Err, Make, Make:Command:Target, Make:Entity:Group,
  Config:Source:CmdLine, Config:Section:Arguments, OOC:Auxiliary:Config, 
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  OOC:Make:Entity:ModuleFile,
  OOC:Make:Command:InterfaceDescr, OOC:Make:Command:InterfaceHTML,
  OOC:Make:Command:CompileModule, OOC:Error, Rep := OOC:Repository,
  OOC:Make:Entity:UsageData;
  


TYPE
  Context = POINTER TO ContextDesc;
  ContextDesc = RECORD
    (Make.ContextDesc)
    usageData: Make.Entity;
  END;

VAR
  context: Context;


VAR
  config: Config.Config;
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  node: ModuleFile.Entity;
  m: Rep.Module;
  mode: SHORTINT;
  closureGroup: Make.Entity;
  
  buildHTML: Options.Option;
  closure: Options.Option;


PROCEDURE InitContext (context: Context; config: Config.Config;
                       target: Make.Command);
  BEGIN
    Make.InitContext (context, config, target);
    context. usageData := NIL;
  END InitContext;

PROCEDURE NewContext (config: Config.Config): Context;
  VAR
    context: Context;
  BEGIN
    NEW (context);
    InitContext (context, config, Target.New());
    RETURN context
  END NewContext;

PROCEDURE (context: Context) GetCommand* (entity: Make.Entity): Make.Command;
  BEGIN
    WITH entity: UsageData.Entity DO
      RETURN UsageData.NewCommand (context, entity)
    | entity: ModuleFile.Entity DO
      CASE entity. fileId OF
      | Rep.modSymbolFile    : RETURN CompileModule.New (context, entity. module)
      | Rep.modInterfaceDescr: RETURN InterfaceDescr.New (context, entity)
      | Rep.modInterfaceHTML : RETURN InterfaceHTML.New (context, entity. module)
      END
    END
  END GetCommand;
  
PROCEDURE (context: Context) GetNamedEntity* (name: ARRAY OF CHAR): Make.Entity;
  BEGIN
    IF (name = "UsageData") THEN
      RETURN context. usageData
    ELSE
      RETURN NIL
    END
  END GetNamedEntity;


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
  Error.oo2cStyleErrors := TRUE;
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
    context := NewContext (config);
    
    IF buildHTML. value(BooleanValue.Value). boolean THEN
      mode := Rep.modInterfaceHTML
    ELSE
      mode := Rep.modInterfaceDescr
    END;
    IF closure. value(BooleanValue.Value). boolean THEN
      closureGroup := Group.New (context);
      context. target. AddAncestor (closureGroup);
    ELSE
      closureGroup := NIL
    END;

    (* instances of `Rep.modInterfaceDescr' automatically add the node with
       the name "UsageData" to their ancestor list *)
    context. usageData := UsageData.NewEntity (context);
    
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
          node := ModuleFile.GetEntity (context, m, mode);
          context. target. AddAncestor (node);
          IF (closureGroup # NIL) THEN
            ModuleFile.CreateClosure (closureGroup, node)
          END
        END
      ELSE
        Err.String ("Error: Invalid module name ");
        Err.String (arg^);
        Err.Ln;
        HALT (1)
      END
    END;
    
    IF ~context. Solve (StdChannels.stdout, StdChannels.stderr) THEN
      HALT (1)
    END
  END
END TestInterfaceGen.
