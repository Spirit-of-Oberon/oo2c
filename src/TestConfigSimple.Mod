MODULE TestConfigSimple;

IMPORT
  RT0, Out, Err, Msg,
  Config:Simple, Config:Source:Environment, Config:Source:CmdLine,
  StringValue := Config:Value:String, Config:Section:Options,
  Config:Section:Arguments;

VAR
  config: Simple.Config;
  vt: Environment.VariableTemplate;
  ot: CmdLine.OptionTemplate;
  
  optionA: Options.Option;
  
  fileName: ARRAY 1024 OF CHAR;
  str: ARRAY 4*1024 OF CHAR;
  errList: Msg.MsgList;
  msg: Msg.Msg;
  i: LONGINT;
  dummy: BOOLEAN;
  
PROCEDURE WriteOption (opt: Options.Option);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    Out.String ("option:");
    Out.String (opt. name^);
    Out.String (" --> ");
    opt. value. ValueToString (str);
    Out.String (str);
    Out.Ln;
  END WriteOption;

PROCEDURE WriteArgument (i: LONGINT);
  VAR
    arg: Arguments.Argument;
  BEGIN
    Out.String ("argument:");
    Out.LongInt (i, 0);
    Out.String (" --> ");
    arg := config. arguments. Get (i);
    Out.String (arg^);
    Out.Ln
  END WriteArgument;

BEGIN
  dummy := RT0.GetEnv ("DEFAULT_CFG_FILE", fileName);
  ASSERT (dummy);
  config := Simple.New (fileName);
  
  optionA := config. options. Set ("a", StringValue.New ("default"));
  
  vt := config. envVars. AddVariableTemplate ("CONFIG_FILE", "$1");
  config. ConfigFileEnvVar (vt);
  vt := config. envVars. AddVariableTemplate ("TEST_A", 
                                  "<options><set name='a'>$1</set></options>");
  
  ot := config. cmdLine. AddOptionTemplate ("--config", "$1");
  config. ConfigFileCmdLineOption (ot);
  ot := config. cmdLine. AddOptionTemplate ("--set-a", 
                                  "<options><set name='a'>$1</set></options>");
  
  errList := Msg.NewMsgList();
  config. Read (errList);
  
  IF (errList. msgCount # 0) THEN
    msg := errList. msgList;
    WHILE (msg # NIL) DO
      msg. GetText (str);
      Err.String (str);
      Err.Ln;
      msg := msg. nextMsg
    END;
    HALT (1)
  ELSE
    WriteOption (optionA);
    
    FOR i := 0 TO config. arguments. ArgNumber()-1 DO
      WriteArgument (i)
    END
  END
END TestConfigSimple.
