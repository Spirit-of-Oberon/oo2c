(* 	$Id$	 *)
MODULE OOC:AST:ExtTree:CreateStatm;
(*  Creates statement tree from the statement's of an abstract syntax tree.
    Copyright (C) 2000  Michael van Acken

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
  OOC:AST, OOC:Expr, OOC:Statm,
  OOC:AST:ExtTree, OOC:AST:ExtTree:CreateExpr;


TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (ExtTree.VisitorDesc)
    eb: Expr.Builder;
    sb: Statm.Builder;
    
    statm: Statm.Statm;
    statmList: Statm.StatmList;
  END;



PROCEDURE Accept (v: Visitor; node: AST.Node): Statm.Statm;
  BEGIN
    IF (node = NIL) THEN
      RETURN NIL
    ELSE
      v. statm := NIL;
      node(ExtTree.Node). Accept (v);
      ASSERT (v. statm # NIL);
      RETURN v. statm
    END
  END Accept;

PROCEDURE AcceptList (v: Visitor; nodeList: AST.NodeList): Statm.StatmList;
  BEGIN
    IF (nodeList = NIL) THEN
      RETURN NIL
    ELSE
      v. statmList := NIL;
      nodeList(ExtTree.NodeList). Accept (v);
      ASSERT (v. statmList # NIL);
      RETURN v. statmList
    END
  END AcceptList;


PROCEDURE (v: Visitor) VisitNodeList* (nl: ExtTree.NodeList);
  VAR
    i: LONGINT;
    sl: Statm.StatmList;
  BEGIN  (* handles statement lists *)
    sl := v. sb. NewStatmList();
    i := 0;
    WHILE (i < nl. len) DO
      IF (nl. n[i] # NIL) THEN
        sl. Append (Accept (v, nl. n[i]))
      END;
      INC (i, 2)
    END;
    v. statmList := sl
  END VisitNodeList;



PROCEDURE (v: Visitor) VisitAssignment* (assignment: ExtTree.Assignment);
  VAR
    expr: Expr.Expr;
  BEGIN
    expr := CreateExpr.CreateExpr (assignment. assignment, v. eb);
    v. statm := v. sb. Assignment (expr)
  END VisitAssignment;

PROCEDURE (v: Visitor) VisitProcedureCall* (procedureCall: ExtTree.ProcedureCall);
  VAR
    expr: Expr.Expr;
  BEGIN
    expr := CreateExpr.CreateExpr (procedureCall. call, v. eb);
    v. statm := v. sb. ProcedureCall (expr)
  END VisitProcedureCall;

PROCEDURE (v: Visitor) VisitIfStatm* (ifStatm: ExtTree.IfStatm);
  VAR
    statm: Statm.Statm;
    trueStatm, falseStatm: Statm.StatmList;
    guard: Expr.Expr;
    i: LONGINT;
  BEGIN
    statm := NIL;
    falseStatm := AcceptList (v, ifStatm. elseStatmSeq);
    i := (ifStatm. guardList. len DIV 4)*4;
    WHILE (i >= 0) DO
      guard := CreateExpr.CreateExpr (ifStatm. guardList. n[i+1], v. eb);
      trueStatm := AcceptList (v, ifStatm. guardList. n[i+3](AST.NodeList));
      statm := v. sb. IfStatm (guard, trueStatm, falseStatm);
      
      IF (i > 0) THEN
        (* there are preceding guards left: build new statement list for
           for "false" path *)
        falseStatm := v. sb. NewStatmList();
        falseStatm. Append (statm)
      END;
      DEC (i, 4)
    END;
    v. statm := statm
  END VisitIfStatm;

PROCEDURE (v: Visitor) VisitCaseStatm* (caseStatm: ExtTree.CaseStatm);
  VAR
    expr: Expr.Expr;
    labels, labelList: Expr.ExprList;
    branch, branches, else: Statm.StatmList;
    astLabels: AST.NodeList;
    i, j: LONGINT;
  BEGIN
    expr := CreateExpr.CreateExpr (caseStatm.expr, v. eb);
    labels := v. eb. NewExprList();
    branches := v. sb. NewStatmList();
    i := 0;
    WHILE (i < caseStatm. caseList. len) DO
      IF (caseStatm. caseList. n[i] # NIL) THEN
        astLabels := caseStatm. caseList. n[i](AST.NodeList);
        labelList := v. eb. NewExprList();
        j := 0;
        WHILE (j < astLabels. len) DO
          labelList. Append (CreateExpr.CreateExpr (astLabels. n[j], v. eb));
          INC (j, 2)
        END;
        labels. Append (labelList);
        branch := AcceptList (v, caseStatm. caseList. n[i+2](AST.NodeList));
        branches. Append (branch)
      END;
      INC (i, 4)
    END;
    else := AcceptList (v, caseStatm. elseStatmSeq);
    v. statm := v. sb. CaseStatm (expr, labels, branches, else)
  END VisitCaseStatm;

PROCEDURE (v: Visitor) VisitWhileStatm* (whileStatm: ExtTree.WhileStatm);
  VAR
    guard: Expr.Expr;
    statmSeq: Statm.StatmList;
  BEGIN
    guard := CreateExpr.CreateExpr (whileStatm. guard, v. eb);
    statmSeq := AcceptList (v, whileStatm. statmSeq);
    v. statm := v. sb. WhileStatm (guard, statmSeq)
  END VisitWhileStatm;

PROCEDURE (v: Visitor) VisitRepeatStatm* (repeatStatm: ExtTree.RepeatStatm);
  VAR
    statmSeq: Statm.StatmList;
    until: Expr.Expr;
  BEGIN
    statmSeq := AcceptList (v, repeatStatm. statmSeq);
    until := CreateExpr.CreateExpr (repeatStatm. until, v. eb);
    v. statm := v. sb. RepeatStatm (statmSeq, until)
  END VisitRepeatStatm;

PROCEDURE (v: Visitor) VisitForStatm* (forStatm: ExtTree.ForStatm);
  VAR
    var, start, end, step: Expr.Expr;
    statmSeq: Statm.StatmList;
  BEGIN
    var := CreateExpr.CreateExpr (forStatm. ident, v. eb);
    start := CreateExpr.CreateExpr (forStatm. startValue, v. eb);
    end := CreateExpr.CreateExpr (forStatm. endValue, v. eb);
    IF (forStatm. step # NIL) THEN
      step := CreateExpr.CreateExpr (forStatm. step, v. eb)
    ELSE
      step := NIL
    END;
    statmSeq := AcceptList (v, forStatm. statmSeq);
    v. statm := v. sb. ForStatm (var, start, end, step, statmSeq)
  END VisitForStatm;

PROCEDURE (v: Visitor) VisitLoopStatm* (loopStatm: ExtTree.LoopStatm);
  VAR
    statmSeq: Statm.StatmList;
  BEGIN
    statmSeq := AcceptList (v, loopStatm. statmSeq);
    v. statm := v. sb. LoopStatm (statmSeq)
  END VisitLoopStatm;

PROCEDURE (v: Visitor) VisitWithStatm* (withStatm: ExtTree.WithStatm);
  VAR
    statm: Statm.Statm;
    trueStatm, falseStatm: Statm.StatmList;
    guard: Expr.Expr;
    i: LONGINT;
  BEGIN
    statm := NIL;
    falseStatm := AcceptList (v, withStatm. elseStatmSeq);
    i := (withStatm. guardList. len DIV 4)*4;
    WHILE (i >= 0) DO
      guard := CreateExpr.CreateExpr (withStatm. guardList. n[i+1], v. eb);
      trueStatm := AcceptList (v, withStatm. guardList. n[i+3](AST.NodeList));
      statm := v. sb. WithStatm (guard, trueStatm, falseStatm);
      
      IF (i > 0) THEN
        (* there are preceding guards left: build new statement list for
           for "false" path *)
        falseStatm := v. sb. NewStatmList();
        falseStatm. Append (statm)
      END;
      DEC (i, 4)
    END;
    v. statm := statm
  END VisitWithStatm;

PROCEDURE (v: Visitor) VisitExitStatm* (exitStatm: ExtTree.ExitStatm);
  BEGIN
    v. statm := v. sb. ExitStatm()
  END VisitExitStatm;

PROCEDURE (v: Visitor) VisitReturnStatm* (returnStatm: ExtTree.ReturnStatm);
  VAR
    expr: Expr.Expr;
  BEGIN
    IF (returnStatm. expr # NIL) THEN
      expr := CreateExpr.CreateExpr (returnStatm. expr, v. eb)
    ELSE
      expr := NIL
    END;
    v. statm := v. sb. ReturnStatm (expr)
  END VisitReturnStatm;



PROCEDURE CreateStatmList* (statmList: AST.NodeList;
                            statementBuilder: Statm.Builder;
                            expressionBuilder: Expr.Builder): Statm.StatmList;
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    v. sb := statementBuilder;
    v. eb := expressionBuilder;
    RETURN AcceptList (v, statmList)
  END CreateStatmList;

END OOC:AST:ExtTree:CreateStatm.
