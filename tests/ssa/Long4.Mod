MODULE Long4;

PROCEDURE Test* ();
  VAR
    c32: UCS4CHAR;
  BEGIN
    c32 := 1;
    c32 := LONG(c32);
  END Test;

END Long4.
