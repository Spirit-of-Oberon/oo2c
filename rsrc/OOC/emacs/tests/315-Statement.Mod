MODULE M;  (* -*-Mode: oberon-2-*- *)

PROCEDURE P(x: INTEGER): INTEGER;
  BEGIN
    TRY
      x := 123;
    CATCH Exception.Checked(e):
    CATCH Exception.Unchecked(e):
    END;
  END P;

END M.
