(*	$Id$	*)
MODULE ADT:ArrayList;
(*  Implements a resizable list of objects.
    Copyright (C) 2000  Michael van Acken

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
  ADT:Object, Language:=LanguageNew;


TYPE
  Array = POINTER TO ARRAY OF Object.Object;
  ArrayList* = POINTER TO ArrayListDesc;
  ArrayListDesc* = RECORD
  (**Resizable-array implementation of a list.  *)
    (Object.ObjectDesc)
    array-: Array;
    (**Holds the elements of the list.  The index values in
       @samp{[0..@ofield{size}-1]} refer to valid entries.  *)
    size-: LONGINT;
    (**Number of elements in the array.  This value is always less or equal to
       @samp{LEN(@ofield{array})}.  *)
  END;


PROCEDURE CreateArray (size: LONGINT; old: ArrayList): Array;
  VAR
    new: Array;
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
    RETURN new
  END CreateArray;

PROCEDURE Init* (l: ArrayList; initialSize: LONGINT);
(**Initializes a list with the stated initial size.  *)
  BEGIN
    Object.Init (l);
    l. array := CreateArray (initialSize, NIL);
    l. size := 0
  END Init;

PROCEDURE New* (initialSize: LONGINT): ArrayList;
(**Creates a new list with the stated initial size.

   @precond
   @samp{@oparam{initialSize} >= 0}
   @end precond  *)
  VAR
    l: ArrayList;
  BEGIN
    NEW (l);
    Init (l, initialSize);
    RETURN l
  END New;

PROCEDURE (l: ArrayList) Destroy*;
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO l. size-1 DO
      l. array[i] := NIL
    END;
    l. array := NIL
  END Destroy;

PROCEDURE (l: ArrayList) Copy*(): ArrayList;
(**Returns a shallow copy of @oparam{l}.  The elements themselves are not
   copied.  *)
  VAR
    new: ArrayList;
    i: LONGINT;
  BEGIN
    new := New (l. size);
    FOR i := 0 TO l. size-1 DO
      new. array[i] := l. array[i]
    END;
    new. size := l. size;
    RETURN new
  END Copy;



PROCEDURE (l: ArrayList) EnsureCapacity* (size: LONGINT);
(**Increases the capacity of @oparam{l}, if necessary, to ensure that it can
   hold at least the number of elements specified by the minimum capacity
   argument @oparam{size}.
   
   @precond
   @samp{@oparam{size} >= 0}
   @end precond  *)
  BEGIN
    IF (LEN (l. array^) < size) THEN
      l. array := CreateArray (size, l)
    END
  END EnsureCapacity;

PROCEDURE (l: ArrayList) Clear*;
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

PROCEDURE (l: ArrayList) Append* (obj: Object.Object);
(**Appends the specified element @oparam{obj} to the end of this list.  *)
  BEGIN
    IF (l. size = LEN (l. array^)) THEN
      l. array := CreateArray (l. size*2, l)
    END;
    l. array[l. size] := obj;
    INC (l. size)
  END Append;

PROCEDURE (l: ArrayList) Insert* (index: LONGINT; obj: Object.Object);
(**Inserts the specified element @oparam{obj} at the specified position
   @oparam{index} in this list.  Shifts the element currently at that position
   (if any) and any subsequent elements to the right (adds one to their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT (index <= l. size);
    IF (l. size = LEN (l. array^)) THEN
      l. array := CreateArray (l. size*2, l)
    END;
    FOR i := l. size-1 TO index DO
      l. array[i+1] := l. array[i]
    END;
    l. array[index] := obj;
    INC (l. size)
  END Insert;

PROCEDURE (l: ArrayList) Get* (index: LONGINT): Object.Object;
(**Returns the element at the specified position @oparam{index} in this list.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  BEGIN
    ASSERT (index < l. size);
    RETURN l. array[index]
  END Get;

PROCEDURE (l: ArrayList) Set* (index: LONGINT; obj: Object.Object);
(**Replaces the element at the specified position @oparam{index} in this list
   with the specified element @oparam{obj}.

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  BEGIN
    ASSERT (index < l. size);
    l. array[index] := obj
  END Set;

PROCEDURE (l: ArrayList) RemoveRange* (fromIndex, toIndex: LONGINT);
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

PROCEDURE (l: ArrayList) Remove* (index: LONGINT);
(**Removes the element at the specified position @oparam{index} in this list.
   Shifts any subsequent elements to the left (subtracts one from their
   indices).

   @precond
   @samp{0 <= @oparam{index}} and @samp{@oparam{index} < @oproc{l.Size}()}
   @end precond  *)
  BEGIN
    l. RemoveRange (index, index+1)
  END Remove;

PROCEDURE (l: ArrayList) TrimToSize*;
(**Trims the capacity of @oparam{l} to be the list's current size.  An
   application can use this operation to minimize the storage of an
   @otype{ArrayList} instance.  *)
  BEGIN
    IF (l. size # LEN (l. array^)) THEN
      l. array := CreateArray (l. size, l)
    END
  END TrimToSize;


PROCEDURE (l: ArrayList) Size* (): LONGINT;
(**Returns the number of elements in this list.  *)
  BEGIN
    RETURN l. size
  END Size;

PROCEDURE (l: ArrayList) Contains* (obj: Object.Object): BOOLEAN;
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

PROCEDURE (l: ArrayList) IndexOf* (obj: Object.Object): LONGINT;
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

PROCEDURE (l: ArrayList) LastIndexOf* (obj: Object.Object): LONGINT;
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

PROCEDURE (l: ArrayList) IsEmpty* (): BOOLEAN;
(**Tests if this list has no elements.  *)
  BEGIN
    RETURN (l. size = 0)
  END IsEmpty;



PROCEDURE (l: ArrayList) Equals* (obj: Language.Object): BOOLEAN;
  BEGIN
    <*PUSH; Assertions:=TRUE*>ASSERT(FALSE)<*POP*>
  END Equals;

PROCEDURE (l: ArrayList) HashCode* (): LONGINT;
  BEGIN
    <*PUSH; Assertions:=TRUE*>ASSERT(FALSE)<*POP*>
  END HashCode;

PROCEDURE (l: ArrayList) Store* (w: Object.Writer);
  VAR
    i: LONGINT;
  BEGIN
    w. WriteNum (l. size);
    FOR i := 0 TO l. size-1 DO
      w. WriteObject (l. array[i]);
    END
  END Store;

PROCEDURE (l: ArrayList) Load* (r: Object.Reader);
  VAR
    i, size: LONGINT;
  BEGIN
    r. ReadNum (size);
    Init (l, size);
    FOR i := 0 TO size-1 DO
      r. ReadObject (l. array[i])
    END;
    l. size := size
  END Load;

END ADT:ArrayList.
