MODULE OOC:IR:Operator [OOC_EXTENSIONS];

IMPORT
  Integers, Log, ADT:ArrayList,
  Language, Language:Boolean, Language:Integer, 
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

  (* variants of LEN() *)
  lenStringConst* = 16;
  (**@code{LEN()} applied to a string constant.  Nodes of this type are
     implicitly created when passing a string constant to an open array
     parameter of character type.  *)
  lenFixedArray* = 17;
  (**@code{LEN()} on a fixed length array variable.  *)
  lenOpenArrayParam* = 18;
  (**@code{LEN()} on a variable length array parameter.  *)
  lenOpenArrayHeap* = 19;
  (**@code{LEN()} on a variable length array on the heap.  *)
  
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
    (**A TypeConv expression represents a type conversion of an expression
       @ofield{expr} to a different type.  The source value is converted to an
       equivalent or close value in the target domain.  Example: An integer
       type representing the value @code{1} is converted to a floating point
       value @code{1.0}.  Type conversions are also used to convert between
       different integer types.  *)
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
  Len* = POINTER TO LenDesc;
  LenDesc = RECORD
    (**Represents a call to the predefined function @code{LEN}.

       Note: Nodes of this type are also created implicitly, for example when
       adding parameters to a procedure call to fill in the length of open
       array parameters.  When passing a string constant to an character array
       parameter, this operator is used to calculate the length of the array
       parameter.  *)
    (IR.OperatorDesc)
    variant-: Variant;
    array-: IR.Expression;
    dim-: LONGINT;
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

VAR
  real : Sym.Type;
  minus1, zero : Integers.Integer;

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

PROCEDURE (b : Builder) AssignType (type : Sym.Type; expr : IR.Expression) : IR.Expression;
(**If necessary, transform @oparam{expr} to be compatible with @oparam{type}.
   For scalar types, this involves returning an explicit type conversion
   operator. Where types are already compatible (eg. extension of record
   types), the original expression is returned without modification. If the
   type of @oparam{expr} is not ccompatible with @oparam{type}, the function
   returns NIL. *)
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
END AssignType;

PROCEDURE (b : Builder) AdjustTypes (VAR left, right : IR.Expression; VAR type : Sym.Type) : BOOLEAN;
(**AdjustTypes implements type checking for arguments of operands. Section 8.2.2
   of the language report states "The type of the result is the type of that
   operand which includes the type of the other operand ...". Where required,
   this procedure modifies left or right expressions with an explicit type
   conversion operator so that the two expressions have compatible types. The
   broadest type of the two operands is returned in @oparam{type}. *)
VAR
  expr : IR.Expression;
  tr : TypeRules.Rules;
BEGIN
  tr := b.typeRules;
  IF tr.SameType(left.type, right.type) THEN
    type := left.type; RETURN TRUE;
  ELSE
    expr := b.AssignType(left.type, right);
    IF expr = NIL THEN
      expr := b.AssignType(right.type, left);
      IF expr = NIL THEN
        RETURN FALSE;
      ELSE
        left := expr; type := right.type; RETURN TRUE;
      END;
    ELSE
      right := expr; type := left.type; RETURN TRUE;
    END;
  END;
END AdjustTypes;

PROCEDURE (b : Builder) FoldBinary(op, left, right : IR.Expression) : IR.Expression;
(**FoldBinary implements simple constant folding for binary operators. If
   operator @oparam{op} has constant arguments @oparam{left} and
   @oparam{right}, it is evaluated. If evaluation is successful, the constant
   result is returned.  Otherwise, the original operator is returned. *)
VAR 
  value : Language.Value;
  env : IR.Environment;
BEGIN
  IF (left IS IR.Const) & (right IS IR.Const) THEN
    env.Init();
    value := op.Evaluate(env);
    IF env.Err() THEN
      b.ErrSym(IR.evaluateConst, op.sym);
      RETURN op;
    ELSE
      RETURN b.NewConst(op.sym, op.type, value);
    END;
  ELSE
    RETURN op;
  END;
END FoldBinary;

PROCEDURE (b : Builder) FoldUnary(op, operand : IR.Expression) : IR.Expression;
(**FoldUnary implements simple constant folding for unary operators. If
   operator @oparam{op} has constant argument @oparam{operand} it is evaluated.
   If evaluation is successful, the constant result is returned. Otherwise,
   the original operator is returned. *)
VAR 
  value : Language.Value;
  env : IR.Environment;
BEGIN
  IF (operand IS IR.Const) THEN
    env.Init();
    value := op.Evaluate(env);
    IF env.Err() THEN
      b.ErrSym(IR.evaluateConst, op.sym);
      RETURN op;
    ELSE
      RETURN b.NewConst(op.sym, op.type, value);
    END;
  ELSE
    RETURN op;
  END;
END FoldUnary;

(* -------- *)

