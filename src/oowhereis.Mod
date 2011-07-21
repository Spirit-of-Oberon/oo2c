MODULE oowhereis;
(*  File finder.
    Copyright (C) 1996-1999, 2002, 2004  Michael van Acken

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
  Out, Object, ADT:StringBuffer, IO:StdChannels, URI, URI:Scheme:File,
  CfgData := Config, Config:Section:Options,
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


PROCEDURE GetExt(path: STRING): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := path.length;
    WHILE (i # 0) &
          (path.CharAt(i-1) # ".") &
          (path.CharAt(i-1) # dirSeparator) DO
      DEC(i);
    END;
    IF (i = 0) THEN
      RETURN -1;
    ELSIF (path.CharAt(i-1) = ".") THEN
      RETURN i-1;
    ELSE
      RETURN -1;
    END;
  END GetExt;

PROCEDURE Query(): BOOLEAN;
  VAR
    arg, ext: STRING;
    module: StringBuffer.StringBuffer;
    pos, extPos: LONGINT;
    fileId: Repository.FileId;
    m: Repository.Module;
    uri: URI.URI;
    chars: Object.CharsLatin1;
    str: Object.String8;
  BEGIN
    arg := Config.arguments.Get(0);

    extPos := GetExt(arg);
    IF (extPos >= 0) THEN
      ext := arg.Substring(extPos, arg.length);
    ELSE
      extPos := arg.length;
      ext := moduleExtension;
    END;

    IF (ext = symbolFileExtension) THEN
      fileId := Repository.modSymbolFile;
    ELSE
      fileId := Repository.modModuleSource;
    END;

    arg := arg.Substring(0, extPos);
    module := StringBuffer.New("");
    pos := 0;
    WHILE (pos # arg.length) DO
      IF (arg.CharAt(pos) = dirSeparator) THEN
        module.Append(moduleSeparator);
      ELSE
        module.AppendChar(arg.CharAt(pos));
      END;
      INC (pos);
    END;
    arg := module.ToString();
    
    str := arg.ToString8("?");
    chars := str.CharsLatin1();
    m := Config.repositories.GetModule(chars^);
    IF (m # NIL) THEN
      uri := m.GetURI(fileId, TRUE);
      Out.Object (uri(File.URI).GetPath());
      Out.Ln;
      RETURN TRUE
    ELSE
      Out.String ("Error: Can't find module ");
      Out.Object (arg);
      Out.Ln;
      RETURN FALSE
    END;
  END Query;

PROCEDURE NewConfig;
  BEGIN
    Config.AddRepositoryListEnv();
    Config.AddCmdLine("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    
    help := Config.AddOption("help", CfgData.NewBooleanVar(FALSE));
    Config.AddCmdLine("-h,--help",
                      "<options><set name='help'>TRUE</set></options>");
    
    CCompiler.RegisterConfig;  (* make oo2c options known *)
  END NewConfig;

BEGIN
  cfgErrList := E.NewList("");
  NewConfig;
  Config.Read(cfgErrList);
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
  END;
  IF ~cfgErrList.NoErrors() THEN
    HALT (1)
  ELSIF (Config.arguments.ArgNumber() # 1) OR
        help.value(CfgData.BooleanVar).boolean THEN
    WriteHelp
  ELSE
    IF Query() THEN
      HALT (0)
    ELSE
      HALT (1)
    END
  END
END oowhereis.
