MODULE With7;

TYPE
  R0 = RECORD      a: INTEGER; END;   P0 = POINTER TO R0;
  R1 = RECORD      b: INTEGER; END;   P1 = POINTER TO R1;
  
PROCEDURE Write (r: R0);
  BEGIN
    WITH r: R1 DO
    END;
  END Write;

END With7.
