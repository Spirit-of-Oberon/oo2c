MODULE Generic74;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD [ABSTRACT]
  END;
  R*(E: Object) = RECORD END;
  Ptr*(E: Object) = POINTER TO R(E);

PROCEDURE P(x: R);
  BEGIN
  END P;

PROCEDURE Test*();
  VAR
    p: Ptr;
  BEGIN
    NEW(p);
    P(p^);
  END Test;

END Generic74.
