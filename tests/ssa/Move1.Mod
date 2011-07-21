MODULE Move1;

IMPORT SYSTEM, Out:=Out0;
  
PROCEDURE Test* ();
  VAR
    a, b: LONGINT;
  BEGIN
    a := 123; b := 456;
    SYSTEM.MOVE(SYSTEM.ADR(a), SYSTEM.ADR(b), SIZE(LONGINT));
    Out.Int(a, 0); Out.Ln;
    Out.Int(b, 0); Out.Ln;
  END Test;

END Move1.
