MODULE LibStringsExtract3;

IMPORT
  Out := Out0, Strings;
  
PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    Strings.Extract ("abcd", 0, 4, dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsExtract3.
