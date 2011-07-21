MODULE Undef20;

PROCEDURE P*(): INTEGER;
  VAR
    y, x: INTEGER;

  PROCEDURE Q(): INTEGER;
    PROCEDURE N(): INTEGER;
      BEGIN
        RETURN x;
      END N;
    
    BEGIN
      RETURN N();
    END Q;
  
  BEGIN
    y := Q();
    x := 1;
    RETURN Q();
  END P;

END Undef20.
