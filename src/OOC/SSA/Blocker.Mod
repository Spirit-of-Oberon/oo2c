(* 	$Id$	 *)
MODULE OOC:SSA:Blocker;
(*  Imposes a block structure on a flat list of SSA instructions.
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
  Channel, TextRider, ADT:String, Dictionary := ADT:Dictionary:IntValue,
  OOC:SSA, OOC:SSA:Opcode;
  
(**

This module rearranges a flat list of SSA instructions into a
``blocked'' hierarchy of instructions.  The idea is that a block
contains a list of instructions that are evaluated under the same
guarding predicate.  The blocked representation is primarly used to
visualize SSA code, so that the code is better suited for human
interpretation.  Additionally, it is intended that is serves as the
starting point for creating the assembler output, where control flow
is realized by jump and branch instructions.

**)

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

   b) it contributes to the loop's back edge, or to the predicate 
      that determines the end of the loop.

3. Non-local exits: exit & return

   A block containing an EXIT or RETURN instruction effectively ends
   with this instruction.

4. Non-local exit from a loop: select-exit

   The select-exit defines a region which contains a single
   instruction, its corresponding loop-end.  Note that loop-end
   is itself a region.
      
5. Non-local merge of control flow: select-return

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
    instr-: SSA.Instr;
    region: Region;
    loopAssoc: Loop;
  END;
  RegionDesc = RECORD
    (ProxyDesc)
    first-, last-: Proxy;
    nestingDepth: LONGINT;
  END;
  SelectDesc = RECORD
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
    nextLoop: Loop;
    parentLoop: Loop;
    preceedingList: Preceeds;
    scheduled: BOOLEAN;
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
  END InitProxy;

PROCEDURE NewProxy (instr: SSA.Instr): Proxy;
  VAR
    p: Proxy;
  BEGIN
    NEW (p);
    InitProxy (p, instr);
    RETURN p;
  END NewProxy;

(* Region
   ------------------------------------------------------------------------ *)

PROCEDURE InitRegion (r: Region; instr: SSA.Instr);
  BEGIN
    InitProxy (r, instr);
    r. first := NIL;
    r. last := NIL;
    r. nestingDepth := 0;
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
      | Opcode.selectExit:
        p := NewRegion (instr);
      ELSE
        p := NewProxy (instr);
      END;
      instr. info := p;
      RETURN p;
    END;
  END GetProxy;

