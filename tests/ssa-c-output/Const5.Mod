MODULE Const5;

IMPORT Out:=Out0;

PROCEDURE Test* ();
  BEGIN
    CASE 10 OF
    | 0..2:
      Out.String ("foo");
      RETURN;
    END;
    Out.String ("bar");
    Out.Ln;
  END Test;

END Const5.
