MODULE OOC:X86:Translate;

IMPORT
  Object:Boxed, ADT:ArrayList, IO,
  Rep := OOC:Repository, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  TR := OOC:SymbolTable:TypeRules, OOC:IR,
  S := OOC:X86:SSA, M := OOC:X86:Machine, B := OOC:X86:Block,
  R := OOC:X86:Register, W := OOC:X86:Write, OOC:X86:Destore,
  OOC:X86:ConstProp, OOC:X86:Algebraic, D := OOC:X86:Debug;

(*CONST
  truePath = 0;
  falsePath = 1;*)
  
PROCEDURE Translate*(m: Rep.Module; symTab: Sym.Module; moduleIR: IR.Module;
                     ch: IO.ByteChannel);
  VAR
    w: W.Writer;
    p: IR.Procedure;

    (* translator state: *)
    b: S.FunctionBlock;
    sp, fp: S.Result;
    returns, loopExits: ArrayList.ArrayList(S.Instr);
    controlCP, memoryCP: S.Instr;
    
  PROCEDURE ControlCP(instr: S.Instr);
    BEGIN
      instr.AddDep(S.depControl, controlCP);
      controlCP := instr;
    END ControlCP;
  
  PROCEDURE MemoryCP(instr: S.Instr);
    BEGIN
      instr.AddDep(S.depMemory, memoryCP);
      memoryCP := instr;
    END MemoryCP;
  
  PROCEDURE FixAddress(arg: S.Result): S.Result;
    BEGIN
      RETURN b.FixType(arg, S.address);
    END FixAddress;
  
  PROCEDURE FixLength(arg: S.Result): S.Result;
    BEGIN
      RETURN b.FixType(arg, S.length);
    END FixLength;
  
  PROCEDURE FailedCheck(fctName: STRING; pos: LONGINT; arg: S.Result);
    VAR
      instr: S.Instr;
    BEGIN
      instr := b.AddInstr2(S.call, b.AddAdrRT(fctName), sp);
      instr.AddOpnd(b.AddAdrModuleDescr());
      instr.AddOpnd(b.AddConstLength(pos));
      IF (arg # NIL) THEN
        instr.AddOpnd(arg);
      END;
      MemoryCP(instr);
      ControlCP(instr);
    END FailedCheck;
  
  PROCEDURE Memcpy(from, to, size: S.Result);
    VAR
      instr: S.Instr;
    BEGIN
      instr := b.AddInstr2(S.call, b.AddAdrRT("memcpy"), sp);
      instr.AddOpnd(to);
      instr.AddOpnd(from);
      instr.AddOpnd(size);
      
      MemoryCP(instr);
      ControlCP(instr);
    END Memcpy;
  
  PROCEDURE StatmSeq(statmSeq: IR.StatementSeq);
  (**Translates the statement sequence @oparam{statmSeq} into a straightforward
     SSA representation.  Instructions are added to the block @ovar{b}.  *)
    VAR
      statm: IR.Statement;
      instr, endTrue, endFalse: S.Instr;
      merge: S.MergeInstr;
      res, var: S.Result;
      controlTrue, memoryTrue, controlFalse, memoryFalse: S.Instr;
      loopStart: S.LoopStartInstr;
      irExpr: IR.Expression;
      type: S.Type;
      oldLoopExits: ArrayList.ArrayList(S.Instr);
      
    PROCEDURE SetCC(res: S.Result): S.Result;
      VAR
        instr: S.Instr;
      BEGIN
        IF (res.register = S.cc) THEN
          RETURN res;
        ELSE
          instr := b.AddInstr2(S.neq, res, b.AddConstBool(FALSE));
          RETURN instr.AddResultReg(S.noType, S.cc);
        END;
      END SetCC;

    PROCEDURE SetBool(res: S.Result): S.Result;
      VAR
        instr: S.Instr;
      BEGIN
        IF (res.register = S.cc) THEN
          instr := b.AddInstr1(S.setBool, res);
          RETURN instr.AddResult(S.boolean);
        ELSE
          RETURN res;
        END;
      END SetBool;

    PROCEDURE AddJump(): S.Instr;
      VAR
        instr: S.Instr;
      BEGIN
        instr := b.AddInstr0(S.jump);
        ControlCP(instr);
        MemoryCP(instr);
        RETURN instr;
      END AddJump;

    PROCEDURE SplitPaths(bool: S.Result; controlCP, memoryCP: S.Instr;
                         VAR controlTrue, memoryTrue: S.Instr;
                         VAR controlFalse, memoryFalse: S.Instr);
    (**Takes a boolean expression @oparam{bool} and produces the two paths,
       ``true'' and ``false'', that are traversed depending on the outcome of
       the boolean expression.

       @oparam{controlCP} and @oparam{memoryCP} are the control and memory
       checkpoints that are valid after @oparam{bool} has been evaluated.  *)
      VAR
        instr: S.Instr;
        gate: S.GateInstr;
        merge: S.MergeInstr;

      PROCEDURE SplitValue();
        VAR
          pathTrue, pathFalse: S.Block;
          branch: S.BranchInstr;
        BEGIN
          (* case: boolean value *)
          branch := b.AddBranch(SetCC(bool), FALSE);
          branch.AddDep(S.depControl, controlCP);
          
          (* first, the "true" path *)
          pathTrue := b.AddMerge0(S.guard, b.AddConstBool(TRUE));
          pathTrue.AddDep(S.depControl, branch);
          controlTrue := pathTrue;
          memoryTrue := memoryCP;
          
          (* second, the "false" path;  *)
          pathFalse := b.AddMerge0(S.guard, b.AddConstBool(FALSE));
          pathFalse.AddDep(S.depControl, branch);
          controlFalse := pathFalse;
          memoryFalse := memoryCP;
          
          branch.SetPaths2(pathTrue, pathFalse);
        END SplitValue;
      
      PROCEDURE SplitAndGate(gate: S.GateInstr; testValue: S.Result;
                             bailOutPath, testPath: S.Instr);
        VAR
          merge: S.MergeInstr;
          ct, mt, cf, mf, guard, branch, instr: S.Instr;
        BEGIN
          SplitPaths(testValue,
                     testPath.GetBeforeInstr(S.depControl),
                     testPath.GetBeforeInstr(S.depMemory),
                     ct, mt, cf, mf);

          guard := bailOutPath.GetBeforeInstr(S.depControl);
          ASSERT(guard.opcode = S.guard);
          branch := guard.GetBranchBeforeInstr(S.depControl);
          ASSERT(branch.opcode = S.branch);
          controlTrue := ct; memoryTrue := mt;

          instr := b.AddInstr0(S.jump);
          instr.AddDep(S.depControl, cf);
          instr.AddDep(S.depMemory, mf);
          controlFalse := bailOutPath.GetBeforeInstr(S.depControl);
          memoryFalse := bailOutPath.GetBeforeInstr(S.depMemory);
          controlFalse(S.MergeInstr).AddJump(instr);
          
          (* ditch old gate, its merge, and the jumps into it *)
          merge := gate.merge(S.MergeInstr);
          gate.Delete();
          merge.Delete();
          bailOutPath.Delete();
          testPath.Delete();
        END SplitAndGate;
      
      PROCEDURE SplitOrGate(gate: S.GateInstr; testValue: S.Result;
                            bailOutPath, testPath: S.Instr);
        VAR
          merge: S.MergeInstr;
          ct, mt, cf, mf, guard, branch, instr: S.Instr;
        BEGIN
          SplitPaths(testValue,
                     testPath.GetBeforeInstr(S.depControl),
                     testPath.GetBeforeInstr(S.depMemory),
                     ct, mt, cf, mf);

          guard := bailOutPath.GetBeforeInstr(S.depControl);
          ASSERT(guard.opcode = S.guard);
          branch := guard.GetBranchBeforeInstr(S.depControl);
          ASSERT(branch.opcode = S.branch);
          controlFalse := cf; memoryFalse := mf;

          instr := b.AddInstr0(S.jump);
          instr.AddDep(S.depControl, ct);
          instr.AddDep(S.depMemory, mt);
          controlTrue := bailOutPath.GetBeforeInstr(S.depControl);
          memoryTrue := bailOutPath.GetBeforeInstr(S.depMemory);
          controlTrue(S.MergeInstr).AddJump(instr);
          
          (* ditch old gate, its merge, and the jumps into it *)
          merge := gate.merge(S.MergeInstr);
          gate.Delete();
          merge.Delete();
          bailOutPath.Delete();
          testPath.Delete();
        END SplitOrGate;
      
      BEGIN
        instr := bool.instr;
        IF (instr.opcode = S.gate) THEN
          gate := instr(S.GateInstr);
          merge := instr(S.GateInstr).merge(S.MergeInstr);
          IF instr.opndList.nextOpnd.arg.IsFalse() THEN
            SplitAndGate(gate, instr.opndList.arg,
                         merge.jumps[1], merge.jumps[0]);
            RETURN;
          ELSIF instr.opndList.arg.IsFalse() THEN
            SplitAndGate(gate, instr.opndList.nextOpnd.arg,
                         merge.jumps[0], merge.jumps[1]);
            RETURN;
          ELSIF instr.opndList.nextOpnd.arg.IsTrue() THEN
            SplitOrGate(gate, instr.opndList.arg,
                        merge.jumps[1], merge.jumps[0]);
            RETURN;
          ELSIF instr.opndList.arg.IsTrue() THEN
            SplitOrGate(gate, instr.opndList.nextOpnd.arg,
                        merge.jumps[0], merge.jumps[1]);
            RETURN;
          END;
        END;
        (* fall back to most general transformation *)
        SplitValue();
      END SplitPaths;
    
    PROCEDURE LoopStart(): S.LoopStartInstr;
      VAR
        loopStart: S.LoopStartInstr;
      BEGIN
        loopStart := b.AddLoopStart();
        ControlCP(loopStart); MemoryCP(loopStart);

        oldLoopExits := loopExits;
        loopExits := NEW(ArrayList.ArrayList(S.Instr), 4);
        
        RETURN loopStart;
      END LoopStart;
        
    PROCEDURE LoopEnd(loopStart: S.LoopStartInstr);
      VAR
        instr: S.Instr;
        loopEnd: S.MergeInstr;
      BEGIN
        instr := b.AddLoopBackedge(loopStart);
        instr.AddDep(S.depMemory, memoryCP);
        instr.AddDep(S.depControl, controlCP);
        loopStart.SetBackedge(instr);
        
        loopEnd := b.AddMerge(S.loopEnd, loopExits.Elements());
        loopEnd.AddDep(S.depControl, loopStart);
        loopStart.SetEnd(loopEnd);
        controlCP := loopEnd; memoryCP := loopEnd;
        loopExits := oldLoopExits;
      END LoopEnd;
        
    PROCEDURE ^ Expression(expr: IR.Expression): S.Result;
      
    PROCEDURE Call(call: IR.Call): S.Result;
      VAR
        instr: S.Instr;
        i: LONGINT;
        args: POINTER TO ARRAY OF S.Result;
      BEGIN
        (* evaluate arguments right to left, and procedure designator last *)
        NEW(args, LEN(call.arguments^));
        FOR i := LEN(call.arguments^)-1 TO 0 BY -1 DO
          args[i] := Expression(call.arguments[i]);
        END;
        
        instr := b.AddInstr2(S.call, Expression(call.design), sp);
        FOR i := 0 TO LEN(call.arguments^)-1 DO
          instr.AddOpnd(args[i]);
        END;
        
        MemoryCP(instr);
        ControlCP(instr);
        IF (call.type = Predef.GetType(Predef.void)) THEN
          RETURN NIL;
        ELSE
          RETURN instr.AddResultExpr(call.type);
        END;
      END Call;

    PROCEDURE Designator2Address(resultOfGet: S.Result): S.Result;
      BEGIN
        ASSERT(resultOfGet.instr.opcode = S.get);
        memoryCP := resultOfGet.instr.GetBeforeInstr(S.depMemory);
        RETURN resultOfGet.instr.opndList.arg;
      END Designator2Address;
    
    PROCEDURE TypeTag(design: IR.Expression; 
                      checkDerefOfNil: BOOLEAN;
                      derefSym: IR.Symbol): S.Result;
    (* `design' is the variable designator *)
      VAR
        instr: S.Instr;
        type: Sym.Type;
        value: S.Result;
      BEGIN
        (* Note: expression evaluates to a "get" on the tested variable.
           For a record, this must be corrected later.  *)
        value := Expression(design);
        
        type := design.type.Deparam();
        type := type.Bound();  (* for a type variable, continue with bound *)
        IF checkDerefOfNil & (type IS Sym.Pointer) THEN
          (*FIXME... check := AddException (pb, derefSym,
             S.checkPointer, value. subclass);
             check. AddOpnd (value, Opnd.arg);
             value := check;*)
        END;
        
        IF (type IS Sym.Pointer) THEN
          instr := b.AddInstr1(S.typeTag, value);
          RETURN instr.AddResult(S.address);
        ELSIF (design IS IR.Var) &
              design(IR.Var).decl(Sym.VarDecl).isVarParam &
              TR.IsRecord(design(IR.Var).decl(Sym.VarDecl).type) THEN
          (* type tag of a VAR parameter *)
          value := Designator2Address(value);
          RETURN b.AddGetParamTypeTag(design(IR.Var).decl(Sym.VarDecl), fp);
        ELSE  (* static type tag; need to get rid of "get" on record *)
          value := Designator2Address(value);
          RETURN b.AddAdrTypeDescr(type);
        END;
      END TypeTag;
    
    PROCEDURE Copy(copy: IR.Copy);
      VAR
        size, from, to, dynTag, staticTag: S.Result;
        eql, endTrue, endFalse: S.Instr;
        branch: S.BranchInstr;
        pathTrue, pathFalse: S.Block;
        merge: S.MergeInstr;
      BEGIN
        size := b.AddConstLength(copy.dest.type.size);
        from := Designator2Address(Expression(copy.source));
        to := Designator2Address(Expression(copy.dest));
        
        IF copy.checkDynamicType THEN
          dynTag := TypeTag(copy.dest, FALSE, NIL);
          staticTag := b.AddAdrTypeDescr(copy.dest.type);
          
          eql := b.AddInstr2(S.eql, staticTag, dynTag);
          branch := b.AddBranch(SetCC(eql.AddResultReg(S.noType, S.cc)),
                                FALSE);
          branch.AddDep(S.depControl, controlCP);
          
          (* first, the "true" path: static and dynamic type match *)
          pathTrue := b.AddMerge0(S.guard, b.AddConstBool(TRUE));
          pathTrue.AddDep(S.depControl, branch);
          endTrue := b.AddInstr0(S.jump);
          endTrue.AddDep(S.depMemory, memoryCP);
          endTrue.AddDep(S.depControl, pathTrue);
          
          (* second, the "false" path: type mismatch *)
          pathFalse := b.AddMerge0(S.guard, b.AddConstBool(FALSE));
          pathFalse.AddDep(S.depControl, branch);
          controlCP := pathFalse;
          FailedCheck("RT0__ErrorFailedTypeAssert", copy.sym.pos, NIL);
          endFalse := AddJump();
          
          (* finally, pull all the strings together again *)
          branch.SetPaths2(pathTrue, pathFalse);
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          controlCP := merge; memoryCP := merge;
        END;
        Memcpy(from, to, size);
      END Copy;

    PROCEDURE MoveBlock(move: IR.MoveBlock);
      VAR
        size, from, to: S.Result;
        instr: S.Instr;
      BEGIN
        size := Expression(move.size);
        from := Expression(move.source);
        to := Expression(move.dest);
        
        instr := b.AddInstr2(S.call, b.AddAdrRT("memcpy"), sp);
        instr.AddOpnd(to);
        instr.AddOpnd(from);
        instr.AddOpnd(size);
        
        MemoryCP(instr);
        ControlCP(instr);
      END MoveBlock;

    PROCEDURE Expression(expr: IR.Expression): S.Result;
      VAR
        instr: S.Instr;
        adr, res, arg1, arg2, baseArray: S.Result;
        designator: S.Designator;
        varDecl: Sym.VarDecl;
        var: S.Var;
        opcode: S.Opcode;
        endTrue, endFalse: S.Instr;
        merge: S.MergeInstr;
        controlTrue, memoryTrue, controlFalse, memoryFalse: S.Instr;
        dim: LONGINT;
        typeId: Sym.PredefId;
        type: Sym.Type;

      PROCEDURE GetIndexBaseArray(indexOp: IR.Expression;
                                  VAR dim: LONGINT): S.Result;
        VAR
          res: S.Result;
        BEGIN
          WITH indexOp: IR.Index DO
            res := GetIndexBaseArray(indexOp.array, dim);
            INC(dim);
            RETURN res;
          ELSE
            dim := -1;
            RETURN Expression(indexOp);
          END;
        END GetIndexBaseArray;
      
      PROCEDURE CalculateLength (pb: S.FunctionBlock; value: IR.Expression;
                                 dim: LONGINT; baseArray: S.Result): S.Result;
      (* Calculate the one-dimensional length of the variable @oparam{value} or of
         one of its elements.  With @oparam{dim=-1}, return the number of elements
         of the whole variable.  With @oparam{dim>=0}, return the length of an
         array element of dimension @oparam{dim}.  @oparam{baseArray} holds the
         (virtual, and dead) @oconst{Opcode.get} instruction on the array variable.  *)
        VAR
          type: Sym.Type;
          i: LONGINT;
          
        PROCEDURE RecursiveGetLength (type: Sym.Type; dim: LONGINT): S.Result;
          VAR
            len: S.Result;
            lenp: S.Instr;
          BEGIN
            type := type.Deparam();
            WITH type: Sym.Array DO
              IF type.isOpenArray THEN
                len := pb.AddGetLengthInstr (baseArray.instr, dim+1, type, fp);
              ELSE
                len := pb.AddConstLength(type.length);
              END;
              len := FixLength(len);
              
              IF TR.IsArray(type.elementType) THEN
                lenp := b.AddInstr2 (S.mul, len,
                                     RecursiveGetLength(type.elementType, dim+1));
                RETURN lenp.AddResult(S.length);
              ELSE
                RETURN len;
              END;
            ELSE
              RETURN pb.AddConstLength(1);
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
      
      PROCEDURE CalculateSize (pb: S.FunctionBlock; value: IR.Expression;
                               length: S.Result): S.Result;
      (* Calculate the size of the variable @oparam{value} based on the given
         length and the (non-array) base type of the index expression
         @oparam{value}.  *)
        VAR
          type: Sym.Type;
          size: S.Instr;
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
          
          size := pb.AddInstr2(S.mul,
                               FixAddress(length),
                               FixAddress(pb.AddConstLength(type.size)));
          RETURN size.AddResult(S.length);
        END CalculateSize;
      
      PROCEDURE Index(indexOp: IR.Index; baseArray: S.Result;
                      elementSize: S.Result; dim: LONGINT): S.Result;
      (* Handles a sequence of index operations on an array.  @oapram{indexOp}
         is the index operation that is to be translated.  @oparam{baseArray}
         holds the (virtual) @oconst{Opcode.get} operation on the array
         variable at the very start of the index sequence.
         @oparam{elementSize} is the size in bytes of the value produced by
         this index operation.  @oparam{dim} is the dimension of
         @oparam{baseArray} on which @oparam{indexOp} operates.  *)
        VAR
          instr, instr1: S.Instr;
          newSize, baseResult, elementAdr, scaledIndex,
              length, index: S.Result;
          adrOpnd: S.Opnd;
          elementType, arrayType: Sym.Type;
        BEGIN
          arrayType := indexOp.array.type.Deparam();
          length := b.AddGetLengthInstr(baseArray.instr, dim,
                                        arrayType(Sym.Array), fp);
          instr := b.AddInstr2(S.mul, elementSize, FixAddress(length));
          newSize := instr.AddResult(S.address);
          
          IF (indexOp.array IS IR.Index) THEN
            baseResult := Index(indexOp.array(IR.Index), baseArray,
                                newSize, dim-1);
          ELSE
            baseResult := baseArray;
            ASSERT(dim = 0);
          END;
          INC(dim);
          ASSERT(baseResult.instr.opcode = S.get);
          
          (* take the "get" instruction of the array's designator and change it
             into a "get" for the array element; the store seen by the index
             expression is the one that is passed into the old "get", and the
             new "get" sees the store after the index expression has been
             evaluated  *)
          instr := baseResult.instr;
          (*controlCP := instr.GetBeforeInstr(S.depControl);*)
          memoryCP := instr.GetBeforeInstr(S.depMemory);
          index := Expression(indexOp.index);
(*          IF indexOp. checkIndex THEN
            check := AddException (pb, indexOp. sym,
                                   Opcode.checkIndex, index. subclass);
            check. AddOpnd (index, Opnd.arg);
            check. AddOpnd (length, Opnd. arg);
            index := check;
          END;*)
          
          instr.DeleteDep(S.depMemory);
          MemoryCP(instr);
          
          elementType := indexOp.type;
          instr1 := b.AddInstr2(S.mul, FixAddress(index), elementSize);
          scaledIndex := instr1.AddResult(S.address);
          
          adrOpnd := instr.opndList;
          instr1 := b.AddInstr2(S.add, adrOpnd.arg, scaledIndex);
          elementAdr := instr1.AddResult(S.address);
          adrOpnd.ReplaceArg(elementAdr);
          instr.resultList.SetType(S.MapType(indexOp.type));
          
          instr.ExtendDesignator(NEW(S.Index, b, index));
          
          RETURN instr.resultList;
        END Index;

      PROCEDURE SelectField(selectOp: IR.SelectField): S.Result;
        VAR
          instr, fieldAdr: S.Instr;
          baseResult: S.Result;
          adrOpnd: S.Opnd;
        BEGIN
          (* take the "get" instruction of the record's designator and
             change it into a "get" for the record field; memoryCP
             is not changed and continues to refer to the old "get" *)
          baseResult := Expression(selectOp.record);
          ASSERT (baseResult.instr.opcode = S.get);
          instr := baseResult.instr;
          
          adrOpnd := instr.opndList;
          fieldAdr := b.AddInstr2(S.add, adrOpnd.arg,
                                  b.AddConstLength(selectOp.field.offset));
          adrOpnd.ReplaceArg(fieldAdr.AddResult(S.address));
          instr.resultList.SetType(S.MapType(selectOp.type));
          
          instr.ExtendDesignator(NEW(S.Field, selectOp.field));
          
          RETURN instr.resultList;
        END SelectField;
      
      PROCEDURE TypeGuard(guard: IR.TypeGuard): S.Result;
        BEGIN  (* FIXME... *)
          RETURN Expression(guard.test.origExpr);
        END TypeGuard;

      PROCEDURE TypeConv(conv: IR.TypeConv): S.Result;
        VAR
          instr: S.Instr;
          typeSource, typeDest: S.Type;
(*          const: S.Result;
          len: LONGINT;
          fct: STRING;*)
        BEGIN
          IF TR.IsSTRING(conv.type) THEN
            (* converting a character or string constant to STRING *)
            (*const := Expression(conv.expr);
            
            instr := pb.AddInstr(S.preloadedVar, S.address);
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
            instr.AddOpnd(pb.GetConst(Boxed.NewString(fct), S.scAddress,
                                      Predef.GetType(Predef.stringChar)),
                          Opnd.arg);
            instr.AddOpnd(const, Opnd.arg);
            IF TR.IsStringConst(conv.expr.type) THEN
              len := conv.expr(IR.Const).value(Boxed.String).value.length;
              instr.AddOpnd(pb.GetConstInt(len+1), Opnd.arg); (* array len *)
              
              instr.AddOpnd(pb.GetConstInt(0), Opnd.arg); (* start *)
              instr.AddOpnd(pb.GetConstInt(len), Opnd.arg); (* end *)
            END;
            RETURN instr;*)
              RETURN NIL;
          ELSE
            typeDest := S.MapType(conv.type);
            typeSource := S.MapType(conv.expr.type);
            IF (typeDest # typeSource) THEN
              instr := b.AddInstr1(S.typeConv, Expression(conv.expr));
              RETURN instr.AddResult(typeDest);
            ELSE
              RETURN Expression(conv.expr);
            END;
          END;
        END TypeConv;

      PROCEDURE Negate(arg: S.Result; type: Sym.Type): S.Result;
        BEGIN
          IF TR.IsRealType(type) THEN  (* convert to `0-x' *)
            instr := b.AddInstr2(S.sub, b.AddConstZero(type), arg);
          ELSE
            instr := b.AddInstr1(S.neg, arg);
          END;
          RETURN instr.AddResult(arg.type);
        END Negate;
      
      PROCEDURE LeftRight(arg: S.Result; argType: Sym.Type;
                          x: S.Result; xType: Sym.Type;
                          ifNeg, ifNotNeg: S.Opcode): S.Result;
        VAR
          valueTrue, valueFalse, xNegate: S.Result;
          branch: S.BranchInstr;
          merge: S.MergeInstr;
          gate: S.GateInstr;
          cmp, endTrue, endFalse: S.Instr;
          pathTrue, pathFalse: S.Block;

        PROCEDURE Op(opc: S.Opcode; y: S.Result): S.Result;
          VAR
            instr: S.Instr;
          BEGIN
            IF (opc = -1) THEN
              RETURN y;
            ELSE
              instr := b.AddInstr2(opc, arg, y);
              RETURN instr.AddResultExpr(argType);
            END;
          END Op;
        
        BEGIN
          (* compare the x argument to zero *)
          cmp := b.AddInstr2(S.lss, x, b.AddConstZero(xType));
          branch := b.AddBranch(SetCC(cmp.AddResultReg(S.noType, S.cc)),
                                FALSE);
          branch.AddDep(S.depControl, controlCP);

          (* first, the "true" path: x<0 *)
          pathTrue := b.AddMerge0(S.guard, b.AddConstBool(TRUE));
          pathTrue.AddDep(S.depControl, branch);
          endTrue := b.AddInstr0(S.jump);
          endTrue.AddDep(S.depMemory, memoryCP);
          endTrue.AddDep(S.depControl, pathTrue);
          xNegate := Negate(x, xType);
          valueTrue := Op(ifNeg, xNegate);
          
          (* second, the "false" path: x>=0 *)
          pathFalse := b.AddMerge0(S.guard, b.AddConstBool(FALSE));
          pathFalse.AddDep(S.depControl, branch);
          endFalse := b.AddInstr0(S.jump);
          endFalse.AddDep(S.depMemory, memoryCP);
          endFalse.AddDep(S.depControl, pathFalse);
          valueFalse := Op(ifNotNeg, x);
          
          (* finally, pull all the strings together again *)
          branch.SetPaths2(pathTrue, pathFalse);
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          gate := merge.AddGate(S.gate);
          gate.AddOpnd(valueTrue);
          gate.AddOpnd(valueFalse);
          controlCP := merge; memoryCP := merge;

          RETURN gate.AddResultExpr(argType);
        END LeftRight;
                      
      PROCEDURE NewObject (new: IR.NewObject): S.Result;
        VAR
          instr, get1, get2: S.Instr;
          ptrTypeDescr, objTypeDescr: S.Result;
        BEGIN
          (* compute typeDescr.baseTypes^[0] *)
          ptrTypeDescr := b.AddAdrTypeDescr(new.type);
          get1 := b.AddInstr1(S.get, ptrTypeDescr);
          get2 := b.AddInstr1(S.get, get1.AddResult(S.address));
          objTypeDescr := get2.AddResult(S.address);
          
          instr := b.AddInstr3(S.call, b.AddAdrRT("RT0__NewObject"), sp,
                               objTypeDescr);
          (*IF (new. length # NIL) THEN
            FOR i := 0 TO LEN (new. length^)-1 DO
              instr. AddOpnd (Expression (new. length[i]), Opnd.arg);
            END;
          END;*)
          
          MemoryCP(instr);
          ControlCP(instr);
          RETURN instr.AddResult(S.address);
        END NewObject;
      
      BEGIN
        WITH expr: IR.Const DO
          typeId := expr.type(Sym.PredefType).id;
          CASE typeId OF
          | Predef.boolean:
            RETURN b.AddConstBool(expr.value(Boxed.Boolean).value);
          | Predef.stringChar..Predef.stringUCS4Char:
            RETURN b.AddConst(NEW(S.Const, expr.value, typeId), expr.type);
          ELSE
            RETURN b.AddConst(NEW(S.Const, expr.value, -1), expr.type);
          END;
          
        | expr: IR.ProcedureRef DO
          RETURN b.AddAdr(NEW(S.Proc, expr.decl(Sym.ProcDecl)));
          
        | expr: IR.Var DO
          varDecl := expr.decl(Sym.VarDecl);
          var := NEW(S.Var, varDecl);
          IF (varDecl.parent IS Sym.Module) THEN (* global variable *)
            adr := b.AddAdr(var);
          ELSE                       (* local variable or parameter *)
            IF ~varDecl.isParameter THEN
              b.AllocateLocalVar(varDecl);
            END;
            instr := b.AddInstr2(S.add, fp, b.AddFramePointerOffset(varDecl));
            adr := instr.AddResult(S.address);
            
            IF varDecl.isPassPerReference &
               ((*FIXME... need copy fir array*)(varDecl.type IS Sym.Array) OR
                ~varDecl.hasLocalCopy) THEN  (* indirect *)
              instr := b.AddInstr1(S.get, adr);
              (*MemoryCP(instr);*)
              adr := instr.AddResult(S.address);
            END;
          END;
          
          NEW(designator, 1);
          designator[0] := var;
          instr := b.AddInstr1(S.get, adr);
          instr.SetDesignator(designator);
          MemoryCP(instr);
          RETURN instr.AddResultExpr(expr.type);

        | expr: IR.Index DO
          baseArray := GetIndexBaseArray(expr, dim);
          RETURN Index(expr, baseArray,
                       CalculateSize(b, expr, 
                                     CalculateLength(b, expr, -1, baseArray)),
                       dim);
          
        | expr: IR.SelectField DO
          RETURN SelectField(expr);
          
        | expr: IR.Deref DO
          (* take the value of the pointer and use it to start a new "get"
             instruction *)
          adr := Expression(expr.pointer);
          IF expr.checkPointer THEN
            (*FIXME... check := AddException (pb, deref. sym,
                                   Opcode.checkPointer, address. subclass);
            check. AddOpnd (address, Opnd.arg);
            address := check;*)
          END;
          
          NEW(designator, 1);
          designator[0] := NEW(S.HeapObj, b, expr.type, adr);
          instr := b.AddInstr1(S.get, adr);
          instr.SetDesignator(designator);
          MemoryCP(instr);
          (*ControlCP(instr);
             FIXME... this is not handled by Designator2Address *)
          RETURN instr.AddResultExpr(expr.type);
          
        | expr: IR.Adr DO
          res := Expression(expr.design);
          IF (res.instr.opcode = S.get) THEN
            res := Designator2Address(res);
            RETURN b.FixType(res, S.address);
          ELSE
            (* must be a string constant; currently, this is its own address
               FIXME... we should probably introduce an address opcode here *)
            RETURN res;
          END;
          
        | expr: IR.Len DO
          IF (expr.variant = IR.lenStringConst) THEN
            RETURN b.AddConstLength(expr.arrayVariable(IR.Const).
                                    value(Boxed.String).value.length+1);
          ELSE
            baseArray := Expression(expr.arrayVariable);
            memoryCP := baseArray.instr.GetBeforeInstr(S.depMemory);
            type := expr.arrayVariable.type.Deparam();
            type := type(Sym.Array).GetNthElementType(expr.dim);
            RETURN b.AddGetLengthInstr(baseArray.instr, expr.dim,
                                       type(Sym.Array), fp);
          END;
              
        | expr: IR.TypeTag DO
          RETURN TypeTag(expr.design, FALSE, expr.sym);
              
        | expr: IR.TypeTest DO
          instr := b.AddInstr2(S.call, b.AddAdrRT("RT0__TypeTest"), sp);
          instr.AddOpnd(TypeTag (expr.expr, expr.checkPointer, expr.sym));
          instr.AddOpnd(b.AddAdrTypeDescr(expr.referenceType));
          MemoryCP(instr);
          ControlCP(instr);
          RETURN instr.AddResult(S.boolean);
          
        | expr: IR.TypeGuard DO
          RETURN TypeGuard(expr);
              
        | expr: IR.TypeConv DO
          RETURN TypeConv(expr);
        | expr: IR.TypeCast DO
          instr := b.AddInstr1(S.typeCast, Expression(expr.expr));
          RETURN instr.AddResultExpr(expr.type);
          
        | expr: IR.BinaryArith DO
          CASE expr.variant OF
          | IR.arithAdd : opcode := S.add;
          | IR.arithSub : opcode := S.sub;
          | IR.arithMul : opcode := S.mul;
          (*                                          | IR.arithMod : opcode := S.modulo;
                                                                                        | IR.arithDivI: opcode := S.divide;
                                                                                                                            | IR.arithDivR: opcode := S.divide;*)
          END;
          arg1 := Expression(expr.left);
          arg2 := Expression(expr.right);
          instr := b.AddInstr2(opcode, arg1, arg2);
          RETURN instr.AddResultExpr(expr.type);
          
        | expr: IR.ChangeElement DO
          CASE expr.variant OF
          | IR.inclElement: opcode := S.bitTestAndSet;
          | IR.exclElement: opcode := S.bitTestAndClear;
          END;
          arg1 := Expression(expr.set);
          arg2 := Expression(expr.element);
          instr := b.AddInstr2(opcode, arg1, arg2);
          RETURN instr.AddResultExpr(expr.type);
          
        | expr: IR.Negate DO
          RETURN Negate(Expression(expr.operand), expr.type);

        | expr: IR.Compare DO
          CASE expr.variant OF
          | IR.equal: opcode := S.eql;
          | IR.notEqual: opcode := S.neq;
          | IR.less: opcode := S.lss;
          | IR.lessEqual: opcode := S.leq;
          | IR.greater: opcode := S.gtr;
          | IR.greaterEqual: opcode := S.geq;
          END;
          arg1 := Expression(expr.left);
          arg2 := Expression(expr.right);
          instr := b.AddInstr2(opcode, arg1, arg2);
          RETURN instr.AddResultReg(S.noType, S.cc);
          
        | expr: IR.BooleanOp DO          (* shortcut "and" and "or" *)
          res := Expression(expr.left);
          SplitPaths(res, controlCP, memoryCP,
                     controlTrue, memoryTrue,
                     controlFalse, memoryFalse);
          (* first, the "true" path *)
          memoryCP := memoryTrue; controlCP := controlTrue;
          IF (expr.variant = IR.and) THEN (* TRUE & right is right *)
            arg1 := SetBool(Expression(expr.right));
          ELSE                           (* TRUE OR right is TRUE *)
            arg1 := b.AddConstBool(TRUE);
          END;
          endTrue := AddJump();
          (* second, the "false" path;  *)
          memoryCP := memoryFalse; controlCP := controlFalse;
          IF (expr.variant = IR.and) THEN (* FALSE & right is FALSE *)
            arg2 := b.AddConstBool(FALSE);
          ELSE                           (* FALSE OR right is right *)
            arg2 := SetBool(Expression(expr.right));
          END;
          endFalse := AddJump();
          (* finally, pull all the strings together again *)
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          controlCP := merge; memoryCP := merge;
          
          (* add the gate that represents the result of the boolean expr *)
          instr := merge.AddGate(S.gate);
          instr.AddOpnd(arg1);
          instr.AddOpnd(arg2);
          RETURN instr.AddResultExpr(expr.type);

        | expr: IR.Abs DO
          RETURN LeftRight(NIL, expr.type,
                           Expression(expr.operand), expr.type, -1, -1);
        | expr: IR.Ash DO
          arg1 := Expression(expr.value);
          arg2 := Expression(expr.exp);
          RETURN LeftRight(b.FixType(arg1, S.signed32), expr.type,
                           arg2, expr.exp.type, S.asr, S.asl);
        | expr: IR.Shift DO
          arg1 := Expression(expr.value);
          arg2 := Expression(expr.by);
          IF expr.rotate THEN
            RETURN LeftRight(arg1, expr.type,
                             arg2, expr.by.type, S.rr, S.rl);
          ELSE
            RETURN LeftRight(arg1, expr.type,
                             arg2, expr.by.type, S.lsr, S.lsl);
          END;
          
        | expr: IR.Call DO
          RETURN Call(expr);
        | expr: IR.NewObject DO
          RETURN NewObject(expr);
        END;
      END Expression;

    PROCEDURE Assign(getInstr: S.Result; newValue: S.Result);
      BEGIN
        ASSERT(memoryCP = getInstr.instr);
        getInstr.instr.SetOpcode(S.set);
        getInstr.instr.AddOpnd(newValue);
        getInstr.DeleteResult();
      END Assign;
        
    PROCEDURE ForStatm(statm: IR.ForStatm);
      VAR
        endValue, stepValue, v, res: S.Result;
        instr, endTrue, endFalse: S.Instr;
        loopStart: S.LoopStartInstr;
        controlTrue, memoryTrue, controlFalse, memoryFalse: S.Instr;

      PROCEDURE Guard(bound: S.Result): S.Result;
        VAR
          instr: S.Instr;
          cmpClass: S.Opcode;
        BEGIN
          IF statm.PositiveStep() THEN
            cmpClass := S.leq;
          ELSE
            cmpClass := S.geq;
          END;
          instr := b.AddInstr2(cmpClass, Expression (statm. var), bound);
          RETURN instr.AddResultReg(S.noType, S.cc);
        END Guard;
      
      BEGIN
        (* "FOR v := beg TO end BY step DO s END"  is translated to
           temp := end; v := beg;
           LOOP IF v<=temp THEN ELSE EXIT END; s; v:=v+step END (if step>0)
           LOOP IF v>=temp THEN ELSE EXIT END; s; v:=v+step END (if step<0)  *)
        (* "WHILE e DO s END"  is translated to
           "LOOP IF e THEN EXIT END; s END" *)
        endValue := Expression(statm.end);
        stepValue := Expression(statm.step);
        v := Expression(statm.var);
        Assign(v, Expression(statm.start));
        
        loopStart := LoopStart();
        
        res := Guard(endValue);
        SplitPaths(res, controlCP, memoryCP,
                   controlTrue, memoryTrue,
                   controlFalse, memoryFalse);
        (* first, the "true" path *)
        memoryCP := memoryTrue; controlCP := controlTrue;
        endTrue := AddJump();
        (* second, the "false" path;  *)
        memoryCP := memoryFalse; controlCP := controlFalse;
        instr := b.AddInstr0(S.loopExit);
        ControlCP(instr); MemoryCP(instr);
        loopExits.Append(instr);
        endFalse := AddJump();
        (* finally, pull all the strings together again *)
        merge := b.AddMerge2(S.merge, endTrue, endFalse);
        controlCP := merge; memoryCP := merge;
        
        StatmSeq(statm.body);
        v := Expression(statm.var);
        instr := b.AddInstr2(S.add, v, stepValue);
        Assign(Expression(statm.var), instr.AddResult(v.type));
        
        LoopEnd(loopStart);
      END ForStatm;
        
    PROCEDURE CaseStatm(statm: IR.CaseStatm);
      VAR
        select: S.Result;
        branch: S.BranchInstr;
        guard: S.Block;
        branchMemory, branchControl, jump: S.Instr;
        i: LONGINT;
        paths: ArrayList.ArrayList(S.Block);
        jumps: ArrayList.ArrayList(S.Instr);
        merge: S.MergeInstr;

      PROCEDURE Labels(guard: S.Instr; labels: IR.CaseLabels);
        VAR
          i: LONGINT;
          value: S.Result;
          l: IR.Expression;
        BEGIN
          FOR i := 0 TO LEN(labels^)-1 DO
            l := labels[i];
            WITH l: IR.SetRange DO
              guard.AddOpnd (Expression(l.from));
              guard.AddOpnd (Expression(l.to));
            ELSE
              value := Expression(l);
              guard.AddOpnd(value);
              guard.AddOpnd(value);
            END;
          END;
        END Labels;
      
      BEGIN
        select := Expression(statm.select);
        jump := b.AddInstr2(S.call, b.AddAdrRT("RT0__ScanCaseRanges"), sp);
        MemoryCP(jump);
        
        branch := b.AddBranch(jump.AddResult(S.address), TRUE);
        branch.AddDep(S.depControl, controlCP);
        branchControl := branch; branchMemory := memoryCP;

        jump.AddOpnd(b.AddConstType(NEW(S.Const, branch, Predef.address),
                                    S.address));
        jump.AddOpnd(select);
                     
        jumps := NEW(ArrayList.ArrayList(S.Instr), 8);
        paths := NEW(ArrayList.ArrayList(S.Block), 8);
        FOR i := 0 TO LEN(statm.caseList^)-1 DO
          IF (LEN(statm.caseList[i].labels^) # 0) THEN
            (* only default branch may have an empty argument list *)
            guard := b.AddMerge0(S.guard, NIL);
            guard.AddDep(S.depControl, branch);
            Labels(guard, statm.caseList[i].labels);
            paths.Append(guard);
            
            controlCP := guard; memoryCP := branchMemory;
            StatmSeq(statm.caseList[i].statmSeq);
            jumps.Append(AddJump());
          END;
        END;

        IF (statm.default # NIL) THEN
          guard := b.AddMerge0(S.guard, NIL);
          guard.AddDep(S.depControl, branch);
          paths.Append(guard);
                 
          controlCP := guard; memoryCP := branchMemory;
          StatmSeq(statm.default);
          jumps.Append(AddJump());
        ELSIF statm.checkMatch THEN
          guard := b.AddMerge0(S.guard, NIL);
          guard.AddDep(S.depControl, branch);
          paths.Append(guard);
                 
          controlCP := guard; memoryCP := branchMemory;
          FailedCheck("RT0__ErrorFailedCase", statm.sym.pos, select);
          jumps.Append(AddJump());
        END;
        
        (* finally, pull all the strings together again *)
        merge := b.AddMerge(S.merge, jumps.Elements());
        branch.SetPaths(paths.Elements());
        controlCP := merge; memoryCP := merge;
      END CaseStatm;
    
    BEGIN
      FOR statm IN statmSeq^ DO
        WITH statm: IR.Assignment DO
          (* note: oo2c-2 evaluates first var, then value *)
          res := Expression(statm.value);
          var := Expression(statm.variable);
          Assign(var, res);
        | statm: IR.Copy DO
          Copy(statm);
        | statm: IR.MoveBlock DO
          MoveBlock(statm);
          
        | statm: IR.IfStatm DO
          res := Expression(statm.guard);
          SplitPaths(res, controlCP, memoryCP,
                     controlTrue, memoryTrue,
                     controlFalse, memoryFalse);
          (* first, the "true" path *)
          memoryCP := memoryTrue; controlCP := controlTrue;
          StatmSeq(statm.pathTrue); endTrue := AddJump();
          (* second, the "false" path;  *)
          memoryCP := memoryFalse; controlCP := controlFalse;
          IF (statm.pathFalse # NIL) THEN
            StatmSeq(statm.pathFalse);
          END;
          endFalse := AddJump();
          (* finally, pull all the strings together again *)
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          controlCP := merge; memoryCP := merge;
          
        | statm: IR.WithStatm DO
          res := Expression(statm.guard);
          SplitPaths(res, controlCP, memoryCP,
                     controlTrue, memoryTrue,
                     controlFalse, memoryFalse);
          (* first, the "true" path *)
          memoryCP := memoryTrue; controlCP := controlTrue;
          StatmSeq(statm.pathTrue); endTrue := AddJump();
          (* second, the "false" path;  *)
          memoryCP := memoryFalse; controlCP := controlFalse;
          IF (statm.pathFalse # NIL) THEN
            StatmSeq(statm.pathFalse);
          ELSIF statm.checkMatch THEN
            irExpr := statm.guard(IR.TypeTest).expr;
            res := TypeTag(irExpr, TRUE, statm.sym);
            FailedCheck("RT0__ErrorFailedWith", statm.sym.pos, res);
          END;
          endFalse := AddJump();
          (* finally, pull all the strings together again *)
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          controlCP := merge; memoryCP := merge;

        | statm: IR.CaseStatm DO
          CaseStatm(statm);
          
        | statm: IR.Return DO
          type := S.MapType(statm.result.type);
          CASE type OF
          | S.real32, S.real64:
            (* keep original type *)
          | S.unsigned8 .. S.unsigned64:
            type := S.unsigned32;
          ELSE
            type := S.signed32;
          END;
          res := b.FixType(Expression(statm.result), type);
          instr := b.AddInstr1(S.return, res);
          ControlCP(instr); MemoryCP(instr);
          res := instr.AddResult(type);
          res.adrMode := S.register;
          IF (type >= S.real32) THEN
            res.register := S.resultRegisterFp;
          ELSE
            res.register := S.resultRegister;
          END;
          returns.Append(instr);

        | statm: IR.LoopStatm DO
          loopStart := LoopStart();
          StatmSeq(statm.body);
          LoopEnd(loopStart);
          
        | statm: IR.RepeatStatm DO
          (* "REPEAT s UNTIL e"  is translated to
             "LOOP s; IF e THEN EXIT END END" *)
          loopStart := LoopStart();
          StatmSeq(statm.body);
          
          res := Expression(statm.exitCondition);
          SplitPaths(res, controlCP, memoryCP,
                     controlTrue, memoryTrue,
                     controlFalse, memoryFalse);
          (* first, the "true" path *)
          memoryCP := memoryTrue; controlCP := controlTrue;
          instr := b.AddInstr0(S.loopExit);
          ControlCP(instr); MemoryCP(instr);
          loopExits.Append(instr);
          endTrue := AddJump();
          (* second, the "false" path;  *)
          memoryCP := memoryFalse; controlCP := controlFalse;
          endFalse := AddJump();
          (* finally, pull all the strings together again *)
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          controlCP := merge; memoryCP := merge;
          
          LoopEnd(loopStart);
          
        | statm: IR.WhileStatm DO  (* FIXME... change to if & repeat *)
          (* "WHILE e DO s END"  is translated to
             "LOOP IF e THEN EXIT END; s END" *)
          loopStart := LoopStart();
          
          res := Expression(statm.guard);
          SplitPaths(res, controlCP, memoryCP,
                     controlTrue, memoryTrue,
                     controlFalse, memoryFalse);
          (* first, the "true" path *)
          memoryCP := memoryTrue; controlCP := controlTrue;
          endTrue := AddJump();
          (* second, the "false" path;  *)
          memoryCP := memoryFalse; controlCP := controlFalse;
          instr := b.AddInstr0(S.loopExit);
          ControlCP(instr); MemoryCP(instr);
          loopExits.Append(instr);
          endFalse := AddJump();
          (* finally, pull all the strings together again *)
          merge := b.AddMerge2(S.merge, endTrue, endFalse);
          controlCP := merge; memoryCP := merge;
          
          StatmSeq(statm.body);
          LoopEnd(loopStart);

        | statm: IR.ForStatm DO
          ForStatm(statm);
          
        | statm: IR.Exit DO
          instr := b.AddInstr0(S.loopExit);
          ControlCP(instr); MemoryCP(instr);
          loopExits.Append(instr);
          
        | statm: IR.Call DO
          res := Call(statm);

        | statm: IR.Assert DO
          IF (statm.predicate = NIL) THEN
            instr := b.AddInstr2(S.call, b.AddAdrRT("RT0__Halt"), sp);
            instr.AddOpnd(b.AddConstLength(statm.code));
            MemoryCP(instr);
            ControlCP(instr);
          ELSIF ~statm.disabled THEN
            res := Expression(statm.predicate);
            SplitPaths(res, controlCP, memoryCP,
                       controlTrue, memoryTrue,
                       controlFalse, memoryFalse);
            (* first, the "true" path *)
            memoryCP := memoryTrue; controlCP := controlTrue;
            endTrue := AddJump();
            (* second, the "false" path;  *)
            memoryCP := memoryFalse; controlCP := controlFalse;
            FailedCheck("RT0__ErrorAssertionFailed", statm.sym.pos,
                        b.AddConstLength(statm.code));
            endFalse := AddJump();
            (* finally, pull all the strings together again *)
            merge := b.AddMerge2(S.merge, endTrue, endFalse);
            controlCP := merge; memoryCP := merge;
          END;
          
        | statm: IR.CopyParameter DO
          (* handled in FctProlog *)
        END;
      END;
    END StatmSeq;
  
  PROCEDURE FctProlog(b: S.FunctionBlock; statmSeq: IR.StatementSeq);
    VAR
      enter, pushFp, setFp, localVars: S.Instr;
      i: LONGINT;
      
    PROCEDURE CopyParameter(cp: IR.CopyParameter);
      VAR
        var: Sym.VarDecl;
        type: Sym.Type;
        paramAdr, getAdr, varAdr: S.Instr;
        from, to, size: S.Result;
      BEGIN
        var := cp.param.decl(Sym.VarDecl);
        type := cp.param.type;
        WITH type: Sym.Record DO
          paramAdr := b.AddInstr2(S.add, fp,
                                  b.AddConstLength(b.Offset(var, -1)));
          getAdr := b.AddInstr1(S.get, paramAdr.AddResult(S.address));
          from := getAdr.AddResult(S.address);

          b.AllocateLocalVar(var);  (* overwrite old offset *)
          varAdr := b.AddInstr2(S.add, fp, b.AddFramePointerOffset(var));
          to := varAdr.AddResult(S.address);
          
          size := b.AddConstLength(type.size);
          Memcpy(from, to, size);
        | type: Sym.Array DO
          (* FIXME *)
        END;
      END CopyParameter;
    
    BEGIN
      enter := b.AddInstr0(S.enter);
      sp := enter.AddResultReg(S.address, S.sp);
      fp := enter.AddResultReg(S.address, S.fp);
      controlCP := enter;
      memoryCP := enter;
      b.SetEnter(enter);
      
      pushFp := b.AddInstr2(S.push, sp, fp);
      sp := pushFp.AddResultReg(S.address, S.sp);
      ASSERT(sp.register = S.sp);
      
      setFp := b.AddInstr1(S.copy, sp);
      fp := setFp.AddResultReg(S.address, S.fp);
      MemoryCP(setFp); (* transfer must happen before allocateStack *)
      
      localVars := b.AddInstr2(S.allocateStack,
                               sp, b.AddFramePointerOffset(NIL));
      ControlCP(localVars);  (* FIXME... temporary workaround for misscheduling of branch/merge combination; this call should be removed later *)
      MemoryCP(localVars);
      sp := localVars.AddResultReg(S.address, S.sp);
      ASSERT(sp.register = S.sp);

      (* deal with CopyParameter instructions *)
      i := 0;
      WHILE (i # LEN(statmSeq^)) & (statmSeq[i] IS IR.CopyParameter) DO
        CopyParameter(statmSeq[i](IR.CopyParameter));
        INC(i);
      END;
    END FctProlog;
  
  PROCEDURE FctEpilog(b: S.FunctionBlock);
    VAR
      leave: S.Instr;
      exit: S.ExitInstr;
    BEGIN
      IF b.checkFunctionResult THEN
        FailedCheck("RT0__ErrorFailedFunction", b.procDecl.name.pos, NIL);
      END;
      
      leave := b.AddInstr2(S.leave, sp, fp);
      sp := leave.AddResultReg(S.address, S.sp);
      fp := leave.AddResultReg(S.address, S.fp);

      exit := b.AddExit(sp, fp, returns.Elements());
      ControlCP(exit);
      MemoryCP(exit);
      b.SetExit(exit);
    END FctEpilog;

  PROCEDURE Procedure(p: IR.Procedure);
    BEGIN
      b := NEW(S.FunctionBlock, p.decl, p.checkFunctionResult);
      FctProlog(b, p.statmSeq);
      StatmSeq(p.statmSeq);
      FctEpilog(b);

      Destore.Transform(b);
      Algebraic.Transform(b, FALSE);
      ConstProp.Transform(b);
      b.DeadCodeElimination();
      
      M.ApplyMachineModel(b);
      
      B.ArrangeInstructions(b);
      R.AssignRegisters(b);
      D.ValidateAllocation(b);

      D.WriteFunction(b);
      w.WriteFunction(b);
    END Procedure;

  BEGIN
    returns := NEW(ArrayList.ArrayList(S.Instr), 4);
    loopExits := NIL;
    
    w := NEW(W.Writer, symTab, ch);
    FOR p IN moduleIR.procList^ DO
      Procedure(p);
    END;
    Procedure(moduleIR.moduleBody);
    
    w.EndFile();
  END Translate;
  
END OOC:X86:Translate.
