MODULE LibSTRING5;

IMPORT
  Out := Out0, String := Object;

PROCEDURE Write (s: STRING);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO s.length-1 DO
      Out.Char(" "); Out.Int(ORD(s.CharAt(i)), 0);
    END;
    Out.Ln;
  END Write;

PROCEDURE Test*;
  VAR
    s1, s2: STRING;
  BEGIN
    s1 := 0X;                            (* string of length 1 *)
    Write(s1);
    
    s1 := ""+0X;                         (* string of length 1 *)
    Write(s1);
    
    s1 := "a"+0X;                        (* string of length 2 *)
    Write(s1);
    
  END Test;
  
END LibSTRING5.
