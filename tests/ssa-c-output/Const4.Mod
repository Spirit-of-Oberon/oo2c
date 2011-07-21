MODULE Const4;

IMPORT Out:=Out0;

PROCEDURE P (b: BOOLEAN);
  BEGIN
    LOOP
      IF FALSE THEN
        Out.String ("foo");
        EXIT;
      END;
    END;
    Out.String ("bar");                  (* unreachable *)
  END P;

PROCEDURE Test* ();
  BEGIN
    P(TRUE);
    Out.Ln;
  END Test;

END Const4.
