MODULE LibStringsFindDiff1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Find (str1, str2: ARRAY OF CHAR);
  VAR
    found: BOOLEAN;
    pos: INTEGER;
  BEGIN
    Out.String ('Find("'); Out.String (str1); Out.String ('", "');
    Out.String (str2); Out.String ('"): ');
    Strings.FindDiff (str1, str2, found, pos);
    IF found THEN
      Out.String ("difference found at "); Out.Int (pos, 0);
    ELSE
      Out.String ("no difference found");
    END;
    Out.Ln;
  END Find;

PROCEDURE Test* ();
  BEGIN
    Find ("", "");
    Find ("a", "a");
    Find ("a", "b");
    Find ("ab", "abc");
    Find ("abc", "ab");
    Find ("abc", "abc");
  END Test;

END LibStringsFindDiff1.
