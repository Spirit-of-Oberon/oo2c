MODULE Generic58;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = ARRAY OF E;
  ListPtr*(E: G.Object) = POINTER TO List(E);

PROCEDURE F(VAR l: ARRAY OF G.Object);
  BEGIN
  END F;

PROCEDURE P*(l1: ListPtr(G.Object); l2: ListPtr);
  BEGIN
    F(l1^);
    F(l2^);
  END P;

END Generic58.
