MODULE LibException7;

IMPORT
  Exception;

PROCEDURE Test*();
  VAR
    e: Exception.Exception;
  BEGIN
    TRY
    CATCH e:
    END;
  END Test;

END LibException7.
