MODULE Short6;

PROCEDURE Test* ();
  VAR
    r: RECORD x: INTEGER; END;
  BEGIN
    r := SHORT(r);
  END Test;

END Short6.
