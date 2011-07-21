MODULE LibException27;

IMPORT
  Exception;
  
PROCEDURE P*(x: INTEGER) RAISES Exception.Exception;
  VAR
    y: INTEGER;
  BEGIN
    x := 1; y := 2;
    TRY
      x := 3; y := 4;
      Exception.Raise(NIL);
    END;
  END P;

END LibException27.
