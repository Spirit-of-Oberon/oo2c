(* 	$Id$	 *)
MODULE OOC:Make:Command:LinkProgramC;
(*  Links object files and libraries to create an executable file.
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
  Channel, Make, Out, Strings, URI, URI:Scheme:File,
  ADT:Object, ADT:String, ADT:Dictionary,
  OS:ProcessManagment, OOC:Make:Entity:ModuleFile,
  OOC:Error, OOC:Repository, OOC:Config:CCompiler, OOC:Auxiliary:Config,
  Sym := OOC:SymbolTable;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
  END;

PROCEDURE New* (context: Make.Context; module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. module := module;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:LinkProgramC]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    IF (cmd. state = Make.commandUndiscovered) THEN
      cmd. AddAncestors (ModuleFile.GetEntity (cmd. context, cmd. module,
                                               Repository.modExecutable));
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
    str: ARRAY 4*1024 OF CHAR;
    path: Repository.URIBuffer;
    uri: URI.URI;
    exit, i: LONGINT;
    res: Error.Msg;
    config: Config.Config;
    aEdge: Make.Edge;
    fileId: Repository.FileId;
    ancestor: Repository.Module;
    linkDirective: Sym.LinkDirective;
    libsMap: Dictionary.Dictionary;
    libs: Object.ObjectArrayPtr;
  BEGIN
    exit := 0;
    config := cmd. context. config(Config.Config);
    
    cmd. module. CreateOutputDir (Repository.modExecutable, res);
    IF (res = NIL) THEN
      CCompiler.LinkProgramCmd (config, 
                          cmd. module. GetURI (Repository.modExecutable), str);

      libsMap := Dictionary.New();
      aEdge := cmd. ancestorList;
      WHILE (aEdge # NIL) DO
        fileId := aEdge. ancestor(ModuleFile.Entity). fileId;
        IF (fileId # Repository.modSymbolFile) THEN
          ancestor := aEdge. ancestor(ModuleFile.Entity). module;
          uri := ancestor. GetURI (fileId);
          uri(File.URI). GetPath (path);
          Strings.Append (" ", str);
          Strings.Append (path, str);

          (* note down any libraries that need to be linked in *)
          linkDirective := ancestor. symbolTable. linkDirectives;
          WHILE (linkDirective # NIL) DO
            WITH linkDirective: Sym.LinkLib DO
              libsMap. Set (linkDirective. libraryName, NIL);
            ELSE                         (* ignore *)
            END;
            linkDirective := linkDirective. next
          END;
        END;
        aEdge := aEdge. nextAncestor
      END;

      (* add "-l" options for the external libraries *)
      (* FIXME... honor interdependencies between libraries in order
         of options *)
      libs := libsMap. Keys();
      FOR i := 0 TO LEN (libs^)-1 DO
        Strings.Append (" -l", str);
        Strings.Append (libs[i](String.String). array^, str);
      END;
    END;
    IF (res = NIL) THEN
      Out.String (str);
      Out.Ln;
      exit := ProcessManagment.system (str)
    END;
    
    RETURN (res = NIL) & (exit = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
  END ProduceOutput;

END OOC:Make:Command:LinkProgramC.

