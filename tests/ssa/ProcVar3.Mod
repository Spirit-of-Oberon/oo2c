MODULE ProcVar3;

IMPORT Out := Out0;

TYPE
  P = PROCEDURE (c: CHAR): CHAR;
  
PROCEDURE Id (c: CHAR): CHAR;
  BEGIN
    RETURN c;
  END Id;

PROCEDURE Cap (c: CHAR): CHAR;
  BEGIN
    RETURN CAP (c);
  END Cap;

PROCEDURE Call (p: P);
  BEGIN
    Out.Char (p("a")); Out.Ln;
  END Call;

PROCEDURE Test* ();
  BEGIN
    Call (Id);
    Call (Cap);
  END Test;

END ProcVar3.
