MODULE Config [OOC_EXTENSIONS];

TYPE
  Config* = POINTER TO ConfigDesc;
  ConfigDesc* = RECORD [ABSTRACT]
  END;

PROCEDURE InitConfig* (config: Config);
  BEGIN
  END InitConfig;

END Config.
