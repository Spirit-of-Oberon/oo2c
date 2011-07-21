MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    TRY
      x := 123;
    CATCH Exception.Checked:
      x := -1;
    END;
  END P;

END M.
