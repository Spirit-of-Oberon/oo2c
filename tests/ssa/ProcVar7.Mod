MODULE ProcVar7;

IMPORT
  Out:=Out0;

TYPE
  P = PROCEDURE(x: INTEGER);
  
PROCEDURE Iterate(a: ARRAY OF INTEGER; p: P);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN(a)-1 DO
      p(a[i]);
    END;
  END Iterate;

PROCEDURE Sum(a: ARRAY OF INTEGER): INTEGER;
  VAR
    sum: INTEGER;

  PROCEDURE Add(x: INTEGER);
    BEGIN
      INC(sum, x);
    END Add;
  
  BEGIN
    sum := 0;
    Iterate(a, Add);
    RETURN sum;
  END Sum;

PROCEDURE Test*();
  VAR
    a: ARRAY 3 OF INTEGER;
  BEGIN
    a[0] := 1; a[1] := 2; a[2] := 3;
    Out.Int(Sum(a), 0); Out.Ln;
  END Test;

END ProcVar7.
