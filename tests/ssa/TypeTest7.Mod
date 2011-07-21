MODULE TypeTest7;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END;   P0 = POINTER TO R0;
  R1 = RECORD      END;   P1 = POINTER TO R1;

PROCEDURE Write (p: P0);
  VAR
    x: INTEGER;
  BEGIN
    IF (p IS P1) THEN
      Out.String ("P2");
    END;
    Out.Ln;
  END Write;

END TypeTest7.
