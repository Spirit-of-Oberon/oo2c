MODULE TestCompile;

IMPORT
  StdChannels, Out, Err, Object, StringSearch, StringSearch:RegexpDFA,
  Config:Section:Arguments,
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  StringValue := Config:Value:String, 
  OOC:Config, OOC:Config:CCompiler,
  OOC:SymbolTable:Builder, OOC:Error, Rep := OOC:Repository, OOC:Make;

VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  m: Rep.Module;
  mode: SHORTINT;
  makeRules: Make.Rules;
  ok: BOOLEAN;
  
  make: Options.Option;
  errorStyle: Options.Option;
  writeAST: Options.Option;
  writeIR: Options.Option;
  useSSA: Options.Option;
  translateIA32: Options.Option;
  inspectProc: Options.Option;
  inspectStage: Options.Option;
  
  
PROCEDURE OptionToMatcher (option: Options.Option; cmdLineName: ARRAY OF CHAR): StringSearch.Matcher;
  VAR
    matcher: StringSearch.Matcher;
    str: Object.String8;
  BEGIN
    str := Object.NewLatin1 (option. value(StringValue.Value). string^);
    matcher := RegexpDFA.factory. Compile (str, {});
    IF (matcher = NIL) THEN
      Err.String ("Warning: Cannot parse regular expression in ");
      Err.String (cmdLineName);
      Err.String (", ignoring it");
      Err.Ln;
      matcher := RegexpDFA.factory. Compile (Object.NewLatin1 ("$"), {});
    END;
    RETURN matcher
  END OptionToMatcher;

PROCEDURE NewConfig;
  BEGIN
    errorStyle := Config.AddOption("errorStyle",
                                   StringValue.New("file:line:column"));
    
    make := Config.AddOption ("make", BooleanValue.New (FALSE));
    writeAST := Config.AddOption ("write-ast", BooleanValue.New (FALSE));
    writeIR := Config.AddOption ("write-ir", BooleanValue.New (FALSE));
    useSSA := Config.AddOption ("use-ssa", BooleanValue.New (FALSE));
    translateIA32 := Config.AddOption ("translate-ia32", BooleanValue.New (FALSE));
    inspectProc := Config.AddOption ("inspect-proc", StringValue.New ("$"));
    inspectStage := Config.AddOption ("inspect-stage", StringValue.New ("$"));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--error-style",
                       "<options><set name='errorStyle'>$1</set></options>");
    Config.AddCmdLine ("--make",
                 "<options><set name='make'>TRUE</set></options>");
    Config.AddCmdLine ("--use-ssa",
                 "<options><set name='use-ssa'>TRUE</set></options>");
    Config.AddCmdLine ("--ia32",
                 "<options><set name='translate-ia32'>TRUE</set><set name='use-ssa'>TRUE</set></options>");
    Config.AddCmdLine ("--write-ast",
                 "<options><set name='write-ast'>TRUE</set></options>");
    Config.AddCmdLine ("--write-ir",
                 "<options><set name='write-ir'>TRUE</set></options>");
    Config.AddCmdLine ("--inspect",
                 "<options><set name='inspect-proc'>$1</set><set name='inspect-stage'>$2</set></options>");

    CCompiler.RegisterConfig;
  END NewConfig;

BEGIN
  Builder.doAutoImport := Builder.autoImportRT0;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  IF make. value(BooleanValue.Value). boolean THEN
    mode := Rep.modExecutable
  ELSIF translateIA32. value(BooleanValue.Value). boolean THEN
    mode := Rep.modObjectFile;
  ELSE
    mode := Rep.modCodeFileC
  END;
  IF (errorStyle.value(StringValue.Value).string^ = "file:line:column") THEN
    Error.style := Error.styleFileLineColumn;
  ELSIF (errorStyle.value(StringValue.Value).string^ = "char-pos") THEN
    Error.style := Error.styleCharPos;
  END;
  
  Make.writeAST := writeAST.value(BooleanValue.Value).boolean;
  Make.writeIR := writeIR.value(BooleanValue.Value).boolean;
  Make.inspectProc := OptionToMatcher(inspectProc, "--inspect.1");
  Make.inspectStage := OptionToMatcher(inspectStage, "--inspect.2");
  
  (* discard errors in config file 
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  END;*)
  IF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestCompile [--config <cfg-file>] {-r <base-dir>} [--make][--write-ast][--write-ir][--use-ssa|--ia32][--inspect <proc-regexp> <stage-regexp>] <file>"); Out.Ln;
    HALT (1)
  ELSE
    makeRules := Make.NewRules();
    IF translateIA32.value(BooleanValue.Value).boolean THEN
      makeRules.SetBackend(Make.backendSSAtoIA32);
    ELSIF useSSA.value(BooleanValue.Value).boolean THEN
      makeRules.SetBackend(Make.backendSSAtoC);
    ELSE
      makeRules.SetBackend(Make.backendIRtoC);
    END;
    makeRules.SetErrOut(StdChannels.stderr);
    
    ok := TRUE;
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments. Get (i);
      m := Config.repositories. GetModule (arg^);
      IF (m = NIL) THEN
        Err.String ("Error: Cannot locate module ");
        Err.String (arg^);
        Err.Ln;
        HALT (1)
      ELSE
        ok := makeRules.Update(m, mode) & ok;
      END
    END;
    
    IF ~ok THEN
      HALT (1)
    END
  END
END TestCompile.
