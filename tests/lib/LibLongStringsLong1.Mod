MODULE LibLongStringsLong1;

IMPORT
  Out := Out0, LongStrings;

PROCEDURE Write (x: ARRAY OF CHAR);
  VAR
    str: ARRAY 32 OF LONGCHAR;
    i: INTEGER;
  BEGIN
    LongStrings.Long (x, str);
    i := 0;
    WHILE (str[i] # 0X) DO
      Out.Int (ORD (str[i]), 0);
      Out.Char (" ");
      INC (i);
    END;
    Out.Ln;
  END Write;

PROCEDURE Test* ();
  BEGIN
    Write ("abc");
  END Test;

END LibLongStringsLong1.
