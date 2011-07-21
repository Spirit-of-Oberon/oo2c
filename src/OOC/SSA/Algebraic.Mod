(* 	$Id: Algebraic.Mod,v 1.9 2003/02/24 00:25:30 mva Exp $	 *)
MODULE OOC:SSA:Algebraic;
(*  Algebraic transformations on SSA expressions.
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

(* FIXME... add more transformations *)

IMPORT
  Object:Boxed, Object:BigInt, OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd;

TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
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
      cmp := value. Cmp (power2[i]);
      IF (cmp = 0) THEN
        RETURN i;
      ELSIF (cmp < 0) THEN
        RETURN -1;
      END;
      INC (i);
    END;
    RETURN -1;
  END IsPowerOf2;

PROCEDURE IsNMinus1(res: SSA.Result): BOOLEAN;
(* Return true if `res' is an integer operation "subtract x,1" that is not
   checked for overflow.  *)
  VAR
    arg: SSA.Result;
  BEGIN
    IF (res IS SSA.Instr) &
       (res(SSA.Instr).opcode = Opcode.subtract) &
       (res.nextResult = NIL)  THEN  (* no overflow check *)
      arg := res(SSA.Instr).NthArg(1);
      RETURN (arg IS SSA.Const) &
          BigInt.one.Equals(arg(SSA.Const).value);
    ELSE
      RETURN FALSE;
    END;
  END IsNMinus1;

PROCEDURE Transform* (pb: SSA.ProcBlock; enableSubstitution: BOOLEAN);
(**With @oparam{enableSubstitution} set, enable substitution of an instruction
   by one of a different class (fFor example, division can turn into a shift,
   and a+b*c into "indexed".  *)
  VAR
    instr: SSA.Instr;
    worklist: Worklist;

  PROCEDURE InspectInstr (instr: SSA.Instr);
    VAR
      exp: LONGINT;
      new, sub: SSA.Instr;
      
    PROCEDURE AddUsesToWorklist(instr: SSA.Instr);
      VAR
        use: SSA.Opnd;

      PROCEDURE AddToWorklist (instr: SSA.Instr);
        VAR
          wl: Worklist;
        BEGIN
          NEW (wl);
          wl. next := worklist;
          wl. instr := instr;
          worklist := wl;
        END AddToWorklist;
      
      BEGIN
        ASSERT (instr. nextResult = NIL);
        use := instr. useList;
        WHILE (use # NIL) DO
          AddToWorklist (use. instr);
          use := use. nextUse;
        END;
      END AddUsesToWorklist;
    
    PROCEDURE Replace (instr: SSA.Instr; with: SSA.Result);
      BEGIN
        AddUsesToWorklist(instr);
        instr. ReplaceUses (with);
      END Replace;

    PROCEDURE ReplaceWithOpnd (instr: SSA.Instr; with: SSA.Opnd);
      BEGIN
        Replace (instr, with. arg);
      END ReplaceWithOpnd;

    PROCEDURE Equals (opnd: SSA.Opnd; const: Boxed.Object): BOOLEAN;
      VAR
        arg: SSA.Result;
      BEGIN
        arg := opnd. arg;
        WITH arg: SSA.Const DO
          RETURN const. Equals (arg. value);
        ELSE
          RETURN FALSE;
        END;
      END Equals;

    PROCEDURE Scaled (res: SSA.Result): BOOLEAN;
    (* Return @code{TRUE} if @oparam{res} is an integer multiplication, and
       the second arguments is an integer constant with a value of 1, 2, 4,
       or 8.  *)
      VAR
        instr: SSA.Instr;
        exp: LONGINT;
      BEGIN
        IF enableSubstitution &
           (res IS SSA.Instr) &
           (res(SSA.Instr). opcode = Opcode.multiply) &
           (res(SSA.Instr). subclass <= Opcode.scAddress) THEN
          instr := res(SSA.Instr);
          IF (instr. opndList. nextOpnd. arg IS SSA.Const) THEN
            exp := IsPowerOf2 (instr. opndList. nextOpnd. arg(SSA.Const). value(BigInt.BigInt));
            RETURN (0 <= exp) & (exp <= 3);  (* 1, 2, 4, or 8 *)
          END;
        END;
        RETURN FALSE;
      END Scaled;

    PROCEDURE ReplaceIndexed (instr: SSA.Instr; base, scale: SSA.Opnd);
      VAR
        new, s: SSA.Instr;
      BEGIN
        new := pb. AddInstr (Opcode.indexed, instr. subclass);
        new. AddOpnd (base. arg, base. class);
        s := scale. arg(SSA.Instr);
        new. AddOpnd (s. opndList. arg, s. opndList. class);
        new. AddOpnd (s. opndList. nextOpnd. arg,
                      s. opndList. nextOpnd. class);
        Replace (instr, new);
      END ReplaceIndexed;
    
    BEGIN
      CASE instr. opcode OF
      | Opcode.add:
        IF Equals (instr. opndList, intZero) THEN (* 0+x = x *)
          ReplaceWithOpnd (instr, instr. opndList. nextOpnd);
        ELSIF Equals (instr. opndList. nextOpnd, intZero) THEN (* x+0 = x *)
          ReplaceWithOpnd (instr, instr. opndList);
        ELSIF Scaled (instr. opndList. arg) THEN
          (* i*c+b = indexed(b,i,c) *)
          ReplaceIndexed (instr, instr. opndList. nextOpnd, instr. opndList);
        ELSIF Scaled (instr. opndList. nextOpnd. arg) THEN
          (* b+i*c = indexed(b,i,c) *)
          ReplaceIndexed (instr, instr. opndList, instr. opndList. nextOpnd);
        END;
        
      | Opcode.subtract:
        IF Equals (instr. opndList. nextOpnd, intZero) THEN (* x-0 = x *)
          ReplaceWithOpnd (instr, instr. opndList);
        END;
        
      | Opcode.multiply:
        IF Equals (instr. opndList, intOne) THEN (* 1*x = x *)
          ReplaceWithOpnd (instr, instr. opndList. nextOpnd);
        ELSIF Equals (instr. opndList. nextOpnd, intOne) THEN (* x*1 = x *)
          ReplaceWithOpnd (instr, instr. opndList);
        ELSIF Equals (instr. opndList, intZero) THEN (* 0*x = 0 *)
          ReplaceWithOpnd (instr, instr. opndList);
        ELSIF Equals (instr. opndList. nextOpnd, intZero) THEN (* x*0 = 0 *)
          ReplaceWithOpnd (instr, instr. opndList. nextOpnd);
        END;

      | Opcode.divide: (* replace DIV by power of two with right shift *)
        IF enableSubstitution &
           (instr. subclass < Opcode.scReal32) &
           (instr. opndList. nextOpnd. arg IS SSA.Const) THEN
          exp := IsPowerOf2 (instr. opndList. nextOpnd. arg(SSA.Const). value(BigInt.BigInt));
          IF (exp >= 0) THEN
            new := pb. AddInstr (Opcode.shiftRight, instr. subclass);
            new. AddOpnd (instr. opndList. arg, Opnd.arg);
            new. AddOpnd (pb. GetConstInt (exp), Opnd.arg);
            instr. ReplaceUses (new);
            ASSERT (instr. nextResult = NIL);
          END;
        END;

      | Opcode.leq:
        IF IsNMinus1(instr.NthArg(1)) THEN (* x<=n-1 = x<n *)
          sub := instr.opndList.nextOpnd.arg(SSA.Instr);
          instr.opndList.nextOpnd.ReplaceArg(sub.opndList.arg);
          instr.opcode := Opcode.lss;
          AddUsesToWorklist(instr);
        END;
        
      | Opcode.gtr:
        IF IsNMinus1(instr.NthArg(1)) THEN (* x>n-1 = x>=n *)
          sub := instr.opndList.nextOpnd.arg(SSA.Instr);
          instr.opndList.nextOpnd.ReplaceArg(sub.opndList.arg);
          instr.opcode := Opcode.geq;
          AddUsesToWorklist(instr);
        END;
      ELSE  (* ignore any other instructions *)
      END;
    END InspectInstr;
  
  BEGIN
    worklist := NIL;
    
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      InspectInstr (instr);
      instr := instr. nextInstr;
    END;

    (* the previous replacements may have brought additional transformation
       opportunities: scan all instructions that have been changed *)
    WHILE (worklist # NIL) DO
      instr := worklist. instr;
      worklist := worklist. next;
      InspectInstr (instr);
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
END OOC:SSA:Algebraic.
