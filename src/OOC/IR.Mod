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
  Language, Language:Boolean, Language:Char, Language:Set,
  LString := Language:String,
  Language:String8, Language:String16, Language:Integer, Language:Real,
  ADT:Object, ADT:ArrayList, ADT:String, ADT:StringBuffer,
  Config:Value, BooleanValue := Config:Value:Boolean, 
  Id := OOC:Scanner:Symbol, OOC:Scanner:Builder:BasicList, OOC:Error,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:AST, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  TR := OOC:SymbolTable:TypeRules, OOC:SymbolTable:Namespace,
  OOC:SymbolTable:CreateNamespace;

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

TYPE
  GuardedVar* = POINTER TO GuardedVarDesc;
  GuardedVarDesc = RECORD
    (**Used to indicate that for a region of code the the static type of
       @ofield{var} should be considered to by @ofield{type}.  This is used
       for the @code{WITH} statement to change the type of the guarded
       variable without touching the symbol table: within a guarded branch,
       a temporary namespace is installed, which maps @samp{var.name} onto
       an instance of this pseudo declaration.  *)
    (Sym.DeclarationDesc)
    var-: Sym.VarDecl;
    type-: Sym.Type;
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

  (* variants of SetElement *)
  inclElement* = 22;
  exclElement* = 23;
  
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
  Abs* = POINTER TO AbsDesc;
  AbsDesc = RECORD
    (OperatorDesc)
    operand-: Expression;
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
  Ash* = POINTER TO AshDesc;
  AshDesc = RECORD
    (OperatorDesc)
    value-, exp- :Expression;
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
  Concat* = POINTER TO ConcatDesc;
  ConcatDesc = RECORD
    (**String concatentation.  The type of the result depends on the types of
       the operands:

       @itemize @bullet
       @item
       If an operand is of type @code{STRING}, then the result is of type
       @code{STRING}.

       @item
       If an operand is a character constant of type @code{LONGCHAR}, or a
       string constant based on @code{LONGCHAR}, then the result is a
       @code{LONGCHAR} string constant @oconst{Predef.longcharString}.

       @item
       Otherweise, result is a @code{CHAR} string constant
       @oconst{Predef.charString}.
       @end itemize  *)
    (OperatorDesc)
    strings-: ExpressionList;
    (**List of string values that are to be concatenated together.  The entries
       are restricted to values of type @oconst{Predef.charString},
       @oconst{Predef.longcharString}, and @ofield{Builder.stringType}.  All
       entries are of the same type, @ofield{type}.

       Right now, this list is always 2 elements long, but this is likely to
       change in the future to an arbitrary length greater than 1.  *)
  END;
  
TYPE
  ChangeElement* = POINTER TO ChangeElementDesc;
  ChangeElementDesc = RECORD
    (**Include or exclude a single set element.  Used for @code{INCL}
       and @code{EXCL}.  *)
    (OperatorDesc)
    variant-: Variant;
    (**One of @oconst{inclElement} or @oconst{exclElement}.  *)
    set-: Expression;
    element-: Expression;
  END;
  
TYPE
  Deref* = POINTER TO DerefDesc;
  DerefDesc = RECORD
    (OperatorDesc)
    (**The deref operator takes a pointer value and returns the referenced
       value.  *)
    pointer-: Expression;
    derefType-: Sym.Type;
    checkPointer-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       pointer value is @code{NIL}.  *)
  END;
  
TYPE
  Entier* = POINTER TO EntierDesc;
  EntierDesc = RECORD
    (OperatorDesc)
    operand- : Expression;
  END;

TYPE
  Index* = POINTER TO IndexDesc;
  IndexDesc = RECORD
    (OperatorDesc)
    (**The index operator selects the element at position @ofield{index} from
       the array variable @ofield{array}.  *)
    array- : Expression;
    index- : Expression;
    checkIndex-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the index
       is out of range.  *)
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
    (**Severely overloaded: integer negation, real negation, and set
       complement.  *)
    (OperatorDesc)
    operand- : Expression;
  END;

TYPE
  NewBlock* = POINTER TO NewBlockDesc;
  NewBlockDesc = RECORD
    (**Implements @code{SYSTEM.NEW}: Allocates a new object on the heap and
       returns a pointer to it.  The object's data is not tracked by the
       garbage collector.  *)
    (OperatorDesc)
    size-: Expression;
    (**Size of the heap block in bytes.  *)
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
  Not* = POINTER TO NotDesc;
  NotDesc = RECORD
    (OperatorDesc)
    operand- : Expression;
  END;

TYPE
  Odd* = POINTER TO OddDesc;
  OddDesc = RECORD
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
    fieldSym-: Symbol;
  END;

TYPE
  SelectProc* = POINTER TO SelectProcDesc;
  SelectProcDesc = RECORD
    (OperatorDesc)
    (**This operator selects the type-bound procedure @ofield{tbProc} belonging
       to the @ofield{receiver} designator.  *)
    receiver-: Expression;
    (**The receiver designator of the call.  *)
    checkPointer-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       receiver value is @code{NIL}.  *)
    
    recordType-: Sym.Record;
    (**The record type of which the type-bound procedure is called.  *)
    
    tbProc-: Sym.ProcDecl;
    (**The static procedure that is referenced by the call's designator
       in the source code.  The actual procedure being called may be this
       procedure, a redefinition of it, or (if this is a super call) its
       definition in one of the base types.  *)

    tbProcSym-: Symbol;
    
    isStaticCall-: BOOLEAN;
    (**If @code{TRUE}, then this is a static call to the procedure indicated
       by @ofield{tbProc}.  No table lookup must be done, instead its
       address must be used directly.  *)
  END;

TYPE 
  SetMember* = POINTER TO SetMemberDesc;
  SetMemberDesc = RECORD
    (**Set membership test. *)
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
     @ofield{to}.

     The constructor of this class may be called with both @ofield{from}
     and @ofield{to} being @code{NIL}.  This special range is immediately
     converted into an empty set constant.  *)
    (OperatorDesc)
    from-, to- : Expression;
  END;

TYPE
  Shift* = POINTER TO ShiftDesc;
  ShiftDesc = RECORD
    (OperatorDesc)
    value-, by-: Expression;
    rotate-: BOOLEAN;
  END;

TYPE
  TypeCast* = POINTER TO TypeCastDesc;
  TypeCastDesc = RECORD
    (**A type cast expression interprets the binary representation of a
       value as if it is of another type.  It resembles @otype{TypeConv}
       in its arguments, in particular how the type information is stored.
       Unlike @otype{TypeConv}, casting a value does not involved any
       translation of the value.  *)
    (OperatorDesc)
    expr- : Expression;
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
       @item
       implicit type conversion of operands of numeric operators
       
       @item
       explicit type conversion using @code{SHORT} or @code{LONG}
       
       @item
       when assigning a character or string constant to a variable
       of type @code{STRING}
       
       @item
       @dots{}
       @end itemize  *)
    (OperatorDesc)
    expr- : Expression;
  END;


TYPE
  TypeTag* = POINTER TO TypeTagDesc;
  TypeRef* = POINTER TO TypeRefDesc;
  TypeTagDesc = RECORD
    (**Computes the type tag of a variable parameter of type @code{RECORD}.  *)
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
    checkPointer-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       left side of the type test is @code{NIL}.  *)

    origExpr-: Expression;
    (**Unnormalized value of @ofield{expr}.  *)
    origType-: TypeRef;
    (**Unnormalized value of @ofield{referenceType}.  *)
  END;

TYPE
  TypeGuard* = POINTER TO TypeGuardDesc;
  TypeGuardDesc = RECORD
    (**The type guard operator. The operator is normalized in the same sense as
       the type test operator. *)
    (OperatorDesc)
    test- : TypeTest;
    checkPointer-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       left side of the type guard is @code{NIL}.  *)
    checkType-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       guard fails.  *)
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
    (**Represents a call to the predefined procedure @code{ASSERT} or
       @code{HALT}.  *)
    (StatementDesc)
    predicate-: Expression;
    (**If this is a @code{HALT}, then this field is @code{NIL}.  *)
    code-: LONGINT;
    disabled-: BOOLEAN;
  END;

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
       left operand of the @otype{BinaryArith} or @otype{ChangeElement}
       instance in @ofield{value}.  Translation of this special assignment must
       take care to evaluate the variable designator only once!  *)
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
  Copy* = POINTER TO CopyDesc;
  CopyDesc = RECORD
    (**Copies a record or fixed size array value.  Used for the assignment
       operator @samp{:=}, if the copied value is not of scalar type.  *)
    (StatementDesc)
    source-: Expression;
    dest-: Expression;
    checkDynamicType-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       dynamic type of the @ofield{dest} record does not match its
       static type.  *)
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
  CopyString* = POINTER TO CopyStringDesc;
  CopyStringDesc = RECORD
    (**Copies a character sequence to a character array.  Used for the
       predefined procedure @samp{COPY}, and when assigning a string
       constant to a character array.  *)
    (StatementDesc)
    source-: Expression;
    dest-: Expression;
    maxLength-: Expression;
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
  END;

TYPE
  Case* = POINTER TO CaseDesc;
  CaseLabels* = POINTER TO ARRAY OF Expression;
  CaseDesc = RECORD
    (StatementDesc)
    labels-:  CaseLabels;
    (**Labels of the case branch.  If this array is of length zero, then all
       label ranges evaluated to the empty set.  *)
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
    checkMatch-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if none of
       the labels matches the value of @ofield{select}.  *)
  END;
  
TYPE
  LoopStatmDesc = RECORD
    (**Holds an @code{LOOP-END} statement.  *)
    (StatementDesc)
    body-: StatementSeq;
  END;

TYPE
  MoveBlock* = POINTER TO MoveBlockDesc;
  MoveBlockDesc = RECORD
    (StatementDesc)
    source-: Expression;
    dest-: Expression;
    size-: Expression;
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

TYPE
  WithStatm* = POINTER TO WithStatmDesc;
  WithStatmDesc = RECORD
    (**Holds a @code{WITH} statement.  If there is no @code{ELSE}, then
       @ofield{pathFalse} is @code{NIL}.  @code{WITH} statements with
       multiple guards are translated to nested @code{WITH} statements.  *)
    (StatementDesc)
    guard-: Expression;
    pathTrue-: StatementSeq;
    pathFalse-: StatementSeq;  (* NIL if the WITH statement has no ELSE *)
    checkMatch-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the
       type guard does not evaluate to @code{TRUE}, and there is no @code{ELSE}
       part.  *)
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
    checkFunctionResult-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the end
       of the function body is reached without encountering any @code{RETURN}.
       *)
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
  ModuleType* = POINTER TO ModuleTypeDesc;
  ModuleTypeDesc = RECORD
    (**This special type is assigned to expressions that designate a module.
       For example, with a (bogus) expression @samp{x := Out}, the right side
       used this type, assuming that @samp{Out} is an imported module.  *)
    (Sym.TypeDesc)
  END;
  
TYPE
  Builder* = POINTER TO BuilderDesc;
  ConstFold* = POINTER TO ConstFoldDesc;
  BuilderDesc* = RECORD
    module: Sym.Module;
    (* The symbol table of the module that is being processed.  *)
    
    pragmaHistory: Pragmas.History;
    errList: Error.List;
    constFold- : ConstFold;
    
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
    moduleType-: ModuleType;
    (**This type is assigned to expressions that designate a module.  *)
    stringType-: Sym.Type;
    (**Type definition for the predefined type @code{STRING}.  If this field
       is @code{NIL}, then the module cannot use this type.  *)
    
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
  notInteger = 19;
  notRecord = 20;
  notPointer = 21;
  notBoolean = 22;
  illegalFunctionOp = 23;
  incompatibleAssignment = 24;
  exitOutsideLoop = 25;
  invalidCaseSelector = 26;
  labelNotInSelect = 27;
  duplicateLabel = 28;
  notVariable = 29;
  invalidStepType = 30;
  stepIsZero = 31;
  returnWithResult = 32;
  returnWithoutResult = 33;
  importedReadOnly = 34;
  notProcedure = 35;
  isFunctionProcedure = 36;
  notFunctionProcedure = 37;
  tooFewArguments = 38;
  tooManyArguments = 39;
  notVarParCompatible = 40;
  redirectFailed = 41;
  readOnlyParameter = 42;
  noDynamicType = 43;
  notNumeric = 44;
  notCharacter = 45;
  notReal = 46;
  dynamicSize = 47;
  notCharacterArray = 48;
  notSet = 49;
  notPointerVar = 50;
  notAddressable = 51;
  objectSizeMismatch = 52;
  unusedDeclaration = 53;
  noLengthInfo = 54;
  noTypeTag = 55;
  cannotCreateInstance = 56;
  abstractWithBegin = 57;
  abstractSuperCall = 58;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  irContext: ErrorContext;

PROCEDURE AppendContext(buffer : StringBuffer.StringBuffer; item : Sym.Item);
  BEGIN
    WITH item : Sym.Declaration DO
      IF item.parent # NIL THEN
        AppendContext(buffer, item.parent);
      END;
      buffer.AppendString(item.name.str^);
      buffer.AppendChar(".");
     END;
  END AppendContext;

PROCEDURE TypeName* (type : Sym.Type) : String.String;
(**Return a string describing type @oparam{type}. For named types, this will
   be of the form "module.@{proc.@}type". If there is no name the name of the
   type constructor is used (eg. RECORD, ARRAY). *)
VAR
  name : StringBuffer.StringBuffer;
