(* 	$Id: SSA.Mod,v 1.83 2004/04/02 20:42:19 mva Exp $	 *)
MODULE OOC:SSA;
(*  Data structures for SSA code representation.
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
  SYSTEM, Log, Object, Object:Boxed, Object:BigInt, ADT:Dictionary,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef, OOC:IR,
  OOC:SSA:Opcode, ResultClass := OOC:SSA:Result, OpndClass := OOC:SSA:Opnd;

<*DEFINE OOC_CHECK_ARGS:=FALSE*>

TYPE
  Node* = POINTER TO NodeDesc;
  Opnd* = POINTER TO OpndDesc;
  Result* = POINTER TO ResultDesc;
  Instr* = POINTER TO InstrDesc;
  Const* = POINTER TO ConstDesc;
  DeclRef* = POINTER TO DeclRefDesc;
  TypeRef* = POINTER TO TypeRefDesc;
  Address* = POINTER TO AddressDesc;

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

    class-: OpndClass.Class;
    (**Identifies the function of the operand.  See @omodule{OpndClass}.  *)
    
    nextOpnd-: Opnd;
    (**This field refers to the next element in the list of operands of an
       instruction.  The head of the list is stored in @ofield{Instr.opndList}.  *)
    
    instr-: Instr;
    (**The instruction to which this operand belongs.  *)
    
    nextUse-: Opnd;
    (**Links that make up the ``uses'' list of a given value.  By traversing
       this list, all using occurences of a result are reached.  The head of
       the list is @ofield{Result.useList}.  *)
  END;

TYPE
  TypedOpnd* = POINTER TO TypedOpndDesc;
  TypedOpndDesc = RECORD 
    (OpndDesc)
    type-: Sym.Type;
    passByReference-: BOOLEAN;
  END;

CONST
  initMarker* = -1;
      
TYPE
  ResultDesc = RECORD 
    (NodeDesc)
    nextResult-: Result;
    (**Next result in list of results, for instructions that have more than
       one.  For @samp{result = result. instr} the result is already the
       instruction, that is, the instruction is the first element of the result
       list.  *)
    
    class-: ResultClass.Class;
    (**Identifies the function of the result.  See @omodule{ResultClass}.  *)
    
    subclass*: Opcode.Subclass;
    (**Subclass id of the result.  For a non-instruction result, this value
       identifies the type of the value that is produced by this result.  In
       most cases, the result does not correspond to a piece of data that is
       actually computed during run-time, and has therefore the value
       @oconst{Opcode.scNone}.  For an instruction, interpretation depends on
       the value of @ofield{Instr.opcode}.  Use the method
       @oproc{Instr.GetResultType} to find out if the instruction produces a
       result value, and of which type.  Also see @omodule{Opcode}.  *)
    
    instr-: Instr;
    (**The instruction to which this result belongs.  *)
    
    useList-: Opnd;
    (**List of uses (use-chain) of this result.  Uses are linked with
       @ofield{Opnd.nextUse}.  *)

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
  InstrDesc = RECORD 
    (ResultDesc)
    opndList-: Opnd;
    (**The instruction's operand list.  The operands are linked with
       @ofield{Opnd.nextOpnd}.  Order of operands is significant.  Each
       operand has an index, starting at @code{0}.  *)
    
    nextInstr-, prevInstr-: Instr;
    (**Links that make up the list of instructions of a given procedure block.
       The head of the list is stored in @ofield{ProcBlock.instrList}.  *)

    opcode*: Opcode.Class;
    (**Instruction opcode.  Symbolic names are defined in module
       @omodule{Opcode}.  *)

    pos-: Sym.ModulePos;
    (**Character position corresponding to this instruction in the source
       code.  Currently, this field is only set for instructions that implement
       run-time exceptions, and is @samp{-1} for all other.  *)
  END;

TYPE
  ConstDesc = RECORD
    (InstrDesc)
    value-: Boxed.Object;
    (**For a constant representing a @code{NIL} value, this field refers to
       @ovar{nil}.  Otherwise, it is an instance of BigInt, Boxed.LongReal,
       or Boxed.String.  *)
    stringType-: Sym.Type;
    (**For a string constant, the instructions @ofield{subclass} is
       @oconst{Opcode.scAddress}, and this field is used to disambiguate the
       string's base character type.  For all other constants, this field
       is @code{NIL}.  *)
  END;
  
TYPE
  DeclRefDesc = RECORD
    (InstrDesc)
    decl-: Sym.Declaration;
  END;
  
TYPE
  TypeRefDesc = RECORD
    (InstrDesc)
    type-: Sym.Type;
  END;
  
TYPE
  AddressDesc = RECORD
    (**Designates the address of a declared variable.  Instances of this
       class use the opcode @oconst{Opcode.address} or
       @oconst{Opcode.copyParameter}.  *)
    (InstrDesc)
    decl-: Sym.Declaration;
  END;
  
TYPE
  ProcBlock* = POINTER TO ProcBlockDesc;
  ProcBlockDesc = RECORD
    (**A procedure block holds the set of instructions of a procedure or module
       body.  The result of evaluating the code block is represented by the
       operand list of a single instruction, @ofield{selectReturn}.  *)
    (NodeDesc)
    
    selectReturn-: Instr;
    (**Represents the whole procedure block.  All results of evaluating the
       block's instructions are summarized---directly or indirectly---in this
       instruction's operand list.  See @oconst{Opcode.selectReturn}.  *)
    
    loopContext-: Instr;
    (**Represents the exit paths of the currently open @code{LOOP} statement,
       or is @code{NIL} if there is no @code{LOOP}.  See
       @oconst{Opcode.loopEnd}.  *)

    tryContext-: Instr;
    (**With a @code{TRY}, this is the currently open
       @oconst{Opcode.pushExceptionContext} instruction.  With the first
       @code{CATCH} clause, the value changes to the current exception thrown
       within the @code{TRY}.  After the @code{TRY} statement, it changes back
       to the value it had before it, and it is @code{NIL} if the current code
       is not within a @code{TRY} statement.  *)
    
    instrList-, instrTail: Instr;
    (**Set of instructions that make up the procedure block.  The instructions
       are linked with @ofield{Instr.nextInstr} and @ofield{Instr.nextInstr}.
       @emph{Note}: The order of instructions in the list is of no relevance.  *)
    procDecl-: Sym.ProcDecl;
    (**The procedure declaration to which this code block belongs.  *)

    checkFunctionResult-: BOOLEAN;
    (**If @code{TRUE}, then a run-time error should be reported if the end
       of the function body is reached without encountering any @code{RETURN}.
       *)
    
    constMap: ARRAY Opcode.lastSubclass+1 OF Dictionary.Dictionary;
    (**Maps constant values onto @code{const} instructions.  See
       @oproc{ProcBlock.GetConst}.  *)
    
    objMap: Dictionary.Dictionary;
    (**Maps declarations and type definitions from the symbol table onto
       @code{declref} and @code{typeref} instructions.  See
       @oproc{ProcBlock.GetDeclRef}.  *)
    
    adrMap: Dictionary.Dictionary;
    (**Maps items of the symbol table to their @code{adr} instructions.  See
       @oproc{ProcBlock.GetAddress}.  *)
  END;

VAR
  nil-: BigInt.BigInt;
  (**A unique value representing @code{NIL}.  Note: Strange things may
     happen if the same object is also used with a different meaning.  *)

  
PROCEDURE InitNode* (n: Node);
  BEGIN
  END InitNode;

  (* ---------------------------------------------------------------------- *)

PROCEDURE SetUse (arg: Result; opnd: Opnd);
(* Sets `opnd. arg = arg' and adds `opnd' to the list of uses of `arg'.  To be
   precise, `opnd' will be made the first element of the use list.  *)
  BEGIN
    opnd. arg := arg;
    opnd. nextUse := arg. useList;
    arg. useList := opnd
  END SetUse;

PROCEDURE DeleteUse (opnd: Opnd);
(* Removes `opnd' from the list of uses of `opnd. arg'.  *)
  VAR
    prev: Opnd;
  BEGIN
    IF (opnd. arg. useList = opnd) THEN
      opnd. arg. useList := opnd. nextUse
    ELSE
      prev := opnd. arg. useList;
      WHILE (prev. nextUse # opnd) DO
        prev := prev. nextUse
      END;
      prev. nextUse := opnd. nextUse
    END;
    opnd. nextUse := NIL;
    opnd. arg := NIL
  END DeleteUse;

PROCEDURE InitOpnd (opnd: Opnd; arg: Result; class: OpndClass.Class);
(* Initializes operand and adds it to the use list of `arg'.  *)
  BEGIN
    InitNode (opnd);
    opnd. arg := arg;
    opnd. nextUse := NIL;
    opnd. nextOpnd := NIL;
    opnd. instr := NIL;
    opnd. class := class;
    SetUse (arg, opnd);      (* add `opnd' to list of uses of `arg' *)
  END InitOpnd;

PROCEDURE NewOpnd (arg: Result; class: OpndClass.Class): Opnd;
(* Creates a new operand and adds it to the use list of `arg'.  *)
  VAR
    opnd: Opnd;
  BEGIN
    NEW (opnd);
    InitOpnd (opnd, arg, class);
    RETURN opnd
  END NewOpnd;
  
PROCEDURE InitTypedOpnd (opnd: TypedOpnd; arg: Result; class: OpndClass.Class;
                         type: Sym.Type; passByReference: BOOLEAN);
  BEGIN
    InitOpnd (opnd, arg, class);
    opnd. type := type;
    opnd. passByReference := passByReference;
  END InitTypedOpnd;

PROCEDURE NewTypedOpnd (arg: Result; class: OpndClass.Class;
                        type: Sym.Type; passByReference: BOOLEAN): Opnd;
  VAR
    opnd: TypedOpnd;
  BEGIN
    NEW (opnd);
    InitTypedOpnd (opnd, arg, class, type, passByReference);
    RETURN opnd
  END NewTypedOpnd;
  
PROCEDURE (opnd: Opnd) DeleteOpnd*;
(**Removes the operand @oparam{opnd} from the operand list of instruction
   @ofield{opnd.instr}.  *)
  VAR
    prev: Opnd;
  BEGIN
    DeleteUse (opnd);
    IF (opnd. instr. opndList = opnd) THEN
      opnd. instr. opndList := opnd. nextOpnd
    ELSE
      prev := opnd. instr. opndList;
      WHILE (prev. nextOpnd # opnd) DO
        prev := prev. nextOpnd
      END;
      prev. nextOpnd := opnd. nextOpnd
    END;
    opnd. nextOpnd := NIL;
    opnd. instr := NIL
  END DeleteOpnd;

<*IF OOC_CHECK_ARGS THEN*>
PROCEDURE CheckArg(instr: Instr; arg: Result);
  BEGIN
    CASE instr.opcode OF
    | Opcode.add, Opcode.subtract, Opcode.multiply:
      ASSERT(arg.subclass = instr.subclass);
    ELSE
    END;
  END CheckArg;
<*END*>

PROCEDURE (opnd: Opnd) ReplaceArg* (arg: Result);
(**Replaces the current argument of the operand with @oparam{arg}.

   @precond
   @samp{arg # @code{NIL}}
   @end precond  *)
  BEGIN
<*IF OOC_CHECK_ARGS THEN*>
    IF (opnd.class=OpndClass.arg) THEN CheckArg(opnd.instr, arg) END;
<*END*>
    DeleteUse (opnd);
    SetUse (arg, opnd)
  END ReplaceArg;

PROCEDURE (opnd: Opnd) OpndIndex*(): LONGINT;
(**Returns the index of @oparam{opnd} in its instruction's operand list.  The
   first operand has the index @code{0}.  *)
  VAR
    i: LONGINT;
    ptr: Opnd;
  BEGIN
    i := 0;
    ptr := opnd. instr. opndList;
    WHILE (ptr # opnd) DO
      INC (i);
      ptr := ptr. nextOpnd
    END;
    RETURN i
  END OpndIndex;

PROCEDURE (opnd: Opnd) GetIntConst*(): LONGINT;
(**@precond
   @ofield{opnd.arg} is an integer constant.
   @end precond*)
  BEGIN
    RETURN opnd. arg(Const). value(BigInt.BigInt). ToLongInt();
  END GetIntConst;

PROCEDURE (opnd: Opnd) IsScheduleOpnd*(): BOOLEAN;
  BEGIN
    CASE opnd. class OF
    | OpndClass.loopExternalDef,
      OpndClass.antiDependency,
      OpndClass.regionDependency:
      RETURN TRUE;
    ELSE
      RETURN FALSE;
    END;
  END IsScheduleOpnd;

PROCEDURE (opnd: Opnd) IsValueOpnd*(): BOOLEAN;
(**Return @code{TRUE} if operand takes an argument that represents a true input
   value of the instruction, and that must be physically computed by the output
   code.  Otherwise, the operand represents meta data that should not appear in
   the emitted code at all.  *)
  BEGIN
    CASE opnd. class OF
    | OpndClass.antiDependency,
      OpndClass.regionDependency,
      OpndClass.readDesign,
      OpndClass.writeDesign:
      RETURN FALSE;
    ELSE
      RETURN TRUE;
    END;
  END IsValueOpnd;

PROCEDURE (opnd: Opnd) IsValueOpndHere*(): BOOLEAN;
(**Return @code{TRUE} if the operand takes an argument that represents a
   phyiscally computed value, and if this value must be available at the place
   of the instruction.

   Right now, this method is only different from @oproc{Opnd.IsValueOpnd} for
   the first operand of a @oconst{Opcode.select}.  This value must be computed,
   but it is used before the select paths and the @oconst{Opcode.select}
   instruction itself.  Therefore, result is @code{FALSE} for this operand.
   The scheduler and the allocator must make sure that the value of the
   selecting expression is available where control flow is split.  *)
  VAR
    instr: Instr;
  BEGIN
    IF opnd. IsValueOpnd() THEN
      instr := opnd. instr;
      (* Return TRUE if the operand is not the first operand of a "select".
         The selecting expression is evaluated before even one of the
         paths into the "select" is entered.  For this reason, it must
         not be live at the place of the select instruction itself.  *)
      RETURN (instr. opcode # Opcode.select) OR (instr. opndList # opnd);
    ELSE
      RETURN FALSE;
    END;
  END IsValueOpndHere;

  (* ---------------------------------------------------------------------- *)
  
PROCEDURE InitResult (res: Result; instr: Instr; class: ResultClass.Class;
                      subclass: Opcode.Subclass);
(* Initializes result.  *)
  BEGIN
    InitNode (res);
    res. nextResult := NIL;
    res. instr := instr;
    res. class := class;
    res. subclass := subclass;
    res. info := NIL;
    res. marker := initMarker;
    res. useList := NIL;
  END InitResult;

PROCEDURE NewResult* (instr: Instr; class: ResultClass.Class; subclass: Opcode.Subclass): Result;
(**Creates a new result instance.  The result is not registered with
   @oparam{instr}, instead use @oproc{Instr.AddResult} and
   @oproc{Instr.AddResultSubclass} for that.  *)
  VAR
    res: Result;
  BEGIN
    NEW (res);
    InitResult (res, instr, class, subclass);
    RETURN res
  END NewResult;
  
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
    prev := res. instr;
    WHILE (prev. nextResult # res) DO
      prev := prev. nextResult
    END;
    prev. nextResult := res. nextResult
  END DeleteResult;

PROCEDURE (res: Result) ReplaceUses* (with: Result);
(**Replaces all uses of @oparam{res} with @oparam{with}.  *)
  VAR
    use, nextUse: Opnd;
  BEGIN
    use := res. useList;
    WHILE (use # NIL) DO
      nextUse := use. nextUse;
<*IF OOC_CHECK_ARGS THEN*>
    IF (use.class=OpndClass.arg) THEN CheckArg(use.instr, with) END;
<*END*>
      DeleteUse (use);
      SetUse (with, use);
      use := nextUse
    END
  END ReplaceUses;

PROCEDURE (result: Result) ResultIndex*(): LONGINT;
(**Returns the index of @oparam{result} in its instruction's result list. The
   first result of an instruction (that is, the instruction itself) has the
   index @code{0}.  *)
  VAR
    i: LONGINT;
    ptr: Result;
  BEGIN
    i := 0;
    ptr := result. instr;
    WHILE (ptr # result) DO
      INC (i);
      ptr := ptr. nextResult;
    END;
    RETURN i;    
  END ResultIndex;

PROCEDURE (calledAdr: Result) CalledProc*(): Sym.ProcDecl;
(**Given the first argument of a @oconst{Opcode.call} instruction, return the
   called procedure iff the call is static.  Otherwise, return @code{NIL}.  *)
  BEGIN
    IF (calledAdr.instr.opcode = Opcode.address) THEN
      RETURN calledAdr.instr(Address).decl(Sym.ProcDecl);
    ELSIF (calledAdr.instr.opcode = Opcode.declRef) THEN
      RETURN calledAdr.instr(DeclRef).decl(Sym.ProcDecl);
    ELSE
      RETURN NIL;
    END;
  END CalledProc;

PROCEDURE (result: Result) IsBooleanConst* (value: BOOLEAN): BOOLEAN;
(**Returns @code{TRUE} if the result is an instruction of type @otype{Const}
   with a boolean value of @oparam{value}.

   @precond
   @samp{@oparam{result} IS @otype{Const}} and the constant value is of type
   @otype{BigInt.BigInt}.
   @end precond  *)
  BEGIN
    ASSERT (result IS Const);
    ASSERT (result(Const).value IS BigInt.BigInt);
    RETURN (result(Const).value.Equals(BigInt.zero) # value)
  END IsBooleanConst;

PROCEDURE (result: Result) LogId* (msg: ARRAY OF CHAR);
  VAR
    i: LONGINT;
  BEGIN
    Log.writer. WriteString (msg);
    Log.writer. WriteString (": ");
<*IF TARGET_ADDRESS = 64 THEN*>
    Log.writer. WriteString ("???");
<*ELSE*>
    Log.writer. WriteHex (SYSTEM.VAL (LONGINT, result. instr), 8);
<*END*>
    i := result. ResultIndex();
    IF (i # 0) THEN
      Log.writer. WriteChar (".");
      Log.writer. WriteLInt (i, 0);
    END;
    Log.writer. WriteLn;
  END LogId;

  (* ---------------------------------------------------------------------- *)

PROCEDURE InitInstr (instr: Instr; opcode: Opcode.Class; subclass: Opcode.Subclass);
  BEGIN
    InitResult (instr, instr, ResultClass.primary, subclass);
    instr. opndList := NIL;
    instr. nextInstr := NIL;
    instr. prevInstr := NIL;
    instr. opcode := opcode;
    instr. subclass := subclass;
    instr. pos := -1;
  END InitInstr;

PROCEDURE (instr: Instr) SetSubclass* (subclass: Opcode.Subclass);
(**Change the subclass id of @oparam{instr} to @oparam{subclass}.  *)
  BEGIN
    instr. subclass := subclass;
  END SetSubclass;

PROCEDURE (instr: Instr) SetPos* (sym: IR.Symbol);
  BEGIN
    instr. pos := sym. pos;
  END SetPos;

PROCEDURE AddOpnd (instr: Instr; opnd: Opnd);
(**Adds @oparam{opnd} to the end of the operand list of instruction
   @oparam{instr}.  *)
  VAR
    prev: Opnd;
  BEGIN
<*IF OOC_CHECK_ARGS THEN*>
    IF (opnd.class=OpndClass.arg) THEN CheckArg(instr, opnd.arg) END;
<*END*>
    opnd. instr := instr;
    IF (instr. opndList = NIL) THEN
      instr. opndList := opnd
    ELSE
      prev := instr. opndList;
      WHILE (prev. nextOpnd # NIL) DO
        prev := prev. nextOpnd
      END;
      prev. nextOpnd := opnd
    END;
  END AddOpnd;

PROCEDURE (instr: Instr) AddOpnd* (arg: Result; class: OpndClass.Class);
(**Adds @oparam{arg} to the end of the operand list of instruction
   @oparam{instr}.

   @precond
   @samp{arg # @code{NIL}}
   @end precond  *)
  BEGIN
    AddOpnd (instr, NewOpnd (arg, class));
  END AddOpnd;

PROCEDURE (instr: Instr) AddOpndFct* (arg: Result; class: OpndClass.Class): Opnd;
(**Like @oproc{Instr.AddOpnd}, but return a reference to the new operand
   object.  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := NewOpnd (arg, class);
    AddOpnd (instr, opnd);
    RETURN opnd;
  END AddOpndFct;

PROCEDURE (instr: Instr) AddUniqueOpnd* (arg: Result; class: OpndClass.Class);
(**Adds @oparam{arg} to the end of the operand list of instruction
   @oparam{instr}, unless an operand with the argument @oparam{arg} already
   exists.

   @precond
   @samp{arg # @code{NIL}}
   @end precond  *)
  VAR
    prev, opnd: Opnd;
  BEGIN
    IF (instr. opndList = NIL) THEN
      opnd := NewOpnd (arg, class);
      opnd. instr := instr;
      instr. opndList := opnd;
    ELSE
      prev := instr. opndList;
      WHILE (prev. arg # arg) & (prev. nextOpnd # NIL) DO
        prev := prev. nextOpnd
      END;
      IF (prev. arg # arg) THEN
        opnd := NewOpnd (arg, class);
        opnd. instr := instr;
        prev. nextOpnd := opnd;
      END;
    END;
  END AddUniqueOpnd;

PROCEDURE (instr: Instr) AddTypedOpnd* (arg: Result; class: OpndClass.Class;
                                        type: Sym.Type; passByReference: BOOLEAN);
(**Adds @oparam{arg} to the end of the operand list of instruction
   @oparam{instr}.

   @precond
   @samp{arg # @code{NIL}}
   @end precond  *)
  BEGIN
    AddOpnd (instr, NewTypedOpnd (arg, class, type, passByReference));
  END AddTypedOpnd;

PROCEDURE (instr: Instr) AddResultSubclass* (class: ResultClass.Class;
                                             subclass: Opcode.Subclass): Result;
(**Adds a new result to the end of the result list of instruction
   @oparam{instr}.  Assign to it the subclass @oparam{subclass}.  *)
  VAR
    res, prev: Result;
  BEGIN
    res := NewResult (instr, class, subclass);
    IF (instr. nextResult = NIL) THEN
      instr. nextResult := res
    ELSE
      prev := instr. nextResult;
      WHILE (prev. nextResult # NIL) DO
        prev := prev. nextResult
      END;
      prev. nextResult := res
    END;
    RETURN res
  END AddResultSubclass;

PROCEDURE (instr: Instr) AddResult* (class: ResultClass.Class): Result;
(**Adds a new result to the end of the result list of instruction
   @oparam{instr}.  The subclass of the new result is @oconst{Opcode.scNone}.  *)
  BEGIN
    RETURN instr. AddResultSubclass (class, Opcode.scNone)
  END AddResult;

PROCEDURE (instr: Instr) SizeOpndList*(): LONGINT;
(**Returns the number of operands of @oparam{instr}. *)
  VAR
    num: LONGINT;
    opnd: Opnd;
  BEGIN
    num := 0;
    opnd := instr. opndList;
    WHILE (opnd # NIL) DO
      INC (num);
      opnd := opnd. nextOpnd;
    END;
    RETURN num;
  END SizeOpndList;

PROCEDURE (instr: Instr) CountOpndClass* (class: OpndClass.Class): LONGINT;
(**Returns the number of operands of @oparam{instr} with a class of
   @oparam{class}. *)
  VAR
    num: LONGINT;
    opnd: Opnd;
  BEGIN
    num := 0;
    opnd := instr. opndList;
    WHILE (opnd # NIL) DO
      IF (opnd. class = class) THEN
        INC (num);
      END;
      opnd := opnd. nextOpnd;
    END;
    RETURN num;
  END CountOpndClass;

PROCEDURE (instr: Instr) SizeResultList*(): LONGINT;
(**Returns the number of results of @oparam{instr}.  Because the instruction is
   an result by itself, the number is always greater or equal to @code{1}.  *)
  VAR
    num: LONGINT;
    res: Result;
  BEGIN
    num := 0;
    res := instr;
    WHILE (res # NIL) DO
      INC (num);
      res := res. nextResult;
    END;
    RETURN num;
  END SizeResultList;


PROCEDURE (instr: Instr) NthOpnd* (nth: LONGINT): Opnd;
(**Returns the @oparam{nth} operand of @oparam{instr}.

   @precond
   @samp{0 <= @oparam{nth} < @oparam{instr}.SizeOpndList()}
   @end precond  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr. opndList;
    WHILE (nth # 0) DO
      opnd := opnd. nextOpnd;
      DEC (nth)
    END;
    RETURN opnd
  END NthOpnd;

PROCEDURE (instr: Instr) NthArg* (nth: LONGINT): Result;
(**Returns the argument of the @oparam{nth} operand of @oparam{instr}.

   @precond
   @samp{0 <= @oparam{nth} < @oparam{instr}.SizeOpndList()}
   @end precond  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr. opndList;
    WHILE (nth # 0) DO
      opnd := opnd. nextOpnd;
      DEC (nth)
    END;
    RETURN opnd. arg
  END NthArg;

PROCEDURE (instr: Instr) LastOpnd*(): Opnd;
(**Returns the last element in @oparam{instr}'s operand list.  Result is
   @code{NIL} if the operand list is empty.  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr. opndList;
    IF (opnd # NIL) THEN
      WHILE (opnd. nextOpnd # NIL) DO
        opnd := opnd. nextOpnd;
      END;
    END;
    RETURN opnd
  END LastOpnd;

PROCEDURE (instr: Instr) GetOpndClass* (class: OpndClass.Class): Opnd;
(**Returns the first operand of @oparam{instr} whose @ofield{Opnd.class} matches
   @oparam{class}.  If no such operand exists, result is @code{NIL}.  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr. opndList;
    WHILE (opnd # NIL) & (opnd. class # class) DO
      opnd := opnd. nextOpnd;
    END;
    RETURN opnd
  END GetOpndClass;

PROCEDURE (instr: Instr) GetArgClass* (class: OpndClass.Class): Result;
(**Returns the first argument of @oparam{instr} whose operand's
   @ofield{Opnd.class} matches @oparam{class}.  If no such operand exists,
   result is @code{NIL}.  *)
  VAR
    opnd: Opnd;
  BEGIN
    opnd := instr. opndList;
    WHILE (opnd # NIL) & (opnd. class # class) DO
      opnd := opnd. nextOpnd;
    END;
    IF (opnd = NIL) THEN
      RETURN NIL
    ELSE
      RETURN opnd. arg
    END
  END GetArgClass;

PROCEDURE (instr: Instr) GetArgStore* (): Result;
(**Short for @code{GetArgClass(store)}.  *)
  BEGIN
    RETURN instr. GetArgClass (OpndClass.store);
  END GetArgStore;

PROCEDURE (instr: Instr) NthResult* (nth: LONGINT): Result;
(**Returns the @oparam{nth} result of @oparam{instr}.  A value of
   @samp{@oparam{nth}=@code{0}} returns the instruction itself

   @precond
   @samp{0 <= @oparam{nth} < @oparam{instr}.SizeResultList()}
   @end precond  *)
  VAR
    res: Result;
  BEGIN
    res := instr;
    WHILE (nth # 0) DO
      res := res. nextResult;
      DEC (nth);
    END;
    RETURN res;    
  END NthResult;

PROCEDURE (instr: Instr) GetResultClass* (class: ResultClass.Class): Result;
(**Returns the first result of @oparam{instr} whose @ofield{Result.class} matches
   @oparam{class}.  If no such result exists, @code{NIL} is returned.  *)
  VAR
    result: Result;
  BEGIN
    result := instr;
    WHILE (result # NIL) & (result. class # class) DO
      result := result. nextResult;
    END;
    RETURN result
  END GetResultClass;

PROCEDURE (instr: Instr) GetResultStore*(): Result;
(**Short for @code{GetResultClass(store)}.  *)
  VAR
    result: Result;
  BEGIN
    result := instr;
    WHILE (result # NIL) & (result. class # ResultClass.store) DO
      result := result. nextResult;
    END;
    RETURN result
  END GetResultStore;

PROCEDURE (instr: Instr) GetOpcodeName* (VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of the instruction's opcode.  The name includes
   both the opcode and the subclass, and it uniquely identifies the
   instruction's operation.  *)
  BEGIN
    Opcode.GetName (instr. opcode, instr. subclass, name);
  END GetOpcodeName;

PROCEDURE (instr: Instr) GetResultType* (): Opcode.Subclass;
  BEGIN
    CASE instr. opcode OF
    | Opcode.set:
      (* a `set' instruction's subclass identifies the type of the data
         item being written, but the instruction itself does not produce
         a value *)
      RETURN Opcode.scNone
    ELSE
      RETURN instr. subclass
    END;
  END GetResultType;

PROCEDURE (instr: Instr) GetLoopEnd* (): Instr;
(**Given a @oconst{Opcode.loopStart} or @code{Opcode.exit} instruction, returns
   the corresponding @oconst{Opcode.loopEnd}.  *)
  VAR
    use: Opnd;
    res: Result;
  BEGIN
    CASE instr. opcode OF
    | Opcode.loopStart:
      use := instr. useList;
    | Opcode.exit:
      res := instr. GetResultStore();
      use := res. useList;
    END;
    WHILE (use # NIL) & (use. instr. opcode # Opcode.loopEnd) DO
      use := use. nextUse;
    END;
    RETURN use. instr;
  END GetLoopEnd;

PROCEDURE (instr: Instr) GetBackwardFeed*(): Result;
(**Given a @oconst{Opcode.loopStart} or @oconst{Opcode.loopEnd} instruction,
   returns the @var{store} value that is passed back from the end of the loop
   to the beginning.  *)
  BEGIN
    IF (instr. opcode = Opcode.loopStart) THEN
      instr := instr. GetLoopEnd();
    END;
    ASSERT (instr. opcode = Opcode.loopEnd);
    RETURN instr. GetArgClass (OpndClass.backwardFeed);
  END GetBackwardFeed;

PROCEDURE (instr: Instr) GetLoopStart* (): Instr;
(**Given a @oconst{Opcode.loopEnd} instruction,
   returns the corresponding @oconst{Opcode.loopStart}.  *)
  BEGIN
    ASSERT (instr. opcode = Opcode.loopEnd);
    RETURN instr. opndList. arg(Instr);
  END GetLoopStart;

PROCEDURE (instr: Instr) GetCollectTarget* (): Instr;
(**For a collect instruction, return the target instruction into which it
   feeds its result.  *)
  VAR
    storeOut: Result;
    use: Opnd;
  BEGIN
    ASSERT (instr. opcode = Opcode.collect);
    storeOut := instr. GetResultStore();
    ASSERT (storeOut # NIL);
    ASSERT (storeOut. useList # NIL);
    ASSERT (storeOut. useList. nextUse = NIL);
    IF (storeOut. useList. class = OpndClass.backwardFeed) THEN
      (* logically, a collect feeding into a loop-end's `backwardFeed'
         passes its data to the loop's loop-start instruction *)
      RETURN storeOut. useList. instr. GetLoopStart();
    ELSIF (storeOut. useList. instr. opcode = Opcode.exit) THEN
      (* logically, a collect feeding into an "exit" instruction
         passes its data to the "loop-end" instruction *)
      storeOut := storeOut. useList. instr. GetResultStore();
      use := storeOut. useList;
      WHILE (use. instr. opcode # Opcode.loopEnd) DO
        use := use. nextUse;
      END;
      RETURN use. instr;
    ELSE
      RETURN storeOut. useList. instr;
    END;
  END GetCollectTarget;

PROCEDURE (select: Instr) NumberOfPaths*(): LONGINT;
(* Return the number of paths leading into the select.

   @precond
   @oparam{select} is one of @oconst{Opcode.select}, @oconst{Opcode.loopStart},
   @oconst{Opcode.loopEnd}.
   @end precond *)
  BEGIN
    CASE select.opcode OF
    | Opcode.select:
      IF (select.GetOpndClass(OpndClass.labels) = NIL) THEN
        RETURN (select.CountOpndClass(OpndClass.arg) DIV 2);
      ELSE
        RETURN select.CountOpndClass(OpndClass.labels);
      END;
    | Opcode.loopStart:
      RETURN 2;
    | Opcode.loopEnd:
      RETURN select.CountOpndClass(OpndClass.storeExit);
    END;
  END NumberOfPaths;

PROCEDURE ^ (pb: ProcBlock) AddInstr* (opcode: Opcode.Class;
                                       subclass: Opcode.Subclass): Instr;
  
PROCEDURE (select: Instr) GetCollect*(pb: ProcBlock; pathNum: LONGINT): Instr;
(* Return the "collect" instruction of path @oparam{pathNum} leading
   into @oparam{select}.  The first path has the number @samp{0}.
   If no matching "collect" exists, create one.

   @precond
   @oparam{select} is one of @oconst{Opcode.select}, @oconst{Opcode.loopStart},
   @oconst{Opcode.loopEnd}.
   @end precond *)
  VAR
    opnd: Opnd;
    collect, loopEnd: Instr;
    oldStore: Result;
  BEGIN
    CASE select.opcode OF
    | Opcode.select:
      opnd := select.NthOpnd(pathNum*2+2);
      
    | Opcode.loopEnd:         (* place collect _before_ "exit" *)
      opnd := select.NthOpnd(pathNum+2);
      ASSERT(opnd.arg.instr.opcode = Opcode.exit);
      opnd := opnd.arg.instr.opndList;
      
    | Opcode.loopStart:
      IF (pathNum = 0) THEN
        opnd := select.NthOpnd(pathNum);
      ELSE
        loopEnd := select.GetLoopEnd();
        opnd := loopEnd.GetOpndClass(OpndClass.backwardFeed);
      END;
    END;
    
    IF (opnd.arg.instr.opcode = Opcode.collect) THEN
      RETURN opnd.arg.instr
    ELSE
      collect := pb.AddInstr(Opcode.collect, Opcode.scNone);
      oldStore := opnd.arg;
      opnd.ReplaceArg(collect.AddResult(ResultClass.store));
      collect.AddOpnd(oldStore, OpndClass.store);
      RETURN collect
    END;
  END GetCollect;


PROCEDURE (instr: Instr) LogOpcode* (msg: ARRAY OF CHAR);
  VAR
    name: ARRAY 64 OF CHAR;
  BEGIN
    instr. GetOpcodeName (name);
    Log.String (msg, name)
  END LogOpcode;

PROCEDURE (instr: Instr) IsConst*(): BOOLEAN;
(**Returns @code{TRUE} if @oparam{instr} represents a constant value.  Such
   instructions have no non-constant operands that constribute to the returned
   value, and within a given procedure block two instructions represent the
   same value iff they are identical.  *)
  BEGIN
    RETURN (instr. opcode = Opcode.getLengthParam) OR
        (instr IS Const) OR (instr IS DeclRef) OR
        (instr IS TypeRef) OR (instr IS Address);
  END IsConst;

PROCEDURE (instr: Instr) UniqueResult*(): BOOLEAN;
(**Return @code{TRUE} if @oparam{instr} produces a unique result, and cannot
   be merged with another instruction.  An example for this is a read access
   of a volatile variable, or a call to the predefined procedure @code{NEW}. *)
  BEGIN
    CASE instr. opcode OF
    | Opcode.newObject, Opcode.exit, Opcode.return(*, Opcode.indexed*):
      RETURN TRUE;
    ELSE
      RETURN FALSE;
    END;
  END UniqueResult;

PROCEDURE (instr: Instr) IsSync*(): BOOLEAN;
(**Returns @code{TRUE} if @oparam{instr} is a synchronization point for the
   global program state @var{store}, but does not change it itself.  That is,
   this function identifies instructions that have @var{store} both as input
   and output parameter, but do not change any of the variables in it.  *)
  BEGIN  (* note: "select", "collect", and "loop" variants are omitted *)
    CASE instr. opcode OF
    | Opcode.return, Opcode.exit,
      Opcode.get,
      Opcode.newObject,
      Opcode.assert, Opcode.halt,
      Opcode.checkIndex, Opcode.checkPointer, Opcode.typeGuard,
      Opcode.failedCase, Opcode.failedWith, Opcode.failedTypeAssert:
      RETURN TRUE;
    ELSE
      RETURN FALSE;
    END;
  END IsSync;

PROCEDURE (instr: Instr) IsSwitchStatm*(): BOOLEAN;
(**Return @code{TRUE} if the instruction is a select with arbitrary many
   paths originating in a @code{CASE} statement.  Otherwise, the select is of
   type boolean with exactly two paths.  *)
  BEGIN
    ASSERT (instr. opcode = Opcode.select);
    (* a "switch" select either has only a single branch (the default) or
       it has an operand refering to a "label" statement *)
    RETURN
        (instr. GetOpndClass (OpndClass.labels) # NIL) OR
        (instr. CountOpndClass (OpndClass.arg) < 4);
  END IsSwitchStatm;

(* ---------------------------------------------------------------------- *)

PROCEDURE InitConst (const: Const; subclass: Opcode.Subclass;
                     value: Boxed.Object; stringType: Sym.Type);
  BEGIN
    InitInstr (const, Opcode.const, subclass);
    ASSERT (value # NIL);
    const. value := value;
    const. stringType := stringType;
  END InitConst;

PROCEDURE InitDeclRef (declRef: DeclRef; decl: Sym.Declaration);
  BEGIN
    InitInstr (declRef, Opcode.declRef, Opcode.scNone);
    declRef. decl := decl;
  END InitDeclRef;

PROCEDURE InitTypeRef (typeRef: TypeRef; type: Sym.Type);
  BEGIN
    InitInstr (typeRef, Opcode.typeRef, Opcode.scNone);
    typeRef. type := type;
  END InitTypeRef;

PROCEDURE InitAddress (address: Address; opcode: Opcode.Class;
                       decl: Sym.Declaration);
  BEGIN
    InitInstr (address, opcode, Opcode.scAddress);
    address. decl := decl;
  END InitAddress;

PROCEDURE NewAddress (opcode: Opcode.Class; decl: Sym.Declaration): Address;
  VAR
    address: Address;
  BEGIN
    NEW (address);
    InitAddress (address, opcode, decl);
    RETURN address
  END NewAddress;

  (* ---------------------------------------------------------------------- *)

PROCEDURE InitProcBlock (pb: ProcBlock; procDecl: Sym.ProcDecl;
                         checkFunctionResult: BOOLEAN);
  VAR
    enter: Instr;
    initialStore: Result;
    i: LONGINT;
  BEGIN
    InitNode (pb);
    pb. instrList := NIL;
    pb. instrTail := NIL;
    pb. procDecl := procDecl;
    pb. checkFunctionResult := checkFunctionResult;
    
    pb. selectReturn := pb. AddInstr (Opcode.selectReturn, Opcode.scNone);
    enter := pb. AddInstr (Opcode.enter, Opcode.scNone);
    initialStore := enter. AddResult (ResultClass.store);
    pb. selectReturn. AddOpnd (initialStore, OpndClass.storeEnter);
    
    pb. loopContext := NIL;
    pb. tryContext := NIL;
    FOR i := 0 TO LEN(pb.constMap)-1 DO
      pb. constMap[i] := NIL;
    END;
    pb. objMap := Dictionary.New();
    pb. adrMap := Dictionary.New();
  END InitProcBlock;

PROCEDURE NewProcBlock* (proc: IR.Procedure): ProcBlock;
(**Creates a new instance of @otype{ProcBlock}.  *)
  VAR
    pb: ProcBlock;
  BEGIN
    NEW (pb);
    InitProcBlock (pb, proc. decl, proc. checkFunctionResult);
    RETURN pb
  END NewProcBlock;

PROCEDURE AppendInstr (pb: ProcBlock; instr: Instr);
  BEGIN
    (* append `instr' to list of instructions in `pb' *)
    instr. nextInstr := NIL;
    instr. prevInstr := pb. instrTail;
    IF (pb. instrList = NIL) THEN        (* add as first element of list *)
      pb. instrList := instr;
      pb. instrTail := instr
    ELSE                                 (* append to end of list *)
      pb. instrTail. nextInstr := instr;
      pb. instrTail := instr
    END;
  END AppendInstr;
  
PROCEDURE (pb: ProcBlock) AddInstr* (opcode: Opcode.Class;
                                     subclass: Opcode.Subclass): Instr;
(**Creates a new instruction in the procedure block @oparam{pb}.  *)
  VAR
    instr: Instr;
  BEGIN
    NEW (instr);
    InitInstr (instr, opcode, subclass);
    AppendInstr (pb, instr);
    RETURN instr
  END AddInstr;
  
PROCEDURE (pb: ProcBlock) DeleteInstr* (instr: Instr);
(**Removes @oparam{instr} from list of instructions of @oparam{pb}.  All
   operands are removed.  @emph{Note}: The use lists of the instruction itself
   and any of its other results is @emph{not} changed.  The caller must make
   sure that no result appears in the operand list of any instructions that are
   still live.  *)
  BEGIN
    (* get rid of any dangling references for "one of its kind" instructions;
       otherwise, such an instruction may be revived via its dictionary, and
       subsequently used within a ProcBlock _without_ appearing in the blocks
       instruction list *)
    WITH instr: Address DO
      pb. adrMap. Delete (instr. decl);
    | instr: Const DO
      IF (instr.stringType = NIL) THEN
        pb.constMap[instr.subclass].Delete(instr.value);
      END;
    | instr: DeclRef DO
      pb. objMap. Delete (instr. decl);
    | instr: TypeRef DO
      pb. objMap. Delete (instr. type);
    ELSE
      (* nothing to do *)
    END;
    
    (* get rid of operands and remove them from use lists *)
    WHILE (instr. opndList # NIL) DO
      instr. opndList. DeleteOpnd();
    END;

    IF (instr. prevInstr = NIL) THEN
      pb. instrList := instr. nextInstr
    ELSE
      instr. prevInstr. nextInstr := instr. nextInstr
    END;
    IF (instr. nextInstr = NIL) THEN
      pb. instrTail := instr. prevInstr
    ELSE
      instr. nextInstr. prevInstr := instr. prevInstr
    END;
    instr. nextInstr := NIL;
    instr. prevInstr := NIL;
  END DeleteInstr;
  
PROCEDURE (pb: ProcBlock) GetConst* (value: Boxed.Object;
                                     subclass: Opcode.Subclass;
                                     stringType: Sym.Type): Const;
(**Returns the @code{const} instruction for the value @oparam{value}.  Equal
   values are mapped to the same unique instruction.  For string constants,
   @oparam{stringType} is not @code{NIL} and identifies the strings exact type.
   For all other constants, @oparam{stringType} must be @code{NIL}.  *)
  VAR
    obj: Object.Object;
    const: Const;
  BEGIN
    (*IF (stringType # NIL) THEN
      ASSERT(subclass = Opcode.scAddress);
    END;
    (* check permitted value, kind of an ASSERT *)
    WITH value: BigInt.BigInt DO
      ASSERT(subclass < Opcode.scReal32);
    | value: Boxed.LongReal DO
      ASSERT(subclass >= Opcode.scReal32);
    | value: Boxed.String DO
      ASSERT(stringType # NIL);
    END;*)
    
    IF (pb. constMap[subclass] = NIL) THEN
      pb. constMap[subclass] := Dictionary.New();
    END;
    
    IF pb.constMap[subclass].HasKey(value) THEN
      obj := pb. constMap[subclass]. Get (value);
      RETURN obj(Const);
    ELSE
      NEW (const);
      InitConst (const, subclass, value, stringType);
      AppendInstr (pb, const);
      IF (stringType = NIL) THEN
        (* only cash constants of basic type, since the hash key does not
           include type information *)
        pb. constMap[subclass]. Set (value, const);
      END;
      RETURN const
    END;
  END GetConst;

PROCEDURE (pb: ProcBlock) GetConstInt* (int: LONGINT): Const;
  VAR
    x: BigInt.BigInt;
    subclass: Opcode.Subclass;
  BEGIN
    x := BigInt.NewInt(int);
    subclass := Opcode.TypeToSubclass(Predef.SmallestIntType(x));
    RETURN pb.GetConst(x, subclass, NIL);
  END GetConstInt;

PROCEDURE (pb: ProcBlock) GetConstBool* (b: BOOLEAN): Const;
  VAR
    x: BigInt.BigInt;
  BEGIN
    IF b THEN
      x := BigInt.one;
    ELSE
      x := BigInt.zero;
    END;
    RETURN pb.GetConst(x, Opcode.scBoolean, NIL);
  END GetConstBool;

PROCEDURE (pb: ProcBlock) GetConstNil*(): Const;
  BEGIN
    RETURN pb.GetConst(nil,
                       Opcode.TypeToSubclass(Predef.GetType(Predef.nil)),
                       NIL);
  END GetConstNil;


PROCEDURE (pb: ProcBlock) GetDeclRef* (decl: Sym.Declaration): DeclRef;
(**Returns the @code{declref} instruction for the declaration @oparam{decl}.
   Equal declarations are mapped to the same unique instruction.  *)
  VAR
    obj: Object.Object;
    declRef: DeclRef;
  BEGIN
    IF pb. objMap. HasKey (decl) THEN
      obj := pb. objMap. Get (decl);
      RETURN obj(DeclRef);
    ELSE
      NEW (declRef);
      InitDeclRef (declRef, decl);
      AppendInstr (pb, declRef);
      pb. objMap. Set (decl, declRef);
      RETURN declRef
    END;
  END GetDeclRef;

PROCEDURE (pb: ProcBlock) GetTypeRef* (type: Sym.Type): TypeRef;
(**Returns the @code{typeref} instruction for the type @oparam{type}.
   Equal types are mapped to the same unique instruction.  *)
  VAR
    obj: Object.Object;
    typeRef: TypeRef;
  BEGIN
    IF pb. objMap. HasKey (type) THEN
      obj := pb. objMap. Get (type);
      RETURN obj(TypeRef);
    ELSE
      NEW (typeRef);
      InitTypeRef (typeRef, type);
      AppendInstr (pb, typeRef);
      pb. objMap. Set (type, typeRef);
      RETURN typeRef
    END;
  END GetTypeRef;

PROCEDURE (pb: ProcBlock) SetAddress (decl: Sym.Declaration;
                                      address: Address);
  BEGIN
    pb. adrMap. Set (decl, address);
  END SetAddress;

PROCEDURE (pb: ProcBlock) GetAddress* (decl: Sym.Declaration): Address;
(**Returns the @code{declref} instruction for the declaration @oparam{decl}.
   Equal declarations are mapped to the same unique instruction.  *)
  VAR
    obj: Object.Object;
    address: Address;
  BEGIN
    IF pb. adrMap. HasKey (decl) THEN
      obj := pb. adrMap. Get (decl);
      RETURN obj(Address);
    ELSE
      address := NewAddress (Opcode.address, decl);
      AppendInstr (pb, address);
      pb. SetAddress (decl, address);
      RETURN address
    END;
  END GetAddress;

PROCEDURE (pb: ProcBlock) AddCopyParameter*(param: Sym.VarDecl;
                                            storeIn: Result;
                                            length, size: Result): Address;
(**Creates a @oconst{Opcode.copyParameter} instruction for the parameter
   @oparam{param}.  Subsequent calls to @oproc{pb.GetAddress} will return
   the @code{copy-parameter} instruction as the address of @oparam{param}.  *)
  VAR
    address: Address;
  BEGIN
    address := NewAddress (Opcode.copyParameter, param);
    address. AddOpnd (storeIn, OpndClass.store);
    address. AddOpnd (length, OpndClass.arg);
    address. AddOpnd (size, OpndClass.arg);
    AppendInstr (pb, address);
    pb. SetAddress (param, address);
    RETURN address
  END AddCopyParameter;

PROCEDURE (pb: ProcBlock) SetMarkers* (newInfo: Node; newMarker: LONGINT);
(**Set the fields @ofield{Result.info} and @ofield{Result.marker} of all
   results in the procedure block to @oparam{newInfo} and @oparam{newMarker}.  *)
  VAR
    instr: Instr;
    res: Result;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      res := instr;
      WHILE (res # NIL) DO
        res. info := newInfo;
        res. marker := newMarker;
        res := res. nextResult
      END;
      instr := instr. nextInstr
    END;
  END SetMarkers;

PROCEDURE (pb: ProcBlock) AddSetInstr* (get: Instr; sourceValue: Result): Instr;
(**Given a @code{get} instruction, this method produces an mirroring @code{set}
   instruction, transferring the scalar value @oparam{sourceValue} into the
   variable.  *)
  VAR
    set: Instr;
    opnd: Opnd;
    
  PROCEDURE MapOpndClass (class: OpndClass.Class): OpndClass.Class;
    BEGIN
      CASE class OF
      | OpndClass.readAdr: RETURN OpndClass.writeAdr
      | OpndClass.readDesign: RETURN OpndClass.writeDesign
      ELSE
        RETURN class
      END;
    END MapOpndClass;
  
  BEGIN
    ASSERT (get. instr. opcode = Opcode.get);
    set := pb. AddInstr (Opcode.set, get. subclass);
    opnd := get. opndList;
    WHILE (opnd # NIL) DO
      set. AddOpnd (opnd. arg, MapOpndClass (opnd. class));
      opnd := opnd. nextOpnd
    END;
    set. AddOpnd (sourceValue, OpndClass.sourceValue);
    RETURN set
  END AddSetInstr;

PROCEDURE (pb: ProcBlock) AddGetLengthInstr* (get: Instr; dim: LONGINT;
                                              dimType: Sym.Array): Instr;
(**Given a @code{get} instruction, this method produces a @code{get-length}
   instruction that returns the length of the variable for @oparam{dim}.
   @oparam{dimType} is the array type of dimension @oparam{dim}.  *)
  VAR
    getLength, dimension: Instr;
    opnd: Opnd;
    paramRef: DeclRef;
    opcode: Opcode.Class;
    
  PROCEDURE VarParamArray (get: Instr): DeclRef;
  (* If the get accesses a parameter without any further selectors, then
     return its declaration.  Otherwise, return NIL.  *)
    VAR
      opnd: Opnd;
    BEGIN
      opnd := get. GetOpndClass (OpndClass.readDesign);
      IF ((opnd. nextOpnd = NIL) OR
          (opnd. nextOpnd. class # OpndClass.readDesign)) &
         (opnd. arg IS DeclRef) &
         opnd. arg(DeclRef). decl(Sym.VarDecl). isParameter THEN
        RETURN opnd. arg(DeclRef);
      ELSE
        RETURN NIL;
      END;
    END VarParamArray;

  PROCEDURE ExistingGetLength (varParam, dimension: Instr): Instr;
  (* If a "get-length" instruction for the variable parameter and dimension
     exists within the procedure, then return this instruction.  *)
    VAR
      use: Opnd;
    BEGIN
      IF (varParam # NIL) THEN
        use := varParam. useList;
        WHILE (use # NIL) DO
          IF (use. instr. opcode = Opcode.getLengthParam) &
             (use. instr. opndList. arg = dimension) THEN
            RETURN use. instr;
          END;
          use := use. nextUse;
        END;
      END;
      RETURN NIL;
    END ExistingGetLength;
  
  BEGIN
    ASSERT (get. instr. opcode = Opcode.get);
    IF dimType. isOpenArray THEN
      dimension := pb. GetConstInt (dim);
      paramRef := VarParamArray (get);
      getLength := ExistingGetLength (paramRef, dimension);
      IF (getLength = NIL) THEN
        IF (paramRef # NIL) THEN
          opcode := Opcode.getLengthParam;
        ELSE
          opcode := Opcode.getLengthHeap;
        END;
        getLength := pb. AddInstr (opcode, Opcode.scLength);
        opnd := get. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd. class = OpndClass.store) THEN
            getLength. AddOpnd (dimension, OpndClass.dimension)
          ELSE
            getLength. AddOpnd (opnd. arg, opnd. class);
          END;
          opnd := opnd. nextOpnd
        END;
      END;
      RETURN getLength;

    ELSE
      RETURN pb. GetConstInt (dimType. length);
    END;
  END AddGetLengthInstr;

PROCEDURE (pb: ProcBlock) SetLoopContext* (loopContext: Instr): Instr;
  VAR
    old: Instr;
  BEGIN
    old := pb. loopContext;
    pb. loopContext := loopContext;
    RETURN old
  END SetLoopContext;

PROCEDURE (pb: ProcBlock) SetTryContext* (tryContext: Instr): Instr;
  VAR
    old: Instr;
  BEGIN
    old := pb. tryContext;
    pb. tryContext := tryContext;
    RETURN old
  END SetTryContext;

PROCEDURE (pb: ProcBlock) FixSubclass*(arg: Result;
                                       subclass: Opcode.Subclass): Result;
(**If @oparam{arg} is not of the indicated subclass, then add a type conversion
   instruction for it and return this instruction.  Otherwise, return
   @oparam{arg}.  *)
  VAR
    instr: Instr;
  BEGIN
    IF (arg.subclass # subclass) THEN
      IF (arg IS Const) &
         ((arg.subclass < Opcode.scReal32) = (subclass < Opcode.scReal32)) THEN
        RETURN pb.GetConst(arg(Const).value, subclass, NIL);
      ELSE
        instr := pb.AddInstr(Opcode.typeConv, subclass);
        instr. AddOpnd (arg, OpndClass.arg);
        RETURN instr;
      END;
    ELSE
      RETURN arg;
    END;
  END FixSubclass;

PROCEDURE (pb: ProcBlock) FixSubclassInstr*(instr: Instr;
                                            subclass: Opcode.Subclass): Instr;
  VAR
    res: Result;
  BEGIN
    res := pb.FixSubclass(instr, subclass);
    RETURN res(Instr);
  END FixSubclassInstr;


PROCEDURE Add (VAR list: Instr; instr: Instr);
  BEGIN
    instr. prevInstr := NIL;
    instr. nextInstr := list;
    IF (list # NIL) THEN
      list. prevInstr := instr
    END;
    list := instr
  END Add;

PROCEDURE Remove (VAR list: Instr; instr: Instr);
  BEGIN
    IF (instr. prevInstr = NIL) THEN
      list := instr. nextInstr
    ELSE
      instr. prevInstr. nextInstr := instr. nextInstr
    END;
    IF (instr. nextInstr # NIL) THEN
      instr. nextInstr. prevInstr := instr. prevInstr
    END
  END Remove;

PROCEDURE (pb: ProcBlock) TopSort* (): BOOLEAN;
(**Topological sort on instructions in @oparam{pb}.  If there are no cyclic
   dependencies between the instructions, the result is @code{TRUE}.  *)
  VAR
    instr, next: Instr;
    ready, waiting: Instr;
    res: Result;
    use: Opnd;
    opndCount: LONGINT;
  BEGIN
    ready := NIL;
    waiting := NIL;
    
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr. nextInstr;

      opndCount := instr. SizeOpndList();
      instr. marker := opndCount;
      IF (opndCount = 0) THEN
        Add (ready, instr)
      ELSE
        Add (waiting, instr)
      END;
      instr := next
    END;

    pb. instrList := NIL;
    pb. instrTail := NIL;
    WHILE (ready # NIL) DO
      instr := ready;
      Remove (ready, instr);
      AppendInstr (pb, instr);
      
      (* decrement marker (=count of blocking results) for all uses of all
         results of `instr' *)
      res := instr;
      WHILE (res # NIL) DO
        use := res. useList;
        WHILE (use # NIL) DO
          DEC (use. instr. marker);
          IF (use. instr. marker = 0) THEN
            Remove (waiting, use. instr);
            Add (ready, use. instr)
          END;
          use := use. nextUse
        END;
        res := res. nextResult
      END;
    END;
    RETURN (waiting = NIL)
  END TopSort;

PROCEDURE (pb: ProcBlock) Reverse*;
(**Reverse order of instructions in @oparam{pb}.  *)
  VAR
    instr, next: Instr;
    newList: Instr;
  BEGIN
    newList := NIL;
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr. nextInstr;
      Add (newList, instr);
      instr := next
    END;
    pb. instrList := newList;
  END Reverse;

PROCEDURE (pb: ProcBlock) GetEnter*(): Instr;
  VAR
    instr: Instr;
  BEGIN
    instr := pb. instrList;
    WHILE (instr # NIL) & (instr. opcode # Opcode.enter) DO
      instr := instr. nextInstr
    END;
    RETURN instr
  END GetEnter;

PROCEDURE (pb: ProcBlock) Destroy*;
(**Zaps the whole data structure.  This should help the conservative gc to
   classify its components as garbage.  *)
  VAR
    instr, nextInstr: Instr;
    res, nextResult: Result;
    opnd, nextOpnd: Opnd;
    i: LONGINT;
  BEGIN
    instr := pb.instrList;
    WHILE (instr # NIL) DO
      nextInstr := instr.nextInstr;
      IF (instr.opcode # Opcode.preloadedVar) THEN
        (* need to keep preloadedVar instruction alive for module init code *)
        opnd := instr.opndList;
        WHILE (opnd # NIL) DO
          nextOpnd := opnd.nextOpnd;
          opnd.arg := NIL;
          opnd.nextOpnd := NIL;
          opnd.instr := NIL;
          opnd.nextUse := NIL;
          opnd := nextOpnd;
        END;
        
        res := instr;
        WHILE (res # NIL) DO
          nextResult := res.nextResult;
          res.nextResult := NIL;
          res.instr := NIL;
          res.useList := NIL;
          res.info := NIL;
          res.marker := 0;
          res := nextResult;
        END;
        
        instr.opndList := NIL;
        instr.nextInstr := NIL;
        instr.prevInstr := NIL;
        instr.pos := 0;
      END;
      instr := nextInstr;
    END;
    
    pb.selectReturn := NIL;
    pb.loopContext := NIL;
    pb.instrList := NIL;
    pb.instrTail := NIL;
    pb.procDecl := NIL;
    FOR i := 0 TO LEN(pb.constMap)-1 DO
      IF (pb.constMap[i] # NIL) THEN
        pb.constMap[i].Destroy(); pb.constMap[i] := NIL;
      END;
    END;
    IF (pb.objMap # NIL) THEN
      pb.objMap.Destroy(); pb.objMap := NIL;
    END;
    IF (pb.adrMap # NIL) THEN
      pb.adrMap.Destroy(); pb.adrMap := NIL;
    END;
  END Destroy;

BEGIN
  nil := BigInt.zero.Add(BigInt.zero);  (* force unique instance *)
  ASSERT(nil # BigInt.zero);
END OOC:SSA.
