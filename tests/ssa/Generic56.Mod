MODULE Generic56;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: E;
  END;

VAR
  l1: List(G.A1);
  
PROCEDURE (l: List(E)) INIT*(x: E);
  BEGIN
    l.x := x;
  END INIT;

PROCEDURE P*(obj: G.A1);
  BEGIN
    l1 := NEW(List(G.A1), obj);
  END P;

END Generic56.
