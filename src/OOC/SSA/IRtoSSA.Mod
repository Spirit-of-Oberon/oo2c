(* 	$Id$	 *)
MODULE OOC:SSA:IRtoSSA;
(*  Converts the IR of a procedure into its SSA representation.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Log, Integers, Language:String8, Language:Integer,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef, OOC:IR, 
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result;


PROCEDURE AddStoreBackwardFeed (pb: SSA.ProcBlock;
                                loopEnd: SSA.Instr; storeArg: SSA.Result);
  VAR
    collect: SSA.Instr;
  BEGIN
    (* install a pass-through collect instruction between `storeArg'
       and the use in `loopEnd'; the allocator code uses this instruction
       to mark some values as live across the whole loop *)
    collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
    collect. AddOpnd (storeArg, Opnd.store);
    loopEnd. AddOpnd (collect. AddResult (Result.store), Opnd.backwardFeed);
  END AddStoreBackwardFeed;

PROCEDURE StatmSeq* (pb: SSA.ProcBlock; s: SSA.Result;
                     statmSeq: IR.StatementSeq): SSA.Result;
(**Translates the statement sequence @oparam{statmSeq} into a straightforward
   SSA representation.  Instructions are added to the procedure block
   @oparam{pb}.  The initial value of @var{store} is taken from the argument
   @oparam{s}, the final value of @var{store} is the return value of the
   function.  *)
  VAR
    statm: IR.Statement;
    i: LONGINT;

  PROCEDURE Chain (instr: SSA.Instr);
    BEGIN
      IF (instr. opcode = Opcode.set) OR (instr. opcode = Opcode.newObject) THEN
        instr. opndList. ReplaceArg (s);
      ELSE
        instr. AddOpnd (s, Opnd.store);
      END;
      s := instr. AddResult (Result.store)
    END Chain;

  PROCEDURE ^ Call (call: IR.Call): SSA.Instr;
  PROCEDURE ^ Expression (expr: IR.Expression): SSA.Result;
    
  PROCEDURE RetrieveLength (pb: SSA.ProcBlock; variant: IR.Variant;
                            arrayVariable: IR.Expression; dim: LONGINT): SSA.Instr;
    VAR
      res: SSA.Result;
    BEGIN
      IF (variant = -1) THEN
        IF (arrayVariable IS IR.Var) THEN
          variant := IR.lenOpenArrayParam;
        ELSE
          variant := IR.lenOpenArrayHeap;
        END;
      END;
      
      CASE variant OF
      | IR.lenStringConst:
        ASSERT (arrayVariable. type(Sym.PredefType). id = Predef.charString);
        RETURN pb. GetConstInt (arrayVariable(IR.Const). value(String8.Value). value. length+1);
        
      | IR.lenOpenArrayParam, IR.lenOpenArrayHeap:
        res := Expression (arrayVariable);
        RETURN pb. AddGetLengthInstr (res(SSA.Instr), pb. GetConstInt (dim));
      END;
    END RetrieveLength;
  
  PROCEDURE CalculateSize (pb: SSA.ProcBlock; value: IR.Expression;
                           dim: LONGINT): SSA.Instr;
  (* Calculate the size of the variable @oparam{value} or of one of its
     elements.  With @oparam{dim=-1}, return the size of the whole variable.
     With @oparam{dim>=0}, return the size of an array element of dimension
     @oparam{dim}.  *)
    VAR
      type: Sym.Type;
      i: LONGINT;
      
    PROCEDURE RecursiveGetSize (type: Sym.Type; dim: LONGINT): SSA.Instr;
      VAR
        size: SSA.Instr;
      BEGIN
        IF (type IS Sym.Array) & type(Sym.Array). isOpenArray THEN
          size := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
          size. AddOpnd (RetrieveLength (pb, -1, value, dim+1), Opnd.arg);
          size. AddOpnd (RecursiveGetSize (type(Sym.Array). elementType,
                                           dim+1), Opnd.arg);
          RETURN size;
        ELSE
          RETURN pb. GetConstInt (type. size);
        END;
      END RecursiveGetSize;
    
    BEGIN
      (* if `value' is an index expression, normalize it to the array
         variable  *)
      WHILE (value IS IR.Index) DO
        value := value(IR.Index). array;
        INC (dim);
      END;
      
      (* get type of the value we are interested in *)
      type := value. type;
      FOR i := 0 TO dim DO
        type := type(Sym.Array). elementType;
      END;
      
      RETURN RecursiveGetSize (type, dim);
    END CalculateSize;
  
  PROCEDURE Expression (expr: IR.Expression): SSA.Result;
    VAR
      instr: SSA.Instr;
      res: SSA.Result;

    PROCEDURE Deref (deref: IR.Deref): SSA.Result;
      VAR
        instr: SSA.Instr;
        address: SSA.Result;
      BEGIN
        (* take the value of the pointer and use it to start a new "get"
           instruction *)
        address := Expression (deref. pointer);
        instr := pb. AddInstr (Opcode.get, 
                               Opcode.TypeToSubclass (deref. derefType));
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (address, Opnd.readAdr);
        instr. AddOpnd (address, Opnd.readDesign);
        RETURN instr
      END Deref;
    
    PROCEDURE Index (indexOp: IR.Index): SSA.Result;
      VAR
        instr, elementAdr, scaledIndex: SSA.Instr;
        baseResult, index: SSA.Result;
        adrOpnd: SSA.Opnd;
        elementType: Sym.Type;
      BEGIN
        (* take the "get" instruction of the array's designator and
           change it into a "get" for the array element *)
        baseResult := Expression (indexOp. array);
        ASSERT (baseResult. instr. opcode = Opcode.get);
        instr := baseResult. instr;
        index := Expression (indexOp. index);

        elementType := indexOp. type;
        scaledIndex := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
        scaledIndex. AddOpnd (index, Opnd.arg);
        scaledIndex. AddOpnd (CalculateSize (pb, indexOp, -1), Opnd.arg);
        
        adrOpnd := instr. opndList. nextOpnd;
        elementAdr := pb. AddInstr (Opcode.add, Opcode.scAddress);
        elementAdr. AddOpnd (adrOpnd. arg, Opnd.arg);
        elementAdr. AddOpnd (scaledIndex, Opnd. arg);
        adrOpnd. ReplaceArg (elementAdr);
        instr. AddOpnd (index, Opnd.readDesign);
        instr. SetSubclass (Opcode.TypeToSubclass (indexOp. type));

        RETURN instr
      END Index;
    
    PROCEDURE SelectField (selectOp: IR.SelectField): SSA.Result;
      VAR
        instr, fieldAdr: SSA.Instr;
        baseResult: SSA.Result;
        adrOpnd: SSA.Opnd;
      BEGIN
        (* take the "get" instruction of the record's designator and
           change it into a "get" for the record field *)
        baseResult := Expression (selectOp. record);
        ASSERT (baseResult. instr. opcode = Opcode.get);
        instr := baseResult. instr;
        
        adrOpnd := instr. opndList. nextOpnd;
        fieldAdr := pb. AddInstr (Opcode.add, Opcode.scAddress);
        fieldAdr. AddOpnd (adrOpnd. arg, Opnd.arg);
        fieldAdr. AddOpnd (pb. GetConstInt (selectOp. field. offset),
                             Opnd. arg);
        adrOpnd. ReplaceArg (fieldAdr);
        instr. AddOpnd (pb. GetDeclRef (selectOp. field), Opnd.readDesign);
        instr. SetSubclass (Opcode.TypeToSubclass (selectOp. field. type));
        
        RETURN instr
      END SelectField;
    
    PROCEDURE AddCompareOp (op: IR.Compare; class: Opcode.Class): SSA.Instr;
      VAR
        instr: SSA.Instr;
      BEGIN
        instr := pb. AddInstr (class, Opcode.scBoolean);
        instr. AddOpnd (Expression (op. left), Opnd.arg);
        instr. AddOpnd (Expression (op. right), Opnd.arg);
        RETURN instr
      END AddCompareOp;

    PROCEDURE NewObject (new: IR.NewObject): SSA.Instr;
      VAR
        instr: SSA.Instr;
        i: LONGINT;
      BEGIN
        instr := pb. AddInstr (Opcode.newObject, Opcode.scAddress);
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (pb. GetTypeRef (new. type), Opnd.type);
        IF (new. length # NIL) THEN
          FOR i := 0 TO LEN (new. length^)-1 DO
            instr. AddOpnd (Expression (new. length[i]), Opnd.arg);
          END;
        END;
        Chain (instr);
        RETURN instr;
      END NewObject;

    PROCEDURE ShortcutAnd (left, right: IR.Expression): SSA.Result;
      VAR
        select, collect: SSA.Instr;
        storeAfterGuard, bool: SSA.Result;
      BEGIN
        select := pb. AddInstr (Opcode.select, Opcode.scNone);
        select. AddOpnd (Expression (left), Opnd.arg);
        storeAfterGuard := s;
        
        select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
        bool := Expression (right);
        collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
        collect. AddOpnd (s, Opnd.store);
        collect. AddOpnd (bool, Opnd.arg);
        select. AddOpnd (collect. AddResult (Result.store), Opnd.arg);
        
        select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
        collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
        collect. AddOpnd (storeAfterGuard, Opnd.store);
        collect. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
        select. AddOpnd (collect. AddResult (Result.store), Opnd.arg);
        
        s := select. AddResult (Result.store);
        RETURN select. AddResultSubclass (Result.selectValue, Opcode.scBoolean)
      END ShortcutAnd;
    
    PROCEDURE ShortcutOr (left, right: IR.Expression): SSA.Result;
      VAR
        select, collect: SSA.Instr;
        storeAfterGuard, bool: SSA.Result;
      BEGIN
        select := pb. AddInstr (Opcode.select, Opcode.scNone);
        select. AddOpnd (Expression (left), Opnd.arg);
        storeAfterGuard := s;
        
        select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
        collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
        collect. AddOpnd (storeAfterGuard, Opnd.store);
        collect. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
        select. AddOpnd (collect. AddResult (Result.store), Opnd.arg);

        select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
        bool := Expression (right);
        collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
        collect. AddOpnd (s, Opnd.store);
        collect. AddOpnd (bool, Opnd.arg);
        select. AddOpnd (collect. AddResult (Result.store), Opnd.arg);
        
        s := select. AddResult (Result.store);
        RETURN select. AddResultSubclass (Result.selectValue, Opcode.scBoolean)
      END ShortcutOr;

    PROCEDURE TypeTag (design: IR.Expression): SSA.Instr;
      VAR
        var: SSA.Result;
        instr: SSA.Instr;
      BEGIN
        var := Expression (design);
        instr := pb. AddInstr (Opcode.typeTag, Opcode.scAddress);
        IF (design. type IS Sym.Pointer) THEN
          instr. AddOpnd (var, Opnd.arg);
        ELSIF (design IS IR.Var) &
              design(IR.Var). decl(Sym.VarDecl). isVarParam &
              (design(IR.Var). decl(Sym.VarDecl). type IS Sym.Record) THEN
          (* type tag of a VAR parameter *)
          instr. AddOpnd (var. instr. GetArgClass (Opnd.readDesign), Opnd.arg);
        ELSE                             (* static type tag *)
          instr. AddOpnd (pb. GetTypeRef (design. type), Opnd.arg);
        END;
        RETURN instr;
      END TypeTag;
    
    PROCEDURE TypeTest (test: IR.TypeTest): SSA.Instr;
      VAR
        instr: SSA.Instr; 
      BEGIN
        instr := pb. AddInstr (Opcode.typeTest, Opcode.scBoolean);
        instr. AddOpnd (TypeTag (test. expr), Opnd.arg);
        instr. AddOpnd (pb. GetTypeRef (test. referenceType), Opnd.type);
        RETURN instr
      END TypeTest;
    
    BEGIN
      WITH expr: IR.Const DO
        RETURN pb. GetConst (expr. value, expr. type)
            
      | expr: IR.ProcedureRef DO
        RETURN pb. GetAddress (expr. decl)

      | expr: IR.Var DO
        instr := pb. AddInstr (Opcode.get, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (pb. GetAddress (expr. decl), Opnd.readAdr);
        instr. AddOpnd (pb. GetDeclRef (expr. decl), Opnd.readDesign);
        RETURN instr

      | expr: IR.Adr DO
        res := Expression (expr. design);
        IF (res. instr. opcode = Opcode.get) THEN
          RETURN res. instr. GetArgClass (Opnd.readAdr);
        ELSE
          (* must be a string constant; currently, this is its own address
             FIXME... we should probably introduce an address opcode here *)
          RETURN res
        END;
        
      | expr: IR.Len DO
        RETURN RetrieveLength (pb, expr. variant,
                               expr. arrayVariable, expr. dim);

      | expr: IR.Deref DO
        RETURN Deref (expr);
        
      | expr: IR.Index DO
        RETURN Index (expr);

      | expr: IR.SelectField DO
        RETURN SelectField (expr);
        
      | expr: IR.TypeConv DO
        (* FIXME... right now, we are simply passing through type converted
           values *)
        RETURN Expression (expr. expr);

      | expr: IR.TypeTag DO
        RETURN TypeTag (expr. design);
      | expr: IR.TypeTest DO
        RETURN TypeTest (expr);
        
      | expr: IR.Negate DO
        instr := pb. AddInstr (Opcode.negate,
                               Opcode.TypeToSubclass (expr. operand. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr
            
      | expr: IR.Cap DO
        instr := pb. AddInstr (Opcode.cap,
                               Opcode.TypeToSubclass (expr. operand. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr
            
      | expr: IR.BinaryArith DO
        CASE expr.variant OF
        | IR.arithAdd:
          instr := pb. AddInstr (Opcode.add,
                                 Opcode.TypeToSubclass (expr. left. type));

        | IR.arithSub:
          instr := pb. AddInstr (Opcode.subtract,
                                 Opcode.TypeToSubclass (expr. left. type));
          
        | IR.arithMul:
          instr := pb. AddInstr (Opcode.multiply,
                                 Opcode.TypeToSubclass (expr. left. type));
          
        ELSE
          Log.Int("++ Unknown variant of BinaryArith in Expression",
                  expr. variant);
          ASSERT (FALSE);
        END;
        instr. AddOpnd (Expression (expr. left), Opnd.arg);
        instr. AddOpnd (Expression (expr. right), Opnd.arg);
        RETURN instr

      | expr: IR.BooleanOp DO
        CASE expr.variant OF
        | IR.and:
          RETURN ShortcutAnd (expr. left, expr. right);
        | IR.or:
          RETURN ShortcutOr (expr. left, expr. right);
        ELSE
          Log.Type("++ Unknown variant of BooleanOp in Expression", expr);
          ASSERT (FALSE);
        END;
        
      | expr: IR.Compare DO
        CASE expr.variant OF
        | IR.equal:
          RETURN AddCompareOp (expr, Opcode.eql);
        | IR.notEqual:
          RETURN AddCompareOp (expr, Opcode.neq);
        | IR.less:
          RETURN AddCompareOp (expr, Opcode.lss);
        | IR.lessEqual:
          RETURN AddCompareOp (expr, Opcode.leq);
        | IR.greater:
          RETURN AddCompareOp (expr, Opcode.gtr);
        | IR.greaterEqual:
          RETURN AddCompareOp (expr, Opcode.geq);
        ELSE
          Log.Type("++ Unknown variant of Compare in Expression", expr);
          ASSERT (FALSE);
        END;

      | expr: IR.NewObject DO
        RETURN NewObject (expr);
        
      | expr: IR.Call DO
        instr := Call (expr);
        (* the pessimistic assumption is that a function call can have
           arbitrary side effects; it's up to later transformations to reduce
           the impact of this  *)
        instr. AddOpnd (s, Opnd.store);
        s := instr. AddResult (Result.store);
        RETURN instr
            
      ELSE
        Log.Type("++ Unknown type in Expression", expr);
        ASSERT (FALSE)
      END;
    END Expression;

  PROCEDURE Assert (assert: IR.Assert): SSA.Instr;
    VAR
      instr: SSA.Instr;
    BEGIN
      instr := pb. AddInstr (Opcode.assert, Opcode.scNone);
      instr. AddOpnd (Expression (assert. predicate), Opnd.arg);
      instr. AddOpnd (pb. GetConstInt (assert. code), Opnd.arg);
      RETURN instr
    END Assert;
  
  PROCEDURE Assignment (assignment: IR.Assignment): SSA.Instr;
    VAR
      get: SSA.Result;
    BEGIN
      (* ... shortcut: ignore non-scalar assignments *)

      (* FIXME... If this is an AssignOp, then we must evaluate the
         variable just once for both the operator and the actual assignment *)
      get := Expression (assignment. variable);
      RETURN pb. AddSetInstr (get(SSA.Instr), Expression (assignment. value));
    END Assignment;
  
  PROCEDURE Call (call: IR.Call): SSA.Instr;
    VAR
      instr: SSA.Instr;
      i: LONGINT;
      fpar: Sym.VarDecl;
      type: Sym.Type;
      isVarParam: BOOLEAN;
    BEGIN
      instr := pb. AddInstr (Opcode.call, Opcode.TypeToSubclass (call. type));
      instr. AddTypedOpnd (Expression (call. design), Opnd.procAdr,
                           call. design. type, FALSE);
      FOR i := 0 TO LEN (call. arguments^)-1 DO
        IF (call. formalPars[i] # NIL) THEN
          fpar := call. formalPars[i];
          type := fpar. type;
          isVarParam := fpar. isPassPerReference;
        ELSE
          type := call. arguments[i]. type;
          isVarParam := FALSE;
        END;
        instr. AddTypedOpnd (Expression (call. arguments[i]),
                             Opnd.arg, type, isVarParam);
      END;
      RETURN instr
    END Call;

  PROCEDURE Return (return: IR.Return);
    VAR
      instr: SSA.Instr;
      store: SSA.Result;
    BEGIN
      instr := pb. AddInstr (Opcode.return, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      IF (return. result # NIL) THEN
        instr. AddOpnd (Expression (return. result), Opnd.functionResult);
      END;
      
      store := instr. AddResult (Result.store);
      pb. selectReturn. AddOpnd (store, Opnd.store);
      s := store
    END Return;

  PROCEDURE IfStatm (ifStatm: IR.IfStatm);
    VAR
      select: SSA.Instr;
      storeAfterGuard: SSA.Result;
    BEGIN
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (Expression (ifStatm. guard), Opnd.arg);
      storeAfterGuard := s;
      
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (StatmSeq (pb, storeAfterGuard, ifStatm. pathTrue),
                       Opnd.arg);
      
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      IF (ifStatm. pathFalse # NIL) THEN
        select. AddOpnd (StatmSeq (pb, storeAfterGuard, ifStatm. pathFalse),
                         Opnd.arg);
      ELSE
        select. AddOpnd (storeAfterGuard, Opnd.arg)
      END;

      s := select. AddResult (Result.store)
    END IfStatm;

  PROCEDURE RepeatStatm (repeatStatm: IR.RepeatStatm);
    VAR
      start, end: SSA.Instr;
      exit: SSA.Result;
    BEGIN
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);
      
      (* evaluate loop body, followed by the exit condition *)
      s := StatmSeq (pb, s, repeatStatm. body);
      exit := Expression (repeatStatm. exitCondition);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (s, Opnd.store);
      end. AddOpnd (exit, Opnd.arg);
      end. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);

      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);
      
      s := end. AddResult (Result.store)
    END RepeatStatm;
  
  PROCEDURE WhileStatm (whileStatm: IR.WhileStatm);
    VAR
      start, end, select: SSA.Instr;
      guard1, guard2, storeAfterGuard1: SSA.Result;
    BEGIN
      (* WHILE e DO s END

         is translated to

         IF e THEN
           REPEAT
             s
           UNTIL ~e;
         END  *)
      guard1 := Expression (whileStatm. guard);
      storeAfterGuard1 := s;

      (* insert "loop-start" instruction *)
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);
      
      (* evaluate loop body, followed by the exit condition *)
      s := StatmSeq (pb, s, whileStatm. body);
      guard2 := Expression (whileStatm. guard);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (s, Opnd.store);
      end. AddOpnd (guard2, Opnd.arg);
      end. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);
      
      (* create the "select" for the IF statement around the loop *)
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard1, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (end. AddResult (Result.store), Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (storeAfterGuard1, Opnd.arg);

      s := select. AddResult (Result.store)
    END WhileStatm;

  PROCEDURE ForStatm (forStatm: IR.ForStatm);
    VAR
      start, end, select, dummy: SSA.Instr;
      guard1, guard2, storeAfterGuard1, v, endValue, stepValue: SSA.Result;

    PROCEDURE Guard (bound: SSA.Result): SSA.Instr;
      VAR
        instr: SSA.Instr;
        cmpClass: Opcode.Class;
      BEGIN
        IF (Integers.Sign (forStatm. step(IR.Const). value(Integer.Value). value) >= 0) THEN
          cmpClass := Opcode.leq;
        ELSE
          cmpClass := Opcode.geq;
        END;
        instr := pb. AddInstr (cmpClass, Opcode.scBoolean);
        instr. AddOpnd (Expression (forStatm. var), Opnd.arg);
        instr. AddOpnd (bound, Opnd.arg);
        RETURN instr
      END Guard;
    
    BEGIN
      (* FOR v := beg TO end BY step DO s END;

         is translated to

         temp := end; v := beg;
         IF step>0 THEN
           IF v<=temp THEN
             REPEAT
               s; v := v+step
             UNTIL ~(v<=temp);
           END
         ELSE
           IF v>=temp THEN
             REPEAT
               s; v := v+step
             UNTIL ~(v>=temp);
           END
         END *)
      endValue := Expression (forStatm. end);
      stepValue := Expression (forStatm. step);
      v := Expression (forStatm. var);
      Chain (pb. AddSetInstr (v(SSA.Instr), Expression (forStatm. start)));
      
      guard1 := Guard (endValue);
      storeAfterGuard1 := s;

      (* insert "loop-start" instruction *)
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);
      
      (* evaluate loop body, followed by the exit condition *)
      s := StatmSeq (pb, s, forStatm. body);
      dummy := pb. AddInstr (Opcode.add,
                             Opcode.TypeToSubclass (forStatm. var. type));
      v := Expression (forStatm. var);
      dummy. AddOpnd (v, Opnd.arg);
      dummy. AddOpnd (stepValue, Opnd.arg);
      Chain (pb. AddSetInstr (v(SSA.Instr), dummy));
      guard2 := Guard (endValue);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (s, Opnd.store);
      end. AddOpnd (guard2, Opnd.arg);
      end. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);
      
      (* create the "select" for the IF statement around the loop *)
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard1, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (end. AddResult (Result.store), Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (storeAfterGuard1, Opnd.arg);

      s := select. AddResult (Result.store);
    END ForStatm;
  
  PROCEDURE LoopStatm (loopStatm: IR.LoopStatm);
    VAR
      start, end, select, oldSelect: SSA.Instr;
    BEGIN
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);

      select := pb. AddInstr (Opcode.selectExit, Opcode.scNone);
      select. AddOpnd (start, Opnd.arg);
      oldSelect := pb. SetSelectExit (select);
      
      (* evaluate loop body *)
      s := StatmSeq (pb, s, loopStatm. body);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (s, Opnd.store);
      end. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      end. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);

      select. opndList. ReplaceArg (end);
      s := select. AddResult (Result.store);
      select := pb. SetSelectExit (oldSelect);
    END LoopStatm;

  PROCEDURE Exit (exit: IR.Exit);
    VAR
      instr: SSA.Instr;
      store: SSA.Result;
    BEGIN
      instr := pb. AddInstr (Opcode.exit, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      
      store := instr. AddResult (Result.store);
      pb. selectExit. AddOpnd (store, Opnd.store);
      s := store
    END Exit;
  
  PROCEDURE CopyParameter (cp: IR.CopyParameter);
    VAR
      instr: SSA.Instr;
    BEGIN
      instr := pb. AddCopyParameter
          (cp. param. decl(Sym.VarDecl), s, CalculateSize (pb, cp. param, -1));
      s := instr. AddResult (Result.store);
    END CopyParameter;
  
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statm := statmSeq[i];
      WITH statm: IR.Assert DO
        Chain (Assert (statm));

      | statm: IR.Assignment DO
        Chain (Assignment (statm))
            
      | statm: IR.Call DO
        Chain (Call (statm));
        
      | statm: IR.Return DO
        (* lets pretend for a moment that a RETURN is not a control flow
           construct... FIXME *)
        Return (statm)

      | statm: IR.IfStatm DO
        IfStatm (statm)

      | statm: IR.RepeatStatm DO
        RepeatStatm (statm)
            
      | statm: IR.WhileStatm DO
        WhileStatm (statm);

      | statm: IR.ForStatm DO
        ForStatm (statm);

      | statm: IR.LoopStatm DO
        LoopStatm (statm);

      | statm: IR.Exit DO
        Exit (statm);
        
      | statm: IR.CopyParameter DO
        CopyParameter (statm)
            
      ELSE
        Log.Type("++ Unknown statement class in StatmSeq", statm);
        ASSERT (FALSE)
      END;
    END;
    RETURN s
  END StatmSeq;

END OOC:SSA:IRtoSSA.
