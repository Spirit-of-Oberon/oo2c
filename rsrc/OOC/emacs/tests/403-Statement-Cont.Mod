MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x, y: INTEGER): INTEGER;
  BEGIN
    CASE x OF
    | 123,
      456,
      789 .. 999,
      1000:
      y := 0;
    | 0 .. 99,
      199:
      y := 1
    END;
  END P;

END M.
