MODULE Abs1;

IMPORT Out := Out0;

PROCEDURE AbsInt (x, abs: INTEGER);
  BEGIN
    Out.Int(x, 4);
    Out.Int(abs, 4);
    Out.Int(ABS(x), 4);
    Out.Int(ABS(abs), 4);
    Out.Ln;
  END AbsInt;

PROCEDURE AbsReal (x, abs: REAL);
  BEGIN
    Out.Real(x, 4); Out.String ("  ");
    Out.Real(abs, 4); Out.String ("  ");
    Out.Real(ABS(x), 4); Out.String ("  ");
    Out.Real(ABS(abs), 4); Out.String ("  ");
    Out.Ln;
  END AbsReal;

PROCEDURE Test* ();
  BEGIN
    AbsInt (-4, ABS(-4));
    AbsInt (0, ABS(0));
    AbsInt (15, ABS(15));
    AbsReal (-4.5, ABS(-4.5));
    AbsReal (0, ABS(0));
    AbsReal (15.4, ABS(15.4));
  END Test;

END Abs1.
