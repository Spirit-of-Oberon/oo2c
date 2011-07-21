MODULE Real4;

IMPORT Out:=Out0;

VAR
  a, b: REAL;
  
PROCEDURE Print(x: REAL);
  BEGIN
    Out.Real(x, 3); Out.Ln;
  END Print;

PROCEDURE Test*();
  BEGIN
    Print(a+b);
    Print(a-b);
  END Test;

BEGIN
  a := 2; b := 3;
END Real4.
