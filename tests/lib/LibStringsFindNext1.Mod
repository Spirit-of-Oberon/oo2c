MODULE LibStringsFindNext1;

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
    Strings.FindNext (pattern, string, startPos, found, pos);
    IF found THEN
      Out.String ("found at "); Out.Int (pos, 0);
    ELSE
      Out.String ("not found");
    END;
    Out.Ln;
  END Find;

PROCEDURE Test* ();
  BEGIN
    Find ("", "", 0);
    Find ("", "a", 0);
    Find ("", "a", 1);
    Find ("a", "ab", 0);
    Find ("b", "ab", 0);
    Find ("ab", "ab", 0);
    Find ("ba", "ab", 0);
  END Test;

END LibStringsFindNext1.
