MODULE Record1;

IMPORT Out := Out0;

TYPE
  R = RECORD
    x, y: INTEGER;
  END;
  
VAR
  r: R;
  
PROCEDURE Set(a, b: INTEGER);
  BEGIN
    r. x := a;
    r. y := b;
  END Set;

PROCEDURE Test* ();
  BEGIN
    Set (1, 2);
    Out.Int (r. x, 2); Out.Int (r. y, 2); Out.Ln;
    Set (3, 4);
    Out.Int (r. x, 2); Out.Int (r. y, 2); Out.Ln;
  END Test;

END Record1.
