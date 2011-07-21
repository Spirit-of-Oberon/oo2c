MODULE Undef2;

TYPE
  R = RECORD
    a*, b*: INTEGER;
  END;
  
PROCEDURE P*(): INTEGER;
  VAR
    r: R;
  BEGIN
    r.a := 1;
    RETURN r.a;
  END P;

END Undef2.
