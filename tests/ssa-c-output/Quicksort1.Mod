MODULE Quicksort1;

IMPORT
  RandomNumbers, Out := Out0;

<* IndexCheck := FALSE *>
PROCEDURE Sort* (VAR a: ARRAY OF LONGINT; m, n: LONGINT);
(* Sort array a[m..n], so that a[m] is the smallest and a[n] the largest
   value.  *)
  VAR
    i, j, v, x: LONGINT;
  BEGIN
    IF (n > m) THEN
      i := m-1; j := n; v := a[n];
      LOOP
        REPEAT
          INC (i);
        UNTIL (a[i] >= v);
        REPEAT
          DEC (j);
        UNTIL (a[j] <= v);
        IF (i >= j) THEN
          EXIT;
        END;
        x := a[i]; a[i] := a[j]; a[j] := x;
      END;
      x := a[i]; a[i] := a[n]; a[n] := x;
      
      Sort (a, m, j);
      Sort (a, i+1, n);
    END;
  END Sort;

PROCEDURE Test* ();
  CONST
    size = 64;
  VAR
    a: ARRAY size OF LONGINT;
    i: LONGINT;
  BEGIN
    FOR i := 0 TO size-1 DO
      a[i] := RandomNumbers.RND(size);
    END;
    Sort (a, 0, size-1);
    FOR i := 0 TO size-1 DO
      Out.Int (a[i], 4);
    END;
    Out.Ln;
  END Test;

END Quicksort1.
