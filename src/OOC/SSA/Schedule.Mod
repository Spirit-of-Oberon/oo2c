(* 	$Id$	 *)
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
  ADT:Object, OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Blocker;

TYPE
  Block* = POINTER TO BlockDesc;
  InstrProxy* = POINTER TO InstrProxyDesc;
  BranchBlock* = POINTER TO BranchBlockDesc;
  JumpBlock* = POINTER TO JumpBlockDesc;
  DeadEndBlock* = POINTER TO DeadEndBlockDesc;

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
       in this context.  *)
    nextDom-: Block;
    (**Link for list of @ofield{Block.domList}.  *)

    parent-: Block;
    (**The block directory dominating this one.  For the root of the domitor
       tree, this field is @code{NIL}.  *)
       
    proxyList-, proxyTail-: InstrProxy;
    (**List with all instructions in this block.  *)

    domList-: Block;
    (**Lists all blocks directly dominated by this one.  The blocks are linked
       by @ofield{nextDom}.  *)

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
    
    info*: Info;
    (**Field free for private use within algorithms operating on blocks.
       See @oproc{Block.SetInfo}.  *)
  END;
  
TYPE
  BranchBlockDesc = RECORD
    (BlockDesc)
    jump-: Jump;
    (**Default target of control flow when leaving this block.
       This field is never @code{NIL}.  *)

    predicate-: SSA.Opnd;
    branchOnTrue-: BOOLEAN;
    branchTo-: Jump;
  END;
  
TYPE
  JumpBlockDesc = RECORD
    (BlockDesc)
    jump-: Jump;
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
    Object.Init (b);
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

