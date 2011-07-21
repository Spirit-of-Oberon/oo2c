MODULE LibStringsEqual1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Equal (a, b: ARRAY OF CHAR);
  BEGIN
    IF Strings.Equal (a, b) THEN
      Out.String ("equal");
    ELSE
      Out.String ("not equal");
    END;
    Out.Ln;
  END Equal;

PROCEDURE Test* ();
  BEGIN
    Equal ("", "");
    Equal ("", "A");
    Equal ("A", "");
    Equal ("A", "A");
    Equal ("abc", "abc");
    Equal ("abc", "abe");
    Equal ("abe", "abc");
  END Test;

END LibStringsEqual1.
