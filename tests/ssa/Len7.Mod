MODULE Len7;

IMPORT Out := Out0;

TYPE
  A3 = ARRAY 3 OF INTEGER;
  A = ARRAY 2 OF A3;
  
VAR
  a: A;

PROCEDURE Test* ();
  VAR
    d: INTEGER;
  BEGIN
    d := 0;
    Out.Int (LEN (a, d), 2); Out.Ln;
  END Test;

END Len7.
