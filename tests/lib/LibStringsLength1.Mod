MODULE LibStringsLength1;

IMPORT
  Out := Out0, Strings;
  
PROCEDURE Test* ();
  BEGIN
    Out.Int (Strings.Length (""), 0); Out.Ln;
    Out.Int (Strings.Length ("1"), 0); Out.Ln;
    Out.Int (Strings.Length ("12"), 0); Out.Ln;
  END Test;

END LibStringsLength1.
