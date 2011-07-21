(* 	$Id: oo2c.Mod,v 1.73 2004/04/03 14:44:47 mva Exp $	 *)
MODULE oo2c;
(*  Main module for the Oberon-2 to C translator.
    Copyright (C) 2002-2004  Michael van Acken

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
  IO:StdChannels, Out, Err, Object, URI, URI:Scheme:File, CfgData := Config,
  ADT:StringBuffer, IO, OS:ProcessManagement, OS:Path, OS:Files,
  Config:Section:Options,
  OOC:Logger, OOC:Config, OOC:Config:CCompiler, OOC:Package,
  OOC:SymbolTable:Builder, OOC:Config:StdPragmas, OOC:Error,
  Rep := OOC:Repository, OOC:Repository:FileSystem, OOC:Make, OOC:SSA:Stats;
  

CONST
  buildPackage = -1;
  installPackage = -2;
  uninstallPackage = -3;
  updateRepository = -4;
  getOption = -5;
  buildPackageDoc = -6;
  packageInstalled = -7;
  listPackages     = -8;
  
VAR
  cfgErrList, errList: Error.List;
  i: LONGINT;
  arg: STRING;
  mode: SHORTINT;
  command, forceUpdate, listUses, useStderr, writeStats,
      verbose, errorStyle, showHelp, showVersion: Options.Option;
  makeRules: Make.Rules;
  rep: Rep.Repository;
  r: Package.Repository;
  pkg, pkgInfo: Package.Package;
  ok, forceUpdateRepository, doInstall: BOOLEAN;
  option: Options.Option;
  module: Rep.Module;
  
PROCEDURE NewConfig;
  BEGIN
    command := Config.AddOption("command", CfgData.NewIntegerVar(0));
    forceUpdate := Config.AddOption("forceUpdate", CfgData.NewBooleanVar(FALSE));
    listUses := Config.AddOption("listUses", CfgData.NewStringVar(""));
    useStderr := Config.AddOption("useStderr", CfgData.NewBooleanVar(FALSE));
    writeStats := Config.AddOption("writeStats", CfgData.NewBooleanVar(FALSE));
    verbose := Config.AddOption("verbose", CfgData.NewBooleanVar(FALSE));
    errorStyle := Config.AddOption("errorStyle",
                                 CfgData.NewStringVar("file:line:column"));
    showHelp := Config.AddOption("showHelp", CfgData.NewBooleanVar(FALSE));
    showVersion := Config.AddOption("showVersion", CfgData.NewBooleanVar(FALSE));
    
    Config.AddRepositoryListEnv();
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
    Config.AddCmdLine ("--package-installed",
                       "<options><set name='command'>8</set></options>");
    Config.AddCmdLine ("--list-packages",
                       "<options><set name='command'>9</set></options>");

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
    Config.AddCmdLine ("--verbose,-v",
                       "<options><set name='verbose'>TRUE</set></options>");
    Config.AddCmdLine ("--warnings,-w", ""); (* ignored for now *)
    
    Config.AddCmdLine ("-A,--all",
                       "<options><set name='forceUpdate'>TRUE</set></options>");
    Config.AddCmdLine ("--uses",
                       "<options>"+
                       "  <set name='listUses'>$1</set>"+
                       "  <set name='command'>1</set>"+  (* --make *)
                       "</options>");
    Config.AddCmdLine ("--error-style",
                       "<options><set name='errorStyle'>$1</set></options>");
    Config.AddCmdLine ("--use-stderr",
                       "<options><set name='useStderr'>TRUE</set></options>");
    Config.AddCmdLine ("--stats",
                       "<options><set name='writeStats'>TRUE</set></options>");
    CCompiler.RegisterConfig;
  END NewConfig;

PROCEDURE GetModule (moduleName: STRING): Rep.Module;
  VAR
    m: Rep.Module;
    chars: Object.CharsLatin1;
    str: Object.String8;
  BEGIN
    str := moduleName.ToString8("?");
    chars := str.CharsLatin1();
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
                       install: BOOLEAN): BOOLEAN
