MODULE LibException24;

IMPORT
  Out:=Out0, Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.ExceptionDesc) 
  END;
  
PROCEDURE NewException(): E;
  VAR
    e: E;
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
      RAISE(NewException());
      Out.String("Still TRY..."); Out.Ln;
    CATCH E:
      Out.String("In CATCH...");
      Out.Ln;
    END;
    Out.String("Behind TRY..."); Out.Ln;
  END Test;

END LibException24.
