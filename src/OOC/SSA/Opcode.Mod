(* 	$Id$	 *)
MODULE OOC:SSA:Opcode;
(*  This modules defines opcodes for SSA instructions.
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
  Strings, OOC:SymbolTable:Item, OOC:SymbolTable:Predef;

  
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
  address* = 2;
  (**Denotes the address of a declared object, for example of a variable or a
     procedures.  Instance of @otype{*OOC:SSA.Address}.  Takes no SSA operands.
     The object can be found in @ofield{*OOC:SSA.Address.decl}.  This
     instruction produces a value of type address.  *)
  
  enter* = 3;
  select* = 4;
  
  return* = 5;
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
  
  selectReturn* = 6;
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

  get* = 7;
  (**Retrieves the value of a variable.  The operands of the instruction and
     their class ids are in this order:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.readAdr
     The address from which the value is read.

     @item *OOC:SSA:Opnd.readDesign
     The symbolic representation of the variable's designator.  Depending on
     the designator, several successive operands can share this class.  For
     non-heap variables, the first entry in the designator is a reference to
     the declaration of the accessed variable.
     @end table  *)
  set* = 8;
  copy* = 9;
  
  assert* = 10;
  call* = 11;

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

  scMerge* = 10;
  (**Subclass of a @const{select} instruction.  *)
  scExit* = 11;
  (**Subclass of a @const{select} instruction.  *)
  scReturn* = 12;
  (**Subclass of a @const{select} instruction.  *)
  

PROCEDURE IsSigned* (subclass: Subclass): BOOLEAN;
  BEGIN
    RETURN (scSigned8 <= subclass) & (subclass <= scSigned64)
  END IsSigned;

PROCEDURE IsUnsigned* (subclass: Subclass): BOOLEAN;
  BEGIN
    RETURN (scUnsigned8 <= subclass) & (subclass <= scUnsigned64)
  END IsUnsigned;

PROCEDURE GetName* (class: Class; subclass: Subclass; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of a (class, subclass) pair.  *)
  VAR
    cstr, scstr: ARRAY 16 OF CHAR;
  BEGIN
    CASE class OF
    | const: cstr := "const";
    | declRef: cstr := "declref";
    | address: cstr := "address";

    | get: cstr := "get";
    | set: cstr := "set";
    | copy: cstr := "copy";
          
    | enter: cstr := "enter";
    | select: cstr := "select";
    | return: cstr := "return";
    | selectReturn: cstr := "select-return";
      
    | assert: cstr := "assert";
    | call: cstr := "call";
    END;
    
    COPY (cstr, name);
    IF (subclass # scNone) THEN
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
      Strings.Append ("-", name);
      Strings.Append (scstr, name)
    END;
  END GetName;

PROCEDURE TypeToSubclass* (type: Item.Type): Subclass;
  BEGIN
    WITH type: Item.PredefType DO
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
    END;
  END TypeToSubclass;

END OOC:SSA:Opcode.
