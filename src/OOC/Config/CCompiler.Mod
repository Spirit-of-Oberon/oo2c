(* 	$Id$	 *)
MODULE OOC:Config:CCompiler;
(*  Generates command lines for the C compiler and linker.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Strings, ADT:String, URI, URI:Scheme:File,
  Config:Section:Options, StringValue := Config:Value:String,
  OOC:Config, OOC:Repository;

VAR
  cc, cppflags, cflags, ldflags, libs-, libtool, libdir-: Options.Option;
  install-, installProgram, installData-, uninstall-: Options.Option;
  bindir-, oocdir-: Options.Option;

PROCEDURE HaveLibtool*(): BOOLEAN;
  BEGIN
    RETURN (libtool.value(StringValue.Value).string^ # "no");
  END HaveLibtool;

PROCEDURE SetCommand(mode: ARRAY OF CHAR; VAR cmd: ARRAY OF CHAR);
  BEGIN
    IF (mode # "") & HaveLibtool() THEN
      COPY (libtool. value(StringValue.Value). string^, cmd);
      Strings.Append (" --mode=", cmd);
      Strings.Append (mode, cmd);
      Strings.Append (" ", cmd);
    ELSE
      COPY("", cmd);
    END;
    Strings.Append (cc. value(StringValue.Value). string^, cmd);
    Strings.Append (" ", cmd);
  END SetCommand;

PROCEDURE CompileFileCmd* (in, out: URI.URI; forLibrary: BOOLEAN;
                           VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 2*1024 OF CHAR;
    include: String.StringArrayPtr;
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
      SetCommand("compile", cmd);
    ELSE
      SetCommand("", cmd);
    END;
    Strings.Append (cflags. value(StringValue.Value). string^, cmd);
    Strings.Append (" ", cmd);
    Strings.Append (cppflags. value(StringValue.Value). string^, cmd);
    
    include := Config.repositories. GetIncludePaths();
    FOR i := 0 TO LEN (include^)-1 DO
      Strings.Append (" -I", cmd);
      Strings.Append (include[i]. array^, cmd)
    END;
    
    (* add include path for the run-time header files; in theory, this include
       directory should have the highest priority, but _only_ for run-time
       headers, not for everything else that might be located there; for this
       reason, this particular include might be better searched last *)
    f := GetURIofRT();
    f. GetPath (str);
    Strings.Append (" -I", cmd);
    Strings.Append (str, cmd);
    
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
      Strings.Append (libdir. value(StringValue.Value). string^, cmd);
    END;
    Strings.Append (" ", cmd);
    Strings.Append (ldflags. value(StringValue.Value). string^, cmd);
  END LinkProgramCmd;

PROCEDURE InstallDirectoryCmd*(path: ARRAY OF CHAR; VAR cmd: ARRAY OF CHAR);
  BEGIN
    COPY(install.value(StringValue.Value).string^, cmd);
    Strings.Append(" -d ", cmd);
    Strings.Append(path, cmd);
  END InstallDirectoryCmd;

PROCEDURE InstallProgramCmd*(file: URI.URI; asLibrary: BOOLEAN;
                             VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    IF HaveLibtool() THEN
      COPY (libtool.value(StringValue.Value).string^, cmd);
      Strings.Append(" --mode=install ", cmd);
    ELSE
      COPY("", cmd);
    END;
    
    Strings.Append(installProgram.value(StringValue.Value).string^, cmd);
    Strings.Append(" ", cmd);
    file(File.URI).GetPath(str);
    Strings.Append(str, cmd);
    Strings.Append(" ", cmd);
    IF asLibrary THEN
      Strings.Append (libdir.value(StringValue.Value).string^, cmd);
    ELSE
      Strings.Append (bindir.value(StringValue.Value).string^, cmd);
    END;
  END InstallProgramCmd;

PROCEDURE UninstallProgramCmd*(path: ARRAY OF CHAR; asLibrary: BOOLEAN;
                               VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    IF HaveLibtool() THEN
      COPY (libtool.value(StringValue.Value).string^, cmd);
      Strings.Append(" --mode=uninstall ", cmd);
    ELSE
      COPY("", cmd);
    END;
    
    Strings.Append(uninstall.value(StringValue.Value).string^, cmd);
    Strings.Append(" ", cmd);
    Strings.Append(path, cmd);
  END UninstallProgramCmd;

PROCEDURE RegisterConfig*;
  BEGIN
    cc := Config.AddOption ("cc", StringValue.New ("gcc"));
    cppflags := Config.AddOption ("cppflags", StringValue.New (""));
    cflags := Config.AddOption ("cflags", StringValue.New ("-O2 -g"));
    ldflags := Config.AddOption ("ldflags", StringValue.New (""));
    libs := Config.AddOption ("libs", StringValue.New ("-lgc"));
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
    
    libtool := Config.AddOption ("libtool", StringValue.New ("libtool"));
    libdir := Config.AddOption ("libdir", StringValue.New ("libdir"));
    Config.AddCmdLine ("--libtool",
                       "<options><set name='libtool'>$1</set></options>");
    Config.AddCmdLine ("--libdir",
                       "<options><set name='libdir'>$1</set></options>");

    install := Config.AddOption ("install", StringValue.New ("install -c"));
    installProgram := Config.AddOption ("installProgram",
                                        StringValue.New ("install -c"));
    installData := Config.AddOption ("installData",
                                     StringValue.New ("install -c -m 644"));
    uninstall := Config.AddOption ("uninstall",
                                   StringValue.New ("rm -f"));
    bindir := Config.AddOption ("bindir", StringValue.New ("bindir"));
    oocdir := Config.AddOption ("oocdir", StringValue.New ("oocdir"));
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
