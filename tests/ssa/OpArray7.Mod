MODULE OpArray7;

PROCEDURE P(VAR x: ARRAY OF INTEGER; n: INTEGER): INTEGER;
  BEGIN
    <*IndexCheck:=TRUE*>
    RETURN x[n];
  END P;

PROCEDURE Test*;
  VAR
    y: INTEGER;
    a: ARRAY 10 OF INTEGER;
  BEGIN
    y := P(a, 10);
  END Test;

END OpArray7.
