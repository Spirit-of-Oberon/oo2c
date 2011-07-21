MODULE HOTLoop7;

PROCEDURE Len (str: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    WHILE str[i] DO
      i := i+1
    END;
    RETURN i
  END Len;

END HOTLoop7.
