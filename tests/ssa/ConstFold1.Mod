MODULE ConstFold1;

IMPORT Out := Out0;
  
CONST c=1;

PROCEDURE Test* ();
  BEGIN
    Out.Int (c, 0); Out.Ln;
  END Test;

END ConstFold1.
