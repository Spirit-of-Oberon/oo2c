MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x, y: INTEGER): INTEGER;
  BEGIN
    WHILE (x < 0) &
          (y < 0) DO
      INC(x);
    END;
  END P;

END M.
