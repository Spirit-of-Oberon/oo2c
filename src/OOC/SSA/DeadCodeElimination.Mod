(* 	$Id$	 *)
MODULE OOC:SSA:DeadCodeElimination;
(*  Removes unreachable code from a procedure's SSA representation.
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
  OOC:SSA;

CONST
  dead = 0;
  live = 1;


PROCEDURE MarkLive (instr: SSA.Instr);
  VAR
    opnd: SSA.Opnd;
  BEGIN
    IF (instr. marker = dead) THEN
      instr. marker := live;
      opnd := instr. opndList;
      WHILE (opnd # NIL) DO
        MarkLive (opnd. arg. instr);
        opnd := opnd. nextOpnd
      END;
    END;
  END MarkLive;

PROCEDURE DeleteDeadCode (pb: SSA.ProcBlock);
  VAR
    instr, next: SSA.Instr;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      IF (instr. marker = dead) THEN
        pb. DeleteInstr (instr)
      END;
      instr := next;
    END;
  END DeleteDeadCode;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  BEGIN
    (* mark all instructions in `pb' as dead *)
    pb. SetMarkers (NIL, dead);
    (* mark exit instruction and all instruction contributing to it as live *)
    MarkLive (pb. selectReturn);
    (* remove all instructions marked as dead *)
    DeleteDeadCode (pb)
  END Transform;

END OOC:SSA:DeadCodeElimination.
