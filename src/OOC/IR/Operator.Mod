MODULE OOC:IR:Operator [OOC_EXTENSIONS];

IMPORT
  ADT:ArrayList,
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
  ConstFold* = POINTER TO ConstFoldDesc;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    (IR.BuilderDesc)
    constFold- : ConstFold;
  END;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
    (IR.VisitorDesc)
  END;

TYPE
  ConstFoldDesc* = RECORD [ABSTRACT]
    (VisitorDesc)
    builder- : Builder;
    result* : IR.Expression;
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
  Adr* = POINTER TO AdrDesc;
  AdrDesc = RECORD
    (**Produces the address of a designator.  Nodes of this type are
       created for calls to @code{SYSTEM.ADR}, and implicitly for pass
       by reference arguments to procedure calls.  *)
    (IR.OperatorDesc)
    design-: IR.Expression;
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

PROCEDURE InitConstFold* (c : ConstFold; b : Builder);
BEGIN
  c.builder := b;
END InitConstFold;

PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
    IR.InitVisitor (v);
  END InitVisitor;

PROCEDURE InitBuilder* (b: Builder; pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules);
  BEGIN
    IR.InitBuilder (b, pragmaHistory, errList, typeRules);
  END InitBuilder;

PROCEDURE NewBuilder* (pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules; fold : ConstFold): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b, pragmaHistory, errList, typeRules);
    InitConstFold(fold, b);
    b.constFold := fold;
    RETURN b
  END NewBuilder;

(* -------- *)

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

PROCEDURE (c : ConstFold) [ABSTRACT] Accept* (expr : IR.Expression);
END Accept;

PROCEDURE (b : Builder) Fold* (expr : IR.Expression) : IR.Expression;
BEGIN
  b.constFold.Accept(expr);
  IF b.constFold.result = NIL THEN
    RETURN expr
  ELSE
    RETURN b.constFold.result;
  END;
END Fold;

(* -------- *)

PROCEDURE InitBinaryArith (op: BinaryArith; sym: IR.Symbol; variant : Variant; left, right: IR.Expression; type : Sym.Type);
  BEGIN
    IR.InitOperator (op, sym, type);
    op.variant := variant;
    op.left := left;
    op.right := right;
  END InitBinaryArith;

PROCEDURE (b: Builder) NewBinaryArith (sym: IR.Symbol; variant: Variant; left, right: IR.Expression): IR.Expression;
  VAR
    op: BinaryArith;  ok : BOOLEAN;
    type : Sym.Type;
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
      NEW (op);
      InitBinaryArith (op, sym, variant, left, right, type);
      RETURN op;
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

PROCEDURE InitAdr (adr: Adr; sym: IR.Symbol; design: IR.Expression);
  BEGIN
    IR.InitOperator (adr, sym, Predef.GetType (Predef.address));
    adr. design := design;
  END InitAdr;

PROCEDURE (b: Builder) NewAdr* (sym: IR.Symbol; design: IR.Expression): Adr;
  VAR
    adr: Adr;
  BEGIN
    NEW (adr);
    InitAdr (adr, sym, design);
    RETURN adr
  END NewAdr;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAdr* (adr: Adr);
  END VisitAdr;

PROCEDURE (adr: Adr) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitAdr (adr)
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
                                array: IR.Expression; dim: LONGINT): IR.Expression;
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
    RETURN len;
  END NewLen;

PROCEDURE (v: Visitor) [ABSTRACT] VisitLen* (len: Len);
  END VisitLen;

PROCEDURE (len: Len) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitLen (len)
  END Accept;

(* -------- *)

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
    RETURN neg;
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
    isNumeric, isSet: BOOLEAN;

  PROCEDURE SetOrNumeric () : IR.Expression;
    VAR
      variant: Variant;
  BEGIN
    IF isNumeric THEN
      CASE sym.id OF
      | Symbol.plus:   variant := arithAdd;
      | Symbol.minus:  variant := arithSub;
      | Symbol.times:  variant := arithMul;
      | Symbol.slash:  variant := arithDivR;
      | Symbol.div:    variant := arithDivI;
      | Symbol.mod:    variant := arithMod;
      END;

      RETURN b.NewBinaryArith(sym, variant, left, right)
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
        RETURN b.ErrExpr(IR.unknownOp, sym);
      END;
    ELSE
      (* binary operator *)
      CASE sym.id OF
      | Symbol.plus, Symbol.minus, Symbol.times, Symbol.slash:
        RETURN SetOrNumeric();
      | Symbol.div:
        RETURN b.NewBinaryArith(sym, arithDivI, left, right);
      | Symbol.mod:
        RETURN b.NewBinaryArith(sym, arithMod, left, right);
      | Symbol.eql, Symbol.neq, Symbol.lss, Symbol.leq, Symbol.gtr, Symbol.geq:
        RETURN b.NewCompare(sym, left, right);
(*      | Symbol.and, Symbol.or:
        RETURN b.NewBoolean(sym, left, right); *)
      ELSE
        RETURN b.ErrExpr(IR.unknownOp, sym);
      END;
    END;
    RETURN b.ErrExpr(IR.unknownOp, sym);  (* shouldn't get here *)
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
    fpar: Sym.VarDecl;
    exprList: IR.ExpressionList;
  BEGIN
    newArgs := ArrayList.New (LEN (arguments^));
    
    fparIndex := 0;
    argIndex := 0;
    WHILE (fparIndex # LEN (formalPars^)) &
          (argIndex # LEN (arguments^)) DO
      (* FIXME... need to check formal and actual type, insert type conversion,
         and so on  *)
      fpar := formalPars[fparIndex];
      IF fpar. isPassPerReference THEN
        (* for argument passed by reference, add the address of the designator
           to the argument list, not its value *)
        newArgs. Append (b. NewAdr (sym, arguments[argIndex]));
      ELSE
        newArgs. Append (arguments[argIndex]);
      END;
      
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
            size := b. NewBinaryArith (sym, arithMul, size, b. NewLen (sym, arrayExpr, dim))
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
END OOC:IR:Operator.
