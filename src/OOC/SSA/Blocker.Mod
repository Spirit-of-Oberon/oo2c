(* 	$Id: Blocker.Mod,v 1.48 2003/03/09 18:04:03 mva Exp $	 *)
MODULE OOC:SSA:Blocker;
(*  Imposes a block structure on a flat list of SSA instructions.
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

<*DEFINE DEBUG_BLOCKER:=FALSE*>

IMPORT
  <*IF DEBUG_BLOCKER THEN*>Log,OOC:SSA:Check,<*END*>
  SYSTEM, Object, Object:BigInt, ADT:Dictionary,
  IntDictionary := ADT:Dictionary:IntValue,
  IO, IO:TextRider, IO:StdChannels,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:DeadCodeElimination,
  OOC:SSA:Destore;
  
(**

   This module rearranges a flat list of SSA instructions into a ``blocked''
   hierarchy of instructions.  The idea is that a block contains a list of
   instructions that are evaluated under the same guarding predicate.  The
   blocked representation is primarly used to visualize SSA code, so that the
   code is better suited for human interpretation.  Additionally, it is
   intended that is serves as the starting point for creating the assembler
   output, where control flow is realized by jump and branch instructions.

  *)

(*
   
1. Control flow variants: select

   One block for each branch of control.  An instruction is in the
   block B_n, if all it its uses are 

   a) in the select operand for B_n,

   b) in select-return or select-exit, or

   c) in other instructions of B_n.

2. Loops: loop-start & loop-end

   An instruction is in the loop block B, if it

   a) depends on the value of the loop's back edge, and

   b) it contributes to the loop's back edge.

3. Non-local exits: exit & return

   A block containing an EXIT or RETURN instruction effectively ends
   with this instruction.

4. Non-local merge of control flow: select-return

   For a select-return, the corresponding block is the whole procedure
   body.
*)


TYPE
  Proxy* = POINTER TO ProxyDesc;
  Region* = POINTER TO RegionDesc;
  Select* = POINTER TO SelectDesc;
  Loop* = POINTER TO LoopDesc;

