MODULE LibStringsAssign1;

IMPORT
  Out := Out0, Strings;
  
PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    Strings.Assign ("", dest4);
    Out.String (dest4); Out.Ln;
    Strings.Assign ("a", dest4);
    Out.String (dest4); Out.Ln;
    Strings.Assign ("ab", dest4);
    Out.String (dest4); Out.Ln;
    Strings.Assign ("abc", dest4);
    Out.String (dest4); Out.Ln;
    Strings.Assign ("abcd", dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsAssign1.
