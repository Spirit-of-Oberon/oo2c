MODULE Case10;

IMPORT Out := Out0;

PROCEDURE P (i: INTEGER);
  BEGIN
    CASE i OF
    | 1..0: Out.String ("empty");
    ELSE
      Out.String ("no match");
    END;
    Out.Ln;
  END P;

PROCEDURE Test* ();
  VAR
    i: INTEGER;
  BEGIN
    FOR i := -1 TO 2 DO
      P (i);
    END;
  END Test;

END Case10.
