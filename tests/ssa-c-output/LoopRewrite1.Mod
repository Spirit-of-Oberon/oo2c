MODULE LoopRewrite1;
<*IndexCheck:=FALSE; Warnings:=FALSE *>

PROCEDURE Zero1(VAR a: ARRAY OF CHAR);
(* Clear all elements upto the first 0X.  Neither the element address nor
   the index are used after the loop, and can therefore be discarded.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (a[i] # 0X) DO
      a[i] := 0X;
      INC(i);
    END;
  END Zero1;

PROCEDURE Zero2(VAR a: ARRAY OF INTEGER);
(* Clear all elements upto the first 0.  Neither the element address nor
   the index are used after the loop, and can therefore be discarded.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (a[i] # 0) DO
      a[i] := 0;
      INC(i);
    END;
  END Zero2;

END LoopRewrite1.
