(* 	$Id$	 *)
MODULE OOC:Make:Command:InterfaceHTML;
(*  Produces an HTML rendition of a module's interface.
    Copyright (C) 2001  Michael van Acken

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

PROCEDURE New* (context: Make.Context; module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
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
    
    uri := m. GetURI (Repository.modInterfaceDescr);
    uri(File.URI). GetPath (path);
    Strings.Append (" '", str);
    Strings.Append (path, str);
    Strings.Append ("' '", str);
    
    uri := m. GetURI (Repository.modInterfaceHTML);
    uri(File.URI). GetPath (path);
    Strings.Append (path, str);
    Strings.Append ("'", str);

    Path.dirname (path, path);
    Files.makedirs (path, Files.defaultMode, res);
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
