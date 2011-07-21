MODULE Generic21;

IMPORT G:=Generic1;

TYPE
  A* = G.Object;
  P1*(T: G.Object) = T;
  B* = P1(G.Object);
  P2*(T: G.Object) = P1(T);
  C* = P2(G.Object);

PROCEDURE P*(o1: G.Object; a1: G.A1);
  VAR
    o2: A;
    o3: P1(G.Object);
    o4: B;
    o5: P2(G.Object);
    o6: C;
  BEGIN
    o2 := o1;
    o3 := o1;
    o4 := o1;
    o5 := o1;
    o6 := o1;
    
    o2 := a1;
    o3 := a1;
    o4 := a1;
    o5 := a1;
    o6 := a1;
    
    o2 := o2;
    o3 := o2;
    o4 := o2;
    o5 := o2;
    o6 := o2;
    
    o3 := o3;
    o4 := o3;
    o5 := o3;
    o6 := o3;

    o4 := o4;
    o5 := o4;
    o6 := o4;
    
    o5 := o5;
    o6 := o5;

    o6 := o6;
  END P;

END Generic21.
