MODULE Undef19;

PROCEDURE P*(): INTEGER;
  VAR
    x: INTEGER;
    
  PROCEDURE N(VAR z: INTEGER; b: BOOLEAN);
    BEGIN
      IF b THEN
        z := 123;
      END;
    END N;
  
  BEGIN
    N(x, FALSE);
    RETURN x;
  END P;

END Undef19.
