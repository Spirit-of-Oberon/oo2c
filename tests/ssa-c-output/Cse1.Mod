MODULE Cse1;

TYPE
  P* = POINTER TO PDesc;
  PDesc = RECORD
  END;
  
VAR
  p, q: P;
  
PROCEDURE Test* ();
  BEGIN
    NEW (p);
    NEW (q);
  END Test;

END Cse1.
