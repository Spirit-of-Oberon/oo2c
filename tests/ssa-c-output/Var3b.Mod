MODULE Var3b;

IMPORT Out := Out0;

PROCEDURE F (a, b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    IF a THEN 
      x := 2
    ELSE
      IF b THEN
        x := 1
      ELSE
        x := 0
      END;
    END;
    RETURN x
  END F;

PROCEDURE Test* ();
  BEGIN
    Out.Int (F (FALSE, FALSE), 0); Out.Ln;
    Out.Int (F (FALSE, TRUE), 0); Out.Ln;
    Out.Int (F (TRUE, FALSE), 0); Out.Ln;
    Out.Int (F (TRUE, TRUE), 0); Out.Ln;
  END Test;

END Var3b.
