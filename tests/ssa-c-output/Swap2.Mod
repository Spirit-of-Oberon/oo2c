MODULE Swap2;

IMPORT Out := Out0;

VAR
  x, y: INTEGER;

PROCEDURE Swap (swap: BOOLEAN);
  VAR
    hx, hy, h: INTEGER;
  BEGIN
    hx := x; hy := y;
    IF swap THEN
      h := hx; hx := hy; hy := h;
    END;
    x := hx; y := hy
  END Swap;

PROCEDURE Test* ();
  BEGIN
    x := 1; y := 2;
    Swap (FALSE);
    Out.Int (x, 2); Out.Int (y, 2); Out.Ln;
    Swap (TRUE);
    Out.Int (x, 2); Out.Int (y, 2); Out.Ln;
    Swap (TRUE);
    Out.Int (x, 2); Out.Int (y, 2); Out.Ln;
  END Test;

END Swap2.
