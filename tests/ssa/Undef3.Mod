MODULE Undef3;

PROCEDURE P*(b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    IF b THEN
      x := 1;
    END;
    RETURN x;
  END P;

END Undef3.
