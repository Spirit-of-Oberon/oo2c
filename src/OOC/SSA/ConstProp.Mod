(* 	$Id$	 *)
MODULE OOC:SSA:ConstProp;
(*  Constant propagation and unreachable code elimination.
    Copyright (C) 2002  Michael van Acken

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
  Language, Language:Integer, Language:Boolean,
  OOC:SSA, OOC:SSA:Opcode;
  
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
    v: Language.Value;
    i1, i2: Integer.Value;
  BEGIN
    IF (instr. SizeOpndList() >= 2) THEN
      arg1 := instr. opndList. arg. info(SSA.Const);
      arg2 := instr. opndList. nextOpnd. arg. info(SSA.Const);
      v := NIL;
      
      CASE arg1. subclass OF
      | Opcode.scSigned8 .. Opcode.scAddress:
        i1 := arg1. value(Integer.Value);
        i2 := arg2. value(Integer.Value);
        
        CASE instr. opcode OF
        | Opcode.add     : v := i1.Sum(i2);
        | Opcode.subtract: v := i1.Difference(i2);
        | Opcode.multiply: v := i1.Product(i2);

        | Opcode.eql: v := Boolean.New(i1.Compare(i2)  = 0);
        | Opcode.neq: v := Boolean.New(i1.Compare(i2)  # 0);
        | Opcode.leq: v := Boolean.New(i1.Compare(i2) <= 0);
        | Opcode.lss: v := Boolean.New(i1.Compare(i2) <  0);
        | Opcode.geq: v := Boolean.New(i1.Compare(i2) >= 0);
        | Opcode.gtr: v := Boolean.New(i1.Compare(i2) >  0);
        ELSE                             (* not supported *)
          (*instr. LogOpcode ("not folding (unsupported opcode)");
          instr. opndList. arg. instr. LogOpcode ("arg1");
          instr. opndList. nextOpnd. arg. instr. LogOpcode ("arg2");*)
        END;
        
      ELSE                               (* not supported *)
        (*instr. LogOpcode ("not folding (unsupported subclass)");
        instr. opndList. arg. instr. LogOpcode ("arg1");
        instr. opndList. nextOpnd. arg. instr. LogOpcode ("arg2");*)
      END;

      IF (v # NIL) THEN
        IF (v IS Boolean.Value) THEN
          RETURN pb. GetConstBool (v(Boolean.Value). value);
        ELSE
          RETURN pb. GetConst (v, arg1. type);
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
  
  PROCEDURE UpdateInfo (instr: SSA.Instr; info: SSA.Result);
    VAR
      res: SSA.Result;
      use: SSA.Opnd;
      useInstr: SSA.Instr;
    BEGIN
      res := instr;
      WHILE (res # NIL) DO
        res. info := info;
        use := res. useList;
        WHILE (use # NIL) DO
          useInstr := use. instr;
          IF (useInstr. info = unclassified) THEN
            AddToWorklist (useInstr);
          END;
          use := use. nextUse;
        END;
        res := res. nextResult;
      END;
    END UpdateInfo;
  
  PROCEDURE ClassifyInstr (instr: SSA.Instr);
    VAR
      state, const: SSA.Result;
      opnd: SSA.Opnd;
    BEGIN
      IF (instr. opcode = Opcode.select) THEN
        ASSERT (instr. useList = NIL);
        (* ... *)
        UpdateInfo (instr, notConstant);
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
  END Transform;

BEGIN
  notConstant := SSA.NewResult(NIL, -1, -1);
END OOC:SSA:ConstProp.
