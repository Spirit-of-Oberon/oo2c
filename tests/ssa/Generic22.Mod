MODULE Generic22;

IMPORT G:=Generic1;

TYPE
  P1*(T: G.Object) = T;

PROCEDURE P*(o1: G.Object);
  VAR
    o3: P1(G.A1);
  BEGIN
    o3 := o1;
  END P;

END Generic22.
