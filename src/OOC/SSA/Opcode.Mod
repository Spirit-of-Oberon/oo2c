(* 	$Id$	 *)
MODULE OOC:SSA:Opcode;
(*  This modules defines opcodes for SSA instructions.
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
  Log, Strings, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef;

  
TYPE
  Class* = SHORTINT;
  (**The class of an instruction identifies the operation.  *)
  Subclass* = SHORTINT;
  (**For operations that can work on several different types, the subclass id
     designates the variant of the operation that should be used.  For some
     opcodes, the subclass identifies the result type of the operation.  Use
     @oproc{*OOC:SSA.Instr.GetResultType} to get the result type of an
     operation.  *)

CONST
  const* = 0;
  (**Wrapper instruction for constant values.  Instance of
     @otype{*OOC:SSA.Const}.  Takes no SSA operands.  Result is the constant
     value @ofield{*OOC:SSA.Const.value}.  *)
  declRef* = 1;
  (**Wrapper instruction for references to declared objects, like variables or
     procedures.  Instance of @otype{*OOC:SSA.DeclRef}.  Takes no SSA operands.
     The declaration can be found in @ofield{*OOC:SSA.DeclRef.decl}.  This
     instruction produces no storable value.  *)
  typeRef* = 2;
  (**Wrapper instruction for references to type definitions, like pointer or
     array types.  Instance of @otype{*OOC:SSA.TypeRef}.  Takes no SSA
     operands.  The type can be found in @ofield{*OOC:SSA.TypeRef.type}.  This
     instruction produces no storable value.  *)
  address* = 3;
  (**Denotes the address of a declared object, for example of a variable or a
     procedures.  Instance of @otype{*OOC:SSA.Address}.  Takes no SSA operands.
     The object can be found in @ofield{*OOC:SSA.Address.decl}.  This
     instruction produces a value of type address.  *)
  
  enter* = 4;
  select* = 5;
  collect* = 6;
  (**A @oconst{collect} instruction temporarily merges local values into the
     global @var{store} state.  This result is subsequently fed into an
     instruction that joins multiple paths of control flow, for example a
     @oconst{select} or a @oconst{loopEnd} (as a stand-in for
     @oconst{loopStart}).  The local values resurface in the joining
     instruction as its results.  The first argument of a @oconst{collect}
     corresponds to the first (non-instruction) result, the second argument to
     the second result, and so on.

     Collects are a little unusual in that they describe an effect that, when
     expressed in terms of basic blocks and jumps, happens as part of a jump
     from the originating block to the joining block.  That is, they define an
     operation that cannot be placed at the end of the originating block, nor
     at the beginning of the target block, but must happen somewhere on the way
     between them.  This can make scheduling and code generation slightly
     tricky.  One way to resolve this is to introduce an additional block
     representing the edge between the ``real'' blocks, containing the
     @oconst{collect} as its sole instruction.

     Operands of the instruction:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.arg
     Arbitrary number of values (possible no value) that are collected in the
     @var{store}.
     @end table

     There is one result, the new value of @var{store}.

     In the initial SSA code, as produced from the intermediate representation,
     only @oconst{collect} instructions with the @var{store} operand are
     created, which are basically identity operations on @var{store}.
     @omodule{*OOC:SSA:Destore} adds further collects, and typically adds more
     values to the argument lists.  *)
  
  return* = 7;
  (**This instruction serves two purposes: it marks the place where control
     flow exists the procedure, and, for function procedures, it defines the
     scalar value that should be produced as the function's result. The
     operands of the instruction and their class ids are in this order:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.functionResult
     The result that the function procedure should return when reaching this
     return statement.  This operand is only present within functions.
     @end table

     The instruction has one result of class @oconst{*OOC:SSA:Result.store}.
     There is at least one use of this result, as operand of the procedure's
     @oconst{selectReturn} instruction.  [Note: Don't know if there will be
     more uses.  FIXME...]  *)
  
  selectReturn* = 8;
  (**Chooses the return statement that leaves the procedure or function.  The
     statement takes @var{n}+2 arguments, all defining values of @var{store} at
     the end of their corresponding branch of control flow.

     @table @oconst
     @item *OOC:SSA:Opnd.storeEnter
     The first argument is the initial value of @var{store} that enters the
     procedure, represented by the @oconst{*OOC:SSA:Result.store} result of the
     @code{enter} instruction.  Implicitly, this argument determines which one
     of the possible @code{return} statements is selected.  It serves as a
     proxy for the selecting expression found in @code{select} statements.
     Assuming a fully deterministic program and no concurrency, the input data
     in the initial @var{store} determines excactly which one of the
     @code{return} statements is taken.

     @item *OOC:SSA:Opnd.storeReturn
     Subsequent arguments are the @code{store} results of the procedure's
     @code{return} statements.  Each of them corresponds to a @code{RETURN}
     statement in the source code.  There are no other instructions between a
     @code{return} and its @code{select-return} instruction.  That is, control
     passes directly to @code{select-return}, and the @code{return} defines the
     output state of the procedure, as represented by its @code{store} result.

     @item *OOC:SSA:Opnd.storeExit
     The last argument is the value of @var{store} at the end of the function
     or procedure.
     @end table  *)

  exit* = 9;
  (**This instruction marks the place where control flow exists the
     @code{LOOP}.  The instruction has one operand:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.
     @end table
     
     The instruction has one result of class @oconst{*OOC:SSA:Result.store}.
     There is one use of this result, as operand of the loop's
     @oconst{selectExit} instruction.  *)
  
  
  selectExit* = 10;
  (**Chooses the @code{EXIT} statement that leaves a @code{LOOP}.  The
     statement takes @var{n}+1 arguments.  All but the first one define values
     of @var{store} at the end of their corresponding branch of control flow,
     that is at the place of the @code{EXIT} instructions.

     @table @oconst
     @item *OOC:SSA:Opnd.arg
     The first argument refers to the loop's @oconst{loopEnd} instruction.

     @item *OOC:SSA:Opnd.storeExit
     Subsequent arguments are the @code{store} results of the loop's
     @code{exit} statements.  Each of them corresponds to a @code{EXIT}
     statement in the source code.
     @end table  *)

  loopStart* = 11;
  (**Marks the beginning of a loop construct.  It has a single operand:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The value of @var{store} before the loop.  This is the input value for the
     first iteration of the loop.
     @end table

     Implicitly, the instruction has a second input parameter: the
     @oconst{*OOC:SSA:Opnd.backwardFeed} argument of its corresponding
     @oconst{loopEnd}.  This is the value of store at the end of the loop.  If
     the loop is evaluted again, then it serves as the input value for the next
     iteration.  This input has been moved from @oconst{loopStart} to
     @oconst{loopEnd} so that the directed graph of definitions and uses is
     acyclic.

     There is one result, the value of @var{store} as seen by the loop body
     when an iteration begins.  *)
  loopEnd* = 12;
  (**Marks the end of a loop construct.  It has four arguments:

     @table @oconst
     @item *OOC:SSA:Opnd.arg
     Reference to the corresponding @oconst{loopStart} instruction.

     @item *OOC:SSA:Opnd.store
     Value of @var{store} once evaluation of the loop is done.  If the
     loop has been completed, the instructions after the loop see the
     global state represented by this value.

     @item *OOC:SSA:Opnd.arg
     The exit predicate of the loop.  A boolean value.

     @item *OOC:SSA:Opnd.arg
     The exit conditional of the loop, a boolean constant.  If the value of the
     preceding argument equals this value, then the loop is exited.  Otherwise,
     its body is evaluted again, using the second argument of
     @oconst{loopStart} as its current @var{store}.

     @item *OOC:SSA:Opnd.backwardFeed
     The input value of @var{store} for the second, third, and so on, iteration
     of the loop.  This is actually a virtual argument to the corresponding
     @oconst{loopStart} instruction.
     @end table

     There is one result, the value of @var{store} as seen by the first
     instruction after the loop.  *)
  
  get* = 13;
  (**Retrieves the value of a variable.  Result is always a scalar value.  The
     operands of the instruction and their class ids are in this order:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.readAdr
     The address from which the value is read.

     @item *OOC:SSA:Opnd.readDesign
     The symbolic representation of the variable's designator.  Depending on
     the designator, several successive operands can share this class.  For
     non-heap variables, the first entry in the designator is a reference to
     the declaration of the accessed variable.  For variables on the heap,
     the designator begins with the address, that is, it duplicates the
     second argument @oconst{*OOC:SSA:Opnd.readAdr}.
     @end table

     The instruction itself represents the result of the read operation.  If it
     accesses a volatile variable, then it has an additional result, the new
     value of @var{store} that is produced by this read operation.  *)
  set* = 14;
  (**Sets the value of a variable.  The source value is always of scalar type.
     The operand list resembles that of a @oconst{get} instruction, using the
     class ids @oconst{*OOC:SSA:Opnd.writeAdr} and
     @oconst{*OOC:SSA:Opnd.writeDesign} to denote the address and the
     designator of the variable.  An additional operand
     @oconst{*OOC:SSA:Opnd.sourceValue} takes the value that should be written
     to memory.

     The instruction has one result of class @oconst{*OOC:SSA:Result.store},
     representing the new value of store with the updated variable.  *)
  copy* = 15;

  add* = 16;
  (**Addition operator.  The two operands must be of the same type, which is at
     the same time the result of the operation.  There is one exception to this
     rule: if one of the operands is of type @oconst{scAddress}, then the other
     operand can be any integer type, signed or unsigned, and the result type
     is @oconst{scAddress}.  *)
  subtract* = 17;
  negate* = 18;
  multiply* = 19;
  (**Multiplication.  The two operands must be of the same type, which is
     also the result of the operation.  There is one exception: when
     multiplying an index with the size of the element, then the result is
     a value of type @oconst{scAddress}.  *)
  divide* = 20;

  eql* = 21;
  neq* = 22;
  lss* = 23;
  leq* = 24;
  gtr* = 25;
  geq* = 26;

  and* = 27;
  or* = 28;
  not* = 29;
  
  cap* = 30;
  
  assert* = 31;
  call* = 32;
  
  getLength* = 33;
  (**Retrieves the length of an open array variable for a given dimension.
     Result is the signed integer of the type corresponding to
     @oconst{Predef.lengthType}.  The operands of the instruction resemble that
     of @oconst{get}, with the @var{store} operand replaced with the dimension:

     @table @oconst
     @item *OOC:SSA:Opnd.dimension
     Dimension for which the length should be retrieved.

     @item *OOC:SSA:Opnd.readAdr
     Like the corresponding argument of @oconst{get}.

     @item *OOC:SSA:Opnd.readDesign
     Like the corresponding argument of @oconst{get}.
     @end table

     The instruction itself represents the result of the operation.  *)
  
  copyParameter* = 34;
  (**Allocates space for a local copy of a value parameter that was passed to
     the procedure as a reference, and initialiazes the local copy using the
     data of the caller's argument.  Instructions of this type are a
     specialization of @oconst{address}, and the instruction objects are
     instances of @otype{*OOC:SSA.Address}.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA.Opnd.arg
     The size of the parameter in bytes.
     @end table

     The result of the instruction is the address of the new copy.  An
     additional result is the new value of @var{store}.  *)

  newArray* = 35;
  (**Allocates space for an array object on the heap.  This opcode is used for
     both fixed size arrays and arrays with open dimensions.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.type
     The type of the pointer to which the new object will be assigned.

     @item *OOC:SSA.Opnd.arg
     For every open dimension of the array type, one argument with the length
     of the dimension.  For a fixed size array, no arguments of this class
     exist.
     @end table

     The result of the instruction is the address of the new object.  An
     additional result is the new value of @var{store}.  *)
  
CONST
  scNone* = 0;
  (**The operation has no variants.  *)
  scSigned8* = 1;
  (**Designates a signed 8 bit result or operands.  *)
  scSigned16* = 2;
  (**Designates a signed 16 bit result or operands.  *)
  scSigned32* = 3;
  (**Designates a signed 32 bit result or operands.  *)
  scSigned64* = 4;
  (**Designates a signed 64 bit result or operands.  *)
  scUnsigned8* = 5;
  (**Designates an unsigned 8 bit result or operands.  *)
  scUnsigned16* = 6;
  (**Designates an unsigned 16 bit result or operands.  *)
  scUnsigned32* = 7;
  (**Designates an unsigned 32 bit result or operands.  *)
  scUnsigned64* = 8;
  (**Designates an unsigned 64 bit result or operands.  *)
  scAddress* = 9;
  (**Designates an address or pointer result or operands.  *)
  scBoolean* = scUnsigned8;
  (**Maps to the integer type that is used to store boolean values.  *)
  scLength* = scSigned32;
  (**Maps to the integer type that is used to store length of arrays.  *)

  scMerge* = 10;
  (**Subclass of a @oconst{select} instruction.  *)
  scExit* = 11;
  (**Subclass of a @oconst{select} instruction.  *)
  scReturn* = 12;
  (**Subclass of a @oconst{select} instruction.  *)
  

PROCEDURE IsSigned* (subclass: Subclass): BOOLEAN;
  BEGIN
    RETURN (scSigned8 <= subclass) & (subclass <= scSigned64)
  END IsSigned;

PROCEDURE IsUnsigned* (subclass: Subclass): BOOLEAN;
  BEGIN
    RETURN (scUnsigned8 <= subclass) & (subclass <= scUnsigned64)
  END IsUnsigned;

PROCEDURE GetSubclassName* (subclass: Subclass; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of a subclass id.  *)
  VAR
    scstr: ARRAY 16 OF CHAR;
  BEGIN
    CASE subclass OF
    | scNone      : scstr := "none"
    | scSigned8   : scstr := "i8"
    | scSigned16  : scstr := "i16"
    | scSigned32  : scstr := "i32"
    | scSigned64  : scstr := "i64"
    | scUnsigned8 : scstr := "u8"
    | scUnsigned16: scstr := "u16"
    | scUnsigned32: scstr := "u32"
    | scUnsigned64: scstr := "u64"
    | scAddress   : scstr := "adr"
    END;
    COPY (scstr, name)
  END GetSubclassName;

PROCEDURE GetName* (class: Class; subclass: Subclass; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of a (class, subclass) pair.  *)
  VAR
    cstr, scstr: ARRAY 16 OF CHAR;
  BEGIN
    CASE class OF
    | const: cstr := "const";
    | declRef: cstr := "declref";
    | typeRef: cstr := "typeref";
    | address: cstr := "address";

    | enter: cstr := "enter";
    | select: cstr := "select";
    | collect: cstr := "collect";
    | return: cstr := "return";
    | selectReturn: cstr := "select-return";
    | exit: cstr := "exit";
    | selectExit: cstr := "select-exit";
    | loopStart: cstr := "loop-start";
    | loopEnd: cstr := "loop-end";
      
      
    | get: cstr := "get";
    | set: cstr := "set";
    | copy: cstr := "copy";
    | getLength: cstr := "get-length";
    | copyParameter: cstr := "copy-parameter";
    | newArray: cstr := "new-array";

    | add: cstr := "add";
    | subtract: cstr := "subtract";
    | negate: cstr := "negate";
    | multiply: cstr := "multiply";
    | divide: cstr := "divide";

    | eql: cstr := "eql";
    | neq: cstr := "neq";
    | lss: cstr := "lss";
    | leq: cstr := "leq";
    | gtr: cstr := "gtr";
    | geq: cstr := "geq";
      
    | and: cstr := "and";
    | or: cstr := "or";
    | not: cstr := "not";
      
    | cap: cstr := "cap";
      
    | assert: cstr := "assert";
    | call: cstr := "call";
    END;
    
    COPY (cstr, name);
    IF (subclass # scNone) THEN
      GetSubclassName (subclass, scstr);
      Strings.Append ("-", name);
      Strings.Append (scstr, name)
    END;
  END GetName;

PROCEDURE TypeToSubclass* (type: Sym.Type): Subclass;
  BEGIN
    WITH type: Sym.PredefType DO
      CASE type. id OF
      | Predef.void: RETURN scNone
      | Predef.char: RETURN scUnsigned8
      | Predef.boolean: RETURN scUnsigned8
      | Predef.shortint: RETURN scSigned8
      | Predef.integer: RETURN scSigned16
      | Predef.longint: RETURN scSigned32
      | Predef.charString: RETURN scAddress
      | Predef.longcharString: RETURN scAddress
      END;
      
    | type: Sym.Array DO
      RETURN scNone;

    | type: Sym.Record DO
      RETURN scNone;

    | type: Sym.Pointer DO
      RETURN scAddress;
      
    ELSE
      Log.Type ("++ Unknown type in TypeToSubclass", type);
      ASSERT (FALSE);
    END;
  END TypeToSubclass;

END OOC:SSA:Opcode.
