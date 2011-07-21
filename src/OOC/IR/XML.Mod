(* 	$Id: XML.Mod,v 1.79 2005/10/07 08:35:42 mva Exp $	 *)
MODULE OOC:IR:XML;
(*  Write an IR data structure as an XML document.
    Copyright (C) 2001-2005  Michael van Acken, Stewart Greenhill

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
  Object, IO, XML:Writer, XML:UnicodeCodec:Latin1,
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

PROCEDURE TypeAttr (w : Writer.Writer; type : Sym.Type);
(** Output the name of @oparam{type} as attribute "Type" of the current tag. *)
  BEGIN
    w.AttrObject("Type", IR.TypeName(type));
  END TypeAttr;

PROCEDURE (v: Visitor) VisitConst* (const: IR.Const);
  VAR
    value: STRING;
    chars: Object.CharsLatin1;
  BEGIN
    v. w. StartTag ("const", TRUE);
    TypeAttr(v.w, const.type);
    value := const. ToString();
    chars := value(Object.String8).CharsLatin1();
    v. w. WriteLatin1 (chars^);
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

PROCEDURE (v: Visitor) VisitConstructor* (cons: IR.Constructor);
  BEGIN
    v. w. StartTag ("constructor", FALSE);
    v. w. StartTag ("alloc", FALSE);
    cons. alloc. Accept(v);
    v. w. EndTag;  (* alloc *)
    IF (cons.init # NIL) THEN
      v. w. StartTag ("init", FALSE);
      cons. init. Accept(v);
      v. w. EndTag;  (* init *)
    END;
    v. w. EndTag;  (* constructor *)
  END VisitConstructor;

PROCEDURE (v: Visitor) VisitCurrentException*(ce: IR.CurrentException);
  BEGIN
    v. w. StartTag ("current-exception", FALSE);
    v. w. EndTag;  (* current-exception *)
  END VisitCurrentException;

PROCEDURE (v: Visitor) VisitDeref* (deref: IR.Deref);
  BEGIN
    v. w. StartTag ("deref", FALSE);
    v. w. AttrBool ("check-pointer", deref. checkPointer);
    deref. pointer. Accept (v);
    v. w. EndTag;  (* deref *)
  END VisitDeref;

PROCEDURE (v: Visitor) VisitIndex* (index: IR.Index);
  BEGIN
    v. w. StartTag ("index", FALSE);
    v. w. AttrBool ("check-index", index. checkIndex);
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

PROCEDURE (v: Visitor) VisitSelectProc* (sp: IR.SelectProc);
  BEGIN
    v. w. StartTag ("select-tb-proc", FALSE);
    v. w. AttrBool ("static-call", sp. isStaticCall);
    v. w. AttrBool ("super-call", sp. isSuperCall);
    v. w. AttrStringLatin1 ("tb-proc", sp. tbProc. name. str^);
    sp. receiver. Accept (v);
    v. w. EndTag;  (* select-tb-proc *)
  END VisitSelectProc;

PROCEDURE (v: Visitor) VisitNegate* (neg: IR.Negate);
  BEGIN
    v. w. StartTag ("negate", FALSE);
    neg. operand. Accept (v);
    v. w. EndTag;  (* negate *)
  END VisitNegate;

PROCEDURE (v: Visitor) VisitNewBlock* (new: IR.NewBlock);
  BEGIN
    v. w. StartTag ("new-block", FALSE);
    (* FIXME... write type *)
    new. size. Accept (v);
    v. w. EndTag;  (* new-block *)
  END VisitNewBlock;

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

PROCEDURE (v: Visitor) VisitNot* (neg: IR.Not);
  BEGIN
    v. w. StartTag ("not", FALSE);
    neg. operand. Accept (v);
    v. w. EndTag;  (* not *)
  END VisitNot;

PROCEDURE (v: Visitor) VisitAbs* (abs: IR.Abs);
  BEGIN
    v. w. StartTag ("abs", FALSE);
    abs. operand. Accept (v);
    v. w. EndTag;  (* abs *)
  END VisitAbs;

PROCEDURE (v: Visitor) VisitAsh* (ash: IR.Ash);
  BEGIN
    v. w. StartTag ("ash", FALSE);
    ash. value. Accept (v);
    ash. exp. Accept (v);
    v. w. EndTag;  (* ash *)
  END VisitAsh;

PROCEDURE (v: Visitor) VisitCap* (cap: IR.Cap);
  BEGIN
    v. w. StartTag ("cap", FALSE);
    cap. operand. Accept (v);
    v. w. EndTag;  (* cap *)
  END VisitCap;

PROCEDURE (v: Visitor) VisitEntier* (entier: IR.Entier);
  BEGIN
    v. w. StartTag ("entier", FALSE);
    entier. operand. Accept (v);
    v. w. EndTag;  (* entier *)
  END VisitEntier;

PROCEDURE (v: Visitor) VisitOdd* (odd: IR.Odd);
  BEGIN
    v. w. StartTag ("odd", FALSE);
    odd. operand. Accept (v);
    v. w. EndTag;  (* odd *)
  END VisitOdd;

PROCEDURE (v: Visitor) VisitShift* (shift: IR.Shift);
  BEGIN
    v. w. StartTag ("logical-shift", FALSE);
    v. w. AttrBool ("rotate", shift. rotate);
    shift. value. Accept (v);
    shift. by. Accept (v);
    v. w. EndTag;  (* logical-shift *)
  END VisitShift;

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

PROCEDURE (v: Visitor) VisitConcat* (op: IR.Concat);
  VAR
    i: LONGINT;
  BEGIN
    v.w.StartTagLatin1("concat", FALSE);
    FOR i := 0 TO LEN(op.strings^)-1 DO
      op.strings[i].Accept(v);
    END;
    v.w.EndTag;                          (* concat *)
  END VisitConcat;

PROCEDURE (v : Visitor) VisitCompare* (op : IR.Compare);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.left, op.right, "compare");
  END VisitCompare;

PROCEDURE (v: Visitor) VisitChangeElement* (op: IR.ChangeElement);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.set, op.element, "change-element");
  END VisitChangeElement;

