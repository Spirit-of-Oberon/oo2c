MODULE Var2;

IMPORT Out := Out0;

VAR
  x: INTEGER;
  
PROCEDURE F(): INTEGER;
  BEGIN
    x := 1;
    x := 2;
    RETURN x
  END F;

PROCEDURE Test* ();
  BEGIN
    x := 0;
    Out.Int (F(), 0); Out.Ln;
    Out.Int (x, 0); Out.Ln;
  END Test;

END Var2.
