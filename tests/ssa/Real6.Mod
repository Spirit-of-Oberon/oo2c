MODULE Real6;

IMPORT Out:=Out0;

VAR
  a, b: REAL;
  
PROCEDURE Print(x: REAL);
  BEGIN
    Out.Real(x, 3); Out.Ln;
  END Print;

PROCEDURE Id(x: REAL): REAL;
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
END Real6.
