MODULE LibStringsAppend1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Append (source, dest: ARRAY OF CHAR);
  BEGIN
    Strings.Append (source, dest);
    Out.String (dest); Out.Ln;
  END Append;

PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    dest4[0] := 0X;
    Append ("abc", dest4);
    dest4[0] := "a"; dest4[1] := "b"; dest4[2] := 0X;
    Append ("", dest4);
    Append ("c", dest4);
    dest4[0] := "a"; dest4[1] := "b"; dest4[2] := "c"; dest4[3] := 0X;
    Append ("X", dest4);
  END Test;

END LibStringsAppend1.
