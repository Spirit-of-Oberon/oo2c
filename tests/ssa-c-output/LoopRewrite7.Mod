MODULE LoopRewrite7;
<*IndexCheck:=FALSE; DerefCheck:=FALSE*>

TYPE
  RealArray* = POINTER TO ARRAY OF REAL;

PROCEDURE CopyArray1* (a, b: RealArray; len: LONGINT);
  VAR
    i : LONGINT;
  BEGIN
    i := 0;
    WHILE i < len DO
      b[i] := a[i];
      INC(i,1);
    END;
  END CopyArray1;

END LoopRewrite7.
