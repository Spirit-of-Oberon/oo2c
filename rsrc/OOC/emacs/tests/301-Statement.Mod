MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    IF (x < 0) THEN
      RETURN -1;
    ELSIF (x = 0) THEN
      RETURN 0;
    ELSE
      RETURN 1;
    END;
    x := 123;
  END P;

END M.
