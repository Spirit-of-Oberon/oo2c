
MODULE ADT:LinkedList;
(*  Implements a list of objects using a linked-list.

    Copyright (C) 2002  Stewart Greenhill

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
  ADT:Storable, Object, IO, SYSTEM;

TYPE
  Entry(E : Object.Object) = POINTER TO EntryDesc(E);
  EntryDesc(E : Object.Object) = RECORD (Object.ObjectDesc)
    next, previous : Entry(E);
    element : E;
  END;

  LinkedList*(E : Object.Object) = POINTER TO LinkedListDesc(E);
  LinkedListDesc*(E : Object.Object) = RECORD (Storable.ObjectDesc)
  (**Linked-list implementation of a list. Objects may be efficiently added to
     or removed from the start or end of the list, making it useful for
     implementing queues. *)

    elements : Entry(E);
    (**Holds the elements of the list. The index values in
       @samp{[0..@ofield{size}-1]} refer to valid entries.  *)
    size-: LONGINT;
    (**Number of elements in the list. *)
  END;

  Iterator*(E : Object.Object) = POINTER TO IteratorDesc(E);
  IteratorDesc(E : Object.Object) = RECORD
  (**Allow efficient traversal and modification of a list. *)
    list : LinkedList(E);
    lastReturned, next : Entry(E);
    nextIndex : LONGINT;
  END;

PROCEDURE (l : LinkedList(E)) NewEntry (element : E; next, previous : Entry(E)) : Entry(E);
VAR e : Entry(E);
BEGIN
  NEW(e);
  e.previous := previous;
  e.next := next;
  e.element := element;
  RETURN e;
END NewEntry;

PROCEDURE (l : LinkedList(E)) INIT*;
(**Initializes an emtpy list *)
VAR
  e : Entry(E);
BEGIN
  e := l.NewEntry(NIL, NIL, NIL); e.next := e; e.previous := e; 
  l.elements := e;
  l.size := 0
END INIT;

PROCEDURE New* (): LinkedList;
(**Creates a new list *)
BEGIN
  RETURN NEW(LinkedList);
END New;

PROCEDURE (l: LinkedList(E)) Destroy*;
BEGIN
  l.elements := NIL;
END Destroy;

PROCEDURE (l : LinkedList(E)) GetFirst* () : E;
(**Returns the first element in this list *)
BEGIN
  ASSERT(l.size # 0);
  RETURN l.elements.next.element;
END GetFirst;

PROCEDURE (l : LinkedList(E)) GetLast* () : E;
(**Returns the last element in this list *)
BEGIN
  ASSERT(l.size # 0);
  RETURN l.elements.previous.element;
END GetLast;

PROCEDURE (l : LinkedList(E)) RemoveEntry(e : Entry(E));
BEGIN
  ASSERT(e # l.elements);
  ASSERT(l.size > 0);
  e.previous.next := e.next;
  e.next.previous := e.previous;
  DEC(l.size);
END RemoveEntry;

PROCEDURE (l : LinkedList(E)) FindEntry(index : LONGINT) : Entry(E);
VAR
  e : Entry(E);
BEGIN
  ASSERT((index >= 0) & (index < l.size));

  e := l.elements;
  IF index < l.size DIV 2 THEN
    WHILE index >= 0 DO e := e.next; DEC(index); END;
  ELSE
    index := l.size - index;
    WHILE index > 0 DO e := e.previous; DEC(index); END;
  END;
  RETURN e;
END FindEntry;

PROCEDURE (l : LinkedList(E)) RemoveFirst* () : E;
(**Removes the first element in this list. 
   Shifts any subsequent elements to the left (subtracts one from their
   indices). *)
VAR result : E;
BEGIN
  result := l.elements.next.element;
  l.RemoveEntry(l.elements.next);
  RETURN result;
END RemoveFirst;

PROCEDURE (l : LinkedList(E)) RemoveLast* () : E;
(**Removes the last element in this list. *)
VAR result : E;
BEGIN
  result := l.elements.previous.element;
  l.RemoveEntry(l.elements.previous);
  RETURN result;
END RemoveLast;

PROCEDURE (l: LinkedList(E)) Remove* (index: LONGINT) : E;
(**Removes the element at the specified position @oparam{index} in this list.
   Shifts any subsequent elements to the left (subtracts one from their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
VAR
  e : Entry(E);
BEGIN
  e := l.FindEntry(index);
  l.RemoveEntry(e);
  RETURN e.element;
END Remove;

PROCEDURE (l: LinkedList(E)) RemoveRange* (fromIndex, toIndex: LONGINT);
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
  fromEntry, toEntry : Entry(E);
  delta : LONGINT;
BEGIN
  delta := toIndex - fromIndex;
  ASSERT(delta >= 0);
  IF delta = 0 THEN RETURN END;

  fromEntry := l.FindEntry(fromIndex);
  toEntry := l.FindEntry(toIndex-1); 

  fromEntry.previous.next := toEntry.next;
  toEntry.next.previous := fromEntry.previous;
  DEC(l.size, delta);
END RemoveRange;

PROCEDURE (l : LinkedList(E)) AddBefore (element : E; e : Entry(E));
VAR new : Entry(E);
BEGIN
  new := l.NewEntry(element, e, e.previous);
  new.previous.next := new;
  new.next.previous := new;
  INC(l.size);
END AddBefore;

PROCEDURE (l : LinkedList(E)) Prepend* (obj : E);
(**Appends the specified element @oparam{obj} to the beginning of this list.  *)
BEGIN
  l.AddBefore(obj, l.elements.next);
END Prepend;

PROCEDURE (l: LinkedList(E)) Append* (obj: E);
(**Appends the specified element @oparam{obj} to the end of this list.  *)
BEGIN
  l.AddBefore(obj, l.elements);
END Append;

PROCEDURE (l: LinkedList(E)) Copy* (): LinkedList(E);
(**Returns a shallow copy of @oparam{l}.  The elements themselves are not
   copied.  *)
VAR
  new: LinkedList(E);
  e : Entry(E);
BEGIN
  new := NEW(LinkedList(E));
  e := l.elements.next;
  WHILE e # l.elements DO
    new.Append(e.element);
    e := e.next;
  END;
  RETURN new
END Copy;

PROCEDURE (l: LinkedList(E)) Clear*;
(**Removes all of the elements from this list.  The list will be empty after
   this call returns.  *)
BEGIN
  l.INIT;
END Clear;

PROCEDURE (l: LinkedList(E)) Insert* (index: LONGINT; obj: E);
(**Inserts the specified element @oparam{obj} at the specified position
   @oparam{index} in this list.  Shifts the element currently at that position
   (if any) and any subsequent elements to the right (adds one to their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} <= @oproc{l.Size}()}
   @end precond  *)
BEGIN
  ASSERT((index >= 0) & (index <= l.size));
  IF index = l.size THEN
    l.AddBefore(obj, l.elements);
  ELSE
    l.AddBefore(obj, l.FindEntry(index));
  END;
END Insert;

PROCEDURE (l: LinkedList(E)) Get* (index: LONGINT): E;
(**Returns the element at the specified position @oparam{index} in this list.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
VAR
  e : Entry(E);
BEGIN
  e := l.FindEntry(index);
  RETURN e.element;
END Get;

PROCEDURE (l: LinkedList(E)) Set* (index: LONGINT; obj: E);
(**Replaces the element at the specified position @oparam{index} in this list
   with the specified element @oparam{obj}.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
VAR
  e : Entry(E);
BEGIN
  e := l.FindEntry(index);
  e.element := obj;
END Set;

PROCEDURE (l: LinkedList(E)) Size* (): LONGINT;
(**Returns the number of elements in this list.  *)
BEGIN
  RETURN l. size
END Size;

PROCEDURE (l: LinkedList(E)) Contains* (obj: E): BOOLEAN;
(**Returns @code{TRUE} if this list contains the specified element.  *)
VAR
  e : Entry(E);
BEGIN
  e := l.elements.next;
  WHILE e # l.elements DO
    IF obj.Equals(e.element) THEN
      RETURN TRUE
    END;
    e := e.next;
  END;
  RETURN FALSE
END Contains;

PROCEDURE (l: LinkedList(E)) IndexOf* (obj: E): LONGINT;
(**Searches for the first occurence of the given argument, testing for equality
   using the @oproc{Object.Object.Equals} method.  Returns @code{-1} if the
   object is not found.  *)
VAR
  e : Entry(E);
  i : LONGINT;
BEGIN
  e := l.elements.next; i := 0;
  WHILE e # l.elements DO
    IF obj. Equals (e.element) THEN
      RETURN i
    END;
    INC(i); e := e.next;
  END;
  RETURN -1
END IndexOf;

PROCEDURE (l: LinkedList(E)) LastIndexOf* (obj: E): LONGINT;
(**Searches for the last occurence of the given argument, testing for equality
   using the @oproc{Object.Object.Equals} method.  Returns @code{-1} if the
   object is not found.  *)
VAR
  e : Entry(E);
  i: LONGINT;
BEGIN
  e := l.elements.previous; i := l.size;
  WHILE e # l.elements DO
    DEC(i);
    IF obj. Equals (e.element) THEN
      RETURN i
    END;
    e := e.previous;
  END;
  RETURN -1
END LastIndexOf;

PROCEDURE (l: LinkedList(E)) IsEmpty* (): BOOLEAN;
(**Tests if this list has no elements.  *)
BEGIN
  RETURN (l. size = 0)
END IsEmpty;

PROCEDURE (l: LinkedList(E)) Equals* (obj: Object.Object): BOOLEAN;
(**Test if an object is equal to this list. To be equal, a list must contain
the same sequence of objects. In this context, "same" means that the Equals
test returns true for pairs of objects at equivalent ordinal positions in the
source lists. *)
VAR
  e1, e2 : Entry(E);
BEGIN
  WITH obj : LinkedList(E) DO
    IF obj.size = l.size THEN
      e1 := l.elements.next;
      e2 := obj.elements.next;
      WHILE e1 # l.elements DO
        IF e1.element.Equals(e2.element) THEN
          e1 := e1.next; e2 := e2.next;
        ELSE
          RETURN FALSE;
        END;
      END;
      RETURN TRUE;
    ELSE
      RETURN FALSE;
    END;
  ELSE
    RETURN FALSE;
  END;
END Equals;

PROCEDURE (l: LinkedList(E)) HashCode* (): LONGINT;
  BEGIN
    <*PUSH; Assertions:=TRUE*>ASSERT(FALSE)<*POP*>
  END HashCode;

PROCEDURE (l: LinkedList(E)) Store* (w: Storable.Writer) RAISES IO.Error;
VAR
  e : Entry(E);
BEGIN
  w. WriteNum (l. size);
  e := l.elements.next;
  WHILE e # l.elements DO
    w.WriteObject(e.element);
    e := e.next;
  END;
END Store;

PROCEDURE (l: LinkedList(E)) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    o : Object.Object;
    i, size: LONGINT;
  BEGIN
    r. ReadNum (size);
    l.INIT;
    FOR i := 0 TO size-1 DO
      r. ReadObject (o);
      l.Append(SYSTEM.VAL(E, o));
    END;
    ASSERT(l.size = size);
  END Load;

PROCEDURE (l : LinkedList(E)) GetIterator* (i : Iterator(E)) : Iterator(E);
(**Return an iterator positioned at the start of this list. If an iterator
@oparam{i} is supplied (ie. not NIL), it will be initialised and returned as
the result. Otherwise (@oparam{i} is NIL), a new iterator is allocated. *)

BEGIN
  IF i = NIL THEN
    i := NEW(Iterator(E))
  END;

  i.list := l;
  i.nextIndex := 0;
  i.next := l.elements.next;
  i.lastReturned := NIL;
  RETURN i;
END GetIterator;

PROCEDURE (i : Iterator(E)) HasNext* () : BOOLEAN;
BEGIN
  RETURN i.nextIndex # i.list.size;
END HasNext;

PROCEDURE (i : Iterator(E)) Next* () : E;
BEGIN
  ASSERT(i.nextIndex # i.list.size);
  i.lastReturned := i.next;
  i.next := i.next.next;
  INC(i.nextIndex);
  RETURN i.lastReturned.element;
END Next;

PROCEDURE (i : Iterator(E)) NextIndex* () : LONGINT;
BEGIN
  RETURN i.nextIndex;
END NextIndex;

PROCEDURE (i : Iterator(E)) Remove*;
BEGIN
  ASSERT(i.lastReturned # NIL);
  i.list.RemoveEntry(i.lastReturned);
  IF i.next = i.lastReturned THEN
    i.next := i.lastReturned.next
  ELSE
    DEC(i.nextIndex);
  END;
END Remove;

PROCEDURE (i : Iterator(E)) Set* (obj : E);
BEGIN
  ASSERT(i.lastReturned # NIL);
  i.lastReturned.element := obj;
END Set;

PROCEDURE (i : Iterator(E)) Insert* (obj : E);
BEGIN
  i.lastReturned := NIL;
  i.list.AddBefore(obj, i.next);
  INC(i.nextIndex);
END Insert;

END ADT:LinkedList.
