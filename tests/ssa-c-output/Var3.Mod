MODULE Var3;

IMPORT Out := Out0;

PROCEDURE F (b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    IF b THEN
      x := 1
    ELSE
      x := 0
    END;
    RETURN x
  END F;

PROCEDURE Test* ();
  BEGIN
    Out.Int (F (FALSE), 0); Out.Ln;
    Out.Int (F (TRUE), 0); Out.Ln;
  END Test;

END Var3.