PROCEDURE ArrangeInstructions* (pb: SSA.ProcBlock): Region;
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
    VAR
      use: SSA.Opnd;
      instr, loopEnd: SSA.Instr;
      loopProxy: Loop;
      dummy: Proxy;

    PROCEDURE RegisterPreceeding (preceeding, following: Loop);
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
              DiscoverLoopStructure (loop,
                                     instr. GetResultStore(),
                                     endOfSearch, preceedingLoop);
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
  
  PROCEDURE AttachToLoop (loop: Loop);
    VAR
      loopStart: SSA.Instr;
      p: Proxy;
      
    PROCEDURE MarkUses (loopStart, instr: SSA.Instr);
      VAR
        res: SSA.Result;
        use: SSA.Opnd;
        p: Proxy;
      BEGIN
        res := instr;
        WHILE (res # NIL) DO
          use := res. useList;
          WHILE (use # NIL) DO
            p := GetProxy(use. instr);
            IF (p. loopAssoc = NIL) &
               ((p. instr. opcode # Opcode.selectExit) OR
                (p. instr. GetLoopStart() # loopStart)) THEN
              (* stop when we reach an instruction that has already been
                 attached to another loop, and also when we reach a
                 select-exit that belongs to the current loop *)
              p. loopAssoc := loop;
              MarkUses (loopStart, use. instr);
            END;
            use := use. nextUse;
          END;
          res := res. nextResult;
        END;
      END MarkUses;
    
    BEGIN
      IF (loop # NIL) THEN
        AttachToLoop (loop. nextLoop);
        AttachToLoop (loop. nestedLoops);
        IF (loop. instr # NIL) THEN
          loopStart := loop. instr. GetLoopStart();
          p := GetProxy (loopStart);
          p. loopAssoc := loop;
          MarkUses (loopStart, loopStart);
        END;
      END;
    END AttachToLoop;
  
  PROCEDURE IgnoredUse (use: SSA.Opnd): BOOLEAN;
    BEGIN
      (* skip all but the first operand of "select-exit", and all of
         "select-return" (the latter is automatically added as first
         instruction to the procedure block, its parents become live
         after that) *)
      RETURN
          (use. instr. opcode = Opcode.selectReturn) OR
          (use. instr. opcode = Opcode.selectExit) &
            (use. instr. opndList # use)
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
          IF (i = 0) THEN
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
        ELSIF (instr. opcode = Opcode.selectExit) &
              (opnd = instr. opndList) THEN
          (* place loop-end inside a loop-exit, if the latter exists *)
          RETURN instr. info(Region);
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
(*          IF (ptr # NIL) & (ptr. instr = NIL) & (ptr. region # NIL) THEN
            ptr := ptr. region;          (* skip path region with select *)
          END;*)
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
          IF (region. instr # NIL) &
             (region. instr. opcode = Opcode.selectExit) THEN
            (* also skip the select-exit around the loop on the way up *)
            region := region. region;
          END;
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
              IF (region = NIL) THEN
                region := useRegion;
              ELSE
                region := Merge (region, useRegion);
              END;
            END;
            use := use. nextUse;
          END;
          res := res. nextResult;        
        END;
        
        IF (region = NIL) THEN
          region := root;
        END;
      END;
      RETURN MoveLoopInvariants (CorrectForLoop (region));
    END GetRegion;

  (*PROCEDURE WriteLoops (l: Loop; indent: INTEGER);
    VAR
      i: INTEGER;
      n: Loop;
    BEGIN
      FOR i := 0 TO indent DO
        Out.String ("    ");
      END;
      Out.String ("loop: ");
      Out.Hex (SYSTEM.VAL(LONGINT,l), 8);
      Out.Ln;
      n := l. nestedLoops;
      WHILE (n # NIL) DO
        WriteLoops (n, indent+1);
        n := n. nextLoop;
      END;
    END WriteLoops;*)
  
  BEGIN
    pb. SetMarkers (NIL, 0);
    enter := pb. GetEnter();
    mainLoop := NewLoop (NIL);
    DiscoverLoopStructure (mainLoop, enter. GetResultStore(),
                           NIL, NIL);
    SortNestedLoops (mainLoop);
    (*WriteLoops (mainLoop, 0);*)
    AttachToLoop (mainLoop);
    
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
       elimiate this instruction from the ready list *)
    p := ready. first;
    WHILE (p # NIL) & (p. instr. opcode # Opcode.selectReturn) DO
      p := p. nextProxy;
    END;
    ready. Remove (p);
    root := p(Region);
    
    (* remove instructions whose uses have been scheduled already from `ready'
       and schedule them into their region *)
    WHILE (ready. first # NIL) DO
      p := ready. first;
      ready. Remove (p);
      UpdateDefs (p);

      region := GetRegion (p);
      region. Insert (p);
    END;
    ASSERT (waiting. first = NIL);
    
    RETURN root
  END ArrangeInstructions;

PROCEDURE Write* (c: Channel.Channel; pb: SSA.ProcBlock);
  VAR
    w: TextRider.Writer;
    idMap: Dictionary.Dictionary;
    instrCount: LONGINT;
    root: Region;
    
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
  
  PROCEDURE WriteInstr (p: Proxy);
    VAR
      instr: SSA.Instr;
      res: SSA.Result;
      opnd: SSA.Opnd;
      str: ARRAY 64 OF CHAR;
      i, resCount: LONGINT;
      
    PROCEDURE WriteResultId (res: SSA.Result);
      VAR
        id, count: LONGINT;
        ptr: SSA.Result;
        value: String.String;
      BEGIN
        instr := res. instr;
        IF instr. IsConst() THEN
          WITH instr: SSA.Const DO
            value := instr. value. ToString();
            w. WriteString (value. array^);
          | instr: SSA.DeclRef DO
            w. WriteString (instr. decl. name. str^);
          | instr: SSA.Address DO
            w. WriteChar ("&");
            w. WriteString (instr. decl. name. str^);
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
    
    BEGIN
      instr := p. instr;
      IF (instr = NIL) OR ~instr. IsConst() THEN
        (*w. WriteString ("L:");
        IF (p. loopAssoc # NIL) THEN
          WriteResultId (p. loopAssoc. instr);
        ELSE
          w. WriteString ("NIL");
        END;
        w. WriteString (09X);*)
        
        IF (p. region # NIL) THEN
          FOR i := 1 TO p. region. nestingDepth DO
            w. WriteString ("  ");
          END;
        END;
        
        IF (instr = NIL) THEN
          w. WriteString ("----");
        ELSE
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
          w. WriteChar (" ");
          
          opnd := instr. opndList;
          WHILE (opnd # NIL) DO
            IF (opnd # instr. opndList) THEN
              w. WriteChar (",");
            END;
            WriteResultId (opnd. arg);
            opnd := opnd. nextOpnd
          END;
        END;
        w. WriteLn;
      END;
    END WriteInstr;

  PROCEDURE WriteRegion (r: Region);
    VAR
      p: Proxy;
    BEGIN
      IF (r. instr = NIL) THEN
        WriteInstr (r);
      END;
      p := r. first;
      WHILE (p # NIL) DO
        WITH p: Region DO
          WriteRegion (p);
        ELSE
          WriteInstr (p);
        END;
        p := p. nextProxy;
      END;
      IF (r. instr # NIL) THEN
        WriteInstr (r);
      END;
    END WriteRegion;
  
  BEGIN
    root := ArrangeInstructions (pb);
    idMap := Dictionary.New();
    instrCount := 1;
    AssignId (root);

    w := TextRider.ConnectWriter (c);
    w. WriteLn;
    w. WriteString ("Procedure: ");
    w. WriteString (pb. procDecl. name. str^);
    w. WriteLn;
    WriteRegion (root);
  END Write;

END OOC:SSA:Blocker.
