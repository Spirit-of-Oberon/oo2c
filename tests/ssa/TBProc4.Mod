MODULE TBProc4;

IMPORT Out := Out0;

TYPE
  R = RECORD END;
  P = POINTER TO R;

PROCEDURE (VAR r: R) Proc ();
  BEGIN
    Out.String ("Hello World"); Out.Ln;
  END Proc;

PROCEDURE Test* ();
  VAR
    p: P;
  BEGIN
    NEW (p);
    p. Proc();
  END Test;

END TBProc4.
