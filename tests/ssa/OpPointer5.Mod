MODULE OpPointer5;

IMPORT Out := Out0;

TYPE
  A = POINTER TO ADesc;
  ADesc = RECORD END;

  B = POINTER TO BDesc;
  BDesc = RECORD (ADesc) END;

  C = POINTER TO CDesc;
  CDesc = RECORD (BDesc) END;

PROCEDURE (a : A) P;
BEGIN
  Out.String("A.P"); Out.Ln;
END P;

PROCEDURE (b : B) P;
BEGIN
  b.P^();
  Out.String("B.P"); Out.Ln;
END P;

PROCEDURE (c : C) P;
BEGIN
  c.P^^();
  Out.String("C.P"); Out.Ln;
END P;

END OpPointer5.
