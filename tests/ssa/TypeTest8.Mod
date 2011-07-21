MODULE TypeTest8;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END;   P0 = POINTER TO R0;
  R1 = RECORD (R0) END;   P1 = POINTER TO R1;

PROCEDURE Write (p: P0);
  VAR
    x: INTEGER;
  BEGIN
    IF (p IS P1) THEN
      Out.String ("P2");
    END;
    Out.Ln;
  END Write;

PROCEDURE Test*;
  BEGIN
    Write(NIL);
  END Test;

END TypeTest8.
