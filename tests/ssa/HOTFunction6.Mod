MODULE HOTFunction6;

IMPORT Out := Out0;
  
PROCEDURE IsA (ch: CHAR): INTEGER;
  BEGIN
    IF ch = "A" THEN
      RETURN 1
    ELSE
      RETURN 0
    END;
  END IsA;

PROCEDURE IsNotB (ch: CHAR): INTEGER;
  BEGIN
    IF (ch # "B") THEN
      RETURN 1
    ELSE
      RETURN 0
    END;
  END IsNotB;

PROCEDURE Test* ();
  BEGIN
    Out.Int(IsA("A"), 0); Out.Ln;
    Out.Int(IsA("B"), 0); Out.Ln;
    Out.Int(IsNotB("A"), 0); Out.Ln;
    Out.Int(IsNotB("B"), 0); Out.Ln;
  END Test;

END HOTFunction6.
