(* 	$Id: RunTests.Mod,v 1.20 2003/05/20 20:10:31 mva Exp $	 *)
MODULE RunTests;
(*  Applies a test schedule to an OOC compiler and produces an XML report.
    Copyright (C) 2001, 2002, 2003  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)


IMPORT
  Err, Msg, Out, ProgramArgs, LongStrings,
  Object, IO, IO:FileChannel, IO:Buffer, OS:Path, TextRider, URI,
  StdChannels, XMLError := XML:Error, XML:UnicodeCodec:Latin1,
  XML:Basic:Element, XMLWriter := XML:Writer, URI:Scheme:File,
  OOC:TestFramework:TestSetup, OOC:TestFramework:Testcases,
  OOC:TestFramework:Processor;

CONST  (* classifications of test results *)
  passed = 0;
  failed = 1;
  tolerated = 2;
  skipped = 3;

TYPE
  Results = ARRAY skipped+1 OF LONGINT;
  
VAR
  testSetup: TestSetup.TestSetup;
  testSuite: Testcases.TestSuite;
  proc: Processor.Processor;
  reportWriter: XMLWriter.Writer;
  results: Results;
  str: ARRAY 256 OF CHAR;
  exitError, stopOnError: BOOLEAN;

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
                      VAR suite: Testcases.TestSuite;
                      VAR stopOnError: BOOLEAN)
RAISES IO.Error;
  CONST
    testSetup = 0;
    testCases = 1;
  VAR
    r: TextRider.Reader;
    arg: ARRAY 1024 OF CHAR;
    elem: Element.Element;
    reportFile: Buffer.Channel;
    uri: URI.URI;
    
  PROCEDURE ReadURI (uri: URI.URI; parser: SHORTINT): Element.Element
  RAISES IO.Error;
    VAR
      ch: IO.ByteChannel;
      errList: XMLError.List;
      elem: Element.Element;
    BEGIN
      elem := NIL;
      ch := uri. GetChannel (URI.channelOld);
      CASE parser OF
      | testSetup:
        elem := TestSetup.Read (ch, uri, errList)
      | testCases:
        elem := Testcases.Read (ch, uri, errList)
      END;
      IF (elem = NIL) THEN
        errList. Write (StdChannels.stderr);
        HALT(1)
      END;
      RETURN elem
    END ReadURI;
  
  BEGIN
    setup := NIL;
    stopOnError := FALSE;
    r := TextRider.ConnectReader (ProgramArgs.args);
    IF (r = NIL) THEN
      CheckError (ProgramArgs.args. res)
    ELSE
      r. ReadLine (arg);
      r. ReadLine (arg);
      LOOP
        IF (arg = "--stop-on-error") THEN
          stopOnError := TRUE;
          r. ReadLine (arg);
        ELSIF (arg = "--out-module") THEN
          r. ReadLine (Processor.outModule);
          r. ReadLine (arg);
        ELSE
          EXIT;
        END;
      END;
      
      uri := File.ToURI (arg);
      elem := ReadURI (uri, testSetup);
      setup := elem(TestSetup.TestSetup);
      elem := ReadURI (setup. testSuite. uri, testCases);
      suite := elem(Testcases.TestSuite);
      
      r. ReadLine (arg);
      reportFile := FileChannel.Open(Object.NewLatin1(arg),
                                     {FileChannel.write, FileChannel.create,
                                      FileChannel.truncate});
      reportWriter := XMLWriter.New (reportFile, Latin1.factory, TRUE, 4)
    END
  END ReadConfig;


PROCEDURE RunTests (testSetup: TestSetup.TestSetup;
                    testSuite: Testcases.TestSuite;
                    proc: Processor.Processor;
                    reportWriter: XMLWriter.Writer;
                    VAR results: Results)
