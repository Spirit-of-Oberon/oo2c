MODULE Generic57;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = ARRAY OF E;
  ListPtr*(E: G.Object) = POINTER TO List(E);

PROCEDURE P*();
  VAR
    l1: ListPtr;
  BEGIN
    NEW(l1, 123);
  END P;

END Generic57.
