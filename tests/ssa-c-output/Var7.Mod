MODULE Var7;

IMPORT Out := Out0;

<*IndexCheck:=TRUE*>

PROCEDURE Len (str: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := -1;
    REPEAT
      i := i+1
    UNTIL (str[i] = 0X);
    RETURN i
  END Len;

PROCEDURE Test* ();
  BEGIN
    Out.Int (Len(""), 0); Out.Ln;
    Out.Int (Len("abc"), 0); Out.Ln;
  END Test;

END Var7.
