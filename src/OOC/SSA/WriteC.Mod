(* 	$Id$	 *)
MODULE OOC:SSA:WriteC [OOC_EXTENSIONS];
(*  Translates a set of scheduled SSA instructions to plain C.
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
  IntStr, Out, StdChannels, Strings, StringSearch,
  ADT:Object, ADT:String, ADT:Dictionary, 
  LString := Language:String, Sym := OOC:SymbolTable,
  TR := OOC:SymbolTable:TypeRules, OOC:SymbolTable:Predef,
  OOC:IR, OOC:IR:VisitAll, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA, OOC:SSA:IRtoSSA, OOC:SSA:Schedule, OOC:SSA:XML, OOC:SSA:Inspector,
  OOC:SSA:DeadCodeElimination, OOC:SSA:Destore, OOC:SSA:Allocator,
  OOC:C:ConvertDecl, OOC:C:Naming, OOC:C:DeclWriter, 
  OOC:Make:Command:TranslateToC;


TYPE
  RegisterSwap = RECORD
    source, dest: String.String;
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
    nonLocalAccess: Dictionary.Dictionary; (* of Sym.VarDecl *)
    (* The keys of this dictionary are variables that are accessed from
       a nested procedure within the procedure in which they are declared.  *)
  END;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc = RECORD
    (DeclWriter.WriterDesc)
    registerMap: Dictionary.Dictionary;
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
    CASE res. subclass OF
    | Opcode.scNone: RETURN DeclWriter.void
    | Opcode.scAddress: RETURN DeclWriter.int32(*DeclWriter.ptr*)
    | Opcode.scUnsigned8: RETURN DeclWriter.uint8
    | Opcode.scUnsigned16: RETURN DeclWriter.uint16
    | Opcode.scUnsigned32: RETURN DeclWriter.uint32
    | Opcode.scUnsigned64: RETURN DeclWriter.uint64
    | Opcode.scSigned8: RETURN DeclWriter.int8
    | Opcode.scSigned16: RETURN DeclWriter.int16
    | Opcode.scSigned32: RETURN DeclWriter.int32
    | Opcode.scSigned64: RETURN DeclWriter.int64
    END;
  END SubclassToBasicType;


PROCEDURE NewWriter (cWriter: DeclWriter.Writer;
                     procBlock: SSA.ProcBlock;
                     registerMap: Dictionary.Dictionary): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    cWriter. CopyTo (w);
    w. procBlock := procBlock;
    w. registerMap := registerMap;
    NEW (w. swapArray, 8);
    w. lengthSwapArray := 0;
    w. swapHelperVars := 0;
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) ClearSwapData;
  BEGIN
    w. lengthSwapArray := 0;
    w. swapHelperVars := 0;
  END ClearSwapData;

