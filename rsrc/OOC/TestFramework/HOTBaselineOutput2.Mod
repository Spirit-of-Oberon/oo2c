MODULE HOTBaselineOutput2;  (* mva *)

IMPORT Out;

PROCEDURE WriteBatch (n: SHORTINT);
  BEGIN
    Out.ShortInt (-123, n); Out.Ln;
    Out.ShortInt (-1, n); Out.Ln;
    Out.ShortInt (0, n); Out.Ln;
    Out.ShortInt (1, n); Out.Ln;
    Out.ShortInt (123, n); Out.Ln;
  END WriteBatch;

PROCEDURE Test*;
  BEGIN
    WriteBatch (0);
    WriteBatch (3);
    WriteBatch (6);
  END Test;

END HOTBaselineOutput2.
