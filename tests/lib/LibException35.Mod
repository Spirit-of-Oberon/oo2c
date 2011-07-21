MODULE LibException35;

IMPORT
  Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.UncheckedDesc)
  END;

PROCEDURE P() RAISES E;
  BEGIN
    RAISE(NEW(E, "unchecked"));
  END P;

PROCEDURE Test*();
  BEGIN
    P();
  END Test;

END LibException35.
