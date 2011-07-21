(* 	$Id: Check.Mod,v 1.1 2002/07/30 02:59:05 mva Exp $	 *)
MODULE OOC:SSA:Check;
(*  Checks some integrity contraints imposed on SSA code.
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
  Log, ADT:ArrayList, Dictionary := ADT:Dictionary:IntValue, OOC:SSA;

(**
   This module is intended as a collection of integrity checks on SSA code.
   Its primary use is to detect violations of rules by the code generator
   and any code transformations.

   Right now, the only check implemented tries to locate cycles in SSA
   use chains.
*)
  
PROCEDURE Cycles (pb: SSA.ProcBlock);
(**Check that the instruction dependencies in @oparam{pb} form an acyclic
   directed graph.  *)
  VAR
    map: Dictionary.Dictionary;          (* maps instr to dependence count *)
    ready: ArrayList.ArrayList;          (* instr with no remaining deps *)
    waiting: ArrayList.ArrayList;        (* instr with remaining deps *)
    instr: SSA.Instr;
    degreeIn: LONGINT;
    res: SSA.Result;
    use: SSA.Opnd;
  BEGIN
    map := Dictionary.New();
    ready := ArrayList.New(16);
    waiting := ArrayList.New(128);

    (* for every instruction, determine the number of instructions it is
       dependent on; this number equals the length of the operand list *)
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      degreeIn := instr. SizeOpndList();
      map. Set (instr, degreeIn);
      IF (degreeIn = 0) THEN
        ready. Append (instr);
      ELSE
        waiting. Append (instr);
      END;
      instr := instr. nextInstr;
    END;

    (* succesively remove instructions from the ready list, update the
       dependence count of its using instructions, and move instructions which
       zero dependencies into ready *)
    WHILE (ready. Size() # 0) DO
      instr := ready. array[0](SSA.Instr);
      ready. Remove (0);

      res := instr;
      WHILE (res # NIL) DO
        use := res. useList;
        WHILE (use # NIL) DO
          degreeIn := map. Get (use. instr);
          map. Set (use. instr, degreeIn-1);
          IF (degreeIn = 1) THEN
            ready. Append (use. instr);
            waiting. Remove (waiting. IndexOf (use. instr));
          END;
          use := use. nextUse;
        END;
        res := res. nextResult;
      END;
    END;

    IF (waiting. size # 0) THEN
      Log.Msg ("Check failed: Cycle in instruction dependencies");
      ASSERT (FALSE);
    END;
  END Cycles;

PROCEDURE All* (pb: SSA.ProcBlock);
  BEGIN
    Cycles (pb);
  END All;

END OOC:SSA:Check.
