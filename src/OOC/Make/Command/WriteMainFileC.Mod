(* 	$Id$	 *)
MODULE OOC:Make:Command:WriteMainFileC;
(*  Generates the main file of a program.
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
  Channel, Files, Make, TextRider, ADT:Dictionary, ADT:String,
  OOC:Make:Entity:ModuleFile, OOC:Error, OOC:Repository;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    res: Error.Msg;
  END;

PROCEDURE New* (context: Make.Context; module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. module := module;
    cmd. res := NIL;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:WriteMainFileC]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  VAR
    entity: Make.Entity;
  BEGIN
    IF (cmd. state = Make.commandUndiscovered) THEN
      entity := ModuleFile.GetEntity (cmd. context, cmd. module, Repository.modMainFileC);
      cmd. AddAncestors (entity);
      RETURN cmd. state+1
    ELSE
      IF cmd. HasInvalidAncestor() THEN
        RETURN Make.commandInvalid
      ELSE
        RETURN Make.commandSchedule
      END
    END
  END Discover;

PROCEDURE WriteFile (cmd: Command; VAR res: Error.Msg);
  VAR
    ch: Channel.Channel;
    w: TextRider.Writer;
  
  PROCEDURE WriteModuleName (w: TextRider.Writer; 
                             prefix: ARRAY OF CHAR;
                             module: Repository.Module;
                             suffix: ARRAY OF CHAR);
    VAR
      str: ARRAY 1024 OF CHAR;
      i: LONGINT;
    BEGIN
      COPY (module. name^, str);
      i := 0;
      WHILE (str[i] # 0X) DO
        IF (str[i] = ":") THEN str[i] := "_" END;
        INC (i)
      END;
      w. WriteString (prefix);
      w. WriteString (str);
      w. WriteString (suffix);
      w. WriteLn;
    END WriteModuleName;
  
  PROCEDURE WriteModules (w: TextRider.Writer; done: Dictionary.Dictionary;
                          module: Repository.Module;
                          prefix, suffix: ARRAY OF CHAR);
    VAR
      import: Repository.Import;
    BEGIN
      IF ~done. HasKey (module) THEN
        done. Set (module, module);
        import := module. importList;
        WHILE (import # NIL) DO
          WriteModules (w, done, import. imported, prefix, suffix);
          import := import. nextImport
        END;
        WriteModuleName (w, prefix, module, suffix)
      END
    END WriteModules;
  
  BEGIN
    ch := cmd. module. GetOutputChannel (Repository.modMainFileC, TRUE, res);
    IF (res = Channel.done) THEN
      w := TextRider.ConnectWriter (ch);
      WriteModules (w, Dictionary.New(), cmd. module,
                    "extern void ", "_init(void);");
      w. WriteLn;
      
      w. WriteString ("int main (int argc, char *argv[]) {");
      w. WriteLn;
      WriteModules (w, Dictionary.New(), cmd. module, "  ", "_init();");
      w. WriteString ("  return 0;  /* _program_exit_code */");
      w. WriteLn;
      w. WriteString ("}");
      w. WriteLn;
      
      res := w. res;
      ch(Files.File). Register;
      IF (ch. res # NIL) & (res = NIL) THEN
        res := ch. res
      END
    END
  END WriteFile;


PROCEDURE (cmd: Command) Run*(): BOOLEAN;
  BEGIN
    WriteFile (cmd, cmd. res);
    RETURN (cmd. res = NIL)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  VAR
    errList: Error.List;
  BEGIN
    IF (cmd. res # NIL) THEN
      errList := Error.NewList("");
      errList. Append (cmd. res);
      errList. Write (stderr)
    END
  END ProduceOutput;

END OOC:Make:Command:WriteMainFileC.
