MODULE Long3;

PROCEDURE Test* ();
  VAR
    r64: LONGREAL;
  BEGIN
    r64 := 1;
    r64 := LONG(r64);
  END Test;

END Long3.