BEGIN
  name := StringBuffer.New("");
  IF type.parent # NIL THEN
    AppendContext(name, type.parent);
  END;
  IF type.namingDecl # NIL THEN
    name.AppendString(type.namingDecl.name.str^);
  ELSE
    WITH 
      type : Sym.PredefType DO
      (* probably doesn't happen since these should be named *)
      name.AppendString("PredefType(");
      name.AppendLongInt(type.id);
      name.AppendString(")")
    | type : Sym.Pointer DO
      name.AppendString("POINTER")
    | type : Sym.FormalPars DO
      name.AppendString("PROCEDURE")
    | type : Sym.Array DO
      name.AppendString("ARRAY")
    | type : Sym.Record DO
      name.AppendString("RECORD")
    END
  END;
  RETURN name.ToString();
END TypeName;

PROCEDURE LogTypeName(message : ARRAY OF CHAR; type : Sym.Type);
VAR name : String.String;
BEGIN
  name := TypeName(type);
  Log.String(message, name.array^);
END LogTypeName;

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
    | incompatibleAssignment:
      t := "Type of expression is not compatible with variable type"
    | wrongNumberOfArguments:
      t := "Wrong number of arguments"
    | invalidIntegerConst:
      t := "Integer constant in the range `${start} <= x < ${end}' required"
    | notArray:
      t := "Expression must be an array value"
    | notTypeExpression:
      t := "Type name expected"
    | notExtensionOfLHS:
      t := "Type must be an extension of the left operand's type"
    | noMinMax:
      t := "MIN/MAX is not applicable to this type"
    | notInteger:
      t := "Expression must be of integer type"
    | notRecord:
      t := "Expression must be of record type"
    | notPointer:
      t := "Expression must be of pointer type"
    | notBoolean:
      t := "Expression must be of type BOOLEAN"
    | illegalFunctionOp:
      t := "Operator may not be applied to function result"
    | exitOutsideLoop:
      t := "EXIT outside of LOOP"
    | invalidCaseSelector:
      t := "Select expression must be integer or character"
    | labelNotInSelect:
      t := "Label not in type of select expression"
    | duplicateLabel:
      t := "Label already in use"
    | notVariable:
      t := "This must be a variable"
    | invalidStepType:
      t := "Step value not in type of loop variable"
    | stepIsZero:
      t := "Step value must not be zero"
    | returnWithResult:
      t := "RETURN must not provide a result value"
    | returnWithoutResult:
      t := "RETURN must provide a result value"
    | importedReadOnly:
      t := "This variable is read-only"
    | notProcedure:
      t := "This must be a procedure designator"
    | isFunctionProcedure:
      t := "This is a function procedure"
    | notFunctionProcedure:
      t := "This is not a function procedure"
    | tooFewArguments:
      t := "Too few arguments"
    | tooManyArguments:
      t := "Too many arguments"
    | notVarParCompatible:
      t := "Actual parameter not compatible with formal VAR parameter"
    | redirectFailed:
      t := "Internal error: Name redirection failed"
    | readOnlyParameter:
      t := "This parameter is read-only"
    | noDynamicType:
      t := "This variable has no dynamic type"
    | notNumeric:
      t := "Expression must be numeric"
    | notCharacter:
      t := "Expression must be a character"
    | notReal:
      t := "Expression must be of real type"
    | dynamicSize:
      t := "Type has no fixed size"
    | notCharacterArray:
      t := "Argument must be a character array"
    | notSet:
      t := "Expression must be of set type"
    | notPointerVar:
      t := "This must be a pointer variable"
    | notAddressable:
      t := "This expression has no address"
    | objectSizeMismatch:
      t := "Size mismatch between type and expression"
    | unusedDeclaration:
      t := Error.warningPrefix+"Unused object"
    | noLengthInfo:
      t := "Length of this array value cannot be determined"
    | noTypeTag:
      t := "This variable has no type tag"
    | cannotCreateInstance:
      t := "Cannot create an instance an abstract type"
    | abstractWithBegin:
      t := "Abstract procedure cannot have a BEGIN part"
    | abstractSuperCall:
      t := "Called procedure is declared abstract"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


(* Guarded Variable Declaration
   ------------------------------------------------------------------------ *)

PROCEDURE InitGuardedVar (gv: GuardedVar; var: Sym.VarDecl; type: Sym.Type);
  BEGIN
    Sym.InitDeclaration (gv, NIL, var. name, var. visibleFrom,
                         var. exportMark, var. docString);
    gv. var := var;
    gv. type := type;
  END InitGuardedVar;

PROCEDURE NewGuardedVar (var: Sym.VarDecl; type: Sym.Type): GuardedVar;
  VAR
    gv: GuardedVar;
  BEGIN
    NEW (gv);
    InitGuardedVar (gv, var, type);
    RETURN gv;
  END NewGuardedVar;

PROCEDURE (gv: GuardedVar) Module*(): Sym.Module;
  BEGIN
    RETURN gv. var. Module();
  END Module;


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

PROCEDURE GetPragmaValue (b: Builder; pragma: Pragmas.Pragma; charPos: Pragmas.CharPos): BOOLEAN;
  VAR
    value: Value.Value;
  BEGIN
    value := b. pragmaHistory. GetValue (pragma. name^, charPos);
    RETURN value(BooleanValue.Value). boolean
  END GetPragmaValue;

PROCEDURE (b: Builder) WarnName (code: Error.Code; name: Sym.Name);
  VAR
    e: Error.Msg;
  BEGIN
    IF (name.str[0] # "-") &
       GetPragmaValue(b, StdPragmas.warnings, name.pos) THEN
      (* don't warn for declarations that were inserted by the compiler
         behind the user's back *)
      e := Error.New (irContext, code);
      e. SetIntAttrib ("pos", name. pos);
      e. SetIntAttrib ("line", name. line);
      e. SetIntAttrib ("column", name. column);
      b. errList. Append (e);
      b. lastError := e;
    END;
  END WarnName;

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

PROCEDURE (b: Builder) AssertBoolean* (expr: Expression): Expression;
(**Generates an error if @oparam{expr} is not a boolean expression.
   In this case, result is @code{errorExpr}.  Otherwise, @oparam{expr}
   is returned.  *)
  BEGIN
    IF (expr. type IS Sym.PredefType) &
       (expr. type(Sym.PredefType). id = Predef.boolean) THEN
      RETURN expr;
    ELSE
      RETURN b. ErrExpr (notBoolean, expr. sym);
    END;
  END AssertBoolean;

PROCEDURE (b : Builder) Fold* (expr : Expression) : Expression;
BEGIN
  RETURN b.constFold.TryConstFold(expr);
END Fold;

PROCEDURE IsPredefType(type : Sym.Type; id : Sym.PredefId) : BOOLEAN;
BEGIN
  RETURN (type IS Sym.PredefType) & (type(Sym.PredefType).id = id);
END IsPredefType;

PROCEDURE ^ (b: Builder) NewCopy* (sym: Symbol; source, dest: Expression): Copy;
PROCEDURE ^ (b: Builder) NewCopyString* (sym: Symbol; source, dest, maxLength: Expression): CopyString;

PROCEDURE ^ (b: Builder) NewCall* (design: Expression;
                                   arguments: ExpressionList;
                                   isFunctionCall: BOOLEAN;
                                   endOfArgsSym: Symbol): Expression;

PROCEDURE ^ (b: Builder) Widen (VAR expr: Expression; type: Sym.Type): BOOLEAN;

PROCEDURE (b : Builder) CheckFunctionOp(expr : Expression; op : Symbol);
(**Check that the operator @oparam{op} is not applied to an expression
   @oparam{expr} that is a function result. This restriction is applied to
   Deref, Index, and Select operators. *)
BEGIN
  IF (expr IS PredefProc) OR (expr IS Call) THEN
    b.ErrSym(illegalFunctionOp, op);
  END;
END CheckFunctionOp;

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
    v: Integer.Value;
  BEGIN
    v := Integer.type. ValueOf (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (numberOutOfRange, sym);
      RETURN b. errorExpr
    ELSE
      RETURN NewConst (sym, Predef.SmallestIntType (v), v)
    END
  END NewIntConst10;

PROCEDURE (b: Builder) NewIntConst16* (sym: Symbol): Expression;
  VAR
    v: Integer.Value;
    result: LONGINT;
    spos, epos: INTEGER;
      
  PROCEDURE GetDigit(c: CHAR): INTEGER;
    VAR
      d: INTEGER;
    BEGIN
      d:=ORD(c);
      IF (ORD ("0") <= d) & (d <= ORD ("9")) THEN
        DEC (d, ORD ("0"))
      ELSE  (* (ORD ("A") <= d) & (d <= ORD ("F")) *)
        (* the explicit test can be omitted, since this procedure is only 
           called for numbers with H or X suffix, and the initial REPEAT 
           loop in `Number' only accepts valid hexadecimal digits from 
           the ranges "0".."9" and "A".."F" *)
        DEC (d, ORD ("A")-10)
      END;
      RETURN d
    END GetDigit;
  
  BEGIN
    (* FIXME... string conversion should probably put into Language.Integer *)
    result := 0; spos := 0; epos := -1;
    WHILE (sym. str[epos+1] # "H") DO
      INC (epos);
    END;
    
    (* skip leading zeros *)
    WHILE (sym. str[spos] = "0") DO 
      INC (spos)
    END;
    IF (epos-spos > 7) THEN  (* value has more than 8 significant digits *)
      ASSERT (FALSE);                 (* number out of range *)
    ELSIF (spos <= epos) THEN         (* if any non-zero digits follow *)
      result := GetDigit (sym. str[spos]);
      INC (spos);
      IF (epos-spos = 6) & (result >= 8) THEN
        (* value is beyond MAX(LONGINT)=07FFFFFFFH: correct this by sub-
           tracting 16 from the value of the most significant digit, creating
           the negative number that matches the bit pattern *)
        (* warning: hex const mapped to negative value *)
        (* FIXME... with HUGEINT, this is no longer true *)
        DEC (result, 10H)
      END;
      WHILE (spos <= epos) DO
        result := result*10H + GetDigit (sym. str[spos]);
        INC (spos)
      END;
      (* ELSE: number is non-empty sequence of "0", keep result=0 *)
    END;
    
    v := Integer.New (result);
    RETURN NewConst (sym, Predef.SmallestIntType (v), v)
  END NewIntConst16;

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
      IF TR.IsIntegerType (const. type) THEN
        v := const. value(Integer.Value). ToInt();
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

PROCEDURE (b: Builder) AssertInteger(expr: Expression): Expression;
(* Generates an error if `expr' is not an integer value.  On success,
   `expr' is returned, and otherwise an integer constant with a value of `1'.*)
  VAR
    v: Integer.Value;
  BEGIN
    IF ~TR.IsIntegerType(expr.type) THEN
      IF (expr # b.errorExpr) THEN
        b.ErrSym(notInteger, expr.sym);
      END;
      v := Integer.New(1);
      RETURN NewConst(expr.sym, Predef.SmallestIntType(v), v);
    END;
    RETURN expr;
  END AssertInteger;

PROCEDURE (b: Builder) AssertReal(expr: Expression): Expression;
(* Generates an error if `expr' is not a floating point value.  On success,
   `expr' is returned, and otherwise a REAL constant with a value of `1.0'.*)
  VAR
    v: Real.Value;
  BEGIN
    IF ~TR.IsRealType(expr.type) THEN
      IF (expr # b.errorExpr) THEN
        b.ErrSym(notReal, expr.sym);
      END;
      v := Real.New(1);
      RETURN NewConst(expr.sym, Predef.GetType(Predef.real), v);
    END;
    RETURN expr;
  END AssertReal;

PROCEDURE (b: Builder) AssertNumeric (expr: Expression): Expression;
(* Generates an error if `expr' is not an integer or real value.  On success,
   `expr' is returned, and otherwise an integer constant with a value of `1'.*)
  VAR
    v: Integer.Value;
  BEGIN
    IF ~TR.IsNumericType(expr.type) THEN
      IF (expr # b.errorExpr) THEN
        b.ErrSym(notNumeric, expr.sym);
      END;
      v := Integer.New(1);
      RETURN NewConst(expr.sym, Predef.SmallestIntType(v), v);
    END;
    RETURN expr;
  END AssertNumeric;

PROCEDURE (b: Builder) AssertChar(expr: Expression): Expression;
(* Generates an error if `expr' is not a character.  On success,
   `expr' is returned, and otherwise an character constant with a value of
   "?".*)
  VAR
    v: String8.Value;
  BEGIN
    IF ~TR.IsCharType(expr.type) THEN
      IF (expr # b.errorExpr) THEN
        b.ErrSym(notCharacter, expr.sym);
      END;
      v := String8.NewString("a");
      RETURN NewConst(expr.sym, Predef.GetType(Predef.char), v);
    END;
    RETURN expr;
  END AssertChar;

PROCEDURE (b: Builder) AssertSet(expr: Expression): Expression;
(* Generates an error if `expr' is not a set value.  On success,
   `expr' is returned, and otherwise the empty set.  *)
  VAR
    v: Set.Value;
  BEGIN
    IF ~TR.IsSetType(expr.type) THEN
      IF (expr # b.errorExpr) THEN
        b.ErrSym(notSet, expr.sym);
      END;
      v := Set.New({});
      RETURN NewConst(expr.sym, Predef.GetType(Predef.set), v);
    END;
    RETURN expr;
  END AssertSet;

PROCEDURE (b: Builder) NewRealConst* (sym: Symbol; type: Sym.PredefId): Expression;
  VAR
    v: Language.Value;
  BEGIN
    v := Real.type. ValueOfLiteral (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (numberOutOfRange, sym);
      RETURN b. errorExpr
    ELSE
      RETURN NewConst (sym, Predef.GetType (type), v)
    END
  END NewRealConst;

PROCEDURE (b: Builder) NewCharConst16* (sym: Symbol): Expression;
  VAR
    v: Language.Value;
  BEGIN
    v := Char.type. ValueOf (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (characterOutOfRange, sym);
      RETURN b. errorExpr
    ELSE
      WITH v: Char.Value DO
        IF (v. value <= ORD (Predef.maxChar)) THEN
          RETURN NewConst (sym, Predef.GetType (Predef.char),
                           String8.NewChar (CHR (v. value)));
        ELSE
          RETURN NewConst (sym, Predef.GetType (Predef.longchar),
                           String16.NewChar (LONGCHR (v. value)));
        END;
      END;
    END
  END NewCharConst16;

PROCEDURE (b: Builder) NewNil* (sym: Symbol): Expression;
  BEGIN
    RETURN NewConst (sym, Predef.GetType (Predef.nil), NIL);
  END NewNil;

PROCEDURE (b: Builder) NewSize* (sym: Symbol; type: Expression): Expression;
  VAR
    t: Sym.Type;
    size: LONGINT;
  BEGIN
    t := b.AssertType(type);
    IF (t.size < 0) THEN
      b.ErrSym(dynamicSize, type.sym);
      size := 1;
    ELSE
      size := t.size;
    END;
    RETURN b. NewConst
        (sym, Predef.GetType (Predef.lengthType), Integer.New (size));
  END NewSize;

PROCEDURE (b: Builder) GetOne (sym: Symbol; type: Sym.Type): Const;
  BEGIN
    RETURN b. NewConst (sym, type, Integer.New (1));
  END GetOne;

PROCEDURE (b : Builder) ValidSetElement(expr : Expression; set : Sym.Type) : Expression;
(**Check if @oparam{expr} is a valid element of set type @oparam{set}. The
   type of @oparam{expr} must be integer. If @oparam{expr} is constant, it
   must be included in the range @samp{MIN(set)..MAX(set)}. 

   This procedure always returns a valid element for @oparam{set}. The
   original expression is returned if it is valid. Otherwise, the value of
   @samp{MIN(set)} is returned. *)

  VAR
    val : Language.Value;
    element, min, max : Integer.Value;

  PROCEDURE MinElement() : Expression;
  (**Return a constant for the minimal element of set @oparam{set}. *)
  BEGIN
    RETURN b.NewConst(expr.sym, Predef.GetType(Predef.shortint), min);
  END MinElement;

  BEGIN
    val := Predef.GetMin(set); min := val(Integer.Value);
    val := Predef.GetMax(set); max := val(Integer.Value);

    expr := b.AssertInteger(expr);
    WITH expr : Const DO
      element := expr.value(Integer.Value);
      IF (element.Compare(min) < 0) OR (element.Compare(max) > 0) THEN
        b. ErrSym (invalidIntegerConst, expr. sym);
        b. lastError. SetIntAttrib ("start", min.ToInt());
        b. lastError. SetIntAttrib ("end", max.ToInt()+1);
	RETURN MinElement()
      END
    ELSE
    END;
    RETURN expr
  END ValidSetElement;

(* Expression Class: Operator
   ------------------------------------------------------------------------ *)

PROCEDURE InitOperator* (op: Operator; sym: Symbol; type: Sym.Type);
  BEGIN
    InitExpression (op, sym, type);
  END InitOperator;

(* Operator Class: Abs
   ------------------------------------------------------------------------ *)

PROCEDURE InitAbs (abs: Abs; sym: Symbol; operand: Expression);
  BEGIN
    InitOperator (abs, sym, operand. type);
    abs. operand := operand;
  END InitAbs;

PROCEDURE (b: Builder) NewAbs (sym: Symbol; operand: Expression): Expression;
  VAR
    abs: Abs;
  BEGIN
    NEW (abs);
    InitAbs (abs, sym, b.AssertNumeric(operand));
    RETURN abs;
  END NewAbs;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAbs* (abs: Abs);
  END VisitAbs;

PROCEDURE (abs: Abs) Accept* (v: Visitor);
  BEGIN
    v. VisitAbs (abs)
  END Accept;

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

  PROCEDURE AssertAddressable (expr: Expression): Expression;
    VAR
      hasAddress, dummy: BOOLEAN;
      e: Expression;
    BEGIN
      e := expr;
      hasAddress := TRUE;
      WITH e: Var DO
      | e: Deref DO
      | e: Index DO
      | e: SelectField DO
      | e: TypeGuard DO
      | e: ProcedureRef DO
      | e: Const DO
        IF TR.IsCharType(expr.type) THEN
          dummy := b.Widen(expr, TR.MatchingStringConst(expr.type));
        END;
        hasAddress := TR.IsStringConst(expr.type);
      ELSE
        hasAddress := FALSE;
      END;
      IF ~hasAddress THEN
        b.ErrSym(notAddressable, expr.sym);
      END;
      RETURN expr;
    END AssertAddressable;
  
  BEGIN
    NEW (adr);
    InitAdr (adr, sym, AssertAddressable(design));
    RETURN adr
  END NewAdr;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAdr* (adr: Adr);
  END VisitAdr;

PROCEDURE (adr: Adr) Accept* (v: Visitor);
  BEGIN
    v. VisitAdr (adr)
  END Accept;

(* Operator Class: Ash
   ------------------------------------------------------------------------ *)

PROCEDURE InitAsh (ash: Ash; sym: Symbol; value, exp: Expression);
  BEGIN
    InitOperator (ash, sym, Predef.GetType (Predef.longint));
    ash. value := value;
    ash. exp := exp;
  END InitAsh;

PROCEDURE (b: Builder) NewAsh (sym: Symbol; value, exp: Expression): Expression;
  VAR
    ash: Ash;
  BEGIN
    NEW (ash);
    InitAsh (ash, sym, b.AssertInteger(value), b.AssertInteger(exp));
    RETURN ash;
  END NewAsh;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAsh* (ash: Ash);
  END VisitAsh;

PROCEDURE (ash: Ash) Accept* (v: Visitor);
  BEGIN
    v. VisitAsh (ash)
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
    ASSERT(TR.SameType(left.type, right.type));
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
    InitCap (cap, sym, b.AssertChar(expr));
    RETURN cap;
  END NewCap;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCap* (cap: Cap);
  END VisitCap;

PROCEDURE (cap: Cap) Accept* (v: Visitor);
  BEGIN
    v. VisitCap (cap)
  END Accept;

(* Operator Class: ChangeElement
   ------------------------------------------------------------------------ *)

PROCEDURE InitChangeElement (ch: ChangeElement; sym: Symbol; variant: Variant;
                             set, element: Expression);
  BEGIN
    InitOperator (ch, sym, set. type);
    ch. variant := variant;
    ch. set := set;
    ch. element := element;
  END InitChangeElement;

PROCEDURE (b: Builder) NewChangeElement* (sym: Symbol; variant: Variant;
                                          set, element: Expression): Expression;
  VAR
    ch : ChangeElement;
  BEGIN
    NEW (ch);
    InitChangeElement (ch, sym, variant, set, element);
    RETURN ch;
  END NewChangeElement;

PROCEDURE (v: Visitor) [ABSTRACT] VisitChangeElement* (ch: ChangeElement);
  END VisitChangeElement;

PROCEDURE (ch: ChangeElement) Accept* (v: Visitor);
  BEGIN
    v. VisitChangeElement (ch)
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

(* Operator Class: Concat
   ------------------------------------------------------------------------ *)

PROCEDURE InitConcat (op: Concat; sym: Symbol; type: Sym.Type;
                      strings: ExpressionList);
  BEGIN
    InitOperator (op, sym, type);
    op.strings := strings;
  END InitConcat;

PROCEDURE (b: Builder) NewConcat (sym: Symbol; strings: ExpressionList): Concat;
  VAR
    op: Concat;
    id, tid: INTEGER;
    i: LONGINT;
    type: Sym.Type;
    dummy: BOOLEAN;
  BEGIN
    id := -1;
    FOR i := 0 TO LEN(strings^)-1 DO
      type := strings[i].type;
      
      tid := MAX(INTEGER);
      IF TR.IsStringConst(type) THEN     (* string constant *)
        tid := type(Sym.PredefType).id;
      ELSIF TR.IsCharType(type) THEN     (* convert char to string constant *)
        IF b.Widen(strings[i], TR.MatchingStringConst(type)) THEN
          tid := strings[i].type(Sym.PredefType).id;
        ELSE
          b.ErrSym(incompatibleTypes, sym);
        END;
      ELSIF (type # b.stringType) THEN   (* not STRING value?  error! *)
        b.ErrSym(incompatibleTypes, sym);
      END;
      IF (tid > id) THEN
        id := tid;
      END;
    END;
    IF (id < MAX(INTEGER)) THEN
      type := Predef.GetType(id);
      FOR i := 0 TO LEN(strings^)-1 DO
        dummy := b.Widen(strings[i], type);
        ASSERT(dummy);
      END;
    ELSE
      type := b.stringType;
      FOR i := 0 TO LEN(strings^)-1 DO
        IF TR.IsStringConst(strings[i].type) THEN
          (* don't try this if this operand is in error *)
          dummy := b.Widen(strings[i], type);
          ASSERT(dummy);
        END;
      END;
    END;
    
    NEW (op);
    InitConcat (op, sym, type, strings);
    RETURN op;
  END NewConcat;

PROCEDURE (v: Visitor) [ABSTRACT] VisitConcat* (op: Concat);
  END VisitConcat;

PROCEDURE (op: Concat) Accept* (v: Visitor);
  BEGIN
    v. VisitConcat (op)
  END Accept;

(* Operator Class: Deref
   ------------------------------------------------------------------------ *)

PROCEDURE InitDeref (d: Deref; sym: Symbol; pointer: Expression;
                     checkPointer: BOOLEAN);
  BEGIN
    InitOperator (d, sym, pointer. type(Sym.Pointer). baseType);
    d. pointer := pointer;
    d. derefType := pointer. type(Sym.Pointer). baseType;
    d. checkPointer := checkPointer;
    ASSERT ((d. derefType IS Sym.Record) OR (d. derefType IS Sym.Array));
  END InitDeref;

PROCEDURE (b: Builder) NewDeref* (sym: Symbol; design: Expression): Expression;
  VAR
    i: Deref;
  BEGIN
    WITH design: SelectProc DO (* super call of type-bound procedure *)
      (* FIXME... check that we are in a redefinition *)
      design. tbProc := design. recordType. ns(Namespace.Extended).
          GetSuperProcByIndex (design. tbProc. tbProcIndex);
      design. type := design. tbProc. formalPars;
      design. isStaticCall := TRUE;
      IF design.tbProc.isAbstract THEN
        b.ErrSym(abstractSuperCall, sym);
      END;
      RETURN design;
    ELSE
      b.CheckFunctionOp(design, sym);
      IF ~(design.type IS Sym.Pointer) THEN
        RETURN b.ErrExpr(notPointer, design.sym);
      ELSE
        NEW (i);
        InitDeref (i, sym, design,
                   GetPragmaValue (b, StdPragmas.derefCheck, sym. pos));
        RETURN i
      END
    END;
  END NewDeref;

PROCEDURE (v: Visitor) [ABSTRACT] VisitDeref* (index: Deref);
  END VisitDeref;

PROCEDURE (index: Deref) Accept* (v: Visitor);
  BEGIN
    v. VisitDeref (index)
  END Accept;

(* Operator Class: Entier
   ------------------------------------------------------------------------ *)

PROCEDURE InitEntier (entier: Entier; sym: Symbol; expr: Expression);
  BEGIN
    InitOperator (entier, sym, Predef.GetType (Predef.longint));
    entier. operand := expr;
  END InitEntier;

PROCEDURE (b: Builder) NewEntier (sym: Symbol; expr: Expression): Expression;
  VAR
    entier: Entier;
  BEGIN
    NEW (entier);
    InitEntier (entier, sym, b.AssertReal(expr));
    RETURN entier;
  END NewEntier;

PROCEDURE (v: Visitor) [ABSTRACT] VisitEntier* (entier: Entier);
  END VisitEntier;

PROCEDURE (entier: Entier) Accept* (v: Visitor);
  BEGIN
    v. VisitEntier (entier)
  END Accept;

(* Operator Class: Index
   ------------------------------------------------------------------------ *)

PROCEDURE InitIndex (i: Index; sym: Symbol; array, index: Expression;
                     checkIndex: BOOLEAN);
  BEGIN
    InitOperator (i, sym, array. type(Sym.Array). elementType);
    i.array := array;
    i.index := index;
    i.checkIndex := checkIndex;
  END InitIndex;

PROCEDURE (b: Builder) NewIndex* (sym: Symbol; array, index: Expression): Expression;
  VAR
    i: Index;
    a : Sym.Array; idx : LONGINT;
    checkIndex: BOOLEAN;
  BEGIN
    checkIndex := GetPragmaValue (b, StdPragmas.indexCheck, sym. pos);
    
    b.CheckFunctionOp(array, sym);
    IF (array. type IS Sym.Pointer) THEN
      array := b. NewDeref (sym, array);
    END;
    IF ~(array. type IS Sym.Array) THEN
      RETURN b. ErrExpr (notArray, sym);
    ELSE
      a := array.type(Sym.Array);
      checkIndex := checkIndex & a.hasLengthInfo;
      index := b.AssertInteger(index);
      IF index IS Const THEN
        IF a.isOpenArray THEN
	  (* FIXME: For open arrays, we simply need to verify that the
	     constant index is not negative. MAX(LONGINT) should be a legal
	     index. *)
          idx := b.AssertIntConst(index, 0, MAX(LONGINT));
        ELSE
          idx := b.AssertIntConst(index, 0, a.length);
        END
      END;
      NEW (i);
      InitIndex (i, sym, array, index, checkIndex);
      RETURN i
    END;
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
      variant := lenOpenArrayParam;
    ELSE
      variant := lenOpenArrayHeap
    END;
    
    IF ((variant = lenOpenArrayHeap) OR (variant = lenOpenArrayHeap)) &
       ~arrayVariable.type(Sym.Array).hasLengthInfo THEN
      RETURN b. ErrExpr (noLengthInfo, array.sym);
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

(* Operator Class: NewBlock
   ------------------------------------------------------------------------ *)

PROCEDURE InitNewBlock (new: NewBlock; sym: Symbol; type: Sym.Type;
                        size: Expression);
  BEGIN
    InitOperator (new, sym, type);
    new. size := size;
  END InitNewBlock;

PROCEDURE (b: Builder) NewNewBlock (sym: Symbol; type: Sym.Type;
                                    size: Expression): Expression;
  VAR
    new: NewBlock;
  BEGIN
    NEW (new);
    InitNewBlock (new, sym, type, size);
    RETURN new;
  END NewNewBlock;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNewBlock* (new: NewBlock);
  END VisitNewBlock;

PROCEDURE (new: NewBlock) Accept* (v: Visitor);
  BEGIN
    v. VisitNewBlock (new)
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
        length[i] := b.AssertInteger(args[i+1]);
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

(* Operator Class: Not
   ------------------------------------------------------------------------ *)

PROCEDURE InitNot (neg: Not; sym: Symbol; expr: Expression);
  BEGIN
    InitOperator (neg, sym, expr. type);
    neg.operand := expr;
  END InitNot;

PROCEDURE (b: Builder) NewNot (sym: Symbol; expr: Expression): Expression;
  VAR
    neg: Not;
  BEGIN
    NEW (neg);
    InitNot (neg, sym, expr);
    RETURN neg;
  END NewNot;

PROCEDURE (v: Visitor) [ABSTRACT] VisitNot* (neg: Not);
  END VisitNot;

PROCEDURE (neg: Not) Accept* (v: Visitor);
  BEGIN
    v. VisitNot (neg)
  END Accept;

(* Operator Class: Odd
   ------------------------------------------------------------------------ *)

PROCEDURE InitOdd (odd: Odd; sym: Symbol; expr: Expression);
  BEGIN
    InitOperator (odd, sym, Predef.GetType (Predef.boolean));
    odd. operand := expr;
  END InitOdd;

PROCEDURE (b: Builder) NewOdd (sym: Symbol; expr: Expression): Expression;
  VAR
    odd: Odd;
  BEGIN
    NEW (odd);
    InitOdd (odd, sym, b.AssertInteger(expr));
    RETURN odd;
  END NewOdd;

PROCEDURE (v: Visitor) [ABSTRACT] VisitOdd* (odd: Odd);
  END VisitOdd;

PROCEDURE (odd: Odd) Accept* (v: Visitor);
  BEGIN
    v. VisitOdd (odd)
  END Accept;

(* Operator Class: SelectField
   ------------------------------------------------------------------------ *)

PROCEDURE InitSelectField (sf: SelectField; sym: Symbol; record: Expression;
                           field: Sym.FieldDecl; fieldSym: Symbol);
  BEGIN
    InitOperator (sf, sym, field. type);
    sf.record := record;
    sf.field := field;
    sf.fieldSym := fieldSym;
  END InitSelectField;

PROCEDURE (b: Builder) NewSelectField (sym: Symbol; record: Expression;
                                       field: Sym.FieldDecl; fieldSym: Symbol): SelectField;
  VAR
    i: SelectField;
  BEGIN
    NEW (i);
    InitSelectField (i, sym, record, field, fieldSym);
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
                          checkPointer: BOOLEAN;
                          recordType: Sym.Record; tbProc: Sym.ProcDecl;
                          tbProcSym: Symbol; isStaticCall: BOOLEAN);
  BEGIN
    InitOperator (sp, sym, tbProc. formalPars);
    sp. receiver := receiver;
    sp. checkPointer := checkPointer;
    sp. recordType := recordType;
    sp. tbProc := tbProc;
    sp. tbProcSym := tbProcSym;
    sp. isStaticCall := isStaticCall;
  END InitSelectProc;

PROCEDURE (b: Builder) NewSelectProc (sym: Symbol; receiver: Expression;
                                      recordType: Sym.Record;
                                      tbProc: Sym.ProcDecl;
                                      tbProcSym: Symbol;
                                      isStaticCall: BOOLEAN): SelectProc;
  VAR
    i: SelectProc;
    checkPointer: BOOLEAN;
  BEGIN
    checkPointer := GetPragmaValue (b, StdPragmas.derefCheck, sym. pos);
    
    NEW (i);
    InitSelectProc (i, sym, receiver, checkPointer,
                    recordType, tbProc, tbProcSym, isStaticCall);
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
    InitSetMember (op, sym, b.ValidSetElement(element, set.type), set);
    RETURN op
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
    ASSERT(TR.SameType(left.type, right.type));
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
    InitOperator (range, sym, Predef.GetType (Predef.set));
    range.from := from;
    range.to := to;
  END InitSetRange;

PROCEDURE (b: Builder) NewSetRange* (sym: Symbol; from, to: Expression; isSet : BOOLEAN): Expression;
  VAR
    range: SetRange;
    set : Sym.Type;
  BEGIN
    set := Predef.GetType(Predef.set);
    IF (from = NIL) & (to = NIL) THEN  (* empty set *)
      RETURN b. NewConst (sym, set, Set.New ({}));
    ELSE
      (* only do semantic checks for SETs and not for labels *)
      IF isSet THEN
        from := b.ValidSetElement(from, set);
        to := b.ValidSetElement(to, set);
      END;
      NEW (range);
      InitSetRange (range, sym, from, to);
      RETURN range
    END
  END NewSetRange;

PROCEDURE (v: Visitor) [ABSTRACT] VisitSetRange* (range: SetRange);
  END VisitSetRange;

PROCEDURE (range: SetRange) Accept* (v: Visitor);
  BEGIN
    v. VisitSetRange (range)
  END Accept;

PROCEDURE (range: SetRange) IsEmpty*(): BOOLEAN;
  BEGIN  (* pre: both `from' and `to' are constants *)
    RETURN (range. from(Const). value. Compare (range. to(Const). value) > 0);
  END IsEmpty;

PROCEDURE (range: SetRange) IntersectsWith* (range2: SetRange): BOOLEAN;
  BEGIN
    (* pre: all `from' and `to' are constants, neither of the
       ranges is empty *)
    RETURN
        ~((range.to(Const).value. Compare (range2.from(Const).value) < 0) OR
          (range.from(Const).value. Compare (range2.to(Const).value) > 0))
  END IntersectsWith;

(* Operator Class: Shift
   ------------------------------------------------------------------------ *)

PROCEDURE InitShift (shift: Shift; sym: Symbol; value, by: Expression;
                     rotate: BOOLEAN);
  BEGIN
    InitOperator (shift, sym, value. type);
    shift. value := value;
    shift. by := by;
    shift. rotate := rotate;
  END InitShift;

PROCEDURE (b: Builder) NewShift (sym: Symbol; value, by: Expression;
                                 rotate: BOOLEAN): Expression;
  VAR
    shift: Shift;
    
  PROCEDURE AssertShiftable (expr: Expression): Expression;
    VAR
      v: Integer.Value;
    BEGIN
      IF (expr # b.errorExpr) THEN
        IF ~(TR.IsIntegerType(expr.type) OR
             TR.IsCharType(expr.type) OR
             TR.IsPredefType(expr.type, Predef.byte)) THEN
          b.ErrSym(invalidOpType, expr.sym);
          v := Integer.New(1);
          RETURN NewConst(expr.sym, Predef.SmallestIntType(v), v);
        END;
      END;
      RETURN expr;
    END AssertShiftable;
  
  BEGIN
    NEW (shift);
    InitShift (shift, sym, AssertShiftable(value),
               b.AssertInteger(by), rotate);
    RETURN shift;
  END NewShift;

PROCEDURE (v: Visitor) [ABSTRACT] VisitShift* (shift: Shift);
  END VisitShift;

PROCEDURE (shift: Shift) Accept* (v: Visitor);
  BEGIN
    v. VisitShift (shift)
  END Accept;

(* Operator Class: TypeCast
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeCast (cast: TypeCast; sym: Symbol; type: Sym.Type;
                     expr: Expression);
  BEGIN
    InitOperator (cast, sym, type);
    cast. expr := expr;
  END InitTypeCast;

PROCEDURE (b: Builder) NewTypeCast (sym: Symbol;
                                    typeExpr, expr: Expression): TypeCast;
  VAR
    cast: TypeCast;
    type: Sym.Type;
  BEGIN
    type := b.AssertType(typeExpr);
    IF (type.size < 0) OR (expr.type.size < 0) OR
       (type.size # expr.type.size) THEN
      b.ErrSym(objectSizeMismatch, expr.sym);
    END;
    NEW (cast);
    InitTypeCast (cast, sym, type, expr);
    RETURN cast
  END NewTypeCast;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeCast* (cast: TypeCast);
  END VisitTypeCast;

PROCEDURE (cast: TypeCast) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeCast (cast)
  END Accept;

(* Operator Class: TypeConv
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeConv (conv: TypeConv; sym: Symbol; type: Sym.Type;
                     expr: Expression);
  BEGIN
    InitOperator (conv, sym, type);
    conv. expr := expr;
  END InitTypeConv;

PROCEDURE (b : Builder) NewTypeConv (type: Sym.Type; expr: Expression): Expression;
  VAR
    conv: TypeConv;
  BEGIN
    IF (expr. type = type) THEN
      RETURN expr;                       (* no conversion necessary *)
    ELSE
      IF (expr IS TypeConv) & TR.IncludesType(type, expr.type) THEN
        (* handle transitivity *)
        expr := expr(TypeConv).expr;
      END;
      NEW (conv);
      InitTypeConv (conv, expr.sym, type, expr);
      RETURN conv
    END;
  END NewTypeConv;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeConv* (conv: TypeConv);
  END VisitTypeConv;

PROCEDURE (conv: TypeConv) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeConv (conv)
  END Accept;

PROCEDURE (b: Builder) Widen (VAR expr: Expression; type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE} if the expression @oparam{expr} is structurally
   compatible to @oparam{type}, or can be made to be compatible.  In the latter
   case, @oparam{expr} is replaced with a new constant value or a type
   conversion operator.  There is no loss of information if type conversion is
   applied.  That is, @oparam{expr} is always converted to a ``wider'' type or
   value.

   For the most part, a positive result indicates that

   @itemize @bullet
   @item
   @oparam{expr} can be assigned to a variable with type @oparam{type},
   @item
   @oparam{expr} can be used in an operation @samp{``expr.type'' op ``type''},
   and
   @item
   @oparam{expr} can be passed to a formal value parameter of type
   @oparam{type}.
   @end itemize

   If the @oparam{type} is an open array, result is generally @code{FALSE}.
   The exception to this rule deals with character arrays and character or
   string constants: the constant is promoted to a string constant whose base
   character type matches that of the array.

   Please note that this function does not implement fully either of the rules
   of assignment compatibility or expression compatibility.  Instead, it
   implements @emph{all} rules where an explicit type conversion must be added,
   and a large part of the common subset of the above notion of compatibility.  *)
  BEGIN
    ASSERT (expr.type # NIL);
    ASSERT (type # NIL);
    
    IF TR.SameType(type, expr. type) THEN (* Case 0a *)
      (* Case 0a: a < b if a and b are the same type. *)
      RETURN TRUE;
      
    ELSIF (expr. type IS Sym.FormalPars) THEN (* Case 0b *)
      (* Case 0b: a < b if a and b are procedures with matching parameter
         lists *)
      RETURN (type IS Sym.FormalPars) &
          TR.FormalParamsMatch (type(Sym.FormalPars),
                                 expr. type(Sym.FormalPars), FALSE);
      
    ELSIF TR.IncludesType(type, expr. type) THEN
      (* Case 1: a < b if the type of 'b' includes the type of 'a'. This
         handles numeric and character inclusion. *)
      expr := b. Fold (b. NewTypeConv (type, expr));
      RETURN TRUE;
      
    ELSIF TR.IsExtensionOf(expr. type, type) THEN
      (* Case 2: a < b if the type of 'b' is an extension of the type of
         'a' *)
      RETURN TRUE;
      
    ELSIF IsPredefType (expr. type, Predef.nil) & TR.IsNilCompatible (type) THEN
      (* Case 3: NIL < pointer value *)
      (* Case 4: NIL < procedure value *)
      RETURN TRUE;
      
    ELSIF (expr. type IS Sym.Pointer) &
          TR.IsPredefType (type, Predef.ptr) THEN
      (* Case 5: pointer value < SYSTEM.PTR *)
      RETURN TRUE;
      
    ELSIF (expr IS Const) &
          TR.IsStringConst (type) &
          (TR.BaseCharType (expr. type) # NIL) &
          TR.IncludesType(TR.BaseCharType (type),
                           TR.BaseCharType (expr. type)) THEN
      (* Case 6: char const and string const < string const *)
      expr := b. Fold (b. NewTypeConv (type, expr));
      RETURN TRUE;

    ELSIF (expr IS Const) &
          (TR.BaseCharType (expr. type) # NIL) &
          (type IS Sym.Array) &
          TR.IsCharType (type(Sym.Array). elementType) THEN
      (* Case 7: string const < ARRAY [n] OF char *)
      RETURN b. Widen(expr, TR.MatchingStringConst(type(Sym.Array). elementType));

    ELSIF (expr IS Const) &
          (type = b. stringType) &
          (TR.BaseCharType(expr. type) # NIL) THEN
      (* Case 8: char const and string const < STRING *)
      expr := b. NewTypeConv (type, expr);
      RETURN TRUE;
      
    ELSE
      RETURN FALSE;
    END;
  END Widen;

PROCEDURE (b: Builder) WidenForAssign (VAR expr: Expression;
                                       type: Sym.Type): BOOLEAN;
(**Takes an expression and a type, and tries to make the expression's value
   assignment compatible to the type.  Returns TRUE on success.

   @precond
   If @oparam{expr} is an argument passed to a formal parameter, then
   @oparam{type} is not an open array type.
   @end precond
   *)
  VAR
    oldExpr: Expression;
    
  PROCEDURE LengthOk (): BOOLEAN;
    BEGIN
      IF TR.IsStringConst (expr. type) THEN
        IF type(Sym.Array). isOpenArray THEN
          RETURN FALSE;
        ELSE
          RETURN (expr(Const). value(LString.Value). Length() <
                  type(Sym.Array). length);
        END;
      ELSE
        RETURN TRUE;
      END;
    END LengthOk;
  
  BEGIN
    oldExpr := expr;
    IF IsPredefType (type, Predef.byte) &
         TR.IsByteCompatible (expr. type) OR
       b. Widen (expr, type) & LengthOk () THEN
      RETURN TRUE;
    ELSE
      expr := oldExpr;
      RETURN FALSE;
    END;
  END WidenForAssign;

PROCEDURE (b : Builder) WidenToCommon(VAR left, right : Expression) : BOOLEAN;
(**Returns true if expressions @oparam{left} and @oparam{right} can be made
   compatible.  If one operand has ``wider'' type than the other, the smaller
   operand is adjusted to have the type of the larger operand and the function
   will return @code{TRUE}. 
   
   A special rule applies to constants of character or string type. If there is
   a common type that is ``wider'' than each of the operands, both operands
   will be widened to that common type. *)

VAR
  base : Sym.Type;

  PROCEDURE CommonBase(t1, t2 : Sym.Type) : Sym.Type;
  (* Find a common type to which types @oparam{t1} and @oparam{t2} may be
  widened. 
  
  PRE: ~ ( (t1 < t2) OR (t2 < t1) ) 
  *)
  VAR 
    base1, base2 : Sym.Type;
  BEGIN
    base1 := TR.BaseCharType(t1);
    base2 := TR.BaseCharType(t2);
    IF (base1 # NIL) & (base2 # NIL) THEN
      IF TR.IncludesType(base2, base1) THEN
        base1 := base2;
      END;
      RETURN TR.MatchingStringConst(base1);
    ELSE
      RETURN NIL;
    END;
  END CommonBase;

BEGIN
  IF b.Widen(left, right.type) OR b.Widen(right, left.type) THEN
    RETURN TRUE;
  ELSIF (left IS Const) & (right IS Const) THEN
    base := CommonBase(left.type, right.type);
    IF base # NIL THEN
      (* Widen both operands to the common base type *)
      ASSERT(b.Widen(left, base) & b.Widen(right, base));
      RETURN TRUE;
    END;
  END;
  RETURN FALSE
END WidenToCommon;

PROCEDURE MakeAssignmentCompatible (b: Builder; sym: Symbol;
                                    VAR expr: Expression;
                                    type: Sym.Type);
(**Takes an expression and a type, and tries to make the expression's value
   assignment compatible to the type.  If this is not possible, an error
   is reported.  *)
  BEGIN
    IF ~b. WidenForAssign (expr, type) THEN
      b.ErrSym(incompatibleAssignment, sym);
    END;
  END MakeAssignmentCompatible;

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
    IF ~(design.type IS Sym.Record) OR
       ~design.type(Sym.Record).hasDescriptor THEN
      b.ErrSym(noTypeTag, design.sym);
    END;
    
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
                        checkPointer: BOOLEAN;
                        origExpr: Expression; origType: TypeRef);
  BEGIN
    InitOperator (test, sym, Predef.GetType(Predef.boolean));
    test. expr := expr;
    test. referenceType := referenceType;
    test. checkPointer := checkPointer;
    test. origExpr := origExpr;
    test. origType := origType;
  END InitTypeTest;

PROCEDURE (b: Builder) NewTypeTest* (sym: Symbol; expr, referenceType: Expression): Expression;
  VAR
    test: TypeTest;
    refType: Sym.Type;
    typeRef: TypeRef;
    origExpr: Expression;
    checkPointer: BOOLEAN;

  PROCEDURE HasDynamicType (expr: Expression): BOOLEAN;
    VAR
      type: Sym.Type;
    BEGIN
      type := expr.type;
      WITH type: Sym.Record DO
        RETURN ~(expr IS Var) OR
            (expr(Var).decl(Sym.VarDecl).isVarParam &
             expr(Var).decl(Sym.VarDecl).supplementArgs);
      | type: Sym.Pointer DO
        RETURN (type.baseType IS Sym.Record) & ~type.isStatic;
      ELSE
        RETURN FALSE;
      END;
    END HasDynamicType;
  
  BEGIN
    refType := b. AssertType (referenceType);
    IF (refType = NIL) THEN
      RETURN b. errorExpr;
    ELSIF ~TR.IsExtensionOf (refType, expr. type) THEN
      RETURN b. ErrExpr (notExtensionOfLHS, referenceType. sym);
    ELSIF ~HasDynamicType(expr) THEN
      (* The test for TR.IsExtensionOf restricts the type of the variable to
         record or pointer type.  We must also check that the variable has
         a dynamic type that can differ from its static one.  *)
      RETURN b. ErrExpr (noDynamicType, expr.sym);
    ELSE
      origExpr := expr;
      checkPointer := GetPragmaValue (b, StdPragmas.derefCheck, sym. pos);
      IF (expr IS Deref) THEN
        expr := expr(Deref). pointer;
      ELSIF (expr. type IS Sym.Pointer) THEN
        refType := refType(Sym.Pointer). baseType;
      END;
      NEW (test);
      IF (referenceType IS TypeRef) THEN
        typeRef := referenceType(TypeRef);
      ELSE
        typeRef := NIL;
      END;
      InitTypeTest (test, sym, expr, refType(Sym.Record), checkPointer,
                    origExpr, typeRef);
      RETURN test;
    END;
  END NewTypeTest;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeTest* (test: TypeTest);
  END VisitTypeTest;

PROCEDURE (test: TypeTest) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeTest (test)
  END Accept;

(* Operator Class: TypeGuard
   ------------------------------------------------------------------------ *)

PROCEDURE InitTypeGuard (guard: TypeGuard; sym: Symbol;
                         type: Sym.Type; test: TypeTest;
                         checkPointer, checkType: BOOLEAN);
  BEGIN
    InitOperator (guard, sym, type);
    guard. test := test;
    guard. checkPointer := checkPointer;
    guard. checkType := checkType;
  END InitTypeGuard;

PROCEDURE (b : Builder) NewTypeGuard(sym: Symbol; design: Expression;
                                     ref: TypeRef): Expression;
VAR 
  guardType : Sym.Type;
  guard : TypeGuard;
  test : Expression;
BEGIN
  guardType := ref. decl(Sym.TypeDecl). type;
  b.CheckFunctionOp(design, sym);
  test := b.NewTypeTest(sym, design, ref);
  IF test IS TypeTest THEN
    NEW(guard);
    InitTypeGuard(guard, sym, guardType, test(TypeTest),
                GetPragmaValue (b, StdPragmas.derefCheck, sym. pos),
                GetPragmaValue (b, StdPragmas.typeGuard, sym. pos));
    RETURN guard;
  ELSE
    RETURN test;
  END;
END NewTypeGuard;

PROCEDURE (v: Visitor) [ABSTRACT] VisitTypeGuard* (test: TypeGuard);
  END VisitTypeGuard;

PROCEDURE (test: TypeGuard) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeGuard (test)
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

PROCEDURE InitModuleRef (modRef: ModuleRef; name: Symbol; type: Sym.Type;
                         decl: Sym.Module);
  BEGIN
    InitReference (modRef, name, type, decl);
  END InitModuleRef;

PROCEDURE (b: Builder) NewModuleRef (name: Symbol; decl: Sym.Module): ModuleRef;
  VAR
    modRef: ModuleRef;
  BEGIN
    NEW (modRef);
    InitModuleRef (modRef, name, b. moduleType, decl);
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

PROCEDURE (b: Builder) NewAssert (sym: Symbol; predicate, code: Expression;
                                  disabled: BOOLEAN): Assert;
  VAR
    assert: Assert;
    c: LONGINT;
  BEGIN
    NEW (assert);
    IF (predicate # NIL) THEN
      predicate := b.AssertBoolean(predicate);
    END;
    IF (code = NIL) THEN
      c := Predef.defaultAssertCode;
    ELSE
      c := b.AssertIntConst(code, Predef.minExitCode, Predef.maxExitCode);
    END;
    InitAssert (assert, sym, predicate, c, disabled);
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

PROCEDURE (b: Builder) AssertVar (expr: Expression);
  BEGIN
    WITH expr: Var DO
      IF TR.IsReadOnly (b. module, expr. decl) THEN
        b. ErrSym (importedReadOnly, expr. sym);
(*  FIXME... disabled, because the writer classes use VAR x:ARRAY OF BYTE
             as value input parameters
      ELSIF (expr.decl IS Sym.VarDecl) & expr.decl(Sym.VarDecl).isReadOnly THEN
        b.ErrSym(readOnlyParameter, expr.sym);*)
      END;
    | expr: Deref DO
      (* a pointer dereference is always a variable *)
    | expr: Index DO
      b. AssertVar (expr. array);   (* check that value is writable *)
    | expr: SelectField DO
      b. AssertVar (expr. record);  (* check that value is writable *)
      IF TR.IsReadOnly (b. module, expr. field) THEN
        b. ErrSym (importedReadOnly, expr. fieldSym);
      END;
    | expr: TypeGuard DO
      b. AssertVar(expr. test. expr);	(* check that value is writable *)
    ELSE
      b. ErrSym (notVariable, expr. sym);
    END;
  END AssertVar;

PROCEDURE (b: Builder) NewAssignment* (sym: Symbol;
                                       variable, value: Expression): Statement;
  VAR
    assignment: Assignment;
  BEGIN
    b. AssertVar (variable);
    MakeAssignmentCompatible (b, sym, value, variable. type);
    IF TR.IsStringConst (value. type) THEN
      (* assigning a string constant: create CopyString opcode *)
      RETURN b. NewCopyString (sym, value, variable,
                               b. Fold (b. NewLen (sym, variable, 0)));
    ELSIF (value. type IS Sym.Array) OR (value. type IS Sym.Record) THEN
      (* assigning a structured value: create Copy opcode *)
      RETURN b. NewCopy (sym, value, variable);
    ELSE
      NEW (assignment);
      InitAssignment (assignment, sym, variable, value);
      RETURN assignment
    END;
  END NewAssignment;

PROCEDURE (v: Visitor) [ABSTRACT] VisitAssignment* (assignment: Assignment);
  END VisitAssignment;

PROCEDURE (assignment: Assignment) Accept* (v: Visitor);
  BEGIN
    v. VisitAssignment (assignment)
  END Accept;

(* Statement Class: AssignOp
   ------------------------------------------------------------------------ *)

PROCEDURE InitAssignOp (ao: AssignOp; sym: Symbol; op: Expression);
  BEGIN
    WITH op: BinaryArith DO
      InitAssignment (ao, sym, op. left, op);
    | op: ChangeElement DO
      InitAssignment (ao, sym, op. set, op);
    END;
  END InitAssignOp;

PROCEDURE (b: Builder) NewAssignOp (sym: Symbol; op: Expression): Expression;
  VAR
    i: AssignOp;
  BEGIN
    WITH op: Const DO
      RETURN b. errorExpr;               (* bail out, op is errorExpr *)
    ELSE
      NEW (i);
      InitAssignOp (i, sym, op);
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

(* Statement Class: Copy
   ------------------------------------------------------------------------ *)

PROCEDURE InitCopy (cp: Copy; sym: Symbol; source, dest: Expression;
                    checkDynamicType: BOOLEAN);
  BEGIN
    InitStatement (cp, sym);
    cp. source := source;
    cp. dest := dest;
    cp. checkDynamicType := checkDynamicType;
  END InitCopy;

PROCEDURE (b: Builder) NewCopy* (sym: Symbol; source, dest: Expression): Copy;
  VAR
    cp: Copy;
    checkDynamicType: BOOLEAN;

  PROCEDURE HasDynamicType (dest: Expression): BOOLEAN;
    BEGIN
      IF (dest. type IS Sym.Record) & dest.type(Sym.Record).hasDescriptor THEN
        IF (dest IS Deref) THEN
          RETURN TRUE;
        ELSIF (dest IS Var) THEN
          RETURN dest(Var). decl(Sym.VarDecl). isVarParam;
        END;
      END;
      RETURN FALSE;
    END HasDynamicType;
  
  BEGIN
    checkDynamicType :=
        HasDynamicType (dest) &
        GetPragmaValue (b, StdPragmas.typeGuard, sym. pos);
    
    NEW (cp);
    InitCopy (cp, sym, source, dest, checkDynamicType);
    RETURN cp
  END NewCopy;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCopy* (cp: Copy);
  END VisitCopy;

PROCEDURE (cp: Copy) Accept* (v: Visitor);
  BEGIN
    v. VisitCopy (cp)
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

(* Statement Class: CopyString
   ------------------------------------------------------------------------ *)

PROCEDURE InitCopyString (cp: CopyString; sym: Symbol;
                          source, dest, maxLength: Expression);
  BEGIN
    InitStatement (cp, sym);
    cp. source := source;
    cp. dest := dest;
    cp. maxLength := maxLength;
  END InitCopyString;

PROCEDURE (b: Builder) NewCopyString* (sym: Symbol; 
                                       source, dest, maxLength: Expression): CopyString;
  VAR
    cp: CopyString;
    baseChar: Sym.Type;
    ok: BOOLEAN;
  BEGIN
    b.AssertVar(dest);
    IF ~TR.IsArrayOfChar(dest.type, TRUE) THEN
      b.ErrSym(notCharacterArray, dest.sym);
    END;
    
    IF (source IS Const) THEN
      (* make sure that any character constant source is converted into
         its equivalent string constant form; this way, the copy operation
         doesn't need to deal with single characters *)
      baseChar := TR.BaseCharType (dest. type);
      IF (baseChar = NIL) THEN
        b.ErrSym(notCharacterArray, source.sym);
      ELSE
        ok := b. Widen (source, TR.MatchingStringConst (baseChar));
      END;
    ELSIF ~TR.IsArrayOfChar(source.type, TRUE) THEN
      b.ErrSym(notCharacterArray, source.sym);
    END;
    
    NEW (cp);
    InitCopyString (cp, sym, source, dest, b. Fold (maxLength));
    RETURN cp
  END NewCopyString;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCopyString* (cp: CopyString);
  END VisitCopyString;

PROCEDURE (cp: CopyString) Accept* (v: Visitor);
  BEGIN
    v. VisitCopyString (cp)
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
    IF (step = NIL) THEN
      step := b. NewConst
          (sym, Predef.GetType (Predef.shortint), Integer.New (1));
    END;

    IF ~(var IS Var) THEN
      b. ErrSym (notVariable, var. sym);
    ELSIF ~TR.IsIntegerType (var. type) THEN
      b. ErrSym (notInteger, var. sym);
    ELSIF ~b. Widen (step, var. type) THEN
      b. ErrSym (invalidStepType, step. sym);
    ELSE
      MakeAssignmentCompatible (b, start. sym, start, var. type);
      MakeAssignmentCompatible (b, end. sym, end, var. type);
      step := b. AssertConst (step);
      IF TR.IsIntegerType (step. type) &
         (Integer.zero.Compare (step(Const). value) = 0) THEN
        b. ErrSym (stepIsZero, step. sym);
      END;
    END;
    
    NEW (forStatm);
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
    InitIfStatm (ifStatm, sym, b. AssertBoolean (guard), pathTrue, pathFalse);
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
    range: SetRange;
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (labels^)-1 DO
      range := labels[i](SetRange);
      range.from := b. AssertConst (range. from);
      range.to := b. AssertConst (range. to);
    END;
    
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

PROCEDURE (case: Case) CheckLabels (b: Builder; type: Sym.Type;
                                    caseList: CaseList);
  VAR
    range: SetRange;
    i, j, deleted: LONGINT;
    new: CaseLabels;
    inUse: BOOLEAN;

  PROCEDURE IntersectsWith (range: SetRange; list: CaseLabels;
                            end: LONGINT): BOOLEAN;
    VAR
      i: LONGINT;
    BEGIN
      i := 0;
      WHILE (i # end) DO
        IF (list[i] # NIL) & range. IntersectsWith (list[i](SetRange)) THEN
          RETURN TRUE;
        END;
        INC (i);
      END;
      RETURN FALSE;
    END IntersectsWith;
  
  BEGIN
    deleted := 0;
    FOR i := 0 TO LEN (case. labels^)-1 DO
      range := case. labels[i](SetRange);
      IF ~b. Widen (range. from, type) THEN
        b. ErrSym (labelNotInSelect, range. from. sym);
        case. labels[i] := NIL; INC (deleted); (* get rid of the problem *)
      ELSIF ~b. Widen (range. to, type) THEN
        b. ErrSym (labelNotInSelect, range. to. sym);
        case. labels[i] := NIL; INC (deleted); (* get rid of the problem *)
      ELSIF range. IsEmpty() THEN
        (* `from' is larger than `to': eliminate entry *)
        case. labels[i] := NIL; INC (deleted);
      ELSE
        inUse := FALSE;
        j := 0;
        WHILE (caseList[j] # case) & ~inUse DO
          inUse := IntersectsWith (range, caseList[j]. labels,
                                   LEN (caseList[j]. labels^));
          INC (j);
        END;
        inUse := inUse OR IntersectsWith (range, case. labels, i);
        IF inUse THEN
          b. ErrSym (duplicateLabel, range. sym);
        END;
      END;
    END;

    IF (deleted # 0) THEN
      NEW (new, LEN (case. labels^)-deleted);
      j := -1;
      FOR i := 0 TO LEN (new^)-1 DO
        REPEAT
          INC (j);
        UNTIL (case. labels[j] # NIL);
        new[i] := case. labels[j];
      END;
      case. labels := new;
    END;
  END CheckLabels;

(* Statement Class: CaseStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitCaseStatm (caseStatm: CaseStatm; sym: Symbol; select: Expression;
                         caseList: CaseList; default: StatementSeq;
                         checkMatch: BOOLEAN);
  BEGIN
    InitStatement (caseStatm, sym);
    caseStatm. select := select;
    caseStatm. caseList := caseList;
    caseStatm. default := default;
    caseStatm. checkMatch := checkMatch;
  END InitCaseStatm;

PROCEDURE (b: Builder) NewCaseStatm* (sym: Symbol; select: Expression;
                                      caseList: CaseList; default: StatementSeq): CaseStatm;
  VAR
    caseStatm: CaseStatm;
    i: LONGINT;
  BEGIN
    NEW (caseStatm);
    IF ~TR.IsValidCaseSelector (select. type) THEN
      b. ErrSym (invalidCaseSelector, select. sym);
    ELSE
      FOR i := 0 TO LEN (caseList^)-1 DO
        caseList[i]. CheckLabels (b, select. type, caseList);
      END;
    END;
    InitCaseStatm (caseStatm, sym, select, caseList, default,
                   GetPragmaValue (b, StdPragmas.caseSelectCheck, sym. pos));
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

(* Statement Class: MoveBlock
   ------------------------------------------------------------------------ *)

PROCEDURE InitMoveBlock (move: MoveBlock; sym: Symbol;
                         source, dest, size: Expression);
  BEGIN
    InitStatement (move, sym);
    move. source := source;
    move. dest := dest;
    move. size := size;
  END InitMoveBlock;

PROCEDURE (b: Builder) NewMoveBlock* (sym: Symbol; source, dest: Expression;
                                      size: Expression): MoveBlock;
  VAR
    move: MoveBlock;
  BEGIN
    NEW (move);
    InitMoveBlock (move, sym,
                   b.AssertInteger(source),
                   b.AssertInteger(dest),
                   b.AssertInteger(size));
    RETURN move
  END NewMoveBlock;

PROCEDURE (v: Visitor) [ABSTRACT] VisitMoveBlock* (move: MoveBlock);
  END VisitMoveBlock;

PROCEDURE (move: MoveBlock) Accept* (v: Visitor);
  BEGIN
    v. VisitMoveBlock (move)
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
    InitRepeatStatm (repeatStatm, sym, body, b. AssertBoolean (exitCondition));
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
    InitWhileStatm (whileStatm, sym, b. AssertBoolean (guard), body);
    RETURN whileStatm
  END NewWhileStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitWhileStatm* (whileStatm: WhileStatm);
  END VisitWhileStatm;

PROCEDURE (whileStatm: WhileStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWhileStatm (whileStatm)
  END Accept;

(* Statement Class: WithStatm
   ------------------------------------------------------------------------ *)

PROCEDURE InitWithStatm (withStatm: WithStatm; sym: Symbol; guard: Expression;
                         pathTrue, pathFalse: StatementSeq;
                         checkMatch: BOOLEAN);
  BEGIN
    InitStatement (withStatm, sym);
    withStatm. guard := guard;
    withStatm. pathTrue := pathTrue;
    withStatm. pathFalse := pathFalse;
    withStatm. checkMatch := checkMatch;
  END InitWithStatm;

PROCEDURE (b: Builder) NewWithStatm* (sym: Symbol; guard: Expression;
                                      pathTrue, pathFalse: StatementSeq): WithStatm;
  VAR
    withStatm: WithStatm;
    checkMatch: BOOLEAN;
  BEGIN
    checkMatch := GetPragmaValue (b, StdPragmas.typeGuard, sym. pos);
    
    NEW (withStatm);
    InitWithStatm (withStatm, sym, guard, pathTrue, pathFalse, checkMatch);
    RETURN withStatm
  END NewWithStatm;

PROCEDURE (v: Visitor) [ABSTRACT] VisitWithStatm* (withStatm: WithStatm);
  END VisitWithStatm;

PROCEDURE (withStatm: WithStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWithStatm (withStatm)
  END Accept;



(* Class: Procedure
   ------------------------------------------------------------------------ *)

PROCEDURE (b: Builder) CheckExit (procDecl: Sym.ProcDecl;
                                  statmSeq: StatementSeq;
                                  currentLoop: LoopStatm);
(* Check that an @code{EXIT} appears within a @code{LOOP}, and that the
   result value of a @code{RETURN} statement is valid.  *)
  
  PROCEDURE CheckStatmSeq (statmSeq: StatementSeq);
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
        | statm: Copy DO
          (* nothing *)
        | statm: CopyParameter DO
          (* nothing *)
        | statm: CopyString DO
          (* nothing *)
        | statm: Exit DO
          IF (currentLoop = NIL) THEN
            b. ErrSym (exitOutsideLoop, statm. sym);
          ELSE
            statm. loop := currentLoop;
          END;
        | statm: ForStatm DO
          CheckStatmSeq (statm. body);
        | statm: IfStatm DO
          CheckStatmSeq (statm. pathTrue);
          CheckStatmSeq (statm. pathFalse);
        | statm: Case DO
          CheckStatmSeq (statm. statmSeq);
        | statm: CaseStatm DO
          FOR i := 0 TO LEN (statm. caseList^)-1 DO
            CheckStatmSeq (statm. caseList[i]. statmSeq);
          END;
          CheckStatmSeq (statm. default);
        | statm: LoopStatm DO
          b. CheckExit (procDecl, statm. body, statm);
        | statm: MoveBlock DO
          (* nothing *)
        | statm: RepeatStatm DO
          CheckStatmSeq (statm. body);
        | statm: Return DO
          IF (procDecl = NIL) OR
             (procDecl. formalPars. resultType = NIL) THEN
            (* module body or non-function procedure *)
            IF (statm. result # NIL) THEN
              b. ErrSym (returnWithResult, statm. result. sym);
            END;
          ELSE
            (* function procedure *)
            IF (statm. result = NIL) THEN
              b. ErrSym (returnWithoutResult, statm. sym);
            ELSE
              MakeAssignmentCompatible (b, statm. result. sym, statm. result,
                                        procDecl. formalPars. resultType);
            END;
          END;
          (* nothing *)
        | statm: WhileStatm DO
          CheckStatmSeq (statm. body);
        | statm: WithStatm DO
          CheckStatmSeq (statm. pathTrue);
          CheckStatmSeq (statm. pathFalse);
        END;
      END CheckStatm;
    
    BEGIN
      IF (statmSeq # NIL) THEN
        FOR i := 0 TO LEN (statmSeq^)-1 DO
          CheckStatm (statmSeq[i])
        END;
      END;
    END CheckStatmSeq;

  BEGIN
    CheckStatmSeq (statmSeq);
  END CheckExit;

PROCEDURE InitProcedure* (p: Procedure; sym: Symbol; 
                          decl: Sym.ProcDecl; statmSeq: StatementSeq;
                          checkFunctionResult: BOOLEAN);
  BEGIN
    InitNode (p, sym);
    p. decl := decl;
    p. statmSeq := statmSeq;
    p. checkFunctionResult := checkFunctionResult;
  END InitProcedure;

PROCEDURE (b: Builder) NewProcedure* (sym: Symbol;
                                      decl: Sym.ProcDecl;
                                      statmSeq: StatementSeq;
                                      hasBegin: BOOLEAN): Procedure;
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
        IF fpar. hasLocalCopy THEN
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
    IF decl.isAbstract & hasBegin THEN
      b.ErrSym(abstractWithBegin, sym);
    END;
    b. CheckExit (decl, statmSeq, NIL);
    
    NEW (p);
    statmSeq := AddSetupCode (sym, decl, statmSeq);
    InitProcedure (p, sym, decl, statmSeq,
                   GetPragmaValue (b, StdPragmas.functionResultCheck,
                                   decl. name. pos));
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
    
  PROCEDURE UnusedDeclarations (item: Sym.Item);
    VAR
      nested: Sym.Item;
    BEGIN
      WITH item: Sym.Declaration DO
        (* emit a warning for declarations that are not exported and have
           a usage count of zero; parameters are ignored, as are procedure
           forward declarations and type-bound procedures *)
        IF (item.usageCount = 0) &
           (item.exportMark = Sym.nameNotExported) &
           (~(item IS Sym.VarDecl) OR ~item(Sym.VarDecl).isParameter) &
           (~(item IS Sym.ProcDecl) OR
            ~(item(Sym.ProcDecl).isForwardDecl OR
              item(Sym.ProcDecl).isTypeBound)) THEN
          b.WarnName(unusedDeclaration, item.name);
        END;
      ELSE  (* ignore *)
      END;
      
      nested := item.nestedItems;
      WHILE (nested # NIL) DO
        UnusedDeclarations(nested);
        nested := nested.nextNested;
      END;
    END UnusedDeclarations;

  BEGIN
    b. CheckExit (NIL, statmSeq, NIL);
    UnusedDeclarations(decl);
    
    NEW (m);
    InitModule (m, sym, name, procList,
                b. NewProcedure (sym, decl. bodyDecl, statmSeq, TRUE));
    RETURN m
  END NewModule;

PROCEDURE (v: Visitor) [ABSTRACT] VisitModule* (module: Module);
  END VisitModule;

PROCEDURE (m: Module) Accept* (v: Visitor);
  BEGIN
    v. VisitModule (m)
  END Accept;

PROCEDURE (m: Module) Destroy*;
(**Zaps the whole data structure.  This should help the conservative gc to
   classify its components as garbage.  *)
  VAR
    i: LONGINT;
    
  PROCEDURE ^ E (VAR n: Expression);
  PROCEDURE ^ S (VAR n: Statement);
    
  PROCEDURE EList (VAR e: ExpressionList);
    VAR
      i: LONGINT;
    BEGIN
      IF (e # NIL) THEN
        FOR i := 0 TO LEN(e^)-1 DO
          E(e[i]);
        END;
        e := NIL;
      END;
    END EList;
  
  PROCEDURE E (VAR n: Expression);
    VAR
      expr: Expression;
    BEGIN
      IF (n # NIL) THEN
        n.type := NIL;
        WITH n: Const DO
          n.value := NIL;
        | n: Operator DO
          WITH n: Abs DO
            E(n.operand);
          | n: Adr DO
            E(n.design);
          | n: Ash DO
            E(n.value);
            E(n.exp);
          | n: BinaryArith DO
            E(n.left);
            E(n.right);
          | n: BooleanOp DO
            E(n.left);
            E(n.right);
          | n: Cap DO
            E(n.operand);
          | n: Compare DO
            E(n.left);
            E(n.right);
          | n: Concat DO
            EList(n.strings);
          | n: ChangeElement DO
            E(n.set);
            E(n.element);
          | n: Deref DO
            E(n.pointer);
            n.derefType := NIL;
          | n: Entier DO
            E(n.operand);
          | n: Index DO
            E(n.array);
            E(n.index);
          | n: Len DO
            E(n.array);
            E(n.arrayVariable);
            n.dim := 0;
          | n: Negate DO
            E(n.operand);
          | n: NewBlock DO
            E(n.size);
          | n: NewObject DO
            EList(n.length);
          | n: Not DO
            E(n.operand);
          | n: Odd DO
            E(n.operand);
          | n: SelectField DO
            E(n.record);
            n.field := NIL;
            n.fieldSym := NIL;
          | n: SelectProc DO
            E(n.receiver);
            n.recordType := NIL;
            n.tbProc := NIL;
            n.tbProcSym := NIL;
          | n: SetMember DO
            E(n.element);
            E(n.set);
          | n: SetOp DO
            E(n.left);
            E(n.right);
          | n: SetRange DO
            E(n.from);
            E(n.to);
          | n: Shift DO
            E(n.value);
            E(n.by);
          | n: TypeCast DO
            E(n.expr);
          | n: TypeConv DO
            E(n.expr);
          | n: TypeTag DO
            E(n.design);
          | n: TypeTest DO
            E(n.expr);
            n.referenceType := NIL;
            E(n.origExpr);
            n.origType := NIL;
          | n: TypeGuard DO
            expr := n.test;
            E(expr);
            n.test := NIL;
          ELSE
            Log.Type("--- operator type: ", n);
            ASSERT(FALSE);
          END;
        | n: Reference DO
          n.decl := NIL;
        | n: Statement DO                (* function call *)
          S(n);
        ELSE
          Log.Type("--- expression type: ", n);
          ASSERT(FALSE);
        END;
        n := NIL;
      END;
    END E;

  PROCEDURE SSeq (VAR n: StatementSeq);
    VAR
      i: LONGINT;
    BEGIN
      IF (n # NIL) THEN
        FOR i := 0 TO LEN(n^)-1 DO
          S(n[i]);
        END;
      END;
    END SSeq;
  
  PROCEDURE S (VAR n: Statement);
    VAR
      i: LONGINT;
    BEGIN
      IF (n # NIL) THEN
        WITH n: Assert DO
          E(n.predicate);
          n.code := 0;
        | n: Assignment DO
          E(n.variable);
          E(n.value);
        | n: Call DO
          E(n.design);
          EList(n.arguments);
          n.formalPars := NIL;
        | n: Copy DO
          E(n.source);
          E(n.dest);
        | n: CopyParameter DO
          n.param := NIL;
        | n: CopyString DO
          E(n.source);
          E(n.dest);
          E(n.maxLength);
        | n: Exit DO
          n.loop := NIL;
        | n: ForStatm DO
          E(n.var);
          E(n.start);
          E(n.end);
          E(n.step);
          SSeq(n.body);
        | n: IfStatm DO
          E(n.guard);
          SSeq(n.pathTrue);
          SSeq(n.pathFalse);
        | n: CaseStatm DO
          E(n.select);
          FOR i := 0 TO LEN(n.caseList^)-1 DO
            n.caseList[i].labels := NIL;
            SSeq(n.caseList[i].statmSeq);
            n.caseList[i] := NIL;
          END;
          n.caseList := NIL;
          SSeq(n.default);
        | n: LoopStatm DO
          SSeq(n.body);
        | n: MoveBlock DO
          E(n.source);
          E(n.dest);
          E(n.size);
        | n: RepeatStatm DO
          SSeq(n.body);
          E(n.exitCondition);
        | n: Return DO
          E(n.result);
        | n: WhileStatm DO
          E(n.guard);
          SSeq(n.body);
        | n: WithStatm DO
          E(n.guard);
          SSeq(n.pathTrue);
          SSeq(n.pathFalse);
        END;
        n := NIL;
      END;
    END S;
  
  BEGIN
    m.name := NIL;
    FOR i := 0 TO LEN(m.procList^)-1 DO
      m.procList[i].decl := NIL;
      SSeq(m.procList[i].statmSeq);
      m.procList[i] := NIL;
    END;
    m.procList := NIL;

    m.moduleBody.decl := NIL;
    SSeq(m.moduleBody.statmSeq);
    m.moduleBody := NIL;

    m := NIL;
  END Destroy;


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

PROCEDURE InitBuilder* (b: Builder; module: Sym.Module;
                        pragmaHistory: Pragmas.History; errList: Error.List;
                        fold : ConstFold);
  VAR
    string: Sym.Item;
    
  PROCEDURE NewTypeType (parent: Sym.Item; position: Sym.Position): TypeType;
    VAR
      typeType: TypeType;
    BEGIN
      NEW (typeType);
      Sym.InitType (typeType, parent, position);
      RETURN typeType;
    END NewTypeType;
  
  PROCEDURE NewModuleType (parent: Sym.Item; position: Sym.Position): ModuleType;
    VAR
      moduleType: ModuleType;
    BEGIN
      NEW (moduleType);
      Sym.InitType (moduleType, parent, position);
      RETURN moduleType;
    END NewModuleType;
  
  BEGIN
    b. module := module;
    b. pragmaHistory := pragmaHistory;
    b. errList := errList;
    b. errorExpr := NewConst (BasicList.NewSymbol (NIL, -1),
                              Predef.GetType(Predef.void),
                              Boolean.New (FALSE));
    b. typeType := NewTypeType (NIL, NIL);
    b. moduleType := NewModuleType (NIL, NIL);
    b. lastError := NIL;
    b. constFold := fold;
    fold. builder := b;

    string := CreateNamespace.ResolveQualident(module.ns, module,
                                               Predef.nameStringModule,
                                               Predef.nameStringType);
    IF (string = NIL) THEN
      b. stringType := NIL;
    ELSE
      b. stringType := string(Sym.TypeDecl).type;
    END;
  END InitBuilder;

PROCEDURE NewBuilder* (module: Sym.Module; pragmaHistory: Pragmas.History;
                       errList: Error.List; constFold: ConstFold): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b, module, pragmaHistory, errList, constFold);
    RETURN b
  END NewBuilder;


PROCEDURE (b: Builder) StartTypeGuard* (typeTest: TypeTest;
                                        VAR namespace: Sym.Namespace);
  VAR
    var: Sym.VarDecl;
    nested: Namespace.Nested;
    da: Sym.DeclarationArray;
  BEGIN
    IF (typeTest.expr IS Var) THEN
      var := typeTest. expr(Var). decl(Sym.VarDecl);
      NEW (da, 1);
      da[0] := NewGuardedVar (var, typeTest. origType. decl(Sym.TypeDecl). type);
      nested := Namespace.NewNested (da, 1);
      nested. SetEnclosingNamespace (namespace(Namespace.Nested));
      namespace := nested;
      RETURN;
    ELSE
      b. ErrSym (notVariable, typeTest.expr.sym);
    END;

    (* fall through: install empty namespace, so that EndTypeGuard works *)
    NEW (da, 0);
    nested := Namespace.NewNested (da, 0);
    nested. SetEnclosingNamespace (namespace(Namespace.Nested));
    namespace := nested;
  END StartTypeGuard;

PROCEDURE (b: Builder) EndTypeGuard* (VAR namespace: Sym.Namespace);
  BEGIN
    namespace := namespace(Namespace.Nested). nestedIn;
  END EndTypeGuard;

PROCEDURE (b: Builder) NewIdentRef* (baseNS, ns: Sym.Namespace;
                                     context: Sym.Item; 
                                     name: Symbol): Expression;
  VAR
    decl: Sym.Declaration;
    varRef: Var;
    redirModule: Sym.Item;
  BEGIN
    IF (name. id = Id.ident) THEN
      decl := ns. Identify (context, b. GetName (name), FALSE);
      IF (decl = NIL) THEN
        b. ErrSym (undeclaredIdent, name)
      ELSE
        decl.IncrUsageCount();
        WITH decl: Sym.ConstDecl DO
          RETURN NewConst (name, decl. type, decl. value)
        | decl: Sym.VarDecl DO
          RETURN b. NewVar (name, decl)
        | decl: GuardedVar DO
          varRef := b. NewVar (name, decl. var);
          varRef. type := decl. type;
          RETURN varRef;
        | decl: Sym.TypeDecl DO
          RETURN b. NewTypeRef (name, decl)
        | decl: Sym.PredefProc DO
          RETURN NewPredefProc (name, decl)
        | decl: Sym.ProcDecl DO
          RETURN NewProcedureRef (name, decl)
        | decl: Sym.Import DO
          RETURN b. NewModuleRef (name, decl. externalSymTab)
        | decl: Sym.Redirect DO
          redirModule := baseNS.Identify(context, decl.module, FALSE);
          IF (redirModule = NIL) OR ~(redirModule IS Sym.Import) THEN
            b.ErrSym(redirectFailed, name);
          ELSE
            ns := redirModule(Sym.Import).externalSymTab.ns;
            RETURN b.NewIdentRef(ns, ns, context,
                                 BasicList.CloneSymbol(name, decl.ident.str^));
          END;
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

PROCEDURE (b: Builder) NewQualident* (baseNS: Sym.Namespace;
                                      modref: ModuleRef; context: Sym.Item; 
                                      name: Symbol): Expression;
  BEGIN
    RETURN b. NewIdentRef (baseNS, modref. decl(Sym.Module). ns, context, name)
  END NewQualident;

PROCEDURE (b: Builder) NewSelect* (sym: Symbol; var: Expression;
                                   context: Sym.Item; name: Symbol): Expression;
(**Resolves a field or type-bound procedure selector.  *)
  VAR
    varRef: Expression;
    decl: Sym.Declaration;
  BEGIN
    b.CheckFunctionOp(var, sym);
    IF (var. type IS Sym.Pointer) THEN
      varRef := b. NewDeref (sym, var);
    ELSE
      varRef := var;
    END;
    
    IF varRef. type IS Sym.Record THEN
      decl := varRef. type(Sym.Record). ns. Identify
          (context, b. GetName (name), FALSE);
      IF (decl # NIL) THEN
        decl.IncrUsageCount();
      END;
      
      IF decl = NIL THEN
        RETURN b.ErrExpr(undeclaredIdent, name);
      ELSIF (decl IS Sym.FieldDecl) THEN
        RETURN b. NewSelectField (sym, varRef, decl(Sym.FieldDecl), name);
      ELSIF (decl IS Sym.ProcDecl) THEN
        RETURN b. NewSelectProc (sym, var, varRef. type(Sym.Record),
                                 decl(Sym.ProcDecl), name, FALSE);
      ELSE
        ASSERT (FALSE);
      END;
    ELSE
      RETURN b.ErrExpr(notRecord, varRef.sym);
    END
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
    isNumeric := TR.IsNumericType(type);
    isSet := TR.IsSetType(type);
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
      IF isBoolean THEN
        RETURN b.NewNot(sym, right);
      ELSE
        RETURN b.ErrExpr(invalidOpType, sym);
      END
    ELSE
      RETURN b.ErrExpr(unknownOp, sym);
    END;
  END UnaryOperator;

  PROCEDURE BinaryOperator() : Expression;
  VAR 
    leftType, rightType, real, nil : Sym.Type;
    result : Expression;
    variant : Variant;
    isNumeric, isSet, isInteger, isBoolean, isChar, dummy : BOOLEAN;
    exprList: ExpressionList;
    
  PROCEDURE IsString(type : Sym.Type) : BOOLEAN;
  BEGIN
    RETURN
      TR.IsStringConst(type) OR 
        (type IS Sym.Array) & TR.IsCharType (type(Sym.Array). elementType);
  END IsString;

  BEGIN
    nil := Predef.GetType (Predef.nil);
    real := Predef.GetType (Predef.real);
    result := NIL;  (* FIXME. keep the compiler happy until ASSERTs are removed *)
    
    IF (id = Id.in) & TR.IsIntegerType(left.type)
       & TR.IsSetType(right.type) THEN
      result := b.NewSetMember(sym, left, right);
    ELSIF (id = Id.is) THEN
      result := b.NewTypeTest(sym, left, right);
    ELSIF b.WidenToCommon(left, right) THEN
      leftType := left.type; rightType := right.type;
      
      isNumeric := TR.IsNumericType(leftType);
      isInteger := TR.IsIntegerType(leftType);
      isSet := TR.IsSetType(leftType);
      isBoolean := IsPredefClass(leftType, {Predef.boolean});
      isChar := TR.IsCharType(leftType);
      
      IF (id IN {Id.plus, Id.minus, Id.times}) & isNumeric THEN
        (* ---- arithmetic operator ---- *)
        CASE id OF
        | Id.plus: variant := arithAdd;
        | Id.minus: variant := arithSub;
        | Id.times: variant := arithMul;
        END;
        result := b.NewBinaryArith(sym, variant, left, right);
        
      ELSIF (id IN {Id.slash }) & isNumeric THEN
        (* ---- arithmetic real division ---- *)
        IF isInteger THEN
          dummy := b.Widen(left, real);
          dummy := b.Widen(right, real);
        END;
        result := b.NewBinaryArith(sym, arithDivR, left, right);
        
        
      ELSIF (id IN {Id.div, Id.mod}) & isInteger THEN
        (* ---- arithmetic integer division/modulus ---- *)
        CASE id OF
        | Id.div: variant := arithDivI;
        | Id.mod: variant := arithMod;
        END;
        result := b.NewBinaryArith(sym, variant, left, right)
            
      ELSIF (id IN {Id.plus, Id.minus, Id.times, Id.slash}) & isSet THEN
        (* ---- set operator ---- *)
        CASE id OF
        | Id.plus: variant := setUnion;
        | Id.minus: variant := setDiff;
        | Id.times: variant := setIntersect;
        | Id.slash: variant := setSymDiff
        END;
        RETURN b.NewSetOp(sym, variant, left, right);
        
      ELSIF (id IN {Id.and, Id.or}) & isBoolean THEN
        CASE id OF
        | Id.and: variant := and;
        | Id.or: variant := or;
        END;
        result := b.NewBooleanOp(sym, variant, left, right);
        
      ELSIF (id IN {Id.eql, Id.neq, Id.lss, Id.leq, Id.gtr, Id.geq}) 
            & IsString(left.type) & IsString(right.type) THEN
        result := b.NewCompare(sym, left, right);

      ELSIF (id = Id.plus) & 
            (isChar OR
             TR.IsStringConst(left.type) OR
             (left.type = b.stringType)) THEN
        NEW(exprList, 2);
        exprList[0] := left;
        exprList[1] := right;
	result := b.NewConcat(sym, exprList);

      ELSIF (id IN {Id.eql, Id.neq, Id.lss, Id.leq, Id.gtr, Id.geq})
            & (isNumeric OR isChar) THEN
        result := b.NewCompare(sym, left, right);
        
      ELSIF (id IN {Id.eql, Id.neq})
            & (isBoolean OR isSet OR (leftType = nil) OR (right.type = nil)
               OR (leftType IS Sym.Pointer) OR (leftType IS Sym.FormalPars)) THEN
        result := b.NewCompare(sym, left, right);
      ELSE
        result := b.ErrExpr(invalidOpType, sym);
      END;
      
    ELSIF IsString(left.type) & IsString(right.type) THEN 
      IF (id IN {Id.eql, Id.neq, Id.lss, Id.leq, Id.gtr, Id.geq}) THEN
        result := b.NewCompare(sym, left, right);
      ELSE
        result := b.ErrExpr(invalidOpType, sym);
      END;
    ELSE
      result := b.ErrExpr(incompatibleTypes, sym);
    END;
    RETURN result;
  END BinaryOperator;

  BEGIN
    id := sym.id;
    
    IF left = NIL THEN 
      RETURN UnaryOperator();
    ELSE
      RETURN BinaryOperator();
    END;
  END NewOperator;

 PROCEDURE (b: Builder) NewCall* (design: Expression;
                                  arguments: ExpressionList;
                                  isFunctionCall: BOOLEAN;
                                  endOfArgsSym: Symbol): Expression;
  VAR
    call: Call;
    targetType: Sym.PredefId;
    predefProc: Sym.PredefProc;
    dim, dummy: LONGINT;
    op: SHORTINT;
    type: Sym.Type;
    formalPars: Sym.VarDeclArray;
    receiver, delta, code: Expression;
    value: Language.Value;
 
  PROCEDURE MakeParameterCompatible (b: Builder; sym: Symbol;
                                     VAR arg: Expression;
                                     fpar: Sym.VarDecl);
  (**Takes an expression @oparam{arg} and a formal parameter declaration
     @oparam{fpar}, and tries to make the expression's value compatible to the
     formal parameter.  If this is not possible, an error is reported.  *)
    VAR
      ok: BOOLEAN;
    BEGIN
      IF fpar.permitArgumentNIL & TR.IsPredefType(arg.type, Predef.nil) THEN
        (* the flag NIL_COMPATH is set for the formal parameter, and the
           actual parameter is NIL: accept *)
        
      ELSIF fpar. isVarParam THEN        (* variable parameter *)
        b. AssertVar (arg);

        IF fpar. isReceiver & (arg. type IS Sym.Pointer) THEN
          (* receiver is a VAR record, argument a pointer: add deref *)
          arg := b. NewDeref (arg. sym, arg);
        END;
        
        IF TR.SameType (fpar. type, arg. type) OR
           IsPredefType (fpar. type, Predef.byte) &
             TR.IsByteCompatible (arg. type) OR
           TR.IsOpenArrayType (fpar. type) &
             IsPredefType (fpar.type(Sym.Array).elementType, Predef.byte) THEN
          (* same type, or passing a CHAR or SHORTINT to a BYTE, or passing
             anything to an ARRAY OF BYTE: argument is compatible to formal
             parameter *)
        ELSIF (fpar. type IS Sym.Record) THEN
          IF ~TR.IsExtensionOf (arg. type, fpar. type) THEN
            (* formal parameter is record, and the argument type is not
               an extension of the record type *)
            b. ErrSym (notVarParCompatible, arg. sym);
          END;
        ELSIF TR.IsOpenArrayType (fpar. type) THEN
          IF ~TR.IsArrayCompatible (arg. type, fpar. type) THEN
            (* formal parameter is open array, and the argument type is not
               array compatible to it *)
            b. ErrSym (notVarParCompatible, arg. sym);
          END;
        ELSE                             (* not compatible *)
          b. ErrSym (notVarParCompatible, arg. sym);
        END;
        
      ELSE                               (* value parameter *)
        IF TR.IsOpenArrayType (fpar. type) THEN
          ok := TR.IsArrayCompatible (arg. type, fpar. type) OR
              b. Widen (arg, fpar. type);  (* do string promotion *)
        ELSE
          ok := b. WidenForAssign (arg, fpar. type);
        END;
        IF ~ok THEN
          b.ErrSym(incompatibleActualParam, arg. sym);
        END;
      END;
    END MakeParameterCompatible;
  
  PROCEDURE TransformArgs (sym, endOfArgsSym: Symbol;
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

    PROCEDURE Dimensions (type: Sym.Type): LONGINT;
      BEGIN
        IF TR.IsStringConst (type) THEN
          RETURN 1;
        ELSIF (type IS Sym.Array) THEN
          RETURN type(Sym.Array). ArrayDimensions();
        ELSE
          RETURN 0;
        END;
      END Dimensions;
    
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
        MakeParameterCompatible (b, arg. sym, arg, fpar);
        
        IF fpar.isPassPerReference &
           ~TR.IsPredefType(arg.type, Predef.nil) THEN
          (* for argument passed by reference, add the address of the
             designator to the argument list, not its value; if the argument is
             NIL and teh formal parameter is NIL_COMPAT, then use the value
             directly *)
          newArgs. Append (b. NewAdr (sym, arg));
        ELSE
          newArgs. Append (arg);
        END;
        newFPars. Append (fpar);

        IF fpar. supplementArgs THEN
          fparType := fpar. type;
          WITH fparType: Sym.Array DO
            IF IsPredefType (fparType. elementType, Predef.byte) THEN
              (* passing a value to an ARRAY OF BYTE: the length argument
                 is the size of the passed value *)
              newArgs. Append (b. NewConst (arg. sym,
                                            Predef.GetType (Predef.lengthType),
                                            Integer.New (arg. type. size)));
              newFPars. Append (NIL);
            ELSIF (Dimensions (arg.type) >= fparType. GetOpenDimensions()) THEN
              (* only try to add the lengths if there are enough dimensions
                 in the argument; otherwise, MakeParameterCompatible should
                 have written out an error message for us *)
              FOR i := 0 TO fparType. GetOpenDimensions()-1 DO
                newArgs. Append (b. Fold (b. NewLen (arg. sym, arg, i)));
                newFPars. Append (NIL);
              END;
            END;

          | fparType: Sym.Record DO
            IF fpar. isVarParam THEN
              newArgs. Append (b. NewTypeTag (arg. sym, arg));
              newFPars. Append (NIL);
            END;
          ELSE  (* nothing to do *)
          END;
        END;
        
        INC (argIndex);
        INC (fparIndex);
      END;

      (* do we have a `...' at the end of our parameter list? *)
      IF formalPars. anyRestParameters THEN
        WHILE (argIndex # LEN (arguments^)) DO
          arg := arguments[argIndex];
          newArgs. Append (arg);
          newFPars. Append (NIL);
          INC (argIndex);
        END;
      END;
      
      IF (fparIndex # LEN (formalPars. params^)) THEN
        (* less arguments than formal parameters *)
        b. ErrSym (tooFewArguments, endOfArgsSym);
      ELSIF (argIndex # LEN (arguments^)) THEN
        (* less formal parameters than arguments *)
        b. ErrSym (tooManyArguments, arguments[argIndex]. sym);
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
        IF (LEN (arguments^) > 1) THEN
          code := arguments[1];
        ELSE
          code := NIL;
        END;
        RETURN b. NewAssert (design. sym, arguments[0], code,
                  ~GetPragmaValue(b, StdPragmas.assertions, design. sym. pos));

      | Predef.halt:
        RETURN b. NewAssert (design. sym, NIL, arguments[0], FALSE);

      | Predef.copy:
        RETURN b. NewCopyString (design. sym, arguments[0], arguments[1],
                                 b. NewLen (design. sym, arguments[1], 0));
        
      | Predef.new:
        IF (arguments[0]. type IS Sym.Pointer) THEN
          b.AssertVar(arguments[0]);
          type := arguments[0]. type(Sym.Pointer). baseType;
          IF (type IS Sym.Array) THEN
            dim := 1+arguments[0].type(Sym.Pointer).baseType(Sym.Array).GetOpenDimensions();
            IF CheckNumberOfArguments (dim, dim) THEN
              RETURN b. NewAssignment
                  (design. sym, arguments[0],
                   b. NewNewObject (design.sym, arguments[0].type, arguments));
            END;
          ELSE (* (type IS Sym.Record) *)
            IF ~TR.VariableInstance(type) THEN
              b.ErrSym(cannotCreateInstance, arguments[0].sym);
            END;
            IF CheckNumberOfArguments (1, 1) THEN
              RETURN b. NewAssignment
                  (design. sym, arguments[0],
                   b. NewNewObject (design. sym, arguments[0].type, NIL));
            END;
          END;
        ELSE
          b.ErrSym(notPointerVar, arguments[0].sym);
        END;
        RETURN b. errorExpr;
        
      | Predef.inc, Predef.dec:
        arguments[0] := b.AssertInteger(arguments[0]);
        b.AssertVar(arguments[0]);
        IF (LEN (arguments^) = 1) THEN
          delta := b. GetOne (design. sym, arguments[0]. type);
        ELSE
          delta := arguments[1];
        END;
        IF b.Widen(delta, arguments[0].type) THEN
          IF (design. decl(Sym.PredefProc). id = Predef.inc) THEN
            op := arithAdd;
          ELSE
            op := arithSub;
          END;
          RETURN b. NewAssignOp (design. sym,
                                 b. NewBinaryArith
                                 (design. sym, op, arguments[0], delta));
        ELSE
          b.ErrSym(invalidOpType, delta.sym);
          RETURN b. NewAssignment(design.sym, arguments[0], arguments[0]);
        END;
        
      | Predef.incl, Predef.excl:
        b.AssertVar(arguments[0]);
        arguments[0] := b.AssertSet(arguments[0]);
        arguments[1] := b.AssertInteger(arguments[1]);
        IF (design. decl(Sym.PredefProc). id = Predef.incl) THEN
          op := inclElement;
        ELSE
          op := exclElement;
        END;
        RETURN b. NewAssignOp(design. sym,
                              b. NewChangeElement(design. sym, op,
                                                  arguments[0], arguments[1]));
        
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
          IF TR.IsSetType (type) THEN (* fix type for SET *)
            type := Predef.GetType (Predef.shortint);
          END;
          RETURN b. NewConst (arguments[0]. sym, type, value);
        END;
        
      | Predef.size:
        RETURN b. NewSize (design. sym, arguments[0])

      | Predef.abs:
        RETURN b. NewAbs (design. sym, arguments[0]);
        
      | Predef.ash:
        RETURN b. NewAsh (design. sym, arguments[0], arguments[1]);
        
      | Predef.cap:
        RETURN b. NewCap (design. sym, b.AssertChar(arguments[0]));

      | Predef.long:
        IF (arguments[0] IS Const) & TR.IsIntegerType(arguments[0].type) THEN
          (* LONG is a noop for integer constants *)
          RETURN arguments[0];
        ELSIF (arguments[0].type IS Sym.PredefType) THEN
          CASE arguments[0].type(Sym.PredefType).id OF
          | Predef.shortint: targetType := Predef.integer;
          | Predef.integer : targetType := Predef.longint;
          | Predef.longint : targetType := Predef.hugeint;
          | Predef.real    : targetType := Predef.longreal;
          | Predef.char    : targetType := Predef.longchar;
          ELSE
            b.ErrSym(invalidOpType, arguments[0].sym);
            RETURN arguments[0];
          END;
          RETURN b.NewTypeConv (Predef.GetType (targetType), arguments[0]);
        ELSE                             (* user defined type *)
          b.ErrSym(invalidOpType, arguments[0].sym);
          RETURN arguments[0];
        END;
        
      | Predef.short:
        IF (arguments[0] IS Const) & TR.IsIntegerType(arguments[0].type) THEN
          (* SHORT is a noop for integer constants *)
          RETURN arguments[0];
        ELSIF (arguments[0].type IS Sym.PredefType) THEN
          CASE arguments[0].type(Sym.PredefType).id OF
          | Predef.integer: targetType := Predef.shortint;
          | Predef.longint: targetType := Predef.integer;
          | Predef.hugeint: targetType := Predef.longint;
          | Predef.longreal: targetType := Predef.real;
          | Predef.longchar: targetType := Predef.char;
          ELSE
            b.ErrSym(invalidOpType, arguments[0].sym);
            RETURN arguments[0];
          END;
          RETURN b.NewTypeConv (Predef.GetType (targetType), arguments[0]);
        ELSE                             (* user defined type *)
          b.ErrSym(invalidOpType, arguments[0].sym);
          RETURN arguments[0];
        END;
        
      | Predef.chr:
        arguments[0] := b.AssertInteger(arguments[0]);
        IF (arguments[0] IS Const) THEN
          (* FIXME... this kind of overflow checking should be done in
             ConstFold, for the argument and the result of each computation *)
          dummy := b.AssertIntConst(arguments[0], ORD(Predef.minChar),
                                    ORD(Predef.maxChar)+1);
        END;
        RETURN b.NewTypeConv (Predef.GetType (Predef.char), arguments[0]);
      | Predef.longchr:
        arguments[0] := b.AssertInteger(arguments[0]);
        IF (arguments[0] IS Const) THEN
          (* FIXME... this kind of overflow checking should be done in
             ConstFold, for the argument and the result of each computation *)
          dummy := b.AssertIntConst(arguments[0],
                                    ORD(Predef.minLongchar),
                                    ORD(Predef.maxLongchar)+1);
        END;
        RETURN b.NewTypeConv (Predef.GetType (Predef.longchar), arguments[0]);
        
      | Predef.entier:
        RETURN b. NewEntier (design. sym, arguments[0]);
        
      | Predef.odd:
        RETURN b. NewOdd (design. sym, arguments[0]);
        
      | Predef.ord:
        IF (arguments[0].type IS Sym.PredefType) &
           (arguments[0].type(Sym.PredefType).id = Predef.longchar) THEN
          targetType := Predef.longint;
        ELSE  (* for CHAR and in case of error *)
          targetType := Predef.integer;
        END;
        RETURN b.NewTypeConv(Predef.GetType(targetType),
                             b.AssertChar(arguments[0]));
        
      (* SYSTEM procedures: *)
      | Predef.move:
        RETURN b. NewMoveBlock (design. sym,
                                arguments[0], arguments[1], arguments[2]);
        
      | Predef.systemNew:
        IF (arguments[0].type IS Sym.Pointer) OR
          TR.IsPredefType(arguments[0].type, Predef.ptr) THEN
          b.AssertVar(arguments[0]);
          type := arguments[0].type;
          RETURN b. NewAssignment
              (design. sym, arguments[0],
               b. NewNewBlock (design.sym, arguments[0].type, arguments[1]));
        ELSE
          b.ErrSym(notPointerVar, arguments[0].sym);
        END;
        RETURN b. errorExpr;
        
      (* SYSTEM functions: *)
      | Predef.adr:
        RETURN b. NewAdr (design. sym, arguments[0]);

      | Predef.lsh:
        RETURN b. NewShift (design. sym, arguments[0], arguments[1], FALSE);
        
      | Predef.val:
        RETURN b. NewTypeCast (design. sym, arguments[0], arguments[1]);
        
      | Predef.rot:
        RETURN b. NewShift (design. sym, arguments[0], arguments[1], TRUE);
      END;
    ELSE
      IF (design = b. errorExpr) THEN
        RETURN b. errorExpr;        (* fall through for errors in designator *)
      ELSIF TR.IsValidReceiverType(design.type) 
        & (LEN(arguments^) = 1) & (arguments[0] IS TypeRef) THEN
        RETURN b.NewTypeGuard(arguments[0]. sym, design,
                              arguments[0](TypeRef));
      ELSIF ~(design. type IS Sym.FormalPars) THEN
        RETURN b. ErrExpr (notProcedure, design. sym);
      ELSIF isFunctionCall &
            (design. type(Sym.FormalPars). resultType = NIL) THEN
        RETURN b. ErrExpr (notFunctionProcedure, design. sym);
      ELSIF ~isFunctionCall &
            (design. type(Sym.FormalPars). resultType # NIL) THEN
        RETURN b. ErrExpr (isFunctionProcedure, design. sym);
      ELSE
        NEW (call);
        IF (design IS SelectProc) THEN
          receiver := design(SelectProc). receiver;
        ELSE
          receiver := NIL;
        END;
        TransformArgs (design. sym, endOfArgsSym,
                       design. type(Sym.FormalPars),
                       receiver, arguments, formalPars);
        InitCall (call, design, arguments, formalPars);
        RETURN call;
      END;
    END
  END NewCall;

BEGIN
  NEW (irContext);
  Error.InitContext (irContext, "OOC:IR");
END OOC:IR.
