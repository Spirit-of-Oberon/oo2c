MODULE Swap1;

IMPORT Out := Out0;

VAR
  x, y: INTEGER;

PROCEDURE Swap();
  VAR
    h: INTEGER;
  BEGIN
    h := x; x := y; y := h;
  END Swap;

PROCEDURE Test* ();
  BEGIN
    x := 1; y := 2;
    Swap;
    Out.Int (x, 2); Out.Int (y, 2); Out.Ln;
    Swap;
    Out.Int (x, 2); Out.Int (y, 2); Out.Ln;
  END Test;

END Swap1.
