MODULE LibStringsConcat1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    Strings.Concat ("", "abc", dest4);
    Out.String (dest4); Out.Ln;
    Strings.Concat ("abc", "", dest4);
    Out.String (dest4); Out.Ln;

    Strings.Concat ("", "ab", dest4);
    Out.String (dest4); Out.Ln;
    Strings.Concat ("ab", "", dest4);
    Out.String (dest4); Out.Ln;

    Strings.Concat ("ab", "c", dest4);
    Out.String (dest4); Out.Ln;

    Strings.Concat ("ab", "cd", dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsConcat1.
