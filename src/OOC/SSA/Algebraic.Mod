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
  Language, Language:Integer, OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd;

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
  END;

CONST
  maxPower2 = 63;
  
VAR
  intZero, intOne, intTwo: Integer.Value;
  power2: ARRAY maxPower2+1 OF Integer.Value;

PROCEDURE IsPowerOf2 (value: Integer.Value): LONGINT;
(**Returns a non-negative integer if @oparam{value} is a power of two, and
   @samp{-1} otherwise.  *)
  VAR
    i, cmp: LONGINT;
  BEGIN
    i := 0;
    WHILE (i <= maxPower2) DO
      cmp := value. Compare (power2[i]);
      IF (cmp = 0) THEN
        RETURN i;
      ELSIF (cmp < 0) THEN
        RETURN -1;
      END;
      INC (i);
    END;
    RETURN -1;
  END IsPowerOf2;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
    worklist: Worklist;

  PROCEDURE InspectInstr (instr: SSA.Instr);
    VAR
      exp: LONGINT;
      new: SSA.Instr;
      
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
          RETURN const. Equals (arg. value);
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
        ELSIF Equals (instr. opndList, intZero) THEN (* 0*x = 0 *)
          Replace (instr, instr. opndList);
        ELSIF Equals (instr. opndList. nextOpnd, intZero) THEN (* x*0 = 0 *)
          Replace (instr, instr. opndList. nextOpnd);
        END;

      | Opcode.divide: (* replace DIV by power of two with right shift *)
        IF (instr. subclass < Opcode.scReal32) &
           (instr. opndList. nextOpnd. arg IS SSA.Const) THEN
          exp := IsPowerOf2 (instr. opndList. nextOpnd. arg(SSA.Const). value(Integer.Value));
          IF (exp >= 0) THEN
            new := pb. AddInstr (Opcode.shiftRight, instr. subclass);
            new. AddOpnd (instr. opndList. arg, Opnd.arg);
            new. AddOpnd (pb. GetConstInt (exp), Opnd.arg);
            instr. ReplaceUses (new);
            ASSERT (instr. nextResult = NIL);
          END;
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

PROCEDURE Init ();
  VAR
    i: LONGINT;
  BEGIN
    intZero := Integer.New (0);
    intOne := Integer.New (1);
    intTwo := Integer.New (2);
    
    power2[0] := intOne;
    FOR i := 1 TO maxPower2 DO
      power2[i] := power2[i-1]. Product (intTwo);
    END;
  END Init;

BEGIN
  Init;
END OOC:SSA:Algebraic.
