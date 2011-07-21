(* 	$Id: Result.Mod,v 1.7 2002/12/11 06:24:42 mva Exp $	 *)
MODULE OOC:SSA:Result;
(*  Symbolic names for result classes.
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

TYPE
  Class* = SHORTINT;
  (**Identifies the function of the data produced by a result.  Results are
     identified by either of two means: their position in an instruction's
     operand list, or their class @ofield{*OOC:SSA:Instr.Result.class}.  The
     class describes the data that is passed from the instruction, and is
     primarily used to mark optional results, and to structure highly variable
     result lists.

     Operands and results of the same kind share the same class id.  See
     @omodule{*OOC:SSA:Opnd}.  *)

CONST
  void* = -2;
  (**A result that does not produce any value.  Because of the nature of a SSA
     representation, such a result can only appear in the @code{exit}
     instruction of a procedure block.  *)
  
  primary* = -1;
  (**The primary result of an instruction.  The result marked like this
     is the instruction itself, and has the index @code{0}.  *)
  
  result* = 0;
  (**A result without any special class.  The result derives its meaning
     exclusively from its index in the instruction's result list.  *)

  store* = 2;
  (**The result produces a new value for the global @var{store}.  The
     @dfn{store} is an abstraction of the program state, and of all input and
     output of the program.  @emph{All} changes to the program state that are
     not private to the current procedure are written into @var{store}, and
     produce a new value for it.  An instruction can have at most one result
     marked as @oconst{store}.  If it produces a new @var{store}, then it must
     have a corresponding operand of the same type (the exception being a
     procedure block's @code{enter} instruction; also see
     @oproc{*OOC:SSA:Opnd.store}).  If the instruction has no @oconst{store}
     result, then it has no side-effects.  This means it only returns a
     function result, but does not modify any nonlocal variables, nor does it
     initiate any I/O, nor can it throw an exception.  *)

  selectValue* = 14;
  (**The result represents a value selected from the
     @oconst{*OOC:SSA:Opcode.collect} operands that appear in the instruction's
     argument list.  Also see @oconst{*OOC:SSA:Opcode.select}.  *)

  exception* = 19;
  (**Marks the possible branch of control flow from the instruction to a
     @oconst{*OOC:SSA:Opcode.selectException} instruction.  *)

  dgatePlaceholder* = 23;
  
PROCEDURE GetName* (class: Class; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of a result class.  *)
  BEGIN
    CASE class OF
    | result: COPY ("result", name)
    | void: COPY ("void", name)
    | primary: COPY ("primary", name)
    | store: COPY ("store", name)
    | selectValue: COPY ("select-value", name)
    | exception: COPY ("exception", name)
    | dgatePlaceholder: COPY ("dgate-placeholder", name)
    END;
  END GetName;
  
END OOC:SSA:Result.
