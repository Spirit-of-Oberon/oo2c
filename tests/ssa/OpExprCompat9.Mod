MODULE OpExprCompat9;

TYPE
  Small = SHORTINT;
  Large = INTEGER;

PROCEDURE Test*;
VAR 
  s : Small;
  l : Large;
BEGIN
  s := s + l;
END Test;

END OpExprCompat9.
