MODULE HOTLoop6;

VAR
  argv: POINTER TO ARRAY OF POINTER TO ARRAY OF CHAR;
  
PROCEDURE Length*();
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0;
    REPEAT
      j := 0;
      IF (argv[i][j] # 0X) THEN
        REPEAT
          INC (j)
        UNTIL (argv[i][j] = 0X);
      END;
      INC (i)
    UNTIL (i >= 111);
  END Length;

PROCEDURE Test* ();
  BEGIN
  END Test;

END HOTLoop6.