RAISES IO.Error;
  VAR
    ok: BOOLEAN;
    i: LONGINT;
    lib: Package.Library;
    exec: Package.Executable;
    normSet: Package.FileSet;
    module: Rep.Module;
    installObjects: BOOLEAN;

  PROCEDURE InstallDirectory(prefix, path: STRING): BOOLEAN;
    VAR
      cmd: STRING;
    BEGIN
      IF (prefix.length # 0) THEN
        path := prefix+"/"+path;
      END;

      IF Files.Exists(path) THEN
        (* path name exists (although it may be a non-directory *)
        RETURN TRUE;
      ELSE
        cmd := CCompiler.InstallDirectoryCmd(path);
        Logger.ShellCommand(cmd);
        RETURN (ProcessManagement.system(cmd) = 0);
      END;
    END InstallDirectory;
  
  PROCEDURE InstallLibrary(module: Rep.Module; makeRules: Make.Rules): BOOLEAN;
  (* Note: This procedure adds symbol files to the package's
     @ofield{pkg.fileSet}.

     pre: Full update has been done for the library's main module.  *)
    VAR
      uri: URI.URI;
      cmd: STRING;
      m: Rep.Module;
      i: LONGINT;
      installObjects: BOOLEAN;
    BEGIN
      installObjects := ~CCompiler.HaveLibtool();
      
      (* For every symbol file, its doc string file, and the header file, add
         an entry to the package's file list.  The source and destination name
         is the file name relative to the repository.  Upon installation, the
         former is interpreted relative to the providing repository, and the
         latter relative to the installation directory.  *)
      FOR i := 0 TO LEN(makeRules.imports^)-1 DO
        m := makeRules.imports[i];

        IF (m.origin = module.origin) THEN
          IF installObjects & ~m.ifData.NoObjectFile() THEN
            pkg.fileSet.Append(Package.NewFile(m.origin.GetLocalPath(m, Rep.modObjectFile), NIL));
          END;
          
          pkg.fileSet.Append(Package.NewFile(m.origin.GetLocalPath(m, Rep.modSymbolFile), NIL));
          pkg.fileSet.Append(Package.NewFile(m.origin.GetLocalPath(m, Rep.modSymbolFileDoc), NIL));
          pkg.fileSet.Append(Package.NewFile(m.origin.GetLocalPath(m, Rep.modHeaderFileC), NIL));
        END;
      END;

      IF installObjects THEN
        RETURN TRUE;
      ELSIF InstallDirectory("", CCompiler.libdir.value(CfgData.StringVar).string) THEN
        uri := module.GetURI(Rep.modLibrary, TRUE);
        cmd := CCompiler.InstallProgramCmd(uri, TRUE);
        Logger.ShellCommand(cmd);
        RETURN (ProcessManagement.system(cmd) = 0);
      ELSE
        RETURN FALSE;
      END;
    END InstallLibrary;
  
  PROCEDURE InstallExecutable(module: Rep.Module): BOOLEAN;
  (* pre: Full update has been done for the program's main module.  *)
    VAR
      uri: URI.URI;
      cmd: STRING;
    BEGIN
      IF InstallDirectory("", CCompiler.bindir.value(CfgData.StringVar).string) THEN
        uri := module.GetURI(Rep.modExecutable, TRUE);
        cmd := CCompiler.InstallProgramCmd(uri, FALSE);
        Logger.ShellCommand(cmd);
        RETURN (ProcessManagement.system(cmd) = 0);
      ELSE
        RETURN FALSE;
      END;
    END InstallExecutable;

  PROCEDURE InstallFiles(list: Package.FileData): BOOLEAN;
    VAR
      end: Package.FileData;
      dir, str, sourcePrefix: STRING;
      cmd: StringBuffer.StringBuffer;
      baseURI: URI.URI;
      chars: Object.CharsLatin1;
      
    (*PROCEDURE SameDirectory(a, b: Package.File): BOOLEAN;
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
      END SameDirectory;*)
    
    BEGIN
      baseURI := rep(FileSystem.Repository).relativeBaseURI;
      sourcePrefix := baseURI(File.URI).GetPath();
      
      WHILE (list # NIL) DO
        end := list.nextFileData;
        (* don't call install with multiple input files: the fallback script
           install-sh does not support this
           
           WHILE (end # NIL) &
              SameDirectory(list(Package.File), end(Package.File)) DO
          end := end.nextFileData;
        END;*)

        dir := Path.DirName(list(Package.File).destName);
        
        chars := dir(Object.String8).CharsLatin1();
        IF InstallDirectory(CCompiler.oocdir.value(CfgData.StringVar).string,
                            dir(Object.String8)) THEN
          cmd := StringBuffer.New(CCompiler.installData.value(CfgData.StringVar).string);
          WHILE (list # end) DO
            cmd.Append(" ");
            cmd.Append(sourcePrefix);
            cmd.Append(list(Package.File).name);
            list := list.nextFileData;
          END;

          cmd.Append(" ");
          IF (CCompiler.oocdir.value(CfgData.StringVar).string.length # 0) THEN
            cmd.Append(CCompiler.oocdir.value(CfgData.StringVar).string);
            IF (dir.length # 0) THEN
              cmd.Append("/");
            END;
          END;
          cmd.Append(dir);

          str := cmd.ToString();
          Logger.ShellCommand(str);
          IF (ProcessManagement.system(str) # 0) THEN
            RETURN FALSE;
          END;
        ELSE
          RETURN FALSE;
        END;
      END;
      RETURN TRUE;
    END InstallFiles;

  PROCEDURE BuildDocs(module: Rep.Module; makeRules: Make.Rules;
                      install: BOOLEAN): BOOLEAN
  RAISES IO.Error;
    VAR
      m: Rep.Module;
      ok: BOOLEAN;
      i: LONGINT;
    BEGIN
      ok := TRUE;
      IF Config.HaveXsltProc() THEN
        i := 0;
        WHILE ok & (i #  LEN(makeRules.imports^)) DO
          m := makeRules.imports[i];
          IF (m.origin = module.origin) THEN
            IF install THEN
              pkg.fileSet.Append(Package.NewFile(m.origin.GetLocalPath(m, Rep.modInterfaceDescr), NIL));
              pkg.fileSet.Append(Package.NewFile(m.origin.GetLocalPath(m, Rep.modInterfaceHTML), NIL));
            ELSE
              ok := makeRules.Update(m, Rep.modInterfaceHTML);
            END;
          END;
          INC(i);
        END;
      END;
      RETURN ok;
    END BuildDocs;
  
  BEGIN
    Rep.readDocStrings := TRUE;
    installObjects := ~CCompiler.HaveLibtool();
    ok := TRUE;

    i := 0;
    WHILE ok & (i # pkg.library.size) DO
      lib := pkg.library.array[i];

      module := GetModule(lib.mainModule);
      IF installObjects THEN
        ok := makeRules.Update(module, Rep.modExecutable)
            & (~install OR InstallLibrary(module, makeRules));
      ELSE
        makeRules.SetLibrary(lib);
        ok := makeRules.Update(module, Rep.modLibrary)
            & (~install OR InstallLibrary(module, makeRules));
      END;

      IF ok THEN
        (* build HTML documentation for modules in library *)
        ok := BuildDocs(module, makeRules, install);
      END;
      
      makeRules.SetLibrary(NIL);
      INC(i);
    END;

    i := 0;
    WHILE ok & (i # pkg.executable.size) DO
      exec := pkg.executable.array[i];
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
                           CCompiler.oocdir.value(CfgData.StringVar).string);
    END;
    
    RETURN ok;
  END BuildPackage;

PROCEDURE UninstallPackage(pkg: Package.Package);
  VAR
    i: LONGINT;
    normSet: Package.FileSet;
    
  PROCEDURE UninstallLibrary(library: Package.Library);
    VAR
      cmd: STRING;
      ok: BOOLEAN;
      b: StringBuffer.StringBuffer;
    BEGIN
      b := StringBuffer.NewLatin1("");
      b.Append(CCompiler.libdir.value(CfgData.StringVar).string);
      b.Append("/lib");
      b.Append(library.name);
      b.Append(".la");
      cmd := CCompiler.UninstallProgramCmd(b.ToString(), TRUE);
      Logger.ShellCommand(cmd);
      ok := (ProcessManagement.system(cmd) = 0);
    END UninstallLibrary;
  
  PROCEDURE UninstallExecutable(executable: Package.Executable);
    VAR
      cmd: STRING;
      ok: BOOLEAN;
      b: StringBuffer.StringBuffer;
    BEGIN
      b := StringBuffer.NewLatin1("");
      b.Append(CCompiler.bindir.value(CfgData.StringVar).string);
      b.Append("/");
      b.Append(executable.mainModule);
      cmd := CCompiler.UninstallProgramCmd(b.ToString(), FALSE);
      Logger.ShellCommand(cmd);
      ok := (ProcessManagement.system(cmd) = 0);
    END UninstallExecutable;

  PROCEDURE UninstallFiles(list: Package.FileData);
    VAR
      str: STRING;
      ok: BOOLEAN;
      b: StringBuffer.StringBuffer;
    BEGIN
      WHILE (list # NIL) DO
        b := StringBuffer.New(CCompiler.uninstall.value(CfgData.StringVar).string);
        b.Append(" ");
        b.Append(CCompiler.oocdir.value(CfgData.StringVar).string);
        b.Append("/");
        b.Append(list(Package.File).destName);

        str := b.ToString();
        Logger.ShellCommand(str);
        ok := (ProcessManagement.system(str) = 0);
        list := list.nextFileData;
      END;
    END UninstallFiles;

  PROCEDURE UninstallPkgInfo(pkg: Package.Package);
    VAR
      ok: BOOLEAN;
      cmd: STRING;
    BEGIN
      cmd := Package.RemovePkgInfoCmd
          (pkg,
           CCompiler.oocdir.value(CfgData.StringVar).string,
           CCompiler.uninstall.value(CfgData.StringVar).string);
      Logger.ShellCommand(cmd);
      ok := (ProcessManagement.system(cmd) = 0);
    END UninstallPkgInfo;
  
  BEGIN
    i := 0;
    WHILE (i # pkg.library.size) DO
      UninstallLibrary(pkg.library.array[i]);
      INC(i);
    END;

    i := 0;
    WHILE (i # pkg.executable.size) DO
      UninstallExecutable(pkg.executable.array[i]);
      INC(i);
    END;
    
    normSet := Package.Normalize(pkg.fileSet);
    UninstallFiles(normSet.head);

    UninstallPkgInfo(pkg);
  END UninstallPackage;

PROCEDURE BuildPackageDoc(pkg: Package.Package): BOOLEAN
RAISES IO.Error;
  VAR
    ok: BOOLEAN;
    i: LONGINT;
    lib: Package.Library;
    exec: Package.Executable;

  PROCEDURE BuildDocs(module: Rep.Module): BOOLEAN
  RAISES IO.Error;
    VAR
      ok: BOOLEAN;
      i: LONGINT;
      list: Make.ModuleList;
    BEGIN
      ok := makeRules.Update(module, Rep.modSymbolFile);
      
      list := Make.ModuleClosure(module);
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
    Rep.readDocStrings := TRUE;
    ok := TRUE;

    i := 0;
    WHILE ok & (i # pkg.library.size) DO
      lib := pkg.library.array[i];
      ok := BuildDocs(GetModule(lib.mainModule));
      INC(i);
    END;

    i := 0;
    WHILE ok & (i # pkg.executable.size) DO
      exec := pkg.executable.array[i];
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
    Out.String("  oo2c --uses <ext-ident> [options] <module> ..."); Out.Ln;
    Out.String("  oo2c --build-package [options] <package>"); Out.Ln;
    Out.String("  oo2c --install-package [options] <package>"); Out.Ln;
    Out.String("  oo2c --uninstall-package [options] <package>"); Out.Ln;
    Out.String("  oo2c --build-pkg-doc [options] <package>"); Out.Ln;
    Out.String("  oo2c --package-installed [options] <package>"); Out.Ln;
    Out.String("  oo2c --list-packages [options]"); Out.Ln;
    Out.String("Options:"); Out.Ln;
    Out.String("  --config <file>"); Out.Ln;
    Out.String("  --repository <directory>, -r <directory>"); Out.Ln;
    Out.String("  --no-rtc"); Out.Ln;
    Out.String("  (--all|-A)"); Out.Ln;
    Out.String("  --error-style (file:line:column|char-pos|attributes)");
    Out.Ln;
  END WriteHelp;

BEGIN  <*Warnings:=FALSE*>
  Error.minErrorDistance := 16;
  Builder.doAutoImport := Builder.fullAutoImport;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  makeRules := Make.NewRules();
  IF useStderr.value(CfgData.BooleanVar).boolean THEN
    makeRules.SetErrOut(StdChannels.stderr);
  END;
  makeRules.SetForceUpdate(forceUpdate.value(CfgData.BooleanVar).boolean);
  ok := makeRules.UsageTracking(listUses.value(CfgData.StringVar).string);
  IF ~ok THEN
    Err.String ("Error: Invalid selector string for `--uses'");
    Err.Ln;
    HALT (1)
  END;
  Make.writeStats := writeStats.value(CfgData.BooleanVar).boolean;
  Logger.silence := ~verbose.value(CfgData.BooleanVar).boolean;
  
  CASE command.value(CfgData.IntegerVar).integer OF
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
  | 8:
    mode := packageInstalled; Logger.silence := TRUE;
  | 9:
    mode := listPackages; Logger.silence := TRUE;
  END;
  IF errorStyle.value(CfgData.StringVar).string.Equals("file:line:column") THEN
    Error.style := Error.styleFileLineColumn;
  ELSIF errorStyle.value(CfgData.StringVar).string.Equals("char-pos") THEN
    Error.style := Error.styleCharPos;
  END;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT(1);
  ELSIF showVersion.value(CfgData.BooleanVar).boolean THEN
    Out.String("oo2c/");
    Out.String(StdPragmas.defaultTargetArch);
    Out.String(" ");
    Out.String(StdPragmas.defaultCompilerVersion);
    Out.Ln;
    HALT(0);
  ELSIF showHelp.value(CfgData.BooleanVar).boolean THEN
    WriteHelp;
  ELSIF ((mode = updateRepository) OR (mode = listPackages))
    # (Config.arguments. ArgNumber() = 0) THEN
    WriteHelp;
    HALT (1)
  ELSE
    ok := TRUE;

    IF (mode = updateRepository) THEN
      ok := Package.UpdateRepository(CCompiler.oocdir.value(CfgData.StringVar).string);

    ELSIF (mode = listPackages) THEN
      r := Package.GetRepository(CCompiler.oocdir.value(CfgData.StringVar).string, errList);
      errList.Write(StdChannels.stderr);
      FOR i := 0 TO r.installedPkgs.size-1 DO
        Out.Object(r.installedPkgs.array[i]); Out.Ln;
      END;

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
          pkg := Package.GetPackage(arg, rep);
          IF (pkg = NIL) THEN
            Err.String ("Error: Cannot locate package ");
            Err.Object (arg);
            Err.Ln;
            HALT (1)
          ELSE
            IF doInstall THEN
              pkgInfo := Package.GetPkgInfo(CCompiler.oocdir.value(CfgData.StringVar).string, arg, errList);
              IF (pkgInfo # NIL) & (errList.msgCount = 0) THEN
                UninstallPackage(pkgInfo);
              END;
            END;
            ok := BuildPackage(pkg, rep, doInstall);
            forceUpdateRepository := doInstall;
          END;
          
        | uninstallPackage:
          pkg := Package.GetPkgInfo(CCompiler.oocdir.value(CfgData.StringVar).string, arg, errList);
          IF (errList.msgCount # 0) THEN
            errList.Write(StdChannels.stdout);
          END;
          IF (pkg = NIL) THEN
            Err.String ("Error: Cannot locate package ");
            Err.Object (arg);
            Err.Ln;
            HALT (1)
          ELSE
            UninstallPackage(pkg);
            forceUpdateRepository := TRUE;
          END;


        | getOption:
          option := Config.options.Get(arg);
          IF (option = NIL) THEN
            Out.String("(none)");
          ELSE
            Out.Object(option.value(CfgData.StringVar).string);
          END;
          Out.Ln;
          
        | buildPackageDoc:
          pkg := Package.GetPackage(arg, rep);
          IF (pkg = NIL) THEN
            Err.String ("Error: Cannot locate package ");
            Err.Object (arg);
            Err.Ln;
            HALT (1)
          ELSE
            ok := BuildPackageDoc(pkg);
          END;
          
        | packageInstalled:
          r := Package.GetRepository(CCompiler.oocdir.value(CfgData.StringVar).string, errList);
          errList.Write(StdChannels.stderr);
          IF r.PackageInstalled(arg) THEN
            HALT(0);
          ELSE
            HALT(1);
          END;

        ELSE
          module := GetModule(arg);
          IF (mode = Rep.modCodeFileC) THEN
            makeRules.SetAllImportsModule(module);
          END;
          ok := makeRules.Update(module, mode);
          makeRules.SetAllImportsModule(NIL);
        END;
        INC(i);
      END;

      IF ok & forceUpdateRepository THEN
        ok := Package.UpdateRepository(CCompiler.oocdir.value(CfgData.StringVar).string);
      END;
    END;
    
    IF ok THEN
      IF Make.writeStats THEN
        Stats.Write();
      END;
    ELSE
      HALT (1)
    END
  END
END oo2c.
