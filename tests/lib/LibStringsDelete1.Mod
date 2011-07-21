MODULE LibStringsDelete1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Test1 (str: ARRAY OF CHAR);
  BEGIN
    Out.String (str); Out.Ln;
    Strings.Delete (str, 2, 1);
    Out.String (str); Out.Ln;
    Strings.Delete (str, 1, 1);
    Out.String (str); Out.Ln;
    Strings.Delete (str, 0, 1);
    Out.String (str); Out.Ln;
  END Test1;

PROCEDURE Test2a (str: ARRAY OF CHAR);
  BEGIN
    Out.String (str); Out.Ln;
    Strings.Delete (str, 1, 2);
    Out.String (str); Out.Ln;
  END Test2a;

PROCEDURE Test2b (str: ARRAY OF CHAR);
  BEGIN
    Out.String (str); Out.Ln;
    Strings.Delete (str, 0, 2);
    Out.String (str); Out.Ln;
  END Test2b;

PROCEDURE Test3 (str: ARRAY OF CHAR);
  BEGIN
    Out.String (str); Out.Ln;
    Strings.Delete (str, 0, 3);
    Out.String (str); Out.Ln;
  END Test3;

PROCEDURE Test* ();
  BEGIN
    Test1 ("abc");
    Test2a ("abc");
    Test2b ("abc");
    Test3 ("abc");
  END Test;

END LibStringsDelete1.
