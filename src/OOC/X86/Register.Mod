MODULE OOC:X86:Register;

IMPORT
  Object, ADT:ArrayList, ADT:Dictionary, S := OOC:X86:SSA,
  M := OOC:X86:Machine, OOC:SSA:IGraph(*, Log, D := OOC:X86:Debug, Err*);
  
CONST
  gpRegisters = 0;
  (**Set of general purpose registers.  *)
  fpRegisters = 1;
  (**Set of floating point registers.  *)
  
TYPE
  RegisterFile = POINTER TO RegisterFileDesc;
  RegisterFiles = POINTER TO ARRAY OF RegisterFile;
  RegisterFileDesc = RECORD
    (S.NodeDesc)
    registerType: SHORTINT;
    resultList: ArrayList.ArrayList(S.Result);
    iGraph: IGraph.Graph;
    maxColor: IGraph.Color;
    prelocatedRep: ARRAY S.lastRegister+1 OF S.Result;
    (* Note: Only applies to general purpose registers.  *)
    doneBranches: Dictionary.Dictionary;
  END;
  
TYPE
  LiveData = POINTER TO LiveDataDesc;
  LiveDataDesc = RECORD
    (Object.ObjectDesc)
    block: S.Block;
    position: S.Instr;
    remainingInput: LONGINT;
    live: IGraph.Vector;
  END;


PROCEDURE (rf: RegisterFile) INIT*(registerType: SHORTINT);
  BEGIN
    rf.INIT^();
    rf.registerType := registerType;
    rf.resultList := NEW(ArrayList.ArrayList(S.Result), 16);
    rf.iGraph := NIL;
    rf.maxColor := -1;
    rf.doneBranches := NEW(Dictionary.Dictionary);
  END INIT;

PROCEDURE (ld: LiveData) INIT*(block: S.Block; position: S.Instr;
                               remainingInput: LONGINT; live: IGraph.Vector);
  BEGIN
    ld.block := block;
    ld.position := position;
    ld.remainingInput := remainingInput;
    ld.live := live;
  END INIT;

PROCEDURE LogLiveData(rf: RegisterFile; ld: LiveData);
(*  VAR
    g: IGraph.Graph;
    i: LONGINT;
  BEGIN
    g := rf.iGraph;
    D.Log("block", ld.block);
    D.Log("  live ranges active after", ld.position);
    FOR i := 0 TO g.size-1 DO
      IF g.In(i, ld.live) THEN
        D.Log("    ", rf.resultList.array[i]);
      END;
    END;*)
  END LogLiveData;

PROCEDURE GetRegisterFiles (): RegisterFiles;
(* Produces an array with empty entries for all possible register files.  *)
  VAR
    rfs: RegisterFiles;
    rf: RegisterFile;
    i: LONGINT;
  CONST
    size = S.real64+1;
  BEGIN
    NEW (rfs, size);
    FOR i := 0 TO LEN (rfs^)-1 DO
      rfs[i] := NIL;
    END;

    rf := NEW(RegisterFile, gpRegisters);
    FOR i := 0 TO S.lastRegister DO
      rf.prelocatedRep[i] := NIL;
    END;
    rfs[S.signed8] := rf;
    rfs[S.signed16] := rf;
    rfs[S.signed32] := rf;
    rfs[S.unsigned8] := rf;
    rfs[S.unsigned16] := rf;
    rfs[S.unsigned32] := rf;
    rfs[S.address] := rf;

    rf := NEW(RegisterFile, fpRegisters);
    FOR i := 0 TO S.lastRegister DO
      rf.prelocatedRep[i] := NIL;
    END;
    rfs[S.real32] := rf;
    rfs[S.real64] := rf;
    
    RETURN rfs
  END GetRegisterFiles;

