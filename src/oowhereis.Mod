MODULE oowhereis;
(*  File finder.
    Copyright (C) 1996-1999, 2002  Michael van Acken

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
  Out, StdChannels, Strings, URI, URI:Scheme:File,
  Config:Section:Arguments, Config:Section:Options, Config:Value:Boolean,
  OOC:Config, OOC:Config:CCompiler, E := OOC:Error, OOC:Repository;


CONST
  moduleSeparator = ":";
  dirSeparator = "/";
  moduleExtension = ".Mod";
  symbolFileExtension = ".Sym";
  
VAR
  cfgErrList: E.List;
  help: Options.Option;

PROCEDURE WriteHelp;
  BEGIN
    Out.String ("Usage: oowhereis [options] <file>"); Out.Ln;
    Out.String ("Options:"); Out.Ln;
    Out.String ("--config <file>           Use <file> as primary configuration file."); Out.Ln;
    Out.String ("--repository <directory>  Add repository."); Out.Ln;
    Out.String ("-r <directory>            Add repository."); Out.Ln;
    Out.String ("--help, -h                Write this text and exit."); Out.Ln;
  END WriteHelp;


PROCEDURE GetExt(path: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := Strings.Length(path);
    WHILE (i # 0) & (path[i-1] # ".") & (path[i-1] # dirSeparator) DO
      DEC(i);
    END;
    IF (i = 0) THEN
      RETURN -1;
    ELSIF (path[i-1] = ".") THEN
      RETURN i-1;
    ELSE
      RETURN -1;
    END;
  END GetExt;

PROCEDURE Query(): BOOLEAN;
  VAR
    arg: Arguments.Argument;
    file, ext: Repository.URIBuffer;
    pos, extPos: INTEGER;
    fileId: Repository.FileId;
    m: Repository.Module;
    uri: URI.URI;
  BEGIN
    arg := Config.arguments.Get(0);

    extPos := GetExt(arg^);
    IF (extPos >= 0) THEN
      Strings.Extract(arg^, extPos, MAX(INTEGER), ext);
    ELSE
      extPos := Strings.Length(arg^);
      ext := moduleExtension;
    END;

    IF (ext = symbolFileExtension) THEN
      fileId := Repository.modSymbolFile;
    ELSE
      fileId := Repository.modModuleSource;
    END;

    arg[extPos] := 0X;
    pos := 0;
    WHILE (arg[pos] # 0X) DO
      IF (arg[pos] = dirSeparator) THEN
        arg[pos] := moduleSeparator;
      END;
      INC (pos);
    END;
    
    m := Config.repositories.GetModule(arg^);
    IF (m # NIL) THEN
      uri := m.GetURI(fileId, TRUE);
      uri(File.URI).GetPath(file);
      Out.String (file);
      Out.Ln;
      RETURN TRUE
    ELSE
      Out.String ("Error: Can't find module ");
      Out.String (arg^);
      Out.Ln;
      RETURN FALSE
    END;
  END Query;

PROCEDURE NewConfig;
  BEGIN
    Config.AddCmdLine("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    
    help := Config.AddOption("help", Boolean.New(FALSE));
    Config.AddCmdLine("-h,--help",
                      "<options><set name='help'>TRUE</set></options>");
    
    CCompiler.RegisterConfig;  (* make oo2c options known *)
  END NewConfig;

BEGIN
  cfgErrList := E.NewList("");
  NewConfig;
  Config.Read(cfgErrList);
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stdout);
  END;
  IF ~cfgErrList.NoErrors() THEN
    HALT (1)
  ELSIF (Config.arguments.ArgNumber() # 1) OR
        help.value(Boolean.Value).boolean THEN
    WriteHelp
  ELSE
    IF Query() THEN
      HALT (0)
    ELSE
      HALT (1)
    END
  END
END oowhereis.
