MODULE ConstFold1;

IMPORT Out;
  
CONST c=1;

PROCEDURE Test* ();
  BEGIN
    Out.Int (c, 0); Out.Ln;
  END Test;

END ConstFold1.
