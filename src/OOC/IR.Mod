MODULE OOC:IR [OOC_EXTENSIONS];

IMPORT
Log,
  Language, Config:Value, BooleanValue := Config:Value:Boolean, 
  OOC:Error, OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
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

TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD [ABSTRACT]
  END;


CONST
  defaultAssertCode = 1;


(* Expressions
   ------------------------------------------------------------------------ *)

TYPE
  Expression* = POINTER TO ExpressionDesc;
  ExpressionList* = POINTER TO ARRAY OF Expression;
  ExpressionDesc = RECORD [ABSTRACT]
    (NodeDesc)
  END;

TYPE
  Const* = POINTER TO ConstDesc;
  ConstDesc = RECORD
    (ExpressionDesc)
    value-: Language.Value;
    decl-: Item.ConstDecl;
  END;

TYPE
  PredefProc* = POINTER TO PredefProcDesc;
  PredefProcDesc = RECORD
  (**Identifies a predefined procedure.  Calls to predefined procedures and
     functions are always mapped to specialized code.  Instances of
     @otype{PredefProc} are created during the translation process, but should
     never appear in the final IR.  *)
    (ExpressionDesc)
    name-: Item.Name;
    decl-: Item.PredefProc;
  END;

TYPE
  ProcedureRef* = POINTER TO ProcedureRefDesc;
  ProcedureRefDesc = RECORD
    (ExpressionDesc)
    name-: Item.Name;
    decl-: Item.ProcDecl;
  END;

TYPE
  ModuleRef* = POINTER TO ModuleRefDesc;
  ModuleRefDesc = RECORD
    (ExpressionDesc)
    name-: Item.Name;
    decl-: Item.Module;
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
  BuilderDesc = RECORD
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


CONST
  undeclaredIdent = 1;
  
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

PROCEDURE NewBuilder* (pragmaHistory: Pragmas.History; errList: Error.List): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b, pragmaHistory, errList);
    RETURN b
  END NewBuilder;

PROCEDURE (b: Builder) ErrName (code: Error.Code; name: Item.Name);
  VAR
    lastError: Error.Msg;
  BEGIN
    lastError := Error.New (irContext, code);
    lastError. SetIntAttrib ("pos", name. pos);
    lastError. SetIntAttrib ("line", name. line);
    lastError. SetIntAttrib ("column", name. column);
    b. errList. Append (lastError)
  END ErrName;



PROCEDURE InitNode* (n: Node);
  BEGIN
  END InitNode;

PROCEDURE (node: Node) [ABSTRACT] Accept* (v: Visitor);
  END Accept;

(* -------- *)

PROCEDURE InitExpression* (expr: Expression);
  BEGIN
    InitNode (expr);
  END InitExpression;

(* -------- *)

PROCEDURE InitConst (const: Const; value: Language.Value; decl: Item.ConstDecl);
  BEGIN
    InitExpression (const);
    const. value := value;
    const. decl := decl;
  END InitConst;

PROCEDURE NewConst (value: Language.Value; decl: Item.ConstDecl): Const;
  VAR
    const: Const;
  BEGIN
    NEW (const);
    InitConst (const, value, decl);
    RETURN const
  END NewConst;

PROCEDURE (v: Visitor) [ABSTRACT] VisitConst* (const: Const);
  END VisitConst;

PROCEDURE (const: Const) Accept* (v: Visitor);
  BEGIN
    v. VisitConst (const)
  END Accept;

(* -------- *)

PROCEDURE InitPredefProc (pproc: PredefProc; name: Item.Name; decl: Item.PredefProc);
  BEGIN
    InitExpression (pproc);
    pproc. name := name;
    pproc. decl := decl;
  END InitPredefProc;

PROCEDURE NewPredefProc (name: Item.Name; decl: Item.PredefProc): PredefProc;
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

PROCEDURE InitProcedureRef (procRef: ProcedureRef; name: Item.Name; decl: Item.ProcDecl);
  BEGIN
    InitExpression (procRef);
    procRef. name := name;
    procRef. decl := decl;
  END InitProcedureRef;

