MODULE RunTests;

IMPORT
  Channel, Err, Msg, Out, ProgramArgs, LongStrings, TextRider, URI,
  StdChannels, XMLError := XML:Error, XML:UnicodeCodec:Latin1,
  XML:Basic:Element, URI:Scheme:File,
  OOC:TestFramework:TestSetup, OOC:TestFramework:Testcases,
  OOC:TestFramework:Processor;

CONST  (* classifications of test results *)
  passed = 0;
  failed = 1;
  tolerated = 2;

CONST
  testedLanguage = "O2";
  
TYPE
  Results = ARRAY tolerated+1 OF LONGINT;
  
VAR
  testSetup: TestSetup.TestSetup;
  testSuite: Testcases.TestSuite;
  proc: Processor.Processor;
  results: Results;

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
  CONST
    testSetup = 0;
    testCases = 1;
    
  VAR
    r: TextRider.Reader;
    arg: ARRAY 1024 OF CHAR;
    elem: Element.Element;
    
  PROCEDURE ReadURI (uri: URI.URI; parser: SHORTINT): Element.Element;
    VAR
      ch: Channel.Channel;
      br: Channel.Reader;
      res: Msg.Msg;
      errList: XMLError.List;
      elem: Element.Element;
      str: ARRAY 1024 OF CHAR;
    BEGIN
      elem := NIL;
      ch := uri. GetChannel (URI.channelOld, res);
      IF (res = Channel.done) THEN
        br := ch. NewReader();
        CASE parser OF
        | testSetup:
          elem := TestSetup.Read (br, uri, errList)
        | testCases:
          elem := Testcases.Read (br, uri, errList)
        END;
        IF (elem = NIL) THEN
          errList. Write (StdChannels.stderr);
          HALT(1)
        END
      ELSE
        uri. GetString (str);
        Err.String ("Error while parsing ");
        Err.String (str);
        Err.String (": ");
        Err.Ln;
        CheckErrorFile (res, str);
        HALT (1)
      END;
      RETURN elem
    END ReadURI;
  
  BEGIN
    setup := NIL;
    r := TextRider.ConnectReader (ProgramArgs.args);
    IF (r = TextRider.done) THEN
      CheckError (ProgramArgs.args. res)
    ELSE
      r. ReadLine (arg);
      r. ReadLine (arg);
      
      elem := ReadURI (File.ToURI (arg), testSetup);
      setup := elem(TestSetup.TestSetup);
      elem := ReadURI (setup. testSuite. uri, testCases);
      suite := elem(Testcases.TestSuite)
    END
  END ReadConfig;


