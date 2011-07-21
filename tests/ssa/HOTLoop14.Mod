MODULE HOTLoop14;

IMPORT Out:=Out0;

PROCEDURE Test* ();
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    LOOP
      i := 1;
    END;
    Out.Int(i, 0); Out.Ln;
  END Test;

END HOTLoop14.
