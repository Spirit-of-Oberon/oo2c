MODULE With3;

TYPE
  R0 = RECORD      a: INTEGER; END;   P0 = POINTER TO R0;
  R1 = RECORD (R0) b: INTEGER; END;   P1 = POINTER TO R1;

PROCEDURE Write (p: P0);
  BEGIN
    <*TypeGuard:=TRUE*>
    WITH p: P1 DO
      (* nothing *)
    END;
  END Write;

PROCEDURE Test* ();
  VAR
    p0: P0;
  BEGIN
    NEW (p0); Write (p0);
  END Test;

END With3.
