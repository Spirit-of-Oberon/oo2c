MODULE TBProc8;

IMPORT Out := Out0, TBProc1;

PROCEDURE Test* ();
  VAR
    p: TBProc1.P;
  BEGIN
    NEW (p);
    p. Proc();          (* should be rejected, Proc is not exported *)
  END Test;

END TBProc8.
