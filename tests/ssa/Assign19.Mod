MODULE Assign19;

IMPORT Out:=Out0;

VAR
  r1: RECORD a, b: SHORTINT; END;
  r2: RECORD a, b: INTEGER; END;
  r4: RECORD a, b: LONGINT; END;

PROCEDURE P1();
  BEGIN
    Out.Int(r1.a, 10);
    Out.Int(r1.b, 10);
    Out.Ln;
  END P1;

PROCEDURE P2();
  BEGIN
    Out.Int(r2.a, 10);
    Out.Int(r2.b, 10);
    Out.Ln;
  END P2;

PROCEDURE P4();
  BEGIN
    Out.Int(r4.a, 10);
    Out.Int(r4.b, 10);
    Out.Ln;
  END P4;

PROCEDURE Test*();
  BEGIN
    r1.a := 1;
    P1();
    r2.a := 258;
    P2();
    r4.a := 67371521;
    P4();
  END Test;

BEGIN
  r1.a := 0; r1.b := -1;
  r2.a := 0; r2.b := -1;
  r4.a := 0; r4.b := -1;
END Assign19.
