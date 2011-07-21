(* 	$Id: Processor.Mod,v 1.26 2003/05/19 22:56:48 mva Exp $	 *)
MODULE OOC:TestFramework:Processor;
(*  Processes test cases using an OOC compiler.
    Copyright (C) 2001-2003  Michael van Acken

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
  C, Files, LongStrings, Msg, Out, Strings, TextRider,
  Object, ADT:StringBuffer, IO, OS:Path, OSFiles := OS:Files,
  OS:ProcessManagement, URI:Scheme:File, XMLWriter := XML:Writer,
  XML:Basic:Element,
  OOC:TestFramework:TestSetup, OOC:TestFramework:Testcases;


CONST
  processCrash* = 0;
  processReject* = 1;
  processRejectMismatch* = 2;      (* rejected, but error msg does not match *)
  processAccept* = 3;
  processMainModuleError* = 4;     (* could not generate main module *)
  processBuildError* = 5;          (* could not compile main for test *)
  processError* = 6;               (* executable aborted with error *)
  processSuccess* = 7;             (* executable ran successfully *)
  processOutputDifference* = 8;    (* executable ran, but output differs *)
  processCompareFailed* = 9;       (* executable ran, but could not compare *)
  processSkipped* = 10;
  processWarningMismatch* = 11;    (* accept/run, but warning is missing *)
  
TYPE
  Processor* = POINTER TO ProcessorDesc;
  ProcessorDesc = RECORD
    baseDir, modDir, symDir, objDir, binDir, txtDir: STRING;
    processCmd, filterCmd, diffCmd, rejectCmd: STRING;
  END;

TYPE
  FilePath = ARRAY 1024 OF CHAR;

VAR
  outModule*: ARRAY 32 OF CHAR;
  

PROCEDURE Init (proc: Processor; setup: TestSetup.TestSetup);
  VAR
    sb: StringBuffer.StringBuffer;
    str: STRING;
    
  PROCEDURE GetPath (subdir: ARRAY OF CHAR): STRING;
    VAR
      path: STRING;
    BEGIN
      path := setup.processor.workingDir(File.URI).GetPath();
      IF (subdir # "") THEN
        RETURN path+"/"+Object.NewLatin1(subdir);
      ELSE
        RETURN path;
      END;
    END GetPath;
  
  BEGIN
    (* set up working directories and files *)
    proc. baseDir := GetPath ("");
    proc. modDir := GetPath ("src");
    proc. symDir := GetPath ("sym");
    proc. objDir := GetPath ("obj");
    proc. binDir := GetPath ("bin");
    proc. txtDir := GetPath ("txt");
    
    (* put together command string for compile/make *)
    sb := StringBuffer.New("");
    sb.AppendLatin1(setup. processor. command);
    (*sb.AppendLatin1 (" --config '");
    setup. processor. configFile(File.URI). GetPath (path);
    sb.AppendLatin1(path);
    sb.AppendLatin1("' ");*)
    sb.AppendLatin1(" ");
    sb.AppendLatin1(setup. processor. flags);
    sb.AppendLatin1(" ");
    str := sb.ToString();
    proc. processCmd := str(Object.String8);
    
    proc. filterCmd := NIL;
    IF (setup. processor. filterCommand # "") THEN
      proc. filterCmd := Object.NewLatin1(setup. processor. filterCommand)
    END;
    IF (setup. processor. diffCommand # "") THEN
      proc. diffCmd := Object.NewLatin1(setup. processor. diffCommand)
    END;
    IF (setup. processor. checkRejectCommand # "") THEN
      proc. rejectCmd := Object.NewLatin1(setup. processor. checkRejectCommand)
    END;
  END Init;

PROCEDURE New* (setup: TestSetup.TestSetup): Processor;
  VAR
   proc: Processor;
  BEGIN
    NEW (proc);
    Init (proc, setup);
    RETURN proc
  END New;

PROCEDURE (proc: Processor) Setup*;
  PROCEDURE MakeDir (dir: STRING);
    BEGIN
      TRY
        OSFiles.MakeDirs(dir, 7*64);
      CATCH IO.Error:
        ASSERT(FALSE);
      END;
    END MakeDir;
  
  BEGIN
    (* set up working directories *)
    MakeDir (proc. modDir);
    MakeDir (proc. symDir);
    MakeDir (proc. objDir);
    MakeDir (proc. binDir);
    MakeDir (proc. txtDir);
  END Setup;

PROCEDURE (proc: Processor) Cleanup*;
  BEGIN
    
  END Cleanup;

PROCEDURE (proc: Processor) CompareOutput (referenceFile, outputFile: ARRAY OF CHAR): SHORTINT;
  VAR
    result: SHORTINT;
    rf, of: Files.File;
    rr, or: TextRider.Reader;
    res: Msg.Msg;
    rLine, oLine: ARRAY 4*1024 OF CHAR;
  BEGIN
    result := processCompareFailed;
    rf := Files.Old (referenceFile, {Files.read}, res);
    IF (res = Files.done) THEN
      of := Files.Old (outputFile, {Files.read}, res);
      IF (res = Files.done) THEN
        rr := TextRider.ConnectReader (rf);
        or := TextRider.ConnectReader (of);
        LOOP
          rr. ReadLine (rLine); or. ReadLine (oLine);
          IF (rr. res = TextRider.done) & (or. res = TextRider.done) THEN
            IF (rLine # oLine) THEN
              rf. Close;
              of. Close;
              RETURN processOutputDifference
            END
          ELSE
            EXIT
          END
        END;
        
        IF (rr. res # Files.done) & (rr. res. code # Files.readAfterEnd) OR
           (or. res # Files.done) & (or. res. code # Files.readAfterEnd) THEN
          (* read error for one of the files: failure *)
          result := processCompareFailed
        ELSIF (rr. res # Files.done) & (rr. res. code = Files.readAfterEnd) &
              (or. res # Files.done) & (or. res. code = Files.readAfterEnd)THEN
          (* both files were read completely: success; make sure that both
             files agree on the line fragment if the last line is not
             terminated with a newline *)
          IF (rLine # oLine) THEN
            result := processOutputDifference
          ELSE
            result := processSuccess
          END
        ELSE  (* one file is through, the other has further lines: failure *)
          result := processOutputDifference
        END;
        of. Close
      END;
      rf. Close
    END;
    RETURN result
  END CompareOutput;

PROCEDURE (proc: Processor) Process* (test: Testcases.Test;
                                      processorInfo: Testcases.ProcessorInfo;
                                      reportWriter: XMLWriter.Writer;
                                      VAR result: SHORTINT);
  VAR
    path: ARRAY 4*1024 OF CHAR;
    exit, status, signal: C.int;
    moduleName, modPath: STRING;
    runOutFile, runErrFile, runDiffFile: FilePath;
    rejectInfo: Element.Element;
    rejectCount, rejectError: LONGINT;
    warningInfo: Element.Element;
    warningError: LONGINT;
    chars: Object.CharsLatin1;
  
  PROCEDURE GetFileName (suffix: ARRAY OF CHAR;
                         VAR path: ARRAY OF CHAR);
    VAR
      chars: Object.CharsLatin1;
    BEGIN
      chars := proc.txtDir(Object.String8).CharsLatin1();
      COPY (chars^, path);
      Strings.Append ("/", path);
      Strings.Append (test. id, path);
      Strings.Append (suffix, path)
    END GetFileName;
  
  PROCEDURE AttrFileRef (attrName: ARRAY OF LONGCHAR;
                         fileName: ARRAY OF CHAR);
    VAR
      f: Files.File;
      res: Msg.Msg;
      len: LONGINT;
    BEGIN
      IF (fileName # "") THEN
        f := Files.Old (fileName, {Files.read}, res);
        IF (res = NIL) THEN
          len := f. Length();
          f. Close
        ELSE
          len := -1
        END;
        IF (len > 0) THEN
          reportWriter. AttrStringLatin1 (attrName, fileName)
        END
      END
    END AttrFileRef;

  PROCEDURE CompileModule (moduleName: STRING;
                           modulePath: ARRAY OF CHAR; build: BOOLEAN;
                           VAR status, signal: C.int);
    VAR
      exit: C.int;
      outFile, errFile, filterFile: FilePath;
      chars: Object.CharsLatin1;
      path: ARRAY 4*1024 OF CHAR;
    
    PROCEDURE Copy (file: ARRAY OF CHAR);
      VAR
        f: Files.File;
        r: TextRider.Reader;
        res: Msg.Msg;
        line: ARRAY 4*1024 OF CHAR;
      BEGIN
        f := Files.Old (file, {Files.read}, res);
        IF (res = Files.done) THEN
          r := TextRider.ConnectReader (f);
          LOOP
            r. ReadLine (line);
            IF (r. res = TextRider.done) THEN
              Out.String (line); Out.Ln
            ELSE
              EXIT
            END
          END;
          f. Close
        END
      END Copy;
    
    BEGIN
      COPY(modulePath, path);
      
      (* determine path for stdout and stderr output *)
      IF build THEN
        GetFileName (".build.out", outFile);
        GetFileName (".build.err", errFile);
        GetFileName (".build.filter", filterFile);
      ELSE
        GetFileName (".compile.out", outFile);
        GetFileName (".compile.err", errFile);
        GetFileName (".compile.filter", filterFile);
      END;
      
      (* compile test module *)
      Strings.Insert ("'", 0, path);
      Strings.Append ("'", path);
      IF build THEN
        Strings.Insert ("--make ", 0, path)
      END;
      chars := proc.processCmd(Object.String8).CharsLatin1();
      Strings.Insert (chars^, 0, path);
      Strings.Append (" >'", path);
      Strings.Append (outFile, path);
      Strings.Append ("' 2>'", path);
      Strings.Append (errFile, path);
      Strings.Append ("'", path);
      IF build THEN
        Out.String ("### build command:"); Out.Ln
      ELSE
        Out.String ("### compile command:"); Out.Ln
      END;
      Out.String (path); Out.Ln;
      
      Out.Flush;
      exit := ProcessManagement.system (Object.NewLatin1(path));
      signal := ProcessManagement.TermSignal(exit);
      status := ProcessManagement.ExitStatus(exit);
     
      IF (proc. filterCmd # NIL) THEN
        (* pass stdout output through filter *)
        chars := proc.filterCmd(Object.String8).CharsLatin1();
        COPY (chars^, path);
        Strings.Insert ("'", 0, path);
        Strings.Append ("' <'", path);
        Strings.Append (outFile, path);
        Strings.Append ("' >'", path);
        Strings.Append (filterFile, path);
        Strings.Append ("'", path);
        exit := ProcessManagement.system (Object.NewLatin1(path))
      ELSE
        COPY ("", filterFile)
      END;
      
      Copy (outFile);
      Copy (errFile);
      
      IF build THEN
        reportWriter. StartTag ("build-status", FALSE)
      ELSE
        reportWriter. StartTag ("compile-status", FALSE)
      END;
      AttrFileRef ("stdout", outFile);
      AttrFileRef ("stderr", errFile);
      AttrFileRef ("filtered", filterFile);
      IF (status # 0) THEN
        reportWriter. AttrInt ("status", status)
      END;
      IF (signal # 0) THEN
        reportWriter. AttrInt ("signal", signal)
      END;
      reportWriter. EndTag
    END CompileModule;
  
  PROCEDURE WriteMainModule (name: STRING): STRING;
    VAR
      path: FilePath;
      f: Files.File;
      w: TextRider.Writer;
      res: Msg.Msg;
      chars: Object.CharsLatin1;
    BEGIN
      chars := proc.modDir(Object.String8).CharsLatin1();
      COPY (chars^, path);
      Strings.Append ("/x", path);
      chars := name(Object.String8).CharsLatin1();
      Strings.Append (chars^, path);
      Strings.Append (".Mod", path);
      f := Files.New (path, {Files.read, Files.write}, res);
      IF (res = NIL) THEN
        w := TextRider.ConnectWriter (f);
        w. WriteString ("MODULE x");
        w. WriteObject (name);
        w. WriteString (";");
        w. WriteLn;
        IF name.Equals(Object.NewLatin1(outModule)) THEN
          w. WriteString ("IMPORT ");
          w. WriteString (outModule);
        ELSE
          w. WriteString ("IMPORT ");
          w. WriteString (outModule);
          w. WriteString (", ");
          w. WriteObject (name);
        END;
        w. WriteString (";");
        w. WriteLn;
        w. WriteString ("BEGIN ");
        w. WriteString (outModule);
        w. WriteString (".Open; ");
        w. WriteObject (name);
        w. WriteString (".Test;");
        w. WriteLn;
        w. WriteString ("END x");
        w. WriteObject (name);
        w. WriteString (".");
        w. WriteLn;
        
        res := w. res;
        f. Close;
        IF (res = NIL) THEN
          res := f. res
        END
      END;
      
      IF (res = NIL) THEN
        RETURN Object.NewLatin1(path)
      ELSE
        RETURN NIL
      END
    END WriteMainModule;
  
  PROCEDURE CheckReject (rejectInfo: Testcases.RejectInfo): BOOLEAN;
    VAR
      errFile: FilePath;
      cmd, str: ARRAY 4*1024 OF CHAR;
      chars: Object.CharsLatin1;

    PROCEDURE Quote (VAR str: ARRAY OF CHAR);
      VAR
        i: INTEGER;
      BEGIN
        i := 0;
        WHILE (str[i] # 0X) DO
          IF (str[i] = '"') OR (str[i] = "`") OR (str[i] = "$") THEN
            Strings.Insert ("\", i, str);  (* " *)
            INC (i)
          END;
          INC (i)
        END;
        Strings.Insert (' "', 0, str);
        Strings.Append ('" ', str);
      END Quote;
      
    BEGIN
      LongStrings.Short (rejectInfo. msg^, "?", cmd);
      Quote (cmd);

      chars := proc.rejectCmd(Object.String8).CharsLatin1();
      Strings.Insert (chars^, 0, cmd);
      LongStrings.Short (rejectInfo. pos^, "?", str);
      Quote (str);
      Strings.Append (str, cmd);
      
      GetFileName (".compile.err", errFile);
      Strings.Append (errFile, cmd);

      Out.String (cmd);
      Out.Ln;
      Out.Flush;
      RETURN (ProcessManagement.system (Object.NewLatin1(cmd)) = 0)
    END CheckReject;
  
  BEGIN
    Out.Ln;
    Out.String ("### TESTCASE: ");
    Out.String (test. id);
    Out.String (" ################################");
    Out.Ln;
    
    moduleName := test. ModuleName();
    chars := Path.Encode(test.file(File.URI).GetPath());
    CompileModule (moduleName, chars^, FALSE, status, signal);
    
    (* determine status of compilation *)
    result := processCrash;
    IF (signal = 0) THEN
      IF (status = 0) THEN
        result := processAccept
      ELSIF (status = 1) THEN
        result := processReject
      ELSE
        (* status is some other value: stick to `processCrash' *)
      END
    END;
    Out.String ("--> compile result: ");
    CASE result OF
    | processCrash: Out.String ("crash")
    | processAccept: Out.String ("accept")
    | processReject: Out.String ("reject")
    END;
    Out.Ln;
    
    IF (result = processAccept) THEN
      warningError := 0;
      IF (processorInfo # NIL) & (proc. rejectCmd # NIL) THEN
        (* we got a successful accept/run test case; now we need to check
           if the warnings generated by the compiler actually match the
           expected one *)
        warningInfo := processorInfo. warningInfoList. head;
        WHILE (warningInfo # NIL) DO
          WITH warningInfo: Testcases.WarningInfo DO
            IF (warningInfo. id = test. id) THEN
              IF ~CheckReject (warningInfo) THEN
                INC (warningError)
              END;
            END;
          END;
          warningInfo := warningInfo. next
        END;
      END;  
      IF (warningError # 0) THEN
        Out.String ("--> checking warning info: error, failed to match data");
        Out.Ln;
        result := processWarningMismatch;
      END
    END;
        
    IF (result = processAccept) & (test. type >= Testcases.testError) THEN
      (* if the module must be evaluated, create a wrapper that calls the
         exported procedure and build an executable *)
      runDiffFile := "";
      modPath := WriteMainModule (moduleName);
      IF (modPath = NIL) THEN
        result := processMainModuleError;
        Out.String ("--> failed to write main module"); Out.Ln
      ELSE
        chars := modPath(Object.String8).CharsLatin1();
        COPY (chars^, path);
        CompileModule (moduleName, path, TRUE, status, signal);
        Out.String ("--> build result: ");
        IF (status # 0) OR (signal # 0) THEN
          Out.String ("error"); Out.Ln;
          result := processBuildError
        ELSE
          Out.String ("ok"); Out.Ln;
          
          (* run the freshly generated program and see if it aborts *)
          GetFileName (".run.out", runOutFile);
          GetFileName (".run.err", runErrFile);
          chars := moduleName(Object.String8).CharsLatin1();
          COPY (chars^, path);
          Strings.Insert ("/x", 0, path);
          chars := proc.binDir(Object.String8).CharsLatin1();
          Strings.Insert (chars^, 0, path);
          Strings.Insert ("'", 0, path);
          Strings.Append ("' >'", path);
          Strings.Append (runOutFile, path);
          Strings.Append ("' 2>'", path);
          Strings.Append (runErrFile, path);
          Strings.Append ("'", path);
          Out.String ("### executing:"); Out.Ln;
          Out.String (path); Out.Ln;
          Out.Flush;
          exit := ProcessManagement.system (Object.NewLatin1(path));
          status := ProcessManagement.ExitStatus(exit);
          signal := ProcessManagement.TermSignal(exit);
          IF (status = 0) & (signal = 0) THEN
            result := processSuccess;
            IF (test. type = Testcases.testOutput) THEN
              chars := Path.Encode(test.output(File.URI).GetPath());
              result := proc. CompareOutput (chars^, runOutFile);
              
              IF (result # processSuccess) THEN
                COPY(chars^, path);
                GetFileName (".run.diff", runDiffFile);
                Strings.Insert (" '", 0, path);
                chars := proc.diffCmd(Object.String8).CharsLatin1();
                Strings.Insert (chars^, 0, path);
                Strings.Append ("' '", path);
                Strings.Append (runOutFile, path);
                Strings.Append ("' >'", path);
                Strings.Append (runDiffFile, path);
                Strings.Append ("'", path);
                exit := ProcessManagement.system (Object.NewLatin1(path));
              END
            END
          ELSE
            result := processError
          END;
          
          reportWriter. StartTag ("run-status", FALSE);
          AttrFileRef ("stdout", runOutFile);
          AttrFileRef ("stderr", runErrFile);
          IF (runDiffFile # "") THEN
            AttrFileRef ("diff", runDiffFile)
          END;
          IF (status # 0) THEN
            reportWriter. AttrInt ("status", status)
          END;
          IF (signal # 0) THEN
            reportWriter. AttrInt ("signal", signal)
          END;
          reportWriter. EndTag;
          
          Out.String ("--> execution result: ");
          CASE result OF
          | processSuccess:
            IF (test. type = Testcases.testOutput) THEN
              Out.String ("success & output ok")
            ELSE
              Out.String ("success")
            END
          | processError: Out.String ("error")
          | processOutputDifference: Out.String ("output differs")
          | processCompareFailed: Out.String ("compare failed")
          END;
          Out.Ln;
        END
      END

    ELSIF (result = processReject) &
          (test. type >= Testcases.testReject) &
          (processorInfo # NIL) &
          (proc. rejectCmd # NIL) THEN
      (* we got a successful reject test case; now we need to check if the
         reject info generated by the compiler actually matches the expected
         one *)
      rejectCount := 0; rejectError := 0;
      rejectInfo := processorInfo. rejectInfoList. head;
      WHILE (rejectInfo # NIL) DO
        WITH rejectInfo: Testcases.RejectInfo DO
          IF (rejectInfo. id = test. id) THEN
            IF ~CheckReject (rejectInfo) THEN
              INC (rejectError)
            END;
            INC (rejectCount)
          END;
        END;
        rejectInfo := rejectInfo. next
      END;

      IF (rejectCount = 0) THEN
        Out.String ("--> checking reject info: error, no reject data defined");
        result := processRejectMismatch
      ELSIF (rejectError # 0) THEN
        Out.String ("--> checking reject info: error, failed to match data");
        result := processRejectMismatch
      ELSE
        Out.String ("--> checking reject info: success");
      END;
      Out.Ln;
    END
  END Process;

BEGIN
  outModule := "Out0";
END OOC:TestFramework:Processor.
