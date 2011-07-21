MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    LOOP
      INC(i);
      IF (i > 0) THEN
        EXIT;
      END;
    END;
    x := 123;
  END P;

END M.
