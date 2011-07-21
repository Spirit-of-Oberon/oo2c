MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    CASE x OF
    | 0..9:
      RETURN 1;
    | 9..99:
      RETURN 2;
    END;
    x := 123;
  END P;

END M.
