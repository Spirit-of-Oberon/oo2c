MODULE LoopRewrite6;
<*IndexCheck:=FALSE; DerefCheck:=FALSE; Warnings:=FALSE *>

TYPE
  RealArray = POINTER TO ARRAY OF REAL;
  
PROCEDURE ZeroArray2(a: RealArray; len: LONGINT);
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE i < len DO
      a[i] := 0;
      a[i+1] := 0;
      INC(i, 2);
    END;
  END ZeroArray2;

END LoopRewrite6.
