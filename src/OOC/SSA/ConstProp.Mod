(* 	$Id: ConstProp.Mod,v 1.13 2004/05/23 18:24:52 mva Exp $	 *)
MODULE OOC:SSA:ConstProp;
(*  Constant propagation and unreachable code elimination.
    Copyright (C) 2002, 2003  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Object:Boxed, Object:BigInt,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result,
  OOC:SSA:DeadCodeElimination;
  
(* FIXME... check for overflows, and don't do folding if an overflow
   happens *)

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
  END;

CONST
  unclassified = NIL;
  
VAR
  notConstant: SSA.Result;

PROCEDURE ComputeConst (pb: SSA.ProcBlock; instr: SSA.Instr): SSA.Const;
  VAR
    arg1, arg2: SSA.Const;
    v: Boxed.Object;
    i1, i2: BigInt.BigInt;
  BEGIN
    IF (instr.opcode = Opcode.typeConv)  THEN
      arg1 := instr. opndList. arg. info(SSA.Const);
      IF (arg1.value IS BigInt.BigInt) &
         (instr.subclass < Opcode.scReal32) THEN
        (* FIXME... check for overflow *)
        RETURN pb. GetConst(arg1.value, instr.subclass, NIL);
      END;
    ELSIF (instr. SizeOpndList() >= 2) &
       (instr. opcode # Opcode.preloadedVar) &
       (instr. opcode # Opcode.setBit) &
       (instr. opcode # Opcode.clearBit) &
       (instr. opcode # Opcode.lsh) &
       (instr. opcode # Opcode.rot) THEN
      (* FIXME... add clearBit, setBit, logical and/or/not/etc. *)
      arg1 := instr. opndList. arg. info(SSA.Const);
      arg2 := instr. opndList. nextOpnd. arg. info(SSA.Const);
      v := NIL;
      
      CASE arg1. subclass OF
      | Opcode.scSigned8 .. Opcode.scAddress:
        IF (arg1.value IS BigInt.BigInt) & (arg2.value IS BigInt.BigInt) THEN
          (* only dealing with integers for now; FIXME... add set values *)
          i1 := arg1. value(BigInt.BigInt);
          i2 := arg2. value(BigInt.BigInt);
          
          CASE instr. opcode OF
          | Opcode.add     : v := i1.Add(i2);
          | Opcode.subtract: v := i1.Sub(i2);
          | Opcode.multiply: v := i1.Mul(i2);
            
          | Opcode.eql: v := Boxed.NewBoolean(i1.Cmp(i2)  = 0);
          | Opcode.neq: v := Boxed.NewBoolean(i1.Cmp(i2)  # 0);
          | Opcode.leq: v := Boxed.NewBoolean(i1.Cmp(i2) <= 0);
          | Opcode.lss: v := Boxed.NewBoolean(i1.Cmp(i2) <  0);
          | Opcode.geq: v := Boxed.NewBoolean(i1.Cmp(i2) >= 0);
          | Opcode.gtr: v := Boxed.NewBoolean(i1.Cmp(i2) >  0);
          ELSE                             (* not supported *)
            (*instr. LogOpcode ("not folding (unsupported opcode)");
               instr. opndList. arg. instr. LogOpcode ("arg1");
               instr. opndList. nextOpnd. arg. instr. LogOpcode ("arg2");*)
          END;
        END;
        
      ELSE                               (* not supported *)
        (*instr. LogOpcode ("not folding (unsupported subclass)");
        instr. opndList. arg. instr. LogOpcode ("arg1");
        instr. opndList. nextOpnd. arg. instr. LogOpcode ("arg2");*)
      END;

      IF (v # NIL) THEN
        IF (v IS Boxed.Boolean) THEN
          RETURN pb. GetConstBool(v(Boxed.Boolean). value);
        ELSE
          RETURN pb. GetConst(v, instr.subclass, NIL);
        END;
      END;
    END;
    RETURN NIL;                          (* fall through: no folding *)
  END ComputeConst;

PROCEDURE Transform* (pb: SSA.ProcBlock);
  VAR
    worklist: Worklist;
    instr: SSA.Instr;
    
  PROCEDURE AddToWorklist (instr: SSA.Instr);
    VAR
      wl: Worklist;
    BEGIN
      IF (instr. marker = 0) THEN
        instr. marker := 1;
        
        NEW (wl);
        wl. next := worklist;
        wl. instr := instr;
        worklist := wl;
      END;
    END AddToWorklist;

  PROCEDURE SetInfo (instr: SSA.Instr; info: SSA.Result);
    VAR
      res: SSA.Result;
    BEGIN
      res := instr;
      WHILE (res # NIL) DO
        res. info := info;
        res := res. nextResult;
      END;
    END SetInfo;

  PROCEDURE AddUsesToWorklist (res: SSA.Result);
    VAR
      use: SSA.Opnd;
      useInstr: SSA.Instr;
    BEGIN
      use := res. useList;
      WHILE (use # NIL) DO
        useInstr := use. instr;
        IF (useInstr. info = unclassified) THEN
          AddToWorklist (useInstr);
        END;
        use := use. nextUse;
      END;
    END AddUsesToWorklist;
  
  PROCEDURE UpdateInfo (instr: SSA.Instr; info: SSA.Result);
    VAR
      res: SSA.Result;
    BEGIN
      res := instr;
      WHILE (res # NIL) DO
        res. info := info;
        AddUsesToWorklist (res);
        res := res. nextResult;
      END;
    END UpdateInfo;
  
  PROCEDURE ClassifyInstr (instr: SSA.Instr);
  (* Try to classify `instr' as `notConstant', or as a constant value.  *)
    VAR
      state, const: SSA.Result;
      opnd: SSA.Opnd;

    PROCEDURE MatchingPath (expr: SSA.Const; isSwitch: BOOLEAN;
                            branch: SSA.Opnd): SSA.Opnd;
    (* Return the branch that corresponds to the selector `expr'.  *)
      
      PROCEDURE InLabelList (expr: Boxed.Object; opnd: SSA.Opnd): BOOLEAN;
        VAR
          lower, upper: Boxed.Object;
        BEGIN
          WHILE (opnd # NIL) DO
            lower := opnd. arg(SSA.Const). value;
            upper := opnd. nextOpnd. arg(SSA.Const). value;
            IF (lower. Cmp (expr) <= 0) & (expr. Cmp (upper) <= 0) THEN
              RETURN TRUE;
            END;
            opnd := opnd. nextOpnd. nextOpnd;
          END;
          RETURN FALSE;
        END InLabelList;
      
      BEGIN
        IF isSwitch THEN
          WHILE (branch # NIL) &
                (branch.class = Opnd.labels) &
                ~(branch.arg IS SSA.Const) DO
            IF InLabelList (expr. value, branch. arg(SSA.Instr). opndList) THEN
              RETURN branch. nextOpnd;
            END;
            branch := branch. nextOpnd. nextOpnd;
          END;
          RETURN branch. nextOpnd;       (* default branch *)
        ELSE
          WHILE (branch # NIL) & (branch. class = Opnd.arg) DO
            IF expr. value. Equals (branch. arg(SSA.Const). value) THEN
              RETURN branch. nextOpnd;
            END;
            branch := branch. nextOpnd. nextOpnd;
          END;
          ASSERT (FALSE);
        END;
      END MatchingPath;

    PROCEDURE ReplaceSelect (select: SSA.Instr; branch: SSA.Opnd);
      VAR
        opnd: SSA.Opnd;
        res: SSA.Result;
      BEGIN
        res := select. nextResult;
        IF (branch. arg. instr. opcode = Opcode.collect) THEN
          (* replace every result of the "select" with the corresponding
             argument of the "collect" *)
          opnd := branch. arg. instr. opndList;
          WHILE (res # NIL) DO
            AddUsesToWorklist (res);
            res. ReplaceUses (opnd. arg);
            res := res. nextResult;
            opnd := opnd. nextOpnd;
          END;
          
        ELSE  (* only need to replace the "store" result *)
          AddUsesToWorklist (res);
          res. ReplaceUses (branch. arg);
        END;
      END ReplaceSelect;
    
    BEGIN
      CASE instr. opcode OF
      | Opcode.collect, Opcode.select:
        (* both "collect" and "select" remain unclassified until all their
           operands have been classified *)
        opnd := instr. opndList;
        WHILE (opnd # NIL) & (opnd. arg. info # unclassified) DO
          opnd := opnd. nextOpnd;
        END;

        IF (opnd = NIL) THEN             (* all operands are classified *)
          ASSERT (instr. useList = NIL);
          ASSERT (instr. nextResult. class = Result.store);
          IF (instr. opcode = Opcode.select) &
             (instr. opndList. arg. info # notConstant) THEN
            (* the selecting expression of the "select" is a constant: replace
               "select" with the matching path *)
            ReplaceSelect (instr,
                           MatchingPath(instr. opndList. arg. info(SSA.Const),
                                        instr. IsSwitchStatm(),
                                        instr. opndList. nextOpnd));
          ELSE
            UpdateInfo (instr, notConstant);
          END;
        (* ELSE: at least one operand is unclassified, more luck next time *)
        END;
        
      ELSE
        state := instr;
        opnd := instr. opndList;
        LOOP
          IF (opnd = NIL) THEN
            EXIT;
          ELSIF (opnd. arg. info = unclassified) THEN
            state := unclassified;
          ELSIF (opnd. arg. info = notConstant) THEN
            state := notConstant;
            EXIT;
          END;
          opnd := opnd. nextOpnd;
        END;

        IF (state = instr) THEN          (* all operands are constants *)
          const := ComputeConst (pb, instr);
          IF (const = NIL) THEN
            (* we cannot fold this expression: treat it a non constant *)
            UpdateInfo (instr, notConstant);
          ELSE
            ASSERT (instr. nextResult = NIL);
            UpdateInfo (instr, const);
          END;
        ELSIF (state = notConstant) THEN (* at least one is not constant *)
          UpdateInfo (instr, notConstant);
        (* ELSE: no opnd is notConstant, at least one unclassified *)
        END;
      END;
    END ClassifyInstr;
  
  BEGIN
    (* Set the `info' field of all results to `unclassified', with the
       exception of constants and the `enter' instructions.  Constants get
       themself as `info', the enter instruction is marked as `notConstant' *)
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      instr. marker := 0;

      IF (instr IS SSA.Const) OR (instr. opcode = Opcode.labels) THEN
        instr. info := instr;
        ASSERT (instr. nextResult = NIL);
      ELSIF (instr. opcode # Opcode.select) & (instr. GetArgStore() # NIL) THEN
        (* any instruction that takes `store' as input cannot be constant;
           "select" is excluded here, because we use it to identify unreachable
           code; note: this also marks run-time checks with otherwise constant
           input as `notConstant'  *)
        SetInfo (instr, notConstant);
      ELSE
        SetInfo (instr, unclassified);
      END;
      instr := instr. nextInstr;
    END;
    ASSERT (pb. selectReturn. opndList. arg. instr. opcode = Opcode.enter);
    SetInfo (pb. selectReturn. opndList. arg. instr, notConstant);
    
    (* first pass over all instructions *)
    worklist := NIL;
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. info = unclassified) & (instr. marker = 0) THEN
        (* ignore instructions that have already been classified, and defer
           instructions that have been put on the worklist already *)
        ClassifyInstr (instr);
      END;
      instr := instr. nextInstr;
    END;

    (* repeat until worklist is empty *)
    WHILE (worklist # NIL) DO
      instr := worklist. instr;
      instr. marker := 0;
      worklist := worklist. next;
      ASSERT (instr. info = unclassified);
      ClassifyInstr (instr);
    END;

    (* replace uses of folded expressions with the constant result *)
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. info # unclassified) &
         (instr. info # notConstant) &
         (instr. info # instr) THEN
        instr. ReplaceUses (instr. info(SSA.Result));
      END;
      instr := instr. nextInstr;
    END;

    (* force DCE to get rid of dangling `store' results *)
    DeadCodeElimination.Transform (pb);
  END Transform;

BEGIN
  notConstant := SSA.NewResult(NIL, -1, -1);
END OOC:SSA:ConstProp.
