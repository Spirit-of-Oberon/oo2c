MODULE TestH2O;

IMPORT 
  StdChannels, Out,
  H2O:Scanner, E := H2O:Error, H2O:Source, H2O:Process, H2O:Parser,
  Config:Source:CmdLine, OOC:Config, Config:Section:Arguments,
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  OOC:Error;

VAR
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

PROCEDURE RegisterCmdLineOptions;
  VAR
    ot: CmdLine.OptionTemplate;
  BEGIN
    ot := Config.cmdLine. AddOptionTemplate ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    ot := Config.cmdLine. AddOptionTemplate ("--preprocess",
                 "<options><set name='preprocess'>TRUE</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--strictRedefine",
                 "<options><set name='strictRedefine'>TRUE</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--strictUndefine",
                 "<options><set name='strictUndefine'>TRUE</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--debugDefine",
                 "<options><set name='debugDefine'>TRUE</set></options>");
    ot := Config.cmdLine. AddOptionTemplate ("--text",
                 "<options><set name='text'>TRUE</set></options>");

  END RegisterCmdLineOptions;

PROCEDURE NewConfig;
  BEGIN
    strictRedefine := Config.options.Set("strictRedefine", BooleanValue.New(FALSE));
    strictUndefine := Config.options.Set("strictUndefine", BooleanValue.New(FALSE));
    debugDefine := Config.options.Set("debugDefine", BooleanValue.New(FALSE));
    text := Config.options.Set("text", BooleanValue.New(FALSE));
    preprocess := Config.options.Set("preprocess", BooleanValue.New(FALSE)); 

    RegisterCmdLineOptions;
  END NewConfig;

BEGIN
  Error.oo2cStyleErrors := TRUE;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);

  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: H2OTestCompile {-r <base-dir>} <file>"); Out.Ln;
    HALT (1)
  ELSE
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
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments. Get (i);
      Scanner.Include(arg^, FALSE);
    END;
*)
    arg := Config.arguments. Get(0);

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
