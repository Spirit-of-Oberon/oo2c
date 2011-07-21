(* 	$Id: Allocator.Mod,v 1.36 2003/04/05 18:55:58 mva Exp $	 *)
MODULE OOC:SSA:Allocator;
(*  A register allocator for the C back-end.
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

<*DEFINE DEBUG_ALLOCATOR := FALSE*>

IMPORT
  Log,
  <*IF DEBUG_ALLOCATOR THEN*>SYSTEM,Err,<*END*>
  IntStr, Strings, Object, ADT:ArrayList, ADT:Dictionary,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Result,
  OOC:SSA:Schedule, OOC:SSA:IGraph, OOC:C:DeclWriter, OOC:SymbolTable:Predef;


TYPE
  BlockList = POINTER TO ARRAY OF Schedule.Block;
  NameArray = POINTER TO ARRAY OF STRING;
  
TYPE
  RegisterFile = POINTER TO RegisterFileDesc;
  RegisterFiles = POINTER TO ARRAY OF RegisterFile;
  RegisterFileDesc = RECORD
    (SSA.NodeDesc)
    registerType: DeclWriter.BasicTypeId;
    resultList: ArrayList.ArrayList;     (* of SSA.Result *)
    blockList: ArrayList.ArrayList;      (* of Schedule.Block *)
    iGraph: IGraph.Graph;
    maxColor: IGraph.Color;
    names: NameArray;
  END;

TYPE
  LiveData = POINTER TO LiveDataDesc;
  LiveDataDesc = RECORD
    (Schedule.InfoDesc)
    outgoingJumps: LONGINT;
    knownJumps: LONGINT;
    live: IGraph.Vector;
  END;

TYPE
  State = Dictionary.Dictionary;
  (* Keeps track of the current values stored in register variables.  The
     dictionary maps the names of register variables onto instances of
     @otype{SSA.Result}, or one of the special values defined below.

     For a given name @var{n}, @samp{State.get(@var{n})} can have one of these
     meanings:

     @table @asis
     @item Key @var{n} does not exist.
     In this case, the variable has not been set on any path leading to the
     current state.  Use of this variable is an error.

     @item @samp{State.get(@var{n})} equals @ovar{undefinedVar}.
     The variable has been set on different paths leading to this state, but
     the possibly different values has not been merged by means of one of the
     @samp{select} instructions.  Use of this variable is an error.

     @item Otherwise:
     In all other cases, the variable is mapped to an instance of
     @otype{SSA.Result}, meaning that its current value has been produced by
     the given result of an SSA instruction.
     @end table  *)

TYPE
  BlockInfo* = POINTER TO BlockInfoDesc;
  BlockInfoDesc = RECORD
    (Schedule.InfoDesc)
    nextInfo: BlockInfo;
    block: Schedule.Block;
    mergeInstr: SSA.Instr;
    initState: State;
    inCollect: POINTER TO ARRAY OF SSA.Instr;
    inState: POINTER TO ARRAY OF State;
    marker: LONGINT;
  END;
  
VAR
  markInPlace-: SSA.Result;
  
PROCEDURE NewRegisterFile (registerType: DeclWriter.BasicTypeId): RegisterFile;
  VAR
    rf: RegisterFile;
  BEGIN
    NEW (rf);
    SSA.InitNode (rf);
    rf. registerType := registerType;
    rf. resultList := ArrayList.New (16);
    rf. blockList := ArrayList.New (16);
    rf. iGraph := NIL;
    rf. maxColor := -1;
    rf. names := NIL;
    RETURN rf
  END NewRegisterFile;

PROCEDURE NewLiveData (g: IGraph.Graph; outgoingJumps: LONGINT): LiveData;
  VAR
    ld: LiveData;
  BEGIN
    NEW (ld);
    Schedule.InitInfo (ld);
    ld. outgoingJumps := outgoingJumps;
    ld. knownJumps := 0;
    ld. live := g. NewVector();
    RETURN ld
  END NewLiveData;

PROCEDURE GetBlockList (enterBlock, exitBlock: Schedule.Block): BlockList;
(**Calculates the list of blocks reachable from @oparam{enterBlock}.  Search
   ends after @oparam{exitBlock}.  Both @oparam{enterBlock} and
   @oparam{exitBlock} are included in the list.

   @precond
   The block's @ofield{Schedule.Block.info} fields are unused.
   @end precond  *)
  VAR
    mark: Schedule.Info;
    al: ArrayList.ArrayList;
    bl: BlockList;
    i: LONGINT;

  PROCEDURE ScanBlock (b: Schedule.Block);
    VAR
      i: LONGINT;
    BEGIN
      IF (b # NIL) & (b. info # mark) THEN
        b. info := mark;

        al. Append (b);

        IF (b # exitBlock) THEN
          WITH b: Schedule.BranchBlock DO
            ScanBlock (b. branchTo. dest);
            ScanBlock (b. jump. dest);
          | b: Schedule.JumpBlock DO
            ScanBlock (b. jump. dest);
          | b: Schedule.DeadEndBlock DO
            (* nowhere to go *)
          | b: Schedule.SwitchBlock DO
            FOR i := 0 TO LEN (b. jump^)-1 DO
              ScanBlock (b. jump[i]. dest);
            END;
          END;
        END;
      END;
    END ScanBlock;
  
  BEGIN
    NEW (mark);                          (* unique value *)
    al := ArrayList.New (16);

    ScanBlock (enterBlock);

    NEW (bl, al. size);
    FOR i := 0 TO LEN (bl^)-1 DO
      bl[i] := al. array[i](Schedule.Block);
      bl[i]. info := NIL;                (* unmark again *)
    END;
    RETURN bl
  END GetBlockList;

PROCEDURE SubclassToBasicType* (subclass: Opcode.Subclass): DeclWriter.BasicTypeId;
  (**Maps a subclass id to a basic type of the C back-end.  *)
  BEGIN
    CASE subclass OF
    | Opcode.scNone: RETURN DeclWriter.void
    | Opcode.scAddress:
      CASE Predef.address OF
      | Predef.hugeint: RETURN DeclWriter.int64;
      | Predef.longint: RETURN DeclWriter.int32;
      END;
    | Opcode.scUnsigned8: RETURN DeclWriter.uint8
    | Opcode.scUnsigned16: RETURN DeclWriter.uint16
    | Opcode.scUnsigned32: RETURN DeclWriter.uint32
    | Opcode.scUnsigned64: RETURN DeclWriter.uint64
    | Opcode.scSigned8: RETURN DeclWriter.int8
    | Opcode.scSigned16: RETURN DeclWriter.int16
    | Opcode.scSigned32: RETURN DeclWriter.int32
    | Opcode.scSigned64: RETURN DeclWriter.int64
    | Opcode.scReal32: RETURN DeclWriter.real32
    | Opcode.scReal64: RETURN DeclWriter.real64
    END;
  END SubclassToBasicType;

PROCEDURE RegisterType* (ctype: DeclWriter.BasicTypeId): DeclWriter.BasicTypeId;
(* Maps a basic type of the C back-end to the type of the register in which
   is value should be stored.

   Note: For every possible result returned by this function, a corresponding
   entry must appear in the output of @oproc{GetRegisterFiles} below.  *)
  BEGIN
    CASE ctype OF
    | DeclWriter.ptr,
      DeclWriter.int8 .. DeclWriter.int32,
      DeclWriter.uint8 .. DeclWriter.uint32:
      CASE Predef.address OF
      | Predef.hugeint: RETURN DeclWriter.int64;
      | Predef.longint: RETURN DeclWriter.int32;
      END;
    | DeclWriter.int64, DeclWriter.uint64:
      RETURN DeclWriter.int64;
    | DeclWriter.real32:
      RETURN DeclWriter.real32
    | DeclWriter.real64:
      RETURN DeclWriter.real64
    END;
  END RegisterType;

PROCEDURE GetRegisterFiles (): RegisterFiles;
(* Produces an array with empty entries for all possible register files.  *)
  VAR
    rfs: RegisterFiles;
    i: LONGINT;
  CONST
    size = DeclWriter.real64+1;
  BEGIN
    NEW (rfs, size);
    FOR i := 0 TO LEN (rfs^)-1 DO
      rfs[i] := NIL;
    END;
    CASE Predef.address OF
    | Predef.longint:
      rfs[DeclWriter.int32] := NewRegisterFile (DeclWriter.int32);
      rfs[DeclWriter.int64] := NewRegisterFile (DeclWriter.int64);
    | Predef.hugeint:
      (* 32 bit register variables are not used on 64 bit targets *)
      rfs[DeclWriter.int64] := NewRegisterFile (DeclWriter.int64);
    END;
    rfs[DeclWriter.real32] := NewRegisterFile (DeclWriter.real32);
    rfs[DeclWriter.real64] := NewRegisterFile (DeclWriter.real64);
    RETURN rfs
  END GetRegisterFiles;

PROCEDURE IdentifyResults (blockList: BlockList;
                           inPlaceEval: Dictionary.Dictionary): RegisterFiles;
(**Identifies all results of instructions from @oparam{blockList} that are
   stored in registers.  These results are added to the
   @ofield{RegisterFile.resultList}, their containing block to
   @ofield{RegisterFiles.blockList}, their @ofield{SSA.Result.info} is changed
   to refer to its instance of @otype{RegisterFile}, and
   @ofield{SSA.Result.marker} is set to the index of the result in the list
   @ofield{RegisterFile.resultList}.

   Results that produce symbolic values that are of importance on the SSA
   level, but do not correspond to tangible values on the C level, are ignored.  *)
  VAR
    i: LONGINT;
    rfs: RegisterFiles;
    
  PROCEDURE ScanBlock (b: Schedule.Block);
    VAR
      proxy: Schedule.InstrProxy;
      instr: SSA.Instr;
      res: SSA.Result;
      type: Opcode.Subclass;
      
    PROCEDURE PassedThroughRegister (instr: SSA.Instr): BOOLEAN;
    (* Result is TRUE if `instr' produces a result that is passed through
       a register to all uses of this value.  Note: Non-instruction results
       that produce tangible values are _always_ passed through registers.  *)
      BEGIN
        RETURN ~instr. IsConst() &
            (instr.opcode # Opcode.set) &
            (instr.opcode # Opcode.tryStart);
      END PassedThroughRegister;

    PROCEDURE RegisterResult (result: SSA.Result;
                              ctype: DeclWriter.BasicTypeId);
      VAR
        rtype: DeclWriter.BasicTypeId;
      BEGIN
        rtype := RegisterType (ctype);
        result. info := rfs[rtype];
        result. marker := rfs[rtype]. resultList. size;
        rfs[rtype]. resultList. Append (result);
        rfs[rtype]. blockList. Append (b);
      END RegisterResult;
    
    BEGIN
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        instr := proxy. instr;
        type := instr. GetResultType();
        IF (type # Opcode.scNone) &
           PassedThroughRegister (instr) THEN
          IF inPlaceEval. HasKey (instr)  THEN
            instr. info := markInPlace;
          ELSE
            RegisterResult (instr, SubclassToBasicType (type));
          END;
        END;
        res := instr. nextResult;
        WHILE (res # NIL) DO
          IF (res. subclass # Opcode.scNone) THEN
            RegisterResult (res, SubclassToBasicType (res. subclass))
          END;
          res := res. nextResult
        END;
        proxy := proxy. nextProxy
      END;
    END ScanBlock;
  
  BEGIN
    rfs := GetRegisterFiles();
    FOR i := 0 TO LEN (blockList^)-1 DO
      ScanBlock (blockList[i])
    END;
    RETURN rfs
  END IdentifyResults;

PROCEDURE AddToCollect (loopHead: Schedule.Block; res: SSA.Result);
  VAR
    loopStart: Schedule.InstrProxy;
    collect: SSA.Instr;
    opnd: SSA.Opnd;
    backwardFeed: SSA.Result;
  BEGIN
    loopStart := loopHead. proxyList;
    WHILE (loopStart. instr. opcode # Opcode.loopStart) DO
      loopStart := loopStart. nextProxy
    END;
    backwardFeed := loopStart. instr. GetBackwardFeed();
    collect := backwardFeed. instr;
    opnd := collect. opndList;
    WHILE (opnd # NIL) & (opnd. arg # res) DO
      opnd := opnd. nextOpnd;
    END;
    IF (opnd = NIL) THEN
      collect. AddOpnd (res, Opnd.loopExternalDef);
    END;
  END AddToCollect;

<*IF DEBUG_ALLOCATOR THEN*>
PROCEDURE WriteRes (res: SSA.Result);
  VAR
    index: LONGINT;
  BEGIN
    Err.Hex (SYSTEM.VAL(LONGINT,res.instr), 8);
    index := res. ResultIndex();
    IF (index # 0) THEN
      Err.Char (".");
      Err.LongInt (index, 0);
    END;
  END WriteRes;
<*END*>

PROCEDURE SweepLiveSet (rf: RegisterFile; b: Schedule.Block;
                        live: IGraph.Vector): Schedule.Block;
(* Result is loop block into whose collect any cross loop results have been
   merged, or NIL otherwise.  *)
  VAR
    iGraph: IGraph.Graph;
    proxy, loopEnd: Schedule.InstrProxy;
    res: SSA.Result;
    loopBlock: Schedule.Block;
    i: LONGINT;

  PROCEDURE GetLoop (b: Schedule.Block; loopStart: SSA.Instr): Schedule.Block;
    VAR
      child: Schedule.Block;
    
    PROCEDURE ContainsInstr (proxy: Schedule.InstrProxy; instr: SSA.Instr): BOOLEAN;
      BEGIN
        WHILE (proxy # NIL) & (proxy. instr # instr) DO
          proxy := proxy. nextProxy;
        END;
        RETURN (proxy # NIL);
      END ContainsInstr;
    
    BEGIN
      child := b. domList;
      WHILE (child # NIL) & ~ContainsInstr (child. proxyList, loopStart) DO
        child := child. nextDom;
      END;
      IF (child = NIL) THEN
        RETURN GetLoop (b. parent, loopStart);
      ELSE
        RETURN child;
      END;
    END GetLoop;

  PROCEDURE MarkOpndAsLive (instr: SSA.Instr; live: IGraph.Vector);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      opnd := instr. opndList;
      WHILE (opnd # NIL) DO
        IF (opnd. arg. info = markInPlace) THEN
          MarkOpndAsLive (opnd. arg. instr, live);
        ELSIF (opnd. arg. info = rf) & opnd. IsValueOpndHere() THEN
          IF ~iGraph. In (opnd. arg. marker, live) THEN
            (* the live range of the value passed to `opnd' interferes with
               all live ranges currently active: calculate union between bit
               matrix (row `opnd.arg.marker') and the live vector  *)
            iGraph. AddToLive (opnd. arg. marker, live)
          END
        END;
        opnd := opnd. nextOpnd
      END;
    END MarkOpndAsLive;

  PROCEDURE AddResToLive (res: SSA.Result; live: IGraph.Vector);
    BEGIN
      IF (res. info = markInPlace) THEN
        MarkOpndAsLive (res. instr, live);
      ELSIF (res. info = rf) & ~iGraph. In (res. marker, live) THEN
        iGraph. AddToLive (res. marker, live);
      END;
    END AddResToLive;
  
  <*IF DEBUG_ALLOCATOR THEN*>
  PROCEDURE WriteLive (b: Schedule.Block; msg: ARRAY OF CHAR;
                       live: IGraph.Vector);
    VAR
      i: LONGINT;
    BEGIN
      Err.String (msg);
      Err.String (" live set: ");
      Err.Hex (SYSTEM.VAL (LONGINT, b), 8);
      Err.String ("  ");
      FOR i := 0 TO rf. resultList. size-1 DO
        IF iGraph. In (i, live) THEN
          Err.Char (" ");
          WriteRes (rf. resultList. array[i](SSA.Result));
        END;
      END;
      Err.Ln;
    END WriteLive;
  <*END*>
  
  BEGIN
    iGraph := rf. iGraph;
    <*IF DEBUG_ALLOCATOR THEN*>WriteLive (b, "end of block", live);<*END*>
    
    WITH b: Schedule.BranchBlock DO
      (* the predicate that is evaluated at the end of a branch block must
         be live at the end of the block *)
      AddResToLive (b. predicate. arg, live);
    ELSE  (* nothing to do *)
    END;

    loopEnd := NIL;
    proxy := b. proxyTail;
    WHILE (proxy # NIL) DO
      IF (proxy. instr. opcode = Opcode.loopEnd) THEN
        loopEnd := proxy;
      END;
      
      res := proxy. instr;
      IF (res. info # markInPlace) THEN
        WHILE (res # NIL) DO
          IF (res. info = rf) & (res. useList = NIL) THEN
            (* this is a pathological case: the instruction leaves a result in
               a register, but its value is never used; in effect this
               corresponds to an empty live range that interferes with nothing;
               but since a register is overwritten here, it _does_ interfere
               with everything live at this point in practice  *)
            iGraph. AddToLive (res. marker, live);
          END;
          res := res. nextResult;
        END;
        
        (* remove all results produced by this instruction from our live set *)
        res := proxy. instr;
        WHILE (res # NIL) DO
          IF (res. info = rf) THEN
            iGraph. RemoveFromLive (res. marker, live);
          END;
          res := res. nextResult;
        END;
        
        (* Every argument of the instruction is checked whether it starts a
           live range and is placed into the live vector if it does.

           The first argument of "select" is skipped (by means of
           IsValueOpnd()), because the select instruction appears after the
           selection expression and the paths it selects, and the selection
           expression is only live at the place at which control flow branches
           (read: at the end of BranchBlock, or the beginning of SwitchBlock).  *)
        MarkOpndAsLive (proxy. instr, live);
      END;
      
      proxy := proxy. prevProxy
    END;

    WITH b: Schedule.SwitchBlock DO
      (* the select expression that is evaluated at the beginning
         switch must be live at the beginning of the block *)
      AddResToLive (b. expr. arg, live);
    ELSE  (* nothing to do *)
    END;

    <*IF DEBUG_ALLOCATOR THEN*>WriteLive (b, "beg of block", live);<*END*>
    
    IF (loopEnd # NIL) THEN
      loopBlock := GetLoop (loopEnd. block. parent,
                            loopEnd. instr. GetLoopStart());
      FOR i := 0 TO rf. resultList. size-1 DO
        IF iGraph. In (i, live) &
           ~Schedule.Dominates (loopBlock, rf. blockList. array[i](Schedule.Block)) THEN
          AddToCollect (loopBlock, rf. resultList. array[i](SSA.Result));
        END;
      END;
      RETURN loopBlock;
    ELSE
      RETURN NIL;
    END;
  END SweepLiveSet;

PROCEDURE AssignRegisterFile (rf: RegisterFile;
                              enterBlock, exitBlock: Schedule.Block;
                              registerMap: Dictionary.Dictionary);
  VAR
    live: IGraph.Vector;
    
  PROCEDURE AssignRegisterNames (rf: RegisterFile;
                                 colors: IGraph.ColorArray;
                                 registerMap: Dictionary.Dictionary);
    VAR
      i: LONGINT;
      maxColor: IGraph.Color;
      names: NameArray;
      str: ARRAY 16 OF CHAR;
    BEGIN
      (* find out the maximum of all assigned colors *)
      maxColor := -1;
      FOR i := 0 TO LEN (colors^)-1 DO
        IF (colors[i] > maxColor) THEN
          maxColor := colors[i]
        END;
      END;
      rf. maxColor := maxColor;

      (* determine variable name for every color id; needs to be coordinated
         with OOC:C:Naming.NameOfDeclaration.IsReservedName *)
      NEW (names, maxColor+1);
      FOR i := 0 TO maxColor DO
        IntStr.IntToStr (i, str);
        CASE rf. registerType OF
        | DeclWriter.int32:
          Strings.Insert ("i", 0, str);
        | DeclWriter.int64:
          CASE Predef.address OF
          | Predef.longint:
            Strings.Insert ("w", 0, str);
          | Predef.hugeint:
            Strings.Insert ("i", 0, str);
          END;
        | DeclWriter.real32:
          Strings.Insert ("f", 0, str);
        | DeclWriter.real64:
          Strings.Insert ("d", 0, str);
        END;
        names[i] := Object.NewLatin1(str);
      END;
      rf. names := names;
      
      (* assign each result the name of "its" register *)
      FOR i := 0 TO LEN (colors^)-1 DO
        registerMap. Set (rf. resultList. array[i](SSA.Result),
                          names[colors[i]]);
      END;
    END AssignRegisterNames;

  PROCEDURE TraverseBlocks (rf: RegisterFile;
                            b: Schedule.Block;
                            live: IGraph.Vector);
  (**The vector in @oparam{live} is a life set active at the beginning of one
     of the blocks that are directly reached from the end of @oparam{b}.
     If the life sets for all directly reachable target blocks are known,
     compute the union of all the sets and use it to calculate the life set
     valid at the beginning of @oparam{b}.

     In the process, extend the interference graph with the data from
     @oparam{b}.  *)
    VAR
      ld: LiveData;
      outgoingJumps, i: LONGINT;
      loopBlock: Schedule.Block;
      
    PROCEDURE Propagate (jump: Schedule.Jump; loopBlock: Schedule.Block);
      VAR
        loopTarget: Schedule.Jump;
      BEGIN
        WHILE (jump # NIL) DO
          IF ~jump. isLoopBackedge THEN
            (* don't follow back-edges of loops *)
            ASSERT (jump. dest = b);
            TraverseBlocks (rf, jump. src, rf. iGraph. CopyVector (live));
          END;
          jump := jump. nextTargetUse
        END;
        IF (loopBlock # NIL) THEN
          (* don't pass in the current live vector, because it contains
             entries that are not live at the backward jump; the values that
             are live have been merged into the loop's back-edge collect *)
          loopTarget := loopBlock. targetUseList;
          WHILE (loopTarget # NIL) & ~loopTarget. isLoopBackedge DO
            loopTarget := loopTarget. nextTargetUse;
          END;
          IF (loopTarget # NIL) THEN
            TraverseBlocks (rf, loopTarget. src, rf. iGraph. NewVector());
          END;
        END;
      END Propagate;

    PROCEDURE BackedgeJump (jump: Schedule.Jump): BOOLEAN;
      BEGIN
        RETURN
            (jump = NIL) OR
            (jump. dest. isLoopHead & jump. isLoopBackedge)
      END BackedgeJump;

    PROCEDURE Merge (ld: LiveData);
      BEGIN
        rf. iGraph. MergeVector (live, ld. live);
        INC (ld. knownJumps);
        ASSERT (ld. knownJumps <= ld. outgoingJumps);
        
        IF (ld. knownJumps = ld. outgoingJumps) THEN
          live := ld. live;
          loopBlock := SweepLiveSet (rf, b, live);
          IF (b # enterBlock) THEN
            Propagate (b. targetUseList, loopBlock)
          END;
          b. info := NIL;                (* clean up when done *)
        END;
      END Merge;
    
    BEGIN
      (* a. for normal source blocks, do the same sweep
         b. for branch blocks, merge the life sets of both jump targets
            before doing the sweep
         c. for a loop branch, the back edge does not contribute to the life
            set, but all results that are defined outside the loop and are
            used within it are live at the end of the branch *)

      WITH b: Schedule.BranchBlock DO
        IF (b. info = NIL) THEN
          outgoingJumps := 2;
          IF BackedgeJump (b. branchTo) THEN
            DEC (outgoingJumps)
          END;
          IF BackedgeJump (b. jump) THEN
            DEC (outgoingJumps)
          END;
          ld := NewLiveData (rf. iGraph, outgoingJumps);
          b. info := ld
        ELSE
          ld := b. info(LiveData);
        END;
        Merge (ld);

      | b: Schedule.SwitchBlock DO
        IF (b. info = NIL) THEN
          outgoingJumps := LEN (b. jump^);
          FOR i := 0 TO LEN (b. jump^)-1 DO
            IF BackedgeJump (b. jump[i]) THEN
              DEC (outgoingJumps);
            END;
          END;
          ld := NewLiveData (rf. iGraph, outgoingJumps);
          b. info := ld
        ELSE
          ld := b. info(LiveData);
        END;
        Merge (ld);
        
      ELSE  (* JumpBlock and DeadEndBlock *)
        loopBlock := SweepLiveSet (rf, b, live);
        IF (b # enterBlock) THEN
          Propagate (b. targetUseList, loopBlock)
        END
      END;
    END TraverseBlocks;

  <*IF DEBUG_ALLOCATOR THEN*>
  PROCEDURE WriteConflicts (rf: RegisterFile);
    VAR
      i, j: LONGINT;
      res: SSA.Result;
    BEGIN
      FOR i := 0 TO rf. resultList. size-1 DO
        res := rf. resultList. array[i](SSA.Result);
        Err.LongInt (i, 0);
        Err.String ("/");
        WriteRes (res);
        Err.String (":");
        FOR j := 0 TO rf. resultList. size-1 DO
          IF rf. iGraph. Conflicts (i, j) THEN
            Err.Char (" ");
            WriteRes (rf. resultList. array[j](SSA.Result));
          END;
        END;
        Err.Ln;
      END;
    END WriteConflicts;
  <*END*>
  
  BEGIN
    rf. iGraph := IGraph.NewGraph (rf. resultList. size);
    
    (* sweep life set backwards over blocks; if a life range begins at a
       instruction, remove it from the life set, if ends there, then add it
       to the life set; each time a new entry is added, it must be marked
       as interfering with all current elements of the set *)
    live := rf. iGraph. NewVector();
    TraverseBlocks (rf, exitBlock, live);
    rf. iGraph. SymmetricMatrix;
    <*IF DEBUG_ALLOCATOR THEN*>WriteConflicts (rf);<*END*>

    (* calculate a coloring for the resulting graph; use the coloring to
       assign register ids to results *)
    AssignRegisterNames (rf, rf. iGraph. ColorGraphSimple(), registerMap);
  END AssignRegisterFile;

PROCEDURE CollectCrossLoopResults (rf: RegisterFile;
                                   b: Schedule.Block;
                                   closestLoop: Schedule.Block);
  VAR
    child, loop: Schedule.Block;
    proxy: Schedule.InstrProxy;
    opnd: SSA.Opnd;
  BEGIN
    IF b. isLoopHead THEN
      closestLoop := b;
    END;
    IF (closestLoop # NIL) THEN
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        opnd := proxy. instr. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd. arg. info = rf) & opnd. IsValueOpnd() THEN
            (* if the argument is from our current register file, and
               if it is defined outside of `loopHead', then it is live
               across the whole loop *)
            loop := closestLoop;
            WHILE (loop # NIL) &
                  ~Schedule.Dominates
                  (loop,
                   rf. blockList. array[opnd. arg. marker](Schedule.Block)) DO
              AddToCollect (loop, opnd. arg);
              REPEAT
                loop := loop. parent;
              UNTIL (loop = NIL) OR loop. isLoopHead;
            END;
          END;
          opnd := opnd. nextOpnd;
        END;
        proxy := proxy. nextProxy;
      END;
    END;
    
    child := b. domList;
    WHILE (child # NIL) DO
      CollectCrossLoopResults (rf, child, closestLoop);
      child := child. nextDom
    END;
  END CollectCrossLoopResults;

PROCEDURE AssignRegisters* (pb: SSA.ProcBlock; domRoot: Schedule.Block;
                            w: DeclWriter.Writer): Dictionary.Dictionary;
(**Assigns registers to values produced by SSA instructions.  For the moment, a
   very simple allocator is sufficient: every value gets its very own variable.
   The C compiler will have to deal with this ;-)

   @precond
   The fields @ofield{SSA.Result.marker} and @ofield{SSA.Result.info} of all
   instructions in @oparam{pb} are not in use.
   @end precond  *)
  VAR
    exitBlock, enterBlock: Schedule.Block;
    blockList: BlockList;
    rfs: RegisterFiles;
    i: LONGINT;
    registerMap, inPlaceEval: Dictionary.Dictionary;
    keys: Object.ObjectArrayPtr;

  PROCEDURE WriteNames (w: DeclWriter.Writer;
                        registerType: DeclWriter.BasicTypeId;
                        names: NameArray);
    VAR
      i: LONGINT;
    BEGIN
      IF (LEN (names^) # 0) THEN
        w. Newline;
        w. WriteString ("register ");
        w. WriteString (w. basicType[registerType]. repr);
        w. WriteChar (" ");

        FOR i := 0 TO LEN (names^)-1 DO
          IF (i # 0) THEN
            w. WriteChar (",");
          END;
          w. WriteObject (names[i]);
        END;
        w. WriteChar (";");
      END;
    END WriteNames;

  PROCEDURE ClearBlockInfo (blockList: BlockList);
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO LEN (blockList^)-1 DO
        blockList[i]. info := NIL;
      END;
    END ClearBlockInfo;

  PROCEDURE CheckRegisters (root: Schedule.Block;
                            registerMap: Dictionary.Dictionary);
    VAR
      ready, current: BlockInfo;
      undefinedVar: SSA.Result;

    PROCEDURE ScanBlock (b: Schedule.Block);
      VAR
        bi: BlockInfo;
        child: Schedule.Block;

      PROCEDURE MergeInstr (proxy: Schedule.InstrProxy): SSA.Instr;
        BEGIN
          WHILE (proxy # NIL) DO
            CASE proxy. instr. opcode OF
            | Opcode.select, Opcode.loopStart, Opcode.loopEnd:
              RETURN proxy. instr;
            ELSE
            END;
            proxy := proxy. nextProxy;
          END;
          RETURN NIL;
        END MergeInstr;
      
      BEGIN
        NEW (bi);
        Schedule.InitInfo (bi);
        bi. nextInfo := NIL;
        bi. block := b;
        bi. initState := NIL;
        bi. mergeInstr := MergeInstr (b. proxyList);
        IF (b. parent = NIL) THEN (* change back to zero for top-level block *)
          ASSERT (b = root);
          bi. marker := b. degreeIn-1;
        ELSE
          bi. marker := b. degreeIn;
        END;
        IF (bi. marker > 1) THEN
          ASSERT (bi. mergeInstr # NIL);
        END;
        NEW (bi. inCollect, bi. marker);
        NEW (bi. inState, bi. marker);
        
        IF (bi. marker = 0) THEN
          IF (b. parent = NIL) THEN
            (* only add the root block to the ready list; discard any other
               unrechable blocks within the procedure *)
            bi. nextInfo := ready;
            ready := bi;
            bi. inCollect := NIL;
            bi. inState := NIL;
            bi. initState := Dictionary.New();
          ELSE
            ASSERT ((b. domList = NIL) OR
                    (b. domList IS Schedule.DeadEndBlock));
          END;
        ELSE
          (* Note: Due to the presence of unreachable blocks, it is possible
             that there are blocks that may never be changed to "ready".  These
             blocks are only reachable from unreachable blocks, and will never
             be touched by `CheckRegisters'.  Since the waiting queue is (in
             general) not shrunk to the empty set, no explicit waiting queue is
             kept.  *)
        END;
        b. info := bi;

        child := b. domList;
        WHILE (child # NIL) DO
          ScanBlock (child);
          child := child. nextDom;
        END;
      END ScanBlock;

    PROCEDURE CheckBlock (bi: BlockInfo; state: State);
      VAR
        proxy: Schedule.InstrProxy;
        collect: SSA.Instr;
        res: SSA.Result;
        b: Schedule.Block;
        i: LONGINT;

      PROCEDURE UpdateTarget (jump: Schedule.Jump; state: State;
                              collect: SSA.Instr);
        VAR
          di: BlockInfo;

        PROCEDURE MergeVariables (di: BlockInfo): State;
        (* pre: di.mergeInstr # NIL *)
          VAR
            outState: State;
            allVarsMap: Dictionary.Dictionary;
            vars: Object.ObjectArrayPtr;
            i, j: LONGINT;
            value: Object.Object;
          BEGIN
            (* if the merge has results that represent values passed from its
               "collect" instructions, then we must simply rely on the back-end
               to move the collected values into the registers mandated by the
               results of the merging instruction *)

            (* create a list of variable names that are defined on at least
               one path into this merge *)
            allVarsMap := Dictionary.New();
            FOR i := 0 TO LEN (di. inState^)-1 DO
              vars := di. inState[i]. Keys();
              FOR j := 0 TO LEN (vars^)-1 DO
                allVarsMap. Set (vars[j], NIL);
              END;
            END;
            vars := allVarsMap. Keys();
            
            outState := Dictionary.New();
            FOR i := 0 TO LEN (di. inState^)-1 DO
              FOR j := 0 TO LEN (vars^)-1 DO
                IF di. inState[i]. HasKey (vars[j]) THEN
                  (* this path defines a value for the variable vars[j] *)
                  value := di. inState[i]. Get (vars[j]);
                  IF outState. HasKey (vars[j]) THEN
                    IF (outState. Get (vars[j]) # value) THEN
                      (* value on path disagrees with that on another path *)
                      outState. Set (vars[j], undefinedVar);
                    END;
                  ELSE  (* first encounter of this variable *)
                    outState. Set (vars[j], value);
                  END;
                ELSE
                  (* this path doesn't define vars[j], but another does:
                     the variable is undefined *)
                  outState. Set (vars[j], undefinedVar);
                END;
              END;
            END;
            
            (* for every result of the merging instruction that is passed in
               a register, set the register variable to point to the result
               instance *)
            res := di. mergeInstr. nextResult. nextResult;
            WHILE (res # NIL) DO
              ASSERT (res. class = Result.selectValue);
              IF registerMap. HasKey (res) THEN
                outState. Set (registerMap. Get (res), res);
              END;
              res := res. nextResult;
            END;

            RETURN outState;
          END MergeVariables;
        
        BEGIN
          di := jump. dest. info(BlockInfo);
          ASSERT (di. marker > 0);
          DEC (di. marker);
          di. inCollect[di. marker] := collect;
          di. inState[di. marker] := state. Copy();
          IF (di. marker = 0) THEN
            (* merge state arriving at this block from all possible sources *)
            IF (di. mergeInstr # NIL) THEN
              di. initState := MergeVariables (di);
            ELSE
              ASSERT (LEN (di. inState^) = 1);
              di. initState := di. inState[0];
            END;
            
            (* add to `ready' queue *)
            di. nextInfo := ready;
            ready := di;
          END;
        END UpdateTarget;

      PROCEDURE ^ CheckOpndList (instr: SSA.Instr);
        
      PROCEDURE CheckOpnd (opnd: SSA.Opnd);
        VAR
          obj: Object.Object;
          defVar: STRING;
          currentValue: SSA.Result;
        BEGIN
          IF registerMap. HasKey (opnd. arg) THEN
            (* the variable that holds the result `opnd.arg' must be known
               at this point *)
            obj := registerMap. Get (opnd. arg);
            IF (obj = markInPlace) THEN
              CheckOpndList (opnd. arg. instr);
            ELSE
              defVar := obj(STRING);
              ASSERT (state. HasKey (defVar));
              
              (* the current value of the variable must be the expected
                 result *)
              obj := state. Get (defVar);
              currentValue := obj(SSA.Result);
              IF currentValue # opnd. arg THEN
                opnd. instr. LogId ("using instruction");
                Log.LongInt ("  operand index", opnd. OpndIndex());
                opnd. arg. LogId ("  expected value");
                currentValue. LogId ("  actual value");
                ASSERT (FALSE);
              END;
            END;
          END;
        END CheckOpnd;

      PROCEDURE CheckOpndList (instr: SSA.Instr);
        VAR
          opnd: SSA.Opnd;
        BEGIN
          (* for every operand that takes its value from a register variable,
             check that the value of the expected result is still stored in the
             register variable at the place of use *)
          opnd := instr. opndList;
          IF (instr. opcode = Opcode.select) THEN
            (* the first argument of a "select" is actually used elsewhere:
               for a SwitchBlock at the beginning of the block, and in a
               BranchBlock at the end *)
            opnd := opnd. nextOpnd;
          END;
          WHILE (opnd # NIL) DO
            IF opnd. IsValueOpndHere() THEN
              CheckOpnd (opnd);
            END;
            opnd := opnd. nextOpnd;
          END;
        END CheckOpndList;
      
      BEGIN
        collect := NIL;

        b := bi. block;
        IF (b IS Schedule.SwitchBlock) THEN
          CheckOpnd (b(Schedule.SwitchBlock). expr);
        END;
        
        proxy := b. proxyList;
        WHILE (proxy # NIL) DO
          IF (proxy. instr. opcode = Opcode.collect) THEN
            ASSERT (collect = NIL);
            ASSERT (proxy. nextProxy = NIL);
            collect := proxy. instr;
          ELSIF (proxy. instr. opcode = Opcode.select) THEN
            ASSERT (proxy = b. proxyList);
          END;

          IF (proxy. instr. info # markInPlace) THEN
            CheckOpndList (proxy. instr);
            
            res := proxy. instr;
            WHILE (res # NIL) DO
              (* for every result that is written to a register variable, update
                 the state to map the register variable to this result *)
              IF registerMap. HasKey (res) THEN
                state. Set (registerMap. Get (res), res);
              END;
              
              res := res. nextResult;
            END;
          END;
          
          proxy := proxy. nextProxy;
        END;
        
        IF (b IS Schedule.BranchBlock) THEN
          CheckOpnd (b(Schedule.BranchBlock). predicate);
        END;
        
        WITH b: Schedule.JumpBlock DO
          UpdateTarget (b. jump, state, collect);
        | b: Schedule.BranchBlock DO
          UpdateTarget (b. jump, state, collect);
          UpdateTarget (b. branchTo, state, collect);
        | b: Schedule.SwitchBlock DO
          FOR i := 0 TO LEN (b. jump^)-1 DO
            UpdateTarget (b. jump[i], state, collect);
          END;
        | b: Schedule.DeadEndBlock DO
          (* nothing to do *)
        END;
      END CheckBlock;
    
    BEGIN
      undefinedVar := SSA.NewResult(NIL, -1, -1);
      ready := NIL;
      ScanBlock (root);
      ASSERT (ready # NIL);
      ASSERT (ready. nextInfo = NIL);
      (* here holds: the ready list holds exactly one block, the root block
         dominating all other blocks in the procedure *)

      WHILE (ready # NIL) DO
        current := ready;
        ready := ready. nextInfo;
        CheckBlock (current, current. initState);
      END;
    END CheckRegisters;

  PROCEDURE InPlaceEval (pb: SSA.ProcBlock): Dictionary.Dictionary;
    VAR
      instr, useInstr: SSA.Instr;
      use: SSA.Opnd;
      inPlaceEval: Dictionary.Dictionary;
      insideUse, outsideUse: LONGINT;
      instrBlock: Schedule.Block;

    PROCEDURE FoldedOpcode (opcode: Opcode.Class): BOOLEAN;
      BEGIN
       CASE opcode OF
        | Opcode.call, Opcode.get, Opcode.copyParameter,
          Opcode.const, Opcode.address,
          Opcode.getLengthHeap, Opcode.getLengthParam:
          RETURN FALSE;
        ELSE
          RETURN TRUE;
        END;
      END FoldedOpcode;
    
    BEGIN
      inPlaceEval := Dictionary.New();
      
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF (instr. subclass # Opcode.scNone) &
           (instr. info # NIL) &
           FoldedOpcode (instr. opcode) THEN
          instrBlock := instr. info(Schedule.InstrProxy). block;

          insideUse := 0; outsideUse := 0;
          use := instr. useList;
          WHILE (use # NIL) DO
            IF use. IsValueOpndHere() THEN
              useInstr := use. instr;
              IF (useInstr. opcode # Opcode.collect) &
                 (useInstr. info(Schedule.InstrProxy). block = instrBlock) THEN
                INC (insideUse);
              ELSE
                INC (outsideUse);
              END;
            END;
            use := use. nextUse;
          END;
          IF (instrBlock IS Schedule.BranchBlock) &
             (instrBlock(Schedule.BranchBlock). predicate. arg = instr) THEN
            INC (insideUse);
          END;
          
          IF (outsideUse = 0) & (insideUse = 1) THEN
            inPlaceEval. Set (instr, NIL);
          END;
        END;
        instr := instr. nextInstr;
      END;

      RETURN inPlaceEval;
    END InPlaceEval;
  
  <*IF DEBUG_ALLOCATOR THEN*>
  PROCEDURE WriteBlock (b: Schedule.Block; indent: LONGINT);
    VAR
      i: LONGINT;
      child: Schedule.Block;
      proxy: Schedule.InstrProxy;
      opnd: SSA.Opnd;
      name: ARRAY 256 OF CHAR;

    PROCEDURE Indent();
      BEGIN
        FOR i := 1 TO indent DO
          Err.String ("  ");
        END;
      END Indent;
    
    PROCEDURE Id (b: Schedule.Block);
      BEGIN
        WITH b: Schedule.SwitchBlock DO
          Err.String ("SB(");
        | b: Schedule.DeadEndBlock DO
          Err.String ("DEB(");
        | b: Schedule.JumpBlock DO
          Err.String ("JB(");
        | b: Schedule.BranchBlock DO
          Err.String ("BB(");
        END;
        Err.Hex (SYSTEM.VAL(LONGINT,b), 8);
        Err.String (")");
      END Id;
    
    BEGIN
      Err.Ln;
      Indent;
      Err.String ("<<");
      Id (b);
      Err.String ("[");
      Err.LongInt (b. degreeIn, 0);
      Err.String ("]");
      WITH b: Schedule.SwitchBlock DO
        FOR i := 0 TO LEN (b. jump^)-1 DO
          Err.String (" -->");
          Id (b. jump[i]. dest);
        END;
      | b: Schedule.DeadEndBlock DO
      | b: Schedule.JumpBlock DO
        Err.String (" -->");
        Id (b. jump. dest);
      | b: Schedule.BranchBlock DO
        IF b. branchOnTrue THEN
          Err.String (" true");
        ELSE
          Err.String (" false");
        END;
        Err.String ("-->");
        Id (b. branchTo. dest);
        IF b. branchOnTrue THEN
          Err.String (" false");
        ELSE
          Err.String (" true");
        END;
        Err.String ("-->");
        Id (b. jump. dest);
      END;
      Err.String (">>");
      Err.Ln;
      
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        Indent;
        Err.Hex (SYSTEM.VAL (LONGINT, proxy. instr), 8);
        Err.Char (" ");
        Opcode.GetName (proxy. instr. opcode, proxy. instr. subclass, name);
        Err.String (name);
        
        opnd := proxy. instr. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd. class = Opnd.loopExternalDef) THEN
            Err.String (" loopExternalDef");
          END;
          opnd := opnd. nextOpnd;
        END;
        
        Err.Ln;
        proxy := proxy. nextProxy;
      END;
      
      child := b. domList;
      WHILE (child # NIL) DO
        WriteBlock (child, indent+1);
        child := child. nextDom;
      END;
    END WriteBlock;
  <*END*>
  
  BEGIN
    <*IF DEBUG_ALLOCATOR THEN*>
    Log.Ln;
    Log.String ("### allocating registers", pb. procDecl. name. str^);
    <*END*>
    (* for the C back-end, mark results that are not stored in register
       variables, but are computed at the place where they are used *)
    inPlaceEval := InPlaceEval (pb);
    
    exitBlock := pb. selectReturn. info(Schedule.InstrProxy). block;
    enterBlock := domRoot;
    pb. SetMarkers (NIL, -1);
    domRoot. SetInfo (NIL);

    (* calculate for each register set the results that are mapped to this
       set *)
    blockList := GetBlockList (enterBlock, exitBlock);
    rfs := IdentifyResults (blockList, inPlaceEval);

    (* for each loop, add all values (which are stored in registers) that are
       used within the loop, but are defined outside the loop, to the argument
       list of the collect instruction  *)
    FOR i := 0 TO LEN (rfs^)-1 DO
      IF (rfs[i] # NIL) THEN
        CollectCrossLoopResults (rfs[i], domRoot, NIL);
      END;
    END;
    
    <*IF DEBUG_ALLOCATOR THEN*>WriteBlock (domRoot, 0);<*END*>
    
    (* assign concrete registers for every result; this is done for each of
       the different register files *)
    registerMap := Dictionary.New();
    FOR i := 0 TO LEN (rfs^)-1 DO
      IF (rfs[i] # NIL) THEN
        ClearBlockInfo (blockList);
        AssignRegisterFile (rfs[i], enterBlock, exitBlock, registerMap);
        WriteNames (w, rfs[i]. registerType, rfs[i]. names);
      END;
    END;
    keys := inPlaceEval. Keys();
    FOR i := 0 TO LEN (keys^)-1 DO
      registerMap. Set (keys[i], markInPlace);
    END;
    
    (* Sanity check: Traverse instructions from the beginning to the end of
       the procedure, keeping track which register variable is in use, and
       which value it holds.  Complain if the usage of a variable does not
       match its current content.  *)
    (*Blocker.WriteMarker (StdChannels.stderr, pb, registerMap);*)
    CheckRegisters (domRoot, registerMap);
    
    RETURN registerMap
  END AssignRegisters;

BEGIN
  markInPlace := SSA.NewResult(NIL, -1, -1);
END OOC:SSA:Allocator.
