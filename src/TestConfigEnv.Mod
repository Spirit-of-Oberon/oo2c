MODULE TestConfigEnv;

IMPORT
  Msg, Out, IO:StdChannels, Config:Source:Environment;


VAR
  env: Environment.Environment;
  err: Msg.Msg;
  errText: ARRAY 1024 OF CHAR;
  t: Environment.VariableTemplate;
BEGIN
  (*Out.String ("Usage: TestConfigEnv"); Out.Ln;
  HALT (1)*)
  
  env := Environment.New();
  
  t := env. AddVariableTemplate ("ENV_VAR1",
                      "<options><set name='env_var1_uc'>TRUE</set></options>");
  t := env. AddVariableTemplate ("env_var1",
                      "<options><set name='env_var1_lc'>$1</set></options>");
  t := env. AddVariableTemplate ("env_var1",
                    "<options><set foo='this is also evaluated!'/></options>");
  
  err := env. Parse();
  IF (err = NIL) THEN
    env. Write (StdChannels.stdout, "configuration")
  END;
  IF (err # NIL) THEN
    err. GetText (errText);
    Out.String ("Error: ");
    Out.String (errText);
    Out.Ln;
    HALT (1)
  END
END TestConfigEnv.
