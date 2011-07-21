MODULE Real7;

IMPORT Out:=Out0;

VAR
  a, b: REAL;
  
PROCEDURE Cmp(a, b: REAL);
  BEGIN
    IF (a < b) THEN
      Out.String("lss");
    ELSIF (a > b) THEN
      Out.String("gtr");
    ELSE
      Out.String("eql");
    END;
    Out.Ln;
  END Cmp;

PROCEDURE Test*();
  BEGIN
    Cmp(3, 5);
    Cmp(5, 3);
    Cmp(7, 7);
  END Test;

END Real7.
