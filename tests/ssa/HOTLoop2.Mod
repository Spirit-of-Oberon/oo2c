MODULE HOTLoop2;

IMPORT Out := Out0;
  
PROCEDURE Len (str: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    WHILE (str[i] # 0X) DO
      i := i+1
    END;
    RETURN i
  END Len;

PROCEDURE Test* ();
  BEGIN
    Out.Int (Len(""), 0); Out.Ln;
    Out.Int (Len("a"), 0); Out.Ln;
    Out.Int (Len("abc"), 0); Out.Ln;
  END Test;

END HOTLoop2.
