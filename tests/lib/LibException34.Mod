MODULE LibException34;

IMPORT
  Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.UncheckedDesc)
  END;
  
PROCEDURE Test*();
  BEGIN
    RAISE(NEW(E, "unchecked"));
  END Test;

END LibException34.
