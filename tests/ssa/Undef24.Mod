MODULE Undef24;

PROCEDURE P*(): INTEGER;
  VAR
    x: INTEGER;

  PROCEDURE N(z: INTEGER);
    BEGIN
      IF (z = 0) THEN
        x := 123;
      ELSE
        N(z-1);
      END;
    END N;
  
  BEGIN
    N(8);
    RETURN x;
  END P;

END Undef24.
