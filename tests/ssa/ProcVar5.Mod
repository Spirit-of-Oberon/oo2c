MODULE ProcVar5;

IMPORT Out := Out0;

TYPE
  T = ARRAY 1 OF INTEGER;
  P = PROCEDURE (source: T; VAR dest: T);

PROCEDURE Copy (source: T; VAR dest: T);
  BEGIN
    dest[0] := source[0];
  END Copy;

PROCEDURE Null (source: T; VAR dest: T);
  BEGIN
    dest[0] := 0;
  END Null;

PROCEDURE Call (p: P);
  VAR
    x, y: T;
  BEGIN
    x[0] := 1;
    p(x, y);
    Out.Int (y[0], 0); Out.Ln;
  END Call;

PROCEDURE Test* ();
  BEGIN
    Call (Null);
    Call (Copy);
  END Test;

END ProcVar5.
