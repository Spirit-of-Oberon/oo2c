(* 	$Id$	 *)
MODULE OOC:SSA:Schedule;
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
  ADT:Object, OOC:SSA, OOC:SSA:Opcode;

TYPE
  Block* = POINTER TO BlockDesc;
  InstrProxy* = POINTER TO InstrProxyDesc;
  BranchBlock* = POINTER TO BranchBlockDesc;

TYPE
  BlockDesc = RECORD
    (Object.ObjectDesc)
    (**A basic block contains a sequence of instructions, with control flow
       entering at the beginning of the block, and leaving at the end of the
       block.  There are no jumps into the block, nor are there any jump or
       branch instructions except at the very end.  Please note that exceptions
       like failed run-time checks are @emph{not} treated as jumps or branches
       in this context.  *)
    nextDom-: Block;
    (**Link for list of @ofield{Block.domList}.  *)
    
    proxyList-: InstrProxy;
    (**List with all instructions in this block.  *)

    domList-: Block;
    (**Lists all blocks directly dominated by this one.  *)

    jump-: Block;
    (**Default target of control flow when leaving this block.  Only @code{NIL}
       if the block is last in a procedure.  *)

    degreeIn-: LONGINT;
    (**The number of jumps or branches that have this block as target.  *)

    isWritten*: BOOLEAN;
    (**Auxiliary field for output procedure: if @code{TRUE}, then this
       block has been written out already.  *)
  END;
  
TYPE
  BranchBlockDesc = RECORD
    (BlockDesc)
    select-: SSA.Instr;
    branchOnTrue-: BOOLEAN;
    branchTo-: Block;
  END;
  
TYPE
  InstrProxyDesc = RECORD
    (SSA.NodeDesc)
    nextProxy-, prevProxy: InstrProxy;
    block-: Block;
    instr-: SSA.Instr;
  END;

PROCEDURE InitBlock (b: Block; jump: Block);
  BEGIN
    Object.Init (b);
    b. proxyList := NIL;
    b. nextDom := NIL;
    b. domList := NIL;
    b. jump := jump;
    b. degreeIn := 0;
    b. isWritten := FALSE;
  END InitBlock;

PROCEDURE NewBlock (jump: Block): Block;
  VAR
    b: Block;
  BEGIN
    NEW (b);
    InitBlock (b, jump);
    RETURN b
  END NewBlock;

PROCEDURE Dominates (dominator, child: Block);
  BEGIN
    child. nextDom := dominator. domList;
    dominator. domList := child
  END Dominates;


PROCEDURE InitBranchBlock (b: BranchBlock; jump: Block; select: SSA.Instr;
                           branchOnTrue: BOOLEAN; branchTo: Block);
  BEGIN
    InitBlock (b, jump);
    b. select := select;
    b. branchOnTrue := branchOnTrue;
    b. branchTo := branchTo;
  END InitBranchBlock;

PROCEDURE NewBranchBlock (jump: Block; select: SSA.Instr;
                          branchOnTrue: BOOLEAN; branchTo: Block): BranchBlock;
  VAR
    b: BranchBlock;
  BEGIN
    NEW (b);
    InitBranchBlock (b, jump, select, branchOnTrue, branchTo);
    RETURN b
  END NewBranchBlock;



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
    END;
    b. proxyList := proxy
  END AddProxy;

