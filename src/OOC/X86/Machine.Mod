MODULE OOC:X86:Machine;  (* machine model *)

IMPORT
  S := OOC:X86:SSA;
  
PROCEDURE InOutOpnd*(instr: S.Instr): S.Opnd;
(**If the target architecture implements a two-address instructin format, then
   this function returns the operand that shares its location with the
   instruction's result.  If input and output operands are dictinct, then the
   result is @code{NIL}.  *)
  BEGIN
    CASE instr.opcode OF
    | S.add, S.sub, S.mul, S.div, S.neg,
      S.asr, S.asl, S.lsr, S.lsl, S.rl, S.rr,
      S.bitTestAndSet, S.bitTestAndClear:
      RETURN instr.opndList;
    ELSE
      RETURN NIL;
    END;
  END InOutOpnd;

PROCEDURE ImmediateOpnd(instr: S.Instr): S.Opnd;
(**If the instruction can take an immediate operand, and if the argument passed
   to the operand is a suitable constant, then return the operand.  Otherwise,
   result is @code{NIL}.  *)
  VAR
    n: LONGINT;
    opnd: S.Opnd;

  PROCEDURE ImmediateValue(type: S.Type): BOOLEAN;
    BEGIN
      RETURN (type # S.real32) & (type # S.real64);
    END ImmediateValue;
  
  BEGIN
    CASE instr.opcode OF
    | S.call, S.guard:
      n := 0;
    | S.return:
      opnd := instr.opndList;
      IF (opnd.arg.instr.opcode = S.const) THEN
        (* shortcut return of fp values to load directly into st0 *)
        RETURN opnd;
      ELSE
        RETURN NIL;
      END;
    | S.eql, S.neq, S.lss, S.leq, S.gtr, S.geq,
      (* x86's cmp instruction is not symmetric with immediate opnd *)
      S.add, S.sub, S.bitTestAndSet, S.bitTestAndClear, S.allocateStack:
      (* first opnd is in/out, second may be immediate *)
      n := 1;
    | S.set:        (* first opnd is memory, second may be immediate *)
      n := 1;
    | S.setStack:
      n := 2;
    ELSE
      RETURN NIL;
    END;
    opnd := instr.NthOpnd(n);
    IF (opnd.arg.instr.opcode = S.const) &
       ImmediateValue (opnd.arg.type) THEN
      RETURN opnd;
    ELSE
      RETURN NIL;
    END;
  END ImmediateOpnd;

PROCEDURE MemOpnd(instr: S.Instr): S.Opnd;
(**If the instruction can take a memory operand, then return the operand.
   Otherwise, result is @code{NIL}.  *)
  VAR
    inout, opnd: S.Opnd;
    opcode: S.Opcode;
    
  PROCEDURE IsOffset(instr: S.Instr): BOOLEAN;
    BEGIN
      RETURN (instr.opcode = S.add);
    END IsOffset;

  BEGIN
    opcode := instr.opcode;
    CASE instr.opcode OF
    | S.set, S.get:
      IF instr.opndList.IsConst() OR IsOffset(instr.opndList.arg.instr) THEN
        instr.opndList.immediate := TRUE;
      END;
    | S.setStack, S.typeTag:
      RETURN NIL;
    ELSE
      inout := InOutOpnd(instr);
      opnd := instr.opndList;
      IF (S.eql <= opcode) & (opcode <= S.geq) & S.IsFloat(opnd.arg.type) THEN
        (* ucomis has different rules than cmp *)
        opnd := opnd.nextOpnd;
      END;
      WHILE (opnd # NIL) DO
        IF (opnd # inout) & (opnd.arg.instr.opcode = S.get) THEN
          RETURN opnd;
        END;
        opnd := opnd.nextOpnd;
      END;
    END;
    RETURN NIL;
  END MemOpnd;

PROCEDURE ApplyMachineModel*(b: S.FunctionBlock);
(**Expand call instructions and enable the target architecture's addressing
   modes by setting ``immediate'' flags for operands.  Also compute the
   stack area reserved for the arguments of function calls and to bounce
   floating point values between the xmm registers and st0.  *)
  VAR
    instr: S.Instr;
    opnd, imm, mem: S.Opnd;
    maxSizeCallStack: LONGINT;
    type: S.Type;
    
  PROCEDURE IsConst(opnd: S.Opnd): BOOLEAN;
    BEGIN
      RETURN (opnd.arg.instr.opcode = S.const);
    END IsConst;

  PROCEDURE ExpandCall(call: S.Instr);
    VAR
      instr, memoryDep: S.Instr;
      opnd, next: S.Opnd;
      offset: LONGINT;
      sp, res, arg: S.Result;
      reg: S.Register;
      clobbered: SET;
      type: S.Type;
      dep: S.Dep;

    PROCEDURE ArgSize(arg: S.Result): LONGINT;
      VAR
        size: LONGINT;
      BEGIN
        size := S.TypeSize(arg.type);
        IF (size < 4) THEN       (* stack elements are word aligned *)
          RETURN 4;
        ELSE
          RETURN size;
        END;
      END ArgSize;
    
    BEGIN
      offset := 0;
      memoryDep := call.GetBeforeInstr(S.depMemory);
      sp := call.opndList.nextOpnd.arg;
      opnd := call.opndList.nextOpnd.nextOpnd;  (* skip adr and sp *)
      WHILE (opnd # NIL) DO
        next := opnd.nextOpnd;

        arg := opnd.arg;
        IF S.IsSigned(arg.type) & (arg.type < S.signed32) THEN
          arg := b.FixType(arg, S.signed32);
        ELSIF S.IsUnsigned(arg.type) & (arg.type < S.unsigned32) THEN
          arg := b.FixType(arg, S.unsigned32);
        END;
        instr := b.AddInstr3(S.setStack, sp, b.AddConstLength(offset), arg);
        instr.AddDep(S.depMemory, memoryDep);
        call.AddDep(S.depMemory, instr);
        INC(offset, ArgSize(opnd.arg));
        
        opnd.DeleteOpnd();
        opnd := next;
      END;
      
      IF (offset > maxSizeCallStack) THEN
        maxSizeCallStack := offset;
      END;
      IF (call.resultList # NIL) THEN
        (* leave enough room on stack to bounce the result of the called
           procedure via the stack into a xmm register  *)
        type := call.resultList.type;
        IF S.IsFloat(type) THEN
          IF (S.TypeSize(type) > maxSizeCallStack) THEN
            maxSizeCallStack := S.TypeSize(type);
          END;

          (* add bounce instruction for function result; add memory dependency
             from bounce to original call, and move all memory dependencies
             on the call to the bounce instruction *)
          instr := b.AddInstr2(S.bounceResult, sp, call.resultList);
          res := instr.AddResult(type);
          call.resultList.ReplaceUsesExcept(res, instr.opndList.nextOpnd);

          FOR dep IN call.AfterList(S.depMemory) DO
            dep.instr.AddDep(S.depMemory, instr);
            dep.DeleteDep();
          END;
          instr.AddDep(S.depMemory, call);
        END;
      END;

      (* mark the registers that are potentially clobbered by the call *)
      clobbered := S.callerSaved;
      IF (call.resultList # NIL) THEN
        res := call.resultList;
        IF (res.type >= S.real32) THEN
          res.register := S.st0;
        ELSE
          res.register := S.gp0;
        END;
        res.adrMode := S.register;
        EXCL(clobbered, res.register);
      END;
      FOR reg := 0 TO MAX(SET) DO
        IF reg IN clobbered THEN
          IF (reg < S.st0) THEN
            type := S.gpRegisterType;
          ELSE
            type := S.fpRegisterType;
          END;
          res := call.AddResultReg(type, reg);
        END;
      END;
    END ExpandCall;
  
  BEGIN
    maxSizeCallStack := 0;
    IF (b.procDecl.formalPars.resultType # NIL) THEN
      type := S.MapType(b.procDecl.formalPars.resultType);
      IF S.IsFloat(type) THEN
        (* leave enough room on stack to bounce the result of the function
           procedure via the stack into the st0 register  *)
        maxSizeCallStack := S.TypeSize(type);
      END;
    END;
    FOR instr IN b.AllInstructions(S.call) DO
      ExpandCall(instr);
    END;
    b.SetMaxSizeCallStack(maxSizeCallStack);
    
    FOR instr IN b.AllInstructions(-1) DO
      CASE instr.opcode OF
      | S.gate:
        opnd := instr.opndList;
        WHILE (opnd # NIL) DO
          opnd.immediate := IsConst(opnd);
          opnd := opnd.nextOpnd;
        END;
      | S.setStack:  (* offset is part of address; value may be immediate *)
        instr.opndList.nextOpnd.immediate := TRUE;
        imm := ImmediateOpnd(instr);
        IF (imm # NIL) THEN
          imm.immediate := TRUE;
        END;
      | S.guard: (* for guards in a case statement, all opnds are immediate *)
        opnd := instr.opndList;
        WHILE (opnd # NIL) DO
          opnd.immediate := IsConst(opnd);
          opnd := opnd.nextOpnd;
        END;
      | S.asr, S.asl, S.lsr, S.lsl, S.rl, S.rr:
        opnd := instr.opndList.nextOpnd;
        IF opnd.IsConst() THEN
          opnd.immediate := TRUE;
        ELSE                             (* force into register %cl *)
          opnd.ReplaceArg(b.AddLoadRegister(opnd.arg, S.gp1));
        END;
      ELSE
        imm := ImmediateOpnd(instr);
        IF (imm # NIL) THEN
          imm.immediate := TRUE;
        END;
        mem := MemOpnd(instr);
        IF (mem # NIL) THEN
          mem.immediate := TRUE;
        END;
      END;
    END;
  END ApplyMachineModel;

END OOC:X86:Machine.
