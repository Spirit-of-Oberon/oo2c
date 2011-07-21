MODULE OpExprCompat10;

TYPE
  Small = INTEGER;
  Large = LONGINT;

PROCEDURE Test*;
VAR 
  s : Small;
  l : Large;
BEGIN
  s := s + l;
END Test;

END OpExprCompat10.
