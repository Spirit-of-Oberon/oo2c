MODULE Array8;

IMPORT Out := Out0;

TYPE
  I = SHORTINT;
  
PROCEDURE WriteVar (VAR a: ARRAY OF I);
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    WHILE (i # LEN(a)) DO
      Out.Int (a[i], 2);
      INC (i);
    END;
    Out.Ln;
  END WriteVar;

PROCEDURE WriteValue (a: ARRAY OF I);
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

PROCEDURE Test* ();
  VAR
    a: POINTER TO ARRAY OF ARRAY OF I;
  BEGIN
    NEW (a, 2, 3);
    a[0,0] := 1; a[0,1] := 2; a[0,2] := 3;
    a[1,0] := 4; a[1,1] := 5; a[1,2] := 6;
    WriteVar   (a[0]); WriteVar   (a[1]); Out.Ln;
    WriteValue (a[0]); WriteValue (a[1]); Out.Ln;
  END Test;

END Array8.
