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
    | S.add, S.sub, S.mul, S.div, S.neg:
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
  BEGIN
    CASE instr.opcode OF
    | S.return, S.call, S.guard:
      n := 0;
    | S.eql, S.neq, S.lss, S.leq, S.gtr, S.geq,
      (* x86's cmp instruction is not symmetric with immediate opnd *)
      S.add, S.sub, S.allocateStack:
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
    IF (opnd.arg.instr.opcode = S.const) THEN
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
    
  PROCEDURE IsOffset(instr: S.Instr): BOOLEAN;
    BEGIN
      RETURN (instr.opcode = S.add);
    END IsOffset;

  BEGIN
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
   modes by setting ``immediate'' flags for operands.  *)
  VAR
    instr: S.Instr;
    opnd, imm, mem: S.Opnd;
    maxSizeCallStack: LONGINT;
    
  PROCEDURE IsConst(opnd: S.Opnd): BOOLEAN;
    BEGIN
      RETURN (opnd.arg.instr.opcode = S.const);
    END IsConst;

  PROCEDURE ExpandCall(call: S.Instr);
    VAR
      instr, memoryDep: S.Instr;
      opnd, next: S.Opnd;
      offset: LONGINT;
      sp, res: S.Result;
      reg: S.Register;

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

        instr := b.AddInstr3(S.setStack, sp, b.AddConstLength(offset),
                             opnd.arg);
        instr.AddDep(S.depMemory, memoryDep);
        call.AddDep(S.depMemory, instr);
        INC(offset, ArgSize(opnd.arg));
        
        opnd.DeleteOpnd();
        opnd := next;
      END;
      
      IF (offset > maxSizeCallStack) THEN
        maxSizeCallStack := offset;
      END;

      (* mark the registers that are potentially clobbered by the call *)
      IF (call.resultList = NIL) THEN
        res := call.AddResult(S.gpRegisterType);
      END;
      call.resultList.adrMode := S.register;
      call.resultList.register := S.gp0;
      FOR reg := S.gp1 TO S.gp2 DO
        res := call.AddResultReg(S.gpRegisterType, reg);
      END;
    END ExpandCall;
  
  BEGIN
    maxSizeCallStack := 0;
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
