(* 	$Id$	 *)
MODULE OOC:SSA:Algebraic;
(*  Algebraic transformations on SSA expressions.
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

(* FIXME... add more transformations *)

IMPORT
  Language, Language:Integer, OOC:SSA, OOC:SSA:Opcode;

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
  END;
  
VAR
  intZero, intOne: Integer.Value;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
    worklist: Worklist;

  PROCEDURE InspectInstr (instr: SSA.Instr);
    PROCEDURE Replace (instr: SSA.Instr; with: SSA.Opnd);
      VAR
        use: SSA.Opnd;

      PROCEDURE AddToWorklist (instr: SSA.Instr);
        VAR
          wl: Worklist;
        BEGIN
          NEW (wl);
          wl. next := worklist;
          wl. instr := instr;
          worklist := wl;
        END AddToWorklist;
      
      BEGIN
        ASSERT (instr. nextResult = NIL);
        use := instr. useList;
        WHILE (use # NIL) DO
          AddToWorklist (use. instr);
          use := use. nextUse;
        END;
        instr. ReplaceUses (with. arg);
      END Replace;

    PROCEDURE Equals (opnd: SSA.Opnd; const: Language.Value): BOOLEAN;
      VAR
        arg: SSA.Result;
      BEGIN
        arg := opnd. arg;
        WITH arg: SSA.Const DO
          RETURN (arg. value # NIL) & const. Equals (arg. value);
        ELSE
          RETURN FALSE;
        END;
      END Equals;
    
    BEGIN
      CASE instr. opcode OF
      | Opcode.add:
        IF Equals (instr. opndList, intZero) THEN (* 0+x = x *)
          Replace (instr, instr. opndList. nextOpnd);
        ELSIF Equals (instr. opndList. nextOpnd, intZero) THEN (* x+0 = x *)
          Replace (instr, instr. opndList);
        END;
        
      | Opcode.subtract:
        IF Equals (instr. opndList. nextOpnd, intZero) THEN (* x-0 = x *)
          Replace (instr, instr. opndList);
        END;
        
      | Opcode.multiply:
        IF Equals (instr. opndList, intOne) THEN (* 1*x = x *)
          Replace (instr, instr. opndList. nextOpnd);
        ELSIF Equals (instr. opndList. nextOpnd, intOne) THEN (* x*1 = x *)
          Replace (instr, instr. opndList);
        END;
        
      ELSE  (* ignore any other instructions *)
      END;
    END InspectInstr;
  
  BEGIN
    worklist := NIL;
    
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      InspectInstr (instr);
      instr := instr. nextInstr;
    END;

    (* the previous replacements may have brought additional transformation
       opportunities: scan all instructions that have been changed *)
    WHILE (worklist # NIL) DO
      instr := worklist. instr;
      worklist := worklist. next;
      InspectInstr (instr);
    END;
  END Transform;

BEGIN
  intZero := Integer.New (0);
  intOne := Integer.New (1);
END OOC:SSA:Algebraic.
