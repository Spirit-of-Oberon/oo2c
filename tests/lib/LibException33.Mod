MODULE LibException33;

IMPORT
  Out:=Out0, Exception;

VAR
  one, two: STRING;

PROCEDURE Write(msg: STRING);
  BEGIN
    IF (msg = NIL) THEN
      Out.String("NIL");
    ELSIF (msg = one) THEN
      Out.String("one");
    ELSIF (msg = two) THEN
      Out.String("two");
    ELSE
      Out.String("???");
    END;
    Out.Ln;
  END Write;

PROCEDURE Test*();
  BEGIN
    Out.String(">>> start"); Out.Ln;
    TRY
      RAISE(NEW(Exception.Checked, one));
    CATCH Exception.Exception(e):
      Write(e.GetMessage());
      TRY
        RAISE(NEW(Exception.Checked, two));
      CATCH Exception.Exception:
        Write(e.GetMessage());
      END;
      Write(e.GetMessage());
    END;
  END Test;

BEGIN
  one := "one";
  two := "two";
END LibException33.
