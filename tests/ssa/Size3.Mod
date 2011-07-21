MODULE Size3;

PROCEDURE P;
  TYPE
    A = ARRAY OF CHAR;
  VAR
    y: LONGINT;
  BEGIN
    y := SIZE(A);
  END P;

END Size3.
