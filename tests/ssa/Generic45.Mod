MODULE Generic45;

IMPORT Out:=Out0, G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: E;
    a: INTEGER;
  END;
  AnotherList*(E: G.Object) = POINTER TO AnotherListDesc(E);
  AnotherListDesc(E: G.Object) = RECORD
    (ListDesc(E))
    b: INTEGER;
  END;

VAR
  l1: List(G.A1);
  l2: AnotherList(G.Object);

PROCEDURE (l: List(E)) INIT*(a: INTEGER);
  BEGIN
    l.a := a;
  END INIT;

PROCEDURE (al: AnotherList(E)) INIT*(a, b: INTEGER);
  BEGIN
    al.INIT^(a);
    al.b := b;
  END INIT;

PROCEDURE Test*();
  BEGIN
    l1 := NEW(List(G.A1), 123);
    l2 := NEW(AnotherList(G.Object), 456, 789);

    Out.Int(l1.a, 0); Out.Ln;
    Out.Int(l2.a, 0); Out.Ln;
    Out.Int(l2.b, 0); Out.Ln;
  END Test;

END Generic45.
