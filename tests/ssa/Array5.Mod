MODULE Array5;

IMPORT Out := Out0;

TYPE
  I = SHORTINT;
  
VAR
  a: ARRAY 2, 3 OF I;
  
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

PROCEDURE WriteArray (VAR a: ARRAY OF ARRAY OF I);
  BEGIN
    a[0,0] := 1; a[0,1] := 2; a[0,2] := 3;
    a[1,0] := 4; a[1,1] := 5; a[1,2] := 6;
    WriteVar   (a[0]); WriteVar   (a[1]); Out.Ln;
    WriteValue (a[0]); WriteValue (a[1]); Out.Ln;
  END WriteArray;

PROCEDURE Test* ();
  BEGIN
    WriteArray (a);
  END Test;

END Array5.
