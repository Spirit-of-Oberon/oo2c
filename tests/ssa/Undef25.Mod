MODULE Undef25;

TYPE
  R = RECORD
    a: INTEGER;
  END;
  
PROCEDURE P*();
  VAR
    r: R;

  PROCEDURE N(VAR x: R);
    BEGIN
      x.a := 1;
    END N;
  
  BEGIN
    N(r);
  END P;

END Undef25.
