MODULE T6b;

PROCEDURE f*(a, b, c: BOOLEAN): LONGINT;
  BEGIN
    IF a & (b & c) THEN
      RETURN 9;
    ELSE
      RETURN -9;
    END;
  END f;

END T6b.
