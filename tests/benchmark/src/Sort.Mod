MODULE Sort;

<* IndexCheck := FALSE *> 

PROCEDURE QuickSort* (VAR a: ARRAY OF LONGINT; m, n: LONGINT);
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
      
      QuickSort (a, m, j);
      QuickSort (a, i+1, n);
    END;
  END QuickSort;

PROCEDURE BubbleSort* (VAR a : ARRAY OF LONGINT);
VAR
  temp, size : LONGINT;
  i, j : LONGINT;
BEGIN
  size := LEN(a);
  FOR i := size-2 TO 0 BY -1 DO
    FOR j := 0 TO i DO
      IF a[j] < a[j+1] THEN
        temp := a[j]; a[j] := a[j+1]; a[j+1] := temp;
      END;
    END;
  END;
END BubbleSort;

END Sort.