PROCEDURE (op : BinaryArith) Evaluate* (VAR env : IR.Environment) : Language.Value;
VAR 
  l, r : Language.Value;

  PROCEDURE IntegerOp () : Language.Value;
  VAR
    result, left, right : Integers.Integer;
  BEGIN
    left := l(Integer.Value).value; 
    right := r(Integer.Value).value;
    
    CASE op.variant OF
      (* FIXME! Properly check for overflow. *)
    | arithAdd:  result := Integers.Sum(left, right);
    | arithSub:  result := Integers.Difference(left, right);
    | arithMul:  result := Integers.Product(left, right);
    | arithDivI: 
      IF Integers.Compare(right, zero) = 0 THEN
        env.Exception(IR.statusDivByZero, op, l, r); RETURN NIL;
      ELSE
        result := Integers.Quotient(left, right);
      END;
    | arithMod:
      IF Integers.Compare(right, zero) = 0 THEN
        env.Exception(IR.statusDivByZero, op, l, r); RETURN NIL;
      ELSE
        result := Integers.Remainder(left, right);
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

PROCEDURE InitBinaryArith (op: BinaryArith; sym: IR.Symbol; variant : Variant; left, right: IR.Expression; type : Sym.Type);
  BEGIN
    IR.InitOperator (op, sym, type);
    op.variant := variant;
    op.left := left;
    op.right := right;
  END InitBinaryArith;

