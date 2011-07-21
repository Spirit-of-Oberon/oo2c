MODULE OOC:X86:SSA;

IMPORT
  Object, Object:Boxed, Object:BigInt, IntDict := ADT:Dictionary:IntValue,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  TR := OOC:SymbolTable:TypeRules;

TYPE
  Opcode* = SHORTINT;
  Register* = SHORTINT;
  AdrMode* = SHORTINT;
  Type* = SHORTINT;
  DepType* = SHORTINT;

CONST  (* Register Names: *)
  sp* = 0;                               (* stack pointer, esp *)
  fp* = 1;                               (* frame pointer, ebp *)
  cc* = 2;                               (* condition codes *)
  gp0* = 3;                              (* eax *)
  gp1* = 4;                              (* ecx *)
  gp2* = 5;                              (* edx *)
  gp3* = 6;                              (* ebx *)
  gp4* = 7;                              (* esi, not byte addressable *)
  gp5* = 8;                              (* edi, not byte addressable *)
  st0* = 9;                              (* x87 register st(0) *)
  fp0* = 10;                             (* xmm0 *)
  fp1* = 11;                             (* xmm1 *)
  fp2* = 12;                             (* xmm2 *)
  fp3* = 13;                             (* xmm3 *)
  fp4* = 14;                             (* xmm4 *)
  fp5* = 15;                             (* xmm5 *)
  fp6* = 16;                             (* xmm6 *)
  fp7* = 17;                             (* xmm7 *)
  resultRegister* = gp0;                 (* register for function results *)
  resultRegisterFp* = st0;               (* register for fp function results *)
  lastRegister* = fp7;                   (* maximum of all register ids *)

  callerSaved* = {gp0, gp1, gp2, st0, fp0..fp7};
  calleeSaved* = {sp, fp, gp3, gp4, gp5};

  lastFpRegister* = 7;
  
CONST  (* Addressing Modes of Locations: *)
  register* = 0;
  (**Value is held in the register itself.  *)
  indirect* = 1;
  (**Value is held in memory, at the address pointed to by the register.  The
     address can be modified by a constant offset.  *)
  noLocation* = -1;
  (**Used if the location has not been determined yet.  *)
  
CONST  (* Instruction Opcodes: *)
  opcodeArithmetic = 0;
  const* = opcodeArithmetic+0;
  (**A value that is constant at run-time.  The precise value may or may not be
     known at compile time.  The instruction's @ofield{Instr.designator} field
     holds the final value or a symbolic representation thereof.

     Usually, @ofield{Instr.designator} is of length one.  For addresses of
     global variables, it may have additional entries.  These are integer
     constants that need to be added to the address at index zero.  *)
  add* = opcodeArithmetic+1;
  sub* = opcodeArithmetic+2;
  mul* = opcodeArithmetic+3;
  div* = opcodeArithmetic+4;
  neg* = opcodeArithmetic+5;
  asr* = opcodeArithmetic+6;
  (**Arithmetic shift right.  That is, the left hand side is a signed number,
     and its sign is preserved by the shift operation.  *)
  asl* = opcodeArithmetic+7;
  (**Arithmetic (and logical) shift left.  *)
  lsr* = opcodeArithmetic+8;
  (**Logical shift right.  *)
  lsl* = opcodeArithmetic+9;
  (**Logical (and arithmetic) shift left.  *)
  rr* = opcodeArithmetic+10;
  (**Rotate right.  *)
  rl* = opcodeArithmetic+11;
  (**Rotate left.  *)
  indexed* = opcodeArithmetic+12;
  eql* = opcodeArithmetic+13;
  neq* = opcodeArithmetic+14;
  lss* = opcodeArithmetic+15;
  leq* = opcodeArithmetic+16;
  gtr* = opcodeArithmetic+17;
  geq* = opcodeArithmetic+18;
  setBool* = opcodeArithmetic+19;
  (**Set byte to @code{0} or @code{1}, depending on the current state of the
     condition codes.  *)
  bitTestAndSet* = opcodeArithmetic+20;
  bitTestAndClear* = opcodeArithmetic+21;
  typeConv* = opcodeArithmetic+22;
  fpLoad* = opcodeArithmetic+23;
  fpStorePop* = opcodeArithmetic+24;
  
  opcodeFunctionFraming = opcodeArithmetic+26;
  enter* = opcodeFunctionFraming+0;
  (**An ``enter'' instruction represents the state of the processor immediately
     after control has passed from the caller to the current function.  Its
     results are the current value of various processor registers, like the
     current stack pointer.  *)
  exit* = opcodeFunctionFraming+1;
  (**The ``exit'' instruction is the mirror image of ``enter''.  Its operands
     describe the processor state immediately before control is returned from
     the function.

     In the assembler output, this instruction is translated to a low-level
     ``return'' instruction.  *)
  return* = opcodeFunctionFraming+2;
  (**Corresponds to a function's @code{RETURN} instruction.  Its is a kind of
     copy instruction, transferring the returned value into the appropriate
     processor register.  It has one argument, the value that should be
     returned, and one result, whose location is that of the result register.

     The argument matches the type of the target register.  If necessary, a
     type conversion instruction is insert to extend the argument to a 32 bit
     value.  *)
  call* = opcodeFunctionFraming+3;
  (**First operand is the called address, and the second the current stack
     pointer.  The rest of the operand list are the actual function parameters.  *)
  bounceResult* = opcodeFunctionFraming+4;
  (**Copies a floating point value from register @samp{st0} into one of the
     SSE2 registers @samp{xmm}.  *)
  function* = opcodeFunctionFraming+5;
  (**This is the block that represents the whole function.  *)
  allocateStack* = opcodeFunctionFraming+6;
  (**Allocate space for local variables on stack.  *)
  standin* = opcodeFunctionFraming+7;
  (**A ``standin'' instruction is a foothold of non-instruction data on a value
     that is part of the function's code.  The instruction has a single
     operand, holding the value of interest to the external data structure; it
     has no results, nor any uses.  This construction implements a level of
     indirection that allows an outside data structure to refer to a value
     whose representation may change due to code transformations.

     The instruction does not contribute to the output of function.  Its
     operand is marked as ``immediate'', so that the argument is not kept live
     for this instruction only.  Standin instructions are not subject to code
     transformations; in particular, two standins are not unified even if they
     have the same argument.  A standin instruction can only be deleted by the
     data that holds the reference to it.  *)
  
  opcodeMemory = opcodeFunctionFraming+8;
  get* = opcodeMemory+0;
  (**@code{get} @var{address} *)
  set* = opcodeMemory+1;
  (**@code{set} @var{address} @var{value} *)
  copy* = opcodeMemory+2;
  typeCast* = opcodeMemory+3;
  loadRegister* = opcodeMemory+4;
  push* = opcodeMemory+5;
  pop* = opcodeMemory+6;
  leave* = opcodeMemory+7;
  getLengthHeap* = opcodeMemory+8;
  setStack* = opcodeMemory+9;
  (**Set stack element to the given value.  First argument is the current stack
     pinter, second the offset relative to the top of the stack, and the third
     the value.

     Instructions of this kind are part of an expanded call statement, where
     the arguments that are passed via the stack are removed from the call's
     operand list and converted into @oconst{setStack} instructions.

     This instruction duplicates the memory dependencies of its call
     instruction, and the call in turn has memory dependencies on all its
     @oconst{setStack} instructions.  *)
  typeTag* = opcodeMemory+10;
  
  opcodeControlFlow = opcodeMemory+12;
  branch* = opcodeControlFlow+0;
  (**A branch is a place in a function were control may continue to one of two
     (or more) mutually exclusive paths.  Each path is represented by a
     @oconst{guard} instruction.

     Branches are used in two slightly different contexts.  In a
     statement-level context, there is a single @oconst{merge} instruction that
     pulls all paths through the branch together again.  That is, if control
     enters through a statement-level branch, then it always leaves through the
     merge instruction.  (Nonlocal exits like @code{RETURN} and @code{EXIT}
     have no effect on the general branch structure.) The merge instruction can
     be located through the function @oproc{Instr.TopLevelMerge}.

     In an expression-level context, a branch is created for one of the
     shortcut operators @code{OR} or @code{&}.  Such a branch has no
     @oconst{merge} instruction of its own.  From its @oconst{guard}s, control
     is passed on either to another @oconst{guard} or another branch's
     @oconst{merge}.

     In a @code{IF} statement, the branch instruction has a single argument
     that is either the boolean constant @code{0} or @code{1}.  In a
     @code{CASE} statement, the branch instructions have an even number of
     arguments, a lower and upper limit taken from an element of the list of
     labels.  The special case of an no-argument @oconst{branch} represents the
     @code{ELSE} part of the @code{CASE}.  *)
  guard* = opcodeControlFlow+1;
  merge* = opcodeControlFlow+2;
  (**Instructions with opcode @oconst{merge} are part of a class of
     instructions that mark the place within a function where control may
     continue from different preceeding instructions.  Conceptually, they are
     part of a (statement-level) @oconst{branch} instruction and, in the
     hierarchical block structure generated by
     @oproc{*OOC:X86:Block.ArrangeInstructions}, are the last instruction
     within their associated @oconst{branch}.  Merge instructions are reached
     through @oconst{jump}s, and when control gets to the end of the merge, it
     continues right after the branch instruction.  *)
  jump* = opcodeControlFlow+3;
  gate* = opcodeControlFlow+4;
  designatorGate* = opcodeControlFlow+5;
  (* Helper instruction for module Destore.  *)
  loopStart* = opcodeControlFlow+6;
  loopEnd* = opcodeControlFlow+7;
  loopExit* = opcodeControlFlow+8;
  loopBackedge* = opcodeControlFlow+9;
  (**From this instruction control passes back to the loop's start.  This means
     that there is an implicit control and memory dependency from
     @oconst{loopStart} onto this instruction.  This dependency is @emph{not}
     made explicit to avoid cyclic instruction dependencies.  *)
  
CONST  (* Operand and Result Types: *)
  noType* = 0;
  signed8* = 1;
  (**Designates a signed 8 bit result or operand.  *)
  signed16* = 2;
  (**Designates a signed 16 bit result or operand.  *)
  signed32* = 3;
  (**Designates a signed 32 bit result or operand.  *)
  signed64* = 4;
  (**Designates a signed 64 bit result or operand.  *)
  unsigned8* = 5;
  (**Designates an unsigned 8 bit result or operand.  *)
  unsigned16* = 6;
  (**Designates an unsigned 16 bit result or operand.  *)
  unsigned32* = 7;
  (**Designates an unsigned 32 bit result or operand.  *)
  unsigned64* = 8;
  (**Designates an unsigned 64 bit result or operand.  *)
  address* = 9;
  (**Designates an address or pointer result or operand.  Please note that
     the intermediate code treats this as a separate type, even if it is
     mapped to a 32 or 64 bit integer type in the end.  *)
  boolean* = unsigned8;
  (**Maps to the integer type that is used to store boolean values.  *)
  length* = signed32;
  (**Maps to the integer type that is used to store length of arrays.  *)
  real32* = 10;
  (**Single precision IEEE-754 floating point number.  *)
  real64* = 11;
  (**Double precision IEEE-754 floating point number.  *)
  gpRegisterType* = signed32;
  fpRegisterType* = real64;

