MODULE TBProc10;

IMPORT
  Out:=Out0;
  
TYPE
  R0 = RECORD      END; P0 = POINTER TO R0;
  R1 = RECORD (R0) END; P1 = POINTER TO R1;
  
PROCEDURE (p: P0) Proc ();
  BEGIN
    Out.String("P0.Proc");
  END Proc;

PROCEDURE (p: P1) ProcX ();
  BEGIN
    p.Proc^; Out.Ln;
  END ProcX;

PROCEDURE (p: P1) Proc ();
  BEGIN
    Out.String("P1.Proc");
  END Proc;

PROCEDURE Test*();
  VAR
    p: P1;
  BEGIN
    NEW(p);
    p.ProcX();
  END Test;

END TBProc10.
