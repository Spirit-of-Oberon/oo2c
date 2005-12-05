MODULE Lsh4;

IMPORT SYSTEM, Out:=Out0;

PROCEDURE Shift(i8: SHORTINT; n: LONGINT);
  BEGIN
    Out.Int (SYSTEM.LSH(i8, -1), 12); 
    Out.Ln;
  END Shift;
  
PROCEDURE Test*;
  VAR
    i8: SHORTINT;
  BEGIN
    i8 := -1;
    Out.Int (SYSTEM.LSH(i8, -1), 12); 
    Out.Ln;
    Shift(-1, -1);
  END Test;

END Lsh4.
