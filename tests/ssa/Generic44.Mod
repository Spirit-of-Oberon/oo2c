MODULE Generic44;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ARRAY 123 OF E;
  
PROCEDURE P*();
  VAR
    l1: List(G.A1);
  BEGIN
    l1 := NEW(List(G.A1));
  END P;

END Generic44.
