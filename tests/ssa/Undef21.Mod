MODULE Undef21;

PROCEDURE P*(): INTEGER;
  VAR
    x: INTEGER;

  PROCEDURE Q();
    PROCEDURE N(b: BOOLEAN);
      BEGIN
        IF b THEN
          x := 123;
        END;
      END N;
    
    BEGIN
      N(FALSE);
    END Q;
  
  BEGIN
    Q();
    RETURN x;
  END P;

END Undef21.
