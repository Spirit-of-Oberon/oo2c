(* 	$Id$	 *)
MODULE OOC:SSA:DeadCodeElimination;
(*  Removes unreachable code from a procedure's SSA representation.
    Copyright (C) 2001-2003  Michael van Acken

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
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd;

CONST
  dead = 0;
  live = 1;


PROCEDURE MarkLive (res: SSA.Result);
  VAR
    instr, loopEnd: SSA.Instr;
    opnd: SSA.Opnd;
    i: LONGINT;

  PROCEDURE MarkStore(opnd: SSA.Opnd; index: LONGINT);
    BEGIN
      IF (index < 1) OR
         (index = 1) & (opnd.arg.instr.opcode # Opcode.collect) THEN
        MarkLive(opnd.arg);
      ELSE
        ASSERT(opnd.arg.instr.opcode = Opcode.collect);
        opnd.arg.marker := live;
        MarkLive(opnd.arg.instr.NthArg(index-1));
      END;
    END MarkStore;
  
  BEGIN
    instr := res.instr;
    
    IF (instr.marker = dead) THEN
      instr. marker := live;
      opnd := instr. opndList;
      IF (instr.opcode # Opcode.collect) THEN
        WHILE (opnd # NIL) DO
          IF (opnd. class # Opnd.storeExit) THEN
            (* a use within a "store-exit" of a "loop-end" or "select-return"
               does not make the instruction live *)
            MarkLive (opnd. arg);
          END;
          opnd := opnd. nextOpnd
        END;
      ELSE  (* only follow the store operand, the rest is marked on demand *)
        MarkLive (opnd. arg);
      END;
    END;
    
    CASE instr.opcode OF
    | Opcode.select:
      IF (res.marker = dead) THEN
        res.marker := live;
        i := res.ResultIndex();
        
        opnd := instr.NthOpnd(2);
        WHILE (opnd # NIL) & (opnd.class = Opnd.arg) DO
          MarkStore(opnd, i);
          opnd := opnd.nextOpnd;
          IF (opnd # NIL) THEN
            opnd := opnd.nextOpnd;
          END;
        END;
      END;
      
    | Opcode.loopStart:
      IF (res.marker = dead) THEN
        res.marker := live;
        i := res.ResultIndex();
        
        MarkStore(instr.opndList, i);
        loopEnd := instr.GetLoopEnd();
        ASSERT(loopEnd.opndList.arg = instr);
        MarkStore(loopEnd.opndList.nextOpnd, i);
      END;
      
    | Opcode.loopEnd:
      IF (res.marker = dead) THEN
        res.marker := live;
        i := res.ResultIndex();
        
        opnd := instr.NthOpnd(2);
        WHILE (opnd # NIL) & (opnd.class = Opnd.storeExit) DO
          ASSERT(opnd.arg.instr.opcode = Opcode.exit);
          MarkStore(opnd.arg.instr.opndList, i);
          opnd := opnd.nextOpnd;
        END;
      END;
    ELSE  (* ignore *)
    END;
  END MarkLive;

PROCEDURE DeleteDeadCode (pb: SSA.ProcBlock);
  VAR
    instr, next, loopEnd: SSA.Instr;
    use, nextUse, opnd: SSA.Opnd;
    res, nextResult: SSA.Result;
    i: LONGINT;

  PROCEDURE DeleteStore(opnd: SSA.Opnd; index: LONGINT);
    BEGIN
      ASSERT(index > 1);
      ASSERT(opnd.arg.instr.opcode = Opcode.collect);
      opnd := opnd.arg.instr.NthOpnd(index-1);
      opnd.DeleteOpnd();
    END DeleteStore;
  
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      IF (instr. marker = dead) THEN
        CASE instr. opcode  OF
        | Opcode.exit, Opcode.return:
          (* make sure that any dangling uses in "select-return" or "loop-end"
             are discarded *)
          use := instr. nextResult. useList;
          WHILE (use # NIL) DO
            nextUse := use. nextUse;
            use. DeleteOpnd;
            use := nextUse;
          END;
        ELSE
        END;
        pb. DeleteInstr (instr);

      ELSIF (instr.opcode = Opcode.select) THEN
        res := instr.nextResult;
        WHILE (res # NIL) DO
          nextResult := res.nextResult;
          IF (res.marker = dead) THEN
            (* if the result is dead, remove the corresponding operand from
               all collect instructions feeding into the select *)
            i := res.ResultIndex();
            
            opnd := instr.NthOpnd(2);
            WHILE (opnd # NIL) & (opnd.class = Opnd.arg) DO
              DeleteStore(opnd, i);
              opnd := opnd.nextOpnd;
              IF (opnd # NIL) THEN
                opnd := opnd.nextOpnd;
              END;
            END;
            res.DeleteResult();
          END;
          res := nextResult;
        END;
        
      ELSIF (instr.opcode = Opcode.loopStart) THEN
        loopEnd := instr.GetLoopEnd();
        res := instr.nextResult;
        WHILE (res # NIL) DO
          nextResult := res.nextResult;
          IF (res.marker = dead) THEN
            (* if the result is dead, remove the corresponding operand from
               the two collect instructions feeding into the loop-start *)
            i := res.ResultIndex();
            
            DeleteStore(instr.opndList, i);
            DeleteStore(loopEnd.opndList.nextOpnd, i);
            res.DeleteResult();
          END;
          res := nextResult;
        END;

      ELSIF (instr.opcode = Opcode.loopEnd) THEN
        res := instr.nextResult;
        WHILE (res # NIL) DO
          nextResult := res.nextResult;
          IF (res.marker = dead) THEN
            (* if the result is dead, remove the corresponding operand from
               any exit instructions feeding into the loop-end *)
            i := res.ResultIndex();
            
            opnd := instr.NthOpnd(2);
            WHILE (opnd # NIL) & (opnd.class = Opnd.storeExit) DO
              DeleteStore(opnd.arg.instr.opndList, i);
              opnd := opnd.nextOpnd;
            END;
            res.DeleteResult();
          END;
          res := nextResult;
        END;
      END;
      instr := next;
    END;
  END DeleteDeadCode;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  BEGIN
    (* mark all instructions in `pb' as dead *)
    pb. SetMarkers (NIL, dead);
    (* mark exit instruction and all instruction contributing to it as live;
       collect instructions are treated specially: their arguments are only
       marked live if the corresponding result of a selct or loop-start is
       live *)
    MarkLive (pb. selectReturn);
    (* remove all instructions marked as dead *)
    DeleteDeadCode (pb)
  END Transform;

END OOC:SSA:DeadCodeElimination.
