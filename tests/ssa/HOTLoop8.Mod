MODULE HOTLoop8;

IMPORT Out := Out0;
  
PROCEDURE Len (str: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := -1;
    REPEAT
      i := i+1
    UNTIL str[i];
    RETURN i
  END Len;

END HOTLoop8.
