MODULE Odd1;

IMPORT Out := Out0;

PROCEDURE Odd (x: INTEGER; odd: BOOLEAN);
  BEGIN
    Out.Int(x, 4);
    Out.Bool(odd);
    Out.Bool(odd);
    Out.Ln;
  END Odd;

PROCEDURE Test* ();
  BEGIN
    Odd (65, TRUE);
    Odd (96, FALSE);
    Odd (-1, TRUE);
    Odd (0, FALSE);
  END Test;

END Odd1.