TYPE
  Node* = POINTER TO NodeDesc;
  Opnd* = POINTER TO OpndDesc;
  Result* = POINTER TO ResultDesc;
  Instr* = POINTER TO InstrDesc;
  InstrList* = Object.ObjectArrayPtr(Instr);
  Block* = POINTER TO BlockDesc;
  BlockList* = Object.ObjectArrayPtr(Block);
  
TYPE
  Selector* = POINTER TO SelectorDesc;
  Designator* = POINTER TO ARRAY OF Selector;
  SelectorDesc = RECORD [ABSTRACT]
  END;
  Global* = POINTER TO GlobalDesc;
  GlobalDesc = RECORD [ABSTRACT]
    (SelectorDesc)
  END;
  Var* = POINTER TO VarDesc;
  VarDesc = RECORD
    (**In a designator associated with a @oconst{get} or @oconst{set}
       instruction, this selector refers to a variable, be it local, global, or
       from an enclosing procedure.

       When used as part of @oconst{const} instruction, then it refers to the
       address of a variable.  There are four slightly different
       interpretations, depending on the sort of variable in the designator:

       @table @asis
       @item Local variable of a function
       The result of the @oconst{const} is the offset of the local variable or
       parameter relative to the function's frame pointer.
       @item Length of an array parameter
       The result of the @oconst{const} is the offset of the length parameter
       relative to the function's frame pointer.
       @item Designator is @code{NIL}
       This means the size of local variable area of the current function.
       @item Global variable of a module
       The address of the variable in the process's address space.
       @end table  *)
    (GlobalDesc)
    decl-: Sym.VarDecl;
    dim-: LONGINT;
  END;
  Proc* = POINTER TO ProcDesc;
  ProcDesc = RECORD
    (**In a designator associated with a @oconst{get} or @oconst{set}
       instruction, this selector refers to a variable, be it local, global, or
       from an enclosing procedure.

       When used as part of @oconst{const} instruction, it refers to the offset
       of the loval variable or parameter relative to the function's frame
       pointer.  The special case @code{NIL} means the size of local variable
       area.  *)
    (GlobalDesc)
    decl-: Sym.ProcDecl;
  END;
  ProcName* = POINTER TO ProcNameDesc;
  ProcNameDesc = RECORD
    (**Refers to the address of the global function @ofield{name}.  *)
    (GlobalDesc)
    name-: STRING;
  END;
  TypeDescr* = POINTER TO TypeDescrDesc;
  TypeDescrDesc = RECORD
    (**Refers to the address of the type descriptor of @ofield{type}.  *)
    (GlobalDesc)
    type-: Sym.Type;
  END;
  ModuleDescr* = POINTER TO ModuleDescrDesc;
  ModuleDescrDesc = RECORD
    (**Refers to the address of the module descriptor of the current module.  *)
    (GlobalDesc)
  END;
  Const* = POINTER TO ConstDesc;
  ConstDesc = RECORD
    (SelectorDesc)
    value-: Object.Object;
    (**Either a @otype{Boxed.Object} or @otype{BranchInstr}.  *)
    type-: Sym.PredefId;
    (**This field holds a type id from module @omodule{Predef} or @samp{-1}.
       It is used to distinguish the size of integer constants and the type of
       string constants.  A string constant is identified by its address in the
       program, but the code generator needs to now if the address points to a
       sequence of 1, 2, or 4 byte values.  *)
  END;
  HeapObj* = POINTER TO HeapObjDesc;
  HeapObjDesc = RECORD
    (**Address of an object on the heap. *)
    (SelectorDesc)
    type-: Sym.Type;
    adrStandin-: Instr;
  END;
  Index* = POINTER TO IndexDesc;
  IndexDesc = RECORD
    (**Array index. *)
    (SelectorDesc)
    indexStandin-: Instr;
  END;
  Field* = POINTER TO FieldDesc;
  FieldDesc = RECORD
    (**Record field. *)
    (SelectorDesc)
    field-: Sym.FieldDecl;
  END;
  
TYPE
  NodeDesc* = RECORD
    (Object.ObjectDesc)
  END;
  
TYPE
  OpndDesc = RECORD 
    (NodeDesc)
    arg-: Result;
    (**Reference to a result of an instruction that defines this operand's
       value.  *)
    nextOpnd-: Opnd;
    (**This field refers to the next element in the list of operands of an
       instruction.  The head of the list is stored in @ofield{Instr.opndList}.  *)
    instr-: Instr;
    (**The instruction to which this operand belongs.  *)
    nextUse-: Opnd;
    (**Links that make up the ``uses'' list of a given @otype{Result} value.
       By traversing this list, all using occurences of a result are reached.
       The head of the list is @ofield{Result.useList}.  *)
    immediate*: BOOLEAN;
    (**If @code{TRUE}, then the value referred to by this operand is computed
       implicitly as part of the operand's instruction, instead of being
       materialized explicitly as a separate expression.  This is used to model
       immediate operands and addressing modes involving offsets and indices,
       for example by modeling the offset as an @oconst{add} operation.

       This field is can be set if

       @itemize @bullet
       @item
       the argument is a constant and the constant should be encoded as an
       immediate operand of the instruction,
       @item
       the argument is part of an address computation that is part of a memory
       operand of the instruction, or
       @item
       the operand's instruction has special properties, like @oconst{standin}.
       @end itemize  *)
  END;

TYPE
  ResultDesc = RECORD 
    (NodeDesc)
    nextResult-: Result;
    (**Next result in list of results.  The head of the list is stored in
       @ofield{Instr.resultList}.  *)
    instr-: Instr;
    (**The instruction to which this result belongs.  *)
    useList-: Opnd;
    (**List of uses (use-chain) of this result.  Uses are linked with
       @ofield{Opnd.nextUse}.  *)
    
    type-: Type;
    (**One of the signed, unsigned, ir floating point result types.  *)
    
    register*: Register;
    (**The register that holds the value (@oconst{register}) or that holds the
       address of the value (@oconst{indirect}).  *)
    adrMode*: AdrMode;
    (**One of @oconst{register} or @oconst{indirect}.  *)
    displacement*: LONGINT;
    (**For @oconst{indirect} adressing, this constant is added to the registers
       value to get the memory address.  A displacement of zero means that
       memory at the address in the register is accessed.  This field is unused
       for the addressing mode @oconst{register}.  *)

    info*: Node;
    (**General purpose field.  Can be used by algorithms to store arbitrary
       data on behalf on a given result.  An algorithm must initialize this
       field before using it.  Keep in mind that this field can serve only one
       operation at a given time.  In case of conflict, consider to use
       @omodule{*ADT:Dictionary} instead of this field.  *)
    marker*: LONGINT;
    (**General purpose field, like @ofield{info}.  In case of conflict,
       consider to use @omodule{*ADT:Dictionary:IntValue} instead of this
       field.  *)
  END;
  IterResultUses = POINTER TO IterResultUsesDesc;
  IterResultUsesDesc = RECORD
    next: Opnd;
  END;

CONST
  depControl* = 0;
  (**Represents a control dependency between two instructions.  Both
     instructuions are relevant to the control flow of the function.  Either
     control can be continue to more than one instruction (like in a branch,
     return, exit, or exception), or there is more than one instruction that
     may pass control to this instruction (like in a merge).

     Control dependencies form a directed graph that describes all possible
     paths from the function's enter instruction to its exit.  All non-merge
     instructions have at most one control dependency on a preceeding
     instruction.  *)
  depMemory* = 1;
  (**Represents a memory dependency between two instructions.  Both
     instructions either read from memory, write to it, branch control flow, or
     merge the memory image from several paths.

     If an instruction has a memory dependency on two or more instructions,
     then all of the ``before'' instructions are evaluated on the path to the
     dependent instruction.  In boolean terms, this is a logical ``and'' of all
     instructions it depends on.

     Merge instructions that combine serveral paths of control have no memory
     dependencies at all.  Instead, the jump instructions pointing to the merge
     have a memory dependency designating the state of global storage just
     before control is passed to the merge via the jump.  *)
  depRegion* = 2;
  (**Instruction depends on a particular region, because it requires some
     result that is computed somewhere within the region.  Introduced by
     @omodule{*OOC:X86:Block}.  *)
  depAny* = -1;
  (**Any of the above.  *)
  anySet = {depControl, depMemory, depRegion};
  
TYPE
  Dep* = POINTER TO DepDesc;
  DepDesc = RECORD
    (**Represents a ``happens before'' relationship.  If instruction @var{A}
       appears in the @ofield{Instr.beforeList} of instruction @var{B}, then
       evaluation of @var{A} must happen before that of @var{B}.  This is
       similar to an instruction's operand list @ofield{Instr.opndList}, with
       two exceptions:

       @enumerate
       @item
       An instance of @otype{Dep} only represents a before vs after
       relationship, not a well defined value.
       @item
       The order of entries in the dependency list is not significant.
       @end enumerate  *)
    before-: Instr;
    (**Reference to an instruction that must be evaluated before
       @ofield{instr}.  *)
    nextBefore-: Dep;
    (**This field refers to the next element in the list of dependencies of an
       instruction.  The head of the list is stored in @ofield{Instr.beforeList}.  *)
    type-: DepType;
    instr-: Instr;
    (**The instruction to which this dependency belongs.  *)
    nextAfter-: Dep;
    (**Links that make up the ``after'' list of a given @otype{Instr} value.
       By traversing this list, all instructions that must be scheduled after
       the given instruction are reached.  The head of the list is
       @ofield{Instr.afterList}.  *)
  END;
  
TYPE
  InstrDesc = RECORD 
    (NodeDesc)
    opndList-: Opnd;
    (**The instruction's operand list.  The operands are linked with
       @ofield{Opnd.nextOpnd}.  Order of operands is significant.  Each
       operand has an index, starting at @code{0}.  *)
    resultList-: Result;
    (**The instruction's result list.  The results are linked with
       @ofield{Result.nextResult}.  Order of results is significant.  Each
       result has an index, starting at @code{0}.  *)
    nextInstr-, prevInstr-: Instr;
    (**Links that make up the list of instructions of a given block.
       The head of the list is stored in @ofield{Block.instrList}.  *)
    block-: Block;
    (**The block this instruction is part of.  *) 
    opcode-: Opcode;
    (**Instruction opcode.  Symbolic names like @oconst{add},
       @oconst{sub}, and so on are defined in this module.  *)
    pos-: Sym.ModulePos;
    (**Character position corresponding to this instruction in the source
       code.  Currently, this field is only set for instructions that implement
       run-time exceptions, and is @samp{-1} for all others.  *)
    designator-: Designator;
    (**For instructions that make use of a variable or a designator, like
       @oconst{get} or @oconst{call}, this field holds a symbolic
       representation of the path to the variable that mirrors the designator
       expression in the source code.  For all other instructions, this field
       is @code{NIL}.  *)
    beforeList-, afterList-: Dep;
    
    info*: Node;
    (**General purpose field.  Can be used by algorithms to store arbitrary
       data on behalf on a given result.  An algorithm must initialize this
       field before using it.  Keep in mind that this field can serve only one
       operation at a given time.  In case of conflict, consider to use
       @omodule{*ADT:Dictionary} instead of this field.  *)
    marker*: LONGINT;
    (**General purpose field, like @ofield{info}.  In case of conflict,
       consider to use @omodule{*ADT:Dictionary:IntValue} instead of this
       field.  *)
  END;
