MODULE OOC:IR [OOC_EXTENSIONS];

IMPORT
Log,
  Language, Language:Boolean, Language:String8, Language:Integer,
  Config:Value, BooleanValue := Config:Value:Boolean, 
  SymbolId := OOC:Scanner:Symbol, OOC:Scanner:Builder:BasicList, OOC:Error,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  OOC:AST, OOC:SymbolTable:Item, OOC:SymbolTable:Predef;

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
   @otype{Builder}.  The builder also implement error checks.  It, and not the
   code calling the factory methods, guarantees that the constructed IR is
   valid if it does not report an error in the process of assembling the IR.

   @item
   The semantics of IR instructions is as simple as possible.  In the ideal
   case, an IR instruction performs a single task, and this task is completely
   identified by the instruction name.  There should be no variants in an
   instruction's semantics based on its arguments.  In other words, in the next
   step of the translation process it should be possible to use a single code
   pattern to translate instructions of the same kind.

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
    sym: Symbol;
    (**This symbol's location is used to refer to the node when writing an
       error or warning message.  For constants or name, this symbol is the
       node's original representation.  For expressions or statements it refers
       to a symbol that can serve as an---ideally unambiguous---identifier for
       the construct.

       The field is @code{NIL} if, and only if, the node is equal to
       @ovar{errorExpr}.  In this case, no error or warning should be written,
       because the node already triggered an error message.  *)
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
  END;


TYPE
  Reference* = POINTER TO ReferenceDesc;
  ReferenceDesc = RECORD [ABSTRACT]
  (**Represents a using occurence of a name.  A reference is associatd with
     exactly one defining declaration.  In the case of predefined procedures
     and operators, this declaration may be overloaded, but in all other cases
     the declaration uniquely identifies the referenced entity.  *)
    (ExpressionDesc)
    decl-: Item.Declaration;
    (**The entity refered to.  *)
  END;

TYPE
  Const* = POINTER TO ConstDesc;
  ConstDesc = RECORD
  (**A constant value, derived from a literal or from a reference to a
     named constant.  *)
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
    opnd1-, opnd2-: Expression;
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
       is not use to represent calls to type-bound procedures, nor to
       predefined procedures.

       Predefined functions are represented as operators of expressions.
       Predefined procedures are mapped to dedicated classes.  The reason to
       distinguish them from normal procedures is that code generators
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
  Procedure* = POINTER TO ProcedureDesc;
  ProcedureList* = POINTER TO ARRAY OF Procedure;
  ProcedureDesc = RECORD
    (NodeDesc)
    decl-: Item.ProcDecl;
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
  END;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
  (**Base class for visitor pattern.  Specializations of various @code{Visit*}
     methods are responsible for traversing the tree of the module
     representation.  *)
  END;


VAR
  errorExpr-: Expression;
  (**This value is returned if there is no real value because of an error.  For
     example, if an identifier cannot be resolved, or if a designator does not
     begin with an identifier, then this value is passed to the caller.  Within
     the IR, no other value is used to indicate illegal operations.

     @strong{Note}: A function can @emph{only} return this value for a node, if
     it also emits an error message.  *)
  
CONST
  undeclaredIdent = 1;
  expectedIdent = 2;
  numberOutOfRange = 3;
  
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
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
  END InitVisitor;

PROCEDURE InitBuilder* (b: Builder; pragmaHistory: Pragmas.History; errList: Error.List);
  BEGIN
    b. pragmaHistory := pragmaHistory;
    b. errList := errList;
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



PROCEDURE InitNode* (n: Node; sym: Symbol);
  BEGIN
    n. sym := sym;
  END InitNode;

PROCEDURE (node: Node) [ABSTRACT] Accept* (v: Visitor);
  END Accept;

(* -------- *)

PROCEDURE InitExpression* (expr: Expression; sym: Symbol);
  BEGIN
    InitNode (expr, sym);
  END InitExpression;

PROCEDURE InitReference (ref: Reference; name: Symbol; decl: Item.Declaration);
  BEGIN
    InitNode (ref, name);
    ref. decl := decl;
  END InitReference;


(* -------- *)

PROCEDURE InitConst (const: Const; sym: Symbol; value: Language.Value);
  BEGIN
    InitExpression (const, sym);
    const. value := value;
  END InitConst;

PROCEDURE NewConst (sym: Symbol; value: Language.Value): Const;
  VAR
    const: Const;
  BEGIN
    NEW (const);
    InitConst (const, sym, value);
    RETURN const
  END NewConst;

PROCEDURE (v: Visitor) [ABSTRACT] VisitConst* (const: Const);
  END VisitConst;

PROCEDURE (const: Const) Accept* (v: Visitor);
  BEGIN
    v. VisitConst (const)
  END Accept;

PROCEDURE (b: Builder) NewStringConst* (sym: Symbol): Expression;
  BEGIN
    RETURN NewConst (sym, String8.type. ValueOf (sym. str^));
  END NewStringConst;

PROCEDURE (b: Builder) NewIntConst10* (sym: Symbol): Expression;
  VAR
    v: Language.Value;
  BEGIN
    v := Integer.type. ValueOf (sym. str^);
    IF (v = NIL) THEN
      b. ErrSym (numberOutOfRange, sym);
      RETURN errorExpr
    ELSE
      RETURN NewConst (sym, v)
    END
  END NewIntConst10;

(* -------- *)

PROCEDURE InitVar (var: Var; name: Symbol; decl: Item.VarDecl);
  BEGIN
    InitReference (var, name, decl);
  END InitVar;

PROCEDURE NewVar (name: Symbol; decl: Item.VarDecl): Var;
  VAR
    var: Var;
  BEGIN
    NEW (var);
    InitVar (var, name, decl);
    RETURN var
  END NewVar;