RAISES IO.Error;
  VAR
    testCases: Testcases.Testcases;
    test: Testcases.Test;
    result, class: SHORTINT;
    timeStr, str: ARRAY 128 OF CHAR;
    (*time: SysClock.DateTime;*)
    elem: Element.Element;
    processorInfo: Testcases.ProcessorInfo;
    
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
    processorInfo := NIL;
    elem := testSuite. processorInfoList. head;
    WHILE (elem # NIL) DO
      WITH elem: Testcases.ProcessorInfo DO
        IF (elem. processorName = testSetup. processor. name) THEN
          processorInfo := elem
        END
      END;
      elem := elem. next
    END;
        
    reportWriter. StartTag ("test-report", FALSE);
    (*SysClock.GetClock (time);
    Calendar.TimeToStr (time, "%c", timeStr);*)
    COPY("unknown", timeStr);
    reportWriter. AttrStringLatin1 ("time", timeStr);
    testSetup. Write (reportWriter);
    
    reportWriter. StartTag ("test-results", FALSE);
    testCases := testSuite. testcasesList. head(Testcases.Testcases);
    WHILE (testCases # NIL) DO
      IF (testCases. tests. head # NIL) THEN
        test := testCases. tests. head(Testcases.Test);
        WHILE (test # NIL) DO
          reportWriter. StartTag ("test-result", FALSE);
          test. Write (reportWriter);

          IF ~testSuite. SelectedTest (test) THEN
            result := Processor.processSkipped;
            class := skipped
          ELSE 
            proc. Process (test, processorInfo, reportWriter, result);
            
            IF (result = Processor.processCrash) THEN
              (* processor crashed *)
              class := failed
            ELSIF (result = Processor.processMainModuleError) OR
                (result = Processor.processBuildError) OR
                (result = Processor.processCompareFailed) THEN
              (* some error while processing the test that cannot be
                 attributed to the processor *)
              class := failed
            ELSIF (result = Processor.processRejectMismatch) THEN
              (* file was rejected fine, but for the wrong reasons *)
              class := failed
            ELSE
              IF In (testSetup. lang^, test. lang^) THEN
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
            END
          END;
            
          reportWriter. StartTag ("outcome", FALSE);
          CASE result OF
          | Processor.processSkipped:
            str := "skipped"
          | Processor.processCrash:
            str := "compiler crashed"
          | Processor.processReject:
            str := "rejected by compiler"
          | Processor.processRejectMismatch:
            str := "rejected by compiler, but error messages do not match"
          | Processor.processAccept:
            str := "accepted by compiler"
          | Processor.processMainModuleError:
            str := "failed to write main module"
          | Processor.processBuildError:
            str := "failed to build executable (no `Test' procedure?)"
          | Processor.processError:
            str := "program exited with error"
          | Processor.processSuccess:
            str := "program completed successfully"
          | Processor.processOutputDifference:
            str := "program ran, but output does not match reference"
          | Processor.processCompareFailed:
            str := "program ran, but failed to compare output with reference"
          | Processor.processWarningMismatch:
            str := "accepted by compiler, but warnings do not match"
          END;
          reportWriter. AttrStringLatin1 ("result", str);
          CASE class OF
          | skipped: str := "skipped"
          | passed: str := "passed"
          | failed: str := "failed"
          | tolerated: str := "tolerated"
          END;
          reportWriter. AttrStringLatin1 ("class", str);
          reportWriter. EndTag;          (* outcome *)
          reportWriter. EndTag;          (* test-result *)

          IF (class = skipped) THEN
            INC (results[class]);
          ELSE
            Out.String ("--> TEST RESULT: ");
            CASE class OF
            | skipped: Out.String ("SKIPPED ")
            | failed: Out.String ("FAILED ")
            | passed: Out.String ("PASSED ")
            | tolerated: Out.String ("TOLERATED ")
            END;
            Out.String (test. id);
            Out.String (" / ");
            Out.Object (Path.BaseName(test.file.ToString()));
            IF (test. relevance = Testcases.relevanceInformal) &
               (result # Processor.processCrash) THEN
              Out.String (" (informal test)")
            ELSE
              IF (class = failed) & stopOnError THEN
                Out.Ln; Out.String ("Aborting..."); Out.Ln; HALT (2)
              END;
              
              INC (results[class])
            END;
            Out.Ln;
          END;
          
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
    END;
    reportWriter. EndTag;  (* test-results *)
    reportWriter. EndTag;  (* test-report *)
    reportWriter. EndOfText
  END RunTests;
    
BEGIN
  IF (ProgramArgs.args. ArgNumber() < 2) THEN
    Err.String ("Usage: RunTests [--stop-on-error][--out-module <module-name>] <test-setup> <report-file>"); Err.Ln; HALT (1)
  ELSE
    (* make error message values "line" and "character position" Emacs
       compatible be having them start at line 1, point 1 for the XML
       parser *)
    XMLError.errMsgLineBase := 1;
    XMLError.errMsgCharPosBase := 1;
    
    ReadConfig (testSetup, testSuite, stopOnError)
  END;
  
  proc := Processor.New (testSetup);
  proc. Setup;
  results[passed] := 0; results[failed] := 0;
  results[tolerated] := 0; results[skipped] := 0;
  RunTests (testSetup, testSuite, proc, reportWriter, results);
  proc. Cleanup;
  
  Out.Ln; Out.Ln;
  Out.String ("OUTCOME"); Out.Ln;
  Out.String ("passed: "); Out.LongInt (results[passed], 0);
  Out.String (", failed: "); Out.LongInt (results[failed], 0);
  Out.String (", tolerated: "); Out.LongInt (results[tolerated], 0);
  Out.String (", skipped: "); Out.LongInt (results[skipped], 0); Out.Ln;
  Out.String ("--> ");
  exitError := FALSE;
  IF (results[failed] # 0) THEN
    Out.String ("Processor incompatible to ");
    exitError := TRUE;
  ELSIF (results[tolerated] # 0) THEN
    Out.String ("Processor accepts ")
  ELSE
    Out.String ("Processor is compliant to ")
  END;
  LongStrings.Short (testSetup. lang^, "?", str);
  Out.String (str); Out.Ln;
  
  (*  writer := Writer.New (StdChannels.stdout. NewWriter(),
                            Latin1.factory, TRUE, 4);
     testSetup. Write (writer);
     writer. EndOfText;
     
     writer := Writer.New (StdChannels.stdout. NewWriter(),
                           Latin1.factory, TRUE, 4);
     testSuite. Write (writer);
     writer. EndOfText*)
  
  IF exitError THEN
    HALT (1)
  ELSE
    HALT (0)
  END
END RunTests.
          
