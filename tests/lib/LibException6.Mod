MODULE LibException6;

IMPORT
  Exception;

PROCEDURE Test*();
  BEGIN
    TRY
    CATCH Exception.CheckedDesc:
    END;
  END Test;

END LibException6.