PROCEDURE RemoveProxy (b: Block; proxy: InstrProxy);
  BEGIN
    IF (proxy. prevProxy # NIL) THEN
      proxy. prevProxy. nextProxy := proxy. nextProxy
    ELSE
      b. proxyList := proxy. nextProxy
    END;
    IF (proxy. nextProxy # NIL) THEN
      proxy. nextProxy. prevProxy := proxy. prevProxy
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
    VAR
      in, path1, path2, exitPath1, exitPath2, exitEnter, exitIn, oldEnter: Block;

    PROCEDURE Move (result: SSA.Result; source, primary, secondary: Block);
    (**Recursively moves the instructions producing @oparam{result} into their
       target blocks.  Order of dependent instructions is kept unchanged.  That
       is, if an instruction @samp{A} depends on instruction @samp{B}, and
       @samp{A} is placed before @samp{B} in the original block, then the same
       holds for their respective placement in the target block.  *)
      VAR
        instr: SSA.Instr;
        opnd: SSA.Opnd;
        moved: BOOLEAN;
      BEGIN
        instr := result. instr;
        proxy := instr. info(InstrProxy);
        moved := FALSE;
        IF (proxy. block = source) THEN
          MoveProxy (proxy, primary);
          moved := TRUE
        ELSIF (proxy. block = primary) THEN
          (* nothing to do *)
        ELSIF (proxy. block = secondary) THEN
          (* nothing to do *)
        ELSE  (* contributes to a different path: use secondary *)
          MoveProxy (proxy, secondary);
          moved := TRUE
        END;

        IF moved THEN
          opnd := instr. opndList;
          WHILE (opnd # NIL) DO
            Move (opnd. arg, source, primary, secondary);
            opnd := opnd. nextOpnd
          END;
        END;
      END Move;
    
    BEGIN
      oldEnter := enter;
      path1 := NewBlock (enter);
      path2 := NewBlock (enter);
      in := NewBranchBlock
          (path2, select,
           select. opndList. nextOpnd. arg. IsBooleanConst (TRUE),
           path1);

      Move (select. opndList. arg, enter, in, in);
      Move (select. NthArg (2), enter, path1, in);
      Move (select. NthArg (4), enter, path2, in);

      exitPath1 := DebranchBlock (path1);
      exitPath2 := DebranchBlock (path2);
      exitIn := DebranchBlock (in);
      select. opcode := -select. opcode;(* mask the current select statement *)
      exitEnter := DebranchBlock (enter);
      select. opcode := -select. opcode;(* unmask it again *)

(*   exitPath1 := path1;
   exitPath2 := path2;
   exitIn := in;
   exitEnter := enter;*)
   
      exitPath1. jump := enter;
      exitPath2. jump := enter;
      exitIn(BranchBlock). jump := path2;
      exitIn(BranchBlock). branchTo := path1;
      
      Dominates (in, path1);
      Dominates (in, path2);
      Dominates (in, enter);

      enter := in;
      ASSERT (exitEnter = oldEnter);
      RETURN exitEnter
    END SplitSelect;
  
  BEGIN
    proxy := enter. proxyList;
    WHILE (proxy # NIL) & (proxy. instr. opcode # Opcode.select) DO
      proxy := proxy. nextProxy
    END;
    IF (proxy # NIL) THEN
      RETURN SplitSelect (enter, proxy. instr)
    ELSE
      RETURN enter
    END
  END DebranchBlock;



PROCEDURE TopSort (b: Block): BOOLEAN;
(**Topological sort on instructions in @oparam{b}.  If there are no cyclic
   dependencies between the instructions, the result is @code{TRUE}.  *)
  VAR
    proxy, next, proxyTail: InstrProxy;
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
        IF (opnd. arg. instr. info(InstrProxy). block = b) THEN
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

    b. proxyList := NIL;
    proxyTail := NIL;
    WHILE (ready # NIL) DO
      proxy := ready;
      Remove (ready, proxy);

      (* append `proxy' to list of instructions in `b' *)
      proxy. prevProxy := proxyTail;
      proxy. nextProxy := NIL;
      IF (proxyTail = NIL) THEN
        b. proxyList := proxy;
        proxyTail := proxy
      ELSE
        proxyTail. nextProxy := proxy
      END;
      proxyTail := proxy;

      (* decrement marker (=count of blocking results) for all uses of all
         results of `proxy' *)
      res := proxy. instr;
      WHILE (res # NIL) DO
        use := res. useList;
        WHILE (use # NIL) DO
          DEC (use. instr. marker);
          IF (use. instr. marker = 0) THEN
            Remove (waiting, use. instr. info(InstrProxy));
            Add (ready, use. instr. info(InstrProxy))
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
    b, exit: Block;
    instr: SSA.Instr;
    proxy: InstrProxy;
    ok: BOOLEAN;

  PROCEDURE CalculateDegree (b: Block);
    BEGIN
      IF (b # NIL) THEN
        INC (b. degreeIn);
        IF (b. degreeIn = 1) THEN
          WITH b: BranchBlock DO
            CalculateDegree (b. branchTo);
            CalculateDegree (b. jump);
          ELSE
            CalculateDegree (b. jump);
          END;
        END;
      END;
    END CalculateDegree;
  
  BEGIN
    (* first, put all instructions into a single block; instructions are
       sorted topological first, and this order is reversed when creating
       the list of `InstrProxy' instances (for DebranchBlock) *)
    ok := pb. TopSort();
    ASSERT (ok);
    pb. SetMarkers (NIL, -1);
    b := NewBlock (NIL);
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

    
    (* set the `degreeIn' fields to the number of blocks that jump or branch
       into the block *)
    CalculateDegree (b);
    
    RETURN b
  END Schedule;

END OOC:SSA:Schedule.
