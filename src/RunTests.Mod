MODULE RunTests;

IMPORT
  Channel, Err, Files, Msg, ProgramArgs, TextRider, URI,
  StdChannels, XML:Writer, XMLError := XML:Error, XML:UnicodeCodec:Latin1,
  URI:Scheme:File, OOC:TestFramework:TestSetup, OOC:TestFramework:Testcases;

VAR
  writer: Writer.Writer;
  testSetup: TestSetup.TestSetup;
  testSuite: Testcases.TestSuite;

PROCEDURE CheckErrorFile (msg: Msg.Msg; file: ARRAY OF CHAR);
  VAR
    str: ARRAY 4*1024 OF CHAR;
  BEGIN
    IF (msg # NIL) THEN
      IF (file # "") THEN
        Err.String ("Error in file ");
        Err.String (file);
        Err.String (": ");
      ELSE
        Err.String ("Error: ");
      END;
      msg. GetText (str);
      Err.String (str);
      Err.Ln;
      HALT (1)
    END
  END CheckErrorFile;

PROCEDURE CheckError (msg: Msg.Msg);
  BEGIN
    CheckErrorFile (msg, "")
  END CheckError;

PROCEDURE ReadConfig (VAR setup: TestSetup.TestSetup;
                      VAR suite: Testcases.TestSuite);
  VAR
    r: TextRider.Reader;
    f: Files.File;
    ch: Channel.Channel;
    br: Channel.Reader;
    arg: ARRAY 1024 OF CHAR;
    res: Msg.Msg;
    errList: XMLError.List;
    baseURI: URI.HierarchicalURI;
  BEGIN
    setup := NIL;
    r := TextRider.ConnectReader (ProgramArgs.args);
    IF (r = TextRider.done) THEN
      CheckError (ProgramArgs.args. res)
    ELSE
      r. ReadLine (arg);
      r. ReadLine (arg);
      
      f := Files.Old (arg, {Files.read}, res);
      IF (res = Files.done) THEN
        (* make error message values "line" and "character position" Emacs
           compatible be having them start at line 1, point 1 for the XML
           parser *)
        XMLError.errMsgLineBase := 1;
        XMLError.errMsgCharPosBase := 1;
        
        br := f. NewReader();
        baseURI := File.ToURI (arg);
        setup := TestSetup.Read (br, baseURI, errList);
        IF (setup = NIL) THEN
          errList. Write (StdChannels.stderr);
          HALT(1)
          
        ELSE
          ch := setup. testSuite. uri. GetChannel (URI.channelOld, res);
          IF (res = Channel.done) THEN
            br := ch. NewReader();
            suite := Testcases.Read (br, setup. testSuite. uri, errList);
            IF (suite = NIL) THEN
              errList. Write (StdChannels.stderr);
              HALT(1)
            END
          ELSE
            setup. testSuite. uri. GetString (arg);
            Err.String ("Error while parsing ");
            Err.String (arg);
            Err.String (": ");
            Err.Ln;
            CheckErrorFile (res, arg)
          END
        END
      ELSE
        Err.String ("Error while parsing ");
        Err.String (arg);
        Err.String (": ");
        Err.Ln;
        CheckErrorFile (res, arg)
      END
    END
  END ReadConfig;

BEGIN
  IF (ProgramArgs.args. ArgNumber() # 1) THEN
    Err.String ("Usage: RunTests <test-setup>"); Err.Ln; HALT (1)
  ELSE
    ReadConfig (testSetup, testSuite)
  END;
  
  writer := Writer.New (StdChannels.stdout. NewWriter(),
                        Latin1.factory, TRUE, 4);
  testSetup. Write (writer);
  writer. EndOfText;
  
  writer := Writer.New (StdChannels.stdout. NewWriter(),
                        Latin1.factory, TRUE, 4);
  testSuite. Write (writer);
  writer. EndOfText
END RunTests.
