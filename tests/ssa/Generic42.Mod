MODULE Generic42;

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

PROCEDURE P*();
  VAR
    l1: List(G.A1);
    l2: AnotherList(G.A1);
  BEGIN
    l1 := NEW(List(G.A1));
    l2 := NEW(AnotherList(G.A1));
  END P;

END Generic42.
