MODULE OOC:Make:BuildCmd:InterfaceHTML;

IMPORT
  Err, Out, Strings, Msg, URI, URI:Scheme:File, OS:Path, OS:Files, 
  OS:ProcessManagment,
  OOC:Error, OOC:Make, OOC:Make:Node:ModuleOutput, OOC:Repository,
  OOC:Config:Repositories;


TYPE
  BuildCmd* = POINTER TO BuildCmdDesc;
  BuildCmdDesc = RECORD
    (Make.BuildCmdDesc)
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

PROCEDURE New*(): BuildCmd;
  VAR
    cmd: BuildCmd;
  BEGIN
    NEW (cmd);
    RETURN cmd
  END New;

PROCEDURE (cmd: BuildCmd) Build* (n: Make.Node): Make.BuildResult;
(**Create an HTML document from a module's XML interface description.  *)
  VAR
    m: Repository.Module;
    str: ARRAY 4*1024 OF CHAR;
    path: Repository.URIBuffer;
    uri: URI.URI;
    exit: LONGINT;
    res: Msg.Msg;
    errList: Error.List;
  BEGIN
    exit := 0;
    m := n(ModuleOutput.Node). module;
    uri := GetSystemId (n. dg. config. repositories);
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
    
    RETURN Make.NewBuildResult ((res = NIL) & (exit = 0), FALSE, errList)
  END Build;

BEGIN
  scriptSystemId := NIL
END OOC:Make:BuildCmd:InterfaceHTML.
