MODULE Copy1;

IMPORT Out:=Out0;
  
VAR
  a4-: ARRAY 4 OF CHAR;
  a3-: ARRAY 3 OF CHAR;

PROCEDURE Test*;
  BEGIN
    COPY("abc", a4);
    Out.String(a4); Out.Ln;
    COPY(a4, a3);
    Out.String(a3); Out.Ln;
  END Test;

END Copy1.
