MODULE ConstFold2;

IMPORT Out := Out0;
  
CONST c=1+2;

PROCEDURE Test* ();
  BEGIN
    Out.Int (c, 0); Out.Ln;
  END Test;

END ConstFold2.

