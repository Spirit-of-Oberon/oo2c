(* 	$Id$	 *)
MODULE OOC:AST:ExtTree:CreateExpr;
(*  Creates operator tree from an abstract syntax tree of an expression.
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
  OOC:Scanner:Symbol, OOC:AST, OOC:AST:ExtTree, OOC:Expr;


TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (ExtTree.VisitorDesc)
    eb: Expr.Builder;
    
    expr: Expr.Expr;
  END;



PROCEDURE Accept (v: Visitor; node: AST.Node): Expr.Expr;
  BEGIN
    IF (node = NIL) THEN
      RETURN NIL
    ELSE
      v. expr := NIL;
      node(ExtTree.Node). Accept (v);
      ASSERT (v. expr # NIL);
      RETURN v. expr
    END
  END Accept;


PROCEDURE (v: Visitor) VisitNodeList* (nl: ExtTree.NodeList);
  BEGIN
    ASSERT (FALSE)  (* must use specialized code *)
  END VisitNodeList;

PROCEDURE (v: Visitor) VisitTerminal* (terminal: ExtTree.Terminal);
  BEGIN
    CASE terminal. sym. id OF
    | Symbol.ident:                (* name (variable, type, const, etc)  *)
      v. expr := v. eb. Name (terminal. sym)
      
    | Symbol.nil,                  (* keyword `NIL' *)
      Symbol.number10,             (* decimal integer constant *)
      Symbol.number16,             (* hexadecimal integer constant *)
      Symbol.number16X,            (* hexadecimal character constant *)
      Symbol.numberExpE,           (* fp constant, real precision *)
      Symbol.numberExpD,           (* fp constant, longreal precision *)
      Symbol.stringSingle,         (* string constant, single/double quotes *)
      Symbol.stringDouble:
      v. expr := v. eb. Const (terminal. sym)
    
    | Symbol.eql .. Symbol.is,     (* operators from `Expr' *)
      Symbol.plus .. Symbol.or,    (* operators from `SimpleExpr' *)
      Symbol.times .. Symbol.and,  (* operators from `Term' *)
      Symbol.not,                  (* operator from `Factor' *)
      Symbol.arrow, Symbol.period, (* operators from `Designator' *)
      Symbol.upto,                 (* operator: set element and case label *)
      Symbol.becomes:              (* assignment operator *)
      v. expr := v. eb. Name (terminal. sym)
    END
  END VisitTerminal;

PROCEDURE (v: Visitor) VisitOperator* (operator: ExtTree.Operator);
  VAR
    leftExpr, rightExpr, opExpr: Expr.Expr;
  BEGIN
    leftExpr := Accept (v, operator. left);
    rightExpr := Accept (v, operator. right);
    opExpr := Accept (v, operator. op);
    v. expr := v. eb. Operator (opExpr, leftExpr, rightExpr)
  END VisitOperator;

PROCEDURE (v: Visitor) VisitFactor* (factor: ExtTree.Factor);
  BEGIN
    (* this is simple: ignore the parenthesis and take the expression *)
    v. expr := Accept (v, factor. expr)
  END VisitFactor;

PROCEDURE (v: Visitor) VisitSet* (set: ExtTree.Set);
  VAR
    type, upper, lower, elem: Expr.Expr;
    node: ExtTree.Node;
    i: LONGINT;
  BEGIN
    type := Accept (v, set. type);
    
    IF (set. elementList. len = 0) THEN  (* empty set *)
      v. expr := v. eb. SetRange (type, NIL, NIL)
    ELSE
      i := 0;
      WHILE (i < set. elementList. len) DO (* entered at least once *)
        node := set. elementList. n[i](ExtTree.Node);
        WITH node: ExtTree.Operator DO   (* range of elements *)
          lower := Accept (v, node. left);
          upper := Accept (v, node. right);
          elem := v. eb. SetRange (type, lower, upper)
        ELSE                             (* single set element *)
          lower := Accept (v, node);
          elem := v. eb. SetRange (type, lower, NIL)
        END;
        
        IF (i = 0) THEN
          v. expr := elem
        ELSE
          v. expr := v. eb. Operator (v. eb. UnionOperator(), v. expr, elem)
        END;
        INC (i, 2)
      END
    END
  END VisitSet;

PROCEDURE (v: Visitor) VisitArrayIndex* (arrayIndex: ExtTree.ArrayIndex);
  VAR
    index: Expr.Expr;
    i: LONGINT;
  BEGIN
    v. expr := Accept (v, arrayIndex. design);
    i := 0;
    WHILE (i < arrayIndex. indices. len) DO
      index := Accept (v, arrayIndex. indices. n[i]);
      v. expr := v. eb. Operator (v. eb. IndexOperator(), v. expr, index);
      INC (i, 2)
    END    
  END VisitArrayIndex;

PROCEDURE (v: Visitor) VisitFunctionCall* (functionCall: ExtTree.FunctionCall);
  VAR
    fct: Expr.Expr;
    i: LONGINT;
    al: Expr.ExprList;
  BEGIN
    fct := Accept (v, functionCall. design);
    al := v. eb. NewExprList();
    i := 0;
    WHILE (i < functionCall. arguments. len) DO
      al. Append (Accept (v, functionCall. arguments. n[i]));
      INC (i, 2)
    END;
    v. expr := v. eb. FunctionCall (fct, al)
  END VisitFunctionCall;


PROCEDURE CreateExpr* (expr: AST.Node;
                       expressionBuilder: Expr.Builder): Expr.Expr;
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    v. eb := expressionBuilder;
    RETURN Accept (v, expr)
  END CreateExpr;

END OOC:AST:ExtTree:CreateExpr.
