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
  Log, Language:String8, Language:Integer,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef, OOC:IR, 
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result, OOC:SSA:Allocator;


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
      IF (instr. opcode = Opcode.set) OR
         (instr. opcode = Opcode.copyString) OR
         (instr. opcode = Opcode.newObject) THEN
        instr. opndList. ReplaceArg (s);
      ELSE
        instr. AddOpnd (s, Opnd.store);
      END;
      s := instr. AddResult (Result.store)
    END Chain;

  PROCEDURE ^ Call (call: IR.Call): SSA.Instr;
  PROCEDURE ^ Expression (expr: IR.Expression): SSA.Result;
    
  PROCEDURE CalculateSize (pb: SSA.ProcBlock; value: IR.Expression;
                           dim: LONGINT; baseArray: SSA.Result): SSA.Instr;
  (* Calculate the size of the variable @oparam{value} or of one of its
     elements.  With @oparam{dim=-1}, return the size of the whole variable.
     With @oparam{dim>=0}, return the size of an array element of dimension
     @oparam{dim}.  @oparam{baseArray} holds the (virtual, and dead)
     @oconst{Opcode.get} instruction on the array variable.  *)
    VAR
      type: Sym.Type;
      i: LONGINT;
      
    PROCEDURE RecursiveGetSize (type: Sym.Type; dim: LONGINT): SSA.Instr;
      VAR
        size: SSA.Instr;
      BEGIN
        IF (type IS Sym.Array) & type(Sym.Array). isOpenArray THEN
          size := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
          size. AddOpnd (pb. AddGetLengthInstr (baseArray(SSA.Instr),
                                                dim+1, type(Sym.Array)),
                         Opnd.arg);
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
  
  PROCEDURE TypeOfString (type: Sym.Type): Sym.Type;
    BEGIN
      WITH type: Sym.Array DO
        IF (type. elementType IS Sym.PredefType) THEN
          CASE type. elementType(Sym.PredefType). id OF
          | Predef.char, Predef.longchar:
            RETURN type. elementType;
          ELSE
            RETURN NIL;
          END;
        ELSE
          RETURN NIL;
        END;
      | type: Sym.PredefType DO
        CASE type. id OF
        | Predef.charString, Predef.longcharString:
          RETURN Predef.GetType (type. id-Predef.charString+Predef.char);
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
  
  PROCEDURE Copy (cp: IR.Copy): SSA.Instr;
    VAR
      instr: SSA.Instr;
      source, dest: SSA.Result;
    BEGIN
      source := Expression (cp. source);
      dest := Expression (cp. dest);
      
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
        instr. AddOpnd (pb. GetTypeRef (deref. pointer. type), Opnd.readDesign);
        instr. AddOpnd (address, Opnd.readDesign);
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

    PROCEDURE AddException (pb: SSA.ProcBlock; opcode: Opcode.Class;
                            subclass: Opcode.Subclass): SSA.Instr;
      VAR
        instr: SSA.Instr;
      BEGIN
        instr := pb. AddInstr (opcode, subclass);
        Chain (instr);
        RETURN instr;
      END AddException;
    
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
        elementType: Sym.Type;
      BEGIN
        length := pb. AddGetLengthInstr (baseArray(SSA.Instr), dim,
                                         indexOp. array. type(Sym.Array));
        newSize := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
        newSize. AddOpnd (elementSize, Opnd.arg);
        newSize. AddOpnd (length, Opnd.arg);
        
        IF (indexOp. array IS IR.Index) THEN
          baseResult := Index (indexOp. array(IR.Index), baseArray,
                               newSize, dim-1);
        ELSE
          baseResult := baseArray;
          ASSERT (dim = 0);
        END;
        INC (dim);
        ASSERT (baseResult. instr. opcode = Opcode.get);
        
        (* take the "get" instruction of the array's designator and
           change it into a "get" for the array element *)
        instr := baseResult. instr;
        index := Expression (indexOp. index);
        IF FALSE & indexOp. checkIndex THEN
          check := AddException (pb, Opcode.checkIndex, index. subclass);
          check. AddOpnd (index, Opnd.arg);
          check. AddOpnd (length, Opnd. arg);
          index := check;
        END;
        
        elementType := indexOp. type;
        scaledIndex := pb. AddInstr (Opcode.multiply, Opcode.scAddress);
        scaledIndex. AddOpnd (index, Opnd.arg);
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
        scSource, scDest: Opcode.Subclass;
      BEGIN
        scDest := Opcode.TypeToSubclass (conv. type);
        scSource := Opcode.TypeToSubclass (conv. expr. type);
        IF (Allocator.RegisterType (Allocator.SubclassToBasicType (scDest)) #
            Allocator.RegisterType (Allocator.SubclassToBasicType (scSource))) THEN
          (* only insert explicit type-conv instruction if the source and
             the destination value are stored in different register sets;
             not sure if this optimization should be done here, though, because
             it makes type information in SSA less strict *)
          instr := pb. AddInstr (Opcode.typeConv, scDest);
          instr. AddOpnd (Expression (conv. expr), Opnd.arg);
          RETURN instr;
        ELSE
          RETURN Expression (conv. expr);
        END;
      END TypeConv;
    
    PROCEDURE SelectProc (selectOp: IR.SelectProc): SSA.Result;
      BEGIN
        IF selectOp. isStaticCall THEN   (* use static address *)
          RETURN pb. GetAddress (selectOp. tbProc);
        ELSE                             (* use dynamic address *)
          instr := pb. AddInstr (Opcode.tbProcAddress, Opcode.scAddress);
          instr. AddOpnd (TypeTag (selectOp. receiver), Opnd.arg);
          instr. AddOpnd (pb. GetDeclRef (selectOp. tbProc), Opnd.arg);
          RETURN instr;
        END;
      END SelectProc;
    
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

      | expr: IR.TypeRef DO
        RETURN pb. GetTypeRef (expr. decl(Sym.TypeDecl). type);
        
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
        IF (expr. variant = IR.lenStringConst) THEN
          RETURN pb. GetConstInt (expr. arrayVariable(IR.Const). value(String8.Value). value. length+1);
        ELSE
          baseArray := Expression (expr. arrayVariable);
          type := expr. arrayVariable. type(Sym.Array). GetNthElementType (expr. dim);
          RETURN pb. AddGetLengthInstr (baseArray(SSA.Instr), expr. dim,
                                        type(Sym.Array));
        END;

      | expr: IR.Deref DO
        RETURN Deref (expr);
        
      | expr: IR.Index DO
        baseArray := GetIndexBaseArray (expr, dim);
        RETURN Index (expr, baseArray, CalculateSize (pb, expr, -1, baseArray), dim);

      | expr: IR.SelectField DO
        RETURN SelectField (expr);
        
      | expr: IR.SelectProc DO
        RETURN SelectProc (expr);

      | expr: IR.TypeCast DO
        RETURN TypeCast (expr);
      | expr: IR.TypeConv DO
        RETURN TypeConv (expr);
      | expr: IR.TypeTag DO
        RETURN TypeTag (expr. design);
      | expr: IR.TypeTest DO
        RETURN TypeTest (expr);
        
      | expr: IR.Negate DO
        instr := pb. AddInstr (Opcode.negate,
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
        instr := pb. AddInstr (Opcode.lsh, Opcode.TypeToSubclass (expr. type));
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
(*        | IR.setDiff  : opcode := Opcode.subtract;*)
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

  PROCEDURE CaseStatm (caseStatm: IR.CaseStatm);
    VAR
      select: SSA.Instr;
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
        select. AddOpnd (Labels (caseStatm. caseList[i]. labels),
                         Opnd.labels);
        select. AddOpnd (StatmSeq (pb, storeAfterSelect,
                                   caseStatm. caseList[i]. statmSeq),
                         Opnd.arg);
      END;
      
      select. AddOpnd (pb. GetConstBool (FALSE), Opnd.arg);
      IF (caseStatm. default # NIL) THEN
        select. AddOpnd (StatmSeq (pb, storeAfterSelect, caseStatm. default),
                         Opnd.labels);
      ELSE
        select. AddOpnd (storeAfterSelect, Opnd.labels)
      END;

      s := select. AddResult (Result.store)
    END CaseStatm;
  
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
        IF (forStatm. step(IR.Const). value(Integer.Value). Sign() >= 0) THEN
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
          (cp. param. decl(Sym.VarDecl), s,
           CalculateSize (pb, cp. param, -1, Expression (cp. param)));
      s := instr. AddResult (Result.store);
    END CopyParameter;
  
  BEGIN
    FOR i := 0 TO LEN (statmSeq^)-1 DO
      statm := statmSeq[i];
      WITH statm: IR.Assert DO
        Chain (Assert (statm));

      | statm: IR.Assignment DO
        Chain (Assignment (statm));
            
      | statm: IR.Call DO
        Chain (Call (statm));
        
      | statm: IR.Return DO
        (* lets pretend for a moment that a RETURN is not a control flow
           construct... FIXME *)
        Return (statm);

      | statm: IR.IfStatm DO
        IfStatm (statm);

      | statm: IR.CaseStatm DO
        CaseStatm (statm);
            
      | statm: IR.RepeatStatm DO
        RepeatStatm (statm);
            
      | statm: IR.WhileStatm DO
        WhileStatm (statm);

      | statm: IR.ForStatm DO
        ForStatm (statm);

      | statm: IR.LoopStatm DO
        LoopStatm (statm);

      | statm: IR.Exit DO
        Exit (statm);
        
      | statm: IR.Copy DO
        Chain (Copy (statm));
            
      | statm: IR.CopyParameter DO
        CopyParameter (statm);
            
      | statm: IR.CopyString DO
        Chain (CopyString (statm));
            
      ELSE
        Log.Type("++ Unknown statement class in StatmSeq", statm);
        ASSERT (FALSE)
      END;
    END;
    RETURN s
  END StatmSeq;

END OOC:SSA:IRtoSSA.
