(* 	$Id: LoopRewrite.Mod,v 1.20 2003/03/12 19:06:06 mva Exp $	 *)
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

<*DEFINE OOC_DEBUG_LOOP_REWRITE := FALSE*>

IMPORT
<*IF OOC_DEBUG_LOOP_REWRITE THEN*>  
  SYSTEM, Err, Log, OOC:SSA:Blocker, IO:StdChannels,
<*END*>  
  Object, Object:BigInt, ADT:Dictionary, ADT:ArrayList,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result;

CONST
  dangerous = FALSE;
  (* Enable all dangerous transformations that may change program
     behaviour.  *)
  dangerousAdr = TRUE;
  (* Enable all dangerous tranformations for address calculations only.  Has
     no effect if `dangerous' is TRUE.  *)
  
(* Possible extension: Instead of Sum being a function of one
   induction variable, it could be extended to cover an arbitrary
   number of variables.  For this, (ce,ceFactor) needs to be
   replaced with a list of such tuples.  *)

CONST
  notVisited = 0;
  visited = 1;

CONST
  loopInvariant = 1;
  forwardInductive = 2;
  bottom = 3;
  initMarker = SSA.initMarker;
  
TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
    (* For an instruction to be in the worklist, at least one argument must
       be not marked as loopInvariant.  *)
  END;

TYPE
  Sum = POINTER TO SumDesc;
  Factors = POINTER TO ARRAY OF Sum;
  (* List of loop-invariant, constant, or ``other'' values.  Sorted by
     ascending @ofield{Sum.id}.  For every element of this array,
     @ofield{Sum.atom} is not @code{NIL}.  *)
  Product = POINTER TO ProductDesc;
  ProductDesc = RECORD
    magnitude: LONGINT;
    (* Number of times this product contributes to the overall sum.  If
       negative, then its value is subtracted.  *)
    factors: Factors;
    (* List of atomic values that make up the product.  An array of length
       zero means `1'.  *)
  END;
  PList = POINTER TO PListDesc;
  PListDesc = RECORD
    (* Summation of products.  The elements are sorted by ascending number of
       factors, and then lexicographically based on their factors' ids.
       A `size' means that the PList is `0'.  *)
    prod: POINTER TO ARRAY OF Product;
    size: LONGINT;
  END;
  
TYPE
  CycleElement = POINTER TO CycleElementDesc;
  SumDesc = RECORD
    (SSA.NodeDesc)
    subclass: Opcode.Subclass;
    (* Subclass of the result produced by this sum.  Any summation operand
       that is not of this type needs to be converted to it.  *)
    atom: SSA.Result;
    (* For atomic values (constant, loop-invariant, or ``others'') this refers
       to the instruction that represents this value in the SSA form.  For all
       other values, this field is NIL.  *)
    id: LONGINT;
    (* If `atom' is non-NIL, this is an unique identifier for the result.
       It is used for normalization purposes.  *)
    replacementCandidate: BOOLEAN;
    (* If TRUE, then the instruction that corresponds to this sum is scheduled
       for replacement by a new induction cycle.  *)
       
    ce: CycleElement;     (* element of induction cycle*)
    ceFactor: PList;      (* loop invariant multiple of `ce' *)
    loopInvariant: PList; (* loop invariant but non constant part of the sum *)
    constant: PList;      (* constant part of the sum *)
    others: PList;        (* the opaque rest of the computation *)

    replacement: SSA.Result;
    useClass: SHORTINT;
    reconstruct: SSA.Result;
  END;

CONST
  useOutsideLoop = 0;
  (* This use happens outside the loop.  *)
  useIndirectOutsideLoop = 1;
  (* Use contributes to an instruction that is outside the loop.  *)
  useReplacementCandidate = 2;
  (* This use constributes only to instructions that are scheduled for
     replacement.  *)
  useReplacementCode = 3;
  (* Use is part of newly added replacement code.  *)
  useInCycleElement = 3;
  (* Use happens in a cycle element of the same induction cycle.  *)
  useBackedgeValue = 4;
  (* Use feeds the value back to the beginning of the loop.  *)
  maxUseId = useBackedgeValue;
  
TYPE
  InductionCycle = POINTER TO InductionCycleDesc;
  CycleElementDesc = RECORD
    (* For every element in a cycle, at least one of the argument for
       @ofield{res} is either the induction head, or another element of the
       cycle.  *)
    (SumDesc)
    next: CycleElement;
    (* List of instructions that make up the cycle.  First entry is the
       induction head, followed by instructions that depend on it.  In general,
       a definition precedes any uses of it in the cycle.  *)
    res: SSA.Result;
    pos: LONGINT;
    (* Unique id of the element, a non-negative number less than
       @ofield{InductionCycle.cycleLength}.  The cycle head has id `0',
       the result at the end of the cycle `cycleLength-1'.  *)
    ic: InductionCycle;
    useCount: ARRAY maxUseId+1 OF LONGINT;
  END;
  RewrittenCycle = POINTER TO RewrittenCycleDesc;
  RewrittenCycleDesc = RECORD
    next: RewrittenCycle;
    origin: Sum;
    a: SSA.Result;   (* factor applied to the induction head, or NIL *)
    b: SSA.Result;   (* loop-invariant but not constant offset, or NIL *)
    replacements: POINTER TO ARRAY OF SSA.Result;
    (* Element at index @ofield{CycleElement.id} holds the replementent
       expression for the main cycle's element within this rewritten
       cycle.  @samp{replacements[0]} holds the head of the new induction
       cycle.  *)
  END;
  InductionCycleDesc = RECORD
    (CycleElementDesc)
    cycleLength: LONGINT;
    rewrittenCycles: RewrittenCycle;
  END;
  
CONST
  zero = NIL;
  signUnknown = -2;
  signNotPositive = -1;  (* negative or zero *)
  signZero = 0;
  signNotNegative = 1;   (* positive or zero *)
  
VAR
  one: PList;
  idCount: LONGINT;
  
PROCEDURE InitSum(sum: Sum; subclass: Opcode.Subclass; atom: SSA.Result);
  BEGIN
    SSA.InitNode(sum);
    sum.subclass := subclass;
    sum.atom := atom;
    IF (atom # NIL) THEN
      sum.id := idCount;
      INC(idCount);
    ELSE
      sum.id := 0;
    END;
    
    sum.ce := NIL;
    sum.ceFactor := zero;
    sum.loopInvariant := zero;
    sum.constant := zero;
    sum.others := zero;

    sum.replacement := NIL;
    sum.replacementCandidate := FALSE;
    sum.useClass := -1;
  END InitSum;

PROCEDURE InitCycleElement(ce: CycleElement; ic: InductionCycle;
                           res: SSA.Result);
  VAR
    ptr: CycleElement;
    i: LONGINT;
  BEGIN
    InitSum(ce, res.subclass, res);

    (* set sum to ce*1+0 *)
    ce.ce := ce;
    ce.ceFactor := one;
    
    ce.next := NIL;
    ce.res := res;
    IF (ic = NIL) THEN
      ce.pos := 0;
      ce.ic := ce(InductionCycle);
    ELSE
      ce.ic := ic;
      ce.pos := ic.cycleLength;
      INC(ic.cycleLength);
      
      ptr := ic;
      WHILE (ptr.next # NIL) DO
        ptr := ptr.next;
      END;
      ptr.next := ce;
    END;

    FOR i := 0 TO maxUseId DO
      ce.useCount[i] := 0;
    END;
    ce.reconstruct := NIL;
  END InitCycleElement;

PROCEDURE InitInductionCycle(ic: InductionCycle; res: SSA.Result);
  BEGIN
    InitCycleElement(ic, NIL, res);
    ic.cycleLength := 1;    (* for starters, `ic' is the only cycle element *)
    ic.rewrittenCycles := NIL;
  END InitInductionCycle;


<*IF OOC_DEBUG_LOOP_REWRITE THEN*>
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

PROCEDURE LogSum(sum: Sum);
  PROCEDURE E(plist: PList);
    VAR
      i, j, m: LONGINT;
      instr: SSA.Result;
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
            instr := plist.prod[i].factors[j].atom;
            IF (j # 0) THEN Err.Char("*") END;
            IF (instr = NIL) THEN
              Err.String("<NIL>");
            ELSE
              WITH instr: SSA.Const DO
                Err.Object(instr.value.ToString());
              ELSE
                Res(instr);
              END;
            END;
          END;
        END;
      END;
    END E;
  
  BEGIN
    IF (sum = NIL) THEN
      Err.String("<NIL>");
    ELSE
      Err.String("ce(");
      IF (sum.ceFactor # zero) THEN
        Res(sum.ce.res);
        Err.Char("*");
        E(sum.ceFactor);
      END;
      Err.String(")+li(");
      E(sum.loopInvariant);
      Err.String(")+c(");
      E(sum.constant);
      Err.String(")+o(");
      E(sum.others);
      Err.String(")");
    END;
    Err.Ln;
  END LogSum;

PROCEDURE DumpSums(pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
  BEGIN
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      IF (instr.info # NIL) THEN
        Res(instr);
        Err.String(": ");
        LogSum(instr.info(Sum));
      END;
      instr := instr.nextInstr;
    END;
  END DumpSums;

PROCEDURE DumpCycle(ic: InductionCycle);
  VAR
    ce: CycleElement;
  BEGIN
    Log.Msg("### Inductive Cycle");
    ce := ic;
    WHILE (ce # NIL) DO
      Log.LongInt("ce.pos", ce.pos);
      Log.Ptr("  ce", ce);
      ce.res.LogId("  ce.res");
      Log.Ptr("  ce", ce);
      Log.Ptr("  ce.next", ce.next);
      ce := ce.next;
    END;
  END DumpCycle;
<*END*>  


PROCEDURE Classify(pb: SSA.ProcBlock; loopStart: SSA.Instr);
  VAR
    worklist: Worklist;
    instr: SSA.Instr;
    res: SSA.Result;

  PROCEDURE ^ UpdateMarker(res: SSA.Result; newMarker: LONGINT);
    
  PROCEDURE UpdateMarkers(instr: SSA.Instr; newMarker: LONGINT);
  (* Call UpdateMarker() for every result of `instr'.  *)
    VAR
      res: SSA.Result;
    BEGIN
      res := instr;
      WHILE (res # NIL) DO
        UpdateMarker(res, newMarker);
        res := res.nextResult;
      END;
    END UpdateMarkers;
  
  PROCEDURE UpdateMarker(res: SSA.Result; newMarker: LONGINT);
  (* If `newMarker' is larger than the current `res.marker', then update it
     and add all instructions that use `res' to the worklist.  *)
    VAR
      use: SSA.Opnd;
      useInstr: SSA.Instr;
      wl: Worklist;
    BEGIN
      ASSERT(newMarker > 0);
      IF (newMarker > ABS(res.marker)) THEN
        IF (res.marker < 0) THEN  (* preserve `in worklist' mark *)
          res.marker := -newMarker;
        ELSE
          res.marker := newMarker;
        END;

        use := res. useList;
        WHILE (use # NIL) DO
          useInstr := use. instr;
          IF (useInstr.marker > 0) THEN  (* not in worklist yet? *)
            useInstr.marker := -useInstr.marker;
            NEW (wl);
            wl.next := worklist;
            wl.instr := useInstr;
            worklist := wl;
          END;
          use := use. nextUse;
        END;
      END;
    END UpdateMarker;

  PROCEDURE ClassifyInstr(instr: SSA.Instr);
    VAR
      marker, min, max, m, opndIndex: LONGINT;
      res: SSA.Result;
      opnd, next: SSA.Opnd;
      gate: SSA.Instr;
    BEGIN
      CASE instr.opcode OF
      | Opcode.add, Opcode.subtract:
        marker := ABS(instr.opndList.nextOpnd.arg.marker);
        IF (ABS(instr.opndList.arg.marker) > marker) THEN
          marker := ABS(instr.opndList.arg.marker);
        END;
        UpdateMarkers(instr, marker);

      | Opcode.typeConv: (* interpret type-conv as identity or x+0 operation *)
        UpdateMarkers(instr, ABS(instr.opndList.arg.marker));

      | Opcode.collect:
        UpdateMarker(instr, bottom);
        UpdateMarker(instr.nextResult, bottom);  (* store output *)
        gate := instr.GetCollectTarget();
        IF (gate = loopStart) OR (gate.opcode # Opcode.loopStart) THEN
          (* don't wrap around to start of loop if gate is not our
             loopStart *)
          res := gate.nextResult;
          opnd := instr.opndList;
          WHILE (res # NIL) DO
            (* marker of a "select" result is the maximum of all corresponding
               collect arguments *)
            UpdateMarker(res, ABS(opnd.arg.marker));
            res := res.nextResult;
            opnd := opnd.nextOpnd;
          END;
          UpdateMarker(instr.nextResult, ABS(instr.opndList.arg.marker));
        END;

      | Opcode.select:
        UpdateMarker(instr, bottom);
        
        IF (ABS(instr.opndList.arg.marker) # loopInvariant) THEN
          (* a loop-variant selecting expression makes all results at
             least forwardInductive *)
          min := forwardInductive;
        ELSE
          min := loopInvariant;
        END;

        opndIndex := 0;
        res := instr.nextResult;
        WHILE (res # NIL) DO
          max := min;
          
          opnd := instr.opndList.nextOpnd;
          WHILE (opnd # NIL) DO
            opnd := opnd.nextOpnd;
            next := opnd.nextOpnd;

            IF (opnd.arg.instr.opcode = Opcode.collect) THEN
              opnd := opnd.arg.instr.NthOpnd(opndIndex);
            END;
            m := ABS(opnd.arg.marker);
            IF (m > max) THEN
              max := m;
            END;
            
            opnd := next;
          END;
          UpdateMarker(res, max);

          INC(opndIndex);
          res := res.nextResult;
        END;

      ELSE  (* one of the arguments is not loopInvariant *)
        UpdateMarkers(instr, bottom);
      END;
    END ClassifyInstr;
  
  BEGIN
    pb.SetMarkers(NIL, loopInvariant);
    worklist := NIL;

    (* mark all results of "loop-start" as forward inductive *)
    UpdateMarker(loopStart, bottom);
    res := loopStart.nextResult;
    WHILE (res # NIL) DO
      UpdateMarker(res, forwardInductive);
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

PROCEDURE FindInductiveCycles(loopStart: SSA.Instr);
(* Locate inductive cycles.  For every cycle, install an instance of
   InductionCycle in the loop-start's result that is its head.  *)
  VAR
    count: LONGINT;
    loopEnd: SSA.Instr;
    res: SSA.Result;
    opnd: SSA.Opnd;
    ic: InductionCycle;
    ce: CycleElement;
    
  PROCEDURE NewInductionCycle(head: SSA.Result): InductionCycle;
    VAR
      ic: InductionCycle;
    BEGIN
      NEW(ic);
      InitInductionCycle(ic, head);
      RETURN ic;
    END NewInductionCycle;

  PROCEDURE AddInductionValue(ic: InductionCycle; res: SSA.Result);
    VAR
      ce: CycleElement;
    BEGIN
      NEW(ce);
      InitCycleElement(ce, ic, res);
    END AddInductionValue;
  
  PROCEDURE SearchCycle(res, head: SSA.Result; ic: InductionCycle): BOOLEAN;
    VAR
      opnd: SSA.Opnd;
      resIndex: LONGINT;
      onCycle: BOOLEAN;
      arg: SSA.Result;
    BEGIN
      IF (res = head) THEN
        RETURN TRUE;
      ELSIF (res.marker = forwardInductive) THEN
        onCycle := FALSE;
        
        CASE res.instr.opcode OF
        | Opcode.add, Opcode.subtract:
          opnd := res.instr.opndList;
          WHILE (opnd # NIL) DO
            IF SearchCycle(opnd.arg, head, ic) THEN
              onCycle := TRUE;
            END;
            opnd := opnd.nextOpnd;
          END;
          
        | Opcode.select:
          resIndex := res.ResultIndex();
          
          opnd := res.instr.NthOpnd(1);
          WHILE (opnd # NIL) DO
            opnd := opnd.nextOpnd;
            IF (opnd.arg.instr.opcode = Opcode.collect) THEN
              arg := opnd.arg.instr.NthArg(resIndex-1);
            ELSE
              arg := opnd.arg;
            END;
            IF SearchCycle(arg, head, ic) THEN
              onCycle := TRUE;
            END;
            opnd := opnd.nextOpnd;
          END;

        | Opcode.typeConv:
          onCycle := SearchCycle(res.instr.opndList.arg, head, ic);
          
        | Opcode.loopStart:
          (* we reached the beginning of the loop, but did not end up with
             our current head *)
          onCycle := FALSE;
        END;
        
        IF onCycle THEN
          AddInductionValue(ic, res);
        END;
        RETURN onCycle;
      ELSE
        RETURN FALSE;
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
        IF SearchCycle(opnd.arg, res, ic) THEN
          ce := ic;
          WHILE (ce # NIL) DO
            ce.res.info := ce;
            ce := ce.next;
          END;
<*IF OOC_DEBUG_LOOP_REWRITE THEN*>  
          DumpCycle(ic);
<*END*>  
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

PROCEDURE NewSum(subclass: Opcode.Subclass; atom: SSA.Result): Sum;
  VAR
    sum: Sum;
  BEGIN
    NEW(sum);
    InitSum(sum, subclass, atom);
    RETURN sum;
  END NewSum;

PROCEDURE Flatten*(res: SSA.Result);
  VAR
    instr: SSA.Instr;
    sum: Sum;
    opnd: SSA.Opnd;

  PROCEDURE ScalePList(a: PList; b: LONGINT): PList;
  (* Calculate a*b.  *)
    VAR
      c: PList;
      i: LONGINT;
    BEGIN
      IF (b = 1) THEN
        RETURN a;
      ELSIF (a = zero) THEN
        RETURN zero;
      ELSE
        NEW(c);
        NEW(c.prod, a.size);
        c.size := a.size;
        FOR i := 0 TO a.size-1 DO
          NEW(c.prod[i]);
          c.prod[i].magnitude := a.prod[i].magnitude*b;
          c.prod[i].factors := a.prod[i].factors;
        END;
        RETURN c;
      END;
    END ScalePList;
  
  PROCEDURE AddPLists(a, b: PList; magnB: LONGINT): PList;
  (* Calculate a+magnB*b.  *)
    VAR
      p: PList;
      i, ia, ib: LONGINT;

    PROCEDURE CopyProduct(a: Product): Product;
      VAR
        p: Product;
      BEGIN
        NEW(p);
        p^ := a^;
        RETURN p;
      END CopyProduct;
    
    BEGIN
      IF (a = zero) THEN
        RETURN ScalePList(b, magnB);
      ELSIF (b = zero) THEN
        RETURN a;
      ELSE
        NEW(p);
        NEW(p.prod, a.size+b.size);
        i := 0; ia := 0; ib := 0;
        WHILE (ia # a.size) OR (ib # b.size) DO
          IF (ia # a.size) &
             ((ib = b.size) OR (Cmp(a.prod[ia], b.prod[ib]) < 0)) THEN
            p.prod[i] := a.prod[ia];
            INC(i); INC(ia);
          ELSIF (ia = a.size) OR (Cmp(a.prod[ia], b.prod[ib]) > 0) THEN
            p.prod[i] := CopyProduct(b.prod[ib]);
            p.prod[i].magnitude := p.prod[i].magnitude * magnB;
            INC(i); INC(ib);
          ELSE  (* Cmp() = 0 *)
            p.prod[i] := CopyProduct(a.prod[ia]);
            INC(p.prod[i].magnitude, b.prod[ib].magnitude * magnB);
            INC(i); INC(ia); INC(ib);
          END;
        END;
        p.size := i;
        RETURN p;
      END;
    END AddPLists;
  
  
  PROCEDURE MultProduct(a: Product; b: PList): PList;
    VAR
      i, j, la, lb, ia, ib: LONGINT;
      p: PList;
      f: Factors;
    BEGIN
      IF (b = zero) THEN
        RETURN zero;
      ELSIF (b = one) THEN
        NEW(p);
        p.size := 1;
        NEW(p.prod, 1);
        p.prod[0] := a;
        RETURN p;
      ELSE
        NEW(p);
        p.size := b.size;
        NEW(p.prod, p.size);
        FOR i := 0 TO p.size-1 DO
          NEW(p.prod[i]);
          
          la := LEN(a.factors^);
          lb := LEN(b.prod[i].factors^);
          NEW(f, la+lb);
          p.prod[i].factors := f;
          p.prod[i].magnitude := b.prod[i].magnitude*a.magnitude;
          
          j := 0; ia := 0; ib := 0;
          WHILE (ia # la) OR (ib # lb) DO
            IF (ia # la) &
               ((ib = lb) OR
                (a.factors[ia].id <= b.prod[i].factors[ib].id)) THEN
              f[j] := a.factors[ia]; INC(ia);
            ELSE
              f[j] := b.prod[i].factors[ib]; INC(ib);
            END;
            INC(j);
          END;
          ASSERT(j = LEN(f^));
        END;
        RETURN p;
      END;
    END MultProduct;
  
  PROCEDURE AddSum(a, b: Sum; magnB: LONGINT): Sum;
  (* Calculate a+magnB*b.  Return NIL if a and b have different cycle
     heads.  *)
    VAR
      sum: Sum;
      subclass: Opcode.Subclass;

    PROCEDURE UseCount(res: SSA.Result): LONGINT;
      VAR
        num: LONGINT;
        use: SSA.Opnd;
      BEGIN
        num := 0;
        use := res.useList;
        WHILE (use # NIL) DO
          INC(num);
          use := use.nextUse;
        END;
        RETURN num;
      END UseCount;

    PROCEDURE MoveCE(a: Sum): Sum;
      VAR
        p: Product;
        plist: PList;
        b: Sum;
      BEGIN
        (* multiply `a.ce' with `a.ceFactor' *)
        NEW(p);
        p.magnitude := 1;
        NEW(p.factors, 1);
        p.factors[0] := a.ce;
        plist := MultProduct(p, a.ceFactor);

        (* add the product to `others' and zero `ceFactor' *)
        NEW(b);
        b^ := a^;
        b.others := AddPLists(b.others, plist, 1);
        b.ceFactor := zero;
        b.ce := NIL;
        RETURN b;
      END MoveCE;
    
    BEGIN
      ASSERT(a.subclass = b.subclass);
      subclass := a.subclass;
      
      NEW(sum);
      InitSum(sum, subclass, NIL);
      IF (a.ceFactor = zero) THEN
        sum.ce := b.ce;
      ELSIF (b.ceFactor = zero) THEN
        sum.ce := a.ce;
      ELSIF (a.ce = b.ce) THEN
        sum.ce := a.ce;
      ELSE
        IF (UseCount(b.ce.res) > UseCount(a.ce.res)) THEN
          RETURN AddSum(MoveCE(a), b, magnB);
        ELSE
          RETURN AddSum(a, MoveCE(b), magnB);
        END;
      END;
      sum.ceFactor := AddPLists(a.ceFactor, b.ceFactor, magnB);
      sum.loopInvariant := AddPLists(a.loopInvariant, b.loopInvariant, magnB);
      sum.constant := AddPLists(a.constant, b.constant, magnB);
      sum.others := AddPLists(a.others, b.others, magnB);
      RETURN sum;
    END AddSum;

  PROCEDURE MultSum(a, b: Sum): Sum;
    VAR
      h, mult: Sum;

    PROCEDURE MultPList(a: PList; b: Sum; subclass: Opcode.Subclass): Sum;
      VAR
        i: LONGINT;
        sum: Sum;
      BEGIN
        NEW(sum);
        InitSum(sum, subclass, NIL);
        
        IF (a = zero) THEN
          RETURN sum;
        ELSIF (a = one) THEN
          RETURN b;
        ELSE
          sum.ce := b.ce;
          FOR i := 0 TO a.size-1 DO
            sum.ceFactor := AddPLists
                (sum.ceFactor, MultProduct(a.prod[i], b.ceFactor), 1);
            sum.constant := AddPLists
                (sum.constant, MultProduct(a.prod[i], b.constant), 1);
            sum.loopInvariant := AddPLists
                (sum.loopInvariant, MultProduct(a.prod[i],b.loopInvariant), 1);
            sum.others := AddPLists
                (sum.others, MultProduct(a.prod[i], b.others), 1);
          END;
          RETURN sum;
        END;
      END MultPList;
    
    BEGIN
      ASSERT(a.subclass = b.subclass);
      
      IF (b.ceFactor = zero) & (b.others = zero) THEN
        h := a; a := b; b := h;
      END;
      IF (a.ceFactor # zero) OR (a.others # zero) THEN
        RETURN NIL;
      END;

      mult := MultPList(a.constant, b, a.subclass);
      IF (a.loopInvariant # zero) THEN
        h := MultPList(a.loopInvariant, b, a.subclass);
        h.loopInvariant := AddPLists(h.loopInvariant, h.constant, 1);
        h.constant := zero;
        mult := AddSum(mult, h, 1);
        ASSERT(mult # NIL);
      END;
      RETURN mult;
    END MultSum;
  
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
      sum := NewSum(res.subclass, res);
      sum.others := NewPList(sum);
      res.info := sum;
      Flatten(res.instr);
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
          Flatten(opnd.arg);
          opnd := opnd.nextOpnd;
        END;

        CASE instr.opcode OF
        | Opcode.add:
          instr.info := AddSum(instr.opndList.arg.info(Sum),
                               instr.opndList.nextOpnd.arg.info(Sum), 1);
        | Opcode.subtract:
          instr.info := AddSum(instr.opndList.arg.info(Sum),
                               instr.opndList.nextOpnd.arg.info(Sum), -1);
        | Opcode.multiply:
          instr.info := MultSum(instr.opndList.arg.info(Sum),
                                instr.opndList.nextOpnd.arg.info(Sum));
        | Opcode.typeConv:  (* copy sum and adjust type *)
          NEW(sum);
          sum^ := instr.opndList.arg.info(Sum)^;
          sum.subclass := instr.subclass;
          instr.info := sum;
        ELSE  (* fall through *)
        END;
        IF (instr.info = NIL) THEN
          sum := NewSum(instr.subclass, instr);
          sum.others := NewPList(sum);
          instr.info := sum;
        ELSE
          sum := instr.info(Sum);
          sum.replacementCandidate := 
              (sum.ce # NIL) &
              (sum.loopInvariant # zero);
        END;
      END;
    END;
  END Flatten;

PROCEDURE InitialValue(pb: SSA.ProcBlock;
                       rc: RewrittenCycle; initOld: SSA.Result;
                       marker: LONGINT): SSA.Result;
  VAR
    res: SSA.Result;
    instr: SSA.Instr;
    subclass: Opcode.Subclass;
  BEGIN
    subclass := rc.origin.subclass;
    res := pb.FixSubclass(initOld, subclass);
    IF (res # initOld) THEN  (* new conversion instruction *)
      res.instr.marker := marker;
    END;
    
    IF (rc.a # NIL) THEN
      instr := pb.AddInstr(Opcode.multiply, subclass);
      instr.AddOpnd(res, Opnd.arg);
      instr.AddOpnd(rc.a, Opnd.arg);
      instr.marker := marker;
      res := instr;
    END;
    
    IF (rc.b # NIL) THEN
      instr := pb.AddInstr(Opcode.add, subclass);
      instr.AddOpnd(rc.b, Opnd.arg);
      instr.AddOpnd(res, Opnd.arg);
      instr.marker := marker;
      res := instr;
    END;
    
    RETURN res;
  END InitialValue;

PROCEDURE Rewrite(pb: SSA.ProcBlock; sum: Sum);
  VAR
    ic: InductionCycle;
    rc: RewrittenCycle;
    loopStart, loopEnd, collect: SSA.Instr;
    res: SSA.Result;
    replacement: Dictionary.Dictionary;
    i: LONGINT;

  PROCEDURE Expr(plist: PList; subclass: Opcode.Subclass): SSA.Result;
    VAR
      i: LONGINT;
      add: SSA.Instr;
      res, instr: SSA.Result;
      
    PROCEDURE Multiply(m: LONGINT; f: Factors): SSA.Result;
      VAR
        i: LONGINT;
        mult: SSA.Instr;
        res: SSA.Result;
      BEGIN
        IF (LEN(f^) = 0) THEN
          res := pb.FixSubclass(pb.GetConstInt(1), subclass);
        ELSE
          res := pb.FixSubclass(f[0].atom, subclass);
          FOR i := 1 TO LEN(f^)-1 DO
            mult := pb.AddInstr(Opcode.multiply, subclass);
            mult.AddOpnd(res, Opnd.arg);
            mult.AddOpnd(pb.FixSubclass(f[i].atom, subclass), Opnd.arg);
            res := mult;
          END;
        END;
        IF (m # 1) THEN
          mult := pb.AddInstr(Opcode.multiply, subclass);
          mult.AddOpnd(res, Opnd.arg);
          mult.AddOpnd(pb.FixSubclass(pb.GetConstInt(m), subclass), Opnd.arg);
          res := mult;
        END;
        RETURN res;
      END Multiply;
    
    BEGIN
      IF (plist.size = 0) THEN
        RETURN pb.FixSubclass(pb.GetConstInt(0), subclass);
      ELSE
        res := Multiply(plist.prod[0].magnitude, plist.prod[0].factors);
        FOR i := 1 TO plist.size-1 DO
          instr := Multiply(plist.prod[i].magnitude, plist.prod[i].factors);
          add := pb.AddInstr(Opcode.add, subclass);
          add.AddOpnd(res, Opnd.arg);
          add.AddOpnd(instr, Opnd.arg);
          res := add;
        END;
        RETURN res;
      END;
    END Expr;

  PROCEDURE RewriteCycle(rc: RewrittenCycle; ce: CycleElement);
    VAR
      ci, mult, instr, collect: SSA.Instr;
      iv, ni, res, mres: SSA.Result;
      obj: Object.Object;
      resultIndex: LONGINT;
      opnd, next: SSA.Opnd;
    BEGIN
      WHILE (ce # NIL) DO
        ci := ce.res.instr;
        CASE ci.opcode OF
        | Opcode.add, Opcode.subtract:
          iv := ci.opndList.arg;           (* induction value *)
          ni := ci.opndList.nextOpnd.arg;  (* non-induction *)
          IF replacement.HasKey(ni) THEN   (* oops, got that backward *)
            res := iv; iv := ni; ni := res;
          END;
          ASSERT(replacement.HasKey(iv));
          
          obj := replacement.Get(iv);
          res := obj(SSA.Result);
          ni := pb.FixSubclass(ni, sum.subclass);
          IF (rc.a # NIL) THEN
            mult := pb.AddInstr(Opcode.multiply, sum.subclass);
            mult.AddOpnd(ni, Opnd.arg);
            mult.AddOpnd(rc.a, Opnd.arg);
            mres := mult;
          ELSE
            mres := ni;
          END;
          
          instr := pb.AddInstr(ci.opcode, sum.subclass);
          instr.AddOpnd(res, Opnd.arg);
          instr.AddOpnd(mres, Opnd.arg);
          res := instr;
          
        | Opcode.select:
          resultIndex := ce.res.ResultIndex();
          
          opnd := ci.opndList.nextOpnd;
          WHILE (opnd # NIL) DO
            opnd := opnd.nextOpnd;
            next := opnd.nextOpnd;
            
            ASSERT(opnd.arg.instr.opcode = Opcode.collect);
            collect := opnd.arg.instr;
            iv := collect.NthArg(resultIndex-1);
            
            IF replacement.HasKey(iv) THEN  (* preceeding element in cycle *)
              obj := replacement.Get(iv);
              res := obj(SSA.Result);
            ELSE
              res := InitialValue(pb, rc, iv, initMarker);
            END;
            
            collect.AddOpnd(res, Opnd.arg);
            
            opnd := next;
          END;
          res := ci.AddResultSubclass(Result.selectValue, sum.subclass);
        END;
        rc.replacements[ce.pos] := res;
        replacement.Set(ce.res, res);

        ce := ce.next;
      END;
    END RewriteCycle;

  PROCEDURE ComputeReplacement(rc: RewrittenCycle; sum: Sum): SSA.Result;
    VAR
      res: SSA.Result;
      instr: SSA.Instr;
    BEGIN
      res := pb.FixSubclass(rc.replacements[sum.ce.pos], sum.subclass);

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
              IF (f1[i].atom # f2[i].atom) THEN
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
        WHILE (i1 # p1.size) & (p1.prod[i1].magnitude = 0) DO
          INC(i1);
        END;
        WHILE (i2 # p2.size) & (p2.prod[i2].magnitude = 0) DO
          INC(i2);
        END;
        RETURN (i1 = p1.size) & (i2 = p2.size);
      END EqualPList;
    
    BEGIN
      RETURN EqualPList(sum1.ceFactor, sum2.ceFactor) &
               EqualPList(sum1.loopInvariant, sum2.loopInvariant);
    END EqualAB;
  
  BEGIN
    ic := sum.ce.ic;
    rc := ic.rewrittenCycles;
    WHILE (rc # NIL) & ~EqualAB(sum, rc.origin) DO
      rc := rc.next;
    END;
    IF (rc = NIL) THEN  (* cannot reuse existing rc: create new one *)
      NEW(rc);
      rc.next := ic.rewrittenCycles;
      ic.rewrittenCycles := rc;
      rc.origin := sum;
      
      IF (sum.ceFactor # one) THEN
        rc.a := Expr(sum.ceFactor, sum.subclass);
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
      loopStart := sum.ce.ic.res.instr;
      collect := loopStart.opndList.arg.instr;
      res := InitialValue(pb, rc,
                          collect.NthArg(sum.ce.ic.res.ResultIndex()-1),
                          initMarker);
      collect.AddOpnd(res, Opnd.arg);
      
      (* add result as gate output to loopStart, and register it in the
         replacement dictionary *)
      replacement := Dictionary.New();
      res := loopStart.AddResultSubclass(Result.selectValue, sum.subclass);
      replacement.Set(sum.ce.ic.res, res);
      NEW(rc.replacements, ic.cycleLength);
      FOR i := 0 TO ic.cycleLength-1 DO
        rc.replacements[i] := NIL;
      END;
      rc.replacements[0] := res;
      
      (* rewrite all other elements in the induction cycle *)
      RewriteCycle(rc, ic.next);
      
      (* add final value of the induction cycle to the back-edge collect *)
      loopEnd := loopStart.GetLoopEnd();
      collect := loopEnd.opndList.nextOpnd.arg.instr;
      collect.AddOpnd(rc.replacements[LEN(rc.replacements^)-1], Opnd.arg);
    END;


    (* compute replacement for `origInstr', and register it with `sum' *)
    sum.replacement := ComputeReplacement(rc, sum);
  END Rewrite;

PROCEDURE ClassifyUse(use: SSA.Opnd; ic: InductionCycle): SHORTINT;
  VAR
    instr, target: SSA.Instr;
    res: SSA.Result;
    recUse: SSA.Opnd;
    min, x: SHORTINT;
    sum: Sum;
  BEGIN
    instr := use.instr;
    IF (instr.marker = SSA.initMarker) THEN
      RETURN useReplacementCode;
    ELSIF (use.class = Opnd.backwardFeed) THEN
      RETURN useBackedgeValue;
    ELSIF (instr.info = NIL) THEN
      RETURN useOutsideLoop;
    ELSIF (instr.opcode = Opcode.collect) THEN
      target := instr.GetCollectTarget();
      res := target.NthResult(use.OpndIndex()+1);
      IF (res.info # NIL) & (res.info IS CycleElement) &
         (res.info(CycleElement).ic = ic) THEN
        RETURN useInCycleElement;
      ELSIF (target.opcode = Opcode.loopStart) THEN
        RETURN useBackedgeValue;
      ELSE
        min := MAX(SHORTINT);
        recUse := res.useList;
        WHILE (recUse # NIL) DO
          x := ClassifyUse(recUse, ic);
          IF (x < min) THEN
            min := x;
          END;
          recUse := recUse.nextUse;
        END;
        IF (min = useOutsideLoop) THEN
          RETURN useIndirectOutsideLoop;
        ELSE
          RETURN min;
        END;
      END;
    ELSIF (instr.info # NIL) & (instr.info IS CycleElement) &
          (instr.info(CycleElement).ic = ic) THEN
      RETURN useInCycleElement;
    ELSE
      sum := instr.info(Sum);
      IF sum.replacementCandidate THEN
        RETURN useReplacementCandidate;
      ELSIF (sum.useClass >= 0) THEN
        RETURN sum.useClass;
      ELSE
        min := MAX(SHORTINT);
        res := instr;
        WHILE (res # NIL) DO
          recUse := res.useList;
          WHILE (recUse # NIL) DO
            x := ClassifyUse(recUse, ic);
            IF (x < min) THEN
              min := x;
            END;
            recUse := recUse.nextUse;
          END;
          res := res.nextResult;
        END;
        IF (min = useOutsideLoop) THEN
          min := useIndirectOutsideLoop;
        END;
        sum.useClass := min;
        RETURN min;
      END;
    END;
  END ClassifyUse;

PROCEDURE RewriteUses(pb: SSA.ProcBlock; rc: RewrittenCycle; ce: CycleElement);
  VAR
    use, nextUse: SSA.Opnd;
    instr, new: SSA.Instr;
    other, res: SSA.Result;
    newOpcode: Opcode.Class;

  PROCEDURE SignPList(a: PList): SHORTINT;
    VAR
      sign, fSign: SHORTINT;
      i: LONGINT;

    PROCEDURE SignProduct(a: Product): SHORTINT;
      VAR
        sign, aSign: SHORTINT;
        i: LONGINT;

      PROCEDURE SignAtom(a: Sum): SHORTINT;
        VAR
          const: SSA.Const;
        BEGIN
          IF (a.atom = NIL) THEN
            RETURN signUnknown;
          ELSE
            CASE a.atom.instr.opcode OF
            | Opcode.const:
              const := a.atom(SSA.Const);
              IF (const.value IS BigInt.BigInt) THEN
                RETURN SHORT(SHORT(const.value(BigInt.BigInt).Sign()));
              ELSE
                RETURN signUnknown;
              END;

            | Opcode.getLengthHeap, Opcode.getLengthParam:
              RETURN signNotNegative;
              
            ELSE
              RETURN signUnknown;
            END;
          END;
        END SignAtom;
      
      BEGIN
        IF (a.magnitude = 0) THEN
          RETURN signZero;
        ELSE
          sign := signNotNegative;
          FOR i := 0 TO LEN(a.factors^)-1 DO
            aSign := SignAtom(a.factors[i]);
            IF (aSign = signUnknown) THEN
              RETURN signUnknown;
            ELSIF (aSign = signZero) THEN
              RETURN signZero;
            ELSIF (aSign = signNotPositive) THEN
              sign := -sign;
            END;
          END;
          IF (a.magnitude < 0) THEN
            RETURN -sign;
          ELSE
            RETURN sign;
          END;
        END;
      END SignProduct;
    
    BEGIN
      IF (a.size = 0) THEN
        RETURN signZero;
      ELSE
        sign := signZero;
        FOR i := 0 TO a.size-1 DO
          fSign := SignProduct(a.prod[i]);
          IF (fSign = signUnknown) THEN  (* cannot determine sign of sum *)
            RETURN signUnknown;
          ELSIF (fSign = signZero) THEN
            (* keep current sign *)
          ELSIF (sign = signZero) THEN
            sign := fSign;
          ELSIF (sign # fSign) THEN
            (* both negative and positive term in sum, assume worst *)
            RETURN signUnknown;
          END;
        END;
        RETURN sign;
      END;
    END SignPList;
  
  BEGIN
    use := ce.res.useList;
    WHILE (use # NIL) DO
      nextUse := use.nextUse;
      
      instr := use.instr;
      IF (Opcode.eql <= instr.opcode) & (instr.opcode <= Opcode.geq) THEN
        newOpcode := instr.opcode;
        IF (newOpcode > Opcode.neq) THEN
          CASE SignPList(rc.origin.ceFactor) OF
          | signNotNegative, signZero:  (* keep opcode *)
          | signNotPositive:            (* change sign on opcode *)
            CASE newOpcode OF
            | Opcode.lss: newOpcode := Opcode.gtr
            | Opcode.leq: newOpcode := Opcode.geq
            | Opcode.gtr: newOpcode := Opcode.lss
            | Opcode.geq: newOpcode := Opcode.leq
            END;
          | signUnknown:                (* cannot replace instruction at all *)
            newOpcode := -1;
          END;
        END;

        IF (newOpcode >= 0) THEN
          new := NIL;
          CASE use.OpndIndex() OF
          | 0:
            other := instr.NthArg(1);
            IF (other.marker = loopInvariant) THEN
              new := pb.AddInstr(newOpcode, rc.origin.subclass);
              new.AddOpnd(rc.replacements[ce.pos], Opnd.arg);
              new.AddOpnd(InitialValue(pb, rc, other, initMarker),
                          Opnd.arg);
            END;
          | 1:
            other := instr.NthArg(0);
            IF (other.marker = loopInvariant) THEN
              new := pb.AddInstr(newOpcode, rc.origin.subclass);
              new.AddOpnd(InitialValue(pb, rc, other, initMarker), Opnd.arg);
              new.AddOpnd(rc.replacements[ce.pos], Opnd.arg);
            END;
          END;
          
          IF (dangerous OR
              dangerousAdr & (rc.origin.subclass = Opcode.scAddress)) &
             (new # NIL) THEN
            IF (instr.info = NIL) THEN
              instr.info := NewSum(rc.origin.subclass, NIL);
            END;
            instr.info(Sum).replacement := new;
          END;
        END;

      ELSIF (ClassifyUse(use, ce.ic) = useOutsideLoop) THEN
        (* using instruction is after the loop *)
        IF (ce.reconstruct = NIL) THEN
          res := rc.replacements[ce.pos];
          
          IF (rc.b # NIL) THEN
            new := pb.AddInstr(Opcode.subtract, rc.origin.subclass);
            new.AddOpnd(res, Opnd.arg);
            new.AddOpnd(rc.b, Opnd.arg);
            res := new;
          END;
          
          IF (rc.a # NIL) THEN
            new := pb.AddInstr(Opcode.divide, rc.origin.subclass);
            new.AddOpnd(res, Opnd.arg);
            new.AddOpnd(rc.a, Opnd.arg);
            res := new;
          END;
          
          res := pb.FixSubclass(res, ce.res.subclass);
          ce.reconstruct := res;
        ELSE
          res := ce.reconstruct;
        END;

        use.ReplaceArg(res);
      END;
      
      use := nextUse;
    END;
  END RewriteUses;


PROCEDURE ClassifyCEUses(pb: SSA.ProcBlock; loopStart: SSA.Instr);
  VAR
    res: SSA.Result;
    ic: InductionCycle;
    ce: CycleElement;
    use: SSA.Opnd;
  BEGIN
    res := loopStart;
    WHILE (res # NIL) DO
      IF (res.info # NIL) & (res.info IS InductionCycle) THEN
        ic := res.info(InductionCycle);
        ce := ic;
        WHILE (ce # NIL) DO
          use := ce.res.useList;
          WHILE (use # NIL) DO
            INC(ce.useCount[ClassifyUse(use, ic)]);
            use := use.nextUse;
          END;

          (*ce.res.LogId("ce.res");
          FOR i := 0 TO maxUseId DO
            Log.LongInt("  id", i);
            Log.LongInt("  count", ce.useCount[i]);
          END;*)
          
          ce := ce.next;
        END;
      END;
      res := res.nextResult;
    END;
  END ClassifyCEUses;

PROCEDURE InstallEquivCE(pb: SSA.ProcBlock; loopStart: SSA.Instr);
  VAR
    res, storeOut: SSA.Result;
    rc: RewrittenCycle;
    ce: CycleElement;
    equiv, anchor, loopEnd: SSA.Instr;

  PROCEDURE UsedOutsideLoop(res: SSA.Result): BOOLEAN;
    VAR
      use: SSA.Opnd;
    BEGIN
      use := res.useList;
      WHILE (use # NIL) DO
        IF (use.instr.marker # loopInvariant) & (use.instr.info = NIL) THEN
          RETURN TRUE;
        END;
        use := use.nextUse;
      END;
      RETURN FALSE;
    END UsedOutsideLoop;
  
  BEGIN
    (* install a "noop" immediately after the loop-end, using the store output
       result to integrate it into the dataflow *)
    loopEnd := loopStart.GetLoopEnd();
    anchor := pb.AddInstr(Opcode.noop, Opcode.scNone);
    storeOut := loopEnd.nextResult;
    res := anchor.AddResult(Result.store);
    storeOut.ReplaceUses(res);
    anchor.AddOpnd(storeOut, Opnd.store);
    
    res := loopStart;
    WHILE (res # NIL) DO
      IF (res.info # NIL) & (res.info IS InductionCycle) THEN
        rc := res.info(InductionCycle).rewrittenCycles;
        WHILE (rc # NIL) DO
          ce := res.info(InductionCycle);
          WHILE (ce # NIL) DO
            IF UsedOutsideLoop(ce.res) THEN
              equiv := pb.AddInstr(Opcode.equiv, Opcode.scNone);
              equiv.AddOpnd(rc.replacements[ce.pos], Opnd.arg);
              equiv.AddOpnd(InitialValue(pb, rc, ce.res, bottom),
                            Opnd.arg);
              anchor.AddOpnd(equiv, Opnd.arg);
            END;
            ce := ce.next;
          END;
          rc := rc.next;
        END;
      END;
      res := res.nextResult;
    END;
  END InstallEquivCE;

PROCEDURE Transform*(pb: SSA.ProcBlock);
(**The rewriting algorithm expects that constant propagation, non-substituting
   algebraic transformations, and common subexpression have been run.
   Otherwise, results may be less than optimal, for example because two
   accesses to a pointer variable are interpreted as two distinct values.  *)
  VAR
    loops: ArrayList.ArrayList;
    loopStart, loopEnd, instr: SSA.Instr;
    opnd: SSA.Opnd;
    i: LONGINT;
    res: SSA.Result;
    ic: InductionCycle;
    ce: CycleElement;
    
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

<*IF OOC_DEBUG_LOOP_REWRITE THEN*>  
  PROCEDURE DumpMarker(marker: LONGINT);
    VAR
      instr: SSA.Instr;
      res: SSA.Result;
    BEGIN
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        res := instr;
        WHILE (res # NIL) DO
          IF (ABS(res.marker) = marker) THEN
            res.LogId("res");
          END;
          res := res.nextResult;
        END;
        instr := instr.nextInstr;
      END;
    END DumpMarker;
<*END*>  
  
  BEGIN
    (* enumerate loops in post order *)
    pb. SetMarkers (NIL, notVisited);
    loops := ArrayList.New(4);
    EnumerateLoops(pb.selectReturn.GetArgStore(), pb.GetEnter());

    idCount := 0;
    i := 0;
    WHILE (i # loops.size) DO
      loopStart := loops.array[i](SSA.Instr);
<*IF OOC_DEBUG_LOOP_REWRITE THEN*>  
      Blocker.Write(StdChannels.stderr, pb);
      Log.Ptr("### loopStart", loopStart);
<*END*>  
      
      (* classify instructions as loopInvariant, forwardInductive, or bottom
         with regard to loop *)
      Classify(pb, loopStart);
<*IF OOC_DEBUG_LOOP_REWRITE THEN*>  
      Log.Msg("loopInvariant");
      DumpMarker(loopInvariant);
      Log.Msg("forwardInductive");
      DumpMarker(forwardInductive);
      Log.Msg("bottom");
      DumpMarker(bottom);
<*END*>  
      
      (* locate inductive cycles in loop *)
      FindInductiveCycles(loopStart);

      (* calculate alternative representations of addition, subtraction, and
         multiplication instructions; as a side-effect, all instructions
         contributing to the arguments of the "loop-end" that are not
         loop-invariant have a non-NIL info field on completion  *)
      loopEnd := loopStart.GetLoopEnd();
      opnd := loopEnd.opndList;
      WHILE (opnd # NIL) DO
        Flatten(opnd.arg.instr);
        opnd := opnd.nextOpnd;
      END;
<*IF OOC_DEBUG_LOOP_REWRITE THEN*>  
      DumpSums(pb);      
<*END*>  

      (* find all instructions that are computed through a sum involving the
         head of an induction cycle and insert replacement instructions for
         them *)
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        (* since we are traversing instructions, we do not hit on the induction
           head themselves, which are additional results of loop-start *)
        IF (instr.info # NIL) &
           (instr.info(Sum).ce # NIL) &
           (instr.info(Sum).loopInvariant # zero) THEN
          Rewrite(pb, instr.info(Sum));
        END;
        instr := instr.nextInstr;
      END;

      (* for every element of an induction cycle, count the uses that are
         replaced *)
      ClassifyCEUses(pb, loopStart);
      
      (* for every element of a rewritten cycle, install an "equiv"
         instruction demonstrating the equivalence of the rewritten element
         with a standard (a*x+b)+c expression after the loop *)
      InstallEquivCE(pb, loopStart);
      
      (* traverse all elements of the induction cycles and see if they are
         used in comparison instructions; if possible, rewrite the comparisons
         to use the rewritten induction cycle *)
      res := loopStart;
      WHILE (res # NIL) DO
        IF (res.info # NIL) &
           (res.info IS InductionCycle) &
           (res.info(InductionCycle).rewrittenCycles # NIL) THEN
          ic := res.info(InductionCycle);
          ce := ic;
          WHILE (ce # NIL) DO
            RewriteUses(pb, ic.rewrittenCycles, ce);
            ce := ce.next;
          END;
        END;
        res := res.nextResult;
      END;

(*      Blocker.Write(StdChannels.stderr, pb);*)
      
      (* replace instructions with their tediously computed equivalents *)
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        IF (instr.info # NIL) & (instr.info(Sum).replacement # NIL) THEN
          instr.ReplaceUses(instr.info(Sum).replacement);
        END;
        instr := instr.nextInstr;
      END;
      
      INC(i);
    END;
  END Transform;

BEGIN
  NEW(one);
  one.size := 1;
  NEW(one.prod, 1);
  NEW(one.prod[0]);
  NEW(one.prod[0].factors, 0);
  one.prod[0].magnitude := 1;
END OOC:SSA:LoopRewrite.
