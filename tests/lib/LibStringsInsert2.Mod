MODULE LibStringsInsert2;

IMPORT
  Out := Out0, Strings;

PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    dest4[0] := "a"; dest4[1] := 0X;
    Strings.Insert ("b", 2, dest4);
    Out.String (dest4); Out.Ln;
    Strings.Insert ("b", 16, dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsInsert2.
