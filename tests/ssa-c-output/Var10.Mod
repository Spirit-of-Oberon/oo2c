MODULE Var10;

IMPORT Out := Out0;
  
PROCEDURE F (b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    x := 2;
    LOOP
      IF b THEN
        x := 1;
        EXIT;
      END;
      x := 3;
    END;
    RETURN x;
  END F;

PROCEDURE Test* ();
  BEGIN
    Out.Int (F(TRUE), 0); Out.Ln;
  END Test;

END Var10.
