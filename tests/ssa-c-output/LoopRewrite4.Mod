MODULE LoopRewrite4;
<*IndexCheck:=FALSE; Warnings:=FALSE *>

PROCEDURE Zero1(VAR a: ARRAY OF ARRAY OF CHAR);
(* Clear all elements of the array.  *)
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # LEN(a)) DO
      j := 0;
      WHILE (j # LEN(a,1)) DO
        a[i,j] := 0X;
        INC(j);
      END;
      INC(i);
    END;
  END Zero1;

PROCEDURE Zero2(VAR a: ARRAY OF ARRAY OF INTEGER);
(* Clear all elements of the array.  *)
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # LEN(a)) DO
      j := 0;
      WHILE (j # LEN(a,1)) DO
        a[i,j] := 0;
        INC(j);
      END;
      INC(i);
    END;
  END Zero2;

END LoopRewrite4.