TYPE
  IterOperands* = POINTER TO IterOperandsDesc;
  IterOperandsDesc = RECORD [ABSTRACT]
  END;
  IterInstrOperands = POINTER TO IterInstrOperandsDesc;
  IterInstrOperandsDesc = RECORD
    (IterOperandsDesc)
    next: Opnd;
  END;
  IterInstrResults = POINTER TO IterInstrResultsDesc;
  IterInstrResultsDesc = RECORD
    next: Result;
  END;
  IterJumpGateOperands = POINTER TO IterJumpGateOperandsDesc;
  IterJumpGateOperandsDesc = RECORD
    (IterOperandsDesc)
    nextInstr: Instr;
    index: LONGINT;
  END;
  IterInstrBeforeList = POINTER TO IterInstrBeforeListDesc;
  IterInstrBeforeListDesc = RECORD
    next: Dep;
    types: SET;
  END;
  IterInstrAfterList* = POINTER TO IterInstrAfterListDesc;
  IterInstrAfterListDesc = RECORD
    next: Dep;
    types: SET;
  END;

TYPE
  BlockDesc = RECORD
    (InstrDesc)
    instrList-, instrTail-: Instr;
  END;
  IterBlockInstructions = POINTER TO IterBlockInstructionsDesc;
  IterBlockInstructionsDesc = RECORD
    next: Instr;
  END;
  IterBlockAllInstructions = POINTER TO IterBlockAllInstructionsDesc;
  IterBlockAllInstructionsDesc = RECORD
    (**Iterate offer instructions and nested blocks in pre-order.  *)
    next: Instr;
    block: Block;  (* block of next *)
    opcode: Opcode;  (* -1 means any opcode *)
  END;

TYPE
  BranchInstr* = POINTER TO BranchInstrDesc;
  MergeInstr* = POINTER TO MergeInstrDesc;
  BranchInstrDesc = RECORD
    (BlockDesc)
    paths-: BlockList;
    (**If this is a boolean branch, then index 0 is the ``true'' path, and
       index 1 ``false''.  *)
    caseBranch-: BOOLEAN;
  END;
  MergeInstrDesc = RECORD
    (**Used for both @oconst{merge}, @oconst{loopEnd} @emph{and}
       @oconst{guard}.

       Merging instructions of opcode @oconst{merge} (and no other merges) are
       unusual in the sense that they do not end with a jump instruction.
       Instead, control passes on to the region that contains the merge and its
       associated branch instruction.  *)
    (BlockDesc)
    jumps-: InstrList;
    (**The @oconst{jump} instructions that end up in this block.  This list
       duplicates the information from the @oconst{depControl} dependencies of
       this merge, with the added twist that the order of list entries is
       significant.

       For a @oconst{guard} that has no jumps leading into it, this field is
       @code{NIL}.  *)
  END;
  GateInstr* = POINTER TO GateInstrDesc;
  GateInstrDesc = RECORD
    (InstrDesc)
    merge-: Block;
  END;
  LoopStartInstr* = POINTER TO LoopStartInstrDesc;
  LoopStartInstrDesc = RECORD
    (BlockDesc)
    backedge-: Instr;
    end-: MergeInstr;
  END;
  LoopBackedgeInstr* = POINTER TO LoopBackedgeInstrDesc;
  LoopBackedgeInstrDesc = RECORD
    (InstrDesc)
    start-: LoopStartInstr;
  END;
  ExitInstr* = POINTER TO ExitInstrDesc;
  ExitInstrDesc = RECORD
    (InstrDesc)
    returns: InstrList;
  END;
  
TYPE
  FunctionBlock* = POINTER TO FunctionBlockDesc;
  FunctionBlockDesc = RECORD
    (BlockDesc)
    procDecl-: Sym.ProcDecl;
    enter-: Instr;
    exit-: ExitInstr;
    localVars: IntDict.Dictionary;
    sizeLocalVars: LONGINT;
    maxSizeCallStack: LONGINT;
    
    checkFunctionResult-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the end
       of the function body is reached without encountering any @code{RETURN}.
       *)
  END;


CONST
  alignStackTo* = 4;

PROCEDURE IsSigned*(type: Type): BOOLEAN;
  BEGIN
    RETURN (signed8 <= type) & (type <= signed64);
  END IsSigned;

PROCEDURE IsUnsigned*(type: Type): BOOLEAN;
  BEGIN
    RETURN (unsigned8 <= type) & (type <= unsigned64);
  END IsUnsigned;

PROCEDURE IsFloat*(type: Type): BOOLEAN;
  BEGIN
    RETURN (type >= real32);
  END IsFloat;

PROCEDURE ^ (b: Block) AddInstr1*(opcode: Opcode; arg1: Result): Instr;

PROCEDURE (s: Selector) INIT*();
  BEGIN
  END INIT;

PROCEDURE (s: Selector) [ABSTRACT] SameSelector*(sel: Selector): BOOLEAN;
  END SameSelector;

PROCEDURE (s: Selector) Type*(): Sym.Type;
  BEGIN
    ASSERT(FALSE);
  END Type;

PROCEDURE (s: Var) INIT*(var: Sym.VarDecl);
  BEGIN
    s.INIT^();
    s.decl := var;
    s.dim := -1;
  END INIT;

PROCEDURE (s: Var) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS Var) & (s.decl = sel(Var).decl);
  END SameSelector;

PROCEDURE (s: Var) IsGlobalVar*(): BOOLEAN;
  BEGIN
    RETURN (s.decl # NIL) & (s.decl.parent IS Sym.Module);
  END IsGlobalVar;

PROCEDURE (s: Var) Type*(): Sym.Type;
  BEGIN
    RETURN s.decl.type;
  END Type;

PROCEDURE (s: Proc) INIT*(decl: Sym.ProcDecl);
  BEGIN
    s.INIT^();
    s.decl := decl;
  END INIT;

PROCEDURE (s: Proc) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS Proc) & (s.decl = sel(Proc).decl);
  END SameSelector;

PROCEDURE (s: ProcName) INIT*(name: STRING);
  BEGIN
    s.INIT^();
    s.name := name;
  END INIT;

PROCEDURE (s: ProcName) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS ProcName) & (s.name.Equals(sel(ProcName).name));
  END SameSelector;

PROCEDURE (s: TypeDescr) INIT*(type: Sym.Type);
  BEGIN
    s.INIT^();
    s.type := type;
  END INIT;

PROCEDURE (s: TypeDescr) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS TypeDescr) & (s.type = sel(TypeDescr).type);
  END SameSelector;

PROCEDURE (s: ModuleDescr) INIT*();
  BEGIN
    s.INIT^();
  END INIT;

PROCEDURE (s: ModuleDescr) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS ModuleDescr);
  END SameSelector;

PROCEDURE (s: Const) INIT*(value: Object.Object; type: Sym.PredefId);
  BEGIN
    s.INIT^();
    s.value := value;
    s.type := type;
  END INIT;

PROCEDURE (s: Const) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS Const) & s.value.Equals(sel(Const).value);
  END SameSelector;

PROCEDURE (s: HeapObj) INIT*(fctBlock: FunctionBlock;
                             type: Sym.Type; adr: Result);
  BEGIN
    s.INIT^();
    s.type := type;
    s.adrStandin := fctBlock.AddInstr1(standin, adr);
  END INIT;

PROCEDURE (s: HeapObj) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN  (* implements "same address" *)
    RETURN (sel IS HeapObj) &
        (s.adrStandin.opndList.arg = sel(HeapObj).adrStandin.opndList.arg);
  END SameSelector;

PROCEDURE (s: HeapObj) Type*(): Sym.Type;
  BEGIN
    RETURN s.type;
  END Type;

PROCEDURE (s: Index) INIT*(fctBlock: FunctionBlock; index: Result);
  BEGIN
    s.INIT^();
    s.indexStandin := fctBlock.AddInstr1(standin, index);
  END INIT;

PROCEDURE (s: Index) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS Index) &
        (s.indexStandin.opndList.arg = sel(Index).indexStandin.opndList.arg);
  END SameSelector;

PROCEDURE (s: Field) INIT*(field: Sym.FieldDecl);
  BEGIN
    s.INIT^();
    s.field := field;
  END INIT;

PROCEDURE (s: Field) SameSelector*(sel: Selector): BOOLEAN;
  BEGIN
    RETURN (sel IS Field) & (s.field = sel(Field).field);
  END SameSelector;