PROCEDURE (v: Visitor) [ABSTRACT] VisitVar* (var: Var);
  END VisitVar;

PROCEDURE (var: Var) Accept* (v: Visitor);
  BEGIN
    v. VisitVar (var)
  END Accept;

(* -------- *)

PROCEDURE InitPredefProc (pproc: PredefProc; name: Symbol; decl: Item.PredefProc);
  BEGIN
    InitReference (pproc, name, decl);
  END InitPredefProc;

PROCEDURE NewPredefProc (name: Symbol; decl: Item.PredefProc): PredefProc;
  VAR
    pproc: PredefProc;
  BEGIN
    NEW (pproc);
    InitPredefProc (pproc, name, decl);
    RETURN pproc
  END NewPredefProc;

PROCEDURE (v: Visitor) [ABSTRACT] VisitPredefProc* (pproc: PredefProc);
  END VisitPredefProc;

PROCEDURE (pproc: PredefProc) Accept* (v: Visitor);
  BEGIN
    v. VisitPredefProc (pproc)
  END Accept;

(* -------- *)

PROCEDURE InitProcedureRef (procRef: ProcedureRef; name: Symbol; decl: Item.ProcDecl);
  BEGIN
    InitReference (procRef, name, decl);
  END InitProcedureRef;

PROCEDURE NewProcedureRef (name: Symbol; decl: Item.ProcDecl): ProcedureRef;
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

PROCEDURE InitModuleRef (modRef: ModuleRef; name: Symbol; decl: Item.Module);
  BEGIN
    InitReference (modRef, name, decl);
  END InitModuleRef;

PROCEDURE NewModuleRef (name: Symbol; decl: Item.Module): ModuleRef;
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

PROCEDURE (b: Builder) NewIdentRef* (ns: Item.Namespace; context: Item.Item; 
                                     name: Symbol): Expression;
  VAR
    decl: Item.Declaration;
  
  PROCEDURE GetName (sym: Symbol): Item.Name;
    VAR
      name: Item.Name;
    BEGIN
      NEW (name);
      Item.InitName (name, sym. str, sym. pos, sym. line, sym. column);
      RETURN name
    END GetName;
  
  BEGIN
    IF (name. id = SymbolId.ident) THEN
      decl := ns. Identify (context, GetName (name), FALSE);
      IF (decl = NIL) THEN
        b. ErrSym (undeclaredIdent, name)
      ELSE
        WITH decl: Item.ConstDecl DO
          RETURN NewConst (name, decl. value)
        | decl: Item.VarDecl DO
          RETURN NewVar (name, decl)
        | decl: Item.PredefProc DO
          RETURN NewPredefProc (name, decl)
        | decl: Item.ProcDecl DO
          RETURN NewProcedureRef (name, decl)
        | decl: Item.Import DO
          RETURN NewModuleRef (name, decl. externalSymTab)
        ELSE
          Log.Type ("decl", decl); ASSERT (FALSE);
        END
      END
    ELSE
      b. ErrSym (expectedIdent, name)
    END;
    
    (* in the case of an error, return the value "FALSE"; returning NIL
       would require more effort in the callers to distinguish between
       correct and faulty expressions *)
    RETURN errorExpr 
  END NewIdentRef;

PROCEDURE (b: Builder) NewQualident* (modref: ModuleRef; context: Item.Item; 
                                      name: Symbol): Expression;
  BEGIN
    RETURN b. NewIdentRef (modref. decl(Item.Module). ns, context, name)
  END NewQualident;

(* -------- *)

PROCEDURE InitOperator* (op: Operator; sym: Symbol; opnd1, opnd2: Expression);
  BEGIN
    InitExpression (op, sym);
    op. opnd1 := opnd1;
    op. opnd2 := opnd2;
  END InitOperator;

PROCEDURE (b: Builder) [ABSTRACT] NewOperator* (op: Symbol; left, right: Expression): Expression;
  END NewOperator;

(* -------- *)

PROCEDURE InitStatement* (statm: Statement; sym: Symbol);
  BEGIN
    InitExpression (statm, sym);
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

PROCEDURE InitCall* (call: Call; design: Expression; arguments: ExpressionList);
  BEGIN
    InitNode (call, design. sym);
    call. design := design;
    call. arguments := arguments;
  END InitCall;

PROCEDURE (b: Builder) NewCall* (design: Expression; arguments: ExpressionList): Expression;
  VAR
    call: Call;
  BEGIN
    NEW (call);
    WITH design: PredefProc DO
      CASE design. decl(Item.PredefProc). id OF
      | Predef.assert:
        RETURN b. NewAssert (design. sym, arguments,
                   GetPragmaValue (b, StdPragmas.assertions, design. sym. pos))
      END
    ELSE
      InitCall (call, design, arguments)
    END;
    RETURN call
  END NewCall;

PROCEDURE (v: Visitor) [ABSTRACT] VisitCall* (call: Call);
  END VisitCall;

PROCEDURE (call: Call) Accept* (v: Visitor);
  BEGIN
    v. VisitCall (call)
  END Accept;

(* -------- *)

PROCEDURE InitProcedure* (p: Procedure; sym: Symbol; 
                          decl: Item.ProcDecl; statmSeq: StatementSeq);
  BEGIN
    InitNode (p, sym);
    p. decl := decl;
    p. statmSeq := statmSeq;
  END InitProcedure;

PROCEDURE (b: Builder) NewProcedure* (sym: Symbol;
                       decl: Item.ProcDecl; statmSeq: StatementSeq): Procedure;
  VAR
    p: Procedure;
  BEGIN
    NEW (p);
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
  errorExpr := NewConst (NIL, Boolean.New (FALSE));
END OOC:IR.
