(* 	$Id$	 *)
MODULE OOC:AST:ExtTree:CreateIR;
(*  Creates an IR representation from the abstract syntax tree.
    Copyright (C) 2001  Michael van Acken

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
OOC:AST:ExtTree:XML, StdChannels,
  OOC:Scanner:Symbol, OOC:AST:ExtTree, OOC:SymbolTable:Item, OOC:IR;



PROCEDURE CreateIR* (module: ExtTree.Module;
                     symTab: Item.Module;
                     b: IR.Builder): IR.Module;
  VAR
    currentNamespace: Item.Namespace;
    currentSourceContext: Item.Item;
    
  PROCEDURE Designator (design: ExtTree.Node): IR.Expression;
    VAR
      left: IR.Expression;
    BEGIN
      WITH design: ExtTree.Terminal DO
        RETURN b. NewIdentRef (currentNamespace, currentSourceContext,
                               design. sym. id, design. sym)
      | design: ExtTree.Operator DO
        (* we only do qualified identifiers for now: "module.ident" *)
        ASSERT (design. op. sym. id = Symbol.period);
        left := Designator (design. left);
        WITH left: IR.ModuleRef DO
          RETURN b. NewQualident (left, currentSourceContext, 
                        design. right(ExtTree.Terminal). sym. id,
                        design. right(ExtTree.Terminal). sym)
        END
      END
    END Designator;
  
  PROCEDURE Expr (expr: ExtTree.Node): IR.Expression;
    VAR
      left, right: IR.Expression;
    BEGIN
      WITH expr: ExtTree.Terminal DO
        CASE expr. sym. id OF
        | Symbol.ident:
          RETURN Designator (expr)
        | Symbol.stringSingle, Symbol.stringDouble:
          RETURN b. NewStringConst (expr. sym)
        | Symbol.number10:
          RETURN b. NewIntConst10 (expr. sym)
        END
        
      | expr: ExtTree.Operator DO
        IF (expr. left # NIL) THEN
          left := Expr (expr. left)
        ELSE
          left := NIL
        END;
        IF (expr. right # NIL) THEN
          right := Expr (expr. right)
        ELSE
          right := NIL
        END;
        RETURN b. NewOperator (expr. op. sym. id, left, right)
      END
    END Expr;
  
  
  PROCEDURE FunctionCall (call: ExtTree.FunctionCall;
                          isProcCall: BOOLEAN): IR.Expression;
    VAR
      design: IR.Expression;
      arguments: IR.ExpressionList;
      i: LONGINT;
    BEGIN
      design := Designator (call. design);
      NEW (arguments, (call. arguments. len+1) DIV 2);
      FOR i := 0 TO LEN (arguments^)-1 DO
        arguments[i] := Expr (call. arguments. n[i*2](ExtTree.Node))
      END;
      RETURN b. NewCall (design, arguments)
    END FunctionCall;

  PROCEDURE ProcedureCall (call: ExtTree.ProcedureCall): IR.Statement;
    VAR
      expr: IR.Expression;
      arguments: IR.ExpressionList;
    BEGIN
      IF (call. call IS ExtTree.FunctionCall) THEN
        expr := FunctionCall (call. call(ExtTree.FunctionCall), TRUE);
      ELSE
        (* create procedure call from lonely designator *)
        NEW (arguments, 0);
        expr := b. NewCall (Designator (call. call), arguments)
      END;
      RETURN expr(IR.Statement)
    END ProcedureCall;
  
  PROCEDURE StatementSeq (statmSeq: ExtTree.NodeList): IR.StatementSeq;
    VAR
      i, count: LONGINT;
      n: ExtTree.Node;
      statmSeqIR: IR.StatementSeq;
    BEGIN
      (* count number of statements, allocate array to hold IR of sequence *)
      count := 0;
      FOR i := 0 TO statmSeq. len-1 BY 2 DO
        IF (statmSeq. n[i] # NIL) THEN
          INC (count)
        END
      END;
      NEW (statmSeqIR, count);
      count := 0;
      FOR i := 0 TO statmSeq. len-1 BY 2 DO
        IF (statmSeq. n[i] # NIL) THEN
          n := statmSeq. n[i](ExtTree.Node);
          WITH n: ExtTree.ProcedureCall DO
            statmSeqIR[count] := ProcedureCall (n);
          END;
          INC (count)
        END
      END;

      RETURN statmSeqIR
    END StatementSeq;
  
  
<* PUSH; Warnings := FALSE *>
  PROCEDURE ProcDecl (procDecl: ExtTree.ProcDecl): IR.Procedure;
    VAR
      statmSeq: IR.StatementSeq;
      oldNamespace: Item.Namespace;
      oldSourceContext: Item.Item;
    BEGIN
      oldNamespace := currentNamespace;
      oldSourceContext := currentSourceContext;
      currentNamespace := procDecl. symTabEntry. ns;
      currentSourceContext := procDecl. symTabEntry;
      
      IF (procDecl. body = NIL) OR (procDecl. body. statmSeq = NIL) THEN
        NEW (statmSeq, 0)
      ELSE
        statmSeq := StatementSeq (procDecl. body. statmSeq)
      END;
      
      currentNamespace := oldNamespace;
      currentSourceContext := oldSourceContext;
      RETURN b. NewProcedure (procDecl. symTabEntry, statmSeq)
    END ProcDecl;
<* POP *>
  
  PROCEDURE Module (module: ExtTree.Module): IR.Module;
    VAR
      declSeq: ExtTree.NodeList;
      i, count: LONGINT;
      n: ExtTree.Node;
      procList: IR.ProcedureList;
      statmSeq: IR.StatementSeq;

    PROCEDURE IsProc (n: ExtTree.Node): BOOLEAN;
      BEGIN
        RETURN (n IS ExtTree.ProcDecl)
      END IsProc;

    BEGIN
      declSeq := module. body. declSeq;

      (* count number of procedures, allocate array to hold IR of procs *)
      count := 0;
      FOR i := 0 TO declSeq. len-1 DO
        n := declSeq. n[i](ExtTree.Node);
        IF IsProc (n) THEN
          INC (count)
        END
      END;
      NEW (procList, count);
      count := 0;
      FOR i := 0 TO declSeq. len-1 DO
        n := declSeq. n[i](ExtTree.Node);
        IF IsProc (n) THEN
          procList[count] := ProcDecl (n(ExtTree.ProcDecl));
          INC (count)
        END
      END;
      
      IF (module. body = NIL) OR (module. body. statmSeq = NIL) THEN
        NEW (statmSeq, 0)
      ELSE
        statmSeq := StatementSeq (module. body. statmSeq)
      END;
      
      RETURN b. NewModule (module. moduleName, procList, statmSeq)
    END Module;
  
  BEGIN
    XML.Write (StdChannels.stdout.NewWriter(), module);
    
    currentSourceContext := symTab;
    currentNamespace := symTab. ns;
    RETURN Module (module)
  END CreateIR;

END OOC:AST:ExtTree:CreateIR.

