MODULE TypeTest9;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END;   P0 = POINTER TO R0;
  R1 = RECORD (R0) END;   P1 = POINTER TO R1;

PROCEDURE Write (r: R0);
  BEGIN
    IF (r IS R1) THEN
      Out.String ("P2");
    END;
    Out.Ln;
  END Write;

END TypeTest9.
