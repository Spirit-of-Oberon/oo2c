(* 	$Id: Destore.Mod,v 1.68 2003/04/14 19:23:16 mva Exp $	 *)
MODULE OOC:SSA:Destore;
(*  Converts reads from/writes to memory into local values.
    Copyright (C) 2001-2003  Michael van Acken

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
  ADT:Dictionary, ADT:ArrayList,
  Sym := OOC:SymbolTable, OOC:SSA, OOC:SSA:Opcode,
  OOC:SSA:Opnd, OOC:SSA:Result, OOC:SSA:Aliasing;

  
(**

   The initial version of the SSA code, as produced by
   @omodule{*OOC:SSA:IRtoSSA}, converts all accesses to variables and
   designators into @oconst{Opcode.get} and @oconst{Opcode.set} instructions.
   These instructions correspond to memory accesses, and are therefore costly.
   They are also part of the @var{store} chain, which can limit the scheduling
   alternatives for these instructions.

   This module tries to remove @oconst{Opcode.get} and @oconst{Opcode.set}
   instructions as far as possible.  It performs four kinds of transformation
   on the SSA code of a procedure:

   @itemize @bullet
   @item
   A ``get'' instruction is replaced with the value that it produces, if that
   value is known.  This turns the instruction into dead code.

   @item
   A ``set'' instruction is removed if the value it is writing is never read by
   another instruction.

   @item
   To pass values to merging points of the control flow, ``collect''
   instructions are added or extended where required.

   @item
   If the paths leading into a ``select'' partially provide a value in memory,
   and partially provide it in registers, then ``get'' instructions are
   inserted so that all paths pass in register values.
   @end itemize


   The criteria that determine if such an instruction is required are for
   @oconst{Opcode.get}:

   @itemize @bullet
   @item
   A ``get'' must be kept if it reads a variable that has been defined before
   the current procedure has been entered.  There may be more than one ``get''
   for one and the same variable reading the input value, but this
   transformation makes no attempt to unify them.

   @item
   A ``get'' must remain after a function or procedure call that may write to
   the variable, be it in part or as a whole.  Such a call erases all local
   knowledge of the variable's content, which must be regained by doing an
   explicit memory read.
   @end itemize

   If it can be removed, a ``get'' is replaced with the value that it produces.
   In the simplest case, this is the value written by a directly preceding
   ``set''.


   Similarly, criteria for retaining a @oconst{Opcode.set} instruction are:

   @itemize @bullet
   @item
   A ``set'' must be kept if it writes a value to a variable is visible in part
   or whole after the current procedure is exited.  There may be more than one
   ``set'' for one and the same variable writing the ouput value, but this
   transformation makes no attempt to unify them.

   @item
   A ``set'' must remain before a function or procedure call that may read the
   written value from the variable.  Here, the ``set'' instruction creates an
   input value to the called procedure that is passed indirectly through
   memory.
   @end itemize

   A ``set'' is made obsolete by replacing all ``get'' instructions reading its
   source value from the variable with the source value itself.  *)


TYPE
  State* = POINTER TO StateDesc;
  StateDesc = RECORD
    pb: SSA.ProcBlock;
    localVarWithAdr: Dictionary.Dictionary;
  END;
  
TYPE
  CacheEntry = POINTER TO CacheEntryDesc;
  CacheEntryDesc = RECORD
    (SSA.NodeDesc)
    next: CacheEntry;
    design: SSA.Opnd;
    value: SSA.Result;
  END;
  
TYPE
  Worklist = POINTER TO WorklistDesc;
  WorklistDesc = RECORD
    next: Worklist;
    instr: SSA.Instr;
  END;

CONST
  read = 0;
  write = 1;

PROCEDURE IsLocalVariable (pb: SSA.ProcBlock; decl: Sym.Declaration): BOOLEAN;
  BEGIN
    RETURN (decl IS Sym.VarDecl) & (decl. Procedure() = pb. procDecl);
  END IsLocalVariable;

PROCEDURE InitState (VAR s: State; pb: SSA.ProcBlock);
  VAR
    localVarWithAdr: Dictionary.Dictionary;
    instr: SSA.Instr;
    
  PROCEDURE UsesAreVarAccess (res: SSA.Result): BOOLEAN;
    VAR
      use: SSA.Opnd;
    BEGIN
      use := res. useList;
      WHILE (use # NIL) DO
        IF (use. class # Opnd.readAdr) &
           (use. class # Opnd.writeAdr) &
           ~use. IsScheduleOpnd() THEN
          RETURN FALSE;
        END;
        use := use. nextUse;
      END;
      RETURN TRUE;
    END UsesAreVarAccess;
  
  BEGIN
    s. pb := pb;
    
    (* create a dictionary of all local variables whose address is taken
       somewhere in this procedure, and used within an instruction other than
       "get", "set", or "copy"  *)
    localVarWithAdr := Dictionary.New();
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr IS SSA.Address) &
         IsLocalVariable (pb, instr(SSA.Address). decl) &
         ~UsesAreVarAccess (instr) THEN
        localVarWithAdr. Set (instr(SSA.Address). decl, NIL);
      END;
      instr := instr. nextInstr;
    END;
    s. localVarWithAdr := localVarWithAdr;
  END InitState;

PROCEDURE New* (pb: SSA.ProcBlock): State;
  VAR
    s: State;
  BEGIN
    NEW (s);
    InitState (s, pb);
    RETURN s;
  END New;

PROCEDURE AccessedByCall (s: State;
                          calledAdr: SSA.Result; design: SSA.Opnd;
                          mode: SHORTINT): BOOLEAN;
(* Determine of the designator @oparam{design} is accessed by the called
   procedure @oparam{calledAdr}.  If yes, then return @code{TRUE}.

   The function implements this approximation: If the called procedure is
   nested into the current one, the result is always @code{TRUE}.  Otherwise,
   result is only @code{FALSE} if @oparam{design} refers to a local variable of
   the current procedure whose address is exclusively used as
   @oconst{Opnd.readAdr} or @oconst{Opnd.writeAdr} of a data read or write.
   This effectively covers local variables of scalar type that are not passed
   to a variable parameter, nor used in conjunction with @code{SYSTEM.ADR}.

   This function can be improved if more is known about the access patterns of
   the called procedure.

   @precond
   @ofield{design.class} is either @oconst{Opnd.readDesign} or
   @oconst{Opnd.writeDesign}.

   @oparam{mode} is either @oconst{read} or @oconsr{write}.
   @end precond  *)
  
  PROCEDURE LocalVarWithoutAdr (design: SSA.Opnd): BOOLEAN;
    BEGIN
      IF (design. arg IS SSA.DeclRef) &
         IsLocalVariable (s. pb, design. arg(SSA.DeclRef). decl) THEN
        RETURN ~s. localVarWithAdr. HasKey (design. arg(SSA.DeclRef). decl);
      ELSE
        RETURN FALSE;
      END;
    END LocalVarWithoutAdr;
  
  PROCEDURE NestedProc (calledAdr: SSA.Result; procDecl: Sym.ProcDecl): BOOLEAN;
    VAR
      proc: Sym.ProcDecl;
    BEGIN
      IF (calledAdr. instr. opcode = Opcode.address) THEN
        proc := calledAdr. instr(SSA.Address). decl(Sym.ProcDecl);
        REPEAT
          proc := proc. Procedure();
        UNTIL (proc = NIL) OR (proc = procDecl);
        RETURN (proc # NIL);
      ELSE
        (* this is either a type-bound procedure or a procedure variable;
           in either case, the called procedure is global and cannot be
           nested in this procedure *)
        RETURN FALSE;
      END;
    END NestedProc;

  PROCEDURE NonlocalWrites(calledAdr: SSA.Result): BOOLEAN;
    VAR
      proc: Sym.ProcDecl;
    BEGIN
      proc := calledAdr.CalledProc();
      IF (proc # NIL) THEN
        RETURN proc.nonlocalWrites;
      ELSE
        RETURN TRUE;  (* be pessimistic *)
      END;
    END NonlocalWrites;
  
  BEGIN
    IF (mode = write) & ~NonlocalWrites(calledAdr) THEN
      RETURN FALSE;
    ELSE
      RETURN NestedProc (calledAdr, s. pb. procDecl) OR
          ~LocalVarWithoutAdr (design);
    END;
  END AccessedByCall;

PROCEDURE (s: State) ClobberedBy* (readDesign: SSA.Opnd; instr: SSA.Instr): BOOLEAN;
(**Return @code{TRUE} if the value described by the read designator
   @oparam{readDesign} may be clobbered by the evaluation of the instruction
   @oparam{instr}.  *)
  VAR
    alias: Aliasing.Id;

  PROCEDURE ModuleVariable(adr: SSA.Result; moduleName: ARRAY OF CHAR): BOOLEAN;
    VAR
      module: Sym.Module;
    BEGIN
      WITH adr: SSA.Address DO
        module := adr.decl.Module();
        RETURN (adr.decl IS Sym.VarDecl) & (module.name.str^ = moduleName);
      ELSE
        RETURN FALSE;
      END;
    END ModuleVariable;
  
  BEGIN
    (* Note: This predicate must mirror the rules of Transform.GetValue *)

    CASE instr. opcode OF
    | Opcode.set, Opcode.copy, Opcode.copyString:
      alias := Aliasing.DesignatorAlias (readDesign,
                                         instr. GetOpndClass (Opnd.writeDesign));
      RETURN (alias # Aliasing.noAliasing);
      
    | Opcode.enter, Opcode.get, Opcode.select,
      Opcode.loopStart, Opcode.loopEnd,
      Opcode.collect, Opcode.newObject, Opcode.newBlock,
      Opcode.copyParameter, Opcode.exit, Opcode.return,
      Opcode.halt, Opcode.assert, Opcode.checkIndex, Opcode.checkPointer,
      Opcode.typeGuard, Opcode.failedTypeAssert,
      Opcode.failedWith, Opcode.failedCase, Opcode.raiseException,
      Opcode.tryStart, Opcode.tryEnd, Opcode.activateContext,
      Opcode.pushExceptionContext, Opcode.popExceptionContext:
      RETURN FALSE;
      
    | Opcode.call:
      RETURN AccessedByCall (s, instr. opndList. arg, readDesign, write);

    | Opcode.clearException:
      RETURN ModuleVariable(instr.opndList.arg, "Exception");
      
    | Opcode.moveBlock:
      RETURN TRUE;
    END;
  END ClobberedBy;

(*PROCEDURE ValidValue (msg: ARRAY OF CHAR; res: SSA.Result);
  BEGIN
    IF (res IS SSA.Instr) & (res(SSA.Instr).opcode = Opcode.select) THEN
      Log.String("Invalid argument value (select)", msg);
      ASSERT(FALSE);
    ELSIF (res IS SSA.Instr) & (res(SSA.Instr).opcode = Opcode.loopEnd) THEN
      Log.String("Invalid argument value (loopEnd)", msg);
      ASSERT(FALSE);
    END;
  END ValidValue;*)

PROCEDURE (s: State) Transform*;
  CONST
    notInWorklist = SSA.initMarker;
    inWorklist = notInWorklist+1;
  VAR
    pb: SSA.ProcBlock;
    instr, next: SSA.Instr;
    value: SSA.Result;
    use, nextUse, opnd: SSA.Opnd;
    worklist: Worklist;
    unknownList: ArrayList.ArrayList;
    i: LONGINT;

  PROCEDURE UnknownValue (res: SSA.Result): BOOLEAN;
    BEGIN
      RETURN (res. class = Result.store);
    END UnknownValue;
  
  PROCEDURE GetValue (store: SSA.Result; get: SSA.Instr): SSA.Result;
  (* Return the value from the @oparam{store} for the memory location (and
     type) designated by the instruction @oparam{get}.  If the value is not
     known, or if there is no single value, result is a SSA result of class
     @oconst{Result.store} from which the value can be retrieved.  Note: It is
     always safe to return the @var{store} argument of the @oparam{get}.  *)
    VAR
      alias: Aliasing.Id;
      instr: SSA.Instr;
      upstream: SSA.Result;

    PROCEDURE InCache (instr: SSA.Instr; VAR value: SSA.Result): BOOLEAN;
      VAR
        ptr: CacheEntry;
        readDesign, opnd1, opnd2: SSA.Opnd;
      BEGIN
        IF (instr. info # NIL) THEN
          ptr := instr. info(CacheEntry);
          readDesign := get. GetOpndClass (Opnd.readDesign);
          WHILE (ptr # NIL) DO
            opnd1 := readDesign; opnd2 := ptr. design;
            ASSERT (opnd1. class = Opnd.readDesign);
            ASSERT (opnd2. class = Opnd.readDesign);
            WHILE (opnd1 # NIL) & (opnd2 # NIL) &
                  (opnd1. arg = opnd2. arg) DO
              opnd1 := opnd1. nextOpnd; opnd2 := opnd2. nextOpnd;
            END;
            IF (opnd1 # NIL) & (opnd1. class = Opnd.readDesign) OR
               (opnd2 # NIL) & (opnd2. class = Opnd.readDesign) THEN
              (* the designator of the old computation `i' does not
                 match the one of the current "get" instruction *)
            ELSE
              value := ptr. value;
              RETURN TRUE;
            END;
            ptr := ptr. next
          END;
        END;
        value := NIL;  (* prevent warning *)
        RETURN FALSE;
      END InCache;
    
    PROCEDURE AddToCache (instr: SSA.Instr; value: SSA.Result): CacheEntry;
      VAR
        entry: CacheEntry;
      BEGIN
        NEW (entry);
        entry. design := get. GetOpndClass (Opnd.readDesign);
        entry. value := value;
        IF (instr. info = NIL) THEN
          entry. next := NIL;
        ELSE
          entry. next := instr. info(CacheEntry);
        END;
        instr. info := entry;
        RETURN entry
      END AddToCache;

    PROCEDURE InitialReplacement(dgate: SSA.Instr);
      BEGIN
        dgate.AddOpnd(dgate.AddResultSubclass(Result.dgatePlaceholder,
                                              dgate.subclass), Opnd.arg);
        (*dgate.AddOpnd(select.GetResultStore(), Opnd.arg);*)
      END InitialReplacement;
    
    PROCEDURE GetSelectValue (select: SSA.Instr): SSA.Result;
    (* Calculate the value of (store,get) for each of the paths leading
       into the select instruction.  *)
      VAR
        opnd: SSA.Opnd;
        res: SSA.Result;
        dgate: SSA.Instr;
        dummy: CacheEntry;
      BEGIN
        IF InCache (select, res) THEN
          (* a previous call to this function already computed the result
             for the designator of this "get": reuse it *)
          RETURN res;
        ELSE
          (* add a "dgate" instruction for the get's designator and determine
             for each incoming path the get's value *)
          dgate := pb.AddInstr(Opcode.dgate, get.subclass);
          dgate.AddOpnd(select, Opnd.dgateBase);
          InitialReplacement(dgate);
          dummy := AddToCache (select, dgate);
          
          CASE select. opcode OF
          | Opcode.select    : opnd := select. NthOpnd (2)
          | Opcode.loopEnd   : opnd := select. NthOpnd (2)
          END;
          WHILE (opnd # NIL) & ~opnd. IsScheduleOpnd() DO
            dgate.AddOpnd(GetValue(opnd. arg, get), Opnd.arg);
            opnd := opnd. nextOpnd;
            IF (select. opcode = Opcode.select) & (opnd # NIL) THEN
              opnd := opnd. nextOpnd;
            END;
          END;
          RETURN dgate;
        END;
      END GetSelectValue;

    PROCEDURE GetLoopValue (loopStart: SSA.Instr): SSA.Result;
      VAR
        res: SSA.Result;
        dummy: CacheEntry;
        dgate: SSA.Instr;
      BEGIN
        IF InCache (loopStart, res) THEN
          (* a previous call to this function already computed the result
             for the designator of this "get" *)
          RETURN res;
        ELSE
          (* add a "dgate" instruction for the get's designator and determine
             for incoming and backedge path the get's value *)
          dgate := pb.AddInstr(Opcode.dgate, get.subclass);
          dgate.AddOpnd(loopStart, Opnd.dgateBase);
          InitialReplacement(dgate);
          dummy := AddToCache (loopStart, dgate);

          dgate.AddOpnd(GetValue (loopStart.opndList.arg, get), Opnd.arg);
          dgate.AddOpnd(GetValue(loopStart.GetBackwardFeed(), get), Opnd.arg);
          RETURN dgate;
        END;
      END GetLoopValue;

    BEGIN
      instr := store. instr;
      CASE instr. opcode OF
      | Opcode.set:
        alias := Aliasing.DesignatorAlias (get. GetOpndClass (Opnd.readDesign),
                                           instr. GetOpndClass (Opnd.writeDesign));
        IF (alias = Aliasing.completelyCovered) THEN
          (* this "set" instruction defines the variable we are tracing *)
          RETURN instr. GetArgClass (Opnd.sourceValue)
        ELSIF (alias # Aliasing.noAliasing) THEN
          (* this set operation does not define completely the value read by
             the "get", or no static aliasing calculation can be done: we
             must read the value from memory  *)
          RETURN instr. GetResultStore();
        ELSE
          (* this "set" and "get" work on different variables, and
             cannot interfere with each other: continue trace through
             `instr' *)
          RETURN GetValue (instr. GetArgClass (Opnd.store), get)
        END;

      | Opcode.get:
        upstream := GetValue (instr. GetArgClass (Opnd.store), get);
        IF UnknownValue(upstream) THEN
          alias := Aliasing.DesignatorAlias (get. GetOpndClass (Opnd.readDesign),
                                             instr. GetOpndClass (Opnd.readDesign));
          IF (alias = Aliasing.completelyCovered) THEN
            (* this "get" instruction reads the variable we are tracing, and
               we don't know what this "get" will return *)
            RETURN instr;
          END;
        END;
        RETURN upstream;
        
      | Opcode.copy, Opcode.copyString:
        alias := Aliasing.DesignatorAlias (get. GetOpndClass (Opnd.readDesign),
                                           instr. GetOpndClass (Opnd.writeDesign));
        IF (alias # Aliasing.noAliasing) THEN
          (* this set operation may define the value read by the "get":
             read the value from memory, because a more fine grained analysis
             would not pay off *)
          RETURN instr. GetResultStore();
        ELSE
          (* this "copy" (or "copy-string") and the "get" work on different
             variables, and cannot interfere with each other: continue trace
             through `instr' *)
          RETURN GetValue (instr. GetArgClass (Opnd.store), get)
        END;
        
      | Opcode.enter:
        (* we are at the beginning of the procedure; the value is either
           coming for an external source, like a parameter or a global
           variable, or it is an undefined value *)        
        RETURN instr. GetResultStore();
        
      | Opcode.select, Opcode.loopEnd:
        RETURN GetSelectValue (instr);
        
      | Opcode.collect, Opcode.newObject, Opcode.newBlock,
        Opcode.copyParameter, Opcode.exit, Opcode.return,
        Opcode.halt, Opcode.assert, Opcode.checkIndex, Opcode.checkPointer,
        Opcode.typeGuard, Opcode.failedTypeAssert,
        Opcode.failedWith, Opcode.failedCase, Opcode.raiseException,
        Opcode.clearException, Opcode.activateContext,
        Opcode.pushExceptionContext, Opcode.popExceptionContext:
        RETURN GetValue (instr. GetArgClass (Opnd.store), get);

      | Opcode.tryStart:
        IF (store.ResultIndex() = 2) THEN  (* in CATCH part *)
          RETURN instr. GetResultStore();
        ELSE  (* in TRY body *)
          RETURN GetValue (instr. GetArgClass (Opnd.store), get);
        END;
        
      | Opcode.tryEnd:
        (* We don't know which path through the TRY statement was taken,
           which means we cannot know in general which values were set.  *)
        RETURN instr. GetResultStore();
        
      | Opcode.loopStart:
        RETURN GetLoopValue (instr);
        
      | Opcode.call:
        IF AccessedByCall (s, instr. opndList. arg,
                           get. GetOpndClass (Opnd.readDesign), write) THEN
          (* be pessimistic: the call rewrites our variable *)
          RETURN instr. GetResultStore();
        ELSE
          (* the "get" accesses a local variable that cannot be accessed by the
             called procedure; this means it cannot be written to behind our
             backs from within this procedure call  *)
          RETURN GetValue (instr. GetArgClass (Opnd.store), get);
        END;
        
      | Opcode.moveBlock:
        (* assume that a SYSTEM.MOVE can interact with anything *)
        RETURN instr. GetResultStore();
      END;
    END GetValue;

  PROCEDURE VisibleEffect (store: SSA.Result; set: SSA.Instr): BOOLEAN;
  (* Return @code{TRUE} if the instruction @oparam{set} performs a modification
     on @oparam{store} that is (or can be) visible to other instructions
     reading from the store.  Note: It is always safe to return @oconst{TRUE}.  *)
    VAR
      use: SSA.Opnd;

    PROCEDURE ReadingUse (use: SSA.Opnd): BOOLEAN;
      VAR
        instr, i: SSA.Instr;
        storeOut: SSA.Result;
        alias: Aliasing.Id;
        readDesign: SSA.Opnd;
        
      PROCEDURE GetVar (instr: SSA.Instr): Sym.VarDecl;
      (* Return the variable that starts the designator of the "get" or
         "set" instruction @oparam{instr}.  Result is @code{NIL} if its
         a heap access.  *)
        VAR
          opnd: SSA.Opnd;
          class: Opnd.Class;
        BEGIN
          CASE instr. opcode OF
          | Opcode.get: class := Opnd.readDesign
          | Opcode.set: class := Opnd.writeDesign
          END;
          opnd := instr. GetOpndClass (class);
          IF ~(opnd. arg IS SSA.DeclRef) OR
             ~(opnd. arg(SSA.DeclRef). decl IS Sym.VarDecl) THEN
            (* designator does not begin with a variable *)
            RETURN NIL
          ELSE
            RETURN opnd. arg(SSA.DeclRef). decl(Sym.VarDecl)
          END;
        END GetVar;
      
      PROCEDURE ExternalVisibility (var: Sym.VarDecl): BOOLEAN;
      (* TRUE if this variable still exists after the procedure is done.  *)
        BEGIN
          RETURN
              (var = NIL) OR             (* heap access *)
              var. isVarParam OR         (* variable parameter *)
              (var. Procedure() # pb. procDecl) (* nonlocal variable *)
        END ExternalVisibility;
      
      BEGIN
        IF (use. class = Opnd.backwardFeed) THEN
          instr := use. instr. GetLoopStart();
          RETURN VisibleEffect (instr. GetResultStore(), set);
        ELSE
          instr := use. instr;
          CASE instr. opcode OF
          | Opcode.get:
            storeOut := instr. GetResultStore();
            alias := Aliasing.DesignatorAlias (set. GetOpndClass (Opnd.writeDesign),
                                               instr. GetOpndClass (Opnd.readDesign));
            IF (alias # Aliasing.noAliasing) THEN
              (* the "get" may read from memory changed by the store *)
              RETURN TRUE;
            ELSE
              RETURN (storeOut # NIL) & VisibleEffect (storeOut, set);
            END;
            
          | Opcode.set:
            alias := Aliasing.DesignatorAlias (set. GetOpndClass (Opnd.writeDesign),
                                               instr. GetOpndClass (Opnd.writeDesign));
            IF (alias = Aliasing.completelyCovered) THEN
              (* this "set" instruction defines the variable we are tracing:
                 we are at the end of the visibility of "origin" *)
              RETURN FALSE;
            ELSIF (alias # Aliasing.noAliasing) THEN
              (* this set operation does not overwrite completely the original
                 set, or no static aliasing calculation can be done: we must
                 keep the write operation alive, but its static visibility ends
                 here *)
              RETURN TRUE;
            ELSE
              (* this "set" and "origin" work on different variables, and
                 cannot interfere with each other: continue trace through
                 `instr' *)
              RETURN VisibleEffect (instr. GetResultStore(), set);
            END;
            
          | Opcode.copyString, Opcode.copy:
            alias := Aliasing.DesignatorAlias (set. GetOpndClass (Opnd.writeDesign),
                                               instr. GetOpndClass (Opnd.writeDesign));
            IF (alias >= Aliasing.partiallyCovered) THEN
              (* this string copy does not overwrite completely the original
                 set, or no static aliasing calculation can be done: we must
                 keep the write operation alive *)
              RETURN TRUE;
            ELSE
              readDesign := instr. GetOpndClass (Opnd.readDesign);
              IF (readDesign = NIL) THEN (* reading from a string constant *)
                RETURN VisibleEffect (instr. GetResultStore(), set);
              ELSE
                alias := Aliasing.DesignatorAlias
                    (set. GetOpndClass (Opnd.writeDesign), readDesign);
                IF (alias # Aliasing.noAliasing) THEN
                  (* this string copy may read the value that is being
                     written *)
                  RETURN TRUE;
                ELSE
                  (* "set" and "copy" work on different variables, and cannot
                     interfere with each other: continue trace through
                     `instr' *)
                  RETURN VisibleEffect (instr. GetResultStore(), set);
                END
              END;
            END;
            
          | Opcode.return, Opcode.selectReturn:
            (* we've reached the end of the procedure: we are done *)
            RETURN ExternalVisibility (GetVar (set));

          | Opcode.exit:
            i := instr. GetLoopEnd();
            RETURN VisibleEffect (i. GetResultStore(), set)
            
          | Opcode.loopStart, Opcode.loopEnd, Opcode.collect,
            Opcode.select, Opcode.newObject, Opcode.newBlock,
            Opcode.assert, Opcode.checkIndex:
            RETURN VisibleEffect (instr. GetResultStore(), set)
            
          | Opcode.call:
            IF AccessedByCall (s, instr. opndList. arg,
                               set. GetOpndClass (Opnd.writeDesign), read) THEN
              RETURN TRUE;               (* assume the worst *)
            ELSE
              (* the called procedure cannot read the local variable  *)
              RETURN VisibleEffect (instr. GetResultStore(), set)
            END;
            
          ELSE
            RETURN TRUE;
          END;
        END;
      END ReadingUse;
    
    BEGIN
      IF (store. instr. marker = 0) THEN
        store. instr. marker := 1;
        use := store. useList;
        WHILE (use # NIL) & ~ReadingUse (use) DO
          use := use. nextUse;
        END;
        store. instr. marker := 0;
        RETURN (use # NIL);
      ELSE
        RETURN FALSE;
      END;
    END VisibleEffect;

  PROCEDURE ReplaceStoreUses (storeOut, storeIn: SSA.Result);
    BEGIN
      storeOut. ReplaceUses (storeIn);
      storeOut. DeleteResult;
    END ReplaceStoreUses;

  PROCEDURE AddToWorklist (instr: SSA.Instr);
    VAR
      wl: Worklist;
    BEGIN
      IF (instr. marker = notInWorklist) THEN
        instr. marker := inWorklist;
        
        NEW (wl);
        wl. next := worklist;
        wl. instr := instr;
        worklist := wl;
      END;
    END AddToWorklist;

  PROCEDURE AddUsesToWorklist (res: SSA.Result);
    VAR
      use: SSA.Opnd;
      useInstr: SSA.Instr;
    BEGIN
      use := res. useList;
      WHILE (use # NIL) DO
        useInstr := use. instr;
        IF (useInstr.opcode = Opcode.dgate) THEN
          AddToWorklist (useInstr);
        END;
        use := use. nextUse;
      END;
    END AddUsesToWorklist;
  
  PROCEDURE ComputeReplacement(dgate: SSA.Instr): SSA.Result;
    VAR
      select: SSA.Instr;
      opnd: SSA.Opnd;
      allTheSame, haveUnknownValue: BOOLEAN;
      value, firstValue: SSA.Result;
      
    PROCEDURE NormValue(opnd: SSA.Opnd): SSA.Result;
    (* If `opnd' refers to a dgate, then map the argument to the dgate's
       replacement value.  *)
      VAR
        value: SSA.Result;
      BEGIN
        value := opnd.arg;
        IF (value IS SSA.Instr) & (value(SSA.Instr).opcode = Opcode.dgate) THEN
          (* use replacement value *)
          value := value(SSA.Instr).opndList.nextOpnd.arg;
        END;
        RETURN value;
      END NormValue;

    PROCEDURE SameInstr(instr: SSA.Instr; res: SSA.Result): BOOLEAN;
      BEGIN
        RETURN (instr = res.instr);
      END SameInstr;
    
    BEGIN
      select := dgate.opndList.arg(SSA.Instr);
      IF (select.opcode = Opcode.loopStart) &
         (dgate.NthOpnd(3) # NIL) &
         (SameInstr(select, NormValue(dgate.NthOpnd(3))) OR
          SameInstr(dgate, NormValue(dgate.NthOpnd(3)))) THEN
        opnd := dgate.NthOpnd(3);
        opnd.DeleteOpnd();
        RETURN NormValue(dgate.NthOpnd(2));
      ELSE
        
        allTheSame := TRUE;
        haveUnknownValue := FALSE;
        opnd := dgate.NthOpnd(2);
        IF (opnd = NIL) THEN  (* LOOP without any exits *)
          RETURN select.GetResultStore();
        ELSE
          firstValue := NormValue(opnd);
          WHILE (opnd # NIL) DO
            value := NormValue(opnd);
            IF (value # firstValue) THEN
              allTheSame := FALSE;
            END;
            IF UnknownValue(value) THEN
              haveUnknownValue := TRUE;
            END;
            opnd := opnd.nextOpnd;
          END;
          
          IF allTheSame THEN
            RETURN firstValue;
          ELSIF haveUnknownValue THEN
            RETURN select.GetResultStore();
          ELSE
            (* pass through collected values *)          
            RETURN dgate.GetResultClass(Result.dgatePlaceholder);
          END;
        END;
      END;
    END ComputeReplacement;
  
  PROCEDURE DGateReplacement(dgate: SSA.Instr): SSA.Result;
    VAR
      select, collect: SSA.Instr;
      opnd: SSA.Opnd;
      replacement, newRes: SSA.Result;
      i: LONGINT;
    BEGIN
      replacement := dgate.opndList.nextOpnd.arg;
      IF (replacement.class = Result.dgatePlaceholder) THEN
        (* produce a gated value: extend collects, and the select
           instruction *)
        dgate := replacement.instr;      (* may differ from input parameter *)
        select := dgate.opndList.arg(SSA.Instr);
        opnd := dgate.NthOpnd(2); i := 0;
        WHILE (opnd # NIL) DO
          collect := select.GetCollect(pb, i);
          collect.AddOpnd(opnd.arg, Opnd.arg);
          opnd := opnd.nextOpnd; INC(i);
        END;
        ASSERT(i = select.NumberOfPaths());
        newRes := select.AddResultSubclass(Result.selectValue, dgate.subclass);
        replacement.ReplaceUses(newRes);
        RETURN newRes;
      ELSE
        RETURN replacement;
      END;
    END DGateReplacement;
  
  BEGIN
    pb := s. pb;
    
    (* visit all "get" instructions and check if their uses can be replaced
       with the value that they are retrieving from memory *)
    unknownList := ArrayList.New(8);
    pb. SetMarkers (NIL, 0);
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) THEN
        value := GetValue (instr. GetArgStore(), instr);
        IF UnknownValue (value) THEN
          unknownList.Append(instr);
          unknownList.Append(value);
        ELSIF (value IS SSA.Instr) &
              (value(SSA.Instr). opcode = Opcode.dgate) THEN
          instr.AddOpnd(value, Opnd.dgateRef);
        ELSE
          instr. ReplaceUses (value);
        END;
      END;
      instr := instr. nextInstr;
    END;
    FOR i := 0 TO unknownList.size-1 BY 2 DO
      instr := unknownList.array[i](SSA.Instr);
      value := unknownList.array[i+1](SSA.Result);
      ReplaceStoreUses(instr.GetResultStore(), instr.opndList.arg);
      instr.opndList.ReplaceArg(value);
    END;
    
    (* visit all "dgate" instructions and compute their replacement
       value *)
    worklist := NIL;
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      IF (instr.opcode = Opcode.dgate) & (instr.marker = notInWorklist) THEN
        value := ComputeReplacement(instr);
        IF (value # instr.opndList.nextOpnd.arg) THEN
          instr.opndList.nextOpnd.ReplaceArg(value);
          AddUsesToWorklist(instr);
        END;
      END;
      instr := next;
    END;
    WHILE (worklist # NIL) DO            (* repeat until worklist empty *)
      instr := worklist.instr;
      instr.marker := notInWorklist;
      worklist := worklist.next;
      value := ComputeReplacement(instr);
      IF (value # instr.opndList.nextOpnd.arg) THEN
        instr.opndList.nextOpnd.ReplaceArg(value);
        AddUsesToWorklist(instr);
      END;
    END;

    (* visit all "dgate" instructions and replace their uses with the
       replacement value *)
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      IF (instr.opcode = Opcode.dgate) THEN
        value := DGateReplacement(instr);
        
        IF UnknownValue(value) THEN      (* need to take value from memory *)
          use := instr.useList;
          WHILE (use # NIL) DO
            nextUse := use.nextUse;
            IF (use.class = Opnd.dgateRef) THEN
              ASSERT(use.instr.opcode = Opcode.get);
              opnd := use.instr.GetOpndClass(Opnd.store);
              ASSERT(opnd # NIL);
              ASSERT(opnd.instr.nextResult.class = Result.store);
              ReplaceStoreUses(opnd.instr.nextResult, opnd.arg);
              opnd.ReplaceArg(value);
            ELSE
              ASSERT(use.instr.opcode = Opcode.dgate);
            END;
            use.DeleteOpnd;
            use := nextUse;
          END;
        ELSE                 (* have value, use it instead of dgate *)
          use := instr.useList;
          WHILE (use # NIL) DO
            nextUse := use.nextUse;
            IF (use.class = Opnd.dgateRef) THEN
              use.instr.ReplaceUses(value);
              use.DeleteOpnd;
            ELSE
              use.ReplaceArg(value);
            END;
            use := nextUse;
          END;
        END;
        ASSERT(instr.useList = NIL);
        pb.DeleteInstr(instr);
      END;
      instr := next;
    END;
    
(*    (* XXX *)
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      IF (instr.opcode = Opcode.dgate) THEN
        use := instr.useList;
        WHILE (use # NIL) DO
          nextUse := use.nextUse;
          use.DeleteOpnd;
          use := nextUse;
        END;
        ASSERT(instr.useList = NIL);
        pb.DeleteInstr(instr);
      END;
      instr := next;
    END;*)
    
    
    (* visit all "get" instructions that have no uses and eliminate them;
       this is done in a separate step, instead of deleting them in the
       loop above, so that the "get" instructions can be used as markers
       above *)
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr. nextInstr;
      IF (instr. opcode = Opcode.get) & (instr. useList = NIL) THEN
        IF (instr. nextResult # NIL) THEN
          (* store result has not been eliminated yet, remove manually *)
          ASSERT (instr. nextResult. nextResult = NIL);
          instr. nextResult. ReplaceUses (instr. opndList. arg);
        END;
        pb. DeleteInstr (instr);
      END;
      instr := next;
    END;
    
    (* visit all "set" instructions and check if they can be eliminated;
       at this place, all obsolete "get"s must have been removed *)
    pb. SetMarkers (NIL, 0);
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr. nextInstr;
      IF (instr. opcode = Opcode.set) &
         ~VisibleEffect (instr. GetResultStore(), instr) THEN
        value := instr. GetResultStore();
        value. ReplaceUses (instr. GetArgClass (Opnd.store));
        ASSERT (instr. useList = NIL);   (* no more uses should exist *)
        ASSERT (instr. nextResult. nextResult = NIL);
        pb. DeleteInstr (instr);
      END;
      instr := next
    END;
  END Transform;

END OOC:SSA:Destore.
