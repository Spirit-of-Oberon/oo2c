MODULE T3;

PROCEDURE f*(select: BOOLEAN; a, b: LONGINT): LONGINT;
  BEGIN
    IF select THEN
      RETURN a+b;
    ELSE
      RETURN a-b;
    END;
  END f;

END T3.
