MODULE LoopRewrite3;
<*IndexCheck:=FALSE; Warnings:=FALSE *>

PROCEDURE Len1(VAR a: ARRAY OF CHAR): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (a[i] # 0X) DO
      INC(i);
    END;
    RETURN i;
  END Len1;

PROCEDURE Len2(VAR a: ARRAY OF LONGCHAR): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (a[i] # 0X) DO
      INC(i);
    END;
    RETURN i;
  END Len2;

PROCEDURE Len2R(VAR a: ARRAY OF LONGCHAR): LONGINT;
  VAR
    i: LONGINT;
  BEGIN
    i := -1;
    REPEAT
      INC(i);
    UNTIL (a[i] = 0X);
    RETURN i;
  END Len2R;

END LoopRewrite3.
