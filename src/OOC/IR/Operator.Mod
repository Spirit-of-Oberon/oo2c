MODULE OOC:IR:Operator [OOC_EXTENSIONS];

IMPORT
  ADT:ArrayList, Language:Integer, Language:String8,
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
  SelectField* = POINTER TO SelectFieldDesc;
  SelectFieldDesc = RECORD
    (IR.OperatorDesc)
    (**This operator selects the field @ofield{field} from the record variable
       @ofield{record}.  *)
    record- : IR.Expression;
    field- : Sym.FieldDecl;
  END;
  
TYPE
  Negate* = POINTER TO NegateDesc;
  NegateDesc = RECORD
    (IR.OperatorDesc)
    operand- : IR.Expression;
  END;

TYPE
  Cap* = POINTER TO CapDesc;
  CapDesc = RECORD
    (IR.OperatorDesc)
    operand- : IR.Expression;
  END;

TYPE
  AssignOp* = POINTER TO AssignOpDesc;
  AssignOpDesc = RECORD
    (IR.AssignmentDesc)
    (**This operation is used to model calls to @code{INC}, @code{DEC},
       @code{INCL}, and @code{EXCL}.  The field @ofield{variable} equals the
       left operand of the @otype{BinaryArith} instance in @ofield{value}.
       Translation of this special assignment must take care to evaluate the
       variable designator only once!  *)
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

PROCEDURE IsPredefType(type : Sym.Type; id : Sym.PredefId) : BOOLEAN;
BEGIN
  RETURN (type IS Sym.PredefType) & (type(Sym.PredefType).id = id);
END IsPredefType;

PROCEDURE (b : Builder) AssignType* (type : Sym.Type; expr : IR.Expression) : IR.Expression;
(**If necessary, transform @oparam{expr} to be compatible with @oparam{type}.
   For scalar types, this involves returning an explicit type conversion
   operator. Where types are already compatible (eg. extension of record
   types), the original expression is returned without modification. If the
   type of @oparam{expr} is not compatible with @oparam{type}, the function
   returns NIL.

   To summarize, we return:
     NIL        assignment IS NOT allowed
     expr       assignment IS allowed without modification
     otherwise  expression IS allowed with modification (eg. type conversion)
*)
VAR
  tr : TypeRules.Rules;
  exprType : Sym.Type;
  result : IR.Expression;
  length : LONGINT;
BEGIN
  tr := b.typeRules;
  exprType := expr.type;
  result := NIL;

  IF tr.SameType(type, exprType) OR tr.IsExtensionOf(type, exprType) THEN
    (* same types *)
    result := expr
  ELSIF tr.IncludesType(type, exprType) THEN
    result := NewTypeConv(type, expr)
  ELSIF IsPredefType(exprType, Predef.charString) THEN
    (* expression is constant string *)
    length := expr(IR.Const). value(String8.Value). value. length;
    IF IsPredefType(type, Predef.char) & (length = 1) THEN
      (* string of length 1 converts to char *)
      result := b.NewConst(expr.sym, type, expr(IR.Const). value);
    ELSE 
      (* string may be assigned to ARRAY OF CHAR with sufficient length *)
      WITH type : Sym.Array DO
        IF IsPredefType(type. elementType, Predef.char) &
          (type.isOpenArray OR (length < type.length)) THEN
          result := expr;
        END;
      ELSE
      END;
    END;
  END;
  RETURN result;
END AssignType;

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

    CASE variant OF
    | arithAdd, arithSub, arithMul:
      (* require two eqivalent numeric types *)
      ok := (b.AdjustTypes(left, right, type) &
             b. typeRules. IsNumericType(type));
    | arithDivI, arithMod:
      (* require two equivalent integer types *)
      ok := (b.AdjustTypes(left, right, type) &
             b. typeRules. IsIntegerType(type));
    | arithDivR:
      (* require two real operands *)
      IF b. typeRules. IsRealType(left. type) OR
         b. typeRules. IsRealType(right. type) THEN
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

PROCEDURE InitSelectField (sf: SelectField; sym: IR.Symbol; record: IR.Expression; field: Sym.Declaration);
  BEGIN
    IR.InitOperator (sf, sym, field(Sym.FieldDecl). type);
    sf.record := record;
    sf.field := field(Sym.FieldDecl);
  END InitSelectField;

PROCEDURE (b: Builder) NewSelectField (sym: IR.Symbol; record: IR.Expression; field: Sym.Declaration): SelectField;
  VAR
    i: SelectField;
  BEGIN
    NEW (i);
    InitSelectField (i, sym, record, field);
    RETURN i
  END NewSelectField;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSelectField* (sf: SelectField);
  END VisitSelectField;

PROCEDURE (sf: SelectField) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitSelectField (sf)
  END Accept;

PROCEDURE (b: Builder) NewSelect* (sym: IR.Symbol; var: IR.Expression;
                                   context: Sym.Item; name: IR.Symbol): IR.Expression;
  BEGIN
    ASSERT (var. type IS Sym.Record);
    RETURN b. NewSelectField (sym, var, var. type(Sym.Record). ns.
                              Identify (context, b. GetName (name), FALSE));
  END NewSelect;

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

PROCEDURE InitCap (cap: Cap; sym: IR.Symbol; expr: IR.Expression);
  BEGIN
    IR.InitOperator (cap, sym, expr. type);
    cap. operand := expr;
  END InitCap;

PROCEDURE (b: Builder) NewCap (sym: IR.Symbol; expr: IR.Expression): IR.Expression;
  VAR
    cap: Cap;
  BEGIN
    NEW (cap);
    InitCap (cap, sym, expr);
    RETURN cap;
  END NewCap;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCap* (cap: Cap);
  END VisitCap;

