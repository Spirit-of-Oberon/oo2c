MODULE OpPointer3;

IMPORT Out := Out0;

TYPE
  A = POINTER TO ADesc;
  ADesc = RECORD END;

  B = POINTER TO BDesc;
  BDesc = RECORD (ADesc) END;

PROCEDURE (a : A) P;
BEGIN
  Out.String("A.P"); Out.Ln;
END P;

PROCEDURE (b : B) P;
BEGIN
  b.P^();
  Out.String("B.P"); Out.Ln;
END P;

PROCEDURE Test*;
VAR b : B;
BEGIN
  NEW(b);
  b.P;
END Test;
  
END OpPointer3.