PROCEDURE (b: Builder) NewBinaryArith (sym: IR.Symbol; left, right: IR.Expression): IR.Expression;
  VAR
    op: BinaryArith;  ok : BOOLEAN;
    variant : Variant; type : Sym.Type;
    tr : TypeRules.Rules;
  BEGIN
    tr := b.typeRules;

    CASE sym.id OF
    | Symbol.plus, Symbol.minus, Symbol.times:
      (* require two eqivalent numeric types *)
      ok := b.AdjustTypes(left, right, type) & 
            tr.IsPredefClass(type, Predef.classNumeric);
    | Symbol.div, Symbol.mod:
      (* require two equivalent integer types *)
      ok := b.AdjustTypes(left, right, type) &
            tr.IsPredefClass(type, Predef.classInteger);
    | Symbol.slash:
      (* require two real operands *)
      IF tr.IsPredefClass(left.type, Predef.classReal) OR tr.IsPredefClass(right.type, Predef.classReal) THEN
        (* one operand is already real *)
        ok := b.AdjustTypes(left, right, type);
      ELSE
        (* Neither operand is real, so try to convert both to real. This
        special case avoids the possibility of generating two TypeConv
        operators (eg. to widen an integer, then to widen integer to real. *)

        left := b.AssignType(real, left); right := b.AssignType(real, right);
        type := real;
        ok := (left # NIL) & (right # NIL)
      END;
    ELSE
      RETURN b.ErrExpr(IR.invalidOpType, sym);
    END;

    IF ok THEN
      CASE sym.id OF
      | Symbol.plus:   variant := arithAdd;
      | Symbol.minus:  variant := arithSub;
      | Symbol.times:  variant := arithMul;
      | Symbol.slash:  variant := arithDivR;
      | Symbol.div:    variant := arithDivI;
      | Symbol.mod:    variant := arithMod;
      END;

      NEW (op);
      InitBinaryArith (op, sym, variant, left, right, type);
      RETURN b.FoldBinary(op, left, right);
    ELSE
      RETURN b.ErrExpr(IR.invalidOpType, sym);
    END;
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
    left, right : Integers.Integer; result : BOOLEAN;
  BEGIN
    left := l(Integer.Value).value; 
    right := r(Integer.Value).value;
    
    CASE op.variant OF
    | equal:        result := Integers.Compare(left, right) = 0;
    | notEqual:     result := Integers.Compare(left, right) # 0;
    | less:         result := Integers.Compare(left, right) < 0;
    | lessEqual:    result := Integers.Compare(left, right) <= 0;
    | greater:      result := Integers.Compare(left, right) > 0;
    | greaterEqual: result := Integers.Compare(left, right) >= 0;
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

PROCEDURE InitLen (len: Len; sym: IR.Symbol; variant: Variant;
                   array: IR.Expression; dim: LONGINT);
  BEGIN
    IR.InitOperator (len, sym, Predef.GetType (Predef.lengthType));
    len. variant := variant;
    len. array := array;
    len. dim := dim;
  END InitLen;

PROCEDURE (b: Builder) NewLen* (sym: IR.Symbol;
                                array: IR.Expression; dim: LONGINT): Len;
  VAR
    len: Len;
    variant: Variant;
  BEGIN
    NEW (len);

    IF (array. type IS Sym.PredefType) THEN
      variant := lenStringConst
    ELSIF (array. type IS Sym.Array) &
          ~array. type(Sym.Array). isOpenArray THEN
      variant := lenFixedArray
    ELSIF (array IS IR.Var) THEN
      variant := lenOpenArrayParam
    ELSE
      variant := lenOpenArrayHeap
    END;
    
    InitLen (len, sym, variant, array, dim);
    RETURN len
  END NewLen;

PROCEDURE (v: Visitor) [ABSTRACT] VisitLen* (len: Len);
  END VisitLen;

PROCEDURE (len: Len) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitLen (len)
  END Accept;

PROCEDURE (len: Len) Evaluate* (VAR env : IR.Environment): Language.Value;
  BEGIN
    ASSERT(FALSE);
    RETURN NIL;
  END Evaluate;

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
    RETURN Integer.type.Value(Integers.Product(minus1, value(Integer.Value).value));
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

PROCEDURE (b: Builder) NewNegate (sym: IR.Symbol; expr: IR.Expression): IR.Expression;
  VAR
    neg: Negate;
  BEGIN
    NEW (neg);
    InitNegate (neg, sym, expr);
    RETURN b.FoldUnary(neg, expr);
  END NewNegate;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNegate* (neg: Negate);
  END VisitNegate;

PROCEDURE (neg: Negate) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitNegate (neg)
  END Accept;

(* -------- *)

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
      | Symbol.plus:
        IF isNumeric THEN 
	  RETURN right;
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

PROCEDURE (b: Builder) TransformArgs* (sym: IR.Symbol;
                                       formalPars: Sym.VarDeclArray;
                                       arguments: IR.ExpressionList): IR.ExpressionList;
(**See @oproc{IR.Builder.TransformArgs}.  *)
  VAR
    newArgs: ArrayList.ArrayList;
    i, fparIndex, argIndex: LONGINT;
    fparType: Sym.Type;
    exprList: IR.ExpressionList;
  BEGIN
    newArgs := ArrayList.New (LEN (arguments^));
    
    fparIndex := 0;
    argIndex := 0;
    WHILE (fparIndex # LEN (formalPars^)) &
          (argIndex # LEN (arguments^)) DO
      (* FIXME... need to check formal and actual type, insert type conversion,
         and so on  *)
      newArgs. Append (arguments[argIndex]);
      
      fparType := formalPars[fparIndex]. type;
      WITH fparType: Sym.Array DO
        FOR i := 0 TO fparType. GetOpenDimensions()-1 DO
          newArgs. Append (b. NewLen (sym, arguments[argIndex], i))
        END;
      ELSE  (* nothing to do *)
      END;
      
      INC (argIndex);
      INC (fparIndex);
    END;
    
    NEW (exprList, newArgs. size);
    FOR i := 0 TO newArgs. size-1 DO
      exprList[i] := newArgs. array[i](IR.Expression)
    END;
    RETURN exprList
  END TransformArgs;

PROCEDURE (b: Builder) AddSetupCode* (sym: IR.Symbol; decl: Sym.ProcDecl;
                                      statmSeq: IR.StatementSeq): IR.StatementSeq;
(**See @oproc{IR.Builder.AddSetupCode}.  *)
  VAR
    newStatm: ArrayList.ArrayList;
    formalPars: Sym.VarDeclArray;
    fparIndex, dim: LONGINT;
    fpar: Sym.VarDecl;
    size, arrayExpr: IR.Expression;

  PROCEDURE MyNewBinaryArith (sym: IR.Symbol; left, right: IR.Expression): IR.Expression;
    VAR
      op: BinaryArith;
    BEGIN
      NEW (op);
      InitBinaryArith (op, sym, arithMul, left, right, left. type);
      RETURN op
    END MyNewBinaryArith;

  PROCEDURE AddStatm (statm: IR.Statement);
    BEGIN
      IF (newStatm = NIL) THEN
        newStatm := ArrayList.New(4)
      END;
      newStatm. Append (statm)
    END AddStatm;

  PROCEDURE Prepend (prefix: ArrayList.ArrayList; statmSeq: IR.StatementSeq): IR.StatementSeq;
    VAR
      new: IR.StatementSeq;
      i: LONGINT;
    BEGIN
      NEW (new, prefix. size+LEN (statmSeq^));
      FOR i := 0 TO prefix. size-1 DO
        new[i] := prefix. array[i](IR.Statement)
      END;
      FOR i := 0 TO LEN (statmSeq^)-1 DO
        new[i+prefix. size] := statmSeq[i]
      END;
      RETURN new
    END Prepend;
  
  BEGIN
    newStatm := NIL;
    formalPars := decl. formalPars. params;
    fparIndex := 0;
    
    fparIndex := 0;
    WHILE (fparIndex # LEN (formalPars^)) DO
      fpar := formalPars[fparIndex];
      IF fpar. isPassPerReference & ~fpar. isVarParam THEN
        IF b. typeRules. IsOpenArrayType (fpar. type) THEN
          arrayExpr := b. NewVar (sym, fpar);
          size := b. NewLen (sym, arrayExpr, 0);
          FOR dim := 1 TO fpar. type(Sym.Array). GetOpenDimensions()-1 DO
            size := MyNewBinaryArith (sym, size, b. NewLen (sym, arrayExpr, dim))
          END;
        ELSE
          size := NIL;
        END;
        
        AddStatm (b. NewCopyParameter (sym, fpar, size))
      END;
      INC (fparIndex)
    END;

    IF (newStatm = NIL) THEN
      RETURN statmSeq
    ELSE
      RETURN Prepend (newStatm, statmSeq)
    END;
  END AddSetupCode;

BEGIN
  real := Predef.GetType(Predef.real);
  zero := Integers.Long(0);
  minus1 := Integers.Long(-1);
END OOC:IR:Operator.
