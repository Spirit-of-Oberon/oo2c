MODULE NoDescriptor2;

TYPE
  R* = RECORD [NO_DESCRIPTOR]
    a*: INTEGER;
  END;

PROCEDURE P* (VAR r: R);
  BEGIN
    IF r IS R THEN
    END;
  END P;

END NoDescriptor2.
