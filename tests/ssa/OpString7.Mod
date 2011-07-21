MODULE OpString7;

IMPORT Out := Out0;
  
PROCEDURE Write (str: ARRAY OF LONGCHAR);
  BEGIN
    Out.LString (str); Out.Ln;
  END Write;

PROCEDURE WriteUCS4 (str: ARRAY OF LONGCHAR);
  BEGIN
    Out.LString (str); Out.Ln;
  END WriteUCS4;

PROCEDURE Test*;
  BEGIN
    Write ("");
    Write ("1");
    Write (61X);
    Write ("12");
    Out.String("---"); Out.Ln;
    WriteUCS4 ("");
    WriteUCS4 ("1");
    WriteUCS4 (61X);
    WriteUCS4 ("12");    
  END Test;

END OpString7.
