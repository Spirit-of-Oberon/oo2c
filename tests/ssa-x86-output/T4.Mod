MODULE T4;

PROCEDURE f*(select: BOOLEAN; a, b: LONGINT): LONGINT;
  VAR
    x: LONGINT;
  BEGIN
    IF select THEN
      x := a+b;
    ELSE
      x := a-b;
    END;
    RETURN x;
  END f;

END T4.
