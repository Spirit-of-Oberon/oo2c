(* 	$Id$	 *)
MODULE OOC:SSA:Schedule [OOC_EXTENSIONS];
(*  Generates basic block representation and schedules instructions.
    Copyright (C) 2001  Michael van Acken

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
  ADT:Object, OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd;

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

PROCEDURE InitBlock (b: Block);
  BEGIN
    Object.Init (b);
    b. proxyList := NIL;
    b. proxyTail := NIL;
    b. parent := NIL;
    b. nextDom := NIL;
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

PROCEDURE MakeDominator (dominator, child: Block);
  BEGIN
    child. nextDom := dominator. domList;
    dominator. domList := child;
    child. parent := dominator
  END MakeDominator;

PROCEDURE Dominates* (dominator, child: Block): BOOLEAN;
  BEGIN
    WHILE (child # NIL) & (child # dominator) DO
      child := child. parent
    END;
    RETURN (child # NIL)
  END Dominates;


PROCEDURE InitBranchBlock (b: BranchBlock; predicate: SSA.Opnd;
                           branchOnTrue: BOOLEAN);
  BEGIN
    InitBlock (b);
    b. jump := NIL;
    b. predicate:= predicate;
    b. branchOnTrue := branchOnTrue;
    b. branchTo := NIL;
  END InitBranchBlock;

PROCEDURE NewBranchBlock (predicate: SSA.Opnd;
                          branchOnTrue: BOOLEAN): BranchBlock;
  VAR
    b: BranchBlock;
  BEGIN
    NEW (b);
    InitBranchBlock (b, predicate, branchOnTrue);
    RETURN b
  END NewBranchBlock;

PROCEDURE (b: BranchBlock) DefaultTarget*(): Block;
  BEGIN
    RETURN b. jump. dest
  END DefaultTarget;


PROCEDURE InitJumpBlock (b: JumpBlock);
  BEGIN
    InitBlock (b);
    b. jump := NIL;
  END InitJumpBlock;

PROCEDURE NewJumpBlock(): JumpBlock;
  VAR
    b: JumpBlock;
  BEGIN
    NEW (b);
    InitJumpBlock (b);
    RETURN b
  END NewJumpBlock;

PROCEDURE (b: JumpBlock) DefaultTarget*(): Block;
  BEGIN
    RETURN b. jump. dest
  END DefaultTarget;


PROCEDURE InitDeadEndBlock (b: DeadEndBlock);
  BEGIN
    InitBlock (b);
  END InitDeadEndBlock;

PROCEDURE NewDeadEndBlock(): DeadEndBlock;
  VAR
    b: DeadEndBlock;
  BEGIN
    NEW (b);
    InitDeadEndBlock (b);
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

PROCEDURE AddProxy (b: Block; proxy: InstrProxy);
  BEGIN
    proxy. nextProxy := b. proxyList;
    proxy. prevProxy := NIL;
    proxy. block := b;
    IF (b. proxyList # NIL) THEN
      b. proxyList. prevProxy := proxy
    ELSE
      b. proxyTail := proxy
    END;
    b. proxyList := proxy
  END AddProxy;

PROCEDURE AppendProxy (b: Block; proxy: InstrProxy);
  BEGIN
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
    AddProxy (to, proxy)
  END MoveProxy;


PROCEDURE DebranchBlock (VAR enter: Block): Block;
(* `enter' is the block that dominates all the instructions in the
   sequence, and is changed by the function if there is a new
   dominating block; result is the block whose `jump' field leaves
   the sequence of instructions; this is always the original value
   of `enter'

   precond: instructions within the block are topologically sorted
   in descending order; that is, if A depends on B, then B follows A *)
  VAR
    proxy: InstrProxy;

  PROCEDURE SplitSelect (VAR enter: Block; select: SSA.Instr): Block;
    CONST
      keepInEnter = 0;
      moveToIn = 1;
      moveToPath1 = 2;
      moveToPath2 = 3;
    VAR
      in, path1, path2, exitPath1, exitPath2, exitEnter, exitIn, oldEnter: Block;
      proxy: InstrProxy;
      opnd: SSA.Opnd;

    PROCEDURE Move (result: SSA.Result; source: Block;
                    primary, secondary: LONGINT);
    (**Recursively moves the instructions producing @oparam{result} into their
       target blocks.  This procedure marks the instructions with the ids of
       their targets blocks.  The actual transfer happens later.  *)
      VAR
        opnd: SSA.Opnd;
        oldBlock, newBlock: LONGINT;
        proxy: InstrProxy;
      BEGIN
        proxy := result. instr. info(InstrProxy);
        IF (proxy. block = source) THEN
          oldBlock := proxy. instr. marker;
          IF (oldBlock = keepInEnter) THEN
            newBlock := primary;
          ELSIF (oldBlock = primary) THEN
            newBlock := oldBlock;
          ELSIF (oldBlock = secondary) THEN
            newBlock := oldBlock;
          ELSE  (* contributes to a different path: use secondary *)
            newBlock := secondary;
          END;

          IF (newBlock # oldBlock) THEN
            proxy. instr. marker := newBlock;
            opnd := proxy. instr. opndList;
            WHILE (opnd # NIL) DO
              Move (opnd. arg, source, primary, secondary);
              opnd := opnd. nextOpnd
            END;
          END;
        END;
      END Move;

    PROCEDURE MarkInstructions (proxy: InstrProxy; marker: LONGINT);
      BEGIN
        WHILE (proxy # NIL) DO
          proxy. instr. marker := marker;
          proxy := proxy. nextProxy
        END;
      END MarkInstructions;

    PROCEDURE MoveInstructions (proxy: InstrProxy; in, p1, p2: Block);
      VAR
        prev: InstrProxy;
      BEGIN
        WHILE (proxy # NIL) DO
          prev := proxy. prevProxy;
          CASE proxy. instr. marker OF
          | keepInEnter: (* done *)
          | moveToIn: MoveProxy (proxy, in)
          | moveToPath1: MoveProxy (proxy, p1)
          | moveToPath2: MoveProxy (proxy, p2)
          END;
          proxy := prev
        END;
      END MoveInstructions;
    
    BEGIN
      oldEnter := enter;
      path1 := NewJumpBlock();
      path2 := NewJumpBlock();
      in := NewBranchBlock
          (select. opndList,
           select. opndList. nextOpnd. arg. IsBooleanConst (TRUE));

      MarkInstructions (enter. proxyList, keepInEnter);
      Move (select. opndList. arg, enter, moveToIn, moveToIn);
      Move (select. NthArg (2), enter, moveToPath1, moveToIn);
      Move (select. NthArg (4), enter, moveToPath2, moveToIn);

      (* if there are any instruction in `enter' that depend on results that
         have been moved to `path1' or `path2', then move these results'
         instructions into `in' *)
      proxy := enter. proxyList;
      WHILE (proxy # NIL) DO
        IF (proxy. instr. marker = keepInEnter) &
           (proxy. instr # select) &
           (proxy. instr. opcode # Opcode.selectReturn) THEN
          opnd := proxy. instr. opndList;
          WHILE (opnd # NIL) DO
            Move (opnd. arg, enter, keepInEnter, moveToIn);
            opnd := opnd. nextOpnd
          END;
        END;
        proxy := proxy. nextProxy
      END;
      
      (* transfer instructions into target blocks *)
      MoveInstructions (enter. proxyTail, in, path1, path2);

      exitPath1 := DebranchBlock (path1);
      exitPath2 := DebranchBlock (path2);
      exitIn := DebranchBlock (in);
      select. opcode := -select. opcode;(* mask the current select statement *)
      exitEnter := DebranchBlock (enter);
      select. opcode := -select. opcode;(* unmask it again *)

      SetJump (exitPath1(JumpBlock). jump, exitPath1, enter);
      SetJump (exitPath2(JumpBlock). jump, exitPath2, enter);
      SetJump (exitIn(BranchBlock). jump, exitIn, path2);
      SetJump (exitIn(BranchBlock). branchTo, exitIn, path1);
      
      MakeDominator (in, path1);
      MakeDominator (in, path2);
      MakeDominator (in, enter);

      enter := in;
      ASSERT (exitEnter = oldEnter);
      RETURN exitEnter
    END SplitSelect;
  
  PROCEDURE SplitLoop (VAR enter: Block; loopEnd: SSA.Instr): Block;
    VAR
      in, body, oldEnter, exitIn, exitBody, exitEnter: Block;
      predicate: SSA.Opnd;
      loopStart: SSA.Instr;
      
    PROCEDURE Move (result: SSA.Result; source, target: Block);
    (**Recursively moves the instructions producing @oparam{result} into
       @oparam{target}.  Order of dependent instructions is kept unchanged.
       That is, if an instruction @samp{A} depends on instruction @samp{B}, and
       @samp{A} is placed before @samp{B} in the original block, then the same
       holds for their respective placement in the target block.  *)
      VAR
        instr: SSA.Instr;
        opnd: SSA.Opnd;
      BEGIN
        instr := result. instr;
        proxy := instr. info(InstrProxy);
        IF (proxy. block = source) THEN
          MoveProxy (proxy, target);
          opnd := instr. opndList;
          WHILE (opnd # NIL) DO
            IF (opnd. class # Opnd.forwardRef) THEN
              Move (opnd. arg, source, target);
            END;
            opnd := opnd. nextOpnd
          END;
        END;
      END Move;
    
    PROCEDURE MoveUses (instr: SSA.Instr; source, target: Block;
                        loopEnd: SSA.Instr);
    (**Recursively moves the instruction @oparam{instr} and all instructions
       using on of its results into @oparam{target}.  Traversal stops at the
       instruction @oparam{loopEnd}; that is, this instruction is not moved,
       nor are any uses of its results inspected.

       Order of dependent instructions is kept unchanged.  That is, if an
       instruction @samp{A} depends on instruction @samp{B}, and @samp{A} is
       placed before @samp{B} in the original block, then the same holds for
       their respective placement in the target block.  *)
      VAR
        use: SSA.Opnd;
        res: SSA.Result;
        proxy: InstrProxy;
      BEGIN
        proxy := instr. info(InstrProxy);
        IF (proxy. block = source) & (instr # loopEnd) THEN
          res := instr;
          WHILE (res # NIL) DO
            use := res. useList;
            WHILE (use # NIL) DO
              IF (use. class # Opnd.forwardRef) THEN
                MoveUses (use. instr, source, target, loopEnd);
              END;
              use := use. nextUse
            END;
            res := res. nextResult
          END;
          MoveProxy (proxy, target);
        END;
      END MoveUses;
    
    BEGIN
      oldEnter := enter;

      (* set up this block structure:
         in: dominates all other instructions, jumps to body
         body: jumps to the old enter, branches to its own beginning  *)
      predicate := loopEnd. NthOpnd (2);
      body := NewBranchBlock
          (predicate, predicate. nextOpnd. arg. IsBooleanConst (FALSE));
      in := NewJumpBlock();
      
      (* move all instructions contributing to the "loop-end" or to the forward
         reference from "loop-start" into the `in' block; then, move all
         instruction in `in' that derive input from "loop-start" into `body' *)
      loopStart := loopEnd. opndList. arg(SSA.Instr);
      ASSERT (loopStart. opcode = Opcode.loopStart);
      Move (loopEnd. NthArg (1), enter, in);
      Move (loopEnd. NthArg (2), enter, in);
      Move (loopStart. NthArg (1), enter, in);
      MoveUses (loopStart, in, body, loopEnd);
      
      exitIn := DebranchBlock (in);
      exitBody := DebranchBlock (body);
      loopEnd. opcode := -loopEnd. opcode; (* mask the current loopEnd *)
      exitEnter := DebranchBlock (enter);
      loopEnd. opcode := -loopEnd. opcode; (* unmask it again *)
      
      SetJump (exitIn(JumpBlock). jump, exitIn, body);
      SetJump (exitBody(BranchBlock). jump, exitBody, enter);
      SetJump (exitBody(BranchBlock). branchTo, exitBody, body);
      
      MakeDominator (in, body);
      MakeDominator (body, enter);
      
      enter := in;
      ASSERT (exitEnter = oldEnter);
      RETURN exitEnter
    END SplitLoop;
  
  BEGIN
    proxy := enter. proxyList;
    WHILE (proxy # NIL) &
          ((proxy. instr. opcode # Opcode.select) &
           (proxy. instr. opcode # Opcode.loopEnd)) DO
      proxy := proxy. nextProxy
    END;
    IF (proxy # NIL) THEN
      CASE proxy. instr. opcode OF
      | Opcode. select:
        RETURN SplitSelect (enter, proxy. instr)
      | Opcode.loopEnd:
        RETURN SplitLoop (enter, proxy. instr)
      END;
    ELSE
      RETURN enter
    END
  END DebranchBlock;



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


PROCEDURE FollowJump* (jump: Jump): Block;
(**Returns @code{NIL} if @oparam{jump} is @code{NIL}, and the target of the
   jump otherwise.  *)
  BEGIN
    IF (jump = NIL) THEN
      RETURN NIL
    ELSE
      RETURN jump. dest
    END;
  END FollowJump;

PROCEDURE Schedule* (pb: SSA.ProcBlock): Block;
(**Takes a procedure representation in SSA format and converts it into a graph
   representation consisting of basic blocks.  *)
  VAR
    b, exit: Block;
    instr: SSA.Instr;
    proxy: InstrProxy;
    ok: BOOLEAN;

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
  
  BEGIN
    (* first, put all instructions into a single block; instructions are
       sorted topological first, and this order is reversed when creating
       the list of `InstrProxy' instances (for DebranchBlock) *)
    ok := pb. TopSort();
    ASSERT (ok);
    pb. SetMarkers (NIL, -1);
    b := NewDeadEndBlock();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      proxy := NewInstrProxy (instr);
      instr. info := proxy;
      AddProxy (b, proxy);
      instr := instr. nextInstr
    END;

    (* second, scan instructions for branches in the control flow; create new
       blocks accordingly, and add links between them representing branches and
       unconditional jumps  *)
    exit := DebranchBlock (b);
    
    (* third, schedule instructions within each basic block *)
    SortBlocks (b);

    (* fourth, arrange dominated blocks within each block in such way that
       loop branches have a target earlier in the chain of blocks, and all
       other jumps and branches a target later in the chain *)
    ArrangeBlock (b);
    
    RETURN b
  END Schedule;

END OOC:SSA:Schedule.
