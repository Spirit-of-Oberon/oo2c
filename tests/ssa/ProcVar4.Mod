MODULE ProcVar4;

IMPORT Out := Out0;

TYPE
  T = RECORD a: INTEGER; END;
  P = PROCEDURE (source: T; VAR dest: T);

PROCEDURE Copy (source: T; VAR dest: T);
  BEGIN
    dest. a := source. a;
  END Copy;

PROCEDURE Null (source: T; VAR dest: T);
  BEGIN
    dest. a := 0;
  END Null;

PROCEDURE Call (p: P);
  VAR
    x, y: T;
  BEGIN
    x. a := 1;
    p(x, y);
    Out.Int (y. a, 0); Out.Ln;
  END Call;

PROCEDURE Test* ();
  BEGIN
    Call (Null);
    Call (Copy);
  END Test;

END ProcVar4.
