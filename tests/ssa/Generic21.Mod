MODULE Generic21;

IMPORT G:=Generic1;

TYPE
  A* = G.Object;
  P1*<T: G.Object> = T;
  B* = P1<G.Object>;
  P2*<T: G.Object> = P1<T>;
  C* = P2<G.Object>;

END Generic21.
