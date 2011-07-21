MODULE L1;

PROCEDURE f*(VAR str: ARRAY OF CHAR): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    LOOP
      IF (str[i] = 0X) THEN
        EXIT;
      END;
      i := i+1;
    END;
    RETURN i;
  END f;

END L1.
