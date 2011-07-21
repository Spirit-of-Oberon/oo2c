MODULE LibException2;

IMPORT
  Out:=Out0, Exception;

TYPE
  One = POINTER TO OneDesc;
  OneDesc = RECORD (Exception.CheckedDesc) END;
  Two = POINTER TO TwoDesc;
  TwoDesc = RECORD (Exception.CheckedDesc) END;
  Three = POINTER TO ThreeDesc;
  ThreeDesc = RECORD (Exception.CheckedDesc) END;
  
PROCEDURE NewException(x: SHORTINT): Exception.Exception;
  VAR
    e1: One;
    e2: Two;
    e3: Three;
    e: Exception.Exception;
  BEGIN
    CASE x OF
    | 1: NEW(e1); e := e1;
    | 2: NEW(e2); e := e2;
    | 3: NEW(e3); e := e3;
    END;
    e.INIT("Exception message");
    RETURN e;
  END NewException;

PROCEDURE P(x: SHORTINT);
  PROCEDURE Raise(x: SHORTINT) RAISES Exception.Exception;
    BEGIN
      Exception.Raise(NewException(x));
    END Raise;
  
  BEGIN
    Out.String("Before TRY..."); Out.Ln;
    TRY
      Out.String("In TRY..."); Out.Ln;
      Raise(x);
      Out.String("Still TRY..."); Out.Ln;
    CATCH One:
      Out.String("One..."); Out.Ln;
    CATCH Two:
      Out.String("Two..."); Out.Ln;
    CATCH Three:
      Out.String("Three..."); Out.Ln;
    CATCH Exception.Exception:
      Out.String("Oops"); Out.Ln;
    END;
    Out.String("Behind TRY..."); Out.Ln;
    Out.Ln;
  END P;

PROCEDURE Test*();
  VAR
    x: SHORTINT;
  BEGIN
    FOR x := 1 TO 3 DO
      P(x);
    END;
  END Test;

END LibException2.
