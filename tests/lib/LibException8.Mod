MODULE LibException8;

IMPORT
  Out:=Out0, Exception;

TYPE
  One = POINTER TO OneDesc;
  OneDesc = RECORD (Exception.CheckedDesc) END;
  
PROCEDURE NewException(): Exception.Exception;
  VAR
    e1: One;
  BEGIN
    NEW(e1);
    e1.INIT("Exception message");
    RETURN e1;
  END NewException;

PROCEDURE P() RAISES Exception.Exception;
  BEGIN
    LOOP
      Out.String("Before TRY..."); Out.Ln;
      TRY
        Out.String("EXIT..."); Out.Ln;
        EXIT;
      CATCH One:
        Out.String("Catch in LOOP..."); Out.Ln;
      END;
    END;
    Out.String("Behind LOOP..."); Out.Ln;
    Exception.Raise(NewException());
  END P;

PROCEDURE Test*() RAISES Exception.Exception;
  BEGIN
    TRY
      P;
    CATCH One:
      Out.String("Top-level CATCH..."); Out.Ln;
    END;
  END Test;

END LibException8.
