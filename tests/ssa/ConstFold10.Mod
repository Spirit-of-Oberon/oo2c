MODULE ConstFold10;

IMPORT Out := Out0;

CONST
  c = SIZE(CHAR);
  
PROCEDURE Test*;
  BEGIN
    Out.Int(c,0); Out.Ln;
  END Test;

END ConstFold10.
