(* 	$Id$	 *)
MODULE OOC:OpTree[OOC_EXTENSIONS];
(*  Abstract builder class for Oberon-2 operator tree.
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
  OOC:Scanner:Builder:BasicList;
  
(**An operator tree is the logical representation of the active parts of a
   module definition.  That is, it describes expressions and statements, but
   not declarations.

   The leafs of an operator tree are

   @itemize @bullet
   @item
   constant values, like @samp{123}, @samp{"abc"}, or @code{NIL}, or
   @item
   object references, like variable or procedure names, operator symbols,
   module names, and so on.
   @end itemize

   The inner nodes of a tree represent

   @itemize @bullet
   @item
   infix operators like @samp{a+b} or @samp{a <= b},
   @item
   prefix operators like @samp{-a} or @samp{~a},
   @item
   designator selectors like @samp{M.a} or @samp{a[b]},
   @item
   function calls,
   @item
   statements or statement sequences.
   @end itemize

   Every node of the tree has certain attributes.  Some of these attribute are
   computed during the generation of the tree.  These attriutes are typically
   determined bottom-up, starting at the leaves of the tree and are propagated
   towards the root.  Other attributes can only be computed at run-time, e.g.,
   a variable's address or the dynamic type of an object.  During compilation,
   the value of such attributes is not known, but the compiler knows how the
   value can be determined during run-time.

   @table @dfn
   @item Type
   Every node, being it leave or inner node, has a type.  For a constant value,
   a variable reference, or the result of an operation it is the corresponding
   Oberon-2 type.  For other objects, like modules, types, and statements,
   special type identifier are introduced.

   @item Value
   The value that would result from evaluation of the subtree rooted in a given
   node.  Note that statement, module, and type nodes have no value.

   @item Address
   For values stored in memory, this attribute refers to the address of the
   value.  Nodes without a value, and nodes that are never stored physically
   (for example, constant values like @samp{123} or @samp{FALSE}), no address
   exists.

   @item Type Tag
   For some nodes, run-time type information is available.  Typically, nodes
   are statically typed.  For object references, the static type may differ
   from the dynamic type.  For open array variables, the exact length of the
   array is only known during run-time.  This attribute provides access to
   run-time type information.
   @end table  *)

TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc* = RECORD [ABSTRACT]
  END;

TYPE
  NodeArray = POINTER TO ARRAY OF Node;
  NodeList* = POINTER TO NodeListDesc;
  NodeListDesc* = RECORD
    (**Defines a simple list of nodes.  This is used to model the
       arguments of a function call, to list the ranges of the label
       list of a @code{CASE} statement, and lists of statements  *)
    (NodeDesc)
    len-: LONGINT;
    (**The number of nodes in the list.  A value of zero means that the
       list is empty.  *)
    n-: NodeArray;
    (**This array holds the nodes of the list.  The elements 
       @samp{[0..@ofield{len}-1]} hold valid data.  If @ofield{len} is zero,
       then @ofield{n} is an array of length zero.  *)
  END;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD [ABSTRACT]
  END;


PROCEDURE InitNodeList* (nl: NodeList);
(**Initializes an expression list of length zero.  *)
  BEGIN
    nl. len := 0;
    NEW (nl. n, 8)
  END InitNodeList;

PROCEDURE (b: Builder) NewNodeList* (): NodeList;
(**Creates a new expression list of length zero.  *)
  VAR
    nl: NodeList;
  BEGIN
    NEW (nl);
    InitNodeList (nl);
    RETURN nl
  END NewNodeList;

PROCEDURE (nl: NodeList) Append* (expr: Node);
(**Appends the expression @oparam{expr} to the list @oparam{nl}.  *)
  VAR
    i: LONGINT;
    new: NodeArray;
  BEGIN
    IF (nl. len = LEN (nl. n^)) THEN
      NEW (new, LEN (nl. n^)*2);
      FOR i := 0 TO LEN (nl. n^)-1 DO
        new[i] := nl. n[i]
      END;
      nl. n := new
    END;
    nl. n[nl. len] := expr;
    INC (nl. len)
  END Append;


PROCEDURE (b: Builder) [ABSTRACT] Const* (sym: BasicList.Symbol): Node;
  END Const;

PROCEDURE (b: Builder) [ABSTRACT] Name* (sym: BasicList.Symbol): Node;
(* @oparam{sym} is either an alphnumerical name, or it is a operator symbol *)
  END Name;

PROCEDURE (b: Builder) [ABSTRACT] Operator* (op, left, right: Node): Node;
  END Operator;

PROCEDURE (b: Builder) [ABSTRACT] UnionOperator* (): Node;
  END UnionOperator;

PROCEDURE (b: Builder) [ABSTRACT] IndexOperator* (): Node;
  END IndexOperator;
  
PROCEDURE (b: Builder) [ABSTRACT] SetRange* (type, lower, upper: Node): Node;
(* Element @samp{@oparam{lower}..@oparam{upper}} or @samp{lower} of a set
   constructor @samp{@{@dots{}@}}.  If @oparam{upper} is @code{NIL}, only
   a single set element is denoted by @oparam{lower}.  If both @oparam{lower}
   and @oparam{upper} are @code{NIL}, then this expression denotes the
   empty set @samp{@{@}}.
   
   @oparam{type} is not @code{NIL}, if the set constructor is prefixed by
   the name of a set type.  *)
  END SetRange;

PROCEDURE (b: Builder) [ABSTRACT] FunctionCall* (fct: Node; arguments: NodeList): Node;
  END FunctionCall;



PROCEDURE (b: Builder) [ABSTRACT] Assignment* (assignment: Node): Node;
  END Assignment;

PROCEDURE (b: Builder) [ABSTRACT] ProcedureCall* (call: Node): Node;
(* See @oproc{AST.Builder.ProcedureCall} for information, how the expression
   @oparam{call} must be interpreted *)
  END ProcedureCall;

PROCEDURE (b: Builder) [ABSTRACT] IfStatm* (guard: Node; if, else: NodeList): Node;
  END IfStatm;

PROCEDURE (b: Builder) [ABSTRACT] CaseStatm* (expr: Node; labels: NodeList; branches: NodeList; else: NodeList): Node;
  END CaseStatm;

PROCEDURE (b: Builder) [ABSTRACT] WhileStatm* (guard: Node; body: NodeList): Node;
  END WhileStatm;

PROCEDURE (b: Builder) [ABSTRACT] RepeatStatm* (body: NodeList; until: Node): Node;
  END RepeatStatm;

PROCEDURE (b: Builder) [ABSTRACT] ForStatm* (var, start, end, step: Node; body: NodeList): Node;
  END ForStatm;

PROCEDURE (b: Builder) [ABSTRACT] LoopStatm* (body: NodeList): Node;
  END LoopStatm;

PROCEDURE (b: Builder) [ABSTRACT] WithStatm* (guard: Node; trueStatm, falseStatm: NodeList): Node;
  END WithStatm;

PROCEDURE (b: Builder) [ABSTRACT] ExitStatm* (): Node;
  END ExitStatm;

PROCEDURE (b: Builder) [ABSTRACT] ReturnStatm* (expr: Node): Node;
  END ReturnStatm;

END OOC:OpTree.
