(* 	$Id: CSE.Mod,v 1.9 2003/02/22 13:22:35 mva Exp $	 *)
MODULE OOC:SSA:CSE;
(*  Common subexpression elimination using value numbering.
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
  OOC:SSA:Blocker, OOC:SSA, OOC:SSA:Opcode;
  
TYPE
  ResultList = POINTER TO ARRAY OF SSA.Result;
  Partition = POINTER TO PartitionDesc;
  ChildrenList = POINTER TO ARRAY OF Partition;
  PartitionDesc = RECORD
    (SSA.NodeDesc)
    nextPartition: Partition;
    nextWorklist: Partition;
    size: LONGINT;
    iList: ResultList;

    splitted: BOOLEAN;
    (* If @code{TRUE}, then @oproc{Transform.Split} has been called for this
       partition, or is currently executed.  *)
    inWorklist: BOOLEAN;
    
    ancestor: Partition;
    (* During a run of @oproc{Transform.Split}, newly created partitions store
       here the partition from which they where split off.  For the original
       partition, this field is @code{NIL}.  *)
    ancestorOpnd: LONGINT;
    (* If @samp{ancestor # NIL}, then this field is the index of the operand
       on which the split operation was based.  Otherwise, it is @samp{-1}.  *)
    splitChildren: ChildrenList;
    (* List of partitions that have been split off from this one.  For every
       child, @ofield{ancestor} refers to this partition.  The value of
       @ofield{ancestorOpnd} of every child is greater than the
       @ofield{ancestorOpnd} of this instance.  The end of the list is marked
       by an entry @code{NIL}.  *)
    
    nextTouched: Partition;
    nextOrigin: Partition;
  END;


  (*
     FIXME... get rid of empty partitions as soon as possible;
     speed up the DependenceData predicates
     *)
  
PROCEDURE InitPartition (p: Partition);
  CONST
    initialSize = 4;
  VAR
    i: LONGINT;
  BEGIN
    SSA.InitNode (p);
    p. nextPartition := NIL;
    p. nextWorklist := NIL;
    p. size := 0;
    NEW (p. iList, initialSize);
    FOR i := 0 TO initialSize-1 DO
      p. iList[i] := NIL;
    END;

    p. splitted := FALSE;
    p. inWorklist := FALSE;
    
    p. ancestor := NIL;
    p. ancestorOpnd := -1;
    NEW (p. splitChildren, initialSize);
    p. splitChildren[0] := NIL;
  END InitPartition;

PROCEDURE NewPartition(): Partition;
  VAR
    p: Partition;
  BEGIN
    NEW (p);
    InitPartition (p);
    RETURN p;
  END NewPartition;

PROCEDURE (p: Partition) Add (instr: SSA.Instr);
  VAR
    old: Partition;
    i: LONGINT;
    new: ResultList;
    
  PROCEDURE Swap (VAR i1, i2: SSA.Result);
    VAR
      j: SSA.Result;
    BEGIN
      j := i1; i1 := i2; i2 := j;
    END Swap;
  
  BEGIN
    IF (instr. info # NIL) THEN
      (* remove instruction from old partition *)
      old := instr. info(Partition);
      IF (old. size > 0) THEN
        i := 0;
        WHILE (old. iList[i] # instr) DO
          INC (i);
        END;
        Swap (old. iList[i], old. iList[old. size-1]);
      END;
      DEC (old. size);
    END;

    IF (p. size = LEN (p. iList^)) THEN  (* instr list is full, extend it *)
      NEW (new, p. size*2);
      FOR i := 0 TO p. size-1 DO
        new[i] := p. iList[i];
      END;
      FOR i := p. size TO LEN (new^)-1 DO
        new[i] := NIL;
      END;
      p. iList := new;
    END;
    
    p. iList[p. size] := instr;
    INC (p. size);
    instr. info := p;
  END Add;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  CONST
    numOpcodes = Opcode.lastOpcode+1;
    numSubclasses = Opcode.scReal64+1;
  VAR
    pList, worklist: Partition;
    opcodes: ARRAY numOpcodes, numSubclasses OF Partition;
    i, j: LONGINT;
    instr: SSA.Instr;
    p: Partition;
    
  PROCEDURE AddPartition(): Partition;
    VAR
      p: Partition;
    BEGIN
      p := NewPartition();
      p. nextWorklist := worklist;
      worklist := p;
      p.inWorklist := TRUE;
      p. nextPartition := pList;
      pList := p;
      RETURN p;
    END AddPartition;

  PROCEDURE SplittedPartition (p: Partition; opndIndex: LONGINT;
                               VAR touchedList: Partition): Partition;
    VAR
      newList: ChildrenList;
      i, j: LONGINT;
      new: Partition;
    BEGIN
      (*ASSERT (opndIndex # p. ancestorOpnd);*)
      
      IF (opndIndex > p. ancestorOpnd) THEN
        (* locate the child for this operand; if there isn't one, create a
           new partition for this operand index *)
        i := 0;
        WHILE (p. splitChildren[i] # NIL) &
              (p. splitChildren[i]. ancestorOpnd # opndIndex) DO
          INC (i);
        END;
        
        IF (p. splitChildren[i] = NIL) THEN
          IF (i+1 = LEN (p. splitChildren^)) THEN
            NEW (newList, (i+1)*2);
            FOR j := 0 TO i DO
              newList[j] := p. splitChildren[j];
            END;
            p. splitChildren := newList;
          END;
          new := AddPartition();
          new. ancestor := p;
          new. ancestorOpnd := opndIndex;
          new. nextTouched := touchedList;
          touchedList := new;
          p. splitChildren[i] := new;
          p. splitChildren[i+1] := NIL;
          RETURN new;
        ELSE
          RETURN p. splitChildren[i];
        END;
        
      ELSE
        (* this operand index is not stored as a child of `p', because it
           would violate the invariant on the childrens' `ancestorIndex';
           delegate locating a partition for `opndIndex' to the ancestor,
           and then get the child for `p.ancestorOpnd' *) 
        new := SplittedPartition (p. ancestor, opndIndex, touchedList);
        RETURN SplittedPartition (new, p. ancestorOpnd, touchedList);
      END;
    END SplittedPartition;
  
  PROCEDURE Split (iList: ARRAY OF SSA.Result; size: LONGINT);
  (* Note: @oparam{iList} is an value parameter, so that the list of
     instructions does not change while we modify the partitions.  *)
    VAR
      i, nextResultCount: LONGINT;
      res: SSA.Result;
      use: SSA.Opnd;
      p, pUse, touched, originList, largest: Partition;
      
    PROCEDURE LargestChild(p: Partition; largest: Partition): Partition;
      VAR
        i: LONGINT;
      BEGIN
        IF (p.size > largest.size) THEN
          largest := p;
        END;
        
        i := 0;
        WHILE (p.splitChildren[i] # NIL) DO
          largest := LargestChild(p.splitChildren[i], largest);
          INC(i);
        END;
        RETURN largest;
      END LargestChild;

    BEGIN
      (* Iterate over the results in iList.  First over all results at position
         0, then over all existing results at position 1, and so on.  With each
         iteration, iList[0..size-1] holds the remaining results, with size
         shrinking to 0 in the last iteration.  *)
      WHILE (size # 0) DO
        touched := NIL;
        originList := NIL;
        nextResultCount := 0;
        FOR i := 0 TO size-1 DO
          res := iList[i];

          use := res. useList;
          WHILE (use # NIL) DO
            pUse := use.instr.info(Partition);
            IF (pUse.size > 1) OR
               (pUse.splitChildren[0] # NIL) OR
               (pUse.ancestor # NIL) THEN
              (* don't move instructions out of a partition that starts out
                 with a single instruction; intermediate partitions with a
                 size of one are handled as before *)

              IF pUse.splitted & (pUse.splitChildren[0] = NIL) THEN
                pUse.nextOrigin := originList;
                originList := pUse;
              END;
              
              p := SplittedPartition(pUse, use.OpndIndex(), touched);
              p.Add(use.instr);
            END;
            use := use. nextUse;
          END;
          
          IF (res. nextResult # NIL) THEN
            (* if there is a result after `res', then add it back into iList,
               to be tackled in the next iteration *)
            iList[nextResultCount] := res. nextResult;
            INC (nextResultCount);
          END;
        END;

        p := originList;
        WHILE (p # NIL) DO
          largest := LargestChild(p, p);
          IF (largest # p) THEN
            IF (p.size > 0) & ~p.inWorklist THEN
              p.nextWorklist := worklist;
              worklist := p;
              p.inWorklist := TRUE;
            END;
            p.splitted := FALSE;
            largest.splitted := TRUE;
          END;
          p := p.nextOrigin;
        END;
        
        (* reset data of touched partitions *)
        p := touched;
        WHILE (p # NIL) DO
          p. ancestor := NIL;
          p. ancestorOpnd := -1;
          p. splitChildren[0] := NIL;
          p := p. nextTouched;
        END;
        
        size := nextResultCount;
      END;
    END Split;

  PROCEDURE Replace (p: Partition);
    VAR
      dd: Blocker.DependenceData;
      i, j: LONGINT;
      iInstr, jInstr: SSA.Instr;

    PROCEDURE ReplaceInstrWith (x, y: SSA.Instr);
      VAR
        rx, ry: SSA.Result;
      BEGIN
        (*Log.Ptr ("  replacing instr", x);
        Log.Ptr ("  with instr", y);*)
        rx := x; ry := y;
        WHILE (rx # NIL) & (ry # NIL) DO
          rx. ReplaceUses (ry);
          rx := rx. nextResult; ry := ry. nextResult;
        END;
        (* the result lists must have the same length *)
        ASSERT (rx = NIL);
        ASSERT (ry = NIL);
      END ReplaceInstrWith;
    
    BEGIN
      dd := Blocker.GetDependenceData (pb);
      WHILE (p # NIL) DO
        IF (p. size > 1) THEN
          i := 0;
          WHILE (i # p. size) DO
            IF (p. iList[i] # NIL) THEN
              j := i+1;
              WHILE (j # p. size) DO
                IF (p. iList[j] # NIL) THEN
                  iInstr := p. iList[i](SSA.Instr);
                  jInstr := p. iList[j](SSA.Instr);
                  IF dd. AvailableTo (iInstr, jInstr) THEN
                    ReplaceInstrWith (jInstr, iInstr);
                    p. iList[j] := NIL;
                  ELSIF dd. AvailableTo (jInstr, iInstr) THEN
                    ReplaceInstrWith (iInstr, jInstr);
                    p. iList[i] := NIL;
                    j := p. size-1;      (* leave inner loop *)
                  END;
                END;
                INC (j);
              END;
            END;
            INC (i);
          END;
        END;
        p := p. nextPartition;
      END;
      Blocker.RemoveAntiDeps(pb);
    END Replace;
  
  BEGIN
    pb. SetMarkers (NIL, 0);
    FOR i := 0 TO numOpcodes-1 DO
      FOR j := 0 TO numSubclasses-1 DO
        opcodes[i,j] := NIL;
      END;
    END;
    worklist := NIL;
    pList := NIL;

    (* create initial partitions for opcodes and constant instructions;
       add partitions to worklist *)
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF instr. IsConst() OR instr. UniqueResult() THEN
        (* the instruction is a constant value or a unique result, and the
           instruction is therefore only equivalent to itself  *)
        p := AddPartition();
      ELSE
        p := opcodes[instr.opcode, instr.subclass];
        IF (p = NIL) THEN
          p := AddPartition();
          opcodes[instr. opcode, instr.subclass] := p;
        END;
      END;
      p. Add(instr);
      instr := instr. nextInstr;
    END;

    WHILE (worklist # NIL) DO
      p := worklist;
      p.inWorklist := FALSE;
      worklist := worklist. nextWorklist;
      IF ~p. splitted THEN
        p. splitted := TRUE;
        Split (p. iList^, p. size);
      END;
    END;

(*    Blocker.Write (StdChannels.stdout, pb);
    p := pList;
    WHILE (p # NIL) DO
      IF (p. size > 1) THEN
        Log.LongInt ("p.size", p. size);
        p. iList[0](SSA.Instr). LogOpcode ("  instr1");
        FOR i := 0 TO p. size-1 DO
          Log.Ptr ("  adr", p. iList[i]);
        END;
      END;
      p := p. nextPartition;
    END;*)

    Replace (pList);
  END Transform;
  
END OOC:SSA:CSE.
