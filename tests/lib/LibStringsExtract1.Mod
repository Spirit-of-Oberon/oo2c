MODULE LibStringsExtract1;

IMPORT
  Out := Out0, Strings;
  
PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    Strings.Extract ("abc", 0, 1, dest4);
    Out.String (dest4); Out.Ln;
    Strings.Extract ("abc", 1, 1, dest4);
    Out.String (dest4); Out.Ln;
    Strings.Extract ("abc", 2, 1, dest4);
    Out.String (dest4); Out.Ln;
    Strings.Extract ("abc", 0, 2, dest4);
    Out.String (dest4); Out.Ln;
    Strings.Extract ("abc", 1, 2, dest4);
    Out.String (dest4); Out.Ln;
    Strings.Extract ("abc", 0, 3, dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsExtract1.
