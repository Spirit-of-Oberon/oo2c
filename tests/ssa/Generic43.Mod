MODULE Generic43;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: E;
  END;
  
PROCEDURE P*();
  VAR
    l1: List(G.A1);
  BEGIN
    l1 := NEW(List(G.A1), 123);
  END P;

END Generic43.
