MODULE LibStringsCompare1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Compare (a, b: ARRAY OF CHAR);
  VAR
    cmp: Strings.CompareResults;
  BEGIN
    cmp := Strings.Compare (a, b);
    IF (cmp = Strings.less) THEN Out.String ("less"); END;
    IF (cmp = Strings.equal) THEN Out.String ("equal"); END;
    IF (cmp = Strings.greater) THEN Out.String ("greater"); END;
    Out.Ln;
  END Compare;

PROCEDURE Test* ();
  BEGIN
    Compare ("", "");
    Compare ("", "A");
    Compare ("A", "");
    Compare ("A", "A");
    Compare ("abc", "abc");
    Compare ("abc", "abe");
    Compare ("abe", "abc");
  END Test;

END LibStringsCompare1.
