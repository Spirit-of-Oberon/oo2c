MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    REPEAT
      INC(i);
    UNTIL (i > 0);
    x := 123;
  END P;

END M.
