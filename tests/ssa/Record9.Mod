MODULE Record9;

IMPORT Out := Out0;

TYPE
  R0 = RECORD
    x: INTEGER;
  END;
  R = RECORD
    (R0)
    y: INTEGER;
  END;
  P = POINTER TO R;
  
VAR
  r: P;
  
PROCEDURE Set(r: R; a, b: INTEGER);
  BEGIN
    r. x := a;
    r. y := b;
  END Set;

PROCEDURE Test* ();
  BEGIN
    NEW (r);
    r. x := 1; r. y := 2;
    Out.Int (r. x, 2); Out.Int (r. y, 2); Out.Ln;
    Set (r^, 3, 4);
    Out.Int (r. x, 2); Out.Int (r. y, 2); Out.Ln;
  END Test;

END Record9.
