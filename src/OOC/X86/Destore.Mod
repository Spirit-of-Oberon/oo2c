MODULE OOC:X86:Destore;

IMPORT
  Object, ADT:Dictionary,
  Sym := OOC:SymbolTable, S := OOC:X86:SSA, OOC:X86:Aliasing;

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: S.Instr;
  END;
  MemAccess = POINTER TO MemAccessDesc;
  MemAccessDesc = RECORD
    (Object.ObjectDesc)
    designator: S.Designator;
    address: S.Result;
    type: S.Type;
  END;

CONST
  read = 0;

PROCEDURE (memAccess: MemAccess) INIT*(type: S.Type; designator: S.Designator;
                                       address: S.Result);
  BEGIN
    memAccess.designator := designator;
    memAccess.address := address;
    memAccess.type := type;
  END INIT;

PROCEDURE Transform*(fctBlock: S.FunctionBlock);
  VAR
    worklist: Worklist;
    undefValue: S.Result;
    instr: S.Instr;
    gate: S.GateInstr;
    gateToInstr: Dictionary.Dictionary(S.GateInstr, MemAccess);
    (* For every gate instruction, this dictionary maps the gate to the
       instruction that triggered its creation.  *)

  PROCEDURE AccessedByCall (calledAdr: S.Result; design: S.Designator;
                            mode: SHORTINT): BOOLEAN;
    BEGIN
      RETURN TRUE;  (* FIXME... provide more accurate approximation *)
    END AccessedByCall;
  
  PROCEDURE AddToWorklist(instr: S.Instr);
    VAR
      entry: Worklist;
    BEGIN
      NEW(entry);
      entry.next := worklist;
      entry.instr := instr;
      worklist := entry;
    END AddToWorklist;
  
  PROCEDURE PropagateInstr(propInstr: S.Instr);
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
                                  designator: S.Designator): S.GateInstr;
        VAR
          instr: S.Instr;
          gate: S.GateInstr;
          i: LONGINT;
          type: S.Type;
        BEGIN
          FOR instr IN merge.Instructions() DO
            IF (instr.opcode = S.designatorGate) &
               S.SameDesignator(designator, instr.designator) THEN
              RETURN instr(S.GateInstr);
            END;
          END;

          gate := merge.AddGate(S.designatorGate);
          gate.SetDesignator(designator);
          FOR i := 1 TO merge.IncomingPaths() DO
            gate.AddOpnd(undefValue);
          END;
          WITH propInstr: S.GateInstr DO
            gateToInstr.Set(gate, gateToInstr.Get(propInstr));
          ELSE
            CASE propInstr.opcode OF
            | S.get:
              type := propInstr.resultList.type;
            | S.set:
              type := propInstr.opndList.nextOpnd.arg.type;
            END;
            ASSERT(type# S.noType);
            gateToInstr.Set(gate, NEW(MemAccess, type, propInstr.designator,
                                      propInstr.opndList.arg));
          END;
          RETURN gate;
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
          IF (opnd.arg = undefValue) THEN
            (* Setting argument value for first time: propagate instruction
               result if all argument slots are filled.  *)
            opnd.ReplaceArg(value);
            
            INC(gate.marker);
            IF (gate.marker = LEN(merge.jumps^)) THEN
              res := gate.AddResult(gate.opndList.arg.type);
              AddToWorklist(gate);
            END;
          ELSE
            opnd.ReplaceArg(value);
          END;
        END MergeValue;
      
      PROCEDURE MergeLoopValue(loopStart: S.Block; pathIndex: LONGINT;
                               designator: S.Designator; value: S.Result);
        VAR
          gate: S.GateInstr;
          opnd: S.Opnd;
          res: S.Result;
          memAccess: MemAccess;
        BEGIN
          gate := GetDesignatorGate(loopStart, designator);
          opnd := gate.opndList;
          WHILE (pathIndex # 0) DO
            opnd := opnd.nextOpnd; DEC(pathIndex);
          END;
          IF (opnd.arg = undefValue) THEN
            (* Setting argument value for first time: propagate instruction
               result if this is the first argument.  *)
            opnd.ReplaceArg(value);
            
            INC(gate.marker);
            IF (gate.marker = 1) THEN  (* first one wins *)
              memAccess := gateToInstr.Get(gate);
              res := gate.AddResult(memAccess.type);
              AddToWorklist(gate);
            END;
          ELSE
            opnd.ReplaceArg(value);
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

          | S.exit:
            (* nothing: we are at the end of the function *)
          END;
        END;
      END PropagateValue;

    PROCEDURE FixedDesignator(designator: S.Designator): BOOLEAN;
      BEGIN
        RETURN (LEN(designator^) = 1) & (designator[0] IS S.Var);
      END FixedDesignator;
    
    BEGIN
      IF (propInstr.info = NIL) THEN
        propInstr.info := propInstr;             (* mark as visited *)
        CASE propInstr.opcode OF
        | S.enter, S.allocateStack, S.return, S.exit, S.guard, S.jump, S.merge,
          S.loopStart, S.loopExit, S.loopBackedge, S.loopEnd, S.call, S.copy:
          (* nothing *)
        | S.get:
          IF FixedDesignator(propInstr.designator) THEN
            PropagateValue(propInstr.designator,
                           propInstr.resultList, propInstr);
          END;
        | S.set:
          IF FixedDesignator(propInstr.designator) THEN
            PropagateValue(propInstr.designator,
                           propInstr.opndList.nextOpnd.arg, propInstr);
          END;
        | S.designatorGate:
          PropagateValue(propInstr.designator,
                         propInstr.resultList, propInstr.block);
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
        | S.guard, S.merge, S.loopStart, S.loopEnd:
          RETURN VisibleEffect(instr, set);
        | S.loopBackedge:
          RETURN VisibleEffect(instr(S.LoopBackedgeInstr).start, set);
        | S.jump, S.loopExit:
          RETURN ReadingUse(instr.MergingTarget());
        | S.call:
          IF AccessedByCall (instr.opndList.arg, set.designator, read) THEN
            RETURN TRUE;               (* assume the worst *)
          ELSE
            (* the called procedure cannot read the local variable  *)
            RETURN VisibleEffect(instr, set)
          END;
          
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
  
  PROCEDURE ReplaceUses(old, new: S.Result; eliminateLoopEnd: BOOLEAN);
    VAR
      use: S.Opnd;
    BEGIN
      WHILE (old.useList # NIL) DO
        use := old.useList;
        (*D.Log("  replacing", use);*)
        IF ((use.instr.opcode = S.designatorGate) OR
            (use.instr.opcode = S.gate)) &
           (use.instr # old.instr) THEN
          AddToWorklist(use.instr);
        END;
        use.ReplaceArg(new);

        IF eliminateLoopEnd &
           use.instr.IsLoopEndGate() &
           use.instr.AllOpndsSameValue() THEN
          (* If we eliminate a gate that is part a loopStart, then we might
             leave dangling gates in the loopEnd that were taking this gate as
             input, and now take a single value from outside the loop.  Such
             gates create artifical values representing in fact the original
             input value.  So we eliminate such gates as well.  *)
          ReplaceUses(use.instr.resultList, use.arg, FALSE);
        END;
      END;
    END ReplaceUses;
  
  PROCEDURE PromoteDesignatorGate(instr: S.GateInstr);
    VAR
      opnd: S.Opnd;
    BEGIN            (* pre: instr.opcode in {designatorGate, gate} *)
      IF (instr.resultList = NIL) THEN
        (* unused; for a gate within a merge, this means that there is at least
           one undefined argument  *)
        instr.Delete();
      ELSIF (instr.merge IS S.LoopStartInstr) THEN
        IF (instr.opndList.nextOpnd.arg = instr.resultList) THEN
          (* value not changed within loop *)
          ReplaceUses(instr.resultList, instr.opndList.arg, TRUE);
          instr.Delete();
        ELSIF (instr.opcode = S.designatorGate) THEN
          instr.DesignatorGateToGate();
        END;
      ELSIF (instr.merge.opcode = S.loopEnd) THEN
        (* gates that belong to a loopEnd are never eliminated; otherwise the
           instruction blocker would get confused for uses of gate operands
           _after_ the loop *)
        instr.DesignatorGateToGate();
      ELSE                               (* no undefined arguments *)
        opnd := instr.opndList;
        WHILE (opnd.nextOpnd # NIL) & (opnd.nextOpnd.arg = opnd.arg) DO
          opnd := opnd.nextOpnd;
        END;
        IF (opnd.nextOpnd = NIL) THEN    (* all arguments are the same *)
          ReplaceUses(instr.resultList, instr.opndList.arg, FALSE);
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

  PROCEDURE FixLoopStart(gate: S.GateInstr);
    VAR
      loopStart: S.LoopStartInstr;
      get: S.Instr;
      memAccess: MemAccess;
      dep: S.Dep;
    BEGIN
      loopStart := gate.merge(S.LoopStartInstr);
      memAccess := gateToInstr.Get(gate);
      
      get := fctBlock.AddInstr1(S.get, memAccess.address);
      get.SetDesignator(memAccess.designator);
      FOR dep IN loopStart.BeforeList(S.depMemory) DO
        get.AddDep(S.depMemory, dep.before);
        dep.DeleteDep();
      END;
      loopStart.AddDep(S.depMemory, get);
      gate.opndList.ReplaceArg(get.AddResult(memAccess.type));
    END FixLoopStart;
  
  BEGIN
    worklist := NIL;

    undefValue := fctBlock.enter.AddResult(S.noType);
    
    fctBlock.SetMarkers(NIL, 0);
    gateToInstr := NEW(Dictionary.Dictionary(S.GateInstr, MemAccess));
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

    (* fix partial gates for which not all operands are defined *)
    WHILE (undefValue.useList # NIL) DO
      gate := undefValue.useList.instr(S.GateInstr);
      CASE gate.merge.opcode OF
      | S.loopStart:
        IF (gate.opndList = undefValue.useList) THEN
          (* the loop gate has no "incoming" argument, only the value of the
             backedge is know: insert "get" instruction in front of the loop
             that provides the missing information *)
          FixLoopStart(gate);
        ELSE
          (* value of variable is unknown at the end of the loop: discard
             loop gate *)
          ReplaceUses(gate.resultList, gate.opndList.arg, TRUE);
          gate.Delete();
        END;
      | S.merge, S.guard:
        ASSERT(gate.resultList = NIL);
        gate.Delete();
      END;
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
      IF (instr.opndList # NIL) THEN
        (* skip if this instruction has already been nuked *)
        PromoteDesignatorGate(instr(S.GateInstr));
      END;
    END;
    ASSERT(undefValue.useList = NIL);
    undefValue.DeleteResult();
  END Transform;

END OOC:X86:Destore.
