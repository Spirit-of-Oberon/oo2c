MODULE Var5b;

IMPORT Out := Out0;

VAR
  x, z: INTEGER;

PROCEDURE Set (y: INTEGER);
  BEGIN
    x := y
  END Set;

PROCEDURE F (b: BOOLEAN): INTEGER;
  BEGIN
    z := 0;
    IF b THEN
      Set (1)
    ELSE
      Set (0)
    END;
    RETURN x
  END F;

PROCEDURE Test* ();
  BEGIN
    x := -1;
    Out.Int (F (FALSE), 0); Out.Ln;
    Out.Int (x, 0); Out.Ln;
    Out.Int (F (TRUE), 0); Out.Ln;
    Out.Int (x, 0); Out.Ln;
  END Test;

END Var5b.
