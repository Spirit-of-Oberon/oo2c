MODULE TestOpTree;

IMPORT
  StdChannels, Out, Err, 
  Config:Source:CmdLine, Config:Section:Arguments, OOC:Auxiliary:Config, 
  OOC:Error, 
  OOC:Make, OOC:Make:SyncDispatcher, OOC:Make:Node:ModuleOutput,
  OOC:Make:BuildCmd:CompileModule,
  Rep := OOC:Repository;
  
  
VAR
  config: Config.Config;
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  dg: Make.DepGraph;
  node: ModuleOutput.Node;
  m: Rep.Module;


PROCEDURE RegisterCmdLineOptions (config: Config.Config);
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := config. cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
  END RegisterCmdLineOptions;

PROCEDURE NewConfig (defaultConfigFile: ARRAY OF CHAR): Config.Config;
  VAR
    config: Config.Config;
  BEGIN
    NEW (config);
    Config.InitConfig (config, defaultConfigFile);
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
    Out.String ("Usage: TestOpTree {-r <base-dir>} <file>"); Out.Ln;
    HALT (1)
  ELSE
    dg := Make.NewDepGraph (config, SyncDispatcher.New());
    dg. SetBuildCmd (Rep.modSymbolFile, CompileModule.New());
    
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
          node := ModuleOutput.GetNode (dg, m, Rep.modOpTreeXML)
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

  
(*  IF (ProgramArgs.args. ArgNumber() = 0) THEN
    Out.String ("Usage: TestOpTree <file>"); Out.Ln;
    HALT (1)
  ELSE
    argReader := TextRider.ConnectReader (ProgramArgs.args);
    argReader. ReadLine (arg);           (* skip command name *)
    
    (* create module containing the predefined constants, types, 
       procedures, and function *)
    NEW (typeRules);
    stb := SymTabBuilder.New();
    predefModule := Predef.CreateModule (stb);
    CreateNamespace.CreateNamespace (predefModule, NIL, typeRules, NIL);
    
    LOOP
      argReader. ReadLine (arg);
      IF (argReader. res # TextRider.done) THEN
        EXIT
      END;
      
      file := Files.Old (arg, {Files.read}, res);
      IF (file = NIL) THEN
        res. GetText (msgText);
        Out.String ("Error opening "); Out.String (arg); Out.Ln;
        Out.String (msgText); Out.Ln;
        HALT (1)
      ELSE
        errList := Error.NewList (arg);
        inputBuffer := InputBuffer.New (file, errList);
        pragmaSection := Pragmas.New();
        scannerBuilder := BasicList.New (inputBuffer);
        Scanner.ScanInput (scannerBuilder, pragmaSection, Scanner.enableAll);

        astBuilder := ExtTree.New();
        ast := Parser.Module (scannerBuilder. head, 
                              astBuilder, errList, Parser.enableAll);

        stb := SymTabBuilder.New();
        symTab := CreateSymTab.CreateSymTab (ast, stb);
        CreateNamespace.CreateNamespace (symTab, predefModule,
                                         typeRules, errList);
        (* note: maybe CreateSymTab should be turned into a method
                 of AST, that calls CreateNamespace when done ...
                 the same could be done with Predef.CreateModule ...
                 BUT: does this also work when reading symbol files??? *)
                 
        CreateCode.CreateCode (ast(ExtTree.Module), symTab, NIL);
        (* ^^^ make this tb? *)
        
        IF (errList. msgCount # 0) THEN
          errList. Write (StdChannels.stderr);
          HALT (1)
        END
      END
    END
  END*)
END TestOpTree.
