(* 	$Id$	 *)
MODULE OOC:Config:CCompiler;
(*  Generates command lines for the C compiler and linker.
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
  Strings, Object, URI, URI:Scheme:File,
  CfgData := Config, Config:Section:Options, OOC:Config, OOC:Repository;

VAR
  cc, cppflags, cflags, ldflags, libs-, libtool, libdir-: Options.Option;
  install-, installProgram, installData-, uninstall-: Options.Option;
  bindir-, oocdir-: Options.Option;

PROCEDURE HaveLibtool*(): BOOLEAN;
  BEGIN
    RETURN ~libtool.value(CfgData.StringVar).string.Equals("no");
  END HaveLibtool;

PROCEDURE Append(str: STRING; VAR cmd: ARRAY OF CHAR);
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    str := str.ToString8("?");
    chars := str(Object.String8).CharsLatin1();
    Strings.Append(chars^, cmd);
  END Append;

PROCEDURE SetCommand(mode: ARRAY OF CHAR; VAR cmd: ARRAY OF CHAR);
  BEGIN
    IF (mode # "") & HaveLibtool() THEN
      COPY("", cmd);
      Append(libtool. value(CfgData.StringVar). string, cmd);
      Strings.Append (" --mode=", cmd);
      Strings.Append (mode, cmd);
      Strings.Append (" ", cmd);
    ELSE
      COPY("", cmd);
    END;
    Append (cc. value(CfgData.StringVar). string, cmd);
    Strings.Append (" ", cmd);
  END SetCommand;

PROCEDURE CompileFileCmd* (in, out: URI.URI; forLibrary: BOOLEAN;
                           VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 2*1024 OF CHAR;
    include: Object.StringArrayPtr;
    i: LONGINT;
    f: File.URI;
    chars: Object.CharsLatin1;
    
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
      SetCommand("compile", cmd);
    ELSE
      SetCommand("", cmd);
    END;
    Append (cflags. value(CfgData.StringVar). string, cmd);
    Strings.Append (" ", cmd);
    Append (cppflags. value(CfgData.StringVar). string, cmd);
    
    (* Add include path for the run-time header files.  In theory, this include
       directory should have the highest priority, but _only_ for run-time
       headers, not for everything else that might be located there.  Since
       currently no .h files except for the run-time data are installed in the
       src/ directory, putting this first should be safe.   *)
    f := GetURIofRT();
    f. GetPath (str);
    Strings.Append (" -I", cmd);
    Strings.Append (str, cmd);
    
    include := Config.repositories. GetIncludePaths();
    FOR i := 0 TO LEN (include^)-1 DO
      Strings.Append (" -I", cmd);
      chars := include[i](Object.String8).CharsLatin1();
      Strings.Append (chars^, cmd)
    END;
    
    Strings.Append (" -c ", cmd);
    in(File.URI). GetPath (str);
    Strings.Append (str, cmd);
    Strings.Append (" -o ", cmd);
    out(File.URI). GetPath (str);
    Strings.Append (str, cmd);
  END CompileFileCmd;

PROCEDURE LinkProgramCmd* (execFile: URI.URI; forLibrary: BOOLEAN;
                           VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    SetCommand("link", cmd);
    Strings.Append ("-o ", cmd);
    execFile(File.URI). GetPath (str);
    Strings.Append (str, cmd);
    IF forLibrary & HaveLibtool() THEN
      Strings.Append (" -rpath ", cmd);
      Append (libdir. value(CfgData.StringVar). string, cmd);
    END;
    Strings.Append (" ", cmd);
    Append (ldflags. value(CfgData.StringVar). string, cmd);
  END LinkProgramCmd;

PROCEDURE InstallDirectoryCmd*(path: ARRAY OF CHAR; VAR cmd: ARRAY OF CHAR);
  BEGIN
    COPY("", cmd);
    Append(install.value(CfgData.StringVar).string, cmd);
    Strings.Append(" -d ", cmd);
    Strings.Append(path, cmd);
  END InstallDirectoryCmd;

PROCEDURE InstallProgramCmd*(file: URI.URI; asLibrary: BOOLEAN;
                             VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    COPY("", cmd);
    IF HaveLibtool() THEN
      Append(libtool.value(CfgData.StringVar).string, cmd);
      Strings.Append(" --mode=install ", cmd);
    END;
    
    Append(installProgram.value(CfgData.StringVar).string, cmd);
    Strings.Append(" ", cmd);
    file(File.URI).GetPath(str);
    Strings.Append(str, cmd);
    Strings.Append(" ", cmd);
    IF asLibrary THEN
      Append (libdir.value(CfgData.StringVar).string, cmd);
    ELSE
      Append (bindir.value(CfgData.StringVar).string, cmd);
    END;
  END InstallProgramCmd;

PROCEDURE UninstallProgramCmd*(path: STRING; asLibrary: BOOLEAN;
                               VAR cmd: ARRAY OF CHAR);
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    COPY("", cmd);
    IF HaveLibtool() THEN
      Append(libtool.value(CfgData.StringVar).string, cmd);
      Strings.Append(" --mode=uninstall ", cmd);
    END;
    
    Append(uninstall.value(CfgData.StringVar).string, cmd);
    Strings.Append(" ", cmd);
    chars := path(Object.String8).CharsLatin1();
    Strings.Append(chars^, cmd);
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
