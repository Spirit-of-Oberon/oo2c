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
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Schedule, OOC:SSA:IGraph, OOC:C:DeclWriter;


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

PROCEDURE SubclassToBasicType (subclass: Opcode.Subclass): DeclWriter.BasicTypeId;
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
    END;
  END SubclassToBasicType;

PROCEDURE RegisterType (ctype: DeclWriter.BasicTypeId): DeclWriter.BasicTypeId;
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
        WITH instr: SSA.Const DO
          RETURN FALSE
        | instr: SSA.Address DO
          RETURN FALSE
        ELSE
          RETURN TRUE
        END;
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
      loopHead: Schedule.Block;
      
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

    PROCEDURE InclNonlocalDefines (loopHead, block: Schedule.Block;
                                   live: IGraph.Vector);
      VAR
        nested: Schedule.Block;
        proxy: Schedule.InstrProxy;
        opnd: SSA.Opnd;
      BEGIN
        proxy := block. proxyList;
        WHILE (proxy # NIL) DO
          opnd := proxy. instr. opndList;
          WHILE (opnd # NIL) DO
            IF (opnd. arg. info = rf) THEN
              (* if the argument is from our current register file, and
                 if it is defined outside of `loopHead', then it is live
                 across the whole loop *)
              IF ~Schedule.Dominates
                 (loopHead,
                  rf. blockList. array[opnd. arg. marker](Schedule.Block)) THEN
                rf. iGraph. AddToLive (opnd. arg. marker, live);
              END;
            END;
            opnd := opnd. nextOpnd;
          END;
          proxy := proxy. nextProxy;
        END;
        
        nested := block. domList;
        WHILE (nested # NIL) DO
          InclNonlocalDefines (loopHead, nested, live);
          nested := nested. nextDom;
        END;
      END InclNonlocalDefines;
    
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
          loopHead := NIL;
          IF BackedgeJump (b. branchTo) THEN
            loopHead := b. branchTo. dest;
            DEC (outgoingJumps)
          END;
          IF BackedgeJump (b. jump) THEN
            loopHead := b. jump. dest;
            DEC (outgoingJumps)
          END;
          ld := NewLiveData (rf. iGraph, outgoingJumps);
          IF (loopHead # NIL) THEN
            InclNonlocalDefines (loopHead, loopHead, ld. live);
          END;
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
  
  BEGIN
    rf. iGraph := IGraph.NewGraph (rf. resultList. size);
    
    (* determine set of values life at the end of `exitBlock'; mark all of
       them as interfering with each other *)
    live := rf. iGraph. NewVector();
    (* ...FIXME: having an empty set is ok when starting at the end of
       the procedure, but a hierarchical allocator that may begin its sweep
       in the middle of the procedure requires non-empty starting sets *)

    (* sweep life set backwards over blocks; if a life range begins at a
       instruction, remove it from the life set, if ends there, then add it
       to the life set; each time a new entry is added, it must be marked
       as interfering with all current elements of the set *)
    TraverseBlocks (rf, exitBlock, live);
    rf. iGraph. SymmetricMatrix;

    (* calculate a coloring for the resulting graph; use the coloring to
       assign register ids to results *)
    AssignRegisterNames (rf, rf. iGraph. ColorGraphSimple(), registerMap);
  END AssignRegisterFile;

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

  PROCEDURE WriteNames (w: DeclWriter.Writer;
                        registerType: DeclWriter.BasicTypeId;
                        names: NameArray);
    VAR
      i: LONGINT;
    BEGIN
      IF (LEN (names^) # 0) THEN
        w. WriteLn;
        w. WriteString ("  register ");
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
  
  BEGIN
    exitBlock := pb. selectReturn. info(Schedule.InstrProxy). block;
    enterBlock := domRoot;
    pb. SetMarkers (NIL, -1);
    domRoot. SetInfo (NIL);

    (* calculate for each register set the results that are mapped to this
       set *)
    blockList := GetBlockList (enterBlock, exitBlock);
    rfs := IdentifyResults (blockList);

    (* assign concrete registers for every result; this is done for each of
       the different register files *)
    registerMap := Dictionary.New();
    FOR i := 0 TO LEN (rfs^)-1 DO
      IF (rfs[i] # NIL) THEN
        AssignRegisterFile (rfs[i], enterBlock, exitBlock, registerMap);
        WriteNames (w, rfs[i]. registerType, rfs[i]. names);
      END;
    END;
    RETURN registerMap
  END AssignRegisters;

END OOC:SSA:Allocator.
