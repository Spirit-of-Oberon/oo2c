MODULE LongReal6;

IMPORT Out:=Out0;

VAR
  a, b: LONGREAL;
  
PROCEDURE Print(x: LONGREAL);
  BEGIN
    Out.LongReal(x, 3); Out.Ln;
  END Print;

PROCEDURE Id(x: LONGREAL): LONGREAL;
  BEGIN
    RETURN x;
  END Id;

PROCEDURE Test*();
  BEGIN
    Print(Id(a)+b);
    Print(Id(a)-b);
  END Test;

BEGIN
  a := 2; b := 3;
END LongReal6.
