MODULE LibStringsReplace1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Replace (source, dest: ARRAY OF CHAR; startPos: INTEGER);
  BEGIN
    Strings.Replace (source, startPos, dest);
    Out.String (dest); Out.Ln;
  END Replace;

PROCEDURE Test* ();
  BEGIN
    Replace ("AB", "abc", 0);
    Replace ("BC", "abc", 1);
    Replace ("", "abc", 0);
    Replace ("", "abc", 3);
  END Test;

END LibStringsReplace1.
