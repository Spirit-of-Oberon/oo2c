MODULE HOTBaselineOutput4;  (* mva *)

IMPORT Out;

PROCEDURE WriteBatch (n: LONGINT);
  BEGIN
    Out.LongInt (-123, n); Out.Ln;
    Out.LongInt (-1, n); Out.Ln;
    Out.LongInt (0, n); Out.Ln;
    Out.LongInt (1, n); Out.Ln;
    Out.LongInt (123, n); Out.Ln;
  END WriteBatch;

PROCEDURE Test*;
  BEGIN
    WriteBatch (0);
    WriteBatch (3);
    WriteBatch (6);
  END Test;

END HOTBaselineOutput4.
