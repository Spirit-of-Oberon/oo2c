MODULE OpTypeGuard1;

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

PROCEDURE TestPointer(a : A);
BEGIN
  a.Do;
  a(B).Do;
END TestPointer;

PROCEDURE (VAR a : ADesc) DoVar;
BEGIN
  Out.String("ADesc:DoVar"); Out.Ln;
END DoVar;

PROCEDURE (VAR b : BDesc) DoVar;
BEGIN
  Out.String("BDesc:DoVar"); Out.Ln;
END DoVar;

PROCEDURE TestVar(VAR a : ADesc);
BEGIN
  a.DoVar;
  a(BDesc).DoVar;
END TestVar;

PROCEDURE TestPointer2(a : A);
BEGIN
  a^.DoVar;
  a^(BDesc).DoVar;
END TestPointer2;

PROCEDURE Test*;
VAR
  b : B;
  bDesc : BDesc;
BEGIN
  NEW(b);
  TestPointer(b);
  TestPointer2(b);
  TestVar(bDesc);
END Test;

END OpTypeGuard1.

