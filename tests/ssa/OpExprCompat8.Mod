MODULE OpExprCompat8;

TYPE
  A = POINTER TO ADesc; ADesc = RECORD END;
  B = POINTER TO BDesc; BDesc = RECORD END;

PROCEDURE Test*;
VAR 
  a : A; b : B;
  res : BOOLEAN;
BEGIN
  NEW(a); NEW(b);
  res := a = b;
END Test;

END OpExprCompat8.
