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
  Sym := OOC:SymbolTable, OOC:SymbolTable:TypeRules,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result, OOC:SSA:Aliasing;

  
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

PROCEDURE Transform* (pb: SSA.ProcBlock; tr: TypeRules.Rules);
  CONST
    unknownValue = NIL;
  VAR
    instr, next: SSA.Instr;
    value: SSA.Result;
    
  PROCEDURE GetValue (store: SSA.Result; get: SSA.Instr;
                      loopTrace: SSA.Instr): SSA.Result;
  (* Return the value from the @oparam{store} for the memory location (and
     type) designated by the instruction @oparam{get}.  If the value is not
     known, or if there is no single value, result is @oconst{unknownValue}.
     Note: It is always safe to return @oconst{unknownValue}.

     If @oparam{loopTrace} is not @code{NIL}, then the semantics of the result
     change:

     @itemize @bullet
     @item
     If the value of the designator is loop invariant with respect to
     @oparam{store}, then result is @oparam{loopTrace}.

     @item
     If it is not invariant, and the value resides in @var{store}, the result
     is @oconst{unknownValue} otherwise.  When this is the outcome for the
     whole loop body, then the @oparam{get} is left unchanged.

     @item
     Any other result indicates that it is not invariant, and the value is not
     in @var{store}.  If this is the outcome for the whole loop, then the
     @oparam{get} is replaced with a gated result of the ``loop-start''
     instruction.
     @end itemize  *)
    TYPE
      CacheEntry = POINTER TO CacheEntryDesc;
      CacheEntryDesc = RECORD
        (SSA.NodeDesc)
        next: CacheEntry;
        design: SSA.Opnd;
        value: SSA.Result;
      END;
      
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
          
        | Opcode.selectExit:         (* place collect _before_ "exit" *)
          opnd := select. NthOpnd (pathNum+1);
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
          | Opcode.select    : RETURN (select. SizeOpndList() DIV 2)
          | Opcode.loopStart : RETURN 2
          | Opcode.selectExit: RETURN (select. SizeOpndList() - 1)
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
          | Opcode.selectExit: opnd := select. NthOpnd (1)
          END;
          WHILE (opnd # NIL) & noUnknownValue DO
            values[i] := GetValue (opnd. arg, get, loopTrace);
            IF (values[i] = unknownValue) THEN
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
          
          IF ~noUnknownValue THEN
            (* for at least one path into the select no value can be
               computed; the using should get its value from memory *)
            dummy := AddToCache (select, unknownValue);
            RETURN unknownValue;
          ELSIF allTheSame THEN
            (* for all input paths the same value is passed to "get" *)
            IF (loopTrace = NIL) THEN
              dummy := AddToCache (select, values[0]);
            END;
            RETURN values[0];
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
        collect: SSA.Instr;
        
      PROCEDURE DuplicateGet (storeIn: SSA.Result): SSA.Instr;
      (* takes the "get" instruction and
         creates a duplicate whose "store" input parameter is `storeIn' *)
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
          IF (r # unknownValue) &
             (r IS SSA.Instr) &
             (r(SSA.Instr). opcode = Opcode.loopStart) THEN
            (* don't return the bogus cache line added by the code below;
               we know that the "get" is invariant with regard to this loop,
               so we can simply return the value from before the loop *)
            RETURN GetValue (loopStart. opndList. arg, get, loopTrace);
          ELSE
            RETURN r;
          END;
          
        ELSE
          invariant := GetValue (loopStart. GetBackwardFeed(), get, loopStart);
          IF (invariant = loopStart) THEN (* designator is invariant to loop *)
            (* within the loop, all "get" see the value of the designator
               before the loop; in case of nested loops, we may end up
               analysing this loop again; to prevent infinite looping, add a
               preliminary result to the cache *)
            entry := AddToCache (loopStart, loopStart);
            entry. value := GetValue (loopStart. opndList. arg, get, loopTrace)
                
          ELSIF (invariant = unknownValue) THEN (* in memory at end of loop *)
            entry := AddToCache (loopStart, unknownValue)
            
          ELSE   (* not invariant, and not in memory at end of loop *)
            (* value is passed through "collect" operands to "select" result *)
            r := loopStart. AddResultSubclass (Result.selectValue,
                                               get. subclass);
            entry := AddToCache (loopStart, r);

            (* extend back-edge "collect" *)
            r := GetValue (loopStart. GetBackwardFeed(), get, NIL);
            ASSERT (r # unknownValue);
            collect := GetCollect (loopStart, 1);
            collect. AddOpnd (r, Opnd.arg);

            (* extend input "collect" *)
            r := GetValue (loopStart. opndList. arg, get, NIL);
            collect := GetCollect (loopStart, 0);
            IF (r = unknownValue) THEN
              r := DuplicateGet (collect. opndList. arg);
            END;
            collect. AddOpnd (r, Opnd.arg);
          END;
          RETURN entry. value
        END;
      END GetLoopValue;
    
    BEGIN
      instr := store. instr;
      CASE store. instr. opcode OF
      | Opcode.set:
        alias := Aliasing.DesignatorAlias (tr,
                                           get. GetOpndClass (Opnd.readDesign),
                                           instr. GetOpndClass (Opnd.writeDesign));
        IF (alias = Aliasing.completelyCovered) THEN
          (* this "set" instruction defines the variable we are tracing *)
          RETURN instr. GetArgClass (Opnd.sourceValue)
        ELSIF (alias # Aliasing.noAliasing) THEN
          (* this set operation does not define completely the value read by
             the "get", or no static aliasing calculation can be done: we
             must read the value from memory  *)
          RETURN unknownValue;
        ELSE
          (* this "set" and "get" work on different variables, and
             cannot interfere with each other: continue trace through
             `instr' *)
          RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace)
        END;
        
      | Opcode.copy, Opcode.copyString:
        alias := Aliasing.DesignatorAlias (tr,
                                           get. GetOpndClass (Opnd.readDesign),
                                           instr. GetOpndClass (Opnd.writeDesign));
        IF (alias # Aliasing.noAliasing) THEN
          (* this set operation may define the value read by the "get":
             read the value from memory, because a more fine grained analysis
             would not pay off *)
          RETURN unknownValue;
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
        RETURN unknownValue;
        
      | Opcode.select, Opcode.selectExit:
        RETURN GetSelectValue (instr);
        
      | Opcode.collect, Opcode.newObject, Opcode.copyParameter, Opcode.loopEnd,
        Opcode.exit, Opcode.return, Opcode.assert:
        RETURN GetValue (instr. GetArgClass (Opnd.store), get, loopTrace);

      | Opcode.loopStart:
        RETURN GetLoopValue (instr);
        
      | Opcode.call:
        (* FIXME... detect when a call can modify our variable; for now
           be pessimistic: the call rewrites our variable *)
        RETURN unknownValue;
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
            alias := Aliasing.DesignatorAlias (tr,
                                               set. GetOpndClass (Opnd.writeDesign),
                                               instr. GetOpndClass (Opnd.readDesign));
            IF (alias # Aliasing.noAliasing) THEN
              (* the "get" may read from memory changed by the store *)
              RETURN TRUE;
            ELSE
              (* continue trace if the "get" instruction accesses a volatile
                 variable *)
              RETURN (storeOut # NIL) & VisibleEffect (storeOut, set);
            END;
            
          | Opcode.set:
            alias := Aliasing.DesignatorAlias (tr,
                                               set. GetOpndClass (Opnd.writeDesign),
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
            
          | Opcode.copyString:
            alias := Aliasing.DesignatorAlias (tr,
                                               set. GetOpndClass (Opnd.writeDesign),
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
                    (tr, set. GetOpndClass (Opnd.writeDesign), readDesign);
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
            i := instr. GetSelectExit();
            RETURN VisibleEffect (i. GetResultStore(), set)
            
          | Opcode.loopEnd:
            storeOut := instr. GetResultStore();
            IF (storeOut = NIL) THEN
              (* loop is left through its "select-exit", control never
                 passes through "loop-end" *)
              RETURN FALSE;
            ELSE
              RETURN VisibleEffect (storeOut, set);
            END;
            
          | Opcode.loopStart, Opcode.selectExit, Opcode.collect,
            Opcode.select, Opcode.newObject:
            RETURN VisibleEffect (instr. GetResultStore(), set)
            
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
  
  BEGIN
    (* visit all "get" instructions and check if their uses can be replaced
       with the value that they are retrieving from memory *)
    pb. SetMarkers (NIL, 0);
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      IF (instr. opcode = Opcode.get) & (instr. GetResultStore() = NIL) THEN
        (* don't try to get rid of "get" instructions on volatile variables:
           we must read from memory, because the value might have changed
           behind our back *)
        value := GetValue (instr. GetArgStore(), instr, NIL);
        IF (value # unknownValue) THEN
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
      IF (instr. useList = NIL) &
         (instr. opcode = Opcode.get) & (instr. GetResultStore() = NIL) THEN
        ASSERT (instr. nextResult = NIL); (* no other result possible *)
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
