MODULE OOC:IR:Operator [OOC_EXTENSIONS];

IMPORT
  Log,
  OOC:Error, OOC:Config:Pragmas, OOC:Scanner:Symbol, Sym := OOC:SymbolTable,
  OOC:IR;


TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    (IR.BuilderDesc)
  END;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
    (IR.VisitorDesc)
  END;

TYPE
  ArithOp2* = POINTER TO ArithOp2Desc;
  ArithOp2Desc* = RECORD 
    (IR.OperatorDesc)
  END;

TYPE
  Index* = POINTER TO IndexDesc;
  IndexDesc = RECORD
    (IR.OperatorDesc)
    (**The index operator selects the element at position @ofield{opnd2} from
       the array variable @ofield{opnd1}.  *)
  END;
  
TYPE
  Negate* = POINTER TO NegateDesc;
  NegateDesc = RECORD
    (IR.OperatorDesc)
  END;

TYPE
  Add* = POINTER TO AddDesc;
  AddDesc = RECORD
    (IR.OperatorDesc) 
  END;
  
TYPE
  Eql* = POINTER TO EqlDesc;
  EqlDesc = RECORD
    (IR.OperatorDesc) 
  END;
  
TYPE
  Neq* = POINTER TO NeqDesc;
  NeqDesc = RECORD
    (IR.OperatorDesc) 
  END;

PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
    IR.InitVisitor (v);
  END InitVisitor;

PROCEDURE InitBuilder* (b: Builder; pragmaHistory: Pragmas.History; errList: Error.List);
  BEGIN
    IR.InitBuilder (b, pragmaHistory, errList);
  END InitBuilder;

PROCEDURE NewBuilder* (pragmaHistory: Pragmas.History; errList: Error.List): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b, pragmaHistory, errList);
    RETURN b
  END NewBuilder;

(* -------- *)

PROCEDURE InitArithOp2 (op: ArithOp2; sym: IR.Symbol; left, right: IR.Expression);
  BEGIN
    IR.InitOperator (op, sym, left. type, left, right);
  END InitArithOp2;

PROCEDURE (b: Builder) NewArithOp2 (sym: IR.Symbol; left, right: IR.Expression): ArithOp2;
  VAR
    op: ArithOp2;
  BEGIN
    NEW (op);
    InitArithOp2 (op, sym, left, right);
    RETURN op
  END NewArithOp2;

PROCEDURE (v: Visitor) [ABSTRACT] VisitArithOp2* (op: ArithOp2);
  END VisitArithOp2;

PROCEDURE (op: ArithOp2) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitArithOp2 (op)
  END Accept;

(* -------- *)

PROCEDURE InitIndex (i: Index; sym: IR.Symbol; array, index: IR.Expression);
  BEGIN
    IR.InitOperator (i, sym, array. type(Sym.Array). elementType,
                     array, index);
  END InitIndex;

PROCEDURE (b: Builder) NewIndex* (sym: IR.Symbol; array, index: IR.Expression): Index;
  VAR
    i: Index;
  BEGIN
    NEW (i);
    InitIndex (i, sym, array, index);
    RETURN i
  END NewIndex;

PROCEDURE (v: Visitor) [ABSTRACT] VisitIndex* (index: Index);
  END VisitIndex;

PROCEDURE (index: Index) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitIndex (index)
  END Accept;

(* -------- *)

PROCEDURE InitNegate (neg: Negate; sym: IR.Symbol; opnd: IR.Expression);
  BEGIN
    IR.InitOperator (neg, sym, opnd. type, opnd, NIL);
  END InitNegate;

PROCEDURE (b: Builder) NewNegate (sym: IR.Symbol; opnd: IR.Expression): Negate;
  VAR
    neg: Negate;
  BEGIN
    NEW (neg);
    InitNegate (neg, sym, opnd);
    RETURN neg
  END NewNegate;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNegate* (neg: Negate);
  END VisitNegate;

PROCEDURE (neg: Negate) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitNegate (neg)
  END Accept;

(* -------- *)

PROCEDURE InitAdd (add: Add; sym: IR.Symbol; left, right: IR.Expression);
  BEGIN
    IR.InitOperator (add, sym, left. type, left, right);
  END InitAdd;

PROCEDURE (b: Builder) NewAdd (sym: IR.Symbol; left, right: IR.Expression): Add;
  VAR
    add: Add;
  BEGIN
    NEW (add);
    InitAdd (add, sym, left, right);
    RETURN add
  END NewAdd;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAdd* (add: Add);
  END VisitAdd;

PROCEDURE (add: Add) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitAdd (add)
  END Accept;

(* -------- *)

PROCEDURE InitEql (eql: Eql; sym: IR.Symbol; left, right: IR.Expression);
  BEGIN
    IR.InitOperator (eql, sym, left. type, left, right);
  END InitEql;

PROCEDURE (b: Builder) NewEql (sym: IR.Symbol; left, right: IR.Expression): Eql;
  VAR
    eql: Eql;
  BEGIN
    NEW (eql);
    InitEql (eql, sym, left, right);
    RETURN eql
  END NewEql;

PROCEDURE (v: Visitor) [ABSTRACT] VisitEql* (eql: Eql);
  END VisitEql;

PROCEDURE (eql: Eql) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitEql (eql)
  END Accept;

(* -------- *)

PROCEDURE InitNeq (neq: Neq; sym: IR.Symbol; left, right: IR.Expression);
  BEGIN
    IR.InitOperator (neq, sym, left. type, left, right);
  END InitNeq;

PROCEDURE (b: Builder) NewNeq (sym: IR.Symbol; left, right: IR.Expression): Neq;
  VAR
    neq: Neq;
  BEGIN
    NEW (neq);
    InitNeq (neq, sym, left, right);
    RETURN neq
  END NewNeq;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNeq* (neq: Neq);
  END VisitNeq;

PROCEDURE (neq: Neq) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitNeq (neq)
  END Accept;

(* -------- *)

PROCEDURE (b: Builder) NewOperator* (sym: IR.Symbol; left, right: IR.Expression): IR.Expression;
  BEGIN
    CASE sym. id OF
    | Symbol.minus:
      ASSERT (left = NIL);
      RETURN b. NewNegate (sym, right)

    | Symbol.plus:
      ASSERT (left. type = right. type);
      RETURN b. NewAdd (sym, left, right)

    | Symbol.eql:
      ASSERT (left. type = right. type);
      RETURN b. NewEql (sym, left, right);
      
    | Symbol.neq:
      ASSERT (left. type = right. type);
      RETURN b. NewNeq (sym, left, right);
      
    END
  END NewOperator;

(* -------- *)

END OOC:IR:Operator.
