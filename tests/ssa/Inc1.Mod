MODULE Inc1;

IMPORT Out := Out0;

VAR
  x: INTEGER;
  
PROCEDURE Test* ();
  BEGIN
    x := 1;
    Out.Int (x, 2); Out.Ln;
    INC (x);
    Out.Int (x, 2); Out.Ln;
  END Test;

END Inc1.
