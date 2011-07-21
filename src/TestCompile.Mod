MODULE TestCompile;

IMPORT
  IO:StdChannels, Out, Err, Object, StringSearch, StringSearch:RegexpDFA,
  CfgData := Config, Config:Section:Options, OOC:Config,
  OOC:Config:Pragmas, OOC:Config:CCompiler, OOC:Config:Autoconf,
  OOC:SymbolTable:Builder, OOC:Error, Rep := OOC:Repository, OOC:Make;

VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: STRING;
  chars: Object.CharsLatin1;
  m: Rep.Module;
  mode: SHORTINT;
  makeRules: Make.Rules;
  ok: BOOLEAN;
  
  make: Options.Option;
  errorStyle: Options.Option;
  writeAST: Options.Option;
  writeIR: Options.Option;
  useSSA: Options.Option;
  inspectProc: Options.Option;
  inspectStage: Options.Option;
  
  
PROCEDURE OptionToMatcher (option: Options.Option; cmdLineName: ARRAY OF CHAR): StringSearch.Matcher;
  VAR
    matcher: StringSearch.Matcher;
  BEGIN
    matcher := RegexpDFA.factory.Compile(option.value(CfgData.StringVar).string.ToString8("_"), {});
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
  VAR
    haveLibM, haveLibGC: Pragmas.Pragma;
  BEGIN
    errorStyle := Config.AddOption("errorStyle",
                                CfgData.NewStringVar("file:line:column"));
    
    make := Config.AddOption ("make",CfgData.NewBooleanVar(FALSE));
    writeAST := Config.AddOption ("write-ast",CfgData.NewBooleanVar(FALSE));
    writeIR := Config.AddOption ("write-ir",CfgData.NewBooleanVar(FALSE));
    useSSA := Config.AddOption ("use-ssa",CfgData.NewBooleanVar(FALSE));
    inspectProc := Config.AddOption ("inspect-proc",CfgData.NewStringVar("$"));
    inspectStage := Config.AddOption ("inspect-stage",CfgData.NewStringVar("$"));
    
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

    haveLibM := Config.pragmas.Set("HAVE_LIB_M", (* added for module RT0 *)
                                  CfgData.NewBooleanVar(Autoconf.haveLibM));
    haveLibGC := Config.pragmas.Set("HAVE_LIB_DL", (* added for module RT0 *)
                                    CfgData.NewBooleanVar(Autoconf.haveLibDL));
    haveLibGC := Config.pragmas.Set("HAVE_LIB_GC", (* added for module RT0 *)
                                    CfgData.NewBooleanVar(Autoconf.haveLibGC));
    
    CCompiler.RegisterConfig;
  END NewConfig;

BEGIN
  Builder.doAutoImport := Builder.autoImportRT0;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  IF make. value(CfgData.BooleanVar). boolean THEN
    mode := Rep.modExecutable
  ELSE
    mode := Rep.modCodeFileC
  END;
  IF errorStyle.value(CfgData.StringVar).string.Equals("file:line:column") THEN
    Error.style := Error.styleFileLineColumn;
  ELSIF errorStyle.value(CfgData.StringVar).string.Equals("char-pos") THEN
    Error.style := Error.styleCharPos;
  END;
  
  Make.writeAST := writeAST.value(CfgData.BooleanVar).boolean;
  Make.writeIR := writeIR.value(CfgData.BooleanVar).boolean;
  Make.inspectProc := OptionToMatcher(inspectProc, "--inspect.1");
  Make.inspectStage := OptionToMatcher(inspectStage, "--inspect.2");
  
  (* discard errors in config file 
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  END;*)
  IF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestCompile [--config <cfg-file>] {-r <base-dir>} [--make][--write-ast][--write-ir][--use-ssa][--inspect <proc-regexp> <stage-regexp>] <file>"); Out.Ln;
    HALT (1)
  ELSE
    makeRules := Make.NewRules();
    IF useSSA.value(CfgData.BooleanVar).boolean THEN
      makeRules.SetBackend(Make.backendSSAtoC);
    END;
    makeRules.SetErrOut(StdChannels.stderr);
    ok := makeRules.UsageTracking("");  (* for deprecation warnings *)
    
    ok := TRUE;
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments.Get(i);
      arg := arg.ToString8("?");
      chars := arg(Object.String8).CharsLatin1();
      m := Config.repositories. GetModule (chars^);
      IF (m = NIL) THEN
        Err.String ("Error: Cannot locate module ");
        Err.Object (arg);
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
