MODULE Abs0;

IMPORT Out := Out0;

PROCEDURE AbsInt(x: INTEGER): INTEGER;
  VAR
    y: INTEGER;
  BEGIN
    IF (x < 0) THEN
      y := -x;
    ELSE
      y := x;
    END;
    RETURN y;
  END AbsInt;

PROCEDURE AbsReal(x: REAL): REAL;
  VAR
    y: REAL;
  BEGIN
    IF (x < 0) THEN
      y := -x;
    ELSE
      y := x;
    END;
    RETURN y;
  END AbsReal;

PROCEDURE Test* ();
  BEGIN
    Out.Int(AbsInt(1), 0); Out.Ln;
    Out.Int(AbsInt(-1), 0); Out.Ln;
    Out.Real(AbsReal(1), 0); Out.Ln;
    Out.Real(AbsReal(-1), 0); Out.Ln;
  END Test;

END Abs0.
