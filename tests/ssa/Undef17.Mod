MODULE Undef17;

PROCEDURE P*(): INTEGER;
  VAR
    x: INTEGER;
    
  PROCEDURE N(b: BOOLEAN);
    BEGIN
      IF b THEN
        x := 123;
      END;
    END N;
  
  BEGIN
    N(FALSE);
    RETURN x;
  END P;

END Undef17.
