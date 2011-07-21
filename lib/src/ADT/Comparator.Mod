(*	$Id: Comparator.Mod,v 1.4 2003/07/21 19:22:41 mva Exp $	*)
MODULE ADT:Comparator [OOC_EXTENSIONS];
(*  Abstract base type for comparison function for objects.
    Copyright (C) 2001, 2003  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)


IMPORT
  Object;

(**Note: The class @otype{Comparator} is modeled after from Java class
   @samp{java.util.Comparator}, from which the documentation is also derived.  *)

TYPE
  Comparator* = POINTER TO ComparatorDesc;
  ComparatorDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
  END;

TYPE
  String* = POINTER TO StringDesc;
  StringDesc = RECORD
    (ComparatorDesc) 
  END;

PROCEDURE (cmp: Comparator) [ABSTRACT] Compare* (o1, o2: Object.Object): LONGINT;
(**Compares its two arguments for order.  Returns a negative integer, zero, or
   a positive integer as the first argument is less than, equal to, or greater
   than the second.

   The implementor must ensure that @samp{sgn(Compare(x, y)) = -sgn(Compare(y,
   x))} for all @samp{x} and @samp{y}. (This implies that @samp{Compare(x, y)}
   must throw an exception if and only if @samp{Compare(y, x)} throws an
   exception.)

   The implementor must also ensure that the relation is transitive:
   @samp{((Compare(x, y)>0) & (Compare(y, z)>0))} implies @samp{Compare(x,
   z)>0}.

   Finally, the implementer must ensure that @samp{Compare(x, y)=0} implies
   that @samp{sgn(Compare(x, z))==sgn(Compare(y, z))} for all @samp{z}.

   It is generally the case, but not strictly required that @samp{(Compare(x,
   y)==0) == (x.Equals(y))}.  Generally speaking, any comparator that violates
   this condition should clearly indicate this fact.  The recommended language
   is "Note: this comparator imposes orderings that are inconsistent with
   @samp{Equals()}."  *)
  END Compare;

PROCEDURE (cmp: String) Compare* (o1, o2: Object.Object): LONGINT;
  BEGIN
    RETURN o1(Object.String).Compare(o2(Object.String));
  END Compare;

END ADT:Comparator.
