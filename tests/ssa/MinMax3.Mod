MODULE MinMax3;

IMPORT Out := Out0;

PROCEDURE Test* ();
  BEGIN
    Out.Int(ORD(MIN(CHAR)), 7); Out.Ln;
    Out.Int(ORD(MAX(CHAR)), 7); Out.Ln;
    Out.Int(ORD(MIN(LONGCHAR)), 7); Out.Ln;
    Out.Int(ORD(MAX(LONGCHAR)), 7); Out.Ln;
    Out.Int(ORD(MIN(UCS4CHAR)), 7); Out.Ln;
    Out.Int(ORD(MAX(UCS4CHAR)), 7); Out.Ln;
  END Test;

END MinMax3.
