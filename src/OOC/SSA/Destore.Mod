(* 	$Id$	 *)
MODULE OOC:SSA:Destore;
(*  Converts reads from/writes to memory into local values.
    Copyright (C) 2001  Michael van Acken

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
  Dictionary := ADT:Dictionary:IntValue,
  Sym := OOC:SymbolTable, OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd;
  
(**The initial version of the SSA code, as produced by
   @omodule{*OOC:SSA:IRtoSSA}, converts all accesses to variables into
   @oconst{Opcode.get} and @oconst{Opcode.set} instructions.  These
   instructions correspond to memory accesses, and are therefore costly.  They
   are also part of the @var{store} chain, which can limit the scheduling
   alternatives for these instructions.

   This module tries to remove @oconst{Opcode.get} and @oconst{Opcode.set}
   instructions as far as possible.  The criteria that determine if such a
   instruction is required are for @oconst{Opcode.get}:

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

CONST
  unknownValue = NIL;
  
TYPE
  OriginMap* = POINTER TO OriginMapDesc;
  DefArray = POINTER TO ARRAY OF ARRAY OF SSA.Instr;
  OutArray = POINTER TO ARRAY OF SSA.Result;
  BooleanArray = POINTER TO ARRAY OF BOOLEAN;
  OriginMapDesc = RECORD
    (SSA.NodeDesc)
    def: DefArray;
    (* for a select statement and variable `v', the definining instruction
       for this variable and the `nth' input path is `def[v,n]'; if there
       is no definining instruction, then this element is `unknownValue' and
       the variable must be read from memory *)
    selectOut: OutArray;
    (* if the select has been processed for a variable, then the end result
       is stored in `selectOut[v]' *)
    visible: BooleanArray;
    (* if the select statement has been traced for a variable, then outside
       visibility is stored in `visible[v]'; if TRUE, then the effects of
       the instruction setting this variable may be visible by others *)
  END;
  
PROCEDURE GetVar (instr: SSA.Instr): Sym.VarDecl;
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
       ~(opnd. arg(SSA.DeclRef). decl IS Sym.VarDecl) OR
       (opnd. nextOpnd # NIL) & (opnd. nextOpnd. class = class) THEN
      (* designator does not begin with a variable, or it is
         structured designator: bail out *)
      RETURN NIL
    ELSE
      RETURN opnd. arg(SSA.DeclRef). decl(Sym.VarDecl)
    END;
  END GetVar;


PROCEDURE Transform* (pb: SSA.ProcBlock);
  VAR
    varMap: Dictionary.Dictionary;

    (* usage of Result.info:

       for "select" instructions, "info" is set to an instance of OriginMap

       for "set" instructions, "info" is set to the instruction itself if
       the "set" must not be deleted, and remains NIL otherwise

       usage of Result.marker:

       for "set" and "get" instructions, this is an index identifying the
       variable that is accessed by the instruction; this field remains
       -1 for instruction that are of no interest for this transformation
       
       *)

  PROCEDURE DoAlias (instr1, instr2: SSA.Instr): BOOLEAN;
    BEGIN
      (* rather incomplete function to determine if two "get" or "set"
         access the same memory locations... FIXME *)
      RETURN (instr1. marker = instr2. marker)
    END DoAlias;
  
  PROCEDURE IdentifyVars(): Dictionary.Dictionary;
    VAR
      varMap: Dictionary.Dictionary;
      instr: SSA.Instr;
      var: Sym.VarDecl;
      count, id: LONGINT;
    BEGIN
      count := 0;
      varMap := Dictionary.New();
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF (instr. opcode = Opcode.get) OR (instr. opcode = Opcode.set) THEN
          var := GetVar (instr);
          IF (var # NIL) THEN
            IF varMap. HasKey (var) THEN
              id := varMap. Get (var);
            ELSE
              varMap. Set (var, count);
              id := count;
              INC (count)
            END;
            instr. marker := id
          END;
        END;
        instr := instr. nextInstr
      END;
      RETURN varMap
    END IdentifyVars;

  PROCEDURE TraceSetForward (numVars: LONGINT);
    VAR
      instr: SSA.Instr;

    PROCEDURE Trace (origin: SSA.Instr; lastDefinition: SSA.Instr;
                     storeOut: SSA.Result): BOOLEAN;
    (**Result is @code{TRUE} if the effects of @oparam{origin} are visible
       after completion of this procedure, or by procedures called by this
       procedure.  *)
      VAR
        use: SSA.Opnd;
        instr: SSA.Instr;
        visible: BOOLEAN;

      PROCEDURE NewOriginMap (numPaths, numVars: LONGINT): OriginMap;
        VAR
          originMap: OriginMap;
          i, j: LONGINT;
        BEGIN
          NEW (originMap);
          SSA.InitNode (originMap);
          NEW (originMap. def, numVars, numPaths);
          NEW (originMap. selectOut, numVars);
          NEW (originMap. visible, numVars);
          FOR i := 0 TO numVars-1 DO
            FOR j := 0 TO numPaths-1 DO
              originMap. def[i, j] := unknownValue;
            END;
            originMap. selectOut[i] := NIL;
            originMap. visible[i] := FALSE;
          END;
          RETURN originMap
        END NewOriginMap;

      PROCEDURE ExternalVisibility (var: Sym.VarDecl): BOOLEAN;
      (* TRUE if this variable still exists after the procedure is done.  *)
        BEGIN
          RETURN (var. Procedure() # pb. procDecl)
        END ExternalVisibility;

      PROCEDURE NumberOfPaths (select: SSA.Instr): LONGINT;
        BEGIN
          CASE select. opcode OF
          | Opcode.select   : RETURN (select. SizeOpndList() DIV 2)
          | Opcode.loopStart: RETURN select. SizeOpndList()
          END;
        END NumberOfPaths;

      PROCEDURE TraceUse (use: SSA.Opnd): BOOLEAN;
        VAR
          originMap: OriginMap;
          visible: BOOLEAN;
          storeOut: SSA.Result;
        BEGIN
          instr := use. instr;
          CASE instr. opcode OF
          | Opcode.get:
            storeOut := instr. GetResultClass (Result.store);
            IF (storeOut = NIL) OR DoAlias (instr, origin) THEN
              (* if the `store' chain ends here, then ignore the "get": we are
                 only interested in writing instructions; if it continues, but
                 the "get" aliases with the original "set", then the visibility
                 of the "set" is also at an end  *)
              RETURN FALSE;
            ELSE
              (* the "get" instruction accesses a volatile variable, but it
                 does not alias with the original "set": continue trace *)
              RETURN Trace (origin, lastDefinition, storeOut);
            END;
            
          | Opcode.set:
            IF DoAlias (instr, origin) THEN
              (* this "set" instruction defines the variable we are tracing:
                 we are at the end of the visibility of "origin" *)
              RETURN FALSE
            ELSE
              (* FIXME... with variable parameters, this "set" may
                 alias with "origin"; this also ends the trace *)
              (* this "set" and "origin" work on different variables, and
                 cannot interfere with each other: continue trace through
                 `instr' *)
              RETURN Trace (origin, lastDefinition,
                            instr. GetResultClass (Result.store))
            END;
            
          | Opcode.select:
            IF (instr. info = NIL) THEN
              (* continue tracing the uses of this select; note: this is
                 only done once for each variable, when we encounter the
                 select for the first time *)
              visible := Trace (origin, instr,
                                instr. GetResultClass (Result.store));
              
              originMap := NewOriginMap (NumberOfPaths (instr), numVars);
              originMap. visible[origin. marker] := visible;
              instr. info := originMap
            ELSE
              originMap := instr. info(OriginMap);
            END;
            
            (* set the instruction defining the store argument `use'
               for the variable identified by `origin. marker' *)
            originMap. def[origin. marker, use. OpndIndex() DIV 2-1]
                := lastDefinition;
            RETURN originMap. visible[origin. marker];

          | Opcode.loopStart:
            IF (instr. info = NIL) THEN
              originMap := NewOriginMap (NumberOfPaths (instr), numVars);
              instr. info := originMap;
              
              (* continue tracing the uses of this loop-start; note: this is
                 only done once for each variable, when we encounter the
                 loop-start for the first time *)
              (* note: originMap. visible[origin. marker] defaults to FALSE *)
              visible := Trace (origin, instr,
                                instr. GetResultClass (Result.store));
              originMap. visible[origin. marker] := visible;
            ELSE
              originMap := instr. info(OriginMap);
            END;
            
            (* set the instruction defining the store argument `use'
               for the variable identified by `origin. marker' *)
            originMap. def[origin. marker, use. OpndIndex()]
                := lastDefinition;
            RETURN originMap. visible[origin. marker];

          | Opcode.loopEnd:
            RETURN Trace (origin, lastDefinition,
                          instr. GetResultClass (Result.store))
            
          | Opcode.call:
            (* FIXME... detect when a call can modify our variable; for now
               be pessimistic: assume that this call may read and write
               the var *)
            RETURN TRUE;
            
          | Opcode.return:
            (* we've reached the end of the procedure: we are done *)
            RETURN ExternalVisibility (GetVar (origin));
            
          | Opcode.selectReturn:
            (* we've reached the end of the procedure: we are done *)
            RETURN ExternalVisibility (GetVar (origin));
          END;
        END TraceUse;
      
      BEGIN
        visible := FALSE;
        use := storeOut. useList;
        WHILE (use # NIL) DO
          IF TraceUse (use) THEN
            visible := TRUE
          END;
          use := use. nextUse
        END;
        RETURN visible
      END Trace;
    
    BEGIN
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF (instr. marker >= 0) & (instr. opcode = Opcode.set) THEN
          IF Trace (instr, instr, instr. GetResultClass (Result.store)) THEN
            instr. info := instr  (* mark instruction as live *)
          END
        END;
        instr := instr. nextInstr
      END;
    END TraceSetForward;
  
  PROCEDURE TraceGetBackward;
    VAR
      instr: SSA.Instr;
      value: SSA.Result;

    PROCEDURE Trace (get: SSA.Instr; storeIn: SSA.Result): SSA.Result;
    (* Traces @oparam{storeIn} back to definition that defines or may
       define the variable read by the @oparam{get}.  If it finds a 100%
       percent match, it returns the value that should be used in place
       of the original "get" instruction.  *)
      VAR
        instr: SSA.Instr;
        
      PROCEDURE TraceSelect (select: SSA.Instr; var: LONGINT;
                             subclass: Opcode.Subclass): SSA.Result;
      (* pre: `select' has opcode "select" or "loopStart" *)
        VAR
          origin: OriginMap;
          i, memoryCount, registerCount: LONGINT;
          collect, allTheSame: SSA.Instr;

        PROCEDURE GetCollect (select: SSA.Instr; pathNum: LONGINT): SSA.Instr;
          VAR
            opnd: SSA.Opnd;
            collect: SSA.Instr;
            oldStore: SSA.Result;
          BEGIN
            CASE select. opcode OF
            | Opcode.select   : opnd := select. NthOpnd (pathNum*2+2);
            | Opcode.loopStart: opnd := select. NthOpnd (pathNum);
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

        PROCEDURE GetValue (source: SSA.Instr): SSA.Result;
          BEGIN
            CASE source. opcode OF
            | Opcode.set:
              RETURN source. GetArgClass (Opnd.sourceValue)
            | Opcode.select:
              RETURN TraceSelect (source, var, subclass)
            | Opcode.loopStart:
              RETURN TraceSelect (source, var, subclass)
            END;
          END GetValue;

        PROCEDURE DuplicateGet (storeIn: SSA.Result): SSA.Instr;
        (* takes the "get" instruction passed to `Trace()' and creates a
           duplicate whose "store" input parameter is `storeIn' *)
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

        PROCEDURE GetStoreOpnd (select: SSA.Instr; pathNum: LONGINT): SSA.Result;
          VAR
            storeIn: SSA.Result;
          BEGIN
            CASE select. opcode OF
            | Opcode.select: storeIn := select. NthArg (pathNum*2+2);
            | Opcode.loopStart: storeIn := select. NthArg (pathNum);
            END;
            IF (storeIn. instr. opcode = Opcode.collect) THEN
              storeIn := storeIn. instr. GetArgClass (Opnd.store)
            END;
            RETURN storeIn
          END GetStoreOpnd;
        
        BEGIN
          IF (select. info = NIL) THEN
            (* there is no information available which value may reach this
               select statement on either path: value must be taken from
               memory *)
            RETURN NIL;
          ELSE
            origin := select. info(OriginMap);
            IF (origin. selectOut[var] = NIL) THEN
              IF (select. opcode = Opcode.loopStart) THEN
                (* place marker that enables us to detect loops when trying
                   to retrieve the variable's variable for an input path *)
                origin. selectOut[var] := select;
                value := GetValue (origin. def[var, 1]);
                IF (value = select) THEN
                  origin. def[var, 1] := origin. def[var, 0]
                END;
              END;
              
              allTheSame := origin. def[var, 0];
              memoryCount := 0; registerCount := 0;
              FOR i := 0 TO LEN (origin. def^, 1)-1 DO
                IF (origin. def[var, i] = unknownValue) THEN
                  INC (memoryCount)
                ELSE
                  INC (registerCount)
                END;
                IF (origin. def[var, i] # allTheSame) THEN
                  allTheSame := NIL
                END;
              END;
              
              IF (memoryCount = 0) THEN
                IF (allTheSame # NIL) THEN
                  (* all paths into the select/loop-start have the same value:
                     use this value for the "get" *)
                  origin. selectOut[var] := GetValue (allTheSame);
                ELSE
                  FOR i := 0 TO LEN (origin. def^, 1)-1 DO
                    collect := GetCollect (select, i);
                    collect. AddOpnd (GetValue (origin. def[var,i]), Opnd.arg);
                  END;
                  origin. selectOut[var] :=
                      select. AddResultSubclass (Result.selectValue, subclass);
                END
                
              ELSIF (registerCount = 0) THEN
                (* we have no information on a single branch: must read
                   from memory *)
                origin. selectOut[var] := NIL;
                
              ELSE
                ASSERT (registerCount+memoryCount = 2);
                (* we have the value we need partially in memory, partially as
                   value; convert this situation into an "all memroy" or "all
                   value" scenario; on the assumption that a reads are cheaper
                   than writes, add a "get" for the current value to the
                   branches we know nothing about *)
                FOR i := 0 TO LEN (origin. def^, 1)-1 DO
                  IF (origin. def[var, i] = unknownValue) THEN
                    value := DuplicateGet (GetStoreOpnd (select, i))
                  ELSE
                    value := GetValue (origin. def[var, i]);
                  END;
                  collect := GetCollect (select, i);
                  collect. AddOpnd (value, Opnd.arg);
                END;
                origin. selectOut[var] :=
                    select. AddResultSubclass (Result.selectValue, subclass);
              END;
            END;
            RETURN origin. selectOut[var]
          END;
        END TraceSelect;
      
      BEGIN
        instr := storeIn. instr;
        CASE instr. opcode OF
        | Opcode.set:
          IF DoAlias (instr, get) THEN
            (* this "set" instruction defines the variable we are tracing *)
            RETURN instr. GetArgClass (Opnd.sourceValue)
          ELSE
            (* FIXME... with variable parameters, this "set" may
               alias with "get"; this also ends the trace, unsuccessfully *)
            (* this "set" and "origin" work on different variables, and
               cannot interfere with each other: continue trace through
               `instr' *)
            RETURN Trace (get, instr. GetArgClass (Opnd.store))
          END;
          
        | Opcode.enter:
          RETURN NIL;  (* undefined value *)
          
        | Opcode.select:
          RETURN TraceSelect (instr, get. marker, get. subclass);

        | Opcode.collect:
          RETURN Trace (get, instr. GetArgClass (Opnd.store));
              
        | Opcode.loopStart:
          RETURN TraceSelect (instr, get. marker, get. subclass);

        | Opcode.loopEnd:
          RETURN Trace (get, instr. GetArgClass (Opnd.store));
              
        | Opcode.call:
          (* FIXME... detect when a call can modify our variable; for now
             be pessimistic: the call rewrites our variable *)
          RETURN NIL;
        END;
      END Trace;
    
    BEGIN
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF (instr. marker >= 0) & (instr. opcode = Opcode.get) &
           (instr. GetResultClass (Result.store) = NIL) THEN
          (* don't try to get rid of "get" instructions on volatile variables:
             we must read from memory, because the value might have changed
             behind our back *)
          value := Trace (instr, instr. opndList. arg);
          IF (value # NIL) THEN
            instr. ReplaceUses (value)
          END;
        END;
        instr := instr. nextInstr
      END;
    END TraceGetBackward;
  
  PROCEDURE RemoveUnusedSet;
    VAR
      instr, next: SSA.Instr;
      storeOut: SSA.Result;
    BEGIN
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        next := instr. nextInstr;
        IF (instr. marker >= 0) &
           (instr. opcode = Opcode.set) &
           (instr. info # instr) THEN
          (* FIXME: don't remove "set" for volatile variable... *)
          ASSERT (instr. opcode = Opcode.set);
          storeOut := instr. GetResultClass (Result.store);
          storeOut. ReplaceUses (instr. GetArgClass (Opnd.store));
          pb. DeleteInstr (instr);
        END;
        instr := next
      END;
    END RemoveUnusedSet;
  
  BEGIN
    pb. SetMarkers (NIL, -1);

    (* first: identify all scalar variables that appear in "get" or "set"
       instructions *)
    varMap := IdentifyVars();

    (* second: for every "set" instruction, establish the visibility of the
       written value in memory *)
    TraceSetForward (varMap. Size());

    (* third: for every "get" instruction, try trace the store value back
       to the definition from which the "get" reads its result *)
    TraceGetBackward;

    (* fourth: eliminate every "set" instruction that does not have any effect
       inside the procedure, not is visible after it has been completed *)
    RemoveUnusedSet;
  END Transform;

END OOC:SSA:Destore.
