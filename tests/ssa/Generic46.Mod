MODULE Generic46;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: E;
  END;
  
PROCEDURE P*(o1: G.Object);
  VAR
    l1: List(G.Object);
  BEGIN
    l1 := o1(List(G.Object));
  END P;

END Generic46.
