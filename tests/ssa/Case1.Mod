MODULE Case1;

IMPORT Out := Out0;

PROCEDURE P (i: INTEGER);
  BEGIN
    CASE i OF
    | 1: Out.String ("one");
    | 2: Out.String ("two");
    | 3: Out.String ("three");
    | 4, 5: Out.String ("many");
    | 6..9: Out.String ("too many");
    ELSE
      Out.String ("no match");
    END;
    Out.Ln;
  END P;

PROCEDURE Test* ();
  VAR
    i: INTEGER;
  BEGIN
    FOR i := 0 TO 10 DO
      P (i);
    END;
  END Test;

END Case1.
