MODULE OpString7;

IMPORT Out := Out0;
  
PROCEDURE Write (str: ARRAY OF LONGCHAR);
  BEGIN
    Out.LString (str); Out.Ln;
  END Write;

PROCEDURE Test*;
  BEGIN
    Write ("");
    Write ("1");
    Write (61X);
    Write ("12");
  END Test;

END OpString7.
