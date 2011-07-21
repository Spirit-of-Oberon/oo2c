MODULE Var8;

<*IndexCheck:=TRUE*>

PROCEDURE Zero (VAR str: ARRAY OF CHAR);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN(str)-1 DO
      str[i] := 0X
    END;
  END Zero;

PROCEDURE Test* ();
  VAR
    s4: ARRAY 4 OF CHAR;
  BEGIN
    Zero (s4);
  END Test;

END Var8.
