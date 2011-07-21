MODULE OpArray9;

IMPORT
  Out := Out0;

PROCEDURE One(): INTEGER;
  BEGIN
    RETURN 1;
  END One;

PROCEDURE Test*;
  VAR
    a: ARRAY 3 OF INTEGER;
  BEGIN
    a[0] := 0; a[1] := 1; a[2] := 2;
    Out.Int (a[One()], 0); Out.Ln;
  END Test;

END OpArray9.
