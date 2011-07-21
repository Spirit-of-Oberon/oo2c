MODULE Undef4;

PROCEDURE P*(b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    IF b THEN
    ELSE
      x := 1;
    END;
    RETURN x;
  END P;

END Undef4.
