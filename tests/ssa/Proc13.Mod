MODULE Proc13;

IMPORT Out := Out0;

PROCEDURE P (y: INTEGER);
  BEGIN
    y := 99;
  END P;

PROCEDURE Test* ();
  VAR
    x: INTEGER;
  BEGIN
    x := 12;
    Out.Int (x, 0); Out.Ln;
    P(x);
    Out.Int (x, 0); Out.Ln;
  END Test;

END Proc13.
