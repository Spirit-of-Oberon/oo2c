(* 	$Id$	 *)
MODULE OOC:IR:CheckUses;
(*  Warn about uninitialized variables and unreachable code, 
    Copyright (C) 2003  Michael van Acken, Stewart Greenhill

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
  Object, Object:Boxed, ADT:Dictionary, ADT:ArrayList,
  Config:Value, Config:Value:Boolean,
  OOC:Config:Pragmas, OOC:Config:Pragmas:StdPragmas,
  Sym := OOC:SymbolTable, TR := OOC:SymbolTable:TypeRules, OOC:Error,
  OOC:Scanner:Builder:BasicList, OOC:IR, OOC:IR:VisitAll;

(* Extensions:

   Detect if variables are set or read by calls to local procedures.

   With passing an argument to a VAR parameter, distinguish between IN,
   OUT, and IN/OUT parameters.  *)
  
TYPE
  Def = POINTER TO DefDesc;
  DefDesc = RECORD
    (Object.ObjectDesc)
    undefined: Dictionary.Dictionary;
    (* Set of variables that are undefined at a given point in the
       statement sequence.  *)
    maybeUndefined: Dictionary.Dictionary;
    (* Set of variables that are only defined on some of the paths leading
       to a given point in the statement sequence.  *)
    unreachable: BOOLEAN;
  END;

CONST
  read = 0;
  write = 1;

TYPE
  Symbol = BasicList.Symbol;
  Visitor = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (VisitAll.VisitorDesc)
    def: Def;
    errList: Error.List;
    pragmaHistory: Pragmas.History;
    mode: SHORTINT;  (* either `read' or `write' *)
  END;
  
CONST
  undefinedVar = 1;
  maybeUndefinedVar = 2;
  unreachableCode = 3;
  endOfFunction = 4;
  deadTypeTest = 5;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  checkUsesContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | undefinedVar:
      t := Error.warningPrefix+"Undefined variable"
    | maybeUndefinedVar:
      t := Error.warningPrefix+"Variable may be undefined"
    | unreachableCode:
      t := Error.warningPrefix+"Unreachable code"
    | endOfFunction:
      t := Error.warningPrefix+"Control may reach end of function procedure"
    | deadTypeTest:
      t := Error.warningPrefix+"Type test made unreachable by preceeding guard"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE NewDef(): Def;
  VAR
    def: Def;
  BEGIN
    NEW(def);
    def.maybeUndefined := Dictionary.New();
    def.undefined := Dictionary.New();
    def.unreachable := FALSE;
    RETURN def;
  END NewDef;

PROCEDURE (def: Def) Copy(): Def;
  VAR
    def2: Def;
  BEGIN
    NEW(def2);
    def2.maybeUndefined := def.maybeUndefined.Copy();
    def2.undefined := def.undefined.Copy();
    def2.unreachable := def.unreachable;
    RETURN def2;
  END Copy;

PROCEDURE (def: Def) Merge(def2: Def);
  VAR
    k: Object.ObjectArrayPtr;
    i: LONGINT;
  BEGIN
    IF def.unreachable THEN
      def^ := def2^;
    ELSIF ~def2.unreachable THEN
      k := def.undefined.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        IF ~def2.undefined.HasKey(k[i]) THEN
          def.undefined.Delete(k[i]);
          def.maybeUndefined.Set(k[i], NIL);
        END;
      END;
      
      k := def2.undefined.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        IF ~def.undefined.HasKey(k[i]) THEN
          def.maybeUndefined.Set(k[i], NIL);
        END;
      END;
      
      k := def2.maybeUndefined.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        def.maybeUndefined.Set(k[i], NIL);
      END;

      def.unreachable := def.unreachable & def2.unreachable;
    END;
  END Merge;

PROCEDURE (def: Def) Unreachable();
  BEGIN
    def.maybeUndefined.Clear();
    def.undefined.Clear();
    def.unreachable := TRUE;
  END Unreachable;



PROCEDURE WarnSym(errList: Error.List; pragmaHistory: Pragmas.History;
                  sym: Symbol; code: Error.Code);
  VAR
    e: Error.Msg;
    value: Value.Value;
  BEGIN
    value := pragmaHistory. GetValue (StdPragmas.warnings.name^, sym.pos);
    IF value(Boolean.Value).boolean THEN
      e := Error.New(checkUsesContext, code);
      e.SetIntAttrib("pos", sym.pos);
      e.SetIntAttrib("line", sym.line);
      e.SetIntAttrib("column", sym.column);
      errList.Append (e);
    END;
  END WarnSym;

PROCEDURE WarnSymV(v: Visitor;
                   sym: Symbol; code: Error.Code);
  BEGIN
    WarnSym(v.errList, v.pragmaHistory, sym, code);
  END WarnSymV;


PROCEDURE (v: Visitor) VisitVar* (var: IR.Var);
  BEGIN
    IF v.def.undefined.HasKey(var.decl) THEN
      IF (v.mode = read) THEN
        WarnSymV(v, var.sym, undefinedVar);
      ELSE
        v.def.undefined.Delete(var.decl);
      END;
    END;
    IF v.def.maybeUndefined.HasKey(var.decl) THEN
      IF (v.mode = read) THEN
        WarnSymV(v, var.sym, maybeUndefinedVar);
      ELSE
        v.def.maybeUndefined.Delete(var.decl);
      END;
    END;
  END VisitVar;

PROCEDURE (v: Visitor) VisitDeref* (deref: IR.Deref);
  VAR
    oldMode: SHORTINT;
  BEGIN
    oldMode := v.mode;
    v.mode := read;
    v.VisitDeref^(deref);
    v.mode := oldMode;
  END VisitDeref;

PROCEDURE (v: Visitor) VisitIndex* (index: IR.Index);
  VAR
    oldMode: SHORTINT;
  BEGIN
    oldMode := v.mode;
    index.array.Accept (v);
    v.mode := read;
    index.index.Accept (v);
    v.mode := oldMode;
  END VisitIndex;

PROCEDURE (v: Visitor) VisitAdr* (adr: IR.Adr);
  BEGIN
    (* ignore, this is neither a read nor a write *)
  END VisitAdr;

PROCEDURE (v: Visitor) VisitCall* (call: IR.Call);
  VAR
    i: LONGINT;
    oldMode: SHORTINT;
  BEGIN
    oldMode := v.mode;
    call.design.Accept(v);
    FOR i := 0 TO LEN(call.arguments^)-1 DO
      IF (call.formalPars[i] # NIL) & call.formalPars[i].isVarParam THEN
        v.mode := write;
        call.arguments[i](IR.Adr).design.Accept(v);
      ELSE
        v.mode := read;
        call.arguments[i].Accept(v);
      END;
    END;
    v.mode := oldMode;
    IF call.design.type(Sym.FormalPars).noReturn THEN
      v.def.Unreachable();
    END;
  END VisitCall;


PROCEDURE CheckUses*(module: IR.Module; pragmaHistory: Pragmas.History;
                     errList: Error.List);
  VAR
    i: LONGINT;
    def: Def;
    proc: IR.Procedure;
    v: Visitor;
    loopExits: Dictionary.Dictionary;
    
  PROCEDURE CheckStatmSeq(def: Def; statmSeq: IR.StatementSeq);
    VAR
      i: LONGINT;
      
    PROCEDURE CheckExpr(expr: IR.Expression);
      BEGIN
        v.def := def;
        v.mode := read;
        expr.Accept(v);
      END CheckExpr;
    
    PROCEDURE CheckDesign(design: IR.Expression; mode: SHORTINT);
      BEGIN
        v.def := def;
        v.mode := mode;
        design.Accept(v);
      END CheckDesign;
    
    PROCEDURE CheckStatm(statm: IR.Statement);
      VAR
        i: LONGINT;
        defIn, def2: Def;
        obj: Object.Object;

      PROCEDURE CheckWith(def: Def; with: IR.WithStatm;
                          prevGuards: ArrayList.ArrayList);
        VAR
          def2: Def;
          localTest, test: IR.TypeTest;
        BEGIN
          localTest := with.guard(IR.TypeTest);
          FOR i := 0 TO prevGuards.size-1 DO
            test := prevGuards.array[i](IR.TypeTest);
            IF (test.expr(IR.Var).decl = localTest.expr(IR.Var).decl) &
               TR.IsExtensionOf(localTest.referenceType,
                                test.referenceType) THEN
              WarnSym(errList, pragmaHistory, localTest.sym, deadTypeTest);
            END;
          END;
          
          CheckExpr(with.guard);
          def2 := def.Copy();
          CheckStatmSeq(def, with.pathTrue);
          IF (with.pathFalse # NIL) THEN
            IF (LEN(with.pathFalse^) = 1) &
               (with.pathFalse[0] IS IR.WithStatm) THEN
              prevGuards.Append(with.guard(IR.TypeTest));
              CheckWith(def2, with.pathFalse[0](IR.WithStatm), prevGuards);
            ELSE
              CheckStatmSeq(def2, with.pathFalse);
            END;
            def.Merge(def2);
          END;
        END CheckWith;
      
      BEGIN
        WITH statm: IR.Assert DO
          IF (statm.predicate = NIL) OR
             ((statm.predicate IS IR.Const) & 
              Boxed.false.Equals(statm.predicate(IR.Const).value)) THEN
            def.Unreachable();
          ELSE
            CheckExpr(statm.predicate);
          END;
          
        | statm: IR.AssignOp DO
          CheckExpr(statm.value);
          CheckExpr(statm.variable);
          CheckDesign(statm.variable, write);
          
        | statm: IR.Assignment DO
          CheckExpr(statm.value);
          CheckDesign(statm.variable, write);
          
        | statm: IR.Call DO
          CheckExpr(statm);
          
        | statm: IR.Copy DO
          CheckExpr(statm.source);
          CheckDesign(statm.dest, write);
          
        | statm: IR.CopyParameter DO
          (* ignore *)
          
        | statm: IR.CopyString DO
          CheckExpr(statm.source);
          CheckDesign(statm.dest, write);
          
        | statm: IR.ForStatm DO
          CheckExpr(statm.start);
          CheckExpr(statm.end);
          CheckDesign(statm.var, write);
          (* `step' is a constant and cannot be undefined *)
          CheckStatmSeq(def, statm.body);
          
        | statm: IR.IfStatm DO
          CheckExpr(statm.guard);
          def2 := def.Copy();
          CheckStatmSeq(def, statm.pathTrue);
          CheckStatmSeq(def2, statm.pathFalse);
          def.Merge(def2);
          
        | statm: IR.CaseStatm DO
          CheckExpr(statm.select);
          defIn := def.Copy();
          def.Unreachable();
          FOR i := 0 TO LEN(statm.caseList^)-1 DO
            def2 := defIn.Copy();
            CheckStatmSeq(def2, statm.caseList[i].statmSeq);
            def.Merge(def2);
          END;
          IF (statm.default # NIL) THEN
            def2 := defIn.Copy();
            CheckStatmSeq(def2, statm.default);
            def.Merge(def2);
          END;
          
        | statm: IR.LoopStatm DO
          defIn := NewDef();
          defIn.Unreachable();
          loopExits.Set(statm, defIn);
          CheckStatmSeq(def, statm.body);
          def^ := defIn^;
          
        | statm: IR.Exit DO
          obj := loopExits.Get(statm.loop);
          obj(Def).Merge(def);
          def.Unreachable();
          
        | statm: IR.MoveBlock DO
          CheckExpr(statm.source);
          CheckExpr(statm.dest);
          CheckExpr(statm.size);
          
        | statm: IR.Raise DO
          CheckExpr(statm.exception);
          def.Unreachable();
          
        | statm: IR.RepeatStatm DO
          CheckStatmSeq(def, statm.body);
          CheckExpr(statm.exitCondition);
          
        | statm: IR.Return DO
          IF (statm.result # NIL) THEN
            CheckExpr(statm.result);
          END;
          def.Unreachable();
          
        | statm: IR.TryStatm DO
          defIn := def.Copy();
          CheckStatmSeq(def, statm.statmSeq);
          FOR i := 0 TO LEN(statm.catchList^)-1 DO
            def2 := defIn.Copy();
            CheckStatmSeq(def2, statm.catchList[i].statmSeq);
            def.Merge(def2);
          END;
          
        | statm: IR.WhileStatm DO
          CheckExpr(statm.guard);
          CheckStatmSeq(def, statm.body);
          
        | statm: IR.WithStatm DO
          CheckWith(def, statm, ArrayList.New(4));
        END;
      END CheckStatm;
    
    BEGIN
      IF (statmSeq # NIL) THEN
        i := 0;
        WHILE (i # LEN(statmSeq^)) & ~def.unreachable DO
          CheckStatm(statmSeq[i]);
          INC(i);
        END;
        IF (i # LEN(statmSeq^)) THEN
          WarnSym(errList, pragmaHistory, statmSeq[i].sym, unreachableCode);
        END;
      END;
    END CheckStatmSeq;
  
  PROCEDURE CreateDef(procDecl: Sym.ProcDecl): Def;
    VAR
      decl: Sym.Item;
      def: Def;
    BEGIN
      def := NewDef();
      decl := procDecl.nestedItems;
      WHILE (decl # NIL) DO
        IF (decl IS Sym.VarDecl) & ~decl(Sym.VarDecl).isParameter THEN
          def.undefined.Set(decl, NIL);
        END;
        decl := decl.nextNested;
      END;
      RETURN def;
    END CreateDef;

  PROCEDURE CheckedFunction(procDecl: Sym.ProcDecl): BOOLEAN;
    BEGIN
      RETURN (procDecl.formalPars.resultType # NIL) &
          ~procDecl.isAbstract;
    END CheckedFunction;
  
  BEGIN
    NEW(v);
    VisitAll.InitVisitor(v);
    v.errList := errList;
    v.pragmaHistory := pragmaHistory;
    v.def := NIL;
    loopExits := Dictionary.New();

    FOR i := 0 TO LEN (module.procList^)-1 DO
      proc := module.procList[i];
      IF (proc.endOfProc # NIL) THEN
        def := CreateDef(proc.decl);
        CheckStatmSeq(def, proc.statmSeq);
        IF ~def.unreachable & CheckedFunction(proc.decl) THEN
          WarnSym(errList, pragmaHistory, proc.endOfProc, endOfFunction);
        END;
      END;
    END;
  END CheckUses;

BEGIN
  NEW (checkUsesContext);
  Error.InitContext (checkUsesContext, "OOC:IR:CheckUses");
END OOC:IR:CheckUses.
