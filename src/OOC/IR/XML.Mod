MODULE OOC:IR:XML;

IMPORT
  Channel, ADT:String, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:SymbolTable:Item, OOC:IR;



TYPE
  Visitor = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (IR.VisitorDesc)
    w: Writer.Writer;
  END;


PROCEDURE InitVisitor (v: Visitor; w: Writer.Writer);
  BEGIN
    IR.InitVisitor (v);
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
    v. w. EndTag;  (* call *)
  END VisitAssert;


PROCEDURE VisitProcedureList (v: Visitor; procList: IR.ProcedureList);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (procList^)-1 DO
      procList[i]. Accept (v)
    END;
  END VisitProcedureList;

PROCEDURE VisitStatementSeq (v: Visitor; statmSeq: IR.StatementSeq);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statmSeq[i]. Accept (v)
    END;
  END VisitStatementSeq;

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
