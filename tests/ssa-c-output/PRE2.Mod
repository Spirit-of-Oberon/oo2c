MODULE PRE2;
<*IndexCheck:=FALSE*>

PROCEDURE P(i: INTEGER; VAR a: ARRAY OF INTEGER): INTEGER;
  BEGIN
    IF (i < 0) THEN
      i := -i;
      a[i] := -i;
    ELSE
      a[i] := i;
    END;
    RETURN a[i];
  END P;

END PRE2.