PROCEDURE (v: Visitor) VisitSetOp* (op: IR.SetOp);
  BEGIN
    VisitDyadicOp (v, op, op.variant, op.left, op.right, "setOp");
  END VisitSetOp;

PROCEDURE (v : Visitor) VisitTypeCast* (op : IR.TypeCast);
  BEGIN
    v. w. StartTag("type-cast", FALSE);
    TypeAttr(v.w, op.type);
    op. expr. Accept(v);
    v. w. EndTag;
  END VisitTypeCast;

PROCEDURE (v : Visitor) VisitTypeConv* (op : IR.TypeConv);
  BEGIN
    v. w. StartTag("type-conv", FALSE);
    TypeAttr(v.w, op.type);
    op. expr. Accept(v);
    v. w. EndTag;
  END VisitTypeConv;

PROCEDURE (v : Visitor) VisitTypeGuard* (op : IR.TypeGuard);
  BEGIN
    v. w. StartTag("type-guard", FALSE);
    TypeAttr(v.w, op.type);
    op. test. origExpr. Accept(v);
    v. w. EndTag;
  END VisitTypeGuard;

PROCEDURE (v : Visitor) VisitTypeTag* (op : IR.TypeTag);
  BEGIN
    v. w. StartTag("type-tag", FALSE);
    op. design. Accept(v);
    v. w. EndTag;
  END VisitTypeTag;

