MODULE LibException31;

IMPORT
  Out:=Out0, Exception;

PROCEDURE Test*();
  VAR
    e: Exception.Exception;
  BEGIN
    TRY
      RAISE(NEW(Exception.Exception, "Jo!"));
    CATCH Exception.Exception:
      EXCEPTION := e;
    END;
  END Test;

END LibException31.
