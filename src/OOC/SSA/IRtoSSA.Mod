MODULE OOC:SSA:IRtoSSA;

IMPORT
  Log, Language:Integer, OOC:IR, OOC:IR:Operator,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result;


PROCEDURE StatmSeq* (pb: SSA.ProcBlock; s: SSA.Result;
                     statmSeq: IR.StatementSeq): SSA.Result;
(**Translates the statement sequence @oparam{statmSeq} into a straightforward
   SSA representation.  Instructions are added to the procedure block
   @oparam{pb}.  The initial value of @var{store} is taken from the argument
   @oparam{s}, the final value of @var{store} is the return value of the
   function.  *)
  VAR
    statm: IR.Statement;
    i: LONGINT;

  PROCEDURE Chain (instr: SSA.Instr);
    BEGIN
      instr. AddOpnd (s, Opnd.store);
      s := instr. AddResult (Result.store)
    END Chain;

  PROCEDURE Expression (expr: IR.Expression): SSA.Result;
    VAR
      instr: SSA.Instr;
    BEGIN
      WITH expr: IR.Const DO
        RETURN pb. GetConst (expr. value)
      | expr: IR.ProcedureRef DO
        RETURN pb. GetAddress (expr. decl)

      | expr: IR.Var DO
        instr := pb. AddInstr (Opcode.get, Opcode.scNone);
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (pb. GetDeclRef (expr. decl), Opnd.arg);
        RETURN instr
            
      | expr: Operator.Negate DO
        (* ok, I'm being very lazy here; don't want to introduce expression
           for something as trifling as `-123' right now, so I'm doing some
           trivial constant folding here... *)
        RETURN pb. GetConst(Integer.New (-SHORT(expr.opnd1(IR.Const).value(Integer.Value).value)))
      ELSE
        Log.Type("++ Unknown type in Expression", expr);
        ASSERT (FALSE)
      END;
    END Expression;

  PROCEDURE Assert (assert: IR.Assert): SSA.Instr;
    VAR
      instr: SSA.Instr;
    BEGIN
      instr := pb. AddInstr (Opcode.assert, Opcode.scNone);
      instr. AddOpnd (Expression (assert. predicate), Opnd.arg);
      instr. AddOpnd (pb. GetConstInt (assert. code), Opnd.arg);
      RETURN instr
    END Assert;
  
  PROCEDURE Call (call: IR.Call): SSA.Instr;
    VAR
      instr: SSA.Instr;
      i: LONGINT;
    BEGIN
      instr := pb. AddInstr (Opcode.call, Opcode.scNone);
      instr. AddOpnd (Expression (call. design), Opnd.procAdr);
      FOR i := 0 TO LEN (call. arguments^)-1 DO
        instr. AddOpnd (Expression (call. arguments[i]), Opnd.arg);
      END;
      RETURN instr
    END Call;
  
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statm := statmSeq[i];
      WITH statm: IR.Assert DO
        Chain (Assert (statm));
      | statm: IR.Call DO
        Chain (Call (statm));
      END;
    END;
    RETURN s
  END StatmSeq;


BEGIN
  
END OOC:SSA:IRtoSSA.
