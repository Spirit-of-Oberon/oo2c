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
  Channel, StdChannels, Dictionary := ADT:Dictionary:IntValue, ADT:ArrayList,
  Sym := OOC:SymbolTable, OOC:SymbolTable:TypeRules,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd, OOC:SSA:Aliasing,
  OOC:SSA:XML;
  
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
    varIsTraced: BooleanArray;
    (* if `varIsTraced[v]' is TRUE, then the visibility of the select statement
       has been traced for this variable  *)
    visible: BooleanArray;
    (* if the select statement has been traced for a variable, then outside
       visibility is stored in `visible[v]'; if TRUE, then the effects of
       the instruction setting this variable may be visible by others *)
  END;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc = RECORD
    (XML.WriterDesc)
    varArray: ArrayList.ArrayList;
  END;


PROCEDURE InitWriter* (w: Writer; cw: Channel.Writer; varArray: ArrayList.ArrayList);
  BEGIN
    XML.InitWriter (w, cw);
    w. varArray := varArray;
  END InitWriter;

PROCEDURE NewWriter* (cw: Channel.Writer; varArray: ArrayList.ArrayList): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, cw, varArray);
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) WriteInstrAttr* (instr: SSA.Instr);
  BEGIN
    IF (instr. info # NIL) & (instr. info IS OriginMap) THEN
      w. AttrString ("info-type", "OriginMap");
    END;
  END WriteInstrAttr;

PROCEDURE (w: Writer) WriteInstrChildren* (instr: SSA.Instr);
  VAR
    i, j: LONGINT;
  BEGIN
    IF (instr. info # NIL) & (instr. info IS OriginMap) THEN
      FOR i := 0 TO w. varArray. size-1 DO
        w. StartTag ("def-var", FALSE);
        w. AttrStringLatin1 ("var-name", w. varArray. array[i](Sym.VarDecl). name. str^);
        FOR j := 0 TO LEN (instr. info(OriginMap). def^, 1)-1 DO
          w. StartTag ("path", FALSE);
          w. AttrInt ("n", j);
          w. AttrRef (instr. info(OriginMap). def[i, j]);
          w. EndTag;  (* path *)
        END;
        w. EndTag;  (* def-var *)
      END;
    END;
  END WriteInstrChildren;


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

PROCEDURE NumberOfPaths (select: SSA.Instr): LONGINT;
  BEGIN
    CASE select. opcode OF
    | Opcode.select    : RETURN (select. SizeOpndList() DIV 2)
    | Opcode.loopStart : RETURN 2
    | Opcode.selectExit: RETURN (select. SizeOpndList() - 1)
    END;
  END NumberOfPaths;

PROCEDURE IndexOfPath (use: SSA.Opnd): LONGINT;
  BEGIN
    CASE use. instr. opcode OF
    | Opcode.select:
      RETURN use. OpndIndex() DIV 2-1
    | Opcode.loopStart:
      RETURN 0;
    | Opcode.loopEnd:                    (* back-edge value of loop-start *)
      RETURN 1;
    | Opcode.selectExit:
      RETURN use. OpndIndex()-1
    END;
  END IndexOfPath;


PROCEDURE Transform* (pb: SSA.ProcBlock; tr: TypeRules.Rules);
  VAR
    varMap: Dictionary.Dictionary;
    varArray: ArrayList.ArrayList;
    w: Writer;

    (* usage of Result.info:

       for "select" instructions, "info" is set to an instance of OriginMap

       for "set" instructions, "info" is set to the instruction itself if
       the "set" must not be deleted, and remains NIL otherwise

       usage of Result.marker:

       for "set" and "get" instructions, this is an index identifying the
       variable that is accessed by the instruction; this field remains
       -1 for instruction that are of no interest for this transformation
       
       *)

  PROCEDURE IdentifyVars (varArray: ArrayList.ArrayList): Dictionary.Dictionary;
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
              ASSERT (count = varArray. size);
              varArray. Append (var);
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
      origin: SSA.Instr;
      originWriteDesign: SSA.Opnd;
      
    PROCEDURE TraceF (lastDefinition: SSA.Instr;
                      storeOut: SSA.Result): BOOLEAN;
    (**Result is @code{TRUE} if the effects of @ovar{origin} are visible
       after completion of this procedure, or by procedures called by this
       procedure, or the memory write must go through because of aliasing
       effects.  *)
      VAR
        use: SSA.Opnd;
        instr, oldLastDefinition: SSA.Instr;
        visible, dummy: BOOLEAN;

      PROCEDURE NewOriginMap (numPaths, numVars: LONGINT): OriginMap;
        VAR
          originMap: OriginMap;
          i, j: LONGINT;
        BEGIN
          NEW (originMap);
          SSA.InitNode (originMap);
          NEW (originMap. def, numVars, numPaths);
          NEW (originMap. selectOut, numVars);
          NEW (originMap. varIsTraced, numVars);
          NEW (originMap. visible, numVars);
          FOR i := 0 TO numVars-1 DO
            FOR j := 0 TO numPaths-1 DO
              originMap. def[i, j] := unknownValue;
            END;
            originMap. selectOut[i] := NIL;
            originMap. visible[i] := FALSE;
            originMap. varIsTraced[i] := FALSE;
          END;
          RETURN originMap
        END NewOriginMap;

      PROCEDURE ExternalVisibility (var: Sym.VarDecl): BOOLEAN;
      (* TRUE if this variable still exists after the procedure is done.  *)
        BEGIN
          RETURN var. isVarParam OR (var. Procedure() # pb. procDecl)
        END ExternalVisibility;

      PROCEDURE TraceUse (use: SSA.Opnd): BOOLEAN;
        VAR
          originMap: OriginMap;
          storeOut: SSA.Result;
          alias: Aliasing.Id;

        PROCEDURE TraceLoopStart (instr: SSA.Instr;
                                  opndIndex: LONGINT): OriginMap;
          VAR
            originMap: OriginMap;
            visible: BOOLEAN;
          BEGIN
            IF (instr. info = NIL) THEN
              originMap := NewOriginMap (NumberOfPaths (instr), numVars);
              instr. info := originMap;
              
              (* continue tracing the uses of this loop-start; note: this is
                 only done once for each variable, when we encounter the
                 loop-start for the first time *)
              (* note: originMap. visible[origin. marker] defaults to FALSE *)
              visible := TraceF (instr, instr. GetResultStore());
              originMap. visible[origin. marker] := visible;
            ELSE
              originMap := instr. info(OriginMap);
            END;
            
            (* set the instruction defining the store argument `use'
               for the variable identified by `origin. marker' *)
            originMap. def[origin. marker, opndIndex]
                := lastDefinition;
            
            RETURN originMap
          END TraceLoopStart;
        
        BEGIN
          instr := use. instr;
          CASE instr. opcode OF
          | Opcode.get:
            storeOut := instr. GetResultStore();
            alias := Aliasing.DesignatorAlias (tr, originWriteDesign, instr. GetOpndClass (Opnd.readDesign));
            IF (storeOut = NIL) OR (alias = Aliasing.completelyCovered) THEN
              (* if the `store' chain ends here, then ignore the "get": we are
                 only interested in writing instructions; if it continues, but
                 the "get" aliases with the original "set", then the visibility
                 of the "set" is also at an end  *)
              RETURN FALSE;
            ELSE
              (* the "get" instruction accesses a volatile variable, but it
                 does not alias completely with the original "set": continue
                 trace  *)
              RETURN TraceF (lastDefinition, storeOut);
            END;
            
          | Opcode.set:
            alias := Aliasing.DesignatorAlias (tr, originWriteDesign, instr. GetOpndClass (Opnd.writeDesign));
            IF (alias = Aliasing.completelyCovered) THEN
              (* this "set" instruction defines the variable we are tracing:
                 we are at the end of the visibility of "origin" *)
              RETURN FALSE
            ELSIF (alias # Aliasing.noAliasing) THEN
              (* this set operation does not overwrite completely the original
                 set, or no static aliasing calculation can be done: we must
                 keep the write operation alive, but its static visibility ends
                 here *)
              RETURN TRUE
            ELSE
              (* this "set" and "origin" work on different variables, and
                 cannot interfere with each other: continue trace through
                 `instr' *)
              RETURN TraceF (lastDefinition,
                            instr. GetResultStore())
            END;
            
          | Opcode.select, Opcode.selectExit:
            IF (instr. info = NIL) THEN
              originMap := NewOriginMap (NumberOfPaths (instr), numVars);
              instr. info := originMap
            ELSE
              originMap := instr. info(OriginMap);
            END;
            
            IF ~originMap. varIsTraced[origin. marker] THEN
              (* continue tracing the uses of this select; note: this is
                 only done once for each variable, when we encounter the
                 select for the first time *)
              originMap. visible[origin. marker] :=
                  TraceF (instr, instr. GetResultStore());
              originMap. varIsTraced[origin. marker] := TRUE;
            END;
            
            (* set the instruction defining the store argument `use'
               for the variable identified by `origin. marker' *)
            originMap. def[origin. marker, IndexOfPath(use)] := lastDefinition;
            RETURN originMap. visible[origin. marker];

          | Opcode.loopStart:
            originMap := TraceLoopStart (instr, use. OpndIndex());
            RETURN originMap. visible[origin. marker];

          | Opcode.loopEnd:
            IF (use. class = Opnd.backwardFeed) THEN
              (* the backward feed is a honorary member of the loop-start
                 operand list, because it passes values back into the loop *)
              originMap := TraceLoopStart (instr. GetLoopStart(), 1);
              RETURN originMap. visible[origin. marker];
            ELSE
              IF (instr. GetSelectExit() # NIL) THEN
                (* if the loop has a select-exit instruction, then control
                   immediately goes back from the loop-end to the loop-start,
                   and no values are passed beyond the loop-end *)
                RETURN FALSE;
              ELSE
                RETURN TraceF (lastDefinition,
                               instr. GetResultStore());
              END;
            END;
            
          | Opcode.collect, Opcode.newObject:
              RETURN TraceF (lastDefinition, instr. GetResultStore())

          | Opcode.call:
            (* FIXME... detect when a call can modify our variable; for now
               be pessimistic: assume that this call may read and write
               the var *)
            RETURN TRUE;
            
          | Opcode.exit:
            (* the current definitions continues to the select-exit to which
               this EXIT passes the flow of control, but it ends at the place
               of every other use; TraceF() distinguishes between the two
               different kinds of uses and selects the appropriate value
               to pass forward *)
            RETURN TraceF (lastDefinition, instr. GetResultStore())

          | Opcode.return, Opcode.selectReturn:
            (* we've reached the end of the procedure: we are done *)
            RETURN ExternalVisibility (GetVar (origin));
          END;
        END TraceUse;

      PROCEDURE UnreachableUse (definition: SSA.Instr; use: SSA.Opnd): BOOLEAN;
        BEGIN
          IF (definition. opcode = Opcode.return) THEN
            RETURN (use. instr. opcode # Opcode.selectReturn)
          ELSE  (* (definition. opcode = Opcode.exit) *)
            RETURN (use. instr. opcode # Opcode.selectExit)
          END;
        END UnreachableUse;
      
      BEGIN
        visible := FALSE;

        use := storeOut. useList;
        IF (storeOut. instr. opcode # Opcode.exit) &
           (storeOut. instr. opcode # Opcode.return) THEN
          (* the defining instruction is neither an "exit" nor a "return",
             which means we are dealing with a normal flow of control here *)
          WHILE (use # NIL) DO
            IF TraceUse (use) THEN
              visible := TRUE
            END;
            use := use. nextUse
          END;
        ELSE
          WHILE (use # NIL) DO
            IF UnreachableUse (storeOut. instr, use) THEN
              (* the result is produced by an "exit" or "return" instruction,
                 and we are not in the corresponding "select-*": this path of
                 control is unreachable, and the special value
                 "pb.selectReturn" is used to mark this  *)
              oldLastDefinition := lastDefinition;
              lastDefinition := pb. selectReturn;
              dummy := TraceUse (use);
              lastDefinition := oldLastDefinition;
            ELSE  (* normal use *)
              IF TraceUse (use) THEN
                visible := TRUE
              END;
            END;
            use := use. nextUse
          END;
        END;
        RETURN visible
      END TraceF;
    
    BEGIN
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF (instr. marker >= 0) & (instr. opcode = Opcode.set) THEN
          origin := instr;
          originWriteDesign := instr. GetOpndClass (Opnd.writeDesign);
          IF TraceF (instr, instr. GetResultStore()) THEN
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
      get: SSA.Instr;
      getDesign: SSA.Opnd;
      
    PROCEDURE GetStoreOpnd (select: SSA.Instr; pathNum: LONGINT): SSA.Result;
      VAR
        storeIn: SSA.Result;
      BEGIN
        CASE select. opcode OF
        | Opcode.select: storeIn := select. NthArg (pathNum*2+2);
        | Opcode.selectExit: storeIn := select. NthArg (pathNum+1);
        | Opcode.loopStart:
          IF (pathNum = 0) THEN
            storeIn := select. NthArg (pathNum);
          ELSE
            storeIn := select. GetBackwardFeed();
          END;
        END;
        IF (storeIn. instr. opcode = Opcode.collect) THEN
          storeIn := storeIn. instr. GetArgClass (Opnd.store)
        END;
        RETURN storeIn
      END GetStoreOpnd;

    PROCEDURE TraceB (storeIn: SSA.Result): SSA.Result;
    (* Traces @oparam{storeIn} back to definition that defines or may
       define the variable read by the @oparam{get}.  If it finds a 100%
       percent match, it returns the value that should be used in place
       of the original "get" instruction.  *)
      VAR
        instr: SSA.Instr;
        alias: Aliasing.Id;
        
      PROCEDURE TraceSelect (select: SSA.Instr; var: LONGINT;
                             subclass: Opcode.Subclass): SSA.Result;
      (* pre: `select' has opcode "select" or "loopStart" *)
        VAR
          origin: OriginMap;
          i, memoryCount, registerCount, unreachableCount: LONGINT;
          collect, allTheSame: SSA.Instr;

        PROCEDURE GetCollect (select: SSA.Instr; pathNum: LONGINT): SSA.Instr;
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

        PROCEDURE GetValue (source: SSA.Instr): SSA.Result;
          BEGIN
            CASE source. opcode OF
            | Opcode.selectReturn:       (* marks unreachable code *)
              RETURN source
            | Opcode.set:
              RETURN source. GetArgClass (Opnd.sourceValue)
            | Opcode.select:
              RETURN TraceSelect (source, var, subclass)
            | Opcode.loopStart:
              RETURN TraceSelect (source, var, subclass)
            END;
          END GetValue;

        PROCEDURE DuplicateGet (storeIn: SSA.Result): SSA.Instr;
        (* takes the "get" instruction passed to `TraceGetBackward()' and
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

        PROCEDURE IsUnreachable (value: SSA.Instr): BOOLEAN;
          BEGIN
            RETURN (value # NIL) & (value. opcode = Opcode.selectReturn);
          END IsUnreachable;
        
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
                IF (origin. def[var, 1] = NIL) THEN
                  (* the back-edge of the loop does not provide a valid
                     value for the variable: take value from memory *)
                  RETURN NIL;
                ELSE
                  (* place marker that enables us to detect loops when trying
                     to retrieve the variable's variable for an input path *)
                  origin. selectOut[var] := select;
                  value := GetValue (origin. def[var, 1]);
                  IF (value = select) THEN
                    origin. def[var, 1] := origin. def[var, 0];
                  END;
                  (* NOTE: the subsequent statements _must_ overwrite
                     `origin. selectOut[var]', or the loop-start instruction
                     may be replaced into an argument of an instruction *)
                END;
              END;
              
              allTheSame := origin. def[var, 0];
              memoryCount := 0; registerCount := 0; unreachableCount := 0;
              FOR i := 0 TO LEN (origin. def^, 1)-1 DO
                IF (origin. def[var, i] = unknownValue) THEN
                  INC (memoryCount)
                ELSIF IsUnreachable (origin. def[var, i]) THEN
                  INC (unreachableCount)
                ELSE
                  INC (registerCount)
                END;
                IF (origin. def[var, i] # allTheSame) THEN
                  IF IsUnreachable (allTheSame) THEN
                    (* the previous paths are all unreachable, to the current
                       one is the best guess what appears further down *)
                    allTheSame := origin. def[var, i];
                  ELSIF ~IsUnreachable (origin. def[var, i]) THEN
                    (* we got at least two different but not unreachable
                       values: erase `allTheSame' *)
                    allTheSame := NIL
                  END;
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
                    ASSERT (GetValue (origin. def[var,i]) # NIL);
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
                   value; convert this situation into an "all memory" or "all
                   value" scenario; on the assumption that a reads are cheaper
                   than writes, add a "get" for the current value to the
                   branches we know nothing about *)
                FOR i := 0 TO LEN (origin. def^, 1)-1 DO
                  IF ~IsUnreachable (origin. def[var, i]) THEN
                    IF (origin. def[var, i] = unknownValue) THEN
                      value := DuplicateGet (GetStoreOpnd (select, i))
                    ELSE
                      value := GetValue (origin. def[var, i]);
                    END;
                    collect := GetCollect (select, i);
                    ASSERT (value # NIL);
                    collect. AddOpnd (value, Opnd.arg);
                  END;
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
          alias := Aliasing.DesignatorAlias (tr, getDesign, instr. GetOpndClass (Opnd.writeDesign));
          IF (alias = Aliasing.completelyCovered) THEN
            (* this "set" instruction defines the variable we are tracing *)
            RETURN instr. GetArgClass (Opnd.sourceValue)
          ELSIF (alias # Aliasing.noAliasing) THEN
            (* this set operation does not define completely the value read by
               the "get", or no static aliasing calculation can be done: we
               must read the value from memory  *)
            RETURN NIL;
          ELSE
            (* this "set" and "origin" work on different variables, and
               cannot interfere with each other: continue trace through
               `instr' *)
            RETURN TraceB (instr. GetArgClass (Opnd.store))
          END;
          
        | Opcode.enter:
          RETURN NIL;  (* undefined value *)
          
        | Opcode.select:
          RETURN TraceSelect (instr, get. marker, get. subclass);

        | Opcode.collect, Opcode.newObject:
          RETURN TraceB (instr. GetArgClass (Opnd.store));
              
        | Opcode.copyParameter:
          RETURN TraceB (instr. GetArgClass (Opnd.store));
              
        | Opcode.loopStart:
          RETURN TraceSelect (instr, get. marker, get. subclass);

        | Opcode.loopEnd:
          RETURN TraceB (instr. GetArgClass (Opnd.store));

        | Opcode.selectExit:
          RETURN TraceSelect (instr, get. marker, get. subclass);
          
        | Opcode.call:
          (* FIXME... detect when a call can modify our variable; for now
             be pessimistic: the call rewrites our variable *)
          RETURN NIL;
        END;
      END TraceB;
    
    PROCEDURE KeepSetInstr (storeIn: SSA.Result);
    (* Make sure that none of the set operations that feed data to
       `storeIn' and that alias with `get'/`getDesign' are removed.  *)
      VAR
        instr: SSA.Instr;
        alias: Aliasing.Id;
        oldMarker: LONGINT;
      CONST
        markerVisited = MIN (LONGINT);
        
      PROCEDURE TraceSelect (select: SSA.Instr);
      (* pre: `select' has opcode "select" or "loopStart" *)
        VAR
          i: LONGINT;
        BEGIN
          FOR i := 0 TO NumberOfPaths (select)-1 DO
            KeepSetInstr (GetStoreOpnd (select, i));
          END;
        END TraceSelect;
      
      BEGIN
        instr := storeIn. instr;
        IF (instr. marker # markerVisited) THEN
          oldMarker := instr. marker;
          instr. marker := markerVisited;
          CASE instr. opcode OF
          | Opcode.set:
            alias := Aliasing.DesignatorAlias (tr, getDesign, instr. GetOpndClass (Opnd.writeDesign));
            IF (alias = Aliasing.completelyCovered) OR
               (alias # Aliasing.noAliasing) THEN
              instr. info := instr  (* mark instruction as live *)
            ELSE
              KeepSetInstr (instr. GetArgClass (Opnd.store))
            END;
            
          | Opcode.enter:
            (* undefined value, nothing to do *)
            
          | Opcode.return:
            (* when we get here from an instruction that is not a
               select-return, then control never passes from the return to
               this instruction *)
            
          | Opcode.select:
            TraceSelect (instr);

          | Opcode.exit:
            KeepSetInstr (instr. GetArgClass (Opnd.store));
            
          | Opcode.selectExit:
            TraceSelect (instr);
            
          | Opcode.collect:
            KeepSetInstr (instr. GetArgClass (Opnd.store));
            
          | Opcode.copyParameter:
            KeepSetInstr (instr. GetArgClass (Opnd.store));
            
          | Opcode.loopStart:
            TraceSelect (instr);
            
          | Opcode.loopEnd:
            KeepSetInstr (instr. GetArgClass (Opnd.store));
            
          | Opcode.call:
            (* FIXME... detect when a call does alias with our variable; for
               now be pessimistic: the call does not touch it, we must keep the
               `set' instructions before the call *)
            KeepSetInstr (instr. GetArgClass (Opnd.store));
          END;
          instr. marker := oldMarker;
        END;
      END KeepSetInstr;
    
    BEGIN
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF (instr. marker >= 0) & (instr. opcode = Opcode.get) &
           (instr. GetResultStore() = NIL) THEN
          (* don't try to get rid of "get" instructions on volatile variables:
             we must read from memory, because the value might have changed
             behind our back *)
          get := instr;
          getDesign := instr. GetOpndClass (Opnd.readDesign);
          value := TraceB (instr. opndList. arg);
          IF (value # NIL) THEN
            instr. ReplaceUses (value)
          ELSE
            KeepSetInstr (instr. opndList. arg);
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
          storeOut := instr. GetResultStore();
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
    varArray := ArrayList.New(4);
    varMap := IdentifyVars (varArray);
                    
    (* second: for every "set" instruction, establish the visibility of the
       written value in memory *)
    TraceSetForward (varMap. Size());
(*    w := NewWriter (StdChannels.stdout. NewWriter(), varArray);
    w. WriteProcBody (pb, FALSE);*)
    
    (* third: for every "get" instruction, try to trace the store value back
       to the definition from which the "get" reads its result *)
    TraceGetBackward;

    (* fourth: eliminate every "set" instruction that does not have any effect
       inside the procedure, not is visible after it has been completed *)
    RemoveUnusedSet;
  END Transform;

END OOC:SSA:Destore.
