MODULE OOC:X86:Algebraic;

(* FIXME... add more transformations *)

IMPORT
  Object:Boxed, Object:BigInt, S := OOC:X86:SSA;

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: S.Instr;
  END;

CONST
  maxPower2 = 63;
  
VAR
  intZero, intOne, intTwo: BigInt.BigInt;
  power2: ARRAY maxPower2+1 OF BigInt.BigInt;

PROCEDURE IsPowerOf2 (value: BigInt.BigInt): LONGINT;
(**Returns a non-negative integer if @oparam{value} is a power of two, and
   @samp{-1} otherwise.  *)
  VAR
    i, cmp: LONGINT;
  BEGIN
    i := 0;
    WHILE (i <= maxPower2) DO
      cmp := value.Cmp(power2[i]);
      IF (cmp = 0) THEN
        RETURN i;
      ELSIF (cmp < 0) THEN
        RETURN -1;
      END;
      INC (i);
    END;
    RETURN -1;
  END IsPowerOf2;

PROCEDURE IsNMinus1(res: S.Result): BOOLEAN;
(* Return true if `res' is an integer operation "subtract x,1" that is not
   checked for overflow.  *)
  VAR
    arg: S.Result;
    instr: S.Instr;
  BEGIN
    instr := res.instr;
    IF (res.instr.opcode = S.sub) & instr.Unchecked() THEN
      arg := res.instr.NthArg(1);
      RETURN (arg.instr.opcode = S.const) &
          BigInt.one.Equals(arg.instr.designator[0](S.Const).value);
    ELSE
      RETURN FALSE;
    END;
  END IsNMinus1;

PROCEDURE Transform* (pb: S.FunctionBlock; enableSubstitution: BOOLEAN);
(**With @oparam{enableSubstitution} set, enable substitution of an instruction
   by one of a different class (for example, division can turn into a shift,
   and a+b*c into "indexed".  *)
  VAR
    instr: S.Instr;
    worklist: Worklist;

  PROCEDURE InspectInstr(instr: S.Instr);
    VAR
      exp: LONGINT;
      new, sub: S.Instr;
      val: Boxed.Object;
      
    PROCEDURE AddUsesToWorklist(instr: S.Instr);
      VAR
        use: S.Opnd;

      PROCEDURE AddToWorklist (instr: S.Instr);
        VAR
          wl: Worklist;
        BEGIN
          NEW(wl);
          wl.next := worklist;
          wl.instr := instr;
          worklist := wl;
        END AddToWorklist;
      
      BEGIN
        ASSERT(instr.resultList.nextResult = NIL);
        use := instr.resultList.useList;
        WHILE (use # NIL) DO
          AddToWorklist(use.instr);
          use := use.nextUse;
        END;
      END AddUsesToWorklist;
    
    PROCEDURE Replace(instr: S.Instr; with: S.Result);
      BEGIN
        AddUsesToWorklist(instr);
        instr.resultList.ReplaceUses(with);
      END Replace;

    PROCEDURE ReplaceWithOpnd(instr: S.Instr; with: S.Opnd);
      BEGIN
        Replace(instr, with.arg);
      END ReplaceWithOpnd;

    PROCEDURE Equals (opnd: S.Opnd; const: Boxed.Object): BOOLEAN;
      BEGIN
        RETURN const.Equals(opnd.arg.GetConst());
      END Equals;

    PROCEDURE Scaled (res: S.Result): BOOLEAN;
    (* Return @code{TRUE} if @oparam{res} is an integer multiplication, and
       the second arguments is an integer constant with a value of 1, 2, 4,
       or 8.  *)
      VAR
        instr: S.Instr;
        exp: LONGINT;
        val: Boxed.Object;
      BEGIN
        IF enableSubstitution &
           (res.instr.opcode = S.mul) & (res.type <= S.address) THEN
          instr := res.instr;
          val := instr.opndList.nextOpnd.arg.GetConst();
          IF (val # NIL) THEN
            exp := IsPowerOf2(val(BigInt.BigInt));
            RETURN (0 <= exp) & (exp <= 3);  (* 1, 2, 4, or 8 *)
          END;
        END;
        RETURN FALSE;
      END Scaled;

    PROCEDURE ReplaceIndexed (instr: S.Instr; base, scale: S.Opnd);
      VAR
        new, s: S.Instr;
      BEGIN
        new := pb.AddInstr0(S.indexed);
        new.AddOpnd(base.arg);
        s := scale.arg.instr;
        new.AddOpnd(s.opndList.arg);
        new.AddOpnd(s.opndList.nextOpnd.arg);
        Replace(instr, new.AddResult(instr.resultList.type));
      END ReplaceIndexed;

    PROCEDURE AdrOfGlobalVar(instr: S.Instr): BOOLEAN;
      BEGIN
        RETURN (instr.opcode = S.const) &
            (instr.designator[0] IS S.Var) &
            instr.designator[0](S.Var).IsGlobalVar();
      END AdrOfGlobalVar;
    
    BEGIN
      CASE instr. opcode OF
      | S.add:
        IF Equals(instr.opndList, intZero) THEN (* 0+x = x *)
          ReplaceWithOpnd(instr, instr.opndList.nextOpnd);
        ELSIF Equals(instr.opndList.nextOpnd, intZero) THEN (* x+0 = x *)
          ReplaceWithOpnd(instr, instr.opndList);
        ELSIF Scaled(instr.opndList.arg) THEN
          (* i*c+b = indexed(b,i,c) *)
          ReplaceIndexed(instr, instr.opndList.nextOpnd, instr.opndList);
        ELSIF Scaled(instr.opndList.nextOpnd.arg) THEN
          (* b+i*c = indexed(b,i,c) *)
          ReplaceIndexed(instr, instr.opndList, instr.opndList.nextOpnd);
        ELSIF AdrOfGlobalVar(instr.opndList.arg.instr) &
              instr.opndList.nextOpnd.IsConst() THEN
          (* adr(globalVar)+c = const(adr(globalVar)+c) *)
          new := pb.AddInstr0(S.const);
          new.SetDesignator(instr.opndList.arg.instr.designator);
          new.ExtendDesignator(instr.opndList.nextOpnd.arg.instr.designator[0]);
          Replace(instr, new.AddResult(instr.resultList.type));
        END;
        
      | S.sub:
        IF Equals(instr.opndList.nextOpnd, intZero) THEN (* x-0 = x *)
          ReplaceWithOpnd(instr, instr.opndList);
        END;
        
      | S.mul:
        IF Equals(instr.opndList, intOne) THEN (* 1*x = x *)
          ReplaceWithOpnd(instr, instr.opndList.nextOpnd);
        ELSIF Equals(instr.opndList.nextOpnd, intOne) THEN (* x*1 = x *)
          ReplaceWithOpnd(instr, instr.opndList);
        ELSIF Equals(instr.opndList, intZero) THEN (* 0*x = 0 *)
          ReplaceWithOpnd(instr, instr.opndList);
        ELSIF Equals(instr.opndList.nextOpnd, intZero) THEN (* x*0 = 0 *)
          ReplaceWithOpnd(instr, instr.opndList.nextOpnd);
        END;

      | S.div: (* replace DIV by power of two with right shift *)
        IF enableSubstitution & (instr.resultList.type < S.real32) THEN
          val := instr.opndList.nextOpnd.arg.GetConst();
          IF (val # NIL) THEN
            exp := IsPowerOf2 (val(BigInt.BigInt));
            IF (exp >= 0) THEN
              new := pb.AddInstr0(S.asr);
              new.AddOpnd(instr.opndList.arg);
              new.AddOpnd(pb.AddConstDim(exp));
              instr.resultList.ReplaceUses(new.AddResult(instr.resultList.type));
              ASSERT(instr.resultList.nextResult = NIL);
            END;
          END;
        END;

      | S.leq:
        IF IsNMinus1(instr.NthArg(1)) THEN (* x<=n-1 = x<n *)
          sub := instr.opndList.nextOpnd.arg.instr;
          instr.opndList.nextOpnd.ReplaceArg(sub.opndList.arg);
          instr.SetOpcode(S.lss);
          AddUsesToWorklist(instr);
        END;
        
      | S.gtr:
        IF IsNMinus1(instr.NthArg(1)) THEN (* x>n-1 = x>=n *)
          sub := instr.opndList.nextOpnd.arg.instr;
          instr.opndList.nextOpnd.ReplaceArg(sub.opndList.arg);
          instr.SetOpcode(S.geq);
          AddUsesToWorklist(instr);
        END;
      ELSE  (* ignore any other instructions *)
      END;
    END InspectInstr;
  
  BEGIN
    worklist := NIL;

    FOR instr IN pb.AllInstructions(-1) DO
      InspectInstr(instr);
    END;

    (* the previous replacements may have brought additional transformation
       opportunities: scan all instructions that have been changed *)
    WHILE (worklist # NIL) DO
      instr := worklist.instr;
      worklist := worklist.next;
      InspectInstr(instr);
    END;
  END Transform;

PROCEDURE Init ();
  VAR
    i: LONGINT;
  BEGIN
    intZero := BigInt.NewInt(0);
    intOne := BigInt.NewInt(1);
    intTwo := BigInt.NewInt(2);
    
    power2[0] := intOne;
    FOR i := 1 TO maxPower2 DO
      power2[i] := power2[i-1].Mul(intTwo);
    END;
  END Init;

BEGIN
  Init;
END OOC:X86:Algebraic.
