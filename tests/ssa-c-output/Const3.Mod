MODULE Const3;

IMPORT Out:=Out0;

PROCEDURE P (b: BOOLEAN);
  BEGIN
    LOOP
      IF FALSE THEN
        Out.String ("foo");
        EXIT;
      ELSIF b THEN
        Out.String ("bar");
        EXIT;
      END;
    END;
  END P;

PROCEDURE Test* ();
  BEGIN
    P(TRUE);
    Out.Ln;
  END Test;

END Const3.
