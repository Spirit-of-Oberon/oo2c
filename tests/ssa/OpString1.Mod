MODULE OpString1;

IMPORT Out := Out0;

CONST
  s1 = "A" + "B";

PROCEDURE Test*;
BEGIN
  Out.String(s1); Out.Ln;
END Test;

END OpString1.
