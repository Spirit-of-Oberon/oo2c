MODULE OOC:SSA:WriteC;

IMPORT
  Log, StdChannels, TextRider, ADT:String, OOC:IR,
  OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:XML,
  OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:WriteConst;


PROCEDURE ^ Call (w: TextRider.Writer; call: SSA.Instr);

PROCEDURE Ref (w: TextRider.Writer; opnd: SSA.Opnd);
  VAR
    arg: SSA.Result;
    name: String.String;
  BEGIN
    arg := opnd. arg;
    WITH arg: SSA.Const DO
      WriteConst.Write (w, arg. value)
          
    | arg: SSA.DeclRef DO
      name := Naming.NameOfDeclaration (arg. decl);
      w. WriteString (name. array^)

    | arg: SSA.Address DO
      name := Naming.NameOfDeclaration (arg. decl);
      w. WriteString (name. array^)

    | arg: SSA.Instr DO
      (* another *very* drastic shortcut... *)
      IF (arg. opcode = Opcode.get) THEN
        Ref (w, arg. opndList. nextOpnd. nextOpnd);
      ELSE
        Call (w, arg)
      END;      
    ELSE
      Log.Type("++ Unknown argument type in Ref", arg);
      ASSERT (FALSE)
    END;
  END Ref;

PROCEDURE RefList (w: TextRider.Writer; start: SSA.Opnd; class: Opnd.Class);
  VAR
    opnd: SSA.Opnd;
    count: LONGINT;
  BEGIN
    count := 0;
    opnd := start;
    WHILE (opnd # NIL) DO
      IF (opnd. class = class) THEN
        IF (count # 0) THEN
          w. WriteString (", ")
        END;
        Ref (w, opnd);
        INC (count)
      END;
      opnd := opnd. nextOpnd
    END;
  END RefList;

PROCEDURE Assert (w: TextRider.Writer; assert: SSA.Instr);
  BEGIN
    w. WriteString ("_assert(");
    RefList (w, assert. opndList, Opnd.arg);
    w. WriteString (", ");
    w. WriteString ("0");  (* ... file position missing *)
    w. WriteString (");")
  END Assert;

PROCEDURE Call (w: TextRider.Writer; call: SSA.Instr);
  BEGIN
    Ref (w, call. opndList);
    w. WriteString ("(");
    RefList (w, call. opndList, Opnd.arg);
    w. WriteString (")")
  END Call;

PROCEDURE WriteInstrList (w: TextRider.Writer; pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
    opnd: SSA.Opnd;
    str: ARRAY 32 OF CHAR;

  PROCEDURE Newline;
    BEGIN
      w. WriteLn; w. WriteString ("  ");
    END Newline;
  
  BEGIN
    ASSERT (pb. TopSort());
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      Newline;
      CASE instr. opcode OF
      | Opcode.assert:
        Assert (w, instr)
      | Opcode.call:
        Call (w, instr);
        w. WriteChar (";")
      | Opcode.exit:
        opnd := instr. GetOpndClass (Opnd.functionResult);
        IF (opnd # NIL) THEN
          w. WriteString ("return ");
          Ref (w, opnd);
          w. WriteChar (";");
        ELSE
          w. WriteString ("return;")
        END;
      ELSE
        w. WriteString ("/*");
        instr. GetOpcodeName (str);
        w. WriteString (str);
        w. WriteString ("*/");
      END;
      
      instr := instr. nextInstr
    END;
  END WriteInstrList;

PROCEDURE ProcBody* (w: TextRider.Writer; converter: ConvertDecl.Converter;
                     procDecl: IR.Procedure);
  
  VAR
    pb: SSA.ProcBlock;
    enter: SSA.Instr;
    s: SSA.Result;
  BEGIN
    pb := SSA.NewProcBlock();
    enter := pb. AddInstr (Opcode.enter, Opcode.scNone);
    s := IRtoSSA.StatmSeq (pb, enter. AddResult (Result.store),
                           procDecl. statmSeq);
    pb. exit. AddOpnd (s, Opnd.store);

    XML.Write (StdChannels.stdout. NewWriter(), pb, TRUE);
    WriteInstrList (w, pb);
  END ProcBody;

PROCEDURE ModuleBody* (w: TextRider.Writer; converter: ConvertDecl.Converter;
                       procDecl: IR.Procedure);
  BEGIN
  END ModuleBody;

END OOC:SSA:WriteC.
