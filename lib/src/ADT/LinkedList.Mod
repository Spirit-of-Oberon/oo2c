
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
  ADT:Object;

TYPE
  Entry = POINTER TO EntryDesc;
  EntryDesc = RECORD (Object.ObjectDesc)
    next, previous : Entry;
    element : Object.Object;
  END;

  LinkedList* = POINTER TO LinkedListDesc;
  LinkedListDesc* = RECORD (Object.ObjectDesc)
  (**Linked-list implementation of a list. Objects may be efficiently added to
     or removed from the start or end of the list, making it useful for
     implementing queues. *)

    elements : Entry;
    (**Holds the elements of the list. The index values in
       @samp{[0..@ofield{size}-1]} refer to valid entries.  *)
    size-: LONGINT;
    (**Number of elements in the list. *)
  END;

  Iterator* = POINTER TO IteratorDesc;
  IteratorDesc = RECORD
  (**Allow efficient traversal and modification of a list. *)
    list : LinkedList;
    lastReturned, next : Entry;
    nextIndex : LONGINT;
  END;

PROCEDURE NewEntry (element : Object.Object; next, previous : Entry) : Entry;
VAR e : Entry;
BEGIN
  NEW(e);
  e.previous := previous;
  e.next := next;
  e.element := element;
  RETURN e;
END NewEntry;

PROCEDURE Init* (l: LinkedList);
(**Initializes an emtpy list *)
VAR
  e : Entry;
BEGIN
  Object.Init (l);
  e := NewEntry(NIL, NIL, NIL); e.next := e; e.previous := e; 
  l.elements := e;
  l.size := 0
END Init;

PROCEDURE New* (): LinkedList;
(**Creates a new list *)
VAR
  l: LinkedList;
BEGIN
  NEW (l);
  Init (l);
  RETURN l
END New;

PROCEDURE (l: LinkedList) Destroy*;
BEGIN
  l.elements := NIL;
END Destroy;

