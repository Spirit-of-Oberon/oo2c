MODULE OOC:IR:ConstFold;

IMPORT 
  Sym := OOC:SymbolTable, OOC:IR, OOC:IR:Operator, OOC:SymbolTable:Predef,
  Language, Language:Integer, Language:Boolean, Language:String8, Integers;

TYPE
  ConstFold = POINTER TO ConstFoldDesc;
  ConstFoldDesc = RECORD
    (Operator.ConstFoldDesc)
  END;

CONST
  maxIntegerTypes = 5;

TYPE
  IntegerType = RECORD
    low, high : Integers.Integer;
    id : Sym.PredefId;
  END;

VAR
  minus1, zero : Integers.Integer;
  nIntegerTypes : INTEGER;
  integerType : ARRAY maxIntegerTypes OF IntegerType;

PROCEDURE AddIntegerType(id : Sym.PredefId; low, high : ARRAY OF CHAR);
BEGIN
  Integers.ConvertFromString(low, integerType[nIntegerTypes].low);
  Integers.ConvertFromString(high, integerType[nIntegerTypes].high);
  integerType[nIntegerTypes].id := id;
  INC(nIntegerTypes);
END AddIntegerType;

PROCEDURE InitConstFold (c : ConstFold);
BEGIN
  Operator.InitConstFold (c, NIL);
END InitConstFold;

PROCEDURE NewConstFold* (): ConstFold;
VAR
  c : ConstFold;
BEGIN
  NEW (c);
  InitConstFold (c);
  RETURN c
END NewConstFold;

PROCEDURE SmallestType(value : Language.Value) : Sym.Type;
(**Return the smallest type that can represent @oparam{value}. *)
VAR i : INTEGER;
BEGIN
  WITH value : Integer.Value DO
    FOR i := 0 TO nIntegerTypes-1 DO
      IF (Integers.Compare(value.value, integerType[i].low) >= 0)
       & (Integers.Compare(value.value, integerType[i].high) <= 0) THEN
        RETURN Predef.GetType(integerType[i].id)
      END;
    END;
     RETURN NIL; 
  END;
END SmallestType;

PROCEDURE (c : ConstFold) ValueConst(value : Language.Value; op : IR.Operator) : IR.Const;
VAR type : Sym.Type;
BEGIN
  type := SmallestType(value);
  IF type = NIL THEN
    c.builder.ErrSym(IR.rangeError, op.sym);
    RETURN NIL
  ELSE
    RETURN c.builder.NewConst(op.sym, type, value)
  END
END ValueConst;

PROCEDURE (c : ConstFold) Accept* (expr : IR.Expression);
BEGIN
  c.result := NIL;
  expr.Accept(c);
END Accept;

PROCEDURE (c : ConstFold) ValidEval (expr : IR.Expression; VAR result : Language.Value) : BOOLEAN;
BEGIN
  c.result := NIL;
  expr.Accept(c);
  IF c.result # NIL THEN
    result := c.result(IR.Const).value;
    RETURN TRUE;
  END;
  RETURN FALSE;
END ValidEval;

PROCEDURE (c: ConstFold) VisitConst* (const: IR.Const);
  BEGIN
    c.result := const;
  END VisitConst;

PROCEDURE (c: ConstFold) VisitVar* (car: IR.Var);
  BEGIN
  END VisitVar;

PROCEDURE (c: ConstFold) VisitPredefProc* (pproc: IR.PredefProc);
  BEGIN
    (* FIXME! *)
  END VisitPredefProc;

PROCEDURE (c: ConstFold) VisitProcedureRef* (procRef: IR.ProcedureRef);
  BEGIN
  END VisitProcedureRef;

PROCEDURE (c: ConstFold) VisitTypeRef* (typeRef: IR.TypeRef);
  BEGIN
  END VisitTypeRef;

PROCEDURE (c: ConstFold) VisitModuleRef* (modRef: IR.ModuleRef);
  BEGIN
  END VisitModuleRef;

PROCEDURE (c: ConstFold) VisitAdr* (adr: Operator.Adr);
  BEGIN
  END VisitAdr;

PROCEDURE (c: ConstFold) VisitLen* (len: Operator.Len);
  VAR length : LONGINT;
  BEGIN
    (* FIXME! Implement lenFixedArray, but how do we get its length? . *)
    CASE len. variant OF
    | Operator.lenStringConst:
      length := len.array(IR.Const).value(String8.Value).value.length+1;
    | Operator.lenFixedArray:
      length := len.array.type(Sym.Array).length;
    | Operator.lenOpenArrayParam, Operator.lenOpenArrayHeap:
      c.result := NIL; RETURN;
    END;
    c.result := c.builder.NewConst(len.sym, Predef.GetType(Predef.lengthType), 
      Integer.NewLInt(length));
  END VisitLen;

PROCEDURE (c: ConstFold) VisitIndex* (index: Operator.Index);
  BEGIN
    (* FIXME! *)
    (* index. array. Accept (c);
    index. index. Accept (c); *)
  END VisitIndex;

PROCEDURE (c: ConstFold) VisitSelectField* (sf: Operator.SelectField);
  BEGIN
  END VisitSelectField;

