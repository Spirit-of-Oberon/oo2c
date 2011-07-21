MODULE OpExprCompat11;

TYPE
  Small = LONGINT;
  Large = REAL;

PROCEDURE Test*;
VAR 
  s : Small;
  l : Large;
BEGIN
  s := s + l;
END Test;

END OpExprCompat11.
