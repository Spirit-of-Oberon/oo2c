(* 	$Id$	 *)
MODULE OOC:Make:Command:CompileFileC;
(*  Translates a C file into an object file.
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
  Channel, Make, Out, ADT:String, OS:ProcessManagment,
  OOC:Make:Entity:ModuleFile,
  OOC:Error, OOC:Repository, OOC:Config:CCompiler, OOC:Auxiliary:Config;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    fileId: Repository.FileId;
    sourceId: Repository.FileId;
  END;

PROCEDURE New* (context: Make.Context; module: Repository.Module;
                fileId: Repository.FileId): Command;
  VAR
    cmd: Command;
    src: Repository.FileId;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. module := module;
    cmd. fileId := fileId;
    CASE cmd. fileId OF
    | Repository.modObjectFile    : src := Repository.modCodeFileC
    | Repository.modMainObjectFile: src := Repository.modMainFileC
    END;
    cmd. sourceId := src;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:CompileFileC]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    IF (cmd. state = Make.commandUndiscovered) THEN
      cmd. AddAncestor (ModuleFile.GetEntity (cmd. context, cmd. module,
                                              cmd. sourceId));
      RETURN cmd. state+1
    ELSE
      IF cmd. HasInvalidAncestor() THEN
        RETURN Make.commandInvalid
      ELSE
        RETURN Make.commandSchedule
      END
    END
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
  VAR
    m: Repository.Module;
    str: ARRAY 4*1024 OF CHAR;
    exit: LONGINT;
    res: Error.Msg;
    config: Config.Config;
  BEGIN
    exit := 0;
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    
    cmd. module. CreateOutputDir (cmd. fileId, res);
    IF (res = NIL) THEN
      CCompiler.CompileFileCmd (config. options, 
                            cmd. module. GetURI (cmd. sourceId),
                            cmd. module. GetURI (cmd. fileId), str);
      Out.String (str);
      Out.Ln;
      exit := ProcessManagment.system (str)
    END;
    
    RETURN (res = NIL) & (exit = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
  END ProduceOutput;

END OOC:Make:Command:CompileFileC.

