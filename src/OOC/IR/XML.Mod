(* 	$Id$	 *)
MODULE OOC:IR:XML;
(*  Write an IR data structure as an XML document.
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
  Channel, ADT:String, ADT:StringBuffer, XML:Writer, XML:UnicodeCodec:Latin1,
  Sym := OOC:SymbolTable, OOC:IR;

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

PROCEDURE TypeName(type : Sym.Type) : String.String;
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

PROCEDURE (v: Visitor) VisitConst* (const: IR.Const);
  VAR
    type, value: String.String;
  BEGIN
    v. w. StartTag ("const", TRUE);
    type := TypeName(const. type);
    v. w. AttrStringLatin1 ("type", type. array^);
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
    module: Sym.Module;
  BEGIN
    v. w. StartTag ("procedure-reference", FALSE);
    module := procRef. decl. Module();
    v. w. AttrStringLatin1 ("module", module. name. str^);
    v. w. AttrStringLatin1 ("name", procRef. decl. name. str^);
    v. w. EndTag;  (* procedure-reference *)
  END VisitProcedureRef;

PROCEDURE (v: Visitor) VisitTypeRef* (typeRef: IR.TypeRef);
  BEGIN
    v. w. StartTag ("type-reference", FALSE);
    v. w. AttrStringLatin1 ("name", typeRef. decl. name. str^);
    v. w. EndTag;  (* type-reference *)
  END VisitTypeRef;

PROCEDURE (v: Visitor) VisitModuleRef* (modRef: IR.ModuleRef);
  BEGIN
    v. w. StartTag ("module-reference", FALSE);
    v. w. AttrStringLatin1 ("name", modRef. decl. name. str^);
    v. w. EndTag;  (* module-reference *)
  END VisitModuleRef;

PROCEDURE (v: Visitor) VisitAdr* (adr: IR.Adr);
  BEGIN
    v. w. StartTag ("adr", FALSE);
    adr. design. Accept (v);
    v. w. EndTag;  (* adr *)
  END VisitAdr;

PROCEDURE (v: Visitor) VisitLen* (len: IR.Len);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    v. w. StartTag ("len", FALSE);
    v. w. AttrInt ("dim", len. dim);
    CASE len. variant OF
    | IR.lenStringConst: str := "string-const"
    | IR.lenFixedArray: str := "fixed-array"
    | IR.lenOpenArrayParam: str := "open-array-param"
    | IR.lenOpenArrayHeap: str := "open-array-heap"
    END;
    v. w. AttrStringLatin1 ("variant", str);
    len. array. Accept (v);
    v. w. EndTag;  (* len *)
  END VisitLen;

PROCEDURE (v: Visitor) VisitDeref* (deref: IR.Deref);
  BEGIN
    v. w. StartTag ("deref", FALSE);
    deref. pointer. Accept (v);
    v. w. EndTag;  (* deref *)
  END VisitDeref;

PROCEDURE (v: Visitor) VisitIndex* (index: IR.Index);
  BEGIN
    v. w. StartTag ("index", FALSE);
    index. array. Accept (v);
    index. index. Accept (v);
    v. w. EndTag;  (* index *)
  END VisitIndex;

PROCEDURE (v: Visitor) VisitSelectField* (sf: IR.SelectField);
  BEGIN
    v. w. StartTag ("select-field", FALSE);
    v. w. AttrStringLatin1 ("field", sf. field. name. str^);
    sf. record. Accept (v);
    v. w. EndTag;  (* select-field *)
  END VisitSelectField;

PROCEDURE (v: Visitor) VisitNegate* (neg: IR.Negate);
  BEGIN
    v. w. StartTag ("negate", FALSE);
    neg. operand. Accept (v);
    v. w. EndTag;  (* negate *)
  END VisitNegate;

PROCEDURE (v: Visitor) VisitNewObject* (new: IR.NewObject);
  VAR
    i: LONGINT;
  BEGIN
    v. w. StartTag ("new-object", FALSE);
    (* FIXME... write type *)
    IF (new. length # NIL) THEN
      FOR i := 0 TO LEN (new. length^)-1 DO
        new. length[i]. Accept (v);
      END;
    END;
    v. w. EndTag;  (* new-object *)
  END VisitNewObject;

PROCEDURE (v: Visitor) VisitCap* (neg: IR.Cap);
  BEGIN
    v. w. StartTag ("cap", FALSE);
    neg. operand. Accept (v);
    v. w. EndTag;  (* cap *)
  END VisitCap;

PROCEDURE VisitDyadicOp (v: Visitor; op: IR.Operator; variant : SHORTINT; left, right : IR.Expression; name: ARRAY OF CHAR);
  BEGIN
    v. w. StartTagLatin1 (name, FALSE);
    v. w. AttrInt ("variant", variant);
    left. Accept (v);
    right. Accept (v);
    v. w. EndTag;  (* name *)
  END VisitDyadicOp;

PROCEDURE (v: Visitor) VisitBinaryArith* (op: IR.BinaryArith);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.left, op.right, "binaryArith");
  END VisitBinaryArith;

PROCEDURE (v: Visitor) VisitBooleanOp* (op: IR.BooleanOp);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.left, op.right, "booleanOp");
  END VisitBooleanOp;

