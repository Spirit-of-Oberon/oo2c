(* 	$Id$	 *)
MODULE OOC:IR:ConstFold;
(*  Constant folding on IR expressions.
    Copyright (C) 2002  Stewart Greenhill, Michael van Acken

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
  Language, 
  Language:Integer, Language:Boolean, Language:String8, Language:Char8,
  Language:Set,
  ADT:String, Integers;

TYPE
  ConstFold = POINTER TO ConstFoldDesc;
  ConstFoldDesc = RECORD
    (IR.ConstFoldDesc)
  END;

CONST
  maxIntegerTypes = 5;

TYPE
  IntegerType = RECORD
    low, high : Integers.Integer;
    id : Sym.PredefId;
  END;

VAR
  minus1, zero : Integers.Integer;
  nIntegerTypes : INTEGER;
  integerType : ARRAY maxIntegerTypes OF IntegerType;

PROCEDURE AddIntegerType(id : Sym.PredefId; low, high : ARRAY OF CHAR);
BEGIN
  Integers.ConvertFromString(low, integerType[nIntegerTypes].low);
  Integers.ConvertFromString(high, integerType[nIntegerTypes].high);
  integerType[nIntegerTypes].id := id;
  INC(nIntegerTypes);
END AddIntegerType;

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

PROCEDURE SmallestType(value : Language.Value) : Sym.Type;
(**Return the smallest type that can represent @oparam{value}. *)
VAR i : INTEGER;
BEGIN
  WITH value : Integer.Value DO
    FOR i := 0 TO nIntegerTypes-1 DO
      IF (Integers.Compare(value.value, integerType[i].low) >= 0)
       & (Integers.Compare(value.value, integerType[i].high) <= 0) THEN
        RETURN Predef.GetType(integerType[i].id)
      END;
    END;
    RETURN NIL; 
  | value : Set.Value DO
    (* FIXME! Figure out the appropriate SET type *)
    RETURN Predef.GetType(Predef.set);
  END;
END SmallestType;

PROCEDURE (c : ConstFold) ValueConst(value : Language.Value; op : IR.Operator) : IR.Const;
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
  RETURN c.builder.NewConst(op.sym, Predef.GetType(Predef.boolean), Boolean.New(value));
END BooleanConst;

PROCEDURE (c : ConstFold) ValidEval (expr : IR.Expression; VAR result : Language.Value) : BOOLEAN;
BEGIN
  c.result := NIL;
  expr.Accept(c);
  IF c.result # NIL THEN
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
  VAR length : LONGINT;
  BEGIN
    (* FIXME! Implement lenFixedArray, but how do we get its length? . *)
    CASE len. variant OF
    | IR.lenStringConst:
      length := len.array(IR.Const).value(String8.Value).value.length+1;
    | IR.lenFixedArray:
      length := len.array.type(Sym.Array).length;
    | IR.lenOpenArrayParam, IR.lenOpenArrayHeap:
      c.result := NIL; RETURN;
    END;
    c.result := c.builder.NewConst(len.sym, Predef.GetType(Predef.lengthType), 
      Integer.NewLInt(length));
  END VisitLen;

PROCEDURE (c: ConstFold) VisitIndex* (index: IR.Index);
  BEGIN
    (* FIXME! *)
    (* index. array. Accept (c);
    index. index. Accept (c); *)
  END VisitIndex;

PROCEDURE (c: ConstFold) VisitSetMember* (op: IR.SetMember);
  VAR 
    i, element : LONGINT; set : SET;
    e, s : Language.Value;
  BEGIN
    IF c.ValidEval(op.element, e) & c.ValidEval(op.set, s) THEN
      element := e(Integer.Value).ToLInt();
      set := s(Set.Value).value;
      c.result := c.BooleanConst(element IN set, op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetMember;

PROCEDURE (c: ConstFold) VisitSetRange* (op: IR.SetRange);
  VAR 
    i, left, right : LONGINT;
    l, r : Language.Value;
  BEGIN
    IF c.ValidEval(op.from, l) & c.ValidEval(op.to, r) THEN
      left := l(Integer.Value).ToLInt();
      right := r(Integer.Value).ToLInt();
      c.result := c.ValueConst(Set.New({left..right}), op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetRange;

PROCEDURE (c: ConstFold) VisitSetOp* (op: IR.SetOp);
  VAR 
    l, r : Language.Value; 
    result : SET;
    left, right : SET; 
  BEGIN
    IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
      left := l(Set.Value).value; 
      right := r(Set.Value).value;
    
      CASE op.variant OF
      | IR.setUnion:     result := left + right;
      | IR.setDiff:      result := left - right;
      | IR.setIntersect: result := left * right;
      | IR.setSymDiff:   result := left / right;
      ELSE
        c.builder.ErrSym(IR.unknownOp, op.sym); 
        c.result := NIL; RETURN
      END;
      c.result := c.ValueConst(Set.New(result), op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetOp;

PROCEDURE (c: ConstFold) VisitSelectField* (sf: IR.SelectField);
  BEGIN
  END VisitSelectField;

PROCEDURE (c: ConstFold) VisitNegate* (op: IR.Negate);
VAR 
  id : Sym.PredefId;
  value : Language.Value;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    id := op.operand.type(Sym.PredefType).id;
    CASE id OF
    | Predef.boolean:
        c.result := c.BooleanConst(~value(Boolean.Value).value, op);
    | Predef.integer:
      value := Integer.New(Integers.Product(minus1, value(Integer.Value).value));

      c.result := c.ValueConst(value, op);
    | Predef.set:
      c.result := c.ValueConst(Set.New(-value(Set.Value).value), op);
    ELSE
      c.builder.ErrSym(IR.incompatibleTypes, op.sym);
      c.result := NIL;
    END;
  ELSE
    c.result := NIL;
  END;
END VisitNegate;

PROCEDURE (c: ConstFold) VisitCap* (op: IR.Cap);
VAR 
  value : Language.Value;
  str: ARRAY 2 OF CHAR;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    str[0] := CAP (value(String8.Value).value.array[0]);
    str[1] := 0X;
    c.result := c.builder.NewConst(op.sym, Predef.GetType(Predef.char), 
                                   String8.NewString (str));
  ELSE
    c.result := NIL;
  END;
END VisitCap;

PROCEDURE (c: ConstFold) VisitBinaryArith* (op: IR.BinaryArith);
VAR 
  l, r, result : Language.Value;

  PROCEDURE IntegerOp () : Language.Value;
  VAR
    result, left, right : Integers.Integer;
  BEGIN
    left := l(Integer.Value).value; 
    right := r(Integer.Value).value;
    
    CASE op.variant OF
      (* FIXME! Properly check for overflow. *)
    | IR.arithAdd:  result := Integers.Sum(left, right);
    | IR.arithSub:  result := Integers.Difference(left, right);
    | IR.arithMul:  result := Integers.Product(left, right);
    | IR.arithDivI: 
      IF Integers.Compare(right, zero) = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym); RETURN NIL;
      ELSE
        result := Integers.Quotient(left, right);
      END;
    | IR.arithMod:
      IF Integers.Compare(right, zero) = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym); RETURN NIL;
      ELSE
        result := Integers.Remainder(left, right);
      END;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Integer.type.Value(result);
  END IntegerOp;

BEGIN
  (* Evaluate left and right operands. Propagate any errors. *)
  IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
    (* for now, only support integers *)
    result := IntegerOp();

    IF result # NIL THEN
      c.result := c.ValueConst(result, op);
      RETURN;
    END
  END;
  c.result := NIL;
END VisitBinaryArith;

PROCEDURE (c: ConstFold) VisitBooleanOp* (op: IR.BooleanOp);
  VAR 
    l, r : Language.Value;
    left, right, result : BOOLEAN;
  BEGIN
    IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
      left := l(Boolean.Value).value;
      right := r(Boolean.Value).value;
      CASE op.variant OF
      | IR.and:  result := left & right;
      | IR.or:   result := left OR right;
      END;
      c.result := c.BooleanConst(result, op);
    ELSE
      c.result := NIL;
    END;
  END VisitBooleanOp;

PROCEDURE (c: ConstFold) VisitCompare* (op : IR.Compare);
  VAR l, r : Language.Value; result : Boolean.Value;

  PROCEDURE StringOp () : Boolean.Value;
  VAR
    left, right : String.String; result : BOOLEAN;
  BEGIN
    left := l(String8.Value).value; 
    right := r(String8.Value).value;
    CASE op.variant OF
    | IR.equal:        result := left.Compare(right) = 0;
    | IR.notEqual:     result := left.Compare(right) # 0;
    | IR.less:         result := left.Compare(right) < 0;
    | IR.lessEqual:    result := left.Compare(right) <= 0;
    | IR.greater:      result := left.Compare(right) > 0;
    | IR.greaterEqual: result := left.Compare(right) >= 0;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boolean.New(result);
  END StringOp;

  PROCEDURE IntegerOp () : Boolean.Value;
  VAR
    left, right : Integers.Integer; result : BOOLEAN;
  BEGIN
    left := l(Integer.Value).value; 
    right := r(Integer.Value).value;
    
    CASE op.variant OF
    | IR.equal:        result := Integers.Compare(left, right) = 0;
    | IR.notEqual:     result := Integers.Compare(left, right) # 0;
    | IR.less:         result := Integers.Compare(left, right) < 0;
    | IR.lessEqual:    result := Integers.Compare(left, right) <= 0;
    | IR.greater:      result := Integers.Compare(left, right) > 0;
    | IR.greaterEqual: result := Integers.Compare(left, right) >= 0;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boolean.New(result);
  END IntegerOp;

  PROCEDURE CharOp () : Boolean.Value;
  VAR
    left, right : CHAR; result : BOOLEAN;
  BEGIN
    left := l(String8.Value).value.GetChar(0);
    right := r(String8.Value).value.GetChar(0);

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
    RETURN Boolean.New(result);
  END CharOp;

  PROCEDURE BooleanOp () : Boolean.Value;
  VAR
    left, right : BOOLEAN; result : BOOLEAN;
  BEGIN
    left := l(Boolean.Value).value;
    right := r(Boolean.Value).value;

    CASE op.variant OF
    | IR.equal:        result := left = right;
    | IR.notEqual:     result := left # right;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym); RETURN NIL;
    END;
    RETURN Boolean.New(result);
  END BooleanOp;

  BEGIN
    IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
      CASE op.left.type(Sym.PredefType).id OF
      | Predef.shortint, Predef.integer, Predef.longint:
                             result := IntegerOp();
      | Predef.char:         result := CharOp();
      | Predef.charString:   result := StringOp(); 
      | Predef.boolean:      result := BooleanOp();
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

PROCEDURE (c: ConstFold) VisitTypeConv* (op : IR.TypeConv);
  VAR
    value : Language.Value;
  BEGIN
    IF c.ValidEval(op.expr, value) THEN
      c.result := c.builder.NewConst(op.sym, op.type, value)
    ELSE
      c.result := NIL;
    END;
  END VisitTypeConv;

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

PROCEDURE VisitStatementSeq (c: ConstFold; statmSeq: IR.StatementSeq);
  BEGIN
  END VisitStatementSeq;

PROCEDURE (c: ConstFold) VisitExit* (exit: IR.Exit);
  BEGIN
  END VisitExit;

PROCEDURE (c: ConstFold) VisitForStatm* (forStatm: IR.ForStatm);
  BEGIN
  END VisitForStatm;

PROCEDURE (c: ConstFold) VisitIfStatm* (ifStatm: IR.IfStatm);
  BEGIN
  END VisitIfStatm;

PROCEDURE (c: ConstFold) VisitLoopStatm* (loopStatm: IR.LoopStatm);
  BEGIN
  END VisitLoopStatm;

PROCEDURE (c: ConstFold) VisitRepeatStatm* (repeatStatm: IR.RepeatStatm);
  BEGIN
  END VisitRepeatStatm;

PROCEDURE (c: ConstFold) VisitWhileStatm* (whileStatm: IR.WhileStatm);
  BEGIN
  END VisitWhileStatm;

PROCEDURE (c: ConstFold) VisitCopyParameter* (cp: IR.CopyParameter);
  BEGIN
  END VisitCopyParameter;


PROCEDURE VisitProcedureList (c: ConstFold; procList: IR.ProcedureList);
  BEGIN
  END VisitProcedureList;

PROCEDURE (c: ConstFold) VisitProcedure* (procedure: IR.Procedure);
  BEGIN
  END VisitProcedure;

PROCEDURE (c: ConstFold) VisitModule* (module: IR.Module);
  BEGIN
  END VisitModule;

BEGIN
  nIntegerTypes := 0;
  AddIntegerType(Predef.shortint, "-128", "127");
  AddIntegerType(Predef.integer, "-32768", "32767");
  AddIntegerType(Predef.longint, "-2147483648", "2147483647");

  zero := Integers.Long(0);
  minus1 := Integers.Long(-1);
END OOC:IR:ConstFold.
