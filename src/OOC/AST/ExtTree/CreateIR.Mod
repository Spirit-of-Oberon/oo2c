MODULE OOC:AST:ExtTree:CreateIR;

IMPORT
OOC:AST:ExtTree:XML, StdChannels,
  OOC:AST:ExtTree, OOC:AST:ExtTree:CreateSymTab, OOC:SymbolTable:Item, OOC:IR;



PROCEDURE CreateIR* (module: ExtTree.Module;
                     symTab: Item.Module;
                     b: IR.Builder): IR.Module;
  VAR
    currentNamespace: Item.Namespace;
    currentSourceContext: Item.Item;
    
  PROCEDURE GetName (identDef: ExtTree.IdentDef): IR.Name;
  (* Returns the name embedded in an instance of @otype{ExtTree.IdentDef}.  *)
    BEGIN
      RETURN identDef. ident. sym. str
    END GetName;
  
  PROCEDURE Designator (design: ExtTree.Node): IR.Expression;
    BEGIN
      WITH design: ExtTree.Terminal DO
        RETURN b. NewIdentRef (currentNamespace, currentSourceContext,
                               CreateSymTab.GetName (design))
      END
    END Designator;
  
  PROCEDURE Expr (expr: ExtTree.Node): IR.Expression;
    BEGIN
      WITH expr: ExtTree.Terminal DO
        RETURN Designator (expr)
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
    BEGIN
      IF (call. call IS ExtTree.FunctionCall) THEN
        expr := FunctionCall (call. call(ExtTree.FunctionCall), TRUE);
        RETURN expr(IR.Statement)
      ELSE
        (* create procedure call from designator... *)
        RETURN NIL
      END
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
        n := statmSeq. n[i](ExtTree.Node);
        IF (n # NIL) THEN
          INC (count)
        END
      END;
      NEW (statmSeqIR, count);
      count := 0;
      FOR i := 0 TO statmSeq. len-1 BY 2 DO
        n := statmSeq. n[i](ExtTree.Node);
        IF (n # NIL) THEN
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
    BEGIN
      IF (procDecl. body = NIL) OR (procDecl. body. statmSeq = NIL) THEN
        NEW (statmSeq, 0)
      ELSE
        statmSeq := StatementSeq (procDecl. body. statmSeq)
      END;
      RETURN b. NewProcedure (procDecl. symTabEntry, statmSeq)
    END ProcDecl;
<* POP *>
  
  PROCEDURE Module (module: ExtTree.Module): IR.Module;
    VAR
      declSeq: ExtTree.NodeList;
      i, count: LONGINT;
      n: ExtTree.Node;
      procList: IR.ProcedureList;

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

      RETURN b. NewModule (module. moduleName, procList)
    END Module;
  
  BEGIN
    XML.Write (StdChannels.stdout.NewWriter(), module);
    
    currentSourceContext := symTab;
    currentNamespace := symTab. ns;
    RETURN Module (module)
  END CreateIR;

END OOC:AST:ExtTree:CreateIR.

