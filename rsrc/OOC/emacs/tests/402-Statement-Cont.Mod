MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x, y: INTEGER): INTEGER;
  BEGIN
    IF (x < 0) &
       (y < 0) THEN
      RETURN -1;
    ELSIF (x > 0) &
          (y > 0) THEN
      RETURN 1;
    ELSE
      RETURN 0;
    END;
  END P;

END M.
