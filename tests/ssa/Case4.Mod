MODULE Case4;

PROCEDURE P (i, j: INTEGER);
  BEGIN
    CASE i OF
    | 1..j: (* nothing *)
    END;
  END P;

END Case4.
