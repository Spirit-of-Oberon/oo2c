MODULE OpTypeGuard5;
   
IMPORT Out := Out0;

TYPE
  A = POINTER TO ADesc; ADesc = RECORD END;
  B = POINTER TO BDesc; BDesc* = RECORD (ADesc) END;

PROCEDURE (a : A) Do*;
BEGIN
  Out.String("A:Do"); Out.Ln;
END Do;

PROCEDURE (b : B) Do*;
BEGIN
  Out.String("B:Do"); Out.Ln;
END Do;


PROCEDURE Test*;
VAR
  a : A;
BEGIN
  a := NIL;
  a(B).Do;
END Test;

END OpTypeGuard5.