PROCEDURE (c: ConstFold) VisitNegate* (op: Operator.Negate);
VAR 
  id : Sym.PredefId;
  value : Language.Value;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    id := op.operand.type(Sym.PredefType).id;
    CASE id OF
    | Predef.boolean:
      c.result := c.builder.NewConst(op.sym, Predef.GetType(Predef.boolean), 
        Boolean.type.Value(~value(Boolean.Value).value));
    | Predef.integer:
      value := Integer.type.Value(Integers.Product(minus1, value(Integer.Value).value));

      c.result := c.ValueConst(value, op);
    ELSE
      c.builder.ErrSym(IR.incompatibleTypes, op.sym);
      c.result := NIL;
    END;
  ELSE
    c.result := NIL;
  END;
END VisitNegate;

PROCEDURE (c: ConstFold) VisitCap* (op: Operator.Cap);
VAR 
  value : Language.Value;
  str: ARRAY 2 OF CHAR;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    str[0] := CAP (value(String8.Value).value.array[0]);
    str[1] := 0X;
    c.result := c.builder.NewConst(op.sym, Predef.GetType(Predef.char), 
                                   String8.NewString (str));
  ELSE
    c.result := NIL;
  END;
END VisitCap;

PROCEDURE (c: ConstFold) VisitBinaryArith* (op: Operator.BinaryArith);
VAR 
  l, r, result : Language.Value;

  PROCEDURE IntegerOp () : Language.Value;
  VAR
    result, left, right : Integers.Integer;
  BEGIN
    left := l(Integer.Value).value; 
    right := r(Integer.Value).value;
    
    CASE op.variant OF
      (* FIXME! Properly check for overflow. *)
    | Operator.arithAdd:  result := Integers.Sum(left, right);
    | Operator.arithSub:  result := Integers.Difference(left, right);
    | Operator.arithMul:  result := Integers.Product(left, right);
    | Operator.arithDivI: 
      IF Integers.Compare(right, zero) = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym); RETURN NIL;
      ELSE
        result := Integers.Quotient(left, right);
      END;
    | Operator.arithMod:
      IF Integers.Compare(right, zero) = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym); RETURN NIL;
      ELSE
        result := Integers.Remainder(left, right);
      END;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Integer.type.Value(result);
  END IntegerOp;

BEGIN
  (* Evaluate left and right operands. Propagate any errors. *)
  IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
    (* for now, only support integers *)
    result := IntegerOp();

    IF result # NIL THEN
      c.result := c.ValueConst(result, op);
      RETURN;
    END
  END;
  c.result := NIL;
END VisitBinaryArith;

PROCEDURE (c: ConstFold) VisitCompare* (op : Operator.Compare);
  BEGIN
    (* FIXME! *)
  END VisitCompare;

PROCEDURE (c: ConstFold) VisitTypeConv* (op : Operator.TypeConv);
  VAR
    value : Language.Value;
  BEGIN
    IF c.ValidEval(op.expr, value) THEN
      c.result := c.builder.NewConst(op.sym, op.type, value)
    ELSE
      c.result := NIL;
    END;
  END VisitTypeConv;

PROCEDURE (c: ConstFold) VisitCall* (call: IR.Call);
  BEGIN
  END VisitCall;

PROCEDURE (c: ConstFold) VisitAssert* (assert: IR.Assert);
  BEGIN
  END VisitAssert;

PROCEDURE (c: ConstFold) VisitReturn* (return: IR.Return);
  BEGIN
  END VisitReturn;

PROCEDURE (c: ConstFold) VisitAssignment* (assignment: IR.Assignment);
  BEGIN
  END VisitAssignment;

PROCEDURE (c: ConstFold) VisitAssignOp* (assignOp: Operator.AssignOp);
  BEGIN
  END VisitAssignOp;

PROCEDURE VisitStatementSeq (c: ConstFold; statmSeq: IR.StatementSeq);
  BEGIN
  END VisitStatementSeq;

PROCEDURE (c: ConstFold) VisitIfStatm* (ifStatm: IR.IfStatm);
  BEGIN
  END VisitIfStatm;

PROCEDURE (c: ConstFold) VisitRepeatStatm* (repeatStatm: IR.RepeatStatm);
  BEGIN
  END VisitRepeatStatm;

PROCEDURE (c: ConstFold) VisitWhileStatm* (whileStatm: IR.WhileStatm);
  BEGIN
  END VisitWhileStatm;

PROCEDURE (c: ConstFold) VisitCopyParameter* (cp: IR.CopyParameter);
  BEGIN
  END VisitCopyParameter;


PROCEDURE VisitProcedureList (c: ConstFold; procList: IR.ProcedureList);
  BEGIN
  END VisitProcedureList;

PROCEDURE (c: ConstFold) VisitProcedure* (procedure: IR.Procedure);
  BEGIN
  END VisitProcedure;

PROCEDURE (c: ConstFold) VisitModule* (module: IR.Module);
  BEGIN
  END VisitModule;

BEGIN
  nIntegerTypes := 0;
  AddIntegerType(Predef.shortint, "-128", "127");
  AddIntegerType(Predef.integer, "-32768", "32767");
  AddIntegerType(Predef.longint, "-2147483648", "2147483647");

  zero := Integers.Long(0);
  minus1 := Integers.Long(-1);
END OOC:IR:ConstFold.
