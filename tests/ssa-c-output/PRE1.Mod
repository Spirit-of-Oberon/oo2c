MODULE PRE1;
<*IndexCheck:=FALSE*>

PROCEDURE P(i: INTEGER; VAR a: ARRAY OF INTEGER): INTEGER;
  BEGIN
    IF (i < 0) THEN
      i := 0;
    ELSE
      a[i] := i;
    END;
    RETURN a[i];
  END P;

END PRE1.
