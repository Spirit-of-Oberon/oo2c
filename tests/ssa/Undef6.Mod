MODULE Undef6;

PROCEDURE P*(b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    LOOP
      IF b THEN
        x := 1;
        EXIT;
      ELSE
        EXIT;
      END;
    END;
    RETURN x;
  END P;

END Undef6.
