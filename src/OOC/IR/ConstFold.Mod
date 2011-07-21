(* 	$Id: ConstFold.Mod,v 1.84 2004/07/25 09:38:58 mva Exp $	 *)
MODULE OOC:IR:ConstFold;
(*  Constant folding on IR expressions.
    Copyright (C) 2002, 2003, 2004  Stewart Greenhill, Michael van Acken

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
  Sym := OOC:SymbolTable, OOC:IR, OOC:SymbolTable:Predef,
  TR := OOC:SymbolTable:TypeRules, Object, Object:Boxed, Object:BigInt;

TYPE
  ConstFold = POINTER TO ConstFoldDesc;
  ConstFoldDesc = RECORD
    (IR.ConstFoldDesc)
  END;

CONST
  (* To enable constant folding for REAL expressions, set foldReals TRUE. Even
  better, allow it to be enabled/disabled at run-time *)
  foldReals = TRUE;

PROCEDURE InitConstFold (c : ConstFold);
BEGIN
  IR.InitConstFold (c, NIL);
END InitConstFold;

PROCEDURE NewConstFold* (): ConstFold;
VAR
  c : ConstFold;
BEGIN
  NEW (c);
  InitConstFold (c);
  RETURN c
END NewConstFold;

PROCEDURE SmallestType(value : Boxed.Object) : Sym.Type;
(**Return the smallest type that can represent @oparam{value}. *)
BEGIN
  WITH value : BigInt.BigInt DO
    RETURN Predef.SmallestIntType (value);
  | value : Boxed.LongReal DO
    (* FIXME! Figure out the appropriate REAL type *)
    RETURN Predef.GetType(Predef.real);
  | value : Boxed.Set DO
    (* FIXME! Figure out the appropriate SET type *)
    RETURN Predef.GetType(Predef.set);
  END;
END SmallestType;

PROCEDURE (c : ConstFold) ValueConst(value : Boxed.Object; op : IR.Operator) : IR.Const;
VAR type : Sym.Type;
BEGIN
  type := SmallestType(value);
  IF type = NIL THEN
    c.builder.ErrSym(IR.rangeError, op.sym);
    RETURN NIL
  ELSE
    RETURN c.builder.NewConst(op.sym, type, value)
  END
END ValueConst;

PROCEDURE (c : ConstFold) BooleanConst(value : BOOLEAN; op : IR.Operator) : IR.Const;
BEGIN
  RETURN c.builder.NewConst(op.sym, Predef.GetType(Predef.boolean), Boxed.NewBoolean(value));
END BooleanConst;

PROCEDURE (c : ConstFold) ValidEval (expr : IR.Expression; VAR result : Boxed.Object) : BOOLEAN;
BEGIN
  c.result := NIL;
  expr.Accept(c);
  IF (c.result # NIL) & (c.result # c.builder.errorExpr) THEN
    result := c.result(IR.Const).value;
    RETURN TRUE;
  END;
  RETURN FALSE;
END ValidEval;

PROCEDURE (c: ConstFold) VisitConst* (const: IR.Const);
  BEGIN
    c.result := const;
  END VisitConst;

PROCEDURE (c: ConstFold) VisitVar* (car: IR.Var);
  BEGIN
  END VisitVar;

PROCEDURE (c: ConstFold) VisitPredefProc* (pproc: IR.PredefProc);
  BEGIN
    (* FIXME! *)
  END VisitPredefProc;

PROCEDURE (c: ConstFold) VisitProcedureRef* (procRef: IR.ProcedureRef);
  BEGIN
  END VisitProcedureRef;

PROCEDURE (c: ConstFold) VisitTypeRef* (typeRef: IR.TypeRef);
  BEGIN
  END VisitTypeRef;

PROCEDURE (c: ConstFold) VisitModuleRef* (modRef: IR.ModuleRef);
  BEGIN
  END VisitModuleRef;

PROCEDURE (c: ConstFold) VisitAdr* (adr: IR.Adr);
  BEGIN
  END VisitAdr;

PROCEDURE (c: ConstFold) VisitLen* (len: IR.Len);
  VAR
    length: LONGINT;
    type: Sym.Type;
  BEGIN
    CASE len. variant OF
    | IR.lenStringConst:
      IF (len.array(IR.Const).value IS Boxed.String) THEN
        length := len.array(IR.Const).value(Boxed.String). value. length+1;
      ELSE                               (* there was an error with LEN *)
        length := 1;
      END;
      
    | IR.lenFixedArray:
      type := len. arrayVariable. type(Sym.Array). GetNthElementType (len.dim);
      length := type(Sym.Array).length;
      
    | IR.lenOpenArrayParam, IR.lenOpenArrayHeap:
      c.result := NIL; RETURN;
    END;
    c.result := c.builder.NewConst(len.sym, Predef.GetType(Predef.lengthType), 
      BigInt.NewInt(length));
  END VisitLen;

PROCEDURE (c: ConstFold) VisitConstructor* (cons: IR.Constructor);
  BEGIN
  END VisitConstructor;

PROCEDURE (c: ConstFold) VisitCurrentException* (ce: IR.CurrentException);
  BEGIN
  END VisitCurrentException;

PROCEDURE (c: ConstFold) VisitDeref* (deref: IR.Deref);
  BEGIN
    (* FIXME! *)
    (* index. array. Accept (c);
    index. index. Accept (c); *)
  END VisitDeref;

PROCEDURE (c: ConstFold) VisitIndex* (index: IR.Index);
  BEGIN
    (* FIXME! *)
    (* index. array. Accept (c);
    index. index. Accept (c); *)
  END VisitIndex;

PROCEDURE (c: ConstFold) VisitSetMember* (op: IR.SetMember);
  VAR 
    element : LONGINT; set : SET;
    e, s : Boxed.Object;
  BEGIN
    IF c.ValidEval(op.element, e) & c.ValidEval(op.set, s) THEN
      element := e(BigInt.BigInt).ToLongInt();
      set := s(Boxed.Set).value;
      c.result := c.BooleanConst(element IN set, op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetMember;

PROCEDURE (c: ConstFold) VisitSetRange* (op: IR.SetRange);
  VAR 
    left, right : LONGINT;
    l, r : Boxed.Object;
  BEGIN
    IF c.ValidEval(op.from, l) & c.ValidEval(op.to, r) THEN
      left := l(BigInt.BigInt).ToLongInt();
      right := r(BigInt.BigInt).ToLongInt();
      c.result := c.ValueConst(Boxed.NewSet({left..right}), op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetRange;

PROCEDURE (c: ConstFold) VisitSetOp* (op: IR.SetOp);
  VAR 
    l, r : Boxed.Object; 
    result : SET;
    left, right : SET; 
  BEGIN
    IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
      left := l(Boxed.Set).value; 
      right := r(Boxed.Set).value;
    
      CASE op.variant OF
      | IR.setUnion:     result := left + right;
      | IR.setDiff:      result := left - right;
      | IR.setIntersect: result := left * right;
      | IR.setSymDiff:   result := left / right;
      ELSE
        c.builder.ErrSym(IR.unknownOp, op.sym); 
        c.result := NIL; RETURN
      END;
      c.result := c.ValueConst(Boxed.NewSet(result), op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetOp;

PROCEDURE (c: ConstFold) VisitChangeElement* (op: IR.ChangeElement);
  BEGIN
  END VisitChangeElement;

PROCEDURE (c: ConstFold) VisitSelectField* (sf: IR.SelectField);
  BEGIN
  END VisitSelectField;

PROCEDURE (c: ConstFold) VisitSelectProc* (sp: IR.SelectProc);
  BEGIN
  END VisitSelectProc;

PROCEDURE (c: ConstFold) VisitNegate* (op: IR.Negate);
VAR 
  id : Sym.PredefId;
  value : Boxed.Object;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    id := op.operand.type(Sym.PredefType).id;
    CASE id OF
    | Predef.shortint .. Predef.real-1:
      c.result := c.ValueConst(value(BigInt.BigInt).Neg(), op);
    | Predef.set:
      c.result := c.ValueConst(Boxed.NewSet(-value(Boxed.Set).value), op);
    | Predef.real, Predef.longreal:
      IF foldReals THEN
        c.result := c.ValueConst(value(Boxed.LongReal).Neg(), op);
      ELSE
        c.result := NIL;
      END;
    ELSE
      c.builder.ErrSym(IR.incompatibleTypes, op.sym);
      c.result := NIL;
    END;
  ELSE
    c.result := NIL;
  END;
END VisitNegate;

PROCEDURE (c: ConstFold) VisitNewBlock* (new: IR.NewBlock);
  BEGIN
  END VisitNewBlock;

PROCEDURE (c: ConstFold) VisitNewObject* (new: IR.NewObject);
  BEGIN
  END VisitNewObject;

PROCEDURE (c: ConstFold) VisitNot* (op: IR.Not);
VAR 
  value : Boxed.Object;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    c.result := c.BooleanConst(~value(Boxed.Boolean).value, op);
  ELSE
    c.result := NIL;
  END;
END VisitNot;

PROCEDURE (c: ConstFold) VisitAbs* (op: IR.Abs);
  BEGIN
    (* FIXME... *)
  END VisitAbs;

PROCEDURE (c: ConstFold) VisitAsh* (op: IR.Ash);
  VAR
    v, e: Boxed.Object;
    shift: LONGINT;
  BEGIN
    IF c.ValidEval(op.value, v) & c.ValidEval(op.exp, e) THEN
      shift := e(BigInt.BigInt).ToLongInt();
      IF (shift < 0) THEN
        c.result := c. ValueConst (v(BigInt.BigInt). RShift (-shift), op);
      ELSE
        c.result := c. ValueConst (v(BigInt.BigInt). LShift (shift), op);
      END;
    ELSE
      c.result := NIL;
    END;
  END VisitAsh;

PROCEDURE (c: ConstFold) VisitCap* (op: IR.Cap);
VAR 
  value : Boxed.Object;
  str: ARRAY 2 OF CHAR;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    str[0] := CAP(SHORT(SHORT(value(Boxed.String).value.CharAt(0))));
    str[1] := 0X;
    c.result := c.builder.NewConst(op.sym, Predef.GetType(Predef.char), 
                                   Boxed.NewString(Object.NewLatin1(str)));
  ELSE
    c.result := NIL;
  END;
END VisitCap;

PROCEDURE (c: ConstFold) VisitEntier* (op: IR.Entier);
  VAR
    value: Boxed.Object;
    i: LONGINT;
  BEGIN
    IF c.ValidEval(op.operand, value) THEN
      i := ENTIER(value(Boxed.LongReal).value);
      c.result := c.builder.NewConst(op.sym, Predef.GetType(Predef.longint), 
                                     BigInt.NewInt(i));
    ELSE
      c.result := NIL;
    END;
  END VisitEntier;

PROCEDURE (c: ConstFold) VisitOdd* (op: IR.Odd);
BEGIN
    (* FIXME! *)
END VisitOdd;

PROCEDURE (c: ConstFold) VisitShift* (op: IR.Shift);
  BEGIN
  END VisitShift;

PROCEDURE (c: ConstFold) VisitBinaryArith* (op: IR.BinaryArith);
VAR 
  l, r, result : Boxed.Object;

  PROCEDURE IntegerOp () : Boxed.Object;
  VAR
    left, right : BigInt.BigInt;
  BEGIN
    left := l(BigInt.BigInt);
    right := r(BigInt.BigInt);
    
    CASE op.variant OF
      (* FIXME! Properly check for overflow. *)
    | IR.arithAdd:  RETURN left.Add(right);
    | IR.arithSub:  RETURN left.Sub(right);
    | IR.arithMul:  RETURN left.Mul(right);
    | IR.arithDivI: 
      IF right.Sign() = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym);
      ELSE
        RETURN left.Div(right);
      END;
    | IR.arithMod:
      IF right.Sign() = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym);
      ELSE
        RETURN left.Mod(right);
      END;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym);
    END;
    RETURN NIL;
  END IntegerOp;

  PROCEDURE RealOp () : Boxed.Object;
  VAR
    left, right : Boxed.LongReal;
  BEGIN
    left := l(Boxed.LongReal);
    right := r(Boxed.LongReal);
    
    CASE op.variant OF
    | IR.arithAdd:  RETURN left.Add(right);
    | IR.arithSub:  RETURN left.Sub(right);
    | IR.arithMul:  RETURN left.Mul(right);
    | IR.arithDivR: 
      IF (right.value = 0) THEN
        c.builder.ErrSym(IR.divideByZero, op.sym);
      ELSE
        RETURN left.Div(right);
      END;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym);
    END;
    RETURN NIL;
  END RealOp;

BEGIN
  (* Evaluate left and right operands. Propagate any errors. *)
  IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
    IF TR.IsIntegerType(op.left.type) THEN
      result := IntegerOp();
    ELSE
      IF foldReals THEN
        result := RealOp();
      ELSE
        result := NIL;
      END;
    END;
    IF result # NIL THEN
      c.result := c.ValueConst(result, op);
      RETURN;
    END
  END;
  c.result := NIL;
END VisitBinaryArith;

PROCEDURE (c: ConstFold) VisitBooleanOp* (op: IR.BooleanOp);
  VAR 
    l, r : Boxed.Object;
    left, right, result : BOOLEAN;
  BEGIN
    IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
      left := l(Boxed.Boolean).value;
      right := r(Boxed.Boolean).value;
      CASE op.variant OF
      | IR.and:  result := left & right;
      | IR.or:   result := left OR right;
      END;
      c.result := c.BooleanConst(result, op);
    ELSE
      c.result := NIL;
    END;
  END VisitBooleanOp;

PROCEDURE (c: ConstFold) VisitConcat* (op: IR.Concat);
  VAR
    i: LONGINT;
    s: STRING;
  BEGIN
    s := Object.emptyString;
    FOR i := 0 TO LEN(op.strings^)-1 DO
      IF (op.strings[i] IS IR.Const) THEN
        s := s+op.strings[i](IR.Const).value(Boxed.String).value;
      ELSE
        c.result := NIL;
        RETURN;
      END;
    END;
    c.result := c.builder.NewConst(op.sym, op.type,
                                   Boxed.NewString(s));
  END VisitConcat;

PROCEDURE (c: ConstFold) VisitCompare* (op : IR.Compare);
  VAR l, r : Boxed.Object; result : Boxed.Boolean;

  PROCEDURE StringOp () : Boxed.Boolean;
  VAR
    left, right : Boxed.String; result : BOOLEAN;
  BEGIN
    left := l(Boxed.String);
    right := r(Boxed.String);
    CASE op.variant OF
    | IR.equal:        result := left.Cmp(right) = 0;
    | IR.notEqual:     result := left.Cmp(right) # 0;
    | IR.less:         result := left.Cmp(right) < 0;
    | IR.lessEqual:    result := left.Cmp(right) <= 0;
    | IR.greater:      result := left.Cmp(right) > 0;
    | IR.greaterEqual: result := left.Cmp(right) >= 0;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boxed.NewBoolean(result);
  END StringOp;

  PROCEDURE IntegerOp () : Boxed.Boolean;
  VAR
    left, right : BigInt.BigInt; result : BOOLEAN;
  BEGIN
    left := l(BigInt.BigInt); 
    right := r(BigInt.BigInt);
    
    CASE op.variant OF
    | IR.equal:        result := left.Cmp(right) = 0;
    | IR.notEqual:     result := left.Cmp(right) # 0;
    | IR.less:         result := left.Cmp(right) < 0;
    | IR.lessEqual:    result := left.Cmp(right) <= 0;
    | IR.greater:      result := left.Cmp(right) > 0;
    | IR.greaterEqual: result := left.Cmp(right) >= 0;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boxed.NewBoolean(result);
  END IntegerOp;

  PROCEDURE RealOp () : Boxed.Boolean;
  VAR
    left, right : Boxed.LongReal; result : BOOLEAN;
  BEGIN
    left := l(Boxed.LongReal); 
    right := r(Boxed.LongReal);
    
    CASE op.variant OF
    | IR.equal:        result := left.Cmp(right) = 0;
    | IR.notEqual:     result := left.Cmp(right) # 0;
    | IR.less:         result := left.Cmp(right) < 0;
    | IR.lessEqual:    result := left.Cmp(right) <= 0;
    | IR.greater:      result := left.Cmp(right) > 0;
    | IR.greaterEqual: result := left.Cmp(right) >= 0;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boxed.NewBoolean(result);
  END RealOp;

  PROCEDURE CharOp () : Boxed.Boolean;
  VAR
    left, right : UCS4CHAR; result : BOOLEAN;
  BEGIN
    left := l(Boxed.String).value.CharAt(0);
    right := r(Boxed.String).value.CharAt(0);
    
    CASE op.variant OF
    | IR.equal:        result := left = right;
    | IR.notEqual:     result := left # right;
    | IR.less:         result := left < right;
    | IR.lessEqual:    result := left <= right;
    | IR.greater:      result := left > right;
    | IR.greaterEqual: result := left >= right;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boxed.NewBoolean(result);
  END CharOp;

  PROCEDURE BooleanOp () : Boxed.Boolean;
  VAR
    left, right : BOOLEAN; result : BOOLEAN;
  BEGIN
    left := l(Boxed.Boolean).value;
    right := r(Boxed.Boolean).value;

    CASE op.variant OF
    | IR.equal:        result := left = right;
    | IR.notEqual:     result := left # right;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boxed.NewBoolean(result);
  END BooleanOp;

  PROCEDURE SetOp(): Boxed.Boolean;
    VAR
      left, right: Boxed.Set;
      result: BOOLEAN;
    BEGIN
      left := l(Boxed.Set);
      right := r(Boxed.Set);
      
      CASE op.variant OF
      | IR.equal:        result := left.Equals(right);
      | IR.notEqual:     result := ~left.Equals(right);
      ELSE
        c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
      END;
      RETURN Boxed.NewBoolean(result);
    END SetOp;

  BEGIN
    IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
      CASE op.left.type(Sym.PredefType).id OF
      | Predef.shortint, Predef.integer, Predef.longint:
        result := IntegerOp();
      | Predef.real, Predef.longreal:
        IF foldReals THEN
          result := RealOp();
        ELSE
          result := NIL;
        END;
      | Predef.char:
        result := CharOp();
      | Predef.stringChar, Predef.stringLongChar, Predef.stringUCS4Char:
        result := StringOp(); 
      | Predef.boolean:
        result := BooleanOp();
      | Predef.set:
        result := SetOp();
      END;
      IF result = NIL THEN 
        c.result := NIL
      ELSE
        c.result := c.BooleanConst(result.value, op);
      END;
    ELSE
      c.result := NIL
    END
  END VisitCompare;

PROCEDURE (c: ConstFold) VisitTypeCast* (op : IR.TypeCast);
  BEGIN
    (* it's probably best to not fold any casts at all *)
  END VisitTypeCast;

PROCEDURE (c: ConstFold) VisitTypeConv* (op : IR.TypeConv);
  VAR
    value: Boxed.Object;
    str: Boxed.String;
  BEGIN
    (* FIXME... this needs to be made "safe": if there is no code
       that performs the required type conversion, then "op"
       is always returned *)
    (* FIXME... make sure that overflows are handled correctly;
       one way to deal with them is to _not_ convert and make
       it a run-time problems; not nice, but cheap ;- *)
    IF c.ValidEval(op.expr, value) THEN
      IF TR.IsIntegerType (op. type) &
         TR.IsCharType (op. expr. type) THEN
        (* type conversion from character to integer value (ORD) *)
        value := BigInt.NewInt(ORD(value(Boxed.String).value.CharAt(0)));
        c.result := c. builder. NewConst (op. sym, op. type, value);
        
      ELSIF TR.IsCharType (op. type) &
            TR.IsIntegerType (op. expr. type) THEN
        (* type conversion from integer to character value (CHR, LONGCHR,
           UCS4CHAR) *)
        CASE op. type(Sym.PredefType). id OF
        | Predef.char:
          value := Boxed.NewString(Object.NewLatin1Char(CHR (value(BigInt.BigInt). ToLongInt())));
        | Predef.longchar:
          value := Boxed.NewString(Object.NewUTF16Char(LONGCHR (value(BigInt.BigInt). ToLongInt())));
        | Predef.ucs4char:
          value := Boxed.NewString(Object.NewUCS4Char(UCS4CHR (value(BigInt.BigInt). ToLongInt())));
        END;
        c.result := c. builder. NewConst (op. sym, op. type, value);
        
      ELSIF TR.IsIntegerType(op.expr.type) & TR.IsRealType(op.type) THEN
        (* type conversion integer -> real *)
        value := Boxed.NewLongReal(value(BigInt.BigInt).ToLongInt());
        c.result := c.builder.NewConst(op.sym, op.type,value);
        
      ELSIF TR.IsCharType(op.type) & TR.IsCharType(op.expr.type) THEN
        (* type conversion between character types is a noop *)
        c. result := c. builder. NewConst (op. expr. sym, op. type, value);
        
      ELSIF TR.IsStringConst (op. type) THEN
        (* handle conversion of character and string constants to string
           constants *)
        ASSERT (TR.IsStringConst (op. expr. type) OR
                (op. expr IS IR.Const) & TR.IsCharType (op. expr. type));
        str := op. expr(IR.Const). value(Boxed.String);
        c. result := c. builder. NewConst (op. expr. sym, op. type, str);
        
      ELSE
        c.result := c.builder.NewConst(op.sym, op.type, value)
      END;
    ELSE
      c.result := NIL;
    END;
  END VisitTypeConv;

PROCEDURE (c: ConstFold) VisitTypeGuard* (op : IR.TypeGuard);
  BEGIN
  END VisitTypeGuard;

PROCEDURE (c: ConstFold) VisitTypeTag* (op : IR.TypeTag);
  BEGIN
  END VisitTypeTag;

PROCEDURE (c: ConstFold) VisitTypeTest* (op : IR.TypeTest);
  BEGIN
  END VisitTypeTest;

PROCEDURE (c: ConstFold) VisitCall* (call: IR.Call);
  BEGIN
  END VisitCall;

PROCEDURE (c: ConstFold) VisitAssert* (assert: IR.Assert);
  BEGIN
  END VisitAssert;

PROCEDURE (c: ConstFold) VisitReturn* (return: IR.Return);
  BEGIN
  END VisitReturn;

PROCEDURE (c: ConstFold) VisitAssignment* (assignment: IR.Assignment);
  BEGIN
  END VisitAssignment;

PROCEDURE (c: ConstFold) VisitAssignOp* (assignOp: IR.AssignOp);
  BEGIN
  END VisitAssignOp;

PROCEDURE (c: ConstFold) VisitExit* (exit: IR.Exit);
  BEGIN
  END VisitExit;

PROCEDURE (c: ConstFold) VisitForStatm* (forStatm: IR.ForStatm);
  BEGIN
  END VisitForStatm;

PROCEDURE (c: ConstFold) VisitIterateArrayStatm* (iterStatm: IR.IterateArrayStatm);
  BEGIN
  END VisitIterateArrayStatm;

PROCEDURE (c: ConstFold) VisitIterateObjectStatm* (iterStatm: IR.IterateObjectStatm);
  BEGIN
  END VisitIterateObjectStatm;

PROCEDURE (c: ConstFold) VisitIfStatm* (ifStatm: IR.IfStatm);
  BEGIN
  END VisitIfStatm;

PROCEDURE (c: ConstFold) VisitCase* (case: IR.Case);
  BEGIN
  END VisitCase;

PROCEDURE (c: ConstFold) VisitCaseStatm* (caseStatm: IR.CaseStatm);
  BEGIN
  END VisitCaseStatm;

PROCEDURE (c: ConstFold) VisitLoopStatm* (loopStatm: IR.LoopStatm);
  BEGIN
  END VisitLoopStatm;

PROCEDURE (c: ConstFold) VisitMoveBlock* (move: IR.MoveBlock);
  BEGIN
  END VisitMoveBlock;

PROCEDURE (c: ConstFold) VisitRaise* (raise: IR.Raise);
  BEGIN
  END VisitRaise;

PROCEDURE (c: ConstFold) VisitRepeatStatm* (repeatStatm: IR.RepeatStatm);
  BEGIN
  END VisitRepeatStatm;

PROCEDURE (c: ConstFold) VisitCatchClause* (catch: IR.CatchClause);
  BEGIN
  END VisitCatchClause;

PROCEDURE (c: ConstFold) VisitTryStatm* (tryStatm: IR.TryStatm);
  BEGIN
  END VisitTryStatm;

PROCEDURE (c: ConstFold) VisitWhileStatm* (whileStatm: IR.WhileStatm);
  BEGIN
  END VisitWhileStatm;

PROCEDURE (c: ConstFold) VisitWithStatm* (withStatm: IR.WithStatm);
  BEGIN
  END VisitWithStatm;

PROCEDURE (c: ConstFold) VisitCopy* (cp: IR.Copy);
  BEGIN
  END VisitCopy;

PROCEDURE (c: ConstFold) VisitCopyParameter* (cp: IR.CopyParameter);
  BEGIN
  END VisitCopyParameter;

PROCEDURE (c: ConstFold) VisitCopyString* (cp: IR.CopyString);
  BEGIN
  END VisitCopyString;


PROCEDURE (c: ConstFold) VisitProcedure* (procedure: IR.Procedure);
  BEGIN
  END VisitProcedure;

PROCEDURE (c: ConstFold) VisitModule* (module: IR.Module);
  BEGIN
  END VisitModule;

END OOC:IR:ConstFold.
