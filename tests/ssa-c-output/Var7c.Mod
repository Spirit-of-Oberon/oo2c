MODULE Var7c;

IMPORT Out := Out0;

<*IndexCheck:=TRUE*>

PROCEDURE Len (str: ARRAY OF CHAR): INTEGER;
  VAR
    i, y: INTEGER;
  BEGIN
    y := 0;
    i := -1;
    REPEAT
      i := i+1
    UNTIL (str[i] = 0X);
    RETURN i+y
  END Len;

PROCEDURE Test* ();
  BEGIN
    Out.Int (Len(""), 0); Out.Ln;
    Out.Int (Len("abc"), 0); Out.Ln;
  END Test;

END Var7c.
