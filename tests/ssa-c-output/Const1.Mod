MODULE Const1;

IMPORT Out:=Out0;

PROCEDURE F(): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    IF FALSE THEN
      x := 1+2;
    ELSE
      x := 3+4;
    END;
    RETURN x+5;
  END F;

PROCEDURE Test* ();
  BEGIN
    Out.Int (F(), 0); Out.Ln;
  END Test;

END Const1.
