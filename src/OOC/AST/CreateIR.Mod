(* 	$Id: CreateIR.Mod,v 1.4 2004/04/13 21:08:20 mva Exp $	 *)
MODULE OOC:AST:CreateIR;
(*  Creates an IR representation from the abstract syntax tree.
    Copyright (C) 2001-2004  Michael van Acken

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
  Log, Object:BigInt,
  OOC:Scanner:Symbol, OOC:Scanner:SymList,
  OOC:AST, Sym := OOC:SymbolTable, TR := OOC:SymbolTable:TypeRules,
  OOC:SymbolTable:Predef, OOC:IR;



PROCEDURE CreateIR* (module: AST.Module;
                     symTab: Sym.Module;
                     b: IR.Builder): IR.Module;
  VAR
    currentNamespace: Sym.Namespace;
    currentSourceContext: Sym.Item;
    
  PROCEDURE ^ Expr (expr: AST.Node): IR.Expression;
    
  PROCEDURE ^ FunctionCall (call: AST.FunctionCall;
                            isProcCall: BOOLEAN): IR.Expression;
    
  PROCEDURE ^ QualType(qualType: AST.QualType): IR.Expression;
    
  PROCEDURE Designator (design: AST.Node): IR.Expression;
    VAR
      left: IR.Expression;
      sym: SymList.Symbol;
      i: LONGINT;

    PROCEDURE Select(design: AST.Operator): IR.Expression;
      VAR
        left: IR.Expression;
      BEGIN
        left := Designator (design. left);
        WITH left: IR.ModuleRef DO
          RETURN b. NewQualident (currentNamespace, left, currentSourceContext,
                                  design. right(AST.Terminal). sym);

        ELSE                             (* field or tb procedure selector *)
          IF (left = b.errorExpr) THEN
            RETURN b. errorExpr;           (* left side has errors *)
          ELSE
            RETURN b. NewSelect (design. op. sym, left, currentSourceContext,
                                 design. right(AST.Terminal). sym);
          END;
        END
      END Select;
    
    BEGIN
      WITH design: AST.Terminal DO
        RETURN b. NewIdentRef (currentNamespace, currentNamespace,
                               currentSourceContext, design. sym)
            
      | design: AST.ArrayIndex DO
        left := Designator (design. design);
        sym := design. lBrak. sym;
        i := 0;
        WHILE (i < design. indices. len) DO
          left := b. NewIndex (sym, left,
                               Expr (design. indices. n[i]));
          INC (i);
          IF (i < design. indices. len) THEN
            sym := design. indices. n[i](AST.Terminal). sym;
          END;
          INC (i)
        END;
        RETURN left
            
      | design: AST.Operator DO
        IF (design. op. sym. id = Symbol.period) THEN
          RETURN Select (design);
        ELSE
          ASSERT (design. op. sym. id = Symbol.arrow);
          RETURN b. NewDeref (design. op. sym, Designator (design. left));
        END;

      | design: AST.FunctionCall DO
        RETURN FunctionCall (design, FALSE);

      | design: AST.QualType DO
        RETURN QualType(design);
        
      ELSE
        Log.Type("++ Unknown type in Designator", design);
        ASSERT (FALSE)
      END
    END Designator;
 
  PROCEDURE Range(type: IR.Expression; expr: AST.Node;
                  isSet: BOOLEAN) : IR.Expression; 
  (* Check for an upto operator ".." or a normal expression. *)
  VAR e : IR.Expression;
  BEGIN
    WITH expr : AST.Operator DO
      IF (expr. op. sym. id = Symbol.upto) THEN
        RETURN b.NewSetRange(expr.op.sym, type,
                             Expr(expr.left), Expr(expr.right), isSet);
      END;
    ELSE
    END;
    e := Expr(expr);
    RETURN b.NewSetRange(e.sym, type, e, e, isSet);
  END Range;

  PROCEDURE SetConstruct(sc : AST.Set) : IR.Expression;
  VAR
    i, len : LONGINT;
    result, type: IR.Expression;
  BEGIN
    IF (sc.type = NIL) THEN
      type := NIL;
    ELSE
      type := Designator(sc.type);
    END;
    IF (sc. elementList. len = 0) THEN
      RETURN b.NewSetRange(sc.lBrace.sym, type, NIL, NIL, TRUE);
    ELSE
      len := (sc.elementList.len+1) DIV 2; 
      result := Range(type, sc.elementList.n[0], TRUE);
      FOR i := 1 TO len-1 DO
        result := b.NewSetOp(NIL, IR.setUnion, result,
                             Range(type, sc.elementList.n[i*2], TRUE));
      END;
      RETURN result;
    END;
  END SetConstruct;

  PROCEDURE QualType(qualType: AST.QualType): IR.Expression;
    VAR
      type: IR.Expression;
      arguments: IR.ExpressionList;
      i: LONGINT;
      n: AST.Node;
    BEGIN
      type := Designator(qualType.qualident);
      NEW(arguments, (qualType.arguments.len+1) DIV 2);
      FOR i := 0 TO LEN(arguments^)-1 DO
        n := qualType.arguments.n[i*2];
        WITH n: AST.QualType DO
          arguments[i] := QualType(n);
        ELSE
          arguments[i] := Designator(n);  (* actually Qualident *)
        END;
      END;
      RETURN b.NewQualType(type, arguments, qualType.rParen.sym);
    END QualType;
  
  PROCEDURE Expr (expr: AST.Node): IR.Expression;
    VAR
      left, right, res: IR.Expression;

    BEGIN
      WITH expr: AST.Terminal DO
        CASE expr. sym. id OF
        | Symbol.ident:
          res := Designator (expr)
        | Symbol.stringSingle, Symbol.stringDouble:
          res := b. NewStringConst (expr. sym)
        | Symbol.number10:
          res := b. NewIntConst10 (expr. sym)
        | Symbol.number16:
          res := b. NewIntConst16 (expr. sym)
        | Symbol.number16X:
          res := b. NewCharConst16 (expr. sym)
        | Symbol.numberExpE:
          res := b. NewRealConst (expr.sym, Predef.real);
        | Symbol.numberExpD:
          res := b. NewRealConst (expr.sym, Predef.longreal);
        | Symbol.nil:
          res := b. NewNil (expr. sym)
        END

      | expr: AST.Factor DO
        res := Expr (expr. expr)
            
      | expr: AST.ArrayIndex DO      (* part of designator *)
        res := Designator (expr)
       
      | expr: AST.Operator DO
        IF (expr. op. sym. id = Symbol.period) OR
           (expr. op. sym. id = Symbol.arrow) THEN
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

      | expr: AST.Set DO
        res := SetConstruct(expr);

      | expr: AST.FunctionCall DO
        res := FunctionCall (expr, FALSE);

      | expr: AST.QualType DO
        res := QualType(expr);
        
      ELSE
        Log.Type("++ Unknown expression class in Expr", expr);
        ASSERT (FALSE)
      END;
      RETURN b. Fold (res)
    END Expr;
  
  PROCEDURE FunctionCall (call: AST.FunctionCall;
                          isProcCall: BOOLEAN): IR.Expression;
    VAR
      design: IR.Expression;
      arguments: IR.ExpressionList;
      i: LONGINT;
    BEGIN
      design := Designator (call. design);
      NEW (arguments, (call. arguments. len+1) DIV 2);
      FOR i := 0 TO LEN (arguments^)-1 DO
        arguments[i] := Expr (call. arguments. n[i*2])
      END;
      RETURN b.NewCall(design, arguments, ~isProcCall, currentSourceContext,
                       call.rParen.sym);
    END FunctionCall;

  PROCEDURE StatementSeq (statmSeq: AST.NodeList): IR.StatementSeq;
    VAR
      i, count: LONGINT;
      n: AST.Node;
      statmSeqIR, copy: IR.StatementSeq;
      statm: IR.Statement;

    PROCEDURE ProcedureCall (call: AST.ProcedureCall): IR.Statement;
      VAR
        expr, design: IR.Expression;
        arguments: IR.ExpressionList;
      BEGIN
        IF (call. call IS AST.FunctionCall) THEN
          expr := FunctionCall (call. call(AST.FunctionCall), TRUE);
        ELSE
          (* create procedure call from lonely designator *)
          NEW (arguments, 0);
          design := Designator (call. call);
          expr := b.NewCall(design, arguments, FALSE, currentSourceContext,
                            design.sym);
        END;
        IF (expr # NIL) & (expr IS IR.Statement) THEN
          RETURN expr(IR.Statement);
        ELSE
          RETURN NIL;  (* return NIL in case of error; skipped in StatmSeq *)
        END;
      END ProcedureCall;
  
    PROCEDURE Return (return: AST.ReturnStatm): IR.Statement;
      BEGIN
        IF (return. expr = NIL) THEN
          RETURN b. NewReturn (return. return. sym, NIL)
        ELSE
          RETURN b. NewReturn (return. return. sym,
                               Expr (return. expr))
        END;
      END Return;

    PROCEDURE Assignment (design, op, value: AST.Node): IR.Statement;
      VAR
        variable, valueExpr: IR.Expression;
      BEGIN
        variable := Designator (design);
        valueExpr := Expr (value);
        RETURN b. NewAssignment (op(AST.Terminal). sym, variable, valueExpr)
      END Assignment;
    
    PROCEDURE IfStatm (ifStatm: AST.IfStatm): IR.Statement;
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
              (ifStatm. guardList. n[i](AST.Terminal). sym,
               Expr (ifStatm. guardList. n[i+1]),
               StatementSeq (ifStatm. guardList. n[i+3](AST.NodeList)),
               elseSeq);
          NEW (elseSeq, 1);
          elseSeq[0] := else;
          DEC (i, 4)
        UNTIL (i < 0);
        RETURN else
      END IfStatm;
  
    PROCEDURE CaseStatm (caseStatm: AST.CaseStatm): IR.Statement;
      VAR
        select: IR.Expression;
        elseSeq: IR.StatementSeq;
        i, count: LONGINT;
        caseList: IR.CaseList;

      PROCEDURE Labels (labels: AST.NodeList): IR.CaseLabels;
        VAR
          i: LONGINT;
          setRanges: IR.CaseLabels;
        BEGIN
          NEW (setRanges, (labels. len+1) DIV 2);
          FOR i := 0 TO labels. len-1 BY 2 DO
            setRanges[i DIV 2] := Range (NIL, labels. n[i], FALSE);
          END;
          RETURN setRanges;
        END Labels;
      
      BEGIN
        select := Expr (caseStatm. expr);

        (* count non-empty branches *)
        count := 0;
        FOR i := 0 TO caseStatm. caseList. len-1 BY 4 DO
          IF (caseStatm. caseList. n[i] # NIL) THEN
            INC (count);
          END;
        END;

        (* translate all non-empty branches *)
        NEW (caseList, count);
        count := 0;
        FOR i := 0 TO caseStatm. caseList. len-1 BY 4 DO
          IF (caseStatm. caseList. n[i] # NIL) THEN
            caseList[count] := b. NewCase
              (caseStatm. caseList. n[i+1](AST.Terminal). sym,
               Labels (caseStatm. caseList. n[i](AST.NodeList)),
               StatementSeq (caseStatm. caseList. n[i+2](AST.NodeList)));
            INC (count);
          END;
        END;
        IF (caseStatm. else # NIL) THEN
          elseSeq := StatementSeq (caseStatm. elseStatmSeq)
        ELSE
          elseSeq := NIL
        END;
        RETURN b. NewCaseStatm (caseStatm. case. sym,
                                select, caseList, elseSeq);
      END CaseStatm;
  
    PROCEDURE RepeatStatm (repeatStatm: AST.RepeatStatm): IR.Statement;
      BEGIN
        RETURN b. NewRepeatStatm (repeatStatm. repeat. sym,
                                  StatementSeq (repeatStatm. statmSeq),
                                  Expr (repeatStatm. expr));
      END RepeatStatm;
  
    PROCEDURE WhileStatm (whileStatm: AST.WhileStatm): IR.Statement;
      BEGIN
        RETURN b. NewWhileStatm (whileStatm. while. sym,
                                 Expr (whileStatm. guard),
                                 StatementSeq (whileStatm. statmSeq));
      END WhileStatm;
  
    PROCEDURE WithStatm (withStatm: AST.WithStatm): IR.Statement;
      VAR
        else: IR.Statement;
        elseSeq, region: IR.StatementSeq;
        i: LONGINT;
        guard: IR.Expression;

      PROCEDURE TypeTestExpr (op: AST.Operator): IR.Expression;
        BEGIN
          RETURN b. NewTypeTest (op.op.sym, Expr (op. left), Expr (op. right));
        END TypeTestExpr;
      
      BEGIN
        IF (withStatm. else # NIL) THEN
          elseSeq := StatementSeq (withStatm. elseStatmSeq)
        ELSE
          elseSeq := NIL
        END;
        else := NIL;
        i := withStatm. guardList. len-4;
        REPEAT
          guard := TypeTestExpr(withStatm.guardList.n[i+1](AST.Operator));
          IF (guard IS IR.TypeTest) THEN   (* otherwise we have an error *)
            b. StartTypeGuard (guard(IR.TypeTest), currentNamespace);
            region := StatementSeq(withStatm.guardList.n[i+3](AST.NodeList));
            b. EndTypeGuard (currentNamespace);
            
            else := b. NewWithStatm
                (withStatm. guardList. n[i](AST.Terminal). sym,
                 guard, region, elseSeq);
            NEW (elseSeq, 1);
            elseSeq[0] := else;
          END;
          DEC (i, 4)
        UNTIL (i < 0);
        RETURN else
      END WithStatm;
  
    PROCEDURE ForStatm (forStatm: AST.ForStatm): IR.Statement;
      PROCEDURE Step (): IR.Expression;
        BEGIN
          IF (forStatm. step # NIL) THEN
            RETURN Expr (forStatm. step);
          ELSE
            RETURN NIL;
          END;
        END Step;
      
      BEGIN
        RETURN b. NewForStatm (forStatm. for. sym,
                               Designator (forStatm. ident),
                               Expr (forStatm. startValue),
                               Expr (forStatm. endValue),
                               Step(),
                               StatementSeq (forStatm. statmSeq));
      END ForStatm;
  
    PROCEDURE IterateStatm (iterStatm: AST.IterateStatm): IR.Statement;
      BEGIN
        RETURN b. NewIterateStatm (iterStatm. for. sym, currentSourceContext,
                                   Designator (iterStatm. ident),
                                   Expr (iterStatm. range),
                                   StatementSeq (iterStatm. statmSeq));
      END IterateStatm;
  
    PROCEDURE LoopStatm (loopStatm: AST.LoopStatm): IR.Statement;
      BEGIN
        RETURN b. NewLoopStatm (loopStatm. loop. sym,
                                StatementSeq (loopStatm. statmSeq));
      END LoopStatm;
  
    PROCEDURE TryStatm (tryStatm: AST.TryStatm): IR.Statement;
      VAR
        statmSeq, catchStatm: IR.StatementSeq;
        catchList: IR.CatchList;
        catch: AST.Catch;
        guard: IR.Expression;
        i: LONGINT;
      BEGIN
        NEW(catchList, tryStatm.catchList.len);
        statmSeq := StatementSeq(tryStatm.statmSeq);
        FOR i := 0 TO tryStatm.catchList.len-1 DO
          catch := tryStatm.catchList.n[i](AST.Catch);
          guard := Expr(catch.type);

          IF (catch.ident = NIL) THEN
            catchStatm := StatementSeq(catch.statmSeq);
          ELSE
            b.StartExceptionScope(guard, catch.ident.sym, currentNamespace);
            catchStatm := StatementSeq(catch.statmSeq);
            b.EndExceptionScope(currentNamespace);
          END;
          
          catchList[i] := b.NewCatchClause(guard, catchStatm);
        END;
        RETURN b.NewTryStatm(tryStatm.try.sym, statmSeq, catchList);
      END TryStatm;
  
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
          n := statmSeq. n[i];
          WITH n: AST.ProcedureCall DO
            statm := ProcedureCall (n);
            
          | n: AST.ReturnStatm DO
            statm := Return (n);

          | n: AST.Assignment DO
            statm := Assignment (n. assignment. left,
                                 n. assignment. op,
                                 n. assignment. right)

          | n: AST.IfStatm DO
            statm := IfStatm (n)

          | n: AST.CaseStatm DO
            statm := CaseStatm (n)
                
          | n: AST.WithStatm DO
            statm := WithStatm (n)

          | n: AST.RepeatStatm DO
            statm := RepeatStatm (n)
              
          | n: AST.WhileStatm DO
            statm := WhileStatm (n)

          | n: AST.ForStatm DO
            statm := ForStatm (n);

          | n: AST.IterateStatm DO
            statm := IterateStatm (n);

          | n: AST.LoopStatm DO
            statm := LoopStatm (n);

          | n: AST.ExitStatm DO
            statm := b. NewExit (n. exit. sym);

          | n: AST.TryStatm DO
            statm := TryStatm(n);
            
          ELSE
            Log.Type("++ Unknown type in StatementSeq", n);
            ASSERT (FALSE)
          END;

          IF (statm # NIL) THEN          (* ignore faulty statements *)
            statmSeqIR[count] := statm;
            INC (count)
          END;
        END
      END;

      IF (count # LEN (statmSeqIR^)) THEN
        (* some statements where dropped because of errors: created shortened
           array *)
        NEW (copy, count);
        FOR i := 0 TO count-1 DO
          copy[i] := statmSeqIR[i]
        END;
        statmSeqIR := copy
      END;
      RETURN statmSeqIR
    END StatementSeq;
  
  PROCEDURE ConstDecl(constDecl: Sym.ConstDecl; constExpr : AST.Node);
  VAR
    expr : IR.Expression;
  BEGIN
    expr := b. AssertConst (Expr (constExpr));
    constDecl. SetValueType (expr(IR.Const). value, expr. type(Sym.PredefType))
  END ConstDecl;
   
<* PUSH; Warnings := FALSE *>
  PROCEDURE ProcDecl (procDecl: Sym.ProcDecl;
                      procCode: AST.ProcDecl): IR.Procedure;
    VAR
      statmSeq: IR.StatementSeq;
      oldNamespace: Sym.Namespace;
      oldSourceContext: Sym.Item;
      endOfBody: SymList.Symbol;
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
      IF (procCode.body = NIL) THEN
        endOfBody := NIL;
      ELSE
        endOfBody := procCode. body. end. sym;
      END;
      
      currentNamespace := oldNamespace;
      currentSourceContext := oldSourceContext;
      RETURN b. NewProcedure (procCode. proc. sym, procDecl, statmSeq,
                              endOfBody,
                              (procCode.body # NIL) & 
                              (procCode.body.begin # NIL))
    END ProcDecl;
<* POP *>
  
  PROCEDURE Module (moduleDecl: Sym.Module;
                    moduleAST: AST.Module): IR.Module;
    VAR
      declSeq: AST.NodeList;
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
            procList[count] := ProcDecl (item, item.procAST(AST.ProcDecl));
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
                           moduleDecl, procList, statmSeq,
                           moduleAST. body. end. sym)
    END Module;

  PROCEDURE TranslateEmbeddedExpr (item: Sym.Item);
  (**Traverses the symbol table and resolves all expressions.  This pass
     calculates the value of declared constants, and the length of array
     types.  Declarations are traversed in the order in which they appear
     in the source code.  This works fine, as long as no forward references
     can appear in the resolved expressions.  *)
    VAR
      expr: IR.Expression;
      oldNamespace: Sym.Namespace;
      oldSourceContext: Sym.Item;

    PROCEDURE TraverseNested (item: Sym.Item);
      VAR
        nested: Sym.Item;
      BEGIN
        nested := item. nestedItems;
        WHILE (nested # NIL) DO
          TranslateEmbeddedExpr (nested);
          nested := nested. nextNested
        END;
      END TraverseNested;
    
    BEGIN
      WITH item: Sym.Record DO
        (* make sure that all issues with the record's fields are resolved
           first; in particular, all array length of fields must be computed *)
        TraverseNested (item);
      ELSE  (* ignore *)  
      END;
      
      WITH item: Sym.Array DO
        IF ~item. isOpenArray THEN
          expr := Expr (item. lengthExpr);
          IF (expr = b. errorExpr) THEN  (* error in array length *)
            item. SetLength(1);
          ELSE
            item. SetLength(expr(IR.Const).value(BigInt.BigInt).ToLongInt());
          END;
        END;

      | item: Sym.ConstDecl DO
        ConstDecl (item, item. constExpr);
        
      ELSE  (* ignore *)
      END;

      WITH item: Sym.Type DO
        IF ~(item IS Sym.TypeName) THEN
          TR.AllocateType (item)
        END;
      ELSE  (* ignore *)  
      END;

      WITH item: Sym.ProcDecl DO
        oldNamespace := currentNamespace;
        oldSourceContext := currentSourceContext;
        currentNamespace := item. ns;
        currentSourceContext := item;
        
        TraverseNested (item);
        
        currentNamespace := oldNamespace;
        currentSourceContext := oldSourceContext;
      ELSE
        IF ~(item IS Sym.Record) THEN
          TraverseNested (item);
        END;
      END;
    END TranslateEmbeddedExpr;
  
  BEGIN
    currentSourceContext := symTab;
    currentNamespace := symTab. ns;
    TranslateEmbeddedExpr (symTab);
    RETURN Module (symTab, module)
  END CreateIR;

END OOC:AST:CreateIR.

