MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    WHILE (x < 0) DO
      INC(i);
    END;
    x := 123;
  END P;

END M.
