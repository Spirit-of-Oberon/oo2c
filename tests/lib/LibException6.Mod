MODULE LibException6;

IMPORT
  Exception;

PROCEDURE Test*();
  BEGIN
    TRY
    CATCH Exception.ExceptionDesc:
    END;
  END Test;

END LibException6.
