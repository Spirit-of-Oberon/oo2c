MODULE Val3;

IMPORT Out := Out0;
  
PROCEDURE Test* ();
  BEGIN
    Out.Int(20H, 0); Out.Ln;
    Out.Int(020H, 0); Out.Ln;
  END Test;

END Val3.
