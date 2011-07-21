MODULE MinMax5;

PROCEDURE Test*;
  TYPE
    P = POINTER TO ARRAY OF CHAR;
  VAR
    x: LONGINT;
  BEGIN
    x := MAX(P);
  END Test;

END MinMax5.
