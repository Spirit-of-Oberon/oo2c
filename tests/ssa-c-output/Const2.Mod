MODULE Const2;

IMPORT Out:=Out0;

PROCEDURE Test* ();
  BEGIN
    IF FALSE THEN
      Out.String ("foo");
      RETURN;
    END;
    Out.String ("bar");
    Out.Ln;
  END Test;

END Const2.
