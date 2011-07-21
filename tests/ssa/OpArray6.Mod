MODULE OpArray6;

TYPE
  A = POINTER TO ARRAY OF CHAR;

PROCEDURE P() : A;
VAR a : A;
BEGIN
  NEW(a, 10);
  a[0] := 0X;
  RETURN a;
END P;

PROCEDURE Test*;
BEGIN
  P()[0] := 0X;
END Test;

END OpArray6.
