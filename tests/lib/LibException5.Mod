MODULE LibException5;

IMPORT
  Out:=Out0, Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.ExceptionDesc) 
  END;
  
PROCEDURE Test*() RAISES Exception.Exception;
  PROCEDURE P() RAISES Exception.Exception;
    VAR
      e: Exception.Exception;
    BEGIN
      NEW(e);
      e.INIT("Some other exception");
      Exception.Raise(e);
    END P;
  
  BEGIN
    TRY
      P;
    CATCH E:
      Out.String("Catch..."); Out.Ln;
    END;
  END Test;

END LibException5.
