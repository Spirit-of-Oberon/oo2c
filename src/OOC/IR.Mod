MODULE OOC:IR [OOC_EXTENSIONS];

IMPORT
Log,
  Language, Language:Boolean, Language:Char8, Language:String8,
  Language:Integer, ADT:Object, 
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
   @end itemize  *)


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


CONST
  defaultAssertCode = 1;


(* Expressions
   ------------------------------------------------------------------------ *)

TYPE
  Expression* = POINTER TO ExpressionDesc;
  ExpressionList* = POINTER TO ARRAY OF Expression;
  ExpressionDesc* = RECORD [ABSTRACT]
    (NodeDesc)
    type-: Sym.Type;
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
  Var* = POINTER TO VarDesc;
  VarDesc = RECORD
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
  ModuleRef* = POINTER TO ModuleRefDesc;
  ModuleRefDesc = RECORD
    (ReferenceDesc)
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

(* Statements
   ------------------------------------------------------------------------ *)

TYPE
  Statement* = POINTER TO StatementDesc;
  StatementSeq* = POINTER TO ARRAY OF Statement;
  StatementDesc = RECORD [ABSTRACT]
    (ExpressionDesc)
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
  Assert* = POINTER TO AssertDesc;
  AssertDesc = RECORD
    (**Represents a call to the predefined procedure @code{ASSERT}.  *)
    (StatementDesc)
    predicate-: Expression;
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
  Return* = POINTER TO ReturnDesc;
  ReturnDesc = RECORD
    (**A procedure's @code{RETURN} statement.  *)
    (StatementDesc)
    result-: Expression;
    (**The result expression.  @code{NIL} if this is a return from
       a procedure.  *)
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
  WhileStatm* = POINTER TO WhileStatmDesc;
  WhileStatmDesc = RECORD
    (**Holds an @code{WHILE-DO} statement.  *)
    (StatementDesc)
    guard-: Expression;
    body-: StatementSeq;
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
  BuilderDesc* = RECORD [ABSTRACT]
    pragmaHistory: Pragmas.History;
    errList: Error.List;
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



PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
  END InitVisitor;

PROCEDURE ^ NewConst (sym: Symbol; type: Sym.Type;
                      value: Language.Value): Const;
  
PROCEDURE InitBuilder* (b: Builder; pragmaHistory: Pragmas.History; errList: Error.List; typeRules : TypeRules.Rules);
  BEGIN
    b. pragmaHistory := pragmaHistory;
    b. errList := errList;
    b. typeRules := typeRules;
    b. errorExpr := NewConst (NIL, Predef.GetType(Predef.void), Boolean.New (FALSE));
  END InitBuilder;

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

PROCEDURE InitNode* (n: Node; sym: Symbol);
  BEGIN
    Object.Init (n);
    n. sym := sym;
  END InitNode;

PROCEDURE (node: Node) [ABSTRACT] Accept* (v: Visitor);
  END Accept;

(* -------- Evaluation of expressions *)

PROCEDURE InitExpression* (expr: Expression; sym: Symbol; type: Sym.Type);
  BEGIN
    InitNode (expr, sym);
    expr. type := type;
  END InitExpression;

PROCEDURE InitReference (ref: Reference; name: Symbol; type: Sym.Type;
                         decl: Sym.Declaration);
  BEGIN
    InitExpression (ref, name, type);
    ref. decl := decl;
  END InitReference;

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

PROCEDURE (b: Builder) GetName* (sym: Symbol): Sym.Name;
  VAR
    name: Sym.Name;
  BEGIN
    NEW (name);
    Sym.InitName (name, sym. str, sym. pos, sym. line, sym. column);
    RETURN name
  END GetName;

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

(* -------- *)

PROCEDURE InitOperator* (op: Operator; sym: Symbol; type: Sym.Type);
  BEGIN
    InitExpression (op, sym, type);
  END InitOperator;

PROCEDURE (b: Builder) [ABSTRACT] NewOperator* (op: Symbol; left, right: Expression): Expression;
  END NewOperator;

(* -------- *)

PROCEDURE InitStatement* (statm: Statement; sym: Symbol);
  BEGIN
    InitExpression (statm, sym, Predef.GetType (Predef.void));
  END InitStatement;

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

(* -------- *)

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

PROCEDURE (b: Builder) [ABSTRACT] TransformArgs* (sym: Symbol;
                                       formalPars: Sym.VarDeclArray;
                                       arguments: ExpressionList): ExpressionList;
(**Takes the argument list from the parser and rewrites it to match the formal
   parameters of the called procedure.  The translation includes changes to the
   argument expressions (for example, type conversion to a different numeric
   type) and insertion of additional arguments (for example, array length for
   open array parameters, or insertion of a type tag for a @code{VAR} parameter
   of record type).  *)
  END TransformArgs;

PROCEDURE (b: Builder) NewCall* (design: Expression; arguments: ExpressionList): Expression;
  VAR
    call: Call;
  BEGIN
    WITH design: PredefProc DO
      (* note: predefined functions are handled by a specialization of thie
         method in module OOC:IR:Operator *)
      CASE design. decl(Sym.PredefProc). id OF
      | Predef.assert:
        RETURN b. NewAssert (design. sym, arguments,
                   GetPragmaValue (b, StdPragmas.assertions, design. sym. pos))
      END
    ELSE
      NEW (call);
      arguments := b. TransformArgs (design. sym,
                                     design. type(Sym.FormalPars). params,
                                     arguments);
      InitCall (call, design, arguments);
      RETURN call;
    END;
  END NewCall;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCall* (call: Call);
  END VisitCall;

PROCEDURE (call: Call) Accept* (v: Visitor);
  BEGIN
    v. VisitCall (call)
  END Accept;

(* -------- *)

PROCEDURE InitProcedure* (p: Procedure; sym: Symbol; 
                          decl: Sym.ProcDecl; statmSeq: StatementSeq);
  BEGIN
    InitNode (p, sym);
    p. decl := decl;
    p. statmSeq := statmSeq;
  END InitProcedure;

PROCEDURE (b: Builder) [ABSTRACT] AddSetupCode*
  (sym: Symbol; decl: Sym.ProcDecl; statmSeq: StatementSeq): StatementSeq;
(**Takes the statement sequence representing the body of a procedure and
   extends it with procedure setup (or tear down) code.  For example,
   statements that allocate and intialize local copies of value parameters
   are added here.  *)
  END AddSetupCode;

PROCEDURE (b: Builder) NewProcedure* (sym: Symbol;
                       decl: Sym.ProcDecl; statmSeq: StatementSeq): Procedure;
  VAR
    p: Procedure;
  BEGIN
    NEW (p);
    statmSeq := b. AddSetupCode (sym, decl, statmSeq);
    InitProcedure (p, sym, decl, statmSeq);
    RETURN p
  END NewProcedure;

PROCEDURE (v: Visitor) [ABSTRACT] VisitProcedure* (procedure: Procedure);
  END VisitProcedure;

PROCEDURE (p: Procedure) Accept* (v: Visitor);
  BEGIN
    v. VisitProcedure (p)
  END Accept;

(* -------- *)

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

BEGIN
  NEW (irContext);
  Error.InitContext (irContext, "OOC:IR");
END OOC:IR.
