MODULE LibException17;

TYPE
  Exception* = POINTER TO CheckedDesc;
  CheckedDesc = RECORD
  END;

PROCEDURE P() RAISES Exception;
  END P;

END LibException17.
