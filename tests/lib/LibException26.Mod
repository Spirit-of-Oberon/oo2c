MODULE LibException26;

IMPORT
  Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.ExceptionDesc)
  END;
  F* = POINTER TO FDesc;
  FDesc = RECORD
    (Exception.ExceptionDesc)
  END;
  
PROCEDURE NewException(): E;
  VAR
    e: E;
  BEGIN
    NEW(e);
    e.INIT("Buh!");
    RETURN e;
  END NewException;

PROCEDURE A*();
  BEGIN
    TRY
      RAISE(NewException());
    CATCH Exception.Exception:
    CATCH E:                             (* unreachable *)
    END;
  END A;

PROCEDURE B*();
  BEGIN
    TRY
      RAISE(NewException());
    CATCH E:
    CATCH F:                             (* unreachable *)
    END;
  END B;

END LibException26.
