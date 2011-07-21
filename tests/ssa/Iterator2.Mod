MODULE Iterator2;

IMPORT
  Out:=Out0;
  
PROCEDURE Write(x: ARRAY OF LONGCHAR);
  VAR
    c: LONGCHAR;
  BEGIN
    FOR c IN x DO
      Out.Char(SHORT(c));
    END;
  END Write;

PROCEDURE Test*();
  VAR
    x: ARRAY 0 OF LONGCHAR;
  BEGIN
    Write(x);
    Out.Ln;
  END Test;

END Iterator2.
