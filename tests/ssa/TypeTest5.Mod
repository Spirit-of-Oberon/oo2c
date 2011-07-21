MODULE TypeTest5;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END;   P0 = POINTER TO R0;

PROCEDURE Write (p: P0);
  BEGIN
    IF (p IS LONGINT) THEN
      Out.String ("P2");
    END;
    Out.Ln;
  END Write;

END TypeTest5.
