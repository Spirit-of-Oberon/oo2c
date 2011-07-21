MODULE T8b;

PROCEDURE f*(a, b, c: BOOLEAN): LONGINT;
  BEGIN
    IF a & (b OR c) THEN
      RETURN 9;
    ELSE
      RETURN -9;
    END;
  END f;

END T8b.
