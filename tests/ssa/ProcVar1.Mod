MODULE ProcVar1;

IMPORT Out := Out0;

TYPE
  P = PROCEDURE;
  
VAR
  p: P;

PROCEDURE A ();
  BEGIN
    Out.String ("A"); Out.Ln;
  END A;

PROCEDURE B ();
  BEGIN
    Out.String ("B"); Out.Ln;
  END B;

PROCEDURE Call (p: P);
  BEGIN
    p;
  END Call;

PROCEDURE Test* ();
  BEGIN
    Call (A);
    Call (B);
  END Test;

END ProcVar1.