PROCEDURE (v : Visitor) VisitCompare* (op : IR.Compare);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.left, op.right, "compare");
  END VisitCompare;

PROCEDURE (v: Visitor) VisitSetOp* (op: IR.SetOp);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.left, op.right, "setOp");
  END VisitSetOp;

PROCEDURE (v : Visitor) VisitTypeConv* (op : IR.TypeConv);
  BEGIN
    v. w. StartTag("type-conv", FALSE);
    (* FIXME! Write type. How? *)
    op. expr. Accept(v);
    v. w. EndTag;
  END VisitTypeConv;

PROCEDURE (v : Visitor) VisitTypeTest* (op : IR.TypeTest);
  BEGIN
    v. w. StartTag("type-test", FALSE);
    op. expr. Accept(v);
    (* FIXME! Write type. How? *)
    v. w. EndTag;
  END VisitTypeTest;


PROCEDURE VisitStatementSeq (v: Visitor; statmSeq: IR.StatementSeq);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statmSeq[i]. Accept (v)
    END;
  END VisitStatementSeq;

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

PROCEDURE (v: Visitor) VisitSetRange* (range: IR.SetRange);
  BEGIN
    v. w. StartTag ("setrange", FALSE);
    range.from.Accept(v);
    range.to.Accept(v);
    v. w. EndTag;  (* range *)
  END VisitSetRange;

PROCEDURE (v: Visitor) VisitSetMember* (range: IR.SetMember);
  BEGIN
    v. w. StartTag ("setmember", FALSE);
    range.element.Accept(v);
    range.set.Accept(v);
    v. w. EndTag; 
  END VisitSetMember;

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

PROCEDURE (v: Visitor) VisitAssignOp* (assignOp: IR.AssignOp);
  BEGIN
    v. w. StartTag ("assign-operation", FALSE);
    assignOp. variable. Accept (v);
    assignOp. value. Accept (v);
    v. w. EndTag;  (* assign-operation *)
  END VisitAssignOp;

PROCEDURE (v: Visitor) VisitExit* (exit: IR.Exit);
  BEGIN
    v. w. StartTag ("exit", FALSE);
    v. w. EndTag;  (* exit *)
  END VisitExit;

PROCEDURE (v: Visitor) VisitForStatm* (whileStatm: IR.ForStatm);
  BEGIN
    v. w. StartTag ("while-statm", FALSE);
    v. w. StartTag ("variable", FALSE);
    whileStatm. var. Accept (v);
    v. w. EndTag;  (* variable *)
    v. w. StartTag ("start-value", FALSE);
    whileStatm. start. Accept (v);
    v. w. EndTag;  (* start-value *)
    v. w. StartTag ("end-value", FALSE);
    whileStatm. end. Accept (v);
    v. w. EndTag;  (* end-value *)
    v. w. StartTag ("step", FALSE);
    whileStatm. step. Accept (v);
    v. w. EndTag;  (* step *)
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, whileStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* while-statm *)
  END VisitForStatm;

PROCEDURE (v: Visitor) VisitIfStatm* (ifStatm: IR.IfStatm);
  BEGIN
    v. w. StartTag ("if-statm", FALSE);
    v. w. StartTag ("guard", FALSE);
    ifStatm. guard. Accept (v);
    v. w. EndTag;  (* guard *)
    
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

PROCEDURE (v: Visitor) VisitLoopStatm* (loopStatm: IR.LoopStatm);
  BEGIN
    v. w. StartTag ("loop-statm", FALSE);
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, loopStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* loop-statm *)
  END VisitLoopStatm;

PROCEDURE (v: Visitor) VisitRepeatStatm* (repeatStatm: IR.RepeatStatm);
  BEGIN
    v. w. StartTag ("repeat-statm", FALSE);
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, repeatStatm. body);
    v. w. EndTag;  (* body *)
    v. w. StartTag ("exit-condition", FALSE);
    repeatStatm. exitCondition. Accept (v);
    v. w. EndTag;  (* exit-condition *)
    v. w. EndTag;  (* repeat-statm *)
  END VisitRepeatStatm;

PROCEDURE (v: Visitor) VisitWhileStatm* (whileStatm: IR.WhileStatm);
  BEGIN
    v. w. StartTag ("while-statm", FALSE);
    v. w. StartTag ("guard", FALSE);
    whileStatm. guard. Accept (v);
    v. w. EndTag;  (* guard *)
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, whileStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* while-statm *)
  END VisitWhileStatm;

PROCEDURE (v: Visitor) VisitCopyParameter* (cp: IR.CopyParameter);
  BEGIN
    v. w. StartTag ("copy-parameter", FALSE);
    v. w. AttrStringLatin1 ("parameter", cp. param. decl. name. str^);
    v. w. EndTag;  (* copy-parameter *)
  END VisitCopyParameter;


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
    VisitStatementSeq (v, module. moduleBody. statmSeq);
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
