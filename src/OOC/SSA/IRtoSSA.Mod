MODULE OOC:SSA:IRtoSSA;

IMPORT
  Log,  OOC:SymbolTable:Item, OOC:SymbolTable:Predef, OOC:IR, OOC:IR:Operator,
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
        instr. opndList. ReplaceArg (s);
      ELSE
        instr. AddOpnd (s, Opnd.store);
      END;
      s := instr. AddResult (Result.store)
    END Chain;

  PROCEDURE ^ Call (call: IR.Call): SSA.Instr;
    
  PROCEDURE Expression (expr: IR.Expression): SSA.Result;
    VAR
      instr: SSA.Instr;

    PROCEDURE Index (indexOp: Operator.Index): SSA.Result;
      VAR
        instr, elementAdr: SSA.Instr;
        baseResult, index: SSA.Result;
        adrOpnd: SSA.Opnd;
      BEGIN
        (* doesn't calculate size yet... FIXME *)
        ASSERT (indexOp. type(Item.PredefType). id = Predef.char);

        (* take the "get" instruction of the array's designator and
           change it into a "get" for the array element *)
        baseResult := Expression (indexOp. opnd1);
        ASSERT (baseResult. instr. opcode = Opcode.get);
        instr := baseResult. instr;
        index := Expression (indexOp. opnd2);

        adrOpnd := instr. opndList. nextOpnd;
        elementAdr := pb. AddInstr (Opcode.add, Opcode.scAddress);
        elementAdr. AddOpnd (adrOpnd. arg, Opnd.arg);
        elementAdr. AddOpnd (index, Opnd. arg);
        adrOpnd. ReplaceArg (elementAdr);
        instr. AddOpnd (index, Opnd.readDesign);
        instr. SetSubclass (Opcode.TypeToSubclass (indexOp. type));

        RETURN instr
      END Index;
    
    PROCEDURE AddCompareOp (op: IR.Operator; class: Opcode.Class): SSA.Instr;
      VAR
        instr: SSA.Instr;
      BEGIN
        instr := pb. AddInstr (class, Opcode.scBoolean);
        instr. AddOpnd (Expression (op. opnd1), Opnd.arg);
        instr. AddOpnd (Expression (op. opnd2), Opnd.arg);
        RETURN instr
      END AddCompareOp;
    
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

      | expr: Operator.Index DO
        RETURN Index (expr)
        
      | expr: Operator.Negate DO
        instr := pb. AddInstr (Opcode.negate,
                               Opcode.TypeToSubclass (expr. opnd1. type));
        instr. AddOpnd (Expression (expr. opnd1), Opnd.arg);
        RETURN instr
            
      | expr: Operator.Add DO
        instr := pb. AddInstr (Opcode.add,
                               Opcode.TypeToSubclass (expr. opnd1. type));
        instr. AddOpnd (Expression (expr. opnd1), Opnd.arg);
        instr. AddOpnd (Expression (expr. opnd2), Opnd.arg);
        RETURN instr

      | expr: Operator.Eql DO
        RETURN AddCompareOp (expr, Opcode.eql);
      | expr: Operator.Neq DO
        RETURN AddCompareOp (expr, Opcode.neq);
            
      | expr: IR.Call DO
        instr := Call (expr);
        (* the pessimistic assumption is that a function call can have
           arbitrary side effects; it's up to later transformations to reduce
           the impact of this  *)
        instr. AddOpnd (s, Opnd.store);
        s := instr. AddResult (Result.store);
        RETURN instr
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
      storeAfterGuard: SSA.Result;
    BEGIN
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (Expression (ifStatm. guard), Opnd.arg);
      storeAfterGuard := s;
      
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (StatmSeq (pb, storeAfterGuard, ifStatm. pathTrue),
                       Opnd.arg);
      
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      IF (ifStatm. pathFalse # NIL) THEN
        select. AddOpnd (StatmSeq (pb, storeAfterGuard, ifStatm. pathFalse),
                         Opnd.arg);
      ELSE
        select. AddOpnd (storeAfterGuard, Opnd.arg)
      END;

      s := select. AddResult (Result.store)
    END IfStatm;

  PROCEDURE RepeatStatm (repeatStatm: IR.RepeatStatm);
    VAR
      start, end: SSA.Instr;
      exit: SSA.Result;
    BEGIN
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);
      
      (* evaluate loop body, followed by the exit condition *)
      s := StatmSeq (pb, s, repeatStatm. body);
      exit := Expression (repeatStatm. exitCondition);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (s, Opnd.store);
      end. AddOpnd (exit, Opnd.arg);
      end. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);

      (* add forward reference from "loop-start" to `store' at end of loop *)
      start. AddOpnd (s, Opnd.forwardRef);
      
      s := end. AddResult (Result.store)
    END RepeatStatm;
  
  PROCEDURE WhileStatm (whileStatm: IR.WhileStatm);
    VAR
      start, end, select: SSA.Instr;
      guard1, guard2, storeAfterGuard1: SSA.Result;
    BEGIN
      (* WHILE e DO s END

         is translated to

         IF e THEN
           REPEAT
             s
           UNTIL ~e;
         END  *)
      guard1 := Expression (whileStatm. guard);
      storeAfterGuard1 := s;

      (* insert "loop-start" instruction *)
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);
      
      (* evaluate loop body, followed by the exit condition *)
      s := StatmSeq (pb, s, whileStatm. body);
      guard2 := Expression (whileStatm. guard);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (s, Opnd.store);
      end. AddOpnd (guard2, Opnd.arg);
      end. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      
      (* add forward reference from "loop-start" to `store' at end of loop *)
      start. AddOpnd (s, Opnd.forwardRef);

      (* create the "select" for the IF statement around the loop *)
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard1, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (end. AddResult (Result.store), Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (storeAfterGuard1, Opnd.arg);

      s := select. AddResult (Result.store)
    END WhileStatm;
  
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

      | statm: IR.RepeatStatm DO
        RepeatStatm (statm)
            
      | statm: IR.WhileStatm DO
        WhileStatm (statm)
            
      ELSE
        Log.Type("++ Unknown statement class in StatmSeq", statm);
        ASSERT (FALSE)
      END;
    END;
    RETURN s
  END StatmSeq;


BEGIN
  
END OOC:SSA:IRtoSSA.
