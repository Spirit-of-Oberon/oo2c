MODULE LibException17;

TYPE
  Exception* = POINTER TO ExceptionDesc;
  ExceptionDesc = RECORD
  END;

PROCEDURE P() RAISES Exception;
  END P;

END LibException17.