PROCEDURE RunTests (testSetup: TestSetup.TestSetup;
                    testSuite: Testcases.TestSuite;
                    proc: Processor.Processor;
                    currLanguage: ARRAY OF LONGCHAR;
                    VAR results: Results);
  VAR
    testCases: Testcases.Testcases;
    test: Testcases.Test;
    result, class: SHORTINT;
  
  PROCEDURE In (pattern, string: ARRAY OF LONGCHAR): BOOLEAN;
    VAR
      pos, posOfPattern: INTEGER;
      found: BOOLEAN;
    BEGIN
      pos := 0;
      LOOP
        LongStrings.FindNext (pattern, string, pos, found, posOfPattern);
        IF found THEN
          IF ((posOfPattern = 0) OR (string[posOfPattern-1] = " ")) &
             (string[posOfPattern+LongStrings.Length (pattern)] <= " ") THEN
            RETURN TRUE
          ELSE
            pos := posOfPattern+1
          END
        ELSE
          EXIT
        END
      END;
      RETURN FALSE
    END In;
  
  PROCEDURE ResultMatches (testType, result: SHORTINT): BOOLEAN;
    BEGIN
      RETURN
        (testType = Testcases.testAccept) &
          (result = Processor.processAccept) OR
        (testType = Testcases.testReject) &
          (result = Processor.processReject) OR
        (testType = Testcases.testError) &
          (result = Processor.processError) OR
        (testType >= Testcases.testRun) &
          (result = Processor.processSuccess)
    END ResultMatches;
  
  BEGIN
    testCases := testSuite. testcasesList. head(Testcases.Testcases);
    WHILE (testCases # NIL) DO
      IF (testCases. tests. head # NIL) THEN
        test := testCases. tests. head(Testcases.Test);
        WHILE (test # NIL) DO
          proc. Process (test, result);
          
          IF (result = Processor.processCrash) THEN
            (* processor crashed *)
            class := failed
          ELSIF (result = Processor.processMainModuleError) OR
                (result = Processor.processInvalidTestModule) OR
                (result = Processor.processCompareFailed) THEN
            (* some error while processing the test that cannot be
               attributed to the processor *)
            class := failed
          ELSE
            IF In (currLanguage, test. lang^) THEN
              IF ResultMatches (test. type, result) THEN
                class := passed
              ELSE
                class := failed
              END
            ELSE
              IF (result = Processor.processReject) THEN
                class := passed
              ELSIF ResultMatches (test. type, result) THEN
                class := tolerated
              ELSE
                class := failed
              END
            END
          END;
          
          Out.String ("--> TEST RESULT: ");
          CASE class OF
          | failed: Out.String ("FAILED")
          | passed: Out.String ("PASSED")
          | tolerated: Out.String ("TOLERATED")
          END;
          IF (test. relevance = Testcases.relevanceInformal) &
             (result # Processor.processCrash) THEN
            Out.String (" (informal test)")
          ELSE
            IF (class = failed) THEN
(*              Out.Ln; Out.String ("Aborting..."); Out.Ln; HALT (1)*)
            END;
            
            INC (results[class])
          END;
          Out.Ln;
          
          IF (test. next # NIL) THEN
            test := test. next(Testcases.Test)
          ELSE
            test := NIL
          END
        END
      END;
      IF (testCases. next # NIL) THEN
        testCases := testCases. next(Testcases.Testcases)
      ELSE
        testCases := NIL
      END
    END
  END RunTests;

BEGIN
  IF (ProgramArgs.args. ArgNumber() # 1) THEN
    Err.String ("Usage: RunTests <test-setup>"); Err.Ln; HALT (1)
  ELSE
    (* make error message values "line" and "character position" Emacs
       compatible be having them start at line 1, point 1 for the XML
       parser *)
    XMLError.errMsgLineBase := 1;
    XMLError.errMsgCharPosBase := 1;

    ReadConfig (testSetup, testSuite)
  END;
  
  proc := Processor.New (testSetup);
  proc. Setup;
  results[passed] := 0; results[failed] := 0; results[tolerated] := 0;
  RunTests (testSetup, testSuite, proc, testedLanguage, results);
  proc. Cleanup;
  
  Out.Ln; Out.Ln;
  Out.String ("OUTCOME"); Out.Ln;
  Out.String ("passed: "); Out.LongInt (results[passed], 0);
  Out.String (", failed: "); Out.LongInt (results[failed], 0);
  Out.String (", tolerated: "); Out.LongInt (results[tolerated], 0); Out.Ln;
  Out.String ("--> ");
  IF (results[failed] # 0) THEN
    Out.String ("Processor incompatible to ")
  ELSIF (results[tolerated] # 0) THEN
    Out.String ("Processor accepts ")
  ELSE
    Out.String ("Processor is compliant to ")
  END;
  Out.String (testedLanguage); Out.Ln;
  
(*  writer := Writer.New (StdChannels.stdout. NewWriter(),
                        Latin1.factory, TRUE, 4);
  testSetup. Write (writer);
  writer. EndOfText;
  
  writer := Writer.New (StdChannels.stdout. NewWriter(),
                        Latin1.factory, TRUE, 4);
  testSuite. Write (writer);
  writer. EndOfText*)
END RunTests.
