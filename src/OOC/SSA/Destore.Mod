(* 	$Id$	 *)
MODULE OOC:SSA:Destore;
(*  Converts reads from/writes to memory into local values.
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
  Log,
  ADT:Dictionary, Sym := OOC:SymbolTable, OOC:SSA, OOC:SSA:Opcode,
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
  
  BEGIN
    RETURN
        NestedProc (calledAdr, s. pb. procDecl) OR
        ~LocalVarWithoutAdr (design);
  END AccessedByCall;

PROCEDURE (s: State) ClobberedBy* (readDesign: SSA.Opnd; instr: SSA.Instr): BOOLEAN;
(**Return @code{TRUE} if the value described by the read designator
   @oparam{readDesign} may be clobbered by the evaluation of the instruction
   @oparam{instr}.  *)
  VAR
    alias: Aliasing.Id;
  BEGIN
    (* Note: This predicate must mirror the rules of Transform.GetValue *)

    CASE instr. opcode OF
    | Opcode.set, Opcode.copy, Opcode.copyString:
      alias := Aliasing.DesignatorAlias (readDesign,
                                         instr. GetOpndClass (Opnd.writeDesign));
      RETURN (alias # Aliasing.noAliasing);
      
    | Opcode.enter, Opcode.get, Opcode.select,
      Opcode.loopStart, Opcode.loopEnd,
      Opcode.collect, Opcode.newObject, Opcode.copyParameter,
      Opcode.exit, Opcode.return,
      Opcode.halt, Opcode.assert, Opcode.checkIndex, Opcode.checkPointer,
      Opcode.typeGuard, Opcode.failedTypeAssert,
      Opcode.failedWith, Opcode.failedCase:
      RETURN FALSE;
      
    | Opcode.call:
      RETURN AccessedByCall (s, instr. opndList. arg, readDesign, write);
      
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
  VAR
    pb: SSA.ProcBlock;
    instr, next: SSA.Instr;
    value: SSA.Result;

  PROCEDURE UnknownValue (res: SSA.Result): BOOLEAN;
    BEGIN
      RETURN (res. class = Result.store);
    END UnknownValue;
  
  PROCEDURE GetValue (store: SSA.Result; get: SSA.Instr;
                      loopTrace: SSA.Instr): SSA.Result;
  (* Return the value from the @oparam{store} for the memory location (and
     type) designated by the instruction @oparam{get}.  If the value is not
     known, or if there is no single value, result is a SSA result of class
     @oconst{Result.store} from which the value can be retrieved.  Note: It is
     always safe to return the @var{store} argument of the @oparam{get}.

     If @oparam{loopTrace} is not @code{NIL}, then the semantics of the result
     change:

     @itemize @bullet
     @item
     If the value of the designator is loop invariant with respect to
     @oparam{store}, then result is @oparam{loopTrace}.

     @item
     If it is not invariant, and the value resides in @var{store}, the result
     is a a SSA result of class @oconst{Result.store}.  When this is the
     outcome for the whole loop body, then the @oparam{get} is left unchanged.

     @item
     Any other result indicates that it is not invariant, and the value is not
     in @var{store}.  If this is the outcome for the whole loop, then the
     @oparam{get} is replaced with a gated result of the ``loop-start''
     instruction.  @emph{Important}: In this case, the returned value must
     @emph{not} be used as an argument of an instruction, because it may
     be a placeholder value like a reference to a select instruction.
     @end itemize  *)
    VAR
      alias: Aliasing.Id;
      instr: SSA.Instr;

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
    
    PROCEDURE GetCollect (select: SSA.Instr; pathNum: LONGINT): SSA.Instr;
    (* Return the "collect" instruction of path @oparam{pathNum} leading
       into @oparam{select}.  The first path has the number @samp{0}.
       If no matching "collect" exists, create one.  *)
      VAR
        opnd: SSA.Opnd;
        collect, loopEnd: SSA.Instr;
        oldStore: SSA.Result;
      BEGIN
        CASE select. opcode OF
        | Opcode.select:
          opnd := select. NthOpnd (pathNum*2+2);
          
        | Opcode.loopEnd:         (* place collect _before_ "exit" *)
          opnd := select. NthOpnd (pathNum+2);
          ASSERT (opnd. arg. instr. opcode = Opcode.exit);
          opnd := opnd. arg. instr. opndList;
          
        | Opcode.loopStart:
          IF (pathNum = 0) THEN
            opnd := select. NthOpnd (pathNum);
          ELSE
            loopEnd := select. GetLoopEnd();
            opnd := loopEnd. GetOpndClass (Opnd.backwardFeed);
          END;
        END;
        
        IF (opnd. arg. instr. opcode = Opcode.collect) THEN
          RETURN opnd. arg.instr
        ELSE
          collect := pb. AddInstr (Opcode.collect, Opcode.scNone);
          oldStore := opnd. arg;
          opnd. ReplaceArg (collect. AddResult (Result.store));
          collect. AddOpnd (oldStore, Opnd.store);
          RETURN collect
        END;
      END GetCollect;
    
    PROCEDURE GetSelectValue (select: SSA.Instr): SSA.Result;
    (* Calculate the value of (store,get) for each of the paths leading
       into the select instruction.  *)
      VAR
        opnd: SSA.Opnd;
        values: POINTER TO ARRAY OF SSA.Result;
        i: LONGINT;
        noUnknownValue, allTheSame: BOOLEAN;
        collect: SSA.Instr;
        r: SSA.Result;
        dummy: CacheEntry;

      PROCEDURE NumberOfPaths (select: SSA.Instr): LONGINT;
      (* Return the number of paths leading into the select.  *)
        BEGIN
          CASE select. opcode OF
          | Opcode.select    :
            IF (select. GetOpndClass (Opnd.labels) = NIL) THEN
              RETURN (select. CountOpndClass (Opnd.arg) DIV 2);
            ELSE
              RETURN (select. CountOpndClass (Opnd.arg)-1);
            END;
          | Opcode.loopStart : RETURN 2
          | Opcode.loopEnd   : RETURN select. CountOpndClass (Opnd.storeExit)
          END;
        END NumberOfPaths;
      
      BEGIN
        IF InCache (select, r) THEN
          (* a previous call to this function already computed the result
             for the designator of this "get"; reuse it, instead of adding
             another result representing the same value *)
          RETURN r;
        ELSE
          NEW (values, NumberOfPaths (select));
          
          i := 0; noUnknownValue := TRUE; allTheSame := TRUE;
          CASE select. opcode OF
          | Opcode.select    : opnd := select. NthOpnd (2)
          | Opcode.loopEnd   : opnd := select. NthOpnd (2)
          END;
          WHILE (opnd # NIL) & ~opnd. IsScheduleOpnd() DO
            values[i] := GetValue (opnd. arg, get, loopTrace);
            IF UnknownValue (values[i]) THEN
              noUnknownValue := FALSE;
            END;
            IF (values[i] # values[0]) THEN
              allTheSame := FALSE;
            END;
            opnd := opnd. nextOpnd;
            IF (select. opcode = Opcode.select) & (opnd # NIL) THEN
              opnd := opnd. nextOpnd;
            END;
            INC (i);
          END;
          
          IF allTheSame THEN
            (* for all input paths the same value is passed to "get" *)
            IF (LEN (values^) = 0) THEN
              ASSERT(FALSE);             (* wrong? better return store?*)
              RETURN select;
            ELSE
              IF (loopTrace = NIL) THEN
                dummy := AddToCache (select, values[0]);
              END;
              RETURN values[0];
            END;
          ELSIF ~noUnknownValue THEN
            (* for at least one path into the select no value can be
               computed; the using instruction should get its value from
               memory *)
            dummy := AddToCache (select, select. GetResultStore());
            RETURN dummy. value;
          ELSIF (loopTrace # NIL) THEN
            (* we are tracing the use of the designator in the loop body, and
               at this place the value is not invariant, and not in memory:
               return the current instruction to signal this to the caller  *)
            RETURN select;
          ELSE
            (* "collect" all values into the "select", return the new result *)
            ASSERT (i = LEN (values^));
            FOR i := 0 TO LEN (values^)-1 DO
              collect := GetCollect (select, i);
              collect. AddOpnd (values[i], Opnd.arg);
            END;
            r := select. AddResultSubclass (Result.selectValue, get. subclass);
            dummy := AddToCache (select, r);
            RETURN r; 
          END;
        END;
      END GetSelectValue;

    PROCEDURE GetLoopValue (loopStart: SSA.Instr): SSA.Result;
      VAR
        invariant, r: SSA.Result;
        entry: CacheEntry;
        collect, newGet: SSA.Instr;
        
      PROCEDURE DuplicateGet (storeIn: SSA.Result): SSA.Instr;
      (* Takes the "get" instruction and creates a duplicate whose "store"
         input parameter is `storeIn'.  No corresponding "store" output is
         created.  *)
        VAR
          new: SSA.Instr;
          opnd: SSA.Opnd;
        BEGIN
          new := pb. AddInstr (Opcode.get, get. subclass);
          opnd := get. opndList;
          WHILE (opnd # NIL) DO
            IF (opnd. class = Opnd.store) THEN
              new. AddOpnd (storeIn, Opnd.store)
            ELSE
              new. AddOpnd (opnd. arg, opnd. class)
            END;
            opnd := opnd. nextOpnd
          END;
          RETURN new
        END DuplicateGet;
      
      BEGIN
        IF (loopTrace = loopStart) THEN
          RETURN loopTrace;
          
        ELSIF InCache (loopStart, r) THEN
          (* a previous call to this function already computed the result
             for the designator of this "get" *)
          IF ~UnknownValue (r) &
             (r IS SSA.Instr) &
             (r(SSA.Instr). opcode = Opcode.loopStart) THEN
            (* don't return the bogus cache line added by the code below;
               we know that the "get" is invariant with regard to this loop,
               so we can simply return the value from before the loop *)
            RETURN GetValue (loopStart. opndList. arg, get, loopTrace);
          ELSE
            RETURN r;
          END;

(*        ELSIF ~SimpleDesignator (get. GetOpndClass (Opnd.readDesign)) THEN
          (* if the designator has components that are loop variant, then
             its end result cannot be moved into a register acroos the loop *)
          RETURN loopStart. GetResultStore();*)
          
        ELSE
          invariant := GetValue (loopStart. GetBackwardFeed(), get, loopStart);
          IF (invariant = loopStart) THEN (* designator is invariant to loop *)
            IF (loopTrace = NIL) THEN
              (* within the loop, all "get" see the value of the designator
                 before the loop; in case of nested loops, we may end up
                 analysing this loop again; to prevent infinite looping, add a
                 preliminary result to the cache *)
              entry := AddToCache (loopStart, loopStart);
              entry. value := GetValue (loopStart. opndList. arg, get, loopTrace)
            ELSE
              (* we are within a loop trace, which means that the value
                 returned by the GetValue() in the other branch may be
                 a placeholde (read: a reference to a select instruction);
                 so don't try to cache the value *)
              RETURN GetValue (loopStart. opndList. arg, get, loopTrace);
            END;
                
          ELSIF UnknownValue (invariant) THEN (* in memory at end of loop *)
            (* "store" of designator is not loop invariant *)
            entry := AddToCache (loopStart, loopStart. GetResultStore());
            
          ELSE   (* not invariant, and not in memory at end of loop *)
            (* value is passed through "collect" operands to "select" result *)
            r := loopStart. AddResultSubclass (Result.selectValue,
                                               get. subclass);
            entry := AddToCache (loopStart, r);

            (* extend back-edge "collect" *)
            r := GetValue (loopStart. GetBackwardFeed(), get, NIL);
            ASSERT (~UnknownValue (r));
            collect := GetCollect (loopStart, 1);
            collect. AddOpnd (r, Opnd.arg);

            (* extend input "collect" *)
            r := GetValue (loopStart. opndList. arg, get, NIL);
            collect := GetCollect (loopStart, 0);
            IF UnknownValue (r) THEN
              newGet := DuplicateGet (collect. opndList. arg);
              collect. opndList. ReplaceArg (newGet. AddResult (Result.store));
              r := newGet;
            END;
            collect. AddOpnd (r, Opnd.arg);
          END;
          RETURN entry. value
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
          RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace)
        END;

      | Opcode.get:
        RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace);
        
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
          RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace)
        END;
        
      | Opcode.enter:
        (* we are at the beginning of the procedure; the value is either
           coming for an external source, like a parameter or a global
           variable, or it is an undefined value *)        
        RETURN instr. GetResultStore();
        
      | Opcode.select, Opcode.loopEnd:
        RETURN GetSelectValue (instr);
        
      | Opcode.collect, Opcode.newObject, Opcode.copyParameter,
        Opcode.exit, Opcode.return,
        Opcode.halt, Opcode.assert, Opcode.checkIndex, Opcode.checkPointer,
        Opcode.typeGuard, Opcode.failedTypeAssert,
        Opcode.failedWith, Opcode.failedCase:
        RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace);

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
          RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace);
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
            Opcode.select, Opcode.newObject,
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

  BEGIN
    pb := s. pb;
    
    (* visit all "get" instructions and check if their uses can be replaced
       with the value that they are retrieving from memory *)
    pb. SetMarkers (NIL, 0);
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) THEN
        value := GetValue (instr. GetArgStore(), instr, NIL);
        IF UnknownValue (value) THEN
          ReplaceStoreUses (instr. GetResultStore(), instr. opndList. arg);
          instr. opndList. ReplaceArg (value);
        ELSE
          instr. ReplaceUses (value);
        END;
      END;
      instr := instr. nextInstr;
    END;
    
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
