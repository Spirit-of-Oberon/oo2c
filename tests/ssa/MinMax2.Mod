MODULE MinMax2;

IMPORT Out := Out0;

PROCEDURE Test* ();
  BEGIN
    Out.Real(MIN(REAL), 9); Out.Ln;
    Out.Real(MAX(REAL), 9); Out.Ln;
    Out.LongReal(MIN(LONGREAL), 17); Out.Ln;
    Out.LongReal(MAX(LONGREAL), 17); Out.Ln;
  END Test;

END MinMax2.
