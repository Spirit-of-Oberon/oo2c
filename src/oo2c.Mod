MODULE oo2c;

IMPORT
  StdChannels, Out, Err,
  Config:Section:Arguments, Config:Section:Options, Config:Value:Boolean,
  OOC:Config, OOC:Config:CCompiler, OOC:Config:Assembler,
  OOC:SymbolTable:Builder, OOC:Error, Rep := OOC:Repository, OOC:Make;
  

VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  m: Rep.Module;
  mode: SHORTINT;
  make, useStderr: Options.Option;
  makeRules: Make.Rules;
  ok: BOOLEAN;

PROCEDURE NewConfig;
  BEGIN
    make := Config.AddOption ("make", Boolean.New (FALSE));
    useStderr := Config.AddOption ("useStderr", Boolean.New (FALSE));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--make",
                 "<options><set name='make'>TRUE</set></options>");
    Config.AddCmdLine ("--use-stderr",
                 "<options><set name='useStderr'>TRUE</set></options>");
    
    CCompiler.RegisterConfig;
  END NewConfig;

BEGIN
  Error.oo2cStyleErrors := TRUE;
  Error.minErrorDistance := 16;
  Builder.doAutoImport := TRUE;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  IF make. value(Boolean.Value). boolean THEN
    mode := Rep.modExecutable
  ELSE
    mode := Rep.modCodeFileC
  END;
  Assembler.useAssembler := FALSE;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stdout);
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: oo2c [--config <cfg-file>] {-r <base-dir>} [--make] <file>"); Out.Ln;
    HALT (1)
  ELSE
    makeRules := Make.NewRules();
    IF useStderr.value(Boolean.Value).boolean THEN
      makeRules.SetErrOut(StdChannels.stderr);
    END;
    
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
END oo2c.
