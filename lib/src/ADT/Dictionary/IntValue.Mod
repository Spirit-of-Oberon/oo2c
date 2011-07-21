(*	$Id: IntValue.Mod,v 1.11 2005/07/05 16:35:58 mva Exp $	*)
MODULE ADT:Dictionary:IntValue;
(*  A dictionary implementation using objects' addresses as keys.
    Copyright (C) 2000, 2001, 2003, 2005  Michael van Acken

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

(**This module is a reimplementation of the Python dictionary code in
   Oberon-2.  It is based on version 2.65 of the python file
   @file{src/Objects/dictobject.c}.  It maps objects on other objects.
   Some bit twiddling is required, partially due to the algorithm and
   partially due to performance, which may impede portability of the
   code.

   Differences between @file{dictobject.c} and this implementation:

   @itemize
   @item
   @code{NIL} can be used as a value.  This implies that the field
   @samp{Entry.value} cannot be used to determine if the entry is in use or
   not.

   @item
   Any inefficiencies in this implementation are my fault, and do not originate
   in the Python implementation.
   @end itemize  *)

IMPORT
  S := SYSTEM, Object, IO, ADT:Storable;


TYPE
  Hash = LONGINT;
  HSet = SET;
  Index = LONGINT;
  Key* = Object.Object;
  Value* = LONGINT;
  
TYPE
  Entry = RECORD
  (**Invariant for entries: When in use, @ofield{key} is not @code{NIL} and not
     @ovar{dummy}.  When not in use, @ofield{key} is either @code{NIL} or
     @ovar{dummy}.  A dummy key value cannot be replaced by @code{NIL}, since
     otherwise other keys may be lost.  *)
    hash: Hash;
    (**The hash value of the object stored in @ofield{key}.  This is computed
       once, at the time the object is added to the dictionary.  *)
    key: Key;
    (**Key object.  For an unused slot, this is either @code{NIL} or
       @ovar{dummy}.  Use @oproc{IsSet} to determine if a given key is part of
       a valid item.  *)
    value: Value;
  END;
  Table = POINTER TO ARRAY OF Entry;

TYPE
  Dictionary* = POINTER TO DictionaryDesc;
  DictionaryDesc = RECORD
  (**Implements a dictionary that maps objects to objects.  The dictionary's
     keys are the object addresses (@code{NIL} is @emph{not} allowed as key),
     the values are arbitrary objects or @code{NIL}.

     At this moment, no iterator is defined for this class.  To get the list of
     all keys or values, use @oproc{Dictionary.Keys}.  *)
    (Storable.ObjectDesc)
    fill: LONGINT;
    (**The number of non-@code{NIL} keys.  *)
    used: LONGINT;
    (**The number of non-@code{NIL}, non-@ovar{dummy} keys.  *)
    size: Index;
    (**Size of the table.  Always a power of 2.  *)
    poly: LONGINT;
    table: Table;
    (**To ensure the lookup algorithm terminates, the table size must be a
       prime number and there must be at least one @code{NIL} key in the table.
       To avoid slowing down lookups on a near-full table, we resize the table
       when it is filled to two thirds.  *)
  END;

TYPE
  Dummy = POINTER TO DummyDesc;
  DummyDesc = RECORD (Object.ObjectDesc) END;

VAR
  dummy: Dummy;
  (**This object is used as dummy key to fill deleted entries.  *)
  
CONST
  minSize = 4;
  (**Minimum size of a dictionary.  Must be a power of 2.  *)

CONST
  maxPoly = 28;
  
VAR
  polys: ARRAY maxPoly+1 OF LONGINT;
  (**Table of irreducible polynomials to efficiently cycle through GF(2^n)-@{0@},
     2<=n<=30.  *)
  

PROCEDURE Init* (dict: Dictionary);
(**Initializes @oparam{dict} to an empty dictionary.  *)
  BEGIN
    dict. size := 0;
    dict. poly := 0;
    dict. table := NIL;
    dict. fill := 0;
    dict. used := 0;
  END Init;

PROCEDURE New* (): Dictionary;
(**Creates a new, empty dictionary.  *)
  VAR
    dict: Dictionary;
  BEGIN
    NEW (dict);
    Init (dict);
    RETURN dict
  END New;

PROCEDURE (dict: Dictionary) Destroy*;
  VAR
    i: LONGINT;
  BEGIN
    IF (dict. table # NIL) THEN
      FOR i := 0 TO dict. size-1 DO      (* clean up all entries for gc *)
        dict. table[i]. key := NIL;
        dict. table[i]. value := 0;
        dict. table[i]. hash := 0
      END;
      dict. table := NIL
    END
  END Destroy;



PROCEDURE IsSet (key: Key): BOOLEAN;
(* Returns TRUE iff `key' does not stand for an unused dictionary slot.  *)
  BEGIN
    RETURN (key # NIL) & (key # dummy)
  END IsSet;

PROCEDURE InternalLookup (dict: Dictionary; key: Key; hash: Hash): LONGINT;
(* Looks up the given (key, hash) pair in the dictionary.  Result is a valid
   index that either refers to an existing entry entry equal to `key', or an
   unused slot that can be filled with `key'.

   This basic lookup function is used by all operations.  This is based on
   Algorithm D from Knuth Vol. 3, Sec. 6.4.  Open addressing is preferred over
   chaining since the link overhead for chaining would be substantial (100%
   with typical malloc overhead).  However, instead of going through the table
   at constant steps, we cycle through the values of GF(2^n)-{0}. This avoids
   modulo computations, being much cheaper on RISC machines, without leading to
   clustering.

   The initial probe index is computed as hash mod the table size.  Subsequent
   probe indices use the values of x^i in GF(2^n) as an offset, where x is a
   root. The initial value is derived from hash, too.

   All arithmetic on hash should ignore overflow.

   (This version is due to Reimer Behrends, some ideas are also due to Jyrki
   Alakuijala and Vladimir Marangozov.)  *)
  VAR
    i, incr, freeslot: Index;
    mask: SET;
    t: Table;
  BEGIN
    t := dict. table;
    mask := S.VAL (SET, dict. size-1);
    i := S.VAL (Hash, (-S.VAL (HSet, hash)) * mask);
    IF (t[i]. key = NIL) OR (t[i]. key = key) THEN
      RETURN i
    ELSIF (t[i]. key = dummy) THEN
      freeslot := i
    ELSIF (t[i]. hash = hash) & key. Equals (t[i]. key) THEN
      RETURN i
    ELSE
      freeslot := -1
    END;
    
    incr := S.VAL (Hash, 
      S.VAL (HSet, hash) / S.VAL (HSet, S.LSH (hash, -3)) * mask);
    IF (incr = 0) THEN incr := dict. size-1 END;
    
    LOOP
      i := S.VAL (Index, S.VAL (SET, i+incr) * mask);
      IF (t[i]. key = NIL) THEN
        IF (freeslot >= 0) THEN
          RETURN freeslot
        ELSE
          RETURN i
        END
      ELSIF (t[i]. key = dummy) THEN
        IF (freeslot < 0) THEN
          freeslot := i
        END
      ELSIF (t[i]. hash = hash) & key. Equals (t[i]. key) THEN
        RETURN i
      END;
      incr := incr*2;
      IF (incr >= dict. size) THEN
        incr := S.VAL (LONGINT, S.VAL (SET, incr) / S.VAL (SET, dict. poly))
        (* this will implicitly clear the highest bit *)
      END
    END
  END InternalLookup;

PROCEDURE Insert (dict: Dictionary; key: Key;
                  hash: Hash; value: Value);
(**Internal procedure to insert a new item into the table.  Used both by the
   resize and the public insert routine.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := InternalLookup (dict, key, hash);
    IF IsSet (dict. table[i]. key) THEN  (* replacing old value *)
      dict. table[i]. value := value
    ELSE                                 (* inserting new value *)
      IF (dict. table[i]. key = NIL) THEN
        INC (dict. fill)
      END;
      dict. table[i]. key := key;
      dict. table[i]. hash := hash;
      dict. table[i]. value := value;
      INC (dict. used)
    END
  END Insert;

PROCEDURE Resize (dict: Dictionary; minUsed: LONGINT);
(**Resizes the table used by @oparam{dict} so that it can hold at least
   @oparam{minUsed} items.

   Only uses the fields @ofield{dict.size} and @ofield{dict.table}, the rest is
   recreated from scratch.  *)
  VAR
    i, oldSize, newSize, newPoly: LONGINT;
    oldTable, newTable: Table;
  BEGIN
    oldSize := dict. size;
    oldTable := dict. table;
    
    i := 0; newSize := minSize;
    WHILE (newSize <= minUsed) DO
      INC (i); newSize := ASH (newSize, 1);
    END;
    newPoly := polys[i];  (* index out of range means out of memory, sort of *)
    
    NEW (newTable, newSize);
    FOR i := 0 TO newSize-1 DO
      newTable[i]. key := NIL;
      newTable[i]. value := 0;
      newTable[i]. hash := 0
    END;
    dict. size := newSize;
    dict. poly := newPoly;
    dict. table := newTable;
    dict. fill := 0;
    dict. used := 0;
    
    FOR i := 0 TO oldSize-1 DO
      IF IsSet (oldTable[i]. key) THEN
        Insert (dict, oldTable[i]. key, oldTable[i]. hash, oldTable[i]. value);
        oldTable[i]. key := NIL;         (* be nice to gc *)
        oldTable[i]. value := 0;
      END
    END
  END Resize;


PROCEDURE (dict: Dictionary) HasKey* (key: Key): BOOLEAN;
(**Tests if an item in @oparam{dict} exists with the key @oparam{key}.

   @precond
   @oparam{key} is not @code{NIL}.
   @end precond  *)
  VAR
    index: LONGINT;
  BEGIN
    IF (dict. used = 0) THEN
      RETURN FALSE
    ELSE
      index := InternalLookup (dict, key, key. HashCode());
      RETURN IsSet (dict. table[index]. key)
    END
  END HasKey;

PROCEDURE (dict: Dictionary) Size* (): LONGINT;
(**Returns the number of items in the dictionary.  *)
  BEGIN
    RETURN dict. used
  END Size;

PROCEDURE (dict: Dictionary) Get* (key: Key): Value;
(**Retrieves the value associated with @oparam{key} in the dictionary
   @oparam{dict}.

   @precond
   An item with the key @oparam{key} exists in the dictionary @oparam{dict}.
   This implies that @oparam{key} is not @code{NIL}.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT (key # NIL);
    ASSERT (dict. used # 0);
    i := InternalLookup (dict, key, key. HashCode());
    ASSERT (IsSet (dict. table[i]. key));
    RETURN dict. table[i]. value
  END Get;

PROCEDURE (dict: Dictionary) Lookup* (key: Key; VAR value: Value): BOOLEAN;
(**If @oparam{key} exists in the dictionary @oparam{dict}, then the procedure
   assigns the value of @oparam{key} to @oparam{value} and returns @code{TRUE};
   otherwise, it returns @code{FALSE} and @oparam{value} is undefined.

   @precond
   @oparam{key} is not @code{NIL}.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT (key # NIL);
    IF dict. used = 0 THEN
      RETURN FALSE
    ELSE
      i := InternalLookup (dict, key, key. HashCode());
      IF IsSet (dict. table[i]. key) THEN
        value := dict. table[i]. value;
        RETURN TRUE
      ELSE
        RETURN FALSE
      END
    END
  END Lookup;

PROCEDURE (dict: Dictionary) Set* (key: Key; value: Value);
(**Sets the value for key @oparam{key} in the dictionary @oparam{dict} to
   @oparam{value}.  If an item with this key already exists, its value is
   replaced.  Otherwise, a new item is created with the given (@oparam{key},
   @oparam{value}) pair.

   @precond
   @oparam{key} is not @code{NIL}.
   @end precond  *)
  BEGIN
    ASSERT (key # NIL);
    IF (dict. fill*3 >= dict. size*2) THEN
      Resize (dict, dict. used*2)
    END;
    Insert (dict, key, key. HashCode(), value)
  END Set;

(*PROCEDURE (dict: Dictionary) SetDefault* (key: Key; default: Value): Value;
(**Set the value associated with @oparam{key} in the dictionary @oparam{dict}
   to @oparam{default} if @oparam{key} does not exist.  In this case,
   @oparam{default} is also the method's return value.  If @oparam{key} does
   exist, then return the current value without changing anything.  *)
  VAR
    i: LONGINT;
    hash: Hash;
  BEGIN
    ASSERT(key # NIL);
    IF (dict. fill*3 >= dict. size*2) THEN
      Resize (dict, dict. used*2)
    END;

    hash := key.HashCode();
    i := Lookup(dict, key, hash);
    IF IsSet(dict.table[i].key) THEN
      RETURN dict.table[i].value;
    ELSE
      IF (dict.table[i].key = NIL) THEN
        INC(dict.fill);
      END;
      
      dict.table[i].key := key;
      dict.table[i].hash := hash;
      dict.table[i].value := default;
      INC(dict.used);
      RETURN default;
    END;
  END SetDefault;*)

PROCEDURE (dict: Dictionary) Copy* (): Dictionary;
(**Creates a copy of the dictionary @oparam{dict}.  *)
  VAR
    copy: Dictionary;
    i: LONGINT;
  BEGIN
    copy := New();
    IF (dict. used > 0) THEN
      Resize (copy, (dict. used*3) DIV 2);
      FOR i := 0 TO dict. size-1 DO
        IF IsSet (dict. table[i]. key) THEN
          Insert (copy, dict. table[i]. key, dict. table[i]. hash,
                  dict. table[i]. value);
        END
      END
    END;
    RETURN copy
  END Copy;


PROCEDURE (dict: Dictionary) Delete* (key: Key);
(**Removes the item with the key @oparam{key} from the dictionary
   @oparam{dict}.

   @precond
   n item with the key @oparam{key} exists in the dictionary @oparam{dict}.
   This implies that @oparam{key} is not @code{NIL}.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT (key # NIL);
    ASSERT (dict. used # 0);
    i := InternalLookup (dict, key, key. HashCode());
    ASSERT (IsSet (dict. table[i]. key));
    dict. table[i]. key := dummy;       (* replace key with dummy, _not_ NIL *)
    dict. table[i]. value := 0;
    DEC (dict. used)
  END Delete;

PROCEDURE (dict: Dictionary) Clear*;
(**Removes all items from the dictionary @oparam{dict}.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (dict. table # NIL) THEN
      FOR i := 0 TO dict. size-1 DO      (* clean up all entries for gc *)
        dict. table[i]. key := NIL;
        dict. table[i]. value := 0;
        dict. table[i]. hash := 0
      END;
      Init (dict)
    END
  END Clear;


PROCEDURE (dict: Dictionary) Keys* (): Object.ObjectArrayPtr;
(**Returns the list of keys of the dictionary @oparam{dict}.  The keys are
   listed in no particular order.  *)
  VAR
    list: Object.ObjectArrayPtr;
    i, j: LONGINT;
  BEGIN
    NEW (list, dict. used);
    j := 0;
    FOR i := 0 TO dict. size-1 DO
      IF IsSet (dict. table[i]. key) THEN
        list[j] := dict. table[i]. key;
        INC (j)
      END
    END;
    ASSERT (j = dict. used);
    RETURN list
  END Keys;

(*PROCEDURE (dict: Dictionary) Values* (): ArrayList.ArrayList;
(**Returns the list of values of the dictionary @oparam{dict}.  The values are
   listed in no particular order.  *)
  VAR
    list: ArrayList.ArrayList;
    i, j: LONGINT;
  BEGIN
    list := ArrayList.New (dict. used);
    j := 0;
    FOR i := 0 TO dict. size-1 DO
      IF IsSet (dict. table[i]. key) THEN
        list. Append (dict. table[i]. value);
        INC (j)
      END
    END;
    ASSERT (j = dict. used);
    RETURN list
  END Values;*)


PROCEDURE (dict: Dictionary) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    w. WriteNum (dict. used);
    IF (dict. used # 0) THEN
      FOR i := 0 TO dict. size-1 DO
        IF IsSet (dict. table[i]. key) THEN
          w. WriteObject (dict. table[i]. key);
          w. WriteNum (dict. table[i]. value)
        END
      END
    END
  END Store;

PROCEDURE (dict: Dictionary) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    i: LONGINT;
    obj: Object.Object;
  BEGIN
    Init (dict);
    r. ReadNum (dict. size);
    IF (dict. size # 0) THEN
      (* first create a pseudo dictionary that holds all the entries from the
         file, then impose the hash structure on it *)
      NEW (dict. table, dict. size);
      FOR i := 0 TO dict. size-1 DO
        r. ReadObject (obj);
        dict. table[i]. key := obj;
        r. ReadNum (dict. table[i]. value);
        dict. table[i]. hash := dict. table[i]. key. HashCode()
      END;
      Resize (dict, (dict. size*3) DIV 2)
    END
  END Load;

BEGIN
  NEW (dummy);
  
  polys[0] := 4 + 3;
  polys[1] := 8 + 3;
  polys[2] := 16 + 3;
  polys[3] := 32 + 5;
  polys[4] := 64 + 3;
  polys[5] := 128 + 3;
  polys[6] := 256 + 29;
  polys[7] := 512 + 17;
  polys[8] := 1024 + 9;
  polys[9] := 2048 + 5;
  polys[10] := 4096 + 83;
  polys[11] := 8192 + 27;
  polys[12] := 16384 + 43;
  polys[13] := 32768 + 3;
  polys[14] := 65536 + 45;
  polys[15] := 131072 + 9;
  polys[16] := 262144 + 39;
  polys[17] := 524288 + 39;
  polys[18] := 1048576 + 9;
  polys[19] := 2097152 + 5;
  polys[20] := 4194304 + 3;
  polys[21] := 8388608 + 33;
  polys[22] := 16777216 + 27;
  polys[23] := 33554432 + 9;
  polys[24] := 67108864 + 71;
  polys[25] := 134217728 + 39;
  polys[26] := 268435456 + 9;
  polys[27] := 536870912 + 5;
  polys[28] := 1073741824 + 83;
END ADT:Dictionary:IntValue.
