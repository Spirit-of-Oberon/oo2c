MODULE HOTFunction7;

IMPORT Out := Out0;

<*FunctResult:=TRUE*>
PROCEDURE IsA (ch: CHAR): INTEGER;
  BEGIN
  END IsA;

PROCEDURE Test* ();
  BEGIN
    Out.Int(IsA("A"), 0); Out.Ln;
  END Test;

END HOTFunction7.
