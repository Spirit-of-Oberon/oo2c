MODULE OOC:X86:ConstProp;

IMPORT
  Object, Object:Boxed, Object:BigInt, S := OOC:X86:SSA;
  
(* FIXME... check for overflows, and don't do folding if an overflow
   happens *)

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: S.Instr;
  END;

CONST
  unclassified = NIL;
  
VAR
  notConstant: S.Result;

PROCEDURE ComputeConst(pb: S.FunctionBlock; instr: S.Instr): S.Result;
  VAR
    arg1, arg2: S.Result;
    val1, val2, v: Object.Object;
    i1, i2: BigInt.BigInt;
  BEGIN
    IF (instr.opcode = S.typeConv) THEN
      arg1 := instr.opndList.arg.info(S.Result);
      v := arg1.instr.designator[0](S.Const).value;
      IF (v IS BigInt.BigInt) & (instr.resultList.type < S.real32) THEN
        (* FIXME... check for overflow *)
        RETURN pb.AddConstType(NEW(S.Const, v, -1), instr.resultList.type);
      END;
    ELSIF (instr.opcode = S.gate) THEN
      (* can only be folded if all paths have the same value *)
      RETURN NIL;
    ELSIF (instr. SizeOpndList() >= 2) THEN
      arg1 := instr.opndList.arg.info(S.Result);
      val1 := arg1.instr.designator[0](S.Const).value;
      arg2 := instr.opndList.nextOpnd.arg.info(S.Result);
      val2 := arg2.instr.designator[0](S.Const).value;
      v := NIL;
      
      CASE arg1.type OF
      | S.signed8 .. S.address:
        IF (val1 IS BigInt.BigInt) & (val2 IS BigInt.BigInt) THEN
          (* only dealing with integers for now; FIXME... add set values *)
          i1 := val1(BigInt.BigInt);
          i2 := val2(BigInt.BigInt);
          
          CASE instr.opcode OF
          | S.add: v := i1.Add(i2);
          | S.sub: v := i1.Sub(i2);
          | S.mul: v := i1.Mul(i2);
            
          | S.asr, S.asl, S.lsr, S.lsl, S.rl, S.rr:
            v := NIL;  (* FIXME... add shift operations *)
            
          | S.eql: v := Boxed.NewBoolean(i1.Cmp(i2)  = 0);
          | S.neq: v := Boxed.NewBoolean(i1.Cmp(i2)  # 0);
          | S.leq: v := Boxed.NewBoolean(i1.Cmp(i2) <= 0);
          | S.lss: v := Boxed.NewBoolean(i1.Cmp(i2) <  0);
          | S.geq: v := Boxed.NewBoolean(i1.Cmp(i2) >= 0);
          | S.gtr: v := Boxed.NewBoolean(i1.Cmp(i2) >  0);
          END;
        END;
        
      ELSE                               (* not supported *)
        (*instr. LogOpcode ("not folding (unsupported subclass)");
        instr. opndList. arg. instr. LogOpcode ("arg1");
        instr. opndList. nextOpnd. arg. instr. LogOpcode ("arg2");*)
      END;

      IF (v # NIL) THEN
        IF (v IS Boxed.Boolean) THEN
          RETURN pb.AddConstBool(v(Boxed.Boolean).value);
        ELSE
          RETURN pb.AddConstType(NEW(S.Const, v, -1), instr.resultList.type);
        END;
      END;
    END;
    RETURN NIL;                          (* fall through: no folding *)
  END ComputeConst;

PROCEDURE Transform* (pb: S.FunctionBlock);
  VAR
    worklist: Worklist;
    instr: S.Instr;
    v: S.Node;
    
  PROCEDURE AddToWorklist(instr: S.Instr);
    VAR
      wl: Worklist;
    BEGIN
      IF (instr.marker = 0) THEN
        instr.marker := 1;
        
        NEW (wl);
        wl.next := worklist;
        wl.instr := instr;
        worklist := wl;
      END;
    END AddToWorklist;

  PROCEDURE SetInfo(instr: S.Instr; info: S.Result);
    VAR
      res: S.Result;
    BEGIN
      IF (info = unclassified) OR (info = notConstant) THEN
        instr.info := info;
      ELSE
        instr.info := info.instr;
      END;
      res := instr.resultList;
      WHILE (res # NIL) DO
        res.info := info;
        res := res.nextResult;
      END;
    END SetInfo;

  PROCEDURE AddUsesToWorklist(res: S.Result);
    VAR
      use: S.Opnd;
      useInstr: S.Instr;
    BEGIN
      use := res.useList;
      WHILE (use # NIL) DO
        useInstr := use.instr;
        IF (useInstr.info = unclassified) THEN
          AddToWorklist(useInstr);
        END;
        use := use.nextUse;
      END;
    END AddUsesToWorklist;
  
  PROCEDURE UpdateInfo(instr: S.Instr; info: S.Result);
    VAR
      res: S.Result;
    BEGIN
      IF (info = unclassified) OR (info = notConstant) THEN
        instr.info := info;
      ELSE
        instr.info := info.instr;
      END;
      res := instr.resultList;
      WHILE (res # NIL) DO
        res.info := info;
        AddUsesToWorklist(res);
        res := res.nextResult;
      END;
    END UpdateInfo;
  
  PROCEDURE ClassifyInstr (instr: S.Instr);
  (* Try to classify `instr' as `notConstant', or as a constant value.  *)
    VAR
      state: S.Node;
      const: S.Result;
      opnd: S.Opnd;
    BEGIN
      state := instr;
      opnd := instr.opndList;
      LOOP
        IF (opnd = NIL) THEN
          EXIT;
        ELSIF (opnd.arg.info = unclassified) THEN
          state := unclassified;
        ELSIF (opnd.arg.info = notConstant) THEN
          state := notConstant;
          EXIT;
        END;
        opnd := opnd.nextOpnd;
      END;
      
      IF (state = instr) THEN          (* all operands are constants *)
        const := ComputeConst(pb, instr);
        IF (const = NIL) THEN
          (* we cannot fold this expression: treat it a non constant *)
          UpdateInfo(instr, notConstant);
        ELSE
          ASSERT(instr.resultList.nextResult = NIL);
          UpdateInfo(instr, const);
        END;
      ELSIF (state = notConstant) THEN (* at least one is not constant *)
        UpdateInfo(instr, notConstant);
        (* ELSE: no opnd is notConstant, at least one unclassified *)
      END;
    END ClassifyInstr;
  
  BEGIN
    (* Set the `info' field of all results to `unclassified', with the
       exception of constants and the `enter' instructions.  Constants get
       themself as `info', the enter instruction is marked as `notConstant' *)
    FOR instr IN pb.AllInstructions(-1) DO
      instr.marker := 0;

      IF (instr.opcode = S.const) THEN
        IF (instr.designator[0] IS S.Const) THEN
          instr.info := instr;
          instr.resultList.info := instr.resultList;
          ASSERT(instr.resultList.nextResult = NIL);
        ELSE  (* constant at run-tine, but we do not know the value here *)
          SetInfo(instr, notConstant);
        END;
      ELSIF (instr.beforeList # NIL) OR (instr.afterList # NIL) THEN
        (* any instruction that accesses memory cannot be constant;
           likewise, any instruction that can branch control flow *)
        SetInfo(instr, notConstant);
      ELSE
        SetInfo(instr, unclassified);
      END;
    END;
    SetInfo(pb.enter, notConstant);
    
    (* first pass over all instructions *)
    worklist := NIL;
    FOR instr IN pb.AllInstructions(-1) DO
      IF (instr.info = unclassified) & (instr.marker = 0) THEN
        (* ignore instructions that have already been classified, and defer
           instructions that have been put on the worklist already *)
        ClassifyInstr(instr);
      END;
    END;

    (* repeat until worklist is empty *)
    WHILE (worklist # NIL) DO
      instr := worklist.instr;
      instr.marker := 0;
      worklist := worklist.next;
      ASSERT (instr.info = unclassified);
      ClassifyInstr(instr);
    END;

    (* replace uses of folded expressions with the constant result *)
    FOR instr IN pb.AllInstructions(-1) DO
      v := instr.info;
      IF (v # unclassified) & (v # notConstant) & (v # instr) THEN
        instr.resultList.ReplaceUses(instr.resultList.info(S.Result));
      END;
    END;
  END Transform;

BEGIN
  notConstant := NEW(S.Result, -1);
END OOC:X86:ConstProp.
