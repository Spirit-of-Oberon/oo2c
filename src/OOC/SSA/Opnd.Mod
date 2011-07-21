(* 	$Id: Opnd.Mod,v 1.24 2002/12/11 06:24:42 mva Exp $	 *)
MODULE OOC:SSA:Opnd;
(*  Symbolic names for operand classes.
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

  writeAdr* = 6;
  (**The address to which a @oconst{*OOC:SSA:Opcode.set} or
     @oconst{*OOC:SSA:Opcode.copy} instruction writes its data.  *)

  writeDesign* = 7;
  (**A part of the symbolic representation of the designator to which a
     @oconst{*OOC:SSA:Opcode.set} or @oconst{*OOC:SSA:Opcode.copy} instruction
     writes its data.  *)

  sourceValue* = 8;
  (**Source value of a @oconst{*OOC:SSA:Opcode.set} instruction.  Must
     be a scalar type.  *)

  functionResult* = 9;
  (**The argument of this operand is a function result.  That is, it is
     defined either directly or indirectly by the expression of a @code{RETURN}
     statement.  *)

  storeEnter* = 10;
  (**Operand of @oconst{*OOC:SSA:Opcode.selectReturn} taking the initial value
     of @var{store} within the procedure.  *)
  storeExit* = 11;
  (**Operand of @oconst{*OOC:SSA:Opcode.selectReturn} taking the final value of
     @var{store} within the procedure at the place of a @code{RETURN}, or of
     @oconst{*OOC:SSA:Opcode.loopEnd} taking the final value of @var{store}
     within a loop at the place of an @code{EXIT}.

     Due to its special function as a non-local exit from within a structured
     flow of control, operands of this type are handled specially when
     converting the SSA graph into a hierarchy of regions, and when eliminating
     dead code.  A using occurence of a value in a @oconst{storeExit}
     instruction is disregarded when placing the defining instruction during
     scheduling.  Likewise, an instruction that is only used in
     @oconst{storeExit} operands is considered dead.  *)

  type* = 12;
  (**Type operand of a @oconst{*OOC:SSA:Opcode.newArray} or
     @oconst{*OOC:SSA:Opcode.copyString} instruction.  Like constants and
     declarations, this is an immutable value as far as SSA is concerned.  *)

  backwardFeed* = 13;
  (**Operand holds the value of @var{store} that is fed back to the beginning
     of a loop once the loop's end is reached.  Conceptually, this operand
     introduces a cycle in the graph representing the data flow.  To avoid
     special cases in some algorithms, it is part of the operand list of
     @oconst{*OOC:SSA:loopEnd}, @emph{not} @oconst{*OOC:SSA:loopStart}.  *)

  dimension* = 15;
  (**Dimension identifier of a @oconst{*OOC:SSA:Opcode.getLength} instruction.
     This is an integer constant.  *)

  labels* = 16;
  (**Used for a pseudo operand of a @oconst{*OOC:SSA:Opcode.select} that
     lists the labels of a @code{CASE} branch.  *)
  
  loopExternalDef* = 17;
  (**An argument added to the back-edge collect instruction of a loop refering
     to a value that is used within the loop, but defined outside the loop.
     The (global) allocator needs this information so that such value are kept
     live across the whole loop, instead of being clobbered somewhere between
     the loop start and end.  *)

  antiDependency* = 18;
  (**This class is used for operands that are inserted into the SSA instruction
     list during the course of a the data dependency analysis.  See
     @omodule{*OOC:SSA:Blocker}.  *)

  regionDependency* = 20;
  (**Used by @omodule{*OOC:SSA:Blocker} to make dependencies between regions
     and instructions, or regions and regions, explicit on the level of the
     common domination region of the two.  *)
  
  dgateBase* = 21;
  dgateRef* = 22;
  
PROCEDURE GetName* (class: Class; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of an operand class.  *)
  BEGIN
    CASE class OF
    | arg: COPY ("arg", name)
    | store: COPY ("store", name)
    | procAdr: COPY ("proc-adr", name)
    | readAdr: COPY ("read-adr", name)
    | readDesign: COPY ("read-design", name)
    | writeAdr: COPY ("write-adr", name)
    | writeDesign: COPY ("write-design", name)
    | sourceValue: COPY ("source-value", name)
    | functionResult: COPY ("function-result", name)
    | storeEnter: COPY("store-enter", name)
    | storeExit: COPY("store-exit", name)
    | type: COPY("type", name)
    | backwardFeed: COPY ("backward-feed", name)
    | dimension: COPY ("dimension", name)
    | labels: COPY ("labels", name)
    | loopExternalDef: COPY ("loop-external-def", name);
    | antiDependency: COPY ("anti-dependency", name);
    | regionDependency: COPY ("region-dependency", name);
    | dgateBase: COPY ("dgate-base", name);
    | dgateRef: COPY ("dgate-ref", name);
    END;
  END GetName;
  
END OOC:SSA:Opnd.