PROCEDURE (v : Visitor) VisitTypeTest* (op : IR.TypeTest);
  BEGIN
    v. w. StartTag("type-test", FALSE);
    TypeAttr(v.w, op.type);
    op. expr. Accept(v);
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
    IF (assert. predicate # NIL) THEN
      assert. predicate. Accept (v);
    END;
    v. w. EndTag;  (* assert *)
  END VisitAssert;

PROCEDURE (v: Visitor) VisitSetRange* (range: IR.SetRange);
  BEGIN
    v. w. StartTag ("set-range", FALSE);
    range.from.Accept(v);
    range.to.Accept(v);
    v. w. EndTag;  (* set-range *)
  END VisitSetRange;

PROCEDURE (v: Visitor) VisitSetMember* (range: IR.SetMember);
  BEGIN
    v. w. StartTag ("set-member", FALSE);
    range.element.Accept(v);
    range.set.Accept(v);
    v. w. EndTag;   (* set-member *)
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

PROCEDURE (v: Visitor) VisitForStatm* (forStatm: IR.ForStatm);
  BEGIN
    v. w. StartTag ("for-statm", FALSE);
    v. w. StartTag ("variable", FALSE);
    forStatm. var. Accept (v);
    v. w. EndTag;  (* variable *)
    v. w. StartTag ("start-value", FALSE);
    forStatm. start. Accept (v);
    v. w. EndTag;  (* start-value *)
    v. w. StartTag ("end-value", FALSE);
    forStatm. end. Accept (v);
    v. w. EndTag;  (* end-value *)
    v. w. StartTag ("step", FALSE);
    forStatm. step. Accept (v);
    v. w. EndTag;  (* step *)
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, forStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* for-statm *)
  END VisitForStatm;

PROCEDURE (v: Visitor) VisitIterateArrayStatm* (iterStatm: IR.IterateArrayStatm);
  BEGIN
    v. w. StartTag ("iterate-array-statm", FALSE);
    v. w. StartTag ("variable", FALSE);
    iterStatm. var. Accept (v);
    v. w. EndTag;  (* variable *)
    v. w. StartTag ("range", FALSE);
    iterStatm. range. Accept (v);
    v. w. EndTag;  (* range *)
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, iterStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* iterate-array-statm *)
  END VisitIterateArrayStatm;

PROCEDURE (v: Visitor) VisitIterateObjectStatm* (iterStatm: IR.IterateObjectStatm);
  BEGIN
    v. w. StartTag ("iterate-object-statm", FALSE);
    v. w. StartTag ("variable", FALSE);
    iterStatm. var. Accept (v);
    v. w. EndTag;  (* variable *)
    v. w. StartTag ("iterator-factory", FALSE);
    iterStatm. iteratorFactory. Accept (v);
    v. w. EndTag;  (* iterator-factory *)
    v. w. StartTag ("stepper-call", TRUE);
    iterStatm. stepperCall. Accept (v);
    v. w. EndTag;  (* stepper-call *)
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, iterStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* iterate-array-statm *)
  END VisitIterateObjectStatm;

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

PROCEDURE (v: Visitor) VisitCase* (case: IR.Case);
  VAR
    i: LONGINT;
  BEGIN
    v. w. StartTag ("case", FALSE);
    v. w. StartTag ("guard", FALSE);
    FOR i := 0 TO LEN (case. labels^)-1 DO
      v. w. StartTag ("label", FALSE);
      case. labels[i]. Accept (v);
      v. w. EndTag;  (* label *)
    END;
    v. w. EndTag;  (* guard *)
    
    v. w. StartTag ("statm-seq", FALSE);
    VisitStatementSeq (v, case. statmSeq);
    v. w. EndTag;  (* statm-seq *)
    v. w. EndTag;  (* case *)
  END VisitCase;

