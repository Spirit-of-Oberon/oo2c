(* 	$Id$	 *)
MODULE OOC:SSA:Aliasing;
(*  Calculates aliasing between instructions.
    Copyright (C) 2002  Michael van Acken

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
  Sym := OOC:SymbolTable, OOC:SSA;
  
(**

   If instructions work on memory areas, then the areas from which they read
   data, or to which they write data, may intersect.  If this happens, then the
   instructions may no longer be independent of each other.  This module
   provides functions to determine if and how a given variable access aliases
   with that of another instruction.

   Aliasing statements are a function of the memory areas touched by
   instructions.  If the instructions work on distinct memory locations, then
   they do not alias.  On the other hand, if they access even a single common
   byte, or if there is a chance that this may happen, then they do alias.

   Read and write access to memory is distinguished.  For example, if two
   reading instructions alias, they can still be scheduled in either order.
   For two aliasing write instructions, order is significant and must not be
   changed.

   When comparing the set of memory locations accessed by two instructions that
   read or write variables, different situations can arise:

   @table @asis
   @item Empty Intersection
   In this case, both instructions are independent of each other, because they
   access distinct subsets of the program's state.

   @item Equal Sets
   The instructions work on the same set of data.  This allows various
   improvements, for example eliminating the second read instruction because it
   delivers the same result as the first.

   @item Non-empty Intersection
   If the sets of memory locations are not equal, but still share common
   locations, then the instructions are not independent.  Interpretation of
   such a situation depends on the context.

   @item Indefinite Intersection
   Most of the time, static program analysis cannot determine the intersection
   set during compile time.  For one and the same instruction, the aliasing
   status may differ with each evaluation during run-time.  In this case, no
   program transformation can be applied that depends on knowledge about its
   aliasing status.
   @end table

   The aliasing relationship between two instructions is commutative for empty
   intersections and for equal sets of memory locations, but not for indefinite
   aliasing or non-empty intersections.  *)

TYPE
  Id* = SHORTINT;
  (**One of @oconst{noAliasing}, @oconst{sameVariable},
     @oconst{partialAliasing}, or @oconst{mayAlias}.  *)

CONST
  noAliasing* = 0;
  (**The two designators access different memory areas.  *)
  completelyCovered* = 1;
  (**The designator accesses a memory area that is completely covered by the
     other designator.  For example, if the designator is a read, and the other
     one a write, then the result of the read operation is completely defined
     by the written data.  *)
  partiallyCovered* = 2;
  (**The designator accesses a memory area that is partially covered by the
     other one.  For example, if the designator is a read, and the other one a
     write, then the result of the read operation is only partially defined by
     the written data, and partially by the old data in memory.  *)
  mayAlias* = 3;
  (**The designators may access the same memory area.  Any of the the variants
     @oconst{noAliasing}, @oconst{completelyCovered}, or
     @oconst{partiallyCovered} may be true during run-time.  *)

  
PROCEDURE DesignatorAlias* (instr, reference: SSA.Opnd): Id;
(**Determines the aliasing status of the designator @oparam{design} with
   respect to the designator @oparam{reference}.  A designator is described by
   a list of operands of class @oconst{Opnd.readDesign} or
   @oconst{Opnd.writeDesign}, as they appear within instructions like
   @oconst{Opcode.get} or @oconst{Opcode.set}.

   Note: The current state of this procedure reflects the progress of the
   SSA back-end, an only deals with a subset of all possible designators.
   *)

  PROCEDURE NextPart (opnd: SSA.Opnd): SSA.Opnd;
    BEGIN
      IF (opnd. nextOpnd = NIL) OR (opnd. nextOpnd. class # opnd. class) THEN
        RETURN NIL
      ELSE
        RETURN opnd. nextOpnd
      END;
    END NextPart;
  
  PROCEDURE IsVariable (opnd: SSA.Opnd): BOOLEAN;
  (* TRUE iff `opnd' refers to a variable that is not a variable parameter *)
    BEGIN
      RETURN
          (opnd. arg IS SSA.DeclRef) &
          (opnd. arg(SSA.DeclRef). decl IS Sym.VarDecl) &
          ~opnd. arg(SSA.DeclRef). decl(Sym.VarDecl). isVarParam
    END IsVariable;

  PROCEDURE CheckSelectors (selInstr, selReference: SSA.Opnd;
                            prefixClass: Id): Id;
  (* pre: the classification of the prefix of the designators `selInstr' and
     `selReference' is `prefixClass'.  *)

    PROCEDURE PartiallyCovered (id: Id): Id;
      BEGIN
        IF (id = mayAlias) THEN
          RETURN mayAlias
        ELSE
          ASSERT (id = completelyCovered);
          RETURN partiallyCovered
        END;
      END PartiallyCovered;
    
    BEGIN
      ASSERT ((prefixClass = completelyCovered) OR
              (prefixClass = mayAlias));
      IF (selInstr = NIL) THEN
        (* no further selectors for our designator *)
        ASSERT (selReference = NIL);
        ASSERT (selInstr = NIL);
        
        IF (selReference = NIL) THEN
          (* reference designator also ends here *)
          RETURN prefixClass
        ELSE
          (* reference designator has further selectors, which means it
             covers less ground than our designator *)
          RETURN PartiallyCovered (prefixClass)
        END;

      ELSIF (selReference = NIL) THEN
        (* the reference designator ends before our designator *)
        RETURN prefixClass;
        
      ELSE  (* everything else has to be an array index *)
        IF (selInstr. arg = selReference. arg) THEN
          (* same index *)
          RETURN CheckSelectors (NextPart (selInstr), NextPart (selReference),
                                 prefixClass);
        ELSE
          (* possibly different indices *)
          RETURN CheckSelectors (NextPart (selInstr), NextPart (selReference),
                                 mayAlias);
        END;
      END;
    END CheckSelectors;
  
  BEGIN
    IF IsVariable (instr) & IsVariable (reference) THEN
      IF (instr. arg(SSA.DeclRef). decl =
          reference. arg(SSA.DeclRef). decl) THEN
        RETURN CheckSelectors (NextPart (instr), NextPart (reference),
                               completelyCovered)
      ELSE
        (* the designators begin with different variable names, and neither of
           the variables is a variable parameter: the designators cannot
           possibly access the same memory *)
        RETURN noAliasing
      END;
    END;
    
    (* default: assume the worst *)
    RETURN mayAlias
  END DesignatorAlias;

BEGIN
END OOC:SSA:Aliasing.
