MODULE OOC:SSA:WriteC [OOC_EXTENSIONS];

IMPORT
  IntStr, StdChannels, Strings, TextRider,
  ADT:Object, ADT:String, ADT:Dictionary,
  Sym := OOC:SymbolTable, OOC:SymbolTable:TypeRules,
  OOC:IR, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:Schedule, OOC:SSA:XML,
  OOC:SSA:DeadCodeElimination, OOC:SSA:Destore, OOC:SSA:Allocator,
  OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:DeclWriter;


TYPE
  RegisterSwap = RECORD
    source, dest: String.String;
    readCount: LONGINT;                (* number of reads of `dest' *)
    ctype: DeclWriter.BasicTypeId;     (* type of transfered value *)
  END;
  SwapArray = POINTER TO ARRAY OF RegisterSwap;
  
TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc = RECORD
    (DeclWriter.WriterDesc)
    registerMap: Dictionary.Dictionary;
    
    swapArray: SwapArray;                (* used by WriteCollect *)
    lengthSwapArray: LONGINT;            (* used by WriteCollect *)
    swapHelperVars: LONGINT;
  END;

CONST
  enableDebugOutput = FALSE;
  

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

PROCEDURE RegisterType (ctype: DeclWriter.BasicTypeId): DeclWriter.BasicTypeId;
  BEGIN
    RETURN DeclWriter.int32
  END RegisterType;


PROCEDURE NewWriter (cWriter: DeclWriter.Writer;
                     registerMap: Dictionary.Dictionary): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    cWriter. CopyTo (w);
    w. registerMap := registerMap;
    NEW (w. swapArray, 8);
    w. lengthSwapArray := 0;
    w. swapHelperVars := 0;
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) ClearSwapData;
  BEGIN
    w. lengthSwapArray := 0;
    w. swapHelperVars := 0;
  END ClearSwapData;

PROCEDURE (w: Writer) AddSwapData (source, dest: String.String;
                                   ctype: DeclWriter.BasicTypeId);
  VAR
    new: SwapArray;
    i: LONGINT;
  BEGIN
    IF (source. array^ # dest. array^) THEN (* suppress things like `i0=i0;' *)
      IF (w. lengthSwapArray = LEN (w. swapArray^)) THEN
        NEW (new, LEN (w. swapArray^)*2);
        FOR i := 0 TO LEN (w. swapArray^)-1 DO
          new[i] := w. swapArray[i]
        END;
        w. swapArray := new
      END;
      w. swapArray[w. lengthSwapArray]. source := source;
      w. swapArray[w. lengthSwapArray]. dest := dest;
      w. swapArray[w. lengthSwapArray]. ctype := ctype;
      w. swapArray[w. lengthSwapArray]. readCount := 0;
      INC (w. lengthSwapArray)
    END;
  END AddSwapData;

PROCEDURE (w: Writer) CountReadsSwapData;
  VAR
    i, j, c: LONGINT;
  BEGIN
    FOR i := 0 TO w. lengthSwapArray-1 DO
      c := 0;
      FOR j := 0 TO w. lengthSwapArray-1 DO
        IF (w. swapArray[j]. source. array^=w. swapArray[i]. dest. array^) THEN
          INC (c)
        END;
      END;
      w. swapArray[i]. readCount := c
    END;
  END CountReadsSwapData;

PROCEDURE (w: Writer) RemoveSwapData (i: LONGINT);
  VAR
    j: LONGINT;
  BEGIN
    ASSERT (w. swapArray[i]. readCount = 0);
    FOR j := 0 TO w. lengthSwapArray-1 DO
      IF (w. swapArray[j]. dest. array^=w. swapArray[i]. source. array^) THEN
        DEC (w. swapArray[j]. readCount)
      END;
    END;
    w. swapArray[i] := w. swapArray[w. lengthSwapArray-1];
    DEC (w. lengthSwapArray);
  END RemoveSwapData;

PROCEDURE (w: Writer) IntroduceHelperVar (i: LONGINT);
  VAR
    str: ARRAY 16 OF CHAR;
    j: LONGINT;
    h: String.String;
  BEGIN
    ASSERT (w. swapArray[i]. readCount # 0);
    IntStr.IntToStr (w. swapHelperVars, str);
    Strings.Insert ("h", 0, str);
    h := String.New (str);
    INC (w. swapHelperVars);
    
    FOR j := 0 TO w. lengthSwapArray-1 DO
      IF (w. swapArray[j]. source. array^=w. swapArray[i]. dest. array^) THEN
        w. swapArray[j]. source := h;
      END;
    END;
    w. swapArray[i]. readCount := 0;

    w. WriteString ("{register ");
    w. WriteString (w. basicType[RegisterType (w. swapArray[i]. ctype)]. repr);
    w. WriteString (" ");
    w. WriteString (h. array^);
    w. WriteChar ("=");
    w. WriteString (w. swapArray[i]. dest. array^);
    w. WriteChar (";");
  END IntroduceHelperVar;

PROCEDURE (w: Writer) FixupHelperVars;
  BEGIN
    WHILE (w. swapHelperVars # 0) DO
      w. WriteChar ("}");
      DEC (w. swapHelperVars)
    END;
  END FixupHelperVars;

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



PROCEDURE WriteLocalDecl (w: Writer;
                          pb: SSA.ProcBlock;
                          VAR haveCopyParameter: BOOLEAN);
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
      WITH instr: SSA.Address DO   (* copy-parameter is instance of Address *)
        RETURN instr. decl(Sym.VarDecl)
      ELSE
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
      END;
    END GetLocalDecl;
  
  BEGIN
    haveCopyParameter := FALSE;
    declMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) OR
         (instr. opcode = Opcode.set) OR
         (instr. opcode = Opcode.copyParameter) THEN
        decl := GetLocalDecl (instr);
        IF (decl # NIL) & ~declMap. HasKey (decl) THEN
          IF (instr. opcode = Opcode.copyParameter) THEN
            cDecl := ConvertDecl.GetPointerDecl (w, decl);
            haveCopyParameter := TRUE
          ELSIF ~decl. isParameter THEN
            cDecl := ConvertDecl.GetDecl (w, decl);
          ELSE
            cDecl := NIL;
          END;

          IF (cDecl # NIL) THEN
            w. Newline;
            w. WriteDeclaration (cDecl);
            w. WriteChar (";");
            declMap. Set (decl, NIL)
          END;
        END;
      END;
      instr := instr. nextInstr
    END;

    IF haveCopyParameter THEN
      w. Newline;
      w. WriteString ("OOC_PUSH_VPAR_STACK");
    END;
  END WriteLocalDecl;


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
      IF (arg. decl IS Sym.VarDecl) &
         arg. decl(Sym.VarDecl). isPassPerReference &
         ~(arg. decl(Sym.VarDecl). type IS Sym.Array) THEN
        (* deref pass-per-reference parameters, unless the parameter type
           happens to be an array *)
        w. WriteString ("*")
      END;
      w. WriteString (name. array^)

    | arg: SSA.Const DO
      (* write constant values directly, without going through an
         intermediate register; the roundabout route is kind of unnatural
         for C code *)
      w. WriteConst (arg. value);

    | arg: SSA.Address DO
      name := Naming.NameOfDeclaration (arg. decl);
      WriteTypeCast (w, DeclWriter.ptr);
      IF ~(((arg. decl IS Sym.VarDecl) &
            (arg. decl(Sym.VarDecl). type IS Sym.Array)) OR
           ((arg. decl IS Sym.VarDecl) &
            arg. decl(Sym.VarDecl). isPassPerReference)) THEN
        (* charming C: the address of the variable is its name; all
           others need the address operator unless we are looking at
           a pass by reference parameter *)
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

PROCEDURE (w: Writer) TypeRef (type: Sym.Type);
  VAR
    cType: DeclWriter.Type;
  BEGIN
    cType := ConvertDecl.GetTypeRef (w, type);
    w. WriteType (cType);
  END TypeRef;


PROCEDURE (w: Writer) WriteInstrList (b: Schedule.Block;
                                      haveCopyParameter: BOOLEAN);
  VAR
    proxy: Schedule.InstrProxy;
    instr: SSA.Instr;
    opnd: SSA.Opnd;
    target: Object.Object;
    str: ARRAY 32 OF CHAR;

  PROCEDURE ^ Call (call: SSA.Instr);
    
  PROCEDURE RefList (start: SSA.Opnd; class, castClass: Opnd.Class);
    VAR
      opnd: SSA.Opnd;
      count: LONGINT;
    BEGIN
      count := 0;
      opnd := start;
      WHILE (opnd # NIL) DO
        IF (opnd. class = class) OR (opnd. class = castClass) THEN
          IF (count # 0) THEN
            w. WriteString (", ")
          END;
          IF (opnd. class = castClass) THEN
            w. WriteString ("(void*)")
          END;
          w. Ref (opnd);
          INC (count)
        END;
        opnd := opnd. nextOpnd
      END;
    END RefList;
  
  PROCEDURE Assert (assert: SSA.Instr);
    BEGIN
      w. Newline;
      w. WriteString ("_assert(");
      RefList (assert. opndList, Opnd.arg, -1);
      w. WriteString (", ");
      w. WriteString ("0");  (* ... file position missing *)
      w. WriteString (");")
    END Assert;
  
  PROCEDURE Call (call: SSA.Instr);
    BEGIN
      w. Ref (call. opndList);
      w. WriteString ("(");
      RefList (call. opndList, Opnd.arg, Opnd.argPointer);
      w. WriteString (")")
    END Call;
  
  PROCEDURE WriteDyadicOp (instr: SSA.Instr; op: ARRAY OF CHAR);
    BEGIN
      w. Ref (instr. opndList);
      w. WriteString (op);
      w. Ref (instr. opndList. nextOpnd);
      w. WriteChar (";");
    END WriteDyadicOp;
  
  PROCEDURE GetLength (instr: SSA.Instr);
    VAR
      varDecl: SSA.Result;
      name: String.String;
    BEGIN
      (* FIXME... handle length of arrays on heap *)
      varDecl := instr. GetArgClass (Opnd.readDesign);
      name := Naming.NameOfLengthParam
          (varDecl(SSA.DeclRef). decl(Sym.VarDecl),
           instr. opndList. GetIntConst());
      w. WriteString (name. array^);
      w. WriteChar (";");
    END GetLength;

  PROCEDURE CopyParameter (instr: SSA.Address);
    VAR
      varDecl: Sym.VarDecl;
      size: SSA.Opnd;
      name: String.String;

    PROCEDURE WriteTypeAndSize ();
      BEGIN
        w. WriteString (",");
        IF (varDecl. type IS Sym.Array) THEN
          w. TypeRef (varDecl. type(Sym.Array). GetNonOpenElementType());
        ELSE
          w. TypeRef (varDecl. type);
        END;
        w. WriteString (",");
        IF (size = NIL) THEN
          w. WriteString ("1")
        ELSE
          w. Ref (size)
        END;
        w. WriteString (")");
      END WriteTypeAndSize;
    
    BEGIN
      varDecl := instr. decl(Sym.VarDecl);
      size := instr. GetOpndClass (Opnd.arg);
      name := Naming.NameOfDeclaration (varDecl);
      
      w. Newline;
      w. WriteString ("OOC_ALLOCATE_VPAR(");
      w. WriteString (name. array^);
      WriteTypeAndSize;
      
      w. Newline;
      w. WriteString ("OOC_INITIALIZE_VPAR(");
      w. WriteString (name. array^);
      w. WriteString (Naming.suffixPassPerRef+",");
      w. WriteString (name. array^);
      WriteTypeAndSize
    END CopyParameter;
  
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
      targetVar, sourceVar: Object.Object;
      i: LONGINT;
    BEGIN
      w. Newline;
      
      (* first pass: collect all copy instructions transfering from a register
         variable into another *)
      w. ClearSwapData;
      opnd := collect. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF w. registerMap. HasKey (opnd. arg) THEN
            sourceVar := w. registerMap. Get (opnd. arg);
            w. AddSwapData (sourceVar(String.String),
                            targetVar(String.String),
                            SubclassToBasicType (res. subclass))
          END;
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;

      (* second pass: write out register transfers in an order that keeps
         the number of helper variables down *)
      w. CountReadsSwapData;
      WHILE (w. lengthSwapArray # 0) DO
        i := 0;
        WHILE (i # w. lengthSwapArray) & (w. swapArray[i]. readCount # 0) DO
          INC (i)
        END;

        IF (i = w. lengthSwapArray) THEN
          w. IntroduceHelperVar (0)
        ELSE                             (* can write out assignment *)
          w. WriteString (w. swapArray[i]. dest. array^);
          w. WriteString ("=");
          w. WriteString (w. swapArray[i]. source. array^);
          w. WriteChar (";");
          w. RemoveSwapData (i)
        END;
      END;
      w. FixupHelperVars;
      
      (* final pass: write out anything that does not read from a register *)
      opnd := collect. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF ~w. registerMap. HasKey (opnd. arg) THEN
            w. WriteString (targetVar(String.String). array^);
            w. WriteString ("=");
            w. Ref (opnd);
            w. WriteChar (";");
          END
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;
    END WriteCollect;

  PROCEDURE SimpleVarAccess (instr: SSA.Instr; adrClass: Opnd.Class): BOOLEAN;
    VAR
      adr: SSA.Result;
      opnd, design: SSA.Opnd;
    BEGIN
      opnd := instr. GetOpndClass (adrClass);
      adr := opnd. arg;
      design := opnd. nextOpnd;
      IF (adr IS SSA.Address) &
         ((design. nextOpnd = NIL) OR
          (design. nextOpnd. class # design. class)) THEN
        (* if this is an access to a variable without any additional selectors
           or a type cast, then return TRUE *)
        RETURN TRUE
      ELSE
        RETURN FALSE
      END;
    END SimpleVarAccess;

  PROCEDURE PrefixReturn ();
  (**Called before every "return" instruction.  *)
    BEGIN
      w. Newline;
      IF haveCopyParameter THEN
        w. WriteString ("OOC_POP_VPAR_STACK");
        w. Newline
      END;
    END PrefixReturn;
  
  BEGIN
    proxy := b. proxyList;
    WHILE (proxy # NIL) DO
      instr := proxy. instr;

      IF enableDebugOutput THEN
        w. Newline;
        instr. GetOpcodeName (str);
        w. WriteString ("/* ");
        w. WriteString (str);
        w. WriteString (": */ ");
      END;
      
      IF w. registerMap. HasKey (instr) THEN
        w. Newline;
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
        IF SimpleVarAccess (instr, Opnd.readAdr) THEN
          w. Ref (instr. GetOpndClass (Opnd.readDesign))
        ELSE
          w. WriteString ("*(");
          w. WriteString (w. basicType
                          [SubclassToBasicType (instr. subclass)]. repr);
          w. WriteString ("*)");
          w. Ref (instr. opndList. nextOpnd);
        END;
        w. WriteChar (";");
        
      | Opcode.set:
        w. Newline;
        IF SimpleVarAccess (instr, Opnd.writeAdr) THEN
          w. Ref (instr. GetOpndClass (Opnd.writeDesign))
        ELSE
          w. WriteString ("*(");
          w. WriteString (w. basicType
                          [SubclassToBasicType (instr. subclass)]. repr);
          w. WriteString ("*)");
          w. Ref (instr. opndList. nextOpnd);
        END;
        w. WriteString (" = ");
        w. Ref (instr. GetOpndClass (Opnd.sourceValue));
        w. WriteChar (";");

      | Opcode.getLength:
        GetLength (instr);
        
      | Opcode.copyParameter:
        CopyParameter (instr(SSA.Address));
        
      | Opcode.add:
        WriteDyadicOp (instr, "+");
        
      | Opcode.negate:
        w. WriteChar ("-");
        w. Ref (instr. opndList);
        w. WriteChar (";");
        
      | Opcode.eql:
        WriteDyadicOp (instr, "==");
      | Opcode.neq:
        WriteDyadicOp (instr, "!=");
        
      | Opcode.assert:
        Assert (instr)
            
      | Opcode.call:
        IF ~w. registerMap. HasKey (instr) THEN
          w. Newline
        END;
        Call (instr);
        w. WriteChar (";");
            
      | Opcode.return:
        PrefixReturn;
        opnd := instr. GetOpndClass (Opnd.functionResult);
        IF (opnd # NIL) THEN
          w. WriteString ("return ");
          w. Ref (opnd);
          w. WriteChar (";");
        ELSE
          w. WriteString ("return;")
        END;
        
      | Opcode.selectReturn:
        IF ~AllPathsClosed (instr) THEN
          PrefixReturn;
          w. WriteString ("return;")
        END;
      END;
      
      proxy := proxy. nextProxy
    END;
  END WriteInstrList;

PROCEDURE (w: Writer) WriteBlocks (domRoot: Schedule.Block;
                                   haveCopyParameter: BOOLEAN);
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
      w. WriteInstrList (b, haveCopyParameter);
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
                     tr: TypeRules.Rules;
                     procDecl: IR.Procedure);
  
  VAR
    pb: SSA.ProcBlock;
    enter: SSA.Instr;
    s: SSA.Result;
    domRoot: Schedule.Block;
    registerMap: Dictionary.Dictionary;
    w: Writer;
    haveCopyParameter: BOOLEAN;
  BEGIN
    pb := SSA.NewProcBlock (procDecl. decl);
    enter := pb. selectReturn. opndList. arg. instr;
    s := IRtoSSA.StatmSeq (pb, enter. nextResult,
                           procDecl. statmSeq);
    pb. selectReturn. AddOpnd (s, Opnd.store);

    (* code transformations *)
    DeadCodeElimination.Transform (pb);
    Destore.Transform (pb, tr);
    DeadCodeElimination.Transform (pb);

    (* write SSA code to stdout, both in native and scheduled format *)
    XML.Write (StdChannels.stdout. NewWriter(), pb, TRUE);
    domRoot := Schedule.Schedule (pb);
    XML.WriteSchedule (StdChannels.stdout. NewWriter(), domRoot);
    
    Fixup (pb);
    registerMap := Allocator.AssignRegisters (pb, domRoot, cWriter);
    w := NewWriter (cWriter, registerMap);
    w. Indent (1);
    WriteLocalDecl (w, pb, haveCopyParameter);
    w. WriteLn;
    w. WriteBlocks (domRoot, haveCopyParameter);
    w. Indent (-1);
  END ProcBody;

PROCEDURE ModuleBody* (w: TextRider.Writer; procDecl: IR.Procedure);
  BEGIN
  END ModuleBody;

END OOC:SSA:WriteC.
