MODULE OpString1;

IMPORT Out := Out0;

CONST
  s1 = "A" + "B";
  s2 = 41X + 42X;
  s3 = 100X + 101X;
  s4 = 10000X + 10001X;
  
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

PROCEDURE WriteUCS4(s: ARRAY OF UCS4CHAR);
  VAR
    i: LONGINT;
  BEGIN
    i := -1;
    REPEAT
      INC(i);
      Out.Int(ORD(s[i]), 6);
    UNTIL (s[i] = 0X);
    Out.Ln;
  END WriteUCS4;

PROCEDURE Test*;
BEGIN
  Out.String(s1); Out.Ln;
  Out.String(s2); Out.Ln;
  Write(s3);
  Write(100X + 101X);
  WriteUCS4(s4);
  WriteUCS4(10000X + 10001X);
END Test;

END OpString1.
