MODULE T8d;

PROCEDURE f*(a, b, c: BOOLEAN): LONGINT;
  BEGIN
    IF a OR (b & c) THEN
      RETURN 9;
    ELSE
      RETURN -9;
    END;
  END f;

END T8d.
