MODULE OOC:Repository:FileSystem;

IMPORT
  Msg, Channel, Files, TextRider, Strings, Time, OSFiles := OS:Files, OS:Path,
  URI, URIParser := URI:Parser, URIError := URI:Error,
  FileURI := URI:Scheme:File,
  OOC:Error, OOC:Scanner:InputBuffer, Rep := OOC:Repository;


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
                      name: Rep.ModuleName);
  BEGIN
    Rep.InitModule (m, origin, name)
  END InitModule;

PROCEDURE NewModule (origin: Repository; name: Rep.ModuleName): Module;
  VAR
    m: Module;
  BEGIN
    NEW (m);
    InitModule (m, origin, name);
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

PROCEDURE (rep: Repository) GetModule* (moduleName: ARRAY OF CHAR): Module;
(* result is NIL in case of error *)
  VAR
    path, str: Rep.URIBuffer;
    res: URIError.Msg;
    uri: URI.URI;
  BEGIN
    (* assemble file name from base URI, module name, and module suffix *)
    rep. GetDefaultSubdir (Rep.modModuleSource, path);
    IF (path # "") & (path[Strings.Length (path)-1] # "/") THEN
      Strings.Append ("/", path)
    END;
    COPY (moduleName, str);
    ModuleToFileName (str);
    Strings.Append (str, path);
    rep. GetDefaultSuffix (Rep.modModuleSource, str);
    Strings.Append (str, path);
    uri := URIParser.NewURI (path, rep. baseURI, res);
    
    IF (res # NIL) THEN
      RETURN NIL
    ELSE
      uri(FileURI.URI). GetPath (str);
      IF Files.Exists (str) THEN
        RETURN NewModule (rep, moduleName)
      ELSE
        RETURN NIL
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

PROCEDURE (m: Module) GetURI* (fileId: Rep.FileId; VAR res: Msg.Msg): URI.HierarchicalURI;
  VAR
    subdir, suffix, path, str: Rep.URIBuffer;
    uri: URI.URI;
  BEGIN
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
    IF (res # NIL) THEN
      RETURN NIL
    ELSE
      RETURN uri(URI.HierarchicalURI)
    END
  END GetURI;

PROCEDURE (m: Module) GetTimeStamp* (fileId: Rep.FileId; VAR ts: Time.TimeStamp);
  VAR
    uri: URI.URI;
    path: Rep.URIBuffer;
    res: Msg.Msg;
  BEGIN
    uri := m. GetURI (fileId, res);
    IF (res = NIL) THEN
      uri(FileURI.URI). GetPath (path);
      Files.GetModTime (path, ts, res)
    END;
    IF (res # NIL) THEN
      Time.InitTimeStamp (ts, MAX (LONGINT), 0)
    END
  END GetTimeStamp;

PROCEDURE (m: Module) GetInputBuffer* (VAR res: Msg.Msg): InputBuffer.Buffer;
  VAR
    file: Channel.Channel;
    errList: Error.List;
    str: Rep.URIBuffer;
    modURI, relative: URI.URI;
  BEGIN
    (* create new error list for the source file *)
    modURI := m. GetURI (Rep.modModuleSource, res);
    relative := modURI. MakeRelative (baseURI);
    relative. GetString (str);
    errList := Error.NewList (str);
    
    (* open file for reading *)
    file := modURI. GetChannel (URI.channelOld, res);
    IF (file = NIL) THEN
      RETURN NIL
    ELSE
      RETURN InputBuffer.New (file, errList)
    END
  END GetInputBuffer;

PROCEDURE (m: Module) GetOutputChannel* (fileId: Rep.FileId; makeTmp: BOOLEAN; VAR res: Msg.Msg): Channel.Channel;
  VAR
    path, str: Rep.URIBuffer;
    uri: URI.URI;
  BEGIN
    uri := m. GetURI (fileId, res);
    IF (res = NIL) THEN
      uri(FileURI.URI). GetPath (path);
      Path.dirname (path, str);
      OSFiles.makedirs(str, OSFiles.defaultMode, res);
      IF (res = OSFiles.done) THEN
        IF makeTmp THEN
          RETURN uri. GetChannel (URI.channelTmp, res)
        ELSE
          RETURN uri. GetChannel (URI.channelNew, res)
        END
      ELSE
        RETURN NIL
      END
    ELSE
      RETURN NIL
    END
  END GetOutputChannel;

BEGIN
  baseURI := FileURI.GetCwd()
END OOC:Repository:FileSystem.
