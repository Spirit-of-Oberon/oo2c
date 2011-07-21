MODULE LibException37;

IMPORT
  Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.CheckedDesc)
  END;
  
PROCEDURE Test*();
  BEGIN
    RAISE(NEW(E, "checked"));
  END Test;

END LibException37.
