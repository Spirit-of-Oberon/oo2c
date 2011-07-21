MODULE OpExprCompat13;

TYPE
  Small = REAL;
  Large = LONGREAL;

PROCEDURE Test*;
VAR 
  i, j, k : INTEGER;
BEGIN
  i := j / k;
END Test;

END OpExprCompat13.
