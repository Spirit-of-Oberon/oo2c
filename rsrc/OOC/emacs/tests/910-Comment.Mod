MODULE M;  (* -*-Mode: oberon-2-*- *)

IMPORT
  X;

PROCEDURE P(VAR x: INTEGER);
  BEGIN
    WHILE (x < 0) DO
      (* furbie 1 *)
      x := 123;
      (* furbie 2 *)
    END;
  END P;

END M.
