(*	$Id: ArrayList.Mod,v 1.16 2004/11/14 20:02:51 mva Exp $	*)
MODULE ADT:ArrayList;
(*  Implements a resizable list of objects.
    Copyright (C) 2000, 2003, 2004  Michael van Acken

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
  SYSTEM, ADT:Storable, ADT:Comparator, Object, IO;


TYPE
  Array(E: Object.Object) = POINTER TO ARRAY OF E;
  ArrayList*(E: Object.Object) = POINTER TO ArrayListDesc(E);
  ArrayListDesc*(E: Object.Object) = RECORD
  (**Resizable-array implementation of a list.  *)
    (Storable.ObjectDesc)
    array-: Array(E);
    (**Holds the elements of the list.  The index values in
       @samp{[0..@ofield{size}-1]} refer to valid entries.  *)
    size-: LONGINT;
    (**Number of elements in the array.  This value is always less or equal to
       @samp{LEN(@ofield{array})}.  *)
  END;
  
TYPE
  IterElements*(E: Object.Object) = POINTER TO IterElementsDesc(E);
  IterElementsDesc(E: Object.Object) = RECORD
    list: ArrayList(E);
    pos: LONGINT;
  END;


PROCEDURE (l: ArrayList(E)) CreateArray (size: LONGINT; old: ArrayList(E));
  VAR
    new: Array(E);
    i: LONGINT;
  BEGIN
    IF (size < 2) THEN
      (* if the size is zero, the mechanism to extend an array by doubling
         the size fails miserably :-( *)
      size := 2
    END;
    
    NEW (new, size);
    IF (old # NIL) THEN
      FOR i := 0 TO old. size-1 DO
        new[i] := old. array[i];
        old. array[i] := NIL             (* be nice to gc *)
      END
    END;
    l.array := new;
  END CreateArray;


PROCEDURE (l: ArrayList(E)) INIT*(initialSize: LONGINT);
(**Initializes a list with the stated initial size.  *)
  BEGIN
    l. CreateArray (initialSize, NIL);
    l. size := 0
  END INIT;

PROCEDURE New* (initialSize: LONGINT): ArrayList;
(**Creates a new list with the stated initial size.

   @precond
   @samp{@oparam{initialSize} >= 0}
   @end precond  *)
  BEGIN
    RETURN NEW(ArrayList, initialSize);
  END New;

PROCEDURE (l: ArrayList(E)) Destroy*;
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO l. size-1 DO
      l. array[i] := NIL
    END;
    l. array := NIL
  END Destroy;

PROCEDURE (l: ArrayList(E)) Copy*(): ArrayList(E);
(**Returns a shallow copy of @oparam{l}.  The elements themselves are not
   copied.  *)
  VAR
    new: ArrayList(E);
    i: LONGINT;
  BEGIN
    new := NEW(ArrayList(E), l. size);
    FOR i := 0 TO l. size-1 DO
      new. array[i] := l. array[i]
    END;
    new. size := l. size;
    RETURN new
  END Copy;



PROCEDURE (l: ArrayList(E)) EnsureCapacity* (size: LONGINT);
(**Increases the capacity of @oparam{l}, if necessary, to ensure that it can
   hold at least the number of elements specified by the minimum capacity
   argument @oparam{size}.
   
   @precond
   @samp{@oparam{size} >= 0}
   @end precond  *)
  BEGIN
    IF (LEN (l. array^) < size) THEN
      l. CreateArray (size, l)
    END
  END EnsureCapacity;

PROCEDURE (l: ArrayList(E)) Clear*;
(**Removes all of the elements from this list.  The list will be empty after
   this call returns.  *)
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO l. size-1 DO
      l. array[i] := NIL
    END;
    l. size := 0
  END Clear;

PROCEDURE (l: ArrayList(E)) Append* (obj: E);
(**Appends the specified element @oparam{obj} to the end of this list.  *)
  BEGIN
    IF (l. size = LEN (l. array^)) THEN
      l. CreateArray (l. size*2, l)
    END;
    l. array[l. size] := obj;
    INC (l. size)
  END Append;

PROCEDURE (l: ArrayList(E)) Insert* (index: LONGINT; obj: E);
(**Inserts the specified element @oparam{obj} at the specified position
   @oparam{index} in this list.  Shifts the element currently at that position
   (if any) and any subsequent elements to the right (adds one to their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} <= @oproc{l.Size}()}
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT (index <= l. size);
    IF (l. size = LEN (l. array^)) THEN
      l. CreateArray (l. size*2, l)
    END;
    FOR i := l. size-1 TO index BY -1 DO
      l. array[i+1] := l. array[i]
    END;
    l. array[index] := obj;
    INC (l. size)
  END Insert;

PROCEDURE (l: ArrayList(E)) Get* (index: LONGINT): E;
(**Returns the element at the specified position @oparam{index} in this list.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  BEGIN
    ASSERT (index < l. size);
    RETURN l. array[index]
  END Get;

PROCEDURE (l: ArrayList(E)) Set* (index: LONGINT; obj: E);
(**Replaces the element at the specified position @oparam{index} in this list
   with the specified element @oparam{obj}.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  BEGIN
    ASSERT (index < l. size);
    l. array[index] := obj
  END Set;

PROCEDURE (l: ArrayList(E)) RemoveRange* (fromIndex, toIndex: LONGINT);
(**Removes from this List all of the elements whose index is between
   @oparam{fromIndex}, inclusive and @oparam{toIndex}, exclusive.  Shifts any
   succeeding elements to the left (reduces their index).  This call shortens
   the list by @samp{toIndex - fromIndex} elements.  (If @samp{@oparam{toIndex}
   = @oparam{fromIndex}}, this operation has no effect.)

   @precond
   @itemize
   @item
   @samp{0 <= @oparam{fromIndex}} and @samp{@oparam{fromIndex} <
   @oproc{l.Size}()}
   @item
   @samp{0 <= @oparam{toIndex}} and @samp{@oparam{toIndex} < @oproc{l.Size}()}
   @item 
   @samp{@oparam{toIndex}-@oparam{fromIndex} >= 0}
   @end itemize
   @end precond  *)
  VAR
    i, delta: LONGINT;
  BEGIN
    delta := toIndex-fromIndex;
    FOR i := toIndex TO l. size-1 DO
      l. array[i-delta] := l. array[i]
    END;
    DEC (l. size, delta)
  END RemoveRange;

PROCEDURE (l: ArrayList(E)) Remove* (index: LONGINT);
(**Removes the element at the specified position @oparam{index} in this list.
   Shifts any subsequent elements to the left (subtracts one from their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  BEGIN
    l. RemoveRange (index, index+1)
  END Remove;

PROCEDURE (l: ArrayList(E)) TrimToSize*;
(**Trims the capacity of @oparam{l} to be the list's current size.  An
   application can use this operation to minimize the storage of an
   @otype{ArrayList} instance.  *)
  BEGIN
    IF (l. size # LEN (l. array^)) THEN
      l. CreateArray (l. size, l)
    END
  END TrimToSize;


PROCEDURE (l: ArrayList(E)) Size* (): LONGINT;
(**Returns the number of elements in this list.  *)
  BEGIN
    RETURN l. size
  END Size;

PROCEDURE (l: ArrayList(E)) Contains* (obj: E): BOOLEAN;
(**Returns @code{TRUE} if this list contains the specified element.  *)
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO l. size-1 DO
      IF obj. Equals (l. array[i]) THEN
        RETURN TRUE
      END
    END;
    RETURN FALSE
  END Contains;

PROCEDURE (l: ArrayList(E)) IndexOf* (obj: E): LONGINT;
(**Searches for the first occurence of the given argument, testing for equality
   using the @oproc{Object.Object.Equals} method.  Returns @code{-1} if the
   object is not found.  *)
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO l. size-1 DO
      IF obj. Equals (l. array[i]) THEN
        RETURN i
      END
    END;
    RETURN -1
  END IndexOf;

PROCEDURE (l: ArrayList(E)) LastIndexOf* (obj: E): LONGINT;
(**Searches for the last occurence of the given argument, testing for equality
   using the @oproc{Object.Object.Equals} method.  Returns @code{-1} if the
   object is not found.  *)
  VAR
    i: LONGINT;
  BEGIN
    FOR i := l. size-1 TO 0 BY -1 DO
      IF obj. Equals (l. array[i]) THEN
        RETURN i
      END
    END;
    RETURN -1
  END LastIndexOf;

PROCEDURE (l: ArrayList(E)) IsEmpty* (): BOOLEAN;
(**Tests if this list has no elements.  *)
  BEGIN
    RETURN (l. size = 0)
  END IsEmpty;



PROCEDURE (l: ArrayList(E)) Equals* (obj: Object.Object): BOOLEAN;
  BEGIN
<*WITH Assertions:=TRUE DO*>
    ASSERT (FALSE);
<*END*>
  END Equals;

PROCEDURE (l: ArrayList(E)) HashCode* (): Object.Hash;
  BEGIN
<*WITH Assertions:=TRUE DO*>
    ASSERT (FALSE);
<*END*>
  END HashCode;

PROCEDURE (l: ArrayList(E)) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    w. WriteNum (l. size);
    FOR i := 0 TO l. size-1 DO
      w. WriteObject (l. array[i]);
    END
  END Store;

PROCEDURE (l: ArrayList(E)) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    i, size: LONGINT;
    obj: Object.Object;
  BEGIN
    r. ReadNum (size);
    l.INIT(size);
    FOR i := 0 TO size-1 DO
      r. ReadObject (obj);
      l. array[i] := SYSTEM.VAL(E, obj);
    END;
    l. size := size
  END Load;

PROCEDURE (a: ArrayList(E)) Sort*(fromIndex, toIndex: LONGINT;
                                  cmp: Comparator.Comparator);
(**Sort array interval @samp{@ofield{a.array}[@oparam{fromIndex},
   @oparam{toIndex}[} according to the comparator function @oparam{cmp}.  *)
   
  PROCEDURE Quicksort (l, r: LONGINT);
    VAR
      t, v: E;
      i, j, m: LONGINT;
    BEGIN
      IF (r > l) THEN
        m := (r+l) DIV 2;
        IF (cmp.Compare(a.array[l], a.array[r]) > 0) THEN
          t := a.array[l]; a.array[l] := a.array[r]; a.array[r] := t
        END;
        IF (cmp.Compare(a.array[l], a.array[m]) > 0) THEN
          t := a.array[l]; a.array[l] := a.array[m]; a.array[m] := t
        END;
        IF (cmp.Compare(a.array[r], a.array[m]) > 0) THEN
          t := a.array[r]; a.array[r] := a.array[m]; a.array[m] := t
        END;
        
        v := a.array[r]; i := l-1; j := r;
        LOOP
          REPEAT
            INC (i);
          UNTIL (cmp.Compare(a.array[i], v) >= 0);
          REPEAT
            DEC (j);
          UNTIL (j < 0) OR (cmp.Compare(a.array[j], v) <= 0);
          IF (i >= j) THEN
            EXIT;
          END;
          t := a.array[i]; a.array[i] := a.array[j]; a.array[j] := t
        END;
        t := a.array[i]; a.array[i] := a.array[r]; a.array[r] := t;
        Quicksort(l, i-1);
        Quicksort(i+1, r);
      END
    END Quicksort;

  BEGIN
    Quicksort(fromIndex, toIndex-1);
  END Sort;

PROCEDURE (l: ArrayList(E)) Elements*(): Object.ObjectArrayPtr(E);
  VAR
    a: Object.ObjectArrayPtr(E);
    i: LONGINT;
  BEGIN
    NEW(a, l.size);
    FOR i := 0 TO l.size-1 DO
      a[i] := l.array[i];
    END;
    RETURN a;
  END Elements;


PROCEDURE (iter: IterElements(E)) INIT*(list: ArrayList(E));
  BEGIN
    iter.list := list;
    iter.pos := 0;
  END INIT;
  
PROCEDURE (l: ArrayList(E)) IterElements*(): IterElements(E);
(**Returns an iterator that traverses the elements of @oparam{l} sequentially.
   It produces the elements at indices @code{0}, @code{1}, @code{2}, and so on,
   until index @ofield{l.size} is reached.

   Behaviour of the iterator is undefined if the array is changed while the
   iterator is traversing it.  *)
  BEGIN
    RETURN NEW(IterElements(E), l);
  END IterElements;

PROCEDURE (iter: IterElements(E)) Next*(VAR elem: E): BOOLEAN;
  BEGIN
    IF (iter.pos >= iter.list.size) THEN
      RETURN FALSE;
    ELSE
      elem := iter.list.array[iter.pos];
      INC(iter.pos);
      RETURN TRUE;
    END;
  END Next;
  
END ADT:ArrayList.
