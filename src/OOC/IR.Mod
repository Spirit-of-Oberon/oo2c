MODULE OOC:IR [OOC_EXTENSIONS];

IMPORT
Log,
  Language, Language:Boolean, Language:Char8, Language:String8,
  Language:Integer, ADT:Object, ADT:ArrayList,
  Config:Value, BooleanValue := Config:Value:Boolean, 
  SymbolId := OOC:Scanner:Symbol, OOC:Scanner:Builder:BasicList, OOC:Error,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:AST, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef, OOC:SymbolTable:TypeRules;

(**Some rules regarding the intermediate representation (short ``IR''):

   @itemize @bullet
   @item
   The IR is a logical representation of a module's data and executable code.
   It is independent of any architecture that is the target of the translation.
   That is, it does not make any assumptions about data types, addresses, data
   alignment, low-level instructions of the target processor, and the like.

   @item
   The process of creating module's IR performs all the checks necessary to
   ensure that the code meets the syntactic and semantic restrictions of the
   source language.  That is, once the IR has been computed, no further
   checking is done on the module's correctness.  No errors may be signaled in
   subsequent processing of the module code.

   @item
   Creation of the IR is done by means of a dedicated builder class
   @otype{Builder}.  The builder also implements error checks.  It, and not the
   code calling the factory methods, guarantees that the constructed IR is
   valid if it does not report an error in the process of assembling the IR.

   @item
   The semantics of IR instructions is as simple as possible.  In the ideal
   case, an IR instruction performs a single task, and this task is completely
   identified by the instruction name.  There should be no variants in an
   instruction's semantics based on its arguments.  In other words, in the next
   step of the translation process it should be possible to use a single code
   pattern to translate instructions of the same kind.  (Well, that is the
   theory.  In practice, several distinct operations are sometimes mapped to a
   one class to avoid an explosion of classes doing very similar things.
   Examples for this are the single class for dyadic arithmetic operators
   @otype{*OOC:IR:Operator.BinaryArith}, or the class
   @otype{*OOC:IR:Operator.Len} handling the different variations of
   @code{LEN}.)

   @item
   All implicit semantics in a module's code is made explicit.  For example,
   creating a local copy of a value array parameter is done through an IR
   instruction, as is registering a module with the run-time environment in its
   initialization code.  This added information typically represents
   conventions of the language or its run-time system.  A back-end
   implementation is not restricted in the way it interprets this information.
   @end itemize


   For every operation defined in the input language, this module defines the
   intermediate representation, and a mapping onto the intermediate
   representation that is invoked when traversing the abstract syntax tree.  It
   also produces all error messages dealing with semantics of the language.
   For this reason, it is rather huge and unwieldly.  To make it more
   accessible, the order of declarations follow some rules.

   @noindent
   Class Definitions:
   @table @asis
   @item Expression Classes
   The classes are listed according to their extension relationship, the
   specializations of a single class are sorted alphabetically.

   @item Statement Classes
   Sorted alphabetically.

   @item Module and Procedure Classes

   @item Other Classes
   These section defines the module, procedure, builder, and visitor classes.
   @end table

   @noindent
   Procedure Definitions:
   @table @asis
   @item Helper Procedures
   Anything that is used in lots of places, and is simple enough to be placed
   at the beginning of the procedure list.  For

   @item Forward Declarations
   If a procedure must be declared before its definition because of some
   interdepdency between classes, it is forward declared at the beginning of
   the module.  Note: Doc comments are placed with the definition, @emph{not}
   the forward declaration.

   @item Class and Instance Methods
   For every declared class, there is a corresponding block of procedures and
   type-bound procedures (see below) in the procedure area of the module.  The
   order of these blocks mirrors that of the the class declarations at the
   beginning of the module.
   @end table

   For every node @var{Foo}, be it an expression or a statement, the following
   declarations appear in the procedure area in this order:

   @table
   @item Comment ``Class: @var{Foo}''
   For searches in the source text.

   @item @code{Init@var{Foo}}
   This is a normal procedure that takes an instance of class @var{Foo} as
   first argument and initializes it from the other arguments.  If the class is
   a specialization, it first calls the @code{Init} procedure of the base type.
   On completion, the instance is initialized to a well known state.

   @item @code{Builder.New@var{Foo}}
   Creates an instance of @var{Foo} and calls @code{Init@var{Foo}} on it.
   Abstract classes have no factory method with @code{Builder}.  

   @item @code{Visitor.Visit@var{Foo}}
   The corresponding visit method for @otype{Visitor}.  (Does not exist
   for abstract classes.)
   
   @item @var{Foo}.Accept}
   The corresponding accept method for @otype{Visitor}.  (Does not exist
   for abstract classes.)
   @end table

   Methods that have a more complex task, for example chosing from a range of
   classes, are collected at the end of the module in the code section of the
   @otype{Builder} class.  *)


TYPE
  Name* = AST.Name;
  Symbol* = BasicList.Symbol;
  
TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD [ABSTRACT]
    (Object.ObjectDesc)
    sym-: Symbol;
    (**This symbol's location is used to refer to the node when writing an
       error or warning message.  For constants or name, this symbol is the
       node's original representation.  For expressions or statements it refers
       to a symbol that can serve as an---ideally unambiguous---identifier for
       the construct.

       The field is @code{NIL} if, and only if, the node is equal to
       @ofield{Builder.errorExpr}.  In this case, no error or warning should be
       written, because the node already triggered an error message.  *)
  END;



(* Expressions
   ------------------------------------------------------------------------ *)

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
  Expression* = POINTER TO ExpressionDesc;
  ExpressionList* = POINTER TO ARRAY OF Expression;
  ExpressionDesc* = RECORD [ABSTRACT]
    (**Common base type of all nodes producing a non-void value.  *)
    (NodeDesc)
    type-: Sym.Type;
  END;
  
TYPE
  Const* = POINTER TO ConstDesc;
  ConstDesc = RECORD
  (**A constant value, derived from a literal, a reference to a named constant,
     or created as the result of constant folding.  Mapping from Oberon-2 types
     to instances of @otype{Language.Value}:

     @table @code
     @item BOOLEAN
     @otype{*Language:Boolean.Value}

     @item CHAR string8
     @otype{*Language:String8.Value}.  Note: String constants can contain any
     character, including @code{0X}.  Character constants are mapped onto
     string values of length 1.

     @item SHORTINT INTEGER LONGINT HUGEINT
     @otype{*Language:Integer.Value}
     @end table  *)
    (ExpressionDesc)
    value-: Language.Value;
  END;

TYPE
  Operator* = POINTER TO OperatorDesc;
  OperatorDesc* = RECORD [ABSTRACT]
  (**An operator represents a unary or dyadic operator and its argument(s).
     There are several differences between a function call and an operator:

     @itemize @bullet
     @item
     An operator is guaranteed to be free of side-effects.
     @item
     An operator is typically overloaded.  For example, all addition operations
     on numeric types are mapped to a single class.
     @item
     Operators are defined by the compiler, not the program.  At least,
     Oberon-2 does not allow to define operators.
     @end itemize

     There is no one-to-one relationship between operators and operator
     symbols.  For example, the symbol @samp{+} is either mapped onto a numeric
     addition, or a set union.  Also some predefined functions, like
     @samp{LEN}, are also mapped on operators.  *)
    (ExpressionDesc)
  END;

