MODULE Generic61;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = ARRAY OF E;
  ListPtr*(E: G.Object) = POINTER TO List(E);
  L* = ListPtr(G.A1);
  ProcType* = PROCEDURE(): L;

PROCEDURE P(): L;
  BEGIN
    RETURN NIL;
  END P;
                
PROCEDURE Test*();
  VAR
    p: ProcType;
  BEGIN
    p := P;
  END Test;

END Generic61.
