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
  Language:Integer, Language:Boolean, LString := Language:String,
  Language:String8, 
  Language:Set, Language:Real,
  ADT:String;

TYPE
  ConstFold = POINTER TO ConstFoldDesc;
  ConstFoldDesc = RECORD
    (IR.ConstFoldDesc)
  END;

CONST
  (* To enable constant folding for REAL expressions, set foldReals TRUE. Even
  better, allow it to be enabled/disabled at run-time *)
  foldReals = FALSE;

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
BEGIN
  WITH value : Integer.Value DO
    RETURN Predef.SmallestIntType (value);
  | value : Real.Value DO
    (* FIXME! Figure out the appropriate REAL type *)
    RETURN Predef.GetType(Predef.real);
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
  VAR
    length: LONGINT;
    type: Sym.Type;
  BEGIN
    CASE len. variant OF
    | IR.lenStringConst:
      length := len.array(IR.Const).value(LString.Value). Length()+1;
      
    | IR.lenFixedArray:
      type := len. arrayVariable. type(Sym.Array). GetNthElementType (len.dim);
      length := type(Sym.Array).length;
      
    | IR.lenOpenArrayParam, IR.lenOpenArrayHeap:
      c.result := NIL; RETURN;
    END;
    c.result := c.builder.NewConst(len.sym, Predef.GetType(Predef.lengthType), 
      Integer.New(length));
  END VisitLen;

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
    e, s : Language.Value;
  BEGIN
    IF c.ValidEval(op.element, e) & c.ValidEval(op.set, s) THEN
      element := e(Integer.Value).ToInt();
      set := s(Set.Value).value;
      c.result := c.BooleanConst(element IN set, op);
    ELSE
      c.result := NIL;
    END;
  END VisitSetMember;

PROCEDURE (c: ConstFold) VisitSetRange* (op: IR.SetRange);
  VAR 
    left, right : LONGINT;
    l, r : Language.Value;
  BEGIN
    IF c.ValidEval(op.from, l) & c.ValidEval(op.to, r) THEN
      left := l(Integer.Value).ToInt();
      right := r(Integer.Value).ToInt();
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

PROCEDURE (c: ConstFold) VisitSelectProc* (sp: IR.SelectProc);
  BEGIN
  END VisitSelectProc;

PROCEDURE (c: ConstFold) VisitNegate* (op: IR.Negate);
VAR 
  id : Sym.PredefId;
  value : Language.Value;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    id := op.operand.type(Sym.PredefType).id;
    CASE id OF
    | Predef.shortint .. Predef.real-1:
      c.result := c.ValueConst(value(Integer.Value).Negate(), op);
    | Predef.set:
      c.result := c.ValueConst(Set.New(-value(Set.Value).value), op);
    | Predef.real, Predef.longreal:
      IF foldReals THEN
        c.result := c.ValueConst(value(Real.Value).Negate(), op);
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

PROCEDURE (c: ConstFold) VisitNewObject* (new: IR.NewObject);
  BEGIN
  END VisitNewObject;

PROCEDURE (c: ConstFold) VisitNot* (op: IR.Not);
VAR 
  value : Language.Value;
BEGIN
  IF c.ValidEval(op.operand, value) THEN
    c.result := c.BooleanConst(~value(Boolean.Value).value, op);
  ELSE
    c.result := NIL;
  END;
END VisitNot;

PROCEDURE (c: ConstFold) VisitAsh* (op: IR.Ash);
  VAR
    v, e: Integer.Value;
  BEGIN
    v := op. value(IR.Const). value(Integer.Value);
    e := op. exp(IR.Const). value(Integer.Value);
    c. result := c. ValueConst (v. Ash (e), op);
  END VisitAsh;

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

PROCEDURE (c: ConstFold) VisitEntier* (op: IR.Entier);
BEGIN
    (* FIXME! *)
END VisitEntier;

PROCEDURE (c: ConstFold) VisitOdd* (op: IR.Odd);
BEGIN
    (* FIXME! *)
END VisitOdd;

