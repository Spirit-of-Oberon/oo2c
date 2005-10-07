MODULE Generic81;

IMPORT Object, Out:=Out0;

TYPE
  Alp(T: Object.Object) = POINTER TO AlpDesc(T);
  AlpDesc(T: Object.Object) = RECORD(Object.ObjectDesc)
    val: LONGINT;
  END;

  Bet = POINTER TO BetDesc;
  BetDesc = RECORD(Object.ObjectDesc)

  END;

  Gam = Alp(Bet);

VAR
  g1: Gam;
  g2: Gam;

PROCEDURE (a: Alp(T)) INIT*(val: INTEGER);
BEGIN
  a.val := val;
END INIT;

PROCEDURE (x: Alp(T)) Equals*(y: Object.Object): BOOLEAN;
BEGIN
  IF y = NIL THEN
    RETURN FALSE;
  ELSE
    WITH y: Alp(T) DO
      RETURN x.val = y.val;
    ELSE
      RETURN FALSE;
    END;
  END;
END Equals;

PROCEDURE Test*();
  BEGIN
    g1 := NEW(Gam, 1);
    g2 := NEW(Gam, 1);
    IF g1.Equals(g2) THEN
      Out.String('equals'); Out.Ln();
    ELSE
      Out.String('not equals'); Out.Ln();
    END;
  END Test;
  
END Generic81.
