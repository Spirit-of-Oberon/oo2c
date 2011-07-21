MODULE Undef7;

PROCEDURE P*(b: BOOLEAN): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    LOOP
      IF b THEN
        x := 1;
        EXIT;
      ELSE
        x := 2;
        EXIT;
      END;
    END;
    RETURN x;
  END P;

END Undef7.
