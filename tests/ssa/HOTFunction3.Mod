MODULE HOTFunction3;

IMPORT Out := Out0;
  
PROCEDURE Identity (n: INTEGER): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    x := n;
    RETURN x
  END Identity;

PROCEDURE Test* ();
  BEGIN
    Out.Int(Identity(1), 0); Out.Ln;
    Out.Int(Identity(2), 0); Out.Ln;
  END Test;

END HOTFunction3.
