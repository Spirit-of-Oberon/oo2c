(* 	$Id: VisitAll.Mod,v 1.16 2004/03/22 21:14:50 mva Exp $	 *)
MODULE OOC:IR:VisitAll;
(*  A visitor traversing the whole IR data structure.
    Copyright (C) 2002, 2003, 2004  Michael van Acken

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
  OOC:IR;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD 
    (**This class implements an empty visitor traversing the whole IR
       data structure.  Note: Expressions that appear in the declaration
       area are currently @emph{not} visited.  *)
    (IR.VisitorDesc)
  END;

PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
    IR.InitVisitor (v);
  END InitVisitor;


(* NOTE: The order of Visit methods mirrors the order of the class
   declarations of IR.Mod *)

PROCEDURE (v: Visitor) VisitConst* (const: IR.Const);
  END VisitConst;

PROCEDURE (v: Visitor) VisitAbs* (abs: IR.Abs);
  BEGIN
    abs. operand. Accept (v);
  END VisitAbs;

PROCEDURE (v: Visitor) VisitAdr* (adr: IR.Adr);
  BEGIN
    adr. design. Accept (v);
  END VisitAdr;

PROCEDURE (v: Visitor) VisitAsh* (ash: IR.Ash);
  BEGIN
    ash. value. Accept (v);
    ash. exp. Accept (v);
  END VisitAsh;

PROCEDURE (v: Visitor) VisitBinaryArith* (op: IR.BinaryArith);
  BEGIN
    op. left. Accept (v);
    op. right. Accept (v);
  END VisitBinaryArith;

PROCEDURE (v: Visitor) VisitBooleanOp* (op: IR.BooleanOp);
  BEGIN
    op. left. Accept (v);
    op. right. Accept (v);
  END VisitBooleanOp;

PROCEDURE (v: Visitor) VisitCap* (cap: IR.Cap);
  BEGIN
    cap. operand. Accept (v);
  END VisitCap;

PROCEDURE (v: Visitor) VisitConcat* (op: IR.Concat);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN(op.strings^)-1 DO
      op.strings[i].Accept(v);
    END;
  END VisitConcat;

PROCEDURE (v: Visitor) VisitCompare* (op: IR.Compare);
  BEGIN
    op. left. Accept (v);
    op. right. Accept (v);
  END VisitCompare;

PROCEDURE (v: Visitor) VisitConstructor* (cons: IR.Constructor);
  BEGIN
    cons.alloc.Accept(v);
    IF (cons.init # NIL) THEN
      cons.init.Accept(v);
    END;
  END VisitConstructor;

PROCEDURE (v: Visitor) VisitCurrentException*(ce: IR.CurrentException);
  BEGIN
  END VisitCurrentException;

PROCEDURE (v: Visitor) VisitDeref* (deref: IR.Deref);
  BEGIN
    deref. pointer. Accept (v);
  END VisitDeref;

PROCEDURE (v: Visitor) VisitEntier* (entier: IR.Entier);
  BEGIN
    entier. operand. Accept (v);
  END VisitEntier;

PROCEDURE (v: Visitor) VisitIndex* (index: IR.Index);
  BEGIN
    index. array. Accept (v);
    index. index. Accept (v);
  END VisitIndex;

PROCEDURE (v: Visitor) VisitLen* (len: IR.Len);
  BEGIN
    len. array. Accept (v);
  END VisitLen;

PROCEDURE (v: Visitor) VisitNegate* (neg: IR.Negate);
  BEGIN
    neg. operand. Accept (v);
  END VisitNegate;

PROCEDURE (v: Visitor) VisitNewBlock* (new: IR.NewBlock);
  BEGIN
    new.size.Accept(v);
  END VisitNewBlock;

PROCEDURE (v: Visitor) VisitNewObject* (new: IR.NewObject);
  VAR
    i: LONGINT;
  BEGIN
    IF (new. length # NIL) THEN
      FOR i := 0 TO LEN (new. length^)-1 DO
        new. length[i]. Accept (v);
      END;
    END;
  END VisitNewObject;

PROCEDURE (v: Visitor) VisitNot* (neg: IR.Not);
  BEGIN
    neg. operand. Accept (v);
  END VisitNot;

PROCEDURE (v: Visitor) VisitOdd* (odd: IR.Odd);
  BEGIN
    odd. operand. Accept (v);
  END VisitOdd;

PROCEDURE (v: Visitor) VisitSelectField* (sf: IR.SelectField);
  BEGIN
    sf. record. Accept (v);
  END VisitSelectField;

PROCEDURE (v: Visitor) VisitSelectProc* (sp: IR.SelectProc);
  BEGIN
    sp. receiver. Accept (v);
  END VisitSelectProc;

PROCEDURE (v: Visitor) VisitSetMember* (range: IR.SetMember);
  BEGIN
    range. element. Accept (v);
    range. set. Accept (v);
  END VisitSetMember;

PROCEDURE (v: Visitor) VisitSetOp* (op: IR.SetOp);
  BEGIN
    op. left. Accept (v);
    op. right. Accept (v);
  END VisitSetOp;

PROCEDURE (v: Visitor) VisitSetRange* (range: IR.SetRange);
  BEGIN
    range. from. Accept (v);
    range. to. Accept (v);
  END VisitSetRange;

PROCEDURE (v: Visitor) VisitChangeElement* (ch: IR.ChangeElement);
  BEGIN
    ch. set. Accept (v);
    ch. element. Accept (v);
  END VisitChangeElement;

PROCEDURE (v: Visitor) VisitShift* (shift: IR.Shift);
  BEGIN
    shift. value. Accept (v);
    shift. by. Accept (v);
  END VisitShift;

PROCEDURE (v: Visitor) VisitTypeCast* (op: IR.TypeCast);
  BEGIN
    op. expr. Accept (v);
  END VisitTypeCast;

PROCEDURE (v: Visitor) VisitTypeConv* (op: IR.TypeConv);
  BEGIN
    op. expr. Accept (v);
  END VisitTypeConv;

PROCEDURE (v: Visitor) VisitTypeGuard* (op: IR.TypeGuard);
  BEGIN
    op. test. Accept(v);
  END VisitTypeGuard;

PROCEDURE (v: Visitor) VisitTypeTag* (op: IR.TypeTag);
  BEGIN
    op. design. Accept (v);
  END VisitTypeTag;

PROCEDURE (v: Visitor) VisitTypeTest* (op: IR.TypeTest);
  BEGIN
    op. expr. Accept(v);
  END VisitTypeTest;

PROCEDURE (v: Visitor) VisitModuleRef* (modRef: IR.ModuleRef);
  END VisitModuleRef;

PROCEDURE (v: Visitor) VisitPredefProc* (pproc: IR.PredefProc);
  END VisitPredefProc;

PROCEDURE (v: Visitor) VisitProcedureRef* (procRef: IR.ProcedureRef);
  END VisitProcedureRef;

PROCEDURE (v: Visitor) VisitTypeRef* (typeRef: IR.TypeRef);
  END VisitTypeRef;

PROCEDURE (v: Visitor) VisitVar* (var: IR.Var);
  END VisitVar;



PROCEDURE VisitStatementSeq (v: Visitor; statmSeq: IR.StatementSeq);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statmSeq[i]. Accept (v)
    END;
  END VisitStatementSeq;

PROCEDURE (v: Visitor) VisitAssert* (assert: IR.Assert);
  BEGIN
    IF (assert. predicate # NIL) THEN
      assert. predicate. Accept (v);
    END;
  END VisitAssert;

PROCEDURE (v: Visitor) VisitAssignment* (assignment: IR.Assignment);
  BEGIN
    assignment. variable. Accept (v);
    assignment. value. Accept (v);
  END VisitAssignment;

PROCEDURE (v: Visitor) VisitAssignOp* (assignOp: IR.AssignOp);
  BEGIN
    assignOp. variable. Accept (v);
    assignOp. value. Accept (v);
  END VisitAssignOp;

PROCEDURE (v: Visitor) VisitCall* (call: IR.Call);
  VAR
    i: LONGINT;
  BEGIN
    call. design. Accept (v);
    FOR i := 0 TO LEN (call. arguments^)-1 DO
      call. arguments[i]. Accept (v);
    END;
  END VisitCall;

PROCEDURE (v: Visitor) VisitCopy* (cp: IR.Copy);
  BEGIN
    cp. source. Accept (v);
    cp. dest. Accept (v);
  END VisitCopy;

PROCEDURE (v: Visitor) VisitCopyParameter* (cp: IR.CopyParameter);
  BEGIN
    cp. param. Accept (v);
  END VisitCopyParameter;

PROCEDURE (v: Visitor) VisitCopyString* (cp: IR.CopyString);
  BEGIN
    cp. source. Accept (v);
    cp. dest. Accept (v);
    cp. maxLength. Accept (v);
  END VisitCopyString;

PROCEDURE (v: Visitor) VisitExit* (exit: IR.Exit);
  BEGIN
  END VisitExit;

PROCEDURE (v: Visitor) VisitForStatm* (forStatm: IR.ForStatm);
  BEGIN
    forStatm. var. Accept (v);
    forStatm. start. Accept (v);
    forStatm. end. Accept (v);
    forStatm. step. Accept (v);
    VisitStatementSeq (v, forStatm. body);
  END VisitForStatm;

PROCEDURE (v: Visitor) VisitIterateArrayStatm* (iterStatm: IR.IterateArrayStatm);
  BEGIN
    iterStatm. var. Accept (v);
    iterStatm. range. Accept (v);
    VisitStatementSeq (v, iterStatm. body);
  END VisitIterateArrayStatm;

PROCEDURE (v: Visitor) VisitIterateObjectStatm* (iterStatm: IR.IterateObjectStatm);
  BEGIN
    iterStatm. var. Accept (v);
    iterStatm. iteratorFactory. Accept (v);
    iterStatm. stepperCall. Accept (v);
    VisitStatementSeq (v, iterStatm. body);
  END VisitIterateObjectStatm;

PROCEDURE (v: Visitor) VisitIfStatm* (ifStatm: IR.IfStatm);
  BEGIN
    ifStatm. guard. Accept (v);
    VisitStatementSeq (v, ifStatm. pathTrue);
    IF (ifStatm. pathFalse # NIL) THEN
      VisitStatementSeq (v, ifStatm. pathFalse);
    END;
  END VisitIfStatm;

PROCEDURE (v: Visitor) VisitCase* (case: IR.Case);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (case. labels^)-1 DO
      case. labels[i]. Accept (v);
    END;
    VisitStatementSeq (v, case. statmSeq);
  END VisitCase;

PROCEDURE (v: Visitor) VisitCaseStatm* (caseStatm: IR.CaseStatm);
  VAR
    i: LONGINT;
  BEGIN
    caseStatm. select. Accept (v);
    FOR i := 0 TO LEN (caseStatm. caseList^)-1 DO
      caseStatm. caseList[i]. Accept (v);
    END;
    IF (caseStatm. default # NIL) THEN
      VisitStatementSeq (v, caseStatm. default);
    END;
  END VisitCaseStatm;

PROCEDURE (v: Visitor) VisitLoopStatm* (loopStatm: IR.LoopStatm);
  BEGIN
    VisitStatementSeq (v, loopStatm. body);
  END VisitLoopStatm;

PROCEDURE (v: Visitor) VisitMoveBlock* (move: IR.MoveBlock);
  BEGIN
    move. source. Accept (v);
    move. dest. Accept (v);
    move. size. Accept (v);
  END VisitMoveBlock;

PROCEDURE (v: Visitor) VisitRaise* (raise: IR.Raise);
  BEGIN
    raise. exception. Accept (v);
  END VisitRaise;

PROCEDURE (v: Visitor) VisitRepeatStatm* (repeatStatm: IR.RepeatStatm);
  BEGIN
    VisitStatementSeq (v, repeatStatm. body);
    repeatStatm. exitCondition. Accept (v);
  END VisitRepeatStatm;

PROCEDURE (v: Visitor) VisitReturn* (return: IR.Return);
  BEGIN
    IF (return. result # NIL) THEN
      return. result. Accept (v);
    END;
  END VisitReturn;

PROCEDURE (v: Visitor) VisitCatchClause* (catch: IR.CatchClause);
  BEGIN
    VisitStatementSeq(v, catch.statmSeq);
  END VisitCatchClause;

PROCEDURE (v: Visitor) VisitTryStatm* (tryStatm: IR.TryStatm);
  VAR
    i: LONGINT;
  BEGIN
    VisitStatementSeq(v, tryStatm.statmSeq);
    FOR i := 0 TO LEN(tryStatm.catchList^)-1 DO
      tryStatm.catchList[i].Accept(v);
    END;
  END VisitTryStatm;

PROCEDURE (v: Visitor) VisitWhileStatm* (whileStatm: IR.WhileStatm);
  BEGIN
    whileStatm. guard. Accept (v);
    VisitStatementSeq (v, whileStatm. body);
  END VisitWhileStatm;

PROCEDURE (v: Visitor) VisitWithStatm* (withStatm: IR.WithStatm);
  BEGIN
    withStatm. guard. Accept (v);
    VisitStatementSeq (v, withStatm. pathTrue);
    IF (withStatm. pathFalse # NIL) THEN
      VisitStatementSeq (v, withStatm. pathFalse);
    END;
  END VisitWithStatm;


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
    VisitStatementSeq (v, procedure. statmSeq);
  END VisitProcedure;

PROCEDURE (v: Visitor) VisitModule* (module: IR.Module);
  BEGIN
    VisitProcedureList (v, module. procList);
    VisitStatementSeq (v, module. moduleBody. statmSeq);
  END VisitModule;

END OOC:IR:VisitAll.
