MODULE Assign20;

IMPORT Out:=Out0;

TYPE
  R1 = RECORD a, b: SHORTINT; END;
  R2 = RECORD a, b: INTEGER; END;
  R4 = RECORD a, b: LONGINT; END;
  
VAR
  r1: R1;
  r2: R2;
  r4: R4;

PROCEDURE P1(VAR v1, v2: R1);
  BEGIN
    v1.a := 1;
    Out.Int(v2.a, 10);
    Out.Int(v2.b, 10);
    Out.Ln;
  END P1;

PROCEDURE P2(VAR v1, v2: R2);
  BEGIN
    v1.a := 258;
    Out.Int(v2.a, 10);
    Out.Int(v2.b, 10);
    Out.Ln;
  END P2;

PROCEDURE P4(VAR v1, v2: R4);
  BEGIN
    v1.a := 67371521;
    Out.Int(v2.a, 10);
    Out.Int(v2.b, 10);
    Out.Ln;
  END P4;

PROCEDURE Test*();
  BEGIN
    P1(r1, r1);
    P2(r2, r2);
    P4(r4, r4);
  END Test;

BEGIN
  r1.a := 0; r1.b := -1;
  r2.a := 0; r2.b := -1;
  r4.a := 0; r4.b := -1;
END Assign20.
