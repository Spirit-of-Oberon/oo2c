MODULE HOTLoop5;

IMPORT Out := Out0;

PROCEDURE Test* ();
  VAR
    i, j: INTEGER;
  BEGIN
    i := 1;
    REPEAT
      j := 1;
      REPEAT
        Out.Int (j, 2);
        INC (j);
      UNTIL (j > i);
      Out.Ln;
      INC (i);
    UNTIL (i = 5);
  END Test;

END HOTLoop5.
