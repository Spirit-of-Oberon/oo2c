MODULE T6;

PROCEDURE f*(a, b: BOOLEAN): LONGINT;
  BEGIN
    IF a & b THEN
      RETURN 9;
    ELSE
      RETURN -9;
    END;
  END f;

END T6.
