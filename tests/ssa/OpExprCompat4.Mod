MODULE OpExprCompat4;

PROCEDURE Test*;
VAR 
  s : SET;
BEGIN
  s := "set" + {0, 2, 4};
END Test;

END OpExprCompat4.
