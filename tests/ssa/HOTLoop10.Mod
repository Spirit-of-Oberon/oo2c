MODULE HOTLoop10;

IMPORT Out := Out0;
  
PROCEDURE Quicksort (VAR a: ARRAY OF INTEGER; l, r: LONGINT);
  VAR
    i, j: LONGINT;
    t, v: INTEGER;
  BEGIN
    IF (l < r) THEN
      i := l-1; j := r;
      v := a[r];
      LOOP
        REPEAT INC (i) UNTIL (i > r) OR (a[i] >= v);
        REPEAT DEC (j) UNTIL (j < l) OR (a[j] <= v);
        IF (i >= j) THEN EXIT END;
        t := a[i]; a[i] := a[j]; a[j] := t
      END;
      t := a[i]; a[i] := a[r]; a[r] := t;
      Quicksort (a, l, i-1);
      Quicksort (a, i+1, r)
    END
  END Quicksort;

PROCEDURE Test* ();
  VAR
    a: ARRAY 3 OF INTEGER;
    i: INTEGER;
  BEGIN
    a[0] := 2; a[1] := 1; a[2] := 0;
    Quicksort(a, 0, 2);
    FOR i := 0 TO 2 DO
      Out.Int (a[i], 3);
    END;
    Out.Ln;
  END Test;

END HOTLoop10.
