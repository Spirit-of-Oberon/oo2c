(* 	$Id$	 *)
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
  Msg, Files, TextRider, Strings, Time, OSFiles := OS:Files, OS:Path,
  Object, Exception, IO, URI, URIParser := URI:Parser, 
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


PROCEDURE ModuleToFileName (VAR name: ARRAY OF CHAR);
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (name[i] # 0X) DO
      IF (name[i] = ":") THEN
        name[i] := "/"
      END;
      INC (i)
    END
  END ModuleToFileName;

PROCEDURE (rep: Repository) GetModule* (moduleName: ARRAY OF CHAR; 
                                 srcFileOverride: URI.HierarchicalURI): Module;
(* result is NIL in case of error *)
  VAR
    uri: URI.URI;
  
  PROCEDURE GetURI (fileId: Rep.FileId): URI.URI
  RAISES Exception.ParseError;
    VAR
      path, str: Rep.URIBuffer;
    BEGIN
      (* assemble file name from base URI, module name, and module suffix *)
      rep. GetDefaultSubdir (fileId, path);
      IF (path # "") & (path[Strings.Length (path)-1] # "/") THEN
        Strings.Append ("/", path)
      END;
      COPY (moduleName, str);
      ModuleToFileName (str);
      Strings.Append (str, path);
      rep. GetDefaultSuffix (fileId, str);
      Strings.Append (str, path);
      RETURN URIParser.NewURI (path, rep. baseURI);
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
    p: Rep.URIBuffer;
    uri: URI.URI;
  BEGIN
    IF (package = "") THEN
      COPY(path, p);
    ELSE
      (* assemble file name from base URI, module name, and module suffix *)
      rep. GetDefaultSubdir (Rep.resourceFile, p);
      IF (p # "") & (p[Strings.Length (p)-1] # "/") THEN
        Strings.Append ("/", p)
      END;
      Strings.Append (package, p);
      Strings.Append ("/", p);
      Strings.Append (path, p);
    END;

    (* can't use relative URI here, or the installation tarball of oo2c breaks
       when it tries to create a relative URI for it  *)
    TRY
      uri := URIParser.NewURI (p, rep. baseURI);
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

PROCEDURE (rep: Repository) GetLocalPath*(m: Rep.Module; fileId: Rep.FileId;
                                          VAR path: ARRAY OF CHAR);
  VAR
    subdir, suffix, str: Rep.URIBuffer;
    chars: Object.CharsLatin1;
  BEGIN
    rep. GetDefaultSubdir (fileId, subdir);
    rep. GetDefaultSuffix (fileId, suffix);
    
    COPY (subdir, path);
    IF (path # "") & (path[Strings.Length (path)-1] # "/") THEN
      Strings.Append ("/", path)
    END;
    COPY (m. name^, str);
    ModuleToFileName (str);
    
    IF (fileId = Rep.modLibrary) THEN
      ASSERT(m.ifQuality = Rep.completeInterface);
      Strings.Append("lib", path);
      chars := m.ifData.libraryName(Object.String8).CharsLatin1();
      COPY(chars^, str);
    ELSE
      ModuleToFileName (str);
    END;
    
    Strings.Append (str, path);
    Strings.Append (suffix, path);
  END GetLocalPath;

PROCEDURE (m: Module) GetURI* (fileId: Rep.FileId;
                               allowRelative: BOOLEAN): URI.HierarchicalURI;
  VAR
    path: Rep.URIBuffer;
    uri: URI.URI;
    huri: URI.HierarchicalURI;
  BEGIN
    huri := m. GetURI^ (fileId, allowRelative);
    IF (huri = NIL) THEN
      IF (fileId = Rep.modModuleSource) & (m. srcFileOverride # NIL) THEN
        RETURN m. srcFileOverride
      ELSE
        m.origin.GetLocalPath(m, fileId, path);
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
