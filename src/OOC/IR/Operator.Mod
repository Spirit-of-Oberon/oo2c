MODULE OOC:IR:Operator [OOC_EXTENSIONS];

IMPORT
  Log, Language, Language:IntegerType, Language:Boolean, Language:Integer,
  OOC:Error, OOC:Config:Pragmas, OOC:Scanner:Symbol, Sym := OOC:SymbolTable,
  OOC:IR, OOC:SymbolTable:TypeRules, OOC:SymbolTable:Predef;

TYPE
  (* Variants for 'classed' binary operators. *)
  Variant = SHORTINT;
  
CONST
  (* arithmetic *)
  arithAdd* = 0;
  arithSub* = 1;
  arithDivI* = 2;
  arithDivR* = 3;
  arithMul* = 4;
  arithMod* = 5;

  (* set *)
  setUnion* = 6;
  setDiff* = 7;
  setIntersect* = 8;
  setSymDiff* = 9;

  (* compare *)
  equal* = 10;
  notEqual* = 11;
  less* = 12;
  lessEqual* = 13;
  greater* = 14;
  greaterEqual* = 15;

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
  TypeConv* = POINTER TO TypeConvDesc;
  TypeConvDesc = RECORD
  (**A TypeConv expression represents a conversion of expression @ofield{expr}
     from type @ofield{from} to type @ofield{to}. *)
    (IR.OperatorDesc)
    expr- : IR.Expression;
  END;

TYPE
  BinaryArith* = POINTER TO BinaryArithDesc;
  BinaryArithDesc = RECORD 
    (IR.OperatorDesc)
    variant- : Variant;
    left-, right- : IR.Expression;
  END;

TYPE
  Compare* = POINTER TO CompareDesc;
  CompareDesc = RECORD
    (IR.OperatorDesc)
    variant- : Variant;
    left-, right- : IR.Expression;
  END;

TYPE
  Index* = POINTER TO IndexDesc;
  IndexDesc = RECORD
    (IR.OperatorDesc)
    (**The index operator selects the element at position @ofield{index} from
       the array variable @ofield{array}.  *)
    array- : IR.Expression;
    index- : IR.Expression;
  END;
  
TYPE
  Negate* = POINTER TO NegateDesc;
  NegateDesc = RECORD
    (IR.OperatorDesc)
    operand- : IR.Expression;
  END;

PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
    IR.InitVisitor (v);
  END InitVisitor;

PROCEDURE InitBuilder* (b: Builder; pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules);
  BEGIN
    IR.InitBuilder (b, pragmaHistory, errList, typeRules);
  END InitBuilder;

PROCEDURE NewBuilder* (pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b, pragmaHistory, errList, typeRules);
    RETURN b
  END NewBuilder;

(* -------- *)

PROCEDURE (c : TypeConv) Evaluate* (VAR env : IR.Environment) : Language.Value;
  VAR
    value : Language.Value;
  BEGIN
    value := c.expr.Evaluate(env); IF env.Err() THEN RETURN NIL END;
    (* FIXME. Convert value here. *)
    RETURN value;
  END Evaluate;

PROCEDURE InitTypeConv (conv: TypeConv; sym: IR.Symbol; type: Sym.Type;
                     expr: IR.Expression);
  BEGIN
    IR.InitOperator (conv, sym, type);
    conv. expr := expr;
  END InitTypeConv;

PROCEDURE NewTypeConv (type: Sym.Type; expr : IR.Expression): TypeConv;
  VAR
    conv: TypeConv;
  BEGIN
    NEW (conv);
    InitTypeConv (conv, expr.sym, type, expr);
    RETURN conv
  END NewTypeConv;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeConv* (conv: TypeConv);
  END VisitTypeConv;

PROCEDURE (conv: TypeConv) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitTypeConv (conv)
  END Accept;

(* -------- *)

PROCEDURE (op : BinaryArith) Evaluate* (VAR env : IR.Environment) : Language.Value;
VAR 
  l, r : Language.Value;

  PROCEDURE IntegerOp () : Language.Value;
  VAR
    result, left, right : LONGINT;
    type : IntegerType.Type;
  BEGIN
    left := l(IntegerType.Value).value; 
    right := r(IntegerType.Value).value;
    
    CASE op.variant OF
      (* FIXME! Properly check for overflow. *)
    | arithAdd:  result := left + right;
    | arithSub:  result := left - right;
    | arithMul:  result := left * right;
    | arithDivR: 
      IF right = 0 THEN
        env.Exception(IR.statusDivByZero, op, l, r); RETURN NIL;
      ELSE
        result := left DIV right;
      END;
    ELSE
      env.Exception(IR.statusInvalidOp, op, l, r); RETURN NIL;
    END;
    RETURN Integer.type.Value(result);
  END IntegerOp;

