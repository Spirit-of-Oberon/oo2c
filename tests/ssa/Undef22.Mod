MODULE Undef22;

PROCEDURE P*(): INTEGER;
  VAR
    y, x: INTEGER;

  PROCEDURE Q(): INTEGER;
    PROCEDURE N(VAR z: INTEGER): INTEGER;
      BEGIN
        RETURN z;
      END N;
    
    BEGIN
      RETURN N(x);
    END Q;
  
  BEGIN
    y := Q();
    x := 1;
    RETURN Q();
  END P;

END Undef22.