PROCEDURE SameDesignator*(d1, d2: Designator): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    IF (LEN(d1^) # LEN(d2^)) THEN
      RETURN FALSE;
    ELSE
      FOR i := 0 TO LEN(d1^)-1 DO
        IF ~d1[i].SameSelector(d2[i]) THEN
          RETURN FALSE;
        END;
      END;
      RETURN TRUE;
    END;
  END SameDesignator;


PROCEDURE (node: Node) INIT*();
  BEGIN
  END INIT;



PROCEDURE SetUse(arg: Result; opnd: Opnd);
(* Sets `opnd. arg = arg' and adds `opnd' to the list of uses of `arg'.  To be
   precise, `opnd' will be made the first element of the use list.  *)
  BEGIN
    opnd.arg := arg;
    opnd.nextUse := arg.useList;
    arg.useList := opnd;
  END SetUse;

PROCEDURE DeleteUse(opnd: Opnd);
(* Removes `opnd' from the list of uses of `opnd.arg'.  *)
  VAR
    prev: Opnd;
  BEGIN
    IF (opnd.arg.useList = opnd) THEN
      opnd.arg.useList := opnd.nextUse;
    ELSE
      prev := opnd.arg.useList;
      WHILE (prev.nextUse # opnd) DO
        prev := prev.nextUse;
      END;
      prev.nextUse := opnd.nextUse;
    END;
    opnd.nextUse := NIL;
    opnd.arg := NIL;
  END DeleteUse;

PROCEDURE (opnd: Opnd) INIT*(arg: Result);
(**Initializes operand and adds it to the use list of @oparam{arg}.  *)
  BEGIN
    opnd.INIT^();
    opnd.arg := arg;
    opnd.nextUse := NIL;
    opnd.nextOpnd := NIL;
    opnd.instr := NIL;
    opnd.immediate := FALSE;
    SetUse(arg, opnd);      (* add `opnd' to list of uses of `arg' *)
  END INIT;

PROCEDURE (opnd: Opnd) DeleteOpnd*();
(**Removes the operand @oparam{opnd} from the operand list of instruction
   @ofield{opnd.instr}.  *)
  VAR
    prev: Opnd;
  BEGIN
    DeleteUse(opnd);
    IF (opnd.instr.opndList = opnd) THEN
      opnd.instr.opndList := opnd.nextOpnd;
    ELSE
      prev := opnd.instr.opndList;
      WHILE (prev.nextOpnd # opnd) DO
        prev := prev.nextOpnd;
      END;
      prev.nextOpnd := opnd.nextOpnd;
    END;
    opnd.nextOpnd := NIL;
    opnd.instr := NIL;
  END DeleteOpnd;

PROCEDURE (opnd: Opnd) ReplaceArg* (arg: Result);
(**Replaces the current argument of the operand with @oparam{arg}.

   @precond
   @samp{arg # @code{NIL}}
   @end precond  *)
  BEGIN
    DeleteUse(opnd);
    SetUse(arg, opnd)
  END ReplaceArg;

PROCEDURE (opnd: Opnd) OpndIndex*(): LONGINT;
(**Returns the index of @oparam{opnd} in its instruction's operand list.  The
   first operand has the index @code{0}.  *)
  VAR
    i: LONGINT;
    ptr: Opnd;
  BEGIN
    i := 0;
    ptr := opnd.instr.opndList;
    WHILE (ptr # opnd) DO
      INC(i);
      ptr := ptr.nextOpnd;
    END;
    RETURN i;
  END OpndIndex;

PROCEDURE (opnd: Opnd) IsBackedgeOpnd*(): BOOLEAN;
  BEGIN
    RETURN (opnd.instr.opcode = gate) &
        (opnd.instr(GateInstr).merge IS LoopStartInstr) &
        (opnd.instr.opndList # opnd);
  END IsBackedgeOpnd;

PROCEDURE (opnd: Opnd) IsConst*(): BOOLEAN;
  BEGIN
    RETURN (opnd.arg.instr.opcode = const);
  END IsConst;



PROCEDURE (res: Result) INIT*(type: Type);
(* Initializes result.  *)
  BEGIN
    res.INIT^();
    res.nextResult := NIL;
    res.instr := NIL;
    res.useList := NIL;
    res.type := type;
    res.register := register;
    res.adrMode := noLocation;
    res.displacement := 0;
    res.info := NIL;
    res.marker := 0;
  END INIT;

PROCEDURE (res: Result) SetType*(type: Type);
  BEGIN
    res.type := type;
  END SetType;

PROCEDURE (res: Result) NonImmediateUses*(): BOOLEAN;
(**Returns @code{TRUE} if @oparam{res} is used in an operand that is not marked
   as @ofield{Opnd.immediate}.  Uses in @oconst{standin} instructions are
   ignored.  *)
  VAR
    use: Opnd;
  BEGIN
    use := res.useList;
    WHILE (use # NIL) DO
      IF ~use.immediate & (use.instr.opcode # standin) THEN
        RETURN TRUE;
      END;
      use := use.nextUse;
    END;
    RETURN FALSE;
  END NonImmediateUses;

PROCEDURE (res: Result) SameLocation*(res2: Result): BOOLEAN;
  BEGIN
    RETURN (res.adrMode = res2.adrMode) &
        (res.register = res2.register) &
        (res.displacement = res2.displacement) &
        (res.adrMode # noLocation);
  END SameLocation;

PROCEDURE (res: Result) DeleteResult*;
(**Removes @oparam{res} from its instruction's result list.  @emph{Note}: The
   use list of the result is @emph{not} changed.  The caller must make sure
   that @oparam{res} does not appear in the operand list of any instructions
   that are still live.

   @precond
   @samp{~(res IS Instruction)}
   @end precond  *)
  VAR
    prev: Result;
  BEGIN
    IF (res = res.instr.resultList) THEN
      res.instr.resultList := res.nextResult;
    ELSE
      prev := res.instr.resultList;
      WHILE (prev.nextResult # res) DO
        prev := prev.nextResult;
      END;
      prev.nextResult := res.nextResult;
    END;
  END DeleteResult;

PROCEDURE (res: Result) ReplaceUses* (with: Result);
(**Replaces all uses of @oparam{res} with @oparam{with}.  *)
  VAR
    use, nextUse: Opnd;
  BEGIN
    use := res.useList;
    WHILE (use # NIL) DO
      nextUse := use.nextUse;
      DeleteUse(use);
      SetUse(with, use);
      use := nextUse;
    END
  END ReplaceUses;

PROCEDURE (res: Result) ReplaceUsesExcept* (with: Result; except: Opnd);
(**Replaces all uses of @oparam{res} with @oparam{with}.  *)
  VAR
    use, nextUse: Opnd;
  BEGIN
    use := res.useList;
    WHILE (use # NIL) DO
      nextUse := use.nextUse;
      IF (use # except) THEN
        DeleteUse(use);
        SetUse(with, use);
      END;
      use := nextUse;
    END
  END ReplaceUsesExcept;

PROCEDURE (calledAdr: Result) CalledProc*(): Sym.ProcDecl;
(**Given the first argument of a @oconst{call} instruction, return the
   called procedure iff the call is static.  Otherwise, return @code{NIL}.  *)
  BEGIN
    IF (calledAdr.instr.opcode = const) THEN
      RETURN calledAdr.instr.designator[0](Proc).decl;
    ELSE
      RETURN NIL;
    END;
  END CalledProc;

PROCEDURE (res: Result) IsFalse*(): BOOLEAN;
(**Return @code{TRUE} if @oparam{res} is the boolean constant @code{FALSE}.  *)
  BEGIN
    RETURN (res.type = boolean) &
        (res.instr.opcode = const) &
        res.instr.designator[0](Const).value.Equals(BigInt.zero);
  END IsFalse;

PROCEDURE (res: Result) IsTrue*(): BOOLEAN;
(**Return @code{TRUE} if @oparam{res} is the boolean constant @code{TRUE}.  *)
  BEGIN
    RETURN (res.type = boolean) &
        (res.instr.opcode = const) &
        ~res.instr.designator[0](Const).value.Equals(BigInt.zero);
  END IsTrue;

PROCEDURE (res: Result) IsFloat*(): BOOLEAN;
(**Return @code{TRUE} if @oparam{res} is a floating point value.  *)
  BEGIN
    RETURN IsFloat(res.type);
  END IsFloat;

PROCEDURE (res: Result) GetConst*(): Boxed.Object;
(**If @oparam{res} is a constant value known at compile time, then return the
   value.  Otherwise, return @code{NIL}.  *)
  BEGIN
    IF (res.instr.opcode = const) & (res.instr.designator[0] IS Const)THEN
      RETURN res.instr.designator[0](Const).value(Boxed.Object);
    ELSE
      RETURN NIL;
    END;
  END GetConst;

PROCEDURE (res: Result) Uses*(): IterResultUses;
  VAR
    iter: IterResultUses;
  BEGIN
    NEW(iter);
    iter.next := res.useList;
    RETURN iter;
  END Uses;

PROCEDURE (iter: IterResultUses) Next*(VAR use: Opnd): BOOLEAN;
  BEGIN
    use := iter.next;
    IF (use = NIL) THEN
      RETURN FALSE;
    ELSE
      iter.next := use.nextUse;
      RETURN TRUE;
    END;
  END Next;



PROCEDURE (dep: Dep) INIT*(type: DepType; before, after: Instr);
  BEGIN
    dep.type := type;
    dep.before := before;
    dep.nextBefore := NIL;
    dep.instr := after;
    dep.nextAfter := NIL;
  END INIT;

PROCEDURE (dep: Dep) DeleteDep*();
  VAR
    instr: Instr;
    ptr: Dep;
  BEGIN
    instr := dep.instr;
    IF (instr.beforeList = dep) THEN
      instr.beforeList := dep.nextBefore;
    ELSE
      ptr := instr.beforeList;
      WHILE (ptr.nextBefore # dep) DO
        ptr := ptr.nextBefore;
      END;
      ptr.nextBefore := dep.nextBefore;
    END;

    instr := dep.before;
    IF (instr.afterList = dep) THEN
      instr.afterList := dep.nextAfter;
    ELSE
      ptr := instr.afterList;
      WHILE (ptr.nextAfter # dep) DO
        ptr := ptr.nextAfter;
      END;
      ptr.nextAfter := dep.nextAfter;
    END;
  END DeleteDep;


PROCEDURE (instr: Instr) INIT*(opcode: Opcode);
  BEGIN
    instr.INIT^();
    instr.opndList := NIL;
    instr.resultList := NIL;
    instr.nextInstr := NIL;
    instr.prevInstr := NIL;
    instr.block := NIL;
    instr.opcode := opcode;
    instr.pos := -1;
    instr.designator := NIL;
    instr.beforeList := NIL;
    instr.afterList := NIL;
    instr.info := NIL;
    instr.marker := 0;
  END INIT;

PROCEDURE (instr: Instr) SetOpcode*(opcode: Opcode);
  BEGIN
    instr.opcode := opcode;
  END SetOpcode;

PROCEDURE (instr: Instr) NonImmediateUses*(): BOOLEAN;
(**Returns @code{TRUE} is at least one result of @oparam{instr} is used in an
   operand that is not marked as @ofield{Opnd.immediate}.  *)
  VAR
    res: Result;
    use: Opnd;
  BEGIN
    res := instr.resultList;
    WHILE (res # NIL) DO
      use := res.useList;
      WHILE (use # NIL) DO
        IF ~use.immediate & (use.instr.opcode # standin) THEN
          RETURN TRUE;
        END;
        use := use.nextUse;
      END;
      res := res.nextResult;
    END;
    RETURN FALSE;
  END NonImmediateUses;

PROCEDURE (instr: Instr) IsLive*(): BOOLEAN;
  BEGIN
    CASE instr.opcode OF
    | enter, exit, return, branch, jump, set, setStack,
      designatorGate, loopStart, loopExit, loopEnd, loopBackedge, call:
      RETURN TRUE;
    ELSE
      RETURN instr.NonImmediateUses();
    END;
  END IsLive;

PROCEDURE (instr: Instr) Unchecked*(): BOOLEAN;
(**If @code{TRUE}, then the evaluation of the instruction does not for invalid
   conditions like overflow or underflow.  This means that this instruction
   will not raise an exception.  *)
  BEGIN
    RETURN (instr.afterList = NIL);
  END Unchecked;

PROCEDURE (instr: Instr) IsLoopEndGate*(): BOOLEAN;
  BEGIN
    RETURN (instr.opcode = gate) & (instr(GateInstr).merge.opcode = loopEnd);
  END IsLoopEndGate;

PROCEDURE (instr: Instr) TopLevelMerge*(): MergeInstr;
  (**If the branch instruction @oparam{instr} is a statement-level branch, then
     return the branch's merge instruction.  Otherwise, return @code{NIL}.

     @precond
     @oproc{*OOC:X86:Block.ArrangeInstructions} has run and
     @ofield{instr.opcode} = @oconst{branch}
     @end precond  *)
  VAR
    last: Instr;
  BEGIN
    last := instr(BranchInstr).instrTail;
    IF (last IS MergeInstr) THEN         (* branch is never empty *)
      RETURN last(MergeInstr);
    ELSE
      RETURN NIL;
    END;
  END TopLevelMerge;

PROCEDURE (instr: Instr) AllOpndsSameValue*(): BOOLEAN;
  VAR
    opnd: Opnd;
  BEGIN
    IF (instr.opndList = NIL) THEN
      RETURN TRUE;
    ELSE
      opnd := instr.opndList;
      WHILE (opnd.nextOpnd # NIL) DO
        IF (opnd.arg # opnd.nextOpnd.arg) THEN
          RETURN FALSE;
        END;
        opnd := opnd.nextOpnd;
      END;
      RETURN TRUE;
    END;
  END AllOpndsSameValue;

PROCEDURE (instr: Instr) SizeOpndList*(): LONGINT;
(**Returns the number of operands of @oparam{instr}. *)
  VAR
    num: LONGINT;
    opnd: Opnd;
  BEGIN
    num := 0;
    opnd := instr.opndList;
    WHILE (opnd # NIL) DO
      INC(num);
      opnd := opnd.nextOpnd;
    END;
    RETURN num;
  END SizeOpndList;

PROCEDURE AddOpnd(instr: Instr; opnd: Opnd);
(**Adds @oparam{opnd} to the end of the operand list of instruction
   @oparam{instr}.  *)
  VAR
    prev: Opnd;
  BEGIN
    opnd.instr := instr;
    IF (instr.opndList = NIL) THEN
      instr.opndList := opnd;
    ELSE
      prev := instr.opndList;
      WHILE (prev.nextOpnd # NIL) DO
        prev := prev.nextOpnd;
      END;
      prev.nextOpnd := opnd;
    END;
  END AddOpnd;

PROCEDURE (instr: Instr) SetDesignator*(designator: Designator);
  BEGIN
    instr.designator := designator;
  END SetDesignator;

PROCEDURE (instr: Instr) ExtendDesignator*(selector: Selector);
  VAR
    new: Designator;
    i: LONGINT;
  BEGIN
    NEW(new, LEN(instr.designator^)+1);
    FOR i := 0 TO LEN(instr.designator^)-1 DO
      new[i] := instr.designator[i];
    END;
    new[LEN(instr.designator^)] := selector;
    instr.designator := new;
  END ExtendDesignator;

PROCEDURE (instr: Instr) AddOpnd* (arg: Result);
(**Adds @oparam{arg} to the end of the operand list of instruction
   @oparam{instr}.

   @precond
   @samp{arg # @code{NIL}}
   @end precond  *)
  BEGIN
    AddOpnd(instr, NEW(Opnd, arg));
  END AddOpnd;

PROCEDURE (instr: Instr) AddResult*(type: Type): Result;
(**Adds a new result to the end of the result list of instruction
   @oparam{instr}.  Its type is set to @oparam{type}.  *)
  VAR
    res, prev: Result;
  BEGIN
    res := NEW(Result, type);
    res.instr := instr;
    IF (instr.resultList = NIL) THEN
      instr.resultList := res;
    ELSE
      prev := instr.resultList;
      WHILE (prev.nextResult # NIL) DO
        prev := prev.nextResult;
      END;
      prev.nextResult := res;
    END;
    RETURN res;
  END AddResult;

PROCEDURE MapType*(type: Sym.Type): Type;
  BEGIN
    type := type.Deparam();
    WITH type: Sym.PredefType DO
      CASE type.id OF
      | Predef.void: RETURN noType
      | Predef.char: RETURN unsigned8
      | Predef.longchar: RETURN unsigned16
      | Predef.ucs4char: RETURN unsigned32
      | Predef.boolean: RETURN unsigned8
      | Predef.shortint: RETURN signed8
      | Predef.integer: RETURN signed16
      | Predef.longint: RETURN signed32
      | Predef.hugeint: RETURN signed64
      | Predef.real: RETURN real32
      | Predef.longreal: RETURN real64
      | Predef.set: RETURN unsigned32
      | Predef.byte: RETURN unsigned8
      | Predef.ptr: RETURN address
      | Predef.stringChar, Predef.stringLongChar, Predef.stringUCS4Char:
        RETURN address
      | Predef.nil: RETURN address
      END;
    | type: Sym.Array DO
      RETURN noType;
    | type: Sym.Record DO
      RETURN noType;
    | type: Sym.Pointer DO
      RETURN address;
    | type: Sym.FormalPars DO
      RETURN address;
    | type: Sym.TypeVar DO
      RETURN MapType(type.bound);
    END;
  END MapType;

PROCEDURE TypeSize*(type: Type): LONGINT;
  BEGIN
    CASE type OF
    | signed8, unsigned8:
      RETURN 1;
    | signed16, unsigned16:
      RETURN 2;
    | signed32, unsigned32, real32, address:
      RETURN 4;
    | signed64, unsigned64, real64:
      RETURN 8;
    END;
  END TypeSize;

PROCEDURE (instr: Instr) AddResultExpr*(type: Sym.Type): Result;
(**Adds a new result to the end of the result list of instruction
   @oparam{instr}.  Its type is set to @oparam{type}.  *)
  BEGIN
    RETURN instr.AddResult(MapType(type));
  END AddResultExpr;

PROCEDURE (instr: Instr) AddResultReg*(type: Type; reg: Register): Result;
(**Adds a new result to the end of the result list of instruction
   @oparam{instr}.  Its type is set to @oparam{type}, and its location to
   @oparam{reg}.  *)
  VAR
    res: Result;
  BEGIN
    res := instr.AddResult(type);
    res.adrMode := register;
    res.register := reg;
    RETURN res;
  END AddResultReg;

PROCEDURE (instr: Instr) NthOpnd*(nth: LONGINT): Opnd;
(**Returns the @oparam{nth} operand of @oparam{instr}.

   @precond
   @samp{0 <= @oparam{nth} < @oparam{instr}.SizeOpndList()}
   @end precond  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr.opndList;
    WHILE (nth # 0) DO
      opnd := opnd.nextOpnd;
      DEC(nth);
    END;
    RETURN opnd;
  END NthOpnd;

PROCEDURE (instr: Instr) NthArg*(nth: LONGINT): Result;
(**Returns the argument of the @oparam{nth} operand of @oparam{instr}.

   @precond
   @samp{0 <= @oparam{nth} < @oparam{instr}.SizeOpndList()}
   @end precond  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr.opndList;
    WHILE (nth # 0) DO
      opnd := opnd.nextOpnd;
      DEC(nth);
    END;
    RETURN opnd.arg;
  END NthArg;

PROCEDURE (instr: Instr) IncomingPaths*(): LONGINT;
  BEGIN
    CASE instr.opcode OF
    | merge, guard, loopEnd:
      RETURN LEN(instr(MergeInstr).jumps^);
    | loopStart:
      RETURN 2;
    END;
  END IncomingPaths;

PROCEDURE (instr: Instr) AddDep*(type: DepType; beforeInstr: Instr);
(**Dependency entries are unique per instruction.  Adding a second dependency
   of the same type snd with the same ``before'' instruction is a no-operation.  *)
  
  VAR
    ptr, dep: Dep;
  BEGIN
    ptr := instr.beforeList;
    WHILE (ptr # NIL) DO
      IF (ptr.before = beforeInstr) & (ptr.type = type) THEN
        RETURN;
      END;
      ptr := ptr.nextBefore;
    END;

    dep := NEW(Dep, type, beforeInstr, instr);
    dep.nextBefore := instr.beforeList;
    instr.beforeList := dep;
    dep.nextAfter := beforeInstr.afterList;
    beforeInstr.afterList := dep;
  END AddDep;

PROCEDURE (instr: Instr) GetDep*(type: DepType): Dep;
  VAR
    x: Dep;
    dep: Dep;
  BEGIN
    x := NIL;
    dep := instr.beforeList;
    WHILE (dep # NIL) DO
      IF (dep.type = type) THEN
        ASSERT(x = NIL);
        x := dep;
      END;
      dep := dep.nextBefore;
    END;
    ASSERT(x # NIL);
    RETURN x;
  END GetDep;

PROCEDURE (instr: Instr) DeleteDep*(type: DepType);
  VAR
    dep: Dep;
  BEGIN
    dep := instr.GetDep(type);
    dep.DeleteDep();
  END DeleteDep;

PROCEDURE (instr: Instr) GetBeforeInstr*(type: DepType): Instr;
  VAR
    dep: Dep;
  BEGIN
    dep := instr.GetDep(type);
    RETURN dep.before;
  END GetBeforeInstr;

PROCEDURE (instr: Instr) GetAfterInstr*(type: DepType): Instr;
  VAR
    x: Instr;
    dep: Dep;
  BEGIN
    x := NIL;
    dep := instr.afterList;
    WHILE (dep # NIL) DO
      IF (dep.type = type) THEN
        ASSERT(x = NIL);
        x := dep.instr;
      END;
      dep := dep.nextAfter;
    END;
    ASSERT(x # NIL);
    RETURN x;
  END GetAfterInstr;

PROCEDURE (instr: Instr) GetAfterInstrOpcode*(type: DepType;
                                              opcode: Opcode): Instr;
  VAR
    x: Instr;
    dep: Dep;
  BEGIN
    x := NIL;
    dep := instr.afterList;
    WHILE (dep # NIL) DO
      IF (dep.type = type) & (dep.instr.opcode = opcode) THEN
        ASSERT(x = NIL);
        x := dep.instr;
      END;
      dep := dep.nextAfter;
    END;
    ASSERT(x # NIL);
    RETURN x;
  END GetAfterInstrOpcode;

PROCEDURE (instr: Instr) GetBranchBeforeInstr*(type: DepType): BranchInstr;
  VAR
    x: Dep;
    dep: Dep;
  BEGIN
    x := NIL;
    dep := instr.beforeList;
    WHILE (dep # NIL) DO
      IF (dep.before.opcode = branch) & (dep.type = type) THEN
        ASSERT(x = NIL);
        x := dep;
      END;
      dep := dep.nextBefore;
    END;
    RETURN x.before(BranchInstr);
  END GetBranchBeforeInstr;

PROCEDURE (instr: Instr) JumpTarget*(): MergeInstr;
  VAR
    merge: Instr;
  BEGIN
    ASSERT(instr.opcode = jump);
    merge := instr.GetAfterInstr(depControl);
    RETURN merge(MergeInstr);
  END JumpTarget;

PROCEDURE (instr: Instr) MergingTarget*(): Block;
  VAR
    target: Instr;
  BEGIN
    CASE instr.opcode OF
    | jump:
      RETURN instr.JumpTarget();
    | loopStart:
      RETURN instr(LoopStartInstr);
    | loopExit:
      target := instr.GetAfterInstrOpcode(depControl, loopEnd);
      RETURN target(Block);
    | loopBackedge:
      RETURN instr(LoopBackedgeInstr).start;
    END;
  END MergingTarget;

PROCEDURE (instr: Instr) TransferDeps*();
(**Transfer all dependencies of @oparam{instr} (that is, the instructions in
   its ``before'' list) to the instructions that depend on @oparam{instr} (that
   is, the instructions in its ``after'' list).  Remove all dependencies on
   @oparam{instr}.  *)
  VAR
    after, nextAfter, before: Dep;
  BEGIN
    after := instr.afterList;
    WHILE (after # NIL) DO
      nextAfter := after.nextAfter;
      before := instr.beforeList;
      WHILE (before # NIL) DO
        after.instr.AddDep(before.type, before.before);
        before := before.nextBefore;
      END;

      after.DeleteDep();
      after := nextAfter;
    END;
  END TransferDeps;

PROCEDURE (instr: Instr) DesignatorGateToGate*();
  BEGIN
    instr.opcode := gate;
    instr.designator := NIL;
  END DesignatorGateToGate;

PROCEDURE (iter: IterOperands) [ABSTRACT] Next*(VAR opnd: Opnd): BOOLEAN;
  END Next;

PROCEDURE (instr: Instr) Operands*(): IterInstrOperands;
  VAR
    iter: IterInstrOperands;
  BEGIN
    NEW(iter);
    iter.next := instr.opndList;
    RETURN iter;
  END Operands;

PROCEDURE (iter: IterInstrOperands) Next*(VAR opnd: Opnd): BOOLEAN;
  BEGIN
    opnd := iter.next;
    IF (opnd = NIL) THEN
      RETURN FALSE;
    ELSE
      iter.next := opnd.nextOpnd;
      RETURN TRUE;
    END;
  END Next;

PROCEDURE (instr: Instr) Results*(): IterInstrResults;
  VAR
    iter: IterInstrResults;
  BEGIN
    NEW(iter);
    iter.next := instr.resultList;
    RETURN iter;
  END Results;

PROCEDURE (iter: IterInstrResults) Next*(VAR res: Result): BOOLEAN;
  BEGIN
    res := iter.next;
    IF (res = NIL) THEN
      RETURN FALSE;
    ELSE
      iter.next := res.nextResult;
      RETURN TRUE;
    END;
  END Next;

PROCEDURE (instr: Instr) GateOperands*(): IterJumpGateOperands;
  VAR
    iter: IterJumpGateOperands;
    i: LONGINT;
    merge: Block;
  BEGIN
    NEW(iter);
    merge := instr.MergingTarget();
    iter.nextInstr := merge.instrList;
    CASE instr.opcode OF
    | jump:
      i := 0;
      WHILE (merge(MergeInstr).jumps[i] # instr) DO
        INC(i);
      END;
    | loopStart:
      i := 0;
    | loopExit:
      i := 0;
      WHILE (merge(MergeInstr).jumps[i] # instr) DO
        INC(i);
      END;
    | loopBackedge:
      i := 1;
    END;
    iter.index := i;
    RETURN iter;
  END GateOperands;

PROCEDURE (iter: IterJumpGateOperands) Next*(VAR opnd: Opnd): BOOLEAN;
  VAR
    instr: Instr;
  BEGIN
    instr := iter.nextInstr;
    WHILE (instr # NIL) & (instr.opcode # gate) DO
      instr := instr.nextInstr;
    END;
    IF (instr = NIL) THEN
      opnd := NIL;
      RETURN FALSE;
    ELSE
      iter.nextInstr := instr.nextInstr;
      opnd := instr.NthOpnd(iter.index);
      RETURN TRUE;
    END;
  END Next;

PROCEDURE (instr: Instr) BeforeList*(type: Type): IterInstrBeforeList;
  VAR
    iter: IterInstrBeforeList;
  BEGIN
    NEW(iter);
    iter.next := instr.beforeList;
    IF (type = depAny) THEN
      iter.types := anySet;
    ELSE
      iter.types := {type};
    END;
    RETURN iter;
  END BeforeList;

PROCEDURE (iter: IterInstrBeforeList) Next*(VAR dep: Dep): BOOLEAN;
  BEGIN
    dep := iter.next;
    WHILE (dep # NIL) & ~(dep.type IN iter.types) DO
      dep := dep.nextBefore;
    END;
    IF (dep = NIL) THEN
      RETURN FALSE;
    ELSE
      iter.next := dep.nextBefore;
      RETURN TRUE;
    END;
  END Next;

PROCEDURE (instr: Instr) AfterList*(type: Type): IterInstrAfterList;
  VAR
    iter: IterInstrAfterList;
  BEGIN
    NEW(iter);
    iter.next := instr.afterList;
    IF (type = depAny) THEN
      iter.types := anySet;
    ELSE
      iter.types := {type};
    END;
    RETURN iter;
  END AfterList;

PROCEDURE (iter: IterInstrAfterList) Next*(VAR dep: Dep): BOOLEAN;
  BEGIN
    dep := iter.next;
    WHILE (dep # NIL) & ~(dep.type IN iter.types) DO
      dep := dep.nextAfter;
    END;
    IF (dep = NIL) THEN
      RETURN FALSE;
    ELSE
      iter.next := dep.nextAfter;
      RETURN TRUE;
    END;
  END Next;


PROCEDURE (b: Block) INIT*(opcode: Opcode);
  BEGIN
    b.INIT^(opcode);
    b.instrList := NIL;
    b.instrTail := NIL;
  END INIT;

PROCEDURE (b: Block) Add*(instr: Instr);
(**Add instruction @oparam{instr} to the block @oparam{b}.

   @precond
   @oparam{instr} is not associated with any block.
   @end precond  *)
  BEGIN
    (* append `instr' to list of instructions in `b' *)
    instr.nextInstr := NIL;
    instr.prevInstr := b.instrTail;
    IF (b.instrList = NIL) THEN     (* add as first element of list *)
      b.instrList := instr;
      b.instrTail := instr;
    ELSE                                 (* append to end of list *)
      b.instrTail.nextInstr := instr;
      b.instrTail := instr;
    END;
    instr.block := b;
  END Add;

PROCEDURE (b: Block) AddInFront*(instr: Instr);
(**Add instruction @oparam{instr} to the beginning of block @oparam{b}.

   @precond
   @oparam{instr} is not associated with any block.
   @end precond  *)
  BEGIN
    instr.prevInstr := NIL;
    instr.nextInstr := b.instrList;
    IF (b.instrList = NIL) THEN     (* add as last element of list *)
      b.instrList := instr;
      b.instrTail := instr;
    ELSE                                 (* insert at beginning of list *)
      b.instrList.prevInstr := instr;
      b.instrList := instr;
    END;
    instr.block := b;
  END AddInFront;

PROCEDURE (b: Block) MoveBehind*(before, after: Instr);
(**Move instruction @oparam{after} behind instruction @oparam{before}.

   @precond
   Both instructions are part of block @oparam{b}.
   @end precond  *)
  BEGIN
    ASSERT(before.block = b);
    ASSERT(after.block = b);
    IF (before.nextInstr # after) THEN
      (* remove `after' *)
      IF (after.prevInstr = NIL) THEN
        b.instrList := after.nextInstr;
      ELSE
        after.prevInstr.nextInstr := after.nextInstr;
      END;
      IF (after.nextInstr = NIL) THEN
        b.instrTail := after.prevInstr;
      ELSE
        after.nextInstr.prevInstr := after.prevInstr;
      END;

      (* add behind `before' *)
      after.prevInstr := before;
      after.nextInstr := before.nextInstr;
      before.nextInstr := after;
      IF (after.nextInstr = NIL) THEN
        b.instrTail := after;
      ELSE
        after.nextInstr.prevInstr := after;
      END;
    END;
  END MoveBehind;

PROCEDURE (b: Block) Remove*(instr: Instr);
(**Removes @oparam{instr} from list of instructions of @oparam{b}.  Operands
   and uses are not touched.  *)
  BEGIN
    ASSERT(b = instr.block);
    IF (instr.prevInstr = NIL) THEN
      b.instrList := instr.nextInstr;
    ELSE
      instr.prevInstr.nextInstr := instr.nextInstr;
    END;
    IF (instr.nextInstr = NIL) THEN
      b.instrTail := instr.prevInstr;
    ELSE
      instr.nextInstr.prevInstr := instr.prevInstr;
    END;
    instr.nextInstr := NIL;
    instr.prevInstr := NIL;
    instr.block := NIL;
  END Remove;

PROCEDURE (instr: Instr) MoveToFront*();
  VAR
    b: Block;
  BEGIN
    b := instr.block;
    b.Remove(instr);
    b.AddInFront(instr);
  END MoveToFront;

PROCEDURE (instr: Instr) Delete*;
(**Removes @oparam{instr} from list of instructions of @ofield{instr.block}.
   All operands and dependencies of @oparam{instr} on other instructions are
   removed.  @emph{Note}: The use lists of the instruction itself and any of
   its other results is @emph{not} changed.  The caller must make sure that no
   result appears in the operand list of any instructions that are still live.  *)
  VAR
    b: Block;
  BEGIN
    (* get rid of any dangling references for "one of its kind" instructions;
       otherwise, such an instruction may be revived via its dictionary, and
       subsequently used within a ProcBlock _without_ appearing in the blocks
       instruction list [FIXME... this isn't in yet] *)
    
    b := instr.block;
    
    (* get rid of operands and remove them from use lists *)
    WHILE (instr.opndList # NIL) DO
      instr.opndList.DeleteOpnd();
    END;

    (* get rid of dependencies and remove them from use lists *)
    WHILE (instr.beforeList # NIL) DO
      instr.beforeList.DeleteDep();
    END;

    b.Remove(instr);
  END Delete;

PROCEDURE (b: Block) RemoveAll*();
  BEGIN
    b.instrList := NIL;
    b.instrTail := NIL;
  END RemoveAll;

PROCEDURE (b: Block) NestingDepth*(): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (b # NIL) DO
      INC(i);
      b := b.block;
    END;
    RETURN i;
  END NestingDepth;

PROCEDURE (b: Block) Dominates*(x: Block): BOOLEAN;
  BEGIN
    WHILE (x # NIL) DO
      IF (x = b) THEN
        RETURN TRUE;
      END;
      x := x.block;
    END;
    RETURN FALSE;
  END Dominates;

PROCEDURE (b: Block) Count*(opcode: Opcode): LONGINT;
  VAR
    i: LONGINT;
    instr: Instr;
  BEGIN
    i := 0;
    instr := b.instrList;
    WHILE (instr # NIL) DO
      IF (instr.opcode = opcode) THEN
        INC(i);
      END;
      instr := instr.nextInstr;
    END;
    RETURN i;
  END Count;

PROCEDURE (b: Block) Instructions*(): IterBlockInstructions;
  VAR
    iter: IterBlockInstructions;
  BEGIN
    NEW(iter);
    iter.next := b.instrList;
    RETURN iter;
  END Instructions;

PROCEDURE (iter: IterBlockInstructions) Next*(VAR instr: Instr): BOOLEAN;
  BEGIN
    instr := iter.next;
    IF (instr = NIL) THEN
      RETURN FALSE;
    ELSE
      iter.next := instr.nextInstr;
      RETURN TRUE;
    END;
  END Next;

PROCEDURE (b: Block) AllInstructions*(opcode: Opcode): IterBlockAllInstructions;
  VAR
    iter: IterBlockAllInstructions;
  BEGIN
    NEW(iter);
    iter.next := b;
    iter.block := NIL;
    iter.opcode := opcode;
    RETURN iter;
  END AllInstructions;

PROCEDURE (iter: IterBlockAllInstructions) Next*(VAR instr: Instr): BOOLEAN;
  VAR
    i: Instr;
  BEGIN
    REPEAT
      i := iter.next;
      IF (i = NIL) THEN
        IF (iter.block = NIL) THEN
          RETURN FALSE;
        ELSE
          iter.next := iter.block.nextInstr;
          iter.block := iter.block.block;
          RETURN iter.Next(instr);
        END;
      ELSE
        IF (i IS Block) THEN
          iter.block := i(Block);
          iter.next := i(Block).instrList;
        ELSE
          iter.next := i.nextInstr;
        END;
      END;
    UNTIL (iter.opcode < 0) OR (i.opcode = iter.opcode);
    instr := i;
    RETURN TRUE;
  END Next;

PROCEDURE (b: Block) AddInstr0*(opcode: Opcode): Instr;
  VAR
    instr: Instr;
  BEGIN
    instr := NEW(Instr, opcode);
    b.Add(instr);
    RETURN instr;
  END AddInstr0;

PROCEDURE (b: Block) AddInstr1*(opcode: Opcode; arg1: Result): Instr;
  VAR
    instr: Instr;
  BEGIN
    instr := NEW(Instr, opcode);
    AddOpnd(instr, NEW(Opnd, arg1));
    b.Add(instr);
    RETURN instr;
  END AddInstr1;

PROCEDURE (b: Block) AddInstr2*(opcode: Opcode; arg1, arg2: Result): Instr;
  VAR
    instr: Instr;
  BEGIN
    instr := NEW(Instr, opcode);
    AddOpnd(instr, NEW(Opnd, arg1));
    AddOpnd(instr, NEW(Opnd, arg2));
    b.Add(instr);
    RETURN instr;
  END AddInstr2;

PROCEDURE (b: Block) AddInstr3*(opcode: Opcode; arg1, arg2, arg3: Result): Instr;
  VAR
    instr: Instr;
  BEGIN
    instr := NEW(Instr, opcode);
    AddOpnd(instr, NEW(Opnd, arg1));
    AddOpnd(instr, NEW(Opnd, arg2));
    AddOpnd(instr, NEW(Opnd, arg3));
    b.Add(instr);
    RETURN instr;
  END AddInstr3;

PROCEDURE (b: Block) AddBlock0*(opcode: Opcode): Block;
  VAR
    instr: Block;
  BEGIN
    instr := NEW(Block, opcode);
    b.Add(instr);
    RETURN instr;
  END AddBlock0;

PROCEDURE (b: Block) AddBlock1*(opcode: Opcode; arg1: Result): Block;
  VAR
    instr: Block;
  BEGIN
    instr := NEW(Block, opcode);
    AddOpnd(instr, NEW(Opnd, arg1));
    b.Add(instr);
    RETURN instr;
  END AddBlock1;

PROCEDURE (b: Block) AddConstType*(selector: Const; type: Type): Result;
  VAR
    instr: Instr;
    designator: Designator;
  BEGIN
    instr := NEW(Instr, const);
    NEW(designator, 1);
    designator[0] := selector;
    instr.SetDesignator(designator);
    b.Add(instr);
    RETURN instr.AddResult(type);
  END AddConstType;

PROCEDURE (b: Block) AddConst*(selector: Const; type: Sym.Type): Result;
  BEGIN
    RETURN b.AddConstType(selector, MapType(type));
  END AddConst;

PROCEDURE (b: Block) AddConstBool*(value: BOOLEAN): Result;
  VAR
    valueInt: LONGINT;
  BEGIN
    IF value THEN
      valueInt := 1;
    ELSE
      valueInt := 0;
    END;
    RETURN b.AddConst(NEW(Const, BigInt.NewInt(valueInt), -1),
                      Predef.GetType(Predef.boolean));
  END AddConstBool;

PROCEDURE (b: Block) AddConstInt*(value: BigInt.BigInt;
                                  type: Sym.Type): Result;
  BEGIN
    RETURN b.AddConst(NEW(Const, value, -1), type);
  END AddConstInt;

PROCEDURE (b: Block) AddConstReal*(value: Boxed.LongReal;
                                  type: Sym.Type): Result;
  BEGIN
    RETURN b.AddConst(NEW(Const, value, -1), type);
  END AddConstReal;

PROCEDURE (b: Block) AddConstZero*(type: Sym.Type): Result;
  BEGIN
    IF TR.IsRealType(type) THEN
      RETURN b.AddConstReal(Boxed.zeroLongReal, type);
    ELSE
      RETURN b.AddConstInt(BigInt.zero, type);
    END;
  END AddConstZero;


PROCEDURE (b: Block) AddConstDim*(dim: LONGINT): Result;
  BEGIN
    RETURN b.AddConst(NEW(Const, BigInt.NewInt(dim), -1),
                      Predef.GetType(Predef.longint));
  END AddConstDim;

PROCEDURE (b: Block) AddConstLength*(length: LONGINT): Result;
  BEGIN
    RETURN b.AddConst(NEW(Const, BigInt.NewInt(length), -1),
                      Predef.GetType(Predef.address));
  END AddConstLength;

PROCEDURE (b: Block) AddAdr*(selector: Global): Result;
  VAR
    instr: Instr;
    designator: Designator;
  BEGIN
    instr := NEW(Instr, const);
    NEW(designator, 1);
    designator[0] := selector;
    instr.SetDesignator(designator);
    b.Add(instr);
    RETURN instr.AddResult(address);
  END AddAdr;

PROCEDURE (b: Block) AddAdrRT*(name: STRING): Result;
  VAR
    instr: Instr;
    designator: Designator;
  BEGIN
    instr := NEW(Instr, const);
    NEW(designator, 1);
    designator[0] := NEW(ProcName, name);
    instr.SetDesignator(designator);
    b.Add(instr);
    RETURN instr.AddResult(address);
  END AddAdrRT;

PROCEDURE (b: Block) AddAdrTypeDescr*(type: Sym.Type): Result;
  VAR
    instr: Instr;
    designator: Designator;
  BEGIN
    instr := NEW(Instr, const);
    NEW(designator, 1);
    designator[0] := NEW(TypeDescr, type);
    instr.SetDesignator(designator);
    b.Add(instr);
    RETURN instr.AddResult(address);
  END AddAdrTypeDescr;

PROCEDURE (b: Block) AddAdrModuleDescr*(): Result;
  VAR
    instr: Instr;
    designator: Designator;
  BEGIN
    instr := NEW(Instr, const);
    NEW(designator, 1);
    designator[0] := NEW(ModuleDescr);
    instr.SetDesignator(designator);
    b.Add(instr);
    RETURN instr.AddResult(address);
  END AddAdrModuleDescr;

PROCEDURE (b: Block) AddFramePointerOffset*(varDecl: Sym.VarDecl): Result;
  VAR
    instr: Instr;
    designator: Designator;
  BEGIN
    instr := NEW(Instr, const);
    NEW(designator, 1);
    designator[0] := NEW(Var, varDecl);
    instr.SetDesignator(designator);
    b.Add(instr);
    RETURN instr.AddResult(address);
  END AddFramePointerOffset;

PROCEDURE (b: Block) AddLoadRegister*(value: Result; reg: Register): Result;
  VAR
    instr: Instr;
  BEGIN
    instr := b.AddInstr1(loadRegister, value);
    RETURN instr.AddResultReg(value.type, reg);
  END AddLoadRegister;

PROCEDURE (opnd: Opnd) InsertCopy*();
  VAR
    opndInstr, instr: Instr;
    b: Block;
  BEGIN
    opndInstr := opnd.instr;
    instr := opndInstr.block.AddInstr1(copy, opnd.arg);
    opnd.ReplaceArg(instr.AddResult(opnd.arg.type));

    (* instr is last, at least one other instruction exists in block *)
    b := instr.block;
    b.instrTail := instr.prevInstr;
    instr.prevInstr.nextInstr := NIL;
    
    instr.prevInstr := opndInstr.prevInstr;
    instr.nextInstr := opndInstr;
    IF (instr.prevInstr = NIL) THEN
      b.instrList := instr;
    ELSE
      instr.prevInstr.nextInstr := instr;
    END;
    opndInstr.prevInstr := instr;
  END InsertCopy;



PROCEDURE (instr: BranchInstr) INIT*(caseBranch: BOOLEAN);
  BEGIN
    instr.INIT^(branch);
    instr.paths := NIL;
    instr.caseBranch := caseBranch;
  END INIT;

PROCEDURE (instr: BranchInstr) SetPaths*(paths: BlockList);
  BEGIN
    instr.paths := paths;
  END SetPaths;
PROCEDURE (instr: BranchInstr) SetPaths2*(pathTrue, pathFalse: Block);
  VAR
    paths: BlockList;
  BEGIN
    NEW(paths, 2);
    paths[0] := pathTrue;
    paths[1] := pathFalse;
    instr.paths := paths;
  END SetPaths2;

PROCEDURE (b: Block) AddBranch*(select: Result;
                                caseBranch: BOOLEAN): BranchInstr;
  VAR
    instr: BranchInstr;
  BEGIN
    instr := NEW(BranchInstr, caseBranch);
    instr.AddOpnd(select);
    b.Add(instr);
    RETURN instr;
  END AddBranch;



PROCEDURE (instr: MergeInstr) INIT*(opcode: Opcode; jumps: InstrList);
(**@oparam{opcode} is either @oconst{merge} or @oconst{guard}.  *)
  BEGIN
    instr.INIT^(opcode);
    instr.jumps := jumps;
  END INIT;

PROCEDURE (instr: MergeInstr) AddJump*(jump: Instr);
  VAR
    new: InstrList;
    i: LONGINT;
  BEGIN
    IF (instr.jumps = NIL) THEN
      NEW(new, 1);
    ELSE
      NEW(new, LEN(instr.jumps^)+1);
      FOR i := 0 TO LEN(instr.jumps^)-1 DO
        new[i] := instr.jumps[i];
      END;
    END;
    new[LEN(new^)-1] := jump;
    instr.jumps := new;
    instr.AddDep(depControl, jump);
  END AddJump;

PROCEDURE (b: Block) AddMerge*(opcode: Opcode; jumps: InstrList): MergeInstr;
  VAR
    instr: MergeInstr;
    jump: Instr;
  BEGIN
    instr := NEW(MergeInstr, opcode, jumps);
    IF (jumps # NIL) THEN
      FOR jump IN jumps^ DO
        instr.AddDep(depControl, jump);
      END;
    END;
    b.Add(instr);
    RETURN instr;
  END AddMerge;

PROCEDURE (b: Block) AddMerge0*(opcode: Opcode; arg1: Result): MergeInstr;
  VAR
    instr: MergeInstr;
  BEGIN
    instr := b.AddMerge(opcode, NIL);
    IF (arg1 # NIL) THEN
      AddOpnd(instr, NEW(Opnd, arg1));
    END;
    RETURN instr;
  END AddMerge0;

PROCEDURE (b: Block) AddMerge2*(opcode: Opcode;
                                jump1, jump2: Instr): MergeInstr;
  VAR
    jumps: InstrList;
  BEGIN
    NEW(jumps, 2);
    jumps[0] := jump1;
    jumps[1] := jump2;
    RETURN b.AddMerge(opcode, jumps);
  END AddMerge2;



PROCEDURE (instr: GateInstr) INIT*(opcode: Opcode; merge: Block);
  BEGIN
    instr.INIT^(opcode);
    instr.merge := merge;
  END INIT;

PROCEDURE (b: Block) AddGate*(opcode: Opcode): GateInstr;
  VAR
    instr: GateInstr;
  BEGIN
    instr := NEW(GateInstr, opcode, b);
    b.Add(instr);
    RETURN instr;
  END AddGate;



PROCEDURE (instr: LoopStartInstr) INIT*();
  BEGIN
    instr.INIT^(loopStart);
    instr.backedge := NIL;
    instr.end := NIL;
  END INIT;

PROCEDURE (instr: LoopStartInstr) SetBackedge*(backedge: Instr);
  BEGIN
    instr.backedge := backedge;
  END SetBackedge;

PROCEDURE (instr: LoopStartInstr) SetEnd*(end: MergeInstr);
  BEGIN
    instr.end := end;
  END SetEnd;

PROCEDURE (b: Block) AddLoopStart*(): LoopStartInstr;
  VAR
    instr: LoopStartInstr;
  BEGIN
    instr := NEW(LoopStartInstr);
    b.Add(instr);
    RETURN instr;
  END AddLoopStart;



PROCEDURE (instr: LoopBackedgeInstr) INIT*(start: LoopStartInstr);
  BEGIN
    instr.INIT^(loopBackedge);
    instr.start := start;
  END INIT;

PROCEDURE (b: Block) AddLoopBackedge*(start: LoopStartInstr): LoopBackedgeInstr;
  VAR
    instr: LoopBackedgeInstr;
  BEGIN
    instr := NEW(LoopBackedgeInstr, start);
    b.Add(instr);
    RETURN instr;
  END AddLoopBackedge;



PROCEDURE (instr: ExitInstr) INIT*(sp, fp: Result; returns: InstrList);
  BEGIN
    instr.INIT^(exit);
    instr.returns := returns;
    AddOpnd(instr, NEW(Opnd, sp));
    AddOpnd(instr, NEW(Opnd, fp));
  END INIT;

PROCEDURE (b: Block) AddExit*(sp, fp: Result; returns: InstrList): ExitInstr;
  VAR
    instr: ExitInstr;
    ret: Instr;
  BEGIN
    instr := NEW(ExitInstr, sp, fp, returns);
    FOR ret IN returns^ DO
      instr.AddDep(depControl, ret);
    END;
    b.Add(instr);
    RETURN instr;
  END AddExit;

PROCEDURE (b: Block) SetMarkers* (newInfo: Node; newMarker: LONGINT);
(**Set the fields @ofield{Result.info} and @ofield{Result.marker} of all
   results in the block to @oparam{newInfo} and @oparam{newMarker}.  *)
  VAR
    instr: Instr;
    res: Result;
  BEGIN
    b.info := newInfo;
    b.marker := newMarker;
    
    instr := b.instrList;
    WHILE (instr # NIL) DO
      WITH instr: Block DO
        instr.SetMarkers(newInfo, newMarker);
      ELSE
        instr.info := newInfo;
        instr.marker := newMarker;
      END;
      
      res := instr.resultList;
      WHILE (res # NIL) DO
        res.info := newInfo;
        res.marker := newMarker;
        res := res.nextResult;
      END;
      instr := instr.nextInstr;
    END;
  END SetMarkers;



PROCEDURE (b: FunctionBlock) INIT*(procDecl: Sym.ProcDecl;
                                   checkFunctionResult: BOOLEAN);
  BEGIN
    b.INIT^(function);
    b.procDecl := procDecl;
    b.enter := NIL;
    b.exit := NIL;
    b.localVars := IntDict.New();
    b.sizeLocalVars := 0;
    b.maxSizeCallStack := -1;
    b.checkFunctionResult := checkFunctionResult;
  END INIT;

PROCEDURE (b: FunctionBlock) SetEnter*(enter: Instr);
  BEGIN
    b.enter := enter;
  END SetEnter;

PROCEDURE (b: FunctionBlock) SetExit*(exit: ExitInstr);
  BEGIN
    b.exit := exit;
  END SetExit;

PROCEDURE (b: FunctionBlock) FixType*(arg: Result; type: Type): Result;
(**If @oparam{arg} is not of the indicated type, then add a type conversion
   instruction for it and return this instruction.  Otherwise, return
   @oparam{arg}.  *)
  VAR
    instr: Instr;
  BEGIN
    IF (arg.type # type) THEN
      IF (arg.instr.opcode = const) &
         ((arg.type < real32) = (type < real32)) THEN
        RETURN b.AddConstType(arg.instr.designator[0](Const), type);
      ELSE
        instr := b.AddInstr1(typeConv, arg);
        RETURN instr.AddResult(type);
      END;
    ELSE
      RETURN arg;
    END;
  END FixType;

PROCEDURE (b: FunctionBlock) AllocateLocalVar*(varDecl: Sym.VarDecl);
  VAR
    i, align: LONGINT;
  BEGIN
    IF ~b.localVars.HasKey(varDecl) THEN
      i := b.sizeLocalVars;
      DEC(i, varDecl.type.size);
      align := varDecl.type.align;
      IF (i MOD align # 0) THEN
        DEC(i, align-i MOD align);
      END;
      b.localVars.Set(varDecl, i);
      b.sizeLocalVars := i;
    END;
  END AllocateLocalVar;

PROCEDURE (b: FunctionBlock) SetMaxSizeCallStack*(size: LONGINT);
  BEGIN
    b.maxSizeCallStack := size;
  END SetMaxSizeCallStack;

PROCEDURE (b: FunctionBlock) Offset*(varDecl: Sym.VarDecl;
                                     dim: LONGINT): LONGINT;
(**Returns the offset of the given parameter relative to the frame pointer of
   the function.  If @oparam{varDecl} is @code{NIL}, result is the size of the
   local variable area, aligned to the nearest multiple of
   @oconst{alignStackTo}.

   @oparam{dim} is used to refer to implicit information associated with
   procedure parameters.  A value of @code{-1} refers to the address of the
   variable itself.  For open array parameters, a non-negative value denotes
   the length of the array for the given dimension.  *)
  CONST
    sizeAddress = 4;
    sizeLength = 4;
  VAR
    p: Sym.VarDecl;
    offset: LONGINT;
    type: Sym.Type;
    
  PROCEDURE ArgumentSize(type: Sym.Type): LONGINT;
    BEGIN
      IF TR.IsPredefType(type, Predef.longreal) THEN
        RETURN 8;
      ELSE
        RETURN 4;
      END;
    END ArgumentSize;
  
  BEGIN
    IF (varDecl = NIL) THEN
      offset := ABS(b.sizeLocalVars);
      ASSERT(b.maxSizeCallStack >= 0);
      INC(offset, b.maxSizeCallStack);
      RETURN (offset+alignStackTo-1) DIV alignStackTo * alignStackTo;
    ELSIF b.localVars.HasKey(varDecl) THEN
      RETURN b.localVars.Get(varDecl);
    ELSE
      offset := sizeAddress*2;  (* return address plus old frame pointer *)
      FOR p IN b.procDecl.formalPars.params^ DO
        type := p.type;
        IF (p = varDecl) THEN
          IF (dim >= 0) THEN
            RETURN offset+ArgumentSize(type)+dim*sizeLength;
          ELSE
            RETURN offset;
          END;
        ELSE
          INC(offset, ArgumentSize(type));
          WITH type: Sym.Record DO
            IF p.isVarParam & type.isExtensible THEN (* type tag *)
              INC(offset, sizeAddress);
            END;
          | type: Sym.Array DO           (* length for every open dimension *)
            INC(offset, type.GetOpenDimensions()*sizeLength);
          ELSE
            (* nothing *)
          END;
        END;
      END;
      ASSERT(FALSE);
    END;
  END Offset;

PROCEDURE (b: FunctionBlock) AddGetLengthInstr* (getInstr: Instr; dim: LONGINT;
                                                 dimType: Sym.Array;
                                                 fp: Result): Result;
(**Given a @code{getInstr} instruction, this method produces a @code{get-length}
   instruction that returns the length of the variable for @oparam{dim}.
   @oparam{dimType} is the array type of dimension @oparam{dim}.  *)
  VAR
    getLength, paramAdr: Instr;
    dimension, offset: Result;
    paramRef: Sym.VarDecl;
    
  PROCEDURE VarParamArray (get: Instr): Sym.VarDecl;
  (* If the get accesses a parameter without any further selectors, then
     return its declaration.  Otherwise, return NIL.  *)
    BEGIN
      IF (LEN(get.designator^) = 1) &
         (get.designator[0] IS Var) &
         get.designator[0](Var).decl.isParameter THEN
        RETURN get.designator[0](Var).decl;
      ELSE
        RETURN NIL;
      END;
    END VarParamArray;

  BEGIN
    ASSERT(getInstr.opcode = get);
    IF dimType.isOpenArray THEN
      dimension := b.AddConstDim(dim);
      paramRef := VarParamArray(getInstr);
      IF (paramRef # NIL) THEN
        offset := b.AddFramePointerOffset(paramRef);
        offset.instr.designator[0](Var).dim := dim;
        paramAdr := b.AddInstr2(add, fp, offset);
        getLength := b.AddInstr1(get, paramAdr.AddResult(address));
      ELSE
        getLength := b.AddInstr0(getLengthHeap);
      END;
      RETURN getLength.AddResult(length);
    ELSE
      RETURN b.AddConstInt(BigInt.NewInt(dimType.length),
                           Predef.GetType(Predef.lengthType));
    END;
  END AddGetLengthInstr;

PROCEDURE (b: FunctionBlock) AddGetParamTypeTag*(parameter: Sym.VarDecl;
                                                 fp: Result): Result;
(**Return the type tag of the record parameter.  *)
  VAR
    getInstr, paramAdr: Instr;
    offset: Result;
  BEGIN
    offset := b.AddFramePointerOffset(parameter);
    offset.instr.designator[0](Var).dim := 0;
    paramAdr := b.AddInstr2(add, fp, offset);
    getInstr := b.AddInstr1(get, paramAdr.AddResult(address));
    RETURN getInstr.AddResult(address);
  END AddGetParamTypeTag;

PROCEDURE (fctBlock: FunctionBlock) DeadCodeElimination*();
  CONST
    dead = 0;
    live = 1;
    
  PROCEDURE MarkLive(instr: Instr);
    VAR
      opnd: Opnd;
      dep: Dep;
    BEGIN
      IF (instr.marker = dead) THEN
        instr.marker := live;
        WITH instr: LoopStartInstr DO
          MarkLive(instr.backedge);
        ELSE
          (* nothing *)
        END;
        FOR opnd IN instr.Operands() DO
          MarkLive(opnd.arg.instr);
        END;
        FOR dep IN instr.BeforeList(depAny) DO
          MarkLive(dep.before);
        END;
      END;
    END MarkLive;

  PROCEDURE RemoveDead(b: Block);
    VAR
      instr: Instr;
    BEGIN
      FOR instr IN b.Instructions() DO
        WITH instr: Block DO
          RemoveDead(instr);
        ELSE
          (* nothing *)
        END;
        IF (instr.marker = dead) THEN
          instr.Delete();
        END;
      END;
    END RemoveDead;
  
  BEGIN
    (* mark all instructions in `fctBlock' as dead *)
    fctBlock.SetMarkers(NIL, dead);
    (* mark exit instruction and all instruction contributing to it as live *)
    MarkLive(fctBlock.exit);
    (* remove all instructions marked as dead *)
    RemoveDead(fctBlock);
  END DeadCodeElimination;

END OOC:X86:SSA.
