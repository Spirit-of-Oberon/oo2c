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
      IF (instr. opcode = Opcode.set) THEN
        instr. opndList. ReplaceOpnd (s);
      ELSE
        instr. AddOpnd (s, Opnd.store);
      END;
      s := instr. AddResult (Result.store)
    END Chain;

  PROCEDURE ^ Call (call: IR.Call): SSA.Instr;
    
  PROCEDURE Expression (expr: IR.Expression): SSA.Result;
    VAR
      instr: SSA.Instr;
    BEGIN
      WITH expr: IR.Const DO
        RETURN pb. GetConst (expr. value, expr. type)
            
      | expr: IR.ProcedureRef DO
        RETURN pb. GetAddress (expr. decl)

      | expr: IR.Var DO
        instr := pb. AddInstr (Opcode.get, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (pb. GetAddress (expr. decl), Opnd.readAdr);
        instr. AddOpnd (pb. GetDeclRef (expr. decl), Opnd.readDesign);
        RETURN instr
            
      | expr: Operator.Negate DO
        (* ok, I'm being very lazy here; don't want to introduce expression
           for something as trifling as `-123' right now, so I'm doing some
           trivial constant folding here... *)
        RETURN pb. GetConst(Integer.New (-SHORT(expr.opnd1(IR.Const).value(Integer.Value).value)), expr.opnd1(IR.Const).type)

      | expr: IR.Call DO
        RETURN Call (expr)
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
  
  PROCEDURE Assignment (assignment: IR.Assignment): SSA.Instr;
    VAR
      get: SSA.Result;
    BEGIN
      (* ... shortcut: ignore non-scalar assignments *)
      get := Expression (assignment. variable);
      RETURN pb. AddSetInstr (get(SSA.Instr), Expression (assignment. value));
    END Assignment;
  
  PROCEDURE Call (call: IR.Call): SSA.Instr;
    VAR
      instr: SSA.Instr;
      i: LONGINT;
    BEGIN
      instr := pb. AddInstr (Opcode.call, Opcode.TypeToSubclass (call. type));
      instr. AddOpnd (Expression (call. design), Opnd.procAdr);
      FOR i := 0 TO LEN (call. arguments^)-1 DO
        instr. AddOpnd (Expression (call. arguments[i]), Opnd.arg);
      END;
      RETURN instr
    END Call;

  PROCEDURE Return (return: IR.Return);
    VAR
      instr: SSA.Instr;
      store: SSA.Result;
    BEGIN
      instr := pb. AddInstr (Opcode.return, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      IF (return. result # NIL) THEN
        instr. AddOpnd (Expression (return. result), Opnd.functionResult);
      END;
      
      store := instr. AddResult (Result.store);
      pb. selectReturn. AddOpnd (store, Opnd.store);
      s := store
    END Return;

  PROCEDURE IfStatm (ifStatm: IR.IfStatm);
    VAR
      select: SSA.Instr;
    BEGIN
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (Expression (ifStatm. guard), Opnd.arg);
      
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (StatmSeq (pb, s, ifStatm. pathTrue), Opnd.arg);
      
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      IF (ifStatm. pathFalse # NIL) THEN
        select. AddOpnd (StatmSeq (pb, s, ifStatm. pathFalse), Opnd.arg);
      ELSE
        select. AddOpnd (s, Opnd.arg)
      END;

      s := select. AddResult (Result.store)
    END IfStatm;
  
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statm := statmSeq[i];
      WITH statm: IR.Assert DO
        Chain (Assert (statm));

      | statm: IR.Assignment DO
        Chain (Assignment (statm))
            
      | statm: IR.Call DO
        Chain (Call (statm));
        
      | statm: IR.Return DO
        (* lets pretend for a moment that a RETURN is not a control flow
           construct... FIXME *)
        Return (statm)

      | statm: IR.IfStatm DO
        IfStatm (statm)
      ELSE
        Log.Type("++ Unknown statement class in StatmSeq", statm);
        ASSERT (FALSE)
      END;
    END;
    RETURN s
  END StatmSeq;


BEGIN
  
END OOC:SSA:IRtoSSA.
