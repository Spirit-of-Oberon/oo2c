MODULE TestCompile;

IMPORT
  StdChannels, Out, Err, Make, Make:Command:Target, 
  Config:Source:CmdLine, Config:Section:Arguments, OOC:Auxiliary:Config, 
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  OOC:Make:Entity:ModuleFile, OOC:Make:Command:TranslateToC,
  OOC:Make:Command:WriteMainFileC, OOC:Make:Command:CompileFileC,
  OOC:Make:Command:LinkProgramC,
  OOC:Error, Rep := OOC:Repository;
  


TYPE
  Context = POINTER TO ContextDesc;
  ContextDesc = RECORD
    (Make.ContextDesc)
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
  
  make: Options.Option;
  writeAST: Options.Option;
  writeIR: Options.Option;
  useSSA: Options.Option;

  
PROCEDURE InitContext (context: Context; config: Config.Config;
                       target: Make.Command);
  BEGIN
    Make.InitContext (context, config, target);
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
    WITH entity: ModuleFile.Entity DO
      CASE entity. fileId OF
      | Rep.modSymbolFile, Rep.modHeaderFileC,
        Rep.modDeclFileC, Rep.modCodeFileC:
        RETURN TranslateToC.New (context, entity. module,
                                 writeAST. value(BooleanValue.Value). boolean,
                                 writeIR. value(BooleanValue.Value). boolean,
                                 useSSA. value(BooleanValue.Value). boolean)
      | Rep.modMainFileC:
        RETURN WriteMainFileC.New (context, entity. module)
      | Rep.modObjectFile, Rep.modMainObjectFile:
        RETURN CompileFileC.New (context, entity. module, entity. fileId)
      | Rep.modExecutable:
        RETURN LinkProgramC.New (context, entity. module)
      END
    END
  END GetCommand;
  

PROCEDURE RegisterCmdLineOptions (config: Config.Config);
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := config. cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    ot := config. cmdLine. AddOptionTemplate ("--make",
                 "<options><set name='make'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--use-ssa",
                 "<options><set name='use-ssa'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--write-ir",
                 "<options><set name='write-ir'>TRUE</set></options>");
  END RegisterCmdLineOptions;

PROCEDURE NewConfig (defaultConfigFile: ARRAY OF CHAR): Config.Config;
  VAR
    config: Config.Config;
  BEGIN
    NEW (config);
    Config.InitConfig (config, defaultConfigFile);

    make := config. options. Set ("make", BooleanValue.New (FALSE));
    writeAST := config. options. Set ("write-ast", BooleanValue.New (FALSE));
    writeIR := config. options. Set ("write-ir", BooleanValue.New (FALSE));
    useSSA := config. options. Set ("use-ssa", BooleanValue.New (FALSE));
    
    RegisterCmdLineOptions (config);
    RETURN config
  END NewConfig;

BEGIN
  Error.oo2cStyleErrors := TRUE;
  cfgErrList := Error.NewList ("");
  config := NewConfig ("");
  config. Read (cfgErrList);
  
  IF make. value(BooleanValue.Value). boolean THEN
    mode := Rep.modExecutable
  ELSE
    mode := Rep.modObjectFile
  END;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  ELSIF (config. arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestCompile {-r <base-dir>} [--make][--write-ast][--write-ir][--use-ssa] <file>"); Out.Ln;
    HALT (1)
  ELSE
    context := NewContext (config);
    
    FOR i := 0 TO config. arguments. ArgNumber()-1 DO
      arg := config. arguments. Get (i);
      m := config. repositories. GetModule (arg^);
      IF (m = NIL) THEN
        Err.String ("Error: Cannot locate module ");
        Err.String (arg^);
        Err.Ln;
        HALT (1)
      ELSE
        node := ModuleFile.GetEntity (context, m, mode);
        context. target. AddAncestor (node)
      END
    END;
    
    IF ~context. Solve (StdChannels.stdout, StdChannels.stderr) THEN
      HALT (1)
    END
  END
END TestCompile.
