MODULE TestConfigSections;

IMPORT
  Object, ProgramArgs, StdChannels, TextRider, Out, Msg,
  XMLBuilder := XML:Builder, XML:DTD, Config, Config:Parser,
  
  Config:Section,
  Config:Section:Options,
  Config:Section:Arguments;


VAR
  p: Parser.Parser;
  typeMap: Config.PrototypeMap;
  sl: Section.SectionList;
  argReader: TextRider.Reader;
  arg, configFile: ARRAY 1024 OF CHAR;
  res: Msg.Msg;

PROCEDURE WriteConfig (node: Parser.Node);
  VAR
    ptr: Parser.Node;
    att: XMLBuilder.Attribute;
    i: LONGINT;
    value: DTD.String;
    
  PROCEDURE Wr (VAR str: ARRAY OF DTD.Char);
    VAR
      i: LONGINT;
    BEGIN
      i := 0;
      WHILE (str[i] # 0X) DO
        IF (str[i] <= MAX (CHAR)) THEN
          Out.Char (SHORT (str[i]))
        ELSE
          Out.Char ("?")
        END;
        INC (i)
      END
    END Wr;
  
  BEGIN
    WITH node: Parser.Element DO
      Out.Char ("<");
      Wr (node. name^);
      FOR i := 0 TO node. attrList. len-1 DO
        att := node. attrList. attr[i];
        Out.Char (" ");
        Wr (att. localName^);
        Out.String ("='");
        value := att. value. Flatten (att. attrDecl);
        Wr (value^);
        Out.Char ("'")
      END;
      Out.Char (">");
      
      ptr := node. content;
      WHILE (ptr # NIL) DO
        WriteConfig (ptr);
        ptr := ptr. nextNode
      END;
      
      Out.String ("</");
      Wr (node. name^);
      Out.Char (">")
    | node: Parser.CharData DO
      Wr (node. string^)
    END
  END WriteConfig;

BEGIN  <*Warnings:=FALSE*>
  IF (ProgramArgs.args. ArgNumber() = 0) OR
     (ProgramArgs.args. ArgNumber() > 1) THEN
    Out.String ("Usage: TestConfigSections <config-file>"); Out.Ln;
    HALT (1)
  ELSE
    argReader := TextRider.ConnectReader (ProgramArgs.args);
    argReader. ReadLine (arg);           (* skip command name *)
    argReader. ReadLine (configFile);
    
    p := Parser.NewFile(Object.NewLatin1(configFile));
    ASSERT (res = NIL);
    p. ParseDocument;
    
    typeMap := NEW(Config.PrototypeMap);
    Config.SetPrototype(typeMap, "string", Config.NewStringVar(""));
    Config.SetPrototype(typeMap, "integer", Config.NewIntegerVar(0));
    Config.SetPrototype(typeMap, "boolean", Config.NewBooleanVar(FALSE));
    
    sl := Section.NewSectionList();
    sl. Add (Options.New ("options", typeMap));
    sl. Add (Arguments.New ("arguments"));
    
    sl. ProcessElements (p. root, "configuration", p);
    
    IF (p. errList. msgCount = 0) THEN
      sl. DumpContent (StdChannels.stdout)
    ELSE
      p. errList. Write (StdChannels.stderr);
      HALT (1)
    END
  END
END TestConfigSections.
