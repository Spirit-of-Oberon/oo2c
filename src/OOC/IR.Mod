(* 	$Id$	 *)
MODULE OOC:IR [OOC_EXTENSIONS];
(*  High-level intermediate code representation.
    Copyright (C) 2001, 2002  Michael van Acken, Stewart Greenhill

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
Log,
  Language, Language:Boolean, Language:Char8, Language:String8,
  Language:Integer, Language:Real,
  ADT:Object, ADT:ArrayList, ADT:String,
  Config:Value, BooleanValue := Config:Value:Boolean, 
  Id := OOC:Scanner:Symbol, OOC:Scanner:Builder:BasicList, OOC:Error,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:AST, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:SymbolTable:TypeRules, OOC:SymbolTable:Namespace;

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
   @otype{*OOC:IR.BinaryArith}, or the class
   @otype{*OOC:IR.Len} handling the different variations of
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

   @table @asis
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
   
   @item @code{@var{Foo}.Accept}
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
  Variant* = SHORTINT;
  
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

  and* = 20;
  or* = 21;
 
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

     @item NIL
     @ofield{value} is @code{NIL}.
     @end table  *)
    (ExpressionDesc)
    value-: Language.Value;
    (**The value of the constant expression, or @code{NIL} if the constant
       represents the literal @code{NIL}.  *)
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
  BooleanOp* = POINTER TO BooleanOpDesc;
  BooleanOpDesc = RECORD 
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
  Deref* = POINTER TO DerefDesc;
  DerefDesc = RECORD
    (OperatorDesc)
    (**The deref operator takes a pointer value and returns the referenced
       value.  *)
    pointer-: Expression;
    derefType-: Sym.Type;
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
    arrayVariable-: Expression;
    (**The array variable whose length is taken.  This may differ from the
       array in @ofield{array} for expressions like @samp{LEN(a[0])}.  *)
  END;

TYPE
  Negate* = POINTER TO NegateDesc;
  NegateDesc = RECORD
    (OperatorDesc)
    operand- : Expression;
  END;

TYPE
  NewObject* = POINTER TO NewObjectDesc;
  NewObjectDesc = RECORD
    (**Allocates a new object on the heap and returns a pointer to it.
       The type of the new pointer value is stored in @ofield{type}.  *)
    (OperatorDesc)
    length-: ExpressionList;
    (**For an array, this holds the length of the open dimensions.  For
       a fixed size array, the field refers to a list of length zero.
       For a record type, this field is @code{NIL}.  *)
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
  SelectProc* = POINTER TO SelectProcDesc;
  SelectProcDesc = RECORD
    (OperatorDesc)
    (**This operator selects the type-bound procedure @ofield{tbProc} belonging
       to the @ofield{receiver} designator.  *)
    receiver-: Expression;
    (**The receiver designator of the call.  *)
    
    recordType-: Sym.Record;
    (**The record type of which the type-bound procedure is called.  *)
    
    tbProc-: Sym.ProcDecl;
    (**The static procedure that is referenced by the call's designator
       in the source code.  The actual procedure being called may be this
       procedure, a redefinition of it, or (if this is a super call) its
       definition in one of the base types.  *)
    
    isStaticCall-: BOOLEAN;
    (**If @code{TRUE}, then this is a static call to the procedure indicated
       by @ofield{tbProc}.  No table lookup must be done, instead its
       address must be used directly.  *)
  END;

TYPE 
  SetMember* = POINTER TO SetMemberDesc;
  SetMemberDesc = RECORD
    (**This operator represents operations on SET values. *)
    (OperatorDesc)
    element-, set- : Expression;
  END;

TYPE
  SetOp* = POINTER TO SetOpDesc;
  SetOpDesc = RECORD
    (**This operator represents operations on SET values. *)
    (OperatorDesc)
    variant- : Variant;
    left-, right- : Expression;
  END;

TYPE
  SetRange* = POINTER TO SetRangeDesc;
  SetRangeDesc = RECORD 
  (**A SetRange represents a sub-range SET constructor.  A range consists of a
     @ofield{from} and @ofield{to} expression which must have the same type. If
     both values are constant, then @ofield{from} must not be greater than
     @ofield{to}. *)

    (OperatorDesc)
    from-, to- : Expression;
  END;

TYPE
  TypeConv* = POINTER TO TypeConvDesc;
  TypeConvDesc = RECORD
    (**A TypeConv expression represents a type conversion of an expression
       @ofield{expr} to a different type.  The source value of type
       @samp{expr.type} is converted to an equivalent or close value in the
       target domain @ofield{type}.  Example: An integer type representing the
       value @code{1} is converted to a floating point value @code{1.0}.  Type
       conversions are also used to convert between different integer types.

       @noindent
       Type conversion nodes are produced in different contexts:
       @itemize @bullet
       @item implicit type conversion of operands of numeric operators
       @item explicit type conversion using @code{SHORT} or @code{LONG}
       @item @dots{}
       @end itemize  *)
    (OperatorDesc)
    expr- : Expression;
  END;

TYPE
  TypeTag* = POINTER TO TypeTagDesc;
  TypeRef* = POINTER TO TypeRefDesc;
  TypeTagDesc = RECORD
    (**Computes the type tag of a record variable.  *)
    (OperatorDesc)
    design-: Expression;
    (**The variable designator.  This is either a record variable, a
       dereferenced pointer variable, or a @code{VAR} parameter of record type.  *)
  END;
  
TYPE
  TypeTest* = POINTER TO TypeTestDesc;
  TypeTestDesc = RECORD
    (**The type test operator @samp{IS}.  The operator is normalized in the
       sense that an expression @samp{p^ IS R} is treated as @samp{p IS P},
       where @samp{P} is some @samp{POINTER TO R}.  *)
    (OperatorDesc)
    expr-: Expression;
    referenceType-: Sym.Record;

    origExpr-: Expression;
    (**Unnormalized value of @ofield{expr}.  *)
    origType-: TypeRef;
    (**Unnormalized value of @ofield{referenceType}.  *)
  END;
  