PROCEDURE (v: Visitor) VisitCaseStatm* (caseStatm: IR.CaseStatm);
  VAR
    i: LONGINT;
  BEGIN
    v. w. StartTag ("case-statm", FALSE);
    v. w. AttrBool ("check-match", caseStatm. checkMatch);
    v. w. StartTag ("select", FALSE);
    caseStatm. select. Accept (v);
    v. w. EndTag;  (* select *)

    FOR i := 0 TO LEN (caseStatm. caseList^)-1 DO
      caseStatm. caseList[i]. Accept (v);
    END;

    IF (caseStatm. default # NIL) THEN
      v. w. StartTag ("default-path", FALSE);
      VisitStatementSeq (v, caseStatm. default);
      v. w. EndTag;  (* default-path *)
    END;
    v. w. EndTag;  (* case-stamt *)
  END VisitCaseStatm;

PROCEDURE (v: Visitor) VisitLoopStatm* (loopStatm: IR.LoopStatm);
  BEGIN
    v. w. StartTag ("loop-statm", FALSE);
    v. w. StartTag ("body", FALSE);
    VisitStatementSeq (v, loopStatm. body);
    v. w. EndTag;  (* body *)
    v. w. EndTag;  (* loop-statm *)
  END VisitLoopStatm;

PROCEDURE (v: Visitor) VisitMoveBlock* (move: IR.MoveBlock);
  BEGIN
    v. w. StartTag ("move", FALSE);
    v. w. StartTag ("source", FALSE);
    move. source. Accept (v);
    v. w. EndTag;  (* source *)
    v. w. StartTag ("dest", FALSE);
    move. dest. Accept (v);
    v. w. EndTag;  (* dest *)
    v. w. StartTag ("size", FALSE);
    move. size. Accept (v);
    v. w. EndTag;  (* size *)
    v. w. EndTag;  (* move *)
  END VisitMoveBlock;

PROCEDURE (v: Visitor) VisitRaise* (raise: IR.Raise);
  BEGIN
    v. w. StartTag ("raise", FALSE);
    raise. exception. Accept (v);
    v. w. EndTag;  (* raise *)
  END VisitRaise;

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

PROCEDURE (v: Visitor) VisitCatchClause* (catch: IR.CatchClause);
  BEGIN
    v.w.StartTag("catch", FALSE);
    TypeAttr(v.w, catch.type);
    VisitStatementSeq(v, catch.statmSeq);
    v.w.EndTag();  (* catch *)
  END VisitCatchClause;

PROCEDURE (v: Visitor) VisitTryStatm* (tryStatm: IR.TryStatm);
  VAR
    i: LONGINT;
  BEGIN
    v.w.StartTag("try-statm", FALSE);
    VisitStatementSeq(v, tryStatm.statmSeq);
    FOR i := 0 TO LEN(tryStatm.catchList^)-1 DO
      tryStatm.catchList[i].Accept(v);
    END;
    v.w.EndTag();  (* try-statm *)
  END VisitTryStatm;

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

PROCEDURE (v: Visitor) VisitWithStatm* (withStatm: IR.WithStatm);
  BEGIN
    v. w. StartTag ("with-statm", FALSE);
    v. w. StartTag ("guard", FALSE);
    withStatm. guard. Accept (v);
    v. w. EndTag;  (* guard *)
    
    v. w. StartTag ("path-true", FALSE);
    VisitStatementSeq (v, withStatm. pathTrue);
    v. w. EndTag;  (* path-true *)
    
    IF (withStatm. pathFalse # NIL) THEN
      v. w. StartTag ("path-false", FALSE);
      VisitStatementSeq (v, withStatm. pathFalse);
      v. w. EndTag;  (* path-false *)
    END;
    v. w. EndTag;  (* with-statm *)
  END VisitWithStatm;

PROCEDURE (v: Visitor) VisitCopy* (cp: IR.Copy);
  BEGIN
    v. w. StartTag ("copy", FALSE);
    v. w. StartTag ("source", FALSE);
    cp. source. Accept (v);
    v. w. EndTag;  (* source *)
    v. w. StartTag ("dest", FALSE);
    cp. dest. Accept (v);
    v. w. EndTag;  (* dest *)
    v. w. EndTag;  (* copy *)
  END VisitCopy;

PROCEDURE (v: Visitor) VisitCopyParameter* (cp: IR.CopyParameter);
  BEGIN
    v. w. StartTag ("copy-parameter", FALSE);
    v. w. AttrStringLatin1 ("parameter", cp. param. decl. name. str^);
    v. w. EndTag;  (* copy-parameter *)
  END VisitCopyParameter;

PROCEDURE (v: Visitor) VisitCopyString* (cp: IR.CopyString);
  BEGIN
    v. w. StartTag ("copy-string", FALSE);
    v. w. StartTag ("source", FALSE);
    cp. source. Accept (v);
    v. w. EndTag;  (* source *)
    v. w. StartTag ("dest", FALSE);
    cp. dest. Accept (v);
    v. w. EndTag;  (* dest *)
    v. w. StartTag ("max-length", FALSE);
    cp. maxLength. Accept (v);
    v. w. EndTag;  (* max-length *)
    v. w. EndTag;  (* copy-string *)
  END VisitCopyString;


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


PROCEDURE Write* (cw: IO.ByteChannel; module: IR.Module)
RAISES IO.Error;
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
