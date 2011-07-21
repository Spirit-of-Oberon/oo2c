MODULE LibStringsCapitalize1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Cap (str: ARRAY OF CHAR);
  BEGIN
    Out.String ("in: "); Out.String (str); Out.Ln;
    Strings.Capitalize (str);
    Out.String ("cap: "); Out.String (str); Out.Ln;
  END Cap;

PROCEDURE Test* ();
  BEGIN
    Cap("");
    Cap("abc123ABC");
  END Test;

END LibStringsCapitalize1.
