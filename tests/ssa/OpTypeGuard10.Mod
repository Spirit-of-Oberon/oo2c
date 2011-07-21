MODULE OpTypeGuard10;

TYPE
  ADesc = RECORD x: INTEGER; END; A = POINTER TO ADesc;

PROCEDURE P(a: ADesc);
BEGIN
  a(ADesc).x := 1;
END P;

END OpTypeGuard10.