PROCEDURE NewProcedureRef (name: Item.Name; decl: Item.ProcDecl): ProcedureRef;
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

PROCEDURE InitModuleRef (modRef: ModuleRef; name: Item.Name; decl: Item.Module);
  BEGIN
    InitExpression (modRef);
    modRef. name := name;
    modRef. decl := decl;
  END InitModuleRef;

PROCEDURE NewModuleRef (name: Item.Name; decl: Item.Module): ModuleRef;
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
                                     name: Item.Name): Expression;
  VAR
    decl: Item.Declaration;
  BEGIN
    decl := ns. Identify (context, name, FALSE);
    IF (decl = NIL) THEN
      b. ErrName (undeclaredIdent, name)
    ELSE
      WITH decl: Item.ConstDecl DO
        RETURN NewConst (decl. value, decl)
      | decl: Item.PredefProc DO
        RETURN NewPredefProc (name, decl)
      | decl: Item.ProcDecl DO
        RETURN NewProcedureRef (name, decl)
      | decl: Item.Import DO
        RETURN NewModuleRef (name, decl. externalSymTab)
      ELSE
        Log.Type ("decl", decl); ASSERT (FALSE);
      END
    END;
    
    RETURN NIL
  END NewIdentRef;

PROCEDURE (b: Builder) NewQualident* (modref: ModuleRef; context: Item.Item; 
                                      name: Item.Name): Expression;
  BEGIN
    RETURN b. NewIdentRef (modref. decl. ns, context, name)
  END NewQualident;


(* -------- *)

PROCEDURE InitStatement* (statm: Statement);
  BEGIN
    InitExpression (statm);
  END InitStatement;

(* -------- *)

PROCEDURE InitAssert (assert: Assert; predicate: Expression; code: LONGINT;
                      disabled: BOOLEAN);
  BEGIN
    InitStatement (assert);
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

PROCEDURE (b: Builder) NewAssert (arguments: ExpressionList; disabled: BOOLEAN): Assert;
  VAR
    assert: Assert;
  BEGIN  (* ... FIXME: check arguments, add default arg *)
    NEW (assert);
    InitAssert (assert, arguments[0], defaultAssertCode, disabled);
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
    InitNode (call);
    call. design := design;
    call. arguments := arguments;
  END InitCall;

PROCEDURE (b: Builder) NewCall* (design: Expression; arguments: ExpressionList): Expression;
  VAR
    call: Call;
  BEGIN
    NEW (call);
    WITH design: PredefProc DO
      CASE design. decl. id OF
      | Predef.assert:
        RETURN b. NewAssert (arguments,
          GetPragmaValue (b, StdPragmas.assertions, design. name. pos))
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

PROCEDURE InitProcedure* (p: Procedure; decl: Item.ProcDecl; statmSeq: StatementSeq);
  BEGIN
    InitNode (p);
    p. decl := decl;
    p. statmSeq := statmSeq;
  END InitProcedure;

PROCEDURE (b: Builder) NewProcedure* (decl: Item.ProcDecl; statmSeq: StatementSeq): Procedure;
  VAR
    p: Procedure;
  BEGIN
    NEW (p);
    InitProcedure (p, decl, statmSeq);
    RETURN p
  END NewProcedure;

PROCEDURE (v: Visitor) [ABSTRACT] VisitProcedure* (procedure: Procedure);
  END VisitProcedure;

PROCEDURE (p: Procedure) Accept* (v: Visitor);
  BEGIN
    v. VisitProcedure (p)
  END Accept;

(* -------- *)

PROCEDURE InitModule* (m: Module; name: Name; procList: ProcedureList;
                       statmSeq: StatementSeq);
  BEGIN
    InitNode (m);
    m. name := name;
    m. procList := procList;
    m. statmSeq := statmSeq;
  END InitModule;

PROCEDURE (b: Builder) NewModule* (name: Name; procList: ProcedureList;
                                   statmSeq: StatementSeq): Module;
  VAR
    m: Module;
  BEGIN
    NEW (m);
    InitModule (m, name, procList, statmSeq);
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
  Error.InitContext (irContext, "OOC:IR")
END OOC:IR.
