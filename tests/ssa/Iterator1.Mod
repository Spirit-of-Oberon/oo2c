MODULE Iterator1;

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
  BEGIN
    Write("Hello World");  (* ends with 0X *)
    Out.Ln;
  END Test;

END Iterator1.