PROCEDURE (c: ConstFold) VisitBinaryArith* (op: IR.BinaryArith);
VAR 
  l, r, result : Language.Value;

  PROCEDURE IntegerOp () : Language.Value;
  VAR
    left, right : Integer.Value;
  BEGIN
    left := l(Integer.Value);
    right := r(Integer.Value);
    
    CASE op.variant OF
      (* FIXME! Properly check for overflow. *)
    | IR.arithAdd:  RETURN left.Sum(right);
    | IR.arithSub:  RETURN left.Difference(right);
    | IR.arithMul:  RETURN left.Product(right);
    | IR.arithDivI: 
      IF right.Sign() = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym);
      ELSE
        RETURN left.Quotient(right);
      END;
    | IR.arithMod:
      IF right.Sign() = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym);
      ELSE
        RETURN left.Remainder(right);
      END;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym);
    END;
    RETURN NIL;
  END IntegerOp;

  PROCEDURE RealOp () : Language.Value;
  VAR
    left, right : Real.Value;
  BEGIN
    left := l(Real.Value);
    right := r(Real.Value);
    
    CASE op.variant OF
    | IR.arithAdd:  RETURN left.Sum(right);
    | IR.arithSub:  RETURN left.Difference(right);
    | IR.arithMul:  RETURN left.Product(right);
    | IR.arithDivR: 
      IF right.Sign() = 0 THEN
        c.builder.ErrSym(IR.divideByZero, op.sym);
      ELSE
        RETURN left.Quotient(right);
      END;
    ELSE
      c.builder.ErrSym(IR.unknownOp, op.sym);
    END;
    RETURN NIL;
  END RealOp;

BEGIN
  (* Evaluate left and right operands. Propagate any errors. *)
  IF c.ValidEval(op.left, l) & c.ValidEval(op.right, r) THEN
    (* for now, only support integers *)
    CASE op.left.type(Sym.PredefType).id OF
    | Predef.shortint, Predef.integer, Predef.longint:
      result := IntegerOp();
    | Predef.real, Predef.longreal:
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
    left, right : Integer.Value; result : BOOLEAN;
  BEGIN
    left := l(Integer.Value); 
    right := r(Integer.Value);
    
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
  END IntegerOp;

  PROCEDURE RealOp () : Boolean.Value;
  VAR
    left, right : Real.Value; result : BOOLEAN;
  BEGIN
    left := l(Real.Value); 
    right := r(Real.Value);
    
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
  END RealOp;

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
      | Predef.real, Predef.longreal:
        IF foldReals THEN
          result := RealOp();
        ELSE
          result := NIL;
        END;
      | Predef.char:
        result := CharOp();
      | Predef.charString:
        result := StringOp(); 
      | Predef.boolean:
        result := BooleanOp();
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
    (* FIXME... this needs to be made "safe": if there is no code
       that performs the required type conversion, then "op"
       is always returned *)
    (* FIXME... make sure that overflows are handled correctly;
       one way to deal with them is to _not_ convert and make
       it a run-time problems; not nice, but cheap ;- *)
    IF c.ValidEval(op.expr, value) THEN
      IF c. builder. typeRules. IsIntegerType (op. type) &
         c. builder. typeRules. IsCharType (op. expr. type) THEN
        (* type conversion from character to integer value (ORD) *)
        value := Integer.New (ORD (value(String8.Value). value. array[0]));
        c.result := c. builder. NewConst (op. sym, op. type, value);
      ELSIF c. builder. typeRules. IsCharType (op. type) &
            c. builder. typeRules. IsIntegerType (op. expr. type) THEN
        (* type conversion from integer to character value (CHR) *)
        value := String8.NewChar (CHR (value(Integer.Value). ToInt()));
        c.result := c. builder. NewConst (op. sym, op. type, value);
      ELSIF c. builder. typeRules. IsRealType (op. type) &
            c. builder. typeRules. IsIntegerType (op. expr. type) THEN
        c.result := NIL;
      END;
      c.result := c.builder.NewConst(op.sym, op.type, value)
    ELSE
      c.result := NIL;
    END;
  END VisitTypeConv;

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

PROCEDURE (c: ConstFold) VisitRepeatStatm* (repeatStatm: IR.RepeatStatm);
  BEGIN
  END VisitRepeatStatm;

PROCEDURE (c: ConstFold) VisitWhileStatm* (whileStatm: IR.WhileStatm);
  BEGIN
  END VisitWhileStatm;

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
