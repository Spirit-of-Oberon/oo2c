MODULE TBProc5;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END; P0 = POINTER TO R0;
  R1 = RECORD (R0) END; P1 = POINTER TO R1;
  
PROCEDURE (p: P0) Proc ();
  BEGIN
    Out.String ("Proc.P0"); Out.Ln;
  END Proc;

PROCEDURE (p: P1) Proc ();
  BEGIN
    Out.String ("Proc.P1"); Out.Ln;
  END Proc;

PROCEDURE Call (p: P0);
  BEGIN
    p. Proc
  END Call;

PROCEDURE Test* ();
  VAR
    p0: P0;
    p1: P1;
  BEGIN
    NEW (p0); p0. Proc(); Call (p0);
    NEW (p1); p1. Proc(); Call (p1);
  END Test;

END TBProc5.
