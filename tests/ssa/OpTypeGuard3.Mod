MODULE OpTypeGuard3;

IMPORT Out := Out0;

TYPE

  A = POINTER TO ADesc; ADesc = RECORD END;

  B = POINTER TO BDesc; BDesc = RECORD (ADesc) END;

  C = POINTER TO CDesc; CDesc = RECORD END;

PROCEDURE (a : A) Do;
BEGIN
  Out.String("A:Do"); Out.Ln;
END Do;

PROCEDURE (b : B) Do;
BEGIN
  Out.String("B:Do"); Out.Ln;
END Do;


PROCEDURE Test*;
VAR
  a : A;
  b : B;
BEGIN
  NEW(b);
  a := b;

  a.Do;
  a(C).Do;
END Test;

END OpTypeGuard3.