PROCEDURE IdentifyResults (b: S.FunctionBlock): RegisterFiles;
(**Identifies all results of instructions from @oparam{b} that are stored in
   registers.  These results are added to the @ofield{RegisterFile.resultList},
   their @ofield{S.Result.info} is changed to refer to its instance of
   @otype{RegisterFile}, and @ofield{S.Result.marker} is set to the index of
   the result in the list @ofield{RegisterFile.resultList}.

   Results that are never materialized as a distinct value are ignored.
   Results that have already been assigned a register location are treated as a
   single life range, using the first result encountered for a particular
   register as its witness.  *)
  VAR
    rfs: RegisterFiles;
    
  PROCEDURE ScanBlock (b: S.Block);
    VAR
      instr: S.Instr;
      res: S.Result;
      rf: RegisterFile;

    PROCEDURE Relevant(res: S.Result): BOOLEAN;
      (**TRUE if the result must be assigned a register, or if its assigned
         register must be considered when computing the interference graph.
         Registers that are hot managed by the allocator, like stack pointer
         and frame pointer, are ignored.  *)
      BEGIN
        RETURN (res.register # S.cc) OR (res.adrMode # S.register);
      END Relevant;
    
    BEGIN
      FOR instr IN b.Instructions() DO
        IF instr.IsLive() THEN
          res := instr.resultList;
          WHILE (res # NIL) DO
            IF Relevant(res) THEN
              rf := rfs[res.type];
              res.info := rf;
              res.marker := rf.resultList.size;
              rf.resultList.Append(res);
            END;
            res := res.nextResult;
          END;
        END;

        WITH instr: S.Block DO
          ScanBlock(instr);
        ELSE
          (* nothing *)
        END;
      END;
    END ScanBlock;
  
  BEGIN
    rfs := GetRegisterFiles();
    ScanBlock (b);
    RETURN rfs;
  END IdentifyResults;

PROCEDURE SweepLiveSet (rf: RegisterFile; b: S.Block; instr: S.Instr;
                        live: IGraph.Vector): S.Instr;
(**The result indicates the place where the sweep stopped, and how the calling
   procedure should propagate the current set of live ranges further along.

   @table @asis
   @item @code{NIL}
   The beginning of the block @oparam{b} has been reached.
   @item @oparam{b}
   The current position is unreachable and the state should be discarded.
   @item any other instruction @var{i}
   The merging block @var{i} has been reached, and the live set @oparam{live}
   represents the state right after the block.
   @end table  *)
  VAR
    iGraph: IGraph.Graph;
    res: S.Result;

  PROCEDURE MarkOpndAsLive (live: IGraph.Vector; iter: S.IterOperands);
    VAR
      opnd: S.Opnd;
    BEGIN
      FOR opnd IN iter DO
        IF opnd.immediate THEN
          MarkOpndAsLive(live, opnd.arg.instr.Operands());
        ELSIF (opnd.arg.info = rf) THEN
          IF ~iGraph.In(opnd.arg.marker, live) THEN
            (* the live range of the value passed to `opnd' interferes with
               all live ranges currently active: calculate union between bit
               matrix (row `opnd.arg.marker') and the live vector  *)
            (*out.Result("AddToLive", opnd.arg);*)
            iGraph.AddToLive(opnd.arg.marker, live);
          END;
        END;
      END;
    END MarkOpndAsLive;

  BEGIN
    iGraph := rf.iGraph;
    (* write current set of live results
    D.Log2("b", b, "instr", instr);
    FOR i := 0 TO rf.resultList.Size()-1 DO
      IF iGraph.In(i, live) THEN
        D.Log("   >>> in live", rf.resultList.array[i]);
      END;
    END;*)
    
    WHILE (instr # NIL) DO
      CASE instr.opcode OF
      | S.merge, S.loopEnd:
        RETURN instr;
      | S.loopExit:  (* S.return as well? FIXME... *)
        RETURN b;
      | S.loopStart:
        MarkOpndAsLive(live, instr.GateOperands());
      ELSE
        IF (instr.opcode = S.branch) & ~rf.doneBranches.HasKey(instr) THEN
          (* Instructions of type `branch' are seen twice.  First, when the
             live set is propagated forward from the instruction following it.
             In this case, the live set is moved to the branch's merge and
             continues there.  Second, when the merge and guards inside the
             branch have been swept and the live set continues at the place
             of the branch.  *)
          RETURN instr;
        END;
        IF instr.IsLive() THEN
          (*out.Instr("current instr", instr);*)
          FOR res IN instr.Results() DO
            IF (res.info = rf) & ~res.NonImmediateUses() THEN
              (* this is a pathological case: the instruction leaves a result
                 in a register, but its value is never used; in effect this
                 corresponds to an empty live range that interferes with
                 nothing; but since a register is overwritten here, it _does_
                 interfere with everything live at this point in practice  *)
              (*out.Result("AddToLive", res);*)
              iGraph.AddToLive(res.marker, live);
            END;
          END;
          
          (* remove all results produced by this instruction from our live set  *)
          FOR res IN instr.Results() DO
            IF (res.info = rf) THEN
              iGraph.RemoveFromLive(res.marker, live);
            END;
          END;
          
          (* Every argument of the instruction is checked whether it starts a
             live range and is placed into the live vector if it does.  *)
          CASE instr.opcode OF
          | S.gate:
            (* nothing *)
          | S.loopBackedge:
            MarkOpndAsLive(live, instr.GateOperands());
          ELSE
            MarkOpndAsLive(live, instr.Operands());
          END;
        END;
      END;
      
      instr := instr.prevInstr;
    END;
    RETURN NIL;
  END SweepLiveSet;

PROCEDURE CoalesceFixedLocations(rf: RegisterFile; b: S.FunctionBlock): LONGINT;
  VAR
    i, addedCopies: LONGINT;
    res: S.Result;
    instr: S.Instr;
    inOutOpnd: S.Opnd;
    success: BOOLEAN;
    
  PROCEDURE CoalesceWith(coalesced, base: S.Result): BOOLEAN;
    VAR
      iGraph: IGraph.Graph;
    BEGIN
      iGraph := rf.iGraph;
      IF iGraph.Conflicts(coalesced.marker, base.marker) THEN
        RETURN FALSE;
      ELSE
        iGraph.MergeRowColumn(coalesced.marker, base.marker);
        coalesced.marker := -base.marker-1;
        RETURN TRUE;
      END;
    END CoalesceWith;
  
  BEGIN
    addedCopies := 0;
    FOR i := 0 TO rf.resultList.size-1 DO
      res := rf.resultList.array[i];
      IF (res.adrMode # S.noLocation) THEN
        IF (rf.prelocatedRep[res.register] = NIL) THEN
          (* register result as representative of all result that are
             forced into a particular register by default *)
          rf.prelocatedRep[res.register] := res;
        ELSE
          success := CoalesceWith(res, rf.prelocatedRep[res.register]);
          ASSERT(success);
        END;
      END;

      instr := res.instr;
      IF (res = instr.resultList) THEN   (* first result *)
        inOutOpnd := M.InOutOpnd(instr);
        IF (inOutOpnd # NIL) THEN
          (* enforce 2-address restriction: coalesce result with operand *)
          ASSERT(res.adrMode = S.noLocation);
          IF (inOutOpnd.arg.marker >= 0) THEN
            success := CoalesceWith(inOutOpnd.arg, res);
          ELSE
            success := CoalesceWith(res, rf.resultList.array[-inOutOpnd.arg.marker-1]);
          END;
          IF ~success THEN
            inOutOpnd.InsertCopy();
            INC(addedCopies);
          END;
        END;
      END;
    END;
    RETURN addedCopies;
  END CoalesceFixedLocations;

PROCEDURE AssignRegisterFile (rf: RegisterFile; b: S.FunctionBlock): LONGINT;
  VAR
    ld, ldBranch: LiveData;
    ldReady: ArrayList.ArrayList(LiveData);
    ldWaiting: Dictionary.Dictionary(S.Block, LiveData);
    instr: S.Instr;
    merge: S.MergeInstr;
    block, branchBlock: S.Block;
    addedCopies: LONGINT;
    
  PROCEDURE AddResToLive (res: S.Result; live: IGraph.Vector);
    BEGIN
      IF (res. info = rf) & ~rf.iGraph.In(res.marker, live) THEN
        rf.iGraph.AddToLive(res.marker, live);
      END;
    END AddResToLive;
  
  PROCEDURE AssignRegisterNames (rf: RegisterFile; colors: IGraph.ColorArray);
    VAR
      i, j: LONGINT;
      c, maxColor: IGraph.Color;
      colorToRegister: ARRAY S.lastRegister+1 OF S.Register;
      reg: S.Register;
      res: S.Result;

    PROCEDURE IsFreeRegister(reg: S.Register): BOOLEAN;
      VAR
        x: S.Register;
      BEGIN
        FOR x IN colorToRegister DO
          IF (x = reg) THEN
            RETURN FALSE;
          END;
        END;
        RETURN TRUE;
      END IsFreeRegister;
    
    BEGIN
      (* for coalesced values, assign the color of the representative to
         all life ranges that have been coalesced with it *)
      FOR i := 0 TO LEN(colors^)-1 DO
        res := rf.resultList.array[i];
        j := res.marker;
        IF (j < 0) THEN
          REPEAT
            j := rf.resultList.array[-j-1].marker;
          UNTIL (j >= 0);
          colors[i] := colors[j];
        END;
      END;
      
      (* find out the maximum of all assigned colors *)
      maxColor := -1;
      FOR c IN colors^ DO
        IF (c > maxColor) THEN
          maxColor := c;
        END;
      END;
      (*ASSERT(maxColor < 4);*)
      rf.maxColor := maxColor;

      (*FOR i := 0 TO maxColor DO
        Log.Int("color", i);
        FOR j := 0 TO LEN(colors^)-1 DO
          IF (colors[j] = i) THEN
            D.Log("  ", rf.resultList.array[j]);
            maxColor := c;
          END;
        END;
      END;*)
      
      (* create mapping of color to register id *)
      FOR i := 0 TO S.lastRegister DO
        colorToRegister[i] := -1;
      END;
      FOR i := 0 TO S.lastRegister DO
        IF (rf.prelocatedRep[i] # NIL) THEN
          colorToRegister[colors[rf.prelocatedRep[i].marker]] :=
              rf.prelocatedRep[i].register;
        END;
      END;
      reg := S.gp0-1;
      FOR i := 0 TO maxColor DO
        IF (colorToRegister[i] < 0) THEN
          REPEAT
            INC(reg);
          UNTIL IsFreeRegister(reg);
          colorToRegister[i] := reg;
        END;
      END;
      
      (* assign each result the name of "its" register *)
      FOR i := 0 TO LEN(colors^)-1 DO
        res := rf.resultList.array[i];
        IF (res.adrMode # S.noLocation) THEN
          ASSERT(res.register = colorToRegister[colors[i]]);
        END;
        res.adrMode := S.register;
        res.register := colorToRegister[colors[i]];
      END;
    END AssignRegisterNames;

  PROCEDURE AddToReady(ld: LiveData);
    BEGIN
      ldReady.Append(ld);
    END AddToReady;
  
  PROCEDURE AddJumpsToReady(merge: S.MergeInstr; ld: LiveData);
    VAR
      jump, position: S.Instr;
      mergedBlock: S.Block;
      opnd: S.Opnd;
      i: LONGINT;
      ldJump: LiveData;
    BEGIN
      FOR i := 0 TO LEN(merge.jumps^)-1 DO
        jump := merge.jumps[i];
        mergedBlock := jump.block;
        position := jump;
        IF (merge.opcode = S.loopEnd) THEN
          position := position.prevInstr;
        END;
        ldJump := NEW(LiveData, mergedBlock, position, 0,
                      rf.iGraph.CopyVector(ld.live));
        FOR opnd IN jump.GateOperands() DO
          AddResToLive(opnd.arg, ldJump.live);
        END;
        AddToReady(ldJump);
      END;
    END AddJumpsToReady;

(*  PROCEDURE DumpMatrix(rf: RegisterFile);
    VAR
      i, j: LONGINT;
    BEGIN
      FOR i := 0 TO rf.resultList.Size()-1 DO
        Err.Object("conflict "+D.Label(rf.resultList.array[i])+":"); 
        FOR j := 0 TO rf.resultList.Size()-1 DO
          IF rf.iGraph.Conflicts(i, j) THEN
            Err.Object(" "+D.Label(rf.resultList.array[j]));
          END;
        END;
        Err.Ln;
      END;
    END DumpMatrix;*)
  
  BEGIN
    (*out := NEW(D.Output, b, "AssignRegisterFile");
    out.WriteBlock();*)

    rf.iGraph := IGraph.NewGraph(rf.resultList.size);
    
    (* sweep life set backwards over blocks; if a life range begins at a
       instruction, remove it from the life set, if ends there, then add it
       to the life set; each time a new entry is added, it must be marked
       as interfering with all current elements of the set *)
    ld := NEW(LiveData, b, b.instrTail, 0, rf.iGraph.NewVector());
    ldReady := NEW(ArrayList.ArrayList(LiveData), 4);
    AddToReady(ld);
    ldWaiting := NEW(Dictionary.Dictionary(S.Block, LiveData));
    WHILE (ldReady.size # 0) DO
      ld := ldReady.array[ldReady.size-1];
      ldReady.Remove(ldReady.size-1);
      LogLiveData(rf, ld);
      instr := SweepLiveSet(rf, ld.block, ld.position, ld.live);
      
      IF (instr = NIL) THEN
        block := ld.block;
        CASE block.opcode OF
        | S.merge:
          AddJumpsToReady(block(S.MergeInstr), ld);
          
        | S.loopEnd:
          AddJumpsToReady(block(S.MergeInstr), ld);
          instr := block.prevInstr;
          ASSERT(instr(S.LoopStartInstr).end = block);
          ld := NEW(LiveData, instr(S.LoopStartInstr),
                    instr(S.LoopStartInstr).instrTail, 0,
                    rf.iGraph.NewVector());
          (* this ld stays empty until the loopBackedge instr fills it *)
          AddToReady(ld);
          
        | S.branch, S.loopStart:
          ld.block := block.block;
          ld.position := block;
          AddToReady(ld);
          
        | S.guard:
          IF (block(S.MergeInstr).jumps # NIL) THEN
            AddJumpsToReady(block(S.MergeInstr), ld);
          END;
          
          branchBlock := block.block(S.BranchInstr);
          IF ldWaiting.HasKey(branchBlock) THEN
            ldBranch := ldWaiting.Get(branchBlock);
            rf.iGraph.MergeVector(ld.live, ldBranch.live);
            DEC(ldBranch.remainingInput);
            IF (ldBranch.remainingInput = 0) THEN
              AddToReady(ldBranch);
              ldWaiting.Delete(branchBlock);
              rf.doneBranches.Set(branchBlock, NIL);
            END;
          ELSE
            ld := NEW(LiveData, branchBlock, NIL,
                      LEN(branchBlock(S.BranchInstr).paths^)-1, ld.live);
            IF (ld.remainingInput = 0) THEN
              AddToReady(ld);
              rf.doneBranches.Set(branchBlock, NIL);
            ELSE
              ldWaiting.Set(branchBlock, ld);
            END;
          END;
          
        | S.function:
          (* we are done *)
        END;
      ELSIF (instr.opcode = S.branch) THEN (* go into merge block *)
        merge := instr.TopLevelMerge();
        ld.block := merge;
        ld.position := ld.block.instrTail;
        AddToReady(ld);
      ELSIF (instr = ld.block) THEN
        (* discard *)
      ELSE       (* looking at merge instruction: sweep merge block *)
        ld.block := instr(S.Block);
        ld.position := ld.block.instrTail;
        AddToReady(ld);
      END;
    END;
    ASSERT(ldWaiting.Size() = 0);
    rf.iGraph.SymmetricMatrix;
(*    DumpMatrix(rf);*)
    
    (* coalesce fixed locations so that all results assigned to a given
       register are given the same color *)
    addedCopies := CoalesceFixedLocations(rf, b);

    IF (addedCopies = 0) THEN
      (* calculate a coloring for the resulting graph; use the coloring to
         assign register ids to results *)
      AssignRegisterNames(rf, rf.iGraph.ColorGraphCombinatorial());
    END;

    RETURN addedCopies;
  END AssignRegisterFile;

PROCEDURE AssignRegisters* (b: S.FunctionBlock);
(**Assigns registers to values produced by SSA instructions.

   @precond
   The fields @ofield{S.Result.marker} and @ofield{S.Result.info} of all
   instructions in @oparam{b} are not in use.
   @end precond  *)
  VAR
    rfs: RegisterFiles;
    rf: RegisterFile;
    addedCopies: LONGINT;
  BEGIN
    REPEAT
      b.SetMarkers(NIL, -1);
      
      (* calculate for each register set the results that are mapped to this
         set *)
      rfs := IdentifyResults(b);
      
      (* assign concrete registers for every result; this is done for each of
         the different register files *)
      addedCopies := 0;
      FOR rf IN rfs^ DO
        IF (rf # NIL) & (rf.iGraph = NIL) THEN
          INC(addedCopies, AssignRegisterFile(rf, b));
        END;
      END;
(*      IF (addedCopies # 0) THEN
        D.WriteFunction(b);
      END;*)
    UNTIL (addedCopies = 0);
  END AssignRegisters;

END OOC:X86:Register.