PROCEDURE (l : LinkedList) GetFirst* () : Object.Object;
(**Returns the first element in this list *)
BEGIN
  ASSERT(l.size # 0);
  RETURN l.elements.next.element;
END GetFirst;

PROCEDURE (l : LinkedList) GetLast* () : Object.Object;
(**Returns the last element in this list *)
BEGIN
  ASSERT(l.size # 0);
  RETURN l.elements.previous.element;
END GetLast;

PROCEDURE (l : LinkedList) RemoveEntry(e : Entry);
BEGIN
  ASSERT(e # l.elements);
  ASSERT(l.size > 0);
  e.previous.next := e.next;
  e.next.previous := e.previous;
  DEC(l.size);
END RemoveEntry;

PROCEDURE (l : LinkedList) FindEntry(index : LONGINT) : Entry;
VAR
  e : Entry;
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

PROCEDURE (l : LinkedList) RemoveFirst* () : Object.Object;
(**Removes the first element in this list. 
   Shifts any subsequent elements to the left (subtracts one from their
   indices). *)
VAR result : Object.Object;
BEGIN
  result := l.elements.next.element;
  l.RemoveEntry(l.elements.next);
  RETURN result;
END RemoveFirst;

PROCEDURE (l : LinkedList) RemoveLast* () : Object.Object;
(**Removes the last element in this list. *)
VAR result : Object.Object;
BEGIN
  result := l.elements.previous.element;
  l.RemoveEntry(l.elements.previous);
  RETURN result;
END RemoveLast;

PROCEDURE (l: LinkedList) Remove* (index: LONGINT) : Object.Object;
(**Removes the element at the specified position @oparam{index} in this list.
   Shifts any subsequent elements to the left (subtracts one from their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
VAR
  e : Entry;
BEGIN
  e := l.FindEntry(index);
  l.RemoveEntry(e);
  RETURN e.element;
END Remove;

PROCEDURE (l: LinkedList) RemoveRange* (fromIndex, toIndex: LONGINT);
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
  fromEntry, toEntry : Entry;
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

PROCEDURE (l : LinkedList) AddBefore (element : Object.Object; e : Entry);
VAR new : Entry;
BEGIN
  new := NewEntry(element, e, e.previous);
  new.previous.next := new;
  new.next.previous := new;
  INC(l.size);
END AddBefore;

PROCEDURE (l : LinkedList) Prepend* (obj : Object.Object);
(**Appends the specified element @oparam{obj} to the beginning of this list.  *)
BEGIN
  l.AddBefore(obj, l.elements.next);
END Prepend;

PROCEDURE (l: LinkedList) Append* (obj: Object.Object);
(**Appends the specified element @oparam{obj} to the end of this list.  *)
BEGIN
  l.AddBefore(obj, l.elements);
END Append;

PROCEDURE (l: LinkedList) Copy* (): LinkedList;
(**Returns a shallow copy of @oparam{l}.  The elements themselves are not
   copied.  *)
VAR
  new: LinkedList;
  e : Entry;
BEGIN
  new := New ();
  e := l.elements.next;
  WHILE e # l.elements DO
    new.Append(e.element);
    e := e.next;
  END;
  RETURN new
END Copy;

PROCEDURE (l: LinkedList) Clear*;
(**Removes all of the elements from this list.  The list will be empty after
   this call returns.  *)
BEGIN
  Init(l);
END Clear;

PROCEDURE (l: LinkedList) Insert* (index: LONGINT; obj: Object.Object);
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

PROCEDURE (l: LinkedList) Get* (index: LONGINT): Object.Object;
(**Returns the element at the specified position @oparam{index} in this list.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
VAR
  e : Entry;
BEGIN
  e := l.FindEntry(index);
  RETURN e.element;
END Get;

PROCEDURE (l: LinkedList) Set* (index: LONGINT; obj: Object.Object);
(**Replaces the element at the specified position @oparam{index} in this list
   with the specified element @oparam{obj}.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
VAR
  e : Entry;
BEGIN
  e := l.FindEntry(index);
  e.element := obj;
END Set;

PROCEDURE (l: LinkedList) Size* (): LONGINT;
(**Returns the number of elements in this list.  *)
BEGIN
  RETURN l. size
END Size;

PROCEDURE (l: LinkedList) Contains* (obj: Object.Object): BOOLEAN;
(**Returns @code{TRUE} if this list contains the specified element.  *)
VAR
  e : Entry;
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

PROCEDURE (l: LinkedList) IndexOf* (obj: Object.Object): LONGINT;
(**Searches for the first occurence of the given argument, testing for equality
   using the @oproc{Object.Object.Equals} method.  Returns @code{-1} if the
   object is not found.  *)
VAR
  e : Entry;
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

PROCEDURE (l: LinkedList) LastIndexOf* (obj: Object.Object): LONGINT;
(**Searches for the last occurence of the given argument, testing for equality
   using the @oproc{Object.Object.Equals} method.  Returns @code{-1} if the
   object is not found.  *)
VAR
  e : Entry;
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

PROCEDURE (l: LinkedList) IsEmpty* (): BOOLEAN;
(**Tests if this list has no elements.  *)
BEGIN
  RETURN (l. size = 0)
END IsEmpty;

PROCEDURE (l: LinkedList) Equals* (obj: Object.Object): BOOLEAN;
(**Test if an object is equal to this list. To be equal, a list must contain
the same sequence of objects. In this context, "same" means that the Equals
test returns true for pairs of objects at equivalent ordinal positions in the
source lists. *)
VAR
  e1, e2 : Entry;
BEGIN
  WITH obj : LinkedList DO
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

PROCEDURE (l: LinkedList) HashCode* (): LONGINT;
  BEGIN
    <*PUSH; Assertions:=TRUE*>ASSERT(FALSE)<*POP*>
  END HashCode;

PROCEDURE (l: LinkedList) Store* (w: Object.Writer);
VAR
  e : Entry;
BEGIN
  w. WriteNum (l. size);
  e := l.elements.next;
  WHILE e # l.elements DO
    w. WriteObject(e.element);
    e := e.next;
  END;
END Store;

PROCEDURE (l: LinkedList) Load* (r: Object.Reader);
  VAR
    o : Object.Object;
    i, size: LONGINT;
  BEGIN
    r. ReadNum (size);
    Init(l);
    FOR i := 0 TO size-1 DO
      r. ReadObject (o);
      l.Append(o);
    END;
    ASSERT(l.size = size);
  END Load;

PROCEDURE (l : LinkedList) GetIterator* (i : Iterator) : Iterator;
(**Return an iterator positioned at the start of this list. If an iterator
@oparam{i} is supplied (ie. not NIL), it will be initialised and returned as
the result. Otherwise (@oparam{i} is NIL), a new iterator is allocated. *)

BEGIN
  IF i = NIL THEN
    NEW(i);
  ELSE
    ASSERT(i IS Iterator);
  END;

  i.list := l;
  i.nextIndex := 0;
  i.next := l.elements.next;
  i.lastReturned := NIL;
  RETURN i;
END GetIterator;

PROCEDURE (i : Iterator) HasNext* () : BOOLEAN;
BEGIN
  RETURN i.nextIndex # i.list.size;
END HasNext;

PROCEDURE (i : Iterator) Next* () : Object.Object;
BEGIN
  ASSERT(i.nextIndex # i.list.size);
  i.lastReturned := i.next;
  i.next := i.next.next;
  INC(i.nextIndex);
  RETURN i.lastReturned.element;
END Next;

PROCEDURE (i : Iterator) NextIndex* () : LONGINT;
BEGIN
  RETURN i.nextIndex;
END NextIndex;

PROCEDURE (i : Iterator) Remove*;
BEGIN
  ASSERT(i.lastReturned # NIL);
  i.list.RemoveEntry(i.lastReturned);
  IF i.next = i.lastReturned THEN
    i.next := i.lastReturned.next
  ELSE
    DEC(i.nextIndex);
  END;
END Remove;

PROCEDURE (i : Iterator) Set* (obj : Object.Object);
BEGIN
  ASSERT(i.lastReturned # NIL);
  i.lastReturned.element := obj;
END Set;

PROCEDURE (i : Iterator) Insert* (obj : Object.Object);
BEGIN
  i.lastReturned := NIL;
  i.list.AddBefore(obj, i.next);
  INC(i.nextIndex);
END Insert;

END ADT:LinkedList.
