
MODULE OpRecord3;

TYPE
  T = POINTER TO TDesc;
  TDesc = RECORD
    i : INTEGER;
    c : CHAR;
  END;

PROCEDURE Test*;
VAR
  p : T;
BEGIN
  NEW(p);
  p.r := 0.0;
END Test;

END OpRecord3.
