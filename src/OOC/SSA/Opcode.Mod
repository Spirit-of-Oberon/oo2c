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


TYPE
  Class* = SHORTINT;
  Subclass* = SHORTINT;

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
  exit* = 4;
  
  get* = 5;
  (**Retrieves the value of a variable.  The operands of the instruction and
     their class ids are in this order:

     @table @oconst
     @item *OOC:SSA:Opnd.store
     The current value of the @var{store}.

     @item *OOC:SSA:Opnd.readAdr
     The address from which the value is read.

     @item *OOC:SSA:Opnd.readDesign@dots{}
     The symbolic representation of the variable's designator.  For non-heap
     variables, the first entry in the designator is a reference to the
     declaration of the accessed variable.
     @end table  *)
  set* = 6;
  copy* = 7;
  
  assert* = 8;
  call* = 9;

CONST
  scNone* = 0;
  

PROCEDURE GetName* (opcode: Class; subclass: Subclass; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of an (opcode, subclass) pair.  *)
  BEGIN
    CASE opcode OF
    | const: COPY ("const", name)
    | declRef: COPY ("declref", name)
    | address: COPY ("address", name)

    | get: COPY ("get", name)
    | set: COPY ("set", name)
    | copy: COPY ("copy", name)
          
    | enter: COPY ("enter", name)
    | exit: COPY ("exit", name)
    | assert: COPY ("assert", name)
    | call: COPY ("call", name)
    END;
  END GetName;

END OOC:SSA:Opcode.
