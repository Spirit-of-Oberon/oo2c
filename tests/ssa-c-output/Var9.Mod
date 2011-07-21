MODULE Var9;

<*IndexCheck:=TRUE*>

PROCEDURE Zero (VAR str: ARRAY OF CHAR);
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    LOOP
      IF (i # LEN (str)) THEN
        str[i] := 0X; INC (i);
      ELSE
        EXIT;
      END;
    END;
  END Zero;

PROCEDURE Test* ();
  VAR
    s4: ARRAY 4 OF CHAR;
  BEGIN
    Zero (s4);
  END Test;

END Var9.
