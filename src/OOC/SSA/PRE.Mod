(* 	$Id: PRE.Mod,v 1.5 2003/04/02 22:09:41 mva Exp $	 *)
MODULE OOC:SSA:PRE;
(*  Partial redundancy elimination.
    Copyright (C) 2003  Michael van Acken

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

(**Note: The algorithm implemented by this module is @emph{very} experimental
   and incomplete in the sense that it hoists expressions only over one level
   of "select" or "loop-start".  That is, it is only detected if an expression
   is partially redundant with respect to the immediately preceding "select"
   instruction.  Partial redundancies in nested "select"s are not found.  *)

IMPORT
  Object, ADT:ArrayList, ADT:Dictionary, OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA:Result, OOC:SSA:Blocker, OOC:SSA:CSE;

PROCEDURE GetSelect(collect: SSA.Instr): SSA.Instr;
  VAR
    instr: SSA.Instr;
  BEGIN
    instr := collect.GetCollectTarget();
    CASE instr.opcode OF
    | Opcode.select:
      RETURN instr;
    | Opcode.loopStart:
      IF (instr.opndList.arg.instr = collect) THEN
        RETURN NIL;
      ELSE
        RETURN instr;
      END;
    ELSE
      RETURN NIL;
    END;
  END GetSelect;

PROCEDURE GetNoop(pb: SSA.ProcBlock; storeOut: SSA.Result): SSA.Instr;
  VAR
    use: SSA.Opnd;
    noop: SSA.Instr;
    res: SSA.Result;
  BEGIN
    ASSERT(storeOut.class = Result.store);
    use := storeOut.useList;
    WHILE (use # NIL) DO
      IF (use.instr.opcode = Opcode.noop) THEN
        RETURN use.instr;
      END;
      use := use.nextUse;
    END;
    
    noop := pb.AddInstr(Opcode.noop, Opcode.scNone);
    res := noop.AddResult(Result.store);
    storeOut.ReplaceUses(res);
    noop.AddOpnd(storeOut, Opnd.store);
    RETURN noop;
  END GetNoop;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  VAR
    worklist, equivList: ArrayList.ArrayList;
    instr, select, enter, h: SSA.Instr;
    opnd: SSA.Opnd;
    dd: Blocker.DependenceData;
    i: LONGINT;
    equivToCollect: Dictionary.Dictionary;
    
  PROCEDURE MigrateCandidates(collectOpnd: SSA.Opnd;
                              undefValue: SSA.Instr);
    VAR
      use, opnd: SSA.Opnd;
      instr, collect, select, new, equiv, sameInstr, anchor,
          c, domReference: SSA.Instr;
      res, selectResult: SSA.Result;
      i: LONGINT;
      
    PROCEDURE Dominates(res: SSA.Result; instr: SSA.Instr): BOOLEAN;
      BEGIN
        RETURN dd.Dominates(res.instr, instr);
      END Dominates;
    
    PROCEDURE GetSelectResult(select, collect: SSA.Instr;
                              arg: SSA.Result): SSA.Result;
      VAR
        opnd, use: SSA.Opnd;
        res: SSA.Result;
      BEGIN
        opnd := collect.opndList.nextOpnd;
        WHILE (opnd # NIL) & (opnd.arg # arg) DO
          opnd := opnd.nextOpnd;
        END;
        IF (opnd = NIL) THEN
          RETURN NIL;
        ELSE
          res := select.NthResult(opnd.OpndIndex()+1);
          use := res.useList;
          WHILE (use # NIL) DO
            IF (use.instr.opcode = Opcode.equivPRE) &
               (use.instr.opndList = use) &
               (equivToCollect.Get(use.instr) = collect) THEN
              (* if there is already an "equiv" entry for the result of the
                 "select" instruction, then return the constructed instruction
                 that is other side of the equivalence *)
              RETURN use.instr.NthArg(1);
            END;
            use := use.nextUse;
          END;
          RETURN res;
        END;
      END GetSelectResult;
    
    BEGIN
      collect := collectOpnd.instr;
      select := GetSelect(collect);
      anchor := GetNoop(pb, select.nextResult);
      IF (select.opcode = Opcode.loopStart) THEN
        domReference := select.GetLoopEnd();
        ASSERT(~dd.Dominates(select, domReference));
      ELSE
        domReference := select;
      END;
      
      use := collectOpnd.arg.useList;
      WHILE (use # NIL) DO
        IF dd.SameRegion(collect, use.instr) &
           (use.instr.opcode # Opcode.equiv) &
           (use.instr.opcode # Opcode.equivPRE) &
           (use.instr.nextResult = NIL) &    (* only one result (no collect) *)
           dd.Dominates(collect, use.instr) THEN  (* is in collect's region *)
          instr := use.instr;

          new := pb.AddInstr(instr.opcode, instr.subclass);
          opnd := instr.opndList;
          WHILE (opnd # NIL) DO
            res := GetSelectResult(select, collect, opnd.arg);
            IF (res # NIL) THEN
              new.AddOpnd(res, opnd.class);
              opnd := opnd.nextOpnd;
            ELSIF (opnd.arg.info = NIL) OR  (* one of our new instructions *)
                  ~Dominates(opnd.arg, domReference) THEN
              ASSERT(new.useList = NIL);
              pb.DeleteInstr(new);
              new := NIL;
              opnd := NIL;                 (* end loop *)
            ELSE
              new.AddOpnd(opnd.arg, opnd.class);
              opnd := opnd.nextOpnd;
            END;
          END;
          
          IF (new # NIL) THEN
            (* if we were able to create a to `instr' equivalent instruction
               `new' after the select instruction: *)
            sameInstr := dd.GetSameInstr(select, new);
            IF (sameInstr # NIL) THEN  (* exists already, reuse old instr *)
              ASSERT(new.useList = NIL);
              pb.DeleteInstr(new);
              new := sameInstr;
            ELSE
              dd.SetRegion(select, new);
            END;
            
            selectResult := select.AddResultSubclass(Result.selectValue,
                                                     instr.subclass);
            FOR i := 0 TO select.NumberOfPaths()-1 DO
              c := select.GetCollect(NIL, i);
              IF (c = collect) THEN
                worklist.Append(collect.AddOpndFct(instr, Opnd.arg));
              ELSE
                c.AddOpnd(undefValue, Opnd.arg);
              END;
            END;
            
            equiv := pb.AddInstr(Opcode.equivPRE, Opcode.scNone);
            equiv.AddOpnd(selectResult, Opnd.arg);
            equiv.AddOpnd(new, Opnd.arg);
            equivToCollect.Set(equiv, collect);
            dd.SetRegion(new, equiv);
            anchor.AddOpnd(equiv, Opnd.arg);
            
            equivList.Append(equiv);
          END;
        END;
        use := use.nextUse;
      END;
    END MigrateCandidates;

  PROCEDURE ResolveEquiv(equiv: SSA.Instr);
    VAR
      collect, select, old, c, new, sameInstr: SSA.Instr;
      res: SSA.Result;
      opnd, h: SSA.Opnd;
      resultIndex, i: LONGINT;
      obj: Object.Object;
    BEGIN
      ASSERT(equiv.opcode = Opcode.equivPRE);

      obj := equivToCollect.Get(equiv);
      collect := obj(SSA.Instr);
      select := GetSelect(collect);
      res := equiv.opndList.nextOpnd.arg;
      old := res.instr;
      IF (old = select) THEN
        (* the non-preferred value of the "equiv" has already been reduced
           to a result of the "select": reuse this result, and discard our
           own (by letting dead code elimination get rid of it) *)
        equiv.opndList.arg.ReplaceUses(res);
      ELSE
        resultIndex := equiv.opndList.arg.ResultIndex();

        FOR i := 0 TO select.NumberOfPaths()-1 DO
          c := select.GetCollect(NIL, i);
          ASSERT(c.opcode = Opcode.collect);
          
          IF (c # collect) THEN
            new := pb.AddInstr(old.opcode, old.subclass);
            opnd := old.opndList;
            WHILE (opnd # NIL) DO
              IF (opnd.arg.instr = select) THEN
                h := c.NthOpnd(opnd.arg.ResultIndex()-1);
                new.AddOpnd(h.arg, opnd.class);
              ELSE
                new.AddOpnd(opnd.arg, opnd.class);
              END;
              opnd := opnd.nextOpnd;
            END;

            sameInstr := dd.GetSameInstr(c, new);
            IF (sameInstr # NIL) THEN  (* exists already, reuse old instr *)
              ASSERT(new.useList = NIL);
              pb.DeleteInstr(new);
              new := sameInstr;
            ELSE
              dd.SetRegion(c, new);
            END;
            
            opnd := c.NthOpnd(resultIndex-1);
            opnd.ReplaceArg(new);
          END;
        END;
        
        old.ReplaceUses(equiv.opndList.arg);
      END;
      ASSERT(equiv.useList.nextUse = NIL);
      equiv.useList.DeleteOpnd();
      ASSERT(equiv.useList = NIL);
      pb.DeleteInstr(equiv);
    END ResolveEquiv;

  PROCEDURE OnlyUsedInEquiv(res: SSA.Result): BOOLEAN;
    VAR
      use: SSA.Opnd;
    BEGIN
      use := res.useList;
      WHILE (use # NIL) DO
        IF (use.instr.opcode # Opcode.equivPRE) THEN
          RETURN FALSE;
        END;
        use := use.nextUse;
      END;
      RETURN TRUE;
    END OnlyUsedInEquiv;
  
  BEGIN
    dd := Blocker.GetDependenceData(pb);
    Blocker.RemoveAntiDeps(pb);
    
    worklist := ArrayList.New(32);
    equivList := ArrayList.New(32);
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      IF (instr.opcode = Opcode.collect) THEN
        select := GetSelect(instr);
        IF (select # NIL) THEN
          opnd := instr.opndList.nextOpnd;
          WHILE (opnd # NIL) DO
            worklist.Append(opnd);
            opnd := opnd.nextOpnd;
          END;
        END;
      END;
      instr := instr.nextInstr;
    END;

    equivToCollect := Dictionary.New();
    enter := pb.GetEnter();
    WHILE (worklist.size # 0) DO
      opnd := worklist.array[worklist.size-1](SSA.Opnd);
      worklist.Remove(worklist.size-1);
      MigrateCandidates(opnd, enter);
    END;

    CSE.Transform(pb);
    
    (* remove all "equiv" instructions where the newly added instruction has
       not been merged by CSE with an existing one *)
    FOR i := equivList.size-1 TO 0 BY -1 DO
      instr := equivList.array[i](SSA.Instr);
      h := instr.opndList.nextOpnd.arg.instr;
      IF OnlyUsedInEquiv(h) THEN
        (* get rid of the "equiv" as one of the last remaining uses of `h' *)
        ASSERT(instr.useList.nextUse = NIL);
        instr.useList.DeleteOpnd();
        ASSERT(instr.useList = NIL);
        pb.DeleteInstr(instr);

        IF (h.useList = NIL) THEN
          (* the instruction `h' we have put into the second operand has no use
             beyond this "equiv" statement, so we can eliminate it again *)
          pb.DeleteInstr(h);
        END;
        
        equivList.Set(i, NIL);
      END;
    END;

    (* resolve remaining "equiv" instructions *)
    FOR i := 0 TO equivList.size-1 DO
      IF (equivList.array[i] # NIL) THEN
        (*Log.Msg("XXX ResolveEquiv");*)
        ResolveEquiv(equivList.array[i](SSA.Instr));
      END;
    END;
  END Transform;

PROCEDURE ResolveEquiv*(pb: SSA.ProcBlock);
(**Resolves instructions @oconst{Opcode.equiv} and @oconst{Opcode.noop}
   that were inserted by @oproc{*OOC:SSA:LoopRewrite.Transform}.  *)
  VAR
    instr, next: SSA.Instr;
  BEGIN
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      IF (instr.opcode = Opcode.equiv) THEN
        instr.opndList.nextOpnd.arg.ReplaceUses(instr.opndList.arg);
        IF (instr.useList # NIL) THEN
          ASSERT(instr.useList.nextUse = NIL);
          instr.useList.DeleteOpnd();
        END;
        pb.DeleteInstr(instr);

      ELSIF (instr.opcode = Opcode.noop) THEN
        instr.nextResult.ReplaceUses(instr.opndList.arg);
        pb.DeleteInstr(instr);
      END;
      instr := next;
    END;
  END ResolveEquiv;

END OOC:SSA:PRE.
