MODULE OOC:X86:Debug;

IMPORT
  Object, Object:Boxed, ADT:Dictionary, IO:TextRider, IO:StdChannels, Out,
  L := Log, OOC:C:Naming, S := OOC:X86:SSA, M := OOC:X86:Machine;

TYPE
  Output = POINTER TO OutputDesc;
  OutputDesc = RECORD
    b: S.Block;
    name: STRING;
    codeDict: Dictionary.Dictionary(S.Instr, STRING);
    codeCount: LONGINT;
  END;

TYPE
  State = POINTER TO StateDesc;
  StateDesc = RECORD
    (Object.ObjectDesc)
    block: S.Block;
    instr: S.Instr;
    controlCP: S.Instr;
    reg: ARRAY S.lastRegister+1 OF S.Result;

    mergeCount: LONGINT;
    undef: S.Instr;
    next: State;
  END;
  
VAR
  out: Output;

CONST
  writeAllInstructions = FALSE;
  writeDesignator = TRUE;
  resultPrefix = "(";
  resultSuffix = ")";
  instrPrefix = "{";
  instrSuffix = "}";
  depPrefix = "   [";
  depSuffix = "]";
  
PROCEDURE (out: Output) INIT*(b: S.Block; name: STRING);
  BEGIN
    out.b := b;
    out.name := name;
    out.codeDict := NEW(Dictionary.Dictionary(S.Instr, STRING));
    out.codeCount := 0;
  END INIT;

PROCEDURE (s: State) INIT*(block: S.Block);
  BEGIN
    s.block := block;
    s.instr := block.instrList;
    s.controlCP := block;
    s.mergeCount := -1;
    s.undef := NIL;
    s.next := NIL;
  END INIT;

PROCEDURE (s: State) Copy*(): State;
  VAR
    t: State;
  BEGIN
    NEW(t);
    t^ := s^;
    RETURN t;
  END Copy;

PROCEDURE Type(type: S.Type): STRING;
  BEGIN
    CASE type OF
    | S.noType: RETURN "";
    | S.signed8: RETURN "i8";
    | S.signed16: RETURN "i16";
    | S.signed32: RETURN "i32";
    | S.signed64: RETURN "i64";
    | S.unsigned8: RETURN "u8";
    | S.unsigned16: RETURN "u16";
    | S.unsigned32: RETURN "u32";
    | S.unsigned64: RETURN "u64";
    | S.address: RETURN "adr";
    | S.real32: RETURN "r32";
    | S.real64: RETURN "r64";
    END;
  END Type;

