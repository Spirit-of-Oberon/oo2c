MODULE OOC:Config:Pragmas:StdPragmas;

IMPORT
  Config:Value:Boolean, Config:Value:Integer, OOC:Config:Pragmas;


CONST
  defaultWarnings = FALSE;
  defaultAssertions = TRUE;
  defaultOverflowCheck = FALSE;
  defaultConformantMode = FALSE;
  defaultTargetInteger = 32;
  defaultTargetAddress = 32;
  
VAR
  warnings-: Pragmas.Pragma;
  assertions-: Pragmas.Pragma;
  overflowCheck-: Pragmas.Pragma;
  conformantMode-: Pragmas.Pragma;
  targetInteger-: Pragmas.Pragma;
  targetAddress-: Pragmas.Pragma;


PROCEDURE CreateVariables* (s: Pragmas.Section);
  VAR
    dummy: Pragmas.Pragma;
  BEGIN
    warnings := s. Set ("Warnings", Boolean.New (defaultWarnings));
    assertions := s. Set ("Assertions", Boolean.New (defaultAssertions));
    assertions := s. Set ("OverflowCheck", Boolean.New (defaultOverflowCheck));
    
    conformantMode := s. Set ("ConformantMode", Boolean.New (defaultConformantMode));

    targetInteger := s. Set ("TARGET_INTEGER", Integer.New (defaultTargetInteger));
    targetAddress := s. Set ("TARGET_ADDRESS", Integer.New (defaultTargetAddress));
    
    
    dummy := s. Set ("LIB_HAVE_LIBIMLIB", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBM", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBZ", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBJPEG", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBTIFF", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBPNG", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBGIF", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBXNET", Boolean.New (FALSE));
  END CreateVariables;

END OOC:Config:Pragmas:StdPragmas.
