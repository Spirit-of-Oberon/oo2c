(* 	$Id: CCompiler.Mod,v 1.35 2004/04/04 07:35:45 mva Exp $	 *)
MODULE OOC:Config:CCompiler;
(*  Generates command lines for the C compiler and linker.
    Copyright (C) 2001, 2002, 2003, 2004  Michael van Acken

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
  Object, ADT:StringBuffer, URI, URI:Scheme:File,
  CfgData := Config, Config:Section:Options,
  OOC:Logger, OOC:Config, OOC:Package, OOC:Repository;

VAR
  cc, cppflags, cflags, ldflags, libs-, libtool, libdir-: Options.Option;
  install-, installProgram, installData-, uninstall-: Options.Option;
  bindir-, oocdir-: Options.Option;

PROCEDURE HaveLibtool*(): BOOLEAN;
  BEGIN
    RETURN ~libtool.value(CfgData.StringVar).string.Equals("no");
  END HaveLibtool;

PROCEDURE SkipCallCC*(): BOOLEAN;
(**Return @code{TRUE} if this ``make'' run should skip all calls to the
   external C compiler.  *)
  BEGIN
    RETURN (cc.value(CfgData.StringVar).string.length = 0);
  END SkipCallCC;

PROCEDURE SetCommand(mode: STRING): StringBuffer.StringBuffer;
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := StringBuffer.New("");
    IF (mode.length # 0) & HaveLibtool() THEN
      sb.Append(libtool.value);
      sb.Append(" --mode=");
      sb.Append(mode);
      sb.Append(" ");
      IF Logger.silence THEN
        sb.Append("--quiet ");
      END;
    END;
    sb.Append(cc.value);
    sb.Append(" ");
    RETURN sb;
  END SetCommand;

PROCEDURE CompileFileCmd* (in, out: URI.URI; forLibrary: BOOLEAN): STRING;
  VAR
    sb: StringBuffer.StringBuffer;
    include: Object.StringArrayPtr;
    i: LONGINT;
    f: File.URI;
    
  PROCEDURE GetURIofRT(): File.URI;
    VAR
      m: Repository.Module;
      uri: URI.HierarchicalURI;
      f: File.URI;
    BEGIN
      m := Config.repositories. GetModule (Config.runtimeModule);
      ASSERT (m # NIL);  (* ... if this fails, then we have no __oo2c.h *)
      uri := m. GetURI (Repository.modModuleSource, TRUE);
      f := uri(File.URI);
      f. StripSegments (1);
      RETURN f;
    END GetURIofRT;
  
  BEGIN
    IF forLibrary THEN
      sb := SetCommand("compile");
    ELSE
      sb := SetCommand("");
    END;
    sb.Append(cflags.value);
    sb.Append(" ");
    sb.Append(cppflags.value);
    
    (* Add include path for the run-time header files.  In theory, this include
       directory should have the highest priority, but _only_ for run-time
       headers, not for everything else that might be located there.  Since
       currently no .h files except for the run-time data are installed in the
       src/ directory, putting this first should be safe.   *)
    f := GetURIofRT();
    sb.Append(" -I");
    sb.Append(f.GetPath());
    
    include := Config.repositories. GetIncludePaths();
    FOR i := 0 TO LEN (include^)-1 DO
      sb.Append(" -I");
      sb.Append(include[i]);
    END;
    
    sb.Append(" -c ");
    sb.Append(in(File.URI).GetPath());
    sb.Append(" -o ");
    sb.Append(out(File.URI).GetPath());
    RETURN sb.ToString();
  END CompileFileCmd;

PROCEDURE LinkProgramCmd* (execFile: URI.URI;
                           forLibrary: Package.Library): STRING;
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := SetCommand("link");
    sb.Append("-o ");
    sb.Append(execFile(File.URI).GetPath());
    IF (forLibrary # NIL) & HaveLibtool() THEN
      sb.Append(" -version-info ");
      sb.AppendLatin1(forLibrary.version.tuple);
      sb.Append(" -rpath ");
      sb.Append(libdir.value);
    END;
    sb.Append(" ");
    sb.Append(ldflags.value);
    RETURN sb.ToString();
  END LinkProgramCmd;

PROCEDURE InstallDirectoryCmd*(path: STRING): STRING;
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := StringBuffer.New(install.value.ToString());
    sb.Append(" -d ");
    sb.Append(path);
    RETURN sb.ToString();
  END InstallDirectoryCmd;

PROCEDURE InstallProgramCmd*(file: URI.URI; asLibrary: BOOLEAN): STRING;
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := StringBuffer.New("");
    IF HaveLibtool() THEN
      sb.Append(libtool.value);
      sb.Append(" --mode=install ");
    END;
    
    sb.Append(installProgram.value);
    sb.Append(" ");
    sb.Append(file(File.URI).GetPath());
    sb.Append(" ");
    IF asLibrary THEN
      sb.Append(libdir.value);
    ELSE
      sb.Append(bindir.value);
    END;
    RETURN sb.ToString();
  END InstallProgramCmd;

PROCEDURE UninstallProgramCmd*(path: STRING; asLibrary: BOOLEAN): STRING;
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := StringBuffer.New("");
    IF HaveLibtool() THEN
      sb.Append(libtool.value);
      sb.Append(" --mode=uninstall ");
    END;
    
    sb.Append(uninstall.value);
    sb.Append(" ");
    sb.Append(path);
    RETURN sb.ToString();
  END UninstallProgramCmd;

PROCEDURE RegisterConfig*;
  BEGIN
    cc := Config.AddOption ("cc", CfgData.NewStringVar("gcc"));
    cppflags := Config.AddOption ("cppflags", CfgData.NewStringVar(""));
    cflags := Config.AddOption ("cflags", CfgData.NewStringVar("-O2 -g"));
    ldflags := Config.AddOption ("ldflags", CfgData.NewStringVar(""));
    libs := Config.AddOption ("libs", CfgData.NewStringVar("-lgc"));
    Config.AddCmdLine ("--cc",
                       "<options><set name='cc'>$1</set></options>");
    Config.AddCmdLine ("--cppflags",
                       "<options><set name='cppflags'>$1</set></options>");
    Config.AddCmdLine ("--cflags",
                       "<options><set name='cflags'>$1</set></options>");
    Config.AddCmdLine ("--ldflags",
                       "<options><set name='ldflags'>$1</set></options>");
    Config.AddCmdLine ("--libs",
                       "<options><set name='libs'>$1</set></options>");
    
    libtool := Config.AddOption ("libtool", CfgData.NewStringVar("libtool"));
    libdir := Config.AddOption ("libdir", CfgData.NewStringVar("libdir"));
    Config.AddCmdLine ("--libtool",
                       "<options><set name='libtool'>$1</set></options>");
    Config.AddCmdLine ("--libdir",
                       "<options><set name='libdir'>$1</set></options>");

    install := Config.AddOption ("install", CfgData.NewStringVar("install -c"));
    installProgram := Config.AddOption ("installProgram",
                                        CfgData.NewStringVar("install -c"));
    installData := Config.AddOption ("installData",
                                     CfgData.NewStringVar("install -c -m 644"));
    uninstall := Config.AddOption ("uninstall",
                                   CfgData.NewStringVar("rm -f"));
    bindir := Config.AddOption ("bindir", CfgData.NewStringVar("bindir"));
    oocdir := Config.AddOption ("oocdir", CfgData.NewStringVar("oocdir"));
    Config.AddCmdLine ("--install",
                       "<options><set name='install'>$1</set></options>");
    Config.AddCmdLine ("--install-program",
                       "<options><set name='installProgram'>$1</set></options>");
    Config.AddCmdLine ("--install-data",
                       "<options><set name='installData'>$1</set></options>");
    Config.AddCmdLine ("--uninstall",
                       "<options><set name='uninstall'>$1</set></options>");
    Config.AddCmdLine ("--bindir",
                       "<options><set name='bindir'>$1</set></options>");
    Config.AddCmdLine ("--oocdir",
                       "<options><set name='oocdir'>$1</set></options>");
  END RegisterConfig;

END OOC:Config:CCompiler.
