MODULE With2;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      a: INTEGER; END;   P0 = POINTER TO R0;
  R1 = RECORD (R0) b: INTEGER; END;   P1 = POINTER TO R1;
  R2 = RECORD (R1) c: INTEGER; END;   P2 = POINTER TO R2;

PROCEDURE Write (p: P0);
  BEGIN
    WITH p: P2 DO
      Out.String ("P2, c="); Out.Int (p.c, 0);
    | p: P1 DO
      Out.String ("P1, b="); Out.Int (p.b, 0);
    ELSE
      Out.String ("P0, a="); Out.Int (p.a, 0);
    END;
    Out.Ln;
  END Write;

PROCEDURE Test* ();
  VAR
    p0: P0; p1: P1; p2: P2;
  BEGIN
    NEW (p0); p0.a := 0; Write (p0);
    NEW (p1); p1.b := 1; Write (p1);
    NEW (p2); p2.c := 2; Write (p2);
  END Test;

END With2.
