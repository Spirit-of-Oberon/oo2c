MODULE LibSTRING4;

IMPORT
  Out := Out0, String := Language:String0;

PROCEDURE Write (s: STRING);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO s.length-1 DO
      Out.Char(" "); Out.Int(s.CharAt(i), 0);
    END;
    Out.Ln;
  END Write;

PROCEDURE Test*;
  VAR
    s1, s2: STRING;
  BEGIN
    s1 := "ab"; s2 := "c1";
    Write(s1+s2);
    Write("ab"+s2);
    Write(s1+"c1");
    Write("ab"+"c1");
    Write(""+s1+s2+"");

    s1 := "a"; s2 := "bc2";
    Write(s1+s2);
    Write("a"+s2);
    Write(61X+s2);

    s1 := 100X; s2 := 101X;
    Write(s1+s2);
    Write(100X+s2);
    Write(s1+101X);
    Write(61X+101X);
    Write(61X+s1+101X);
  END Test;
  
END LibSTRING4.
