MODULE LibStringsFindPrev2;

IMPORT
  Out := Out0, Strings;

PROCEDURE Find (pattern, string: ARRAY OF CHAR; startPos: INTEGER);
  VAR
    found: BOOLEAN;
    pos: INTEGER;
  BEGIN
    Out.String ('Find("'); Out.String (pattern); Out.String ('", "');
    Out.String (string); Out.String ('", '); Out.Int (startPos, 0);
    Out.String ("): ");
    Strings.FindPrev (pattern, string, startPos, found, pos);
    IF found THEN
      Out.String ("found at "); Out.Int (pos, 0);
    ELSE
      Out.String ("not found");
    END;
    Out.Ln;
  END Find;

PROCEDURE Test* ();
  BEGIN
    Find ("abc", "xbc", 3);
    Find ("xabc", "abc", 3);
    Find ("abc", "abc", 4);
    Find ("abc", "abcxbc", 1000);
  END Test;

END LibStringsFindPrev2.
