MODULE OOC:C:IRtoC;

IMPORT
  Log, ADT:String, Language:String8,
  OOC:IR,  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:C:DeclWriter, OOC:C:Naming, OOC:Make:TranslateToC;

TYPE
  Translator* = POINTER TO TranslatorDesc;
  TranslatorDesc = RECORD
    (TranslateToC.TranslatorDesc)
  END;


PROCEDURE ^ WriteExpr (w : DeclWriter.Writer; expr : IR.Expression);

PROCEDURE Call (w : DeclWriter.Writer; statm: IR.Call);
  VAR
    i: LONGINT;
    design: IR.Expression;
    name: String.String;
  BEGIN
    design := statm. design;
    WITH design: IR.ProcedureRef DO
      name := Naming.NameOfDeclaration (design. decl);
      w. WriteString (name. array^)
    END;
    w. WriteString ("(");
    FOR i := 0 TO LEN (statm. arguments^)-1 DO
      (* FIXME... this may be incorrect if the argument list includes
         multiple occurences of expressions that should only be 
         evaluated once *)
      IF (i # 0) THEN
        w. WriteString (", ")
      END;
      WriteExpr (w, statm. arguments[i])
    END;
    w. WriteString (")");
  END Call;

PROCEDURE WriteExpr (w: DeclWriter.Writer;
                     expr: IR.Expression);
  VAR
    name: String.String;

  PROCEDURE SetRange(expr : IR.SetRange);
    
    PROCEDURE Bit(expr : IR.Expression; next : BOOLEAN);
      BEGIN
        w. WriteString("(1<<(");
        WriteExpr(w, expr);
        IF next THEN w.WriteString("+1") END;
        w.WriteString("))");
      END Bit;
    
    BEGIN
      IF expr.to = expr.from THEN
        Bit(expr.from, FALSE);
      ELSE
        w. WriteString ("(");
        Bit(expr.to, TRUE);
        w. WriteString("-");
        Bit(expr.from, FALSE);
        w. WriteString(")");
      END;
    END SetRange;
  
  BEGIN
    WITH expr: IR.Const DO
      w. WriteConst (expr. value, expr. type)
          
    | expr: IR.Var DO
      name := Naming.NameOfDeclaration (expr. decl);
      w. WriteString (name. array^);
      
    | expr: IR.Adr DO
      (* FIXME... this is a workaround to get addresses of string constants
         translated properly; breaks horribly for all other cases *)
      WriteExpr (w, expr. design);
      
    | expr: IR.Len DO
      (* FIXME... there are a lot more variants to LEN than the length
         of a string constant *)
      ASSERT (expr. array. type(Sym.PredefType). id = Predef.charString);
      w. WriteLInt (expr. array(IR.Const). value(String8.Value). value. length+1, 0);
      
    | expr: IR.Negate DO
      w. WriteChar ("-");
      WriteExpr (w, expr. operand);
      
    | expr: IR.BinaryArith DO
      WriteExpr(w, expr. left);
      CASE expr.variant OF
      | IR.arithAdd:  w. WriteChar("+");
      | IR.arithSub:  w. WriteChar("-");
      | IR.arithDivI: w. WriteChar("/");
      | IR.arithDivR: w. WriteChar("/");
      | IR.arithMul:  w. WriteChar("*");
      | IR.arithMod:  w. WriteChar("%");
      END;
      WriteExpr(w, expr. right);
      
    | expr: IR.SetOp DO
      WriteExpr(w, expr.left);
      CASE expr.variant OF
      | IR.setUnion:  w. WriteChar("|");
      | IR.setDiff:   w. WriteString("& ~");
      | IR.setIntersect: w. WriteChar("&");
      | IR.setSymDiff:   w. WriteChar("^");
      END;
      WriteExpr(w, expr.right);        
      
    | expr: IR.TypeConv DO
      WriteExpr(w, expr.expr);  (* FIXME! generate type casts if required *)
      
    | expr: IR.Call DO
      Call (w, expr)
          
    | expr : IR.SetRange DO
      SetRange(expr);
    ELSE
      Log.Type("++ Unknown operator class in WriteExpr", expr);
      ASSERT (FALSE)
    END
  END WriteExpr;


PROCEDURE WriteStatmSeq* (w: DeclWriter.Writer;
                          statmSeq: IR.StatementSeq);
  VAR
    i: LONGINT;
    statm: IR.Statement;
    
  PROCEDURE Assert (statm: IR.Assert);
    BEGIN
      IF ~statm. disabled THEN
        w. WriteLn;
        w. WriteString ("_assert(");
        WriteExpr (w, statm. predicate);
        w. WriteString (", ");
        w. WriteLInt (statm. code, 0);
        w. WriteString (", ");
        w. WriteString ("0");  (* ... file position missing *)
        w. WriteString (");")
      END
    END Assert;
  
  PROCEDURE Return (return: IR.Return);
    BEGIN
      w. WriteLn;
      IF (return. result = NIL) THEN
        w. WriteString ("return;")
      ELSE
        w. WriteString ("return ");
        WriteExpr (w, return. result);
        w. WriteString (";")
      END;
    END Return;
  
  BEGIN
    (* quick and dirty translation with limited scope; should be placed
       in a separate module ... *)
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statm := statmSeq[i];
      WITH statm: IR.Assert DO
        Assert (statm)
      | statm: IR.Call DO
        w. WriteLn;
        Call (w, statm);
        w. WriteChar (";");
      | statm: IR.Return DO
        Return (statm)
      ELSE
        Log.Type("++ Unknown statement class in WriteStatmSeq", statm);
        ASSERT (FALSE)
      END
    END
  END WriteStatmSeq;


PROCEDURE InitTranslator* (t: Translator);
  BEGIN
    TranslateToC.InitTranslator (t);
  END InitTranslator;

PROCEDURE NewTranslator*(): Translator;
  VAR
    t: Translator;
  BEGIN
    NEW (t);
    InitTranslator (t);
    RETURN t
  END NewTranslator;

PROCEDURE (t: Translator) WriteProcBody* (proc: IR.Procedure);
  BEGIN
    WriteStatmSeq (t. w, proc. statmSeq);
  END WriteProcBody;

END OOC:C:IRtoC.
