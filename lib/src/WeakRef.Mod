MODULE WeakRef;

(*  Implementation of parametric weak references.
    Copyright (C) 2003,2004  Stewart Greenhill

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

IMPORT RT0;

TYPE
  Type = RT0.Object;

TYPE
  WeakRef* (T : Type) = POINTER TO WeakRefDesc(T);
  WeakRefDesc (T : Type) = RECORD [NO_TRACED_POINTERS]
	(**WeakRef encapsulates a pointer to a collectable object, but does not
       prevent the object from being collected by the run-time system. *)
    ptr : T;
  END;

PROCEDURE (r : WeakRef(T)) Get* () : T;
(**Return a pointer to the object referenced by this weak reference. This will
   be the previous value of the reference (defined via @oproc{r.Set} or
   @oproc{r.INIT}), or @code{NIL} if the object has been collected. *)
BEGIN
  RETURN r.ptr;
END Get;

PROCEDURE (r : WeakRef(T)) Set* (ptr : T);
(**Set this reference to refer to @oparam{ptr}. The weak reference may be
   explicitly cleared by specifying @code{NIL} for @oparam{ptr}. While this
   has no visible effect, it may result in a slight improvement in GC
   performance. *)
BEGIN
  IF ptr = NIL THEN
    IF r.ptr # NIL THEN
      RT0.UnregisterDisappearingLink(r.ptr);
    END;
    r.ptr := NIL;
  ELSE
    r.ptr := ptr;
    RT0.RegisterDisappearingLink(r.ptr);
  END;
END Set;

PROCEDURE (r : WeakRef(T)) Equal* (r2 : WeakRef(T)) : BOOLEAN;
(**Determine of two weak references are equal. This function returns
   @code{TRUE} if the object). This is equivalent to 
   @code{r.Get() = r2.Get()}. *)
BEGIN
  RETURN r.ptr = r2.ptr;
END Equal;

PROCEDURE (r : WeakRef(T)) INIT* (ptr : T);
(**Create a weak reference to @oparam{ptr}. The reference does not prevent the
   object from being collected by the garbage collector. *)
BEGIN
  r.ptr := NIL;
  r.Set(ptr);
END INIT;

END WeakRef.
