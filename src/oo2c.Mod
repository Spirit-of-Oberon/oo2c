MODULE oo2c;

IMPORT
  Msg, StdChannels, Strings, Out, Err, Object, URI, URI:Scheme:File,
  ADT:StringBuffer,
  OS:ProcessManagement, Config:Section:Arguments, Config:Section:Options,
  Config:Value:Boolean, Config:Value:Integer, StringValue:=Config:Value:String,
  OOC:Logger, OOC:Config, OOC:Config:CCompiler, OOC:Package,
  OOC:SymbolTable:Builder, OOC:Config:Pragmas:StdPragmas, OOC:Error,
  Rep := OOC:Repository, OOC:Repository:FileSystem, OOC:Make;
  

CONST
  buildPackage = -1;
  installPackage = -2;
  uninstallPackage = -3;
  updateRepository = -4;
  getOption = -5;
  buildPackageDoc = -6;
  
VAR
  cfgErrList, errList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  mode: SHORTINT;
  command, useStderr, errorStyle, showHelp, showVersion: Options.Option;
  makeRules: Make.Rules;
  rep: Rep.Repository;
  pkg, pkgInfo: Package.Package;
  ok, forceUpdateRepository, doInstall: BOOLEAN;
  option: Options.Option;
  module: Rep.Module;
  
PROCEDURE NewConfig;
  BEGIN
    command := Config.AddOption("command", Integer.New(0));
    useStderr := Config.AddOption("useStderr", Boolean.New(FALSE));
    errorStyle := Config.AddOption("errorStyle",
                                   StringValue.New("file:line:column"));
    showHelp := Config.AddOption("showHelp", Boolean.New(FALSE));
    showVersion := Config.AddOption("showVersion", Boolean.New(FALSE));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--make,-M",
                 "<options><set name='command'>1</set></options>");
    Config.AddCmdLine ("--build-package",
                       "<options><set name='command'>2</set></options>");
    Config.AddCmdLine ("--install-package",
                       "<options><set name='command'>3</set></options>");
    Config.AddCmdLine ("--uninstall-package",
                       "<options><set name='command'>4</set></options>");
    Config.AddCmdLine ("--update-repository",
                       "<options><set name='command'>5</set></options>");
    Config.AddCmdLine ("--get-option",
                       "<options><set name='command'>6</set></options>");
    Config.AddCmdLine ("--build-pkg-doc",
                       "<options><set name='command'>7</set></options>");

    Config.AddCmdLine ("-h,--help",
                       "<options><set name='showHelp'>TRUE</set></options>");
    Config.AddCmdLine ("--version",
                       "<options><set name='showVersion'>TRUE</set></options>");
    Config.AddCmdLine ("--no-rtc",
                       "<pragmas>"+
                       "  <set name='Assertions'>FALSE</set>"+
                       "  <set name='IndexCheck'>FALSE</set>"+
                       "  <set name='DerefCheck'>FALSE</set>"+
                       "  <set name='OverflowCheck'>FALSE</set>"+
                       "  <set name='CaseSelectCheck'>FALSE</set>"+
                       "  <set name='FunctResult'>FALSE</set>"+
                       "  <set name='TypeGuard'>FALSE</set>"+
                       "</pragmas>");
    Config.AddCmdLine ("--verbose,-v", "");  (* ignored for now *)
    Config.AddCmdLine ("--warnings,-w", ""); (* ignored for now *)
    
    Config.AddCmdLine ("--error-style",
                       "<options><set name='errorStyle'>$1</set></options>");
    Config.AddCmdLine ("--use-stderr",
                       "<options><set name='useStderr'>TRUE</set></options>");
    CCompiler.RegisterConfig;
  END NewConfig;

PROCEDURE GetModule (moduleName: STRING): Rep.Module;
  VAR
    m: Rep.Module;
    chars: Object.CharsLatin1;
  BEGIN
    chars := moduleName(Object.String8).CharsLatin1();
    m := Config.repositories.GetModule(chars^);
    IF (m = NIL) THEN
      Err.String ("Error: Cannot locate module ");
      Err.String (chars^);
      Err.Ln;
      HALT (1)
    END;
    RETURN m;
  END GetModule;

