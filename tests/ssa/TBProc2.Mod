MODULE TBProc2;

IMPORT Out := Out0;

TYPE
  R = RECORD END;

PROCEDURE (VAR r: R) Proc ();
  BEGIN
    Out.String ("Hello World"); Out.Ln;
  END Proc;

PROCEDURE Test* ();
  VAR
    r: R;
  BEGIN
    r. Proc
  END Test;

END TBProc2.
