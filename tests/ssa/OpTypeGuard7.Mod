
MODULE OpTypeGuard7;

TYPE
  A = POINTER TO ADesc; ADesc = RECORD END;

  B = POINTER TO BDesc; BDesc = RECORD (ADesc) END;

PROCEDURE F(a : A) : A;
BEGIN
  RETURN a;
END F;

PROCEDURE TestFunction(a : A);
VAR
  pA : A;
  pB : B;
BEGIN
  pA := F(a);
  pB := F(a)(B);
END TestFunction;

PROCEDURE Test*;
VAR
  b : B;
BEGIN
  NEW(b);
  TestFunction(b);
END Test;

END OpTypeGuard7.

