MODULE Const7;

IMPORT Out:=Out0;

<*CaseSelectCheck:=TRUE*>
PROCEDURE P (b: BOOLEAN);
  BEGIN
    LOOP
      CASE 1 OF
      | 0:
        Out.String ("foo");
        EXIT;
      ELSE
      END;
    END;
    Out.String ("bar");                  (* unreachable *)
  END P;

PROCEDURE Test* ();
  BEGIN
    P(TRUE);
    Out.Ln;
  END Test;

END Const7.