BEGIN
  (* Evaluate left and right operands. Propagate any errors. *)
  l := op.left.Evaluate(env); IF env.Err() THEN RETURN NIL END;
  r := op.right.Evaluate(env); IF env.Err() THEN RETURN NIL END;

  (* for now, only support integers *)
  RETURN IntegerOp();
END Evaluate;

PROCEDURE InitBinaryArith (op: BinaryArith; sym: IR.Symbol; variant : Variant; left, right: IR.Expression);
  BEGIN
    IR.InitOperator (op, sym, left. type);
    op.variant := variant;
    op.left := left;
    op.right := right;
  END InitBinaryArith;

PROCEDURE (b: Builder) NewBinaryArith (sym: IR.Symbol; left, right: IR.Expression): BinaryArith;
  VAR
    op: BinaryArith; variant : Variant;
  BEGIN
    (* FIXME! Check types of left and right operands *)
    CASE sym.id OF
    | Symbol.plus:
      variant := arithAdd;
    | Symbol.minus:
      variant := arithSub;
    | Symbol.times:
      variant := arithMul;
    END;
    NEW (op);
    InitBinaryArith (op, sym, arithAdd, left, right);
    RETURN op
  END NewBinaryArith;

PROCEDURE (v: Visitor) [ABSTRACT] VisitBinaryArith* (op: BinaryArith);
  END VisitBinaryArith;

PROCEDURE (op: BinaryArith) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitBinaryArith (op)
  END Accept;

(* -------- *)

