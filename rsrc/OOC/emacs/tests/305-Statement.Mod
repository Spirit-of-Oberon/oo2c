MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    FOR i := 1 TO x BY 2 DO
      INC(x);
    END;
    x := 123;
  END P;

END M.
