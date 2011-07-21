MODULE Generic37;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = POINTER TO ADesc(T);
  ADesc*(T: G.Object) = RECORD
    x-: T;
  END;

PROCEDURE P*();
  VAR
    a: A;
    b: A(G.A1);
  BEGIN
    NEW(a);
    NEW(b);
  END P;

END Generic37.
