MODULE LibException30;

IMPORT
  Out:=Out0, Object, Exception;

TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.ExceptionDesc)
    x: INTEGER;
  END;

PROCEDURE (e: E) INIT*(x: INTEGER);
  BEGIN
    e.INIT^("msg");
    e.x := x;
  END INIT;

PROCEDURE P() RAISES Exception.Exception;
  VAR
    msg: STRING;
    msg8: Object.String8;
    chars: Object.CharsLatin1;
  BEGIN
    TRY
      Out.String("In P..."); Out.Ln;
      RAISE(NEW(E, 123));
      Out.String("Still in P..."); Out.Ln;
    CATCH E(e):
      Out.String("In CATCH of P...");
      Out.Ln;
      Out.Int(e.x, 0);
      Out.Ln;
      RAISE(e);      
    CATCH Exception.Exception:
      ASSERT(FALSE);
    END;
    Out.String("End of P..."); Out.Ln;
  END P;

PROCEDURE Test*();
  BEGIN
    TRY
      P;
    CATCH Exception.Exception:
    END;
  END Test;

END LibException30.
