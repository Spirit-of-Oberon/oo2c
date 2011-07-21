MODULE Generic19;

IMPORT G:=Generic1;

TYPE
  P*(Base: G.Object) = POINTER TO R(Base);
  R*(Base: G.Object) = RECORD
  END;

PROCEDURE (p: P(Base)) Proc1*(v: G.Object): BOOLEAN;
  BEGIN
    RETURN (v IS Base);
  END Proc1;

END Generic19.
