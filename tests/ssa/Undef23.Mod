MODULE Undef23;

PROCEDURE P*(): INTEGER;
  VAR
    x: INTEGER;

  PROCEDURE Q();
    PROCEDURE N(VAR z: INTEGER; b: BOOLEAN);
      BEGIN
        IF b THEN
          z := 123;
        END;
      END N;
    
    BEGIN
      N(x, FALSE);
    END Q;
  
  BEGIN
    Q();
    RETURN x;
  END P;

END Undef23.
