MODULE OpArray11;

TYPE
  A = ARRAY 3, 5 OF CHAR;

PROCEDURE Test*;
  VAR
    a: A;
  BEGIN
    a[0,1,2] := 0X;
  END Test;

END OpArray11.