PROCEDURE Opcode*(instr: S.Instr): STRING;
  VAR
    str, type: STRING;
  BEGIN
    CASE instr.opcode OF
      (* arithmetic *)
    | S.const: str := "const";
    | S.add: str := "add";
    | S.sub: str := "sub";
    | S.mul: str := "mul";
    | S.div: str := "div";
    | S.neg: str := "neg";
    | S.asr: str := "asr";
    | S.asl: str := "asl";
    | S.lsr: str := "lsr";
    | S.lsl: str := "lsl";
    | S.rr: str := "rr";
    | S.rl: str := "rl";
    | S.indexed: str := "indexed";
    | S.eql: str := "eql";
    | S.neq: str := "neq";
    | S.lss: str := "lss";
    | S.leq: str := "leq";
    | S.gtr: str := "gtr";
    | S.geq: str := "geq";
    | S.setBool: str := "setBool";
    | S.bitTestAndSet: str := "bitTestAndSet";
    | S.bitTestAndClear: str := "bitTestAndClear";
    | S.typeConv: str := "typeConv";
    | S.fpLoad: str := "fpLoad";
    | S.fpStorePop: str := "fpStorePop";

      (* function framing *)
    | S.enter: str := "enter";
    | S.exit: str := "exit";
    | S.return: str := "return";
    | S.call: str := "call";
    | S.bounceResult: str := "bounceResult";
    | S.function: str := "function";
    | S.allocateStack: str := "allocateStack";
    | S.standin: str := "standin";

      (* memory *)
    | S.get: str := "get";
    | S.set: str := "set";
    | S.copy: str := "copy";
    | S.typeCast: str := "typeCast";
    | S.loadRegister: str := "loadRegister";
    | S.push: str := "push";
    | S.pop: str := "pop";
    | S.leave: str := "leave";
    | S.getLengthHeap: str := "getLengthHeap";
    | S.setStack: str := "setStack";
    | S.typeTag: str := "typeTag";

      (* control flow *)
    | S.branch: str := "branch";
    | S.guard:
      IF (instr(S.MergeInstr).jumps # NIL) THEN
        str := "guard-or-merge";
      ELSE
        str := "guard";
      END;
    | S.merge: str := "merge";
    | S.jump: str := "jump";
    | S.gate: str := "gate";
    | S.designatorGate: str := "designatorGate";
    | S.loopStart: str := "loopStart";
    | S.loopEnd: str := "loopEnd";
    | S.loopExit: str := "loopExit";
    | S.loopBackedge:  str := "loopBackedge";
    END;
    IF (instr.resultList # NIL) & (instr.resultList.type # S.noType) THEN
      type := Type(instr.resultList.type);
      IF (instr.opcode = S.const) THEN
        RETURN type;
      ELSE
        RETURN str+"-"+type;
      END;
    ELSE
      RETURN str;
    END;
  END Opcode;

PROCEDURE Register*(reg: S.Register): STRING;
  BEGIN
    CASE reg OF
    | S.sp: RETURN "sp";
    | S.fp: RETURN "fp";
    | S.cc: RETURN "cc";
    | S.gp0: RETURN "gp0";
    | S.gp1: RETURN "gp1";
    | S.gp2: RETURN "gp2";
    | S.gp3: RETURN "gp3";
    | S.gp4: RETURN "gp4";
    | S.gp5: RETURN "gp5";
    | S.st0: RETURN "st0";
    | S.fp0: RETURN "fp0";
    | S.fp1: RETURN "fp1";
    | S.fp2: RETURN "fp2";
    | S.fp3: RETURN "fp3";
    | S.fp4: RETURN "fp4";
    | S.fp5: RETURN "fp5";
    | S.fp6: RETURN "fp6";
    | S.fp7: RETURN "fp7";
    ELSE
      RETURN "???";
    END;
  END Register;

PROCEDURE (out: Output) GetInstrCode(instr: S.Instr): STRING;
  VAR
    str: STRING;
  BEGIN
    IF out.codeDict.HasKey(instr) THEN
      RETURN out.codeDict.Get(instr);
    ELSE
      INC(out.codeCount);
      str := Boxed.IntToString(out.codeCount);
      out.codeDict.Set(instr, str);
      RETURN str;
    END;
  END GetInstrCode;

PROCEDURE (out: Output) Label(node: S.Node): STRING;
  VAR
    i: LONGINT;
    res: S.Result;
    str: STRING;
    
  PROCEDURE Location(res: S.Result): STRING;
    BEGIN
      CASE res.adrMode OF
      | S.register:
        RETURN ":"+Register(res.register);
      | S.indirect:
        RETURN ":Indirect";
      | S.noLocation:
        RETURN "";
      END;
    END Location;
  
  BEGIN
    IF (node = NIL) THEN
      RETURN "NIL";
    ELSE
      WITH node: S.Instr DO
        RETURN instrPrefix+out.GetInstrCode(node)+instrSuffix;
      | node: S.Result DO
        IF (node.instr.resultList.nextResult = NIL) THEN
          (* single result: use short version *)
          str := resultPrefix+out.GetInstrCode(node.instr)+resultSuffix ;
        ELSE
          i := 1;
          res := node.instr.resultList;
          WHILE (res # node) DO
            INC(i);
            res := res.nextResult;
          END;
          str := resultPrefix+out.GetInstrCode(node.instr)+"."+Boxed.IntToString(i)+resultSuffix ;
        END;
        RETURN str+Location(node);
      | node: S.Opnd DO
        RETURN out.GetInstrCode(node.instr)+"/"+
            Boxed.IntToString(node.OpndIndex())+"="+out.Label(node.arg);
      END;
    END;
  END Label;

PROCEDURE (out: Output) Result*(msg: STRING; res: S.Result);
  BEGIN
    Out.Object(msg);
    Out.String(": ");
    Out.Object(out.Label(res));
    Out.Ln;
  END Result;

PROCEDURE (out: Output) Instr*(msg: STRING; instr: S.Instr);
  BEGIN
    Out.Object(msg);
    Out.String(": ");
    Out.Object(out.Label(instr));
    Out.String(": ");
    Out.Object(Opcode(instr));
    Out.Ln;
  END Instr;

PROCEDURE (out: Output) WriteFunction*();
  VAR
    w: TextRider.Writer;
    
  PROCEDURE WriteConst(selector: S.Selector);
    BEGIN
      WITH selector: S.Const DO
        w.WriteObject(selector.value);
      | selector: S.Var DO
        IF (selector.decl = NIL) THEN
          w.WriteObject("offset(.)");
        ELSIF selector.IsGlobalVar() THEN
          w.WriteObject("adr("+Naming.NameOfDeclaration(selector.decl)+")");
        ELSE
          w.WriteObject("offset("+selector.decl.Name());
          IF (selector.dim >= 0) THEN
            w.WriteChar(".");
            w.WriteLInt(selector.dim, 0);
          END;
          w.WriteObject(")");
        END;
      | selector: S.Proc DO
        w.WriteObject("adr("+selector.decl.Name()+")");
      | selector: S.ProcName DO
        w.WriteObject('adr("'+selector.name+'")');
      | selector: S.TypeDescr DO
        w.WriteObject('adr("'+Naming.NameOfTypeDescriptor(selector.type, NIL)+'")');
      | selector: S.ModuleDescr DO
        w.WriteObject('_mid');
      END;
    END WriteConst;

  PROCEDURE Expr(instr: S.Instr);
    VAR
      opnd: S.Opnd;
      s: S.Selector;
      i: LONGINT;
      jump: S.Instr;
    BEGIN
      w.WriteString("(");
      IF writeDesignator & (instr.designator # NIL) THEN
        w.WriteString("<");
        FOR s IN instr.designator^ DO
          WITH s: S.Var DO
            IF (s.decl = NIL) THEN
              w.WriteString("offset(.)");
            ELSE
              w.WriteString(s.decl.name.str^);
            END;
          | s: S.Const DO
            w.WriteString("const");
          | s: S.Proc DO
            w.WriteString(s.decl.name.str^);
          | s: S.Index DO
            w.WriteString("[");
            w.WriteObject(out.Label(s.indexStandin.opndList));
            w.WriteString("]");
          | s: S.Field DO
            w.WriteString(".");
            w.WriteString(s.field.name.str^);
          | s: S.ProcName DO
            w.WriteObject('"'+s.name+'"');
          | s: S.TypeDescr DO
            w.WriteObject(Naming.NameOfTypeDescriptor(s.type, NIL));
          | s: S.ModuleDescr DO
            w.WriteString("_mid");
          | s: S.HeapObj DO
            w.WriteObject("heap");
          END;
        END;
        w.WriteString("> ");
      END;
        
      w.WriteObject(Opcode(instr));
      FOR opnd IN instr.Operands() DO
        w.WriteChar(" ");
        IF opnd.immediate THEN
          Expr(opnd.arg.instr);
        ELSE
          w.WriteObject(out.Label(opnd.arg));
        END;
      END;

      CASE instr.opcode OF
      | S.const:
        w.WriteChar(" ");
        FOR i := 0 TO LEN(instr.designator^)-1 DO
          IF (i # 0) THEN
            w.WriteChar("+");
          END;
          WriteConst(instr.designator[i]);
        END;
      ELSE
        (* nothing *)
      END;

      WITH instr: S.MergeInstr DO
        IF (instr.jumps = NIL) THEN
            w.WriteString(" [no incoming jumps]");
        ELSE
          FOR jump IN instr.jumps^ DO
            w.WriteString(" [");
            w.WriteObject(out.Label(jump));
            w.WriteChar("]");
          END;
        END;
      ELSE
        (* nothing *)
      END;
      w.WriteString(")");
    END Expr;

  PROCEDURE WriteBlock(b: S.Block; indent: LONGINT);
    VAR
      instr: S.Instr;
      dep: S.Dep;
      i: LONGINT;
    BEGIN
      FOR instr IN b.Instructions() DO
        IF writeAllInstructions OR
           (instr.beforeList # NIL) OR (instr.afterList # NIL) OR
           instr.IsLive() THEN
          w.WriteLn;
          FOR i := 1 TO indent DO
            w.WriteString("  ");
          END;
          
          IF (instr.resultList = NIL) THEN
            w.WriteObject(out.Label(instr));
            w.WriteChar(" ");
          ELSE
            w.WriteObject(out.Label(instr.resultList));
            w.WriteChar(" ");
            IF (instr.resultList.nextResult # NIL) THEN
              w.WriteObject(out.Label(instr.resultList.nextResult));
              w.WriteChar(" ");
              IF (instr.resultList.nextResult.nextResult # NIL) THEN
                w.WriteString("... ");
              END;
            END;
            w.WriteString("<- ");
          END;
          Expr(instr);

          IF (instr.beforeList # NIL) THEN
            w.WriteString(depPrefix);
            FOR dep IN instr.BeforeList(S.depAny) DO
              IF (dep # instr.beforeList) THEN
                w.WriteChar(" ");
              END;
              CASE dep.type OF
              | S.depControl: w.WriteString("c:");
              | S.depMemory: w.WriteString("m:");
              | S.depRegion: w.WriteString("r:");
              END;
              w.WriteObject(out.Label(dep.before));
            END;
            w.WriteString(depSuffix);
          END;
        END;

        IF (instr IS S.Block) THEN
          WriteBlock(instr(S.Block), indent+1);
        END;
      END;
    END WriteBlock;
  
  BEGIN
    w := TextRider.ConnectWriter(StdChannels.stderr);
    w.WriteLn;
    w.WriteObject("PROCEDURE "+out.name);
    WriteBlock(out.b, 0);
    w.WriteLn;
  END WriteFunction;


PROCEDURE UndefState(s: State);
  VAR
    i: LONGINT;
  BEGIN
    s.undef := NEW(S.Instr, -1);
    FOR i := 0 TO S.lastRegister DO
      s.reg[i] := s.undef.AddResult(S.signed32);
    END;
  END UndefState;

PROCEDURE WriteFunctionAgain*();
  BEGIN
    out.WriteFunction();
  END WriteFunctionAgain;

PROCEDURE WriteFunction*(b: S.FunctionBlock);
  VAR
    name: STRING;
  BEGIN
    IF (b.procDecl.procAST = NIL) THEN
      name := "MODULE_BODY";
    ELSE
      name := Naming.NameOfDeclaration(b.procDecl);
    END;
    out := NEW(Output, b, name);
    out.WriteFunction();
  END WriteFunction;

PROCEDURE Label*(node: S.Node): STRING;
  BEGIN
    RETURN out.Label(node);
  END Label;

PROCEDURE Log*(msg: ARRAY OF CHAR; node: S.Node);
  BEGIN
    L.Object(msg, Label(node));
  END Log;

PROCEDURE Log2*(msg1: ARRAY OF CHAR; node1: S.Node;
                msg2: ARRAY OF CHAR; node2: S.Node);
  BEGIN
    L.Object(msg1, Label(node1)+", "+Object.NewLatin1(msg2)+": "+Label(node2));
  END Log2;

PROCEDURE ValidateAllocation*(b: S.FunctionBlock);
(**Checks that every read operation on a register, parameter, local variable,
   or spill variable indeed retrieves the value it expects to get.  This is one
   way to check that the register allocator did not produce an invalid register
   assignment.  *)
  VAR
    s, ready: State;
    block: S.Block;
    dep: S.Dep;
    waiting: Dictionary.Dictionary(S.Instr, State);
    keys: Object.ObjectArrayPtr(S.Instr);
    instr: S.Instr;
    loopStart: S.LoopStartInstr;
  
  PROCEDURE ValidateBlock(s: State);
   (**Track changes to the state @oparam{s} performed by the sequence of
      instructions in the block @ofield{s.block}, beginning with instruction
      @ofield{s.instr}.  Tracking ends either if control flow branches, or if
      the end of the block is reached.  In the former case, @ofield{s.instr}
      indicates the branching instruction, in the latter case it is @code{NIL}.  *)
    VAR
      instr: S.Instr;
      res: S.Result;
      inOutOpnd: S.Opnd;
      
    PROCEDURE ValidateOpnds(instr: S.Instr);
      VAR
        opnd: S.Opnd;
        arg: S.Result;
        iter: S.IterOperands;
      BEGIN
        CASE instr.opcode OF
        | S.jump:                        (* fold gate opnds into jump *)
          iter := instr.GateOperands();
        | S.gate:                        (* opnds folded into jump *)
          RETURN;
        ELSE                             (* normal instruction *)
          iter := instr.Operands();
        END;
        FOR opnd IN iter DO
          IF opnd.immediate THEN
            ValidateOpnds(opnd.arg.instr);
          ELSE
            arg := opnd.arg;
            ASSERT(arg.adrMode = S.register);
            IF (arg # s.reg[arg.register]) THEN
              L.Object("arg not in register", Label(opnd));
              L.Object("instead the register holds",
                       Label(s.reg[arg.register]));
              L.Ptr("ptr", Label(s.reg[arg.register]));
              L.Ptr("opcode", Opcode(s.reg[arg.register].instr));
              ASSERT(arg = s.reg[arg.register]);
            END;
          END;
        END;
      END ValidateOpnds;

    PROCEDURE HasControlDep(instr: S.Instr): BOOLEAN;
      VAR
        dep: S.Dep;
        iter: S.IterInstrAfterList;
      BEGIN
        iter := instr.AfterList(S.depControl);
        RETURN iter.Next(dep);
      END HasControlDep;
    
    BEGIN
      instr := s.instr;
      WHILE (instr # NIL) DO
        CASE instr.opcode OF
        | S.branch, S.loopStart, S.loopExit:
          s.instr := instr;
          RETURN;
        ELSE
          IF instr.IsLive()THEN
            IF HasControlDep(instr) THEN
              s.controlCP := instr;
            END;
            
            ValidateOpnds(instr);
            
            FOR res IN instr.Results() DO
              IF (res.adrMode # S.register) THEN
                Log("not in register", res);
                ASSERT(res.adrMode = S.register);
              END;
              IF (s.reg[res.register] # NIL) THEN
                ASSERT(s.reg[res.register].instr # instr);
              END;
              s.reg[res.register] := res;
            END;
            
            inOutOpnd := M.InOutOpnd(instr);
            IF (inOutOpnd # NIL) THEN
              IF (inOutOpnd.arg.register # instr.resultList.register) THEN
                Log("in/out opnd mismatch", inOutOpnd);
                ASSERT(inOutOpnd.arg.register = instr.resultList.register);
              END;
            END;
          END;
        END;

        instr := instr.nextInstr;
      END;
      s.instr := NIL;
    END ValidateBlock;

  PROCEDURE PushState(s: State);
    BEGIN
      s.next := ready;
      ready := s;
    END PushState;

  PROCEDURE PushBlock(s: State; block: S.Block);
    VAR
      t: State;
    BEGIN
      t := s.Copy();
      t.block := block;
      t.instr := block.instrList;
      t.controlCP := block;
      PushState(t);
    END PushBlock;

  PROCEDURE PopState(): State;
    VAR
      s: State;
    BEGIN
      s := ready;
      ready := ready.next;
      RETURN s;
    END PopState;

  PROCEDURE MergedBlocks(merge: S.Instr): LONGINT;
    VAR
      c: LONGINT;
      dep: S.Dep;
    BEGIN
      c := 0;
      FOR dep IN merge.BeforeList(S.depControl) DO
        INC(c);
      END;
      IF (merge.opcode = S.loopEnd) THEN
        (* uncount dep loopEnd -> loopStart *)
        DEC(c);
      END;
      RETURN c;
    END MergedBlocks;
  
  PROCEDURE MergeState(merge: S.MergeInstr; s: State);
    VAR
      i: LONGINT;
      t: State;
    BEGIN
      IF waiting.HasKey(merge) THEN
        t := waiting.Get(merge);
        FOR i := 0 TO S.lastRegister DO
          IF (t.reg[i] # s.reg[i]) THEN
            t.reg[i] := NIL;
          END;
        END;
        DEC(t.mergeCount);
        IF (t.mergeCount = 0) THEN
          PushState(t);
          waiting.Delete(merge);
        END;
      ELSE
        t := s.Copy();
        t.block := merge;
        t.instr := merge.instrList;
        t.controlCP := merge;
        t.mergeCount := MergedBlocks(merge)-1;
        IF (t.mergeCount = 0) THEN
          PushState(t);
        ELSE
          waiting.Set(merge, t);
        END;
      END;
    END MergeState;
  
  BEGIN
    waiting := NEW(Dictionary.Dictionary(S.Instr, State));
    s := NEW(State, b);
    UndefState(s);
    ready := NIL;
    PushState(s);

    WHILE (ready # NIL) DO
      s := PopState();
      ValidateBlock(s);
      
      IF (s.instr # NIL) THEN
        CASE s.instr.opcode OF
        | S.branch:
          FOR block IN s.instr(S.BranchInstr).paths^ DO
            MergeState(block(S.MergeInstr), s);
          END;
        | S.loopStart:
          loopStart := s.instr(S.LoopStartInstr);
          PushBlock(s, loopStart);
          IF (MergedBlocks(loopStart.end) = 0) THEN
            (* special case: if the loop has no exit, then the end of the
               loop is never reached by normal means *)
            PushBlock(s, loopStart.end);
          END;
        | S.loopExit:
          (* add state to loopEnd *)
          block := s.instr.MergingTarget();
          MergeState(block(S.MergeInstr), s);
          (* and push instruction after the loopExit *)
          s.instr := s.instr.nextInstr;
          PushState(s);
        END;
      ELSIF (s.block.opcode = S.merge) THEN
        (* continue after the branch in the block that contains the
           merge's branch instruction  *)
        ASSERT(s.block.block.opcode = S.branch);
        s.instr := s.block.block.nextInstr;
        s.block := s.block.block.block;
        s.controlCP := s.instr;
        PushState(s);
      ELSIF (s.block.opcode = S.loopEnd) THEN
        (* continue after the loopEnd block *)
        s.instr := s.block.nextInstr;
        s.block := s.block.block;
        s.controlCP := s.instr;
        PushState(s);
      ELSE
        FOR dep IN s.controlCP.AfterList(S.depControl) DO
          IF (dep.instr IS S.MergeInstr) & (dep.instr.opcode # S.loopEnd) THEN
            MergeState(dep.instr(S.MergeInstr), s);
          END;
        END;
      END;
    END;
    IF (waiting.Size() # 0) THEN
      keys := waiting.Keys();
      FOR instr IN keys^ DO
        Log("waiting", instr);
      END;
      ASSERT(waiting.Size() = 0);
    END;
  END ValidateAllocation;

END OOC:X86:Debug.
