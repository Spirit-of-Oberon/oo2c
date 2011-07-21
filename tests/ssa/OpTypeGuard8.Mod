MODULE OpTypeGuard8;

TYPE
  P = POINTER TO ARRAY OF CHAR;

  ADesc = RECORD END; A = POINTER TO ADesc;

PROCEDURE Test*;
VAR
  a : P;
BEGIN
  NEW(a,10);
  a(ADesc).Do;
END Test;

END OpTypeGuard8.

