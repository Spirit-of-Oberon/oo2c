(* 	$Id: WriteMainFileAssembler.Mod,v 1.6 2003/02/02 19:10:08 mva Exp $	 *)
MODULE OOC:Make:WriteMainFileAssembler;
(*  Generates the main file of a program as i386 assembler code.
    Copyright (C) 2002, 2003  Michael van Acken

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
  Ascii, IO, IO:TextRider, OOC:Repository;

PROCEDURE WriteFile*(module: Repository.Module;
                     imports: ARRAY OF Repository.Module)
RAISES IO.Error;
  VAR
    ch: IO.ByteChannel;
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
  
  PROCEDURE WriteModules (w: TextRider.Writer; prefix, suffix: ARRAY OF CHAR);
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO LEN(imports)-1 DO
        IF ~imports[i].ifData.NoObjectFile() THEN
          WriteModuleName (w, prefix, imports[i], suffix);
        END;
      END;
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
    ch := module.GetOutputChannel(Repository.modMainFileAssembler, TRUE);
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
    
    WriteModules (w, Ascii.ht+"call OOC_", "_init0");
    Instr("xorl %eax,%eax");
    Instr("leave");
    Instr("ret");
    Directive(".Lfe1:");
    Instr(".size"+Ascii.ht+" main,.Lfe1-main");
    Directive(".Lscope0:");
    Instr(".text");
    Directive("Letext:");
    Instr(".ident"+Ascii.ht+'"OOC: 0.1"');

    ch.CloseAndRegister();
  END WriteFile;

END OOC:Make:WriteMainFileAssembler.
