MODULE Undef16;

PROCEDURE P*(): INTEGER;
  VAR
    y, x: INTEGER;
    
  PROCEDURE N(): INTEGER;
    BEGIN
      RETURN x;
    END N;
  
  BEGIN
    y := N();
    x := 1;
    RETURN N();
  END P;

END Undef16.
