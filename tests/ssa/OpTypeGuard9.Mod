
MODULE OpTypeGuard9;

TYPE
  A = POINTER TO ADesc; ADesc = RECORD END;

PROCEDURE Test*;
VAR
  a : A;
BEGIN
  NEW(a);
  a(a).Do;
END Test;

END OpTypeGuard9.

