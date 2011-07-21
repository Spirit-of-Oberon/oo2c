MODULE Dec1;

IMPORT Out := Out0;

VAR
  x: INTEGER;
  
PROCEDURE Test* ();
  BEGIN
    x := 1;
    Out.Int (x, 2); Out.Ln;
    DEC (x);
    Out.Int (x, 2); Out.Ln;
  END Test;

END Dec1.
