MODULE Undef18;

PROCEDURE P*(): INTEGER;
  VAR
    y, x: INTEGER;
    
  PROCEDURE N(VAR z: INTEGER): INTEGER;
    BEGIN
      RETURN z;
    END N;
  
  BEGIN
    y := N(x);
    x := 1;
    RETURN N(x);
  END P;

END Undef18.
