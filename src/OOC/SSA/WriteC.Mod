MODULE OOC:SSA:WriteC;

IMPORT
  Log, IntStr, StdChannels, Strings, TextRider,
  ADT:Object, ADT:String, ADT:Dictionary,
  OOC:IR, OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:XML,
  OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:WriteConst, OOC:C:WriteDecl;


PROCEDURE SubclassToBasicType (subclass: Opcode.Subclass): WriteDecl.BasicTypeId;
  BEGIN
    CASE subclass OF
    | Opcode.scNone: RETURN WriteDecl.void
    | Opcode.scAddress: RETURN WriteDecl.ptr
    | Opcode.scUnsigned8: RETURN WriteDecl.uint8
    | Opcode.scUnsigned16: RETURN WriteDecl.uint16
    | Opcode.scUnsigned32: RETURN WriteDecl.uint32
    | Opcode.scUnsigned64: RETURN WriteDecl.uint64
    | Opcode.scSigned8: RETURN WriteDecl.int8
    | Opcode.scSigned16: RETURN WriteDecl.int16
    | Opcode.scSigned32: RETURN WriteDecl.int32
    | Opcode.scSigned64: RETURN WriteDecl.int64
    END;
  END SubclassToBasicType;

PROCEDURE AssignRegisters (w: TextRider.Writer; pb: SSA.ProcBlock): Dictionary.Dictionary;
(**Assigns registers to values produced by SSA instructions.  For the moment,
   a very simple allocator is sufficient: every value gets its very own
   variable.  The C compiler will have to deal with this ;-) *)
  VAR
    registerMap: Dictionary.Dictionary;
    instr: SSA.Instr;
    type: Opcode.Subclass;
    ctype: WriteDecl.BasicTypeId;
    str: ARRAY 32 OF CHAR;
    count: LONGINT;
  BEGIN
    count := 0;
    registerMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      type := instr. GetResultType();
      IF (type # Opcode.scNone) THEN
        ctype := SubclassToBasicType (type);

        (* create name for result *)
        IntStr.IntToStr (count, str);
        Strings.Insert ("i", 0, str);
        registerMap. Set (instr, String.New (str));
        INC (count);
        
        (* emit declaration for variable *)
        w. WriteLn;
        w. WriteString ("  register ");
        w. WriteString (WriteDecl.basicType[ctype]. repr);
        w. WriteChar (" ");
        w. WriteString (str);
        w. WriteChar (";");
      END;
      instr := instr. nextInstr
    END;
    w. WriteLn;
    RETURN registerMap;
  END AssignRegisters;

PROCEDURE WriteInstrList (w: TextRider.Writer; pb: SSA.ProcBlock;
                          registerMap: Dictionary.Dictionary);
  VAR
    instr: SSA.Instr;
    opnd: SSA.Opnd;
    str: ARRAY 32 OF CHAR;
    target: Object.Object;
    name: String.String;

  PROCEDURE ^ Call (call: SSA.Instr);
    
  PROCEDURE Ref (opnd: SSA.Opnd);
    VAR
      arg: SSA.Result;
      obj: Object.Object;
    BEGIN
      arg := opnd. arg;
      WITH arg: SSA.Address DO
        (* shortcut to save the type cast when calling a procedure *)
        name := Naming.NameOfDeclaration (arg. decl);
        w. WriteString (name. array^)
      ELSE
        IF registerMap. HasKey (opnd. arg) THEN
          obj := registerMap. Get (opnd. arg);
          w. WriteString (obj(String.String). array^)
        ELSE
          w. WriteString ("/* undefined ref */")
        END
      END
    END Ref;
  
  PROCEDURE RefList (start: SSA.Opnd; class: Opnd.Class);
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
          Ref (opnd);
          INC (count)
        END;
        opnd := opnd. nextOpnd
      END;
    END RefList;
  
  PROCEDURE Assert (assert: SSA.Instr);
    BEGIN
      w. WriteString ("_assert(");
      RefList (assert. opndList, Opnd.arg);
      w. WriteString (", ");
      w. WriteString ("0");  (* ... file position missing *)
      w. WriteString (");")
    END Assert;
  
  PROCEDURE Call (call: SSA.Instr);
    BEGIN
      Ref (call. opndList);
      w. WriteString ("(");
      RefList (call. opndList, Opnd.arg);
      w. WriteString (")")
    END Call;
  
  PROCEDURE Newline;
    BEGIN
      w. WriteLn; w. WriteString ("  ");
    END Newline;
  
  BEGIN
    ASSERT (pb. TopSort());
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      Newline;

      IF registerMap. HasKey (instr) THEN
        target := registerMap. Get (instr);
        w. WriteString (target(String.String). array^);
        w. WriteString (" = ");
      END;
      
      CASE instr. opcode OF
      | Opcode.const:
        WriteConst.Write (w, instr(SSA.Const). value);
        w. WriteChar (";")

      | Opcode.address:
        name := Naming.NameOfDeclaration (instr(SSA.Address). decl);
        w. WriteChar ("&");
        w. WriteString (name. array^);
        w. WriteChar (";")

      | Opcode.get:
        (* another *very* drastic shortcut... *)
        name := Naming.NameOfDeclaration (instr. opndList. nextOpnd. nextOpnd. arg(SSA.DeclRef). decl);
        w. WriteString (name. array^);
        w. WriteChar (";")
        
      | Opcode.assert:
        Assert (instr)
            
      | Opcode.call:
        Call (instr);
        w. WriteChar (";")
            
      | Opcode.exit:
        opnd := instr. GetOpndClass (Opnd.functionResult);
        IF (opnd # NIL) THEN
          w. WriteString ("return ");
          Ref (opnd);
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
    registerMap: Dictionary.Dictionary;
  BEGIN
    pb := SSA.NewProcBlock();
    enter := pb. AddInstr (Opcode.enter, Opcode.scNone);
    s := IRtoSSA.StatmSeq (pb, enter. AddResult (Result.store),
                           procDecl. statmSeq);
    pb. exit. AddOpnd (s, Opnd.store);

    XML.Write (StdChannels.stdout. NewWriter(), pb, TRUE);
    
    registerMap := AssignRegisters (w, pb);
    WriteInstrList (w, pb, registerMap);
  END ProcBody;

PROCEDURE ModuleBody* (w: TextRider.Writer; converter: ConvertDecl.Converter;
                       procDecl: IR.Procedure);
  BEGIN
  END ModuleBody;

END OOC:SSA:WriteC.
