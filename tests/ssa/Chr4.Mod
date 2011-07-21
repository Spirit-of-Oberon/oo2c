MODULE Chr4;

PROCEDURE Test;
  VAR
    x: LONGCHAR;
    y: UCS4CHAR;
  BEGIN
    x := LONGCHR(256);
    y := UCS4CHR(256);
  END Test;

END Chr4.
