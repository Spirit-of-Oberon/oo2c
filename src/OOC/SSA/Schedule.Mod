(* 	$Id: Schedule.Mod,v 1.39 2003/04/06 12:11:14 mva Exp $	 *)
MODULE OOC:SSA:Schedule [OOC_EXTENSIONS];
(*  Generates basic block representation and schedules instructions.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Object,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Blocker;

TYPE
  Block* = POINTER TO BlockDesc;
  InstrProxy* = POINTER TO InstrProxyDesc;
  BranchBlock* = POINTER TO BranchBlockDesc;
  JumpBlock* = POINTER TO JumpBlockDesc;
  DeadEndBlock* = POINTER TO DeadEndBlockDesc;
  SwitchBlock* = POINTER TO SwitchBlockDesc;
  
TYPE
  Info* = POINTER TO InfoDesc;
  InfoDesc* = RECORD
  END;
  
TYPE
  Dependent = POINTER TO DependentDesc;
  DependentDesc = RECORD
    next: Dependent;
    block: Block;
  END;

TYPE
  Jump* = POINTER TO JumpDesc;
  JumpDesc = RECORD
    src-: Block;
    (**Source block of the jump or branch instruction.  *)
    
    dest-: Block;
    (**Target of the jump.  *)
    
    nextTargetUse-: Jump;
    (**Next entry in target list @ofield{Block.targetUseList}.  *)

    isLoopBackedge-: BOOLEAN;
    (**@code{TRUE} iff this jump instruction returns control to the beginning
       of the loop.  This is equivalent to the target block of the jump
       instruction dominating the origin block:
       @samp{Dominates(@ofield{dest},@ofield{src})}.  *)
  END;
  
TYPE
  BlockDesc = RECORD [ABSTRACT]
    (Object.ObjectDesc)
    (**A basic block contains a sequence of instructions, with control flow
       entering at the beginning of the block, and leaving at the end of the
       block.  There are no jumps into the block, nor are there any jump or
       branch instructions except at the very end.  Please note that exceptions
       like failed run-time checks are @emph{not} treated as jumps or branches
       in this context.

       See the code of procedure @samp{Schedule.Check} for some of the
       invariants of the structure of the block hierarchy.  *)
    nextDom-: Block;
    (**Link for list of @ofield{Block.domList}.  *)

    parent-: Block;
    (**The block directory dominating this one.  For the root of the domitor
       tree, this field is @code{NIL}.  *)
       
    proxyList-, proxyTail-: InstrProxy;
    (**List with all instructions in this block.  *)

    domList-: Block;
    (**Lists all blocks directly dominated by this one.  The blocks are linked
       by @ofield{nextDom}.  Note: With the exception of @otype{SwitchBlock},
       the order of the blocks in this list is undefined.  *)

    dependentList: Dependent;
    (* lists blocks that should be written after this one *)
    depCount: LONGINT;
    (* number of blocks that should be written before this one can be written*)
    
    isLoopHead-: BOOLEAN;
    (**TRUE iff this block is the head of a loop *)

    targetUseList-: Jump;
    (**List of all jump or branch instructions that have this block as their
       target.  List entries are linked through @ofield{Jump.nextTargetUse}.  *)
    degreeIn-: LONGINT;
    (**The number of jumps or branches that have this block as target.  This is
       equivalent to the length of the list in @ofield{targetUseList}.  *)

    id-: LONGINT;
    (**The unique id of the block, starting at @samp{0}.  Blocks are numbered
       in the order in which they are written out.  That is, a block with
       a higher number is written further down in the output stream.  *)
       
    info*: Info;
    (**Field free for private use within algorithms operating on blocks.
       See @oproc{Block.SetInfo}.  *)
  END;
  
TYPE
  BranchBlockDesc = RECORD
    (BlockDesc)
    jump*: Jump;                     (* export rw for jump chaining *)
    (**Default target of control flow when leaving this block.
       This field is never @code{NIL}.  *)

    predicate-: SSA.Opnd;
    branchOnTrue*: BOOLEAN;             (* export rw for jump fixup *)
    branchTo*: Jump;                 (* export rw for jump chaining *)
  END;
  
TYPE
  JumpBlockDesc = RECORD
    (BlockDesc)
    jump*: Jump;                     (* export rw for jump chaining *)
    (**Target of control flow when leaving this block.
       This field is never @code{NIL}.  *)
  END;
  
TYPE
  DeadEndBlockDesc = RECORD
    (**A block at the very end of the control flow of a procedure.  There is
       no branch or jump instruction at the end of this block.  *)
    (BlockDesc)
  END;

TYPE
  SwitchBlockDesc = RECORD
    (**This block is translated into C's @code{switch} statement.  The
       @ofield{domList} contains exactly @samp{LEN(@ofield{jump}^)+1} blocks,
       one for each switch path, followed by the block immediately following
       the whole switch.  *)
    (BlockDesc)
    expr-: SSA.Opnd;
    jump-: POINTER TO ARRAY OF Jump;
    endOfPath: POINTER TO ARRAY OF JumpBlock;
    caseValues-: POINTER TO ARRAY OF SSA.Opnd;
  END;
  
TYPE
  InstrProxyDesc = RECORD
    (SSA.NodeDesc)
    nextProxy-, prevProxy-: InstrProxy;
    block-: Block;
    instr-: SSA.Instr;
  END;

  
PROCEDURE InitInfo* (info: Info);
  BEGIN
  END InitInfo;

PROCEDURE InitBlock (b: Block; dominator: Block);
  BEGIN
    b. proxyList := NIL;
    b. proxyTail := NIL;
    b. parent := dominator;
    IF (dominator # NIL) THEN
      b. nextDom := dominator. domList;
      dominator. domList := b;
    ELSE
      b. nextDom := NIL;
    END;
    b. domList := NIL;
    b. dependentList := NIL;
    b. depCount := 0;
    b. targetUseList := NIL;
    b. degreeIn := 0;
    b. isLoopHead := FALSE;
    b. id := -1;
    b. info := NIL;
  END InitBlock;

PROCEDURE (b: Block) SetInfo* (info: Info);
  VAR
    nested: Block;
  BEGIN
    b. info := info;
    nested := b. domList;
    WHILE (nested # NIL) DO
      nested. SetInfo (info);
      nested := nested. nextDom
    END;
  END SetInfo;

PROCEDURE (b: Block) DefaultTarget*(): Block;
(**The default target of the control flow when the end of this block is
   reached.  At the end of the procedure, the result is @code{NIL}.  For
   blocks that split the control flow, result is the fall through path.  *)
  BEGIN
    RETURN NIL
  END DefaultTarget;

PROCEDURE RevertDomList (b: Block);
  VAR
    new, old, next: Block;
  BEGIN
    new := NIL;
    old := b. domList;
    WHILE (old # NIL) DO
      next := old. nextDom;
      old. nextDom := new;
      new := old;
      old := next;
    END;
    b. domList := new;
  END RevertDomList;

PROCEDURE ClearJump (reference: Jump);
  PROCEDURE Remove (VAR list: Jump; entry: Jump);
    BEGIN
      IF (list = entry) THEN
        list := list. nextTargetUse
      ELSE
        Remove (list. nextTargetUse, entry)
      END;
    END Remove;
  
  BEGIN
    ASSERT (reference # NIL);
    DEC (reference. dest. degreeIn);
    Remove (reference. dest. targetUseList, reference); 
  END ClearJump;

PROCEDURE SetJump (VAR reference: Jump; src, dest: Block);
  PROCEDURE NewJump (src, dest: Block; nextTargetUse: Jump): Jump;
    VAR
      j: Jump;
    BEGIN
      NEW (j);
      j. src := src;
      j. dest := dest;
      j. nextTargetUse := nextTargetUse;
      j. isLoopBackedge := FALSE;
      RETURN j
    END NewJump;
  
  BEGIN
    ASSERT (reference = NIL);
    INC (dest. degreeIn);
    reference := NewJump (src, dest, dest. targetUseList);
    dest. targetUseList := reference
  END SetJump;

PROCEDURE Dominates* (dominator, child: Block): BOOLEAN;
  BEGIN
    WHILE (child # NIL) & (child # dominator) DO
      child := child. parent
    END;
    RETURN (child # NIL)
  END Dominates;

PROCEDURE ChangeJumpTarget* (reference: Jump; dest: Block);
  BEGIN
    ASSERT (reference # NIL);
    
    ClearJump (reference);
    
    INC (dest. degreeIn);
    reference. dest := dest;
    reference. isLoopBackedge :=
        dest. isLoopHead & Dominates (dest, reference. src);
    reference. nextTargetUse := dest. targetUseList;
    
    dest. targetUseList := reference
  END ChangeJumpTarget;

PROCEDURE ChangeTargets (oldTarget, newTarget: Block);
(**Change all jumps to @oparam{oldTarget} to go to @oparam{newTarget}.  *)
  BEGIN
    ASSERT (oldTarget # newTarget);

    WHILE (oldTarget. targetUseList # NIL) DO
      ChangeJumpTarget (oldTarget. targetUseList, newTarget);
    END;
  END ChangeTargets;


PROCEDURE InitBranchBlock (b: BranchBlock; dominator: Block;
                           predicate: SSA.Opnd; branchOnTrue: BOOLEAN);
  BEGIN
    InitBlock (b, dominator);
    b. jump := NIL;
    b. predicate:= predicate;
    b. branchOnTrue := branchOnTrue;
    b. branchTo := NIL;
  END InitBranchBlock;

PROCEDURE NewBranchBlock (dominator: Block; predicate: SSA.Opnd;
                          branchOnTrue: BOOLEAN): BranchBlock;
  VAR
    b: BranchBlock;
  BEGIN
    NEW (b);
    InitBranchBlock (b, dominator, predicate, branchOnTrue);
    RETURN b
  END NewBranchBlock;

PROCEDURE (b: BranchBlock) DefaultTarget*(): Block;
  BEGIN
    IF (b. branchTo. dest IS JumpBlock) &
       b. branchTo. dest(JumpBlock). jump. isLoopBackedge THEN
      RETURN b. branchTo. dest;
    ELSE
      RETURN b. jump. dest;
    END;
  END DefaultTarget;


PROCEDURE InitJumpBlock (b: JumpBlock; dominator: Block);
  BEGIN
    InitBlock (b, dominator);
    b. jump := NIL;
  END InitJumpBlock;

PROCEDURE NewJumpBlock(dominator: Block): JumpBlock;
  VAR
    b: JumpBlock;
  BEGIN
    NEW (b);
    InitJumpBlock (b, dominator);
    RETURN b
  END NewJumpBlock;

PROCEDURE (b: JumpBlock) DefaultTarget*(): Block;
  BEGIN
    RETURN b. jump. dest
  END DefaultTarget;


PROCEDURE InitDeadEndBlock (b: DeadEndBlock; dominator: Block);
  BEGIN
    InitBlock (b, dominator);
  END InitDeadEndBlock;

PROCEDURE NewDeadEndBlock (dominator: Block): DeadEndBlock;
  VAR
    b: DeadEndBlock;
  BEGIN
    NEW (b);
    InitDeadEndBlock (b, dominator);
    RETURN b
  END NewDeadEndBlock;

PROCEDURE (b: DeadEndBlock) DefaultTarget*(): Block;
  BEGIN
    RETURN NIL
  END DefaultTarget;


PROCEDURE InitSwitchBlock (b: SwitchBlock; dominator: Block;
                           expr: SSA.Opnd; paths: LONGINT);
  VAR
    i: LONGINT;
  BEGIN
    InitBlock (b, dominator);
    b. expr := expr;
    NEW (b. jump, paths);
    NEW (b. endOfPath, paths);
    NEW (b. caseValues, paths);
    FOR i := 0 TO paths-1 DO
      b. jump[i] := NIL; b. endOfPath[i] := NIL; b. caseValues[i] := NIL;
    END;
  END InitSwitchBlock;

PROCEDURE NewSwitchBlock (dominator: Block; expr: SSA.Opnd;
                          paths: LONGINT): SwitchBlock;
  VAR
    b: SwitchBlock;
  BEGIN
    NEW (b);
    InitSwitchBlock (b, dominator, expr, paths);
    RETURN b
  END NewSwitchBlock;

PROCEDURE (b: SwitchBlock) DefaultTarget*(): Block;
  BEGIN
    RETURN NIL;
  END DefaultTarget;



PROCEDURE InitInstrProxy (proxy: InstrProxy; instr: SSA.Instr);
  BEGIN
    SSA.InitNode (proxy);
    proxy. nextProxy := NIL;
    proxy. prevProxy := NIL;
    proxy. block := NIL;
    proxy. instr := instr;
  END InitInstrProxy;

PROCEDURE NewInstrProxy (instr: SSA.Instr): InstrProxy;
  VAR
    proxy: InstrProxy;
  BEGIN
    NEW (proxy);
    InitInstrProxy (proxy, instr);
    RETURN proxy
  END NewInstrProxy;

PROCEDURE AppendProxy (b: Block; proxy: InstrProxy);
  BEGIN
    proxy. block := b;
    proxy. prevProxy := b. proxyTail;
    proxy. nextProxy := NIL;
    IF (b. proxyTail = NIL) THEN
      b. proxyList := proxy
    ELSE
      b. proxyTail. nextProxy := proxy
    END;
    b. proxyTail := proxy;
  END AppendProxy;


PROCEDURE TransferInstructions (region: Blocker.Region; block: JumpBlock): JumpBlock;
(**Transfers all instructions in @oparam{region} into @oparam{block}.  The
   given @oparam{block} directly dominates @oparam{region}.  That is, any
   path of control leading up to @oparam{region}'s instructions end with
   @oparam{block}.

   Result is the instruction block that directly dominates any instructions
   following @oparam{region}.  *)
  VAR
    bProxy: Blocker.Proxy;
    proxy: InstrProxy;
    newBlock: JumpBlock;

  PROCEDURE TransferSelect (select: Blocker.Select; block: JumpBlock): JumpBlock;
    VAR
      branch: BranchBlock;
      switch: SwitchBlock;
      path1, path2, path, out: JumpBlock;
      paths, i: LONGINT;
      opnd: SSA.Opnd;
    BEGIN
      IF select. instr. IsSwitchStatm() THEN
        (* this select represents a CASE statement *)
        paths := select. instr. CountOpndClass (Opnd.labels);
        switch := NewSwitchBlock (block, select. instr. opndList, paths);
        SetJump (block. jump, block, switch);

        opnd := select. instr. opndList. nextOpnd;
        FOR i := 0 TO paths-1 DO
          switch. caseValues[i] := opnd;
          
          path := NewJumpBlock (switch);
          SetJump (switch. jump[i], switch, path);
          switch. endOfPath[i] := TransferInstructions (select.paths[i], path);
          opnd := opnd. nextOpnd. nextOpnd;
        END;
        
        out := NewJumpBlock (switch);
        FOR i := 0 TO paths-1 DO
          SetJump (switch. endOfPath[i]. jump, switch. endOfPath[i], out);
        END;
        RevertDomList (switch);
        
        RETURN out
      ELSE                               (* a "normal" IF statement *)
        branch := NewBranchBlock
            (block,
             select. instr. opndList,
             select. instr. opndList. nextOpnd. arg. IsBooleanConst (TRUE));
        SetJump (block. jump, block, branch);
        
        path1 := NewJumpBlock (branch);
        SetJump (branch. branchTo, branch, path1);
        path1 := TransferInstructions (select. paths[0], path1);
        
        path2 := NewJumpBlock (branch);
        SetJump (branch. jump, branch, path2);
        path2 := TransferInstructions (select. paths[1], path2);
        
        out := NewJumpBlock (branch);
        SetJump (path1. jump, path1, out);
        SetJump (path2. jump, path2, out);
        RETURN out
      END;
    END TransferSelect;
  
  PROCEDURE TransferLoop (loop: Blocker.Loop; block: JumpBlock): JumpBlock;
    VAR
      body, bodyEnd, out, exit: JumpBlock;
      opnd: SSA.Opnd;
      loopEnd: SSA.Instr;
    BEGIN
      (* transfer instructions of loop body *)
      body := NewJumpBlock (block);
      body. isLoopHead := TRUE;
      SetJump (block. jump, block, body);
      bodyEnd := TransferInstructions (loop, body);

      loopEnd := loop. instr;
      ASSERT (loopEnd # NIL);
      SetJump (bodyEnd. jump, bodyEnd, body);
      
      (* fixup blocks with exit instructions to jump to the end of the loop;
         the end of the loop `out' is dominated by the beginning of the loop
         body, although flow of control must pass through one of the loop's
         exit paths before it ends up there  *)
      out := NewJumpBlock (body);
      opnd := loopEnd. NthOpnd (2);
      WHILE (opnd # NIL) & (opnd. class = Opnd.storeExit) DO
        exit := opnd. arg. instr. info(InstrProxy). block(JumpBlock);
        ChangeJumpTarget (exit. jump, out);
        opnd := opnd. nextOpnd;
      END;
      RETURN out;
    END TransferLoop;
  
  BEGIN
    bProxy := region. first;
    WHILE (bProxy # NIL) DO
      proxy := NewInstrProxy (bProxy. instr);
      bProxy. instr. info := proxy;
      
      WITH bProxy: Blocker.Loop DO
        block := TransferLoop (bProxy, block);
      | bProxy: Blocker.Select DO
        block := TransferSelect (bProxy, block);
      | bProxy: Blocker.Region DO        (* this is a "select-exit" *)
        block := TransferInstructions (bProxy, block);
      ELSE
        (* nothing to do *)
      END;
      
      AppendProxy (block, proxy);
      IF (proxy. instr. opcode = Opcode.exit) THEN
        (* set block end with an EXIT instruction, and move the rest of
           the instructions into a new block *)
        newBlock := NewJumpBlock (block);
        SetJump (block. jump, block, newBlock);
        block := newBlock;
      END;
      
      bProxy := bProxy. nextProxy;
    END;
    RETURN block;
  END TransferInstructions;


PROCEDURE Schedule* (pb: SSA.ProcBlock): Block;
(**Takes a procedure representation in SSA format and converts it into a graph
   representation consisting of basic blocks.  *)
  VAR
    b, lastBlock: JumpBlock;
    root: Blocker.Region;
    proxy: InstrProxy;
    count: LONGINT;
    
  PROCEDURE ArrangeBlock (b: Block);
  (* arrange children within each block in such way that loop branches have a
     target earlier in the linear chain of blocks, and all other jumps and
     branches a target later in the chain  *)
    VAR
      nested: Block;
      
    PROCEDURE LocateJumps (path: Block; b: Block);
    (* find all jumps in or below `b' that have the parent of `path' as
       the parent of their target; for every jump, add a dependency from `path'
       to the child of `path.parent' containg the jump target *)
      VAR
        nested: Block;
        i: LONGINT;
        
      PROCEDURE ProcessJump (target: Block);
        PROCEDURE WriteBefore (VAR dependentList: Dependent; b: Block);
          BEGIN
            IF (dependentList = NIL) THEN
              ASSERT (b. parent = path. parent);
              NEW (dependentList);
              dependentList. block := b;
              dependentList. next := NIL;
              INC (b. depCount);
            ELSIF (dependentList. block # b) THEN
              WriteBefore (dependentList. next, b)
            END;
          END WriteBefore;
        
        BEGIN
          IF (target # path. parent) THEN
            WHILE (target # NIL) & (target. parent # path. parent) DO
              target := target. parent
            END;
            IF (target # NIL) & (target # path) THEN
              WriteBefore (path. dependentList, target)
            END;
          END;
        END ProcessJump;
      
      BEGIN
        WITH b: BranchBlock DO
          ProcessJump (b. branchTo. dest);
          ProcessJump (b. jump. dest);
        | b: JumpBlock DO
          ProcessJump (b. jump. dest);
        | b: DeadEndBlock DO
          (* nowhere to go *)
        | b: SwitchBlock DO
          FOR i := 0 TO LEN (b. jump^)-1 DO
            ProcessJump (b. jump[i]. dest);
          END;
        END;
        
        nested := b. domList;
        WHILE (nested # NIL) DO
          LocateJumps (path, nested);
          nested := nested. nextDom
        END;
      END LocateJumps;

    PROCEDURE AddToList (VAR list: Block; b: Block);
      BEGIN
        b. nextDom := list;
        list := b
      END AddToList;

    PROCEDURE AppendToList (VAR list: Block; b: Block);
      BEGIN
        IF (list = NIL) THEN
          b. nextDom := NIL;
          list := b
        ELSE
          AppendToList (list. nextDom, b)
        END;
      END AppendToList;

    PROCEDURE RemoveFromList (VAR list: Block; b: Block);
      BEGIN
        IF (list = b) THEN
          list := list. nextDom
        ELSE
          RemoveFromList (list. nextDom, b)
        END;
      END RemoveFromList;

    PROCEDURE In (list: Block; b: Block): BOOLEAN;
      VAR
        ptr: Block;
      BEGIN
        ptr := list;
        WHILE (ptr # NIL) & (ptr # b) DO
          ptr := ptr. nextDom;
        END;
        RETURN (ptr # NIL);
      END In;

    PROCEDURE SortBlocks (domBlock: Block);
    (* sort nested blocks of `domBlock' topologically: if block A contains
       a jump to block B, then place block A before block B *)
      VAR
        b, nested, next, ready, waiting, preferedBlock: Block;
        dep: Dependent;
      BEGIN
        ready := NIL; waiting := NIL;
        nested := domBlock. domList;
        WHILE (nested # NIL) DO
          next := nested. nextDom;
          IF (nested. depCount = 0) THEN
            AddToList (ready, nested)
          ELSE
            AddToList (waiting, nested)
          END;
          nested := next
        END;
        
        domBlock. domList := NIL;
        preferedBlock := domBlock. DefaultTarget();
        WHILE (ready # NIL) DO
          IF (preferedBlock # NIL) & In (ready, preferedBlock) THEN
            b := preferedBlock
          ELSE
            b := ready
          END;
          
          RemoveFromList (ready, b);
          ASSERT (b. parent = domBlock);
          AppendToList (domBlock. domList, b);
          b. depCount := -1;
          
          dep := b. dependentList;
          WHILE (dep # NIL) DO
            DEC (dep. block. depCount);
            IF (dep. block. depCount = 0) THEN
              RemoveFromList (waiting, dep. block);
              AddToList (ready, dep. block)
            END;
            dep := dep. next
          END;
          preferedBlock := b. DefaultTarget();
        END;
        ASSERT (waiting = NIL)
      END SortBlocks;
    
    BEGIN
      (* recursively process all nested blocks *)
      nested := b. domList;
      WHILE (nested # NIL) DO
        ArrangeBlock (nested);
        nested := nested. nextDom
      END;

      (* sort nested blocks, but leave the relative ordering of children
         of switch blocks as it is *)
      IF ~(b IS SwitchBlock) THEN
        nested := b. domList;
        WHILE (nested # NIL) DO
          nested. dependentList := NIL;
          nested. depCount := 0;
          nested := nested. nextDom
        END;
        
        nested := b. domList;
        WHILE (nested # NIL) DO
          LocateJumps (nested, nested);
          nested := nested. nextDom
        END;
        
        SortBlocks (b);
      END;
    END ArrangeBlock;

  PROCEDURE MarkBackedges (b: Block);
    VAR
      nested: Block;
      i: LONGINT;

    PROCEDURE Check (jump: Jump);
      BEGIN
        jump. isLoopBackedge := Dominates (jump. dest, b);
      END Check;
    
    BEGIN
      WITH b: JumpBlock DO
        Check (b. jump)
      | b: BranchBlock DO
        Check (b. branchTo);
        Check (b. jump)
      | b: DeadEndBlock DO
        (* nowhere to go *)
      | b: SwitchBlock DO
        FOR i := 0 TO LEN (b. jump^)-1 DO
          Check (b. jump[i]);
        END;
      END;

      nested := b. domList;
      WHILE (nested # NIL) DO
        MarkBackedges (nested);
        nested := nested. nextDom
      END;
    END MarkBackedges;

  PROCEDURE RemoveUnreachable (VAR b: Block);
  (* Note: This procedure does not eliminate blocks that contain the end marker
     of a block, like @oconst{Opcode.loopEnd} or @oconst{Opcode.selectReturn},
     even if they are unreachable.  *)
    VAR
      d: LONGINT;
      j: Jump;

    PROCEDURE ContainsEndOfBlock (b: Block): BOOLEAN;
      VAR
        proxy: InstrProxy;
      BEGIN
        proxy := b. proxyList;
        WHILE (proxy # NIL) DO
          CASE proxy. instr. opcode OF
          | Opcode.selectReturn, Opcode.loopEnd:
            RETURN TRUE;
          ELSE
          END;
          proxy := proxy. nextProxy;
        END;
        RETURN FALSE;
      END ContainsEndOfBlock;
    
    BEGIN
      IF (b # NIL) THEN
        d := b. degreeIn;
        IF b. isLoopHead THEN
          (* don't count jumps originating in the loop itself here *)
          j := b. targetUseList;
          WHILE (j # NIL) DO
            IF j. isLoopBackedge THEN
              DEC (d);
            END;
            j := j. nextTargetUse;
          END;
        END;
        IF (d = 0) & ContainsEndOfBlock (b) THEN
          (* the block may be unreachable, but the current C back-end needs
             it (or rather, the "select-return" and "loop-end") to get its
             stuff right *)
          INC (d);
        END;
        
        IF (d = 0) THEN
          ASSERT (b. targetUseList = NIL);
          
          (* the block has no incoming jumps, that is, it is unreachable *)
          WITH b: JumpBlock DO
            ClearJump (b. jump);
          | b: BranchBlock DO
            ClearJump (b. jump);
            ClearJump (b. branchTo);
          | b: SwitchBlock DO
            ASSERT (FALSE);
          | b: DeadEndBlock DO
            (* nothing *)
          END;
        END;
        
        RemoveUnreachable (b. domList);
        RemoveUnreachable (b. nextDom);
        
        IF (d = 0) THEN
          ASSERT (b. domList = NIL);
          b := b. nextDom;
        END;
      END;
    END RemoveUnreachable;
  
  PROCEDURE RemoveEmpty (VAR b: Block);
    BEGIN
      IF (b # NIL) THEN
        RemoveEmpty (b. domList);
        RemoveEmpty (b. nextDom);
        
        IF (b IS JumpBlock) &
           (b. proxyList = NIL) &
           ~(b. parent IS SwitchBlock) &
           (b(JumpBlock). jump. dest # b) THEN
          ChangeTargets (b, b(JumpBlock). jump. dest);
          ASSERT (b. targetUseList = NIL);
          ClearJump (b(JumpBlock). jump);
          b(JumpBlock). jump := NIL;
          
          IF (b. domList # NIL) THEN
            ASSERT (b. domList. nextDom = NIL);
            b. domList. nextDom := b. nextDom;
            b. domList. parent := b. parent;
            b := b. domList;
          ELSE
            b := b. nextDom;
          END;
        END;
      END;
    END RemoveEmpty;
  
  PROCEDURE NumberBlocks (b: Block; VAR count: LONGINT);
    VAR
      nested: Block;
    BEGIN
      b. id := count;
      INC (count);
      
      nested := b. domList;
      WHILE (nested # NIL) DO
        NumberBlocks (nested, count);
        nested := nested. nextDom
      END;
    END NumberBlocks;

  (*PROCEDURE WriteBlocks (b: Block; indent: LONGINT);
    VAR
      nested: Block;
      i: LONGINT;
    BEGIN
      IF b. isLoopHead THEN
        Err.String ("L ");
      ELSE
        Err.String ("  ");
      END;
      Err.Hex (SYSTEM.VAL (LONGINT, b), 8);
      FOR i := 1 TO indent DO
        Err.String ("  ");
      END;
      Log.Type ("+ block", b);

      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        Err.String ("  ");
        Err.Hex (0, 8);
        FOR i := 1 TO indent DO
          Err.String ("  ");
        END;
        Err.String ("  ");
        proxy. instr. LogOpcode ("instr");
        proxy := proxy. nextProxy;
      END;
      
      nested := b. domList;
      WHILE (nested # NIL) DO
        WriteBlocks (nested, indent+1);
        nested := nested. nextDom;
      END;
    END WriteBlocks;*)
  
  PROCEDURE Check (b: Block);
  (* Sanity checks on the generated blocks, their instructions, and their
     domination topology.  *)
    VAR
      nested: Block;
      proxy, select: InstrProxy;
      i: LONGINT;
    BEGIN
      (* `collect' instructions may not appear in a branch block.  *)
      IF ~(b IS JumpBlock) THEN
        proxy := b. proxyList;
        WHILE (proxy # NIL) DO
          ASSERT (proxy. instr. opcode # Opcode.collect);
          proxy := proxy. nextProxy
        END;
      END;
      
      (* If the block merges control flow, that is, if it has an inbound degree
         larger than 1, then it must contain exactly one instruction that
         identifies all incoming paths of control.  *)
      IF (b. degreeIn > 1) THEN
        select := NIL;
        proxy := b. proxyList;
        WHILE (proxy # NIL) DO
          CASE proxy. instr. opcode OF
          | Opcode.select, Opcode.loopStart, Opcode.loopEnd:
            ASSERT (select = NIL);
            select := proxy;
          ELSE
          END;
          proxy := proxy. nextProxy
        END;
      END;

      WITH b: SwitchBlock DO
        (* A switch statement directly dominates exactly as many blocks as
           there are paths through the switch, plus one block for the code
           following the switch.  *)
        (*nested := b. domList;
        FOR i := 0 TO LEN (b. jump^)-1 DO
          Log.Ptr("nested",nested);
          Log.Ptr("jump[i].dest", b.jump[i].dest);
          Log.Ptr("endOfPath[i]",b.endOfPath[i]);
          nested := nested. nextDom;
        END;*)
        nested := b. domList;
        FOR i := 0 TO LEN (b. jump^)-1 DO
          ASSERT (b. jump[i]. dest = nested);
          nested := nested. nextDom;
        END;
        ASSERT (nested # NIL);
        ASSERT (nested. nextDom = NIL);

      | b: JumpBlock DO
        IF b. jump. isLoopBackedge THEN
          (* A block ending with a jump to the beginning of a loop dominates
             no other blocks, unless it is the loop body itself.  *)
          IF ~b. isLoopHead THEN
            ASSERT (b. domList = NIL);
          END;
        ELSIF (b. domList # NIL) THEN
          IF b. isLoopHead THEN
            (* A loop always begins with a jump block containing the prefix
               of the loop body (which includes at least the "loop-start"
               instruction).  This block jumps to the rest of the loop
               body, and therefore dominates it directly.  The second block
               dominates by the loop block holds the code that follows the
               loop.  There are not other blocks that are directly dominated
               by a loop block.

               The second block may be eliminated, if the loop prefix jumps
               back unconditionally to the loop beginning, or there is no
               code that follows the loop. *)
            IF (b. domList. nextDom # NIL) THEN
              ASSERT (b. domList. nextDom. nextDom = NIL);
            END;
          ELSE
            (* For a non-loop jump block (that isn't a loop back-edge),
               at most one other block dominated by it.  This block is
               also the target of the jump, unless the nested block is
               unreachable (e.g., because it follows an EXIT or RETURN).  *)
            ASSERT (b. domList. nextDom = NIL);
            IF (b. domList. degreeIn # 0) THEN
              ASSERT (b. jump. dest = b. domList);
            END;
          END;
        END;

      | b: DeadEndBlock DO
        (* A dead end dominates nothing.  *)
        ASSERT (b. domList = NIL);
      ELSE
      END;
      
      nested := b. domList;
      WHILE (nested # NIL) DO
        Check (nested);
        nested := nested. nextDom
      END;
    END Check;

  PROCEDURE MoveSelectReturn (root: Blocker.Region; block: Block);
    VAR
      proxy: InstrProxy;
    BEGIN
      proxy := NewInstrProxy (root. instr);
      root. instr. info := proxy;
      AppendProxy (block, proxy);
    END MoveSelectReturn;
  
  BEGIN
    (*Blocker.Write (StdChannels.stdout, pb);*)
    
    root := Blocker.ArrangeInstructions (pb, TRUE);
    proxy := NewInstrProxy (root. instr);
    root. instr. info := proxy;
    b := NewJumpBlock (NIL);
    lastBlock := TransferInstructions (root, b);
    MoveSelectReturn (root, lastBlock);
    SetJump (lastBlock. jump, lastBlock, NewDeadEndBlock (lastBlock));
    
    (* mark jump instructions that are loop backedges *)
    MarkBackedges (b);

    (* remove unreachable and empty blocks *)
    RemoveUnreachable (b. domList);
    RemoveEmpty (b. domList);

    (* some santity checks; this is mostly for debug purposes *)
    Check(b);
    
    (* note: if ArrangeInstructions does not return a valid schedule, then
       the instructions within each basic block must be reordered here *)
    
    (* arrange dominated blocks within each block in such way that
       loop branches have a target earlier in the chain of blocks, and all
       other jumps and branches a target later in the chain *)
    ArrangeBlock (b);

    (* assign unique ids to the blocks; the ids reflect the ordering
       of the blocks when written out *)
    count := 0;
    NumberBlocks (b, count);

    (* remove anti-dependency pseudo operands *)
    Blocker.RemoveAntiDeps (pb);
    
    b. degreeIn := 1;  (* the root block is reached by exactly one edge *)
    RETURN b
  END Schedule;

END OOC:SSA:Schedule.
