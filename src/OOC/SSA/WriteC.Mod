(* 	$Id: WriteC.Mod,v 1.173 2004/01/14 23:50:39 mva Exp $	 *)
MODULE OOC:SSA:WriteC [OOC_EXTENSIONS];
(*  Translates a set of scheduled SSA instructions to plain C.
    Copyright (C) 2001-2004  Michael van Acken

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
  IntStr, Err, Out, Strings, StringSearch, IO, IO:StdChannels,
  Object, Object:Boxed, ADT:Dictionary, IntDict := ADT:Dictionary:IntValue,
  Sym := OOC:SymbolTable,
  TR := OOC:SymbolTable:TypeRules, OOC:SymbolTable:Predef,
  OOC:SymbolTable:Builder,
  OOC:IR, OOC:IR:VisitAll, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:Schedule, OOC:SSA:XML,
  OOC:SSA:DeadCodeElimination, OOC:SSA:Destore, OOC:SSA:CSE, OOC:SSA:Algebraic,
  OOC:SSA:ConstProp, OOC:SSA:LoopRewrite, OOC:SSA:PRE, OOC:SSA:Stats,
  OOC:SSA:Allocator, OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:DeclWriter, 
  OOC:Make:TranslateToC, OOC:SSA:Blocker;


CONST
  enableLoopRewriting = TRUE;
  
TYPE
  RegisterSwap = RECORD
    source, dest: STRING;
    readCount: LONGINT;                (* number of reads of `dest' *)
    ctype: DeclWriter.BasicTypeId;     (* type of transfered value *)
  END;
  SwapArray = POINTER TO ARRAY OF RegisterSwap;
  
TYPE
  Translator* = POINTER TO TranslatorDesc;
  TranslatorDesc = RECORD
    (TranslateToC.TranslatorDesc)
    inspectProc: StringSearch.Matcher;
    inspectStage: StringSearch.Matcher;
    writeStats: BOOLEAN;
    
    nonLocalAccess: Dictionary.Dictionary; (* of Sym.VarDecl *)
    (* The keys of this dictionary are variables that are accessed from
       a nested procedure within the procedure in which they are declared.  *)
    
    preloadedVars: IntDict.Dictionary;
  END;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc = RECORD
    (DeclWriter.WriterDesc)
    translator: Translator;
    registerMap, jmpbufMap: Dictionary.Dictionary;
    procBlock: SSA.ProcBlock;

    swapArray: SwapArray;                (* used by WriteCollect *)
    lengthSwapArray: LONGINT;            (* used by WriteCollect *)
    swapHelperVars: LONGINT;
  END;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (VisitAll.VisitorDesc)
    currentProcedure: Sym.ProcDecl;
    nonLocalAccess: Dictionary.Dictionary; (* of Sym.VarDecl *)
  END;
  
CONST
  enableDebugOutput = FALSE;
  prefixPreloadVar = "_c";

PROCEDURE NewVisitor (): Visitor;
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    VisitAll.InitVisitor (v);
    v. currentProcedure := NIL;
    v. nonLocalAccess := Dictionary.New();
    RETURN v
  END NewVisitor;

PROCEDURE (v: Visitor) VisitProcedure* (procedure: IR.Procedure);
  BEGIN
    v. currentProcedure := procedure. decl;
    v. VisitProcedure^ (procedure);
    v. currentProcedure := NIL;
  END VisitProcedure;

PROCEDURE (v: Visitor) VisitVar* (var: IR.Var);
  VAR
    proc: Sym.ProcDecl;
  BEGIN
    proc := var. decl. Procedure();
    IF (proc # v. currentProcedure) THEN
      v. nonLocalAccess. Set (var. decl, proc);
    END;
  END VisitVar;




PROCEDURE SubclassToBasicType (res: SSA.Result): DeclWriter.BasicTypeId;
  BEGIN
    RETURN Allocator.SubclassToBasicType(res.subclass);
  END SubclassToBasicType;


PROCEDURE NewWriter (translator: Translator;
                     cWriter: DeclWriter.Writer;
                     procBlock: SSA.ProcBlock;
                     registerMap, jmpbufMap: Dictionary.Dictionary): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    cWriter. CopyTo (w);
    w. procBlock := procBlock;
    w. registerMap := registerMap;
    w. jmpbufMap := jmpbufMap;
    NEW (w. swapArray, 8);
    w. lengthSwapArray := 0;
    w. swapHelperVars := 0;
    w. translator := translator;
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) ClearSwapData;
  BEGIN
    w. lengthSwapArray := 0;
    w. swapHelperVars := 0;
  END ClearSwapData;

PROCEDURE (w: Writer) AddSwapData (source, dest: STRING;
                                   ctype: DeclWriter.BasicTypeId);
  VAR
    new: SwapArray;
    i: LONGINT;
  BEGIN
    IF ~source.Equals(dest) THEN (* suppress things like `i0=i0;' *)
      IF (w. lengthSwapArray = LEN (w. swapArray^)) THEN
        NEW (new, LEN (w. swapArray^)*2);
        FOR i := 0 TO LEN (w. swapArray^)-1 DO
          new[i] := w. swapArray[i]
        END;
        w. swapArray := new
      END;
      w. swapArray[w. lengthSwapArray]. source := source;
      w. swapArray[w. lengthSwapArray]. dest := dest;
      w. swapArray[w. lengthSwapArray]. ctype := ctype;
      w. swapArray[w. lengthSwapArray]. readCount := 0;
      INC (w. lengthSwapArray)
    END;
  END AddSwapData;

PROCEDURE (w: Writer) CountReadsSwapData;
  VAR
    i, j, c: LONGINT;
  BEGIN
    FOR i := 0 TO w. lengthSwapArray-1 DO
      c := 0;
      FOR j := 0 TO w. lengthSwapArray-1 DO
        IF w. swapArray[j]. source. Equals(w. swapArray[i]. dest) THEN
          INC (c)
        END;
      END;
      w. swapArray[i]. readCount := c
    END;
  END CountReadsSwapData;

PROCEDURE (w: Writer) RemoveSwapData (i: LONGINT);
  VAR
    j: LONGINT;
  BEGIN
    ASSERT (w. swapArray[i]. readCount = 0);
    FOR j := 0 TO w. lengthSwapArray-1 DO
      IF w. swapArray[j]. dest. Equals(w. swapArray[i]. source) THEN
        DEC (w. swapArray[j]. readCount)
      END;
    END;
    w. swapArray[i] := w. swapArray[w. lengthSwapArray-1];
    DEC (w. lengthSwapArray);
  END RemoveSwapData;

PROCEDURE (w: Writer) IntroduceHelperVar (i: LONGINT);
  VAR
    str: ARRAY 16 OF CHAR;
    j: LONGINT;
    h: STRING;
  BEGIN
    ASSERT (w. swapArray[i]. readCount # 0);
    IntStr.IntToStr (w. swapHelperVars, str);
    Strings.Insert ("h", 0, str);
    h := Object.NewLatin1(str);
    INC (w. swapHelperVars);
    
    FOR j := 0 TO w. lengthSwapArray-1 DO
      IF w. swapArray[j]. source. Equals(w. swapArray[i]. dest) THEN
        w. swapArray[j]. source := h;
      END;
    END;
    w. swapArray[i]. readCount := 0;

    w. WriteString ("{register ");
    w. WriteString (w. basicType[Allocator.RegisterType (w. swapArray[i]. ctype)]. repr);
    w. WriteString (" ");
    w. WriteObject (h);
    w. WriteChar ("=");
    w. WriteObject (w. swapArray[i]. dest);
    w. WriteChar (";");
  END IntroduceHelperVar;

PROCEDURE (w: Writer) FixupHelperVars;
  BEGIN
    WHILE (w. swapHelperVars # 0) DO
      w. WriteChar ("}");
      DEC (w. swapHelperVars)
    END;
  END FixupHelperVars;

PROCEDURE Fixup (pb: SSA.ProcBlock; VAR jmpbufMap: Dictionary.Dictionary);
  VAR
    instr, next: SSA.Instr;
    num: ARRAY 16 OF CHAR;
    regDest, regSource: DeclWriter.BasicTypeId;
  BEGIN
    jmpbufMap := NIL;
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      CASE instr. opcode OF
      | Opcode.call:
        IF (instr. opndList. arg IS SSA.Address) THEN
          (* if the function address of a call is taken from an address
             instruction, then replace this operand with a `declref';
             this way, the name of the called function is used directly,
             without going through an intermediate address value *)
          instr. opndList. ReplaceArg
              (pb. GetDeclRef (instr. opndList. arg(SSA.Address). decl));
        END;

      | Opcode.tryStart:
        IF (jmpbufMap = NIL) THEN
          jmpbufMap := Dictionary.New();
        END;
        IntStr.IntToStr(jmpbufMap.Size(), num);
        jmpbufMap.Set(instr, Object.NewLatin1(num));

      | Opcode.typeConv:
        regDest := Allocator.RegisterType
            (Allocator.SubclassToBasicType(instr.subclass));
        regSource := Allocator.RegisterType
            (Allocator.SubclassToBasicType(instr.opndList.arg.subclass));
        IF (regDest = regSource) THEN
          ASSERT(instr.nextResult = NIL);
          instr.ReplaceUses(instr.opndList.arg);
          pb.DeleteInstr(instr);
        END;
      ELSE (* nothing to do *)
      END;
      instr := next;
    END;
  END Fixup;


PROCEDURE WriteTypeCast (w: DeclWriter.Writer; ctype: DeclWriter.BasicTypeId);
  VAR
    rtype: DeclWriter.BasicTypeId;
  BEGIN
    rtype := Allocator.RegisterType (ctype);
    IF (rtype # ctype) THEN
      w. WriteChar ("(");
      w. WriteString (w. basicType[rtype]. repr);
      w. WriteChar (")");
    END;
  END WriteTypeCast;

PROCEDURE ^ (w: Writer) TypeRef (type: Sym.Type);
PROCEDURE ^ (w: Writer) Ref (opnd: SSA.Opnd);

PROCEDURE WriteTypeAndLength (w: Writer; instr: SSA.Instr;
                              varDecl: Sym.VarDecl; inBytes: BOOLEAN);
  VAR
    type: Sym.Type;
  BEGIN
    w. WriteString (",");
    type := varDecl.type.Deparam(); 
    IF (type IS Sym.Array) THEN
      w.TypeRef(type(Sym.Array).GetInnermostElementType());
    ELSE
      w.TypeRef(type);
    END;
    w. WriteString (",");
    IF inBytes THEN
      w.Ref(instr.NthOpnd(2));
    ELSE
      w.Ref(instr.NthOpnd(1));
    END;
    w. WriteString (")");
  END WriteTypeAndLength;



PROCEDURE WriteLocalDecl (t: Translator; w: Writer;
                          pb: SSA.ProcBlock; volatile: BOOLEAN);
(**Writes local declarations of the procedure, most of all local variables.  *)
  VAR
    declMap: Dictionary.Dictionary;
    instr: SSA.Instr;
    decl: Sym.VarDecl;
    cDecl: DeclWriter.Declaration;
    item: Sym.Item;
    name: STRING;
    
  PROCEDURE GetLocalDecl (instr: SSA.Instr): Sym.VarDecl;
    VAR
      opnd: SSA.Opnd;
      varDecl: Sym.VarDecl;
    BEGIN
      WITH instr: SSA.Address DO   (* copy-parameter is instance of Address *)
        IF (instr. decl IS Sym.VarDecl) &
           (instr. decl(Sym.VarDecl). Procedure() = pb. procDecl) THEN
          RETURN instr. decl(Sym.VarDecl);
        ELSE
          RETURN NIL;
        END;
      ELSE
        opnd := instr. opndList;
        WHILE (opnd # NIL) &
              ((opnd. class # Opnd.readDesign) &
               (opnd. class # Opnd.writeDesign)) DO
          opnd := opnd. nextOpnd;
        END;
        IF (opnd. arg IS SSA.DeclRef) THEN
          varDecl := opnd. arg(SSA.DeclRef). decl(Sym.VarDecl);
          IF (varDecl. Procedure() = pb. procDecl) THEN
            RETURN varDecl
          END;
        END;
        RETURN NIL
      END;
    END GetLocalDecl;
  
  BEGIN
    declMap := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) OR
         (instr. opcode = Opcode.set) OR
         (instr. opcode = Opcode.copyParameter) OR
         (instr. opcode = Opcode.address) THEN
        decl := GetLocalDecl (instr);
        IF (decl # NIL) & ~declMap. HasKey (decl) THEN
          IF (instr. opcode = Opcode.copyParameter) THEN
            name := Naming.NameOfDeclaration(decl);
            w. Newline;
            w. WriteString ("OOC_ALLOCATE_VPAR(");
            w. WriteObject (name);
            WriteTypeAndLength(w, instr, decl, FALSE);
          ELSIF ~decl. isParameter THEN
            cDecl := ConvertDecl.GetDecl (w, decl);
            IF volatile THEN
              cDecl.SetTypeQualifier(DeclWriter.tqVolatile);
            END;
            w. Newline;
            w. WriteDeclaration (cDecl);
            w. WriteChar (";");
            declMap. Set (decl, NIL)
          END;
        END;
      END;
      instr := instr. nextInstr
    END;

    (* pick up any additional variable declarations that are not touched
       by the body of the current procedure, but are referenced by
       local procedures of it *)
    item := pb. procDecl. nestedItems;
    WHILE (item # NIL) DO
      WITH item: Sym.VarDecl DO
        IF ~item. isParameter &
           ~declMap. HasKey (item) &
           t. nonLocalAccess. HasKey (item) THEN
          cDecl := ConvertDecl.GetDecl (w, item);
          w. Newline;
          w. WriteDeclaration (cDecl);
          w. WriteChar (";");
          declMap. Set (item, NIL);
        END;
      ELSE                             (* ignore *)
      END;
      item := item. nextNested;
    END;
    
    (* write prototypes for all nested functions, so that recursive calls
       between them work *)
    item := pb. procDecl. nestedItems;
    WHILE (item # NIL) DO
      WITH item: Sym.ProcDecl DO
        cDecl := ConvertDecl.GetProc (w, item, TRUE);
        w. Newline;
        w. WriteDeclaration (cDecl);
        w. WriteChar (";");
        declMap. Set (item, NIL);
      ELSE                             (* ignore *)
      END;
      item := item. nextNested;
    END;
  END WriteLocalDecl;


PROCEDURE (w: Writer) LengthExprHeap (instr: SSA.Instr);
  BEGIN
    w. WriteString ("OOC_ARRAY_LENGTH(");
    w. Ref (instr. opndList. nextOpnd);
    w. WriteString (", ");
    w. Ref (instr. opndList);
    w. WriteString (")");
  END LengthExprHeap;

PROCEDURE (w: Writer) LengthExprParam (instr: SSA.Instr);
  VAR
    design: SSA.Result;
    name: STRING;
  BEGIN
    design := instr. GetArgClass (Opnd.readDesign);
    name := Naming.NameOfLengthParam
        (design(SSA.DeclRef). decl(Sym.VarDecl), instr. opndList. GetIntConst());
    w. WriteObject (name);
  END LengthExprParam;

PROCEDURE ^ WriteExpr (w: Writer; instr: SSA.Instr);

PROCEDURE (w: Writer) Ref (opnd: SSA.Opnd);
  VAR
    arg: SSA.Result;
    obj: Object.Object;
    name: STRING;
    instr: SSA.Instr;
    bt: DeclWriter.BasicTypeId;
  BEGIN
    arg := opnd. arg;
    WITH arg: SSA.DeclRef DO
      (* insert name of the object; shortcut to save the type cast
         when calling a procedure *)
      name := Naming.NameOfDeclaration (arg. decl);
      IF (arg. decl IS Sym.VarDecl) &
         arg. decl(Sym.VarDecl). isPassPerReference &
         ~(arg. decl(Sym.VarDecl). type IS Sym.Array) THEN
        (* deref pass-per-reference parameters, unless the parameter type
           happens to be an array *)
        w. WriteString ("*")
      END;
      w. WriteObject (name)

    | arg: SSA.Const DO
      (* write constant values directly, without going through an
         intermediate register; the roundabout route is kind of unnatural
         for C code *)
      IF (arg.value = SSA.nil) THEN
        CASE Predef.address OF
        | Predef.hugeint: bt := DeclWriter.int64;
        | Predef.longint: bt := DeclWriter.int32;
        END;
        w. WriteString ("(");
        w. WriteString (w. basicType[bt]. repr);
        w. WriteString (")");
        w.WriteString("0");
      ELSIF (arg.stringType # NIL) THEN
        w.WriteStringConst(arg.value, arg.stringType);
      ELSE
        w.WriteBasicConst(arg.value,
                          Allocator.SubclassToBasicType(arg.subclass));
      END;

    | arg: SSA.Address DO
      name := Naming.NameOfDeclaration (arg. decl);
      WriteTypeCast (w, DeclWriter.ptr);
      IF ~(((arg. decl IS Sym.VarDecl) &
            (arg. decl(Sym.VarDecl). type IS Sym.Array)) OR
           ((arg. decl IS Sym.VarDecl) &
            arg. decl(Sym.VarDecl). isPassPerReference)) THEN
        (* charming C: the address of the variable is its name; all
           others need the address operator unless we are looking at
           a pass by reference parameter *)
        w. WriteChar ("&");
      END;
      w. WriteObject (name);
      
    ELSE
      instr := opnd. arg. instr;
      IF w. registerMap. HasKey (opnd. arg) THEN
        obj := w. registerMap. Get (opnd. arg);
        IF (obj = Allocator.markInPlace) THEN
          w. WriteChar ("(");
          WriteExpr (w, opnd. arg. instr);
          w. WriteChar (")");
        ELSE
          w. WriteObject (obj);
        END;

      ELSIF (instr. opcode = Opcode.getLengthParam) THEN
        w. LengthExprParam (instr);
        
      ELSIF (instr.opcode = Opcode.tryStart) THEN
        w.WriteString("setjmp(_target");
        obj := w.jmpbufMap.Get(instr);
        w.WriteObject(obj);
        w.WriteString(")");
        
      ELSE
        (* provoke an C error if this value is used: *)
        w. WriteString ("XXX undefined ref /*internal error*/");
      END
    END
  END Ref;

PROCEDURE (w: Writer) TypeRef (type: Sym.Type);
  VAR
    cType: DeclWriter.Type;
  BEGIN
    cType := ConvertDecl.GetTypeRef (w, type);
    w. WriteType (cType);
  END TypeRef;


PROCEDURE (w: Writer) Noop (instr: SSA.Instr): BOOLEAN;
  VAR
    targetInstr: SSA.Instr;
    opnd: SSA.Opnd;
    res: SSA.Result;
    targetVar, sourceVar: Object.Object;
  BEGIN
    CASE instr. opcode OF
    | Opcode.const,
      Opcode.declRef,
      Opcode.typeRef,
      Opcode.address,
      Opcode.enter,
      Opcode.select,
      Opcode.labels,
      Opcode.loopStart,
      Opcode.loopEnd,
      Opcode.exit:
      RETURN TRUE;
      
    | Opcode.collect:
      targetInstr := instr. GetCollectTarget();
      opnd := instr. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) & ~opnd. IsScheduleOpnd() DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF w. registerMap. HasKey (opnd. arg) THEN
            sourceVar := w. registerMap. Get (opnd. arg);
            IF ~sourceVar.Equals(targetVar) THEN
              RETURN FALSE;              (* source and target differ *)
            END;
          ELSE
            RETURN FALSE;                (* source not from register *)
          END;
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;
      RETURN TRUE;
      
    ELSE
      RETURN FALSE;
    END;
  END Noop;

PROCEDURE (w: Writer) EmptyBlock (b: Schedule.Block): BOOLEAN;
(* Return TRUE if the block is empty.  This means it must be a JumpBlock, and
   all of its instructions are noops.  *)
  VAR
    proxy: Schedule.InstrProxy;
  BEGIN
    WITH b: Schedule.JumpBlock DO
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        IF ~w. Noop (proxy. instr) THEN
          RETURN FALSE;
        END;
        proxy := proxy. nextProxy;
      END;
      RETURN TRUE;
    ELSE
      RETURN FALSE;
    END;
  END EmptyBlock;

PROCEDURE CastToPtr (w: Writer; var: SSA.Result; type: Sym.Type;
                     passByReference: BOOLEAN);
  VAR
    name: STRING;
  BEGIN
    type := type.Deparam();
    IF (var. instr. opcode = Opcode.typeTag) THEN
      w. WriteString ("(RT0__Struct)");
    ELSIF (type IS Sym.Pointer) OR
          (type IS Sym.FormalPars) OR
          (type IS Sym.TypeVar) OR
          passByReference OR
          TR.IsPredefType (type, Predef.ptr) THEN
      IF (var IS SSA.Const) &
         (var(SSA.Const). value IS Boxed.String) THEN
        (* omit cast on string constant *)
      ELSIF passByReference OR
            (type. namingDecl = NIL) OR
            TR.IsPredefType (type, Predef.ptr) THEN
        w. WriteString ("(void*)");
      ELSE
        name := Naming.NameOfType (type);
        w. WriteString ("(");
        w. WriteObject (name);
        w. WriteString (")");
      END;
    END;
  END CastToPtr;

PROCEDURE GetPreloadId(preloadedVars: IntDict.Dictionary;
                       instr: SSA.Instr): LONGINT;
  VAR
    id: LONGINT;
  BEGIN
    IF preloadedVars.HasKey(instr) THEN
      id := preloadedVars.Get(instr);
    ELSE
      id := preloadedVars.Size();
      preloadedVars.Set(instr, id);
    END;
    RETURN id;
  END GetPreloadId;

PROCEDURE WriteExceptionContext(w: Writer; instr: SSA.Instr): Object.Object;
  VAR
    obj: Object.Object;
  BEGIN
    CASE instr.opcode OF
    | Opcode.pushExceptionContext:
      (* keep instr *)
    | Opcode.clearException, Opcode.currentException:
      instr := instr.opndList.arg.instr;
    END;
    obj := w.jmpbufMap.Get(instr.opndList.arg.instr);
    w.WriteString("_context");
    w.WriteObject(obj);
    RETURN obj;
  END WriteExceptionContext;

PROCEDURE WriteExpr (w: Writer; instr: SSA.Instr);
  VAR
    opnd: SSA.Opnd;
    var: SSA.Result;

  PROCEDURE ^ Call (call: SSA.Instr);
    
  PROCEDURE RefList (start: SSA.Opnd; class: Opnd.Class);
    VAR
      opnd: SSA.Opnd;
      count: LONGINT;
    BEGIN
      count := 0;
      opnd := start;
      WHILE (opnd # NIL) DO
        IF (opnd. class = class) THEN
          IF (count # 0) THEN
            w. WriteString (", ")
          END;
          IF (opnd IS SSA.TypedOpnd) THEN
            CastToPtr (w, opnd. arg,
                       opnd(SSA.TypedOpnd). type,
                       opnd(SSA.TypedOpnd). passByReference);
          END;
          w. Ref (opnd);
          INC (count)
        END;
        opnd := opnd. nextOpnd
      END;
    END RefList;
  
  PROCEDURE Assert (assert: SSA.Instr);
    BEGIN
      w. Newline;
      w. WriteString ("_assert(");
      RefList (assert. opndList. nextOpnd, Opnd.arg);
      w. WriteString (", ");
      w. WriteLInt (assert. pos, 0);
      w. WriteString (")")
    END Assert;
  
  PROCEDURE CheckIndex (checkIndex: SSA.Instr);
    VAR
      bt: DeclWriter.BasicTypeId;
    BEGIN
      w. WriteString ("_check_index(");
      RefList (checkIndex. opndList, Opnd.arg);
      w. WriteString (", ");
      bt := SubclassToBasicType (instr)+(DeclWriter.uint8-DeclWriter.int8);
      w. WriteString (w. basicType[bt]. repr);
      w. WriteString (", ");
      w. WriteLInt (checkIndex. pos, 0);
      w. WriteString (")")
    END CheckIndex;

  PROCEDURE CheckPointer (checkPointer: SSA.Instr);
    BEGIN
      w. WriteString ("_check_pointer(");
      w. Ref (checkPointer. opndList. nextOpnd);
      w. WriteString (", ");
      w. WriteLInt (checkPointer. pos, 0);
      w. WriteString (")")
    END CheckPointer;

  PROCEDURE TypeGuard (typeGuard: SSA.Instr);
    VAR
      name: STRING;
      opnd: SSA.Opnd;
      type: Sym.Type;
    BEGIN
      opnd := typeGuard. GetOpndClass (Opnd.type);
      type := opnd. arg(SSA.TypeRef). type;
      
      IF (type IS Sym.TypeClosure) THEN  (* slower but more powerful *)
        w. WriteString ("_type_guard_q(");
      ELSE
        w. WriteString ("_type_guard(");
      END;
      RefList (typeGuard. opndList. nextOpnd, Opnd.arg);
      w. WriteString (", &");
      name := Naming.NameOfTypeDescriptor (type, w.translator.qtdData);
      w. WriteObject (name);
      w. WriteString (", ");
      w. WriteLInt (typeGuard. pos, 0);
      w. WriteString (")")
    END TypeGuard;

  PROCEDURE FailedCheck (instr: SSA.Instr; fct: ARRAY OF CHAR; opnd: SSA.Opnd);
    BEGIN
      w. Newline;
      w. WriteString (fct);
      w. WriteString ("(");
      IF (opnd # NIL) THEN
        w. Ref (opnd);
        w. WriteString (", ");
      END;
      w. WriteLInt (instr. pos, 0);
      w. WriteString (")");
    END FailedCheck;
  
  PROCEDURE Call (call: SSA.Instr);
    VAR
      adr: SSA.Instr;
      decl: Sym.Declaration;
      name: STRING;
      procType: Sym.FormalPars;
      class : Opcode.Class;
    BEGIN
      class := call. opndList. arg. instr. opcode;
      IF   (class = Opcode.tbProcAddress) 
        OR (class = Opcode.vtableProcAddress) THEN
        (* calling type bound procedure: cast procedure address *)
        adr := call. opndList. arg. instr;
        decl := adr. opndList. nextOpnd. arg. instr(SSA.DeclRef). decl;
        w. WriteString ("OOC_TBCALL(");
        w. Ref (call. opndList);
        w. WriteChar (",");
        name := Naming.NameOfDeclaration (decl);
        w. WriteObject (name);
        w. WriteChar (")");
      ELSIF ~(call. opndList. arg IS SSA.DeclRef) THEN
        (* calling through variable: cast address to function type *)
        procType := call. opndList(SSA.TypedOpnd). type(Sym.FormalPars);
        w. WriteChar ("(");
        w. WriteTypeCast (ConvertDecl.ConvertType (w, procType, procType));
        w. Ref (call. opndList);
        w. WriteChar (")");
      ELSE
        w. Ref (call. opndList);
      END;
      w. WriteString ("(");
      RefList (call. opndList, Opnd.arg);
      w. WriteString (")")
    END Call;
  
  PROCEDURE WriteDyadicOp (instr: SSA.Instr; op: ARRAY OF CHAR);
    BEGIN
      w. Ref (instr. opndList);
      w. WriteString (op);
      w. Ref (instr. opndList. nextOpnd);
    END WriteDyadicOp;
  
  PROCEDURE WriteDyadicOpU (instr: SSA.Instr; op: ARRAY OF CHAR);
  (* Like WriteDyadicOp, but if first argument is unsigned, then cast both
     arguments to the unsigned type.  *)
    VAR
      type: DeclWriter.BasicTypeId;
      subclass: Opcode.Subclass;
    BEGIN
      subclass := instr.opndList.arg.subclass;
      IF (Opcode.scUnsigned8 <= subclass) & (subclass <= Opcode.scAddress) THEN
        type := Allocator.SubclassToBasicType(subclass);
        IF (type < DeclWriter.uint8) THEN  (* force unsigned for address *)
          INC(type, DeclWriter.uint8-DeclWriter.int8);
        END;
        
        w. WriteChar ("(");
        w. WriteString (w. basicType[type]. repr);
        w. WriteChar (")");
        w. Ref (instr. opndList);
        w. WriteString (op);
        w. WriteChar ("(");
        w. WriteString (w. basicType[type]. repr);
        w. WriteChar (")");
        w. Ref (instr. opndList. nextOpnd);
      ELSE
        WriteDyadicOp(instr, op);
      END;
    END WriteDyadicOpU;
  
  PROCEDURE WriteDyadicFct (instr: SSA.Instr; fct: ARRAY OF CHAR);
    BEGIN
      w. WriteString (fct);
      w. WriteChar ("(");
      w. Ref (instr. opndList);
      w. WriteChar (",");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteString (")");
    END WriteDyadicFct;
  
  PROCEDURE WriteMonadicOp (instr: SSA.Instr; op, suffix: ARRAY OF CHAR);
    BEGIN
      w. WriteString (op);
      w. Ref (instr. opndList);
      w. WriteString (suffix);
    END WriteMonadicOp;
  
  PROCEDURE CastFromPtr (res: SSA.Result);
    BEGIN
      IF (res. subclass = Opcode.scAddress) THEN
        w. WriteString ("(");
        w. WriteString (w. basicType[SubclassToBasicType (instr)]. repr);
        w. WriteString (")");
      END;
    END CastFromPtr;
  
  PROCEDURE NewObject (instr: SSA.Instr);
    VAR
      name: STRING;
      opnd: SSA.Opnd;
    BEGIN
      CastFromPtr (instr);
      w. WriteString ("RT0__NewObject(");
      opnd := instr. GetOpndClass (Opnd.type);
      name := Naming.NameOfTypeDescriptor (opnd. arg(SSA.TypeRef). type,
                                           w.translator.qtdData);
      w. WriteObject (name);
      w. WriteString (".baseTypes[0]");

      opnd := opnd. nextOpnd;
      WHILE (opnd # NIL) & (opnd. class = Opnd.arg) DO
        w. WriteString (", ");
        w. Ref (opnd);
        opnd := opnd. nextOpnd;
      END;
      w. WriteString (")");
    END NewObject;
  
  PROCEDURE NewBlock (instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      CastFromPtr (instr);
      w. WriteString ("RT0__NewBlock(");
      opnd := instr. GetOpndClass (Opnd.arg);
      w. Ref (opnd);
      w. WriteString (")");
    END NewBlock;
  
  PROCEDURE TypeCast (instr: SSA.Instr);
    VAR
      destType, sourceType: Opcode.Subclass;
    BEGIN
      CastFromPtr (instr);
      destType := Allocator.SubclassToBasicType (instr. subclass);
      sourceType := Allocator.SubclassToBasicType (instr. opndList. arg. subclass);
      IF Opcode.ConvDiffersFromCast (sourceType, destType) THEN
        w. WriteString ("_type_cast(");
      ELSE
        w. WriteString ("_type_cast_fast(");
      END;
      w. WriteString (w. basicType[destType]. repr);
      w. WriteString (", ");
      w. WriteString (w. basicType[sourceType]. repr);
      w. WriteString (", ");
      w. Ref (instr. opndList);
      w. WriteString (")");
    END TypeCast;

  PROCEDURE TypeConv (instr: SSA.Instr);
    VAR
      destType: Opcode.Subclass;
    BEGIN
      destType := Allocator.SubclassToBasicType (instr. subclass);
      w. WriteString ("(");
      w. WriteString (w. basicType[destType]. repr);
      w. WriteString (")");
      w. Ref (instr. opndList);
    END TypeConv;

  PROCEDURE TypeTag (instr: SSA.Instr);
    VAR
      name: STRING;
    BEGIN
      CastFromPtr (instr);
      IF (instr. opndList. arg IS SSA.DeclRef) THEN
        name := Naming.NameOfTypeTagParam (instr. opndList. arg(SSA.DeclRef). decl(Sym.VarDecl));
        w. WriteObject (name);
      ELSIF (instr. opndList. arg IS SSA.TypeRef) THEN
        w. WriteChar ("&");
        name := Naming.NameOfTypeDescriptor(instr.opndList.arg(SSA.TypeRef).type,
                                            w.translator.qtdData);
        w. WriteObject (name);
      ELSE
        w. WriteString ("OOC_TYPE_TAG(");
        w. Ref (instr. opndList);
        w. WriteChar (")");
      END;
    END TypeTag;
  
  PROCEDURE TypeTest (instr: SSA.Instr);
    VAR
      name: STRING;
      opnd: SSA.Opnd;
      type: Sym.Type;
    BEGIN
      opnd := instr. opndList. nextOpnd;
      type := opnd. arg(SSA.TypeRef). type;

      IF (type IS Sym.TypeClosure) THEN  (* slower but more powerful *)
        w.WriteString("RT0__TypeTest((OOC_PTR)");
      ELSE
        w.WriteString("OOC_TYPE_TEST(");
      END;
      w. Ref (instr. opndList);
      w. WriteString (", &");
      name := Naming.NameOfTypeDescriptor (type, w.translator.qtdData);
      w. WriteObject (name);
      w. WriteString (")");
    END TypeTest;

  PROCEDURE TBProcAddress (instr: SSA.Instr);
    VAR
      name: STRING;
    BEGIN
      CastFromPtr (instr);
      w. WriteString ("OOC_TBPROC_ADR(");
      w. Ref (instr. opndList);
      w. WriteString (", ");
      name := Naming.NameOfDeclaration (instr. opndList. nextOpnd. arg(SSA.DeclRef). decl);
      w. WriteObject (name);
      w. WriteString (")");
    END TBProcAddress;

   PROCEDURE VTableProcAddress (instr: SSA.Instr);
    VAR
      name: STRING;
    BEGIN
      CastFromPtr (instr);
      w. WriteString ("OOC_VTABLEPROC_ADR(");
      w. Ref (instr. opndList);
      w. WriteString (", ");
      name := Naming.NameOfDeclaration (instr. opndList. nextOpnd. arg(SSA.DeclRef). decl);
      w. WriteObject (name);
      w. WriteString (")");
    END VTableProcAddress;
  
  PROCEDURE CopyParameter (instr: SSA.Address);
    VAR
      varDecl: Sym.VarDecl;
      name: STRING;
    BEGIN
      varDecl := instr. decl(Sym.VarDecl);
      name := Naming.NameOfDeclaration (varDecl);
      
      w. Newline;
      w. WriteString ("OOC_INITIALIZE_VPAR(");
      w. WriteObject (name);
      w. WriteString (Naming.suffixPassPerRef+",");
      w. WriteObject (name);
      WriteTypeAndLength(w, instr, varDecl, TRUE);
    END CopyParameter;
  
  PROCEDURE Copy (instr: SSA.Instr);
    VAR
      type: Sym.Type;
    BEGIN
      w. Newline;
      type := instr. opndList. nextOpnd. arg(SSA.TypeRef). type;
      w. WriteString ("_copy_block(");
      w. Ref (instr. GetOpndClass (Opnd.readAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.writeAdr));
      w. WriteChar (",");
      w. WriteLInt (type. size, 0);
      w. WriteString (")");
    END Copy;
  
  PROCEDURE TypeId (res: SSA.Result): LONGINT;
    BEGIN
      RETURN res(SSA.TypeRef). type(Sym.PredefType). id;
    END TypeId;
  
  PROCEDURE CopyString (instr: SSA.Instr);
    VAR
      source, dest: LONGINT;
    BEGIN
      w. Newline;
      source := TypeId (instr. NthArg (1));
      dest := TypeId (instr. NthArg (2));

      IF (source = Predef.char) THEN
        CASE dest OF
        | Predef.char    : w. WriteString ("_copy_8(");
        | Predef.longchar: w. WriteString ("_copy_8to16(");
        | Predef.ucs4char: w. WriteString ("_copy_8to32(");
        END;
      ELSIF (source = Predef.longchar) THEN
        CASE dest OF
        | Predef.longchar: w. WriteString ("_copy_16(");
        | Predef.ucs4char: w. WriteString ("_copy_16to32(");
        END;
      ELSE (* (source = Predef.ucs4char) & (dest = Predef.ucs4char) *)
        w. WriteString ("_copy_32(");
      END;
      w. WriteString ("(const void*)");
      w. Ref (instr. GetOpndClass (Opnd.readAdr));
      w. WriteString (",(void*)");
      w. Ref (instr. GetOpndClass (Opnd.writeAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.arg));
      w. WriteString (")");
    END CopyString;
  
  PROCEDURE CmpString (instr: SSA.Instr);
    BEGIN
      w. Newline;
      CASE TypeId(instr.NthArg(1)) OF
      | Predef.char:     w.WriteString("_cmp8((const void*)");
      | Predef.longchar: w.WriteString("_cmp16((const void*)");
      | Predef.ucs4char: w.WriteString("_cmp32((const void*)");
      END;
      opnd := instr. GetOpndClass (Opnd.readAdr);
      w. Ref (opnd);
      w. WriteString (",(const void*)");
      REPEAT                             (* locate second readAdr *)
        opnd := opnd. nextOpnd;
      UNTIL (opnd. class = Opnd.readAdr);
      w. Ref (opnd);
      w. WriteString (")");
    END CmpString;

  PROCEDURE Concat (instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      CastFromPtr(instr);
      w.WriteString (Builder.stringModuleC+"__Concat2(");
      opnd := instr.opndList;
      WHILE (opnd # NIL) DO
        IF (opnd # instr.opndList) THEN
          w.WriteString (",");
        END;
        w.WriteString ("(void*)");
        w.Ref(opnd);
        opnd := opnd.nextOpnd;
      END;
      w.WriteString (")");
    END Concat;
  
  PROCEDURE MoveBlock (instr: SSA.Instr);
    BEGIN
      w. Newline;
      w. WriteString ("_move_block(");
      w. Ref (instr. GetOpndClass (Opnd.readAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.writeAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.arg));
      w. WriteString (")");
    END MoveBlock;
  
  PROCEDURE Shift (instr: SSA.Instr; rotate: BOOLEAN);
    BEGIN
      IF rotate THEN
        w. WriteString ("_rot(");
      ELSE
        w. WriteString ("_lsh(");
      END;
      w. WriteString (w. basicType[Allocator.SubclassToBasicType (instr. subclass)]. repr);
      w. WriteString (", ");
      w. Ref (instr. opndList);
      w. WriteString (", ");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteString (")");
    END Shift;

  PROCEDURE Indexed (instr: SSA.Instr);
    BEGIN
      w. Ref (instr. opndList);
      w. WriteChar ("+");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteChar ("*");
      w. Ref (instr. opndList. nextOpnd. nextOpnd);
    END Indexed;
  
  PROCEDURE SimpleVarAccess (instr: SSA.Instr; adrClass: Opnd.Class): BOOLEAN;
    VAR
      adr: SSA.Result;
      opnd, design: SSA.Opnd;
    BEGIN
      opnd := instr. GetOpndClass (adrClass);
      adr := opnd. arg;
      design := opnd. nextOpnd;
      IF (adr IS SSA.Address) &
         ((design. nextOpnd = NIL) OR
          (design. nextOpnd. class # design. class)) THEN
        (* if this is an access to a variable without any additional selectors
           or a type cast, then return TRUE *)
        RETURN TRUE
      ELSE
        RETURN FALSE
      END;
    END SimpleVarAccess;

  PROCEDURE PreloadedVar (instr: SSA.Instr);
    VAR
      wd: DeclWriter.Writer;
      id: LONGINT;
    BEGIN
      id := GetPreloadId(w.translator.preloadedVars, instr);
      CastFromPtr(instr);
      w.WriteString(prefixPreloadVar);
      w.textWriter.WriteLInt(id, 0);

      wd := w.translator.wd;
      wd.WriteString("static void* "+prefixPreloadVar);
      wd.textWriter.WriteLInt(id, 0);
      wd.WriteString(";");
      wd.Newline;
    END PreloadedVar;
  
  BEGIN
    CASE instr. opcode OF
    | Opcode.get:
      CastFromPtr (instr);
      IF SimpleVarAccess (instr, Opnd.readAdr) THEN
        w. Ref (instr. GetOpndClass (Opnd.readDesign))
      ELSE
        w. WriteString ("*(");
        w. WriteString (w. basicType
                        [SubclassToBasicType (instr)]. repr);
        w. WriteString ("*)");
        w. Ref (instr. opndList. nextOpnd);
      END;
      
    | Opcode.set:
      w. Newline;
      IF SimpleVarAccess (instr, Opnd.writeAdr) THEN
        w. Ref (instr. GetOpndClass (Opnd.writeDesign));
        var := instr. GetArgClass (Opnd.writeDesign);
        w. WriteString (" = ");
        CastToPtr (w, var, var(SSA.DeclRef). decl(Sym.VarDecl). type, FALSE);
      ELSE
        w. WriteString ("*(");
        w. WriteString (w. basicType
                        [SubclassToBasicType (instr)]. repr);
        w. WriteString ("*)");
        w. Ref (instr. opndList. nextOpnd);
        w. WriteString (" = ");
      END;
      w. Ref (instr. GetOpndClass (Opnd.sourceValue));
      
    | Opcode.copy:
      Copy (instr);
    | Opcode.copyString:
      CopyString (instr);
    | Opcode.cmpString:
      CmpString (instr);
    | Opcode.concat:
      Concat (instr);
    | Opcode.moveBlock:
      MoveBlock (instr);
      
    | Opcode.getLengthHeap:
      w. LengthExprHeap (instr);
    | Opcode.getLengthParam:
      (* don't write statement for length of open array parameter *)
      
    | Opcode.copyParameter:
      CopyParameter (instr(SSA.Address));
      
    | Opcode.newObject:
      NewObject (instr);
    | Opcode.newBlock:
      NewBlock (instr);
    | Opcode.typeTag:
      TypeTag (instr);
    | Opcode.typeTest:
      TypeTest (instr);
    | Opcode.tbProcAddress:
      TBProcAddress (instr);
    | Opcode.vtableProcAddress:
      VTableProcAddress (instr);
    | Opcode.typeCast:
      TypeCast (instr);
    | Opcode.typeConv:
      TypeConv (instr);
      
    | Opcode.add:
      WriteDyadicOp (instr, "+");
    | Opcode.subtract:
      WriteDyadicOp (instr, "-");
    | Opcode.negate:
      WriteMonadicOp (instr, "-", "");
    | Opcode.multiply:
      WriteDyadicOp (instr, "*");
    | Opcode.divide:
      IF (instr. subclass < Opcode.scUnsigned8) THEN
        WriteDyadicFct (instr, "_div");
      ELSE
        WriteDyadicOp (instr, "/");
      END;
    | Opcode.modulo:
      WriteDyadicFct (instr, "_mod");
      
    | Opcode.and:
      WriteDyadicOp (instr, "&&");
    | Opcode.or:
      WriteDyadicOp (instr, "||");
    | Opcode.not:
      WriteMonadicOp (instr, "!", "");
    | Opcode.logicalAnd:
      WriteDyadicOp (instr, "&");
    | Opcode.logicalOr:
      WriteDyadicOp (instr, "|");
    | Opcode.logicalXor:
      WriteDyadicOp (instr, "^");
    | Opcode.logicalSubtr:
      WriteDyadicFct (instr, "_logical_subtr");
    | Opcode.logicalComplement:
      WriteMonadicOp (instr, "~", "");
    | Opcode.setBit:
      WriteDyadicFct (instr, "_set_bit");
    | Opcode.clearBit:
      WriteDyadicFct (instr, "_clear_bit");
      
    | Opcode.setMember:
      WriteDyadicFct (instr, "_in");
    | Opcode.setRange:
      WriteDyadicFct (instr, "_bit_range");
    | Opcode.abs:
      WriteMonadicOp (instr, "_abs(", ")");
    | Opcode.shiftLeft:
      WriteDyadicOp (instr, "<<");
    | Opcode.shiftRight:
      WriteDyadicOp (instr, ">>");
    | Opcode.ash:
      WriteDyadicFct (instr, "_ash");
    | Opcode.cap:
      WriteMonadicOp (instr, "_cap(", ")");
    | Opcode.entier:
      WriteMonadicOp (instr, "_entier(", ")");
    | Opcode.indexed:
      Indexed (instr);
    | Opcode.lsh:
      Shift (instr, FALSE);
    | Opcode.rot:
      Shift (instr, TRUE);
    | Opcode.odd:
      WriteMonadicOp (instr, "_odd(", ")");
      
    | Opcode.eql:
      WriteDyadicOp (instr, "==");
    | Opcode.neq:
      WriteDyadicOp (instr, "!=");
    | Opcode.lss:
      WriteDyadicOpU (instr, "<");
    | Opcode.leq:
      WriteDyadicOpU (instr, "<=");
    | Opcode.gtr:
      WriteDyadicOpU (instr, ">");
    | Opcode.geq:
      WriteDyadicOpU (instr, ">=");
      
    | Opcode.assert:
      Assert (instr);
    | Opcode.halt:
      w. Newline;
      w. WriteString ("_halt(");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteString (")")
    | Opcode.checkIndex:
      CheckIndex (instr);
    | Opcode.checkPointer:
      CheckPointer (instr);
    | Opcode.typeGuard:
      TypeGuard (instr);
    | Opcode.failedCase:
      FailedCheck (instr, "_failed_case", instr. opndList. nextOpnd);
    | Opcode.failedWith:
      FailedCheck (instr, "_failed_with", instr. opndList. nextOpnd);
    | Opcode.failedTypeAssert:
      FailedCheck (instr, "_failed_type_assert", NIL);
      
    | Opcode.call:
      IF ~w. registerMap. HasKey (instr) THEN
        w. Newline;
      ELSE
        CastFromPtr (instr);
      END;
      Call (instr);

    | Opcode.currentException:
      CastFromPtr(instr);
      w.WriteString("Exception__Current()");
      
    | Opcode.preloadedVar:
      PreloadedVar(instr);
    END;
  END WriteExpr;

PROCEDURE (w: Writer) WriteInstrList (b: Schedule.Block);
  VAR
    proxy: Schedule.InstrProxy;
    instr: SSA.Instr;
    target: Object.Object;
    str: ARRAY 32 OF CHAR;
    opnd: SSA.Opnd;
    obj: Object.Object;
    fpars: Sym.FormalPars;
    
  PROCEDURE WriteCollect (collect, targetInstr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
      res: SSA.Result;
      targetVar, sourceVar: Object.Object;
      i: LONGINT;
    BEGIN
      w. Newline;
      
      (* first pass: collect all copy instructions transfering from a register
         variable into another *)
      w. ClearSwapData;
      opnd := collect. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) & ~opnd. IsScheduleOpnd() DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF w. registerMap. HasKey (opnd. arg) THEN
            sourceVar := w. registerMap. Get (opnd. arg);
            w. AddSwapData (sourceVar(STRING),
                            targetVar(STRING),
                            SubclassToBasicType (res))
          END;
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;

      (* second pass: write out register transfers in an order that keeps
         the number of helper variables down *)
      w. CountReadsSwapData;
      WHILE (w. lengthSwapArray # 0) DO
        i := 0;
        WHILE (i # w. lengthSwapArray) & (w. swapArray[i]. readCount # 0) DO
          INC (i)
        END;

        IF (i = w. lengthSwapArray) THEN
          w. IntroduceHelperVar (0)
        ELSE                             (* can write out assignment *)
          w. WriteObject (w. swapArray[i]. dest);
          w. WriteString ("=");
          w. WriteObject (w. swapArray[i]. source);
          w. WriteChar (";");
          w. RemoveSwapData (i)
        END;
      END;
      w. FixupHelperVars;
      
      (* final pass: write out anything that does not read from a register *)
      opnd := collect. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) & ~opnd. IsScheduleOpnd() DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF ~w. registerMap. HasKey (opnd. arg) THEN
            w. WriteObject (targetVar);
            w. WriteString ("=");
            w. Ref (opnd);
            w. WriteChar (";");
          END
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;
    END WriteCollect;

  PROCEDURE PrefixReturn;
  (**Called before every "return" instruction.  *)
    BEGIN
      w. Newline;
    END PrefixReturn;
  
  PROCEDURE AllPathsClosed (selectReturn: SSA.Instr): BOOLEAN;
  (* Returns TRUE if all paths into the "select-return" end with a "return"
     instruction.  The current approximation only checks if the function ends
     with a RETURN statement.  A more sophisticated version could traverse the
     final store backward and see if all paths end at a RETURN or at a
     procedure call that cannot return.  *)
    VAR
      opnd: SSA.Opnd;
    BEGIN
      opnd := selectReturn. opndList. nextOpnd;
      WHILE (opnd. nextOpnd # NIL) DO
        opnd := opnd. nextOpnd;
      END;
      RETURN (opnd. arg. instr. opcode = Opcode.return);
    END AllPathsClosed;

  BEGIN
    proxy := b. proxyList;
    WHILE (proxy # NIL) DO
      instr := proxy. instr;

      IF enableDebugOutput THEN
        w. Newline;
        instr. GetOpcodeName (str);
        w. WriteString ("/* ");
        w. WriteString (str);
        w. WriteString (": */ ");
      END;

      target := NIL;
      IF w. registerMap. HasKey (instr) THEN
        target := w. registerMap. Get (instr);
        IF (target # Allocator.markInPlace) THEN
          w. Newline;
          (*w. WriteString ("/* ");
             w. textWriter. WriteHex (SYSTEM.VAL(LONGINT,instr),8);
             w. WriteString ("*/ ");*)
          w. WriteObject (target);
          w. WriteString (" = ");
        END;
      END;

      (*w. WriteString("/*");
      Opcode.GetName (instr. opcode, instr. subclass, str);
      w. WriteString(str);
      w. WriteString("*/");*)
      IF (target # Allocator.markInPlace) THEN
        CASE instr. opcode OF
        | Opcode.const:
          (* nothing, handled in `Ref' *)
          
        | Opcode.declRef:
          (* nothing, handled in `Ref' *)
          
        | Opcode.typeRef:
          (* nothing, handled in `Ref' *)
          
        | Opcode.address:
          (* nothing, handled in `Ref' *)
          
        | Opcode.enter:
          (* nothing *)
        | Opcode.select:
          (* nothing *)
        | Opcode.labels:
          (* nothing *)
        | Opcode.designStandin:
          (* nothing *)
          
        | Opcode.loopStart:
          (* nothing *)
          
        | Opcode.loopEnd:
          (* nothing *)
          
        | Opcode.exit:
          (* nothing, the immediately following jump does all the work *)
          
        | Opcode.collect:
          WriteCollect (instr, instr. GetCollectTarget());

        | Opcode.return:
          PrefixReturn;
          opnd := instr. GetOpndClass (Opnd.functionResult);
          IF (opnd # NIL) THEN
            w. WriteString ("return ");
            CastToPtr (w, opnd. arg,
                       w. procBlock. procDecl. formalPars. resultType, FALSE);
            w. Ref (opnd);
          ELSE
            w. WriteString ("return")
          END;
          w. WriteChar (";")
          
        | Opcode.selectReturn:
          IF ~AllPathsClosed (instr) THEN
            PrefixReturn;
            fpars := w.procBlock.procDecl.formalPars;
            IF (fpars.resultType # NIL) THEN
              IF w. procBlock. checkFunctionResult THEN
                w. WriteString ("_failed_function(");
                w. WriteLInt (w. procBlock. procDecl. name. pos, 0);
                w. WriteString ("); ");
              END;
              IF ~fpars.noReturn THEN
                w. WriteString ("return 0;");
              END;
            ELSIF ~fpars.noReturn THEN
              w. WriteString ("return;")
            END;
          END;
          
        | Opcode.tryStart:
          w.Newline;
          w.WriteString("{");
          w.Indent(1);
        | Opcode.tryEnd:
          w.WriteString(";");
          w.Indent(-1);
          w.Newline;
          w.WriteString("}");
        | Opcode.raiseException:
          w.Newline;
          w.WriteString("Exception__Raise((void*)");
          w.Ref(instr.NthOpnd(1));
          w.WriteString(");");
        | Opcode.pushExceptionContext:
          w.Newline;
          w.WriteString("Exception__PushContext(&");
          obj := WriteExceptionContext(w, instr);
          w.WriteString(", &_target");
          w.WriteObject(obj);
          w.WriteString(");");
        | Opcode.popExceptionContext:
          w.Newline;
          w.WriteString("Exception__PopContext(");
          w.WriteBasicConst(instr.opndList.nextOpnd.arg(SSA.Const).value,
                            DeclWriter.int32);
          w.WriteString(");");
        | Opcode.clearException:
          w.Newline;
          w.WriteString("Exception__Clear();");
        | Opcode.activateContext:
          w.Newline;
          w.WriteString("Exception__ActivateContext();");
        ELSE
          WriteExpr (w, instr);
          IF ~instr. IsConst() THEN  (* FIXME... omit ; for some getLength *)
            w. WriteChar (";");
          END;
        END;
      END;
      
      proxy := proxy. nextProxy
    END;
  END WriteInstrList;

PROCEDURE (w: Writer) WriteBlocks (domRoot: Schedule.Block);
  VAR
    registeredGoto: Schedule.Block;
    (* this is the goto that would have been written at the end of the
       last block; we actually write it only if the next block starts
       with a different label *)

  PROCEDURE WriteBlockId (b: Schedule.Block);
    BEGIN
      IF (b = NIL) THEN
        w. WriteString ("XXX WriteBlockId(NIL)");
      ELSE
        w. WriteString ("l");
        w. WriteLInt (b. id, 0);
        IF b. isLoopHead THEN
          w. WriteString ("_loop");
        END;
      END;
    END WriteBlockId;
  
  PROCEDURE WriteGoto (target: Schedule.Block);
    BEGIN
      IF (target = NIL) THEN
        w. WriteString ("/* goto: unreachable */");
      ELSE
        w. WriteString ("goto ");
        WriteBlockId (target);
        w. WriteChar (";");
      END;
    END WriteGoto;
  
  PROCEDURE WriteBlock (b: Schedule.Block);
    VAR
      i, d: LONGINT;
      nested: Schedule.Block;
      
    PROCEDURE WriteNested (nested: Schedule.Block);
      BEGIN
        WHILE (nested # NIL) DO
          WriteBlock (nested);
          nested := nested. nextDom
        END;
      END WriteNested;

    PROCEDURE WriteCases (instr: SSA.Instr);
      VAR
        opnd, lower, upper: SSA.Opnd;
      BEGIN
        IF (instr. opcode = Opcode.labels) THEN
          opnd := instr. opndList;
          WHILE (opnd # NIL) DO
            lower := opnd;
            opnd := opnd. nextOpnd;
            upper := opnd;
            opnd := opnd. nextOpnd;
            
            w. Newline;
            w. WriteString ("case ");
            w. Ref (lower);
            IF (lower. arg # upper. arg) THEN
              w. WriteString (" ... "); (* this is a gcc specialty *)
              w. Ref (upper);
            END;
            w. WriteString (":");
          END;
        ELSE
          w. Newline;
          w. WriteString ("default:");
        END;
      END WriteCases;
    
    BEGIN
      IF (b. degreeIn # 0) OR ~(b IS Schedule.JumpBlock) THEN
        IF (registeredGoto # NIL) & (registeredGoto # b) THEN
          w. Newline;
          WriteGoto (registeredGoto);
          registeredGoto := NIL;
        END;

        d := b. degreeIn;
        IF (b = registeredGoto) THEN
          DEC (d);
        END;
        IF (d # 0) THEN
          w. WriteLn;
          WriteBlockId (b);
          w. WriteChar (":");
        END;
        w. WriteInstrList (b);
      END;
      
      WITH b: Schedule.BranchBlock DO
        w. Newline;
        w. WriteString ("if (");
        IF (b. DefaultTarget() = b. jump. dest) THEN
          IF ~b. branchOnTrue THEN
            w. WriteChar("!");
          END;
          w. Ref (b. predicate);
          w. WriteString (") ");
          WriteGoto (b. branchTo. dest);
          registeredGoto := b. jump. dest;
        ELSE
          IF b. branchOnTrue THEN
            w. WriteChar("!");
          END;
          w. Ref (b. predicate);
          w. WriteString (") ");
          WriteGoto (b. jump. dest);
          registeredGoto := b. branchTo. dest;
        END;
        WriteNested (b. domList);
        
      | b: Schedule.SwitchBlock DO
        w. Newline;
        w. WriteString ("switch (");
        w. Ref (b. expr);
        w. WriteString (") {");
          
        nested := b. domList; i := 0;
        WHILE (nested # NIL) & (i # LEN (b. jump^)) DO
          ASSERT (nested = b. jump[i]. dest);
          WriteCases (b. caseValues[i]. arg. instr);
          
          w. Indent (1);
          registeredGoto := b. jump[i]. dest;
          WriteBlock (b. jump[i]. dest);
          w. Newline;
          WriteGoto (registeredGoto);
          w. Indent (-1);
          nested := nested. nextDom; INC (i);
        END;
        ASSERT (nested. nextDom = NIL);
        w. Newline;
        w. WriteString ("}");
        registeredGoto := NIL;
        WriteNested (nested);
        
      | b: Schedule.JumpBlock DO
        IF (b. degreeIn # 0) THEN (* no need for goto if block is unused *)
          registeredGoto := b. jump. dest;
        END;
        WriteNested (b. domList);

      | b: Schedule.DeadEndBlock DO
        WriteNested (b. domList);
      END;
    END WriteBlock;
  
  BEGIN
    registeredGoto := domRoot;
    WriteBlock (domRoot);
  END WriteBlocks;

PROCEDURE (t: Translator) WriteProcBody* (proc: IR.Procedure);
  VAR
    pb: SSA.ProcBlock;
    enter, instr: SSA.Instr;
    s: SSA.Result;
    domRoot: Schedule.Block;
    registerMap, jmpbufMap: Dictionary.Dictionary;
    w: Writer;
    writeProc: BOOLEAN;
    destore: Destore.State;
    dummy: LONGINT;

  PROCEDURE WriteJmpBufDecl(jmpbufMap: Dictionary.Dictionary);
    VAR
      i: LONGINT;
    BEGIN
      IF (jmpbufMap # NIL) THEN
        w.Newline;
        w.WriteString("jmp_buf ");
        FOR i := 0 TO jmpbufMap.Size()-1 DO
          IF (i # 0) THEN w.WriteString(", ") END;
          w.WriteString("_target"); w.WriteLInt(i, 0);
        END;
        w.WriteString(";");

        w.Newline;
        w.WriteString("Exception__Context ");
        FOR i := 0 TO jmpbufMap.Size()-1 DO
          IF (i # 0) THEN w.WriteString(", ") END;
          w.WriteString("_context"); w.WriteLInt(i, 0);
        END;
        w.WriteString(";");
      END;
    END WriteJmpBufDecl;
  
  PROCEDURE Write (pre, post: ARRAY OF CHAR; addToStats: BOOLEAN);
    BEGIN
      IF writeProc &
         ((t. inspectStage. MatchChars (pre, 0, -1) # NIL) OR
          (t. inspectStage. MatchChars (post, 0, -1) # NIL)) THEN
        Err.String ("PROCEDURE ");
        Err.String (pb. procDecl. name. str^);
        Err.String ("/");
        Err.String (pre);
        Err.String ("/");
        Err.String (post);
        Err.String (":");
        Err.Ln;
        Err.Flush;

        (*XML.ToStderr(pb);*)
        Blocker.Write(StdChannels.stderr, pb);
        Err.Flush;
      END;

      IF addToStats THEN
        Stats.AddProcBlock(Object.NewLatin1(pre), pb);
      END;
    END Write;

  PROCEDURE JumpChaining (b: Schedule.Block);
    VAR
      nested: Schedule.Block;

    PROCEDURE Chain (VAR jump: Schedule.Jump);
      BEGIN
        WHILE ~jump. dest. isLoopHead &
              w. EmptyBlock (jump. dest) &
              (jump. dest # jump. src) DO
          Schedule.ChangeJumpTarget (jump, 
                                     jump.dest(Schedule.JumpBlock).jump.dest);
        END;
      END Chain;
    
    BEGIN
      WITH b: Schedule.BranchBlock DO
        Chain (b. jump);
        Chain (b. branchTo);
        
      | b: Schedule.SwitchBlock DO
        (* the data in b.jump[] remains unchanged *)

      | b: Schedule.JumpBlock DO
        Chain (b. jump);

      | b: Schedule.DeadEndBlock DO
        (* nothing to do *)
      END;

      nested := b. domList;
      WHILE (nested # NIL) DO
        JumpChaining (nested);
        nested := nested. nextDom
      END;
    END JumpChaining;
  
  PROCEDURE FixCrossJumps (b: Schedule.Block);
    VAR
      nested: Schedule.Block;

    PROCEDURE Switch (VAR negate: BOOLEAN; VAR j1, j2: Schedule.Jump);
      VAR
        j3: Schedule.Jump;
      BEGIN
        negate := ~negate;
        j3 := j1; j1 := j2; j2 := j3
      END Switch;
    
    BEGIN
      WITH b: Schedule.BranchBlock DO
        IF (b. branchTo. dest. id > b. id) &
           (b. jump. dest. id <= b. id) THEN
          (* if() jumps to later block, goto() to earlier *)
          Switch (b. branchOnTrue, b. branchTo, b. jump);
        ELSIF (b. id < b. branchTo. dest. id) &
              (b. branchTo. dest. id < b. jump. dest. id) THEN
          (* if() jumps over destination of goto() *)
          Switch (b. branchOnTrue, b. branchTo, b. jump);
        END;
      ELSE
        (* ignore *)
      END;
      
      nested := b. domList;
      WHILE (nested # NIL) DO
        FixCrossJumps (nested);
        nested := nested. nextDom
      END;
    END FixCrossJumps;

  PROCEDURE InitPreloadedVars (vars: IntDict.Dictionary);
    VAR
      i, count: LONGINT;
      opnd: SSA.Opnd;
      chars: Object.CharsLatin1;
      instrList, varList: Object.ObjectArrayPtr;
    BEGIN
      instrList := vars.Keys();

      (* sort `instrList' by id *)
      NEW(varList, LEN(instrList^));
      FOR i := 0 TO LEN(instrList^)-1 DO
        varList[vars.Get(instrList[i])] := instrList[i];
      END;
      
      FOR i := 0 TO LEN(varList^)-1 DO
        w.Newline;
        w.WriteString(prefixPreloadVar);
        w.textWriter.WriteLInt(i, 0);
        w.WriteString(" = ");

        opnd := varList[i](SSA.Instr). opndList;
        chars := opnd.arg(SSA.Const).value(Boxed.String).value(Object.String8).CharsLatin1();
        w.WriteString(chars^);
        w.WriteString("(");
        count := 0;
        opnd := opnd. nextOpnd;
        WHILE (opnd # NIL) DO
          IF (count # 0) THEN
            w.WriteString(", ");
          END;
          w.Ref(opnd);
          opnd := opnd. nextOpnd;
          INC (count);
        END;
        w.WriteString(");");
      END;
    END InitPreloadedVars;
  
  BEGIN
    (*Log.String ("procedure",proc. decl. name. str^);*)
    pb := SSA.NewProcBlock (proc);
    writeProc := (t. inspectProc. MatchChars (proc. decl. name. str^, 0, -1) # NIL);
    enter := pb. selectReturn. opndList. arg. instr;
    s := IRtoSSA.StatmSeq (pb, enter. nextResult,
                           proc. statmSeq);
    pb. selectReturn. AddOpnd (s, Opnd.store);
    IRtoSSA.DiscardGets (pb);

    (*Blocker.Write (StdChannels.stdout, pb);*)
    
    (* code transformations *)
    DeadCodeElimination.Transform (pb);
    Write ("initial", "destore1-pre", TRUE);
    destore := Destore.New(pb);
    destore. Transform();
    DeadCodeElimination.RemoveDesignators(pb);
    DeadCodeElimination.Transform(pb);
    Write("destore1-post", "constprop1-pre", TRUE);
    
    ConstProp.Transform(pb);
    DeadCodeElimination.Transform(pb);
    Write("constprop1-post", "algebraic1-pre", TRUE);
    
    Algebraic.Transform(pb, ~enableLoopRewriting);
    DeadCodeElimination.Transform(pb);
    Write("algebraic1-post", "cse1-pre", TRUE);
    
    CSE.Transform(pb);
    DeadCodeElimination.Transform(pb);
    Write("cse1-post", "loop-pre", TRUE);

    IF enableLoopRewriting THEN
      LoopRewrite.Transform(pb);
      DeadCodeElimination.Transform(pb);
      Write("loop-post", "pared-pre", TRUE);
      
      PRE.Transform(pb);
      PRE.ResolveEquiv(pb);
      DeadCodeElimination.Transform(pb);
      Write("pared-post", "constprop2-pre", TRUE);
      
      ConstProp.Transform(pb);
      DeadCodeElimination.Transform(pb);
      Write("constprop2-post", "algebraic2-pre", TRUE);
      
      Algebraic.Transform(pb, TRUE);
      DeadCodeElimination.Transform(pb);
      Write("algebraic2-post", "cse2-pre", TRUE);
      
      CSE.Transform(pb);
      DeadCodeElimination.Transform(pb);
      Write("cse2-post", "final", TRUE);
    END;
    
    Fixup (pb, jmpbufMap);
    domRoot := Schedule.Schedule (pb);
    IF writeProc THEN
      IF (t. inspectStage. MatchChars ("schedule", 0, -1) # NIL) THEN
        (* write schedule SSA code to stdout *)
        TRY
          XML.WriteSchedule (StdChannels.stdout, domRoot);
        CATCH IO.Error:
        END;
        Out.Flush
      END;
    END;
    
    t. w. Indent (1);
    registerMap := Allocator.AssignRegisters (pb, domRoot, t. w);
    w := NewWriter (t, t. w, pb, registerMap, jmpbufMap);
    WriteLocalDecl (t, w, pb, jmpbufMap # NIL);
    WriteJmpBufDecl(jmpbufMap);
    IF proc.decl.IsModuleBody() THEN
      (* pick up any preloaded-var instructions in the module body, so that
         we can write them out at the beginning of the init function *)
      instr := pb.instrList;
      WHILE (instr # NIL) DO
        IF (instr.opcode = Opcode.preloadedVar) THEN
          dummy := GetPreloadId(t.preloadedVars, instr);
        END;
        instr := instr.nextInstr;
      END;
      
      InitPreloadedVars(t.preloadedVars);
    END;
    t. WriteNestedProcedures();          (* up call *)
    
    JumpChaining (domRoot);
    FixCrossJumps (domRoot);
    w. WriteLn;
    w. WriteBlocks (domRoot);
    w. Newline;
    (* add empty statement to avoid gcc's warning `deprecated use of
       label at end of compound statement'  *)
    w. WriteString (";");
    t. w. Indent (-1);

    pb.Destroy();                        (* cleanup for the sake of the gc *)
  END WriteProcBody;



PROCEDURE InitTranslator* (t: Translator; writeStats: BOOLEAN;
                           inspectProc, inspectStage: StringSearch.Matcher);
  BEGIN
    TranslateToC.InitTranslator (t);
    t. inspectProc := inspectProc;
    t. inspectStage := inspectStage;
    t. writeStats := writeStats;
    t. nonLocalAccess := NIL;
    t. preloadedVars := IntDict.New();
  END InitTranslator;

PROCEDURE NewTranslator* (writeStats: BOOLEAN;
                          inspectProc, inspectStage: StringSearch.Matcher): Translator;
  VAR
    t: Translator;
  BEGIN
    NEW (t);
    InitTranslator (t, writeStats, inspectProc, inspectStage);
    RETURN t
  END NewTranslator;

PROCEDURE (t: Translator) SetProcedureList* (procList: IR.ProcedureList);
  VAR
    v: Visitor;
    i: LONGINT;
  BEGIN
    t. SetProcedureList^ (procList);

    IF (procList # NIL) THEN
      v := NewVisitor();
      FOR i := 0 TO LEN (procList^)-1 DO
        procList[i]. Accept (v);
      END;
      t. nonLocalAccess := v. nonLocalAccess;
    END;
  END SetProcedureList;

END OOC:SSA:WriteC.
