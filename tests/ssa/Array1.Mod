MODULE Array1;

IMPORT Out := Out0;

TYPE
  I = SHORTINT;
  
VAR
  a: ARRAY 3 OF I;
  
PROCEDURE SumVar (VAR a: ARRAY OF I): INTEGER;
  VAR
    i, sum: INTEGER;
  BEGIN
    sum := 0;
    i := 0;
    WHILE (i # LEN(a)) DO
      sum := sum+a[i];
      INC (i);
    END;
    RETURN sum
  END SumVar;

PROCEDURE SumValue (a: ARRAY OF I): INTEGER;
  VAR
    i, sum: INTEGER;
  BEGIN
    sum := 0;
    i := 0;
    WHILE (i # LEN(a)) DO
      sum := sum+a[i];
      INC (i);
    END;
    RETURN sum
  END SumValue;

PROCEDURE Test* ();
  BEGIN
    a[0] := 1; a[1] := 2; a[2] := 3;
    Out.Int (SumVar (a), 0); Out.Ln;
    Out.Int (SumValue (a), 0); Out.Ln;
  END Test;

END Array1.
