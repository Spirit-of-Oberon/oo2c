MODULE oo2c;

IMPORT
  StdChannels, Out, Err, URI, OS:ProcessManagement,
  Config:Section:Arguments, Config:Section:Options,
  Config:Value:Boolean, Config:Value:Integer, Config:Value:String,
  OOC:Logger, OOC:Config, OOC:Config:CCompiler, OOC:Package,
  OOC:SymbolTable:Builder, OOC:Error, Rep := OOC:Repository, OOC:Make;
  

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
  pkg: Package.Package;
  ok: BOOLEAN;

PROCEDURE NewConfig;
  BEGIN
    command := Config.AddOption("command", Integer.New(0));
    libraryName := Config.AddOption("libraryName", String.New(""));
    libraryVersion := Config.AddOption("libraryVersion", String.New(""));
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

PROCEDURE BuildPackage(pkg: Package.Package; install: BOOLEAN): BOOLEAN;
  VAR
    ok: BOOLEAN;
    i: LONGINT;
    lib: Package.Library;
    exec: Package.Executable;
    module: Rep.Module;
    
  PROCEDURE InstallLibrary(module: Rep.Module): BOOLEAN;
  (* pre: Full update has been done for the library's main module.  The
     target directory `libdir' must exist.  *)
    VAR
      uri: URI.URI;
      str: Make.ShellCommand;
    BEGIN
      uri := module.GetURI(Rep.modLibrary, TRUE);
      CCompiler.InstallProgramCmd(uri, TRUE, str);
      Logger.ShellCommand(str);
      RETURN (ProcessManagement.system(str) = 0);
    END InstallLibrary;
  
  PROCEDURE InstallExecutable(module: Rep.Module): BOOLEAN;
  (* pre: Full update has been done for the program's main module.  The
     target directory `bindir' must exist. *)
    VAR
      uri: URI.URI;
      str: Make.ShellCommand;
    BEGIN
      uri := module.GetURI(Rep.modExecutable, TRUE);
      CCompiler.InstallProgramCmd(uri, FALSE, str);
      Logger.ShellCommand(str);
      RETURN (ProcessManagement.system(str) = 0);
    END InstallExecutable;
  
  BEGIN
    ok := TRUE;
    
    FOR i := 0 TO pkg.library.size-1 DO
      lib := pkg.library.array[i](Package.Library);
      makeRules.SetLibraryName(lib.name^, lib.version.tuple);
      module := GetModule(lib.mainModule^);
      ok := makeRules.Update(module, Rep.modLibrary)
          & (~install OR InstallLibrary(module))
          & ok;
    END;
    
    FOR i := 0 TO pkg.executable.size-1 DO
      exec := pkg.executable.array[i](Package.Executable);
      module := GetModule(exec.mainModule^);
      ok := makeRules.Update(module, Rep.modExecutable)
          & (~install OR InstallExecutable(module))
          & ok;
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
    makeRules.SetLibraryName(libraryName.value(String.Value).string^,
                             libraryVersion.value(String.Value).string^);
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
        pkg := Config.repositories.GetPackage(arg^);
        IF (pkg = NIL) THEN
          Err.String ("Error: Cannot locate package ");
          Err.String (arg^);
          Err.Ln;
          HALT (1)
        ELSE
          ok := BuildPackage(pkg, (mode = installPackage)) & ok;
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
