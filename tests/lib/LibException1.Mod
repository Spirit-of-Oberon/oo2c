MODULE LibException1;

IMPORT
  Out:=Out0, Exception;

PROCEDURE NewException(): Exception.Exception;
  VAR
    e: Exception.Exception;
  BEGIN
    NEW(e);
    e.INIT("Exception message");
    RETURN e;
  END NewException;

PROCEDURE Test*();
  BEGIN
    Out.String("Before TRY..."); Out.Ln;
    TRY
      Out.String("In TRY..."); Out.Ln;
      Exception.Raise(NewException());
      Out.String("Still TRY..."); Out.Ln;
    CATCH Exception.Exception:
      Out.String("In CATCH...");
      Out.Ln;
    END;
    Out.String("Behind TRY..."); Out.Ln;
  END Test;

END LibException1.
