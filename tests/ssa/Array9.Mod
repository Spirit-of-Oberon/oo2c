MODULE Array9;

IMPORT Out := Out0;

PROCEDURE WriteValue (a: ARRAY OF INTEGER);
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    WHILE (i # LEN(a)) DO
      Out.Int (a[i], 2);
      INC (i);
    END;
    Out.Ln;
  END WriteValue;

PROCEDURE P (a: ARRAY OF INTEGER);
  BEGIN
    a[0] := 3; a[1] := 4;
  END P;

PROCEDURE Test* ();
  VAR
    a: ARRAY 2 OF INTEGER;
  BEGIN
    a[0] := 1; a[1] := 2;
    WriteValue (a);
    P(a);
    WriteValue (a);
  END Test;

END Array9.
