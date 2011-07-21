MODULE HOTLoop4;

IMPORT Out := Out0;
  
PROCEDURE Div10 (i: INTEGER): INTEGER;
  VAR
    j: INTEGER;
  BEGIN
    j := -1;
    LOOP
      IF (i = 0) THEN
        j := 0; EXIT;
      ELSIF (i = 10) THEN
        j := 1; EXIT;
      ELSE
        DEC (i);
      END;
    END;
    RETURN j
  END Div10;

PROCEDURE Test* ();
  BEGIN
    Out.Int (Div10(0), 0); Out.Ln;
    Out.Int (Div10(1), 0); Out.Ln;
    Out.Int (Div10(9), 0); Out.Ln;
    Out.Int (Div10(10), 0); Out.Ln;
    Out.Int (Div10(11), 0); Out.Ln;
  END Test;

END HOTLoop4.
