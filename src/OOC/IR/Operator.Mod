MODULE OOC:IR:Operator [OOC_EXTENSIONS];

IMPORT
  OOC:Error, OOC:Config:Pragmas, OOC:Scanner:Symbol, OOC:IR;


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
  Negate* = POINTER TO NegateDesc;
  NegateDesc = RECORD
    (IR.OperatorDesc)
  END;

TYPE
  Add* = POINTER TO AddDesc;
  AddDesc = RECORD
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

PROCEDURE InitNegate (neg: Negate; sym: IR.Symbol; opnd: IR.Expression);
  BEGIN
    IR.InitOperator (neg, sym, opnd. type, opnd, NIL);
  END InitNegate;

PROCEDURE NewNegate (sym: IR.Symbol; opnd: IR.Expression): Negate;
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

PROCEDURE NewAdd (sym: IR.Symbol; left, right: IR.Expression): Add;
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

PROCEDURE (b: Builder) NewOperator* (sym: IR.Symbol; left, right: IR.Expression): IR.Expression;
  BEGIN
    CASE sym. id OF
    | Symbol.minus:
      ASSERT (left = NIL);
      RETURN NewNegate (sym, right)

    | Symbol.plus:
      ASSERT (left. type = right. type);
      RETURN NewAdd (sym, left, right)
    END
  END NewOperator;

(* -------- *)

END OOC:IR:Operator.
