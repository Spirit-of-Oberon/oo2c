MODULE LibException31;

IMPORT
  Out:=Out0, Exception;

PROCEDURE Test*();
  VAR
    bar: Exception.Exception;
  BEGIN
    TRY
      RAISE(NEW(Exception.Exception, "Jo!"));
    CATCH Exception.Exception(e):
      e := bar;
    END;
  END Test;

END LibException31.
