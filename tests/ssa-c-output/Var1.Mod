MODULE Var1;

IMPORT Out := Out0;

PROCEDURE F(x: INTEGER): INTEGER;
  VAR
    y: INTEGER;
  BEGIN
    y := x;
    RETURN y
  END F;

PROCEDURE Test* ();
  BEGIN
    Out.Int (F(0), 0); Out.Ln;
    Out.Int (F(1), 0); Out.Ln;
  END Test;

END Var1.
