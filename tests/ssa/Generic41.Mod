MODULE Generic41;

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

PROCEDURE (l: List(E)) INIT*(a: INTEGER);
  BEGIN
  END INIT;

PROCEDURE (al: AnotherList(E)) INIT*(a, b: INTEGER);
  BEGIN
    al.INIT^(a);
  END INIT;

PROCEDURE P*();
  VAR
    l1: List(G.A1);
    l2: AnotherList(G.A1);
  BEGIN
    NEW(l1);
    l1.INIT(12);

    NEW(l2);
    l2.INIT(12, 34);
  END P;

END Generic41.
