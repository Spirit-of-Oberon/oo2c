MODULE LibStringsInsert1;

IMPORT
  Out := Out0, Strings;

PROCEDURE Insert (source, dest: ARRAY OF CHAR; startPos: INTEGER);
  BEGIN
    Out.String ("src:"); Out.String (source); Out.Ln;
    Out.String ("in :"); Out.String (dest); Out.Ln;
    Strings.Insert (source, startPos, dest);
    Out.String ("out:"); Out.String (dest); Out.Ln;
  END Insert;

PROCEDURE Test* ();
  VAR
    dest4: ARRAY 4 OF CHAR;
  BEGIN
    dest4[0] := 0X;
    Insert ("abc", dest4, 0);
    dest4[0] := "a"; dest4[1] := 0X;
    Insert ("bc", dest4, 1);
    dest4[0] := "c"; dest4[1] := 0X;
    Insert ("ab", dest4, 0);
    dest4[0] := "a"; dest4[1] := "c"; dest4[2] := 0X;
    Insert ("b", dest4, 1);
  END Test;

END LibStringsInsert1.
