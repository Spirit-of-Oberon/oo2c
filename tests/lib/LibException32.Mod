MODULE LibException32;

IMPORT
  Out:=Out0, Exception;

PROCEDURE Test*();
  VAR
    e: Exception.Exception;
  BEGIN
    TRY
      e := EXCEPTION;
      RAISE(NEW(Exception.Exception, "frobozz"));
    CATCH Exception.Exception:
    END;
  END Test;

END LibException32.
