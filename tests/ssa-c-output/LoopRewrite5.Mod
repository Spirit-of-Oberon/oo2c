MODULE LoopRewrite5;
<*IndexCheck:=FALSE; Warnings:=FALSE *>

PROCEDURE Trim1(VAR src, dest: ARRAY OF CHAR);
(* Remove all characters <=" " from string.  *)
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0; j := 0;
    WHILE (src[i] # 0X) DO
      IF (src[i] > " ") THEN
        dest[j] := src[i];
        INC(j);
      END;
      INC(i);
    END;
    dest[j] := 0X;
  END Trim1;

PROCEDURE Trim2(VAR src, dest: ARRAY OF LONGCHAR);
(* Remove all characters <=" " from string.  *)
  VAR
    i, j: LONGINT;
  BEGIN
    i := 0; j := 0;
    WHILE (src[i] # 0X) DO
      IF (src[i] > " ") THEN
        dest[j] := src[i];
        INC(j);
      END;
      INC(i);
    END;
    dest[j] := 0X;
  END Trim2;

END LoopRewrite5.
