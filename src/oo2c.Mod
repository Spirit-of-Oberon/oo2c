MODULE oo2c;

IMPORT
  StdChannels, Strings, Out, Err, ADT:String, URI, URI:Scheme:File,
  OS:ProcessManagement, Config:Section:Arguments, Config:Section:Options,
  Config:Value:Boolean, Config:Value:Integer, StringValue:=Config:Value:String,
  OOC:Logger, OOC:Config, OOC:Config:CCompiler, OOC:Package,
  OOC:SymbolTable:Builder, OOC:Error,
  Rep := OOC:Repository, OOC:Repository:FileSystem, OOC:Make;
  

CONST
  buildPackage = -1;
  installPackage = -2;
  
VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  mode: SHORTINT;
  command, libraryName, libraryVersion, useStderr: Options.Option;
  makeRules: Make.Rules;
  rep: Rep.Repository;
  pkg: Package.Package;
  ok: BOOLEAN;

PROCEDURE NewConfig;
  BEGIN
    command := Config.AddOption("command", Integer.New(0));
    libraryName := Config.AddOption("libraryName", StringValue.New(""));
    libraryVersion := Config.AddOption("libraryVersion", StringValue.New(""));
    useStderr := Config.AddOption("useStderr", Boolean.New(FALSE));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--make",
                 "<options><set name='command'>1</set></options>");
    Config.AddCmdLine ("--make-lib",
                       "<options><set name='command'>2</set>"+
                       "<set name='libraryName'>$1</set>"+
                       "<set name='libraryVersion'>$2</set></options>");
    Config.AddCmdLine ("--build-package",
                       "<options><set name='command'>3</set></options>");
    Config.AddCmdLine ("--install-package",
                       "<options><set name='command'>4</set></options>");
    Config.AddCmdLine ("--library",
                 "<options><set name='library'>TRUE</set></options>");
    Config.AddCmdLine ("--use-stderr",
                 "<options><set name='useStderr'>TRUE</set></options>");
    
    CCompiler.RegisterConfig;
  END NewConfig;

PROCEDURE GetModule (moduleName: ARRAY OF CHAR): Rep.Module;
  VAR
    m: Rep.Module;
  BEGIN
    m := Config.repositories.GetModule(arg^);
    IF (m = NIL) THEN
      Err.String ("Error: Cannot locate module ");
      Err.String (arg^);
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
      name: String.String;
    BEGIN
      (* For every symbol file, add an entry to the package's file list.  The
         source and destination name is the file name relative to the
         repository.  Upon installation, the former is interpreted relative to
         the providing repository, and the latter relative to the installation
         directory.  *)
      FOR i := 0 TO LEN(makeRules.imports^)-1 DO
        m := makeRules.imports[i];
        m.origin.GetLocalPath(m, Rep.modSymbolFile, path);
        name := String.New(path);
        pkg.fileSet.Append(Package.NewFile(name, name));
      END;
      
      IF InstallDirectory("", CCompiler.libdir.value(StringValue.Value).string^) THEN
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
      dir: String.String;
      sourcePrefix: Rep.URIBuffer;
      cmd: Make.ShellCommand;
      baseURI: URI.URI;
      
    PROCEDURE SameDirectory(a, b: Package.File): BOOLEAN;
      VAR
        sa, sb: String.String;
        i, j: LONGINT;
      BEGIN
        sa := a.destName; sb := b.destName;
        i := 0;
        WHILE (i # sa.length) & (i # sb.length) &
              (sa.array[i] = sb.array[i]) DO
          INC(i);
        END;
        WHILE (i # 0) & (sa.array[i-1] # "/") DO
          DEC(i);
        END;
        
        IF (i = 0) OR (sa.array[i-1] = "/") & (sb.array[i-1] = "/") THEN
          (* sa and sb have the same prefix ending with a "/"; check that both
             have no "/" in the rest of their path *)
          j := i;
          WHILE (j # sa.length) & (sa.array[j] # "/") DO
            INC (j);
          END;
          IF (j = sa.length) THEN
            j := i;
            WHILE (j # sb.length) & (sb.array[j] # "/") DO
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
        WHILE (i # 0) & (dir.array[i-1] # "/") DO
          DEC(i);
        END;
        dir := dir.Extract(0, i);
        
        IF InstallDirectory(CCompiler.oocdir.value(StringValue.Value).string^,
                            dir.array^) THEN
          COPY(CCompiler.installData.value(StringValue.Value).string^, cmd);
          WHILE (list # end) DO
            Strings.Append(" ", cmd);
            Strings.Append(sourcePrefix, cmd);
            Strings.Append(list(Package.File).name.array^, cmd);
            list := list.nextFileData;
          END;

          Strings.Append(" ", cmd);
          IF (CCompiler.oocdir.value(StringValue.Value).string^ # "") THEN
            Strings.Append(CCompiler.oocdir.value(StringValue.Value).string^,
                           cmd);
            Strings.Append("/", cmd);
          END;
          Strings.Append(dir.array^, cmd);

          Logger.ShellCommand(cmd);
          IF (ProcessManagement.system(cmd) # 0) THEN
            RETURN FALSE;
          END;
        ELSE
          RETURN FALSE;
        END;
      END;
      RETURN TRUE;
    END InstallFiles;
  
  BEGIN
    ok := TRUE;
    
    FOR i := 0 TO pkg.library.size-1 DO
      lib := pkg.library.array[i](Package.Library);
      makeRules.SetLibraryName(lib.name.array^, lib.version.tuple);
      module := GetModule(lib.mainModule.array^);
      ok := makeRules.Update(module, Rep.modLibrary)
          & (~install OR InstallLibrary(module, makeRules))
          & ok;
    END;
    
    FOR i := 0 TO pkg.executable.size-1 DO
      exec := pkg.executable.array[i](Package.Executable);
      module := GetModule(exec.mainModule.array^);
      ok := makeRules.Update(module, Rep.modExecutable)
          & (~install OR InstallExecutable(module))
          & ok;
    END;
    
    IF install THEN
      normSet := Package.Normalize(pkg.fileSet);
      ok := InstallFiles(normSet.head) & ok;
    END;
    
    RETURN ok;
  END BuildPackage;

BEGIN
  Error.oo2cStyleErrors := TRUE;
  Error.minErrorDistance := 16;
  Builder.doAutoImport := TRUE;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  ASSERT(Config.repositories.ParseMetaData());
  
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
    mode := Rep.modLibrary;
    makeRules.SetLibraryName(libraryName.value(StringValue.Value).string^,
                             libraryVersion.value(StringValue.Value).string^);
  | 3:
    mode := buildPackage;
  | 4:
    mode := installPackage;
  END;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stdout);
  END;
  IF ~cfgErrList.NoErrors() THEN
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: oo2c [--config <cfg-file>] {-r <base-dir>} [--make] <file>"); Out.Ln;
    HALT (1)
  ELSE
    ok := TRUE;
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments. Get (i);
      CASE mode OF
      | buildPackage, installPackage:
        pkg := Config.repositories.GetPackage(arg^, rep);
        IF (pkg = NIL) THEN
          Err.String ("Error: Cannot locate package ");
          Err.String (arg^);
          Err.Ln;
          HALT (1)
        ELSE
          ok := BuildPackage(pkg, rep, (mode = installPackage)) & ok;
        END;
      ELSE
        ok := makeRules.Update(GetModule(arg^), mode) & ok;
      END;
    END;
    
    IF ~ok THEN
      HALT (1)
    END
  END
END oo2c.
