MODULE Generic18;

IMPORT G:=Generic1;

TYPE
  P*(Base: G.Object) = POINTER TO R(Base);
  R*(Base: G.Object) = RECORD
  END;

PROCEDURE (p: P(Base)) Proc1*(a: G.Object);
  VAR
    v: Base;
  BEGIN
    v := a(Base);
  END Proc1;

END Generic18.
