(* 	$Id$	 *)
MODULE OOC:SSA:LoopRewrite;
(*  Reassociation and strength reduction within loops.
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

IMPORT
  SYSTEM, Err, Log,
  Object, ADT:Dictionary, ADT:ArrayList,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result;

CONST
  notVisited = 0;
  visited = 1;

CONST
  loopInvariant = 1;
  forwardInductive = 2;
  bottom = 3;
  
TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
  END;

TYPE
  Sum = POINTER TO SumDesc;
  Factors = POINTER TO ARRAY OF Sum;
  (* List of loop-invariant or constant values.  Sorted by ascending
     @ofield{Sum.id}.  *)
  Product = POINTER TO ProductDesc;
  ProductDesc = RECORD
    magnitude: LONGINT;
    (* Number of times this product contributes to the overall sum.  If
       negative, then its value is subtracted.  *)
    factors: Factors;
  END;
  PList = POINTER TO PListDesc;
  PListDesc = RECORD
    (* Summation of products.  The elements are sorted by ascending number of
       factors, and then lexicographically based on their factors' ids.  *)
    prod: POINTER TO ARRAY OF Product;
    size: LONGINT;
  END;
  
TYPE
  SumDesc = RECORD
    (SSA.NodeDesc)
    subclass: Opcode.Subclass;
    instr: SSA.Instr;
    (* For atomic values (constant, loop-invariant, or ``others'') this refers
       to the instruction that represents this value in the SSA form.  For all
       other values, this field is NIL.  *)
    id: LONGINT;
    (* If `instr' is non-NIL, this is an unique identifier for the result.
       It is used for normalization purposes.  *)
    
    head: SSA.Result;     (* head of induction cycle; a result of loop-start *)
    headFactor: PList;    (* loop invariant multiple of `head' *)
    loopInvariant: PList; (* loop invariant but non constant part of the sum *)
    constant: PList;      (* constant part of the sum *)
    others: PList;        (* the opaque rest of the computation *)

    replacement: SSA.Result;
  END;

TYPE
  CycleElement = POINTER TO CycleElementDesc;
  CycleElementDesc = RECORD
    next: CycleElement;
    res: SSA.Result;
  END;
  RewrittenCycle = POINTER TO RewrittenCycleDesc;
  RewrittenCycleDesc = RECORD
    next: RewrittenCycle;
    origin: Sum;
    a: SSA.Instr;   (* factor applied to the induction head, or NIL *)
    b: SSA.Instr;   (* loop-invariant but not constant offset, or NIL *)
    newHead: SSA.Result;  (* induction head of the rewritten cycle *)
  END;
  InductionCycle = POINTER TO InductionCycleDesc;
  InductionCycleDesc = RECORD
    (SumDesc)
    cycleElements: CycleElement;
    (* List of instructions that make up the cycle.  First entry is the
       induction head, followed by instructions that depend on it.  In general,
       a definition precedes any uses of it in the cycle.  *)
    rewrittenCycles: RewrittenCycle;
  END;
  
CONST
  zero = NIL;
  
VAR
  one: PList;
  idCount: LONGINT;
  
PROCEDURE InitSum(sum: Sum; subclass: Opcode.Subclass;
                  instr: SSA.Instr; id: LONGINT);
  BEGIN
    SSA.InitNode(sum);
    sum.subclass := subclass;
    sum.instr := instr;
    sum.id := id;
    
    sum.head := NIL;
    sum.headFactor := zero;
    sum.loopInvariant := zero;
    sum.constant := zero;
    sum.others := zero;

    sum.replacement := NIL;
  END InitSum;

PROCEDURE Classify(pb: SSA.ProcBlock; loopStart: SSA.Instr);
  VAR
    worklist: Worklist;
    instr: SSA.Instr;
    res: SSA.Result;

  PROCEDURE AddToWorklist (instr: SSA.Instr);
  (* pre-cond: one of the arguments is not loopInvariant *)
    VAR
      wl: Worklist;
    BEGIN
      IF (instr.marker > 0) THEN  (* not in worklist yet? *)
        instr. marker := -instr.marker;
        
        NEW (wl);
        wl. next := worklist;
        wl. instr := instr;
        worklist := wl;
      END;
    END AddToWorklist;
  
  PROCEDURE ^ SetMarker(res: SSA.Result; newMarker: LONGINT);
    
  PROCEDURE SetMarkers(instr: SSA.Instr; newMarker: LONGINT);
  (* Call SetMarker() for every result of `instr'.  *)
    VAR
      res: SSA.Result;
    BEGIN
      res := instr;
      WHILE (res # NIL) DO
        SetMarker(res, newMarker);
        res := res.nextResult;
      END;
    END SetMarkers;
  
  PROCEDURE SetMarker(res: SSA.Result; newMarker: LONGINT);
    PROCEDURE AddUsesToWorklist (res: SSA.Result);
      VAR
        use: SSA.Opnd;
        useInstr, gate: SSA.Instr;
        out: SSA.Result;
      BEGIN
        use := res. useList;
        WHILE (use # NIL) DO
          useInstr := use. instr;
          IF (useInstr.opcode = Opcode.collect) THEN
            (* don't add collect instructions to worklist, instead recalculate
               the label of the gate instruction (select, loop-start, or
               loop-end) to which the collect passes its result *)
            SetMarkers(useInstr, bottom);
            gate := useInstr.GetCollectTarget();
            out := gate.NthResult(use.OpndIndex()+1);
            IF (ABS(res.marker) >= ABS(out.marker)) THEN
              SetMarker(out, ABS(res.marker));
            END;
          ELSE
            AddToWorklist (useInstr);
          END;
          use := use. nextUse;
        END;
      END AddUsesToWorklist;
    
    BEGIN
      ASSERT(newMarker >= ABS(res.marker));
      IF (newMarker # ABS(res.marker)) THEN
        IF (res.marker < 0) THEN  (* preserve `in worklist' mark *)
          res.marker := -newMarker;
        ELSE
          res.marker := newMarker;
        END;
        AddUsesToWorklist(res);
      END;
    END SetMarker;

  PROCEDURE ClassifyInstr(instr: SSA.Instr);
    VAR
      marker: LONGINT;
    BEGIN
      IF (instr.opcode = Opcode.add) OR (instr.opcode = Opcode.subtract) THEN
        marker := ABS(instr.opndList.nextOpnd.arg.marker);
        IF (ABS(instr.opndList.arg.marker) > marker) THEN
          marker := ABS(instr.opndList.arg.marker);
        END;
        SetMarkers(instr, marker);
      ELSE  (* one of the arguments is not loopInvariant *)
        SetMarkers(instr, bottom);
      END;
    END ClassifyInstr;
  
  BEGIN
    pb.SetMarkers(NIL, loopInvariant);
    worklist := NIL;

    (* mark all result of "loop-start" as forward inductive *)
    res := loopStart;
    WHILE (res # NIL) DO
      SetMarker(res, forwardInductive);
      res := res.nextResult;
    END;
    
    (* repeat until worklist is empty *)
    WHILE (worklist # NIL) DO
      instr := worklist. instr;
      ASSERT(instr.marker < 0);
      instr.marker := -instr.marker;
      worklist := worklist. next;
      ClassifyInstr (instr);
    END;
  END Classify;

PROCEDURE FindInductiveCycles*(loopStart: SSA.Instr);
(* Locate inductive cycles.  For every cycle, install an instance of
   InductionCycle in the loop-start's result that is its head.  *)
  VAR
    count: LONGINT;
    loopEnd: SSA.Instr;
    res: SSA.Result;
    opnd: SSA.Opnd;
    ic: InductionCycle;
    cyclic: BOOLEAN;

  PROCEDURE NewInductionCycle(head: SSA.Result): InductionCycle;
    VAR
      ic: InductionCycle;
    BEGIN
      NEW(ic);
      InitSum(ic, head.subclass, NIL, 0);
      ic.head := head;
      ic.headFactor := one;
      ic.cycleElements := NIL;
      ic.rewrittenCycles := NIL;
      RETURN ic;
    END NewInductionCycle;

  PROCEDURE AddInductionValue(ic: InductionCycle; res: SSA.Result);
    VAR
      ce: CycleElement;
    BEGIN
      NEW(ce);
      ce.next := ic.cycleElements;
      ce.res := res;
      ic.cycleElements := ce;
      Log.Ptr("AddInductionValue", res.instr);
    END AddInductionValue;
  
  PROCEDURE SearchCycle(res, head: SSA.Result; ic: InductionCycle;
                        VAR cyclic: BOOLEAN);
    VAR
      opnd: SSA.Opnd;
      opndCyclic: BOOLEAN;
    BEGIN
      IF (res = head) THEN
        cyclic := TRUE;
      ELSIF (res.marker = forwardInductive) THEN
        opnd := res.instr.opndList;
        WHILE (opnd # NIL) DO
          opndCyclic := FALSE;
          SearchCycle(opnd.arg, head, ic, opndCyclic);
          cyclic := cyclic OR opndCyclic;
          opnd := opnd.nextOpnd;
        END;
        IF cyclic THEN
          AddInductionValue(ic, res);
        END;
      END;
    END SearchCycle;
  
  BEGIN
    loopEnd := loopStart.GetLoopEnd();

    count := 1;
    res := loopStart.NthResult(2);
    WHILE (res # NIL) DO
      IF (res.marker = forwardInductive) THEN
        ic := NewInductionCycle(res);
        ASSERT(loopEnd.opndList.nextOpnd.arg.instr.opcode = Opcode.collect);
        opnd := loopEnd.opndList.nextOpnd.arg.instr.NthOpnd(count);
        cyclic := FALSE;
        SearchCycle(opnd.arg, res, ic, cyclic);
        IF cyclic THEN
          res.info := ic;
          AddInductionValue(ic, res);
        END;
      END;
      res := res.nextResult;
      INC(count);
    END;
  END FindInductiveCycles;

PROCEDURE Cmp(a, b: Product): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    IF (LEN(a.factors^) = LEN(b.factors^)) THEN
      i := 0;
      WHILE (i # LEN(a.factors^)) DO
        IF (a.factors[i].id # b.factors[i].id) THEN
          RETURN (a.factors[i].id - b.factors[i].id);
        ELSE
          INC(i);
        END;
      END;
      RETURN 0;
    ELSE
      RETURN (LEN(a.factors^) - LEN(b.factors^));
    END;
  END Cmp;

PROCEDURE Flatten*(res: SSA.Result);
  VAR
    instr: SSA.Instr;
    sum: Sum;
    opnd: SSA.Opnd;
    
  PROCEDURE NewSum(subclass: Opcode.Subclass; instr: SSA.Instr): Sum;
    VAR
      sum: Sum;
    BEGIN
      NEW(sum);
      IF (instr # NIL) THEN
        InitSum(sum, subclass, instr, idCount);
        INC(idCount);
      ELSE
        InitSum(sum, subclass, NIL, 0);
      END;
      RETURN sum;
    END NewSum;

  PROCEDURE AddSum(a, b: Sum; magnB: LONGINT): Sum;
    VAR
      sum: Sum;
      subclass: Opcode.Subclass;

    PROCEDURE AddPLists(a, b: PList): PList;
      VAR
        p: PList;
        i, ia, ib: LONGINT;
      BEGIN
        IF (a = zero) THEN
          RETURN b;
        ELSIF (b = zero) THEN
          RETURN a;
        ELSE
          NEW(p);
          NEW(p.prod, a.size+b.size);
          i := 0; ia := 0; ib := 0;
          WHILE (ia # a.size) OR (ib # b.size) DO
            IF (ib = b.size) OR (Cmp(a.prod[ia], b.prod[ib]) < 0) THEN
              p.prod[i] := a.prod[ia];
              INC(i); INC(ia);
            ELSIF (ia = a.size) OR (Cmp(a.prod[ia], b.prod[ib]) > 0) THEN
              p.prod[i] := b.prod[ib];
              p.prod[i].magnitude := p.prod[i].magnitude * magnB;
              INC(i); INC(ib);
            ELSE  (* Cmp() = 0 *)
              p.prod[i] := a.prod[ia];
              INC(p.prod[i].magnitude, b.prod[ib].magnitude * magnB);
              INC(i); INC(ia); INC(ib);
            END;
          END;
          p.size := i;
          RETURN p;
        END;
      END AddPLists;
    
    BEGIN
      (* ideally, the subclasses of both sides are the same; until then... *)
      subclass := a.subclass;
      IF (b.subclass > subclass) THEN
        subclass := b.subclass;
      END;
      
      NEW(sum);
      InitSum(sum, subclass, NIL, 0);
      IF (a.headFactor = zero) THEN
        sum.head := b.head;
        sum.headFactor := b.headFactor;
      ELSIF (b.headFactor = zero) THEN
        sum.head := a.head;
        sum.headFactor := a.headFactor;
      ELSE
        ASSERT(a.head = b.head);
        sum.head := a.head;
        sum.headFactor := AddPLists(a.headFactor, b.headFactor);
      END;
      sum.loopInvariant := AddPLists(a.loopInvariant, b.loopInvariant);
      sum.constant := AddPLists(a.constant, b.constant);
      sum.others := AddPLists(a.others, b.others);
      RETURN sum;
    END AddSum;

  PROCEDURE NewPList(factor: Sum): PList;
    VAR
      plist: PList;
    BEGIN
      NEW(plist);
      plist.size := 1;
      NEW(plist.prod, 1);
      NEW(plist.prod[0]);
      plist.prod[0].magnitude := 1;
      NEW(plist.prod[0].factors, 1);
      plist.prod[0].factors[0] := factor;
      RETURN plist;
    END NewPList;
  
  BEGIN
    IF (res.info # NIL) THEN
      (* been here, done it *)
    ELSIF ~(res IS SSA.Instr) THEN
      (* we are only interested in the instruction itself *)
    ELSE
      instr := res(SSA.Instr);
      IF (instr.marker = loopInvariant) THEN
        WITH instr: SSA.Const DO
          sum := NewSum(instr.subclass, instr);
          sum.constant := NewPList(sum);
        ELSE  (* non-constant loop-invariant value *)
          sum := NewSum(instr.subclass, instr);
          sum.loopInvariant := NewPList(sum);
        END;
        instr.info := sum;
        
      ELSE
        opnd := instr.opndList;
        WHILE (opnd # NIL) DO
          Flatten(opnd.arg.instr);
          opnd := opnd.nextOpnd;
        END;
        
        IF (instr.opcode = Opcode.add) THEN
          instr.info := AddSum(instr.opndList.arg.info(Sum),
                               instr.opndList.nextOpnd.arg.info(Sum), 1);
        ELSIF (instr.opcode = Opcode.subtract) THEN
          instr.info := AddSum(instr.opndList.arg.info(Sum),
                               instr.opndList.nextOpnd.arg.info(Sum), -1);
        END;
        IF (instr.info = NIL) THEN
          sum := NewSum(instr.subclass, instr);
          sum.others := NewPList(sum);
          instr.info := sum;
        END;
      END;
    END;
  END Flatten;

PROCEDURE Rewrite(pb: SSA.ProcBlock; sum: Sum);
  VAR
    ic: InductionCycle;
    rc: RewrittenCycle;
    loopStart, loopEnd, collect: SSA.Instr;
    res: SSA.Result;
    replacement: Dictionary.Dictionary;

  PROCEDURE Expr(plist: PList; subclass: Opcode.Subclass): SSA.Instr;
    VAR
      i: LONGINT;
      res, instr, add: SSA.Instr;

    PROCEDURE Multiply(m: LONGINT; f: Factors): SSA.Instr;
      VAR
        i: LONGINT;
        res, mult: SSA.Instr;
      BEGIN
        res := f[0].instr;
        FOR i := 0 TO LEN(f^)-1 DO
          mult := pb.AddInstr(Opcode.multiply, subclass);
          mult.AddOpnd(res, Opnd.arg);
          mult.AddOpnd(f[i].instr, Opnd.arg);
          res := mult;
        END;
        IF (m # 1) THEN
          mult := pb.AddInstr(Opcode.multiply, subclass);
          mult.AddOpnd(res, Opnd.arg);
          mult.AddOpnd(pb.GetConstInt(m), Opnd.arg);
          res := mult;
        END;
        RETURN res;
      END Multiply;
    
    BEGIN
      ASSERT(plist.size > 0);
      res := Multiply(plist.prod[0].magnitude, plist.prod[0].factors);
      FOR i := 1 TO plist.size-1 DO
        instr := Multiply(plist.prod[i].magnitude, plist.prod[i].factors);
        add := pb.AddInstr(Opcode.add, subclass);
        add.AddOpnd(res, Opnd.arg);
        add.AddOpnd(instr, Opnd.arg);
        res := add;
      END;
      RETURN res;
    END Expr;

  PROCEDURE InitialValue(rc: RewrittenCycle; initOld: SSA.Result): SSA.Result;
    VAR
      res: SSA.Result;
      instr: SSA.Instr;
    BEGIN
      res := initOld;

      IF (rc.a # NIL) THEN
        instr := pb.AddInstr(Opcode.multiply, sum.subclass);
        instr.AddOpnd(res, Opnd.arg);
        instr.AddOpnd(rc.a, Opnd.arg);
        res := instr;
      END;

      IF (rc.b # NIL) THEN
        instr := pb.AddInstr(Opcode.add, sum.subclass);
        instr.AddOpnd(res, Opnd.arg);
        instr.AddOpnd(rc.b, Opnd.arg);
        res := instr;
      END;

      RETURN res;
    END InitialValue;

  PROCEDURE RewriteCycle(rc: RewrittenCycle; ce: CycleElement): SSA.Result;
    VAR
      ci, mult, instr: SSA.Instr;
      iv, ni, res, mres: SSA.Result;
      obj: Object.Object;
    BEGIN
      ci := ce.res.instr;
      CASE ci.opcode OF
      | Opcode.add:
        iv := ci.opndList.arg;           (* induction value *)
        ni := ci.opndList.nextOpnd.arg;  (* non-induction *)
        IF replacement.HasKey(ni) THEN   (* oops, got that backward *)
          res := iv; iv := ni; ni := res;
        END;
        ASSERT(replacement.HasKey(iv));

        obj := replacement.Get(iv);
        res := obj(SSA.Result);
        IF (rc.a # NIL) THEN
          mult := pb.AddInstr(Opcode.multiply, sum.subclass);
          mult.AddOpnd(ni, Opnd.arg);
          mult.AddOpnd(rc.a, Opnd.arg);
          mres := mult;
        ELSE
          mres := ni;
        END;
        
        instr := pb.AddInstr(Opcode.add, sum.subclass);
        instr.AddOpnd(res, Opnd.arg);
        instr.AddOpnd(mres, Opnd.arg);
        res := instr;
        replacement.Set(ce.res, res);
      END;
      
      IF (ce.next # NIL) THEN
        res := RewriteCycle(rc, ce.next);
      END;
      RETURN res;
    END RewriteCycle;

  PROCEDURE ComputeReplacement(rc: RewrittenCycle; sum: Sum): SSA.Result;
    VAR
      res: SSA.Result;
      instr: SSA.Instr;
    BEGIN
      res := rc.newHead;

      IF (sum.others # zero) THEN
        instr := pb.AddInstr(Opcode.add, sum.subclass);
        instr.AddOpnd(res, Opnd.arg);
        instr.AddOpnd(Expr(sum.others, sum.subclass), Opnd.arg);
        res := instr;
      END;

      IF (sum.constant # zero) THEN
        instr := pb.AddInstr(Opcode.add, sum.subclass);
        instr.AddOpnd(res, Opnd.arg);
        instr.AddOpnd(Expr(sum.constant, sum.subclass), Opnd.arg);
        res := instr;
      END;

      RETURN res;
    END ComputeReplacement;

  PROCEDURE EqualAB(sum1, sum2: Sum): BOOLEAN;
    PROCEDURE EqualPList(p1, p2: PList): BOOLEAN;
      VAR
        i1, i2: LONGINT;

      PROCEDURE EqualFactors(f1, f2: Factors): BOOLEAN;
        VAR
          i: LONGINT;
        BEGIN
          IF (LEN(f1^) # LEN(f2^)) THEN
            RETURN FALSE;
          ELSE
            FOR i := 0 TO LEN(f1^)-1 DO
              IF (f1[i].instr # f2[i].instr) THEN
                RETURN FALSE;
              END;
            END;
            RETURN TRUE;
          END;
        END EqualFactors;
      
      BEGIN
        i1 := 0; i2 := 0;
        WHILE (i1 # p1.size) & (i2 # p2.size) DO
          IF (p1.prod[i1].magnitude = 0) THEN
            INC(i1);
          ELSIF (p2.prod[i2].magnitude = 0) THEN
            INC(i2);
          ELSIF (p1.prod[i1].magnitude # p2.prod[i2].magnitude) OR
                ~EqualFactors(p1.prod[i1].factors, p2.prod[i2].factors) THEN
            RETURN FALSE;
          ELSE
            INC(i1); INC(i2);
          END;
        END;
        RETURN TRUE;
      END EqualPList;
    
    BEGIN
      RETURN EqualPList(sum1.headFactor, sum2.headFactor) &
          EqualPList(sum1.loopInvariant, sum2.loopInvariant);
    END EqualAB;
  
  BEGIN
    Log.Msg("XXX");

    ic := sum.head.info(InductionCycle);
    rc := ic.rewrittenCycles;
    WHILE (rc # NIL) & ~EqualAB(sum, rc.origin) DO
      Log.Msg("  ...");
      rc := rc.next;
    END;
    IF (rc = NIL) THEN
      Log.Msg("  ---");
      NEW(rc);
      rc.next := ic.rewrittenCycles;
      ic.rewrittenCycles := rc;
      rc.origin := sum;
      
      IF (sum.headFactor # one) THEN
        rc.a := Expr(sum.headFactor, sum.subclass);
      ELSE
        rc.a := NIL;
      END;
      IF (sum.loopInvariant # zero) THEN
        rc.b := Expr(sum.loopInvariant, sum.subclass);
      ELSE
        rc.b := NIL;
      END;
      
      (* calculate the initial value of the rewritten cycle and add it to the
         collect instruction in front of the loop *)
      loopStart := sum.head.instr;
      collect := loopStart.opndList.arg.instr;
      res := InitialValue(rc, collect.NthArg(sum.head.ResultIndex()-1));
      collect.AddOpnd(res, Opnd.arg);
      
      (* add result as gate output to loopStart, and register it in the
         replacement dictionary *)
      replacement := Dictionary.New();
      res := loopStart.AddResultSubclass(Result.selectValue, sum.subclass);
      replacement.Set(sum.head, res);
      rc.newHead := res;
      
      (* rewrite all other elements in the induction cycle *)
      IF (ic.cycleElements.next # NIL) THEN
        res := RewriteCycle(rc, ic.cycleElements.next);
      END;
      
      (* add final value of the induction cycle to the back-edge collect *)
      loopEnd := loopStart.GetLoopEnd();
      collect := loopEnd.opndList.nextOpnd.arg.instr;
      collect.AddOpnd(res, Opnd.arg);
    END;


    (* compute replacement for `origInstr', and register it with `sum' *)
    sum.replacement := ComputeReplacement(rc, sum);
  END Rewrite;

PROCEDURE DumpSums(pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
    sum: Sum;

  PROCEDURE Res(res: SSA.Result);
    VAR
      ptr: LONGINT;
    BEGIN
      ptr := SYSTEM.VAL(LONGINT, res.instr);
      Err.Hex(ptr, 8);
      IF (res # res.instr) THEN
        Err.Char(".");
        Err.LongInt(res.ResultIndex(), 0);
      END;
    END Res;

  PROCEDURE E(plist: PList);
    VAR
      i, j, m: LONGINT;
      instr: SSA.Instr;
    BEGIN
      IF (plist = zero) THEN
        Err.Char("0");
      ELSIF (plist.size = 0) THEN
        Err.Char("1");
      ELSE
        FOR i := 0 TO plist.size-1 DO
          m := plist.prod[i].magnitude;
          IF (m >= 0) & (i # 0) THEN
            Err.Char("+");
          END;
          IF (m # 1) THEN
            Err.LongInt(m, 0);
            Err.Char("*");
          END;
          FOR j := 0 TO LEN(plist.prod[i].factors^)-1 DO
            instr := plist.prod[i].factors[j].instr;
            WITH instr: SSA.Const DO
              Err.Object(instr.value.ToString());
            ELSE
              Res(instr);
            END;
          END;
        END;
      END;
    END E;
  
  BEGIN
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      IF (instr.info # NIL) THEN
        sum := instr.info(Sum);

        Res(instr);
        Err.String(": ind(");
        IF (sum.headFactor # zero) THEN
          Res(sum.head);
          Err.Char("*");
          E(sum.headFactor);
        END;
        Err.String(")+li(");
        E(sum.loopInvariant);
        Err.String(")+c(");
        E(sum.constant);
        Err.String(")+o(");
        E(sum.others);
        Err.String(")");
        Err.Ln;
      END;
      instr := instr.nextInstr;
    END;
  END DumpSums;

PROCEDURE Transform*(pb: SSA.ProcBlock);
  VAR
    loops: ArrayList.ArrayList;
    loopStart, loopEnd, instr: SSA.Instr;
    opnd: SSA.Opnd;
    i: LONGINT;
    
  PROCEDURE EnumerateLoops(storeOut: SSA.Result; firstInstr: SSA.Instr);
    VAR
      instr, loopStart: SSA.Instr;
      opnd: SSA.Opnd;
    BEGIN
      IF (storeOut.marker = notVisited) THEN
        storeOut.marker := visited;
        
        WHILE (storeOut.instr # firstInstr) DO
          instr := storeOut.instr;
          CASE instr.opcode OF
          | Opcode.loopEnd:
            loopStart := instr.opndList.arg(SSA.Instr);
            EnumerateLoops(instr.opndList.nextOpnd.arg, loopStart);
            storeOut := loopStart.opndList.arg;
            loops.Append(loopStart);
            
          | Opcode.select:
            opnd := instr.opndList.nextOpnd;
            WHILE (opnd # NIL) & (opnd.class = Opnd.arg) DO
              opnd := opnd.nextOpnd;
              EnumerateLoops(opnd.arg, firstInstr);
              opnd := opnd.nextOpnd;
            END;
            storeOut := firstInstr;      (* abort loop *)
            
          ELSE
            storeOut := instr.GetArgStore();
            ASSERT(storeOut # NIL)
          END;
        END;
      END;
    END EnumerateLoops;

  PROCEDURE DumpMarker(marker: LONGINT);
    VAR
      instr: SSA.Instr;
    BEGIN
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        IF (ABS(instr.marker) = marker) THEN
          Log.Ptr("instr", instr);
        END;
        instr := instr.nextInstr;
      END;
    END DumpMarker;
  
  BEGIN
    (* enumerate loops in post order *)
    pb. SetMarkers (NIL, notVisited);
    loops := ArrayList.New(4);
    EnumerateLoops(pb.selectReturn.GetArgStore(), pb.GetEnter());

    idCount := 0;
    i := 0;
    WHILE (i # loops.size) DO
      loopStart := loops.array[i](SSA.Instr);
      
      (* classify instructions as loopInvariant, forwardInductive, or bottom
         with regard to loop *)
      Classify(pb, loopStart);
      
      (* locate inductive cycles in loop *)
      FindInductiveCycles(loopStart);

      (* calculate alternative representations of addition, subtraction, and
         multiplication instructions *)
      loopEnd := loopStart.GetLoopEnd();
      opnd := loopEnd.opndList;
      WHILE (opnd # NIL) DO
        Flatten(opnd.arg.instr);
        opnd := opnd.nextOpnd;
      END;

      (* find all instructions that are computed through a sum involving the
         head of an induction cycle *)
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        (* since we are traversing instructions, we do not hit on the induction
           head themselves, which are additional results of loop-start *)
        IF (instr.info # NIL) &
           (instr.info(Sum).head # NIL) &
           (instr.info(Sum).loopInvariant # zero) THEN
          Rewrite(pb, instr.info(Sum));
        END;
        instr := instr.nextInstr;
      END;
      
      (* replace instructions with their tediously computed equivalents *)
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        IF (instr.info # NIL) & (instr.info(Sum).replacement # NIL) THEN
          Log.Ptr("replacing", instr);
          Log.Ptr("  with", instr.info(Sum).replacement);
          instr.ReplaceUses(instr.info(Sum).replacement);
        END;
        instr := instr.nextInstr;
      END;
      
      INC(i);
    END;

    Log.Msg("loopInvariant");
    DumpMarker(loopInvariant);
    Log.Msg("forwardInductive");
    DumpMarker(forwardInductive);
    (*Log.Msg("bottom");
    DumpMarker(bottom);*)
    DumpSums(pb);
  END Transform;

BEGIN
  NEW(one);
  NEW(one.prod, 0);
  one.size := 0;
END OOC:SSA:LoopRewrite.
