MODULE LibStringsDelete2;

IMPORT
  Out := Out0, Strings;

PROCEDURE Test1 (str: ARRAY OF CHAR);
  BEGIN
    Strings.Delete (str, 1, 2);
    Out.String (str); Out.Ln;
  END Test1;

PROCEDURE Test2 (str: ARRAY OF CHAR);
  BEGIN
    Strings.Delete (str, 2, 2);
    Out.String (str); Out.Ln;
  END Test2;

PROCEDURE Test3 (str: ARRAY OF CHAR);
  BEGIN
    Strings.Delete (str, 3, 2);
    Out.String (str); Out.Ln;
  END Test3;

PROCEDURE Test4 (str: ARRAY OF CHAR);
  BEGIN
    Strings.Delete (str, 4, 2);
    Out.String (str); Out.Ln;
  END Test4;

PROCEDURE Test* ();
  BEGIN
    Test1 ("abc");
    Test2 ("abc");
    Test3 ("abc");
    Test4 ("abc");
  END Test;

END LibStringsDelete2.