PROCEDURE (op : Compare) Evaluate* (VAR env : IR.Environment) : Language.Value;
VAR 
  l, r : Language.Value;

  PROCEDURE IntegerOp () : Language.Value;
  VAR
    left, right : LONGINT; result : BOOLEAN;
  BEGIN
    left := l(IntegerType.Value).value; 
    right := r(IntegerType.Value).value;
    
    CASE op.variant OF
    | equal:        result := (left = right);
    | notEqual:     result := (left # right);
    | less:         result := (left < right);
    | lessEqual:    result := (left <= right);
    | greater:      result := (left > right);
    | greaterEqual: result := (left <= right);
    ELSE
      env.Exception(IR.statusInvalidOp, op, l, r);
    END;
    RETURN Boolean.type.Value(result);
  END IntegerOp;

BEGIN
  (* Evaluate left and right operands. Propagate any errors. *)
  l := op.left.Evaluate(env); IF env.Err() THEN RETURN NIL END;
  r := op.right.Evaluate(env); IF env.Err() THEN RETURN NIL END;

  (* for now, only support integers *)
  RETURN IntegerOp();
END Evaluate;

PROCEDURE InitCompare (op: Compare; sym: IR.Symbol; variant : Variant; left, right: IR.Expression);
  BEGIN
    IR.InitOperator (op, sym, Predef.GetType(Predef.boolean));
    op.left := left;
    op.right := right;
    op.variant := variant;
  END InitCompare;

PROCEDURE (b: Builder) NewCompare (sym: IR.Symbol; left, right: IR.Expression): Compare;
  VAR
    op: Compare; variant : Variant;

  BEGIN
    (* FIXME! Check types of left and right operands *)
    CASE sym.id OF
    | Symbol.eql:  variant := equal;
    | Symbol.neq:  variant := notEqual;
    | Symbol.lss:  variant := less;
    | Symbol.leq:  variant := lessEqual;
    | Symbol.gtr:  variant := greater;
    | Symbol.geq:  variant := greaterEqual;
    END;
    NEW (op);
    InitCompare (op, sym, variant, left, right);
    RETURN op;
  END NewCompare;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCompare* (op: Compare);
  END VisitCompare;

PROCEDURE (op: Compare) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitCompare (op)
  END Accept;

(* -------- *)

PROCEDURE (i : Index) Evaluate* (VAR env : IR.Environment) : Language.Value;
BEGIN
  env.Exception(IR.statusInvalidOp, i, NIL, NIL);
  RETURN NIL;
END Evaluate;

PROCEDURE InitIndex (i: Index; sym: IR.Symbol; array, index: IR.Expression);
  BEGIN
    IR.InitOperator (i, sym, array. type(Sym.Array). elementType);
    i.array := array;
    i.index := index;
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

PROCEDURE (op : Negate) Evaluate* (VAR env : IR.Environment) : Language.Value;
VAR 
  id : Sym.PredefId;
  bool : BOOLEAN;
  int : INTEGER;
  set : SET;
  value : Language.Value;
BEGIN
  value := op.operand.Evaluate(env); IF env.Err() THEN RETURN  NIL END;
  id := op.operand.type(Sym.PredefType).id;
  CASE id OF
  | Predef.boolean:
    RETURN Boolean.type.Value(~value(Boolean.Value).value);
  | Predef.integer:
    RETURN Integer.type.Value(-value(IntegerType.Value).value);
  ELSE
    env.Exception(IR.statusIncompatibleTypes, op, NIL, NIL);
    RETURN NIL;
  END;
END Evaluate;

PROCEDURE InitNegate (neg: Negate; sym: IR.Symbol; expr: IR.Expression);
  BEGIN
    IR.InitOperator (neg, sym, expr. type);
    neg.operand := expr;
  END InitNegate;

PROCEDURE (b: Builder) NewNegate (sym: IR.Symbol; expr: IR.Expression): Negate;
  VAR
    neg: Negate;
  BEGIN
    NEW (neg);
    InitNegate (neg, sym, expr);
    RETURN neg
  END NewNegate;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNegate* (neg: Negate);
  END VisitNegate;

PROCEDURE (neg: Negate) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitNegate (neg)
  END Accept;

(* -------- *)

PROCEDURE (b : Builder) WidenExpr (type : Sym.Type; expr : IR.Expression) : IR.Expression;
VAR
  tr : TypeRules.Rules;
BEGIN
  tr := b.typeRules;
  IF tr.SameType(type, expr.type) OR tr.IsExtensionOf(type, expr.type) THEN
    RETURN expr
  ELSIF tr.IncludesType(type, expr.type) THEN
    RETURN NewTypeConv(type, expr)
  ELSE
    RETURN NIL;
  END;
END WidenExpr;

PROCEDURE (b: Builder) NewOperator* (sym: IR.Symbol; left, right: IR.Expression): IR.Expression;
(**Return an IR expression for the given symbol and left/right expressions.
   This procedure handles operator polymorphism, mapping an operator symbol to
   different operations according to the type of its operands. This procedure
   returns an operator, or the value IR.errorExpr. If the given symbol is not a
   recognised operator, an unknownOp error is signalled. If the types of the
   arguments are not valid for the given operator, an invalidOpType error is
   signalled. *)

  VAR
    tr : TypeRules.Rules;
    isNumeric, isSet, isString : BOOLEAN;

  PROCEDURE SetOrNumeric () : IR.Expression;
  BEGIN
    IF isNumeric THEN
      RETURN b.NewBinaryArith(sym, left, right)
(*    ELSIF isSet THEN
      RETURN b.NewSet(sym, left, right); *)
    ELSE
      RETURN b.ErrExpr(IR.invalidOpType, sym);
    END;
  END SetOrNumeric;

  BEGIN
    tr := b.typeRules;
    isNumeric := tr.IsPredefClass(right.type, Predef.classNumeric);
    isSet := tr.IsPredefClass(right.type, Predef.classSet);

    IF left = NIL THEN 
      (* unary operator *)
      CASE sym.id OF
      | Symbol.minus:
        IF isNumeric THEN
          RETURN b.NewNegate(sym, right);
        ELSIF isSet THEN
          (* for now, map set/numeric negation onto Negate operator *)
          RETURN b.NewNegate(sym, right);
        ELSE
          RETURN b.ErrExpr(IR.invalidOpType, sym);
        END;
      | Symbol.not:
        (* for now, map logical negation onto Negate operator *)
        RETURN b.NewNegate(sym, right);
      ELSE
      END;
    ELSE
      (* binary operator *)
      CASE sym.id OF
      | Symbol.plus, Symbol.minus, Symbol.times, Symbol.slash:
        RETURN SetOrNumeric();
      | Symbol.div, Symbol.mod:
        RETURN b.NewBinaryArith(sym, left, right);
      | Symbol.eql, Symbol.neq, Symbol.lss, Symbol.leq, Symbol.gtr, Symbol.geq:
        RETURN b.NewCompare(sym, left, right);
(*      | Symbol.and, Symbol.or:
        RETURN b.NewBoolean(sym, left, right); *)
      ELSE
      END;
    END;
    RETURN b.ErrExpr(IR.unknownOp, sym);
  END NewOperator;

(* -------- *)

END OOC:IR:Operator.
