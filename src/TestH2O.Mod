MODULE TestH2O;

IMPORT 
  StdChannels, Out,
  H2O:Scanner, E := H2O:Error, H2O:Source, H2O:Process, H2O:Parser,
  Config:Source:CmdLine, OOC:Auxiliary:Config, Config:Section:Arguments,
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  OOC:Error;

VAR
  config: Config.Config;
  cfgErrList: Error.List;
  arg: Arguments.Argument;
  tokenSource : Scanner.TokenSource;
  token : Scanner.Token;

  source : Source.Input;		(* input source *)
  scanner : Scanner.Scanner;		(* scanner *)
  process : Process.Process;		(* preprocessor *)
  parser : Parser.Parser;		(* language parser *)
  error : E.Error;

  preprocess : Options.Option;
  strictRedefine : Options.Option;
  strictUndefine : Options.Option;
  debugDefine : Options.Option;
  text : Options.Option;

  processOptions : SET; 

PROCEDURE RegisterCmdLineOptions (config: Config.Config);
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := config. cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    ot := config. cmdLine. AddOptionTemplate ("--preprocess",
                 "<options><set name='preprocess'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--strictRedefine",
                 "<options><set name='strictRedefine'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--strictUndefine",
                 "<options><set name='strictUndefine'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--debugDefine",
                 "<options><set name='debugDefine'>TRUE</set></options>");
    ot := config. cmdLine. AddOptionTemplate ("--text",
                 "<options><set name='text'>TRUE</set></options>");

  END RegisterCmdLineOptions;

PROCEDURE NewConfig (defaultConfigFile: ARRAY OF CHAR): Config.Config;
  VAR
    config: Config.Config;

  BEGIN
    NEW (config);
    Config.InitConfig (config, defaultConfigFile);

    strictRedefine := config.options.Set("strictRedefine", BooleanValue.New(FALSE));
    strictUndefine := config.options.Set("strictUndefine", BooleanValue.New(FALSE));
    debugDefine := config.options.Set("debugDefine", BooleanValue.New(FALSE));
    text := config.options.Set("text", BooleanValue.New(FALSE));
    preprocess := config.options.Set("preprocess", BooleanValue.New(FALSE)); 

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
    Out.String ("Usage: H2OTestCompile {-r <base-dir>} <file>"); Out.Ln;
    HALT (1)
  ELSE
    Source.Init(config);

    processOptions := {};
    IF debugDefine.value(BooleanValue.Value).boolean THEN
      INCL(processOptions, Process.debugDefine);
    END;
    IF strictUndefine.value(BooleanValue.Value).boolean THEN
      INCL(processOptions, Process.strictUndefine);
    END;
    IF strictRedefine.value(BooleanValue.Value).boolean THEN
      INCL(processOptions, Process.strictRedefine);
    END;
    Process.Init(processOptions);

(*
    FOR i := 0 TO config. arguments. ArgNumber()-1 DO
      arg := config. arguments. Get (i);
      Scanner.Include(arg^, FALSE);
    END;
*)
    arg := config. arguments. Get(0);

    source := Source.New(); source.Include(arg^, FALSE);
    error := E.New(source);
    scanner := Scanner.New(source, error);

    parser := Parser.New();
    process := Process.New(scanner, parser, error);
    Parser.Init(process);
    tokenSource := process;
    IF preprocess. value(BooleanValue.Value). boolean THEN
      token := Scanner.NewToken(Scanner.endFile);
      IF text.value(BooleanValue.Value).boolean THEN
        REPEAT
          tokenSource.GetToken(token, {Scanner.optComment, Scanner.optReturnWhiteSpace});
          token.Text(Out.writer);
        UNTIL token.sym = Scanner.endFile;
      ELSE
        REPEAT
          tokenSource.GetToken(token, {});
          token.Write(Out.writer); Out.Ln;
        UNTIL token.sym = Scanner.endFile;
      END;
    ELSE
      Parser.Body();
    END;

    scanner.in.Summary;
  END;
END TestH2O.
