MODULE OpTypeGuard2;

TYPE
  A = POINTER TO ADesc; ADesc = RECORD END;

PROCEDURE Test*;
VAR
  a : A;
BEGIN
  NEW(a);
  a(INTEGER).Do;
END Test;

END OpTypeGuard2.

