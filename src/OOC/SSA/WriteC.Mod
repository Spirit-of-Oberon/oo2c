MODULE OOC:SSA:WriteC [OOC_EXTENSIONS];

IMPORT
  IntStr, StdChannels, Strings, TextRider,
  ADT:Object, ADT:String, ADT:Dictionary,
  OOC:SymbolTable:Item, OOC:IR, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:Schedule, OOC:SSA:XML,
  OOC:SSA:DeadCodeElimination, OOC:SSA:Destore,
  OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:WriteConst, OOC:C:WriteDecl;


TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc = RECORD
    w: TextRider.Writer;
    registerMap: Dictionary.Dictionary;
  END;

PROCEDURE NewWriter (textWriter: TextRider.Writer;
                     registerMap: Dictionary.Dictionary): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    w. w := textWriter;
    w. registerMap := registerMap;
    RETURN w
  END NewWriter;

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

PROCEDURE Fixup (pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      CASE instr. opcode OF
      | Opcode.call:
        IF (instr. opndList. arg IS SSA.Address) THEN
          (* if the function address of a call is taken from an address
             instruction, then replace this operand with a `declref';
             this way, the name of the called function is used directly,
             without going through an intermediate address value *)
          instr. opndList. ReplaceOpnd
              (pb. GetDeclRef (instr. opndList. arg(SSA.Address). decl));
        END;
      ELSE (* nothing to do *)
      END;
      instr := instr. nextInstr
    END;
  END Fixup;


PROCEDURE AssignRegisters (w: TextRider.Writer; pb: SSA.ProcBlock): Dictionary.Dictionary;
(**Assigns registers to values produced by SSA instructions.  For the moment,
   a very simple allocator is sufficient: every value gets its very own
   variable.  The C compiler will have to deal with this ;-) *)
  VAR
    registerMap: Dictionary.Dictionary;
    instr: SSA.Instr;
    res: SSA.Result;
    type: Opcode.Subclass;
    str: ARRAY 32 OF CHAR;
    count: LONGINT;

  PROCEDURE StoredInRegister (instr: SSA.Instr): BOOLEAN;
    BEGIN
      WITH instr: SSA.Const DO
        RETURN FALSE
      ELSE
        RETURN TRUE
      END;
    END StoredInRegister;

  PROCEDURE AssignRegister (result: SSA.Result; ctype: WriteDecl.BasicTypeId);
    BEGIN
      (* create name for result *)
      IntStr.IntToStr (count, str);
      Strings.Insert ("i", 0, str);
      registerMap. Set (result, String.New (str));
      INC (count);
      
      (* emit declaration for variable *)
      w. WriteLn;
      w. WriteString ("  register ");
      w. WriteString (WriteDecl.basicType[ctype]. repr);
      w. WriteChar (" ");
      w. WriteString (str);
      w. WriteChar (";");
    END AssignRegister;
  
  BEGIN
    count := 0;
    registerMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      type := instr. GetResultType();
      IF (type # Opcode.scNone) & StoredInRegister (instr) THEN
        AssignRegister (instr, SubclassToBasicType (type));
      END;
      res := instr. nextResult;
      WHILE (res # NIL) DO
        IF (res. subclass # Opcode.scNone) THEN
          AssignRegister (res, SubclassToBasicType (res. subclass))
        END;
        res := res. nextResult
      END;
      instr := instr. nextInstr
    END;
    w. WriteLn;
    RETURN registerMap;
  END AssignRegisters;

PROCEDURE WriteLocalDecl (w: TextRider.Writer;
                          converter: ConvertDecl.Converter;
                          pb: SSA.ProcBlock);
(**Writes local declarations of the procedure, most of all local variables.  *)
  VAR
    declMap: Dictionary.Dictionary;
    instr: SSA.Instr;
    decl: Item.VarDecl;
    cDecl: WriteDecl.Declaration;
    block: WriteDecl.Block;

  PROCEDURE GetLocalDecl (instr: SSA.Instr): Item.VarDecl;
    VAR
      opnd: SSA.Opnd;
      varDecl: Item.VarDecl;
    BEGIN
      opnd := instr. opndList;
      WHILE (opnd # NIL) &
            ((opnd. class # Opnd.readDesign) &
             (opnd. class # Opnd.writeDesign)) DO
        opnd := opnd. nextOpnd;
      END;
      IF (opnd. arg IS SSA.DeclRef) THEN
        varDecl := opnd. arg(SSA.DeclRef). decl(Item.VarDecl);
        IF (varDecl. Procedure() = pb. procDecl) THEN
          RETURN varDecl
        END;
      END;
      RETURN NIL
    END GetLocalDecl;
  
  BEGIN
    block := WriteDecl.NewBlock ();
    
    declMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) OR (instr. opcode = Opcode.set) THEN
        decl := GetLocalDecl (instr);
        IF (decl # NIL) & ~declMap. HasKey (decl) &
           ~decl. isParameter THEN
          cDecl := converter. ConvertDecl (block, decl);
          w. WriteLn;
          w. WriteString ("  ");
          cDecl. Write (w);
          w. WriteChar (";");
          declMap. Set (decl, NIL)
        END;
      END;
      instr := instr. nextInstr
    END;
    
    w. WriteLn;
  END WriteLocalDecl;


PROCEDURE (w: Writer) WriteString (str[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    w. w. WriteString (str)
  END WriteString;

PROCEDURE (w: Writer) WriteChar (ch: CHAR);
  BEGIN
    w. w. WriteChar (ch)
  END WriteChar;

PROCEDURE (w: Writer) Newline;
  BEGIN
    w. w. WriteLn;
    w. w. WriteString ("  ");
  END Newline;

PROCEDURE (w: Writer) Ref (opnd: SSA.Opnd);
  VAR
    arg: SSA.Result;
    obj: Object.Object;
    name: String.String;
  BEGIN
    arg := opnd. arg;
    WITH arg: SSA.DeclRef DO
      (* insert name of the object; shortcut to save the type cast
         when calling a procedure *)
      name := Naming.NameOfDeclaration (arg. decl);
      w. WriteString (name. array^)

    | arg: SSA.Const DO
      (* write constant values directly, without going through an
         intermediate register; kind of unnatural for C code *)
      WriteConst.Write (w. w, arg. value);
      
    ELSE
      IF w. registerMap. HasKey (opnd. arg) THEN
        obj := w. registerMap. Get (opnd. arg);
        w. WriteString (obj(String.String). array^)
      ELSE
        w. WriteString ("/* undefined ref */")
      END
    END
  END Ref;

PROCEDURE (w: Writer) WriteInstrList (b: Schedule.Block);
  VAR
    proxy: Schedule.InstrProxy;
    instr: SSA.Instr;
    opnd: SSA.Opnd;
    target: Object.Object;
    name: String.String;

  PROCEDURE ^ Call (call: SSA.Instr);
    
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
          w. Ref (opnd);
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
      w. WriteChar (")")
    END Assert;
  
  PROCEDURE Call (call: SSA.Instr);
    BEGIN
      w. Ref (call. opndList);
      w. WriteString ("(");
      RefList (call. opndList, Opnd.arg);
      w. WriteString (")")
    END Call;
  
  PROCEDURE WriteOpcode (instr: SSA.Instr);
    VAR
      i: LONGINT;
      str: ARRAY 32 OF CHAR;
    CONST
      padWidth = 11;
    BEGIN
      w. WriteString ("/*");
      instr. GetOpcodeName (str);
      i := 0;
      WHILE (str[i] # 0X) DO
        INC (i);
      END;
      WHILE (i < padWidth) DO
        str[i] := " "; INC (i)
      END;
      str[i] := 0X;
      w. WriteString (str);
      w. WriteString ("*/ ");
    END WriteOpcode;

  PROCEDURE WriteDyadicOp (instr: SSA.Instr; op: ARRAY OF CHAR);
    BEGIN
      w. Ref (instr. opndList);
      w. WriteString (op);
      w. Ref (instr. opndList. nextOpnd);
    END WriteDyadicOp;
  
  
  PROCEDURE AllPathsClosed (selectReturn: SSA.Instr): BOOLEAN;
  (* Returns TRUE if all paths into the "select-return" end with a
     "return" instruction.  *)
    VAR
      opnd: SSA.Opnd;
    BEGIN
      IF (selectReturn. opndList. nextOpnd. nextOpnd = NIL) THEN
        RETURN FALSE                     (* not at single RETURN in the proc *)
      ELSE
        opnd := selectReturn. opndList. nextOpnd;
        WHILE (opnd. nextOpnd # NIL) DO
          IF ~(opnd. arg. instr. opcode = Opcode.return) THEN
            RETURN FALSE
          END;
          opnd := opnd. nextOpnd;
        END;
        RETURN TRUE
      END
    END AllPathsClosed;
  
  PROCEDURE WriteCollect (collect, targetInstr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
      res: SSA.Result;
      targetVar: Object.Object;
    BEGIN
      opnd := collect. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          w. WriteString (targetVar(String.String). array^);
          w. WriteString ("=");
          w. Ref (opnd);
          w. WriteChar (";");
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;
    END WriteCollect;
  
  BEGIN
    proxy := b. proxyList;
    WHILE (proxy # NIL) DO
      instr := proxy. instr;
      w. Newline;
      WriteOpcode (instr);

      IF w. registerMap. HasKey (instr) THEN
        target := w. registerMap. Get (instr);
        w. WriteString (target(String.String). array^);
        w. WriteString (" = ");
      END;
      
      CASE instr. opcode OF
      | Opcode.const:
        (* nothing *)

      | Opcode.declRef:
        (* nothing *)
        
      | Opcode.address:
        name := Naming.NameOfDeclaration (instr(SSA.Address). decl);
        IF ~(instr(SSA.Address). decl IS Item.VarDecl) OR
             ~(instr(SSA.Address). decl(Item.VarDecl). type IS Item.Array) THEN
          (* charming C: the address of the variable is its name, all
             others need the address operator *)
          w. WriteChar ("&");
        END;
        w. WriteString (name. array^);

      | Opcode.enter:
        (* nothing *)
        
      | Opcode.select:
        (* nothing *)

      | Opcode.collect:
        WriteCollect (instr, instr. GetCollectTarget());
        
      | Opcode.loopStart:
        (* nothing *)
        
      | Opcode.loopEnd:
        (* nothing *)
        
      | Opcode.get:
        w. WriteString ("*(");
        w. WriteString (WriteDecl.basicType
                        [SubclassToBasicType (instr. subclass)]. repr);
        w. WriteString ("*)");
        w. Ref (instr. opndList. nextOpnd);
        
      | Opcode.set:
        w. WriteString ("*(");
        w. WriteString (WriteDecl.basicType
                        [SubclassToBasicType (instr. subclass)]. repr);
        w. WriteString ("*)");
        w. Ref (instr. opndList. nextOpnd);
        w. WriteString (" = ");
        w. Ref (instr. GetOpndClass (Opnd.sourceValue));

      | Opcode.add:
        WriteDyadicOp (instr, "+");
        
      | Opcode.negate:
        w. WriteChar ("-");
        w. Ref (instr. opndList);
        
      | Opcode.eql:
        WriteDyadicOp (instr, "==");
      | Opcode.neq:
        WriteDyadicOp (instr, "!=");
        
      | Opcode.assert:
        Assert (instr)
            
      | Opcode.call:
        Call (instr);
            
      | Opcode.return:
        opnd := instr. GetOpndClass (Opnd.functionResult);
        IF (opnd # NIL) THEN
          w. WriteString ("return ");
          w. Ref (opnd)
        ELSE
          w. WriteString ("return")
        END;
        
      | Opcode.selectReturn:
        IF ~AllPathsClosed (instr) THEN
          w. WriteString ("return")
        END;
      END;
      w. WriteChar (";");
      
      proxy := proxy. nextProxy
    END;
  END WriteInstrList;

PROCEDURE (w: Writer) WriteBlocks (domRoot: Schedule.Block);
  VAR
    lastBlock: Schedule.Block;
    blockCount: LONGINT;
    blockMap: Dictionary.Dictionary;
    
  PROCEDURE AssignIds (b: Schedule.Block);
  (* assign block ids in the same order as they are written by `WriteBlock' *)
    VAR
      str: ARRAY 16 OF CHAR;
      obj: Object.Object;
    BEGIN
      IF (b # NIL) & ~blockMap. HasKey (b) THEN
        IntStr.IntToStr (blockCount, str);
        Strings.Insert ("l", 0, str);
        obj := String.New (str);
        blockMap. Set (b, obj);
        INC (blockCount);
        
        WITH b: Schedule.BranchBlock DO
          AssignIds (b. jump);
          AssignIds (b. branchTo);
        ELSE (* standard block *)
          AssignIds (b. jump);
        END;
      END;
    END AssignIds;
  
  PROCEDURE WriteBlock (b: Schedule.Block);
    PROCEDURE WriteBlockId (b: Schedule.Block);
      VAR
        obj: Object.Object;
      BEGIN
        obj := blockMap. Get (b);
        w. WriteString (obj(String.String). array^);
      END WriteBlockId;
    
    PROCEDURE WriteGoto (target: Schedule.Block);
      BEGIN
        w. WriteString ("goto ");
        WriteBlockId (target);
        w. WriteChar (";");
      END WriteGoto;
    
    BEGIN
      IF (b = NIL) THEN
        RETURN
      ELSIF b. isWritten THEN
        w. Newline;
        WriteGoto (b)
      ELSE
        b. isWritten := TRUE;
        IF (b. degreeIn # 1) OR
           (lastBlock # NIL) & (lastBlock. jump # b) THEN
          (* we have a goto instruction jumping in this block, so we
             better write out a label *)
          w. w. WriteLn;
          WriteBlockId (b);
          w. WriteChar (":");
        END;
        w. WriteInstrList (b);
        
        WITH b: Schedule.BranchBlock DO
          w. Newline;
          w. WriteString ("if (");
          IF ~b. branchOnTrue THEN
            w. WriteChar("!");
          END;
          w. Ref (b. predicate);
          w. WriteString (") ");
          WriteGoto (b. branchTo);
          WriteBlock (b. jump);
          WriteBlock (b. branchTo);
        ELSE (* standard block *)
          WriteBlock (b. jump);
        END;
        lastBlock := b;
      END;
    END WriteBlock;
  
  BEGIN
    blockCount := 0;
    blockMap := Dictionary.New();
    lastBlock := NIL;

    AssignIds (domRoot);
    WriteBlock (domRoot)
  END WriteBlocks;

PROCEDURE ProcBody* (textWriter: TextRider.Writer;
                     converter: ConvertDecl.Converter;
                     procDecl: IR.Procedure);
  
  VAR
    pb: SSA.ProcBlock;
    enter: SSA.Instr;
    s: SSA.Result;
    domRoot: Schedule.Block;
    w: Writer;
  BEGIN
    pb := SSA.NewProcBlock (procDecl. decl);
    enter := pb. selectReturn. opndList. arg. instr;
    s := IRtoSSA.StatmSeq (pb, enter. nextResult,
                           procDecl. statmSeq);
    pb. selectReturn. AddOpnd (s, Opnd.store);

    (* code transformations *)
    DeadCodeElimination.Transform (pb);
    Destore.Transform (pb);
    DeadCodeElimination.Transform (pb);

    (* write SSA code to stdout, both in native and scheduled format *)
    XML.Write (StdChannels.stdout. NewWriter(), pb, TRUE);
    domRoot := Schedule.Schedule (pb);
    XML.WriteSchedule (StdChannels.stdout. NewWriter(), domRoot);
    
    Fixup (pb);
    WriteLocalDecl (textWriter, converter, pb);
    w := NewWriter (textWriter, AssignRegisters (textWriter, pb));
    w. WriteBlocks (domRoot);
  END ProcBody;

PROCEDURE ModuleBody* (w: TextRider.Writer; converter: ConvertDecl.Converter;
                       procDecl: IR.Procedure);
  BEGIN
  END ModuleBody;

END OOC:SSA:WriteC.
