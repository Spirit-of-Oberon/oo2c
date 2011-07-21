MODULE Real1;

IMPORT Out:=Out0;

PROCEDURE Print(x: REAL);
  BEGIN
    Out.Real(x, 3); Out.Ln;
  END Print;

PROCEDURE Test*();
  BEGIN
    Print(1.0);
    Print(2.0);
    Print(-0.025);
  END Test;

END Real1.
