MODULE TBProc9;

TYPE
  R0 = RECORD      END; P0 = POINTER TO R0;
  R1 = RECORD (R0) END; P1 = POINTER TO R1;
  
PROCEDURE (p: P0) Proc ();
  BEGIN
  END Proc;

PROCEDURE (p: P1) Proc ();
  BEGIN
  END Proc;

PROCEDURE (p: P1) ProcX ();
  BEGIN
    p.Proc^;
  END ProcX;

END TBProc9.
