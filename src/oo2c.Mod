MODULE oo2c;

IMPORT
  StdChannels, Out, Err,
  Config:Section:Arguments, Config:Section:Options,
  Config:Value:Boolean, Config:Value:Integer, Config:Value:String,
  OOC:Config, OOC:Config:CCompiler,
  OOC:SymbolTable:Builder, OOC:Error, Rep := OOC:Repository, OOC:Make;
  

VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  m: Rep.Module;
  mode: SHORTINT;
  command, libraryName, libraryVersion, useStderr: Options.Option;
  makeRules: Make.Rules;
  ok: BOOLEAN;

PROCEDURE NewConfig;
  BEGIN
    command := Config.AddOption("command", Integer.New(0));
    libraryName := Config.AddOption("libraryName", String.New(""));
    libraryVersion := Config.AddOption("libraryVersion", String.New(""));
    useStderr := Config.AddOption("useStderr", Boolean.New(FALSE));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--make",
                 "<options><set name='command'>1</set></options>");
    Config.AddCmdLine ("--make-lib",
                       "<options><set name='command'>2</set>"+
                       "<set name='libraryName'>$1</set>"+
                       "<set name='libraryVersion'>$2</set></options>");
    Config.AddCmdLine ("--library",
                 "<options><set name='library'>TRUE</set></options>");
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
  
  makeRules := Make.NewRules();
  IF useStderr.value(Boolean.Value).boolean THEN
    makeRules.SetErrOut(StdChannels.stderr);
  END;
    
  CASE command.value(Integer.Value).integer OF
  | 0:
    mode := Rep.modCodeFileC;
  | 1:
    mode := Rep.modExecutable;
  | 2:
    mode := Rep.modLibrary;
    makeRules.SetLibraryName(libraryName.value(String.Value).string^,
                             libraryVersion.value(String.Value).string^);
  END;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stdout);
  END;
  IF ~cfgErrList.NoErrors() THEN
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: oo2c [--config <cfg-file>] {-r <base-dir>} [--make] <file>"); Out.Ln;
    HALT (1)
  ELSE
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
