MODULE Config:Simple;

IMPORT
  Msg, ProgramArgs, IO, IO:Memory,
  
  C := Config,
  Config:Parser,
  
  Config:Source,
  Config:Source:Environment,
  Config:Source:CmdLine,
  
  Config:Value,
  StringValue := Config:Value:String,
  IntegerValue := Config:Value:Integer,
  BooleanValue := Config:Value:Boolean,
  
  Config:Section,
  Config:Section:Options,
  Config:Section:Arguments;

CONST
  rootName = "configuration";
  
TYPE
  Config* = POINTER TO ConfigDesc;
  ConfigDesc* = RECORD
    (C.ConfigDesc)
    cfgFile: Value.StringPtr;
    cfgFileEnvVar: Environment.VariableTemplate;
    cfgFileCmdLineOption: CmdLine.OptionTemplate;
    
    envVars-: Environment.Environment;
    cmdLine-: CmdLine.CmdLine;
    
    typeList-: Value.PrototypeList;
    
    options-: Options.Section;
    arguments-: Arguments.Section;
    sectionList-: Section.SectionList;
    
    resolver-: Parser.Resolver;
  END;


PROCEDURE Init* (config: Config; defaultConfigFile: ARRAY OF CHAR);
  BEGIN
    C.InitConfig (config);
    
    IF (defaultConfigFile = "") THEN
      config. cfgFile := NIL
    ELSE
      config. cfgFile := Value.GetStringPtr (defaultConfigFile)
    END;
    config. cfgFileEnvVar := NIL;
    config. cfgFileCmdLineOption := NIL;
    
    config. envVars := Environment.New();
    config. cmdLine := CmdLine.New();
    
    config. typeList := Value.NewPrototypeList();
    config. typeList. RegisterPrototype ("string", StringValue.New (""));
    config. typeList. RegisterPrototype ("integer", IntegerValue.New (0));
    config. typeList. RegisterPrototype ("boolean", BooleanValue.New (FALSE));
    
    config. options := Options.New ("options", config. typeList);
    config. arguments := Arguments.New ("arguments");
    config. sectionList := Section.NewSectionList();
    config. sectionList. Add (config. options);
    config. sectionList. Add (config. arguments);
    
    config. resolver := NIL;
    
  END Init;


PROCEDURE New* (defaultConfigFile: ARRAY OF CHAR): Config;
  VAR
    config: Config;
  BEGIN
    NEW (config);
    Init (config, defaultConfigFile);
    RETURN config
  END New;

PROCEDURE (config: Config) ConfigFileEnvVar* (envTemplate: Environment.VariableTemplate);
  BEGIN
    config. cfgFileEnvVar := envTemplate
  END ConfigFileEnvVar;

PROCEDURE (config: Config) ConfigFileCmdLineOption* (optionTemplate: CmdLine.OptionTemplate);
  BEGIN
    config. cfgFileCmdLineOption := optionTemplate
  END ConfigFileCmdLineOption;


PROCEDURE (config: Config) Read* (errList: Msg.MsgList) RAISES IO.Error;
  VAR
    errMsg: Msg.Msg;
    cmdEnv: Environment.Command;
    cmdCmdLine: CmdLine.Command;
    
  PROCEDURE EvaluateFile (fileName: Value.StringPtr) RAISES IO.Error;
    VAR
      p: Parser.Parser;
    BEGIN
      (* create parser for `fileName' *)
      p := Parser.NewFile (fileName^);
      (* parse the XML document in `buffer'; if the XML parser does not
         report any errors, process the elements of the document;
         otherwise, transfer the error messages into `errList' *)
      p. ParseDocument();
      IF (p. errList. msgCount = 0) THEN
        config. sectionList. ProcessElements (p. root, rootName, p) 
      ELSE
        errList. AppendList (p. errList)
      END;
    END EvaluateFile;
  
  PROCEDURE EvaluateSource (source: Source.Source) RAISES IO.Error;
    VAR
      buffer: Memory.Channel;
      p: Parser.Parser;
    BEGIN
      buffer := Memory.Open();
      source. Write (buffer, rootName);
      buffer.SetPos(0);
      
      (* create parser for `buffer' *)
      p := Parser.NewChannel (buffer);
      
      (* parse the XML document in `buffer'; if the XML parser does not
         report any errors, process the elements of the document;
         otherwise, transfer the error messages into `errList' *)
      p. ParseDocument();
      IF (p. errList. msgCount = 0) THEN
        config. sectionList. ProcessElements (p. root, rootName, p) 
      ELSE
        errList. AppendList (p. errList)
      END
    END EvaluateSource;
  
  BEGIN
    errMsg := config. envVars. Parse();
    IF (errMsg # NIL) THEN errList. Append (errMsg) END;
    
    errMsg := config. cmdLine. Parse (ProgramArgs.args);
    IF (errMsg # NIL) THEN errList. Append (errMsg) END;
    
    
    IF (config. cfgFileEnvVar # NIL) THEN
      (* if a enviroment variable has been designated, whose content can
         supersede the file name of the configuration file, then replace
         `config.cfgFile' with the content of this variable *)
      cmdEnv := config. envVars. commandList;
      WHILE (cmdEnv # NIL) & (cmdEnv. template # config. cfgFileEnvVar) DO
        cmdEnv := cmdEnv. nextCommand
      END;
      
      IF (cmdEnv # NIL) THEN
        cmdEnv. DoNotWrite;
        IF (cmdEnv. argument^ = "") THEN (* empty string: don't parse file *)
          config. cfgFile := NIL
        ELSE
          config. cfgFile := cmdEnv. argument
        END
      END
    END;
    
    IF (config. cfgFileCmdLineOption # NIL) THEN
      (* if a command line option has been designated, whose argument
         supersedes the file name of the configuration file, then replace
         `config.cfgFile' with the first argument of this command line option;
         do nothing, if the option has no argument at all *)
      cmdCmdLine := config. cmdLine. commandList;
      WHILE (cmdCmdLine # NIL) DO
        IF (cmdCmdLine. template = config. cfgFileCmdLineOption) THEN
          cmdCmdLine. DoNotWrite;
          IF (LEN (cmdCmdLine. argList^) >= 1) THEN
            IF (cmdCmdLine. argList[0]^ = "") THEN
              config. cfgFile := NIL     (* empty string: don't parse file *)
            ELSE
              config. cfgFile := cmdCmdLine. argList[0]
            END
          END
        END;
        cmdCmdLine := cmdCmdLine. nextCommand
      END
    END;
    
    (* Incorporate data from the various sources.  This is done starting with
       the least specific, and ending with the most specific source.  This way,
       the more specialized settings overide the general ones:
       
         1. read configuration file
         2. incorporate data from environment variables
         3. evaluate command line options
    *)
    IF (config. cfgFile # NIL) THEN
      EvaluateFile (config. cfgFile)
    END;
    EvaluateSource (config. envVars);
    EvaluateSource (config. cmdLine);
  END Read;


END Config:Simple.
