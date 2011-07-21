MODULE Undef5;

PROCEDURE P*(b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    IF b THEN
      x := 1;
    ELSE
      x := 2;
    END;
    RETURN x;
  END P;

END Undef5.
