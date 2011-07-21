MODULE Generic38;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
  END;

PROCEDURE (l: List(E)) Get(i: LONGINT): E;
  BEGIN
    RETURN NIL;
  END Get;

PROCEDURE P*(l1: List(G.A1); l2: List(List(G.A1)));
  VAR
    a1: G.A1;
  BEGIN
    l1 := l2.Get(0);
    a1 := l1.Get(0);
  END P;

END Generic38.
