MODULE Const5;

IMPORT Out:=Out0;

<*CaseSelectCheck:=TRUE*>
PROCEDURE Test* ();
  BEGIN
    CASE 10 OF
    | 0..2:
      Out.String ("foo");
      RETURN;
    ELSE
    END;
    Out.String ("bar");
    Out.Ln;
  END Test;

END Const5.
