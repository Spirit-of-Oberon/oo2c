(* 	$Id: Opcode.Mod,v 1.104 2003/09/16 03:27:13 sgreenhill Exp $	 *)
MODULE OOC:SSA:Opcode;
(*  This modules defines opcodes for SSA instructions.
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
     The object can be found in @ofield{*OOC:SSA.AddressDesc.decl}.  This
     instruction produces a value of type address.  *)
  
  enter* = 4;
  select* = 5;
  (**Select one of several states, depending on the value of the selecting
     expression.  This instruction is used for @code{IF}, @code{WITH}, and
     @code{CASE} statements, as well as for the boolean operators @code{&}
     and @code{OR}.
     
     @table @oconst
     @item *OOC:SSA:Opnd.arg
     The selecting expression.

     @item *OOC:SSA:Opnd.arg
     A constant, one of the possible values of the first argument.  For a
     branch of a @code{CASE} statement, the operand is of class
     @oconst{*OOC:SSA:Opnd.arg} and refers either to an instruction of type
     @oconst{labels}, or, for the default path, to the constant @samp{FALSE}.
     
     @item *OOC:SSA:Opnd.arg
     The value of store if the first argument matches the preceeding constant.
     @end table

     There are as many pairs of @samp{(constant, store)} as there are paths
     through the select statement.

     The instruction has one mandatory result of class
     @oconst{*OOC:SSA:Result.store}.  If there @var{store} arguments are
     produced by @oconst{collect} statements, then there are additional
     results, one for each collected value.  These results use the class
     id @oconst{*OOC:SSA:Result.selectValue}.

     FIXME... still need more explanation.  *)
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
     values to the argument lists.

     The result of a collect instruction is used in one of @oconst{select},
     @oconst{loopStart}, @oconst{loopEnd}, or @oconst{exit}.  *)
  
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
     @oconst{selectReturn} instruction.  All other uses are unreachable from
     the point of the @oconst{return} instruction.  *)
  
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
     @oconst{loopEnd} instruction.  *)
  
  
  loopStart* = 10;
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
  loopEnd* = 11;
  (**Marks the end of a loop construct.  The instruction has n+2 arguments:

     @table @oconst
     @item *OOC:SSA:Opnd.arg
     Reference to the corresponding @oconst{loopStart} instruction.

     @item *OOC:SSA:Opnd.backwardFeed
     The input value of @var{store} for the second, third, and so on, iteration
     of the loop.  This is actually a virtual argument to the corresponding
     @oconst{loopStart} instruction.  It is placed with the end of the loop to
     avoid cycles in the instruction graph.  Some algorithms need to treat this
     argument specially, as if it is an argument of the @oconst{loopStart}.

     @item *OOC:SSA:Opnd.storeExit
     Subsequent arguments are the @code{store} results of the loop's
     @code{exit} statements.  Each of them corresponds to a @code{EXIT}
     statement in the source code.
     @end table

     There is one result of class @oconst{*OOC:SSA:Opnd.store}, the value of
     @var{store} as seen by the first instruction after the loop.  Like for
     @oconst{select}, there are additional results if @oconst{collect}
     instructions feed distinct values into this instruction.  *)
  
  get* = 12;
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
     the declaration of the accessed variable.  For variables on the heap, the
     designator begins with the a @otype{*OOC:SSA.TypeRef} of the pointer's
     type, followed by the address of the heap object.
     @end table

     The instruction itself represents the result of the read operation.  If it
     accesses a volatile variable, then it has an additional result, the new
     value of @var{store} that is produced by this read operation.

     Note: Once @oproc{*OOC:SSA:DeadCodeElimination.RemoveDesignators} has been
     run, most @samp{readDesign} and @samp{writeDesign} operands are not
     longer available.  *)
  set* = 13;
  (**Sets the value of a variable.  The source value is always of scalar type.
     The operand list resembles that of a @oconst{get} instruction, using the
     class ids @oconst{*OOC:SSA:Opnd.writeAdr} and
     @oconst{*OOC:SSA:Opnd.writeDesign} to denote the address and the
     designator of the variable.  An additional operand
     @oconst{*OOC:SSA:Opnd.sourceValue} takes the value that should be written
     to memory.

     The instruction has one result of class @oconst{*OOC:SSA:Result.store},
     representing the new value of store with the updated variable.

     Note: Once @oproc{*OOC:SSA:DeadCodeElimination.RemoveDesignators} has been
     run, most @samp{readDesign} and @samp{writeDesign} operands are not
     longer available.  *)
  copy* = 14;
  (**Copy a record or array value.  Used for assignment statements where the
     source and target are not scalar values.  The instruction is very similar
     to the @oconst{copyString} opcode below, with two differences:

     @itemize @bullet
     @item
     The is only one type operand, because the left and right side of the copy
     instruction are of the same type.

     @item
     There is no length operand, because the size of the memory block to be
     copied is size of the first operand's type.
     @end itemize

     Note: Once @oproc{*OOC:SSA:DeadCodeElimination.RemoveDesignators} has been
     run, most @samp{readDesign} and @samp{writeDesign} operands are not
     longer available.  *)  
  copyString* = 15;
  (**Copy a sequence of characters into a string variable.  This corresponds to
     the @samp{COPY} statement.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.type
     The element type of the source value of the copy.  This is a
     @otype{*OOC:SSA:TypeRef} for a character type.

     @item *OOC:SSA:Opnd.type
     The element type of the destination variable of the copy.  This is
     a @otype{*OOC:SSA:TypeRef} for a character type.

     @item *OOC:SSA:Opnd.readAdr
     Like the corresponding argument of @oconst{get}.  If the source of the
     copy operation is a string constant, then this operand refers to the
     constant.

     @item *OOC:SSA:Opnd.readDesign
     Like the corresponding argument of @oconst{get}.  If the source of the
     copy operation is a string constant, then no argument of this type exists.

     @item *OOC:SSA:Opnd.writeAdr
     Like the corresponding argument of @oconst{set}.

     @item *OOC:SSA:Opnd.writeDesign
     Like the corresponding argument of @oconst{set}.

     @item *OOC:SSA:Opnd.arg
     The length of the target variable in characters.  At most this many minus
     one characters are copied, and the termination character @samp{0X} is
     added.
     @end table

     The result is undefined if the source value is not terminated with
     @samp{0X}, or if the target as a length of zero characters.  The
     instruction has one result of class @oconst{*OOC:SSA:Result.store},
     representing the new value of store with the updated variable.

     Note: Once @oproc{*OOC:SSA:DeadCodeElimination.RemoveDesignators} has been
     run, most @samp{readDesign} and @samp{writeDesign} operands are not
     longer available.  *)
  cmpString* = 16;
  (**Compare two string values and return the difference of the first
     characters that differ, or @samp{0} if both strings are equal.
     If the result is negative, then the left side is smaller than the
     right side, and it is positive if the left side is greater than the
     right.
     
     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.type
     The element type of the strings.  This is a
     @otype{*OOC:SSA:TypeRef} for a character type.

     @item *OOC:SSA:Opnd.readAdr
     Like the corresponding argument of @oconst{get}.  If the left side of the
     compare operation is a string constant, then this operand refers to the
     constant.

     @item *OOC:SSA:Opnd.readDesign
     Like the corresponding argument of @oconst{get}.  If the left side of the
     compare operation is a string constant, then this argument does not
     exists.

     @item *OOC:SSA:Opnd.readAdr
     Right side of the compare.

     @item *OOC:SSA:Opnd.readDesign
     Right side of the compare.
     @end table

     The result is undefined if the strings are not terminated with
     @samp{0X}.

     Note: Once @oproc{*OOC:SSA:DeadCodeElimination.RemoveDesignators} has been
     run, most @samp{readDesign} and @samp{writeDesign} operands are not
     longer available.  *)
  concat* = 17;
  (**Concatenate two or more instances of @code{STRING}.  *)
  
  moveBlock* = 18;
  (**Copy a memory block between two addresses in memory.  This corresponds to
     the @samp{SYSTEM.MOVE} statement.
     
     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.readAdr
     Source address.

     @item *OOC:SSA:Opnd.writeAdr
     Destination address.
     
     @item *OOC:SSA:Opnd.arg
     Number of bytes.
     @end table
     
     The result is undefined if source and destination overlap, or if
     the size is negative.  *)
  
  add* = 19;
  (**Addition operator.  The two operands must be of the same type, which is at
     the same time the result of the operation.  There is one exception to this
     rule: if one of the operands is of type @oconst{scAddress}, then the other
     operand can be any integer type, signed or unsigned, and the result type
     is @oconst{scAddress}.  *)
  subtract* = 20;
  negate* = 21;
  multiply* = 22;
  (**Multiplication.  The two operands must be of the same type, which is
     also the result of the operation.  There is one exception: when
     multiplying an index with the size of the element, then the result is
     a value of type @oconst{scAddress}.  *)
  divide* = 23;
  modulo* = 24;

  eql* = 25;
  neq* = 26;
  lss* = 27;
  leq* = 28;
  gtr* = 29;
  geq* = 30;

  and* = 31;
  (**Boolean @samp{AND}.  Note: This opcode does not perform shortcut
     evaluation.  That is, both arguments are always evaluated, irregardless
     of the value of the first argument.  *)
  or* = 32;
  (**Boolean @samp{OR}.  Note: This opcode does not perform shortcut
     evaluation.  That is, both arguments are always evaluated, irregardless
     of the value of the first argument.  *)
  not* = 33;
  (**Boolean @samp{NOT}.  *)

  logicalAnd* = 34;
  logicalOr* = 35;
  logicalXor* = 36;
  logicalComplement* = 37;
  logicalSubtr* = 38;
  setBit* = 39;
  clearBit* = 40;
  
  typeCast* = 41;
  (**Type cast.  Takes one argument, the value that should be
     casted.  The result type of the convertion is the instructions's
     subclass, the source type that of the first argument.  *)
  typeConv* = 42;
  (**Type conversion operation.  Takes one argument, the value that should be
     converted.  The result type of the convertion is the instructions's
     subclass, the source type that of the first argument.  *)
  setMember* = 43;
  (**Set membership test.  First argument is an index, second is the
     set value.  *)
  setRange* = 44;
  (**Set range.  Produces a set with the elements [from, to] inclusive.
     The range is empty if to<from.  *)
  abs* = 45;
  (**Absolute value.  *)
  shiftLeft* = 46;
  (**Arithmetic (and logical) shift left.  *)
  shiftRight* = 47;
  (**Arithmetic shift right.  That is, the left hand side is a signed number,
     and its sign is preserved by the shift operation.  *)
  ash* = 48;
  (**Arithmetic shift.  *)
  cap* = 49;
  (**Capitalize character.  *)
  entier* = 50;
  (**Floating point to integer, rounding to @samp{-inf}.  *)
  indexed* = 51;
  (**Base + index*scale.  *)
  lsh* = 52;
  (**Arithmetic shift.  *)
  rot* = 53;
  (**Rotate bits.  *)
  odd* = 54;
  (**Return @code{TRUE} for odd numbers.  *)
  
  
  call* = 55;
  (**Used to call a procedure or a function.  The first argument is the address
     of the procedure to be called, followed by the call's arguments.  This
     opcode is used both for normal and type-bound procedures.  The address can
     be almost any address expression, and a @oconst{declRef} instruction may
     be used as a shorthand notation for the referenced procedure declaration's
     address.  *)
  
  getLengthHeap* = 56;
  (**Retrieves the length of an open array variable on the heap for a given
     dimension.  Result is the signed integer of the type corresponding to
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
  
  getLengthParam* = 57;
  (**Retrieves the length of an open array variable parameter for a given
     dimension.  Operands are semantics are like @oconst{getLengthHeap}.  *)
  
  copyParameter* = 58;
  (**Allocates space for a local copy of a value parameter that was passed to
     the procedure as a reference, and initialiazes the local copy using the
     data of the caller's argument.  Instructions of this type are a
     specialization of @oconst{address}, and the instruction objects are
     instances of @otype{*OOC:SSA.Address}.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA.Opnd.arg
     Number of elements in the array.  For multi-dimensional arrays, this
     is the product of the lengths of all dimensions, of both open and fixed
     size dimensions.  For non-array variables, this is @samp{1}.
     
     @item *OOC:SSA.Opnd.arg
     The size of the parameter in bytes.
     @end table

     The result of the instruction is the address of the new copy.  An
     additional result is the new value of @var{store}.  *)

  newObject* = 59;
  (**Allocates space for an array or record object on the heap.  This opcode is
     used for both fixed size arrays, arrays with open dimensions, and records.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.type
     The type of the pointer to which the new object will be assigned.

     @item *OOC:SSA.Opnd.arg
     For every open dimension of the array type, one argument with the length
     of the dimension.  For a fixed size array or record, no arguments of this
     class exist.
     @end table

     The result of the instruction is the address of the new object.  An
     additional result is the new value of @var{store}.  *)
  
  newBlock* = 60;
  (**Allocates an untyped block of heap space.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.type
     The type of the pointer to which the new object will be assigned.

     @item *OOC:SSA.Opnd.arg
     The size of the block in bytes.
     @end table

     The result of the instruction is the address of the new object.  An
     additional result is the new value of @var{store}.  *)
  
  typeTag* = 61;
  (**Returns the type tag of a pointer variable or of a variable parameter.

     @table @oconst
     @item *OOC:SSA.Opnd.arg
     This is either a @oconst{declRef} refering to a @code{VAR} record
     parameter, a @oconst{typeRef} denoting a record type, or a pointer value.
     @end table

     The result of the instruction is the address of the type descriptor.  *)
  
  typeTest* = 62;
  (**Performs a type test on a given type tag.

     @table @oconst
     @item *OOC:SSA.Opnd.arg
     The type tag of the variable being tested.  This an address of a type
     descriptor.

     @item *OOC:SSA:Opnd.type
     The type of which the first operand must be an extension of.  The argument
     is an instance of @otype{*OOC:SSA.TypeRef}.  This type is either equal to
     the one of the first operand, or an extension of it.
     @end table

     The result of the instruction is a boolean value.  *)

  tbProcAddress* = 63;
  (**Calculates the address of the procedure that is to be used for a dynamic
     type-bound call.

     @table @oconst
     @item *OOC:SSA.Opnd.arg
     The type tag of the variable that is the call's receiver.

     @item *OOC:SSA.Opnd.arg
     The static procedure declaration that is used by the call in the source
     code.  The referenced instruction's opcode is @oconst{declRef}.
     @end table

     Result of the instruction is the address of the procedure.  *)

  assert* = 64;
  halt* = 65;
  
  checkIndex* = 66;
  (**Ensures that an index is value with respect to a given array length.  An
     exception is raised if the index is negative, or less or equal to the
     array's length.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA.Opnd.arg
     The index value.

     @item *OOC:SSA.Opnd.arg
     The length of the array.
     @end table

     The result of the instruction is the checked index.  One additional result
     is the new value of @var{store}, another one is of class
     @oconst{*OOC:SSA:Result.exception}.  *)
  checkPointer* = 67;
  (**Raise an exception if the pointer value is @code{NIL}.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA.Opnd.arg
     The pointer value.
     @end table

     The result of the instruction is the checked pointer.  One additional
     result is the new value of @var{store}, another one is of class
     @oconst{*OOC:SSA:Result.exception}.  *)
  typeGuard* = 68;
  (**Raise an exception if the given type is not an extension of the type tag.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA.Opnd.arg
     The address of the variable being tested.

     @item *OOC:SSA.Opnd.arg
     The type tag of the variable.  This an address of a type descriptor.

     @item *OOC:SSA:Opnd.type
     The type of which the first operand must be an extension of.  The argument
     is an instance of @otype{*OOC:SSA.TypeRef}.  This type is either equal to
     the one of the first operand, or an extension of it.
     @end table

     The result of the instruction is the checked variable address, that is,
     the value of the second argument.  One additional result is the new value
     of @var{store}, another one is of class
     @oconst{*OOC:SSA:Result.exception}.  *)

  failedCase* = 69;
  failedWith* = 70;
  failedTypeAssert* = 71;
  
  tryStart* = 72;
  (**Marks the beginning of a @code{TRY} block.

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.
     @end table

     The result of the instruction is an indicator which path through the
     @code{TRY} statement should be taken.  @samp{FALSE} means the body,
     @code{TRUE} the alternative path through the @code{CATCH} clauses.  The
     value of the second argument.  This instruction has @emph{two} results for
     @var{store}, the first (result index @samp{1}) for the body and the second
     (result index @samp{2}) is used for the @code{CATCH} clauses.  *)
  tryEnd* = 73;
  (**Marks the end of a @code{TRY} block.  This instruction has 2 operands
     representing values of @var{store}.  The first operand is the @var{store}
     at the end of the @code{TRY}'s body.  The second one holds the @var{store}
     after processing the @code{CATCH} clauses.  *)
  raiseException* = 74;
  (**Raise an exception.  Takes @var{store} and the exception as
     arguments and produces a new @var{store}.  *)
  (*storeCurrentException* = 75;  ... unused *)
  currentException* = 76;
  (**Produces a pointer to the current exception.  Result is @code{NIL} if
     there is no active exception.  Takes its @oconst{pushExceptionContext}
     instruction and @var{store} as arguments.  *)
  clearException* = 77;
  (**Clears the variable with the current exception.  Takes 
     its @oconst{pushExceptionContext} instruction and @var{store} as
     arguments and produces a new @var{store}.  *)
  pushExceptionContext* = 78;
  (**Puts the current exception handler context on the top of the stack.
     This instruction takes a single argument, the @var{store} result of its
     associated @oconst{tryStart} instruction.  It has one additional result:
     the new @var{store}.  *)
  popExceptionContext* = 79;
  (**Removes one or more top entries from the stack of exception handlers.
     Takes @var{store} as argument and produces a new @var{store}.  The second
     argument is a positive integer constant with the number of contexts that
     should be removed.  *)
  activateContext* = 80;
  (**Passes control to the top-level entry in the stack of exception handlers.
     Takes @var{store} as argument and produces a new @var{store}.  This
     operation never returns.  *)
  
  preloadedVar* = 81;
  (**Value of a variable that is defined as part of the module's
     initialization.  The instruction is both a placeholder for the value,
     and a description how the actual value is computed during run-time.
     The first argument is the name of a C function, optionally with a
     type cast prefix, followed by the arguments that should be passed to
     the function.  All arguments are constants.  *)
  
  labels* = 82;
  (**Pseudo instruction listing all labels of a @code{CASE} branch.  Every
     range and every single value is represented by two consecutive operands,
     the lower and the upper bound.  All operands are of class
     @oconst{*OOC:SSA:Opnd.arg}  *)
  
  dgate* = 83;
  (**Represents a value of a designator at the position of an instruction that
     selects from different flows of control.  This opcode is used internally
     by @omodule{*OOC:SSA:Destore}, and should not appear outside this module.

     @table @oconst
     @item *OOC:SSA:Opnd.dgateBase
     The associated @oconst{select}, @oconst{loopStart}, or @oconst{loopEnd}
     instruction.

     @item *OOC:SSA.Opnd.arg
     Replacement value.  This is either the @var{store} result of the
     associated instruction, a @var{store} originating elsewhere, a reference
     to a @oconst{*OOC:SSA:Result.dgatePlaceholder} result of the
     @oconst{dgate} instruction itself (signalling that the final replacement
     value is a gated value), or a valid value.

     @item *OOC:SSA.Opnd.arg
     For each path into the selecting instruction, the value of the designator
     for this path.  This is either a @var{store}, a reference to a
     @oconst{dgate}, or a valid value.
     @end table  *)
  
  designStandin* = 84;
  (**@oproc{*OOC:SSA:DeadCodeElimination.RemoveDesignators} replaces computed
     @samp{readDesign} and @samp{writeDesign} operands with a reference to
     this instruction.  Only a single instruction with this opcode exists in
     a procedure, so that CSE can still discover equivalent computations.  *)

  equiv* = 85;
  (**Marks a equivalence between two values.  Both results are of class
     @oconst{*OOC:SSA:Opnd.arg}.  The first result is the preferred
     representation of the two values.  The instruction has one use,
     which is an operand of a @oconst{noop} instruction.  Right now,
     only loop rewriting makes use of this instruction, in combination with
     partial redundancy elimination.  *)
  equivPRE* = 86;
  (**Like @oconst{equiv}, but used only in the context of the algorithm for
     partial redundancy elimination.  *)
     
  vtableProcAddress* = 87;
  (**Calculates the address of the procedure that is to be used for a dynamic
     vtable type-bound call.

     @table @oconst
     @item *OOC:SSA.Opnd.arg
	 A pointer to a VTABLE record.

     @item *OOC:SSA.Opnd.arg
     The static procedure declaration that is used by the call in the source
     code.  The referenced instruction's opcode is @oconst{declRef}.
     @end table

     Result of the instruction is the address of the procedure.  *)

  noop* = 88;
  (**No operation.  Used to anchor other information in the SSA graph.
     Conceptually, every result of this instruction is the value of the
     corresponding operand.  Any operands beyond the number of results is
     simply swallowed.  The instruction itself has no uses.  *)
  
  lastOpcode* = noop;
  
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
  
  scReal32* = 10;
  (**Single precision IEEE-754 floating point number.  *)
  scReal64* = 11;
  (**Double precision IEEE-754 floating point number.  *)

  lastSubclass* = scReal64;
  
PROCEDURE IsSigned* (subclass: Subclass): BOOLEAN;
  BEGIN
    RETURN (scSigned8 <= subclass) & (subclass <= scSigned64)
  END IsSigned;

PROCEDURE IsUnsigned* (subclass: Subclass): BOOLEAN;
  BEGIN
    RETURN (scUnsigned8 <= subclass) & (subclass <= scUnsigned64)
  END IsUnsigned;

PROCEDURE ConvDiffersFromCast* (from, to: Subclass): BOOLEAN;
(**Returns @code{TRUE}, if a C type cast expression would do a type conversion,
   instead of merely reinterpreting the bit pattern of the source value.  *)
  BEGIN
    RETURN (from < scReal32) # (to < scReal32);
  END ConvDiffersFromCast;

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
    | scReal32    : scstr := "r32"
    | scReal64    : scstr := "r64"
    END;
    COPY (scstr, name)
  END GetSubclassName;

PROCEDURE GetName* (class: Class; subclass: Subclass; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of a (class, subclass) pair.  *)
  VAR
    cstr, scstr: ARRAY 32 OF CHAR;
  BEGIN
    CASE class OF
    | const: cstr := "const";
    | declRef: cstr := "declref";
    | typeRef: cstr := "typeref";
    | address: cstr := "address";

    | enter: cstr := "enter";
    | select: cstr := "select";
    | collect: cstr := "collect";
    | labels: cstr := "labels";
    | return: cstr := "return";
    | selectReturn: cstr := "select-return";
    | exit: cstr := "exit";
    | loopStart: cstr := "loop-start";
    | loopEnd: cstr := "loop-end";
      
      
    | get: cstr := "get";
    | set: cstr := "set";
    | copy: cstr := "copy";
    | copyString: cstr := "copy-string";
    | cmpString: cstr := "cmp-string";
    | concat: cstr := "concat";
    | moveBlock: cstr := "move-block";
      
    | getLengthHeap: cstr := "get-length-heap";
    | getLengthParam: cstr := "get-length-param";
    | copyParameter: cstr := "copy-parameter";
    | newObject: cstr := "new-object";
    | newBlock: cstr := "new-block";
    | typeTag: cstr := "type-tag";
    | typeTest: cstr := "type-test";
    | tbProcAddress: cstr := "tb-proc-address";
      
    | add: cstr := "add";
    | subtract: cstr := "subtract";
    | negate: cstr := "negate";
    | multiply: cstr := "multiply";
    | divide: cstr := "divide";
    | modulo: cstr := "modulo";

    | eql: cstr := "eql";
    | neq: cstr := "neq";
    | lss: cstr := "lss";
    | leq: cstr := "leq";
    | gtr: cstr := "gtr";
    | geq: cstr := "geq";
      
    | and: cstr := "and";
    | or: cstr := "or";
    | not: cstr := "not";
    | logicalAnd: cstr := "logical-and";
    | logicalOr: cstr := "logical-or";
    | logicalXor: cstr := "logical-xor";
    | logicalComplement: cstr := "logical-complement";
    | logicalSubtr: cstr := "logical-subtr";
    | setBit: cstr := "set-bit";
    | clearBit: cstr := "clear-bit";
      
    | typeCast: cstr := "type-cast";
    | typeConv: cstr := "type-conv";
    | setMember: cstr := "set-member";
    | setRange: cstr := "set-range";
    | abs: cstr := "abs";
    | shiftLeft: cstr := "shift-left";
    | shiftRight: cstr := "shift-right";
    | ash: cstr := "ash";
    | cap: cstr := "cap";
    | entier: cstr := "entier";
    | indexed: cstr := "indexed";
    | lsh: cstr := "lsh";
    | rot: cstr := "rot";
    | odd: cstr := "odd";
      
    | call: cstr := "call";

    | assert: cstr := "assert";
    | halt: cstr := "halt";
    | checkIndex: cstr := "check-index";
    | checkPointer: cstr := "check-pointer";
    | typeGuard: cstr := "type-guard";
    | failedCase: cstr := "failed-case";
    | failedWith: cstr := "failed-with";
    | failedTypeAssert: cstr := "failed-type-assert";
    | preloadedVar: cstr := "preloaded-var";

    | tryStart: cstr := "try-start";
    | tryEnd: cstr := "try-end";
    | raiseException: cstr := "raise-exception";
    | currentException: cstr := "current-exception";
    | clearException: cstr := "clear-exception";
    | pushExceptionContext: cstr := "push-exception-context";
    | popExceptionContext: cstr := "pop-exception-context";
    | activateContext: cstr := "activate-context";
      
    | dgate: cstr := "dgate";
    | designStandin: cstr := "design-standin";
    | equiv: cstr := "equiv";
    | equivPRE: cstr := "equiv-pre";
    | vtableProcAddress: cstr := "vtable-proc-address";
    | noop: cstr := "noop";
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
    type := type.Deparam();
    WITH type: Sym.PredefType DO
      CASE type. id OF
      | Predef.void: RETURN scNone
      | Predef.char: RETURN scUnsigned8
      | Predef.longchar: RETURN scUnsigned16
      | Predef.ucs4char: RETURN scUnsigned32
      | Predef.boolean: RETURN scUnsigned8
      | Predef.shortint: RETURN scSigned8
      | Predef.integer: RETURN scSigned16
      | Predef.longint: RETURN scSigned32
      | Predef.hugeint: RETURN scSigned64
      | Predef.real: RETURN scReal32
      | Predef.longreal: RETURN scReal64
      | Predef.set: RETURN scUnsigned32
      | Predef.byte: RETURN scUnsigned8
      | Predef.ptr: RETURN scAddress
      | Predef.stringChar, Predef.stringLongChar, Predef.stringUCS4Char:
        RETURN scAddress
      | Predef.nil: RETURN scAddress
      END;
      
    | type: Sym.Array DO
      RETURN scNone;

    | type: Sym.Record DO
      RETURN scNone;

    | type: Sym.Pointer DO
      RETURN scAddress;

    | type: Sym.FormalPars DO
      RETURN scAddress;

    | type: Sym.TypeVar DO
      RETURN TypeToSubclass(type.bound);
      
    ELSE
      Log.Type ("++ Unknown type in TypeToSubclass", type);
      ASSERT (FALSE);
    END;
  END TypeToSubclass;

END OOC:SSA:Opcode.