TYPE
  ProxyDesc = RECORD
    (SSA.NodeDesc)
    nextProxy-, prevProxy: Proxy;
    (**Links instructions within a region.  *)
    
    instr-: SSA.Instr;
    (**The SSA instruction that is represented by this object.  For a region,
       this entry either refers to the last instruction of the region, or is
       @code{NIL}, depending on the kind of region.  *)
    
    region: Region;
    loopAssoc: Loop;
    (**Refers to the loop this instruction is part of.  An instruction is
       considered to be part of a loop if

       @itemize @bullet
       @item
       it takes one of its input parameters directly or indirectly from the
       @oconst{Opcode.loopStart} instruction, @emph{and}

       @item
       one of it results is passed directly or indirectly to the
       @oconst{Opnd.backwardFeed} operand or to the exit predicateof the
       @oconst{Opcode.loopEnd} instruction.
       @end itemize

       The field is @code{NIL} for instructions that are outside of any loop.
       By definition, dead code is not part of any loop.

       This field is calculated by @oproc{ArrangeInstructions.AttachToLoop}.  *)
    visitedForLoop: Loop;
    (**This field is used by @oproc{ArrangeInstructions.AttachToLoop}.  *)
    visitedResult: BOOLEAN;
    (**This field is used by @oproc{ArrangeInstructions.AttachToLoop}.  *)
    
    discoveredForLoop: Loop;
    (**This field is used by @oproc{ArrangeInstructions.DiscoverLoopStructure}.  *)

    marker: LONGINT;
    (**Use by @oproc{AntiDepViolation} and
       @oproc{ArrangeInstructions.SortRegion.CalculateWeight}.  *)

    
    length: LONGINT;
    (**Length of an instruction within the region.  For a nested region, this
       is approximated by the number of instructions within the region.  For
       all other instructions, this is @samp{1}.  If the length has not
       been computed yet, then this field is negative.  *)

    distance: LONGINT;
    (**Distance of this instruction to the end of the region.  This is the
       maximum of the distance of all local using instructions, plus the
       instruction's @ofield{length}.  A value of zero means that the
       instruction can be scheduled at the very end of the region.  *)

    degreeDiff: LONGINT;
    (**Number of produced register values minus the number of register values
       taken as operands.  *)
  END;
  RegionDesc = RECORD
    (ProxyDesc)
    first-, last-: Proxy;
    (**List of instructions local to this region.  Instructions are chained
       using @ofield{Proxy.nextProxy}.  *)
    
    nestingDepth: LONGINT;
    (**Number of parents of the region.  The top-level region has a depth of
       zero.  *)
  END;
  SelectDesc = RECORD
    (**This region is corresponds to a @oconst{Opcode.select} instruction.  It
       contains one region for every path leading to the
       @oconst{Opcode.select}, but no other instructions.  *)
    (RegionDesc)
    paths-: POINTER TO ARRAY OF Region;
  END;
  Preceeds = POINTER TO PreceedsDesc;
  PreceedsDesc = RECORD
    nextPreceeds: Preceeds;
    preceedingLoop: Loop;
  END;
  LoopDesc = RECORD
    (RegionDesc)
    nestedLoops: Loop;
    (**List of loops nested in this one.  This data structure
       disregards all other compound statements, only looking at the various
       loop constructs.  The list is linked via @ofield{Loop.nextLoop}.
       Loops are listed after all loops they depend on.  For loops that are
       independent of each other, no particular order is guaranteed.  *)
    
    nextLoop: Loop;
    (**Refers to the next nested loop in the loop's parent.  *)
    
    parentLoop: Loop;
    (**The enclosing loop.  The procedure's top-level is also represented by a
       @otype{Loop} as well.  *)
    
    preceedingList: Preceeds;
    (**Lists all loops on the same nesting level from which control can pass to
       this loop.  Created by @oproc{ArrangeInstructions.DiscoverLoopStructure}
       and used by @oproc{ArrangeInstructions.SortNestedLoops}.  *)
    
    scheduled: BOOLEAN;
    (**Used by @oproc{ArrangeInstructions.SortNestedLoops} to mark loops that
       have been sorted already.  *)
  END;

TYPE
  DependenceData* = POINTER TO DependenceDataDesc;
  DependenceDataDesc = RECORD
    root: Region;
    proxyMap: Dictionary.Dictionary;  (* maps SSA.Instr onto Proxy *)
  END;
  
  
(* Proxy
   ------------------------------------------------------------------------ *)
  
PROCEDURE InitProxy (p: Proxy; instr: SSA.Instr);
  BEGIN
    p. nextProxy := NIL;
    p. prevProxy := NIL;
    p. instr := instr;
    p. region := NIL;
    p. loopAssoc := NIL;
    p. visitedForLoop := NIL;
    p. visitedResult := FALSE;
    p. discoveredForLoop := NIL;
    p. marker := 0;
    p. length := -1;
    p. distance := 0;
    p. degreeDiff := 0;
  END InitProxy;

PROCEDURE NewProxy (instr: SSA.Instr): Proxy;
  VAR
    p: Proxy;
  BEGIN
    NEW (p);
    InitProxy (p, instr);
    RETURN p;
  END NewProxy;

PROCEDURE ClearMarkers (r: Region);
  VAR
    proxy: Proxy;
  BEGIN
    r. marker := 0;
    proxy := r. first;
    WHILE (proxy # NIL) DO
      proxy. marker := 0;
      WITH proxy: Region DO
        ClearMarkers (proxy);
      ELSE                               (* ignore *)
      END;
      proxy := proxy. nextProxy;
    END;
  END ClearMarkers;

(* Region
   ------------------------------------------------------------------------ *)

PROCEDURE InitRegion (r: Region; instr: SSA.Instr);
  BEGIN
    InitProxy (r, instr);
    r. first := NIL;
    r. last := NIL;
    r. nestingDepth := 0;
    r. marker := 0;
  END InitRegion;

PROCEDURE NewRegion (instr: SSA.Instr): Region;
  VAR
    r: Region;
  BEGIN
    NEW (r);
    InitRegion (r, instr);
    RETURN r
  END NewRegion;

PROCEDURE (r: Region) Append (p: Proxy);
  BEGIN
    ASSERT (p. region = NIL);
    
    p. prevProxy := r. last;
    p. nextProxy := NIL;
    IF (r. last # NIL) THEN
      r. last. nextProxy := p;
    ELSE
      r. first := p;
    END;
    r. last := p;
    
    p. region := r;
    IF (p IS Region) THEN
      p(Region). nestingDepth := r. nestingDepth+1
    END;
  END Append;

PROCEDURE (r: Region) Insert (p: Proxy);
  BEGIN
    ASSERT (p. region = NIL);
    
    p. prevProxy := NIL;
    p. nextProxy := r. first;
    IF (r. first # NIL) THEN
      r. first. prevProxy := p;
    ELSE
      r. last := p;
    END;
    r. first := p;
    
    p. region := r;
    IF (p IS Region) THEN
      p(Region). nestingDepth := r. nestingDepth+1
    END;
  END Insert;

PROCEDURE (r: Region) Remove (p: Proxy);
  BEGIN
    ASSERT (p. region = r);
    IF (p. prevProxy # NIL) THEN
      p. prevProxy. nextProxy := p. nextProxy;
    ELSE
      r. first := p. nextProxy;
    END;
    IF (p. nextProxy # NIL) THEN
      p. nextProxy. prevProxy := p. prevProxy;
    ELSE
      r. last := p. prevProxy;
    END;
    
    p. region := NIL;
    IF (p IS Region) THEN
      p(Region). nestingDepth := 0
    END;
  END Remove;


(* Select
   ------------------------------------------------------------------------ *)

PROCEDURE InitSelect (r: Select; instr: SSA.Instr);
  VAR
    i: LONGINT;
  BEGIN
    InitRegion (r, instr);
    NEW (r. paths, instr. SizeOpndList() DIV 2);
    FOR i := 0 TO LEN (r. paths^)-1 DO
      r. paths[i] := NIL;
    END;
  END InitSelect;

PROCEDURE NewSelect (instr: SSA.Instr): Select;
  VAR
    r: Select;
  BEGIN
    NEW (r);
    InitSelect (r, instr);
    RETURN r
  END NewSelect;

(* Loop
   ------------------------------------------------------------------------ *)

PROCEDURE InitLoop (r: Loop; instr: SSA.Instr);
  BEGIN
    InitRegion (r, instr);
    r. nextLoop := NIL;
    r. nestedLoops := NIL;
    r. parentLoop := NIL;
    r. preceedingList := NIL;
    r. scheduled := FALSE;
  END InitLoop;

PROCEDURE NewLoop (instr: SSA.Instr): Loop;
  VAR
    r: Loop;
  BEGIN
    NEW (r);
    InitLoop (r, instr);
    RETURN r
  END NewLoop;

PROCEDURE (loop: Loop) AppendLoop (nestedLoop: Loop);
  PROCEDURE App (VAR list: Loop);
    BEGIN
      ASSERT (nestedLoop # list);
      IF (list = NIL) THEN
        nestedLoop. nextLoop := NIL;
        list := nestedLoop;
      ELSE
        App (list. nextLoop);
      END;
    END App;
  
  BEGIN
    App (loop. nestedLoops);
    nestedLoop. parentLoop := loop;
  END AppendLoop;



PROCEDURE GetProxy (instr: SSA.Instr): Proxy;
  VAR
    p: Proxy;  
  BEGIN
    IF (instr. info # NIL) THEN
      RETURN instr. info(Proxy);
    ELSE
      CASE instr. opcode OF
      | Opcode.selectReturn:
        p := NewRegion (instr);
      | Opcode.select:
        p := NewSelect (instr);
      | Opcode.loopEnd:
        p := NewLoop (instr);
      ELSE
        p := NewProxy (instr);
      END;
      instr. info := p;
      RETURN p;
    END;
  END GetProxy;

PROCEDURE Dominates (dom, child: Region): BOOLEAN;
  BEGIN
    WHILE (child # NIL) & (child # dom) DO
      child := child. region;
    END;
    RETURN (child # NIL);
  END Dominates;

PROCEDURE WriteBlocks (c: IO.ByteChannel; pb: SSA.ProcBlock; root: Region;
                       marker: Dictionary.Dictionary);
  VAR
    w: TextRider.Writer;
    idMap: IntDictionary.Dictionary;
    instrCount: LONGINT;
    
  PROCEDURE AssignId (p: Proxy);
    VAR
      n: Proxy;
    BEGIN
      WITH p: Region DO
        n := p. first;
        WHILE (n # NIL) DO
          AssignId (n);
          n := n. nextProxy;
        END;
      ELSE
      END;

      IF (p. instr # NIL) & ~p. instr. IsConst() THEN
        idMap. Set (p. instr, instrCount);
        INC (instrCount);
      END;
    END AssignId;

  PROCEDURE WriteInstrPrefix (p: Proxy);
    VAR
      instr: SSA.Instr;
      i, d: LONGINT;
      r: Region;
    BEGIN
      instr := p. instr;

<*IF TARGET_ADDRESS = 64 THEN*>
      w. WriteString ("???");
<*ELSE*>
      IF (instr = NIL) THEN
        w. WriteHex (SYSTEM.VAL (LONGINT, p), 8);
      ELSE
        w. WriteHex (SYSTEM.VAL (LONGINT, instr), 8);
      END;
<*END*>
      w. WriteString ("  ");
      (*IF (instr = NIL) THEN
        d := 0;
      ELSE
        d := instr. info(Proxy). distance;
      END;
      w. WriteLInt (d, 3);
      w. WriteString ("  ");*)
      (*IF (instr = NIL) THEN
        d := 0;
      ELSE
        d := instr. info(Proxy). degreeDiff;
      END;
      w. WriteLInt (d, 3);
      w. WriteString ("  ");*)
      (*w. WriteString ("L:");
         IF (p. loopAssoc # NIL) THEN
           WriteResultId (p. loopAssoc. instr);
         ELSE
           w. WriteString ("NIL");
         END;
         w. WriteString (09X);*)
      
      IF (p. region # NIL) THEN
        d := p. region. nestingDepth;
        r := p. region;
        WHILE (r # NIL) DO
          IF (r IS Select) THEN
            DEC (d);
          END;
          r := r. region;
        END;
        FOR i := 1 TO d DO
          w. WriteString ("  ");
        END;
      END;
    END WriteInstrPrefix;
  
  PROCEDURE WriteResultId (res: SSA.Result);
    VAR
      id, count: LONGINT;
      ptr: SSA.Result;
      value: STRING;
      instr: SSA.Instr;
      obj: Object.Object;
    BEGIN
      IF marker. HasKey (res) THEN
        obj := marker. Get (res);
        w. WriteChar ("[");
        w. WriteObject (obj);
        w. WriteChar ("]");
      END;
      
      (*w.WriteHex(SYSTEM.VAL(LONGINT,res),8);*)
      instr := res. instr;
      IF instr. IsConst() THEN
        WITH instr: SSA.Const DO
          IF (instr. value = SSA.nil) THEN
            w. WriteString ("NIL");
          ELSE
            value := instr. value. ToString();
            w. WriteObject (value);
          END;
        | instr: SSA.DeclRef DO
          w. WriteString (instr. decl. name. str^);
        | instr: SSA.TypeRef DO
          w. WriteString ("<typeref>");
        | instr: SSA.Address DO
          w. WriteChar ("&");
          w. WriteString (instr. decl. name. str^);
        ELSE
          CASE instr. opcode OF
          | Opcode.getLengthHeap, Opcode.getLengthParam:
            w. WriteString (instr. opndList. nextOpnd. nextOpnd.
                            arg(SSA.DeclRef). decl. name. str^);
            w. WriteString ("/dim");
            w. WriteLInt (instr. opndList. arg(SSA.Const). value(BigInt.BigInt). ToLongInt(), 0);
          ELSE
            instr. LogOpcode ("instr.opcode");
            ASSERT (FALSE);
          END;
        END
      ELSE
        id := idMap. Get (res. instr);
        w. WriteChar ("(");
        w. WriteLInt (id, 0);
        IF (res. instr # res) THEN
          count := 1;
          ptr := res. instr. nextResult;
          WHILE (ptr # res) DO
            INC (count);
            ptr := ptr. nextResult;
          END;
          w. WriteChar (".");
          w. WriteLInt (count, 0);
        END;
        w. WriteChar (")");
      END;
    END WriteResultId;

  PROCEDURE WriteOpnd (opnd: SSA.Opnd);
    BEGIN
      CASE opnd. class OF
      | Opnd.antiDependency:
        w. WriteString ("*ad*");
      | Opnd.regionDependency:
        w. WriteString ("*rd*");
      | Opnd.loopExternalDef:
        w. WriteString ("*led*");
      ELSE
        (*Opnd.GetName (opnd. class, str);
        w. WriteString (str);
        w. WriteString (":");*)
      END;
      WriteResultId (opnd. arg);
    END WriteOpnd;
  
  PROCEDURE WriteInstr (p: Proxy);
    VAR
      instr: SSA.Instr;
      res: SSA.Result;
      opnd: SSA.Opnd;
      str: ARRAY 64 OF CHAR;
      resCount: LONGINT;
      
    BEGIN
      instr := p. instr;
      IF ~instr. IsConst() THEN
        WriteInstrPrefix (p);
        
        resCount := 0;
        res := instr;
        WHILE (res # NIL) DO
          IF (res. useList # NIL) OR (instr. opcode = Opcode.selectReturn) THEN
            IF (resCount # 0) THEN
              w. WriteChar (",");
            END;
            WriteResultId (res);
            INC (resCount);
          END;
          res := res. nextResult;
        END;
        IF (resCount = 0) THEN
          w. WriteString ("(--)");
        END;
        
        w. WriteString (" := ");
        Opcode.GetName (instr. opcode, instr. subclass, str);
        w. WriteString (str);
        IF (instr. pos >= 0) THEN
          w. WriteString ("@");
          w. WriteLInt (instr. pos, 0);
        END;
        w. WriteChar (" ");
        
        opnd := instr. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd # instr. opndList) THEN
            w. WriteChar (",");
          END;
          WriteOpnd (opnd);
          opnd := opnd. nextOpnd
        END;
        w. WriteLn;
      END;
    END WriteInstr;

  PROCEDURE WriteRegion (r: Region);
    VAR
      i: LONGINT;
      opnd: SSA.Opnd;
      
    PROCEDURE WriteBody (p: Proxy);
      BEGIN
        WHILE (p # NIL) DO
          WITH p: Region DO
            WriteRegion (p);
          ELSE
            WriteInstr (p);
          END;
          p := p. nextProxy;
        END;
      END WriteBody;

    PROCEDURE WriteBranchHead (select, opnd: SSA.Opnd);
      BEGIN
        w. WriteString ("IF ");
        WriteOpnd (select);
        w. WriteString (" = ");
        WriteOpnd (opnd);
        w. WriteString (" THEN");
      END WriteBranchHead;
    
    BEGIN
      WITH r: Loop DO
        WriteInstrPrefix (r); w. WriteString ("LOOP"); w. WriteLn;
        WriteBody (r. first);
        WriteInstrPrefix (r); w. WriteString ("END LOOP"); w. WriteLn;
      | r: Select DO
        WriteInstrPrefix (r); w. WriteString ("SELECT"); w. WriteLn;
        opnd := r. instr. opndList;
        i := 0;
        WHILE (i # LEN (r. paths^)) DO
          opnd := opnd. nextOpnd;
          WriteInstrPrefix (r. paths[i]);
          WriteBranchHead (r. instr. opndList, opnd);
          w. WriteLn;
          WriteBody (r. paths[i]. first);
          opnd := opnd. nextOpnd;
          INC (i);
        END;
        WriteInstrPrefix (r); w. WriteString ("END SELECT"); w. WriteLn;
      ELSE
        WriteBody (r. first);
      END;
      IF (r. instr # NIL) THEN
        WriteInstr (r);
      END;
    END WriteRegion;
  
  BEGIN
    idMap := IntDictionary.New();
    instrCount := 1;
    AssignId (root);

    w := TextRider.ConnectWriter (c);
    w. WriteLn;
    w. WriteString ("Procedure: ");
    w. WriteString (pb. procDecl. name. str^);
    w. WriteLn;
    WriteRegion (root);
  END WriteBlocks;

PROCEDURE AntiDepViolation (pb: SSA.ProcBlock; root: Region): BOOLEAN;
  VAR
    get: SSA.Instr;
    destore: Destore.State;
    violationCount, currentId: LONGINT;
    startOfScan: Proxy;
    
  PROCEDURE ScanBackward (region: Region; proxy: Proxy;
                          readDesign: SSA.Opnd; storeInGet: SSA.Result);
    VAR
      storeOut: SSA.Result;
      i: LONGINT;
      opnd: SSA.Opnd;
      x: Proxy;
    BEGIN
      WHILE (proxy # NIL) & ~(proxy IS Region) DO
        storeOut := proxy. instr. GetResultStore();
        IF (proxy. marker = currentId) OR (storeOut = storeInGet) THEN
          (* done; we have reached the instruction that produces the state
             we are using, or we have been here before *)
          RETURN;
          
        ELSIF (storeOut # NIL) &
              destore. ClobberedBy (readDesign, proxy. instr) THEN
          INC (violationCount);
          proxy. instr. AddOpnd (get, Opnd.antiDependency);
<*IF DEBUG_BLOCKER THEN*>
          Log.Ptr ("  adding backward anti-dep to", proxy. instr);
          Check.All (pb);
<*END*>
        END;
        proxy. marker := currentId;
        proxy := proxy. prevProxy;
      END;

      IF (proxy # NIL) THEN
        (* descending in nested region; we return from the nested region
           if the search "falls off" its beginning; if it doesn't fall off,
           we never return to this region *)
        storeOut := proxy. instr. GetResultStore();
        IF (proxy. marker = currentId) OR (storeOut = storeInGet) THEN
          RETURN;
        ELSE
          proxy. marker := currentId;
          WITH proxy: Select DO
            i := 0;
            WHILE (i # LEN (proxy. paths^)) DO
              ScanBackward (proxy. paths[i], proxy. paths[i]. last,
                            readDesign, storeInGet);
              INC (i);
            END;
            
          | proxy: Loop DO
            opnd := proxy. instr. NthOpnd (2);
            WHILE (opnd # NIL) & (opnd. class = Opnd.storeExit) DO
              x := opnd. arg. instr. info(Proxy);
              ScanBackward (x. region, x, readDesign, storeInGet);
              opnd := opnd. nextOpnd;
            END;
          ELSE  (* not a nested region *)
          END;
        END;
        
      ELSE
        (* falling off the beginning of the region *)
        IF (region. region # NIL) THEN
          IF (region. region IS Select) THEN
            region := region. region;
          END;
          ScanBackward (region. region, region. prevProxy,
                        readDesign, storeInGet);
        END;
      END;
    END ScanBackward;

  PROCEDURE ScanForward (proxy: Proxy; readDesign: SSA.Opnd);
    VAR
      storeOut: SSA.Result;
    BEGIN
      (* note: scanning aborts with the first region; this is fine, as long
         no scheduler building on this tries to move instructions of this
         region over nested regions  *)
      WHILE (proxy # NIL) & ~(proxy IS Region) DO
        storeOut := proxy. instr. GetResultStore();
        IF (storeOut # NIL) &
           destore. ClobberedBy (readDesign, proxy. instr) THEN
          proxy. instr. AddOpnd (get, Opnd.antiDependency);
<*IF DEBUG_BLOCKER THEN*>
          Log.Ptr ("  adding forward anti-dep to", proxy. instr);
          Check.All (pb);
<*END*>

          (* stop with the first instruction that may clobber the value we
             desire; since this instruction aliases with our variable, any
             instruction further down the road that aliases with the variable
             must also alias with the instruction; by construction, all these
             instruction must be data-dependent on the current one, and do
             not need to be marked explicitly *)
          RETURN;
        END;
        proxy := proxy. nextProxy;
      END;
    END ScanForward;

  BEGIN
    destore := Destore.New (pb);
    ClearMarkers (root);
    violationCount := 0;
    currentId := 1;
    
    get := pb. instrList;
    WHILE (get # NIL) DO
      IF (get. opcode = Opcode.get) & (get. GetResultStore() = NIL) THEN
<*IF DEBUG_BLOCKER THEN*>
        Log.Ptr ("get base", get);
<*END*>
        startOfScan := get. info(Proxy);
        ScanBackward (startOfScan. region,
                      startOfScan. prevProxy,
                      get. GetOpndClass (Opnd.readDesign),
                      get. opndList. arg);
        
        ScanForward (startOfScan. nextProxy,
                     get. GetOpndClass (Opnd.readDesign));
        
        INC (currentId);
      END;
      get := get. nextInstr;
    END;

<*IF DEBUG_BLOCKER THEN*>
    IF (violationCount # 0) THEN
      (* try again with additional anti-dependencies being inserted *)
      Log.Msg ("RETRY ARRANGE_INSTRUCTIONS");
      WriteBlocks (StdChannels.stderr, pb, root, Dictionary.New());
      Check.All(pb);
    END;
<*END*>
    RETURN (violationCount # 0);
  END AntiDepViolation;

PROCEDURE RemoveAntiDeps* (pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
    opnd, next: SSA.Opnd;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      opnd := instr. opndList;
      WHILE (opnd # NIL) DO
        next := opnd. nextOpnd;
        CASE opnd. class OF
        | Opnd.antiDependency, Opnd.regionDependency:
          opnd. DeleteOpnd;
        ELSE                             (* keep *)
        END;
        opnd := next;
      END;
      instr := instr. nextInstr;
    END;
  END RemoveAntiDeps;

PROCEDURE RemoveRegionDeps* (pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
    opnd, next: SSA.Opnd;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      opnd := instr. opndList;
      WHILE (opnd # NIL) DO
        next := opnd. nextOpnd;
        IF (opnd. class = Opnd.regionDependency) THEN
          opnd. DeleteOpnd;
        END;
        opnd := next;
      END;
      instr := instr. nextInstr;
    END;
  END RemoveRegionDeps;

PROCEDURE ArrangeInstructions* (pb: SSA.ProcBlock;
                                markAntiDeps: BOOLEAN): Region;
(**With @oparam{markAntiDeps}, the resulting schedule honors data dependencies.
   Additional operands are added to some instructions to make anti-dependencies
   explicit.  As long as the calling procedure does not move instructions
   between regions or across regions, all schedules derived from the produced
   region hierarchy should be valid.
   
   Don't forget to call @oproc{RemoveAntiDeps} when done!  *)
  VAR
    instr, enter: SSA.Instr;
    res: SSA.Result;
    ready, waiting: Region;
    useCount: LONGINT;
    use: SSA.Opnd;
    p: Proxy;
    root, region: Region;
    mainLoop: Loop;

  PROCEDURE DiscoverLoopStructure (loop: Loop; storeIn: SSA.Result;
                                   endOfSearch: SSA.Instr;
                                   preceedingLoop: Loop);
  (**Discover the loop structure within the parent region @oparam{loop}.
     @oparam{loop} is either the procedure body, or another loop.  Discovered
     loops are appended to @oparam{loop}'s nested loops.  @oparam{storeIn} is
     the store value that is to be traced, and the trace ends once the store
     value @oparam{endOfSearch} is reached.  The latter is the final
     @var{store} that marks the end of the parent region.  If the search is
     started by the caller after another loop in @oparam{loop}, then
     @oparam{preceedingLoop} refers to this loop.

     At the end, the field @ofield{loop.nestedLoops} represents the structure
     of loops in @oparam{loop}.  This information is used later on to create
     all the non-loop regions, and to place instructions into their final
     region.  *)
    VAR
      use: SSA.Opnd;
      instr, loopEnd: SSA.Instr;
      loopProxy: Loop;
      dummy: Proxy;

    PROCEDURE RegisterPreceeding (preceeding, following: Loop);
    (* Register `preceeding' as one of the loops that feed data into
       `following'.  *)
      VAR
        pre: Preceeds;
      BEGIN
        IF (preceeding # NIL) THEN
          NEW (pre);
          pre. preceedingLoop := preceeding;
          pre. nextPreceeds := following. preceedingList;
          following. preceedingList := pre;
        END;
      END RegisterPreceeding;
    
    BEGIN
      IF (storeIn # NIL) THEN
        use := storeIn. useList;
        WHILE (use # NIL) DO
          instr := use. instr;
          IF (instr # endOfSearch) THEN
            IF (instr. opcode = Opcode.loopStart) THEN
              (* for each scan within a given parent, we may encounter one and
                 the same nested loop multiple times; the preceeding loop 
                 may differ for the encounters, so we note those down for each
                 of them *)
              loopEnd := instr. GetLoopEnd();
              p := GetProxy (loopEnd);
              loopProxy := p(Loop);
              RegisterPreceeding (preceedingLoop, loopProxy);
              
              IF (instr. info = NIL) THEN
                (* if we are seeing this loop for the first time, discover
                   the structure of its content *)
                dummy := GetProxy (instr); (* mark loop-start as seen *)
                loop. AppendLoop (loopProxy);
                DiscoverLoopStructure (loopProxy,
                                       instr. GetResultStore(),
                                       loopEnd, NIL);
                DiscoverLoopStructure (loop,
                                       loopEnd. GetResultStore(),
                                       endOfSearch, loopProxy);
              END;
            ELSE
              p := GetProxy (instr);
              IF (p. discoveredForLoop # loop) THEN
                p. discoveredForLoop := loop;
                DiscoverLoopStructure (loop,
                                       instr. GetResultStore(),
                                       endOfSearch, preceedingLoop);
              END;
            END;
          END;
          use := use. nextUse;
        END;
      END;
    END DiscoverLoopStructure;

  PROCEDURE SortNestedLoops (loop: Loop);
  (**Do a simple topological sort on the nested loops to make sure that if
     there are multiple paths of control flow between loops, then all paths are
     considered to determine if a loop follows another.  *)
    VAR
      oldNested, nested: Loop;

    PROCEDURE GetNext (VAR list: Loop): Loop;
      VAR
        ptr: Preceeds;
        best: Loop;
      BEGIN
        ASSERT (list # NIL);           (* or we have a cycle *)
        
        ptr := list. preceedingList;
        WHILE (ptr # NIL) & ptr. preceedingLoop. scheduled DO
          ptr := ptr. nextPreceeds;
        END;
        IF (ptr = NIL) THEN
          best := list;
          list := list. nextLoop;
          best. scheduled := TRUE;
          RETURN best;
        ELSE
          RETURN GetNext (list. nextLoop);
        END;
      END GetNext;
    
    BEGIN
      oldNested := loop. nestedLoops;
      loop. nestedLoops := NIL;

      WHILE (oldNested # NIL) DO
        nested := GetNext (oldNested);
        loop. AppendLoop (nested);
      END;
    END SortNestedLoops;
  
  PROCEDURE AttachToLoop(loop: Loop);
  (**Starting with the instructions using @oparam{loop}'s
     @oconst{Opcode.loopStart} instruction, set the regions of all dependent
     instructions to @oparam{loop} if they also contribute to the loop's
     @oconst{Opcode.loopEnd}.  That is, for every instruction that is not loop
     invariant with respect to @oparam{loop}, set its region to this loop.  To
     make it unique, the established reference is always to the smallest
     enclosing loop.

     The procedure is called recursively on the loops nested into
     @oparam{loop}, and the ones following it.  *)
    VAR
      dummy: BOOLEAN;
      
    PROCEDURE PartOfLoop(loop: Loop; instr: SSA.Instr): BOOLEAN;
    (**Return @code{TRUE} iff @oparam{instr} is a loop variant instruction of
       @oparam{loop}.  As a side-effect, the instruction's region is set to
       @oparam{loop} in this case.

       @precond
       @oparam{instr} is directly or indirectly dependent on the
       @oconst{Opcode.loopStart} instruction of @oparam{loop}.
       @end precond

       @postcond
       Result is @code{TRUE} if the loop's @oconst{Opcode.loopEnd} depends on
       @oparam{instr}.
       @end postcond  *)
      VAR
        res: SSA.Result;
        use: SSA.Opnd;
        inLoopUse: LONGINT;
        instrProxy, useProxy: Proxy;
      BEGIN
        (* ... The performance of this function can improved by aborting the
           depth first search altogether if one of the parents of `loop' is
           encountered.

           Until this approach has proven itself, though, simplicity is
           king. ...  *)
        instrProxy := GetProxy(instr);
        IF (instrProxy. visitedForLoop = loop) THEN
          (* been here before, this instruction is not part of `loop' *)
          RETURN instrProxy. visitedResult;
        ELSE
          inLoopUse := 0;
          res := instr;
          WHILE (res # NIL) DO
            use := res. useList;
            WHILE (use # NIL) DO
              useProxy := GetProxy(use. instr);
              IF (useProxy = loop) &
                 ((use. class = Opnd.backwardFeed) OR
                  (use. OpndIndex() = 2)) OR
                 PartOfLoop(loop, use. instr) THEN
                INC (inLoopUse);
              END;
              use := use. nextUse;
            END;
            res := res. nextResult;
          END;

          instrProxy. visitedForLoop := loop;
          instrProxy. visitedResult := (inLoopUse # 0);
          IF instrProxy. visitedResult & (instrProxy. loopAssoc = NIL) THEN
            (* only mark instruction as belonging to `loop' if it has not
               been associated with one of the nested loops yet *)
            instrProxy. loopAssoc := loop;
          END;
          RETURN instrProxy. visitedResult;
        END;
      END PartOfLoop;
    
    BEGIN
      IF (loop # NIL) THEN
        AttachToLoop (loop. nextLoop);
        AttachToLoop (loop. nestedLoops);
        IF (loop. instr # NIL) THEN
          dummy := PartOfLoop (loop, loop. instr. GetLoopStart());
        END;
      END;
    END AttachToLoop;

  PROCEDURE AddRegionDeps (r: Region);
    VAR
      proxy: Proxy;
      opnd: SSA.Opnd;

    PROCEDURE AddOpndDep (proxy: Proxy; opnd: SSA.Opnd);
      VAR
        argProxy, a, b: Proxy;
        argLoop: Loop;
        exit: SSA.Opnd;
        exitInstr: SSA.Instr;
      BEGIN
        argProxy := opnd. arg. instr. info(Proxy);
        IF (argProxy. region # r) THEN
          a := argProxy;
          b := proxy;
          WHILE (a. region. nestingDepth > b. region. nestingDepth) DO
            a := a. region;
          END;
          WHILE (b. region. nestingDepth > a. region. nestingDepth) DO
            b := b. region;
          END;
          WHILE (a. region # b. region) DO
            a := a. region;
            b := b. region;
          END;
          b. instr. AddUniqueOpnd (a. instr, Opnd.regionDependency);
        END;

        (* if a loop variant value is used outside of the loop, then it must
           be available at all places where an "exit" appears *)
        argLoop := argProxy. loopAssoc;
        IF (argLoop # NIL) & ~Dominates (argLoop, proxy. region) THEN
          ASSERT (argLoop. instr. opcode = Opcode.loopEnd);
          exit := argLoop. instr. NthOpnd (2);
          WHILE (exit # NIL) & (exit. class = Opnd.storeExit) DO
            exitInstr := exit. arg. instr;
            ASSERT (exitInstr. opcode = Opcode.exit);
            exitInstr. AddOpnd (opnd. arg. instr, Opnd.antiDependency);
            AddOpndDep (exitInstr. info(Proxy), exitInstr. LastOpnd());
            exit := exit. nextOpnd;
          END;
        END;
      END AddOpndDep;
    
    BEGIN
      proxy := r. first;
      WHILE (proxy # NIL) DO
        IF (proxy. instr # NIL) THEN
          CASE proxy. instr. opcode OF
          | Opcode.select:
            AddOpndDep (proxy, proxy. instr. opndList);
          | Opcode.selectReturn:
            (* nothing *)
          | Opcode.loopEnd:
            (* nothing *)
          ELSE
            opnd := proxy. instr. opndList;
            WHILE (opnd # NIL) & (opnd. class # Opnd.regionDependency) DO
              AddOpndDep (proxy, opnd);
              opnd := opnd. nextOpnd;
            END;
          END;
        END;

        IF (proxy IS Region) THEN
          AddRegionDeps (proxy(Region));
        END;
        proxy := proxy. nextProxy;
      END;
    END AddRegionDeps;
  
  PROCEDURE IgnoredUse (use: SSA.Opnd): BOOLEAN;
    VAR
      opcode: Opcode.Class;
    BEGIN
      (* skip all but the first operand of "select-exit", and all of
         "select-return" (the latter is automatically added as first
         instruction to the procedure block, its parents become live
         after that) *)
      opcode := use.instr.opcode;
      RETURN
          (opcode = Opcode.selectReturn) OR
          (opcode = Opcode.loopEnd) & (use.class = Opnd.storeExit) OR
          (opcode = Opcode.equivPRE) & (use.OpndIndex() = 2);
    END IgnoredUse;

  PROCEDURE UpdateDefs (p: Proxy);
    VAR
      opnd: SSA.Opnd;
      defInstr: SSA.Instr;
      pDef: Proxy;
    BEGIN
      opnd := p. instr. opndList;
      WHILE (opnd # NIL) DO
        IF ~IgnoredUse (opnd) THEN
          defInstr := opnd. arg. instr;
          DEC (defInstr. marker);
          IF (defInstr. marker = 0) THEN
            pDef := defInstr. info(Proxy);
            waiting. Remove (pDef);
            ready. Append (pDef);
          END;
        END;
        opnd := opnd. nextOpnd;
      END;
    END UpdateDefs;

  PROCEDURE GetRegion (p: Proxy): Region;
    VAR
      region, useRegion: Region;
      res: SSA.Result;
      use: SSA.Opnd;
      loopEnd: SSA.Instr;

    PROCEDURE Merge (a, b: Region): Region;
      BEGIN
        (* Without loops, the rules of region select are simple: the
           instruction is placed into the least global region that dominates
           all its uses.

           Things get more complicated, if loops enter the picture.  For one
           thing, the above rule may cause an instruction to be moved out of a
           loop, although it uses values provided by the back-edge of the loop.

           In addition to this, an instruction may end up within a loop,
           although it is in fact loop invariant.  *)
        WHILE (a. nestingDepth > b. nestingDepth) DO
          a := a. region;
        END;
        WHILE (b. nestingDepth > a. nestingDepth) DO
          b := b. region;
        END;
        WHILE (a # b) DO
          a := a. region;
          b := b. region;
        END;
        IF (a. instr # NIL) & (a. instr. opcode = Opcode.select) THEN
          a := a. region;
        END;
        RETURN a;
      END Merge;

    PROCEDURE RegionOfUse (opnd: SSA.Opnd): Region;
      VAR
        i, pathNum: LONGINT;
        instr: SSA.Instr;
        selectProxy: Select;
      BEGIN
        instr := opnd. instr;
        IF (instr. opcode = Opcode.select) THEN
          i := opnd. OpndIndex();
          IF (i = 0) OR opnd. IsScheduleOpnd() THEN
            RETURN instr. info(Proxy). region;
          ELSE
            pathNum := (i-1) DIV 2;
            selectProxy := instr. info(Select);
            IF (selectProxy. paths[pathNum] = NIL) THEN
              selectProxy. paths[pathNum] := NewRegion (NIL);
              selectProxy. Append (selectProxy. paths[pathNum]);
            END;
            RETURN selectProxy. paths[pathNum];
          END;
        ELSIF (instr. opcode = Opcode.loopEnd) THEN
          RETURN instr. info(Loop);
        ELSE
          RETURN instr. info(Proxy). region;
        END;
      END RegionOfUse;

    PROCEDURE CorrectForLoop (region: Region): Region;
      VAR
        ptr: Proxy;
        loopProxy: Loop;
      BEGIN
        loopProxy := p. loopAssoc;
        WHILE (loopProxy # NIL) DO
          ptr := loopProxy. region;
          IF (ptr = region) THEN
            RETURN loopProxy;
          END;
          loopProxy := loopProxy. parentLoop;
        END;
        RETURN region;
      END CorrectForLoop;

    PROCEDURE MoveLoopInvariants (region: Region): Region;
      VAR
        ptr, lowerBound: Region;
        lastLoop: Loop;
      BEGIN
        ptr := region;
        WHILE (ptr # NIL) & ~(ptr IS Loop) DO
          ptr := ptr. region
        END;

        (* determine the lower bound for moving the instruction downward
           in the hierarchy *)
        lowerBound := p. loopAssoc;
        IF (p. loopAssoc = NIL) THEN
          lowerBound := root;
        END;
        
        IF (ptr # NIL) & (ptr # lowerBound) THEN
          (* prelimiary placement put the instruction into a loop, but
             the instruction is invariant with regard to this loop *)
          lastLoop := ptr(Loop);
          WHILE (ptr # NIL) & (ptr # lowerBound) DO
            IF (ptr IS Loop) THEN
              lastLoop := ptr(Loop);
            END;
            ptr := ptr. region;
          END;
          
          (* move instruction just below the most global loop for which
             it is an invariant *)
          region := lastLoop. region;
        END;
        RETURN region;
      END MoveLoopInvariants;

    BEGIN
      IF (p. instr. opcode = Opcode.loopStart) THEN
        (* a "loop-start" is always placed in the region defined by the
           associated "loop-end" *)
        loopEnd := p. instr. GetLoopEnd();
        RETURN loopEnd. info(Region);
      ELSE
        region := NIL;
        res := p. instr;
        WHILE (res # NIL) DO
          use := res. useList;
          WHILE (use # NIL) DO
            IF ~IgnoredUse (use) THEN
              useRegion := RegionOfUse (use);
              IF (p. loopAssoc = NIL) OR
                 Dominates (p. loopAssoc, useRegion) THEN
                (* if `p' is part of a loop, then ignore all uses in regions
                   that are not dominated by the loop; they have no impact
                   on the placement of the instruction, because it must not
                   be moved outside its loop *)
                IF (region = NIL) THEN
                  region := useRegion;
                ELSE
                  region := Merge (region, useRegion);
                END;
              END;
            END;
            use := use. nextUse;
          END;
          res := res. nextResult;        
        END;
        
        IF (region = NIL) THEN
          region := root;
        ELSIF (region IS Select) THEN (* no instructions into select *)
          region := region. region;
        END;
      END;

      IF (p. instr. opcode = Opcode.labels) THEN
        RETURN region;
      ELSE
        RETURN MoveLoopInvariants (CorrectForLoop (region));
      END;
    END GetRegion;

  (*PROCEDURE WriteLoops (l: Loop; indent: INTEGER);
    VAR
      i: INTEGER;
      n: Loop;
    BEGIN
      FOR i := 0 TO indent DO
        Err.String ("    ");
      END;
      Err.String ("loop: ");
      Err.Hex (SYSTEM.VAL(LONGINT,l), 8);
      Err.Ln;
      n := l. nestedLoops;
      WHILE (n # NIL) DO
        WriteLoops (n, indent+1);
        n := n. nextLoop;
      END;
    END WriteLoops;*)

  PROCEDURE SortRegion (r: Region);
    VAR
      proxy, ready, waiting: Proxy;

    PROCEDURE Add (VAR list: Proxy; proxy: Proxy);
      BEGIN
        proxy. nextProxy := list;
        list := proxy;
      END Add;

    PROCEDURE Remove (VAR list: Proxy; proxy: Proxy);
      BEGIN
        IF (list = proxy) THEN
          list := proxy. nextProxy;
        ELSE
          Remove (list. nextProxy, proxy); 
        END;
      END Remove;

    PROCEDURE GetLength (proxy: Proxy): LONGINT;
      VAR
        l: LONGINT;

      PROCEDURE RegionLength(region: Region): LONGINT;
        VAR
          p: Proxy;
          l: LONGINT;
        BEGIN
          l := 1;
          p := region. first;
          WHILE (p # NIL) DO
            INC (l, GetLength (p));
            p := p. nextProxy;
          END;
          RETURN l;
        END RegionLength;

      PROCEDURE IsEmpty(region: Region): BOOLEAN;
        BEGIN
          RETURN (region.first = NIL);
        END IsEmpty;
      
      PROCEDURE IsExit(region: Region): BOOLEAN;
        BEGIN
          RETURN (region.first # NIL) &
              (region.first.nextProxy = NIL) &
              (region.first.instr.opcode = Opcode.exit);
        END IsExit;
      
      BEGIN
        IF (proxy. length < 0) THEN
          WITH proxy: Select DO
            IF (LEN(proxy.paths^) = 2) &
               ((IsEmpty(proxy.paths[0]) & IsExit(proxy.paths[1])) OR
                (IsEmpty(proxy.paths[1]) & IsExit(proxy.paths[0]))) THEN
              (* treat two way select containing only a single exit in one of
                 its branches specially; the idea is to move such a select,
                 which appears at the end of a WHILE or REPEAT, pretty much
                 to the end of the block *)
              l := 0;
            ELSE
              l := RegionLength(proxy);
            END;
          | proxy: Region DO
            l := RegionLength(proxy);
          ELSE
            CASE proxy. instr. opcode OF
            | Opcode.collect: l := -1;
            | Opcode.call   : l := 20;
            ELSE
              l := 1;
            END;
          END;
          proxy. length := l;
        END;
        RETURN proxy. length;
      END GetLength;
    
    PROCEDURE CalculateWeight (VAR list: Proxy);
      VAR
        proxy, defProxy, useProxy, ready, waiting: Proxy;
        res: SSA.Result;
        use, opnd: SSA.Opnd;
        max, degreeDiff: LONGINT;
        selectingValue: BOOLEAN;

      PROCEDURE CountAsRegister (arg: SSA.Result): BOOLEAN;
        BEGIN
          IF (arg.subclass = Opcode.scNone) OR
             (arg.instr.opcode = Opcode.set) THEN
            (* the "set" instruction's subclass is that of the memory location
               it writes to, but it does not produce a value in a register *)
            RETURN FALSE;
          ELSE
            RETURN ~(arg IS SSA.Instr) OR ~arg(SSA.Instr). IsConst();
          END;
        END CountAsRegister;
      
      BEGIN
        ready := NIL;
        waiting := NIL;
        WHILE (list # NIL) DO
          proxy := list;
          list := list. nextProxy;

          
          degreeDiff := 0;
          useCount := 0;
          IF (proxy. instr # NIL) THEN
            (* count outgoing values minus incoming values *)
            res := proxy. instr;
            WHILE (res # NIL) DO
              IF CountAsRegister (res) THEN
                INC (degreeDiff);
              END;
              res := res. nextResult;
            END;
            opnd := proxy. instr. opndList;
            WHILE (opnd # NIL) DO
              IF opnd. IsValueOpndHere() & CountAsRegister (opnd. arg) THEN
                DEC (degreeDiff);
              END;
              opnd := opnd. nextOpnd;
            END;
            
            (* count results that are used in the local region *)
            res := proxy. instr;
            WHILE (res # NIL) DO
              use := res. useList;
              WHILE (use # NIL) DO
                IF (use. instr. info(Proxy). region = r) THEN
                  INC (useCount);
                END;
                use := use. nextUse;
              END;
              res := res. nextResult;
            END;
          END;
          proxy. degreeDiff := degreeDiff;
          proxy. marker := useCount;
          IF (useCount = 0) THEN
            proxy. distance := proxy. length;
            Add (ready, proxy);
          ELSE
            Add (waiting, proxy);
          END;
        END;

        WHILE (ready # NIL) DO
          proxy := ready;
          Remove (ready, proxy);

          selectingValue := FALSE;
          max := 0;
          IF (proxy. instr # NIL) THEN
            res := proxy. instr;
            WHILE (res # NIL) DO
              use := res. useList;
              WHILE (use # NIL) DO
                useProxy := use. instr. info(Proxy);
                IF (useProxy. region = r) & (useProxy. distance > max) THEN
                  max := useProxy. distance;
                END;
                IF (use.instr.opcode = Opcode.select) &
                   (use.instr.opndList = use) THEN
                  selectingValue := TRUE;
                END;
                use := use. nextUse;
              END;
              res := res. nextResult;
            END;
                
            opnd := proxy. instr. opndList;
            WHILE (opnd # NIL) DO
              defProxy := opnd. arg. instr. info(Proxy);
              IF (defProxy. region = r) THEN
                DEC (defProxy. marker);
                IF (defProxy. marker = 0) THEN
                  Remove (waiting, defProxy);
                  Add (ready, defProxy);
                END;
              END;
              opnd := opnd. nextOpnd;
            END;
          END;
          IF ~selectingValue THEN
            (* only increase distance for non-selection operands, so that
               predicates are scheduled immediately in front of their
               "select" *)
            INC(max, GetLength(proxy));
          END;
          proxy. distance := max;
          
          proxy. nextProxy := list;
          list := proxy;
        END;
        ASSERT (waiting = NIL);
      END CalculateWeight;
    
    PROCEDURE CountLocalUses (VAR head: Proxy);
      VAR
        proxy: Proxy;
        opndCount: LONGINT;
        opnd: SSA.Opnd;
      BEGIN
        WHILE (head # NIL) DO
          proxy := head;
          head := head. nextProxy;

          (* count operands whose values are produced in the local region,
             and store the number in proxy.instr.marker *)
          opndCount := 0;
          IF (proxy. instr # NIL) THEN
            opnd := proxy. instr. opndList;
            WHILE (opnd # NIL) DO
              IF (opnd. arg. instr. info(Proxy). region = r) THEN
                INC (opndCount);
              END;
              opnd := opnd. nextOpnd;
            END;
            proxy. instr. marker := opndCount;
          END;
          IF (opndCount = 0) THEN
            Add (ready, proxy);
          ELSE
            ASSERT (proxy.instr # NIL);
            Add (waiting, proxy);
          END;
        END;
      END CountLocalUses;
    
    PROCEDURE UpdateUses (instr: SSA.Instr);
      VAR
        res: SSA.Result;
        use: SSA.Opnd;
        useProxy: Proxy;
      BEGIN
        res := instr;
        WHILE (res # NIL) DO
          use := res. useList;
          WHILE (use # NIL) DO
            useProxy := use. instr. info(Proxy);
            IF (useProxy. region = r) THEN
              DEC (use. instr. marker);
              IF (use. instr. marker = 0) THEN
                Remove (waiting, useProxy);
                Add (ready, useProxy);
              END;
            END;
            use := use. nextUse;
          END;
          res := res. nextResult;
        END;
      END UpdateUses;

    PROCEDURE NextInstr (ready: Proxy): Proxy;
      VAR
        best: Proxy;
      BEGIN
        best := ready;
        ready := ready. nextProxy;
        WHILE (ready # NIL) DO
          IF (ready. distance > best. distance) OR
             (ready. distance = best. distance) &
               (ready. degreeDiff < best. degreeDiff) THEN
            best := ready;
          END;
          ready := ready. nextProxy;
        END;
        RETURN best;
      END NextInstr;
    
    BEGIN
      (* for every instruction, write the number of operands that refer to
         results from the current region into its `marker' field; instructions
         with no such operands are placed in `ready', the rest is put into
         `waiting'  *)
      ready := NIL;
      waiting := NIL;
      r. last := NIL;
      CalculateWeight (r. first);
      CountLocalUses (r. first);
      
      (* remove instructions whose definitions have been scheduled already from
         `ready' and schedule them  *)
      WHILE (ready # NIL) DO
        proxy := NextInstr (ready);
        Remove (ready, proxy);
        UpdateUses (proxy. instr);
        ASSERT (proxy. region = r);
        proxy. region := NIL;
        r. Append (proxy);
      END;
      ASSERT (waiting = NIL);

      ready := r. first;
      WHILE (ready # NIL) DO
        IF (ready IS Region) THEN
          SortRegion (ready(Region));
        END;
        ready := ready. nextProxy;
      END;
    END SortRegion;

  PROCEDURE ClearRegion (r: Region);
    VAR
      p: Proxy;
    BEGIN
      p := r. first;
      WHILE (p # NIL) DO
        WITH p: Region DO
          ClearRegion (p);
          IF ~(p. region IS Select) THEN
            p. region := NIL;
          END;
        ELSE
          p. region := NIL;
        END;
        p := p. nextProxy;
      END;
      IF ~(r IS Select) THEN
        r. first := NIL;
        r. last := NIL;
      END;
    END ClearRegion;
  
  BEGIN
    (* get rid of dead instructions.  they cannot be put at their
       "right" place, because this would require using instructions ---
       and by definition dead code has no using instructions *)
    DeadCodeElimination.Transform (pb);

    RemoveAntiDeps (pb);
    pb. SetMarkers (NIL, 0);
    enter := pb. GetEnter();
    mainLoop := NewLoop (NIL);
    DiscoverLoopStructure (mainLoop, enter. GetResultStore(),
                           NIL, NIL);
    SortNestedLoops (mainLoop);
    (*WriteLoops (mainLoop, 0);*)
    AttachToLoop (mainLoop);

    LOOP
      (* for every instruction, write the number of uses into its `marker'
         field; instructions with no uses are placed in `ready', the rest
         is put into `waiting' *)
      ready := NewRegion (NIL);
      waiting := NewRegion (NIL);
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        useCount := 0;
        res := instr;
        WHILE (res # NIL) DO
          use := res. useList;
          WHILE (use # NIL) DO
            IF ~IgnoredUse (use) THEN
              INC (useCount);
            END;
            use := use. nextUse;
          END;
          res := res. nextResult;
        END;
        
        p := GetProxy (instr);
        instr. marker := useCount;
        IF (useCount = 0) THEN
          ready. Append (p);
        ELSE
          waiting. Append (p);
        END;
        instr := instr. nextInstr;
      END;

      (* the `ready' list must contain the "select-return" instruction;
         eliminate this instruction from the list and make it the root region*)
      p := ready. first;
      WHILE (p # NIL) & (p. instr. opcode # Opcode.selectReturn) DO
        p := p. nextProxy;
      END;
      ready. Remove (p);
      root := p(Region);

      (* remove instructions whose uses have been scheduled already from
         `ready' and schedule them into their region; this creates a hierarchy
         of regions containing all instructions  *)
      WHILE (ready. first # NIL) DO
        p := ready. first;
        ready. Remove (p);
        UpdateDefs (p);
        
        region := GetRegion (p);
        region. Insert (p);
      END;
      ASSERT (waiting. first = NIL);
      
      (* sort instructions within each newly created region *)
      AddRegionDeps (root);
      SortRegion (root);

<*IF DEBUG_BLOCKER THEN*>
      IF markAntiDeps THEN
        Log.Msg ("PRE ANTI-DEP VIOLATION");
        WriteBlocks (StdChannels.stderr, pb, root, Dictionary.New());
      END;
<*END*>
      IF markAntiDeps & AntiDepViolation (pb, root) THEN
        RemoveRegionDeps (pb);
        ClearRegion (root);
      ELSE
        EXIT;
      END;
    END;
    
<*IF DEBUG_BLOCKER THEN*>
    Check.All(pb);
<*END*>
    RETURN root;
  END ArrangeInstructions;



PROCEDURE GetDependenceData* (pb: SSA.ProcBlock): DependenceData;
(**Note: When done, call RemoveAntiDeps(pb) to remove auxiliary operands.  *)
  VAR
    dd: DependenceData;
    proxyMap: Dictionary.Dictionary;
    instr: SSA.Instr;
  BEGIN
    NEW (dd);
    dd. root := ArrangeInstructions (pb, FALSE);
    
    proxyMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      proxyMap. Set (instr, instr. info(Proxy));
      instr := instr. nextInstr;
    END;
    dd. proxyMap := proxyMap;
    
    RETURN dd;
  END GetDependenceData;

PROCEDURE (dd: DependenceData) SameRegion* (x, y: SSA.Instr): BOOLEAN;
(**Return @code{TRUE} if the region of @oparam{x} is that of
   @oparam{y}.  *)
  BEGIN
    RETURN (x.info(Proxy).region = y.info(Proxy).region);
  END SameRegion;

PROCEDURE (dd: DependenceData) Dominates* (x, y: SSA.Instr): BOOLEAN;
(**Return @code{TRUE} if the region of @oparam{x} dominates that of
   @oparam{y}.  *)
  BEGIN
    RETURN Dominates(x.info(Proxy).region, y.info(Proxy).region);
  END Dominates;

PROCEDURE (dd: DependenceData) Conflict* (x, y: SSA.Instr): BOOLEAN;
  VAR
    p: Object.Object;
    a, b: Region;
  BEGIN
    p := dd. proxyMap. Get (x);
    a := p(Proxy). region;
    p := dd. proxyMap. Get (y);
    b := p(Proxy). region;
    
    WHILE (a. nestingDepth > b. nestingDepth) DO
      a := a. region;
    END;
    WHILE (b. nestingDepth > a. nestingDepth) DO
      b := b. region;
    END;
    WHILE (a. region # b. region) DO
      a := a. region;
      b := b. region;
    END;
    RETURN (a. region # NIL) & (a. region IS Select) & (a # b);
  END Conflict;

PROCEDURE (dd: DependenceData) DependsOn* (x, y: SSA.Instr): BOOLEAN;
(**Return @code{TRUE} if instruction @oparam{x} depends on instruction
   @oparam{y}.  That is, result is @code{TRUE} if there is a sequence of
   result & use links leading from instruction @oparam{y} to @oparam{x}.  *)
  VAR
    visited: Dictionary.Dictionary;

  PROCEDURE PassesResult (res: SSA.Result): BOOLEAN;
    VAR
      use: SSA.Opnd;
    BEGIN
      WHILE (res # NIL) DO
        use := res. useList;
        WHILE (use # NIL) DO
          IF ~visited. HasKey (use. instr) THEN
            visited. Set (use. instr, NIL);
            IF (use. instr = x) OR PassesResult (use. instr) THEN
              RETURN TRUE;
            END;
          END;
          use := use. nextUse;
        END;
        res := res. nextResult;
      END;
      RETURN FALSE;
    END PassesResult;
  
  BEGIN
    visited := Dictionary.New();
    RETURN (x # y) & PassesResult (y);
  END DependsOn;

PROCEDURE (dd: DependenceData) AvailableTo* (x, y: SSA.Instr): BOOLEAN;
(**Return @code{TRUE} if the results of instruction @oparam{x} are available
   at the place of instruction @oparam{y}.  *)
  VAR
    xValue: SSA.Instr;
    xLoop: Loop;
    exit: SSA.Opnd;
  BEGIN
    (* a loop variant value is only available outside the loop, if it is
       available at the place of every loop exit; in this case, the value
       if available everywhere after the loop *)
    xValue := x;
    xLoop := x. info(Proxy). loopAssoc;
    WHILE (xLoop # NIL) & ~Dominates (xLoop, y. info(Proxy). region) DO
      exit := xLoop. instr. NthOpnd (2);
      WHILE (exit # NIL) & (exit. class = Opnd.storeExit) DO
        IF ~dd. AvailableTo (xValue, exit. arg. instr) THEN
          (* value `x' is not visible after the loop, and `y' is not part of
             the loop: we can abort with a nak *)
          RETURN FALSE;
        END;
        exit := exit. nextOpnd;
      END;
      xValue := xLoop. instr;
      xLoop := xLoop. loopAssoc;
    END;

    (* note: the test for `Dominates()' ensures that no common subexpressions
       are pulled out of two different selects, possibly past the guards that
       would prevent them from being executed at all *)
    RETURN
        Dominates (xValue. info(Proxy). region, y. info(Proxy). region) &
        ~dd. DependsOn (xValue, y);
  END AvailableTo;

PROCEDURE (dd: DependenceData) GetSameInstr*(regionInstr, instr: SSA.Instr): SSA.Instr;
  VAR
    region: Region;
    p: Proxy;
    opnd1, opnd2: SSA.Opnd;
    instr2: SSA.Instr;
  BEGIN
    region := regionInstr.info(Proxy).region;
    p := region.first;
    WHILE (p # NIL) DO
      instr2 := p.instr;
      IF (instr.opcode = instr2.opcode) &
         (instr.subclass = instr2.subclass) THEN
        opnd1 := instr.opndList;
        opnd2 := instr2.opndList;
        WHILE (opnd1 # NIL) & (opnd2 # NIL) & (opnd1.arg = opnd2.arg) DO
          opnd1 := opnd1.nextOpnd;
          opnd2 := opnd2.nextOpnd;
        END;
        IF (opnd1 = NIL) & (opnd2 = NIL) THEN  (* got a complete match *)
          RETURN instr2;
        END;
      END;
      p := p.nextProxy;
    END;
    RETURN NIL;
  END GetSameInstr;

PROCEDURE (dd: DependenceData) SetRegion*(regionInstr, instr: SSA.Instr);
  VAR
    p: Proxy;
  BEGIN
    p := NewProxy(instr);
    regionInstr.info(Proxy).region.Append(p);
    instr.info := p;
  END SetRegion;

PROCEDURE Write* (c: IO.ByteChannel; pb: SSA.ProcBlock);
  VAR
    root: Region;
  BEGIN
    root := ArrangeInstructions (pb, FALSE);
    WriteBlocks (c, pb, root, Dictionary.New());
    RemoveAntiDeps (pb);
  END Write;

PROCEDURE WriteMarker* (c: IO.ByteChannel; pb: SSA.ProcBlock;
                        marker: Dictionary.Dictionary);
  VAR
    root: Region;
  BEGIN
    root := ArrangeInstructions (pb, FALSE);
    WriteBlocks (c, pb, root, marker);
    RemoveAntiDeps (pb);
  END WriteMarker;

PROCEDURE ToStderr*(pb: SSA.ProcBlock);
  BEGIN
    Write(StdChannels.stderr, pb);
  END ToStderr;

END OOC:SSA:Blocker.
