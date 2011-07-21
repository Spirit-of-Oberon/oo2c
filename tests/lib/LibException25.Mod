MODULE LibException25;

IMPORT
  Out:=Out0, Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
  END;
  
PROCEDURE NewException(): E;
  VAR
    e: E;
  BEGIN
    NEW(e);
    RETURN e;
  END NewException;

PROCEDURE Test*();
  BEGIN
    RAISE(NewException());
  END Test;

END LibException25.
