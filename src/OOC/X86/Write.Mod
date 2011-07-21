MODULE OOC:X86:Write;

IMPORT
  Log, D := OOC:X86:Debug,
  SYSTEM, Ascii, Object, Object:Boxed, Object:BigInt,
  ADT:Dictionary, ADT:ArrayList, ADT:StringBuffer, IO, IO:TextRider,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  OOC:C:Naming, S := OOC:X86:SSA, OOC:X86:RuntimeData;

TYPE
  Arc = POINTER TO ArcDesc;
  Block = POINTER TO BlockDesc;
  ArcDesc = RECORD
    from, to: Block;
    type: S.Type;
    opcode: S.Opcode;
    nextIncoming: Arc;
  END;
  BlockDesc = RECORD
    (Object.ObjectDesc)
    instructions: StringBuffer.StringBuffer;
    incomingList: Arc;
    branch, jump: Arc;
    blockInstr: S.Block;
    label: LONGINT;
  END;
  
TYPE
  Writer* = POINTER TO WriterDesc;
  StringToLabel = Dictionary.Dictionary(STRING, STRING);
  WriterDesc = RECORD
    module: Sym.Module;
    w: TextRider.Writer;
    blocks: ArrayList.ArrayList(Block);
    blockMap: Dictionary.Dictionary(S.Block, Block);
    blockCount: LONGINT;

    strings: ARRAY 3 OF StringToLabel;
    stringList: ARRAY 3 OF ArrayList.ArrayList(STRING);
    
    (* current function: *)
    fctBlock: S.FunctionBlock;
    name: STRING;
    labelExit: STRING;
  END;
  
CONST
  nl = Ascii.lf;
  tab = Ascii.ht;
  nlTab = nl+tab;

CONST  (* taken from gcc 3.4.0 with -march=k8 *)
  padFunction = nlTab+".p2align 4,,15";


PROCEDURE (block: Block) INIT*(blockInstr: S.Block);
  BEGIN
    block.instructions := NIL;
    block.incomingList := NIL;
    block.branch := NIL;
    block.jump := NIL;
    block.blockInstr := blockInstr;
    block.label := 0;
  END INIT;

PROCEDURE (block: Block) IsEmpty(): BOOLEAN;
  BEGIN
    RETURN (block.branch = NIL) & (block.instructions.length = 0);
  END IsEmpty;

PROCEDURE AddToIncoming(block: Block; arc: Arc);
  BEGIN
    arc.to := block;
    arc.nextIncoming := block.incomingList;
    block.incomingList := arc;
  END AddToIncoming;

PROCEDURE (block: Block) SetArc(VAR arc: Arc; to: Block;
                                type: S.Type; opcode: S.Opcode);
  BEGIN
    ASSERT(arc = NIL);
    NEW(arc);
    arc.from := block;
    arc.type := type;
    arc.opcode := opcode;
    AddToIncoming(to, arc);
  END SetArc;

