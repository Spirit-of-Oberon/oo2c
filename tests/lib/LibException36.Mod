MODULE LibException36;

IMPORT
  Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.UncheckedDesc)
  END;

PROCEDURE P();
  BEGIN
    RAISE(NEW(E, "unchecked"));
  END P;

PROCEDURE Test*();
  BEGIN
    TRY
      P();
    CATCH E:
      (* something *)
    END;
  END Test;

END LibException36.
