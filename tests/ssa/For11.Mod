MODULE For11;

PROCEDURE Test*;
  VAR
    c, i, j: LONGINT;
  BEGIN
    c := 0;
    FOR i := 0 TO 1 DO
      FOR j := 0 TO i DO
        INC (c)
      END
    END;
    ASSERT (c = 3);
  END Test;

END For11.
