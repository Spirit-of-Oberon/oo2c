MODULE Div2;

IMPORT Out := Out0;

PROCEDURE Div (i, j: INTEGER);
  BEGIN
    Out.Int (i, 3); Out.String (" DIV "); Out.Int (j, 0); Out.String (" = ");
    Out.Int (i DIV j, 0); Out.Ln;
  END Div;

PROCEDURE Test* ();
  VAR
    i: INTEGER;
  BEGIN
    FOR i := -6 TO 6 DO
      Div (i, -3);
    END;
  END Test;

END Div2.
