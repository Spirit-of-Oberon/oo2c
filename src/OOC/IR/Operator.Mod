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
    IR.InitOperator (neg, sym, opnd, NIL);
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

PROCEDURE (b: Builder) NewOperator* (sym: IR.Symbol; left, right: IR.Expression): IR.Expression;
  BEGIN
    CASE sym. id OF
    | Symbol.minus:
      ASSERT (left = NIL);
      RETURN NewNegate (sym, right)
    END
  END NewOperator;

(* -------- *)

END OOC:IR:Operator.
