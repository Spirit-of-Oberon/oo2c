MODULE LibException3;

IMPORT
  Out:=Out0, Exception;

PROCEDURE Test*();
  BEGIN
    Out.String("Before TRY..."); Out.Ln;
    TRY
      Out.String("In TRY..."); Out.Ln;
    END;
    Out.String("Behind TRY..."); Out.Ln;
  END Test;

END LibException3.
