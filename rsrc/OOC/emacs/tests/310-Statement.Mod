MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: P): INTEGER;
  BEGIN
    WITH x: T0 DO
      RETURN 0;
    | x: T1 DO
      RETURN 1;
    ELSE
      RETURN -1;
    END;
    x := 123;
  END P;

END M.
