MODULE LongReal5;

IMPORT Out:=Out0;

VAR
  a, b: LONGREAL;
  
PROCEDURE Print(x: LONGREAL);
  BEGIN
    Out.LongReal(x, 3); Out.Ln;
  END Print;

PROCEDURE Add(a, b: LONGREAL): LONGREAL;
  BEGIN
    RETURN a+b;
  END Add;

PROCEDURE Sub(a, b: LONGREAL): LONGREAL;
  BEGIN
    RETURN a-b;
  END Sub;

PROCEDURE Test*();
  BEGIN
    Print(Add(a, b));
    Print(Sub(a, b));
  END Test;

BEGIN
  a := 2; b := 3;
END LongReal5.