TYPE
  Adr* = POINTER TO AdrDesc;
  AdrDesc = RECORD
    (**Produces the address of a designator.  Nodes of this type are
       created for calls to @code{SYSTEM.ADR}, and implicitly for pass
       by reference arguments to procedure calls.  *)
    (OperatorDesc)
    design-: Expression;
  END;

TYPE
  BinaryArith* = POINTER TO BinaryArithDesc;
  BinaryArithDesc = RECORD 
    (OperatorDesc)
    variant- : Variant;
    left-, right- : Expression;
  END;

TYPE
  Cap* = POINTER TO CapDesc;
  CapDesc = RECORD
    (OperatorDesc)
    operand- : Expression;
  END;

TYPE
  Compare* = POINTER TO CompareDesc;
  CompareDesc = RECORD
    (OperatorDesc)
    variant- : Variant;
    left-, right- : Expression;
  END;

TYPE
  Index* = POINTER TO IndexDesc;
  IndexDesc = RECORD
    (OperatorDesc)
    (**The index operator selects the element at position @ofield{index} from
       the array variable @ofield{array}.  *)
    array- : Expression;
    index- : Expression;
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
    (OperatorDesc)
    variant-: Variant;
    array-: Expression;
    dim-: LONGINT;
  END;

TYPE
  Negate* = POINTER TO NegateDesc;
  NegateDesc = RECORD
    (OperatorDesc)
    operand- : Expression;
  END;

TYPE
  SelectField* = POINTER TO SelectFieldDesc;
  SelectFieldDesc = RECORD
    (OperatorDesc)
    (**This operator selects the field @ofield{field} from the record variable
       @ofield{record}.  *)
    record- : Expression;
    field- : Sym.FieldDecl;
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
    (OperatorDesc)
    expr- : Expression;
  END;

TYPE
  Reference* = POINTER TO ReferenceDesc;
  ReferenceDesc = RECORD [ABSTRACT]
  (**Represents a using occurence of a name.  A reference is associatd with
     exactly one defining declaration.  In the case of predefined procedures
     and operators, this declaration may be overloaded, but in all other cases
     the declaration uniquely identifies the referenced entity.  *)
    (ExpressionDesc)
    decl-: Sym.Declaration;
    (**The entity refered to.  *)
  END;

TYPE
  ModuleRef* = POINTER TO ModuleRefDesc;
  ModuleRefDesc = RECORD
    (ReferenceDesc)
  END;

TYPE
  PredefProc* = POINTER TO PredefProcDesc;
  PredefProcDesc = RECORD
  (**Identifies a predefined procedure.  Calls to predefined procedures and
     functions are always mapped to specialized code.  Instances of
     @otype{PredefProc} are created during the translation process, but should
     never appear in the final IR.  *)
    (ReferenceDesc)
  END;

TYPE
  ProcedureRef* = POINTER TO ProcedureRefDesc;
  ProcedureRefDesc = RECORD
    (ReferenceDesc)
  END;

TYPE
  TypeRef* = POINTER TO TypeRefDesc;
  TypeRefDesc = RECORD
    (ReferenceDesc)
  END;

TYPE
  Var* = POINTER TO VarDesc;
  VarDesc = RECORD
    (ReferenceDesc)
  END;

(* Statements
   ------------------------------------------------------------------------ *)

TYPE
  Statement* = POINTER TO StatementDesc;
  StatementSeq* = POINTER TO ARRAY OF Statement;
  StatementDesc = RECORD [ABSTRACT]
    (ExpressionDesc)
  END;

TYPE
  Assert* = POINTER TO AssertDesc;
  AssertDesc = RECORD
    (**Represents a call to the predefined procedure @code{ASSERT}.  *)
    (StatementDesc)
    predicate-: Expression;
    code-: LONGINT;
    disabled-: BOOLEAN;
  END;
CONST
  defaultAssertCode = 1;

TYPE
  Assignment* = POINTER TO AssignmentDesc;
  AssignmentDesc* = RECORD
    (**Assignment statement.  *)
    (StatementDesc)
    variable-: Expression;
    value-: Expression;
  END;
  
TYPE
  AssignOp* = POINTER TO AssignOpDesc;
  AssignOpDesc = RECORD
    (AssignmentDesc)
    (**This operation is used to model calls to @code{INC}, @code{DEC},
       @code{INCL}, and @code{EXCL}.  The field @ofield{variable} equals the
       left operand of the @otype{BinaryArith} instance in @ofield{value}.
       Translation of this special assignment must take care to evaluate the
       variable designator only once!  *)
  END;
  
TYPE
  Call* = POINTER TO CallDesc;
  CallDesc = RECORD
    (**Calls to normal functions and procedures are mapped to this class.  It
       is not used to represent calls to type-bound procedures, nor to
       predefined procedures.

       Predefined functions are represented as operators of expressions.
       Predefined procedures are mapped to dedicated classes.  The reason for
       distinguishing them from normal procedures is that code generators
       typically emit very specialized code patterns for them.  *)
    (StatementDesc)
    design-: Expression;
    arguments-: ExpressionList;
  END;

TYPE
  CopyParameter* = POINTER TO CopyParameterDesc;
  CopyParameterDesc = RECORD
    (**Used to create local copies of value parameters that are passed to
       the callee as references.  This statement allocates the space for a
       local copy of the parameter, and initializes it with the actual
       value of the argument.  *)
    (StatementDesc)
    
    param-: Sym.VarDecl;
    (**The value parameter that must be copied.  *)

    openArraySize-: Expression;
    (**If the parameter is an open array, then this field holds the total
       number of elements of the array.  The number is the product of the
       array length for all open dimensions.  If the parameter is not an
       open array, then this field is @code{NIL}.  *)
  END;
  
TYPE
  IfStatm* = POINTER TO IfStatmDesc;
  IfStatmDesc = RECORD
    (**Holds an @code{IF-ELSE-END} statement.  If there is no @code{ELSE}, then
       @ofield{pathFalse} is @code{NIL}.  @code{IF} statements with
       @code{ELSIF} parts are translated to nested @code{IF} statements.  *)
    (StatementDesc)
    guard-: Expression;
    pathTrue-: StatementSeq;
    pathFalse-: StatementSeq;  (* NIL if the IF statement has no ELSE *)
  END;
  
TYPE
  RepeatStatm* = POINTER TO RepeatStatmDesc;
  RepeatStatmDesc = RECORD
    (**Holds an @code{REPEAT-UNTIL} statement.  *)
    (StatementDesc)
    body-: StatementSeq;
    exitCondition-: Expression;
  END;
  
