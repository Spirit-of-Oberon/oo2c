(* 	$Id$	 *)
MODULE OOC:SSA:Opnd;
(*  Symbolic names for operand classes.
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
  OOC:SSA:Result;

  
TYPE
  Class* = SHORTINT;
  (**Identifies the function of the data passed to an operand.  Operands are
     identified by either of two means: their position in an instruction's
     operand list, or their identifier @ofield{*OOC:SSA:Instr.Opnd.class}.  The
     class describes the data that is passed to the instruction, and is
     primarily used to mark optional operands, and to structure highly variable
     operand lists.

     Operands and results of the same kind share the same class id.  See
     @omodule{*OOC:SSA:Result}.  *)

CONST
  arg* = 1;
  (**An operand without any special id.  The argument derives its meaning
     exclusively from its index in the instruction's operand list.  *)
  
  store* = Result.store;
  (**The result reads from the global @var{store}.  An instruction can have at
     most one operand marked as @oconst{store} [FIXME... Do we merge stores?].
     If it has no @oconst{store} operand, then it reads no data from the
     program state in addition to the value arguments it gets passed from the
     caller.  *)
     
  procAdr* = 3;
  (**The procedure address argument of a @oconst{*Opcode.call} instruction.
     *)

  readAdr* = 4;
  (**The address from which a @oconst{*OOC:SSA:Opcode.get} or
     @oconst{*OOC:SSA:Opcode.copy} instruction reads its data.  *)

  readDesign* = 5;
  (**A part of the symbolic representation of the designator from which a
     @oconst{*OOC:SSA:Opcode.get} or @oconst{*OOC:SSA:Opcode.copy} instruction
     reads its data.  *)

PROCEDURE GetName* (class: Class; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of an operand class.  *)
  BEGIN
    CASE class OF
    | arg: COPY ("arg", name)
    | store: COPY ("store", name)
    | procAdr: COPY ("proc-adr", name)
    | readAdr: COPY ("read-adr", name)
    | readDesign: COPY ("read-design", name)
    END;
  END GetName;
  
END OOC:SSA:Opnd.
