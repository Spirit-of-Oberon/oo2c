MODULE LibException28;

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

PROCEDURE P() RAISES Exception.Exception;
  BEGIN
    TRY
      Out.String("In P..."); Out.Ln;
      RAISE(NewException());
      Out.String("Still in P..."); Out.Ln;
    CATCH Exception.Exception:
      Out.String("In CATCH of P...");
      Out.Ln;
      RAISE(Exception.Current());
    END;
    Out.String("End of P..."); Out.Ln;
  END P;

PROCEDURE Test*();
  BEGIN
    Out.String("Before TRY..."); Out.Ln;
    TRY
      Out.String("In TRY..."); Out.Ln;
      P();
      Out.String("Still TRY..."); Out.Ln;
    CATCH Exception.Exception:
      Out.String("In CATCH...");
      Out.Ln;
    END;
    Out.String("Behind TRY..."); Out.Ln;
  END Test;

END LibException28.
