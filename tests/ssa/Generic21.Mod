MODULE Generic21;

IMPORT G:=Generic1;

TYPE
  A* = G.Object;
  P1*<T: G.Object> = T;
  B* = P1<G.Object>;
  P2*<T: G.Object> = P1<T>;
  C* = P2<G.Object>;

PROCEDURE P*(o1: G.Object);
  VAR
    o2: A;
    o3: P1<G.Object>;
    o4: B;
    o5: P2<G.Object>;
    o6: C;
  BEGIN
    o2 := o1;
    o3 := o1;
    o4 := o1;
    o5 := o1;
    o6 := o1;
    
  END P;

END Generic21.
