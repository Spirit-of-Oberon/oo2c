MODULE LibRealMath;

IMPORT
  RealMath;
  
PROCEDURE Test* ();
  VAR
    x, y: LONGREAL;
  BEGIN
    x := RealMath.sin(RealMath.pi / 2);
    y := RealMath.arcsin(0.5);
  END Test;

END LibRealMath.