TYPE
  Return* = POINTER TO ReturnDesc;
  ReturnDesc = RECORD
    (**A procedure's @code{RETURN} statement.  *)
    (StatementDesc)
    result-: Expression;
    (**The result expression.  @code{NIL} if this is a return from
       a procedure.  *)
  END;

TYPE
  WhileStatm* = POINTER TO WhileStatmDesc;
  WhileStatmDesc = RECORD
    (**Holds an @code{WHILE-DO} statement.  *)
    (StatementDesc)
    guard-: Expression;
    body-: StatementSeq;
  END;

  
(* Modules and Procedures
   ------------------------------------------------------------------------ *)

TYPE
  Procedure* = POINTER TO ProcedureDesc;
  ProcedureList* = POINTER TO ARRAY OF Procedure;
  ProcedureDesc = RECORD
    (NodeDesc)
    decl-: Sym.ProcDecl;
    statmSeq-: StatementSeq;             (* statements in body, never NIL *)
  END;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc = RECORD
    (NodeDesc)
    name-: Name;
    procList-: ProcedureList;
    statmSeq-: StatementSeq;             (* statements in body, never NIL *)
  END;

TYPE
  Builder* = POINTER TO BuilderDesc;
  ConstFold* = POINTER TO ConstFoldDesc;
  BuilderDesc* = RECORD
    pragmaHistory: Pragmas.History;
    errList: Error.List;
    constFold- : ConstFold;
    
    typeRules- : TypeRules.Rules;
    
    errorExpr-: Expression;
    (**This value is returned if there is no real value because of an error.
       For example, if an identifier cannot be resolved, or if a designator
       does not begin with an identifier, then this value is passed to the
       caller.  Within the IR, no other value is used to indicate illegal
       operations.

       @strong{Note}: A function can @emph{only} return this value for a node,
       if it also emits an error message.  *)
  END;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
  (**Base class for visitor pattern.  Specializations of various @code{Visit*}
     methods are responsible for traversing the tree of the module
     representation.  *)
  END;

TYPE
  ConstFoldDesc* = RECORD [ABSTRACT]
    (VisitorDesc)
    builder- : Builder;
    result* : Expression;
  END;


VAR
  real : Sym.Type;

CONST
  undeclaredIdent* = 1;
  expectedIdent* = 2;
  numberOutOfRange* = 3;
  characterOutOfRange* = 4;
  invalidOpType* = 5;
  (** types of operands are not allowed for this operator *)
  unknownOp* = 6;
  (** symbol is not an operator *)
  incompatibleTypes* = 7;
  (** types of operands are not equivalent as required by operator *)
  divideByZero* = 8;
  exprNotConstant* = 9;
  rangeError* = 10;
  exprByRef* = 11;
  incompatibleActualParam* = 12;

TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  irContext: ErrorContext;

  
PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | undeclaredIdent:
      t := "Undeclared identifier"
    | expectedIdent:
      t := "Expected identifier"
    | numberOutOfRange:
      t := "Number out of range"
    | characterOutOfRange:
      t := "Character value out of range"
    | invalidOpType:
      t := "Invalid type for operator"
    | unknownOp:
      t := "Unknown operator"
    | incompatibleTypes:
      t := "Incompatible types for operator"
    | divideByZero:
      t := "Divisor is zero"
    | exprNotConstant:
      t := "Expression is not constant"
    | rangeError:
      t := "Value out of range"
    | exprByRef:
      t := "Expression may not be passed by reference"
    | incompatibleActualParam:
      t := "Type of actual parameter is not compatible with formal type"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



(* Helper Procedures
   ------------------------------------------------------------------------ *)

PROCEDURE InitNode* (n: Node; sym: Symbol);
  BEGIN
    Object.Init (n);
    n. sym := sym;
  END InitNode;

PROCEDURE (node: Node) [ABSTRACT] Accept* (v: Visitor);
  END Accept;

PROCEDURE (c : ConstFold) TryConstFold* (expr: Expression): Expression;
(**Attempts to apply constant folding to the expression @oparam{expr}.  If
   the expression cannot be reduced to a constant, the argument @oparam{expr}
   is returned.  On success, result is an instance of @otype{Const}.  *)
  BEGIN
    c.result := NIL;
    expr.Accept(c);
    IF c.result = NIL THEN
      RETURN expr
    ELSE
      RETURN c.result;
    END;
  END TryConstFold;

PROCEDURE (b: Builder) ErrSym* (code: Error.Code; sym: Symbol);
  VAR
    lastError: Error.Msg;
  BEGIN
    lastError := Error.New (irContext, code);
    lastError. SetIntAttrib ("pos", sym. pos);
    lastError. SetIntAttrib ("line", sym. line);
    lastError. SetIntAttrib ("column", sym. column);
    b. errList. Append (lastError)
  END ErrSym;

PROCEDURE (b : Builder) ErrExpr* (code : Error.Code; sym : Symbol) : Expression;
  BEGIN
    b.ErrSym(code, sym);
    RETURN b. errorExpr;
  END ErrExpr;

PROCEDURE (b: Builder) GetName* (sym: Symbol): Sym.Name;
  VAR
    name: Sym.Name;
  BEGIN
    NEW (name);
    Sym.InitName (name, sym. str, sym. pos, sym. line, sym. column);
    RETURN name
  END GetName;

PROCEDURE (b : Builder) Fold* (expr : Expression) : Expression;
BEGIN
  RETURN b.constFold.TryConstFold(expr);
END Fold;

PROCEDURE IsPredefType(type : Sym.Type; id : Sym.PredefId) : BOOLEAN;
BEGIN
  RETURN (type IS Sym.PredefType) & (type(Sym.PredefType).id = id);
END IsPredefType;

PROCEDURE ^ (b : Builder) AssignType (type : Sym.Type; expr : Expression) : Expression;

(* Expression Class: Expression
   ------------------------------------------------------------------------ *)

PROCEDURE InitExpression* (expr: Expression; sym: Symbol; type: Sym.Type);
  BEGIN
    InitNode (expr, sym);
    expr. type := type;
  END InitExpression;

(* Expression Class: Const
   ------------------------------------------------------------------------ *)

PROCEDURE InitConst (const: Const; sym: Symbol; type: Sym.Type;
                     value: Language.Value);
  BEGIN
    InitExpression (const, sym, type);
    const. value := value;
  END InitConst;

PROCEDURE NewConst (sym: Symbol; type: Sym.Type;
                    value: Language.Value): Const;
  VAR
    const: Const;
  BEGIN
    NEW (const);
    InitConst (const, sym, type, value);
    RETURN const
  END NewConst;

PROCEDURE (v: Visitor) [ABSTRACT] VisitConst* (const: Const);
  END VisitConst;

PROCEDURE (const: Const) Accept* (v: Visitor);
  BEGIN
    v. VisitConst (const)
  END Accept;

PROCEDURE (b : Builder) NewConst* (sym: Symbol; type: Sym.Type;
                    value: Language.Value): Const;
  BEGIN
    RETURN NewConst(sym, type, value);
  END NewConst;

PROCEDURE (b: Builder) NewStringConst* (sym: Symbol): Expression;
  BEGIN
    IF (sym. str[2] # 0X) & (sym. str[3] = 0X) THEN
      (* strings with one char are mapped to characters; note: because
         the symbol includes the string delimiters, the test actually
         checks for a length of exactly 3 characters *)
      RETURN NewConst (sym, Predef.GetType (Predef.char),
                       String8.type. ValueOf (sym. str^));
    ELSE
      RETURN NewConst (sym, Predef.GetType (Predef.charString),
                       String8.type. ValueOf (sym. str^));
    END;
  END NewStringConst;

PROCEDURE (b: Builder) NewIntConst10* (sym: Symbol): Expression;
  VAR
    v: Language.Value;
  BEGIN
    v := Integer.type. ValueOf (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (numberOutOfRange, sym);
      RETURN b. errorExpr
    ELSE
      RETURN NewConst (sym, Predef.GetType (Predef.integer), v)
    END
  END NewIntConst10;

PROCEDURE (b: Builder) NewCharConst16* (sym: Symbol): Expression;
  VAR
    v: Language.Value;
    str: ARRAY 2 OF CHAR;
  BEGIN
    v := Char8.type. ValueOf (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (characterOutOfRange, sym);
      RETURN b. errorExpr
    ELSE
      WITH v: Char8.Value DO
        ASSERT (v. value < 256);
        str[0] := CHR (v. value);
        str[1] := 0X;
        RETURN NewConst (sym, Predef.GetType (Predef.char),
                         String8.NewString (str));
      END;
    END
  END NewCharConst16;

PROCEDURE (b: Builder) NewSize* (sym: Symbol; type: Expression): Expression;
  BEGIN
    ASSERT (type IS TypeRef);
    RETURN b. NewConst
        (sym, Predef.GetType (Predef.longint),
         Integer.NewLInt (type(TypeRef). decl(Sym.TypeDecl). type. size));
  END NewSize;

(* Expression Class: Operator
   ------------------------------------------------------------------------ *)

PROCEDURE InitOperator* (op: Operator; sym: Symbol; type: Sym.Type);
  BEGIN
    InitExpression (op, sym, type);
  END InitOperator;

(* Operator Class: Adr
   ------------------------------------------------------------------------ *)

PROCEDURE InitAdr (adr: Adr; sym: Symbol; design: Expression);
  BEGIN
    InitOperator (adr, sym, Predef.GetType (Predef.address));
    adr. design := design;
  END InitAdr;

PROCEDURE (b: Builder) NewAdr* (sym: Symbol; design: Expression): Adr;
  VAR
    adr: Adr;
  BEGIN
    NEW (adr);
    InitAdr (adr, sym, design);
    RETURN adr
  END NewAdr;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAdr* (adr: Adr);
  END VisitAdr;

PROCEDURE (adr: Adr) Accept* (v: Visitor);
  BEGIN
    v. VisitAdr (adr)
  END Accept;

(* Operator Class: BinaryArith
   ------------------------------------------------------------------------ *)

PROCEDURE InitBinaryArith (op: BinaryArith; sym: Symbol; variant : Variant; left, right: Expression; type : Sym.Type);
  BEGIN
    InitOperator (op, sym, type);
    op.variant := variant;
    op.left := left;
    op.right := right;
  END InitBinaryArith;

PROCEDURE (b: Builder) NewBinaryArith (sym: Symbol; variant: Variant; left, right: Expression): Expression;
  VAR
    op: BinaryArith;  ok : BOOLEAN;
    type : Sym.Type;
    tr : TypeRules.Rules;
    
  PROCEDURE AdjustTypes (VAR left, right : Expression; VAR type : Sym.Type) : BOOLEAN;
  (**AdjustTypes implements type checking for arguments of operands. Section
     8.2.2 of the language report states "The type of the result is the type of
     that operand which includes the type of the other operand ...". Where
     required, this procedure modifies left or right expressions with an
     explicit type conversion operator so that the two expressions have
     compatible types. The broadest type of the two operands is returned in
     @oparam{type}.  *)
    VAR
      expr : Expression;
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
  
  BEGIN
    tr := b.typeRules;

    CASE variant OF
    | arithAdd, arithSub, arithMul:
      (* require two eqivalent numeric types *)
      ok := (AdjustTypes(left, right, type) &
             b. typeRules. IsNumericType(type));
    | arithDivI, arithMod:
      (* require two equivalent integer types *)
      ok := (AdjustTypes(left, right, type) &
             b. typeRules. IsIntegerType(type));
    | arithDivR:
      (* require two real operands *)
      IF b. typeRules. IsRealType(left. type) OR
         b. typeRules. IsRealType(right. type) THEN
        (* one operand is already real *)
        ok := AdjustTypes(left, right, type);
      ELSE
        (* Neither operand is real, so try to convert both to real. This
        special case avoids the possibility of generating two TypeConv
        operators (eg. to widen an integer, then to widen integer to real. *)

        left := b.AssignType(real, left); right := b.AssignType(real, right);
        type := real;
        ok := (left # NIL) & (right # NIL)
      END;
    ELSE
      RETURN b.ErrExpr(invalidOpType, sym);
    END;

    IF ok THEN
      NEW (op);
      InitBinaryArith (op, sym, variant, left, right, type);
      RETURN op;
    ELSE
      RETURN b.ErrExpr(invalidOpType, sym);
    END;
  END NewBinaryArith;

PROCEDURE (v: Visitor) [ABSTRACT] VisitBinaryArith* (op: BinaryArith);
  END VisitBinaryArith;

PROCEDURE (op: BinaryArith) Accept* (v: Visitor);
  BEGIN
    v. VisitBinaryArith (op)
  END Accept;

(* Operator Class: Cap
   ------------------------------------------------------------------------ *)

PROCEDURE InitCap (cap: Cap; sym: Symbol; expr: Expression);
  BEGIN
    InitOperator (cap, sym, expr. type);
    cap. operand := expr;
  END InitCap;

PROCEDURE (b: Builder) NewCap (sym: Symbol; expr: Expression): Expression;
  VAR
    cap: Cap;
  BEGIN
    NEW (cap);
    InitCap (cap, sym, expr);
    RETURN cap;
  END NewCap;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCap* (cap: Cap);
  END VisitCap;

PROCEDURE (cap: Cap) Accept* (v: Visitor);
  BEGIN
    v. VisitCap (cap)
  END Accept;

(* Operator Class: Compare
   ------------------------------------------------------------------------ *)

PROCEDURE InitCompare (op: Compare; sym: Symbol; variant : Variant; left, right: Expression);
  BEGIN
    InitOperator (op, sym, Predef.GetType(Predef.boolean));
    op.left := left;
    op.right := right;
    op.variant := variant;
  END InitCompare;

PROCEDURE (b: Builder) NewCompare (sym: Symbol; left, right: Expression): Compare;
  VAR
    op: Compare; variant : Variant;

  BEGIN
    (* FIXME! Check types of left and right operands *)
    CASE sym.id OF
    | SymbolId.eql:  variant := equal;
    | SymbolId.neq:  variant := notEqual;
    | SymbolId.lss:  variant := less;
    | SymbolId.leq:  variant := lessEqual;
    | SymbolId.gtr:  variant := greater;
    | SymbolId.geq:  variant := greaterEqual;
    END;
    NEW (op);
    InitCompare (op, sym, variant, left, right);
    RETURN op;
  END NewCompare;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCompare* (op: Compare);
  END VisitCompare;

PROCEDURE (op: Compare) Accept* (v: Visitor);
  BEGIN
    v. VisitCompare (op)
  END Accept;

(* Operator Class: Index
   ------------------------------------------------------------------------ *)

PROCEDURE InitIndex (i: Index; sym: Symbol; array, index: Expression);
  BEGIN
    InitOperator (i, sym, array. type(Sym.Array). elementType);
    i.array := array;
    i.index := index;
  END InitIndex;

PROCEDURE (b: Builder) NewIndex* (sym: Symbol; array, index: Expression): Index;
  VAR
    i: Index;
  BEGIN
    NEW (i);
    InitIndex (i, sym, array, index);
    RETURN i
  END NewIndex;

PROCEDURE (v: Visitor) [ABSTRACT] VisitIndex* (index: Index);
  END VisitIndex;

PROCEDURE (index: Index) Accept* (v: Visitor);
  BEGIN
    v. VisitIndex (index)
  END Accept;

(* Operator Class: Len
   ------------------------------------------------------------------------ *)

PROCEDURE InitLen (len: Len; sym: Symbol; variant: Variant;
                   array: Expression; dim: LONGINT);
  BEGIN
    InitOperator (len, sym, Predef.GetType (Predef.lengthType));
    len. variant := variant;
    len. array := array;
    len. dim := dim;
  END InitLen;

PROCEDURE (b: Builder) NewLen* (sym: Symbol;
                                array: Expression; dim: LONGINT): Expression;
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
    ELSIF (array IS Var) THEN
      variant := lenOpenArrayParam
    ELSE
      variant := lenOpenArrayHeap
    END;
    
    InitLen (len, sym, variant, array, dim);
    RETURN len;
  END NewLen;

PROCEDURE (v: Visitor) [ABSTRACT] VisitLen* (len: Len);
  END VisitLen;

PROCEDURE (len: Len) Accept* (v: Visitor);
  BEGIN
    v. VisitLen (len)
  END Accept;

(* Operator Class: Negate
   ------------------------------------------------------------------------ *)

PROCEDURE InitNegate (neg: Negate; sym: Symbol; expr: Expression);
  BEGIN
    InitOperator (neg, sym, expr. type);
    neg.operand := expr;
  END InitNegate;

PROCEDURE (b: Builder) NewNegate (sym: Symbol; expr: Expression): Expression;
  VAR
    neg: Negate;
  BEGIN
    NEW (neg);
    InitNegate (neg, sym, expr);
    RETURN neg;
  END NewNegate;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNegate* (neg: Negate);
  END VisitNegate;

PROCEDURE (neg: Negate) Accept* (v: Visitor);
  BEGIN
    v. VisitNegate (neg)
  END Accept;

(* Operator Class: SelectField
   ------------------------------------------------------------------------ *)

PROCEDURE InitSelectField (sf: SelectField; sym: Symbol; record: Expression; field: Sym.Declaration);
  BEGIN
    InitOperator (sf, sym, field(Sym.FieldDecl). type);
    sf.record := record;
    sf.field := field(Sym.FieldDecl);
  END InitSelectField;

PROCEDURE (b: Builder) NewSelectField (sym: Symbol; record: Expression; field: Sym.Declaration): SelectField;
  VAR
    i: SelectField;
  BEGIN
    NEW (i);
    InitSelectField (i, sym, record, field);
    RETURN i
  END NewSelectField;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSelectField* (sf: SelectField);
  END VisitSelectField;

PROCEDURE (sf: SelectField) Accept* (v: Visitor);
  BEGIN
    v. VisitSelectField (sf)
  END Accept;

(* Operator Class: TypeConv
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeConv (conv: TypeConv; sym: Symbol; type: Sym.Type;
                     expr: Expression);
  BEGIN
    InitOperator (conv, sym, type);
    conv. expr := expr;
  END InitTypeConv;

PROCEDURE NewTypeConv (type: Sym.Type; expr : Expression): TypeConv;
  VAR
    conv: TypeConv;
  BEGIN
    NEW (conv);
    InitTypeConv (conv, expr.sym, type, expr);
    RETURN conv
  END NewTypeConv;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeConv* (conv: TypeConv);
  END VisitTypeConv;

PROCEDURE (conv: TypeConv) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeConv (conv)
  END Accept;

(* Expression Class: Reference
   ------------------------------------------------------------------------ *)

PROCEDURE InitReference (ref: Reference; name: Symbol; type: Sym.Type;
                         decl: Sym.Declaration);
  BEGIN
    InitExpression (ref, name, type);
    ref. decl := decl;
  END InitReference;

(* Expression Class: ModuleRef
   ------------------------------------------------------------------------ *)

PROCEDURE InitModuleRef (modRef: ModuleRef; name: Symbol; decl: Sym.Module);
  BEGIN
    InitReference (modRef, name, NIL, decl);
  END InitModuleRef;

PROCEDURE NewModuleRef (name: Symbol; decl: Sym.Module): ModuleRef;
  VAR
    modRef: ModuleRef;
  BEGIN
    NEW (modRef);
    InitModuleRef (modRef, name, decl);
    RETURN modRef
  END NewModuleRef;

PROCEDURE (v: Visitor) [ABSTRACT] VisitModuleRef* (modRef: ModuleRef);
  END VisitModuleRef;

PROCEDURE (modRef: ModuleRef) Accept* (v: Visitor);
  BEGIN
    v. VisitModuleRef (modRef)
  END Accept;

(* Expression Class: PredefProc
   ------------------------------------------------------------------------ *)

PROCEDURE InitPredefProc (pproc: PredefProc; name: Symbol; type: Sym.Type;
                          decl: Sym.PredefProc);
  BEGIN
    InitReference (pproc, name, type, decl);
  END InitPredefProc;

PROCEDURE NewPredefProc (name: Symbol; decl: Sym.PredefProc): PredefProc;
  VAR
    pproc: PredefProc;
  BEGIN
    NEW (pproc);
    InitPredefProc (pproc, name, NIL, decl);
    RETURN pproc
  END NewPredefProc;

PROCEDURE (v: Visitor) [ABSTRACT] VisitPredefProc* (pproc: PredefProc);
  END VisitPredefProc;

PROCEDURE (pproc: PredefProc) Accept* (v: Visitor);
  BEGIN
    v. VisitPredefProc (pproc)
  END Accept;

(* Expression Class: ProcedureRef
   ------------------------------------------------------------------------ *)

PROCEDURE InitProcedureRef (procRef: ProcedureRef; name: Symbol; decl: Sym.ProcDecl);
  BEGIN
    InitReference (procRef, name, decl. formalPars, decl);
  END InitProcedureRef;

PROCEDURE NewProcedureRef (name: Symbol; decl: Sym.ProcDecl): ProcedureRef;
  VAR
    procRef: ProcedureRef;
  BEGIN
    NEW (procRef);
    InitProcedureRef (procRef, name, decl);
    RETURN procRef
  END NewProcedureRef;

PROCEDURE (v: Visitor) [ABSTRACT] VisitProcedureRef* (procRef: ProcedureRef);
  END VisitProcedureRef;

PROCEDURE (procRef: ProcedureRef) Accept* (v: Visitor);
  BEGIN
    v. VisitProcedureRef (procRef)
  END Accept;

(* Expression Class: TypeRef
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeRef (typeRef: TypeRef; name: Symbol; decl: Sym.TypeDecl);
  BEGIN
    InitReference (typeRef, name, NIL, decl);
  END InitTypeRef;

PROCEDURE NewTypeRef (name: Symbol; decl: Sym.TypeDecl): TypeRef;
  VAR
    typeRef: TypeRef;
  BEGIN
    NEW (typeRef);
    InitTypeRef (typeRef, name, decl);
    RETURN typeRef
  END NewTypeRef;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeRef* (typeRef: TypeRef);
  END VisitTypeRef;

PROCEDURE (typeRef: TypeRef) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeRef (typeRef)
  END Accept;

(* Expression Class: Var
   ------------------------------------------------------------------------ *)

PROCEDURE InitVar (var: Var; name: Symbol; type: Sym.Type;
                   decl: Sym.VarDecl);
  BEGIN
    InitReference (var, name, type, decl);
  END InitVar;

PROCEDURE (b: Builder) NewVar* (name: Symbol; decl: Sym.VarDecl): Var;
  VAR
    var: Var;
  BEGIN
    NEW (var);
    InitVar (var, name, decl. type, decl);
    RETURN var
  END NewVar;

PROCEDURE (v: Visitor) [ABSTRACT] VisitVar* (var: Var);
  END VisitVar;

PROCEDURE (var: Var) Accept* (v: Visitor);
  BEGIN
    v. VisitVar (var)
  END Accept;

(* Statement Class: Statement
   ------------------------------------------------------------------------ *)

PROCEDURE InitStatement* (statm: Statement; sym: Symbol);
  BEGIN
    InitExpression (statm, sym, Predef.GetType (Predef.void));
  END InitStatement;

(* Statement Class: Assert
   ------------------------------------------------------------------------ *)

PROCEDURE InitAssert (assert: Assert; sym: Symbol; 
                      predicate: Expression; code: LONGINT; disabled: BOOLEAN);
  BEGIN
    InitStatement (assert, sym);
    assert. predicate := predicate;
    assert. code := code;
    assert. disabled := disabled;
  END InitAssert;

PROCEDURE GetPragmaValue (b: Builder; pragma: Pragmas.Pragma; charPos: Pragmas.CharPos): BOOLEAN;
  VAR
    value: Value.Value;
  BEGIN
    value := b. pragmaHistory. GetValue (pragma. name^, charPos);
    RETURN value(BooleanValue.Value). boolean
  END GetPragmaValue;

PROCEDURE (b: Builder) NewAssert (sym: Symbol;
                         arguments: ExpressionList; disabled: BOOLEAN): Assert;
  VAR
    assert: Assert;
  BEGIN  (* ... FIXME: check arguments, add default arg *)
    NEW (assert);
    InitAssert (assert, sym, arguments[0], defaultAssertCode, disabled);
    RETURN assert
  END NewAssert;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAssert* (assert: Assert);
  END VisitAssert;

PROCEDURE (assert: Assert) Accept* (v: Visitor);
  BEGIN
    v. VisitAssert (assert)
  END Accept;

(* Statement Class: Assignment
   ------------------------------------------------------------------------ *)

PROCEDURE InitAssignment* (assignment: Assignment; sym: Symbol;
                           variable, value: Expression);
  BEGIN
    InitStatement (assignment, sym);
    assignment. variable := variable;
    assignment. value := value;
  END InitAssignment;

PROCEDURE (b: Builder) NewAssignment* (sym: Symbol;
                                       variable, value: Expression): Assignment;
  VAR
    assignment: Assignment;
  BEGIN
    NEW (assignment);
    InitAssignment (assignment, sym, variable, value);
    RETURN assignment
  END NewAssignment;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAssignment* (assignment: Assignment);
  END VisitAssignment;

PROCEDURE (assignment: Assignment) Accept* (v: Visitor);
  BEGIN
    v. VisitAssignment (assignment)
  END Accept;

(* Statement Class: AssignOp
   ------------------------------------------------------------------------ *)

PROCEDURE InitAssignOp (ao: AssignOp; sym: Symbol; op: BinaryArith);
  BEGIN
    InitAssignment (ao, sym, op. left, op);
  END InitAssignOp;

PROCEDURE (b: Builder) NewAssignOp (sym: Symbol; op: Expression): Expression;
  VAR
    i: AssignOp;
  BEGIN
    WITH op: Const DO
      RETURN b. errorExpr;               (* bail out, op is errorExpr *)
    ELSE
      NEW (i);
      InitAssignOp (i, sym, op(BinaryArith));
      RETURN i;
    END;
  END NewAssignOp;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAssignOp* (ao: AssignOp);
  END VisitAssignOp;

PROCEDURE (ao: AssignOp) Accept* (v: Visitor);
  BEGIN
    v. VisitAssignOp (ao)
  END Accept;

(* Expression Class: Call
   ------------------------------------------------------------------------ *)

PROCEDURE InitCall (call: Call; design: Expression; arguments: ExpressionList);
  BEGIN
    InitStatement (call, design. sym);
    IF (design. type(Sym.FormalPars). resultType # NIL) THEN
      (* fix result type for function calls *)
      call. type := design. type(Sym.FormalPars). resultType
    END;
    call. design := design;
    call. arguments := arguments;
  END InitCall;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCall* (call: Call);
  END VisitCall;

PROCEDURE (call: Call) Accept* (v: Visitor);
  BEGIN
    v. VisitCall (call)
  END Accept;

(* Statement Class: CopyParameter
   ------------------------------------------------------------------------ *)

PROCEDURE InitCopyParameter (cp: CopyParameter; sym: Symbol;
                             param: Sym.VarDecl; openArraySize: Expression);
  BEGIN
    InitStatement (cp, sym);
    cp. param := param;
    cp. openArraySize := openArraySize;
  END InitCopyParameter;

PROCEDURE (b: Builder) NewCopyParameter* (sym: Symbol; param: Sym.VarDecl;
                                          openArraySize: Expression): CopyParameter;
  VAR
    cp: CopyParameter;
  BEGIN
    ASSERT (b.typeRules.IsOpenArrayType (param.type) = (openArraySize#NIL));
    NEW (cp);
    InitCopyParameter (cp, sym, param, openArraySize);
    RETURN cp
  END NewCopyParameter;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCopyParameter* (cp: CopyParameter);
  END VisitCopyParameter;

PROCEDURE (cp: CopyParameter) Accept* (v: Visitor);
  BEGIN
    v. VisitCopyParameter (cp)
  END Accept;

(* Statement Class: IfStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitIfStatm (ifStatm: IfStatm; sym: Symbol; guard: Expression;
                       pathTrue, pathFalse: StatementSeq);
  BEGIN
    InitStatement (ifStatm, sym);
    ifStatm. guard := guard;
    ifStatm. pathTrue := pathTrue;
    ifStatm. pathFalse := pathFalse;
  END InitIfStatm;

PROCEDURE (b: Builder) NewIfStatm* (sym: Symbol; guard: Expression;
                                    pathTrue, pathFalse: StatementSeq): IfStatm;
  VAR
    ifStatm: IfStatm;
  BEGIN
    NEW (ifStatm);
    InitIfStatm (ifStatm, sym, guard, pathTrue, pathFalse);
    RETURN ifStatm
  END NewIfStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitIfStatm* (ifStatm: IfStatm);
  END VisitIfStatm;

PROCEDURE (ifStatm: IfStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitIfStatm (ifStatm)
  END Accept;

(* Statement Class: RepeatStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitRepeatStatm (repeatStatm: RepeatStatm; sym: Symbol;
                           body: StatementSeq; exitCondition: Expression);
  BEGIN
    InitStatement (repeatStatm, sym);
    repeatStatm. body := body;
    repeatStatm. exitCondition := exitCondition;
  END InitRepeatStatm;

PROCEDURE (b: Builder) NewRepeatStatm* (sym: Symbol; body: StatementSeq;
                                        exitCondition: Expression):RepeatStatm;
  VAR
    repeatStatm: RepeatStatm;
  BEGIN
    NEW (repeatStatm);
    InitRepeatStatm (repeatStatm, sym, body, exitCondition);
    RETURN repeatStatm
  END NewRepeatStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitRepeatStatm* (repeatStatm: RepeatStatm);
  END VisitRepeatStatm;

PROCEDURE (repeatStatm: RepeatStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitRepeatStatm (repeatStatm)
  END Accept;

(* Statement Class: Return
   ------------------------------------------------------------------------ *)

PROCEDURE InitReturn (return: Return; sym: Symbol; result: Expression);
  BEGIN
    InitStatement (return, sym);
    return. result := result;
  END InitReturn;

PROCEDURE (b: Builder) NewReturn* (sym: Symbol; result: Expression): Return;
  VAR
    return: Return;
  BEGIN
    NEW (return);
    InitReturn (return, sym, result);
    RETURN return
  END NewReturn;

PROCEDURE (v: Visitor) [ABSTRACT] VisitReturn* (return: Return);
  END VisitReturn;

PROCEDURE (return: Return) Accept* (v: Visitor);
  BEGIN
    v. VisitReturn (return)
  END Accept;

(* Statement Class: WhileStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitWhileStatm (whileStatm: WhileStatm; sym: Symbol;
                          guard: Expression; body: StatementSeq);
  BEGIN
    InitStatement (whileStatm, sym);
    whileStatm. guard := guard;
    whileStatm. body := body;
  END InitWhileStatm;

PROCEDURE (b: Builder) NewWhileStatm* (sym: Symbol; guard: Expression;
                                       body: StatementSeq):WhileStatm;
  VAR
    whileStatm: WhileStatm;
  BEGIN
    NEW (whileStatm);
    InitWhileStatm (whileStatm, sym, guard, body);
    RETURN whileStatm
  END NewWhileStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitWhileStatm* (whileStatm: WhileStatm);
  END VisitWhileStatm;

PROCEDURE (whileStatm: WhileStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWhileStatm (whileStatm)
  END Accept;



(* Class: Procedure
   ------------------------------------------------------------------------ *)

PROCEDURE InitProcedure* (p: Procedure; sym: Symbol; 
                          decl: Sym.ProcDecl; statmSeq: StatementSeq);
  BEGIN
    InitNode (p, sym);
    p. decl := decl;
    p. statmSeq := statmSeq;
  END InitProcedure;

PROCEDURE (b: Builder) NewProcedure* (sym: Symbol;
                       decl: Sym.ProcDecl; statmSeq: StatementSeq): Procedure;
  VAR
    p: Procedure;
    
  PROCEDURE AddSetupCode (sym: Symbol; decl: Sym.ProcDecl;
                          statmSeq: StatementSeq): StatementSeq;
  (**Takes the statement sequence representing the body of a procedure and
     extends it with procedure setup (or tear down) code.  For example,
     statements that allocate and intialize local copies of value parameters
     are added here.  *)
    VAR
      newStatm: ArrayList.ArrayList;
      formalPars: Sym.VarDeclArray;
      fparIndex, dim: LONGINT;
      fpar: Sym.VarDecl;
      size, arrayExpr: Expression;
      
    PROCEDURE AddStatm (statm: Statement);
      BEGIN
        IF (newStatm = NIL) THEN
          newStatm := ArrayList.New(4)
        END;
        newStatm. Append (statm)
      END AddStatm;
    
    PROCEDURE Prepend (prefix: ArrayList.ArrayList; statmSeq: StatementSeq): StatementSeq;
      VAR
        new: StatementSeq;
        i: LONGINT;
      BEGIN
        NEW (new, prefix. size+LEN (statmSeq^));
        FOR i := 0 TO prefix. size-1 DO
          new[i] := prefix. array[i](Statement)
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
    NEW (p);
    statmSeq := AddSetupCode (sym, decl, statmSeq);
    InitProcedure (p, sym, decl, statmSeq);
    RETURN p
  END NewProcedure;

PROCEDURE (v: Visitor) [ABSTRACT] VisitProcedure* (procedure: Procedure);
  END VisitProcedure;

PROCEDURE (p: Procedure) Accept* (v: Visitor);
  BEGIN
    v. VisitProcedure (p)
  END Accept;

(* Class: Module
   ------------------------------------------------------------------------ *)

PROCEDURE InitModule* (m: Module; sym: Symbol;
                       name: Name; procList: ProcedureList;
                       statmSeq: StatementSeq);
  BEGIN
    InitNode (m, sym);
    m. name := name;
    m. procList := procList;
    m. statmSeq := statmSeq;
  END InitModule;

PROCEDURE (b: Builder) NewModule* (sym: Symbol;
                                   name: Name; procList: ProcedureList;
                                   statmSeq: StatementSeq): Module;
  VAR
    m: Module;
  BEGIN
    NEW (m);
    InitModule (m, sym, name, procList, statmSeq);
    RETURN m
  END NewModule;

PROCEDURE (v: Visitor) [ABSTRACT] VisitModule* (module: Module);
  END VisitModule;

PROCEDURE (m: Module) Accept* (v: Visitor);
  BEGIN
    v. VisitModule (m)
  END Accept;



(* Class: Visitor
   ------------------------------------------------------------------------ *)

PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
  END InitVisitor;

PROCEDURE InitConstFold* (c : ConstFold; b : Builder);
BEGIN
  InitVisitor (c);
  c.builder := b;
END InitConstFold;


(* Class: Builder
   ------------------------------------------------------------------------ *)

PROCEDURE InitBuilder* (b: Builder; pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules; fold : ConstFold);
  BEGIN
    b. pragmaHistory := pragmaHistory;
    b. errList := errList;
    b. typeRules := typeRules;
    b. errorExpr := NewConst (NIL, Predef.GetType(Predef.void), Boolean.New (FALSE));
    b. constFold := fold;
    fold. builder := b;
  END InitBuilder;

PROCEDURE NewBuilder* (pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules; constFold: ConstFold): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b, pragmaHistory, errList, typeRules, constFold);
    RETURN b
  END NewBuilder;


PROCEDURE (b: Builder) NewIdentRef* (ns: Sym.Namespace; context: Sym.Item; 
                                     name: Symbol): Expression;
  VAR
    decl: Sym.Declaration;
  BEGIN
    IF (name. id = SymbolId.ident) THEN
      decl := ns. Identify (context, b. GetName (name), FALSE);
      IF (decl = NIL) THEN
        b. ErrSym (undeclaredIdent, name)
      ELSE
        WITH decl: Sym.ConstDecl DO
          RETURN NewConst (name, decl. type, decl. value)
        | decl: Sym.VarDecl DO
          RETURN b. NewVar (name, decl)
        | decl: Sym.TypeDecl DO
          RETURN NewTypeRef (name, decl)
        | decl: Sym.PredefProc DO
          RETURN NewPredefProc (name, decl)
        | decl: Sym.ProcDecl DO
          RETURN NewProcedureRef (name, decl)
        | decl: Sym.Import DO
          RETURN NewModuleRef (name, decl. externalSymTab)
        ELSE
          Log.Type ("Unknown decl in NewIdentRef", decl);
          ASSERT (FALSE);
        END
      END
    ELSE
      b. ErrSym (expectedIdent, name)
    END;
    
    (* in the case of an error, return the value "FALSE"; returning NIL
       would require more effort in the callers to distinguish between
       correct and faulty expressions *)
    RETURN b. errorExpr 
  END NewIdentRef;

PROCEDURE (b: Builder) NewQualident* (modref: ModuleRef; context: Sym.Item; 
                                      name: Symbol): Expression;
  BEGIN
    RETURN b. NewIdentRef (modref. decl(Sym.Module). ns, context, name)
  END NewQualident;

PROCEDURE (b: Builder) NewSelect* (sym: Symbol; var: Expression;
                                   context: Sym.Item; name: Symbol): Expression;
(**Resolves a field or type-bound procedure selector.  *)
  BEGIN
    ASSERT (var. type IS Sym.Record);
    RETURN b. NewSelectField (sym, var, var. type(Sym.Record). ns.
                              Identify (context, b. GetName (name), FALSE));
  END NewSelect;

PROCEDURE (b: Builder) NewOperator* (sym: Symbol; left, right: Expression): Expression;
(**Return an IR expression for the given symbol and left/right expressions.
   This procedure handles operator polymorphism, mapping an operator symbol to
   different operations according to the type of its operands. This procedure
   returns an operator, or the value errorExpr. If the given symbol is not a
   recognised operator, an unknownOp error is signalled. If the types of the
   arguments are not valid for the given operator, an invalidOpType error is
   signalled. *)

  VAR
    tr : TypeRules.Rules;
    isNumeric, isSet: BOOLEAN;

  PROCEDURE SetOrNumeric () : Expression;
    VAR
      variant: Variant;
  BEGIN
    IF isNumeric THEN
      CASE sym.id OF
      | SymbolId.plus:   variant := arithAdd;
      | SymbolId.minus:  variant := arithSub;
      | SymbolId.times:  variant := arithMul;
      | SymbolId.slash:  variant := arithDivR;
      | SymbolId.div:    variant := arithDivI;
      | SymbolId.mod:    variant := arithMod;
      END;

      RETURN b.NewBinaryArith(sym, variant, left, right)
(*    ELSIF isSet THEN
      RETURN b.NewSet(sym, left, right); *)
    ELSE
      RETURN b.ErrExpr(invalidOpType, sym);
    END;
  END SetOrNumeric;

  BEGIN
    tr := b.typeRules;
    isNumeric := b. typeRules. IsNumericType(right. type);
    isSet := b. typeRules. IsSetType(right. type);

    IF left = NIL THEN 
      (* unary operator *)
      CASE sym.id OF
      | SymbolId.minus:
        IF isNumeric THEN
          RETURN b.NewNegate(sym, right);
        ELSIF isSet THEN
          (* for now, map set/numeric negation onto Negate operator *)
          RETURN b.NewNegate(sym, right);
        ELSE
          RETURN b.ErrExpr(invalidOpType, sym);
        END;
      | SymbolId.plus:
        IF isNumeric THEN 
	  RETURN right;
	ELSE
	  RETURN b.ErrExpr(invalidOpType, sym);
	END;
      | SymbolId.not:
        (* for now, map logical negation onto Negate operator *)
        RETURN b.NewNegate(sym, right);
      ELSE
        RETURN b.ErrExpr(unknownOp, sym);
      END;
    ELSE
      (* binary operator *)
      CASE sym.id OF
      | SymbolId.plus, SymbolId.minus, SymbolId.times, SymbolId.slash:
        RETURN SetOrNumeric();
      | SymbolId.div:
        RETURN b.NewBinaryArith(sym, arithDivI, left, right);
      | SymbolId.mod:
        RETURN b.NewBinaryArith(sym, arithMod, left, right);
      | SymbolId.eql, SymbolId.neq,
        SymbolId.lss, SymbolId.leq,
        SymbolId.gtr, SymbolId.geq:
        RETURN b.NewCompare(sym, left, right);
(*      | Symbol.and, Symbol.or:
        RETURN b.NewBoolean(sym, left, right); *)
      ELSE
        RETURN b.ErrExpr(unknownOp, sym);
      END;
    END;
    RETURN b.ErrExpr(unknownOp, sym);  (* shouldn't get here *)
  END NewOperator;

PROCEDURE (b: Builder) NewCall* (design: Expression; arguments: ExpressionList): Expression;
  VAR
    call: Call;

  PROCEDURE MakeAssignmentCompatible (b: Builder; sym: Symbol;
                                      expr: Expression;
                                      type: Sym.Type): Expression;
  (**Takes an expression and a type, and tries to make the expression's value
     assignment compatible to the type.  If this is not possible, and error
     is reported.  *)
    BEGIN
      expr := b.AssignType(type, expr);
      IF expr = NIL THEN
        RETURN b.ErrExpr(incompatibleActualParam, sym);
      ELSE
        RETURN expr
      END;
    END MakeAssignmentCompatible;
  
  PROCEDURE TransformArgs (sym: Symbol;
                           formalPars: Sym.VarDeclArray;
                           arguments: ExpressionList): ExpressionList;
  (**Takes the argument list from the parser and rewrites it to match the
     formal parameters of the called procedure.  The translation includes
     changes to the argument expressions (for example, type conversion to a
     different numeric type) and insertion of additional arguments (for
     example, array length for open array parameters, or insertion of a type
     tag for a @code{VAR} parameter of record type).  *)
    VAR
      newArgs: ArrayList.ArrayList;
      i, fparIndex, argIndex: LONGINT;
      fparType: Sym.Type;
      fpar: Sym.VarDecl;
      arg: Expression;
      exprList: ExpressionList;
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
          arg := MakeAssignmentCompatible (b, arg. sym, arg, fpar. type);
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
        exprList[i] := newArgs. array[i](Expression)
      END;
      RETURN exprList
    END TransformArgs;
  
  PROCEDURE GetOne (type: Sym.Type): Const;
    BEGIN
      RETURN b. NewConst (design. sym, type, Integer.NewLInt (1));
    END GetOne;
  
  BEGIN
    WITH design: PredefProc DO
      (* note: predefined functions are handled by a specialization of thie
         method in module OOC:IR:Operator *)
      CASE design. decl(Sym.PredefProc). id OF
      (* predefined procedures *)
      | Predef.assert:
        RETURN b. NewAssert (design. sym, arguments,
                   GetPragmaValue(b, StdPragmas.assertions, design. sym. pos));

      (* predefined functions *)
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
      END
    ELSE
      NEW (call);
      arguments := TransformArgs (design. sym,
                                  design. type(Sym.FormalPars). params,
                                  arguments);
      InitCall (call, design, arguments);
      RETURN call;
    END
  END NewCall;

PROCEDURE (b : Builder) AssignType (type : Sym.Type; expr : Expression) : Expression;
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
  result : Expression;
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
    length := expr(Const). value(String8.Value). value. length;
    IF IsPredefType(type, Predef.char) & (length = 1) THEN
      (* string of length 1 converts to char *)
      result := b.NewConst(expr.sym, type, expr(Const). value);
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

BEGIN
  NEW (irContext);
  Error.InitContext (irContext, "OOC:IR");
  real := Predef.GetType(Predef.real);
END OOC:IR.
