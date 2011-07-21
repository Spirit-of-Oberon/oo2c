MODULE OOC:X86:Block;

IMPORT
  S := OOC:X86:SSA, Log, D := OOC:X86:Debug;
  
PROCEDURE ArrangeInstructions* (fctBlock: S.FunctionBlock);
  VAR
    instr, next: S.Instr;
    ready, waiting, block: S.Block;
    dummy: S.MergeInstr;

  PROCEDURE InflateControlFlow(b: S.Block; instr: S.Instr): S.MergeInstr;
    VAR
      path: S.Block;
      merge, m: S.MergeInstr;
      nonMergeCount: LONGINT;

    PROCEDURE NextInControlFlow(instr: S.Instr): S.Instr;
      VAR
        next: S.Instr;
        dep: S.Dep;
        
      PROCEDURE RelevantAfterDep(dep: S.Dep): BOOLEAN;
        BEGIN
          CASE dep.instr.opcode OF
          | S.exit, S.loopEnd:
            RETURN FALSE;
          ELSE
            RETURN TRUE;
          END;
        END RelevantAfterDep;
      
      BEGIN
        next := NIL;
        dep := instr.afterList;
        WHILE (dep # NIL) DO
          IF (dep.type = S.depControl) & RelevantAfterDep(dep) THEN
            ASSERT(next = NIL);
            next := dep.instr;
          END;
          dep := dep.nextAfter;
        END;
        RETURN next;
      END NextInControlFlow;

    PROCEDURE Prelocate(instr: S.Instr; block: S.Instr);
      BEGIN
        instr.info := block;
      END Prelocate;
    
    BEGIN
      WHILE (instr # NIL) & (instr.opcode # S.loopEnd) DO
        ASSERT(instr.info = NIL);
        Prelocate(instr, b);
        
        WITH instr: S.BranchInstr DO
          merge := NIL;
          nonMergeCount := 0;
          FOR path IN instr.paths^ DO
            Prelocate(path, instr);
            m := InflateControlFlow(path, NextInControlFlow(path));
            IF (m = NIL) THEN
              INC(nonMergeCount);
            ELSE
              ASSERT((merge = NIL) OR (merge = m));
              merge := m;
            END;
          END;
          IF (nonMergeCount = 0) THEN
            ASSERT(merge.opcode = S.merge);
            Prelocate(merge, instr);
            next := NextInControlFlow(merge);
          ELSE
            RETURN merge;
          END;

        | instr: S.LoopStartInstr DO
          m := InflateControlFlow(instr, NextInControlFlow(instr));
          Prelocate(instr.backedge, instr);
          Prelocate(instr.end, b);
          next := NextInControlFlow(instr.end);
          
        ELSE  (* set next instr for next iteration of the loop *)
          IF (instr.opcode = S.jump) THEN
            m := instr.JumpTarget();
            IF (m.opcode = S.merge) THEN
              RETURN m;
            ELSE
              RETURN NIL;
            END;
          ELSE
            next := NextInControlFlow(instr);
          END;
        END;
        instr := next;
      END;
      RETURN NIL;
    END InflateControlFlow;

  PROCEDURE AddToReady(instr: S.Instr);
    BEGIN
      CASE instr.opcode OF
      | S.jump, S.loopBackedge:
        ready.AddInFront(instr);
      ELSE
        ready.Add(instr);
      END;
    END AddToReady;
  
  PROCEDURE SetUseCount(b: S.Block);
    VAR
      instr: S.Instr;
      res: S.Result;
      use: S.Opnd;
      dep: S.Dep;
      useCount: LONGINT;
    BEGIN
      FOR instr IN b.Instructions() DO
        useCount := 0;
        
        FOR res IN instr.Results() DO
          FOR use IN res.Uses() DO
            IF ~use.IsBackedgeOpnd() THEN
              INC (useCount);
            END;
          END;
        END;
        FOR dep IN instr.AfterList(S.depAny) DO
          INC (useCount);
        END;
        
        instr.marker := useCount;
        
        IF (useCount = 0) THEN
          AddToReady(instr);
        ELSE
          waiting.Add(instr);
        END;

        WITH instr: S.Block DO
          SetUseCount(instr);
        ELSE
          (* nothing *)
        END;
      END;
    END SetUseCount;
  
  PROCEDURE UpdateDefs(instr: S.Instr);
    VAR
      opnd: S.Opnd;
      dep: S.Dep;
      defInstr: S.Instr;
    BEGIN
      FOR opnd IN instr.Operands() DO
        IF ~opnd.IsBackedgeOpnd() THEN
          defInstr := opnd.arg.instr;
          DEC(defInstr.marker);
          IF (defInstr.marker = 0) THEN
            waiting.Remove(defInstr);
            AddToReady(defInstr);
          END;
        END;
      END;
      FOR dep IN instr.BeforeList(S.depAny) DO
        defInstr := dep.before;
        DEC(defInstr.marker);
        IF (defInstr.marker = 0) THEN
          waiting.Remove(defInstr);
          AddToReady(defInstr);
        END;
      END;
    END UpdateDefs;

  PROCEDURE GetBlock (instr: S.Instr): S.Block;
    VAR
      block, useBlock: S.Block;
      res: S.Result;
      use: S.Opnd;
      dep: S.Dep;

    PROCEDURE Merge (a, b: S.Block): S.Block;
      PROCEDURE Up(b: S.Block): S.Block;
        BEGIN
          IF (b.info # NIL) THEN
            RETURN b.info(S.Block);
          ELSE
            RETURN b.block;
          END;
        END Up;
      
      PROCEDURE NestingDepth(b: S.Block): LONGINT;
        VAR
          i: LONGINT;
        BEGIN
          i := 0;
          WHILE (b # NIL) DO
            INC(i);
            b := Up(b);
          END;
          RETURN i;
        END NestingDepth;
      
      BEGIN
        (* Without loops, the rules of block selection are simple: the
           instruction is placed into the least global block that dominates
           all its uses.

           Things get more complicated, if loops enter the picture.  For one
           thing, the above rule may cause an instruction to be moved out of a
           loop, although it uses values provided by the back-edge of the loop.

           In addition to this, an instruction may end up within a loop,
           although it is in fact loop invariant.  *)
        WHILE (NestingDepth(a) > NestingDepth(b)) DO
          a := Up(a);
        END;
        WHILE (NestingDepth(b) > NestingDepth(a)) DO
          b := Up(b);
        END;
        WHILE (a # b) DO
          a := Up(a); b := Up(b);
        END;
        (*IF (a # NIL) & (a.opcode = Opcode.select) THEN
          a := Up(a);
        END;*)
        RETURN a;
      END Merge;

    PROCEDURE BlockOfUse (opnd: S.Opnd): S.Block;
      VAR
        instr: S.Instr;
        merge: S.Block;
      BEGIN
        instr := opnd.instr;
        IF (instr.opcode = S.gate) THEN
          merge := instr(S.GateInstr).merge;
          WITH merge: S.MergeInstr DO
            RETURN merge.jumps[opnd.OpndIndex()].info(S.Block);
          | merge: S.LoopStartInstr DO
            IF (opnd = instr.opndList) THEN
              RETURN merge.info(S.Block);
            ELSE
              RETURN merge;
            END;
          END;
        ELSE
          RETURN instr.block;
        END;
      END BlockOfUse;

    BEGIN
      IF (instr.info # NIL) THEN
        block := instr.info(S.Block);
      ELSIF (instr.opcode = S.gate) THEN
        (* gates are always placed within their merge block *)
        ASSERT(instr(S.GateInstr).merge # NIL);
        block := instr(S.GateInstr).merge;
      ELSE
        block := NIL;
        FOR res IN instr.Results() DO
          FOR use IN res.Uses() DO
            useBlock := BlockOfUse(use);
            IF (block = NIL) THEN
              block := useBlock;
            ELSE
              block := Merge(block, useBlock);
            END;
          END;
        END;
        FOR dep IN instr.AfterList(S.depAny) DO
          useBlock := dep.instr.block;
          IF (block = NIL) THEN
            block := useBlock;
          ELSE
            block := Merge(block, useBlock);
          END;
        END;
        
        IF (block = NIL) THEN
          block := fctBlock;
        END;
      END;
      RETURN block;
    END GetBlock;

  PROCEDURE ClearBlock(b: S.Block);
    VAR
      instr: S.Instr;
    BEGIN
      FOR instr IN b.Instructions() DO
        WITH instr: S.Block DO
          ClearBlock(instr);
        ELSE
          (* nothing *)
        END;
        b.RemoveAll();
      END;
    END ClearBlock;
  
  PROCEDURE SortBlock(b: S.Block);
    VAR
      instr: S.Instr;
    BEGIN
      FOR instr IN b.Instructions() DO
        WITH instr: S.Block DO
          IF (instr.opcode = S.loopStart) THEN
            instr.block.MoveBehind(instr, instr(S.LoopStartInstr).end);
          END;
          SortBlock(instr);
        ELSE
          IF (instr.opcode = S.gate) OR (instr.opcode = S.enter) THEN
            instr.MoveToFront();
          ELSIF (b.opcode = S.branch) &
                ((instr.opcode # S.guard) & (instr.opcode # S.merge)) THEN
            (* If an unexpected instruction ends up within a branch, which can
               happen for an instruction if it is used in several guards of the
               branch, then move the instruction in front of the branch.  *)
            b.Remove(instr);
            b.block.AddInFront(instr);
            IF (b.prevInstr # instr) THEN
              b.block.MoveBehind(b.prevInstr, instr);
            END;
          END;
        END;
      END;
    END SortBlock;

  BEGIN
    fctBlock.SetMarkers(NIL, 0);

    (* use the existing control flow dependencies to create an initial
       framework of nested blocks  *)
    dummy := InflateControlFlow(fctBlock, fctBlock.enter);
    
    (* for every instruction, write the number of uses into its `marker'
       field; instructions with no uses are placed in `ready', the rest
       is put into `waiting' *)
    ready := NEW(S.Block, -1);
    waiting := NEW(S.Block, -1);
    SetUseCount(fctBlock);
    ClearBlock(fctBlock);
    
    (* remove instructions whose uses have been scheduled already from
       `ready' and schedule them into their block; this creates a hierarchy
       of blocks containing all instructions  *)
    WHILE (ready.instrList # NIL) DO
      instr := ready.instrList;
      ready.Remove(instr);
      UpdateDefs(instr);

      block := GetBlock(instr);
      block.AddInFront(instr);
    END;
    IF waiting.instrList#NIL THEN
      instr := waiting.instrList;
      WHILE (instr # NIL) DO
        Log.Object("waiting", D.Label(instr));
        Log.Int("  marker", instr.marker);
        instr := instr.nextInstr;
      END;
    END;
    ASSERT(waiting.instrList = NIL);
    
    (* sort instructions within each newly created block *)
    SortBlock(fctBlock);
(*    AddBlockDeps (root);
    SortBlock (root);*)
  END ArrangeInstructions;

END OOC:X86:Block.

