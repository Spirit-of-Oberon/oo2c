MODULE Array6;

IMPORT Out := Out0;

TYPE
  I = SHORTINT;
  A = ARRAY 3 OF I;
  P = POINTER TO A;
  
VAR
  p: P;
  
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

PROCEDURE SumPtr (p: P): INTEGER;
  VAR
    i, sum: INTEGER;
  BEGIN
    sum := 0;
    i := 0;
    WHILE (i # LEN(p^)) DO
      sum := sum+p[i];
      INC (i);
    END;
    RETURN sum
  END SumPtr;

PROCEDURE Test* ();
  BEGIN
    NEW (p);
    p[0] := 1; p[1] := 2; p[2] := 3;
    Out.Int (SumVar (p^), 0); Out.Ln;
    Out.Int (SumValue (p^), 0); Out.Ln;
    Out.Int (SumPtr (p), 0); Out.Ln;
  END Test;

END Array6.
