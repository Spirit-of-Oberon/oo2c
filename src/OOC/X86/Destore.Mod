MODULE OOC:X86:Destore;

IMPORT
  Sym := OOC:SymbolTable, S := OOC:X86:SSA, OOC:X86:Aliasing;

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: S.Instr;
  END;

PROCEDURE Transform*(fctBlock: S.FunctionBlock);
  VAR
    worklist: Worklist;
    undefValue: S.Result;
    instr: S.Instr;

  PROCEDURE AddToWorklist(instr: S.Instr);
    VAR
      entry: Worklist;
    BEGIN
      NEW(entry);
      entry.next := worklist;
      entry.instr := instr;
      worklist := entry;
    END AddToWorklist;
  
  PROCEDURE PropagateInstr(instr: S.Instr);
  (* Propagate the effect of the instruction down the chain of memory
     dependencies.  *)

    PROCEDURE PropagateValue(designator: S.Designator; value: S.Result;
                             instr: S.Instr);
    (* Propagate the value of the designator down the chain of memory
       dependencies.  *)
      VAR
        afterInstr, merge: S.Instr;
        dep: S.Dep;

      PROCEDURE GetDesignatorGate(merge: S.Block;
                                  designator: S.Designator): S.Instr;
        VAR
          instr: S.Instr;
          i: LONGINT;
        BEGIN
          FOR instr IN merge.Instructions() DO
            IF (instr.opcode = S.designatorGate) &
               S.SameDesignator(designator, instr.designator) THEN
              RETURN instr;
            END;
          END;

          instr := merge.AddGate(S.designatorGate);
          instr.SetDesignator(designator);
          FOR i := 1 TO merge.IncomingPaths() DO
            instr.AddOpnd(undefValue);
          END;
          RETURN instr;
        END GetDesignatorGate;
      
      PROCEDURE MergeValue(merge: S.MergeInstr; jump: S.Instr;
                           designator: S.Designator; value: S.Result);
        VAR
          gate: S.Instr;
          opnd: S.Opnd;
          i: LONGINT;
          res: S.Result;
        BEGIN
          gate := GetDesignatorGate(merge, designator);
          opnd := gate.opndList; i := 0;
          WHILE (merge.jumps[i] # jump) DO
            opnd := opnd.nextOpnd; INC(i);
          END;
          opnd.ReplaceArg(value);

          INC(gate.marker);
          IF (gate.marker = LEN(merge.jumps^)) THEN
            res := gate.AddResult(gate.opndList.arg.type);
            AddToWorklist(gate);
          END;
        END MergeValue;
      
      PROCEDURE MergeLoopValue(loopStart: S.Block; pathIndex: LONGINT;
                               designator: S.Designator; value: S.Result);
        VAR
          gate: S.Instr;
          opnd: S.Opnd;
          res: S.Result;
        BEGIN
          gate := GetDesignatorGate(loopStart, designator);
          opnd := gate.opndList;
          WHILE (pathIndex # 0) DO
            opnd := opnd.nextOpnd; DEC(pathIndex);
          END;
          opnd.ReplaceArg(value);

          INC(gate.marker);
          IF (gate.marker = 1) THEN  (* first one wins *)
            res := gate.AddResult(gate.opndList.arg.type);
            AddToWorklist(gate);
          END;
        END MergeLoopValue;
      
      BEGIN
        FOR dep IN instr.AfterList(S.depMemory) DO
          afterInstr := dep.instr;
          CASE afterInstr.opcode OF
          | S.get:
            CASE Aliasing.DesignatorAlias(afterInstr.designator, designator) OF
            | Aliasing.noAliasing:
              PropagateValue(designator, value, afterInstr);
            | Aliasing.completelyCovered:
              PropagateValue(designator, value, afterInstr);
              afterInstr.resultList.ReplaceUses(value);
              afterInstr.TransferDeps();
              afterInstr.Delete();
            ELSE
              (* partial coverage or may alias: do nothing *)
            END;
          | S.set:
            CASE Aliasing.DesignatorAlias(afterInstr.designator, designator) OF
            | Aliasing.noAliasing:
              PropagateValue(designator, value, afterInstr);
            ELSE
              (* any kind of coverage or may alias: do nothing *)
            END;
          | S.call:
            (* nothing; FIXME... can do better here *)
          | S.jump:
            merge := afterInstr.GetAfterInstr(S.depControl);
            MergeValue(merge(S.MergeInstr), afterInstr, designator, value);
          | S.guard:
            PropagateValue(designator, value, afterInstr);
          | S.loopStart:
            MergeLoopValue(afterInstr(S.Block), 0, designator, value);
          | S.loopExit:
            FOR dep IN afterInstr.AfterList(-1) DO
              CASE dep.instr.opcode OF
              | S.loopEnd:
                MergeValue(dep.instr(S.MergeInstr), afterInstr,
                           designator, value);
              ELSE
                PropagateValue(designator, value, afterInstr);
              END;
            END;
          | S.loopBackedge:
            MergeLoopValue(afterInstr(S.LoopBackedgeInstr).start, 1,
                           designator, value);
          | S.return:
            (* nothing; FIXME... see loopExit *)
          END;
        END;
      END PropagateValue;

    PROCEDURE FixedDesignator(designator: S.Designator): BOOLEAN;
      BEGIN
        RETURN (LEN(designator^) = 1) & (designator[0] IS S.Var);
      END FixedDesignator;
    
    BEGIN
      IF (instr.info = NIL) THEN
        instr.info := instr;             (* mark as visited *)
        CASE instr.opcode OF
        | S.enter, S.allocateStack, S.return, S.exit, S.guard, S.jump, S.merge,
          S.loopStart, S.loopExit, S.loopBackedge, S.loopEnd, S.call:
          (* nothing *)
        | S.get:
          IF FixedDesignator(instr.designator) THEN
            PropagateValue(instr.designator, instr.resultList, instr);
          END;
        | S.set:
          IF FixedDesignator(instr.designator) THEN
            PropagateValue(instr.designator, instr.opndList.nextOpnd.arg, instr);
          END;
        | S.designatorGate:
          PropagateValue(instr.designator, instr.resultList, instr.block);
        END;
      END;
    END PropagateInstr;
  
  PROCEDURE VisibleEffect (store: S.Instr; set: S.Instr): BOOLEAN;
  (* Return @code{TRUE} if the instruction @oparam{set} performs a modification
     in memory that is (or can be) visible to an instruction depending on
     @oparam{store}.  Note: It is always safe to return @oconst{TRUE}.  *)
    VAR
      dep: S.Dep;
    
    PROCEDURE ReadingUse(instr: S.Instr): BOOLEAN;
      VAR
        alias: Aliasing.Id;
        
      PROCEDURE GetVar (designator: S.Designator): Sym.VarDecl;
      (* Return the variable that starts the designator of the "get" or
         "set" instruction @oparam{instr}.  Result is @code{NIL} if its
         a heap access.  *)
        BEGIN
          IF (designator[0] IS S.Var) THEN
            RETURN designator[0](S.Var).decl;
          ELSE
            (* designator does not begin with a variable *)
            RETURN NIL
          END;
        END GetVar;
      
      PROCEDURE ExternalVisibility (var: Sym.VarDecl): BOOLEAN;
      (* TRUE if this variable still exists after the procedure is done.  *)
        BEGIN
          RETURN (var = NIL) OR          (* heap access *)
              var.isVarParam OR          (* variable parameter *)
              (var. Procedure() # fctBlock.procDecl);  (* nonlocal variable *)
        END ExternalVisibility;
      
      BEGIN
        CASE instr.opcode OF
        | S.get:
          alias := Aliasing.DesignatorAlias(set.designator, instr.designator);
          IF (alias # Aliasing.noAliasing) THEN
            (* the "get" may read from memory changed by the store *)
            RETURN TRUE;
          ELSE
            RETURN VisibleEffect(instr, set);
          END;
        | S.set:
          alias := Aliasing.DesignatorAlias(set.designator, instr.designator);
          IF (alias = Aliasing.completelyCovered) THEN
            (* this "set" instruction defines the variable we are tracing:
               we are at the end of the visibility of "origin" *)
            RETURN FALSE;
          ELSIF (alias # Aliasing.noAliasing) THEN
            (* this set operation does not overwrite completely the original
               set, or no static aliasing calculation can be done: we must
               keep the write operation alive, but its static visibility ends
               here *)
            RETURN TRUE;
          ELSE
            (* this "set" and "origin" work on different variables, and
               cannot interfere with each other: continue trace through
               `instr' *)
            RETURN VisibleEffect(instr, set);
          END;
        | S.return, S.exit:
          (* we've reached the end of the procedure: we are done *)
          RETURN ExternalVisibility(GetVar(set.designator));
        | S.merge, S.loopStart, S.loopEnd:
          RETURN VisibleEffect(instr, set);
        | S.loopBackedge:
          RETURN VisibleEffect(instr(S.LoopBackedgeInstr).start, set);
        | S.jump, S.loopExit:
          RETURN ReadingUse(instr.MergingTarget());
        END;
      END ReadingUse;
    
    BEGIN
      IF (store.info # set) THEN
        store.info := set;
        store.marker := 0;  (* in case of cycle, return FALSE *)
        dep := store.afterList;
        WHILE (dep # NIL) & ((dep.type # S.depMemory) OR
                             ~ReadingUse(dep.instr)) DO
          dep := dep.nextAfter;
        END;
        IF (dep # NIL) THEN
          store.marker := 1;
          RETURN TRUE;
        ELSE
          store.marker := 0;
          RETURN FALSE;
        END;
      ELSE
        RETURN (store.marker # 0);
      END;
    END VisibleEffect;

  PROCEDURE AddDesignatorGatetoWorklist(b: S.Block);
    VAR
      instr: S.Instr;
    BEGIN
      FOR instr IN b.Instructions() DO
        IF (instr.opcode = S.designatorGate) THEN
          AddToWorklist(instr);
        ELSIF (instr IS S.Block) THEN
          AddDesignatorGatetoWorklist(instr(S.Block));
        END;
      END;
    END AddDesignatorGatetoWorklist;
  
  PROCEDURE PromoteDesignatorGate(instr: S.GateInstr);
    VAR
      opnd: S.Opnd;

    PROCEDURE ReplaceUses(old, new: S.Result);
      VAR
        use: S.Opnd;
      BEGIN
        WHILE (old.useList # NIL) DO
          use := old.useList;
          IF ((use.instr.opcode = S.designatorGate) OR
              (use.instr.opcode = S.gate)) &
             (use.instr # old.instr) THEN
            AddToWorklist(use.instr);
          END;
          use.ReplaceArg(new);
        END;
      END ReplaceUses;
    
    BEGIN            (* pre: instr.opcode in {designatorGate, gate} *)
      IF (instr.resultList = NIL) THEN
        (* unused; for a gate within a merge, this means that there is at least
           one undefined argument  *)
        instr.Delete();
      ELSIF (instr.merge IS S.LoopStartInstr) THEN
        IF (instr.opndList.nextOpnd.arg = instr.resultList) THEN
          (* value not changed within loop *)
          ReplaceUses(instr.resultList, instr.opndList.arg);
          instr.Delete();
        ELSIF (instr.opcode = S.designatorGate) THEN
          instr.DesignatorGateToGate();
        END;
      ELSE                               (* no undefined arguments *)
        opnd := instr.opndList;
        WHILE (opnd.nextOpnd # NIL) & (opnd.nextOpnd.arg = opnd.arg) DO
          opnd := opnd.nextOpnd;
        END;
        IF (opnd.nextOpnd = NIL) THEN    (* all arguments are the same *)
          ReplaceUses(instr.resultList, instr.opndList.arg);
          instr.Delete();
        ELSIF (instr.opcode = S.designatorGate) THEN
          instr.DesignatorGateToGate();
        END;
      END;
    END PromoteDesignatorGate;

  PROCEDURE AddMemoryDeps(instr: S.Instr);
    VAR
      dep: S.Dep;
    BEGIN
      FOR dep IN instr.AfterList(S.depMemory) DO
        AddToWorklist(dep.instr);
      END;
      IF (instr.opcode = S.jump) THEN
        FOR dep IN instr.AfterList(S.depControl) DO
          AddToWorklist(dep.instr);
        END;
      END;
    END AddMemoryDeps;
  
  BEGIN
    worklist := NIL;

    undefValue := fctBlock.enter.AddResult(S.noType);
    
    fctBlock.SetMarkers(NIL, 0);
    AddToWorklist(fctBlock.enter);
    WHILE (worklist # NIL) DO
      instr := worklist.instr;
      worklist := worklist.next;
      PropagateInstr(instr);
      
      (* with the exception of merge instructions, every instruction has
         at most one predecessor in the "memory dependency" relationship;
         by traversing this graph starting at "enter", we reach all relevant
         instructions *)
      AddMemoryDeps(instr);
    END;

    (* visit all "set" instructions and check if they can be eliminated;
       at this place, all obsolete "get"s must have been removed *)
    fctBlock.SetMarkers(NIL, 0);
    AddToWorklist(fctBlock.enter);
    WHILE (worklist # NIL) DO
      instr := worklist.instr;
      worklist := worklist.next;
      AddMemoryDeps(instr);
      IF (instr.opcode = S.set) & ~VisibleEffect(instr, instr) THEN
        instr.TransferDeps();
        instr.Delete();
      END;
    END;

    (* turn designatorGate into gate or eliminate instruction *)
    AddDesignatorGatetoWorklist(fctBlock);
    WHILE (worklist # NIL) DO
      instr := worklist.instr;
      worklist := worklist.next;
      PromoteDesignatorGate(instr(S.GateInstr));
    END;
    ASSERT(undefValue.useList = NIL);
    undefValue.DeleteResult();
  END Transform;

END OOC:X86:Destore.
