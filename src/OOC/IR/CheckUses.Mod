MODULE OOC:IR:CheckUses;

IMPORT
  ADT:Dictionary, Sym := OOC:SymbolTable, OOC:Error,
  OOC:Scanner:Builder:BasicList, OOC:IR, OOC:IR:VisitAll;

TYPE
  Def = POINTER TO DefDesc;
  DefDesc = RECORD
    undefined, maybeUndefined: Dictionary.Dictionary;
  END;

TYPE
  Symbol = BasicList.Symbol;
  Visitor = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (VisitAll.VisitorDesc)
    def: Def;
    errList: Error.List;
  END;
  
CONST
  undefinedVar = 1;
  maybeUndefinedVar = 2;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  checkUsesContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | undefinedVar:
      t := Error.warningPrefix+"Undefined variable"
    | maybeUndefinedVar:
      t := Error.warningPrefix+"Variable may be undefined"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE NewDef(): Def;
  VAR
    def: Def;
  BEGIN
    NEW(def);
    def.maybeUndefined := Dictionary.New();
    def.undefined := Dictionary.New();
    RETURN def;
  END NewDef;


PROCEDURE ErrSym(v: Visitor; code: Error.Code; sym: Symbol);
  VAR
    e: Error.Msg;
  BEGIN
    e := Error.New(checkUsesContext, code);
    e.SetIntAttrib("pos", sym.pos);
    e.SetIntAttrib("line", sym.line);
    e.SetIntAttrib("column", sym.column);
    v.errList.Append (e);
  END ErrSym;

PROCEDURE (v: Visitor) VisitVar* (var: IR.Var);
  BEGIN
    IF v.def.undefined.HasKey(var.decl) THEN
      ErrSym(v, undefinedVar, var.sym);
    END;
    IF v.def.maybeUndefined.HasKey(var.decl) THEN
      ErrSym(v, maybeUndefinedVar, var.sym);
    END;
  END VisitVar;


PROCEDURE CheckUses*(module: IR.Module; errList: Error.List);
  VAR
    i: LONGINT;
    proc: IR.Procedure;
    v: Visitor;
    
  PROCEDURE CheckStatmSeq(def: Def; statmSeq: IR.StatementSeq);
    VAR
      i: LONGINT;
      
    PROCEDURE CheckExpr(expr: IR.Expression);
      BEGIN
        v.def := def;
        expr.Accept(v);
      END CheckExpr;
    
    PROCEDURE CheckDesign(design: IR.Expression; mode: SHORTINT);
      BEGIN
      END CheckDesign;
    
    PROCEDURE CheckStatm(statm: IR.Statement);
      CONST
        read = 0;
        write = 1;
      VAR
        i: LONGINT;
      BEGIN
        WITH statm: IR.Assert DO
          CheckExpr(statm.predicate);
        | statm: IR.AssignOp DO
          CheckExpr(statm.variable);
          CheckExpr(statm.value);
          CheckDesign(statm.variable, write);
        | statm: IR.Assignment DO
          CheckExpr(statm.value);
          CheckDesign(statm.variable, write);
        | statm: IR.Call DO
          CheckDesign(statm.design, read);
          FOR i := 0 TO LEN(statm.arguments^)-1 DO
            CheckExpr(statm.arguments[i]);
          END;
        | statm: IR.Copy DO
          CheckExpr(statm.source);
          CheckDesign(statm.dest, write);
        | statm: IR.CopyParameter DO
          (* ignore *)
        | statm: IR.CopyString DO
          CheckExpr(statm.source);
          CheckDesign(statm.dest, write);
        | statm: IR.ForStatm DO
          CheckExpr(statm.start);
          CheckExpr(statm.end);
        | statm: IR.IfStatm DO
          CheckExpr(statm.guard);
        | statm: IR.CaseStatm DO
          CheckExpr(statm.select);
        | statm: IR.LoopStatm DO
          (* ... *)
        | statm: IR.MoveBlock DO
          CheckExpr(statm.source);
          CheckExpr(statm.dest);
          CheckExpr(statm.size);
        | statm: IR.Raise DO
          CheckExpr(statm.exception);
        | statm: IR.RepeatStatm DO
          CheckExpr(statm.exitCondition);
        | statm: IR.Return DO
          IF (statm.result # NIL) THEN
            CheckExpr(statm.result);
          END;
        | statm: IR.TryStatm DO
          (* ... *)
        | statm: IR.WhileStatm DO
          CheckExpr(statm.guard);
        | statm: IR.WithStatm DO
          CheckExpr(statm.guard);
        END;
      END CheckStatm;
    
    BEGIN
      FOR i := 0 TO LEN(statmSeq^)-1 DO
        CheckStatm(statmSeq[i]);
      END;
    END CheckStatmSeq;
  
  PROCEDURE CreateDef(procDecl: Sym.ProcDecl): Def;
    VAR
      decl: Sym.Item;
      def: Def;
    BEGIN
      def := NewDef();
      decl := procDecl.nestedItems;
      WHILE (decl # NIL) DO
        IF (decl IS Sym.VarDecl) & ~decl(Sym.VarDecl).isParameter THEN
          def.undefined.Set(decl, NIL);
        END;
        decl := decl.nextNested;
      END;
      RETURN def;
    END CreateDef;
  
  BEGIN
    RETURN;  (* incomplete; disable for now *)
    
    NEW(v);
    VisitAll.InitVisitor(v);
    v.errList := errList;
    v.def := NIL;
    
    FOR i := 0 TO LEN (module.procList^)-1 DO
      proc := module.procList[i];
      CheckStatmSeq(CreateDef(proc.decl), proc.statmSeq);
    END;
  END CheckUses;

BEGIN
  NEW (checkUsesContext);
  Error.InitContext (checkUsesContext, "OOC:IR:CheckUses");
END OOC:IR:CheckUses.
