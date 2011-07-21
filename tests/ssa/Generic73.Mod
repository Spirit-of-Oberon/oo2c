MODULE Generic73;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectArray*(E: Object) = ARRAY OF E;
  ObjectArrayPtr*(E: Object) = POINTER TO ObjectArray(E);
  ObjectDesc* = RECORD [ABSTRACT]
  END;

PROCEDURE P(x: ObjectArray);
  BEGIN
  END P;

PROCEDURE Test*();
  VAR
    p: ObjectArrayPtr;
  BEGIN
    NEW(p, 123);
    P(p^);
  END Test;

END Generic73.
