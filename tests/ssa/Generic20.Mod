MODULE Generic20;

IMPORT G:=Generic1;

TYPE
  P*(Base: G.Object) = POINTER TO R(Base);
  R*(Base: G.Object) = RECORD
  END;

PROCEDURE (p: P(Base)) Proc1*();
  VAR
    v: Base;
  BEGIN
    NEW(v);
  END Proc1;

END Generic20.
