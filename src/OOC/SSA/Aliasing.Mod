(* 	$Id: Aliasing.Mod,v 1.10 2004/05/09 16:10:26 mva Exp $	 *)
MODULE OOC:SSA:Aliasing;
(*  Calculates aliasing between instructions.
    Copyright (C) 2002,2003  Michael van Acken

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
  Sym := OOC:SymbolTable, TR := OOC:SymbolTable:TypeRules, OOC:SSA;
  
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
  (**One of @oconst{noAliasing}, @oconst{completelyCovered},
     @oconst{partiallyCovered}, or @oconst{mayAlias}.  *)

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
(**Determines the aliasing status of the designator @oparam{instr} with
   respect to the designator @oparam{reference}.  A designator is described by
   a list of operands of class @oconst{*OOC:SSA:Opnd.readDesign} or
   @oconst{*OOC:SSA:Opnd.writeDesign}, as they appear within instructions like
   @oconst{*OOC:SSA:Opcode.get} or @oconst{*OOC:SSA:Opcode.set}.

   Note: The current state of this procedure reflects the progress of the
   SSA back-end, an only deals with a subset of all possible designators.
   *)
  VAR
    typeInstr, typeRef: Sym.Type;
    
  PROCEDURE NextPart (opnd: SSA.Opnd): SSA.Opnd;
    BEGIN
      IF (opnd. arg IS SSA.TypeRef) THEN
        opnd := opnd. nextOpnd;          (* move over pointer type *)
      END;
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

  PROCEDURE IsVarParam (opnd: SSA.Opnd): BOOLEAN;
  (* TRUE iff `opnd' refers to a VAR parameter *)
    BEGIN
      RETURN
          (opnd. arg IS SSA.DeclRef) &
          (opnd. arg(SSA.DeclRef). decl IS Sym.VarDecl) &
          opnd. arg(SSA.DeclRef). decl(Sym.VarDecl). isVarParam
    END IsVarParam;

  PROCEDURE IsHeapObject (opnd: SSA.Opnd): BOOLEAN;
  (* TRUE iff `opnd' refers to a heap object.  *)
    BEGIN
      RETURN (opnd. arg IS SSA.TypeRef)
    END IsHeapObject;

  PROCEDURE CompatiblePointers (a, b: Sym.Type): BOOLEAN;
    BEGIN
      IF TR.SameType(a, b) THEN
        RETURN TRUE;
      ELSE
        a := a.Bound(); b := b.Bound();
        IF TR.IsPointer(a) & TR.IsPointer(b) THEN
          RETURN TR.IsExtensionOf (a, b) OR TR.IsExtensionOf (b, a);
        ELSE
          RETURN FALSE;
        END;
      END;
    END CompatiblePointers;
  
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
        IF (selReference = NIL) THEN
          (* reference designator also ends here *)
          RETURN prefixClass
        ELSE
          (* reference designator has further selectors, which means it
             covers less ground than our designator *)
          RETURN PartiallyCovered (prefixClass)
        END;

      ELSIF (selReference = NIL) THEN
        (* the reference designator ends before our designator, which means
           our designator works on something that is completely included in
           the other designator *)
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

  PROCEDURE NotHigherLevel (varParam, variable: Sym.Declaration): BOOLEAN;
  (* Returns TRUE if `varParam' is declared in the same procedure as
     `variable', or in a procedure that encloses that of `variable'.  *)
    VAR
      pVarParam, pVariable: Sym.Item;
    BEGIN
      pVariable := variable. Procedure();
      IF (pVariable = NIL) THEN
        (* variable is declared globally; this means it is declared by
           definition on a higher level than any parameter *)
        RETURN FALSE
      ELSE
        pVarParam := varParam. Procedure();
        REPEAT
          pVarParam := pVarParam. parent
        UNTIL (pVarParam = NIL) OR (pVarParam = pVariable);
        RETURN (pVarParam = NIL)
      END;
    END NotHigherLevel;
  
  BEGIN
    IF IsVariable (instr) & IsVariable (reference) THEN
      (* both designators begin with a variable name (this excludes variable
         parameters, but includes value parameters); this is probably one
         of the most common cases, and a very simple one *)
      IF (instr. arg(SSA.DeclRef). decl =
          reference. arg(SSA.DeclRef). decl) THEN
        (* both designators begin with the same variable: inspect selectors *)
        RETURN CheckSelectors (NextPart (instr), NextPart (reference),
                               completelyCovered)
      ELSE
        (* the designators begin with different variable names, and neither of
           the variables is a variable parameter: the designators cannot
           possibly access the same memory *)
        RETURN noAliasing
      END;

    ELSIF IsHeapObject (instr) & IsHeapObject (reference) THEN
      (* both designators refer to an object on the heap *)
      IF CompatiblePointers (instr. arg(SSA.TypeRef). type,
                             reference. arg(SSA.TypeRef). type) THEN
        IF (instr. nextOpnd. arg = reference. nextOpnd. arg) THEN
          (* both designators begin with the same pointer: inspect selectors *)
          RETURN CheckSelectors (NextPart (instr), NextPart (reference),
                                 completelyCovered)
        ELSE
          (* both designators may or may not begin with the same pointer:
             inspect selectors *)
          RETURN CheckSelectors (NextPart (instr), NextPart (reference),
                                 mayAlias)
        END;
      ELSE
        (* the designators begin with different variable names, and neither of
           the variables is a variable parameter: the designators cannot
           possibly access the same memory *)
        RETURN noAliasing
      END;

    ELSIF IsVarParam (instr) THEN
      IF IsVarParam (reference) &
         (instr.arg(SSA.DeclRef).decl = reference.arg(SSA.DeclRef).decl) THEN
        (* both designators begin with one and the same variable parameter:
           inspect selectors *)
        RETURN CheckSelectors (NextPart (instr), NextPart (reference),
                               completelyCovered);
      ELSIF IsVariable (reference) &
         NotHigherLevel (instr. arg(SSA.DeclRef). decl,
                         reference. arg(SSA.DeclRef). decl) THEN
        (* the variable parameter is declared on the same, or on a lower level
           than the variable: there is no way that it may refer to the
           variable *)
        RETURN noAliasing;
      ELSE
        (* for all other cases: inspect the types of the designators and
           try to find out if the variable parameter can point anywhere into
           the other variable; because of the strict type rules of Oberon-2,
           a static type analysis can rule out many potential aliases *)
        typeInstr := instr. arg(SSA.DeclRef). decl(Sym.VarDecl). type;
        IF (reference. arg IS SSA.DeclRef) THEN
          typeRef := reference. arg(SSA.DeclRef). decl(Sym.VarDecl). type;
        ELSIF (reference. arg IS SSA.TypeRef) THEN
          typeRef := reference. arg(SSA.TypeRef). type;
        ELSE
          ASSERT (FALSE);
        END;

        IF TR.IsComponentOf (typeInstr, typeRef, TRUE) OR
           (IsVarParam (reference) &
            TR.IsComponentOf (typeRef, typeInstr, TRUE)) THEN
          RETURN mayAlias
        ELSE
          RETURN noAliasing
        END;
      END;
      
    ELSIF IsVarParam (reference) THEN
      (* if one of the inspected designators is a variable parameter, then the
         result is other `noAliasing' or `mayAlias', because the other classes
         make no sense in the context of a var param that may point anywhere;
         this means that this function is symmetric in the presence of variable
         parameters, and we can save half the work by normalizing the arguments
         so that `instr' is the variable parameter *)
      RETURN DesignatorAlias (reference, instr);

    ELSIF IsHeapObject (instr) THEN
      (* ~IsHeapObject (reference) & ~IsVarParam (reference); in other words,
         reference must be a variable of the procedure or module *)
      RETURN noAliasing;

    ELSIF IsHeapObject (reference) THEN
      (* ~IsHeapObject (instr) & ~IsVarParam (instr); in other words,
         instr must be a variable of the procedure or module *)
      RETURN noAliasing;
    END;
    
    (* default: assume the worst *)
    RETURN mayAlias
  END DesignatorAlias;

END OOC:SSA:Aliasing.
