MODULE Generic40;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: E;
  END;
  AnotherList*(E: G.Object) = POINTER TO AnotherListDesc(E);
  AnotherListDesc(E: G.Object) = RECORD
    (ListDesc(E))
  END;
  
PROCEDURE P*(l1: List; l2: List(G.Object); l3: List(G.A1);
             l4: List(List(G.A1)));
  VAR
    b: BOOLEAN;
    a1: AnotherList;
    a2: AnotherList(G.Object);
    a3: AnotherList(G.A1);
    a4: AnotherList(List(G.A1));
    x: List(G.A1);
  BEGIN
    a1 := l1(AnotherList);
    a2 := l2(AnotherList(G.Object));
    a3 := l3(AnotherList(G.A1));
    a4 := l4(AnotherList(List(G.A1)));
    
    b := l1 IS AnotherList;
    b := l2 IS AnotherList(G.Object);
    b := l3 IS AnotherList(G.A1);
    b := l4 IS AnotherList(List(G.A1));
    
    WITH l1: AnotherList DO ELSE END;
    WITH l2: AnotherList(G.Object) DO ELSE END;
    WITH l3: AnotherList(G.A1) DO ELSE END;
    WITH l4: AnotherList(List(G.A1)) DO ELSE END;
    
    x := l3(List(G.A1));
  END P;

END Generic40.
