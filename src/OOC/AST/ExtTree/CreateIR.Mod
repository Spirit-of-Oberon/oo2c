(* 	$Id$	 *)
MODULE OOC:AST:ExtTree:CreateIR;
(*  Creates an IR representation from the abstract syntax tree.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Log, Language:Integer,
  OOC:Scanner:Symbol, OOC:Scanner:Builder:BasicList,
  OOC:AST:ExtTree, Sym := OOC:SymbolTable, OOC:IR, OOC:IR:Operator;



PROCEDURE CreateIR* (module: ExtTree.Module;
                     symTab: Sym.Module;
                     b: Operator.Builder): IR.Module;
  VAR
    currentNamespace: Sym.Namespace;
    currentSourceContext: Sym.Item;
    
  PROCEDURE ^ Expr (expr: ExtTree.Node): IR.Expression;
    
  PROCEDURE Designator (design: ExtTree.Node): IR.Expression;
    VAR
      left: IR.Expression;
      sym: BasicList.Symbol;
      i: LONGINT;
    BEGIN
      WITH design: ExtTree.Terminal DO
        RETURN b. NewIdentRef (currentNamespace, currentSourceContext,
                               design. sym)
            
      | design: ExtTree.ArrayIndex DO
        left := Designator (design. design);
        sym := design. lBrak. sym;
        i := 0;
        WHILE (i < design. indices. len) DO
          left := b. NewIndex (sym, left,
                               Expr (design. indices. n[i](ExtTree.Node)));
          INC (i);
          IF (i < design. indices. len) THEN
            sym := design. indices. n[i](ExtTree.Terminal). sym;
          END;
          INC (i)
        END;
        RETURN left
            
      | design: ExtTree.Operator DO
        (* we only do qualified identifiers for now: "module.ident" *)
        ASSERT (design. op. sym. id = Symbol.period);
        left := Designator (design. left);
        WITH left: IR.ModuleRef DO
          RETURN b. NewQualident (left, currentSourceContext, 
                                  design. right(ExtTree.Terminal). sym);
          
        | left: IR.Const DO
          ASSERT (left = b. errorExpr);
          RETURN b. errorExpr;           (* left side has errors *)

        ELSE                             (* field or tb procedure selector *)
          RETURN b. NewSelect (design. op. sym, left, currentSourceContext,
                               design. right(ExtTree.Terminal). sym);
        END
            
      ELSE
        Log.Type("++ Unknown type in Designator", design);
        ASSERT (FALSE)
      END
    END Designator;
  
  PROCEDURE ^ FunctionCall (call: ExtTree.FunctionCall;
                            isProcCall: BOOLEAN): IR.Expression;
    
  PROCEDURE Expr (expr: ExtTree.Node): IR.Expression;
    VAR
      left, right, res: IR.Expression;
    BEGIN
      WITH expr: ExtTree.Terminal DO
        CASE expr. sym. id OF
        | Symbol.ident:
          res := Designator (expr)
        | Symbol.stringSingle, Symbol.stringDouble:
          res := b. NewStringConst (expr. sym)
        | Symbol.number10:
          res := b. NewIntConst10 (expr. sym)
        | Symbol.number16X:
          res := b. NewCharConst16 (expr. sym)
        END

      | expr: ExtTree.Factor DO
        res := Expr (expr. expr)
            
      | expr: ExtTree.ArrayIndex DO      (* part of designator *)
        res := Designator (expr)
        
      | expr: ExtTree.Operator DO
        IF (expr. op. sym. id = Symbol.period) THEN
          (* handled as part of designator *)
          res := Designator (expr);
        ELSE
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
          res := b. NewOperator (expr. op. sym, left, right);
        END;

      | expr: ExtTree.FunctionCall DO
        res := FunctionCall (expr, FALSE)
            
      ELSE
        Log.Type("++ Unknown expression class in Expr", expr);
        ASSERT (FALSE)
      END;
      RETURN b. Fold (res)
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
  
  PROCEDURE StatementSeq (statmSeq: ExtTree.NodeList): IR.StatementSeq;
    VAR
      i, count: LONGINT;
      n: ExtTree.Node;
      statmSeqIR: IR.StatementSeq;
      statm: IR.Statement;

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
  
    PROCEDURE Return (return: ExtTree.ReturnStatm): IR.Statement;
      BEGIN
        IF (return. expr = NIL) THEN
          RETURN b. NewReturn (return. return. sym, NIL)
        ELSE
          RETURN b. NewReturn (return. return. sym,
                               Expr (return. expr(ExtTree.Node)))
        END;
      END Return;

    PROCEDURE Assignment (design, op, value: ExtTree.Node): IR.Statement;
      VAR
        variable, valueExpr: IR.Expression;
      BEGIN
        variable := Designator (design);
        valueExpr := Expr (value);
        RETURN b. NewAssignment (op(ExtTree.Terminal). sym, variable, valueExpr)
      END Assignment;
    
    PROCEDURE IfStatm (ifStatm: ExtTree.IfStatm): IR.Statement;
      VAR
        else: IR.Statement;
        elseSeq: IR.StatementSeq;
        i: LONGINT;
      BEGIN
        IF (ifStatm. else # NIL) THEN
          elseSeq := StatementSeq (ifStatm. elseStatmSeq)
        ELSE
          elseSeq := NIL
        END;
        i := ifStatm. guardList. len-4;
        REPEAT
          else := b. NewIfStatm
              (ifStatm. guardList. n[i](ExtTree.Terminal). sym,
               Expr (ifStatm. guardList. n[i+1](ExtTree.Node)),
               StatementSeq (ifStatm. guardList. n[i+3](ExtTree.NodeList)),
               elseSeq);
          NEW (elseSeq, 1);
          elseSeq[0] := else;
          DEC (i, 4)
        UNTIL (i < 0);
        RETURN else
      END IfStatm;
  
    PROCEDURE RepeatStatm (repeatStatm: ExtTree.RepeatStatm): IR.Statement;
      BEGIN
        RETURN b. NewRepeatStatm (repeatStatm. repeat. sym,
                                  StatementSeq (repeatStatm. statmSeq),
                                  Expr (repeatStatm. expr));
      END RepeatStatm;
  
    PROCEDURE WhileStatm (whileStatm: ExtTree.WhileStatm): IR.Statement;
      BEGIN
        RETURN b. NewWhileStatm (whileStatm. while. sym,
                                 Expr (whileStatm. guard),
                                 StatementSeq (whileStatm. statmSeq));
      END WhileStatm;
  
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
            statm := ProcedureCall (n);
            
          | n: ExtTree.ReturnStatm DO
            statm := Return (n);

          | n: ExtTree.Assignment DO
            statm := Assignment (n. assignment. left,
                                 n. assignment. op,
                                 n. assignment. right)

          | n: ExtTree.IfStatm DO
            statm := IfStatm (n)

          | n: ExtTree.RepeatStatm DO
            statm := RepeatStatm (n)
              
          | n: ExtTree.WhileStatm DO
            statm := WhileStatm (n)
              
          ELSE
            Log.Type("++ Unknown type in StatementSeq", n);
            ASSERT (FALSE)
          END;
          statmSeqIR[count] := statm;
          INC (count)
        END
      END;

      RETURN statmSeqIR
    END StatementSeq;
  
  PROCEDURE ConstDecl(constDecl: Sym.ConstDecl; constExpr : ExtTree.Node);
  VAR
    expr : IR.Expression;
  BEGIN
    expr := Expr(constExpr);
    IF expr = b. errorExpr THEN RETURN END;
    WITH expr : IR.Const DO
      constDecl.SetValueType(expr.value, expr.type(Sym.PredefType));
    ELSE
      b.ErrSym(IR.exprNotConstant, expr.sym);
    END;
  END ConstDecl;
   
<* PUSH; Warnings := FALSE *>
  PROCEDURE ProcDecl (procDecl: Sym.ProcDecl;
                      procCode: ExtTree.ProcDecl): IR.Procedure;
    VAR
      statmSeq: IR.StatementSeq;
      oldNamespace: Sym.Namespace;
      oldSourceContext: Sym.Item;
    BEGIN
      oldNamespace := currentNamespace;
      oldSourceContext := currentSourceContext;
      currentNamespace := procDecl. ns;
      currentSourceContext := procDecl;
      
      IF (procCode. body = NIL) OR (procCode. body. statmSeq = NIL) THEN
        NEW (statmSeq, 0)
      ELSE
        statmSeq := StatementSeq (procCode. body. statmSeq)
      END;
      
      currentNamespace := oldNamespace;
      currentSourceContext := oldSourceContext;
      RETURN b. NewProcedure (procCode. proc. sym, procDecl, statmSeq)
    END ProcDecl;
<* POP *>
  
  PROCEDURE Module (moduleDecl: Sym.Module;
                    moduleAST: ExtTree.Module): IR.Module;
    VAR
      declSeq: ExtTree.NodeList;
      count: LONGINT;
      procList: IR.ProcedureList;
      statmSeq: IR.StatementSeq;

    PROCEDURE IsProc (procDecl: Sym.ProcDecl): BOOLEAN;
      BEGIN
        RETURN ~procDecl. isForwardDecl
      END IsProc;

    PROCEDURE CountProcs (item: Sym.Item): LONGINT;
      VAR
        nested: Sym.Item;
        count: LONGINT;
      BEGIN
        IF (item IS Sym.ProcDecl) & IsProc (item(Sym.ProcDecl)) THEN
          count := 1
        ELSE
          count := 0;
        END;
        
        nested := item. nestedItems;
        WHILE (nested # NIL) DO
          INC (count, CountProcs (nested));
          nested := nested. nextNested
        END;
        RETURN count
      END CountProcs;

    PROCEDURE TraverseProcedures (item: Sym.Item);
      VAR
        nested: Sym.Item;
      BEGIN
        WITH item: Sym.ProcDecl DO
          IF IsProc (item) THEN
            procList[count] := ProcDecl (item, item.procAST(ExtTree.ProcDecl));
            INC (count)
          END;
        ELSE                             (* ignore *)
        END;
        
        nested := item. nestedItems;
        WHILE (nested # NIL) DO
          TraverseProcedures (nested);
          nested := nested. nextNested
        END;
      END TraverseProcedures;
    
    BEGIN
      declSeq := moduleAST. body. declSeq;

      NEW (procList, CountProcs (moduleDecl));
      count := 0;
      TraverseProcedures (moduleDecl);
      
      IF (moduleAST. body = NIL) OR (moduleAST. body. statmSeq = NIL) THEN
        NEW (statmSeq, 0)
      ELSE
        statmSeq := StatementSeq (moduleAST. body. statmSeq)
      END;
      
      RETURN b. NewModule (moduleAST. module. sym, moduleAST. moduleName,
                           procList, statmSeq)
    END Module;

  PROCEDURE TranslateEmbeddedExpr (item: Sym.Item);
  (**Traverses the symbol table and resolves all expressions.  This pass
     calculates the value of declared constants, and the length of array
     types.  Declarations are traversed in the order in which they appear
     in the source code.  This works fine, as long as no forward references
     can appear in the resolved expressions.  *)
    VAR
      nested: Sym.Item;
      expr: IR.Expression;
    BEGIN
      WITH item: Sym.Array DO
        IF ~item. isOpenArray THEN
          expr := Expr (item. lengthExpr(ExtTree.Node));
          item. SetLength (expr(IR.Const). value(Integer.Value). ToLInt());
        END;

      | item: Sym.ConstDecl DO
        ConstDecl (item, item. constExpr(ExtTree.Node));
        
      ELSE  (* ignore *)
      END;

      WITH item: Sym.Type DO
        IF ~(item IS Sym.TypeName) THEN
          b. typeRules. AllocateType (item)
        END;
      ELSE  (* ignore *)  
      END;
      
      nested := item. nestedItems;
      WHILE (nested # NIL) DO
        TranslateEmbeddedExpr (nested);
        nested := nested. nextNested
      END;
    END TranslateEmbeddedExpr;
  
  BEGIN
    currentSourceContext := symTab;
    currentNamespace := symTab. ns;
    TranslateEmbeddedExpr (symTab);
    RETURN Module (symTab, module)
  END CreateIR;

END OOC:AST:ExtTree:CreateIR.

