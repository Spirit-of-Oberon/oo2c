MODULE OOC:TestFramework:Processor;

IMPORT
  C, Files, Msg, Out, Strings, TextRider, ADT:String, OSFiles := OS:Files,
  OS:ProcessManagment, URI:Scheme:File, XMLWriter := XML:Writer,
  OOC:TestFramework:TestSetup, OOC:TestFramework:Testcases;


CONST
  processCrash* = 0;
  processReject* = 1;
  processAccept* = 2;
  processMainModuleError* = 3;     (* could not generate main module *)
  processBuildError* = 4;          (* could not compile main for test *)
  processError* = 5;               (* executable aborted with error *)
  processSuccess* = 7;             (* executable ran successfully *)
  processOutputDifference* = 8;    (* executable ran, but output differs *)
  processCompareFailed* = 9;       (* executable ran, but could not compare *)

TYPE
  Processor* = POINTER TO ProcessorDesc;
  ProcessorDesc = RECORD
    baseDir, modDir, symDir, objDir, binDir, txtDir: String.String;
    processCmd, filterCmd: String.String;
  END;

TYPE
  FilePath = ARRAY 1024 OF CHAR;


PROCEDURE Init (proc: Processor; setup: TestSetup.TestSetup);
  VAR
    s: String.String;
    path: FilePath;
    
  PROCEDURE GetPath (subdir: ARRAY OF CHAR): String.String;
    VAR
      path: FilePath;
    BEGIN
      setup. processor. workingDir(File.URI). GetPath (path);
      IF (subdir # "") THEN
        Strings.Append ("/", path);
        Strings.Append (subdir, path)
      END;
      RETURN String.New (path)
    END GetPath;
  
  BEGIN
    (* set up working directories and files *)
    proc. baseDir := GetPath ("");
    proc. modDir := GetPath ("mod");
    proc. symDir := GetPath ("sym");
    proc. objDir := GetPath ("obj");
    proc. binDir := GetPath ("bin");
    proc. txtDir := GetPath ("txt");
    
    (* put together command string for compile/make *)
    s := String.New (setup. processor. command);
    s. AppendString (" --config '");
    setup. processor. configFile(File.URI). GetPath (path);
    s. AppendString (path);
    s. AppendString ("' ");
    s. AppendString (setup. processor. flags);
    s. AppendString (" ");
    proc. processCmd := s;
    
    proc. filterCmd := NIL;
    IF (setup. processor. filterCommand # "") THEN
      proc. filterCmd := String.New (setup. processor. filterCommand)
    END
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
  PROCEDURE MakeDir (dir: String.String);
    VAR
      res: Msg.Msg;
    BEGIN
      OSFiles.makedirs (dir. array^, 7*64, res);
      ASSERT (res = NIL)
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
          (* both files were read completely: success *)
          result := processSuccess
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
                                      reportWriter: XMLWriter.Writer;
                                      VAR result: SHORTINT);
  VAR
    path: ARRAY 4*1024 OF CHAR;
    exit, status, signal: C.int;
    moduleName, modPath: String.String;
    runOutFile, runErrFile: FilePath;
  
  PROCEDURE GetFileName (moduleName: String.String; suffix: ARRAY OF CHAR;
                         VAR path: ARRAY OF CHAR);
    BEGIN
      COPY (proc. txtDir. array^, path);
      Strings.Append ("/", path);
      Strings.Append (moduleName. array^, path);
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

  PROCEDURE CompileModule (moduleName: String.String;
                           path: ARRAY OF CHAR; build: BOOLEAN;
                           VAR status, signal: C.int);
    VAR
      exit: C.int;
      outFile, errFile, filterFile: FilePath;
    
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
      (* determine path for stdout and stderr output *)
      IF build THEN
        GetFileName (moduleName, ".build.out", outFile);
        GetFileName (moduleName, ".build.err", errFile);
        GetFileName (moduleName, ".build.filter", filterFile);
      ELSE
        GetFileName (moduleName, ".compile.out", outFile);
        GetFileName (moduleName, ".compile.err", errFile);
        GetFileName (moduleName, ".compile.filter", filterFile);
      END;
      
      (* compile test module *)
      Strings.Insert ("'", 0, path);
      Strings.Append ("'", path);
      IF build THEN
        Strings.Insert ("--make ", 0, path)
      END;
      Strings.Insert (proc. processCmd. array^, 0, path);
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
      exit := ProcessManagment.system (path);
      status := ASH (exit, -8) MOD 256;
      signal := exit MOD 256;
      
      IF (proc. filterCmd # NIL) & (status # 0) THEN
        (* if exit status is non-zero, then filter the stdout output through
           filter *)
        COPY (proc. filterCmd. array^, path);
        Strings.Insert ("'", 0, path);
        Strings.Append ("' <'", path);
        Strings.Append (outFile, path);
        Strings.Append ("' >'", path);
        Strings.Append (filterFile, path);
        Strings.Append ("'", path);
        exit := ProcessManagment.system (path)
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
  
  PROCEDURE WriteMainModule (name: String.String): String.String;
    VAR
      path: FilePath;
      f: Files.File;
      w: TextRider.Writer;
      res: Msg.Msg;
    BEGIN
      COPY (proc. modDir. array^, path);
      Strings.Append ("/x", path);
      Strings.Append (name. array^, path);
      Strings.Append (".Mod", path);
      f := Files.New (path, {Files.read, Files.write}, res);
      IF (res = NIL) THEN
        w := TextRider.ConnectWriter (f);
        w. WriteString ("MODULE x");
        w. WriteString (name. array^);
        w. WriteString (";");
        w. WriteLn;
        w. WriteString ("IMPORT ");
        w. WriteString (name. array^);
        w. WriteString (";");
        w. WriteLn;
        w. WriteString ("BEGIN ");
        w. WriteString (name. array^);
        w. WriteString (".Test;");
        w. WriteLn;
        w. WriteString ("END x");
        w. WriteString (name. array^);
        w. WriteString (".");
        w. WriteLn;
        
        res := w. res;
        f. Close;
        IF (res = NIL) THEN
          res := f. res
        END
      END;
      
      IF (res = NIL) THEN
        RETURN String.New (path)
      ELSE
        RETURN NIL
      END
    END WriteMainModule;
  
  BEGIN
    Out.Ln;
    
    moduleName := test. ModuleName();
    test. file(File.URI). GetPath (path);
    CompileModule (moduleName, path, FALSE, status, signal);
    
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
    
    IF (result = processAccept) & (test. type >= Testcases.testError) THEN
      (* if the module must be evaluated, create a wrapper that calls the
         exported procedure and build an executable *)
      modPath := WriteMainModule (moduleName);
      IF (modPath = NIL) THEN
        result := processMainModuleError;
        Out.String ("--> failed to write main module"); Out.Ln
      ELSE
        COPY (modPath. array^, path);
        CompileModule (moduleName, path, TRUE, status, signal);
        Out.String ("--> build result: ");
        IF (status # 0) OR (signal # 0) THEN
          Out.String ("error"); Out.Ln;
          result := processBuildError
        ELSE
          Out.String ("ok"); Out.Ln;
          
          (* run the freshly generated program and see if it aborts *)
          GetFileName (moduleName, ".run.out", runOutFile);
          GetFileName (moduleName, ".run.err", runErrFile);
          COPY (moduleName. array^, path);
          Strings.Insert ("/x", 0, path);
          Strings.Insert (proc. binDir. array^, 0, path);
          Strings.Insert ("'", 0, path);
          Strings.Append ("' >'", path);
          Strings.Append (runOutFile, path);
          Strings.Append ("' 2>'", path);
          Strings.Append (runErrFile, path);
          Strings.Append ("'", path);
          Out.String ("### executing:"); Out.Ln;
          Out.String (path); Out.Ln;
          exit := ProcessManagment.system (path);
          status := ASH (exit, -8) MOD 256;
          signal := exit MOD 256;
          IF (status = 0) & (signal = 0) THEN
            result := processSuccess;
            IF (test. type = Testcases.testOutput) THEN
              test. output(File.URI). GetPath (path);
              result := proc. CompareOutput (path, runOutFile)
            END
          ELSE
            result := processError
          END;
          
          reportWriter. StartTag ("run-status", FALSE);
          AttrFileRef ("stdout", runOutFile);
          AttrFileRef ("stderr", runErrFile);
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
    END
  END Process;


END OOC:TestFramework:Processor.