TYPE
  Reference* = POINTER TO ReferenceDesc;
  ReferenceDesc = RECORD [ABSTRACT]
  (**Represents a using occurence of a name.  A reference is associated with
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
  LoopStatm* = POINTER TO LoopStatmDesc;
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
    
    formalPars-: Sym.VarDeclArray;
    (**Lists the formal parameter declarations matching the expressions in
       @ofield{arguments}.  This information is passed along for the sake of C
       back-ends, which need to be aware of the differences between formal and
       actual type to be able to insert appropriate type casts.

       @samp{formalPars[@var{i}]} is only @code{NIL}, if the value of
       @samp{arguments[@var{i}]} does not represent the actual argument, but
       rather an additional piece of information like an array length or a type
       tag.  In this case, @samp{formalPars[@var{j}]} with @var{j} being the
       largest index with @samp{@var{j} < @var{i}} and
       @samp{formalPars[@var{j}] # NIL}, holds the matching formal parameter.  *)
  END;

TYPE
  CopyParameter* = POINTER TO CopyParameterDesc;
  CopyParameterDesc = RECORD
    (**Used to create local copies of value parameters that are passed to
       the callee as references.  This statement allocates the space for a
       local copy of the parameter, and initializes it with the actual
       value of the argument.  *)
    (StatementDesc)
    
    param-: Var;
    (**The value parameter that must be copied.  *)
  END;
  
TYPE
  Exit* = POINTER TO ExitDesc;
  ExitDesc* = RECORD
    (**Exit statement.  *)
    (StatementDesc)
    loop-: LoopStatm;
  END;
  
TYPE
  ForStatm* = POINTER TO ForStatmDesc;
  ForStatmDesc = RECORD
    (**Holds an @code{FOR-BY} statement.  *)
    (StatementDesc)
    var-: Expression;
    start-, end-: Expression;
    step-: Expression;
    body-: StatementSeq;
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
    isWithClause-: BOOLEAN;
    (**If @code{TRUE}, then this statement was derived from a @code{WITH}
       statement.  In this case, @ofield{guard} is a type test, and the guard
       asserts that the tested variable is of the right hand side type across
       the whole region of @ofield{pathTrue}.  *)
  END;

TYPE
  Case* = POINTER TO CaseDesc;
  CaseLabels* = POINTER TO ARRAY OF Expression;
  CaseDesc = RECORD
    (StatementDesc)
    labels-:  CaseLabels;
    statmSeq-: StatementSeq;
  END;
  
TYPE
  CaseStatm* = POINTER TO CaseStatmDesc;
  CaseList* = POINTER TO ARRAY OF Case;
  CaseStatmDesc = RECORD
    (**Holds a @code{CASE} statement.  If there is no @code{ELSE}, then
       @ofield{default} is @code{NIL}.  *)
    (StatementDesc)
    select-: Expression;
    caseList-: CaseList;
    default-: StatementSeq;  (* NIL if the CASE statement has no ELSE *)
  END;
  
TYPE
  LoopStatmDesc = RECORD
    (**Holds an @code{LOOP-END} statement.  *)
    (StatementDesc)
    body-: StatementSeq;
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
    moduleBody-: Procedure;  (* holds statements in body, never NIL *)
  END;

TYPE
  TypeType* = POINTER TO TypeTypeDesc;
  TypeTypeDesc = RECORD
    (**This special type is assigned to expressions that evaluate to a type.
       For example, the type of the right hand side of @samp{x IS T} is an
       instance of this class.  *)
    (Sym.TypeDesc)
  END;
  
TYPE
  Builder* = POINTER TO BuilderDesc;
  ConstFold* = POINTER TO ConstFoldDesc;
  BuilderDesc* = RECORD
    pragmaHistory: Pragmas.History;
    errList: Error.List;
    constFold- : ConstFold;
    
    typeRules- : TypeRules.Rules;
    
    errorExpr-: Const;
    (**This value is returned if there is no real value because of an error.
       For example, if an identifier cannot be resolved, or if a designator
       does not begin with an identifier, then this value is passed to the
       caller.  Within the IR, no other value is used to indicate illegal
       operations.

       @strong{Note}: A function can @emph{only} return this value for a node,
       if it also emits an error message.  *)

    typeType-: TypeType;
    (**This type is assigned to expressions that produce a type value.  *)
    
    lastError: Error.Msg;
    (* Holds the last error message produced by @oproc{Builder.ErrSym}.  *)
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


CONST
  undeclaredIdent = 1;
  expectedIdent = 2;
  numberOutOfRange = 3;
  characterOutOfRange = 4;
  invalidOpType = 5;
  (** types of operands are not allowed for this operator *)
  unknownOp* = 6;
  (** symbol is not an operator *)
  incompatibleTypes* = 7;
  (** types of operands are not equivalent as required by operator *)
  divideByZero* = 8;
  exprNotConstant = 9;
  rangeError* = 10;
  exprByRef = 11;
  incompatibleActualParam = 12;
  wrongNumberOfArguments = 13;
  invalidIntegerConst = 14;
  notArray = 15;
  notTypeExpression = 16;
  notExtensionOfLHS = 17;
  noMinMax = 18;
  
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
    | wrongNumberOfArguments:
      t := "Wrong number of arguments"
    | invalidIntegerConst:
      t := "Integer constant in the range `${start} <= x < ${end}' required"
    | notArray:
      t := "First argument of LEN must be an array designator"
    | notTypeExpression:
      t := "Type name expected"
    | notExtensionOfLHS:
      t := "Type must be an extension of the left operand's type"
    | noMinMax:
      t := "MIN/MAX is not applicable to this type"
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
    e: Error.Msg;
  BEGIN
    e := Error.New (irContext, code);
    IF (sym # b. errorExpr. sym) THEN    (* discard stacked followup errors *)
      e. SetIntAttrib ("pos", sym. pos);
      e. SetIntAttrib ("line", sym. line);
      e. SetIntAttrib ("column", sym. column);
      b. errList. Append (e);
    END;
    b. lastError := e;
  END ErrSym;

PROCEDURE (b : Builder) ErrExpr* (code : Error.Code; sym : Symbol) : Const;
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

PROCEDURE (b: Builder) AssertType* (expr: Expression): Sym.Type;
(**Generates an error if @oparam{expr} is not a type name.  In this case,
   result is @code{NIL}.  Otherwise, the type to which the expression refers is
   returned.  *)
  BEGIN
    WITH expr: TypeRef DO
      RETURN expr. decl(Sym.TypeDecl). type;
    ELSE  (* not a type: report error *)
      b. ErrSym (notTypeExpression, expr. sym);
      RETURN expr. type;
    END;
  END AssertType;

PROCEDURE (b : Builder) Fold* (expr : Expression) : Expression;
BEGIN
  RETURN b.constFold.TryConstFold(expr);
END Fold;

PROCEDURE IsPredefType(type : Sym.Type; id : Sym.PredefId) : BOOLEAN;
BEGIN
  RETURN (type IS Sym.PredefType) & (type(Sym.PredefType).id = id);
END IsPredefType;

PROCEDURE CheckExit (statmSeq: StatementSeq; currentLoop: LoopStatm);
  VAR
    i: LONGINT;

  PROCEDURE CheckStatm (statm: Statement);
    VAR
      i: LONGINT;
    BEGIN
      WITH statm: Assert DO
        (* nothing *)
      | statm: Assignment DO             (* this includes AssignOp *)
        (* nothing *)
      | statm: Call DO
        (* nothing *)
      | statm: CopyParameter DO
        (* nothing *)
      | statm: Exit DO
        ASSERT (currentLoop # NIL);      (* FIXME... report error *)
        statm. loop := currentLoop;
      | statm: ForStatm DO
        CheckExit (statm. body, currentLoop);
      | statm: IfStatm DO
        CheckExit (statm. pathTrue, currentLoop);
        CheckExit (statm. pathFalse, currentLoop);
      | statm: Case DO
        CheckExit (statm. statmSeq, currentLoop);
      | statm: CaseStatm DO
        FOR i := 0 TO LEN (statm. caseList^)-1 DO
          CheckExit (statm. caseList[i]. statmSeq, currentLoop);
        END;
        CheckExit (statm. default, currentLoop);
      | statm: LoopStatm DO
        CheckExit (statm. body, statm);
      | statm: RepeatStatm DO
        CheckExit (statm. body, currentLoop);
      | statm: Return DO
        (* nothing *)
      | statm: WhileStatm DO
        CheckExit (statm. body, currentLoop);
      END;
    END CheckStatm;
  
  BEGIN
    IF (statmSeq # NIL) THEN
      FOR i := 0 TO LEN (statmSeq^)-1 DO
        CheckStatm (statmSeq[i])
      END;
    END;
  END CheckExit;

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
    ASSERT (type # NIL);
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

PROCEDURE (const: Const) ToString*(): String.String;
  BEGIN
    IF (const. value = NIL) THEN
      RETURN String.New ("NIL");
    ELSE
      RETURN const. value. ToString();
    END;
  END ToString;

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

PROCEDURE (b: Builder) NewRealConst* (sym: Symbol): Expression;
  VAR
    v: Language.Value;
  BEGIN
    v := Real.type. ValueOf (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (numberOutOfRange, sym);
      RETURN b. errorExpr
    ELSE
      RETURN NewConst (sym, Predef.GetType (Predef.real), v)
    END
  END NewRealConst;

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

PROCEDURE (b: Builder) NewNil* (sym: Symbol): Expression;
  BEGIN
    RETURN NewConst (sym, Predef.GetType (Predef.char), NIL);
  END NewNil;

PROCEDURE (b: Builder) NewSize* (sym: Symbol; type: Expression): Expression;
  BEGIN
    ASSERT (type IS TypeRef);
    RETURN b. NewConst
        (sym, Predef.GetType (Predef.longint),
         Integer.NewLInt (type(TypeRef). decl(Sym.TypeDecl). type. size));
  END NewSize;

PROCEDURE (b: Builder) GetOne (sym: Symbol; type: Sym.Type): Const;
  BEGIN
    RETURN b. NewConst (sym, type, Integer.NewLInt (1));
  END GetOne;

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
    op : BinaryArith;
  BEGIN
    NEW (op);
    ASSERT(b.typeRules.SameType(left.type, right.type));
    InitBinaryArith (op, sym, variant, left, right, left.type);
    RETURN op;
  END NewBinaryArith;

PROCEDURE (v: Visitor) [ABSTRACT] VisitBinaryArith* (op: BinaryArith);
  END VisitBinaryArith;

PROCEDURE (op: BinaryArith) Accept* (v: Visitor);
  BEGIN
    v. VisitBinaryArith (op)
  END Accept;

(* Operator Class: BooleanOp
   ------------------------------------------------------------------------ *)

PROCEDURE InitBooleanOp (op: BooleanOp; sym: Symbol; variant : Variant; left, right: Expression; type : Sym.Type);
  BEGIN
    InitOperator (op, sym, type);
    op.variant := variant;
    op.left := left;
    op.right := right;
  END InitBooleanOp;

PROCEDURE (b: Builder) NewBooleanOp (sym: Symbol; variant: Variant; left, right: Expression): Expression;
  VAR
    op : BooleanOp;
  BEGIN
    NEW (op);
    ASSERT (left. type(Sym.PredefType). id = Predef.boolean);
    ASSERT (right. type(Sym.PredefType). id = Predef.boolean);
    InitBooleanOp (op, sym, variant, left, right, left.type);
    RETURN op;
  END NewBooleanOp;

PROCEDURE (v: Visitor) [ABSTRACT] VisitBooleanOp* (op: BooleanOp);
  END VisitBooleanOp;

PROCEDURE (op: BooleanOp) Accept* (v: Visitor);
  BEGIN
    v. VisitBooleanOp (op)
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
    | Id.eql:  variant := equal;
    | Id.neq:  variant := notEqual;
    | Id.lss:  variant := less;
    | Id.leq:  variant := lessEqual;
    | Id.gtr:  variant := greater;
    | Id.geq:  variant := greaterEqual;
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

(* Operator Class: Deref
   ------------------------------------------------------------------------ *)

PROCEDURE InitDeref (d: Deref; sym: Symbol; pointer: Expression);
  BEGIN
    InitOperator (d, sym, pointer. type(Sym.Pointer). baseType);
    d. pointer := pointer;
    d. derefType := pointer. type(Sym.Pointer). baseType;
    ASSERT ((d. derefType IS Sym.Record) OR (d. derefType IS Sym.Array));
  END InitDeref;

PROCEDURE (b: Builder) NewDeref* (sym: Symbol; design: Expression): Expression;
  VAR
    i: Deref;
  BEGIN
    WITH design: SelectProc DO (* super call of type-bound procedure *)
      (* FIXME... check that we are in a redefinition; make sure that "^"
         cannot be stacked ;-) *)
      design. tbProc := design. recordType. ns(Namespace.Extended).
          GetSuperProcByIndex (design. tbProc. tbProcIndex);
      design. type := design. tbProc. formalPars;
      design. isStaticCall := TRUE;
      RETURN design;
    ELSE
      NEW (i);
      InitDeref (i, sym, design);
      RETURN i
    END;
  END NewDeref;

PROCEDURE (v: Visitor) [ABSTRACT] VisitDeref* (index: Deref);
  END VisitDeref;

PROCEDURE (index: Deref) Accept* (v: Visitor);
  BEGIN
    v. VisitDeref (index)
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
    IF (array. type IS Sym.Pointer) THEN
      array := b. NewDeref (sym, array);
    END;
    
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
                   array, arrayVariable: Expression; dim: LONGINT);
  BEGIN
    InitOperator (len, sym, Predef.GetType (Predef.lengthType));
    len. variant := variant;
    len. array := array;
    len. arrayVariable := arrayVariable;
    len. dim := dim;
  END InitLen;

PROCEDURE (b: Builder) NewLen* (sym: Symbol; array: Expression;
                                dim: LONGINT): Expression;
  VAR
    len: Len;
    variant: Variant;
    arrayVariable: Expression;
  BEGIN
    NEW (len);

    arrayVariable := array;
    WHILE (arrayVariable IS Index) DO
      arrayVariable := arrayVariable(Index). array;
      INC (dim);
    END;
    
    IF (arrayVariable. type IS Sym.PredefType) THEN
      variant := lenStringConst
    ELSIF (arrayVariable. type IS Sym.Array) &
          (dim >= arrayVariable. type(Sym.Array). GetOpenDimensions()) THEN
      variant := lenFixedArray
    ELSIF (arrayVariable IS Var) THEN
      variant := lenOpenArrayParam
    ELSE
      variant := lenOpenArrayHeap
    END;

    InitLen (len, sym, variant, array, arrayVariable, dim);
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

(* Operator Class: NewObject
   ------------------------------------------------------------------------ *)

PROCEDURE InitNewObject (new: NewObject; sym: Symbol; type: Sym.Type;
                        length: ExpressionList);
  BEGIN
    InitOperator (new, sym, type);
    new. length := length;
  END InitNewObject;

PROCEDURE (b: Builder) NewNewObject (sym: Symbol; type: Sym.Type;
                                     args: ExpressionList): Expression;
  VAR
    new: NewObject;
    length: ExpressionList;
    i: LONGINT;
  BEGIN
    IF (args = NIL) THEN
      length := NIL;
    ELSE
      NEW (length, LEN (args^)-1);
      FOR i := 0 TO LEN (length^)-1 DO
        length[i] := args[i+1];
      END;
    END;
    
    NEW (new);
    InitNewObject (new, sym, type, length);
    RETURN new;
  END NewNewObject;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNewObject* (new: NewObject);
  END VisitNewObject;

PROCEDURE (new: NewObject) Accept* (v: Visitor);
  BEGIN
    v. VisitNewObject (new)
  END Accept;

(* Operator Class: SelectField
   ------------------------------------------------------------------------ *)

PROCEDURE InitSelectField (sf: SelectField; sym: Symbol; record: Expression; field: Sym.FieldDecl);
  BEGIN
    InitOperator (sf, sym, field. type);
    sf.record := record;
    sf.field := field;
  END InitSelectField;

PROCEDURE (b: Builder) NewSelectField (sym: Symbol; record: Expression; field: Sym.FieldDecl): SelectField;
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

(* Operator Class: SelectProc
   ------------------------------------------------------------------------ *)

PROCEDURE InitSelectProc (sp: SelectProc; sym: Symbol; receiver: Expression;
                          recordType: Sym.Record;
                          tbProc: Sym.ProcDecl; isStaticCall: BOOLEAN);
  BEGIN
    InitOperator (sp, sym, tbProc. formalPars);
    sp. receiver := receiver;
    sp. recordType := recordType;
    sp. tbProc := tbProc;
    sp. isStaticCall := isStaticCall;
  END InitSelectProc;

PROCEDURE (b: Builder) NewSelectProc (sym: Symbol; receiver: Expression;
                                      recordType: Sym.Record;
                                      tbProc: Sym.ProcDecl;
                                      isStaticCall: BOOLEAN): SelectProc;
  VAR
    i: SelectProc;
  BEGIN
    NEW (i);
    InitSelectProc (i, sym, receiver, recordType, tbProc, isStaticCall);
    RETURN i
  END NewSelectProc;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSelectProc* (sp: SelectProc);
  END VisitSelectProc;

PROCEDURE (sp: SelectProc) Accept* (v: Visitor);
  BEGIN
    v. VisitSelectProc (sp)
  END Accept;

(* Operator Class: SetMember
   ------------------------------------------------------------------------ *)

PROCEDURE InitSetMember (op: SetMember; sym: Symbol; element, set : Expression);
  BEGIN
    InitOperator (op, sym, Predef.GetType(Predef.boolean));
    op.element := element;
    op.set := set;
  END InitSetMember;

PROCEDURE (b: Builder) NewSetMember* (sym: Symbol; element, set : Expression): Expression;
  VAR
    op : SetMember;
  BEGIN
    NEW (op);
    InitSetMember (op, sym, element, set);
    RETURN op;
  END NewSetMember;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSetMember* (op: SetMember);
  END VisitSetMember;

PROCEDURE (op: SetMember) Accept* (v: Visitor);
  BEGIN
    v. VisitSetMember (op)
  END Accept;

(* Operator Class: SetOp
   ------------------------------------------------------------------------ *)

PROCEDURE InitSetOp (op: SetOp; sym: Symbol; variant : Variant; left, right: Expression; type : Sym.Type);
  BEGIN
    InitOperator (op, sym, type);
    op.variant := variant;
    op.left := left;
    op.right := right;
  END InitSetOp;

PROCEDURE (b: Builder) NewSetOp* (sym: Symbol; variant: Variant; left, right: Expression): Expression;
  VAR
    op : SetOp;
  BEGIN
    NEW (op);
    ASSERT(b.typeRules.SameType(left.type, right.type));
    InitSetOp (op, sym, variant, left, right, left.type);
    RETURN op;
  END NewSetOp;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSetOp* (op: SetOp);
  END VisitSetOp;

PROCEDURE (op: SetOp) Accept* (v: Visitor);
  BEGIN
    v. VisitSetOp (op)
  END Accept;

(* Operator Class: SetRange
   ------------------------------------------------------------------------ *)

PROCEDURE InitSetRange (range: SetRange; sym: Symbol;
                        from, to : Expression);
  BEGIN
    InitOperator (range, sym, from.type);
    range.from := from;
    range.to := to;
  END InitSetRange;

PROCEDURE (b: Builder) NewSetRange* (sym: Symbol; from, to : Expression) : SetRange;
  VAR
    range: SetRange;
  BEGIN
    NEW (range);
    InitSetRange (range, sym, from, to);
    RETURN range
  END NewSetRange;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSetRange* (range: SetRange);
  END VisitSetRange;

PROCEDURE (range: SetRange) Accept* (v: Visitor);
  BEGIN
    v. VisitSetRange (range)
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

(* Operator Class: TypeTag
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeTag (tag: TypeTag; sym: Symbol; design: Expression);
  BEGIN
    InitOperator (tag, sym, Predef.GetType(Predef.address));
    tag. design := design;
  END InitTypeTag;

PROCEDURE (b: Builder) NewTypeTag (sym: Symbol; design: Expression): Expression;
  VAR
    tag: TypeTag;
  BEGIN
    NEW (tag);
    InitTypeTag (tag, sym, design);
    RETURN tag;
  END NewTypeTag;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeTag* (tag: TypeTag);
  END VisitTypeTag;

PROCEDURE (tag: TypeTag) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeTag (tag)
  END Accept;

(* Operator Class: TypeTest
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeTest (test: TypeTest; sym: Symbol;
                        expr: Expression; referenceType: Sym.Record;
                        origExpr: Expression; origType: TypeRef);
  BEGIN
    InitOperator (test, sym, Predef.GetType(Predef.boolean));
    test. expr := expr;
    test. referenceType := referenceType;
    test. origExpr := origExpr;
    test. origType := origType;
  END InitTypeTest;

PROCEDURE (b: Builder) NewTypeTest* (sym: Symbol; expr, referenceType: Expression): Expression;
  VAR
    test: TypeTest;
    refType: Sym.Type;
    origExpr: Expression;
  BEGIN
    refType := b. AssertType (referenceType);
    IF (refType = NIL) THEN
      RETURN b. errorExpr;
    ELSIF ~b. typeRules. IsExtensionOf (refType, expr. type) THEN
      RETURN b. ErrExpr (notExtensionOfLHS, referenceType. sym);
    ELSE
      origExpr := expr;
      IF (expr IS Deref) THEN
        expr := expr(Deref). pointer;
      ELSIF (expr. type IS Sym.Pointer) THEN
        refType := refType(Sym.Pointer). baseType;
      END;
      NEW (test);
      InitTypeTest (test, sym, expr, refType(Sym.Record),
                    origExpr, referenceType(TypeRef));
      RETURN test;
    END;
  END NewTypeTest;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeTest* (test: TypeTest);
  END VisitTypeTest;

PROCEDURE (test: TypeTest) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeTest (test)
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

PROCEDURE InitTypeRef (typeRef: TypeRef; name: Symbol; type: Sym.Type;
                       decl: Sym.TypeDecl);
  BEGIN
    InitReference (typeRef, name, type, decl);
  END InitTypeRef;

PROCEDURE (b: Builder) NewTypeRef (name: Symbol; decl: Sym.TypeDecl): TypeRef;
  VAR
    typeRef: TypeRef;
  BEGIN
    NEW (typeRef);
    InitTypeRef (typeRef, name, b. typeType, decl);
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

PROCEDURE InitCall (call: Call; design: Expression; arguments: ExpressionList;
                    formalPars: Sym.VarDeclArray);
  BEGIN
    InitStatement (call, design. sym);
    IF (design. type(Sym.FormalPars). resultType # NIL) THEN
      (* fix result type for function calls *)
      call. type := design. type(Sym.FormalPars). resultType
    END;
    call. design := design;
    call. arguments := arguments;
    call. formalPars := formalPars;
  END InitCall;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCall* (call: Call);
  END VisitCall;

PROCEDURE (call: Call) Accept* (v: Visitor);
  BEGIN
    v. VisitCall (call)
  END Accept;

(* Statement Class: CopyParameter
   ------------------------------------------------------------------------ *)

PROCEDURE InitCopyParameter (cp: CopyParameter; sym: Symbol; param: Var);
  BEGIN
    InitStatement (cp, sym);
    cp. param := param;
  END InitCopyParameter;

PROCEDURE (b: Builder) NewCopyParameter* (sym: Symbol; param: Var): CopyParameter;
  VAR
    cp: CopyParameter;
  BEGIN
    NEW (cp);
    InitCopyParameter (cp, sym, param);
    RETURN cp
  END NewCopyParameter;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCopyParameter* (cp: CopyParameter);
  END VisitCopyParameter;

PROCEDURE (cp: CopyParameter) Accept* (v: Visitor);
  BEGIN
    v. VisitCopyParameter (cp)
  END Accept;

(* Statement Class: Exit
   ------------------------------------------------------------------------ *)

PROCEDURE InitExit* (exit: Exit; sym: Symbol);
  BEGIN
    InitStatement (exit, sym);
    exit. loop := NIL;
  END InitExit;

PROCEDURE (b: Builder) NewExit* (sym: Symbol): Exit;
  VAR
    exit: Exit;
  BEGIN
    NEW (exit);
    InitExit (exit, sym);
    RETURN exit
  END NewExit;

PROCEDURE (v: Visitor) [ABSTRACT] VisitExit* (exit: Exit);
  END VisitExit;

PROCEDURE (exit: Exit) Accept* (v: Visitor);
  BEGIN
    v. VisitExit (exit)
  END Accept;

(* Statement Class: ForStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitForStatm (forStatm: ForStatm; sym: Symbol;
                        var, start, end, step: Expression;
                        body: StatementSeq);
  BEGIN
    InitStatement (forStatm, sym);
    forStatm. var := var;
    forStatm. start := start;
    forStatm. end := end;
    forStatm. step := step;
    forStatm. body := body;
  END InitForStatm;

PROCEDURE (b: Builder) NewForStatm* (sym: Symbol;
                                     var, start, end, step: Expression;
                                     body: StatementSeq):ForStatm;
  VAR
    forStatm: ForStatm;
  BEGIN
    NEW (forStatm);
    IF (step = NIL) THEN
      step := b. NewConst
          (sym, Predef.GetType (Predef.shortint), Integer.NewLInt (1));
    END;
    InitForStatm (forStatm, sym, var, start, end, step, body);
    RETURN forStatm
  END NewForStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitForStatm* (forStatm: ForStatm);
  END VisitForStatm;

PROCEDURE (forStatm: ForStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitForStatm (forStatm)
  END Accept;

(* Statement Class: IfStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitIfStatm (ifStatm: IfStatm; sym: Symbol; guard: Expression;
                       pathTrue, pathFalse: StatementSeq;
                       isWithClause: BOOLEAN);
  BEGIN
    InitStatement (ifStatm, sym);
    ifStatm. guard := guard;
    ifStatm. pathTrue := pathTrue;
    ifStatm. pathFalse := pathFalse;
    ifStatm. isWithClause := isWithClause;
  END InitIfStatm;

PROCEDURE (b: Builder) NewIfStatm* (sym: Symbol; guard: Expression;
                                    pathTrue, pathFalse: StatementSeq;
                                    isWithClause: BOOLEAN): IfStatm;
  VAR
    ifStatm: IfStatm;
  BEGIN
    NEW (ifStatm);
    InitIfStatm (ifStatm, sym, guard, pathTrue, pathFalse, isWithClause);
    RETURN ifStatm
  END NewIfStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitIfStatm* (ifStatm: IfStatm);
  END VisitIfStatm;

PROCEDURE (ifStatm: IfStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitIfStatm (ifStatm)
  END Accept;

(* Statement Class: Case
   ------------------------------------------------------------------------ *)

PROCEDURE InitCase (case: Case; sym: Symbol; labels: CaseLabels;
                    statmSeq: StatementSeq);
  BEGIN
    InitStatement (case, sym);
    case. labels := labels;
    case. statmSeq := statmSeq;
  END InitCase;

PROCEDURE (b: Builder) NewCase* (sym: Symbol; labels: CaseLabels;
                                 statmSeq: StatementSeq): Case;
  VAR
    case: Case;
  BEGIN
    NEW (case);
    InitCase (case, sym, labels, statmSeq);
    RETURN case
  END NewCase;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCase* (case: Case);
  END VisitCase;

PROCEDURE (case: Case) Accept* (v: Visitor);
  BEGIN
    v. VisitCase (case)
  END Accept;

(* Statement Class: CaseStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitCaseStatm (caseStatm: CaseStatm; sym: Symbol; select: Expression;
                         caseList: CaseList; default: StatementSeq);
  BEGIN
    InitStatement (caseStatm, sym);
    caseStatm. select := select;
    caseStatm. caseList := caseList;
    caseStatm. default := default;
  END InitCaseStatm;

PROCEDURE (b: Builder) NewCaseStatm* (sym: Symbol; select: Expression;
                                      caseList: CaseList; default: StatementSeq): CaseStatm;
  VAR
    caseStatm: CaseStatm;
  BEGIN
    NEW (caseStatm);
    InitCaseStatm (caseStatm, sym, select, caseList, default);
    RETURN caseStatm
  END NewCaseStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCaseStatm* (caseStatm: CaseStatm);
  END VisitCaseStatm;

PROCEDURE (caseStatm: CaseStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitCaseStatm (caseStatm)
  END Accept;

(* Statement Class: LoopStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitLoopStatm (loopStatm: LoopStatm; sym: Symbol;
                         body: StatementSeq);
  BEGIN
    InitStatement (loopStatm, sym);
    loopStatm. body := body;
  END InitLoopStatm;

PROCEDURE (b: Builder) NewLoopStatm* (sym: Symbol;
                                      body: StatementSeq):LoopStatm;
  VAR
    loopStatm: LoopStatm;
  BEGIN
    NEW (loopStatm);
    InitLoopStatm (loopStatm, sym, body);
    RETURN loopStatm
  END NewLoopStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitLoopStatm* (loopStatm: LoopStatm);
  END VisitLoopStatm;

PROCEDURE (loopStatm: LoopStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitLoopStatm (loopStatm)
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
      fparIndex: LONGINT;
      fpar: Sym.VarDecl;
      
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
          AddStatm (b. NewCopyParameter (sym, b. NewVar (NIL, fpar)))
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
    CheckExit (statmSeq, NIL);
    
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

PROCEDURE InitModule* (m: Module; sym: Symbol; name: Name;
                       procList: ProcedureList; moduleBody: Procedure);
  BEGIN
    InitNode (m, sym);
    m. name := name;
    m. procList := procList;
    m. moduleBody := moduleBody;
  END InitModule;

PROCEDURE (b: Builder) NewModule* (sym: Symbol; name: Name; decl: Sym.Module;
                                   procList: ProcedureList;
                                   statmSeq: StatementSeq): Module;
  VAR
    m: Module;
  BEGIN
    CheckExit (statmSeq, NIL);
    
    NEW (m);
    InitModule (m, sym, name, procList,
                b. NewProcedure (sym, decl. bodyDecl, statmSeq));
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
  
  PROCEDURE NewTypeType (parent: Sym.Item; position: Sym.Position): TypeType;
    VAR
      typeType: TypeType;
    BEGIN
      NEW (typeType);
      Sym.InitType (typeType, parent, position);
      RETURN typeType;
    END NewTypeType;
  
  BEGIN
    b. pragmaHistory := pragmaHistory;
    b. errList := errList;
    b. typeRules := typeRules;
    b. errorExpr := NewConst (BasicList.NewSymbol (NIL, -1),
                              Predef.GetType(Predef.void),
                              Boolean.New (FALSE));
    b. typeType := NewTypeType (NIL, NIL);
    b. lastError := NIL;
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


PROCEDURE (b: Builder) StartTypeGuard* (typeTest: TypeTest): Sym.Type;
  VAR
    var: Sym.VarDecl;
    type: Sym.TypeDecl;
    oldType: Sym.Type;
  BEGIN
    var := typeTest. expr(Var). decl(Sym.VarDecl);
    type := typeTest. origType. decl(Sym.TypeDecl);
    oldType := var. type;
    var. SetType (type. type);
    RETURN oldType;
  END StartTypeGuard;

PROCEDURE (b: Builder) EndTypeGuard* (typeTest: TypeTest; oldType: Sym.Type);
  BEGIN
    typeTest. expr(Var). decl(Sym.VarDecl). SetType (oldType);
  END EndTypeGuard;

PROCEDURE (b: Builder) NewIdentRef* (ns: Sym.Namespace; context: Sym.Item; 
                                     name: Symbol): Expression;
  VAR
    decl: Sym.Declaration;
  BEGIN
    IF (name. id = Id.ident) THEN
      decl := ns. Identify (context, b. GetName (name), FALSE);
      IF (decl = NIL) THEN
        b. ErrSym (undeclaredIdent, name)
      ELSE
        WITH decl: Sym.ConstDecl DO
          RETURN NewConst (name, decl. type, decl. value)
        | decl: Sym.VarDecl DO
          RETURN b. NewVar (name, decl)
        | decl: Sym.TypeDecl DO
          RETURN b. NewTypeRef (name, decl)
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
  VAR
    varRef: Expression;
    decl: Sym.Declaration;
  BEGIN
    IF (var. type IS Sym.Pointer) THEN
      varRef := b. NewDeref (sym, var);
    ELSE
      varRef := var;
    END;
    ASSERT (varRef. type IS Sym.Record);
    decl := varRef. type(Sym.Record). ns. Identify
        (context, b. GetName (name), FALSE);
    (* FIXME... add error checks *)
    IF (decl IS Sym.FieldDecl) THEN
      RETURN b. NewSelectField (sym, varRef, decl(Sym.FieldDecl));
    ELSIF (decl IS Sym.ProcDecl) THEN
      RETURN b. NewSelectProc (sym, var, varRef. type(Sym.Record),
                               decl(Sym.ProcDecl), FALSE);
    ELSE
      ASSERT (FALSE);
    END;
  END NewSelect;

PROCEDURE (b: Builder) NewOperator* (sym: Symbol; left, right: Expression): Expression;
(**Return an IR expression for the given symbol and left/right expressions.
   This procedure handles operator polymorphism, mapping an operator symbol to
   different operations according to the type of its operands. This procedure
   implements the rules defined for "Expression Compatible" in Appendix A of
   the Oberon-2 language report.

   This procedure returns an operator, or the value errorExpr. If the given
   symbol is not a recognised operator, an unknownOp error is signalled. If the
   types of the arguments are not valid for the given operator, an
   invalidOpType error is signalled.  

   Error reporting could probably be improved...
   *)

  VAR
    tr : TypeRules.Rules;
    id : Id.Id;

  PROCEDURE IsPredefClass(type : Sym.Type; classes : SET) : BOOLEAN;
  BEGIN
    WITH type : Sym.PredefType DO
      RETURN type.id IN classes;
    ELSE
      RETURN FALSE;
    END;
  END IsPredefClass;

  PROCEDURE UnaryOperator() : Expression;
  VAR 
    isNumeric, isSet, isBoolean : BOOLEAN;
    type : Sym.Type;
  BEGIN
    type := right.type;
    isNumeric := tr.IsNumericType(type);
    isSet := tr.IsSetType(type);
    isBoolean := IsPredefClass(type, {Predef.boolean});

    CASE id OF
    | Id.minus:
      IF isNumeric THEN
        RETURN b.NewNegate(sym, right);
      ELSIF isSet THEN
        (* for now, map set/numeric negation onto Negate operator *)
        RETURN b.NewNegate(sym, right);
      ELSE
        RETURN b.ErrExpr(invalidOpType, sym);
      END
    | Id.plus:
      IF isNumeric THEN 
        RETURN right;
      ELSE
        RETURN b.ErrExpr(invalidOpType, sym);
      END
    | Id.not:
      (* for now, map logical negation onto Negate operator *)
      IF isBoolean THEN
        RETURN b.NewNegate(sym, right);
      ELSE
        RETURN b.ErrExpr(invalidOpType, sym);
      END
    ELSE
      RETURN b.ErrExpr(unknownOp, sym);
    END;
  END UnaryOperator;

  PROCEDURE BinaryOperator() : Expression;
  VAR 
    result : Expression;
    variant : Variant;
    leftType, rightType : Sym.Type;
    leftIsNumeric, leftIsSet, leftIsInteger, leftIsBoolean, 
    leftIsChar, leftIsString : BOOLEAN;
    rightIsNumeric, rightIsSet, rightIsInteger, rightIsBoolean, 
    rightIsChar, rightIsString : BOOLEAN;

    PROCEDURE WidenType();
    (**This procedure adjusts the expressions to that they have the smallest
       type that includes both types. A type conversion operator is used where
       required.

       PRE: types of left and right are the same, or one includes the other. 
       POST: types of left and right are the same *)
    BEGIN
      IF tr.SameType(leftType, rightType) THEN
        (* do nothing *)
      ELSIF tr.IncludesType(leftType, rightType) THEN
        right := NewTypeConv(leftType, right);
      ELSIF tr.IncludesType(rightType, leftType) THEN
        left := NewTypeConv(rightType, left);
      ELSE
        ASSERT(FALSE);   (* we made a mistake in BinaryOperator *)
      END;
    END WidenType;

  BEGIN
    leftType := left.type; 
    leftIsNumeric := tr.IsNumericType(leftType);
    leftIsInteger := tr.IsIntegerType(leftType);
    leftIsSet := tr.IsSetType(leftType);
    leftIsBoolean := IsPredefClass(leftType, {Predef.boolean});
    leftIsChar := tr.IsCharType(leftType);
    leftIsString := IsPredefClass(leftType, {Predef.charString});

    rightType := right.type; 
    rightIsNumeric := tr.IsNumericType(rightType);
    rightIsInteger := tr.IsIntegerType(rightType);
    rightIsSet := tr.IsSetType(rightType);
    rightIsBoolean := IsPredefClass(rightType, {Predef.boolean});
    rightIsChar := tr.IsCharType(rightType);
    rightIsString := IsPredefClass(rightType, {Predef.charString});

    result := NIL;  (* FIXME. keep the compiler happy until ASSERTs are removed *)
    IF (id IN {Id.plus, Id.minus, Id.times})
      & leftIsNumeric & rightIsNumeric THEN
      (* ---- arithmetic operator ---- *)
      CASE id OF
      | Id.plus: variant := arithAdd;
      | Id.minus: variant := arithSub;
      | Id.times: variant := arithMul;
      END;
      WidenType();
      result := b.NewBinaryArith(sym, variant, left, right);

    ELSIF (id IN {Id.slash }) & leftIsNumeric & rightIsNumeric THEN
      (* ---- arithmetic real division ---- *)
      IF leftIsInteger & rightIsInteger THEN
        left := NewTypeConv(Predef.GetType(Predef.real), left);
        right := NewTypeConv(Predef.GetType(Predef.real), right);
      ELSE
        WidenType();
      END;
      result := b.NewBinaryArith(sym, arithDivR, left, right);

    ELSIF (id IN {Id.div, Id.mod}) & leftIsInteger & rightIsInteger THEN
      (* ---- arithmetic integer division/modulus ---- *)
      CASE id OF
      | Id.div: variant := arithDivI;
      | Id.mod: variant := arithMod;
      END;
      WidenType();
      result := b.NewBinaryArith(sym, variant, left, right)

    ELSIF (id IN {Id.plus, Id.minus, Id.times, Id.slash})
      & leftIsSet & rightIsSet THEN
      (* ---- set operator ---- *)
      CASE id OF
      | Id.plus: variant := setUnion;
      | Id.minus: variant := setDiff;
      | Id.times: variant := setIntersect;
      | Id.slash: variant := setSymDiff
      END;
      WidenType();
      RETURN b.NewSetOp(sym, variant, left, right);

    ELSIF (id IN {Id.and, Id.or}) & leftIsBoolean & rightIsBoolean THEN
      CASE id OF
      | Id.and: variant := and;
      | Id.or: variant := or;
      END;
      result := b.NewBooleanOp(sym, variant, left, right);

    ELSIF (id IN {Id.eql, Id.neq, Id.lss, Id.leq, Id.gtr, Id.geq})
      & ((leftIsNumeric & rightIsNumeric) OR (leftIsChar & rightIsChar)) THEN
      WidenType();
      result := b.NewCompare(sym, left, right);

    ELSIF (id IN {Id.eql, Id.neq, Id.lss, Id.leq, Id.gtr, Id.geq})
      & (leftIsString & rightIsString) THEN
      (* FIXME... handle char array., string *)
      result := b.NewCompare(sym, left, right);
    ELSIF (id IN {Id.eql, Id.neq})
      & ((leftIsBoolean & rightIsBoolean) OR (leftIsSet & rightIsSet)) THEN
      (* FIXME... handle pointer types, procedure types *)
      result := b.NewCompare(sym, left, right);
    ELSIF (id = Id.in) & leftIsInteger & rightIsSet THEN
      result := b.NewSetMember(sym, left, right);
    ELSIF (id = Id.is) THEN
      result := b.NewTypeTest(sym, left, right);
    ELSE
      result := b.ErrExpr(invalidOpType, sym);
    END;
    RETURN result;
  END BinaryOperator;

  BEGIN
    id := sym.id;
    tr := b.typeRules;

    IF left = NIL THEN 
      RETURN UnaryOperator();
    ELSE
      RETURN BinaryOperator();
    END;
  END NewOperator;

PROCEDURE (b: Builder) AssertConst* (expr: Expression): Const;
(**Generates an error if @oparam{expr} is not a constant.  In this case, result
   is @ofield{b.errorExpr}.  Otherwise, @oparam{expr} is returned.  In any
   case, the returned value is an instance of @otype{Const}.  *)
  BEGIN
    WITH expr: Const DO
      RETURN expr;
    ELSE  (* not a constant: report error *)
      RETURN b. ErrExpr (exprNotConstant, expr. sym);
    END;
  END AssertConst;

PROCEDURE (b: Builder) AssertIntConst (expr: Expression; start, end: LONGINT): LONGINT;
(* Generates an error if `expr' is not an integer constant on the range
   `start <= expr < end'.  On success, the value of the constant is returned,
   and `start' otherwise.

   Note: If `start >= end', the error message is discarded, because it would
   be meaningless.  In this case, it is assumed that something else went wrong
   and that the caller handles this case.  *)
  VAR
    v: LONGINT;
    const: Const;
  BEGIN
    const := b. AssertConst (expr);
    IF (const # b. errorExpr) THEN
      IF b. typeRules. IsIntegerType (const. type) THEN
        v := const. value(Integer.Value). ToLInt();
        IF (start <= v) & (v < end) THEN
          RETURN v;
        END;
      END;
      
      IF (start < end) THEN  (* only write error if it makes sense ;-) *)
        b. ErrSym (invalidIntegerConst, const. sym);
        b. lastError. SetIntAttrib ("start", start);
        b. lastError. SetIntAttrib ("end", end);
      END;
    END;
    RETURN start;
  END AssertIntConst;

PROCEDURE (b: Builder) NewCall* (design: Expression; arguments: ExpressionList): Expression;
  VAR
    call: Call;
    targetType: Sym.PredefId;
    predefProc: Sym.PredefProc;
    dim: LONGINT;
    type: Sym.Type;
    formalPars: Sym.VarDeclArray;
    receiver: Expression;
    value: Language.Value;
    
  PROCEDURE MakeAssignmentCompatible (b: Builder; sym: Symbol;
                                      expr: Expression;
                                      type: Sym.Type): Expression;
  (**Takes an expression and a type, and tries to make the expression's value
     assignment compatible to the type.  If this is not possible, an error
     is reported.  *)
    BEGIN
      expr := b.AssignType(type, expr);
      IF expr = NIL THEN
        RETURN b.ErrExpr(incompatibleActualParam, sym);
      ELSE
        RETURN expr
      END;
    END MakeAssignmentCompatible;
  
  PROCEDURE MakeParameterCompatible (b: Builder; sym: Symbol;
                                     arg: Expression;
                                     fpar: Sym.VarDecl): Expression;
  (**Takes an expression @oparam{arg} and a formal parameter declaration
     @oparam{fpar}, and tries to make the expression's value compatible to the
     formal parameter.  If this is not possible, an error is reported.  *)
    BEGIN
      IF fpar. isVarParam THEN           (* variable parameter *)
        (* ... nothing for now *)
      ELSE                               (* value parameter *)
        IF b. typeRules. IsOpenArrayType (fpar. type) THEN
          IF b. typeRules. IsArrayOfChar (fpar. type) & (arg IS Const) THEN
            arg := b. AssignType (fpar. type, arg);
            IF (arg = NIL) THEN
              arg := b.ErrExpr(incompatibleActualParam, sym);
            END;
          ELSIF ~b. typeRules. IsArrayCompatible (arg. type, fpar. type) THEN
            RETURN b.ErrExpr(incompatibleActualParam, sym);
          END;
        ELSE
          arg := MakeAssignmentCompatible (b, arg. sym, arg, fpar. type);
        END;
      END;
      RETURN arg
    END MakeParameterCompatible;
  
  PROCEDURE TransformArgs (sym: Symbol;
                           formalPars: Sym.FormalPars;
                           receiver: Expression;
                           VAR arguments: ExpressionList;
                           VAR argFormalPars: Sym.VarDeclArray);
  (**Takes the argument list from the parser and rewrites it to match the
     formal parameters of the called procedure.  The translation includes
     changes to the argument expressions (for example, type conversion to a
     different numeric type) and insertion of additional arguments (for
     example, array length for open array parameters, or insertion of a type
     tag for a @code{VAR} parameter of record type).  *)
    VAR
      newArgs, newFPars: ArrayList.ArrayList;
      i, fparIndex, argIndex: LONGINT;
      fparType: Sym.Type;
      fpar: Sym.VarDecl;
      arg: Expression;
    BEGIN
      newArgs := ArrayList.New (LEN (arguments^));
      newFPars := ArrayList.New (LEN (arguments^));
      
      IF (receiver # NIL) THEN
        argIndex := -1;
        fparIndex := -1;
      ELSE        
        argIndex := 0;
        fparIndex := 0;
      END;
      WHILE (fparIndex # LEN (formalPars. params^)) &
            (argIndex # LEN (arguments^)) DO
        IF (argIndex = -1) THEN
          fpar := formalPars. receiver;
          arg := receiver;
        ELSE
          fpar := formalPars. params[fparIndex];
          arg := arguments[argIndex];
        END;
        arg := MakeParameterCompatible (b, arg. sym, arg, fpar);
        
        IF fpar. isPassPerReference THEN
          (* for argument passed by reference, add the address of the
             designator to the argument list, not its value *)
          newArgs. Append (b. NewAdr (sym, arg));
        ELSE
          newArgs. Append (arg);
        END;
        newFPars. Append (fpar);
        
        fparType := fpar. type;
        WITH fparType: Sym.Array DO
          FOR i := 0 TO fparType. GetOpenDimensions()-1 DO
            newArgs. Append (b. Fold (b. NewLen (arg. sym, arg, i)));
            newFPars. Append (NIL);
          END;

        | fparType: Sym.Record DO
          IF fpar. isVarParam THEN
            newArgs. Append (b. NewTypeTag (arg. sym, arg));
            newFPars. Append (NIL);
          END;
        ELSE  (* nothing to do *)
        END;
        
        INC (argIndex);
        INC (fparIndex);
      END;
      
      NEW (arguments, newArgs. size);
      NEW (argFormalPars, newArgs. size);
      FOR i := 0 TO newArgs. size-1 DO
        arguments[i] := newArgs. array[i](Expression);
        IF (newFPars. array[i] = NIL) THEN
          argFormalPars[i] := NIL;
        ELSE
          argFormalPars[i] := newFPars. array[i](Sym.VarDecl);
        END;
      END;
    END TransformArgs;

  PROCEDURE CheckNumberOfArguments (min, max: LONGINT): BOOLEAN;
    BEGIN
      IF (LEN (arguments^) < min) OR (LEN (arguments^) > max) THEN
        b. ErrSym (wrongNumberOfArguments, design. sym);
        RETURN FALSE;
      ELSE
        RETURN TRUE;
      END;
    END CheckNumberOfArguments;
  
  BEGIN
    WITH design: PredefProc DO
      predefProc := design. decl(Sym.PredefProc);

      IF ~CheckNumberOfArguments(predefProc. minArgs, predefProc. maxArgs) THEN
        (* call does not have the required number of arguments; we bail out
           early, to avoid running into run-time errors in the more fine
           grained checks below *)
        RETURN b. errorExpr;
      END;
      
      CASE design. decl(Sym.PredefProc). id OF
      (* predefined procedures *)
      | Predef.assert:
        RETURN b. NewAssert (design. sym, arguments,
                  ~GetPragmaValue(b, StdPragmas.assertions, design. sym. pos));

      | Predef.copy:
        ASSERT (FALSE);
        
      | Predef.new:
        ASSERT (arguments[0]. type IS Sym.Pointer);
        type := arguments[0]. type(Sym.Pointer). baseType;
        IF (type IS Sym.Array) THEN
          IF CheckNumberOfArguments (1, 1+arguments[0]. type(Sym.Pointer). baseType(Sym.Array). GetOpenDimensions()) THEN
            (* FIXME... check argument type here or in NewNewObject() *)
            RETURN b. NewAssignment
                (design. sym, arguments[0],
                 b. NewNewObject (design.sym, arguments[0].type, arguments));
          END;
        ELSE (* (type IS Sym.Record) *)
          IF CheckNumberOfArguments (1, 1) THEN
            RETURN b. NewAssignment
                (design. sym, arguments[0],
                 b. NewNewObject (design. sym, arguments[0].type, NIL));
          END;
        END;
        RETURN b. errorExpr;
        
      (* predefined functions *)
      | Predef.len:
        IF (LEN (arguments^) # 2) THEN
          dim := 0;
        ELSE  (* LEN (arguments^) = 2 *)
          dim := b. AssertIntConst (arguments[1], 0,
                                    arguments[0]. type. ArrayDimensions());
        END;
        
        IF ~(arguments[0]. type IS Sym.Array) THEN
          b. ErrSym (notArray, arguments[0]. sym);
        END;
        
        RETURN b. NewLen (design. sym, arguments[0], dim);

      | Predef.min, Predef.max:
        type := b. AssertType (arguments[0]);
        IF (design. decl(Sym.PredefProc). id = Predef.min) THEN
          value := Predef.GetMin (type);
        ELSE
          value := Predef.GetMax (type);
        END;
        IF (value = NIL) THEN
          RETURN b. ErrExpr (noMinMax, arguments[0]. sym);
        ELSE
          RETURN b. NewConst (arguments[0]. sym, type, value);
        END;
        
      | Predef.size:
        RETURN b. NewSize (design. sym, arguments[0])

      | Predef.inc:
        ASSERT (LEN (arguments^) = 1);
        RETURN b. NewAssignOp (design. sym,
                               b. NewBinaryArith
                               (design. sym, arithAdd, arguments[0],
                                b. GetOne (design. sym, arguments[0]. type)));
        
      | Predef.dec:
        ASSERT (LEN (arguments^) = 1);
        RETURN b. NewAssignOp (design. sym,
                               b. NewBinaryArith
                               (design. sym, arithSub, arguments[0],
                                b. GetOne (design. sym, arguments[0]. type)));
      | Predef.cap:
        RETURN b. NewCap (design. sym, arguments[0]);

      | Predef.long:
        CASE arguments[0]. type(Sym.PredefType). id OF
        | Predef.shortint: targetType := Predef.integer;
        | Predef.integer : targetType := Predef.longint;
        END;
        RETURN NewTypeConv (Predef.GetType (targetType), arguments[0]);
        
      | Predef.short:
        CASE arguments[0]. type(Sym.PredefType). id OF
        | Predef.integer: targetType := Predef.shortint;
        | Predef.longint: targetType := Predef.integer;
        END;
        RETURN NewTypeConv (Predef.GetType (targetType), arguments[0]);
        
      | Predef.chr:
        RETURN NewTypeConv (Predef.GetType (Predef.char), arguments[0]);
        
      | Predef.ord:
        CASE arguments[0]. type(Sym.PredefType). id OF
        | Predef.char: targetType := Predef.integer;
        END;
        RETURN NewTypeConv (Predef.GetType (targetType), arguments[0]);
      END;

    ELSE
      IF (design = b. errorExpr) THEN
        RETURN b. errorExpr;        (* fall through for errors in designator *)
      ELSE
        NEW (call);
        IF (design IS SelectProc) THEN
          receiver := design(SelectProc). receiver;
        ELSE
          receiver := NIL;
        END;
        TransformArgs (design. sym,
                       design. type(Sym.FormalPars),
                       receiver, arguments, formalPars);
        InitCall (call, design, arguments, formalPars);
        RETURN call;
      END;
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
      (* FIXME: can assign a string constant to an "array of char" _only_
         if the array belongs to a formal parameter... (same with char
         const below) *)
      WITH type : Sym.Array DO
        IF IsPredefType(type. elementType, Predef.char) &
          (type.isOpenArray OR (length < type.length)) THEN
          result := expr;
        END;
      ELSE
      END;
    END;
  ELSIF IsPredefType(exprType, Predef.char) & (expr IS Const) THEN
    (* expression is constant character *)
    length := expr(Const). value(String8.Value). value. length;
    WITH type : Sym.Array DO
      IF IsPredefType(type. elementType, Predef.char) &
         (type.isOpenArray OR (type.length > 1)) THEN
        (* char may be assigned to ARRAY OF CHAR with sufficient length *)
        result := b.NewConst(expr.sym, Predef.GetType (Predef.charString),
                             expr(Const). value);
      END;
    ELSE
    END;

  ELSIF (expr. type IS Sym.FormalPars) THEN
    IF (type IS Sym.FormalPars) &
       tr. FormalParamsMatch (type(Sym.FormalPars),
                              expr. type(Sym.FormalPars), FALSE) THEN
      result := expr;
    END;

  ELSIF (expr. type IS Sym.Pointer) & tr. IsExtensionOf (expr. type, type) THEN
    result := expr;
  END;
  RETURN result;
END AssignType;

BEGIN
  NEW (irContext);
  Error.InitContext (irContext, "OOC:IR");
END OOC:IR.
