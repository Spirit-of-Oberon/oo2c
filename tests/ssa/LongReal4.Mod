MODULE LongReal4;

IMPORT Out:=Out0;

VAR
  a, b: LONGREAL;
  
PROCEDURE Print(x: LONGREAL);
  BEGIN
    Out.LongReal(x, 3); Out.Ln;
  END Print;

PROCEDURE Test*();
  BEGIN
    Print(a+b);
    Print(a-b);
  END Test;

BEGIN
  a := 2; b := 3;
END LongReal4.
