(* 	$Id$	 *)
MODULE OOC:Make:Command:InterfaceXML;
(*  Writes a module's exported interface as XML document.
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
  Channel, Files, Msg, URI, Make, ADT:String,
  OOC:Make:Entity:ModuleFile, OOC:Auxiliary:ParseModule, OOC:Auxiliary:Config,
  OOC:Error, OOC:Config:Pragmas, OOC:Repository, OOC:AST, 
  Sym := OOC:SymbolTable, OOC:SymbolTable:InterfaceXML;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
  END;

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
    RETURN String.New ("[OOC:Make:Command:InterfaceXML]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    cmd. AddAncestors (ModuleFile.GetEntity (cmd. context, cmd. module,
                                             Repository.modSymbolFile));
    RETURN Make.commandSchedule
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Writes the description of the module's public interface as an XML document.
   *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    res: Msg.Msg;
    outputChannel: Channel.Channel;
    outputURI: URI.HierarchicalURI;
    m: Repository.Module;
    config: Config.Config;
    pragmaHistory: Pragmas.History;
  BEGIN
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    ParseModule.ParseModule (m, config, FALSE, TRUE, FALSE,
                             ast, symTab, pragmaHistory, errList);
    IF (errList. msgCount = 0) THEN
      outputURI := m. GetURI (Repository.modInterfaceXML);
      outputChannel := m. GetOutputChannel (Repository.modInterfaceXML, TRUE, res);
      IF (outputChannel = NIL) THEN
        errList. Append (res)
      ELSE
        InterfaceXML.Write (outputChannel.NewWriter(), outputURI, symTab,
                            config. repositories);
        outputChannel(Files.File). Register;
        outputChannel. Close;
        IF (outputChannel. res # Channel.done) THEN
          errList. Append (outputChannel. res)
        END
      END
    END;
    cmd. errList := errList;
    RETURN (errList. msgCount = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
    IF (cmd. errList. msgCount # 0) THEN
      cmd. errList. Write (stderr)
    END
  END ProduceOutput;

END OOC:Make:Command:InterfaceXML.
