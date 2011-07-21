MODULE With5;

TYPE
  R0 = RECORD      a: INTEGER; END;   P0 = POINTER TO R0;
  R1 = RECORD (R0) b: INTEGER; END;   P1 = POINTER TO R1;
  Record = RECORD p: P0; END;
  
PROCEDURE Write (r: Record);
  BEGIN
    WITH r.p: P1 DO
    END;
  END Write;

END With5.
