MODULE LibLRealMath;

IMPORT
  LRealMath;
  
PROCEDURE Test* ();
  VAR
    x, y: LONGREAL;
  BEGIN
    x := LRealMath.sin(LRealMath.pi / 2);
    y := LRealMath.arcsin(0.5);
  END Test;

END LibLRealMath.
