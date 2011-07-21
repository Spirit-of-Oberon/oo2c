MODULE TypeTest4;

IMPORT Out := Out0;

TYPE
  R0 = RECORD      END;
  R1 = RECORD (R0) END;
  R2 = RECORD (R1) END;

PROCEDURE Write (VAR r: R0);
  BEGIN
    IF (r IS R2) THEN
      Out.String ("R2");
    ELSIF (r IS R1) THEN
      Out.String ("R1");
    ELSE
      Out.String ("R0");
    END;
    Out.Ln;
  END Write;

PROCEDURE Test* ();
  VAR
    r0: R0; r1: R1; r2: R2;
  BEGIN
    Write (r0);
    Write (r1);
    Write (r2);
  END Test;

END TypeTest4.
