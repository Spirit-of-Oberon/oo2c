MODULE TestSymTab;

IMPORT
  StdChannels, Out, Err, Msg, Channel, URI, ADT:String,
  Config:Source:CmdLine, Config:Section:Arguments, OOC:Config, 
  Config:Section:Options, IntegerValue := Config:Value:Integer,
  BooleanValue := Config:Value:Boolean, OOC:Config:Pragmas,
  OOC:Error, OOC:AST, Sym := OOC:SymbolTable, Rep := OOC:Repository,
  Make, Make:Command:Target, OOC:Make:Entity:ModuleFile,
  XML := OOC:SymbolTable:XML, OOC:Auxiliary:ParseModule,
  OOC:Make:Command:InterfaceXML, OOC:Make:Command:CompileModule;
  
CONST
  modeNameOnlyXML = 0;
  modeResolveNamesXML = 1;
  modeInterfaceXML = 2;
  
VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  dummy: Make.Node;
  m: Rep.Module;

  mode: Options.Option;
  oo2cStyleErrors: Options.Option;

TYPE
  Command = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Rep.Module;
    errList: Error.List;
  END;

TYPE
  Context = POINTER TO ContextDesc;
  ContextDesc = RECORD
    (Make.ContextDesc)
  END;

VAR
  context: Context;


PROCEDURE InitCommand (cmd: Command; context: Context; module: Rep.Module);
  BEGIN
    Make.InitCommand (cmd, context);
    cmd. module := module;
    cmd. errList := NIL;
  END InitCommand;

PROCEDURE NewCommand (context: Context; module: Rep.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    InitCommand (cmd, context, module);
    RETURN cmd
  END NewCommand;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[TestSymTab.Command]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    cmd. AddAncestors (ModuleFile.GetEntity (cmd. context, cmd. module,
                                             Rep.modSymbolFile));
    RETURN Make.commandSchedule
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Writes the description of the module's public interface as an XML document.
   *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    res: Msg.Msg;
    outputChannel: Channel.Channel;
    outputURI: URI.HierarchicalURI;
    m: Rep.Module;
    resolve: BOOLEAN;
    pragmaHistory: Pragmas.History;
  BEGIN
    m := cmd. module;
    resolve := mode. value(IntegerValue.Value). integer = modeResolveNamesXML;

    ParseModule.ParseModule (m, FALSE, resolve, FALSE,
                             ast, symTab, pragmaHistory, errList);
    IF (errList. msgCount = 0) THEN
      outputURI := m. GetURI (Rep.modSymbolTableXML);
      outputChannel := m. GetOutputChannel (Rep.modSymbolTableXML, FALSE, res);
      IF (outputChannel = NIL) THEN
        errList. Append (res)
      ELSE
        XML.Write (outputChannel.NewWriter(), symTab);
        outputChannel. Close;
        IF (outputChannel. res # Channel.done) THEN
          errList. Append (outputChannel. res)
        END
      END
    END;
    cmd. errList := errList;
    RETURN (errList. msgCount = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
    IF (cmd. errList. msgCount # 0) THEN
      cmd. errList. Write (stderr)
    END
  END ProduceOutput;


PROCEDURE InitContext (context: Context; target: Make.Command);
  BEGIN
    Make.InitContext (context, NIL, target);
  END InitContext;

PROCEDURE NewContext(): Context;
  VAR
    context: Context;
  BEGIN
    NEW (context);
    InitContext (context, Target.New());
    RETURN context
  END NewContext;

PROCEDURE (context: Context) GetCommand* (entity: Make.Entity): Make.Command;
  VAR
    e: ModuleFile.Entity;
  BEGIN
    e := entity(ModuleFile.Entity);
    CASE e. fileId OF
    | Rep.modSymbolFile    : RETURN CompileModule.New (context, e. module)
    | Rep.modSymbolTableXML: RETURN NewCommand (context, e. module)
    | Rep.modInterfaceXML  : RETURN InterfaceXML.New (context, e. module)
    END
  END GetCommand;
  


PROCEDURE RegisterCmdLineOptions();
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := Config.cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    ot := Config.cmdLine. AddOptionTemplate ("--names-only-xml",
           "<options><set name='mode'>0</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--resolve-names-xml",
           "<options><set name='mode'>1</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--interface-xml",
           "<options><set name='mode'>2</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--terse-errors",
           "<options><set name='oo2cStyleErrors'>TRUE</set></options>");
  END RegisterCmdLineOptions;

PROCEDURE NewConfig;
  BEGIN
    mode := Config.AddOption ("mode", IntegerValue.New (modeResolveNamesXML));
    oo2cStyleErrors := Config.AddOption ("oo2cStyleErrors", BooleanValue.New (FALSE));
    
    RegisterCmdLineOptions;
  END NewConfig;

BEGIN
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestSymTab [--names-only-xml|--resolve-names-xml|--interface-xml] [--terse-errors] -r <repository> <file>"); Out.Ln;
    HALT (1)
  ELSE
    Error.oo2cStyleErrors := oo2cStyleErrors. value(BooleanValue.Value). boolean;
    
    context := NewContext();
    
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments. Get (i);
      IF Rep.ValidModuleName (arg^) THEN
        m := Config.repositories. GetModule (arg^);
        IF (m = NIL) THEN
          Err.String ("Error: Cannot locate module ");
          Err.String (arg^);
          Err.Ln;
          HALT (1)
        ELSE
          CASE mode. value(IntegerValue.Value). integer OF
          | modeNameOnlyXML, modeResolveNamesXML:
            dummy := ModuleFile.GetEntity (context, m, Rep.modSymbolTableXML)
          | modeInterfaceXML:
            dummy := ModuleFile.GetEntity (context, m, Rep.modInterfaceXML)
          END;
          context. target. AddAncestor (dummy)
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
END TestSymTab.