PROCEDURE (w: Writer) AddSwapData (source, dest: String.String;
                                   ctype: DeclWriter.BasicTypeId);
  VAR
    new: SwapArray;
    i: LONGINT;
  BEGIN
    IF (source. array^ # dest. array^) THEN (* suppress things like `i0=i0;' *)
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
        IF (w. swapArray[j]. source. array^=w. swapArray[i]. dest. array^) THEN
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
      IF (w. swapArray[j]. dest. array^=w. swapArray[i]. source. array^) THEN
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
    h: String.String;
  BEGIN
    ASSERT (w. swapArray[i]. readCount # 0);
    IntStr.IntToStr (w. swapHelperVars, str);
    Strings.Insert ("h", 0, str);
    h := String.New (str);
    INC (w. swapHelperVars);
    
    FOR j := 0 TO w. lengthSwapArray-1 DO
      IF (w. swapArray[j]. source. array^=w. swapArray[i]. dest. array^) THEN
        w. swapArray[j]. source := h;
      END;
    END;
    w. swapArray[i]. readCount := 0;

    w. WriteString ("{register ");
    w. WriteString (w. basicType[Allocator.RegisterType (w. swapArray[i]. ctype)]. repr);
    w. WriteString (" ");
    w. WriteString (h. array^);
    w. WriteChar ("=");
    w. WriteString (w. swapArray[i]. dest. array^);
    w. WriteChar (";");
  END IntroduceHelperVar;

PROCEDURE (w: Writer) FixupHelperVars;
  BEGIN
    WHILE (w. swapHelperVars # 0) DO
      w. WriteChar ("}");
      DEC (w. swapHelperVars)
    END;
  END FixupHelperVars;

PROCEDURE Fixup (pb: SSA.ProcBlock);
  VAR
    instr: SSA.Instr;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
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
      ELSE (* nothing to do *)
      END;
      instr := instr. nextInstr
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



PROCEDURE WriteLocalDecl (t: Translator; w: Writer;
                          pb: SSA.ProcBlock; VAR haveCopyParameter: BOOLEAN);
(**Writes local declarations of the procedure, most of all local variables.  *)
  VAR
    declMap: Dictionary.Dictionary;
    instr: SSA.Instr;
    decl: Sym.VarDecl;
    cDecl: DeclWriter.Declaration;
    item: Sym.Item;
    
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
    haveCopyParameter := FALSE;
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
            cDecl := ConvertDecl.GetPointerDecl (w, decl);
            haveCopyParameter := TRUE
          ELSIF ~decl. isParameter THEN
            cDecl := ConvertDecl.GetDecl (w, decl);
          ELSE
            cDecl := NIL;
          END;

          IF (cDecl # NIL) THEN
            w. Newline;
            w. WriteDeclaration (cDecl);
            w. WriteChar (";");
            declMap. Set (decl, NIL)
          END;
        END;
      END;
      instr := instr. nextInstr
    END;

    (* pick up any additional variable declarations that are not touch
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
    
    IF haveCopyParameter THEN
      w. Newline;
      w. WriteString ("OOC_PUSH_VPAR_STACK");
    END;
  END WriteLocalDecl;


PROCEDURE ^ (w: Writer) Ref (opnd: SSA.Opnd);

PROCEDURE (w: Writer) LengthExpr (instr: SSA.Instr);
  VAR
    design: SSA.Result;
    name: String.String;
  BEGIN
    design := instr. GetArgClass (Opnd.readDesign);
    WITH design: SSA.DeclRef DO        (* length parameter *)
      name := Naming.NameOfLengthParam
          (design. decl(Sym.VarDecl), instr. opndList. GetIntConst());
      w. WriteString (name. array^);
      
    ELSE                               (* length from type tag *)
      w. WriteString ("OOC_ARRAY_LENGTH(");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteString (", ");
      w. Ref (instr. opndList);
      w. WriteString (")");
    END;
  END LengthExpr;

PROCEDURE (w: Writer) Ref (opnd: SSA.Opnd);
  VAR
    arg: SSA.Result;
    obj: Object.Object;
    name: String.String;
    instr: SSA.Instr;
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
      w. WriteString (name. array^)

    | arg: SSA.Const DO
      (* write constant values directly, without going through an
         intermediate register; the roundabout route is kind of unnatural
         for C code *)
      w. WriteConst (arg. value, arg. type);

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
      w. WriteString (name. array^);
      
    ELSE
      instr := opnd. arg. instr;
      IF w. registerMap. HasKey (opnd. arg) THEN
        obj := w. registerMap. Get (opnd. arg);
        w. WriteString (obj(String.String). array^);

      ELSIF (instr. opcode = Opcode.getLength) THEN
        w. LengthExpr (instr);
        
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


PROCEDURE (w: Writer) WriteInstrList (b: Schedule.Block;
                                      haveCopyParameter: BOOLEAN);
  VAR
    proxy: Schedule.InstrProxy;
    instr: SSA.Instr;
    opnd: SSA.Opnd;
    target: Object.Object;
    str: ARRAY 32 OF CHAR;
    var: SSA.Result;

  PROCEDURE ^ Call (call: SSA.Instr);
    
  PROCEDURE CastToPtr (var: SSA.Result; type: Sym.Type;
                       passByReference: BOOLEAN);
    VAR
      name: String.String;
    BEGIN
      IF (var. instr. opcode = Opcode.typeTag) THEN
        w. WriteString ("(RT0__Struct)");
      ELSIF (type IS Sym.Pointer) OR
            (type IS Sym.FormalPars) OR
            passByReference OR
            TR.IsPredefType (type, Predef.ptr) THEN
        IF (var IS SSA.Const) &
           (var(SSA.Const). value # NIL) &
           (var(SSA.Const). value IS LString.Value) THEN
          (* omit cast on string constant *)
        ELSIF passByReference OR
              (type. namingDecl = NIL) OR
              TR.IsPredefType (type, Predef.ptr) THEN
          w. WriteString ("(void*)");
        ELSE
          name := Naming.NameOfType (type);
          w. WriteString ("(");
          w. WriteString (name. array^);
          w. WriteString (")");
        END;
      END;
    END CastToPtr;
  
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
            CastToPtr (opnd. arg,
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
      w. WriteString (");")
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
      w. WriteString (");")
    END CheckIndex;

  PROCEDURE CheckPointer (checkPointer: SSA.Instr);
    BEGIN
      w. WriteString ("_check_pointer(");
      w. Ref (checkPointer. opndList. nextOpnd);
      w. WriteString (", ");
      w. WriteLInt (checkPointer. pos, 0);
      w. WriteString (");")
    END CheckPointer;

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
      w. WriteString (");");
    END FailedCheck;
  
  PROCEDURE Call (call: SSA.Instr);
    VAR
      adr: SSA.Instr;
      decl: Sym.Declaration;
      name: String.String;
      procType: Sym.FormalPars;
    BEGIN
      IF (call. opndList. arg. instr. opcode = Opcode.tbProcAddress) THEN
        (* calling type bound procedure: cast procedure address *)
        adr := call. opndList. arg. instr;
        decl := adr. opndList. nextOpnd. arg. instr(SSA.DeclRef). decl;
        w. WriteString ("OOC_TBCALL(");
        w. Ref (call. opndList);
        w. WriteChar (",");
        name := Naming.NameOfDeclaration (decl);
        w. WriteString (name. array^);
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
      w. WriteChar (";");
    END WriteDyadicOp;
  
  PROCEDURE WriteDyadicFct (instr: SSA.Instr; fct: ARRAY OF CHAR);
    BEGIN
      w. WriteString (fct);
      w. WriteChar ("(");
      w. Ref (instr. opndList);
      w. WriteChar (",");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteString (");");
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
      name: String.String;
      opnd: SSA.Opnd;
    BEGIN
      CastFromPtr (instr);
      w. WriteString ("RT0__NewObject(");
      opnd := instr. GetOpndClass (Opnd.type);
      name := Naming.NameOfTypeDescriptor (opnd. arg(SSA.TypeRef). type);
      w. WriteString (name. array^);
      w. WriteString (".baseTypes[0]");

      opnd := opnd. nextOpnd;
      WHILE (opnd # NIL) & (opnd. class = Opnd.arg) DO
        w. WriteString (", ");
        w. Ref (opnd);
        opnd := opnd. nextOpnd;
      END;
      w. WriteString (");");
    END NewObject;
  
  PROCEDURE TypeCast (instr: SSA.Instr);
    VAR
      destType, sourceType: Opcode.Subclass;
    BEGIN
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
      w. WriteString (");");
    END TypeCast;

  PROCEDURE TypeTag (instr: SSA.Instr);
    VAR
      name: String.String;
    BEGIN
      CastFromPtr (instr);
      IF (instr. opndList. arg IS SSA.DeclRef) THEN
        name := Naming.NameOfTypeTagParam (instr. opndList. arg(SSA.DeclRef). decl(Sym.VarDecl));
        w. WriteString (name. array^);
      ELSIF (instr. opndList. arg IS SSA.TypeRef) THEN
        w. WriteChar ("&");
        name := Naming.NameOfTypeDescriptor (instr. opndList. arg(SSA.TypeRef). type);
        w. WriteString (name. array^);
      ELSE
        w. WriteString ("OOC_TYPE_TAG(");
        w. Ref (instr. opndList);
        w. WriteChar (")");
      END;
      w. WriteChar (";");
    END TypeTag;
  
  PROCEDURE TypeTest (instr: SSA.Instr);
    VAR
      name: String.String;
      opnd: SSA.Opnd;
    BEGIN
      w. WriteString ("OOC_TYPE_TEST(");
      w. Ref (instr. opndList);
      w. WriteString (", &");
      opnd := instr. opndList. nextOpnd;
      name := Naming.NameOfTypeDescriptor (opnd. arg(SSA.TypeRef). type);
      w. WriteString (name. array^);
      w. WriteString (");");
    END TypeTest;

  PROCEDURE TBProcAddress (instr: SSA.Instr);
    VAR
      name: String.String;
    BEGIN
      CastFromPtr (instr);
      w. WriteString ("OOC_TBPROC_ADR(");
      w. Ref (instr. opndList);
      w. WriteString (", ");
      name := Naming.NameOfDeclaration (instr. opndList. nextOpnd. arg(SSA.DeclRef). decl);
      w. WriteString (name. array^);
      w. WriteString (");");
    END TBProcAddress;
  
  PROCEDURE CopyParameter (instr: SSA.Address);
    VAR
      varDecl: Sym.VarDecl;
      size: SSA.Opnd;
      name: String.String;

    PROCEDURE WriteTypeAndSize ();
      BEGIN
        w. WriteString (",");
        IF (varDecl. type IS Sym.Array) THEN
          w. TypeRef (varDecl. type(Sym.Array). GetNonOpenElementType());
        ELSE
          w. TypeRef (varDecl. type);
        END;
        w. WriteString (",");
        w. Ref (size);
        w. WriteString (")");
      END WriteTypeAndSize;
    
    BEGIN
      varDecl := instr. decl(Sym.VarDecl);
      size := instr. GetOpndClass (Opnd.arg);
      name := Naming.NameOfDeclaration (varDecl);
      
      w. Newline;
      w. WriteString ("OOC_ALLOCATE_VPAR(");
      w. WriteString (name. array^);
      WriteTypeAndSize;
      
      w. Newline;
      w. WriteString ("OOC_INITIALIZE_VPAR(");
      w. WriteString (name. array^);
      w. WriteString (Naming.suffixPassPerRef+",");
      w. WriteString (name. array^);
      WriteTypeAndSize
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
      w. WriteString (");");
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

      IF (source = Predef.char) & (dest = Predef.char) THEN
        w. WriteString ("_copy_8(");
      ELSIF (source = Predef.longchar) & (dest = Predef.longchar) THEN
        w. WriteString ("_copy_16(");
      ELSE (* (source = Predef.char) & (dest = Predef.longchar) *)
        w. WriteString ("_copy_8to16(");
      END;
      w. Ref (instr. GetOpndClass (Opnd.readAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.writeAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.arg));
      w. WriteString (");");
    END CopyString;
  
  PROCEDURE CmpString (instr: SSA.Instr);
    VAR
      source: LONGINT;
    BEGIN
      w. Newline;
      source := TypeId (instr. NthArg (1));

      IF (source = Predef.char) THEN
        w. WriteString ("_cmp8((const void*)");
      ELSE
        w. WriteString ("_cmp16((const void*)");
      END;
      opnd := instr. GetOpndClass (Opnd.readAdr);
      w. Ref (opnd);
      w. WriteString (",(const void*)");
      REPEAT                             (* locate second readAdr *)
        opnd := opnd. nextOpnd;
      UNTIL (opnd. class = Opnd.readAdr);
      w. Ref (opnd);
      w. WriteString (");");
    END CmpString;
  
  PROCEDURE MoveBlock (instr: SSA.Instr);
    BEGIN
      w. Newline;
      w. WriteString ("_move_block(");
      w. Ref (instr. GetOpndClass (Opnd.readAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.writeAdr));
      w. WriteChar (",");
      w. Ref (instr. GetOpndClass (Opnd.arg));
      w. WriteString (");");
    END MoveBlock;
  
  PROCEDURE Shift (instr: SSA.Instr);
    BEGIN
      w. WriteString ("_lsh(");
      w. WriteString (w. basicType[Allocator.SubclassToBasicType (instr. subclass)]. repr);
      w. WriteString (", ");
      w. Ref (instr. opndList);
      w. WriteString (", ");
      w. Ref (instr. opndList. nextOpnd);
      w. WriteString (");");
    END Shift;

  PROCEDURE AllPathsClosed (selectReturn: SSA.Instr): BOOLEAN;
  (* Returns TRUE if all paths into the "select-return" end with a
     "return" instruction.  *)
    VAR
      opnd: SSA.Opnd;
    BEGIN
      IF (selectReturn. opndList. nextOpnd. nextOpnd = NIL) THEN
        RETURN FALSE                     (* not at single RETURN in the proc *)
      ELSE
        opnd := selectReturn. opndList. nextOpnd;
        WHILE (opnd. nextOpnd # NIL) DO
          IF ~(opnd. arg. instr. opcode = Opcode.return) THEN
            RETURN FALSE
          END;
          opnd := opnd. nextOpnd;
        END;
        RETURN TRUE
      END
    END AllPathsClosed;
  
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
      WHILE (opnd # NIL) & (opnd. class # Opnd.loopExternalDef) DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF w. registerMap. HasKey (opnd. arg) THEN
            sourceVar := w. registerMap. Get (opnd. arg);
            w. AddSwapData (sourceVar(String.String),
                            targetVar(String.String),
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
          w. WriteString (w. swapArray[i]. dest. array^);
          w. WriteString ("=");
          w. WriteString (w. swapArray[i]. source. array^);
          w. WriteChar (";");
          w. RemoveSwapData (i)
        END;
      END;
      w. FixupHelperVars;
      
      (* final pass: write out anything that does not read from a register *)
      opnd := collect. opndList;
      res := targetInstr. nextResult;
      WHILE (opnd # NIL) & (opnd. class # Opnd.loopExternalDef) DO
        IF (opnd. class # Opnd.store) THEN
          targetVar := w. registerMap. Get (res);
          IF ~w. registerMap. HasKey (opnd. arg) THEN
            w. WriteString (targetVar(String.String). array^);
            w. WriteString ("=");
            w. Ref (opnd);
            w. WriteChar (";");
          END
        END;
        opnd := opnd. nextOpnd; res := res. nextResult
      END;
    END WriteCollect;

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

  PROCEDURE PrefixReturn ();
  (**Called before every "return" instruction.  *)
    BEGIN
      w. Newline;
      IF haveCopyParameter THEN
        w. WriteString ("OOC_POP_VPAR_STACK");
        w. Newline
      END;
    END PrefixReturn;
  
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
      
      IF w. registerMap. HasKey (instr) THEN
        w. Newline;
        target := w. registerMap. Get (instr);
        w. WriteString (target(String.String). array^);
        w. WriteString (" = ");
      END;
      
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

      | Opcode.collect:
        WriteCollect (instr, instr. GetCollectTarget());
        
      | Opcode.loopStart:
        (* nothing *)
        
      | Opcode.loopEnd:
        (* nothing *)

      | Opcode.exit:
        (* nothing, the immediately following jump does all the work *)

      | Opcode.selectExit:
        (* nothing *)
        
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
        w. WriteChar (";");
        
      | Opcode.set:
        w. Newline;
        IF SimpleVarAccess (instr, Opnd.writeAdr) THEN
          w. Ref (instr. GetOpndClass (Opnd.writeDesign));
          var := instr. GetArgClass (Opnd.writeDesign);
          w. WriteString (" = ");
          CastToPtr (var, var(SSA.DeclRef). decl(Sym.VarDecl). type, FALSE);
        ELSE
          w. WriteString ("*(");
          w. WriteString (w. basicType
                          [SubclassToBasicType (instr)]. repr);
          w. WriteString ("*)");
          w. Ref (instr. opndList. nextOpnd);
          w. WriteString (" = ");
        END;
        w. Ref (instr. GetOpndClass (Opnd.sourceValue));
        w. WriteChar (";");

      | Opcode.copy:
        Copy (instr);
      | Opcode.copyString:
        CopyString (instr);
      | Opcode.cmpString:
        CmpString (instr);
      | Opcode.moveBlock:
        MoveBlock (instr);
        
      | Opcode.getLength:
        IF ~instr. IsConst() THEN
          (* don't write statement for length of open array parameter *)
          w. LengthExpr (instr);
          w. WriteChar (";");
        END;
        
      | Opcode.copyParameter:
        CopyParameter (instr(SSA.Address));

      | Opcode.newObject:
        NewObject (instr);
      | Opcode.typeTag:
        TypeTag (instr);
      | Opcode.typeTest:
        TypeTest (instr);
      | Opcode.tbProcAddress:
        TBProcAddress (instr);

      | Opcode.typeCast:
        TypeCast (instr);
      | Opcode.typeConv:
        w. Ref (instr. opndList);
        w. WriteChar (";");
        
      | Opcode.add:
        WriteDyadicOp (instr, "+");
      | Opcode.subtract:
        WriteDyadicOp (instr, "-");
      | Opcode.negate:
        WriteMonadicOp (instr, "-", ";");
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
        WriteMonadicOp (instr, "!", ";");
      | Opcode.logicalAnd:
        WriteDyadicOp (instr, "&");
      | Opcode.logicalOr:
        WriteDyadicOp (instr, "|");
      | Opcode.logicalXor:
        WriteDyadicOp (instr, "^");
      | Opcode.logicalComplement:
        WriteMonadicOp (instr, "!", ";");
      | Opcode.setBit:
        WriteDyadicFct (instr, "_set_bit");
      | Opcode.clearBit:
        WriteDyadicFct (instr, "_clear_bit");
        
      | Opcode.setMember:
        WriteDyadicFct (instr, "_in");
      | Opcode.setRange:
        WriteDyadicFct (instr, "_bit_range");
      | Opcode.abs:
        WriteMonadicOp (instr, "_abs(", ");");
      | Opcode.ash:
        WriteDyadicFct (instr, "_ash");
      | Opcode.cap:
        WriteMonadicOp (instr, "_cap(", ");");
      | Opcode.entier:
        WriteMonadicOp (instr, "_entier(", ");");
      | Opcode.lsh:
        Shift (instr);
      | Opcode.odd:
        WriteMonadicOp (instr, "_odd(", ");");
        
      | Opcode.eql:
        WriteDyadicOp (instr, "==");
      | Opcode.neq:
        WriteDyadicOp (instr, "!=");
      | Opcode.lss:
        WriteDyadicOp (instr, "<");
      | Opcode.leq:
        WriteDyadicOp (instr, "<=");
      | Opcode.gtr:
        WriteDyadicOp (instr, ">");
      | Opcode.geq:
        WriteDyadicOp (instr, ">=");
        
      | Opcode.assert:
        Assert (instr);
      | Opcode.halt:
        w. Newline;
        w. WriteString ("_halt(");
        w. Ref (instr. opndList. nextOpnd);
        w. WriteString (");")
      | Opcode.checkIndex:
        CheckIndex (instr);
      | Opcode.checkPointer:
        CheckPointer (instr);
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
        w. WriteChar (";");
            
      | Opcode.return:
        PrefixReturn;
        opnd := instr. GetOpndClass (Opnd.functionResult);
        IF (opnd # NIL) THEN
          w. WriteString ("return ");
          CastToPtr (opnd. arg, w. procBlock. procDecl. formalPars. resultType, FALSE);
          w. Ref (opnd);
          w. WriteChar (";");
        ELSE
          w. WriteString ("return;")
        END;
        
      | Opcode.selectReturn:
        IF ~AllPathsClosed (instr) THEN
          PrefixReturn;
          IF (w. procBlock. procDecl. formalPars. resultType # NIL) THEN
            IF w. procBlock. checkFunctionResult THEN
              w. WriteString ("_failed_function(");
              w. WriteLInt (w. procBlock. procDecl. name. pos, 0);
              w. WriteString ("); ");
            END;
            w. WriteString ("return 0;");
          ELSE
            w. WriteString ("return;")
          END;
        END;
      END;
      
      proxy := proxy. nextProxy
    END;
  END WriteInstrList;

PROCEDURE (w: Writer) WriteBlocks (domRoot: Schedule.Block;
                                   haveCopyParameter: BOOLEAN);
  VAR
    lastBlock: Schedule.Block;
    blockCount: LONGINT;
    blockMap: Dictionary.Dictionary;
    
  PROCEDURE AssignIds (b: Schedule.Block);
  (* assign block ids in the same order as they are written by `WriteBlock' *)
    VAR
      str: ARRAY 24 OF CHAR;
      obj: Object.Object;
      nested: Schedule.Block;
    BEGIN
      IntStr.IntToStr (blockCount, str);
      Strings.Insert ("l", 0, str);
      IF b. isLoopHead THEN
        Strings.Append ("_loop", str);
      END;
      obj := String.New (str);
      blockMap. Set (b, obj);
      INC (blockCount);
      
      nested := b. domList;
      WHILE (nested # NIL) DO
        AssignIds (nested);
        nested := nested. nextDom
      END;
    END AssignIds;
  
  PROCEDURE WriteBlockId (b: Schedule.Block);
    VAR
      obj: Object.Object;
    BEGIN
      IF (b = NIL) THEN
        w. WriteString ("XXX WriteBlockId(NIL)");
      ELSE
        obj := blockMap. Get (b);
        w. WriteString (obj(String.String). array^);
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
  
  PROCEDURE FixLastJump (currentBlock: Schedule.Block);
    VAR
      d: LONGINT;
      
    PROCEDURE WriteLabel (b: Schedule.Block);
      BEGIN
        w. WriteLn;
        WriteBlockId (b);
        w. WriteChar (":");
      END WriteLabel;
    
    BEGIN
      IF (lastBlock # NIL) &
         (lastBlock. DefaultTarget() # currentBlock) THEN
        w. Newline;
        WriteGoto (lastBlock. DefaultTarget());
        d := 0;
      ELSE
        d := 1
      END;
      IF (currentBlock # NIL) & (currentBlock. degreeIn > d) THEN
        WriteLabel (currentBlock)
      END;
    END FixLastJump;
  
  PROCEDURE WriteBlock (b: Schedule.Block);
    VAR
      i: LONGINT;
      nested: Schedule.Block;
      default: BOOLEAN;
      
    PROCEDURE WriteNested (nested: Schedule.Block);
      BEGIN
        WHILE (nested # NIL) DO
          WriteBlock (nested);
          nested := nested. nextDom
        END;
      END WriteNested;

    PROCEDURE WriteCases (instr: SSA.Instr): BOOLEAN;
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
          RETURN FALSE;
        ELSE
          w. Newline;
          w. WriteString ("default:");
          RETURN TRUE;
        END;
      END WriteCases;
    
    BEGIN
      IF (b. degreeIn # 0) THEN
        FixLastJump (b);
        w. WriteInstrList (b, haveCopyParameter);
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
          ELSE
            IF b. branchOnTrue THEN
              w. WriteChar("!");
            END;
            w. Ref (b. predicate);
            w. WriteString (") ");
            WriteGoto (b. jump. dest);
          END;
          lastBlock := b;
          WriteNested (b. domList);

        | b: Schedule.SwitchBlock DO
          w. Newline;
          w. WriteString ("switch (");
          w. Ref (b. expr);
          w. WriteString (") {");
          
          nested := b. domList; i := 0;
          WHILE (nested # NIL) & (i # LEN (b. jump^)) DO
            ASSERT (nested = b. jump[i]. dest);
            default := WriteCases (b. caseValues[i]. arg. instr);
            
            lastBlock := NIL;
            w. Indent (1);
            WriteBlock (b. jump[i]. dest);
            w. Newline;
            IF ~default THEN
              (*w. WriteString ("break;");*)
              WriteGoto (lastBlock(Schedule.JumpBlock). jump. dest);
            END;
            w. Indent (-1);
            nested := nested. nextDom; INC (i);
          END;
          w. Newline;
          w. WriteString ("}");
          lastBlock := NIL;
          WriteNested (nested);
          
        ELSE (* standard block *)
          lastBlock := b;
          WriteNested (b. domList);
        END;
      END;
    END WriteBlock;
  
  BEGIN
    blockCount := 0;
    blockMap := Dictionary.New();
    lastBlock := NIL;

    AssignIds (domRoot);
    WriteBlock (domRoot);
    FixLastJump (NIL)
  END WriteBlocks;

PROCEDURE (t: Translator) WriteProcBody* (proc: IR.Procedure);
  VAR
    pb: SSA.ProcBlock;
    enter: SSA.Instr;
    s: SSA.Result;
    domRoot: Schedule.Block;
    registerMap: Dictionary.Dictionary;
    w: Writer;
    haveCopyParameter, writeProc: BOOLEAN;

  PROCEDURE Write (pre, post: ARRAY OF CHAR);
    BEGIN
      IF writeProc &
         ((t. inspectStage. MatchChars (pre, 0, -1) # NIL) OR
          (t. inspectStage. MatchChars (post, 0, -1) # NIL)) THEN
        Out.String ("PROCEDURE ");
        Out.String (pb. procDecl. name. str^);
        Out.String ("/");
        Out.String (pre);
        Out.String ("/");
        Out.String (post);
        Out.String (":");
        Out.Ln;
        Out.Flush;
        XML.Write (StdChannels.stdout. NewWriter(), pb, TRUE);
        Out.Flush;
      END;
    END Write;
  
  BEGIN
    (*Log.String ("procedure",proc. decl. name. str^);*)
    pb := SSA.NewProcBlock (proc);
    writeProc := (t. inspectProc. MatchChars (proc. decl. name. str^, 0, -1) # NIL);
    enter := pb. selectReturn. opndList. arg. instr;
    s := IRtoSSA.StatmSeq (pb, enter. nextResult,
                           proc. statmSeq);
    pb. selectReturn. AddOpnd (s, Opnd.store);

    (*Blocker.Write (StdChannels.stdout, pb);*)
    
    (* code transformations *)
    Write ("initial", "dce-pre");
    DeadCodeElimination.Transform (pb);
    Write ("dce-post", "destore-pre");
    Destore.Transform (pb);
    Write ("destore-post", "dce-pre");
    DeadCodeElimination.Transform (pb);
    Write ("dce-post", "final");

    domRoot := Schedule.Schedule (pb);
    IF writeProc THEN
      IF (t. inspectStage. MatchChars ("schedule", 0, -1) # NIL) THEN
        (* write schedule SSA code to stdout *)
        XML.WriteSchedule (StdChannels.stdout. NewWriter(), domRoot);
        Out.Flush
      END;
      IF (t. inspectStage. MatchChars ("schedule-html", 0, -1) # NIL) THEN
        (* create a temporary web server displaying the SSA code *)
        Inspector.Show (proc, domRoot);
      END;
    END;
    
    Fixup (pb);
    t. w. Indent (1);
    registerMap := Allocator.AssignRegisters (pb, domRoot, t. w);
    w := NewWriter (t. w, pb, registerMap);
    WriteLocalDecl (t, w, pb, haveCopyParameter);
    t. WriteNestedProcedures();          (* up call *)
    w. WriteLn;
    w. WriteBlocks (domRoot, haveCopyParameter);
    t. w. Indent (-1);
  END WriteProcBody;



PROCEDURE InitTranslator* (t: Translator; 
                           inspectProc, inspectStage: StringSearch.Matcher);
  BEGIN
    TranslateToC.InitTranslator (t);
    t. inspectProc := inspectProc;
    t. inspectStage := inspectStage;
    t. nonLocalAccess := NIL;
  END InitTranslator;

PROCEDURE NewTranslator* (inspectProc, inspectStage: StringSearch.Matcher): Translator;
  VAR
    t: Translator;
  BEGIN
    NEW (t);
    InitTranslator (t, inspectProc, inspectStage);
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