PROCEDURE (cap: Cap) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitCap (cap)
  END Accept;

(* -------- *)

PROCEDURE (b: Builder) NewSize* (sym: IR.Symbol; type: IR.Expression): IR.Expression;
  BEGIN
    ASSERT (type IS IR.TypeRef);
    RETURN b. NewConst
        (sym, Predef.GetType (Predef.longint),
         Integer.NewLInt (type(IR.TypeRef). decl(Sym.TypeDecl). type. size));
  END NewSize;

(* -------- *)

PROCEDURE InitAssignOp (ao: AssignOp; sym: IR.Symbol; op: BinaryArith);
  BEGIN
    IR.InitAssignment (ao, sym, op. left, op);
  END InitAssignOp;

PROCEDURE (b: Builder) NewAssignOp (sym: IR.Symbol; op: IR.Expression): IR.Expression;
  VAR
    i: AssignOp;
  BEGIN
    WITH op: IR.Const DO
      RETURN b. errorExpr;               (* bail out, op is errorExpr *)
    ELSE
      NEW (i);
      InitAssignOp (i, sym, op(BinaryArith));
      RETURN i;
    END;
  END NewAssignOp;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAssignOp* (ao: AssignOp);
  END VisitAssignOp;

PROCEDURE (ao: AssignOp) Accept* (v: IR.Visitor);
  BEGIN
    v(Visitor). VisitAssignOp (ao)
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
    isNumeric := b. typeRules. IsNumericType(right. type);
    isSet := b. typeRules. IsSetType(right. type);

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

PROCEDURE (b: Builder) NewCall* (design: IR.Expression; arguments: IR.ExpressionList): IR.Expression;
  PROCEDURE GetOne (type: Sym.Type): IR.Const;
    BEGIN
      RETURN b. NewConst (design. sym, type, Integer.NewLInt (1));
    END GetOne;
  
  BEGIN
    WITH design: IR.PredefProc DO
      (* note: predefined functions are handled by a specialization of thie
         method in module OOC:IR:Operator *)
      CASE design. decl(Sym.PredefProc). id OF
      | Predef.len:
        ASSERT (LEN (arguments^) = 1);   (* FIXME... needs error msg *)
        RETURN b. NewLen (design. sym, arguments[0], 0)
        
      | Predef.size:
        ASSERT (LEN (arguments^) = 1);   (* FIXME... needs error msg *)
        RETURN b. NewSize (design. sym, arguments[0])

      | Predef.inc:
        ASSERT (LEN (arguments^) = 1);
        RETURN b. NewAssignOp (design. sym,
                               b. NewBinaryArith (design. sym, arithAdd,
                                                  arguments[0],
                                                  GetOne (arguments[0].type)));
        
      | Predef.dec:
        ASSERT (LEN (arguments^) = 1);
        RETURN b. NewAssignOp (design. sym,
                               b. NewBinaryArith (design. sym, arithSub,
                                                  arguments[0],
                                                  GetOne (arguments[0].type)));
      | Predef.cap:
        ASSERT (LEN (arguments^) = 1);
        RETURN b. NewCap (design. sym, arguments[0]);
        
      ELSE
        RETURN b. NewCall^ (design, arguments);
      END
    ELSE
      RETURN b. NewCall^ (design, arguments);
    END
  END NewCall;


(* -------- *)

PROCEDURE MakeAssignmentCompatible (b: Builder; sym: IR.Symbol;
                                    expr: IR.Expression;
                                    type: Sym.Type): IR.Expression;
(**Takes an expression and a type, and tries to make the expression's value
   assignment compatible to the type.  If this is not possible, and error
   is reported.  *)
  BEGIN
    (* ... FIXME, this is _very_ incomplete :-)  *)
    IF (type IS Sym.PredefType) &
       (type(Sym.PredefType). id = Predef.char) &
       (expr. type IS Sym.PredefType) &
       (expr. type(Sym.PredefType). id = Predef.charString) THEN
      (* create character constant from string constant *)
      ASSERT (expr(IR.Const). value(String8.Value). value. length = 1);
      RETURN b. NewConst (sym, type, expr(IR.Const). value)
    ELSE
      RETURN expr
    END;
  END MakeAssignmentCompatible;

PROCEDURE (b: Builder) TransformArgs* (sym: IR.Symbol;
                                       formalPars: Sym.VarDeclArray;
                                       arguments: IR.ExpressionList): IR.ExpressionList;
(**See @oproc{IR.Builder.TransformArgs}.  *)
  VAR
    newArgs: ArrayList.ArrayList;
    i, fparIndex, argIndex: LONGINT;
    fparType: Sym.Type;
    fpar: Sym.VarDecl;
    arg: IR.Expression;
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
      arg := arguments[argIndex];

      IF fpar. isVarParam THEN           (* variable parameter *)
        (* ... nothing for now *)
      ELSE                               (* value parameter *)
        arg := b.AssignType(fpar. type, arg);
        IF arg = NIL THEN
          arg := b.ErrExpr(IR.incompatibleActualParam, arguments[argIndex].sym);
        END;
      END;

      IF fpar. isPassPerReference THEN
        (* for argument passed by reference, add the address of the designator
           to the argument list, not its value *)
        newArgs. Append (b. NewAdr (sym, arg));
      ELSE
        newArgs. Append (arg);
      END;
      
      fparType := formalPars[fparIndex]. type;
      WITH fparType: Sym.Array DO
        FOR i := 0 TO fparType. GetOpenDimensions()-1 DO
          newArgs. Append (b. NewLen (sym, arg, i))
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
