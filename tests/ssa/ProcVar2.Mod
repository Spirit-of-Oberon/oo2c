MODULE ProcVar2;

IMPORT Out := Out0;

TYPE
  P = PROCEDURE (c: CHAR; VAR x: CHAR);
  
PROCEDURE Set (c: CHAR; VAR x: CHAR);
  BEGIN
    x := c;
  END Set;

PROCEDURE SetCap (c: CHAR; VAR x: CHAR);
  BEGIN
    x := CAP (c);
  END SetCap;

PROCEDURE Call (p: P);
  VAR
    out: CHAR;
  BEGIN
    p("a", out);
    Out.Char (out); Out.Ln;
  END Call;

PROCEDURE Test* ();
  BEGIN
    Call (Set);
    Call (SetCap);
  END Test;

END ProcVar2.
