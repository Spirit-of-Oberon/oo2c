MODULE Real5;

IMPORT Out:=Out0;

VAR
  a, b: REAL;
  
PROCEDURE Print(x: REAL);
  BEGIN
    Out.Real(x, 3); Out.Ln;
  END Print;

PROCEDURE Add(a, b: REAL): REAL;
  BEGIN
    RETURN a+b;
  END Add;

PROCEDURE Sub(a, b: REAL): REAL;
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
END Real5.