PROCEDURE SetJump (VAR reference: Jump; src, dest: Block);
  PROCEDURE NewJump (src, dest: Block; nextTargetUse: Jump): Jump;
    VAR
      j: Jump;
    BEGIN
      NEW (j);
      j. src := src;
      j. dest := dest;
      j. nextTargetUse := nextTargetUse;
      RETURN j
    END NewJump;

  PROCEDURE Remove (VAR list: Jump; entry: Jump);
    BEGIN
      IF (list = entry) THEN
        list := list. nextTargetUse
      ELSE
        Remove (list. nextTargetUse, entry)
      END;
    END Remove;
  
  BEGIN
    IF (reference # NIL) THEN
      DEC (reference. dest. degreeIn);
      Remove (reference. dest. targetUseList, reference); 
    END;
    INC (dest. degreeIn);
    reference := NewJump (src, dest, dest. targetUseList);
    dest. targetUseList := reference
  END SetJump;

PROCEDURE ClearProxyList (b: Block);
  BEGIN
    b. proxyList := NIL;
    b. proxyTail := NIL;
  END ClearProxyList;

PROCEDURE Dominates* (dominator, child: Block): BOOLEAN;
  BEGIN
    WHILE (child # NIL) & (child # dominator) DO
      child := child. parent
    END;
    RETURN (child # NIL)
  END Dominates;


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

PROCEDURE RemoveProxy (b: Block; proxy: InstrProxy);
  BEGIN
    IF (proxy. prevProxy # NIL) THEN
      proxy. prevProxy. nextProxy := proxy. nextProxy
    ELSE
      b. proxyList := proxy. nextProxy
    END;
    IF (proxy. nextProxy # NIL) THEN
      proxy. nextProxy. prevProxy := proxy. prevProxy
    ELSE
      b. proxyTail := proxy. prevProxy
    END;
    proxy. nextProxy := NIL;
    proxy. prevProxy := NIL;
    proxy. block := NIL;
  END RemoveProxy;

PROCEDURE MoveProxy (proxy: InstrProxy; to: Block);
  BEGIN
    RemoveProxy (proxy. block, proxy);
    AppendProxy  (to, proxy)
  END MoveProxy;


PROCEDURE TransferInstructions (region: Blocker.Region; block: JumpBlock): JumpBlock;
  VAR
    bProxy: Blocker.Proxy;
    proxy: InstrProxy;
    newBlock: JumpBlock;

  PROCEDURE TransferSelect (select: Blocker.Select; block: JumpBlock): JumpBlock;
    VAR
      branch: BranchBlock;
      path1, path2, out: JumpBlock;
    BEGIN
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
    END TransferSelect;
  
  PROCEDURE TransferLoop (loop: Blocker.Loop; block: JumpBlock): JumpBlock;
    VAR
      body, bodyEnd, backward, out, exit: JumpBlock;
      branch: BranchBlock;
      predicate, opnd: SSA.Opnd;
      loopStart, selectExit: SSA.Instr;
      backwardStore: SSA.Result;
    BEGIN
      (* transfer instructions of loop body *)
      body := NewJumpBlock (block);
      SetJump (block. jump, block, body);
      bodyEnd := TransferInstructions (loop, body);

      predicate := loop. instr. NthOpnd (2);
      IF (predicate. arg. instr. opcode = Opcode.selectExit) THEN
        selectExit := predicate. arg. instr;
        SetJump (bodyEnd. jump, bodyEnd, body);

        (* fixup blocks with exit instructions to jump to the end of the
           loop *)
        out := NewJumpBlock (block);
        opnd := selectExit. opndList. nextOpnd;
        WHILE (opnd # NIL) DO
          exit := opnd. arg. instr. info(InstrProxy). block(JumpBlock);
          SetJump (exit. jump, exit, out);
          opnd := opnd. nextOpnd;
        END;
      ELSE
        (* attach a branch block to the end of the loop body *)
        branch := NewBranchBlock
            (bodyEnd, predicate,
             predicate. nextOpnd. arg. IsBooleanConst (FALSE));
        SetJump (bodyEnd. jump, bodyEnd, branch);
        
        (* install backward jump; the collect is moved from the loop body
           into the backward path *)
        backward := NewJumpBlock (branch);
        SetJump (branch. branchTo, branch, backward);
        SetJump (backward. jump, backward, body);
        loopStart := loop. instr. GetLoopStart();
        backwardStore := loopStart. opndList. nextOpnd. arg;
        IF (backwardStore. instr. opcode = Opcode.collect) THEN
          MoveProxy (backwardStore. instr. info(InstrProxy), backward);
        END;
        
        (* install outgoing block *)
        out := NewJumpBlock (branch);
        SetJump (branch. jump, branch, out);
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

PROCEDURE TopSort (b: Block): BOOLEAN;
(**Topological sort on instructions in @oparam{b}.  If there are no cyclic
   dependencies between the instructions, the result is @code{TRUE}.  *)
  VAR
    proxy, next: InstrProxy;
    ready, waiting: InstrProxy;
    res: SSA.Result;
    use, opnd: SSA.Opnd;
    opndCount: LONGINT;

  PROCEDURE Add (VAR list: InstrProxy; instr: InstrProxy);
    BEGIN
      instr. prevProxy := NIL;
      instr. nextProxy := list;
      IF (list # NIL) THEN
        list. prevProxy := instr
      END;
      list := instr
    END Add;
  
  PROCEDURE Remove (VAR list: InstrProxy; instr: InstrProxy);
    BEGIN
      IF (instr. prevProxy = NIL) THEN
        list := instr. nextProxy
      ELSE
        instr. prevProxy. nextProxy := instr. nextProxy
      END;
      IF (instr. nextProxy # NIL) THEN
        instr. nextProxy. prevProxy := instr. prevProxy
      END
    END Remove;
  
  BEGIN
    ready := NIL;
    waiting := NIL;
    
    proxy := b. proxyList;
    WHILE (proxy # NIL) DO
      next := proxy. nextProxy;

      (* count number of operands with arguments originating in this block *)
      opndCount := 0;
      opnd := proxy. instr. opndList;
      WHILE (opnd # NIL) DO
        IF (opnd. class # Opnd.forwardRef) &
           (opnd. arg. instr. info(InstrProxy). block = b) THEN
          INC (opndCount)
        END;
        opnd := opnd. nextOpnd;
      END;
      
      proxy. instr. marker := opndCount;
      IF (opndCount = 0) THEN
        Add (ready, proxy)
      ELSE
        Add (waiting, proxy)
      END;
      proxy := next
    END;

    ClearProxyList (b);
    WHILE (ready # NIL) DO
      proxy := ready;
      IF (proxy. instr. opcode = Opcode.collect) &
         (proxy. nextProxy # NIL) THEN
        (* postpone scheduling of collect instructions until the very end
           of the block *)
        proxy := proxy. nextProxy
      END;
      Remove (ready, proxy);
      
      (* append `proxy' to list of instructions in `b' *)
      AppendProxy (b, proxy);

      (* decrement marker (=count of blocking results) for all uses of all
         results of `proxy' *)
      res := proxy. instr;
      WHILE (res # NIL) DO
        use := res. useList;
        WHILE (use # NIL) DO
          IF (use. instr. info(InstrProxy). block = b) &
             (use. class # Opnd.forwardRef) THEN
            DEC (use. instr. marker);
            IF (use. instr. marker = 0) THEN
              Remove (waiting, use. instr. info(InstrProxy));
              Add (ready, use. instr. info(InstrProxy))
            END;
          END;
          use := use. nextUse
        END;
        res := res. nextResult
      END;
    END;
    RETURN (waiting = NIL)
  END TopSort;

PROCEDURE SortBlocks (b: Block);
  VAR
    ok: BOOLEAN;
    nested: Block;
  BEGIN
    ok := TopSort (b);
    ASSERT (ok);

    nested := b. domList;
    WHILE (nested # NIL) DO
      SortBlocks (nested);
      nested := nested. nextDom
    END;
  END SortBlocks;


PROCEDURE Schedule* (pb: SSA.ProcBlock): Block;
(**Takes a procedure representation in SSA format and converts it into a graph
   representation consisting of basic blocks.  *)
  VAR
    b, lastBlock: JumpBlock;
    root: Blocker.Region;
    proxy: InstrProxy;
    
  PROCEDURE ArrangeBlock (b: Block);
  (* arrange children within each block in such way that loop branches have a
     target earlier in the linear chain of blocks, and all other jumps and
     branches a target later in the chain  *)
    VAR
      nested: Block;
      
    PROCEDURE LocateJumps (path: Block; b: Block);
    (* find all jumps in or below `b' that have the parent of `path' as
       target; for every jump, add a dependency from `path' to
       the child of `path.parent' containg the jump target *)
      VAR
        nested: Block;
        
      PROCEDURE ProcessJump (target: Block);
        PROCEDURE WriteBefore (VAR dependentList: Dependent; b: Block);
          BEGIN
            IF (dependentList = NIL) THEN
              NEW (dependentList);
              dependentList. block := b;
              dependentList. next := NIL;
              INC (b. depCount);
            ELSIF (dependentList. block # b) THEN
              WriteBefore (dependentList. next, b)
            END;
          END WriteBefore;
        
        BEGIN
          IF (target = path. parent) THEN
            path. parent. isLoopHead := TRUE
          ELSE
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
          IF (preferedBlock # NIL) &
             (preferedBlock. parent = domBlock) &
             (preferedBlock. depCount = 0) THEN
            b := preferedBlock
          ELSE
            b := ready
          END;
          
          RemoveFromList (ready, b);
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

      (* locate jump and branch instructions in our nested blocks *)
      IF (b. DefaultTarget() = b) OR
         (b IS BranchBlock) & (b(BranchBlock). branchTo. dest = b)THEN
        b. isLoopHead := TRUE
      END;
      nested := b. domList;
      WHILE (nested # NIL) DO
        LocateJumps (nested, nested);
        nested := nested. nextDom
      END;

      (* sort nested blocks *)
      SortBlocks (b);
    END ArrangeBlock;

  PROCEDURE MarkBackedges (b: Block);
    VAR
      nested: Block;

    PROCEDURE Check (jump: Jump);
      BEGIN
        jump. isLoopBackedge := Dominates (jump. dest, b)
      END Check;
    
    BEGIN
      WITH b: JumpBlock DO
        Check (b. jump)
      | b: BranchBlock DO
        Check (b. branchTo);
        Check (b. jump)
      | b: DeadEndBlock DO
        (* nowhere to go *)
      END;

      nested := b. domList;
      WHILE (nested # NIL) DO
        MarkBackedges (nested);
        nested := nested. nextDom
      END;
    END MarkBackedges;
  
  PROCEDURE CheckCollects (b: Block);
    VAR
      nested: Block;
      proxy: InstrProxy;
    BEGIN
      WITH b: JumpBlock DO
      | b: BranchBlock DO
        proxy := b. proxyList;
        WHILE (proxy # NIL) DO
          ASSERT (proxy. instr. opcode # Opcode.collect);
          proxy := proxy. nextProxy
        END;
      | b: DeadEndBlock DO
      END;

      nested := b. domList;
      WHILE (nested # NIL) DO
        CheckCollects (nested);
        nested := nested. nextDom
      END;
    END CheckCollects;
  
  BEGIN
    root := Blocker.ArrangeInstructions (pb);
    proxy := NewInstrProxy (root. instr);
    root. instr. info := proxy;
    b := NewJumpBlock (NIL);
    lastBlock := TransferInstructions (root, b);
    SetJump (lastBlock. jump, lastBlock, NewDeadEndBlock (lastBlock));
    
    (* mark jump instructions that are loop backedges *)
    MarkBackedges (b);
    
    (* schedule instructions within each basic block *)
    SortBlocks (b);

    (* arrange dominated blocks within each block in such way that
       loop branches have a target earlier in the chain of blocks, and all
       other jumps and branches a target later in the chain *)
    ArrangeBlock (b);

    CheckCollects(b);

    b. degreeIn := 1;  (* the root block is reached by exactly one edge *)
    RETURN b
  END Schedule;

END OOC:SSA:Schedule.
