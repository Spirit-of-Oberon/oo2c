MODULE OpString1;

IMPORT Out := Out0;

CONST
  s1 = "A" + "B";
  s2 = 41X + 42X;
  s3 = 100X + 101X;

PROCEDURE Write(s: ARRAY OF LONGCHAR);
  VAR
    i: LONGINT;
  BEGIN
    i := -1;
    REPEAT
      INC(i);
      Out.Int(ORD(s[i]), 4);
    UNTIL (s[i] = 0X);
    Out.Ln;
  END Write;

PROCEDURE Test*;
BEGIN
  Out.String(s1); Out.Ln;
  Out.String(s2); Out.Ln;
  Write(s3);
  Write(100X + 101X);
END Test;

END OpString1.
