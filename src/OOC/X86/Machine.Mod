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

PROCEDURE ImmediateOpnd*(opnd: S.Opnd): BOOLEAN;
(**If the operand's value can be encoded as an immediate operand of its
   instruction, the return @code{TRUE}.  This function takes the instruction of
   which @oparam{opnd} is part of and the instruction that computes the
   argument of @oparam{opnd} into account.  Interdependencies with other
   operands of the instruction are ignored, as are addressing modes
   more complex than immediate operands.

   @precond
   @oparam{opnd} is a value operand.  That is @oproc{InOutOpnd} returns
   @code{FALSE}.
   @end precond  *)
  VAR
    n: LONGINT;
    argOpcode, instrOpcode: S.Opcode;
  BEGIN
    argOpcode := opnd.arg.instr.opcode;
    instrOpcode := opnd.instr.opcode;
    IF (argOpcode = S.get) THEN (* base + index *)
      RETURN (instrOpcode # S.setStack);
    ELSIF (argOpcode # S.const) THEN
      RETURN FALSE;
    ELSE                              (* constant is passed to opnd *)
      n := opnd.OpndIndex();
      IF (n = 0) THEN                    (* first operand *)
        RETURN (instrOpcode = S.return) OR (instrOpcode = S.call);
      ELSIF (n = 1) THEN                 (* second operand *)
        CASE instrOpcode OF
        | S.eql, S.neq, S.lss, S.leq, S.gtr, S.geq:
          (* x86's cmp instruction is not symmetric with immediate opnd *)
          RETURN TRUE;
        | S.add, S.sub, S.allocateStack:
          (* first opnd is in/out, second may be immediate *)
          RETURN TRUE;
        | S.setStack:
          (* first opnd is value, second indicates stack offset *)
          RETURN TRUE;
        ELSE
          RETURN FALSE;
        END;
      ELSE
        RETURN FALSE;
      END;
    END;
  END ImmediateOpnd;

PROCEDURE ApplyMachineModel*(b: S.FunctionBlock);
(**Expand call instructions and enable the target architecture's addressing
   modes by setting ``immediate'' flags for operands.  *)
  VAR
    instr: S.Instr;
    opnd, inout: S.Opnd;
    memoryCount, maxSizeCallStack: LONGINT;
    
  PROCEDURE IsOffset(instr: S.Instr): BOOLEAN;
    BEGIN
      RETURN (instr.opcode = S.add);
    END IsOffset;

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
      | S.get, S.set:
        IF IsOffset(instr.opndList.arg.instr) THEN
          instr.opndList.immediate := TRUE;
        END;
      | S.gate:
        opnd := instr.opndList;
        WHILE (opnd # NIL) DO
          opnd.immediate := IsConst(opnd);
          opnd := opnd.nextOpnd;
        END;
      ELSE
        inout := InOutOpnd(instr);
        memoryCount := 0;
        opnd := instr.opndList;
        WHILE (opnd # NIL) DO
          IF (opnd # inout) & ImmediateOpnd(opnd) THEN
            opnd.immediate := TRUE;
            IF (opnd.arg.instr.opcode # S.const) THEN
              INC(memoryCount);
            END;
          END;
          opnd := opnd.nextOpnd;
        END;
        
        IF (memoryCount > 1) THEN
          ASSERT(memoryCount = 2);
          ASSERT(instr.opndList.nextOpnd.immediate);
          ASSERT(instr.opndList.nextOpnd.arg.instr.opcode # S.const);
          instr.opndList.nextOpnd.immediate := FALSE;
        END;
      END;
    END;
  END ApplyMachineModel;

END OOC:X86:Machine.
