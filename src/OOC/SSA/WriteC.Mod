MODULE OOC:SSA:WriteC [OOC_EXTENSIONS];

IMPORT
  IntStr, StdChannels, Strings, TextRider,
  ADT:Object, ADT:String, ADT:Dictionary,
  Sym := OOC:SymbolTable, OOC:IR, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:Schedule, OOC:SSA:XML,
  OOC:SSA:DeadCodeElimination, OOC:SSA:Destore, OOC:SSA:Allocator,
  OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:DeclWriter;


TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc = RECORD
    (DeclWriter.WriterDesc)
    registerMap: Dictionary.Dictionary;
  END;

PROCEDURE NewWriter (cWriter: DeclWriter.Writer;
                     registerMap: Dictionary.Dictionary): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    cWriter. CopyTo (w);
    w. registerMap := registerMap;
    RETURN w
  END NewWriter;

PROCEDURE SubclassToBasicType (subclass: Opcode.Subclass): DeclWriter.BasicTypeId;
  BEGIN
    CASE subclass OF
    | Opcode.scNone: RETURN DeclWriter.void
    | Opcode.scAddress: RETURN DeclWriter.ptr
    | Opcode.scUnsigned8: RETURN DeclWriter.uint8
    | Opcode.scUnsigned16: RETURN DeclWriter.uint16
    | Opcode.scUnsigned32: RETURN DeclWriter.uint32
    | Opcode.scUnsigned64: RETURN DeclWriter.uint64
    | Opcode.scSigned8: RETURN DeclWriter.int8
    | Opcode.scSigned16: RETURN DeclWriter.int16
    | Opcode.scSigned32: RETURN DeclWriter.int32
    | Opcode.scSigned64: RETURN DeclWriter.int64
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
          instr. opndList. ReplaceArg
              (pb. GetDeclRef (instr. opndList. arg(SSA.Address). decl));
        END;
      ELSE (* nothing to do *)
      END;
      instr := instr. nextInstr
    END;
  END Fixup;


PROCEDURE RegisterType (ctype: DeclWriter.BasicTypeId): DeclWriter.BasicTypeId;
  BEGIN
    RETURN DeclWriter.int32
  END RegisterType;

