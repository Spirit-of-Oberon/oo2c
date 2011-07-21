MODULE ConstFold11;

IMPORT Out := Out0;

TYPE
  A = ARRAY 16 OF CHAR;
  
CONST
  c = SIZE(A);
  
PROCEDURE Test*;
  BEGIN
    Out.Int(c,0); Out.Ln;
  END Test;

END ConstFold11.
