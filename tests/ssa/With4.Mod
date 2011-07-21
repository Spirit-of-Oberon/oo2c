MODULE With4;

TYPE
  R0 = RECORD      a: INTEGER; END;   P0 = POINTER TO R0;
  R1 = RECORD (R0) b: INTEGER; END;   P1 = POINTER TO R1;

PROCEDURE Write (p, q: P0);
  BEGIN
    WITH p: P1 DO
      Write (q, q);
    END;
  END Write;

END With4.