PROCEDURE WriteTypeCast (w: DeclWriter.Writer; ctype: DeclWriter.BasicTypeId);
  VAR
    rtype: DeclWriter.BasicTypeId;
  BEGIN
    rtype := RegisterType (ctype);
    IF (rtype # ctype) THEN
      w. WriteChar ("(");
      w. WriteString (w. basicType[rtype]. repr);
      w. WriteChar (")");
    END;
  END WriteTypeCast;

PROCEDURE WriteLocalDecl (w: DeclWriter.Writer;
                          pb: SSA.ProcBlock);
(**Writes local declarations of the procedure, most of all local variables.  *)
  VAR
    declMap: Dictionary.Dictionary;
    instr: SSA.Instr;
    decl: Sym.VarDecl;
    cDecl: DeclWriter.Declaration;
    
  PROCEDURE GetLocalDecl (instr: SSA.Instr): Sym.VarDecl;
    VAR
      opnd: SSA.Opnd;
      varDecl: Sym.VarDecl;
    BEGIN
      opnd := instr. opndList;
      WHILE (opnd # NIL) &
            ((opnd. class # Opnd.readDesign) &
             (opnd. class # Opnd.writeDesign)) DO
        opnd := opnd. nextOpnd;
      END;
      IF (opnd. arg IS SSA.DeclRef) THEN
        varDecl := opnd. arg(SSA.DeclRef). decl(Sym.VarDecl);
        IF (varDecl. Procedure() = pb. procDecl) THEN
          RETURN varDecl
        END;
      END;
      RETURN NIL
    END GetLocalDecl;
  
  BEGIN
    declMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) OR (instr. opcode = Opcode.set) THEN
        decl := GetLocalDecl (instr);
        IF (decl # NIL) & ~declMap. HasKey (decl) &
           ~decl. isParameter THEN
          cDecl := ConvertDecl.GetDecl (w, decl);
          w. WriteLn;
          w. WriteString ("  ");
          w. WriteDeclaration (cDecl);
          w. WriteChar (";");
          declMap. Set (decl, NIL)
        END;
      END;
      instr := instr. nextInstr
    END;
  END WriteLocalDecl;


PROCEDURE (w: Writer) Newline;
  BEGIN
    w. WriteLn;
    w. WriteString ("  ");
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
         intermediate register; the roundabout route is kind of unnatural
         for C code *)
      w. WriteConst (arg. value);

    | arg: SSA.Address DO
      name := Naming.NameOfDeclaration (arg. decl);
      WriteTypeCast (w, DeclWriter.ptr);
      IF ~(arg. decl IS Sym.VarDecl) OR
         ~(arg. decl(Sym.VarDecl). type IS Sym.Array) THEN
        (* charming C: the address of the variable is its name, all
           others need the address operator *)
        w. WriteChar ("&");
      END;
      w. WriteString (name. array^);

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
        (* nothing, handled in `Ref' *)

      | Opcode.declRef:
        (* nothing, handled in `Ref' *)
        
      | Opcode.address:
        (* nothing, handled in `Ref' *)

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
        w. WriteString (w. basicType
                        [SubclassToBasicType (instr. subclass)]. repr);
        w. WriteString ("*)");
        w. Ref (instr. opndList. nextOpnd);
        
      | Opcode.set:
        w. WriteString ("*(");
        w. WriteString (w. basicType
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
      str: ARRAY 24 OF CHAR;
      obj: Object.Object;
      nested: Schedule.Block;
    BEGIN
      IntStr.IntToStr (blockCount, str);
      Strings.Insert ("l", 0, str);
      IF b. isLoopHead THEN
        Strings.Append ("_loop", str);
      END;
      obj := String.New (str);
      blockMap. Set (b, obj);
      INC (blockCount);

      nested := b. domList;
      WHILE (nested # NIL) DO
        AssignIds (nested);
        nested := nested. nextDom
      END;
    END AssignIds;
  
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
  
  PROCEDURE FixLastJump (currentBlock: Schedule.Block);
    VAR
      d: LONGINT;
      
    PROCEDURE WriteLabel (b: Schedule.Block);
      BEGIN
        w. WriteLn;
        WriteBlockId (b);
        w. WriteChar (":");
      END WriteLabel;
    
    BEGIN
      IF (lastBlock # NIL) &
         (lastBlock. DefaultTarget() # currentBlock) THEN
        w. Newline;
        WriteGoto (lastBlock. DefaultTarget());
        d := 0;
      ELSE
        d := 1
      END;
      IF (currentBlock # NIL) & (currentBlock. degreeIn > d) THEN
        WriteLabel (currentBlock)
      END;
    END FixLastJump;
  
  PROCEDURE WriteBlock (b: Schedule.Block);
    VAR
      nested: Schedule.Block;
      
    BEGIN
      FixLastJump (b);
      w. WriteInstrList (b);
      WITH b: Schedule.BranchBlock DO
        w. Newline;
        w. WriteString ("if (");
        IF ~b. branchOnTrue THEN
          w. WriteChar("!");
        END;
        w. Ref (b. predicate);
        w. WriteString (") ");
        WriteGoto (b. branchTo. dest);
      ELSE (* standard block *)
      END;
      lastBlock := b;
      
      nested := b. domList;
      WHILE (nested # NIL) DO
        WriteBlock (nested);
        nested := nested. nextDom
      END;
    END WriteBlock;
  
  BEGIN
    blockCount := 0;
    blockMap := Dictionary.New();
    lastBlock := NIL;

    AssignIds (domRoot);
    WriteBlock (domRoot);
    FixLastJump (NIL)
  END WriteBlocks;

PROCEDURE ProcBody* (cWriter: DeclWriter.Writer;
                     procDecl: IR.Procedure);
  
  VAR
    pb: SSA.ProcBlock;
    enter: SSA.Instr;
    s: SSA.Result;
    domRoot: Schedule.Block;
    registerMap: Dictionary.Dictionary;
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
    WriteLocalDecl (cWriter, pb);
    registerMap := Allocator.AssignRegisters (pb, domRoot, cWriter);
    cWriter. WriteLn;
    w := NewWriter (cWriter, registerMap);
    w. WriteBlocks (domRoot);
  END ProcBody;

PROCEDURE ModuleBody* (w: TextRider.Writer; procDecl: IR.Procedure);
  BEGIN
  END ModuleBody;

END OOC:SSA:WriteC.
