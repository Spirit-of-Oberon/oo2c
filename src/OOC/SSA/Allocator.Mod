(* 	$Id$	 *)
MODULE OOC:SSA:Allocator;
(*  A register allocator for the C back-end.
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
  IntStr, Strings, ADT:ArrayList, ADT:Dictionary, ADT:String,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd,
  OOC:SSA:Schedule, OOC:SSA:IGraph, OOC:C:DeclWriter;


TYPE
  BlockList = POINTER TO ARRAY OF Schedule.Block;
  NameArray = POINTER TO ARRAY OF String.String;
  
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
    | Opcode.scAddress: RETURN DeclWriter.ptr
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
      RETURN DeclWriter.int32
    | DeclWriter.real32, DeclWriter.real64:
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
    rfs[DeclWriter.int32] := NewRegisterFile (DeclWriter.int32);
    rfs[DeclWriter.real64] := NewRegisterFile (DeclWriter.real64);
    RETURN rfs
  END GetRegisterFiles;

PROCEDURE IdentifyResults (blockList: BlockList): RegisterFiles;
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
        RETURN ~instr. IsConst();
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
        IF (type # Opcode.scNone) & PassedThroughRegister (instr) THEN
          RegisterResult (instr, SubclassToBasicType (type));
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

PROCEDURE SweepLiveSet (rf: RegisterFile; b: Schedule.Block;
                        live: IGraph.Vector);
  VAR
    iGraph: IGraph.Graph;
    proxy: Schedule.InstrProxy;
    res: SSA.Result;
    opnd: SSA.Opnd;
  BEGIN
    iGraph := rf. iGraph;

    WITH b: Schedule.BranchBlock DO
      (* the predicate that is evaluated at the end of a branch block must
         be live at the end of the block *)
      res := b. predicate. arg;
      IF (res. info = rf) & ~iGraph. In (res. marker, live) THEN
        iGraph. AddToLive (res. marker, live);
      END;
    ELSE  (* nothing to do *)
    END;
    
    proxy := b. proxyTail;
    WHILE (proxy # NIL) DO
      res := proxy. instr;
      WHILE (res # NIL) DO
        IF (res. info = rf) & (res. useList = NIL) THEN
          (* this is a pathological case: the instruction leaves a result in
             a register, but its value is never used; in effect this 
             corresponds to an empty live range that interferes with nothing;
             but since a register is overwritten here, it _does_ interfere with
             everything live at this point in practice *)
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
      
      (* every argument of the instruction is checked whether it starts a
         live range and is placed into the live vector if it does *)
      opnd := proxy. instr. opndList;
      WHILE (opnd # NIL) DO
        IF (opnd. arg. info = rf) THEN
          IF ~iGraph. In (opnd. arg. marker, live) THEN
            (* the live range of the value passed to `opnd' interferes with all
               live ranges currently active: calculate union between bit matrix
               (row `opnd.arg.marker') and the live vector *)
            iGraph. AddToLive (opnd. arg. marker, live)
          END
        END;
        opnd := opnd. nextOpnd
      END;
      
      proxy := proxy. prevProxy
    END;

    WITH b: Schedule.SwitchBlock DO
      (* the select expression that is evaluated at the beginning
         switch must be live at the beginning of the block *)
      res := b. expr. arg;
      IF (res. info = rf) & ~iGraph. In (res. marker, live) THEN
        iGraph. AddToLive (res. marker, live);
      END;
    ELSE  (* nothing to do *)
    END;
  END SweepLiveSet;

PROCEDURE AssignRegisterFile (rf: RegisterFile;
                              enterBlock, exitBlock: Schedule.Block;
                              deadEnds: ArrayList.ArrayList;
                              registerMap: Dictionary.Dictionary);
  VAR
    live: IGraph.Vector;
    i: LONGINT;
    
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

      (* determine variable name for every color id *)
      NEW (names, maxColor+1);
      FOR i := 0 TO maxColor DO
        IntStr.IntToStr (i, str);
        CASE rf. registerType OF
        | DeclWriter.int32:
          Strings.Insert ("i", 0, str);
        | DeclWriter.real64:
          Strings.Insert ("r", 0, str);
        END;
        names[i] := String.New (str);
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
      outgoingJumps: LONGINT;
      
    PROCEDURE Propagate (jump: Schedule.Jump);
      BEGIN
        WHILE (jump # NIL) DO
          IF ~jump. isLoopBackedge THEN
            (* don't follow back-edges of loops *)
            ASSERT (jump. dest = b);
            TraverseBlocks (rf, jump. src, rf. iGraph. CopyVector (live));
          END;
          jump := jump. nextTargetUse
        END;
      END Propagate;

    PROCEDURE BackedgeJump (jump: Schedule.Jump): BOOLEAN;
      BEGIN
        RETURN
            (jump = NIL) OR
            (jump. dest. isLoopHead & jump. isLoopBackedge)
      END BackedgeJump;

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
        rf. iGraph. MergeVector (live, ld. live);
        INC (ld. knownJumps);
        
        IF (ld. knownJumps = ld. outgoingJumps) THEN
          live := ld. live;
          SweepLiveSet (rf, b, live);
          IF (b # enterBlock) THEN
            Propagate (b. targetUseList)
          END;
          b. info := NIL;                (* clean up when done *)
        END;
        
      ELSE  (* JumpBlock and DeadEndBlock *)
        SweepLiveSet (rf, b, live);
        IF (b # enterBlock) THEN
          Propagate (b. targetUseList)
        END
      END;
    END TraverseBlocks;

  (*PROCEDURE WriteConflicts (rf: RegisterFile);
    VAR
      i, j: LONGINT;
      res: SSA.Result;
    BEGIN
      FOR i := 0 TO rf. resultList. size-1 DO
        res := rf. resultList. array[i](SSA.Result);
        Err.LongInt (i, 0);
        Err.String ("/");
        Err.Hex (SYSTEM.VAL(LONGINT,res), 8);
        Err.String (":");
        FOR j := 0 TO rf. resultList. size-1 DO
          IF rf. iGraph. Conflicts (i, j) THEN
            Err.Char (" ");
            Err.LongInt (j, 0);
          END;
        END;
        Err.Ln;
      END;
    END WriteConflicts;*)
  
  BEGIN
    rf. iGraph := IGraph.NewGraph (rf. resultList. size);
    
    (* sweep life set backwards over blocks; if a life range begins at a
       instruction, remove it from the life set, if ends there, then add it
       to the life set; each time a new entry is added, it must be marked
       as interfering with all current elements of the set *)
    FOR i := 0 TO deadEnds. size-1 DO
      live := rf. iGraph. NewVector();
      TraverseBlocks (rf, deadEnds. array[i](Schedule.Block), live);
    END;
    rf. iGraph. SymmetricMatrix;
    (*WriteConflicts (rf);*)

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
  
  BEGIN
    IF b. isLoopHead THEN
      closestLoop := b;
    END;
    IF (closestLoop # NIL) THEN
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        opnd := proxy. instr. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd. arg. info = rf) THEN
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
    registerMap: Dictionary.Dictionary;
    deadEnds: ArrayList.ArrayList;

  PROCEDURE LocateDeadEnds (root: Schedule.Block): ArrayList.ArrayList;
    VAR
      deadEnds: ArrayList.ArrayList;

    PROCEDURE CheckBlock (b: Schedule.Block);
      VAR
        child: Schedule.Block;
        outgoingJumps: LONGINT;
        
     PROCEDURE BackedgeJump (jump: Schedule.Jump): BOOLEAN;
       BEGIN
         RETURN
             (jump. dest. isLoopHead & jump. isLoopBackedge)
       END BackedgeJump;

      BEGIN
        WITH b: Schedule.BranchBlock DO
          outgoingJumps := 2;
          IF BackedgeJump (b. branchTo) THEN
            DEC (outgoingJumps)
          END;
          IF BackedgeJump (b. jump) THEN
            DEC (outgoingJumps)
          END;
          
        | b: Schedule.JumpBlock DO
          outgoingJumps := 1;
          IF BackedgeJump (b. jump) THEN
            DEC (outgoingJumps)
          END;

        | b: Schedule.DeadEndBlock DO
          outgoingJumps := 0;

        | b: Schedule.SwitchBlock DO
          outgoingJumps := LEN (b. jump^);
          FOR i := 0 TO LEN (b. jump^)-1 DO
            IF BackedgeJump (b. jump[i]) THEN
              DEC (outgoingJumps);
            END;
          END;
        END;

        IF (outgoingJumps = 0) THEN
          deadEnds. Append (b);
        END;

        child := b. domList;
        WHILE (child # NIL) DO
          CheckBlock (child);
          child := child. nextDom
        END;
      END CheckBlock;
    
    BEGIN
      deadEnds := ArrayList.New(4);
      CheckBlock (root);
      RETURN deadEnds
    END LocateDeadEnds;
  
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
          w. WriteString (names[i]. array^);
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
  
  BEGIN
    exitBlock := pb. selectReturn. info(Schedule.InstrProxy). block;
    enterBlock := domRoot;
    pb. SetMarkers (NIL, -1);
    domRoot. SetInfo (NIL);

    (* calculate for each register set the results that are mapped to this
       set *)
    blockList := GetBlockList (enterBlock, exitBlock);
    rfs := IdentifyResults (blockList);

    (* for each loop, add all values (which are stored in registers) that are
       used within the loop, but are defined outside the loop, to the argument
       list of the collect instruction  *)
    FOR i := 0 TO LEN (rfs^)-1 DO
      IF (rfs[i] # NIL) THEN
        CollectCrossLoopResults (rfs[i], domRoot, NIL);
      END;
    END;
    
    (* locate all blocks that a dead ends from the point of view of the
       interference calculation; that is, get a list of all blocks whose
       live set if known to be empty at their end *)
    deadEnds := LocateDeadEnds (enterBlock);
    
    (* assign concrete registers for every result; this is done for each of
       the different register files *)
    registerMap := Dictionary.New();
    FOR i := 0 TO LEN (rfs^)-1 DO
      IF (rfs[i] # NIL) THEN
        ClearBlockInfo (blockList);
        AssignRegisterFile (rfs[i], enterBlock, exitBlock, deadEnds,
                            registerMap);
        WriteNames (w, rfs[i]. registerType, rfs[i]. names);
      END;
    END;
    RETURN registerMap
  END AssignRegisters;

END OOC:SSA:Allocator.
