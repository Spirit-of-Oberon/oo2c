MODULE Val7;

IMPORT SYSTEM;

PROCEDURE Test*();
  TYPE
    Char2 = ARRAY 2 OF CHAR;
  VAR
    x: Char2; y: INTEGER;
  BEGIN
    y := 12H;
    x := SYSTEM.VAL(Char2,y);
    ASSERT((x[0] = 12X) OR (x[1] = 12X));
  END Test;

END Val7.
