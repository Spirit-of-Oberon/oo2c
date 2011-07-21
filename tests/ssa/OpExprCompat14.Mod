MODULE OpExprCompat14;

TYPE
  Small = REAL;
  Large = LONGREAL;

PROCEDURE Test*;
VAR 
  i, j : REAL;
  k : LONGREAL;
BEGIN
  i := j / k;
END Test;

END OpExprCompat14.
