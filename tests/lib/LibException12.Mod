MODULE LibException12;

IMPORT
  Out:=Out0, Exception;

TYPE
  One = POINTER TO OneDesc;
  OneDesc = RECORD (Exception.ExceptionDesc) END;
  
PROCEDURE NewException(): Exception.Exception;
  VAR
    e1: One;
  BEGIN
    NEW(e1);
    e1.INIT("Exception message");
    RETURN e1;
  END NewException;

PROCEDURE Test*() RAISES Exception.Exception;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    TRY
      i := 1;
      Exception.Raise(NewException());
    CATCH One:
    END;
    Out.String("Top-level... "); Out.Int(i, 0); Out.Ln;
  END Test;

END LibException12.
