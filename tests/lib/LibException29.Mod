MODULE LibException29;

IMPORT
  Out:=Out0, Object, Exception;

PROCEDURE NewException(): Exception.Exception;
  VAR
    e: Exception.Checked;
  BEGIN
    NEW(e);
    e.INIT("Exception message");
    RETURN e;
  END NewException;

PROCEDURE P() RAISES Exception.Exception;
  VAR
    msg: STRING;
    msg8: Object.String8;
    chars: Object.CharsLatin1;
  BEGIN
    TRY
      Out.String("In P..."); Out.Ln;
      RAISE(NewException());
      Out.String("Still in P..."); Out.Ln;
    CATCH Exception.Exception(e):
      Out.String("In CATCH of P...");
      Out.Ln;
      msg := e.GetMessage();
      msg8 := msg.ToString8("?");
      chars := msg8.CharsLatin1();
      Out.String(chars^);
      Out.Ln;
      RAISE(e);
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

END LibException29.
