MODULE TestConfigCmdLine;

IMPORT
  RT0, Msg, Out, ProgramArgs, StdChannels, Config:Source:CmdLine;


VAR
  cmdLine: CmdLine.CmdLine;
  err: Msg.Msg;
  errText: ARRAY 1024 OF CHAR;
  t: CmdLine.OptionTemplate;
BEGIN
  (*Out.String ("Usage: TestConfigCmdLine <test-options>..."); Out.Ln;
  HALT (1)*)
  
  cmdLine := CmdLine.New();

  IF RT0.GetEnv ("DISABLE_DASH_DASH", errText) THEN
    cmdLine. EnableDashDash (FALSE)
  END;
  IF RT0.GetEnv ("DISABLE_EXPAND_SINGLE", errText) THEN
    cmdLine. EnableExpandToSingleChar (FALSE)
  END;
  IF RT0.GetEnv ("DISABLE_START_WITH_DASH", errText) THEN
    cmdLine. OptionsStartWithDash (FALSE)
  END;
  
  t := cmdLine. AddOptionTemplate ("-o,-1,--flag-one",
                         "<options><set name='flag_one'>TRUE</set></options>");
  t := cmdLine. AddOptionTemplate ("-o,-2,--flag-two",
                         "<options><set name='flag_two'>TRUE</set></options>");
  t := cmdLine. AddOptionTemplate ("-a,--arg-option",
                "<options><set name='one_argument_option'>$1</set></options>");
  t := cmdLine. AddOptionTemplate ("three,--three-arg-option",
                "<options><set name='three_argument_option'"+
                "a1='$1' a2='$2' a3='$3'/></options>");
  t := cmdLine. AddOptionTemplate ("-o2", 
                                        "<options><set name='o2'/></options>");
  
  err := cmdLine. Parse (ProgramArgs.args);
  IF (err = NIL) THEN
    cmdLine. Write (StdChannels.stdout, "configuration", err);
  END;
  IF (err # NIL) THEN
    err. GetText (errText);
    Out.String ("Error: ");
    Out.String (errText);
    Out.Ln;
    HALT (1)
  END
END TestConfigCmdLine.
