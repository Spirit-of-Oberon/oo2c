MODULE Generic60;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = ARRAY OF E;
  ListPtr*(E: G.Object) = POINTER TO List(E);
  L* = ListPtr(G.A1);
  ProcType* = PROCEDURE(l: L);

PROCEDURE P(l: L);
  BEGIN
  END P;
                
PROCEDURE Test*();
  VAR
    p: ProcType;
  BEGIN
    p := P;
  END Test;

END Generic60.
