MODULE HOTBaselineOutput3;  (* mva *)

IMPORT Out := Out0;

PROCEDURE WriteBatch (n: INTEGER);
  BEGIN
    Out.Int (-123, n); Out.Ln;
    Out.Int (-1, n); Out.Ln;
    Out.Int (0, n); Out.Ln;
    Out.Int (1, n); Out.Ln;
    Out.Int (123, n); Out.Ln;
  END WriteBatch;

PROCEDURE Test*;
  BEGIN
    WriteBatch (0);
    WriteBatch (3);
    WriteBatch (6);
  END Test;

END HOTBaselineOutput3.
