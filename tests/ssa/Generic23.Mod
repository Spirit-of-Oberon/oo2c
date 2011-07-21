MODULE Generic23;

IMPORT G:=Generic1;

TYPE
  P1*(T: G.Object) = T;
  P2*(T: G.Object) = P1(T);

PROCEDURE P*(o1: G.Object);
  VAR
    o3: P2(G.A1);
  BEGIN
    o3 := o1;
  END P;

END Generic23.
