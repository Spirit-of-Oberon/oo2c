MODULE OOC:Make:Command:InterfaceHTML;

IMPORT
  Channel, Err, Out, Strings, Make, Msg, ADT:String, 
  URI, URI:Scheme:File, OS:Path, OS:Files, OS:ProcessManagment,
  OOC:Error, OOC:Make:Entity:ModuleFile, OOC:Repository,
  OOC:Config:Repositories, OOC:Auxiliary:Config;


TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
  END;

CONST
  scriptPackageName = "OOC";
  scriptResourcePath = "xml/gen-interface-description";

VAR
  scriptSystemId: URI.URI;


PROCEDURE GetSystemId (repositories: Repositories.Section): URI.URI;
  BEGIN
    IF (scriptSystemId = NIL) THEN
      scriptSystemId := repositories. GetResource (scriptPackageName, scriptResourcePath);
      IF (scriptSystemId = NIL) THEN
        Err.String ("Error: Cannot locate script "+scriptResourcePath+
                    " from package "+scriptPackageName+" in any of the "+
                    "configured repositories.");
        Err.Ln;
        HALT (1)
      END;
      RETURN scriptSystemId
    ELSE
      RETURN scriptSystemId
    END
  END GetSystemId;

PROCEDURE New* (module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd);
    cmd. module := module;
    cmd. errList := NIL;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:InterfaceHTML]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    cmd. AddAncestors (ModuleFile.GetEntity (cmd. context, cmd. module,
                                             Repository.modInterfaceXML));
    RETURN Make.commandSchedule
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Create an HTML document from a module's XML interface description.  *)
  VAR
    m: Repository.Module;
    str: ARRAY 4*1024 OF CHAR;
    path: Repository.URIBuffer;
    uri: URI.URI;
    exit: LONGINT;
    res: Msg.Msg;
    errList: Error.List;
    config: Config.Config;
  BEGIN
    exit := 0;
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    uri := GetSystemId (config. repositories);
    uri(File.URI). GetPath (str);
    uri := m. GetURI (Repository.modInterfaceDescr, res);
    IF (res = NIL) THEN
      uri(File.URI). GetPath (path);
      Strings.Append (" '", str);
      Strings.Append (path, str);
      Strings.Append ("' '", str);
      uri := m. GetURI (Repository.modInterfaceHTML, res);
    END;
    IF (res = NIL) THEN
      uri(File.URI). GetPath (path);
      Strings.Append (path, str);
      Strings.Append ("'", str);

      Path.dirname (path, path);
      Files.makedirs (path, Files.defaultMode, res)
    END;
    IF (res = NIL) THEN
      Out.String ("make: ");
      Out.String (str);
      Out.Ln;
      exit := ProcessManagment.system (str)
    END;
    
    errList := NIL;
    IF (res # NIL) THEN
      errList := Error.NewList("");
      errList. Append (res)
    END;
    
    cmd. errList := errList;
    RETURN (res = NIL) & (exit = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
    IF (cmd. errList # NIL) & (cmd. errList. msgCount # 0) THEN
      cmd. errList. Write (stderr)
    END
  END ProduceOutput;

BEGIN
  scriptSystemId := NIL
END OOC:Make:Command:InterfaceHTML.
