(* 	$Id$	 *)
MODULE OOC:Repository:FileSystem;
(*  Implementation of a repository in the local file system.
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
  Msg, Channel, Files, TextRider, Strings, Time, OSFiles := OS:Files, OS:Path,
  URI, URIParser := URI:Parser, URIError := URI:Error,
  FileURI := URI:Scheme:File,
  OOC:Logger, OOC:Error, OOC:Scanner:InputBuffer, Rep := OOC:Repository;


TYPE
  Repository* = POINTER TO RepositoryDesc;
  RepositoryDesc = RECORD
    (Rep.RepositoryDesc)
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
  BEGIN
    NEW (rep);
    Rep.Init (rep, baseRep, baseDir);
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
    str: Rep.URIBuffer;
    res: URIError.Msg;
    uri: URI.URI;
  
  PROCEDURE GetURI (fileId: Rep.FileId; VAR res: URIError.Msg): URI.URI;
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
      RETURN URIParser.NewURI (path, rep. baseURI, res);
    END GetURI;
  
  BEGIN
    uri := GetURI (Rep.modModuleSource, res);
    
    IF (res # NIL) THEN
      RETURN NIL
    ELSIF (srcFileOverride # NIL) THEN
      RETURN NewModule (rep, moduleName, srcFileOverride)
    ELSE
      (* check if the module's source code is located in this repository *)
      uri(FileURI.URI). GetPath (str);
      IF Files.Exists (str) THEN
        RETURN NewModule (rep, moduleName, srcFileOverride)
      ELSE
        (* cannot find source code, try to find symbol file *)
        uri := GetURI (Rep.modSymbolFile, res);
        IF (res # NIL) THEN
          RETURN NIL
        ELSE
          uri(FileURI.URI). GetPath (str);
          IF Files.Exists (str) THEN
            RETURN NewModule (rep, moduleName, srcFileOverride)
          ELSE
            (* cannot find source code OR symbol file *)
            RETURN NIL
          END
        END
      END
    END
  END GetModule;

PROCEDURE (rep: Repository) GetResource* (package, path: ARRAY OF CHAR): URI.URI;
  VAR
    p, str: Rep.URIBuffer;
    res: URIError.Msg;
    uri: URI.URI;
  BEGIN
    (* assemble file name from base URI, module name, and module suffix *)
    rep. GetDefaultSubdir (Rep.resourceFile, p);
    IF (p # "") & (p[Strings.Length (p)-1] # "/") THEN
      Strings.Append ("/", p)
    END;
    Strings.Append (package, p);
    Strings.Append ("/", p);
    Strings.Append (path, p);
    uri := URIParser.NewURI (p, rep. baseURI, res);
    
    IF (res # NIL) THEN
      RETURN NIL
    ELSE
      uri(FileURI.URI). GetPath (str);
      IF Files.Exists (str) THEN
        RETURN uri
      ELSE
        RETURN NIL
      END
    END
  END GetResource;
  
PROCEDURE (rep: Repository) DumpContent* (w: TextRider.Writer);
  VAR
    str: Rep.URIBuffer;
  BEGIN
    w. WriteString ("  <file-system>");
    rep. baseURI. GetString (str);
    w. WriteString (str);
    w. WriteString ("</file-system>");
    w. WriteLn
  END DumpContent;

PROCEDURE (m: Module) GetURI* (fileId: Rep.FileId): URI.HierarchicalURI;
  VAR
    subdir, suffix, path, str: Rep.URIBuffer;
    uri: URI.URI;
    huri: URI.HierarchicalURI;
    res: Msg.Msg;
  BEGIN
    huri := m. GetURI^ (fileId);
    IF (huri = NIL) THEN
      IF (fileId = Rep.modModuleSource) & (m. srcFileOverride # NIL) THEN
        RETURN m. srcFileOverride
      ELSE
        m. origin. GetDefaultSubdir (fileId, subdir);
        m. origin. GetDefaultSuffix (fileId, suffix);
        
        COPY (subdir, path);
        IF (path # "") & (path[Strings.Length (path)-1] # "/") THEN
          Strings.Append ("/", path)
        END;
        COPY (m. name^, str);
        ModuleToFileName (str);
        Strings.Append (str, path);
        Strings.Append (suffix, path);
        uri := URIParser.NewURI (path, m. origin. baseURI, res);
        
        ASSERT (res = NIL);
        (* this should never trigger if subdir and suffix are ok *)
        
        RETURN uri(URI.HierarchicalURI)
      END
    ELSE
      RETURN huri;
    END;
  END GetURI;

PROCEDURE (m: Module) GetTimeStamp* (fileId: Rep.FileId; VAR ts: Time.TimeStamp);
  VAR
    uri: URI.URI;
    path: Rep.URIBuffer;
    res: Msg.Msg;
  BEGIN
    uri := m. GetURI (fileId);
    uri(FileURI.URI). GetPath (path);
    Files.GetModTime (path, ts, res);
    IF (res # NIL) THEN
      Time.InitTimeStamp (ts, MAX (LONGINT), 0)
    END
  END GetTimeStamp;

PROCEDURE (m: Module) FileExists* (fileId: Rep.FileId): BOOLEAN;
  VAR
    uri: URI.URI;
    path: Rep.URIBuffer;
  BEGIN
    uri := m. GetURI (fileId);
    uri(FileURI.URI). GetPath (path);
    RETURN Files.Exists(path);
  END FileExists;

PROCEDURE (m: Module) GetInputBuffer* (VAR res: Msg.Msg): InputBuffer.Buffer;
  VAR
    file: Channel.Channel;
    errList: Error.List;
    str: Rep.URIBuffer;
    modURI, relative: URI.URI;
    i: LONGINT;
    scheme: ARRAY 6 OF CHAR;
  BEGIN
    (* create new error list for the source file *)
    modURI := m. GetURI (Rep.modModuleSource);
    relative := modURI. MakeRelative (baseURI);
    relative. GetString (str);
    i := 0;
    WHILE (str[i] = ".") OR (str[i] = "/") DO
      INC (i)
    END;
    IF (i > 6) THEN
      (* string begins with ../../..; with this many steps back in the
         directory hierarchy, a relative file name is pretty useless,
         so we use the original absolue one *)
      modURI. GetString (str);
      Strings.Extract (str, 0, 5, scheme);
      Strings.Capitalize (scheme);
      IF (scheme = "FILE:") THEN
        Strings.Delete (str, 0, 5)
      END;
    END;
    errList := Error.NewList (str);
    
    (* open file for reading *)
    file := modURI. GetChannel (URI.channelOld, res);
    IF (file = NIL) THEN
      RETURN NIL
    ELSE
      Logger.ReadFile(modURI);
      RETURN InputBuffer.New (file, errList)
    END
  END GetInputBuffer;

PROCEDURE (m: Module) CreateOutputDir* (fileId: Rep.FileId; VAR res: Msg.Msg);
  VAR
    path, str: Rep.URIBuffer;
    uri: URI.URI;
  BEGIN
    uri := m. GetURI (fileId);
    uri(FileURI.URI). GetPath (path);
    Path.dirname (path, str);
    OSFiles.makedirs(str, OSFiles.defaultMode, res)
  END CreateOutputDir;

PROCEDURE (m: Module) GetOutputChannel* (fileId: Rep.FileId; makeTmp: BOOLEAN; VAR res: Msg.Msg): Channel.Channel;
  VAR
    uri: URI.URI;
  BEGIN
    m. CreateOutputDir (fileId, res);
    IF (res = OSFiles.done) THEN
      uri := m. GetURI (fileId);
      Logger.WriteFile(uri);
      IF makeTmp THEN
        RETURN uri. GetChannel (URI.channelTmp, res)
      ELSE
        RETURN uri. GetChannel (URI.channelNew, res)
      END
    ELSE
      RETURN NIL
    END
  END GetOutputChannel;

BEGIN
  baseURI := FileURI.GetCwd()
END OOC:Repository:FileSystem.
