MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    CASE x OF
    | 0..9:
      IF ODD(x) THEN
        RETURN 1;
      ELSE
        RETURN 0;
      END;
    | 9..99:
      RETURN 2;
    ELSE
      RETURN -1;
    END;
    x := 123;
  END P;

END M.