PROCEDURE RemoveFromIncoming(arc: Arc);
  VAR
    block: Block;
    ptr: Arc;
  BEGIN
    block := arc.to;
    IF (block.incomingList = arc) THEN
      block.incomingList := arc.nextIncoming;
    ELSE
      ptr := block.incomingList;
      WHILE (ptr.nextIncoming # arc) DO
        ptr := ptr.nextIncoming;
      END;
      ptr.nextIncoming := arc.nextIncoming;
    END;
    arc.to := NIL;
  END RemoveFromIncoming;

PROCEDURE ClearArc(VAR arc: Arc);
  BEGIN
    RemoveFromIncoming(arc);
    arc := NIL;
  END ClearArc;

PROCEDURE (arc: Arc) ReplaceTo(to: Block);
  BEGIN
    RemoveFromIncoming(arc);
    AddToIncoming(to, arc);
  END ReplaceTo;

PROCEDURE NegateBranch(opcode: S.Opcode): S.Opcode;
  BEGIN
    CASE opcode OF
    | S.eql: RETURN S.neq;
    | S.neq: RETURN S.eql;
    | S.lss: RETURN S.geq;
    | S.leq: RETURN S.gtr;
    | S.gtr: RETURN S.leq;
    | S.geq: RETURN S.lss;
    END;
  END NegateBranch;

PROCEDURE OpcodeCC(type: S.Type; opcode: S.Opcode): STRING;
  VAR
    str: STRING;
  BEGIN
    IF (opcode = S.jump) THEN            (* unconditional jump *)
      str := "mp";
    ELSIF (type < S.unsigned8) THEN (* signed compare *)
      CASE opcode OF
      | S.eql: str := "e";
      | S.neq: str := "ne";
      | S.lss: str := "l";
      | S.leq: str := "le";
      | S.gtr: str := "g";
      | S.geq: str := "ge";
      END;
    ELSE                           (* unsigned compare *)
      CASE opcode OF
      | S.eql: str := "e";
      | S.neq: str := "ne";
      | S.lss: str := "b";
      | S.leq: str := "be";
      | S.gtr: str := "a";
      | S.geq: str := "ae";
      END;
    END;
    RETURN str;
  END OpcodeCC;

PROCEDURE WriteArc(w: TextRider.Writer; arc: Arc);
  BEGIN
    IF (arc # NIL) &
       ((arc.opcode # S.jump) OR (arc.to.label # arc.from.label+1)) THEN
      w.WriteObject(nlTab+"j"+OpcodeCC(arc.type, arc.opcode)+" .L");
      w.WriteLInt(arc.to.label, 0);
    END;
  END WriteArc;

PROCEDURE (w: Writer) INIT*(module: Sym.Module; ch: IO.ByteChannel);
  VAR
    i: LONGINT;
  BEGIN
    w.module := module;
    w.w := TextRider.ConnectWriter(ch);
    w.w.WriteString(tab+".arch athlon");
    w.blockCount := 0;

    FOR i := 0 TO 2 DO
      w.strings[i] := NEW(StringToLabel);
      w.stringList[i] := NEW(ArrayList.ArrayList(STRING), 8);
    END;
  END INIT;

PROCEDURE (w: Writer) GetBlock(b: S.Block): Block;
  VAR
    block: Block;
  BEGIN
    IF w.blockMap.HasKey(b) THEN
      RETURN w.blockMap.Get(b);
    ELSE
      block := NEW(Block, b);
      w.blockMap.Set(b, block);
      RETURN block;
    END;
  END GetBlock;

PROCEDURE (w: Writer) RuntimeData();
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := NEW(StringBuffer.StringBuffer, 2048);
    RuntimeData.Write(sb, w.module);
    w.w.WriteObject(sb);
  END RuntimeData;

PROCEDURE (w: Writer) ModuleVariables();
  VAR
    item: Sym.Item;
    name: STRING;
  BEGIN
    item := w.module.nestedItems;
    WHILE (item # NIL) DO
      WITH item: Sym.VarDecl DO
        name := Naming.NameOfDeclaration(item);
        IF (item.exportMark = Sym.nameNotExported) THEN
          w.w.WriteObject(nlTab+".local "+name);
        END;
        w.w.WriteObject(nlTab+".comm "+name+",");
        w.w.WriteLInt(item.type.size, 0);
      ELSE
        (* ignore *)
      END;
      item := item.nextNested;
    END;
  END ModuleVariables;

PROCEDURE (w: Writer) StringSymbol(value: STRING; type: Sym.PredefId): STRING;
  VAR
    dict: StringToLabel;
    array: ArrayList.ArrayList(STRING);
  BEGIN
    ASSERT(type = Predef.stringChar);
    dict := w.strings[type-Predef.stringChar];
    array := w.stringList[type-Predef.stringChar];
    IF ~dict.HasKey(value) THEN
      dict.Set(value, ".LS"+Boxed.IntToString(array.size));
      array.Append(value);
    END;
    RETURN dict.Get(value);
  END StringSymbol;

PROCEDURE (w: Writer) StringConstants();
  VAR
    s, i: LONGINT;
    value, label: STRING;
  BEGIN
    FOR s := 0 TO 2 DO
      FOR i := 0 TO w.stringList[s].size-1 DO
        ASSERT(s = 0);
        value := w.stringList[s].array[i];
        label := w.strings[s].Get(value);
        w.w.WriteObject(nl+label+":");
        w.w.WriteObject(nlTab+'.string "'+value+'"'); (* FIXME... needs to be quoted *)
      END;
    END;
  END StringConstants;

PROCEDURE (w: Writer) EndFile*();
  VAR
    name0, name: STRING;
    
  BEGIN
    name0 := Naming.NameOfModuleInit(w.module, TRUE);
    name := Naming.NameOfModuleInit(w.module, FALSE);
    w.w.WriteObject(nl+".global "+name0);
    w.w.WriteObject(nlTab+".type "+name0+", @function");
    w.w.WriteObject(nl+name0+":");
    w.w.WriteObject(nlTab+"call "+name);
    w.w.WriteObject(nlTab+"ret");
    w.w.WriteObject(nlTab+".size "+name0+", .-"+name0);

    w.RuntimeData();
    w.ModuleVariables();
    w.StringConstants();
    
    w.w.WriteString(nl);
  END EndFile;

PROCEDURE (w: Writer) WriteBlock(b: S.Block): Block;
  VAR
    instr, nextInstr, cmp: S.Instr;
    type: S.Type;
    str: STRING;
    sb: StringBuffer.StringBuffer;
    block, dummy: Block;
    opnd: S.Opnd;
    qtdData: Naming.QualTypeData;
    merge: S.MergeInstr;
    
    opndWidth: S.Type;
    (* Operand/result size of the operation.  Defaults to the type of the
       operation's result.  Operations that produce no result, or whose operand
       width differs from the result's size override the default.  This value
       is used as type by @oproc{Opc} and @oproc{Reg}.  *)
    
  PROCEDURE OpcTT(opc[NO_COPY]: ARRAY OF CHAR; type1, type2: S.Type);
  (* Opcode with zero, one, or two type suffixes.  *)
    VAR
      suffix: ARRAY 3 OF CHAR;

    PROCEDURE Type(type: S.Type): CHAR;
      BEGIN
        CASE type OF
        | S.noType:
          RETURN 0X;
        | S.signed8, S.unsigned8:
          RETURN "b";
        | S.signed16, S.unsigned16:
          RETURN "w";
        | S.signed32, S.unsigned32, S.real32, S.address:
          RETURN "l";
        | S.signed64, S.unsigned64:
          RETURN "q";
        END;
      END Type;
    
    BEGIN
      sb.AppendLatin1(nlTab);
      sb.AppendLatin1(opc);
      suffix[0] := Type(type1);
      suffix[1] := Type(type2);
      suffix[2] := 0X;
      sb.AppendLatin1(suffix);
      sb.AppendLatin1(" ");
    END OpcTT;

  PROCEDURE Opc0(opc[NO_COPY]: ARRAY OF CHAR);
  (* Opcode without any (or any additional) type suffix.  *)
    BEGIN
      OpcTT(opc, S.noType, S.noType);
    END Opc0;

  PROCEDURE Opc(opc[NO_COPY]: ARRAY OF CHAR);
  (* Opcode with type suffix taken from @ovar{opndWidth}.  *)
    BEGIN
      OpcTT(opc, opndWidth, S.noType);
    END Opc;

  PROCEDURE RegT(reg: S.Register; type: S.Type);
    VAR
      str: ARRAY 8 OF CHAR;
    BEGIN
      CASE type OF
      | S.signed8, S.unsigned8:
        (* note: some register's low-level byte cannot be addressed *)
        CASE reg OF
        | S.gp0: str := "%al";
        | S.gp1: str := "%cl";
        | S.gp2: str := "%dl";
        | S.gp3: str := "%bl";
        (*| S.gp4: str := "%si"; no such thing in x86 *)
        (*| S.gp5: str := "%di"; no such thing in x86 *)
        END;
      | S.signed16, S.unsigned16:
        CASE reg OF
        | S.sp: str := "%sp";
        | S.fp: str := "%bp";
        | S.gp0: str := "%ax";
        | S.gp1: str := "%cx";
        | S.gp2: str := "%dx";
        | S.gp3: str := "%bx";
        | S.gp4: str := "%si";
        | S.gp5: str := "%di";
        END;
      | S.signed32, S.unsigned32, S.real32, S.address:
        CASE reg OF
        | S.sp: str := "%esp";
        | S.fp: str := "%ebp";
        | S.gp0: str := "%eax";
        | S.gp1: str := "%ecx";
        | S.gp2: str := "%edx";
        | S.gp3: str := "%ebx";
        | S.gp4: str := "%esi";
        | S.gp5: str := "%edi";
        END;
      END;
      sb.AppendLatin1(str);
    END RegT;

  PROCEDURE RegAdr(reg: S.Register);
  (* Register reference with address size.  *)
    BEGIN
      RegT(reg, S.address);
    END RegAdr;
  
  PROCEDURE Reg(reg: S.Register);
  (* Register reference with size `opndWidth'.  *)
    BEGIN
      RegT(reg, opndWidth);
    END Reg;
  
  PROCEDURE Comma();
    BEGIN
      sb.AppendLatin1(", ");
    END Comma;
  
  PROCEDURE Literal(instr: S.Instr);
    VAR
      s: S.Selector;
      value: Boxed.Object;
      i: LONGINT;

    PROCEDURE ToHex(n: LONGINT; digits: LONGINT): STRING;
      CONST
        BASE=16;
      VAR
        dig, shift, i: LONGINT;
        str: ARRAY 16 OF CHAR;
      BEGIN
        shift := -4*digits;
        FOR i := 0 TO digits-1 DO
          INC(shift, 4);
          dig := ASH(n, shift) MOD BASE;
          IF (dig <= 9) THEN
            str[i] := CHR(ORD("0") + dig);
          ELSE
            str[i] := CHR(ORD("A") - 10 + dig);
          END;
        END;
        RETURN Object.NewLatin1Region(str, 0, digits);
      END ToHex;
    
    BEGIN
      FOR i := 0 TO LEN(instr.designator^)-1 DO
        IF (i # 0) THEN
          sb.AppendLatin1Char("+");
        END;
        
        s := instr.designator[i];
        WITH s: S.Const DO
          value := s.value;
          type := instr.resultList.type;
          IF (s.type >= 0) THEN          (* string constant *)
            sb.Append(w.StringSymbol(value(Boxed.String).value, s.type));
          ELSIF (value = NIL) THEN
            sb.Append("0");
          ELSE
            WITH value: Boxed.String DO
              sb.AppendInt(ORD(value.value.CharAt(0)));
            | value: Boxed.Set DO
              sb.AppendInt(value.ToLongInt());
            | value: Boxed.LongReal DO
              sb.Append("0x");
              sb.Append(ToHex(SYSTEM.VAL(LONGINT, SHORT(value.value)), 8));
            ELSE
              sb.Append(s.value);
            END;
          END;
        | s: S.Var DO
          IF s.IsGlobalVar() THEN
            sb.Append(Naming.NameOfDeclaration(s.decl));
          ELSE
            sb.AppendInt(w.fctBlock.Offset(s.decl));
          END;
        | s: S.Proc DO
          sb.Append(Naming.NameOfDeclaration(s.decl));
        | s: S.ProcName DO
          sb.Append(s.name);
        | s: S.TypeDescr DO
          sb.Append(Naming.NameOfTypeDescriptor(s.type, qtdData));
        | s: S.ModuleDescr DO
          sb.Append("_mid");
        END;
      END;
    END Literal;
  
  PROCEDURE Result(res: S.Result);
    BEGIN
      CASE res.adrMode OF
      | S.register:
        Reg(res.register);
      END;
    END Result;

  PROCEDURE OpndMem(opnd: S.Opnd);
    BEGIN
      sb.AppendLatin1Char("(");
      RegAdr(opnd.arg.register);
      sb.AppendLatin1Char(")");
    END OpndMem;

  PROCEDURE Opnd(opnd: S.Opnd);
    VAR
      argInstr1, argInstr2: S.Instr;

    PROCEDURE Offset(arg1, arg2: S.Result);
      BEGIN
        IF (arg2.instr.opcode = S.const) THEN
          Literal(arg2.instr);
          sb.AppendLatin1Char("(");
          RegAdr(arg1.register);
          sb.AppendLatin1Char(")");
        ELSIF (arg1.instr.opcode = S.const)  THEN
          Offset(arg2, arg1);
        ELSE
          sb.AppendLatin1Char("(");
          RegAdr(arg1.register);
          sb.AppendLatin1Char(",");
          RegAdr(arg2.register);
          sb.AppendLatin1Char(")");
        END;
      END Offset;
    
    BEGIN
      IF opnd.immediate THEN
        argInstr1 := opnd.arg.instr;
        CASE argInstr1.opcode OF
        | S.const:
          sb.AppendLatin1Char("$");
          Literal(argInstr1);
        | S.add:           (* address is register plus displacement *)
          Offset(argInstr1.opndList.arg,
                 argInstr1.opndList.nextOpnd.arg);
        | S.get:
          argInstr2 := argInstr1.opndList.arg.instr;
          IF (argInstr2.opcode = S.const) THEN
            Literal(argInstr2);
          ELSIF argInstr1.opndList.immediate THEN
            Opnd(argInstr1.opndList);
          ELSE
            OpndMem(argInstr1.opndList);
          END;
        END;
      ELSE
        Result(opnd.arg);
      END;
    END Opnd;

  PROCEDURE DirectOpnd(opnd: S.Opnd);
    VAR
      argInstr: S.Instr;
    BEGIN
      argInstr := opnd.arg.instr;
      IF (argInstr.opcode = S.const) THEN
        Literal(argInstr);
      ELSE
        Opnd(opnd);
      END;
    END DirectOpnd;
  
  PROCEDURE AssertResultMatch(opnd: S.Opnd);
    BEGIN
      ASSERT(opnd.instr.resultList.SameLocation(opnd.arg));
    END AssertResultMatch;

  PROCEDURE FixGatedValues(jump: S.Instr);
    TYPE
      IO = RECORD in: S.Opnd; out: S.Result END;
    VAR
      merge: S.Block;
      io: POINTER TO ARRAY OF IO;
      opnd: S.Opnd;
      i, j, len: LONGINT;
    BEGIN
      merge := jump.MergingTarget();
      NEW(io, merge.Count(S.gate));
      i := 0;
      FOR opnd IN jump.GateOperands() DO
        io[i].in := opnd;
        io[i].out := opnd.instr.resultList;
        INC(i);
      END;

      (* pass 1: eliminate all moves from and to the same location *)
      len := i; i := 0;
      WHILE (i # len) DO
        IF io[i].in.arg.SameLocation(io[i].out) THEN
          io[i] := io[len-1];
          DEC(len);
        ELSE
          INC(i);
        END;
      END;
      
      (* pass 2: do moves to output locations that do not appear as inputs;
         note that any given output location only appears once *)
      i := 0;
      WHILE (i # len) DO
        j := 0;
        WHILE (j # len) & ~io[i].out.SameLocation(io[j].in.arg) DO
          INC(j);
        END;
        IF (j = len) THEN  (* can clobber old value of location *)
          (* FIXME... mem/mem does not work *)
          opndWidth := io[i].out.type;
          Opc("mov");
          Opnd(io[i].in);
          Comma();
          Result(io[i].out);
          io[i] := io[len-1];
          DEC(len);
        ELSE
          INC(i);
        END;
      END;

      IF (len # 0) THEN
        (* pass 3: perform cyclical exchange of values; note that in addition
           to all outputs, here all input locations only appear once *)
        ASSERT(len = 2);
        (* ... FIXME need to deal with general case of n-tuple permutation, and
           with multiple permutations*)
        (* FIXME... mem/mem does not work *)
        (* FIXME... only use xchg for reg/reg to avoid LOCK *)
        opndWidth := io[0].out.type;
        Opc("xchg");
        Opnd(io[0].in);
        Comma();
        Result(io[0].out);
      END;
    END FixGatedValues;

  PROCEDURE WriteBranch2(cmp: S.Instr; neg: BOOLEAN; path1, path2: S.Block);
    VAR
      opc: S.Opcode;
      dummy: Block;
    BEGIN
      opc := cmp.opcode;
      IF (opc = S.const) THEN      (* condition with constant guard *)
        IF (neg # cmp.resultList.IsTrue()) THEN
          block.SetArc(block.jump, w.GetBlock(path2), -1, S.jump);
        ELSE
          block.SetArc(block.jump, w.GetBlock(path1), -1, S.jump);
        END;
      ELSE
        IF neg THEN opc := NegateBranch(opc); END;
        block.SetArc(block.branch, w.GetBlock(path2),
                     cmp.opndList.arg.type, opc);
        block.SetArc(block.jump, w.GetBlock(path1), -1, S.jump);
      END;
      dummy := w.WriteBlock(path1);
      dummy := w.WriteBlock(path2);
    END WriteBranch2;

  PROCEDURE WriteMerge(instr: S.MergeInstr);
    VAR
      dummy: Block;
    BEGIN
      dummy := w.WriteBlock(instr);
      
      block := NEW(Block, NIL);
      dummy.SetArc(dummy.jump, block, -1, S.jump);
      sb := NEW(StringBuffer.StringBuffer, 1024);
      block.instructions := sb;
      w.blocks.Append(block);
    END WriteMerge;
  
  PROCEDURE MovMemReg(fromMemReg: S.Opnd; fromType: S.Type;
                      valueOpnd: BOOLEAN; toReg: S.Result);
  (* Move from memory or register to register.  If source type `fromType' and
     destinataion type differ, then extend the value accordingly.

     If `valueOpnd' is TRUE, then `fromMemReg' does designate a value, instead
     of a memory address.  In this case, it may be a register or immediate
     operand, and the value is copied into the output register.  *)
    VAR
      toType: S.Type;
    BEGIN
      toType := toReg.type;
      IF (fromType = toType) THEN
        IF valueOpnd & (toReg.register = fromMemReg.arg.register) THEN
          RETURN;                        (* copy register onto itself *)
        END;
        OpcTT("mov", fromType, S.noType);
      ELSIF (toType < S.unsigned8) THEN  (* to signed type *)
        OpcTT("movs", fromType, toType);
      ELSE                               (* to unsigned type *)
        OpcTT("movz", fromType, toType);
      END;
      
      opndWidth := fromType;
      IF valueOpnd THEN
        Opnd(instr.opndList);
      ELSE
        IF fromMemReg.immediate THEN
          DirectOpnd(fromMemReg);
        ELSE
          OpndMem(fromMemReg);
        END;
      END;
      Comma();
      RegT(toReg.register, toType);
    END MovMemReg;
  
  BEGIN
    qtdData := NIL;
    sb := NEW(StringBuffer.StringBuffer, 1024);
    block := w.GetBlock(b);
    block.instructions := sb;
    w.blocks.Append(block);

    instr := b.instrList;
    WHILE (instr # NIL) DO
      nextInstr := instr.nextInstr;
      IF instr.IsLive() THEN
        (*sb.Append(nl+"# "+D.Label(instr));*)
        IF (instr.resultList # NIL) THEN
          opndWidth := instr.resultList.type;
        ELSE
          opndWidth := S.noType;
        END;
        
        CASE instr.opcode OF
          (* arithmetic *)
        | S.const:
          type := instr.resultList.type;
          Opc("mov");
          sb.AppendLatin1Char("$");
          Literal(instr);
          Comma();
          Result(instr.resultList);
        | S.add:
          IF BigInt.one.Equals(instr.opndList.nextOpnd.arg.GetConst()) THEN
            Opc("inc");
          ELSE
            Opc("add");
            Opnd(instr.opndList.nextOpnd);
            Comma();
          END;
          Result(instr.resultList);
          AssertResultMatch(instr.opndList);
        | S.sub, S.allocateStack:
          IF (instr.opcode = S.allocateStack) THEN
            sb.AppendLatin1(nlTab+"pushl %edi");
            sb.AppendLatin1(nlTab+"pushl %esi");
            sb.AppendLatin1(nlTab+"pushl %ebx");
          END;
          IF BigInt.one.Equals(instr.opndList.nextOpnd.arg.GetConst()) THEN
            Opc("dec");
          ELSE
            Opc("sub");
            Opnd(instr.opndList.nextOpnd);
            Comma();
          END;
          Result(instr.resultList);
          AssertResultMatch(instr.opndList);

        | S.mul:
          Opc("imul");
          Opnd(instr.opndList.nextOpnd);
          Comma();
          Result(instr.resultList);
          AssertResultMatch(instr.opndList);
        | S.neg:
          Opc("neg");
          Opnd(instr.opndList);
          AssertResultMatch(instr.opndList);
        | S.eql, S.neq, S.lss, S.leq, S.gtr, S.geq:
          opndWidth := instr.opndList.arg.type;
          Opc("cmp");
          Opnd(instr.opndList.nextOpnd);
          Comma();
          Opnd(instr.opndList);
        | S.setBool:
          cmp := instr.opndList.arg.instr;
          str := "set"+OpcodeCC(cmp.opndList.arg.type, cmp.opcode)+" ";
          sb.Append(str);
          Opnd(instr.opndList);
          
          (* function framing *)
        | S.enter:
          (* nothing *)
        | S.exit:
          Opc0("ret");
        | S.call:
          Opc0("call");
          DirectOpnd(instr.opndList);
        | S.leave:
          (* undo local variables and call arguments: *)
          sb.Append(nl+w.labelExit+":");
          sb.AppendLatin1(nlTab+"lea -12(%ebp), %esp");
          sb.AppendLatin1(nlTab+"popl %ebx");
          sb.AppendLatin1(nlTab+"popl %esi");
          sb.AppendLatin1(nlTab+"popl %edi");
          Opc0("leave");
          
          (* memory *)
        | S.copy, S.typeConv:
          (* prevent zero or sign extension when switching between integer
             and address type *)
          IF (instr.resultList.type = S.address) &
             ((instr.opndList.arg.type = S.signed32) OR
              (instr.opndList.arg.type = S.unsigned32)) THEN
            type := S.address;
          ELSIF (instr.opndList.arg.type = S.address) &
                ((instr.resultList.type = S.signed32) OR
                 (instr.resultList.type = S.unsigned32)) THEN
            type := instr.resultList.type;
          ELSE
            type := instr.opndList.arg.type;
          END;
          MovMemReg(instr.opndList, type, TRUE, instr.resultList);
        | S.return:
          MovMemReg(instr.opndList, instr.opndList.arg.type, TRUE,
                    instr.resultList);
          Opc0("jmp");
          sb.Append(w.labelExit);
        | S.get:
          MovMemReg(instr.opndList, instr.resultList.type, FALSE,
                    instr.resultList);
        | S.set:
          opndWidth := instr.opndList.nextOpnd.arg.type;
          Opc("mov");
          Opnd(instr.opndList.nextOpnd);
          Comma();
          IF instr.opndList.immediate THEN
            DirectOpnd(instr.opndList);
          ELSE
            OpndMem(instr.opndList);
          END;
        | S.push:
          opndWidth := instr.opndList.nextOpnd.arg.type;
          Opc("push");
          Opnd(instr.opndList.nextOpnd);
        | S.setStack:
          opnd := instr.NthOpnd(2);
          opndWidth := opnd.arg.type;
          Opc("mov");
          Opnd(opnd);
          sb.Append(", ");
          Literal(instr.opndList.nextOpnd.arg.instr);
          sb.Append("(%esp)");
        | S.typeTag:
          Opc("mov");
          sb.Append("-4(");
          Opnd(instr.opndList);
          sb.Append(")");
          Comma();
          Result(instr.resultList);
          
          (* control flow *)
        | S.branch:                      (* handled below *)
        | S.jump, S.loopExit:
          FixGatedValues(instr);
          block.SetArc(block.jump, w.GetBlock(instr.MergingTarget()),
                       -1, S.jump);
          nextInstr := NIL;              (* bail out *)
        | S.gate:                        (* nothing to do *)
        | S.loopStart:
          FixGatedValues(instr);
        | S.loopBackedge:
          FixGatedValues(instr);
          block.SetArc(block.jump,
                       w.GetBlock(instr(S.LoopBackedgeInstr).start),
                       -1, S.jump);
        | S.loopEnd:
          (* nothing *)
        END;
      END;
      
      WITH instr: S.BranchInstr DO
        cmp := instr.opndList.arg.instr;
        IF (instr.paths[0](S.MergeInstr).jumps # NIL) THEN
          WriteBranch2(cmp, FALSE, instr.paths[1], instr.paths[0]);
        ELSE
          WriteBranch2(cmp, TRUE, instr.paths[0], instr.paths[1]);
        END;

        merge := instr.instrTail(S.MergeInstr);
        IF (merge.opcode = S.merge) THEN
          WriteMerge(merge);
        END;
      | instr: S.MergeInstr DO
        ASSERT(instr.opcode = S.loopEnd);
        WriteMerge(instr);
      | instr: S.LoopStartInstr DO
        dummy := w.WriteBlock(instr);
      | instr: S.Block DO
        Log.Type("instr", instr);
        D.Log("instr", instr);
        ASSERT(FALSE);
      ELSE
        (* nothing *)
      END;
      instr := nextInstr;
    END;
    RETURN block;
  END WriteBlock;

PROCEDURE (w: Writer) WriteFunction*(b: S.FunctionBlock);
  VAR
    dummy: Block;
    
  PROCEDURE StartFunction(fctBlock: S.FunctionBlock): STRING;
    PROCEDURE IsGlobal(procDecl: Sym.ProcDecl): BOOLEAN;
      BEGIN
        RETURN (procDecl.exportMark # Sym.nameNotExported) OR
            (procDecl.tbProcIndex >= 0);
      END IsGlobal;
    
    BEGIN
      w.blockMap := NEW(Dictionary.Dictionary(S.Block, Block));
      w.blocks := NEW(ArrayList.ArrayList(Block), 16);
      w.fctBlock := fctBlock;
      IF (fctBlock.procDecl.procAST = NIL) THEN
        w.name := Naming.NameOfModuleInit(w.module, FALSE);
      ELSE        
        w.name := Naming.NameOfDeclaration(fctBlock.procDecl);
      END;
      
      w.w.WriteObject(padFunction);
      IF IsGlobal(fctBlock.procDecl) THEN
        w.w.WriteObject(nl+".global "+w.name);
      END;
      w.w.WriteObject(nlTab+".type "+w.name+", @function");
      w.w.WriteObject(nl+w.name+":");

      RETURN ".LE_"+w.name;
    END StartFunction;
  
  PROCEDURE EndFunction();
    VAR
      i: LONGINT;
      block, nextBlock: Block;
      incoming, next: Arc;
    BEGIN
      FOR i := 0 TO w.blocks.size-1 DO
        block := w.blocks.array[i];
        IF block.IsEmpty() THEN
          ASSERT(block.jump # NIL);
          nextBlock := block.jump.to;
          
          incoming := block.incomingList;
          WHILE (incoming # NIL) DO
            next := incoming.nextIncoming;
            incoming.ReplaceTo(nextBlock);
            incoming := next;
          END;
        END;
      END;

      (* block 0 is function entry point *)
      w.blocks.array[0].label := w.blockCount;
      INC(w.blockCount);
      FOR i := 1 TO w.blocks.size-1 DO
        block := w.blocks.array[i];
        IF (block.incomingList = NIL) THEN
          ASSERT(block.branch = NIL);
          IF (block.jump # NIL) THEN
            ClearArc(block.jump);
          END;
          block.label := -1;
        ELSE
          block.label := w.blockCount;
          INC(w.blockCount);
        END;
      END;
      
      FOR i := 0 TO w.blocks.size-1 DO
        block := w.blocks.array[i];
        IF (block.incomingList # NIL) THEN
          w.w.WriteString(nl+".L");
          w.w.WriteLInt(block.label, 0);
          w.w.WriteString(":");
        END;
        w.w.WriteObject(block.instructions);

        IF (block.branch # NIL) & (block.branch.to.label = block.label+1) THEN
          (* switch target of branch and jump, so that the jump can be
             omitted *)
          nextBlock := block.branch.to;
          block.branch.ReplaceTo(block.jump.to);
          block.jump.ReplaceTo(nextBlock);
          block.branch.opcode := NegateBranch(block.branch.opcode);
        END;
        WriteArc(w.w, block.branch);
        WriteArc(w.w, block.jump);
      END;
      w.w.WriteObject(nlTab+".size "+w.name+", .-"+w.name);
    END EndFunction;
  
  BEGIN
    w.labelExit := StartFunction(b);
    dummy := w.WriteBlock(b);
    EndFunction();
  END WriteFunction;

END OOC:X86:Write.