PROCEDURE BuildPackage(pkg: Package.Package; rep: Rep.Repository;
                       install: BOOLEAN): BOOLEAN;
  VAR
    ok: BOOLEAN;
    i: LONGINT;
    lib: Package.Library;
    exec: Package.Executable;
    normSet: Package.FileSet;
    module: Rep.Module;
    res: Msg.Msg;
    str: ARRAY 256 OF CHAR;
    installObjects: BOOLEAN;

  PROCEDURE InstallDirectory(prefix, path: ARRAY OF CHAR): BOOLEAN;
    VAR
      str: Make.ShellCommand;
    BEGIN
      IF (prefix = "") THEN
        CCompiler.InstallDirectoryCmd(path, str);
      ELSE
        COPY(prefix, str);
        Strings.Append("/", str);
        Strings.Append(path, str);
        CCompiler.InstallDirectoryCmd(str, str);
      END;
      Logger.ShellCommand(str);
      RETURN (ProcessManagement.system(str) = 0);
    END InstallDirectory;
  
  PROCEDURE InstallLibrary(module: Rep.Module; makeRules: Make.Rules): BOOLEAN;
  (* Note: This procedure adds symbol files to the package's
     @ofield{pkg.fileSet}.

     pre: Full update has been done for the library's main module.  *)
    VAR
      uri: URI.URI;
      str: Make.ShellCommand;
      m: Rep.Module;
      path: Rep.URIBuffer;
      i: LONGINT;
      installObjects: BOOLEAN;
    BEGIN
      installObjects := ~CCompiler.HaveLibtool();
      
      (* For every symbol and header file, add an entry to the package's file
         list.  The source and destination name is the file name relative to
         the repository.  Upon installation, the former is interpreted relative
         to the providing repository, and the latter relative to the
         installation directory.  *)
      FOR i := 0 TO LEN(makeRules.imports^)-1 DO
        m := makeRules.imports[i];

        IF (m.origin = module.origin) THEN
          IF installObjects & ~m.ifData.NoObjectFile() THEN
            m.origin.GetLocalPath(m, Rep.modObjectFile, path);
            pkg.fileSet.Append(Package.NewFile(Object.NewLatin1(path), NIL));
          END;
          
          m.origin.GetLocalPath(m, Rep.modSymbolFile, path);
          pkg.fileSet.Append(Package.NewFile(Object.NewLatin1(path), NIL));
          m.origin.GetLocalPath(m, Rep.modHeaderFileC, path);
          pkg.fileSet.Append(Package.NewFile(Object.NewLatin1(path), NIL));
        END;
      END;

      IF installObjects THEN
        RETURN TRUE;
      ELSIF InstallDirectory("", CCompiler.libdir.value(StringValue.Value).string^) THEN
        uri := module.GetURI(Rep.modLibrary, TRUE);
        CCompiler.InstallProgramCmd(uri, TRUE, str);
        Logger.ShellCommand(str);
        RETURN (ProcessManagement.system(str) = 0);
      ELSE
        RETURN FALSE;
      END;
    END InstallLibrary;
  
  PROCEDURE InstallExecutable(module: Rep.Module): BOOLEAN;
  (* pre: Full update has been done for the program's main module.  *)
    VAR
      uri: URI.URI;
      str: Make.ShellCommand;
    BEGIN
      IF InstallDirectory("", CCompiler.bindir.value(StringValue.Value).string^) THEN
        uri := module.GetURI(Rep.modExecutable, TRUE);
        CCompiler.InstallProgramCmd(uri, FALSE, str);
        Logger.ShellCommand(str);
        RETURN (ProcessManagement.system(str) = 0);
      ELSE
        RETURN FALSE;
      END;
    END InstallExecutable;

  PROCEDURE InstallFiles(list: Package.FileData): BOOLEAN;
    VAR
      end: Package.FileData;
      dir: STRING;
      string: Object.String;
      sourcePrefix: Rep.URIBuffer;
      cmd: StringBuffer.StringBuffer;
      baseURI: URI.URI;
      chars: Object.CharsLatin1;
      charsCmd: StringBuffer.CharsLatin1;
      
    PROCEDURE SameDirectory(a, b: Package.File): BOOLEAN;
      VAR
        sa, sb: STRING;
        i, j: LONGINT;
      BEGIN
        sa := a.destName; sb := b.destName;
        i := 0;
        WHILE (i # sa.length) & (i # sb.length) &
              (sa.CharAt(i) = sb.CharAt(i)) DO
          INC(i);
        END;
        WHILE (i # 0) & (sa.CharAt(i-1) # "/") DO
          DEC(i);
        END;
        
        IF (i = 0) OR
           ((sa.CharAt(i-1) = "/") &
            (sb.CharAt(i-1) = "/")) THEN
          (* sa and sb have the same prefix ending with a "/"; check that both
             have no "/" in the rest of their path *)
          j := i;
          WHILE (j # sa.length) & (sa.CharAt(j) # "/") DO
            INC (j);
          END;
          IF (j = sa.length) THEN
            j := i;
            WHILE (j # sb.length) & (sb.CharAt(j) # "/") DO
              INC (j);
            END;
            RETURN (j = sb.length)
          END;
        END;
        RETURN FALSE;
      END SameDirectory;
    
    BEGIN
      baseURI := rep(FileSystem.Repository).relativeBaseURI;
      baseURI(File.URI).GetPath(sourcePrefix);
      
      WHILE (list # NIL) DO
        end := list.nextFileData;
        WHILE (end # NIL) &
              SameDirectory(list(Package.File), end(Package.File)) DO
          end := end.nextFileData;
        END;

        (* extract name of target directory *)
        dir := list(Package.File).destName;
        i := dir.length;
        WHILE (i # 0) & (dir.CharAt(i-1) # "/") DO
          DEC(i);
        END;
        string := dir.Substring(0, i);
        dir := string(Object.String8);

        chars := dir(Object.String8).CharsLatin1();
        IF InstallDirectory(CCompiler.oocdir.value(StringValue.Value).string^,
                            chars^) THEN
          cmd := StringBuffer.NewLatin1(CCompiler.installData.value(StringValue.Value).string^);
          WHILE (list # end) DO
            cmd.Append(" ");
            cmd.AppendLatin1(sourcePrefix);
            cmd.Append(list(Package.File).name);
            list := list.nextFileData;
          END;

          cmd.Append(" ");
          IF (CCompiler.oocdir.value(StringValue.Value).string^ # "") THEN
            cmd.AppendLatin1(CCompiler.oocdir.value(StringValue.Value).string^);
            cmd.Append("/");
          END;
          cmd.Append(dir);

          charsCmd := cmd.CharsLatin1();
          Logger.ShellCommand(charsCmd^);
          IF (ProcessManagement.system(charsCmd^) # 0) THEN
            RETURN FALSE;
          END;
        ELSE
          RETURN FALSE;
        END;
      END;
      RETURN TRUE;
    END InstallFiles;

  PROCEDURE BuildDocs(module: Rep.Module; makeRules: Make.Rules;
                      install: BOOLEAN): BOOLEAN;
    VAR
      m: Rep.Module;
      ok: BOOLEAN;
      i: LONGINT;
      path: Rep.URIBuffer;
    BEGIN
      ok := TRUE;
      IF Config.HaveXsltProc() THEN
        i := 0;
        WHILE ok & (i #  LEN(makeRules.imports^)) DO
          m := makeRules.imports[i];
          IF install THEN
            IF (m.origin = module.origin) THEN
              m.origin.GetLocalPath(m, Rep.modInterfaceDescr, path);
              pkg.fileSet.Append(Package.NewFile(Object.NewLatin1(path), NIL));
              m.origin.GetLocalPath(m, Rep.modInterfaceHTML, path);
              pkg.fileSet.Append(Package.NewFile(Object.NewLatin1(path), NIL));
            END;
          ELSE
            ok := makeRules.Update(m, Rep.modInterfaceHTML);
          END;
          INC(i);
        END;
      END;
      RETURN ok;
    END BuildDocs;
  
  BEGIN
    installObjects := ~CCompiler.HaveLibtool();
    ok := TRUE;

    i := 0;
    WHILE ok & (i # pkg.library.size) DO
      lib := pkg.library.array[i](Package.Library);

      module := GetModule(lib.mainModule);
      IF installObjects THEN
        ok := makeRules.Update(module, Rep.modExecutable)
            & (~install OR InstallLibrary(module, makeRules));
      ELSE
        makeRules.SetLibraryName(lib.name,
                                 Object.NewLatin1(lib.version.tuple));
        ok := makeRules.Update(module, Rep.modLibrary)
            & (~install OR InstallLibrary(module, makeRules));
      END;

      IF ok THEN
        (* build HTML documentation for modules in library *)
        ok := BuildDocs(module, makeRules, install);
      END;
      
      makeRules.SetLibraryName(NIL, NIL);
      INC(i);
    END;

    i := 0;
    WHILE ok & (i # pkg.executable.size) DO
      exec := pkg.executable.array[i](Package.Executable);
      module := GetModule(exec.mainModule);
      ok := makeRules.Update(module, Rep.modExecutable)
          & (~install OR InstallExecutable(module));
      INC(i);
    END;
    
    IF ok & install THEN
      normSet := Package.Normalize(pkg.fileSet);
      ok := InstallFiles(normSet.head);
    END;

    IF ok & install THEN
      Package.WritePackage(pkg,
                           CCompiler.oocdir.value(StringValue.Value).string^,
                           res);
      IF (res # NIL) THEN
        res.GetText(str);
        Out.String(str); Out.Ln;
        ok := FALSE;
      END;
    END;
    
    RETURN ok;
  END BuildPackage;

PROCEDURE UninstallPackage(pkg: Package.Package);
  VAR
    i: LONGINT;
    normSet: Package.FileSet;
    
  PROCEDURE UninstallLibrary(library: Package.Library);
    VAR
      str: Make.ShellCommand;
      ok: BOOLEAN;
      b: StringBuffer.StringBuffer;
    BEGIN
      b := StringBuffer.NewLatin1(CCompiler.libdir.value(StringValue.Value).string^);
      b.Append("/lib");
      b.Append(library.name);
      b.Append(".la");
      CCompiler.UninstallProgramCmd(b.ToString(), TRUE, str);
      Logger.ShellCommand(str);
      ok := (ProcessManagement.system(str) = 0);
    END UninstallLibrary;
  
  PROCEDURE UninstallExecutable(executable: Package.Executable);
    VAR
      str: Make.ShellCommand;
      ok: BOOLEAN;
      b: StringBuffer.StringBuffer;
    BEGIN
      b := StringBuffer.NewLatin1(CCompiler.bindir.value(StringValue.Value).string^);
      b.Append("/");
      b.Append(executable.mainModule);
      CCompiler.UninstallProgramCmd(b.ToString(), FALSE, str);
      Logger.ShellCommand(str);
      ok := (ProcessManagement.system(str) = 0);
    END UninstallExecutable;

  PROCEDURE UninstallFiles(list: Package.FileData);
    VAR
      cmd: StringBuffer.CharsLatin1;
      ok: BOOLEAN;
      b: StringBuffer.StringBuffer;
    BEGIN
      WHILE (list # NIL) DO
        b := StringBuffer.NewLatin1(CCompiler.uninstall.value(StringValue.Value).string^);
        b.Append(" ");
        b.AppendLatin1(CCompiler.oocdir.value(StringValue.Value).string^);
        b.Append("/");
        b.Append(list(Package.File).destName);

        cmd := b.CharsLatin1();
        Logger.ShellCommand(cmd^);
        ok := (ProcessManagement.system(cmd^) = 0);
        list := list.nextFileData;
      END;
    END UninstallFiles;

  PROCEDURE UninstallPkgInfo(pkg: Package.Package);
    VAR
      cmd: Make.ShellCommand;
      ok: BOOLEAN;
    BEGIN
      Package.RemovePkgInfoCmd
          (pkg,
           CCompiler.oocdir.value(StringValue.Value).string^,
           CCompiler.uninstall.value(StringValue.Value).string^,
           cmd);
        Logger.ShellCommand(cmd);
        ok := (ProcessManagement.system(cmd) = 0);
    END UninstallPkgInfo;
  
  BEGIN
    i := 0;
    WHILE (i # pkg.library.size) DO
      UninstallLibrary(pkg.library.array[i](Package.Library));
      INC(i);
    END;

    i := 0;
    WHILE (i # pkg.executable.size) DO
      UninstallExecutable(pkg.executable.array[i](Package.Executable));
      INC(i);
    END;
    
    normSet := Package.Normalize(pkg.fileSet);
    UninstallFiles(normSet.head);

    UninstallPkgInfo(pkg);
  END UninstallPackage;

PROCEDURE BuildPackageDoc(pkg: Package.Package): BOOLEAN;
  VAR
    ok: BOOLEAN;
    i: LONGINT;
    lib: Package.Library;
    exec: Package.Executable;

  PROCEDURE BuildDocs(module: Rep.Module): BOOLEAN;
    VAR
      ok: BOOLEAN;
      i: LONGINT;
      list: Make.ModuleList;
    BEGIN
      ok := makeRules.Update(module, Rep.modSymbolFile);
      
      list := Make.ModuleClosure(module, NIL);
      i := 0;
      WHILE ok & (i #  LEN(list^)) DO
        IF (list[i].origin = module.origin) THEN
          ok := makeRules.Update(list[i], Rep.modInterfaceHTML);
        END;
        INC(i);
      END;
      RETURN ok;
    END BuildDocs;
  
  BEGIN
    ok := TRUE;

    i := 0;
    WHILE ok & (i # pkg.library.size) DO
      lib := pkg.library.array[i](Package.Library);
      ok := BuildDocs(GetModule(lib.mainModule));
      INC(i);
    END;

    i := 0;
    WHILE ok & (i # pkg.executable.size) DO
      exec := pkg.executable.array[i](Package.Executable);
      ok := BuildDocs(GetModule(exec.mainModule));
      INC(i);
    END;
    
    RETURN ok;
  END BuildPackageDoc;

PROCEDURE WriteHelp();
  BEGIN
    Out.String("Usage:"); Out.Ln;
    Out.String("  oo2c [options] <module>..."); Out.Ln;
    Out.String("  oo2c (--make|-M) [options] <module>"); Out.Ln;
    Out.String("  oo2c --build-package [options] <package>"); Out.Ln;
    Out.String("  oo2c --install-package [options] <package>"); Out.Ln;
    Out.String("  oo2c --uninstall-package [options] <package>"); Out.Ln;
    Out.String("  oo2c --build-pkg-doc [options] <package>"); Out.Ln;
    Out.String("Options:"); Out.Ln;
    Out.String("  --config <file>"); Out.Ln;
    Out.String("  --repository <directory>, -r <directory>"); Out.Ln;
    Out.String("  --no-rtc"); Out.Ln;
    Out.String("  --error-style <string>"); Out.Ln;
  END WriteHelp;

BEGIN
  Error.minErrorDistance := 16;
  Builder.doAutoImport := Builder.fullAutoImport;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  makeRules := Make.NewRules();
  IF useStderr.value(Boolean.Value).boolean THEN
    makeRules.SetErrOut(StdChannels.stderr);
  END;
    
  CASE command.value(Integer.Value).integer OF
  | 0:
    mode := Rep.modCodeFileC;
  | 1:
    mode := Rep.modExecutable;
  | 2:
    mode := buildPackage;
  | 3:
    mode := installPackage;
  | 4:
    mode := uninstallPackage;
  | 5:
    mode := updateRepository;
  | 6:
    mode := getOption; Logger.silence := TRUE;
  | 7:
    mode := buildPackageDoc;
  END;
  IF (errorStyle.value(StringValue.Value).string^ = "file:line:column") THEN
    Error.style := Error.styleFileLineColumn;
  ELSIF (errorStyle.value(StringValue.Value).string^ = "char-pos") THEN
    Error.style := Error.styleCharPos;
  END;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stdout);
  END;
  IF ~cfgErrList.NoErrors() THEN
    HALT (1)
  ELSIF showVersion.value(Boolean.Value).boolean THEN
    Out.String("oo2c/gcc ");
    Out.String(StdPragmas.defaultCompilerVersion);
    Out.Ln;
    HALT(0);
  ELSIF showHelp.value(Boolean.Value).boolean THEN
    WriteHelp;
  ELSIF (mode = updateRepository) # (Config.arguments. ArgNumber() = 0) THEN
    WriteHelp;
    HALT (1)
  ELSE
    ok := TRUE;

    IF (mode = updateRepository) THEN
      ok := Package.UpdateRepository(CCompiler.oocdir.value(StringValue.Value).string^);
    ELSE
      IF ~Package.ParseMetaData(Config.options, Config.pragmas) THEN
        HALT(1);
      END;
      
      forceUpdateRepository := FALSE;
      i := 0;
      WHILE ok & (i # Config.arguments. ArgNumber()) DO
        arg := Config.arguments. Get (i);
        CASE mode OF
        | buildPackage, installPackage:
          doInstall := (mode = installPackage);
          pkg := Package.GetPackage(arg^, rep);
          IF (pkg = NIL) THEN
            Err.String ("Error: Cannot locate package ");
            Err.String (arg^);
            Err.Ln;
            HALT (1)
          ELSE
            IF doInstall THEN
              pkgInfo := Package.GetPkgInfo(CCompiler.oocdir.value(StringValue.Value).string^, arg^, errList);
              IF (errList.msgCount = 0) THEN
                UninstallPackage(pkgInfo);
              END;
            END;
            ok := BuildPackage(pkg, rep, doInstall);
            forceUpdateRepository := doInstall;
          END;
          
        | uninstallPackage:
          pkg := Package.GetPkgInfo(CCompiler.oocdir.value(StringValue.Value).string^, arg^, errList);
          IF (errList.msgCount # 0) THEN
            errList.Write(StdChannels.stdout);
          END;
          IF (pkg = NIL) THEN
            Err.String ("Error: Cannot locate package ");
            Err.String (arg^);
            Err.Ln;
            HALT (1)
          ELSE
            UninstallPackage(pkg);
            forceUpdateRepository := TRUE;
          END;


        | getOption:
          option := Config.options.Get(arg^);
          IF (option = NIL) THEN
            Out.String("(none)");
          ELSE
            Out.String(option.value(StringValue.Value).string^);
          END;
          Out.Ln;
          
        | buildPackageDoc:
          pkg := Package.GetPackage(arg^, rep);
          IF (pkg = NIL) THEN
            Err.String ("Error: Cannot locate package ");
            Err.String (arg^);
            Err.Ln;
            HALT (1)
          ELSE
            ok := BuildPackageDoc(pkg);
          END;
          
        ELSE
          module := GetModule(Object.NewLatin1(arg^));
          IF (mode = Rep.modCodeFileC) THEN
            makeRules.SetAllImportsModule(module);
          END;
          ok := makeRules.Update(module, mode);
          makeRules.SetAllImportsModule(NIL);
        END;
        INC(i);
      END;

      IF ok & forceUpdateRepository THEN
        ok := Package.UpdateRepository(CCompiler.oocdir.value(StringValue.Value).string^);
      END;
    END;
    
    IF ~ok THEN
      HALT (1)
    END
  END
END oo2c.
