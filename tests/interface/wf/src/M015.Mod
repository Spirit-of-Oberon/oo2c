MODULE M015;

TYPE
  OptionTemplate* = POINTER TO OptionTemplateDesc;
  OptionTemplateDesc = RECORD
    optTemplate-: CHAR;
  END;

TYPE
  Command*= POINTER TO CommandDesc;
  ArgList = POINTER TO ARRAY OF POINTER TO ARRAY OF CHAR;
  CommandDesc = RECORD
    template-: OptionTemplate;
    (**Text template, that is used to create the XML fragment.  Any references
       $1, $2, ..., $9 are replaced with the arguments from @ofield{argList}.*)
    argList-: ArgList;
    (**Arguments of the command line option.  If the option has no arguments,
       @samp{LEN(argList^)} is zero.  *)
  END;

END M015.
