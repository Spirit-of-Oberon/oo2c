MODULE OOC:IR:XML;

IMPORT
  Channel, ADT:String, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:SymbolTable:Item, OOC:IR, OOC:IR:Operator;



TYPE
  Visitor = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (Operator.VisitorDesc)
    w: Writer.Writer;
  END;


PROCEDURE InitVisitor (v: Visitor; w: Writer.Writer);
  BEGIN
    Operator.InitVisitor (v);
    v. w := w;
  END InitVisitor;

PROCEDURE NewVisitor (w: Writer.Writer): Visitor;
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    InitVisitor (v, w);
    RETURN v
  END NewVisitor;


PROCEDURE (v: Visitor) VisitConst* (const: IR.Const);
  VAR
    type, value: String.String;
  BEGIN
    v. w. StartTag ("const", TRUE);
    type := const. value. type. ToString();
    v. w. AttrStringLatin1 ("type", type. array^);
    (* ... WRONG! The type above shoule be the logical type, not the
           internal representation that happens to be used by the compiler *)
    
    value := const. value. ToString();
    v. w. WriteLatin1 (value. array^);
    v. w. EndTag;  (* const *)
  END VisitConst;

PROCEDURE (v: Visitor) VisitVar* (var: IR.Var);
  BEGIN
    v. w. StartTag ("var", TRUE);
    v. w. WriteLatin1 (var. decl. name. str^);
    v. w. EndTag;  (* var *)
  END VisitVar;

PROCEDURE (v: Visitor) VisitPredefProc* (pproc: IR.PredefProc);
  BEGIN
    v. w. StartTag ("predef-proc", FALSE);
    v. w. AttrStringLatin1 ("name", pproc. decl. name. str^);
    v. w. EndTag;  (* predef-proc *)
  END VisitPredefProc;

PROCEDURE (v: Visitor) VisitProcedureRef* (procRef: IR.ProcedureRef);
  VAR
    module: Item.Module;
  BEGIN
    v. w. StartTag ("procedure-reference", FALSE);
    module := procRef. decl. Module();
    v. w. AttrStringLatin1 ("module", module. name. str^);
    v. w. AttrStringLatin1 ("name", procRef. decl. name. str^);
    v. w. EndTag;  (* procedure-reference *)
  END VisitProcedureRef;

PROCEDURE (v: Visitor) VisitModuleRef* (modRef: IR.ModuleRef);
  BEGIN
    v. w. StartTag ("module-reference", FALSE);
    v. w. AttrStringLatin1 ("name", modRef. decl. name. str^);
    v. w. EndTag;  (* module-reference *)
  END VisitModuleRef;

PROCEDURE (v: Visitor) VisitIndex* (index: Operator.Index);
  BEGIN
    v. w. StartTag ("index", FALSE);
    index. opnd1. Accept (v);
    index. opnd2. Accept (v);
    v. w. EndTag;  (* index *)
  END VisitIndex;

PROCEDURE (v: Visitor) VisitNegate* (neg: Operator.Negate);
  BEGIN
    v. w. StartTag ("negate", FALSE);
    neg. opnd1. Accept (v);
    v. w. EndTag;  (* negate *)
  END VisitNegate;

PROCEDURE (v: Visitor) VisitAdd* (add: Operator.Add);
  BEGIN
    v. w. StartTag ("add", FALSE);
    add. opnd1. Accept (v);
    add. opnd2. Accept (v);
    v. w. EndTag;  (* add *)
  END VisitAdd;


PROCEDURE (v: Visitor) VisitCall* (call: IR.Call);
  VAR
    i: LONGINT;
  BEGIN
    v. w. StartTag ("call", FALSE);
    v. w. StartTag ("designator", FALSE);
    call. design. Accept (v);
    v. w. EndTag;  (* designator *)
    FOR i := 0 TO LEN (call. arguments^)-1 DO
      v. w. StartTag ("argument", FALSE);
      call. arguments[i]. Accept (v);
      v. w. EndTag;  (* argument *)
    END;
    v. w. EndTag;  (* call *)
  END VisitCall;

PROCEDURE (v: Visitor) VisitAssert* (assert: IR.Assert);
  BEGIN
    v. w. StartTag ("assert", FALSE);
    v. w. AttrBool ("disabled", assert. disabled);
    v. w. AttrInt ("code", assert. code);
    assert. predicate. Accept (v);
    v. w. EndTag;  (* assert *)
  END VisitAssert;

PROCEDURE (v: Visitor) VisitReturn* (return: IR.Return);
  BEGIN
    v. w. StartTag ("return", FALSE);
    IF (return. result # NIL) THEN
      return. result. Accept (v);
    END;
    v. w. EndTag;  (* return *)
  END VisitReturn;

PROCEDURE (v: Visitor) VisitAssignment* (assignment: IR.Assignment);
  BEGIN
    v. w. StartTag ("assignment", FALSE);
    assignment. variable. Accept (v);
    assignment. value. Accept (v);
    v. w. EndTag;  (* assignment *)
  END VisitAssignment;

PROCEDURE VisitStatementSeq (v: Visitor; statmSeq: IR.StatementSeq);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statmSeq[i]. Accept (v)
    END;
  END VisitStatementSeq;

PROCEDURE (v: Visitor) VisitIfStatm* (ifStatm: IR.IfStatm);
  BEGIN
    v. w. StartTag ("if-statm", FALSE);
    ifStatm. guard. Accept (v);
    v. w. StartTag ("path-true", FALSE);
    VisitStatementSeq (v, ifStatm. pathTrue);
    v. w. EndTag;  (* path-true *)
    IF (ifStatm. pathFalse # NIL) THEN
      v. w. StartTag ("path-false", FALSE);
      VisitStatementSeq (v, ifStatm. pathFalse);
      v. w. EndTag;  (* path-false *)
    END;
    v. w. EndTag;  (* if-statm *)
  END VisitIfStatm;


PROCEDURE VisitProcedureList (v: Visitor; procList: IR.ProcedureList);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (procList^)-1 DO
      procList[i]. Accept (v)
    END;
  END VisitProcedureList;

PROCEDURE (v: Visitor) VisitProcedure* (procedure: IR.Procedure);
  BEGIN
    v. w. StartTag ("procedure", FALSE);
    v. w. AttrStringLatin1 ("name", procedure. decl. name. str^);
    v. w. StartTag ("proc-code", FALSE);
    VisitStatementSeq (v, procedure. statmSeq);
    v. w. EndTag;  (* proc-code *)
    v. w. EndTag;  (* procedure *)
  END VisitProcedure;

PROCEDURE (v: Visitor) VisitModule* (module: IR.Module);
  BEGIN
    v. w. StartTag ("module", FALSE);
    v. w. AttrStringLatin1 ("name", module. name^);
    VisitProcedureList (v, module. procList);
    v. w. StartTag ("init-code", FALSE);
    VisitStatementSeq (v, module. statmSeq);
    v. w. EndTag;  (* init-code *)
    v. w. EndTag;  (* module *)
  END VisitModule;


PROCEDURE Write* (cw: Channel.Writer; module: IR.Module);
  VAR
    w: Writer.Writer;
    v: Visitor;
  BEGIN
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");
    
    v := NewVisitor (w);
    module. Accept (v);
    
    w. EndOfText
  END Write;
  
END OOC:IR:XML.
