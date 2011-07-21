(* 	$Id: FileSystem.Mod,v 1.28 2003/06/05 22:09:31 mva Exp $	 *)
MODULE OOC:Repository:FileSystem;
(*  Implementation of a repository in the local file system.
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
  Msg, Files, TextRider, Time, OSFiles := OS:Files, OS:Path,
  Object, Exception, ADT:StringBuffer, IO, URI, URIParser := URI:Parser, 
  FileURI := URI:Scheme:File,
  OOC:Logger, OOC:Error, OOC:Scanner:InputBuffer, Rep := OOC:Repository;


TYPE
  Repository* = POINTER TO RepositoryDesc;
  RepositoryDesc = RECORD
    (Rep.RepositoryDesc)
    relativeBaseURI-: URI.HierarchicalURI;
  END;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc = RECORD
    (Rep.ModuleDesc)
  END;

VAR
  baseURI-: URI.HierarchicalURI;
  (**Using this URI, any relative file names are expanded into absolule
     file URIs.  *)


PROCEDURE New* (baseRep: Rep.Repository; baseDir: URI.HierarchicalURI): Repository;
  VAR
    rep: Repository;
    relative: URI.URI;
  BEGIN
    NEW (rep);
    Rep.Init (rep, baseRep, baseDir);
    relative := baseDir.MakeRelative(FileURI.GetCwd());
    IF (relative.schemeId = NIL) &
       (relative IS FileURI.URI) &
       (relative(FileURI.URI). pathList # NIL) &
       ~relative(FileURI.URI). pathList. string.Equals("..") THEN
      rep.relativeBaseURI := relative(FileURI.URI);
    ELSE
      rep.relativeBaseURI := baseDir;
    END;
    RETURN rep
  END New;

PROCEDURE InitModule (m: Module; origin: Repository;
                      name: Rep.ModuleName;
                      srcFileOverride: URI.HierarchicalURI);
  BEGIN
    Rep.InitModule (m, origin, name, srcFileOverride)
  END InitModule;

PROCEDURE NewModule (origin: Repository; name: Rep.ModuleName;
                     srcFileOverride: URI.HierarchicalURI): Module;
  VAR
    m: Module;
  BEGIN
    NEW (m);
    InitModule (m, origin, name, srcFileOverride);
    RETURN m
  END NewModule;


PROCEDURE ModuleToFileName*(name: ARRAY OF CHAR): Object.String8;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (name[i] # 0X) DO
      IF (name[i] = ":") THEN
        name[i] := "/"
      END;
      INC (i)
    END;
    RETURN Object.NewLatin1(name);
  END ModuleToFileName;

PROCEDURE (rep: Repository) GetModule* (moduleName: ARRAY OF CHAR; 
                                 srcFileOverride: URI.HierarchicalURI): Module;
(* result is NIL in case of error *)
  VAR
    uri: URI.URI;
  
  PROCEDURE GetURI (fileId: Rep.FileId): URI.URI
  RAISES Exception.ParseError;
    VAR
      string: STRING;
      sb: StringBuffer.StringBuffer;
    BEGIN
      (* assemble file name from base URI, module name, and module suffix *)
      sb := StringBuffer.New(rep.GetDefaultSubdir(fileId));
      IF (sb.CharAt(sb.length-1) # "/") THEN
        sb.Append("/");
      END;
      sb.Append(ModuleToFileName(moduleName));
      sb.Append(rep.GetDefaultSuffix(fileId));

      string := sb.ToString();
      RETURN URIParser.NewURI(string(Object.String8), rep.baseURI);
    END GetURI;
  
  BEGIN
    TRY
      uri := GetURI (Rep.modModuleSource);
    CATCH Exception.ParseError:
      RETURN NIL;
    END;
    
    IF (srcFileOverride # NIL) THEN
      RETURN NewModule (rep, moduleName, srcFileOverride)
    ELSE
      (* check if the module's source code is located in this repository *)
      ;
      IF OSFiles.Exists (uri(FileURI.URI).GetPath()) THEN
        RETURN NewModule (rep, moduleName, srcFileOverride)
      ELSE
        (* cannot find source code, try to find symbol file *)
        TRY
          uri := GetURI(Rep.modSymbolFile);
        CATCH Exception.ParseError:
          RETURN NIL;
        END;
        
        IF OSFiles.Exists(uri(FileURI.URI).GetPath()) THEN
          RETURN NewModule (rep, moduleName, srcFileOverride)
        ELSE
          (* cannot find source code OR symbol file *)
          RETURN NIL
        END
      END
    END
  END GetModule;

PROCEDURE (rep: Repository) GetResource* (package, path: ARRAY OF CHAR): URI.URI;
  VAR
    sb: StringBuffer.StringBuffer;
    string: STRING;
    uri: URI.URI;
  BEGIN
    IF (package = "") THEN
      string := Object.NewLatin1(path);
    ELSE
      (* assemble file name from base URI, module name, and module suffix *)
      sb := StringBuffer.New(rep.GetDefaultSubdir(Rep.resourceFile));
      IF (sb.length # 0) & (sb.CharAt(sb.length-1) # "/") THEN
        sb.Append("/");
      END;
      sb.AppendLatin1(package);
      sb.Append("/");
      sb.AppendLatin1(path);
      string := sb.ToString();
    END;

    (* can't use relative URI here, or the installation tarball of oo2c breaks
       when it tries to create a relative URI for it  *)
    TRY
      uri := URIParser.NewURI (string(Object.String8), rep. baseURI);
    CATCH Exception.ParseError:
      RETURN NIL;
    END;
    
    IF OSFiles.Exists(uri(FileURI.URI).GetPath()) THEN
      RETURN uri
    ELSE
      RETURN NIL
    END
  END GetResource;
  
PROCEDURE (rep: Repository) DumpContent* (w: TextRider.Writer);
  BEGIN
    w. WriteString ("  <file-system>");
    w. WriteObject (rep.baseURI.ToString());
    w. WriteString ("</file-system>");
    w. WriteLn
  END DumpContent;

PROCEDURE (rep: Repository) GetLocalPath*(m: Rep.Module; fileId: Rep.FileId): Object.String8;
  VAR
    sb: StringBuffer.StringBuffer;
    string: STRING;
  BEGIN
    sb := StringBuffer.New(rep.GetDefaultSubdir(fileId));
    IF (sb.length # 0) & (sb.CharAt(sb.length-1) # "/") THEN
      sb.Append("/");
    END;
    
    IF (fileId = Rep.modLibrary) THEN
      ASSERT(m.ifQuality = Rep.completeInterface);
      sb.Append("lib");
      sb.Append(m.ifData.libraryName);
    ELSE
      sb.Append(ModuleToFileName(m.name^));
    END;
    sb.Append(rep.GetDefaultSuffix(fileId));

    string := sb.ToString();
    RETURN string(Object.String8);
  END GetLocalPath;

PROCEDURE (m: Module) GetURI* (fileId: Rep.FileId;
                               allowRelative: BOOLEAN): URI.HierarchicalURI;
  VAR
    path: Object.String8;
    uri: URI.URI;
    huri: URI.HierarchicalURI;
  BEGIN
    huri := m. GetURI^ (fileId, allowRelative);
    IF (huri = NIL) THEN
      IF (fileId = Rep.modModuleSource) & (m. srcFileOverride # NIL) THEN
        RETURN m. srcFileOverride
      ELSE
        path := m.origin.GetLocalPath(m, fileId);
        TRY
          IF allowRelative THEN
            uri := URIParser.NewURI(path, m.origin(Repository).relativeBaseURI);
          ELSE
            uri := URIParser.NewURI(path, m.origin.baseURI);
          END;
        CATCH Exception.ParseError:
          (* this should never trigger if subdir and suffix are ok *)
          ASSERT (FALSE);
        END;
        RETURN uri(URI.HierarchicalURI)
      END
    ELSE
      RETURN huri;
    END;
  END GetURI;

PROCEDURE (m: Module) GetTimeStamp* (fileId: Rep.FileId; VAR ts: Time.TimeStamp);
  VAR
    uri: URI.URI;
    path: STRING;
    chars: Object.CharsLatin1;
    res: Msg.Msg;
  BEGIN
    uri := m. GetURI (fileId, FALSE);
    path := uri(FileURI.URI).GetPath();
    chars := Path.Encode(path);
    Files.GetModTime(chars^, ts, res);
    IF (res # NIL) THEN
      Time.InitTimeStamp (ts, MAX (LONGINT), 0)
    END
  END GetTimeStamp;

PROCEDURE (m: Module) FileExists* (fileId: Rep.FileId): BOOLEAN;
  VAR
    uri: URI.URI;
  BEGIN
    uri := m.GetURI(fileId, FALSE);
    RETURN OSFiles.Exists(uri(FileURI.URI).GetPath());
  END FileExists;

PROCEDURE (m: Module) GetInputBuffer* (): InputBuffer.Buffer
RAISES IO.Error;
  VAR
    file: IO.ByteChannel;
    errList: Error.List;
    str: STRING;
    modURI: URI.URI;
  BEGIN
    (* create new error list for the source file *)
    modURI := m. GetURI (Rep.modModuleSource, TRUE);
    IF (modURI IS FileURI.URI) THEN
      str := modURI(FileURI.URI).GetPath();
    ELSE
      str := modURI.ToString();
    END;
    errList := Error.NewList(str);
    
    (* open file for reading *)
    file := modURI. GetChannel (URI.channelOld);
    Logger.ReadFile(modURI);
    RETURN InputBuffer.New (file, errList);
  END GetInputBuffer;

PROCEDURE (m: Module) CreateOutputDir* (fileId: Rep.FileId)
RAISES IO.Error;
  VAR
    uri: URI.URI;
  BEGIN
    uri := m. GetURI (fileId, TRUE);
    OSFiles.MakeDirs(Path.DirName(uri(FileURI.URI).GetPath()),
                     OSFiles.defaultMode);
  END CreateOutputDir;

PROCEDURE (m: Module) GetOutputChannel* (fileId: Rep.FileId;
                                         makeTmp: BOOLEAN): IO.ByteChannel
RAISES IO.Error;
  VAR
    uri: URI.URI;
  BEGIN
    m. CreateOutputDir (fileId);
    uri := m. GetURI (fileId, TRUE);
    Logger.WriteFile(uri);
    IF makeTmp THEN
      RETURN uri. GetChannel (URI.channelTmp)
    ELSE
      RETURN uri. GetChannel (URI.channelNew)
    END
  END GetOutputChannel;

BEGIN
  baseURI := FileURI.GetCwd()
END OOC:Repository:FileSystem.
