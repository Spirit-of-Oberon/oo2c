(* 	$Id$	 *)
MODULE OOC:Make:Command:WriteMainFileAssembler;
(*  Generates the main file of a program as i386 assembler code.
    Copyright (C) 2002  Michael van Acken

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
  Ascii, Channel, Files, Make, TextRider, ADT:Dictionary, ADT:String,
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
    RETURN String.New ("[OOC:Make:Command:WriteMainFileAssembler]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  VAR
    entity: Make.Entity;
  BEGIN
    IF (cmd. state = Make.commandUndiscovered) THEN
      entity := ModuleFile.GetEntity (cmd. context, cmd. module, Repository.modMainFileAssembler);
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

  PROCEDURE Directive (cmd: ARRAY OF CHAR);
    BEGIN
      w. WriteString (cmd);
      w. WriteLn;
    END Directive;

  PROCEDURE Instr (instr: ARRAY OF CHAR);
    BEGIN
      w. WriteChar (Ascii.ht);
      w. WriteString (instr);
      w. WriteLn;
    END Instr;
  
  BEGIN
    ch := cmd. module. GetOutputChannel (Repository.modMainFileAssembler, TRUE, res);
    IF (res = Channel.done) THEN
      w := TextRider.ConnectWriter (ch);
      Directive(".text");
      Directive(".Ltext0:");
      Instr(".align 4");
      Directive(".globl main");
      Instr(".type "+Ascii.ht+" main,@function");
      Directive("main:");
      Instr("pushl %ebp");
      Instr("movl %esp,%ebp");
      Instr("subl $8,%esp");
      
      Instr("movl 8(%ebp),%eax");
      Instr("movl %eax,RT0__argc");
      Instr("movl 12(%ebp),%eax");
      Instr("movl %eax,RT0__argv");
      
      (*Instr("addl $-12,%esp");  function has been removed
      Instr("pushl $262144");
      Instr("call RT0__InitVParStack");  
      Instr("addl $16,%esp");*)
      
      WriteModules (w, Dictionary.New(), cmd. module, Ascii.ht+"call ", "_init0");
      Instr("xorl %eax,%eax");
      Instr("leave");
      Instr("ret");
      Directive(".Lfe1:");
      Instr(".size"+Ascii.ht+" main,.Lfe1-main");
      Directive(".Lscope0:");
      Instr(".text");
      Directive("Letext:");
      Instr(".ident"+Ascii.ht+'"OOC: 0.1"');
      
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

END OOC:Make:Command:WriteMainFileAssembler.
