MODULE TypeTest6;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END;   P0 = POINTER TO R0;

PROCEDURE Write (p: P0);
  VAR
    x: P0;
  BEGIN
    IF (p IS x) THEN
      Out.String ("P2");
    END;
    Out.Ln;
  END Write;

END TypeTest6.
