MODULE Len6;

IMPORT Out := Out0;

TYPE
  A3 = ARRAY 3 OF INTEGER;
  A = ARRAY 2 OF A3;
  
VAR
  a: A;

PROCEDURE Test* ();
  BEGIN
    Out.Int (LEN (a, 0X), 2); Out.Ln;
  END Test;

END Len6.
