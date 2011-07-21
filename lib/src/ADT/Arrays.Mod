(*	$Id: Arrays.Mod,v 1.3 2002/12/20 17:46:21 mva Exp $	*)
MODULE ADT:Arrays;
(*  Miscellaneous operations on arrays of objects.
    Copyright (C) 2001  Michael van Acken

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
  Object, ADT:Comparator;



PROCEDURE Sort* (VAR a: ARRAY OF Object.Object; pos, endpos: LONGINT;
                 cmp: Comparator.Comparator);
(**Sort array interval @samp{@oparam{a}[@oparam{pos}, @oparam{endpos}[}
   according to the comparator function @oparam{cmp}.  *)
   
  PROCEDURE Quicksort (l, r: LONGINT);
    VAR
      t, v: Object.Object;
      i, j, m: LONGINT;
    BEGIN
      IF (r > l) THEN
        m := (r+l) DIV 2;
        IF (cmp. Compare (a[l], a[r]) > 0) THEN
          t := a[l]; a[l] := a[r]; a[r] := t
        END;
        IF (cmp. Compare (a[l], a[m]) > 0) THEN
          t := a[l]; a[l] := a[m]; a[m] := t
        END;
        IF (cmp. Compare (a[r], a[m]) > 0) THEN
          t := a[r]; a[r] := a[m]; a[m] := t
        END;
        
        v := a[r]; i := l-1; j := r;
        LOOP
          REPEAT
            INC (i)
          UNTIL (cmp. Compare (a[i], v) >= 0);
          REPEAT
            DEC (j)
          UNTIL (j < 0) OR (cmp. Compare (a[j], v) <= 0);
          IF (i >= j) THEN
            EXIT
          END;
          t := a[i]; a[i] := a[j]; a[j] := t
        END;
        t := a[i]; a[i] := a[r]; a[r] := t;
        Quicksort (l, i-1);
        Quicksort (i+1, r)
      END
    END Quicksort;

  BEGIN
    Quicksort (pos, endpos-1)
  END Sort;

END ADT:Arrays.
