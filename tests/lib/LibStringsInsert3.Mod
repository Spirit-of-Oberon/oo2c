MODULE LibStringsInsert3;

IMPORT
  Out := Out0, Strings;

PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    dest4[0] := "b"; dest4[1] := "c"; dest4[2] := "X"; dest4[3] := 0X;
    Strings.Insert ("a", 0, dest4);
    Out.String (dest4); Out.Ln;
    dest4[0] := "a"; dest4[1] := "b"; dest4[2] := "X"; dest4[3] := 0X;
    Strings.Insert ("cY", 2, dest4);
    Out.String (dest4); Out.Ln;
    dest4[0] := "a"; dest4[1] := "b"; dest4[2] := "c"; dest4[3] := 0X;
    Strings.Insert ("X", 3, dest4);
    Out.String (dest4); Out.Ln;
  END Test;

END LibStringsInsert3.
