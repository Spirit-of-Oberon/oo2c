MODULE LoopRewrite2;
<*IndexCheck:=FALSE; Warnings:=FALSE *>

PROCEDURE Zero1(VAR a: ARRAY OF CHAR);
(* Clear all elements of the array.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # LEN(a)) DO
      a[i] := 0X;
      INC(i);
    END;
  END Zero1;

PROCEDURE Zero2(VAR a: ARRAY OF INTEGER);
(* Clear all elements of the array.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # LEN(a)) DO
      a[i] := 0;
      INC(i);
    END;
  END Zero2;

END LoopRewrite2.
