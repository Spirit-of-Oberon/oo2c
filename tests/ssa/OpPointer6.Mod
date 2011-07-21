MODULE OpPointer6;

TYPE
  A = POINTER TO ADesc;
  ADesc = RECORD x: INTEGER; END;

PROCEDURE P(a: A);
  BEGIN
    a.x := 0;
  END P;

PROCEDURE Test* ();
  BEGIN
    P(NIL);
  END Test;

END OpPointer6.
