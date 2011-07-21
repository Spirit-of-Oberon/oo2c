MODULE Long6;

PROCEDURE Test* ();
  VAR
    r: RECORD x: INTEGER; END;
  BEGIN
    r := LONG(r);
  END Test;

END Long6.
