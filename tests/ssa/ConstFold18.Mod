MODULE ConstFold18;

IMPORT Out := Out0;

CONST c = ENTIER(-1.9);

PROCEDURE Test*;
BEGIN
  Out.Int(c, 3);
  Out.Ln;
END Test;

END ConstFold18.
