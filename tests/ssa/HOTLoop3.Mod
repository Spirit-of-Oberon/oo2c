MODULE HOTLoop3;

IMPORT Out := Out0;
  
PROCEDURE Len (str: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    LOOP
      IF (str[i] # 0X) THEN
        i := i+1;
      ELSE
        EXIT;
      END;
    END;
    RETURN i
  END Len;

PROCEDURE Test* ();
  BEGIN
    Out.Int (Len(""), 0); Out.Ln;
    Out.Int (Len("a"), 0); Out.Ln;
    Out.Int (Len("abc"), 0); Out.Ln;
  END Test;

END HOTLoop3.
