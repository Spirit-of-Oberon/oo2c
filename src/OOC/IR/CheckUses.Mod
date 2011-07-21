(* 	$Id: CheckUses.Mod,v 1.25 2004/05/08 13:34:46 mva Exp $	 *)
MODULE OOC:IR:CheckUses;
(*  Warn about uninitialized variables and unreachable code, 
    Copyright (C) 2003, 2004  Michael van Acken, Stewart Greenhill

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
  Object, Object:Boxed, ADT:Dictionary, DictInt := ADT:Dictionary:IntValue,
  ADT:ArrayList, Config, Msg,
  OOC:Config:Pragmas, OOC:Config:StdPragmas,
  Sym := OOC:SymbolTable, TR := OOC:SymbolTable:TypeRules,
  OOC:SymbolTable:Predef,
  OOC:Error, OOC:Scanner:SymList, OOC:IR, OOC:IR:VisitAll;


(* Some notes on the dataflow analysis of this module:

   @itemize @bullet
   @item
   It tracks reads and writes to nonlocal variables and variable parameters.

   @item
   Calls to and between nested procedures are taken into account.

   @item
   For read and write operations on tracked variables, it is precise down to
   the level of statements and expressions.  That is, it can distinguish ``read
   before write'' and ``write before read'' situations.

   @item
   A structured variable, like a records and an array, is treated like an
   atomic variable.  The first assignment to one of its members is assumed to
   define the whole value, with the effect that all following reads are assumed
   to be valid.

   @item
   The algorithm distinguishes situations where no, all, or some paths leading
   to a read have a defined value.

   @item
   For heap objects, only writes are tracked.  The information is used to
   set @ofield{Sym.ProcDecl.nonlocalWrites}.
   @end itemize  *)
  
CONST
  undefined = 0;
  maybeUndefined = 1;
  defined = 2;
  
TYPE
  Def = POINTER TO DefDesc;
  DefDesc = RECORD
    (Object.ObjectDesc)
    class: DictInt.Dictionary;  (* of Sym.VarDecl or Sym.Type *)
    (* Set of variables that haven been seen at a given point in the
       statement sequence.  Each variables is classified as either
       @oconst{undefined}, @oconst{maybeUndefined}, or @oconst{defined}.  *)
    unreachable: BOOLEAN;
    (* If TRUE, then there is no path of control leading to this point.  *)
  END;

CONST
  doesNotRead = 0;
  doesRead = 1;
  (* At least one path through the procedure reads the value of the variable
     from before the procedure call.  *)
  
  doesNotWrite = 0;
  mayWrite = 1;
  (* Some, but not all, paths through the procedure write to the variable.  *)
  doesWrite = 2;
  (* All paths through the procedure write to the variable.  *)

  scaleR = 4;
  
TYPE
  ProcData = POINTER TO ProcDataDesc;
  ProcDataDesc = RECORD
    (Object.ObjectDesc)
    callers: ArrayList.ArrayList;  (* of Sym.ProcDecl *)
    (* List of known callers of this procedure.  *)
    inout: DictInt.Dictionary;  (* of Sym.VarDecl or Sym.Type *)
    (* Maps a variable to `w+scaleR*r', where `r' and `w' are one of the
       `xxxRead' and `xxxWrite' flags above.  Only nonlocal variables and
       variable parameters appear here.  If a variable is not in the
       dictionary, then this is equivalent to `doesNotRead' and `doesNotWrite'.  *)
    inWorklist: BOOLEAN;
    updatedInOut: BOOLEAN;
  END;
  
CONST
  read = 0;
  write = 1;
  writeMaybe = 2;
  passCollectWrites = 0;
  passAnalyzeCalls = 1;
  passEmitWarnings = 2;
  
TYPE
  Symbol = SymList.Symbol;
  Visitor = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (VisitAll.VisitorDesc)
    errList: Error.List;
    pragmaHistory: Pragmas.History;
    pass: SHORTINT;
    knownProcs: Dictionary.Dictionary;  (* of Sym.ProcDecl *)

    procExit: Def;
    localProc: Sym.ProcDecl;
    localProcData: ProcData;
    
    def: Def;
    mode: SHORTINT;  (* either `read', `write', or `writeMaybe' *)
  END;
  VisitorCalls = POINTER TO VisitorCallsDesc;
  VisitorCallsDesc = RECORD
    (VisitAll.VisitorDesc)
    localProc: Sym.ProcDecl;
    knownProcs: Dictionary.Dictionary;  (* of Sym.ProcDecl *)
  END;
  
CONST
  undefinedVar = 1;
  maybeUndefinedVar = 2;
  unreachableCode = 3;
  endOfFunction = 4;
  deadTypeTest = 5;
  calleeUndefinedvar = 6;

VAR
  any: Sym.Type;
  
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
    | calleeUndefinedvar:
      t := Error.warningPrefix+"Callee may read undefined variable `${name}'";
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE (v: VisitorCalls) VisitCall* (call: IR.Call);
  VAR
    obj: Object.Object;
    procDecl: Sym.Declaration;
  BEGIN
    v.VisitCall^(call);
    
    IF (call.design IS IR.ProcedureRef) &
       v.knownProcs.HasKey(call.design(IR.ProcedureRef).decl) THEN
      procDecl := call.design(IR.ProcedureRef).decl;
      obj := v.knownProcs.Get(procDecl);
      obj(ProcData).callers.Append(v.localProc);
    END;
  END VisitCall;

PROCEDURE KnownProcs(module: IR.Module): Dictionary.Dictionary;
(* Create set with all procedures local to the module.  These are the
   procedures that are considered for further analysis in the rest of this
   module.  *)
  VAR
    i: LONGINT;
    knownProcs: Dictionary.Dictionary;
    v: VisitorCalls;
    pd: ProcData;
  BEGIN
    knownProcs := Dictionary.New();
    
    FOR i := 0 TO LEN (module.procList^)-1 DO
      NEW(pd);
      pd.callers := ArrayList.New(4);
      pd.inout := DictInt.New();
      pd.inWorklist := TRUE;
      pd.updatedInOut := FALSE;
      knownProcs.Set(module.procList[i].decl, pd);
    END;

    NEW(v);
    VisitAll.InitVisitor(v);
    v.knownProcs := knownProcs;
    FOR i := 0 TO LEN (module.procList^)-1 DO
      v.localProc := module.procList[i].decl;
      module.procList[i].Accept(v);
    END;

    RETURN knownProcs;
  END KnownProcs;



PROCEDURE NewDef(): Def;
  VAR
    def: Def;
  BEGIN
    NEW(def);
    def.class := DictInt.New();
    def.unreachable := FALSE;
    RETURN def;
  END NewDef;

PROCEDURE (def: Def) Copy(): Def;
  VAR
    def2: Def;
  BEGIN
    NEW(def2);
    def2.class := def.class.Copy();
    def2.unreachable := def.unreachable;
    RETURN def2;
  END Copy;

PROCEDURE (def: Def) GetClass(var: Sym.Item): LONGINT;
  BEGIN
    IF def.class.HasKey(var) THEN
      RETURN def.class.Get(var);
    ELSE
      RETURN undefined;
    END;
  END GetClass;

PROCEDURE (def: Def) SetClass(var: Sym.Item; class: LONGINT);
  BEGIN
    def.class.Set(var, class);
  END SetClass;

PROCEDURE (def: Def) Merge(def2: Def);
  VAR
    k: Object.ObjectArrayPtr;
    v: Sym.Item;
    i: LONGINT;

  PROCEDURE Merge(a, b: LONGINT): LONGINT;
    BEGIN
      IF (a = b) & (a # maybeUndefined) THEN
        RETURN a;
      ELSE
        RETURN maybeUndefined;
      END;
    END Merge;
  
  BEGIN
    IF def.unreachable THEN
      def.class := def2.class.Copy();
      def.unreachable := def2.unreachable;
    ELSIF ~def2.unreachable THEN  (* & ~def.unreachable *)
      k := def.class.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        v := k[i](Sym.Item);
        def.SetClass(v, Merge(def.GetClass(v), def2.GetClass(v)));
      END;
      
      k := def2.class.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        v := k[i](Sym.Item);
        def.SetClass(v, Merge(def.GetClass(v), def2.GetClass(v)));
      END;
    (* ELSE: ~def.unreachable & def2.unreachable *)
    END;
  END Merge;

PROCEDURE (def: Def) Unreachable();
  BEGIN
    def.class.Clear();
    def.unreachable := TRUE;
  END Unreachable;

PROCEDURE NewUnreachableDef(): Def;
  VAR
    def: Def;
  BEGIN
    def := NewDef();
    def.Unreachable();
    RETURN def;
  END NewUnreachableDef;


PROCEDURE WarnSymE(errList: Error.List; pragmaHistory: Pragmas.History;
                   sym: Symbol; code: Error.Code): Error.Msg;
  VAR
    e: Error.Msg;
    value: Config.Variable;
  BEGIN
    value := pragmaHistory.GetValue(StdPragmas.warnings.name, sym.pos);
    IF value(Config.BooleanVar).boolean THEN
      e := Error.New(checkUsesContext, code);
      e.SetIntAttrib("pos", sym.pos);
      e.SetIntAttrib("line", sym.line);
      e.SetIntAttrib("column", sym.column);
      errList.Append (e);
      RETURN e;
    ELSE
      RETURN NIL;
    END;
  END WarnSymE;

PROCEDURE WarnSym(errList: Error.List; pragmaHistory: Pragmas.History;
                  sym: Symbol; code: Error.Code);
  VAR
    e: Error.Msg;
  BEGIN
    e := WarnSymE(errList, pragmaHistory, sym, code);
  END WarnSym;

PROCEDURE WarnSymV(v: Visitor; sym: Symbol; code: Error.Code;
                   varDecl: Sym.VarDecl);
  VAR
    e: Error.Msg;
  BEGIN
    e := WarnSymE(v.errList, v.pragmaHistory, sym, code);
    IF (e # NIL) & (varDecl # NIL) THEN
      e.SetStringAttrib("name", Msg.GetStringPtr(varDecl.name.str^));
    END;
  END WarnSymV;


PROCEDURE NonlocalVar(localProc: Sym.ProcDecl; varDecl: Sym.VarDecl): BOOLEAN;
(* TRUE iff `varDecl' is a VAR parameter or a variable outside of
   `localProc'.  *)
  VAR
    proc: Sym.ProcDecl;
  BEGIN
    IF varDecl.isVarParam THEN
      RETURN TRUE;
    ELSE
      proc := varDecl.Procedure();
      RETURN (proc # localProc);  (* proc=NIL for global variables *)
    END;
  END NonlocalVar;

PROCEDURE (pd: ProcData) SetReadFlag(varDecl: Sym.VarDecl; flag: LONGINT);
  VAR
    oldFlag, newFlag: LONGINT;
  BEGIN
    IF pd.inout.HasKey(varDecl) THEN
      oldFlag := pd.inout.Get(varDecl);
    ELSE
      oldFlag := doesNotWrite + doesNotRead*scaleR;
    END;
    newFlag := (oldFlag MOD scaleR)+flag*scaleR;
    
    IF (newFlag # oldFlag) THEN
      ASSERT(oldFlag < newFlag);
      pd.inout.Set(varDecl, newFlag);
      pd.updatedInOut := TRUE;
    END;
  END SetReadFlag;

PROCEDURE (pd: ProcData) SetWriteFlag(item: Sym.Item; flag: LONGINT);
  VAR
    oldFlag, newFlag: LONGINT;
  BEGIN
    IF pd.inout.HasKey(item) THEN
      oldFlag := pd.inout.Get(item);
    ELSE
      oldFlag := doesNotWrite + doesNotRead*scaleR;
    END;
    newFlag := (oldFlag DIV scaleR)*scaleR + flag;
    
    IF (newFlag # oldFlag) THEN
      ASSERT(oldFlag > newFlag);
      pd.inout.Set(item, newFlag);
      pd.updatedInOut := TRUE;
    END;
  END SetWriteFlag;


PROCEDURE EmitVarWarning(v: Visitor; varDecl: Sym.VarDecl;
                         sym: Symbol; contextCall: BOOLEAN);
  VAR
    class: LONGINT;

  PROCEDURE LocalVar(varDecl: Sym.VarDecl): BOOLEAN;
    BEGIN
      RETURN ~varDecl.isParameter &
          (varDecl.Procedure() = v.localProc);
    END LocalVar;
  
  BEGIN
    IF LocalVar(varDecl) THEN
      IF (v.mode = read) THEN
        class := v.def.GetClass(varDecl);
        CASE class OF
        | undefined:
          IF contextCall THEN
            WarnSymV(v, sym, calleeUndefinedvar, varDecl);
          ELSE
            WarnSymV(v, sym, undefinedVar, varDecl);
          END;
        | maybeUndefined:
          IF contextCall THEN
            WarnSymV(v, sym, calleeUndefinedvar, varDecl);
          ELSE
            WarnSymV(v, sym, maybeUndefinedVar, varDecl);
          END;
        | defined:
          (* ignore *)
        END;
      ELSIF (v.mode = write) THEN
        v.def.SetClass(varDecl, defined);
      ELSIF (v.def.GetClass(varDecl) # defined) THEN  (* v.mode=writeMaybe *)
        v.def.SetClass(varDecl, maybeUndefined);
      END;
    END;
  END EmitVarWarning;

PROCEDURE VisitVarDecl(v: Visitor; varDecl: Sym.VarDecl;
                       sym: Symbol; contextCall: BOOLEAN);
  VAR
    pb: Object.Object;
    class: LONGINT;
  BEGIN
    CASE v.pass OF
    | passCollectWrites:
      IF (v.mode >= write) & NonlocalVar(v.localProc, varDecl) THEN
        pb := v.knownProcs.Get(v.localProc);
        pb(ProcData).inout.Set(varDecl, doesWrite);
      END;

    | passAnalyzeCalls:
      IF NonlocalVar(v.localProc, varDecl) THEN
        IF (v.mode = read) THEN
          class := v.def.GetClass(varDecl);
          IF (class # defined) THEN
            v.localProcData.SetReadFlag(varDecl, doesRead);
          END;
        ELSIF (v.mode = write) THEN
          v.def.SetClass(varDecl, defined);
        ELSIF (v.def.GetClass(varDecl) # defined) THEN  (* v.mode=writeMaybe *)
          v.def.SetClass(varDecl, maybeUndefined);
        END;
      END;
      
    | passEmitWarnings:
      EmitVarWarning(v, varDecl, sym, contextCall);
    END;
  END VisitVarDecl;

PROCEDURE (v: Visitor) VisitVar* (var: IR.Var);
  BEGIN
    VisitVarDecl(v, var.decl(Sym.VarDecl), var.sym, FALSE);
  END VisitVar;

PROCEDURE (v: Visitor) VisitDeref* (deref: IR.Deref);
  VAR
    oldMode: SHORTINT;
    pb: Object.Object;
  BEGIN
    CASE v.pass OF
    | passCollectWrites:
      IF (v.mode >= write) THEN
        pb := v.knownProcs.Get(v.localProc);
        pb(ProcData).inout.Set(deref.type, doesWrite);
      END;

    | passAnalyzeCalls, passEmitWarnings:
      IF (v.mode = read) THEN
        deref.pointer.Accept(v);
      ELSE
        v.def.SetClass(deref.type, defined);
        oldMode := v.mode;
        v.mode := read;
        deref.pointer.Accept(v);
        v.mode := oldMode;
      END;
    END;
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
    i, class: LONGINT;
    oldMode: SHORTINT;
    inout, writeMaybeDict: DictInt.Dictionary;
    obj: Object.Object;
    design: IR.Expression;
    readList, writeList: ArrayList.ArrayList;
    k: Object.ObjectArrayPtr;
    callee: Sym.ProcDecl;
    varDecl: Sym.VarDecl;
    type: Sym.Type;
  BEGIN
    oldMode := v.mode;
    call.design.Accept(v);
    
    CASE v.pass OF
    | passCollectWrites:
      IF ~(call.design IS IR.ProcedureRef) OR
         call.design(IR.ProcedureRef).decl(Sym.ProcDecl).nonlocalWrites THEN
        v.localProcData.inout.Set(any, doesWrite);  (* assume worst *)
      END;
      
      FOR i := 0 TO LEN(call.arguments^)-1 DO
        IF (call.formalPars[i] # NIL) & call.formalPars[i].isVarParam THEN
          IF ~(call.arguments[i] IS IR.Const) THEN (* avoid NIL to VAR param *)
            v.mode := write;
            call.arguments[i](IR.Adr).design.Accept(v);
          END;
        ELSE
          v.mode := read;
          call.arguments[i].Accept(v);
        END;
      END;
        
    | passAnalyzeCalls, passEmitWarnings:
      IF (call.design IS IR.ProcedureRef) &
         v.knownProcs.HasKey(call.design(IR.ProcedureRef).decl) THEN
        callee := call.design(IR.ProcedureRef).decl(Sym.ProcDecl);
        obj := v.knownProcs.Get(call.design(IR.ProcedureRef).decl);
        inout := obj(ProcData).inout;
      ELSE
        IF ~(call.design IS IR.ProcedureRef) OR
           call.design(IR.ProcedureRef).decl(Sym.ProcDecl).nonlocalWrites THEN
          v.def.SetClass(any, defined);  (* can write anything *)
        END;
      
        callee := NIL;
        inout := NIL;
      END;
      
      readList := ArrayList.New(8);
      writeList := ArrayList.New(8);
      writeMaybeDict := DictInt.New();
      FOR i := 0 TO LEN(call.arguments^)-1 DO
        IF (call.formalPars[i] = NIL) THEN
          (* ignore *)
        ELSIF call.formalPars[i].isVarParam THEN
          IF ~(call.arguments[i] IS IR.Const) THEN (* avoid NIL to VAR param *)
            design := call.arguments[i](IR.Adr).design;
            IF (inout = NIL) THEN  (* no info on caller, assume write *)
              writeList.Append(design);
            ELSIF inout.HasKey(call.formalPars[i]) THEN
              class := inout.Get(call.formalPars[i]);
              CASE class DIV scaleR OF
              | doesRead:
                readList.Append(design);
              | doesNotRead:
                (* ignore *)
              END;
              
              CASE class MOD scaleR OF
              | doesWrite:
                writeList.Append(design);
              | mayWrite:
                writeMaybeDict.Set(design, 0);
                writeList.Append(design);
              | doesNotWrite:
                (* ignore *)
              END;
            END;
          END;
        ELSE
          readList.Append(call.arguments[i]);
        END;
      END;

      FOR i := 0 TO readList.size-1 DO
        v.mode := read;
        readList.array[i](IR.Expression).Accept(v);
      END;
      
      IF (inout # NIL) THEN
        k := inout.Keys();
        FOR i := 0 TO LEN(k^)-1 DO
          IF (k[i] IS Sym.VarDecl) THEN
            varDecl := k[i](Sym.VarDecl);
            IF (varDecl.Procedure() # callee) THEN
              class := inout.Get(varDecl);
              
              CASE class DIV scaleR OF
              | doesRead:
                v.mode := read;
                VisitVarDecl(v, varDecl, call.sym, TRUE);
              | doesNotRead:
                (* ignore *)
              END;
              
              CASE class MOD scaleR OF
              | doesWrite:
                v.mode := write;
                VisitVarDecl(v, varDecl, call.sym, TRUE);
              | mayWrite:
                v.mode := writeMaybe;
                VisitVarDecl(v, varDecl, call.sym, TRUE);
              | doesNotWrite:
                (* ignore *)
              END;
            END;
          ELSE  (* k[i] IS Sym.Type *)
            v.def.SetClass(k[i](Sym.Type), defined);
          END;
        END;
      END;
      
      FOR i := 0 TO writeList.size-1 DO
        IF writeMaybeDict.HasKey(writeList.array[i]) THEN
          v.mode := writeMaybe;
        ELSE
          v.mode := write;
        END;
        writeList.array[i](IR.Expression).Accept(v);
      END;
    END;
    
    v.mode := oldMode;
    type := call.design.type.Deparam();
    IF type(Sym.FormalPars).noReturn THEN
      v.def.Unreachable();
    END;
  END VisitCall;


PROCEDURE TransitiveWriteClosure(knownProcs: Dictionary.Dictionary;
                                 pd: ProcData);
  VAR
    i, j: LONGINT;
    k: Object.ObjectArrayPtr;
    pdCaller: ProcData;
    obj: Object.Object;
    callerDecl: Sym.ProcDecl;
  BEGIN
    k := pd.inout.Keys();
    FOR i := 0 TO LEN(k^)-1 DO
      FOR j := 0 TO pd.callers.size-1 DO
        callerDecl := pd.callers.array[j](Sym.ProcDecl);
        obj := knownProcs.Get(callerDecl);
        pdCaller := obj(ProcData);
        IF ~pdCaller.inout.HasKey(k[i]) &
           ((k[i] IS Sym.Type) OR
            NonlocalVar(callerDecl, k[i](Sym.VarDecl))) THEN
          pdCaller.inout.Set(k[i], doesWrite);
          TransitiveWriteClosure(knownProcs, pdCaller);
        END;
      END;
    END;
  END TransitiveWriteClosure;

PROCEDURE CheckUses*(module: IR.Module; moduleDecl: Sym.Module;
                     pragmaHistory: Pragmas.History; errList: Error.List);
  VAR
    i, inWorklist: LONGINT;
    def: Def;
    proc: IR.Procedure;
    v: Visitor;
    knownProcs, loopExits: Dictionary.Dictionary;
    pd: Object.Object;
    
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
        expr: IR.Expression;

      PROCEDURE CheckWith(defIn: Def; with: IR.WithStatm;
                          prevGuards: ArrayList.ArrayList);
        VAR
          def2, defOld: Def;
          localTest, test: IR.TypeTest;
        BEGIN
          localTest := with.guard(IR.TypeTest);
          FOR i := 0 TO prevGuards.size-1 DO
            test := prevGuards.array[i](IR.TypeTest);
            IF (test.expr(IR.Var).decl = localTest.expr(IR.Var).decl) &
               TR.IsExtensionOf(localTest.referenceType,
                                test.referenceType) &
               (v.pass = passEmitWarnings) THEN
              WarnSym(errList, pragmaHistory, localTest.sym, deadTypeTest);
            END;
          END;

          defOld := def;
          def := defIn;
          CheckExpr(with.guard);
          def := defOld;
          
          def2 := defIn.Copy();
          CheckStatmSeq(def2, with.pathTrue);
          def.Merge(def2);
          
          IF (with.pathFalse # NIL) THEN
            IF (LEN(with.pathFalse^) = 1) &
               (with.pathFalse[0] IS IR.WithStatm) THEN
              prevGuards.Append(with.guard(IR.TypeTest));
              CheckWith(defIn, with.pathFalse[0](IR.WithStatm), prevGuards);
            ELSE
              def2 := defIn.Copy();
              CheckStatmSeq(def2, with.pathFalse);
              def.Merge(def2);
            END;
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
          
        | statm: IR.IterateArrayStatm DO
          CheckExpr(statm.range);
          CheckDesign(statm.var, write);
          CheckStatmSeq(def, statm.body);
          
        | statm: IR.IterateObjectStatm DO
          CheckExpr(statm.iteratorFactory);
          CheckExpr(statm.stepperCall);
          CheckDesign(statm.var, write);
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
          defIn := NewUnreachableDef();
          loopExits.Set(statm, defIn);
          CheckStatmSeq(def, statm.body);
          def^ := defIn^;
          
        | statm: IR.Exit DO
          obj := loopExits.Get(statm.loop);
          obj(Def).Merge(def);
          def.Unreachable();
          
        | statm: IR.MoveBlock DO
          IF (v.pass = passCollectWrites) THEN
            v.localProcData.inout.Set(any, defined);  (* assume worst *)
          END;
          
          IF (statm.source IS IR.Adr) THEN
            CheckExpr(statm.source(IR.Adr).design);
          ELSE
            CheckExpr(statm.source);
          END;
          CheckExpr(statm.size);
          
          expr := statm.dest;
          IF (expr IS IR.TypeConv) THEN
            expr := expr(IR.TypeConv).expr;
          END;
          IF (expr IS IR.Adr) THEN
            CheckDesign(expr(IR.Adr).design, write);
          ELSE
            v.def.SetClass(any, defined);
            CheckExpr(statm.dest);
          END;
          
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
          v.procExit.Merge(def);
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
          defIn := def.Copy();
          def.Unreachable();
          CheckWith(defIn, statm, ArrayList.New(4));
        END;
      END CheckStatm;
    
    BEGIN
      IF (statmSeq # NIL) THEN
        i := 0;
        WHILE (i # LEN(statmSeq^)) & ~def.unreachable DO
          CheckStatm(statmSeq[i]);
          INC(i);
        END;
        IF (i # LEN(statmSeq^)) & (v.pass = passEmitWarnings) THEN
          WarnSym(errList, pragmaHistory, statmSeq[i].sym, unreachableCode);
        END;
      END;
    END CheckStatmSeq;
  
  PROCEDURE CheckedFunction(procDecl: Sym.ProcDecl): BOOLEAN;
    BEGIN
      RETURN (procDecl.formalPars.resultType # NIL) &
          ~procDecl.isAbstract;
    END CheckedFunction;

  PROCEDURE CallersToWorklist(callers: ArrayList.ArrayList);
    VAR
      i: LONGINT;
      pd: Object.Object;
    BEGIN
      FOR i := 0 TO callers.size-1 DO
        pd := knownProcs.Get(callers.array[i]);
        pd(ProcData).inWorklist := TRUE;
      END;
    END CallersToWorklist;

  PROCEDURE SetWriteFlags(localProc: Sym.ProcDecl; pd: ProcData; def: Def;
                          VAR nonlocalWrites: BOOLEAN);
    VAR
      k: Object.ObjectArrayPtr;
      i: LONGINT;
      item: Object.Object;
    BEGIN
      nonlocalWrites := FALSE;
            
      k := pd.inout.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        IF ~def.class.HasKey(k[i]) THEN  (* is undefined *)
          pd.SetWriteFlag(k[i](Sym.Item), doesNotWrite);
        END;
      END;
      
      k := def.class.Keys();
      FOR i := 0 TO LEN(k^)-1 DO
        item := k[i];
        WITH item: Sym.VarDecl DO
          IF NonlocalVar(localProc, item) THEN
            CASE def.class.Get(item) OF
            | undefined:
              pd.SetWriteFlag(item, doesNotWrite);
            | maybeUndefined:
              nonlocalWrites := TRUE;
              pd.SetWriteFlag(item, mayWrite);
            | defined:
              nonlocalWrites := TRUE;
              pd.SetWriteFlag(item, doesWrite);
            END;
          END;
        | item: Sym.Type DO
          nonlocalWrites := TRUE;
          IF (item # any) THEN
            (* For item=any (aka Predef.void), the assertion oldFlag>newFlag in
               SetWriteFlag() may fail.  I don't know if it the right action to
               simply skip it.  Given that `any' seems to be used as a target
               that is never read, and therefore might be complete redundant,
               this change should do no harm.  *)
            pd.SetWriteFlag(item, doesWrite);
          END;
        END;
      END;

      IF def.unreachable &                 (* no path to end of proc *)
         ~localProc.formalPars.noReturn &  (* not marked as NO_RETURN *)
         (~localProc.IsTypeBound() OR      (* normal procedure *)
          localProc.notRedefined) THEN 
        localProc.formalPars.noReturn := TRUE;
        pd.updatedInOut := TRUE;
      END;
    END SetWriteFlags;

(*  PROCEDURE DumpInOut();
    VAR
      i, j: LONGINT;
      procDecl: Sym.ProcDecl;
      pd: Object.Object;
      varDecl: Sym.VarDecl;
      inout: DictInt.Dictionary;
      k: Object.ObjectArrayPtr;
    BEGIN
      Log.Ln;
      
      k := knownProcs.Keys();
      FOR i := 0 TO knownProcs.Size()-1 DO
        pd := knownProcs.Get(k[i]);
        Log.String("Callee", k[i](Sym.ProcDecl).name.str^);
        FOR j := 0 TO pd(ProcData).callers.size-1 DO
          Log.String("  caller", pd(ProcData).callers.array[j](Sym.ProcDecl).name.str^);
        END;
      END;
      
      FOR i := 0 TO LEN (module.procList^)-1 DO
        procDecl := module.procList[i].decl;
        pd := knownProcs.Get(procDecl);
        inout := pd(ProcData).inout;
        Log.String("PROCEDURE", procDecl.name.str^);

        k := inout.Keys();
        FOR j := 0 TO LEN(k^)-1 DO
          varDecl := k[j](Sym.VarDecl);
          Log.String("var", varDecl.name.str^);
          CASE inout.Get(varDecl) DIV scaleR OF
          | doesRead: Err.String("  read: yes");
          | doesNotRead: Err.String("  read: no");
          END;
          Err.Ln;
          CASE inout.Get(varDecl) MOD scaleR OF
          | doesWrite: Err.String("  write: yes");
          | doesNotWrite: Err.String("  write: no");
          | mayWrite: Err.String("  write: maybe");
          END;
          Err.Ln;
        END;
      END;
    END DumpInOut;*)
  
  BEGIN
    IF (moduleDecl.class # Sym.mcStandard) THEN
      RETURN;  (* nothing to check *)
    END;
    
    knownProcs := KnownProcs(module);
    
    NEW(v);
    VisitAll.InitVisitor(v);
    v.errList := errList;
    v.pragmaHistory := pragmaHistory;
    v.def := NIL;
    v.knownProcs := knownProcs;
    loopExits := Dictionary.New();

    (* first pass: assume that every assignment and every designator passed
       to a VAR parameter means that the variable in question is a `doesWrite'
       classification; propagate this classification to all callers *)
    v.pass := passCollectWrites;
    FOR i := 0 TO LEN (module.procList^)-1 DO
      proc := module.procList[i];
      v.localProc := proc.decl;
      pd := knownProcs.Get(v.localProc);
      v.localProcData := pd(ProcData);
      v.procExit := NewUnreachableDef();
      
      CheckStatmSeq(NewDef(), proc.statmSeq);
      TransitiveWriteClosure(knownProcs, pd(ProcData));
    END;
    
    (* second pass: fine tune write classifications by reducing them to
       `mayWrite' or `noWrite' where appropriate; add read classifications *)
    v.pass := passAnalyzeCalls;
    REPEAT
      inWorklist := 0;
      FOR i := 0 TO LEN (module.procList^)-1 DO
        proc := module.procList[i];
        pd := knownProcs.Get(proc.decl);
        IF pd(ProcData).inWorklist THEN
          v.localProc := proc.decl;
          v.localProcData := pd(ProcData);
          v.localProcData.updatedInOut := FALSE;
          v.procExit := NewUnreachableDef();

          def := NewDef();
          CheckStatmSeq(def, proc.statmSeq);
          v.procExit.Merge(def);
          SetWriteFlags(v.localProc, v.localProcData, v.procExit,
                        proc.decl.nonlocalWrites);
          
          IF v.localProcData.updatedInOut THEN
            CallersToWorklist(pd(ProcData).callers);
            INC(inWorklist);
          END;
        END;
      END;
    UNTIL (inWorklist = 0);
    (*DumpInOut();*)
    
    (* final pass: emit warnings *)
    v.pass := passEmitWarnings;
    FOR i := 0 TO LEN (module.procList^)-1 DO
      proc := module.procList[i];
      v.localProc := proc.decl;
      v.procExit := NewUnreachableDef();
      IF (proc.endOfProc # NIL) THEN
        def := NewDef();
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
  any := Predef.GetType(Predef.void);
END OOC:IR:CheckUses.
