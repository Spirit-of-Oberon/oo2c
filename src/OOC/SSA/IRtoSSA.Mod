(* 	$Id: IRtoSSA.Mod,v 1.138 2005/10/07 08:35:41 mva Exp $	 *)
MODULE OOC:SSA:IRtoSSA;
(*  Converts the IR of a procedure into its SSA representation.
    Copyright (C) 2001-2005  Michael van Acken

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
  SYSTEM, Log, Object, Object:Boxed, Object:BigInt,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef, OOC:SymbolTable:Builder,
  TR := OOC:SymbolTable:TypeRules, OOC:IR, 
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result;


PROCEDURE AddStoreBackwardFeed (pb: SSA.ProcBlock;
                                loopEnd: SSA.Instr; storeArg: SSA.Result);
  VAR
    collect: SSA.Instr;
    opnd: SSA.Opnd;
  BEGIN
    (* install a pass-through collect instruction between `storeArg'
       and the use in `loopEnd'; the allocator code uses this instruction
       to mark some values as live across the whole loop *)
    collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
    collect. AddOpnd (storeArg, Opnd.store);
    opnd := loopEnd. GetOpndClass (Opnd.backwardFeed);
    IF (opnd = NIL) THEN
      loopEnd. AddOpnd (collect. AddResult (Result.store), Opnd.backwardFeed);
    ELSE
      opnd. ReplaceArg (collect. AddResult (Result.store));
    END;
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
      IF (instr. opcode = Opcode.set) OR
         (instr. opcode = Opcode.get) OR
         (instr. opcode = Opcode.copyString) OR
         (instr. opcode = Opcode.newObject) THEN
        instr. opndList. ReplaceArg (s);
      ELSE
        instr. AddOpnd (s, Opnd.store);
      END;
      s := instr. AddResult (Result.store)
    END Chain;

  PROCEDURE FixAddress(arg: SSA.Result): SSA.Result;
    BEGIN
      RETURN pb.FixSubclass(arg, Opcode.scAddress);
    END FixAddress;
  
  PROCEDURE FixLength(arg: SSA.Result): SSA.Result;
    BEGIN
      RETURN pb.FixSubclass(arg, Opcode.scLength);
    END FixLength;
  
  PROCEDURE ^ Call (call: IR.Call): SSA.Instr;
  PROCEDURE ^ Expression (expr: IR.Expression): SSA.Result;
    
  PROCEDURE CalculateLength (pb: SSA.ProcBlock; value: IR.Expression;
                             dim: LONGINT; baseArray: SSA.Result): SSA.Result;
  (* Calculate the one-dimensional length of the variable @oparam{value} or of
     one of its elements.  With @oparam{dim=-1}, return the number of elements
     of the whole variable.  With @oparam{dim>=0}, return the length of an
     array element of dimension @oparam{dim}.  @oparam{baseArray} holds the
     (virtual, and dead) @oconst{Opcode.get} instruction on the array variable.  *)
    VAR
      type: Sym.Type;
      i: LONGINT;
      
    PROCEDURE RecursiveGetLength (type: Sym.Type; dim: LONGINT): SSA.Result;
      VAR
        len: SSA.Result;
        lenp: SSA.Instr;
      BEGIN
        type := type.Deparam();
        WITH type: Sym.Array DO
          IF type.isOpenArray THEN
            len := pb.AddGetLengthInstr (baseArray(SSA.Instr), dim+1, type);
          ELSE
            len := pb.GetConstInt(type.length);
          END;
          len := FixLength(len);
          
          IF TR.IsArray(type.elementType) THEN
            lenp := pb. AddInstr (Opcode.multiply, Opcode.scLength);
            lenp. AddOpnd (len, Opnd.arg);
            lenp. AddOpnd (RecursiveGetLength (type.elementType, dim+1),
                           Opnd.arg);
            RETURN lenp;
          ELSE
            RETURN len;
          END;
        ELSE
          RETURN FixLength(pb.GetConstInt(1));
        END;
      END RecursiveGetLength;
    
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
        type := type.Deparam();
        type := type(Sym.Array). elementType;
      END;
      
      RETURN RecursiveGetLength (type, dim);
    END CalculateLength;
  
  PROCEDURE CalculateSize (pb: SSA.ProcBlock; value: IR.Expression;
                           length: SSA.Result): SSA.Instr;
  (* Calculate the size of the variable @oparam{value} based on the given
     length and the (non-array) base type of the index expression
     @oparam{value}.  *)
    VAR
      type: Sym.Type;
      size: SSA.Instr;
    BEGIN
      (* if `value' is an index expression, normalize it to the array
         variable  *)
      WHILE (value IS IR.Index) DO
        value := value(IR.Index).array;
      END;
      
      (* get type of the value we are interested in *)
      type := value.type;
      WHILE TR.IsArrayType(type) DO
        type := TR.ArrayElementType(type);
      END;
      type := type.Deparam();
      
      size := pb.AddInstr (Opcode.multiply, Opcode.scAddress);
      size.AddOpnd(FixAddress(length), Opnd.arg);
      size.AddOpnd(FixAddress(pb.GetConstInt(type.size)), Opnd.arg);
      RETURN size;
    END CalculateSize;
  
  PROCEDURE TypeOfString (type: Sym.Type): Sym.Type;
    BEGIN
      WITH type: Sym.Array DO
        IF (type. elementType IS Sym.PredefType) THEN
          CASE type. elementType(Sym.PredefType). id OF
          | Predef.char, Predef.longchar, Predef.ucs4char:
            RETURN type. elementType;
          ELSE
            RETURN NIL;
          END;
        ELSE
          RETURN NIL;
        END;
      | type: Sym.PredefType DO
        CASE type. id OF
        | Predef.stringChar, Predef.stringLongChar, Predef.stringUCS4Char:
          RETURN Predef.GetType (type. id-Predef.stringChar+Predef.char);
        ELSE
          RETURN NIL;
        END;
      ELSE
        RETURN NIL;
      END;
    END TypeOfString;
  
  PROCEDURE TransferReadDesign (source: SSA.Result; instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      IF (source IS SSA.Const) THEN
        (* copying a string constant *)
        instr. AddOpnd (source, Opnd.readAdr);
      ELSE
        opnd := source. instr. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd. class = Opnd.readAdr) OR
             (opnd. class = Opnd.readDesign) THEN
            instr. AddOpnd (opnd. arg, opnd. class);
          END;
          opnd := opnd. nextOpnd;
        END;
      END;
    END TransferReadDesign;

  PROCEDURE TransferWriteDesign (source: SSA.Result; instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      opnd := source. instr. opndList;
      WHILE (opnd # NIL) DO
        IF (opnd. class = Opnd.readAdr) THEN
          instr. AddOpnd (opnd. arg, Opnd.writeAdr);
        ELSIF (opnd. class = Opnd.readDesign) THEN
          instr. AddOpnd (opnd. arg, Opnd.writeDesign);
        END;
        opnd := opnd. nextOpnd;
      END;
    END TransferWriteDesign;
  
  PROCEDURE CopyString (cp: IR.CopyString): SSA.Instr;
    VAR
      instr: SSA.Instr;
      source, dest, maxLength: SSA.Result;
    BEGIN
      source := Expression (cp. source);
      dest := Expression (cp. dest);
      maxLength := Expression (cp. maxLength);

      instr := pb. AddInstr (Opcode.copyString, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      instr. AddOpnd (pb. GetTypeRef (TypeOfString (cp. source. type)), Opnd.type);
      instr. AddOpnd (pb. GetTypeRef (TypeOfString (cp. dest. type)), Opnd.type);
      TransferReadDesign (source, instr);
      TransferWriteDesign (dest, instr);
      instr. AddOpnd (maxLength, Opnd.arg);

      RETURN instr;
    END CopyString;
  
  PROCEDURE AddException (pb: SSA.ProcBlock; sym: IR.Symbol;
                          opcode: Opcode.Class; subclass: Opcode.Subclass): SSA.Instr;
    VAR
      instr: SSA.Instr;
      res: SSA.Result;
    BEGIN
      instr := pb. AddInstr (opcode, subclass);
      instr. SetPos (sym);
      res := instr. AddResult (Result.exception);
      Chain (instr);
      RETURN instr;
    END AddException;
  
  PROCEDURE TypeTag (design: IR.Expression; value: SSA.Result;
                     checkDerefOfNil: BOOLEAN; derefSym: IR.Symbol): SSA.Instr;
  (* `design' is the variable designator, `value' its translation to SSA *)
    VAR
      instr, check: SSA.Instr;
      type: Sym.Type;
    BEGIN
      type := design.type.Deparam();
      type := type.Bound();  (* for a type variable, continue with bound *)
      IF checkDerefOfNil & (type IS Sym.Pointer) THEN
        check := AddException (pb, derefSym,
                               Opcode.checkPointer, value. subclass);
        check. AddOpnd (value, Opnd.arg);
        value := check;
      END;
      
      instr := pb. AddInstr (Opcode.typeTag, Opcode.scAddress);
      IF (type IS Sym.Pointer) THEN
        instr. AddOpnd (value, Opnd.arg);
      ELSIF (design IS IR.Var) &
            design(IR.Var). decl(Sym.VarDecl). isVarParam &
            TR.IsRecord(design(IR.Var).decl(Sym.VarDecl).type) THEN
        (* type tag of a VAR parameter *)
        instr. AddOpnd (value. instr. GetArgClass (Opnd.readDesign), Opnd.arg);
      ELSE                             (* static type tag *)
        instr. AddOpnd (pb. GetTypeRef (type), Opnd.arg);
      END;
      RETURN instr;
    END TypeTag;
  
  PROCEDURE Copy (cp: IR.Copy): SSA.Instr;
    VAR
      expr: IR.Expression;
      instr, dynTag, staticTag, neq, failed, select: SSA.Instr;
      source, dest, okStore: SSA.Result;
    BEGIN
      (* taking the address of a type casted expression fails, but we can
         always try to take the address of the original value -- if it is
         a variable *)
      expr := cp.source;
      WHILE (expr IS IR.TypeCast) DO
        expr := expr(IR.TypeCast).expr;
      END;
      source := Expression (expr);
      dest := Expression (cp. dest);

      IF cp. checkDynamicType THEN
        dynTag := TypeTag (cp. dest, dest, FALSE, NIL);
        staticTag := pb. AddInstr (Opcode.typeTag, Opcode.scAddress);
        staticTag. AddOpnd (pb. GetTypeRef (cp. dest. type), Opnd.arg);

        neq := pb. AddInstr (Opcode.neq, Opcode.scAddress);
        neq. AddOpnd (staticTag, Opnd.arg);
        neq. AddOpnd (dynTag, Opnd.arg);
        okStore := s;
        
        failed := AddException (pb, cp. dest. sym,
                                Opcode.failedTypeAssert, Opcode.scNone);
        
        select := pb. AddInstr (Opcode.select, Opcode.scNone);
        select. AddOpnd (neq, Opnd.arg);
        select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
        select. AddOpnd (s, Opnd.arg);
        select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
        select. AddOpnd (okStore, Opnd.arg);

        s := select. AddResult (Result.store);
      END;
      
      instr := pb. AddInstr (Opcode.copy, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      instr. AddOpnd (pb. GetTypeRef (cp. dest. type), Opnd.type);
      TransferReadDesign (source, instr);
      TransferWriteDesign (dest, instr);
      RETURN instr;
    END Copy;
  
  PROCEDURE Expression (expr: IR.Expression): SSA.Result;
    VAR
      instr: SSA.Instr;
      res, baseArray: SSA.Result;
      opcode: Opcode.Class;
      dim: LONGINT;
      type: Sym.Type;
      v: Boxed.Object;
      x: BigInt.BigInt;

    PROCEDURE Deref (deref: IR.Deref): SSA.Result;
      VAR
        instr, check: SSA.Instr;
        address: SSA.Result;
      BEGIN
        (* take the value of the pointer and use it to start a new "get"
           instruction *)
        address := Expression (deref. pointer);
        IF deref. checkPointer THEN
          check := AddException (pb, deref. sym,
                                 Opcode.checkPointer, address. subclass);
          check. AddOpnd (address, Opnd.arg);
          address := check;
        END;
        
        instr := pb. AddInstr (Opcode.get, Opcode.TypeToSubclass (deref.type));
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (address, Opnd.readAdr);
        instr. AddOpnd (pb. GetTypeRef (deref. pointer. type), Opnd.readDesign);
        instr. AddOpnd (address, Opnd.readDesign);
        Chain (instr);
        RETURN instr
      END Deref;

    PROCEDURE GetIndexBaseArray (indexOp: IR.Expression; VAR dim: LONGINT): SSA.Result;
      VAR
        res: SSA.Result;
      BEGIN
        WITH indexOp: IR.Index DO
          res := GetIndexBaseArray (indexOp. array, dim);
          INC (dim);
          RETURN res;
        ELSE
          dim := -1;
          RETURN Expression (indexOp);
        END;
      END GetIndexBaseArray;

    PROCEDURE Index (indexOp: IR.Index;
                     baseArray: SSA.Result;
                     elementSize: SSA.Result;
                     dim: LONGINT): SSA.Result;
    (* Handles a sequence of index operations on an array.  @oapram{indexOp} is
       the index operation that is to be translated.  @oparam{baseArray} holds
       the (virtual) @oconst{Opcode.get} operation on the array variable at the
       very start of the index sequence.  @oparam{elementSize} is the size in
       bytes of the value produced by this index operation.  @oparam{dim} is
       the dimension of @oparam{baseArray} on which @oparam{indexOp} operates.  *)
      VAR
        instr, elementAdr, scaledIndex, newSize, check: SSA.Instr;
        baseResult, length, index: SSA.Result;
        adrOpnd: SSA.Opnd;
        elementType, arrayType: Sym.Type;
      BEGIN
        arrayType := indexOp.array.type.Deparam();
        length := pb. AddGetLengthInstr (baseArray(SSA.Instr), dim,
                                         arrayType(Sym.Array));
        newSize := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
        newSize. AddOpnd (elementSize, Opnd.arg);
        newSize. AddOpnd (FixAddress(length), Opnd.arg);
        
        IF (indexOp. array IS IR.Index) THEN
          baseResult := Index (indexOp. array(IR.Index), baseArray,
                               newSize, dim-1);
        ELSE
          baseResult := baseArray;
          ASSERT (dim = 0);
        END;
        INC (dim);
        ASSERT (baseResult. instr. opcode = Opcode.get);
        
        (* take the "get" instruction of the array's designator and change it
           into a "get" for the array element; the store seen by the index
           expression is the one that is passed into the old "get", and the new
           "get" sees the store after the index expression has been evaluated  *)
        instr := baseResult. instr;
        s := instr. opndList. arg;
        index := Expression (indexOp. index);
        IF indexOp. checkIndex THEN
          check := AddException (pb, indexOp. sym,
                                 Opcode.checkIndex, index. subclass);
          check. AddOpnd (index, Opnd.arg);
          check. AddOpnd (length, Opnd. arg);
          index := check;
        END;
        instr. opndList. ReplaceArg (s);
        s := instr. GetResultStore();
            
        elementType := indexOp. type;
        scaledIndex := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
        scaledIndex. AddOpnd (FixAddress(index), Opnd.arg);
        scaledIndex. AddOpnd (elementSize, Opnd.arg);
        
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
        baseResult, offset: SSA.Result;
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
        offset := pb.GetConstInt(selectOp.field.offset);
        fieldAdr.AddOpnd(FixAddress(offset), Opnd.arg);
        adrOpnd. ReplaceArg (fieldAdr);
        instr. AddOpnd (pb. GetDeclRef (selectOp. field), Opnd.readDesign);
        instr. SetSubclass (Opcode.TypeToSubclass (selectOp. field. type));
        
        RETURN instr
      END SelectField;

    PROCEDURE AddCompareOp (op: IR.Compare; class: Opcode.Class): SSA.Instr;
      VAR
        instr: SSA.Instr;
        left, right: SSA.Result;
        typeOfString: Sym.Type;
      BEGIN
        typeOfString := TypeOfString (op. left. type);
        left := Expression (op. left);
        right := Expression (op. right);
        
        IF (typeOfString # NIL) THEN     (* string compare *)
          instr := pb. AddInstr (Opcode.cmpString, Opcode.scSigned32);
          instr. AddOpnd (s, Opnd.store);
          instr. AddOpnd (pb. GetTypeRef (typeOfString), Opnd.type);
          TransferReadDesign (left, instr);
          TransferReadDesign (right, instr);
          
          left := instr;
          right := pb. GetConstInt (0);
        END;
        
        instr := pb. AddInstr (class, Opcode.scBoolean);
        instr. AddOpnd (left, Opnd.arg);
        instr. AddOpnd (right, Opnd.arg);
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

    PROCEDURE NewBlock (new: IR.NewBlock): SSA.Instr;
      VAR
        instr: SSA.Instr;
      BEGIN
        instr := pb. AddInstr (Opcode.newBlock, Opcode.scAddress);
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (pb. GetTypeRef (new. type), Opnd.type);
        instr. AddOpnd (Expression (new. size), Opnd.arg);
        Chain (instr);
        RETURN instr;
      END NewBlock;

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

    PROCEDURE ReceiverTypeTag(receiver: IR.Expression;
                              referenceType: Sym.Type): SSA.Instr;
      BEGIN
        IF (receiver = NIL) OR ~TR.IsTypeVar(referenceType) THEN
          RETURN pb.GetConstNil();
        ELSE
          RETURN TypeTag(receiver, Expression(receiver), FALSE, NIL);
        END;
      END ReceiverTypeTag;
      
    PROCEDURE TypeTest (test: IR.TypeTest): SSA.Instr;
      VAR
        instr, tt: SSA.Instr; 
      BEGIN
        tt := ReceiverTypeTag(test.receiver, test.origType.qualType);
        instr := pb. AddInstr (Opcode.typeTest, Opcode.scBoolean);
        instr. AddOpnd (TypeTag (test. expr, Expression (test. expr),
                                 test. checkPointer, test. sym),
                        Opnd.arg);
        instr. AddOpnd (pb. GetTypeRef (test. referenceType), Opnd.type);
        instr. AddOpnd (tt, Opnd.arg);
        RETURN instr
      END TypeTest;
    
    PROCEDURE TypeGuard (guard: IR.TypeGuard): SSA.Result;
      VAR
        design: SSA.Result;
        tag, instr, adr: SSA.Instr;
        opnd: SSA.Opnd;

      PROCEDURE NewTypeGuard (adr, tag: SSA.Result): SSA.Instr;
        VAR
          instr, tt: SSA.Instr;
        BEGIN
          tt := ReceiverTypeTag(guard.test.receiver, guard.test.origType.qualType);
          instr := AddException (pb, guard. test. origType. sym,
                                 Opcode.typeGuard, adr. instr. subclass);
          instr. AddOpnd (adr, Opnd.arg);
          instr. AddOpnd (tag, Opnd.arg);
          instr. AddOpnd (pb. GetTypeRef (guard. test. referenceType),
                          Opnd.type);
          instr. AddOpnd (tt, Opnd.arg);
          RETURN instr;
        END NewTypeGuard;
      
      BEGIN
        design := Expression (guard. test. expr);

        IF guard. checkType THEN
          IF (design.instr.opcode = Opcode.typeGuard) THEN (* stacked guards *)
            opnd := design.instr.NthOpnd(3);
            opnd.ReplaceArg(pb.GetTypeRef(guard.test.referenceType));
            RETURN design;
          ELSE
            ASSERT (design. instr. opcode = Opcode.get);
            tag := TypeTag (guard. test. expr, design,
                            guard. checkPointer, guard. sym);
            IF (guard. test. origExpr IS IR.Var) &
               (guard. test. origExpr. type IS Sym.Record) THEN
              (* applying type guard to a record VAR parameter: replace the
                 address _input_ of the get with the type guard instruction *)
              design. instr. opndList. nextOpnd. ReplaceArg
                  (NewTypeGuard (design. instr. opndList. nextOpnd. arg, tag));
              RETURN design;
            ELSIF (guard.test.origExpr IS IR.Deref) THEN
              (* need to dereference the tested pointer, because TypeTest
                 dropped this *)
              adr := NewTypeGuard (design, tag);
              instr := pb.AddInstr(Opcode.get,
                                   Opcode.TypeToSubclass(guard.type));
              instr.AddOpnd(s, Opnd.store);
              instr.AddOpnd(adr, Opnd.readAdr);
              instr.AddOpnd(pb.GetTypeRef(guard.test.expr.type),
                            Opnd.readDesign);
              instr.AddOpnd(adr, Opnd.readDesign);
              Chain (instr);
              RETURN instr;
            ELSE
              RETURN NewTypeGuard (design, tag);
            END;
          END;
        ELSE
          RETURN design;
        END;
      END TypeGuard;
    
    PROCEDURE TypeCast (cast: IR.TypeCast): SSA.Result;
      VAR
        instr: SSA.Instr;
        scDest: Opcode.Subclass;
      BEGIN
        scDest := Opcode.TypeToSubclass (cast. type);
        instr := pb. AddInstr (Opcode.typeCast, scDest);
        instr. AddOpnd (Expression (cast. expr), Opnd.arg);
        RETURN instr;
      END TypeCast;
    
    PROCEDURE TypeConv (conv: IR.TypeConv): SSA.Result;
      VAR
        instr: SSA.Instr;
        const: SSA.Result;
        scSource, scDest: Opcode.Subclass;
        len: LONGINT;
        fct: STRING;
      BEGIN
        IF TR.IsSTRING(conv.type) THEN
          (* converting a character or string constant to STRING *)
          const := Expression(conv.expr);
          
          instr := pb.AddInstr(Opcode.preloadedVar, Opcode.scAddress);
          CASE conv.expr.type(Sym.PredefType).id OF
          | Predef.char:
            fct := Object.NewLatin1(Builder.stringModuleC+"__NewLatin1Char");
          | Predef.stringChar:
            fct := Object.NewLatin1(Builder.stringModuleC+"__NewLatin1Region");
          | Predef.longchar:
            fct := Object.NewLatin1(Builder.stringModuleC+"__NewUTF16Char");
          | Predef.stringLongChar:
            fct := Object.NewLatin1(Builder.stringModuleC+"__NewUTF16Region");
          | Predef.ucs4char:
            fct := Object.NewLatin1(Builder.stringModuleC+"__NewUCS4Char");
          | Predef.stringUCS4Char:
            fct := Object.NewLatin1(Builder.stringModuleC+"__NewUCS4Region");
          END;
          instr.AddOpnd(pb.GetConst(NEW(Boxed.String, fct), Opcode.scAddress,
                                    Predef.GetType(Predef.stringChar)),
                        Opnd.arg);
          instr.AddOpnd(const, Opnd.arg);
          IF TR.IsStringConst(conv.expr.type) THEN
            len := conv.expr(IR.Const).value(Boxed.String).value.length;
            instr.AddOpnd(pb.GetConstInt(len+1), Opnd.arg); (* array len *)
            
            instr.AddOpnd(pb.GetConstInt(0), Opnd.arg); (* start *)
            instr.AddOpnd(pb.GetConstInt(len), Opnd.arg); (* end *)
          END;
          RETURN instr;
        ELSE
          scDest := Opcode.TypeToSubclass (conv. type);
          scSource := Opcode.TypeToSubclass (conv. expr. type);
          IF (scDest # scSource) THEN
            instr := pb. AddInstr (Opcode.typeConv, scDest);
            instr. AddOpnd (Expression (conv. expr), Opnd.arg);
            RETURN instr;
          ELSE
            RETURN Expression (conv. expr);
          END;
        END;
      END TypeConv;
    
    PROCEDURE SelectProc (selectOp: IR.SelectProc): SSA.Result;
      VAR
        object: IR.Expression;
        type : Sym.Type;
      BEGIN
        IF selectOp. isStaticCall THEN   (* use static address *)
          RETURN pb. GetAddress (selectOp. tbProc);
        ELSE                             (* use dynamic address *)
          IF (selectOp. receiver IS IR.Deref) THEN
            object := selectOp. receiver(IR.Deref). pointer;
          ELSE
            object := selectOp. receiver;
          END;
          type := selectOp. recordType. Deparam();
          IF type(Sym.Record).isVtable THEN
            (* TODO: Add deref check *)
            instr := pb. AddInstr (Opcode.vtableProcAddress, Opcode.scAddress);
            instr. AddOpnd (Expression(object), Opnd.arg);
          ELSE
            instr := pb. AddInstr (Opcode.tbProcAddress, Opcode.scAddress);
            instr. AddOpnd (TypeTag (object,
                                   Expression (object),
                                   selectOp. checkPointer,
                                   selectOp. sym), Opnd.arg);
          END;
          instr. AddOpnd (pb. GetDeclRef (selectOp. tbProc), Opnd.arg);
          RETURN instr;
        END;
      END SelectProc;

    PROCEDURE Concat (expr: IR.Concat): SSA.Result;
      VAR
        i: LONGINT;
        instr: SSA.Instr;
      BEGIN
        instr := pb. AddInstr(Opcode.concat, Opcode.scAddress);
        FOR i := 0 TO LEN(expr.strings^)-1 DO
          instr.AddOpnd(Expression(expr.strings[i]), Opnd.arg);
        END;
        RETURN instr;
      END Concat;

    PROCEDURE Constructor(expr: IR.Constructor): SSA.Result;
      VAR
        obj, call: SSA.Result;
      BEGIN
        obj := NewObject(expr.alloc);
        IF (expr.init # NIL) THEN
          call := Expression(expr.init);
          call.instr.opndList.nextOpnd.ReplaceArg(obj);  (* fixup receiver *)
        END;
        RETURN obj;
      END Constructor;
    
    BEGIN
      WITH expr: IR.Const DO
        IF (expr. value = NIL) THEN
          RETURN pb.GetConst(SSA.nil, Opcode.scAddress, NIL);
        ELSE
          v := expr.value;
          WITH v: Boxed.String DO
            IF TR.IsStringConst(expr.type) THEN
              RETURN pb.GetConst(v, Opcode.scAddress, expr.type);
            ELSE
              x := BigInt.NewInt(ORD(v.value.CharAt(0)));
              RETURN pb.GetConst(x, Opcode.TypeToSubclass(expr.type), NIL);
            END;

          | v: Boxed.Boolean DO
            RETURN pb.GetConstBool(v.value);

          | v: Boxed.Set DO
            x := BigInt.NewInt(SYSTEM.VAL(LONGINT, v.value));
            RETURN pb.GetConst(x, Opcode.TypeToSubclass(expr.type), NIL);

          ELSE
            RETURN pb.GetConst(v, Opcode.TypeToSubclass(expr.type), NIL);
          END;
        END;
            
      | expr: IR.ProcedureRef DO
        RETURN pb. GetAddress (expr. decl)

      | expr: IR.Var DO
        instr := pb. AddInstr (Opcode.get, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (s, Opnd.store);
        instr. AddOpnd (pb. GetAddress (expr. decl), Opnd.readAdr);
        instr. AddOpnd (pb. GetDeclRef (expr. decl), Opnd.readDesign);
        Chain (instr);
        RETURN instr

      | expr: IR.TypeRef DO
        RETURN pb. GetTypeRef (expr. decl(Sym.TypeDecl). type);
        
      | expr: IR.Adr DO
        res := Expression (expr. design);
        IF (res. instr. opcode = Opcode.get) THEN
          RETURN pb.FixSubclass(res. instr. GetArgClass (Opnd.readAdr),
                                Opcode.TypeToSubclass(expr.type));
        ELSE
          (* must be a string constant; currently, this is its own address
             FIXME... we should probably introduce an address opcode here *)
          RETURN res;
        END;
        
      | expr: IR.Len DO
        IF (expr. variant = IR.lenStringConst) THEN
          RETURN pb. GetConstInt (expr. arrayVariable(IR.Const). value(Boxed.String). value. length+1);
        ELSE
          baseArray := Expression (expr. arrayVariable);
          type := expr. arrayVariable. type.Deparam();
          type := type(Sym.Array).GetNthElementType(expr.dim);
          RETURN pb. AddGetLengthInstr (baseArray(SSA.Instr), expr. dim,
                                        type(Sym.Array));
        END;

      | expr: IR.Deref DO
        RETURN Deref (expr);
        
      | expr: IR.Index DO
        baseArray := GetIndexBaseArray (expr, dim);
        RETURN Index (expr, baseArray,
                      CalculateSize(pb, expr, 
                                    CalculateLength(pb, expr, -1, baseArray)),
                      dim);

      | expr: IR.SelectField DO
        RETURN SelectField (expr);
        
      | expr: IR.SelectProc DO
        RETURN SelectProc (expr);

      | expr: IR.TypeCast DO
        RETURN TypeCast (expr);
      | expr: IR.TypeConv DO
        RETURN TypeConv (expr);
      | expr: IR.TypeTag DO
        RETURN TypeTag (expr. design, Expression (expr. design), FALSE, NIL);
      | expr: IR.TypeTest DO
        RETURN TypeTest (expr);
      | expr: IR.TypeGuard DO
        RETURN TypeGuard (expr);
        
      | expr: IR.Negate DO
        IF TR.IsPredefType(expr.type, Predef.set) THEN
          opcode := Opcode.logicalComplement;
        ELSE
          opcode := Opcode.negate;
        END;
        instr := pb. AddInstr (opcode,
                               Opcode.TypeToSubclass (expr. operand. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr;
      | expr: IR.Not DO
        instr := pb. AddInstr (Opcode.not, Opcode.scBoolean);
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr;
        
      | expr: IR.SetMember DO
        instr := pb. AddInstr (Opcode.setMember, Opcode.scBoolean);
        instr. AddOpnd (Expression (expr. element), Opnd.arg);
        instr. AddOpnd (Expression (expr. set), Opnd.arg);
        RETURN instr;

      | expr: IR.Abs DO
        instr := pb. AddInstr (Opcode.abs, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr;
        
      | expr: IR.Ash DO
        instr := pb. AddInstr (Opcode.ash, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (Expression (expr. value), Opnd.arg);
        instr. AddOpnd (Expression (expr. exp), Opnd.arg);
        RETURN instr;
        
      | expr: IR.Cap DO
        instr := pb. AddInstr (Opcode.cap, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr;

      | expr: IR.Entier DO
        instr := pb. AddInstr (Opcode.entier, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr;
            
      | expr: IR.Shift DO
        IF expr. rotate THEN
          opcode := Opcode.rot;
        ELSE
          opcode := Opcode.lsh;
        END;
        instr := pb. AddInstr (opcode, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (Expression (expr. value), Opnd.arg);
        instr. AddOpnd (Expression (expr. by), Opnd.arg);
        RETURN instr;
        
      | expr: IR.Odd DO
        instr := pb. AddInstr (Opcode.odd, Opcode.TypeToSubclass (expr. type));
        instr. AddOpnd (Expression (expr. operand), Opnd.arg);
        RETURN instr;
            
      | expr: IR.BinaryArith DO
        CASE expr.variant OF
        | IR.arithAdd : opcode := Opcode.add;
        | IR.arithSub : opcode := Opcode.subtract;
        | IR.arithMul : opcode := Opcode.multiply;
        | IR.arithMod : opcode := Opcode.modulo;
        | IR.arithDivI: opcode := Opcode.divide;
        | IR.arithDivR: opcode := Opcode.divide;
        ELSE
          Log.Int("++ Unknown variant of BinaryArith in Expression",
                  expr. variant);
          ASSERT (FALSE);
        END;
        instr := pb. AddInstr (opcode, Opcode.TypeToSubclass (expr.left.type));
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
        
      | expr: IR.SetOp DO
        CASE expr.variant OF
        | IR.setUnion : opcode := Opcode.logicalOr;
        | IR.setDiff  : opcode := Opcode.logicalSubtr;
        | IR.setIntersect : opcode := Opcode.logicalAnd;
        | IR.setSymDiff : opcode := Opcode.logicalXor;
        ELSE
          Log.Int("++ Unknown variant of SetOp in Expression",
                  expr. variant);
          ASSERT (FALSE);
        END;
        instr := pb. AddInstr (opcode, Opcode.TypeToSubclass (expr.left.type));
        instr. AddOpnd (Expression (expr. left), Opnd.arg);
        instr. AddOpnd (Expression (expr. right), Opnd.arg);
        RETURN instr;
      | expr: IR.SetRange DO
        instr := pb. AddInstr (Opcode.setRange, Opcode.TypeToSubclass (expr.type));
        instr. AddOpnd (Expression (expr. from), Opnd.arg);
        instr. AddOpnd (Expression (expr. to), Opnd.arg);
        RETURN instr;
      | expr: IR.ChangeElement DO
        CASE expr.variant OF
        | IR.inclElement: opcode := Opcode.setBit;
        | IR.exclElement: opcode := Opcode.clearBit;
        END;
        instr := pb. AddInstr (opcode, Opcode.TypeToSubclass (expr.set.type));
        instr. AddOpnd (Expression (expr. set), Opnd.arg);
        instr. AddOpnd (Expression (expr. element), Opnd.arg);
        RETURN instr;

      | expr: IR.Concat DO
        RETURN Concat(expr);
        
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
      | expr: IR.NewBlock DO
        RETURN NewBlock (expr);
        
      | expr: IR.Call DO
        instr := Call (expr);
        (* the pessimistic assumption is that a function call can have
           arbitrary side effects; it's up to later transformations to reduce
           the impact of this  *)
        instr. AddOpnd (s, Opnd.store);
        s := instr. AddResult (Result.store);
        RETURN instr

      | expr: IR.Constructor DO
        RETURN Constructor(expr);
      | expr: IR.CurrentException DO
        RETURN pb.tryContext;
        
      ELSE
        Log.Type("++ Unknown type in Expression", expr);
        ASSERT (FALSE)
      END;
    END Expression;

  PROCEDURE Assert (assert: IR.Assert);
    VAR
      predicate: SSA.Result;
      instr: SSA.Instr;
    BEGIN
      IF (assert. predicate = NIL) THEN
        instr := AddException (pb, assert. sym, Opcode.halt, Opcode.scNone);
        instr. AddOpnd (pb. GetConstInt (assert. code), Opnd.arg);
      ELSIF ~assert.disabled THEN
        predicate := Expression (assert. predicate);
        instr := AddException (pb, assert. sym, Opcode.assert, Opcode.scNone);
        instr. AddOpnd (predicate, Opnd.arg);
        instr. AddOpnd (pb. GetConstInt (assert. code), Opnd.arg);
      END;
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
      args: POINTER TO ARRAY OF SSA.Result;
    BEGIN
      (* evaluate arguments right to left, and procedure designator last *)
      NEW(args, LEN(call.arguments^));
      FOR i := LEN (call. arguments^)-1 TO 0 BY -1 DO
        args[i] := Expression (call. arguments[i]);
      END;
      
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
        instr. AddTypedOpnd (args[i], Opnd.arg, type, isVarParam);
      END;
      RETURN instr
    END Call;

  PROCEDURE PopExceptionContext(storeIn: SSA.Result; n: LONGINT): SSA.Result;
    VAR
      instr: SSA.Instr;
    BEGIN
      IF (n # 0) THEN
        instr := pb.AddInstr(Opcode.popExceptionContext, Opcode.scNone);
        instr.AddOpnd(storeIn, Opnd.store);
        instr.AddOpnd(pb.GetConstInt(n), Opnd.arg);
        RETURN instr.AddResult(Result.store);
      ELSE
        RETURN storeIn;
      END;
    END PopExceptionContext;
  
  PROCEDURE Return (return: IR.Return);
    VAR
      instr: SSA.Instr;
      expr, store: SSA.Result;
    BEGIN
      IF (return. result # NIL) THEN
        expr := Expression (return. result);
        
        instr := pb. AddInstr (Opcode.return, Opcode.scNone);
        instr. AddOpnd (PopExceptionContext(s, return.popExceptionContext),
                        Opnd.store);
        instr. AddOpnd (expr, Opnd.functionResult);
      ELSE
        instr := pb. AddInstr (Opcode.return, Opcode.scNone);
        instr. AddOpnd (PopExceptionContext(s, return.popExceptionContext),
                        Opnd.store);
      END;
      
      store := instr. AddResult (Result.store);
      pb. selectReturn. AddOpnd (store, Opnd.storeExit);
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

  PROCEDURE WithStatm (withStatm: IR.WithStatm);
    VAR
      select, instr, typeTag: SSA.Instr;
      storeAfterGuard: SSA.Result;
      var: IR.Expression;
    BEGIN
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (Expression (withStatm. guard), Opnd.arg);
      storeAfterGuard := s;
      
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (StatmSeq (pb, storeAfterGuard, withStatm. pathTrue),
                       Opnd.arg);
      
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      IF (withStatm. pathFalse # NIL) THEN
        select. AddOpnd (StatmSeq (pb, storeAfterGuard, withStatm. pathFalse),
                         Opnd.arg);
        
      ELSIF withStatm. checkMatch THEN
        s := storeAfterGuard;
        var := withStatm. guard(IR.TypeTest). expr;
        typeTag := TypeTag (var, Expression (var), TRUE, withStatm. sym);
        instr := AddException (pb, withStatm. sym,
                               Opcode.failedWith, Opcode.scNone);
        instr. AddOpnd (typeTag, Opnd.arg);
        select. AddOpnd (s, Opnd.arg);
                        
      ELSE
        select. AddOpnd (storeAfterGuard, Opnd.arg)
      END;

      s := select. AddResult (Result.store)
    END WithStatm;

  PROCEDURE CaseStatm (caseStatm: IR.CaseStatm);
    VAR
      select, instr: SSA.Instr;
      storeAfterSelect: SSA.Result;
      i: LONGINT;

    PROCEDURE Labels (labels: IR.CaseLabels): SSA.Instr;
      VAR
        i: LONGINT;
        instr: SSA.Instr;
        value: SSA.Result;
        l: IR.Expression;
      BEGIN
        instr := pb. AddInstr (Opcode.labels, Opcode.scNone);
        FOR i := 0 TO LEN (labels^)-1 DO
          l := labels[i];
          WITH l: IR.SetRange DO
            instr. AddOpnd (Expression (l. from), Opnd.arg);
            instr. AddOpnd (Expression (l. to), Opnd.arg);
          ELSE
            value := Expression (l);
            instr. AddOpnd (value, Opnd.arg);
            instr. AddOpnd (value, Opnd.arg);
          END;
        END;
        RETURN instr
      END Labels;
    
    BEGIN
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (Expression (caseStatm. select), Opnd.arg);
      storeAfterSelect := s;

      FOR i := 0 TO LEN (caseStatm. caseList^)-1 DO
        IF (LEN (caseStatm. caseList[i]. labels^) > 0) THEN
          select. AddOpnd (Labels (caseStatm. caseList[i]. labels),
                           Opnd.labels);
          select. AddOpnd (StatmSeq (pb, storeAfterSelect,
                                     caseStatm. caseList[i]. statmSeq),
                           Opnd.arg);
        END;
      END;
      
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.labels);
      IF (caseStatm. default # NIL) THEN
        select. AddOpnd (StatmSeq (pb, storeAfterSelect, caseStatm. default),
                         Opnd.arg);
        
      ELSIF caseStatm. checkMatch THEN
        s := storeAfterSelect;
        instr := AddException (pb, caseStatm. sym,
                               Opcode.failedCase, Opcode.scNone);
        instr. AddOpnd (select. opndList. arg, Opnd.arg);
        select. AddOpnd (s, Opnd.arg);
        
      ELSE
        select. AddOpnd (storeAfterSelect, Opnd.arg)
      END;

      s := select. AddResult (Result.store)
    END CaseStatm;
  
  PROCEDURE RepeatStatm (repeatStatm: IR.RepeatStatm);
    VAR
      start, end, exit, select: SSA.Instr;
      guard: SSA.Result;
    BEGIN
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);
      
      (* evaluate loop body, followed by the exit condition *)
      s := StatmSeq (pb, s, repeatStatm. body);
      guard := Expression (repeatStatm. exitCondition);

      (* create "select" with "exit" *)
      exit := pb. AddInstr (Opcode.exit, Opcode.scNone);
      exit. AddOpnd (s, Opnd.store);
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (exit. AddResult (Result.store), Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (s, Opnd.arg);
      s := select. AddResult (Result.store);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);
      (* link "exit" to "loop-end" *)
      end. AddOpnd (exit. nextResult, Opnd.storeExit);
      
      s := end. AddResult (Result.store)
    END RepeatStatm;
  
  PROCEDURE WhileStatm (whileStatm: IR.WhileStatm);
    VAR
      start, end, select, exit: SSA.Instr;
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
      
      (* create "select" with "exit" *)
      exit := pb. AddInstr (Opcode.exit, Opcode.scNone);
      exit. AddOpnd (s, Opnd.store);
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard2, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (s, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (exit. AddResult (Result.store), Opnd.arg);
      s := select. AddResult (Result.store);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);
      (* link "exit" to "loop-end" *)
      end. AddOpnd (exit. nextResult, Opnd.storeExit);
      
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
      start, end, select, exit, dummy: SSA.Instr;
      guard1, guard2, storeAfterGuard1, v, endValue, stepValue: SSA.Result;

    PROCEDURE Guard (bound: SSA.Result): SSA.Instr;
      VAR
        instr: SSA.Instr;
        cmpClass: Opcode.Class;
      BEGIN
        IF forStatm.PositiveStep() THEN
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
      
      (* create "select" with "exit" *)
      exit := pb. AddInstr (Opcode.exit, Opcode.scNone);
      exit. AddOpnd (s, Opnd.store);
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard2, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (s, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (exit. AddResult (Result.store), Opnd.arg);
      s := select. AddResult (Result.store);
      
      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);
      (* link "exit" to "loop-end" *)
      end. AddOpnd (exit. nextResult, Opnd.storeExit);
      
      (* create the "select" for the IF statement around the loop *)
      select := pb. AddInstr (Opcode.select, Opcode.scNone);
      select. AddOpnd (guard1, Opnd.arg);
      select. AddOpnd (pb. GetConstBool (TRUE), Opnd.arg);
      select. AddOpnd (end. AddResult (Result.store), Opnd.arg);
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      select. AddOpnd (storeAfterGuard1, Opnd.arg);

      s := select. AddResult (Result.store);
    END ForStatm;
  
  PROCEDURE IterateArrayStatm (iterStatm: IR.IterateArrayStatm);
    VAR
      curr2, collect: SSA.Instr;
      end, get, loopStart, loopEnd, select, exit: SSA.Instr;
      array, numElements, size, start, curr,
          guard1, guard2, storeAfterGuard1, v: SSA.Result;
      elementType: Sym.Type;
      opnd: SSA.Opnd;

    PROCEDURE Guard (curr: SSA.Result): SSA.Instr;
      VAR
        instr: SSA.Instr;
      BEGIN
        instr := pb.AddInstr(Opcode.neq, Opcode.scBoolean);
        instr.AddOpnd(end, Opnd.arg);
        instr.AddOpnd(curr, Opnd.arg);
        RETURN instr
      END Guard;

    BEGIN
      (* FOR v IN a DO s END;

         is translated to

         curr := adr(a);
         end := curr+sizeof(a);
         IF (curr # end) THEN
           esize := sizeof(a[0]);
           REPEAT
             v := get(start);
             s;
             curr := curr+esize;
           UNTIL (curr = end);
         END *)
      array := Expression(iterStatm.range);
      numElements := CalculateLength(pb, iterStatm.range, -1, array);
      size := CalculateSize(pb, iterStatm.range, numElements);
      
      start := array.instr.GetArgClass(Opnd.readAdr);
      end := pb.AddInstr(Opcode.add, Opcode.scAddress);
      end.AddOpnd(start, Opnd.arg);
      end.AddOpnd(FixAddress(size), Opnd.arg);

      (* only if the array is not empty we enter the loop *)
      guard1 := Guard(start);
      storeAfterGuard1 := s;

      (* insert "loop-start" instruction *)
      collect := pb.AddInstr(Opcode.collect, Opcode.scNone);
      collect.AddOpnd(s, Opnd.store);
      collect.AddOpnd(start, Opnd.arg);
      loopStart := pb.AddInstr(Opcode.loopStart, Opcode.scNone);
      loopStart.AddOpnd(collect.AddResult(Result.store), Opnd.store);
      s := loopStart.AddResult(Result.store);
      curr := loopStart.AddResultSubclass(Result.selectValue,
                                          Opcode.scAddress);

      (* retrieve current value *)
      elementType := TR.ArrayElementType(iterStatm.range.type);
      get := pb.AddInstr(Opcode.get, Opcode.TypeToSubclass(elementType));
      get.AddOpnd(s, Opnd.store);
      get.AddOpnd(curr, Opnd.readAdr);
      opnd := array.instr.GetOpndClass(Opnd.readDesign);
      WHILE (opnd # NIL) & (opnd.class = Opnd.readDesign) DO
        get.AddOpnd(opnd.arg, Opnd.readDesign);
        opnd := opnd.nextOpnd;
      END;
      s := get.AddResult(Result.store);  (* for the sake of Destore *)
          
      (* set variable to the current value *)
      v := Expression(iterStatm. var);
      Chain(pb.AddSetInstr(v(SSA.Instr), get));
      
      (* evaluate loop body *)
      s := StatmSeq(pb, s, iterStatm.body);

      (* increment pointer into array *)
      curr2 := pb.AddInstr(Opcode.add, Opcode.scAddress);
      curr2.AddOpnd (curr, Opnd.arg);
      curr2.AddOpnd (FixAddress(pb.GetConstInt(elementType.size)), Opnd.arg);
      
      guard2 := Guard (curr2);
      
      (* create "select" with "exit" *)
      exit := pb.AddInstr(Opcode.exit, Opcode.scNone);
      exit.AddOpnd(s, Opnd.store);
      select := pb.AddInstr(Opcode.select, Opcode.scNone);
      select.AddOpnd(guard2, Opnd.arg);
      select.AddOpnd(pb.GetConstBool(TRUE), Opnd.arg);
      select.AddOpnd(s, Opnd.arg);
      select.AddOpnd(pb.GetConstBool(FALSE), Opnd.arg);
      select.AddOpnd(exit.AddResult(Result.store), Opnd.arg);
      s := select.AddResult(Result.store);
      
      (* create "loop-end" instruction *)
      loopEnd := pb.AddInstr(Opcode. loopEnd, Opcode.scNone);
      loopEnd.AddOpnd(loopStart, Opnd.arg);
      (* add backward feed of `store' to "loop-end" *)
      collect := pb.AddInstr(Opcode.collect, Opcode.scNone);
      collect.AddOpnd(s, Opnd.store);
      collect.AddOpnd(curr2, Opnd.arg);
      loopEnd.AddOpnd(collect.AddResult(Result.store), Opnd.backwardFeed);
      (* link "exit" to "loop-end" *)
      loopEnd.AddOpnd(exit.nextResult, Opnd.storeExit);
      
      (* create the "select" for the IF statement around the loop *)
      select := pb.AddInstr(Opcode.select, Opcode.scNone);
      select.AddOpnd(guard1, Opnd.arg);
      select.AddOpnd(pb.GetConstBool(TRUE), Opnd.arg);
      select.AddOpnd(loopEnd.AddResult(Result.store), Opnd.arg);
      select.AddOpnd(pb.GetConstBool(FALSE), Opnd.arg);
      select.AddOpnd(storeAfterGuard1, Opnd.arg);

      s := select.AddResult(Result.store);
    END IterateArrayStatm;
  
  PROCEDURE IterateObjectStatm (iterStatm: IR.IterateObjectStatm);
    VAR
      loopStart, loopEnd, select, exit: SSA.Instr;
      iterator, guard1, guard2, storeAfterGuard1: SSA.Result;

    PROCEDURE Guard(): SSA.Instr;
      VAR
        res: SSA.Result;
        instr, typeTag: SSA.Instr;
      BEGIN
        res := Expression(iterStatm.stepperCall);
        instr := res(SSA.Instr);
        typeTag := instr.opndList.arg(SSA.Instr).opndList.arg(SSA.Instr);
        typeTag.opndList.ReplaceArg(iterator);
        instr.opndList.nextOpnd.ReplaceArg(iterator);
        RETURN instr;
      END Guard;

    BEGIN
      (* FOR v IN obj.Iterator() DO s END;

         is translated to

         temp := obj.Iterator();
         IF temp.Next(v) THEN
           REPEAT
             s;
           UNTIL ~temp.Next(v);
         END *)
      iterator := Expression(iterStatm.iteratorFactory);
      
      (* only if the first call to Next() is successful we enter the loop *)
      guard1 := Guard();
      storeAfterGuard1 := s;

      (* insert "loop-start" instruction *)
      loopStart := pb.AddInstr(Opcode.loopStart, Opcode.scNone);
      loopStart.AddOpnd(s, Opnd.store);
      s := loopStart.AddResult(Result.store);

      (* evaluate loop body *)
      s := StatmSeq(pb, s, iterStatm.body);

      (* next call to Next() *)
      guard2 := Guard();
      
      (* create "select" with "exit" *)
      exit := pb.AddInstr(Opcode.exit, Opcode.scNone);
      exit.AddOpnd(s, Opnd.store);
      select := pb.AddInstr(Opcode.select, Opcode.scNone);
      select.AddOpnd(guard2, Opnd.arg);
      select.AddOpnd(pb.GetConstBool(TRUE), Opnd.arg);
      select.AddOpnd(s, Opnd.arg);
      select.AddOpnd(pb.GetConstBool(FALSE), Opnd.arg);
      select.AddOpnd(exit.AddResult(Result.store), Opnd.arg);
      s := select.AddResult(Result.store);
      
      (* create "loop-end" instruction *)
      loopEnd := pb.AddInstr(Opcode. loopEnd, Opcode.scNone);
      loopEnd.AddOpnd(loopStart, Opnd.arg);
      (* add backward feed of `store' to "loop-end" *)
      loopEnd.AddOpnd(s, Opnd.backwardFeed);
      (* link "exit" to "loop-end" *)
      loopEnd.AddOpnd(exit.nextResult, Opnd.storeExit);
      
      (* create the "select" for the IF statement around the loop *)
      select := pb.AddInstr(Opcode.select, Opcode.scNone);
      select.AddOpnd(guard1, Opnd.arg);
      select.AddOpnd(pb.GetConstBool(TRUE), Opnd.arg);
      select.AddOpnd(loopEnd.AddResult(Result.store), Opnd.arg);
      select.AddOpnd(pb.GetConstBool(FALSE), Opnd.arg);
      select.AddOpnd(storeAfterGuard1, Opnd.arg);

      s := select.AddResult(Result.store);
    END IterateObjectStatm;
  
  PROCEDURE LoopStatm (loopStatm: IR.LoopStatm);
    VAR
      start, end, oldSelect: SSA.Instr;
    BEGIN
      start := pb. AddInstr (Opcode.loopStart, Opcode.scNone);
      start. AddOpnd (s, Opnd.store);
      s := start. AddResult (Result.store);

      (* create "loop-end" instruction *)
      end := pb. AddInstr (Opcode. loopEnd, Opcode.scNone);
      end. AddOpnd (start, Opnd.arg);
      end. AddOpnd (start, Opnd.backwardFeed); (* placeholder *)
      oldSelect := pb. SetLoopContext (end);
      
      (* evaluate loop body *)
      s := StatmSeq (pb, s, loopStatm. body);
      
      (* add backward feed of `store' to "loop-end" *)
      AddStoreBackwardFeed (pb, end, s);

      (* note: any EXIT instructions in the loop body have added themself
         to the "loop-end" instruction *)
      
      s := end. AddResult (Result.store);
      end := pb. SetLoopContext (oldSelect);
    END LoopStatm;

  PROCEDURE Exit (exit: IR.Exit);
    VAR
      instr: SSA.Instr;
      store: SSA.Result;
    BEGIN
      s := PopExceptionContext(s, exit.popExceptionContext);
      instr := pb. AddInstr (Opcode.exit, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      
      store := instr. AddResult (Result.store);
      pb. loopContext. AddOpnd (store, Opnd.storeExit);
      s := store
    END Exit;

  PROCEDURE TryStatm(try: IR.TryStatm);
    VAR
      start, instr, e, end, typeTag, typeTest,
          pushExceptionContext, oldPushContext: SSA.Instr;
      sDefault, sCatch, catchClause: SSA.Result;
      i: LONGINT;
    BEGIN
      start := pb.AddInstr(Opcode.tryStart, Opcode.scBoolean);
      start.AddOpnd(s, Opnd.store);
      s := start.AddResult(Result.store);
      
      (* evaluate TRY body *)
      instr := pb.AddInstr(Opcode.pushExceptionContext, Opcode.scNone);
      instr.AddOpnd(s, Opnd.store);
      oldPushContext := pb.SetTryContext(instr);
      s := StatmSeq(pb, instr.AddResult(Result.store), try.statmSeq);
      sDefault := PopExceptionContext(s, 1);
      pushExceptionContext := instr;
      
      (* prepare CATCH block *)
      s := PopExceptionContext(start.AddResult(Result.store), 1);
      
      (* get type tag of current exception *)
      e := pb.AddInstr(Opcode.currentException, Opcode.scAddress);
      e.AddOpnd(pb.tryContext, Opnd.arg);
      e.AddOpnd(s, Opnd.store);
      instr := pb.SetTryContext(e); (* set `tryContext' to current exception *)
      typeTag := pb.AddInstr(Opcode.typeTag, Opcode.scAddress);
      typeTag.AddOpnd(e, Opnd.arg);
      sCatch := s;
      
      (* prepare fall through path *)
      instr := pb.AddInstr(Opcode.activateContext, Opcode.scNone);
      instr.AddOpnd(s, Opnd.store);
      s := instr.AddResult(Result.store);
      
      FOR i := LEN(try.catchList^)-1 TO 0 BY -1 DO
        typeTest := pb.AddInstr(Opcode.typeTest, Opcode.scBoolean);
        typeTest.AddOpnd(typeTag, Opnd.arg);
        typeTest.AddOpnd(pb.GetTypeRef(try.catchList[i].exceptionType(Sym.Pointer).baseType), Opnd.type);

        catchClause := StatmSeq(pb, sCatch, try.catchList[i].statmSeq);
        instr := pb.AddInstr(Opcode.select, Opcode.scNone);
        instr.AddOpnd(typeTest, Opnd.arg);
        instr.AddOpnd(pb.GetConstBool(TRUE), Opnd.arg);
        instr.AddOpnd(catchClause, Opnd.arg);
        instr.AddOpnd(pb.GetConstBool(FALSE), Opnd.arg);
        instr.AddOpnd(s, Opnd.arg);
        s := instr.AddResult(Result.store);
      END;
      instr := pb.AddInstr(Opcode.clearException, Opcode.scNone);
      instr.AddOpnd(pushExceptionContext, Opnd.arg);
      instr.AddOpnd(s, Opnd.store);
      s := instr.AddResult(Result.store);
      
      (* merge paths through body and CATCH block *)
      instr := pb.AddInstr(Opcode.select, Opcode.scNone);
      instr.AddOpnd(start, Opnd.arg);
      instr.AddOpnd(pb.GetConstBool(FALSE), Opnd.arg);
      instr.AddOpnd(sDefault, Opnd.arg);
      instr.AddOpnd(pb.GetConstBool(TRUE), Opnd.arg);
      instr.AddOpnd(s, Opnd.arg);
      
      (* create instruction marking the end of the block *)
      end := pb.AddInstr(Opcode.tryEnd, Opcode.scNone);
      end.AddOpnd(instr.AddResult(Result.store), Opnd.store);
      s := end.AddResult(Result.store);
      
      instr := pb.SetTryContext(oldPushContext);
    END TryStatm;
  
  PROCEDURE CopyParameter (cp: IR.CopyParameter);
    VAR
      instr: SSA.Instr;
      len: SSA.Result;
    BEGIN
      len := CalculateLength(pb, cp.param, -1, Expression (cp.param));
      instr := pb. AddCopyParameter(cp. param. decl(Sym.VarDecl), s, len,
                                    CalculateSize(pb, cp.param, len));
      s := instr. AddResult (Result.store);
    END CopyParameter;
  
  PROCEDURE MoveBlock (move: IR.MoveBlock): SSA.Instr;
    VAR
      instr: SSA.Instr;
      source, dest, size: SSA.Result;
    BEGIN
      source := Expression (move. source);
      dest := Expression (move. dest);
      size := Expression (move. size);

      instr := pb. AddInstr (Opcode.moveBlock, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      instr. AddOpnd (source, Opnd.readAdr);
      instr. AddOpnd (dest, Opnd.writeAdr);
      instr. AddOpnd (size, Opnd.arg);
      
      RETURN instr;
    END MoveBlock;
  
  PROCEDURE Raise (raise: IR.Raise): SSA.Instr;
    VAR
      instr: SSA.Instr;
      exception: SSA.Result;
    BEGIN
      exception := Expression (raise. exception);
      instr := pb. AddInstr (Opcode.raiseException, Opcode.scNone);
      instr. AddOpnd (s, Opnd.store);
      instr. AddOpnd (exception, Opnd.arg);
      RETURN instr;
    END Raise;
  
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statm := statmSeq[i];
      WITH statm: IR.Assert DO
        Assert (statm);

      | statm: IR.Assignment DO
        Chain (Assignment (statm));
            
      | statm: IR.Call DO
        Chain (Call (statm));
        
      | statm: IR.Return DO
        Return (statm);

      | statm: IR.IfStatm DO
        IfStatm (statm);

      | statm: IR.WithStatm DO
        WithStatm (statm);

      | statm: IR.CaseStatm DO
        CaseStatm (statm);
            
      | statm: IR.RepeatStatm DO
        RepeatStatm (statm);
            
      | statm: IR.WhileStatm DO
        WhileStatm (statm);

      | statm: IR.ForStatm DO
        ForStatm (statm);

      | statm: IR.IterateArrayStatm DO
        IterateArrayStatm (statm);

      | statm: IR.IterateObjectStatm DO
        IterateObjectStatm (statm);

      | statm: IR.LoopStatm DO
        LoopStatm (statm);

      | statm: IR.Exit DO
        Exit (statm);

      | statm: IR.TryStatm DO
        TryStatm (statm);
        
      | statm: IR.Copy DO
        Chain (Copy (statm));
            
      | statm: IR.CopyParameter DO
        CopyParameter (statm);
            
      | statm: IR.CopyString DO
        Chain (CopyString (statm));

      | statm: IR.MoveBlock DO
        Chain (MoveBlock (statm));

      | statm: IR.Raise DO
        Chain (Raise (statm));
      ELSE
        Log.Type("++ Unknown statement class in StatmSeq", statm);
        ASSERT (FALSE)
      END;
    END;
    RETURN s
  END StatmSeq;

PROCEDURE DiscardGets* (pb: SSA.ProcBlock);
  VAR
    instr, next: SSA.Instr;
    storeOut: SSA.Result;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr. nextInstr;
      IF (instr. opcode = Opcode.get) & (instr. useList = NIL) THEN
        storeOut := instr. GetResultStore();
        storeOut. ReplaceUses (instr. opndList. arg);
        pb. DeleteInstr (instr);
      END;
      instr := next;
    END;
  END DiscardGets;

END OOC:SSA:IRtoSSA.
