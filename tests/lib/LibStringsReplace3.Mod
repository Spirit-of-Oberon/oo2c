MODULE LibStringsReplace3;

IMPORT
  Out := Out0, Strings;

PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    dest4[0] := "a"; dest4[1] := "b"; dest4[2] := 0X;
    Strings.Replace ("BC", 1, dest4);
    Out.String (dest4); Out.Ln;
    dest4[0] := "a"; dest4[1] := "b"; dest4[2] := "c"; dest4[3] := 0X;
    Strings.Replace ("CD", 2, dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsReplace3.
